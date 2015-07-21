Ámbito
======

La API se integrará con diferentes aplicaciones mediante su compilación como biblioteca compartida. Este archivo se almacenará en uno de los directorios de búsqueda de bibliotecas del sistema, del mismo modo que los archivos de cabecera serán situados en uno de los directorios de inclusión. La gestión de esta dependencia se ultima con la utilización de un módulo de búsqueda de CMake, por lo que se recomendará su uso (de forma opcional) a los diferentes usuarios.

Los usuarios con privilegios de acceso a la API serán aquellos miembros del grupo ``gpio``, del cual son miembros todos los desarrolladores de la organización en la que la biblioteca se utilizará.