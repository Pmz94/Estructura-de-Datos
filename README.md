# Estructura de Datos escritos en lenguaje C.

Estos codigos se corren en consola, necesitaras un compilador.

### Para Windows

En este ejemplo usare el TCC (portable).

Guarde los archivos dentro de la carpeta del compilador.

Para correr los programas abra la consola, vaya a la carpeta del compilador:

```> cd C:/User/Documents/TCC```

Luego corra los sig. comandos:

```> tcc -o archivo archivo.c```

```> tcc archivo.c```

```> archivo.exe```

### Para Linux

En este ejemplo usare un compilador GNU C/C++ con otras herramientas relacionadas que ya vienen en Linux.

Para instalar todo esto escriba en la terminal:

```$ sudo apt update```

```$ sudo apt install build-essential manpages-dev```

Ya que tenga lo anterior, vaya a la carpeta donde tenga los archivos:

```$ cd /home/user/estructura-de-datos/```

Luego corra los sig. comandos:

```$ cc archivos/archivo.c -o ejecutables/archivo```

```$ ./ejecutables/archivo```