#include "..\include\Manolo.hpp"

Manolo::Manolo(int x, int y)
{
    vida = true;
    iniciado = false;
    estado = 0;
    relojEstado = 10;
    mover = 0;
    estados.resize(3);
    if (!estados[0].loadFromFile("assets/image/birdArriba.png"))
    {
        std::cout << "Error al cargar la textura" << std::endl;
    }
    if (!estados[1].loadFromFile("assets/image/birdMedio.png"))
    {
        std::cout << "Error al cargar la textura" << std::endl;
    }
    if (!estados[2].loadFromFile("assets/image/birdAbajo.png"))
    {
        std::cout << "Error al cargar la textura" << std::endl;
    }

    sprite.setTexture(estados[estado]);
    sprite.setPosition(x, y);
    sprite.setOrigin(estados[estado].getSize().x / 2, estados[estado].getSize().y / 2);
    sprite.setScale(2, 2);
}

void Manolo::Actualizar()
{
    if (!vida)
    {
        if (sprite.getPosition().y < 700 - 136)
        {
            sprite.move(0, 12);
            sprite.setRotation(sprite.getRotation() + 10);
        }
        return;
    }

    relojEstado--;
    if (relojEstado == 0)
    {
        estado++;
        estado %= (int)estados.size();
        sprite.setTexture(estados[estado]);
        sprite.setOrigin(estados[estado].getSize().x / 2, estados[estado].getSize().y / 2);
        relojEstado = 10;
    }

    if (!iniciado)
        return;
    sprite.move(0, mover);
    mover += 0.5f;

    if (mover > 8 && mover < 10)
    {
        sprite.setRotation(sprite.getRotation() + 4);
    }
}

void Manolo::Saltar()
{
    mover = -8;
    sprite.setRotation(-15);
}

sf::Vector2f Manolo::ObtenerPosicion()
{
    return sprite.getPosition();
}

bool Manolo::ObtenerVida()
{
    return vida;
}

void Manolo::Muerte()
{
    vida = false;
}

void Manolo::Iniciado()
{
    iniciado = true;
}

void Manolo::draw(sf::RenderTarget &rt, sf::RenderStates rs) const
{
    rt.draw(sprite, rs);
}