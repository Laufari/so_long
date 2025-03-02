so_long

Descripción

so_long es un pequeño juego 2D desarrollado en C utilizando la librería MiniLibX. 
El objetivo del juego es que el jugador recoja todos los objetos del mapa y llegue a la salida,
evitando las paredes y utilizando la menor cantidad de movimientos posible.

Características

Uso de MiniLibX para la gestión de gráficos.

Movimiento del personaje con W, A, S, D.

Contador de movimientos en la terminal.

Validación del mapa según las reglas establecidas.

Soporte para diferentes diseños de mapa en formato .ber.

Cierre limpio del programa al presionar ESC o al hacer clic en la cruz de la ventana.

Tecnologías Usadas

Lenguaje: C

Librería Gráfica: MiniLibX

Gestor de Compilación: Makefile

Instalación y Ejecución

Requisitos

Sistema operativo basado en Unix.

MiniLibX instalada.

Compilador gcc.

Instalación de MiniLibX

    git clone https://github.com/42Paris/minilibx-linux.git
    cd minilibx-linux
    make
    sudo cp mlx.h /usr/include
    sudo cp libmlx.a /usr/lib

Clonar el repositorio

    git clone https://github.com/tu_usuario/so_long.git
    cd so_long

Compilar el juego

    make

Ejecutar el juego

    ./so_long mapas/ejemplo.ber

Formato del Mapa

El archivo del mapa debe tener la extensión .ber y debe contener los siguientes caracteres:

0 - Espacio vacío.

1 - Pared.

C - Coleccionable.

E - Salida.

P - Posición inicial del jugador.

Ejemplo de un mapa válido:

11111
1P0C1
10001
1C0E1
11111

Controles del Juego

W - Mover hacia arriba.

A - Mover hacia la izquierda.

S - Mover hacia abajo.

D - Mover hacia la derecha.

ESC - Salir del juego.

Reglas del Juego

El jugador debe recolectar todos los objetos antes de salir.

No se puede atravesar paredes.

El mapa debe ser rectangular y estar rodeado de paredes.

Debe existir un camino válido hasta la salida.

Limpieza

Para eliminar los archivos generados por la compilación:

    make clean  # Borra archivos objetos
    make fclean # Borra archivos objetos y ejecutables

Para recompilar completamente:

    make re
    

Autor

👤 Tu Nombre: Laura Farina 📧 Email: laufmk@gmail.com 🔗 LinkedIn🔗 GitHub

