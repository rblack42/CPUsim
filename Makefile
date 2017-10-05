# Makefile for CPUsim

# what to build
USRAPP	:= cpusim
TSTAPP	:= sim_test
LIBAR	:= cpusim_lib.a

# project directories
SRC		:=	src
LIB		:=  lib
TST 	:=  tests
DOC		:=	docs
INC		:=	include
BLD		:=	_build

DIRS 	:=	$(SRC) $(LIB) $(TST) $(DOC) $(INC) \
		$(BLD) $(BLD)/$(SRC) $(BLD)/$(LIB) $(BLD)/$(TST)

USRCS = $(wildcard $(SRC)/*.cpp)
LSRCS = $(wildcard $(LIB)/*.cpp)
TSRCS = $(wildcard $(TST)/*.cpp)

UOBJS = $(USRCS:%.cpp=$(BLD)/%.o)
LOBJS = $(LSRCS:%.cpp=$(BLD)/%.o)
TOBJS = $(TSRCS:%.cpp=$(BLD)/%.o)
OBJS  = $(UOBJS) $(LOBJS) $(TOBJS)

# generate a list of dependencies
UDEPS	:= $(UOBJS:.o=.d)
LDEPS	:= $(LOBJS:.o=.d)
TDEPS	:= $(TOBJS:.o=.d)
DEPS	:= $(UDEPS) $(LDEPS) $(TDEPS)

# tools
CXX	:= g++
AR	:= ar
RM	:= RM -f
PIP	:= pip
SPHINX	:= _venv/bin/sphinx-build
VENV	:= python3 -m venv

CFLAGS	:= -std=c++11 -I $(INC)
LFLAGS	:= -L $(LIB) $(LIBAR)

# targets follow ----------------------

.PHONY: all
# target: all - build directories, app and test-app
all:	setup $(USRAPP) $(TSTAPP)

.PHONY:	run
# target: run - run application
run:	$(USRAPP)
	./$(USRAPP)

.PHONY: test
# target: test - run test-app
test:	$(TSTAPP)
	./$(TSTAPP)

$(USRAPP):	$(UOBJS) $(LIBAR)
	$(CXX) $(LFLAGS) -o $@ $^ 

$(TSTAPP):	$(TOBJS) $(LIBAR)
	$(CXX) $(LFLAGS) -o $@ $^

$(LIBAR):	$(LOBJS)
	$(AR) rcs $@ $^

# build any needed directories
.PHONY:	setup
# target: setup - create project directories
setup: $(DIRS)

$(DIRS):
	mkdir -p $@

# inplicit rule to build object files
$(BLD)/%.o:	%.cpp
	$(CXX) -c $(CFLAGS) $< -o $@ -MMD -MP

.PHONY:	clean
# target: clean - remove all unneeded files
clean:
	$(RM) $(USRAPP) $(TSTAPP) $(OBJS) $(DEPS)

# show file lists
.PHONY: debug
# target: debug - display all make variables
debug:
	-@echo USRCS = $(USRCS)
	-@echo LSRCS = $(LSRCS)
	-@echo TSRCS = $(TSRCS)
	-@echo UOBJS = $(UOBJS)
	-@echo LOBJS = $(LOBJS)
	-@echo TOBJS = $(TOBJS)
	-@echo UDEPS = $(UDEPS)
	-@echo LDEPS = $(LDEPS)
	-@echo TDEPS = $(TDEPS)
	-@echo DIRS  = $(DIRS)

# build rules for Sphinx documentation
.PHONY:	install
# target: install - build sphinx documentation project
install:	docs/_venv activate
	cd docs && _venv/bin/pip install -Ur requirements.txt && \
	mkdir -p _static && cp ../files/conf.py . && \
	cp ../files/index.rst . && \
	cp ../files/webbrowser _venv/bin

docs/_venv:
	$(VENV)	docs/_venv

.PHONY:	activate
activate:	docs/_venv
	bash docs/_venv/bin/activate

.PHONY: html
# target: html - build sphinx html files
html:	activate
	cd docs && \
	$(SPHINX) -b html -d ../_build/doctrees . ../_build/html

.PHONY: view
# target: - view generated HTML doc pages
view:	activate html
	cd docs && \
	_venv/bin/webbrowser

.PHONY: help
# target: help - Display all callable targets
help:
	@echo
	@egrep "^\s*#\s*target\s*:\s*" [Mm]akefile \
		| sed -E "s/^\s*#\s*target\s*:\s*//g"
	@echo

# include compiler generated dependencies
-include $(BLD)/*.d

