#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class Manolo : public sf::Drawable // Clase Manolo de personaje principal
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
    Manolo(int, int);
    void Actualizar();
    void Saltar();
    void Muerte();
    bool ObtenerVida();
    sf::Vector2f ObtenerPosicion();
    void Iniciado();
    virtual void draw(sf::RenderTarget &, sf::RenderStates) const;
};