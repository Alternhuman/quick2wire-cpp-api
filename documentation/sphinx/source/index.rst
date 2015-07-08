.. quick2wire-cpp-api documentation master file, created by
   sphinx-quickstart on Tue Jun  2 13:51:48 2015.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

quick2wire-cpp-api
==================

The quick2wire-cpp-api is a port of the `quick2wire-python-api <https://github.com/quick2wire/quick2wire-python-api>`_ written entirely in C++ with C support. It grants access to the GPIO ports to unprivileged users using the quick2wire `gpio-admin <https://github.com/quick2wire/quick2wire-gpio-admin>`_ tool (or a modified version in **Arch Linux**).

The library is a literal port of its parent project, so users of the Python implementation should feel comfortable with this variant as well.

This is a work in progress. So far, only the GPIO is implemented (and only the OUT mode), but a port of the whole API is on the way.

Contents
--------

.. toctree::
   :maxdepth: 2

   principles
   reference
   usage
   examples
   software_engineering/intro


Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`

