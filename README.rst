CPUsim
######

:Author: Roie R. Black
:Date: Sep 12, 2017
:Course: COSC2325
:School: Austin Community College

A simple CPU simulator.

Travis-CI Built status:
***********************

..  image::  https://travis-ci.org/rblack42/CPUsim.svg?branch=master

Cloning this Project
********************

Students should not clone this project directly into their lab repository.
Instead, clone it outside of any course repositories, and use it as a template
for your project. 

Assuming you have a ``cosc2325`` folder in your VM home directory, you can
start by cloning the example project:

..  code-block:: bash

    $ cd ~/cosc2325
    $ git clone https://github.com/rblack42/CPUsim

Next, assuming you have your empty lab project file cloned into this same
directory:

..  code-block:: bash

    $ cd lab-CPUsim
    $ cp ../CPUsim/Makefile .
    $ make

This will build your project directory structure, but obviously will not build
anything, since there are no files in the project yet!

Copy the basic project files, including the hidden ``.travis.yml`` into your
lab project repo and try ``make`` again.

Copy the example ``README.rst`` file and edit it to add your details (not mine).

Testing the Starter code
========================

Since I may continue to update this project, you should do this periodically:

..  code-block:: bash

    $ cd ~/cosc2325/CPUsim
    $ git pull

This will update your local copy of the project with any updates I have made.

Next, test the example project as follows:

..  code-block:: bash

    $ make
    $ make run
    $ make test
    $ make html

If you are doing this in your Linux VM, edit the ``files/webbrowser`` file and
comment out the ``browser_path`` line I use on my Mac, and uncomment the Linux
line below that. Then do this:

..  code-block:: bash

    $ make view

You should see your documentation. Hopefully, Guido will like this!

If you use the example ``Makefile`` and set up your lab project like the example, these same commands should work on your project as well. After I enable TravisCI testing, you should be able to get a nice green badge as well!

