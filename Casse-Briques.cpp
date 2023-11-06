#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameObject.h"
#include "Math.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    sf::Clock o_clock;
    float deltaTime = 0.f;

    GameObject o_gameObject = GameObject(100.f, 100.f, 50.f, 50.f, 90.f);
    GameObject o_gameObject2 = GameObject(50.0, 100.f, 100.f, 90.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            while (true)
            {

                // EVENT 
                if (event.type == sf::Event::Closed)
                {
                    window.close();

                }

                // UPDATE
                o_gameObject.moveShape(deltaTime, Math::normalizeVector({ 1.f, 1.f }));

                // DRAW
                window.clear();
                window.draw(o_gameObject2.getShape());
                window.draw(o_gameObject.getShape());
                window.display();

                deltaTime = o_clock.restart().asSeconds();
            }

        }
    }
    return 0;
}