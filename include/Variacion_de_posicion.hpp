#include <iostream>
#include "SFML/Graphics.hpp"
#include <time.h>
#include "Choques.hpp" 

class Variacion_de_posicion : public sf::Drawable
{
private:
    int ultimo;
    int puntaje;
    bool iniciado;
    sf::Texture choquesT;
    sf::Texture baseT;
    std::vector<sf::Sprite> bases;
    std::vector<Choques> obstaculos;
    int posicionUltimoChoquesPasado;

public:
    Variacion_de_posicion();
    void Actualizar();
    bool Colision(sf::IntRect);
    void Iniciado();
    int Puntaje();
    virtual void draw(sf::RenderTarget &, sf::RenderStates) const;
};