# Circus_Charlie_SFML
Proyecto de Programación para diseñar un videoVideojuego 2D inspirado en Circus Charlie de NES




# Circus Charlie Game

Este proyecto es una implementación simple del videojuego **Circus Charlie** en C, utilizando la biblioteca SFML, inspirado en la mecánica de **Flappy Bird**. El juego presenta un payaso que el jugador controla para realizar saltos acrobáticos a través de aros de fuego que se desplazan de manera similar a las tuberías de Flappy Bird. Al igual que en Flappy Bird, el objetivo es evitar los obstáculos, pero en este caso, los aros deben ser atravesados sin tocarlos. El juego aumenta de dificultad progresivamente, con los aros moviéndose más rápido y cambiando de altura, ofreciendo un desafío continuo al jugador.

## Estructura del Proyecto

La estructura del proyecto es la siguiente:

- **bin**: Almacena los archivos ejecutables generados tras la compilación del código fuente.
- **docs**: Contiene toda la documentación relacionada con el proyecto, incluyendo instrucciones y detalles técnicos.
- **include**: Guarda los archivos de encabezado (.hpp) que declaran las interfaces y estructuras de las clases del proyecto.
- **src**: Agrupa los archivos fuente (.cpp) que implementan la lógica y funcionalidades del proyecto.
- **Makefile**: Documento que define las reglas y comandos para compilar y ejecutar el proyecto de forma eficiente.

## Diagrama de Clases

El diagrama de clases del proyecto incluye las siguientes clases:

- **Manolo**: Representa al payaso protagonista en el videojuego, encargado de realizar los saltos acrobáticos a través de los aros de fuego.
- **Obstaculo**: Representa los aros de fuego que el payaso debe evitar al realizar sus saltos acrobáticos durante el juego.
- **Videojuego**: Se encarga de gestionar la lógica principal del juego, incluyendo la interacción del jugador, el seguimiento del puntaje y el control de los obstáculos.

## Integrantes:

    Luis Daniel Moreno Ortiz 20110074
   

## Compilación y Ejecución

Para compilar y ejecutar el proyecto, simplemente ingresa el siguiente comando en la terminal:

    make runmain

En caso de que surjan problemas al ejecutar el juego, intenta los siguientes comandos para limpiar los archivos generados y recompilar:

    make clean 
    make runmain


# Capturas de pantalla 
![image-1](https://github.com/user-attachments/assets/905812df-5de6-417c-a725-869d79144b0a)
![image](https://github.com/user-attachments/assets/e8abe056-bf30-4752-9654-99f1f9048909)
