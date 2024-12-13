#include "..\include\Sonido.hpp"

Sonido::Sonido()
{
    if (!this->puntosBird->loadFromFile("assets/music/punto.ogg"))
    {
        std::cout << "Error al cargar el sonido" << std::endl;
    }
    if (!golpeBird.loadFromFile("assets/music/golpe.ogg"))
    {
        std::cout << "Error al cargar el sonido" << std::endl;
    }
    if (!aleteoBird.loadFromFile("assets/music/aleteo.ogg"))
    {
        std::cout << "Error al cargar el sonido" << std::endl;
    }
    if (!musica.openFromFile("assets/music/musica.ogg"))
    {
        std::cout << "Error al cargar la musica" << std::endl;
    }
    if (!fuente.loadFromFile("assets/fonts/fuente.ttf"))
    {
        std::cout << "Error al cargar la fuente" << std::endl;
    }
    if (!gameOverT.loadFromFile("assets/image/gameOver.png"))
    {
        std::cout << "Error al cargar la textura" << std::endl;
    }
    if (!incializadoTextura.loadFromFile("assets/image/inicio.png"))
    {
        std::cout << "Error al cargar la textura" << std::endl;
    }
    musica.openFromFile("assets/music/musica.ogg");
    musica.setLoop(true);
    musica.play();

    //punto.setBuffer(puntosBird);
    //aleteo.setBuffer(aleteoBird);
    //golpe.setBuffer(golpeBird);

    puntaje = 0;
    puntajeT.setFont(fuente);
    puntajeT.setCharacterSize(40);
    puntajeT.setString(std::to_string(puntaje));
    puntajeT.setOrigin(puntajeT.getGlobalBounds().width / 2, puntajeT.getGlobalBounds().height / 2);
    puntajeT.setPosition(210, 50);

    std::ifstream in("puntaje");
    in >> maxPuntaje;

    maxPuntajeT.setFont(fuente);
    maxPuntajeT.setCharacterSize(20);
    maxPuntajeT.setString(std::to_string(maxPuntaje));
    maxPuntajeT.setOrigin(maxPuntajeT.getGlobalBounds().width / 2, maxPuntajeT.getGlobalBounds().height / 2);
    maxPuntajeT.setPosition(210, 100);

    gameOverS.setTexture(gameOverT);
    gameOverS.setOrigin(gameOverT.getSize().x / 2, gameOverT.getSize().y / 2);
    gameOverS.setPosition(210, 350);
    gameOverS.setScale(2, 2);

    incializadoSprite.setTexture(incializadoTextura);
    incializadoSprite.setOrigin(incializadoTextura.getSize().x / 2, incializadoTextura.getSize().y / 2);
    incializadoSprite.setPosition(210, 280);
    incializadoSprite.setScale(1.5f, 1.5f);
}
void Sonido::DefinirPuntaje(int p)
{
    //if (puntaje != p) {
    sf::Music punto;
    punto.openFromFile("assets/music/assets_music_punto.ogg");
    punto.play();
    //}
    puntaje = p;
    puntajeT.setString(std::to_string(puntaje));
    puntajeT.setOrigin(puntajeT.getGlobalBounds().width / 2, puntajeT.getGlobalBounds().height / 2);
}
void Sonido::Incializado(bool estado)
{
    incializado = estado;
    puntaje = 0;
    gameOver = false;
    std::ifstream in("puntaje");
    in >> maxPuntaje;
    maxPuntajeT.setString(std::to_string(maxPuntaje));
    maxPuntajeT.setOrigin(maxPuntajeT.getGlobalBounds().width / 2, maxPuntajeT.getGlobalBounds().height / 2);
    puntajeT.setString(std::to_string(puntaje));
    puntajeT.setOrigin(puntajeT.getGlobalBounds().width / 2, puntajeT.getGlobalBounds().height / 2);
}

void Sonido::GameOver()
{
    if (!gameOver)
        golpe.play();
    if (puntaje > maxPuntaje)
    {
        maxPuntaje = puntaje;
        std::ofstream out("puntaje");
        out << puntaje;
    }
    gameOver = true;
}

void Sonido::Aleteo()
{
    aleteo.play();
}

void Sonido::draw(sf::RenderTarget &rt, sf::RenderStates rs) const
{
    if (!incializado)
        rt.draw(incializadoSprite, rs);
    else
    {
        rt.draw(puntajeT, rs);
        rt.draw(maxPuntajeT, rs);
        if (gameOver)
            rt.draw(gameOverS, rs);
    }
}