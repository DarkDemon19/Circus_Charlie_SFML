#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <fstream>

class Audio : public sf::Drawable
{
private:
    sf::SoundBuffer *puntosManolo;
    sf::SoundBuffer golpeManolo;
    sf::SoundBuffer aleteoManolo;
    sf::Music punto;
    sf::Sound aleteo;
    sf::Sound golpe;
    sf::Music musica;
    sf::Font fuente;
    sf::Text maxPuntajeT;
    sf::Text puntajeT;
    int maxPuntaje;
    int puntaje;
    bool incializado, gameOver;
    sf::Texture gameOverT;
    sf::Sprite gameOverS;
    sf::Texture incializadoTextura;
    sf::Sprite incializadoSprite;

public:
    Audio();
    void DefinirPuntaje(int);
    void Incializado(bool);
    void GameOver();
    void Aleteo();
    virtual void draw(sf::RenderTarget &, sf::RenderStates) const;
};