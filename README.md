pro_complejidad
===============

proyecto de complejidad y optimización, Univeresidad del Valle - Semestre II 2012

******Instalas librerias(ubuntu)

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
