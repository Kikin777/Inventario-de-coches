**Inventario de autos**

Este proyecto es un sistema simple para manejar un inventario de autos.
usa una clase base `auto` y clases hijas `sedan`, `suv` y `deportivo`.
también usa la clase `motor` y la clase `agencia` para mostrar composición.

**Componentes del proyecto**

Diagrama de clases  
    Archivo: `diagrama_clases.png`  
    Muestra:
            - clase auto
            - clases sedan, suv y deportivo con herencia
            - clase motor como composición dentro de auto
            - clase agencia con una lista de autos (agregación)

Implementación en c++  
   Archivo: `autos.cpp`  
   Incluye:
            - clase `motor`
            - clase base `auto`
            - clases hijas `sedan`, `suv`, `deportivo`
            - clase `agencia` para manejar el inventario
            - función `main` que crea autos de ejemplo y muestra el inventario

Repositorio  
   Contiene solo los archivos del proyecto:
     - `AUTOS.cpp`
     - `diagrama_clases.png` 
     - `README.md`





**Correcciones realizadas**

**1. Encapsulamiento de atributos**
**Antes:**  
Todas las clases tenían atributos públicos ('public').  
No había getters ni setters.

**Ahora:**  
Los atributos de `motor`, `auto`, `sedan`, `suv`, `deportivo` y `agencia`
son privados. se agregaron getters y setters para acceder a ellos.

Sub-competencia:  
Implementación de acciones (SICT0303 / SING0303A)  
Aplicación de estándares y normas (SICT0401 / SING0401A)  
Dónde está:  
En `autos.cpp`, definición de todas las clases.


### 2. uso de constructores con valores iniciales
**Antes:** 
Muchas variables no se inicializaban en el constructor.

**Ahora:**  
Todas las clases tienen constructor por defecto y constructor con parámetros.
Se da un valor inicial a las variables.

Sub-competencia:
Implementación de acciones (SICT0303 / SING0303A)  
Dónde está: 
En `autos.cpp`, constructores de `motor`, `auto`, `sedan`, `suv`, `deportivo` y `agencia`.

**3. Herencia correcta y método sobreescrito**
**Antes:**  
Ya existía herencia, pero solo se usaba el método `mostrar` sin explicar bien
el diseño.

**Ahora:**  
`auto` tiene el método virtual `mostrarInfo` y cada clase hija
(`sedan`, `suv`, `deportivo`) lo sobreescribe para mostrar su atributo extra
(puertas, tracción 4x4, 0–100).

sub-competencia:  
toma de decisiones en el diseño (SICT0302 / SING0302A)  
implementación de acciones (SICT0303 / SING0303A)  
dónde está:  
en `autos.cpp`, métodos `mostrarInfo` de `auto`, 'sedan, `suv`, `deportivo`.

**4. composición y agregación**
**Antes:**  
El motor estaba como struct simple y la relación con las clases no estaba
clara en el diagrama.

**Ahora:**  
`auto` tiene un objeto `motor` como parte interna (composición).  
`agencia` tiene un `vector<Auto*>` que guarda varios autos (agregación).  
El diagrama se actualizó para usar los símbolos correctos de uml.

Sub-competencia:  
Toma de decisiones (SICT0302 / SING0302A)  
Implementación de acciones (SICT0303 / SING0303A)  
Dónde está:  
en `autos.cpp` (atributo `motor` en `auto` y vector en `agencia`) 
en `diagrama_clases.png` con las flechas y rombos estándar.

**5. aplicación del estándar de codificación visto en la primera clase**
**Antes:**  
- No había bloque de comentarios al inicio del archivo.  
- No había comentarios en los métodos.  
- Algunos nombres no seguían camelCase/pascalCase.  
- El archivo no seguía por completo el estándar del curso.

**Ahora:**  
- Se agregó un comentario inicial con descripción, autor y fecha.  
- Cada método tiene un comentario breve que explica qué hace.  
- Las clases usan pascalCase (`Auto`, `Sedan`, etc.)  
- Las funciones y variables usan camelCase (`calcularAutonomia`,
  `mostrarInventario`, `ceroACien`, etc.).  
- No se usan acentos ni letra ñ en los identificadores.

Sub-competencia:  
Aplicación de estándares y normas (SICT0401 / SING0401A)  
Dónde está:  
En `autos.cpp` y en `README.md`.


**6. Uso de github y organización del repositorio**
**antes:**  
El repositorio no tenía `README.md` y tenía archivos que no eran parte
del proyecto (por ejemplo, carpetas de configuración).

**Ahora:**  
- Se agregó este `README.md` que explica el proyecto y las correcciones.  
- Se limpió el repositorio para dejar solo los archivos del proyecto.  
- Se usan commits para guardar los avances.

Sub-competencia:  
Tecnologías de vanguardia (SEG0702A / SICT0702A)  
Dónde está:  
En el repositorio de github y en el archivo `README.md`.


