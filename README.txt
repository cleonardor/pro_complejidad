pro_complejidad
===============

proyecto de complejidad y optimización, Univeresidad del Valle - Semestre II 2012

Presentado por:
Yerminson Doney Gonzalez Muñoz, código 0843846
Edwin Fernando Muñoz Delgado, código 0910398
Crsitian Leonardo Ríos López, código 0842139
Erika Suárez Valencia, código 0743588

^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
*Estructura de carpetas
>carpeta principal:
  readme.txt
 >informe: Contiene el informe del proyeto
   informe.pdf
 >fuentes: Contiene los archivos con el código fuente de la aplicación
   board.h
   board.cpp
   branchandbound.h
   branchandbound.cpp
   canvas.h
   canvas.cpp
   city.h
   city.cpp
   constraintsmanager.h
   constraintsmanager.cpp
   main.cpp
   mainwindow.h
   mainwindow.cpp
   resources.qrc
   solution.h
   solution.cpp
   solver.h
   solver.cpp
  >images: Contiene imagenes utilizadas en la aplicación
    city3.png
    fileopen.png
    filesave.png
    recycle.jpeg
    run.png
 >pruebas: Contiene los archivos de ejemplo utilizados para las pruebas
   prueba.txt
   prueba2.txt
   prueba3.txt
   prueba4.txt
   prueba5.txt
   prueba6.txt
   prueba7.txt
   sample.txt
   sample2.txt
   sample3.txt
   sample4.txt

^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
*Requerimientos del software

-Qt versión 4.8
-lpsolve versión 5.5.0 o superior

^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
*Para ejecutar, desde una consola:

1. qmake -makefile
2. make
3. ./pro_complejidad

^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
******Instalación libreria lpsolve (ubuntu)

-utilice el siguiente comando:
# sudo apt-get install liblpsolve55-dev

-verifique lo siguiente:
-- en la ruta /usr/include/lpsolve/ deben haber varios .h en especial lp_lib.h
-- debe de existir /usr/lib/lp_solve/liblpsolve55

-se debe actualizar la cache de las librerias
--verifique lo siguiente
--- que exista el archivo /etc/ld.so.conf y que contenga "include /etc/ld.so.conf.d/*.conf" sin las comillas

--cree el archivo /etc/ld.so.conf.d/lpsolve.conf y escriba "/usr/lib/lp_solve/" sin las comillas

--ejecute el comando:
# sudo ldconfig

--verfique que la libreria ahora existe en la caché, use el siguiente comando para listar
# ldconfig -p
