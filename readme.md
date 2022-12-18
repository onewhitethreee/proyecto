# **sistema de gestion de libros**

## Funciones del sistema:

* Registro del usuario
* Iniciar session del usuario
* Buscar el libro de diferente manera,  por nombre/ISBN/auto
* Buscar el libro por genero
* Hacer prestamo del libro
* Volver el libro al sistema.

**REGISTRO DEL USUARIO:** esta función permitiría a los usuarios crear una cuenta en el sistema. Para ello, necesitarían proporcionar su nombre de usuario, contraseña.

**INICIAR SESSION DEL USUARIO:** esta función permitiría a los usuarios iniciar sesión en el sistema utilizando su nombre de usuario y contraseña. Si los datos proporcionados coinciden con los almacenados en el archivo de texto(user.txt), se les permitirá acceder al resto de funcionalidades del programa.

**BUSQUEDA DEL LIBRO:** esta función permitiría a los usuarios buscar libros en el sistema de diferentes maneras. Por ejemplo, podrían buscar por nombre del libro, por el ISBN o por el autor.

**BUSQUEDA DEL LIBRO POR GENERO:** esta funcion se permite que el usuario cuando seleccione, muestra todos los libros que hay en ese genero.


```console
PROYECTO
.
├── code
│   ├── UserLibroPrestado_123456.txt
│   ├── bienvenido.cpp
│   ├── buscarLirpoPorAutorNombreISBN.cpp
│   ├── buscarUnLibroGenero.cpp
│   ├── devolverUnLibro.cpp
│   ├── hacerPrestamoDeLibro.cpp
│   ├── loginn.cpp
│   ├── main
│   ├── main.cpp
│   └── user.txt
├── libro
│   ├── ciencia.csv
│   ├── descargarLibro.py
│   ├── empresa.csv
│   ├── historiaPoliticaSociologia.csv
│   ├── infantil.csv
│   ├── literatura.csv
│   └── todoLibro.csv
├── readme.md
└── subir.bat
```
