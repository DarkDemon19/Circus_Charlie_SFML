#include <iostream>
#include "SFML/Graphics.hpp"

class Obstaculo : public sf::Drawable
{
private:
    sf::Sprite spriteSuperior;
    sf::Sprite spriteInferior;

public:
    Obstaculo(sf::Texture &, int, int);
    void Actualizar();
    bool Colision(sf::IntRect);
    sf::Vector2f GetPosicion();
    virtual void draw(sf::RenderTarget &, sf::RenderStates) const;
};