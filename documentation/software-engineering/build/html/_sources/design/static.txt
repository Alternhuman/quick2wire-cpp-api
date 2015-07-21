Vista estática del producto
===========================

API
---

.. figure:: ../img/design_quick2wire-cpp-api.*
    :align: center

    La API utiliza como punto de entrada la clase ``GPIO``, que gestionará un objeto ``PinBank``, el cual se encargará de la gestión de los diferentes pines.

gpio-admin
----------

.. figure:: ../img/design_quick2wire-gpio-admin.*
    :align: center

    El ejecutable ``gpio-admin`` no se implementa siguiendo el paradigma de orientación a objetos. Se representa en el diagrama mediante una clase con el estereotipo ``<<file>>``.