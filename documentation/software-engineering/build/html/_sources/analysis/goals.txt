Objetivos
---------

**OBJ1**: Control de los pines GPIO por usuarios no privilegiados
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- **Versión**: 1
- **Autores**: Requisito marcado por la implementación original
- **Fuentes**: Implementación original
- **Descripción**: La biblioteca y el resto de utilidades deberán proveer acceso a este dispositivo de forma que el acceso no exiga contar con privilegios de administración del sistema (usuario *root* en sistemas \*NIX).
- **Importancia**: Muy alta
- **Urgencia**: Alta
- **Estado**: Alta
- **Estabilidad**: Estable

**OBJ2** Compatibilidad con C y C++
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- **Versión**: 1
- **Autores**: Diego Martín
- **Fuentes**: Fase de análisis preliminar
- **Descripción**: La biblioteca deberá ser integrable en código fuente escrito en C, utilizando para ello puntos de acceso a la biblioteca que no dependan de C++.
- **Importancia**: Media
- **Urgencia**: Media
- **Estado**: Completo
- **Estabilidad**: Estable
- **Comentarios**
  
**OBJ3** Gestión de permisos y propiedad
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- **Versión**: 1.5
- **Autores**: Requisito marcado por la implementación original
- **Fuentes**: Implementación original
- **Descripción**: Una vez que un usuario controle un pin la biblioteca debe garantizar la exclusividad de uso del mismo.
- **Importancia**: Muy alta
- **Urgencia**: Alta
- **Estado**: Alta
- **Estabilidad**: Estable 
- **Comentarios**   

**OBJ4** Independencia del *hardware*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- **Versión**: 1.5
- **Autores**: Requisito marcado por la implementación original
- **Fuentes**: Implementación original
- **Descripción**: La biblioteca debe ser compatible con todas las versiones de la placa **Raspberry Pi** , detectando el modelo sobre el que la biblioteca se encuentra en tiempo de ejecución sin intervención del programador.
- **Importancia**: Alta
- **Urgencia**: Alta
- **Estado**: Completo
- **Estabilidad**: Estable
- **Comentarios**

.. 
    - **Versión**
    - **Autores**
    - **Fuentes**
    - **Descripción**
    - **Subobjetivos**
    - **Importancia**
    - **Urgencia**
    - **Estado**
    - **Estabilidad**
    - **Comentarios**