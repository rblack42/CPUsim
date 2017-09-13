Decoding the Makefile
#####################

OK, I admit it, this project ``Makefile`` looks scary. But, it is not so bad,
and it handles a lot of the management details you need to think about when you
set up a complicated project. (Well, one more complicated than the simple ones
you probably did for your earlier courses!).

Identifying the build products
******************************

The first think we need to do it identify the things we want to build in this
project. Obviously, we want to buit a program of some sort. But to make Guido
happy, we also want to build a test program that exercises the major components
of our program, and we want to process documentation files and produce noce to
look at HTML files we can view with a web browser. The major program components
in this example will be collected into a single library file (a simple wrapper
around a set of object files that the linker can read).

We start off this ``Makefile`` by setting up names for these products:

..  literalinclude::    ../Makefile

Creating File Name Lists
************************

We could create names for lists of files we need to either have in the project
code directories, or build as part of constructing the products. But I am lazy,
and I would rather let ``make`` figure those things out. Fortunately, ``make``
has the ability to create lists by looking into your directories to see what is
there. Here is how we build alist of C++ files we need to compile:

..  literalinclude::    ../Makefile


    

