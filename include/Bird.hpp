#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class Bird : public sf::Drawable // Clase Bird de personaje principal
{
private:
    bool vida;
    bool iniciado;
    int estado;
    int relojEstado;
    std::vector<sf::Texture> estados;
    sf::Sprite sprite;
    float mover;

public:
    Bird(int, int);
    void Actualizar();
    void Saltar();
    void Muerte();
    bool ObtenerVida();
    sf::Vector2f ObtenerPosicion();
    void Iniciado();
    virtual void draw(sf::RenderTarget &, sf::RenderStates) const;
};