#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>
using namespace std;
#pragma once

// Factor de escala para convertir entre Box2D (metros) y SFML (pixeles)
const float SCALE = 30.0f;

class Personaje {
public:
    Personaje(b2World& mundo, sf::Vector2f position, sf::Color color) {
        // Crear el cuerpo dinámico en Box2D
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(position.x / SCALE, position.y / SCALE);
        body = mundo.CreateBody(&bodyDef);

        // Crear una forma cuadrada para el personaje
        b2PolygonShape boxShape;
        boxShape.SetAsBox(25.0f / SCALE, 25.0f / SCALE); // Tamaño ajustado para Box2D

        // Agregar la forma al cuerpo
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &boxShape;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.5f;
        body->CreateFixture(&fixtureDef);

        // Crear representación visual con SFML
        shape.setSize(sf::Vector2f(50, 50)); // Tamaño en píxeles
        shape.setOrigin(25, 25); // El origen está al centro
        shape.setFillColor(color);
        shape.setPosition(position);
    }

    void move(float offsetX, float offsetY) {
        // Aplicar un impulso lineal en Box2D
        body->ApplyLinearImpulse(b2Vec2(offsetX, offsetY), body->GetWorldCenter(), true);
    }

    void update() {
        // Sincronizar posición del rectángulo SFML con el cuerpo de Box2D
        b2Vec2 position = body->GetPosition();
        shape.setPosition(position.x * SCALE, position.y * SCALE);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }

private:
    sf::RectangleShape shape;
    b2Body* body;
};

int main() {
    // Configurar la ventana SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "Manolo puede brincar");

    // Crear el mundo de Box2D
    b2Vec2 gravity(0.0f, 10.0f); // Gravedad hacia abajo
    b2World mundo(gravity);

    // Crear el suelo estático
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(400.0f / SCALE, 550.0f / SCALE); // Posición en metros
    b2Body* groundBody = mundo.CreateBody(&groundBodyDef);

    b2PolygonShape groundBox;
    groundBox.SetAsBox(400.0f / SCALE, 10.0f / SCALE); // Tamaño del suelo en metros

    b2FixtureDef groundFixtureDef;
    groundFixtureDef.shape = &groundBox;
    groundFixtureDef.friction = 1.0f;
    groundBody->CreateFixture(&groundFixtureDef);

    // Crear al personaje `Manolo`
    Personaje manolo(mundo, sf::Vector2f(400, 500), sf::Color::Blue); // Azul y cerca del suelo

    // Bucle principal
    bool saltando = false;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Control del personaje
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            manolo.move(-0.5f, 0.0f); // Mover a la izquierda
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            manolo.move(0.5f, 0.0f); // Mover a la derecha
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            if (!saltando)
            {
                saltando = true;
                manolo.move(0.0f, -40.0f); // Saltar
            }
        }

        // Actualizar física del mundo
        mundo.Step(1.0f / 60.0f, 6, 2);

        // Actualizar al personaje
        manolo.update();

        // Dibujar en la ventana
        window.clear();

        // Dibujar el suelo
        sf::RectangleShape suelo(sf::Vector2f(800, 20)); // Tamaño del suelo en píxeles
        suelo.setOrigin(400, 10);
        suelo.setPosition(groundBody->GetPosition().x * SCALE, groundBody->GetPosition().y * SCALE);
        suelo.setFillColor(sf::Color::White);
        window.draw(suelo);

        // Dibujar al personaje
        manolo.draw(window);

        // Mostrar ventana
        window.display();
    }

    return 0;
}
