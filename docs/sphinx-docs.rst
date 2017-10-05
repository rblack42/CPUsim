Building Sphinx Documentation
#############################

I have modified the ``CPUsim`` project ``Makefile`` so it will process
reStructuredText documentation in your virtual machine. To use this feature,
you need to update your ``Makefile`` and copy the ``files`` folder from
``CPUsim`` into your project.


Before trying this, you need one more tool installed in your virtual machine:

..  code-block:: bash

    $ sudo apt-get install python3-venv

This will create an isolated environment for Python in the docs folder. The
needed files to manage this environment are all stored in a folder named
``_venv``. Do not delete or modify that file.

..  note::  

    The CPUsim project ``.gitignore`` file has been uupdated to keep this
    directory out of your repo. Be sure to update that (hidden) file in your
    project.

Preparing your System
*********************

Before you can build your documentation HTML files, we need to prepare the
``docs`` directory. Make sure your project folder has the ``files`` folder from
the ``CPUsim`` project, then do this:

..  code-block:: bash

    $ make install

Configuration
*************

In your ``docs`` folder now, yiou shuld see a file named ``conf.py``. Edit this
file and change the ``YourName`` setting so it lists your name. 

Once you have done this, try building the docs:

..  code-block:: bash

    $ make html
    $ make view
    
    
That last line should launch FIrefox and show you the default documentation
set. Not much to see, but it should worka. You should see this document in the list of files on the opening page.

Adding Documentation
********************

You can now create one or more documentation files, each named
``something.rst``. This setup will process all ``.rst`` files it finds in the
``docs`` directory and build nice HTML pages. We can configure the
```index.rst`` file so it displays pages in an order you specify, but then you
have to list all the files to process. See me for help setting this up if you
like.



