#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Manolo.hpp"
#include "Sonido.hpp"
#include "Variacion_de_posicion.hpp"

class Videojuego
{
public:
    Videojuego() {}
    ~Videojuego() {}
    void Ventana();
};

void Videojuego::Ventana()
{
    sf::Texture fondoTextura;
    sf::Sprite fondo;

    if (fondoTextura.loadFromFile("assets/image/fondo.png"))
    {
        std::cout << "Error al cargar la textura" << std::endl;
    }

    fondo.setTexture(fondoTextura);
    fondo.setPosition(0, -15);
    fondo.setScale(1.5f, 1.5f);

    bool inciado;
    bool presionado;

    sf::RenderWindow ventana(sf::VideoMode(400, 700), "Flappy Manolo");
    ventana.setFramerateLimit(60);

    presionado = false;

    //Sonido sonido;
    
    sf::Music punto;
    punto.openFromFile("assets/music/assets_music_musica.ogg");
    punto.play();

    while (ventana.isOpen())
    {
        Manolo *manolo = new Manolo(210, 350);
        Variacion_de_posicion *variacion_de_posicion = new Variacion_de_posicion();
        inciado = false;
        Sonido *sonido = new Sonido();
        sonido->Incializado(false);
        while (true)
        {
            sf::Event event;
            while (ventana.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    ventana.close();
                    return;
                }
            }
            manolo->Actualizar();
            if (manolo->ObtenerVida())
            {
                variacion_de_posicion->Actualizar();
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !presionado)
                {
                    manolo->Saltar();
                    presionado = true;
                    sonido->Aleteo();
                    if (!inciado)
                    {
                        inciado = true;
                        manolo->Iniciado();
                        variacion_de_posicion->Iniciado();
                        sonido->Incializado(true);
                    }
                }
            }
            else
            {
                sonido->GameOver();
            }

            if (!manolo->ObtenerVida() && sf::Mouse::isButtonPressed(sf::Mouse::Left) && !presionado)
            {
                presionado = true;
                break;
            }

            sf::IntRect rect(manolo->ObtenerPosicion().x - 23, manolo->ObtenerPosicion().y - 21, 44, 40);

            if (variacion_de_posicion->Colision(rect))
            {
                manolo->Muerte();
            }

            if (manolo->ObtenerPosicion().y < 0 || manolo->ObtenerPosicion().y > 700 - 136)
            {
                manolo->Muerte();
            }

            if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                presionado = false;
            }

            sonido->DefinirPuntaje(variacion_de_posicion->Puntaje());
            ventana.clear();
            ventana.draw(fondo);
            ventana.draw(*variacion_de_posicion);
            ventana.draw(*manolo);
            ventana.draw(*sonido);
            ventana.display();
        }
        delete manolo;
        delete variacion_de_posicion;
        delete sonido;
    }
    return;
}