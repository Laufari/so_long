#so_long

Es un juego 2D en C usando MiniLibX. 
El objetivo es recolectar objetos y llegar a la salida evitando obstáculos, con el menor número de movimientos posible.

Características

Gráficos con MiniLibX.
Movimiento con W, A, S, D.
Soporte para mapas .ber.

Cierre con ESC o cruz de ventana.

Instalación
MiniLibX:
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux
make
sudo cp mlx.h /usr/include
sudo cp libmlx.a /usr/lib

Clonar y compilar:
git clone https://github.com/tu_usuario/so_long.git
cd so_long
make
./so_long mapas/ejemplo.ber

Controles
WASD - Mover
ESC - Salir

Reglas
Recoger objetos y llegar a la salida.
No atravesar paredes.

Limpieza
make clean   # Borra objetos
make fclean  # Borra objetos y ejecutables

Laura Farina

📧 laufmk@gmail.com | GitHub
