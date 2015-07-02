Diseño procedimental
====================

En este apartado se referencian los algoritmos implementados en el sistema que son considerados de mayor relevancia.

Detección de la versión de la placa, para adaptar el número de pines ofrecidos al valor físico.

.. literalinclude:: ../../../../../src/board_revision.cpp
	:language: c


Apertura de un pin mediante una llamada al comando ``gpio-admin``.

.. literalinclude:: ../../../../../src/gpio.cpp
	:language: c
	:lines: 4-12,103-115

Modificación del valor de un pin.

.. literalinclude:: ../../../../../src/gpio.cpp
	:language: c
	:lines: 213-232