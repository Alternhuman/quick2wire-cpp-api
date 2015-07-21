Requisitos no funcionales
=========================

NFR1: CMake
-----------

- **Versión**: 1
- **Autores**: Diego Martín
- **Fuentes**: Análisis preliminar
- **Objetivos asociados**: OBJ-2
- **Descripción**: Se utilizará CMake para la gestión de los diferentes procesos de compilación e instalación del *software*. Además se deberá crear un módulo de CMake que permita localizar la biblioteca creada al ser invocado.
- **Importancia**: Media
- **Urgencia**: Baja
- **Estado**: Completo
- **Estabilidad**: Alta

NFR2: Biblioteca compartida
---------------------------

- **Versión**: 1
- **Autores**: Diego Martín
- **Fuentes**: Análisis preliminar
- **Objetivos asociados**: OBJ-2
- **Descripción**: La inclusión de la biblioteca en el sistema debe realizarse en tiempo de ejecución mediante el su compilación como biblioteca compartida. 
- **Importancia**: Baja
- **Urgencia**: Baja
- **Estado**: Completo
- **Estabilidad**: Alta
  
NFR3: Similitud
---------------

- **Versión**: 1
- **Autores**: Diego Martín 
- **Fuentes**: Análisis preliminar
- **Descripción**: A fin de facilitar el trabajo con la API a desarrolladores conocedores de la versión en Python, se conservarán las convenciones de nombres y secuencias de operación que esta utiliza, sin que esto impida aprovechar características de C++ no presentes en Python que se consideren beneficiosas.
- **Importancia**: Media
- **Urgencia**: Media
- **Estado**: Completo
- **Estabilidad**: Estable

NFR4: Documentación
-------------------

- **Versión**: 1
- **Autores**: Diego Martín
- **Fuentes**: Análisis preliminar
- **Descripción**: La API deberá incluir una documentación fácil de comprender por cualquier desarrollador con conocimientos de C++.
- **Importancia**: Media
- **Urgencia**: Media
- **Estado**: Completo
- **Estabilidad**: Estable

.. 
    - **Versión**
    - **Autores**
    - **Fuentes**
    - **Objetivos asociados**
    - **Requisitos asociados**
    - **Descripción**
    - **Importancia**
    - **Urgencia**
    - **Estado**
    - **Estabilidad**
    - **Comentarios**