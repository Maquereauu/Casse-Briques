#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameObject.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");

    GameObject o_gameObject = GameObject(100.f, 100.f, 50.f, 50.f);
    GameObject o_gameObject2 = GameObject(50.0, 100.f, 100.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();

            }
            window.clear();
            window.draw(o_gameObject2.getShape());
            window.draw(o_gameObject.getShape());
            window.display();
        }
    }
    return 0;
}