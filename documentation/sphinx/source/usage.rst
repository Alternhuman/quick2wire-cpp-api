Usage
=====

The API works using a combination of object instances. The entry point is the GPIO object, which provides appropiate translation of pin numbering and automatic creation of Pin objects. Here's a reference sequence: 

.. code-block:: cpp
	
	GPIO g;
	Pin p = g.pins->at(3);

	p.open();
	p.setDirection(OUT);
	p.setValue(1);

	p.close()

