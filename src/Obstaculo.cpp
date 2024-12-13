#include "../include/Obstaculo.hpp"

Obstaculo::Obstaculo(sf::Texture &textura, int x, int y)
{
    spriteSuperior.setTexture(textura);
    spriteInferior.setTexture(textura);
    spriteSuperior.setOrigin(textura.getSize().x,0);
    spriteSuperior.setRotation(180);

    spriteSuperior.setPosition(x,y);
    spriteInferior.setPosition(x,y+150);

    spriteSuperior.setScale(1.5f,1.5f);
    spriteInferior.setScale(1.5f,1.5f);
}

void Obstaculo::Actualizar()
{
    spriteSuperior.move(-2.5f,0);
    spriteInferior.move(-2.5f,0);
}

bool Obstaculo::Colision(sf::IntRect rect)
{
    sf::IntRect rectUp(spriteSuperior.getPosition().x+4,spriteSuperior.getPosition().y-480,70,480);
    sf::IntRect rectDown(spriteInferior.getPosition().x+4,spriteInferior.getPosition().y,70,480);
    if(rectUp.intersects(rect) || rectDown.intersects(rect)) 
    {
    return true;
    }
    return false;
}

sf::Vector2f Obstaculo::GetPosicion()
{
    return spriteSuperior.getPosition();
}

void Obstaculo::draw(sf::RenderTarget &rt, sf::RenderStates rs) const
{
    rt.draw(spriteSuperior,rs);
    rt.draw(spriteInferior,rs);
}