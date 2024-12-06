#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main()
{
    // Crear una ventana de SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "Circus Manolo");

    // Crear una forma ,circular de SFML
    sf::Texture fondoTextura;
    if(!fondoTextura.loadFromFile("./assets/sprites/stage1.png")){
        cout<<"error";
        return -1;
    }
    sf::Texture charlieNormal;
    if(!charlieNormal.loadFromFile("./assets/sprites/CircusCharlieSprite.png")){
        cout<<"error";
        return -1;
    }
    sf::Sprite fondo(fondoTextura);
    //sf::Sprite fondo(charlieNormal);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Verificar si se ha cerrado la ventana
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Limpiar la ventana
        window.clear();

        // Dibujar la forma en la ventana
        window.draw(fondo);

        // Mostrar la ventana
        window.display();
    }

    return 0;
}