#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Bird.hpp"
#include "Sonido.hpp"
#include "Paralaje.hpp"

class Juego
{
public:
    Juego() {}
    ~Juego() {}
    void Ventana();
};

void Juego::Ventana()
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

    sf::RenderWindow ventana(sf::VideoMode(400, 700), "Flappy Bird");
    ventana.setFramerateLimit(60);

    presionado = false;

    //Sonido sonido;
    
    sf::Music punto;
    punto.openFromFile("assets/music/assets_music_musica.ogg");
    punto.play();

    while (ventana.isOpen())
    {
        Bird *bird = new Bird(210, 350);
        Paralaje *paralaje = new Paralaje();
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
            bird->Actualizar();
            if (bird->ObtenerVida())
            {
                paralaje->Actualizar();
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !presionado)
                {
                    bird->Saltar();
                    presionado = true;
                    sonido->Aleteo();
                    if (!inciado)
                    {
                        inciado = true;
                        bird->Iniciado();
                        paralaje->Iniciado();
                        sonido->Incializado(true);
                    }
                }
            }
            else
            {
                sonido->GameOver();
            }

            if (!bird->ObtenerVida() && sf::Mouse::isButtonPressed(sf::Mouse::Left) && !presionado)
            {
                presionado = true;
                break;
            }

            sf::IntRect rect(bird->ObtenerPosicion().x - 23, bird->ObtenerPosicion().y - 21, 44, 40);

            if (paralaje->Colision(rect))
            {
                bird->Muerte();
            }

            if (bird->ObtenerPosicion().y < 0 || bird->ObtenerPosicion().y > 700 - 136)
            {
                bird->Muerte();
            }

            if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                presionado = false;
            }

            sonido->DefinirPuntaje(paralaje->Puntaje());
            ventana.clear();
            ventana.draw(fondo);
            ventana.draw(*paralaje);
            ventana.draw(*bird);
            ventana.draw(*sonido);
            ventana.display();
        }
        delete bird;
        delete paralaje;
        delete sonido;
    }
    return;
}