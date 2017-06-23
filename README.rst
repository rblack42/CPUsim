CPUsim
######

:Author: Roie R. Black
:Date: Jun 21, 2017
:Course: COSC2325
:School: Austin Community College

A simple CPU simpuator.

Travis-CI Built status:
***********************

Code:

..  image::

Documentation:

..  image::

Cloning this Project
********************

This simulator project is maintained in three repositories on Github_. This
repository is a top-level management layer, which holds a master Makefile used
for managing the project.

Cloned inside this project, (but kept separate by a **.gitignore** file in this
project, are repositories for the code and documentation. They are kept
separate, and do not use Git_ submodules, or subtrees, so that the
documentation can navigate through the history of the code as it evolved. This
structure may seem unusual, until you read through the documentation and see
what can be done using this approach.

Cloning is managed by an Ansible_ management layer in this repository. Follow
these steps to complete a full project cloning operation:

1. Clone this repository:
=========================

..  code-block:: bash

    $ git clone https://github.com/rblack42/CPUsim

This will clone the current management project repository onto your system. The
actual project is not installed after this step.

2. run "make reqs"
==================

..  code-block: bash

    $ make reqs

This will install Python and Ansible on your system in a Python virtualenv. It will then run Ansible_ to clone the remaining two repositories into the **src** and **docs** subdirectories, and provision those projects with required tools so they can be built. 

Once this step has completed, you should be able to run the following commands:

..  code-block:: bash

    $ make code
    $ make test
    $ make docs

The docs may be displayed locally by running this:

..  code-block:: bash

    make serve

This will launch your web browser and aim it at the local copy of the documentation.

