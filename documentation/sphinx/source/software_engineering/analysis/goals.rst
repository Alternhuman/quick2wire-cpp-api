Objetivos
---------

**OBJ1**: Control de los pines GPIO por usuarios no privilegiados
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- **Descripción**: La biblioteca y el resto de utilidades deberán proveer acceso a este dispositivo de forma que el acceso no exiga contar con privilegios de administración del sistema (usuario *root* en sistemas \*NIX).
- **Importancia**: Muy alta
- **Urgencia**: Alta
- **Estado**: Alta
- **Estabilidad**: Estable 
- **Comentarios**   

**OBJ2** Compatibilidad con C y C++
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
- **Descripción**: La biblioteca deberá ser integrable en código fuente escrito en C, utilizando para ello puntos de acceso a la biblioteca que no dependan de C++.
- **Importancia**: Media
- **Urgencia**: Media
- **Estado**: Completo
- **Estabilidad**: Estable
- **Comentarios**
  
**OBJ3** Gestión de permisos y propiedad
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- **Descripción**: Una vez que un usuario controle un pin la biblioteca debe garantizar la exclusividad de uso del mismo.
- **Importancia**: Muy alta
- **Urgencia**: Alta
- **Estado**: Alta
- **Estabilidad**: Estable 
- **Comentarios**   

**OBJ4** Independencia del *hardware*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    - **Descripción**: La biblioteca debe ser compatible con todas las versiones de la placa **Raspberry Pi**, detectando esta en tiempo de ejecución sin intervención del programador.
    - **Importancia**: Alta
    - **Urgencia**: Alta
    - **Estado**: Completo
    - **Estabilidad**: Estable
    - **Comentarios**

..
    - **Descripción**: 
    - **Importancia**: 
    - **Urgencia**: 
    - **Estado**: 
    - **Estabilidad**: 
    - **Comentarios**: 