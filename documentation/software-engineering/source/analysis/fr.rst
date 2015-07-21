Requisitos funcionales
======================

RF-1: Comunicación con la biblioteca
------------------------------------

- **Versión**: 1
- **Autores**: Requisito marcado por la implementación original
- **Fuentes**: Implementación original
- **Objetivos asociados**: OBJ-1, OBJ-3
- **Requisitos asociados**: NFR-2
- **Descripción**: Siguiendo el mismo modelo de trabajo de la implementación original, la realización de las diferentes operaciones se realizará mediante llamadas al comando ``gpio-admin``.
- **Precondición**
- **Secuencia normal**:

    1. La implementación de la biblioteca solicita la realización de una tarea al comando, especificando los parámetros de la aplicación a través de los parámetros de entrada propios de una llamada al sistema (recogidos en el array ``argv``).
    2. La biblioteca determina la identidad del usuario mediante el UID del proceso.
    3. Se realiza la operación solicitada y emite un mensaje de confirmación o fallo.
- **Poscondición**: La operación es realizada.
- **Excepciones**:

    + En el caso de que la biblioteca retorne un error, comienza el caso de uso **RF-7**
- **Rendimiento**: Alto
- **Frecuencia**: Alta
- **Importancia**: Media
- **Urgencia**: Alta
- **Estado**: Completo
- **Estabilidad**: Estable

RF-2: "Registro" de un pin
--------------------------

- **Versión**: 1
- **Autores**: Requisito marcado por la implementación original
- **Fuentes**: Implementación original
- **Objetivos asociados**: OBJ-3
- **Requisitos asociados**: IRQ-1
- **Descripción**: La biblioteca considera que un pin debe ser "propiedad" de un usuario antes de poder utilizar el mismo, y a petición de un usuario verificará que el pin solicitado está libre u ocupado, reservándolo en el primer caso.
- **Precondición**
- **Secuencia normal**:

    1. La aplicación solicita el registro de un pin para su uso a la biblioteca. Comienza el caso de uso RF-1.
    2. Se analiza el código de retorno de la llamada al sistema. En caso de que el pin se encuentre reservado, el caso de uso finaliza y el usuario es notificado. En caso de que el pin no se encuentre reservado, la biblioteca indica que el usuario solicitante es el nuevo propietario.
    3. La biblioteca notifica al usuario de que la reserva ha sido satisfactoria.
- **Poscondición**: El usuario obtiene acceso al pin.
- **Excepciones**: No se plantean excepciones
- **Rendimiento**: Alto
- **Frecuencia**: Generalmente un usuario realizará una reserva en cada ejecución.
- **Importancia**: Alta
- **Urgencia**: Alta
- **Estado**: Completo
- **Estabilidad**: Estable

RF-3: "Liberación" de un pin
----------------------------

- **Versión**: 1
- **Autores**: Requisito marcado por la implementación original
- **Fuentes**: Implementación original
- **Objetivos asociados**: OBJ-1, OBJ-3
- **Requisitos asociados**: IRQ-1
- **Descripción**: De la misma forma que un pin es reservado debe ser liberado al finalizar la ejecución, de forma que posteriores usuarios puedan utilizar el mismo.
- **Precondición**: El pin debe estar reservado.
- **Secuencia normal**:

    1. La aplicación solicita la liberación del pin al comando ``gpio-admin``. Comienza el caso de uso *RF-1*
    2. La aplicación es notificado del resultado de la operación.
- **Poscondición**: El pin es liberado.
- **Excepciones**: En caso de que se solicite la liberación de un pin no reservado, se notifica a la aplicación y el caso de uso finaliza.
- **Rendimiento**: Alto
- **Frecuencia**: Media
- **Importancia**: Alta
- **Urgencia**: Alta
- **Estado**: Completo
- **Estabilidad**: Estable

RF-4: Modificación de la "dirección" del pin
--------------------------------------------

- **Versión**: 1
- **Autores**: Requisito marcado por la implementación original
- **Fuentes**: Implementación original
- **Objetivos asociados**: OBJ-1, OBJ-3
- **Requisitos asociados**: IRQ-1
- **Descripción**: La dirección del pin indica si se utilizará para recibir o enviar información. Todos los pines pueden operar en ambos modos.
- **Precondición**: El pin debe estar reservado previamente.
- **Secuencia normal**:

    1. La aplicación solicita modificar la dirección del pin al comando ``gpio-admin``. Comienza el caso de uso *RF-1*.
- **Poscondición**: La dirección del pin es modificada.
- **Excepciones**: En caso de que se solicite la modificación de un pin no reservado, se notifica a la aplicación y el caso de uso finaliza.
- **Rendimiento**
- **Frecuencia**: Se estima que durante cada ejecución se modificará la dirección del pin únicamente durante la fase de inicialización del mismo.
- **Importancia**: Alta
- **Urgencia**: Alta
- **Estado**: Completo
- **Estabilidad**: Estable

RF-5: Modificación del valor de un pin
--------------------------------------

- **Versión**: 1
- **Autores**: Requisito marcado por la implementación original
- **Fuentes**: Implementación original
- **Objetivos asociados**: OBJ-1, OBJ-3
- **Requisitos asociados**: IRQ-1
- **Descripción**: En caso de que la dirección del pin sea de salida, el valor del pin podrá ser modificado (los valores de tensión admitidos con 0 y 5 voltios).
- **Precondición**: El pin debe estar reservado previamente.
- **Secuencia normal**:

    1. La aplicación solicita modificar el valor del pin al comando ``gpio-admin``. Comienza el caso de uso *RF-1*.
- **Poscondición**: El valor del pin es modificado.
- **Excepciones**: En caso de que se solicite la modificación de un pin no reservado, se notifica a la aplicación y el caso de uso finaliza.
- **Rendimiento**:
- **Frecuencia**: El número de modificaciones que se realizarán en un programa se estima muy elevado, por lo que el rendimiento deberá ser alto.
- **Importancia**: Alta
- **Urgencia**: Alta
- **Estado**: Completo
- **Estabilidad**: Estable

RF-6: Lectura del valor de un pin
---------------------------------

- **Versión**: 1
- **Autores**: Requisito marcado por la implementación original
- **Fuentes**: Implementación original
- **Objetivos asociados**: OBJ-1, OBJ-3
- **Requisitos asociados**: IRQ-1
- **Descripción**: En caso de que la dirección del pin sea de entrada, el valor (tensión) del pin podrá ser consultado (los valores de trabajo son 0 y 5 voltios).
- **Precondición**: El pin debe estar reservado previamente.
- **Secuencia normal**:

    1. La aplicación solicita el valor del pin al comando ``gpio-admin``. Comienza el caso de uso *RF-1*.
    2. Se retorna el valor del pin a la aplicación.
- **Poscondición**: La aplicación cuenta con el valor pin.
- **Excepciones**: En caso de que se solicite la lectura de un pin no reservado, se notifica a la aplicación y el caso de uso finaliza.
- **Rendimiento**:
- **Frecuencia**: El número de consultas que se realizarán en un programa se estima muy elevado, por lo que el rendimiento deberá ser alto.
- **Importancia**: Alta
- **Urgencia**: Alta
- **Estado**: No realizado
- **Estabilidad**: Estable
  
RF-7: Gestión de error
----------------------

- **Versión**: 1
- **Autores**: Diego Martín
- **Fuentes**: Análisis preliminar
- **Objetivos asociados**: OBJ-1, OBJ-3
- **Requisitos asociados**: NFR-3
- **Descripción**: En el caso de que la biblioteca o la herramienta ``gpio-admin`` retornen un código de error no identificado, comienza este caso de uso.
- **Precondición**: Se debe dar un error en la biblioteca o en ``gpio-admin``
- **Secuencia normal**:

    1. La biblioteca intenta identificar el error que se ha dado.
    2. En caso de poder determinarlo envía un mensaje descriptivo a la aplicación. En caso contrario utilizará un mensaje genérico.
- **Poscondición**: La aplicación es informada del error.
- **Excepciones**: No se plantean excepciones
- **Rendimiento**: Medio
- **Frecuencia**: Baja
- **Importancia**: Media
- **Urgencia**: Media
- **Estado**: Completo
- **Estabilidad**: Estable

RF-8: Interacción directa con ``gpio-admin``
--------------------------------------------

- **Versión**: 1
- **Autores**: Diego Martín
- **Fuentes**: Análisis preliminar
- **Objetivos asociados**: OBJ-1
- **Requisitos asociados**: IRQ-1
- **Descripción**: La herramienta ``gpio-admin`` puede ser utilizada de forma directa por el usuario, de la misma forma que la biblioteca interactúa con ella.
- **Precondición**: El usuario debe haber iniciado sesión en el sistema.
- **Secuencia normal**:

    1. El usuario ejecuta la herramienta, utilizando los parámetros de la línea de comandos para indicar la acción a realizar.
    2. La biblioteca ejecuta la acción y muestra los resultados de éxito o error. 
- **Poscondición**: La operación a ejecutar se ha llevado a cabo.
- **Excepciones**: En caos de que se dé algún tipo de error, la biblioteca mostrará un mensaje informativo.
- **Rendimiento**: Alto
- **Frecuencia**: Alta
- **Importancia**: Alta
- **Urgencia**: Media
- **Estado**: Completo
- **Estabilidad**: Estable

Vista de casos de uso
---------------------

.. toctree::
    :maxdepth: 2

    uc

.. 
    - **Versión**: 
    - **Autores**: 
    - **Fuentes**: 
    - **Objetivos asociados**: 
    - **Requisitos asociados**: 
    - **Descripción**
    - **Precondición**
    - **Secuencia normal**
    - **Poscondición**
    - **Excepciones**
    - **Rendimiento**
    - **Frecuencia**
    - **Importancia**
    - **Urgencia**
    - **Estado**
    - **Estabilidad**
    - **Comentarios**