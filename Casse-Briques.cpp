#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameObject.h"
#include "Math.h"
#include "FileReader.h"
#include "Test.h"

void integrationTest()
{
    Test o_test = Test();

    o_test.fileReader();
    o_test.normalizeVector();
    o_test.scalarProduct();
    o_test.getAngle();
}

void integrationGame()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    sf::Clock o_clock;
    float deltaTime = 0.f;

    GameObject* o_gameObject = new GameObject(100.f, 100.f, 100.f, 100.f, 90.f);
    GameObject* o_gameObject5 = new GameObject(200.f, 100.f, 50.f, 70.f, 90.f);


    GameObject* o_gameObject2 = new GameObject(50.0, 100.f, 100.f, 90.f);
    GameObject* o_gameObject3 = new GameObject();
    GameObject* o_gameObject4 = new GameObject(100.f, 100.f, 1000.f, 50.f, 90.f);

    std::vector<GameObject*> list = { o_gameObject,o_gameObject4 };

    o_gameObject->setOriginPointOnBase();

    Math::Vector2 vector1 = Math::Vector2(2.f, 1.f);
    Math::Vector2 vector2 = Math::Vector2(1.f, 0.f);

    vector1.normalizeVector();
    vector2.normalizeVector();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // EVENT 
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
            // UPDATE
            o_gameObject2->moveShape(deltaTime, vector1);
            o_gameObject->rotateShape(deltaTime, 45.f);
            o_gameObject3->moveShape(deltaTime, vector2);

            // DRAW
            window.clear();
            window.draw(o_gameObject2->getShape());
            window.draw(o_gameObject->getShape());
            window.draw(o_gameObject5->getShape());
            window.draw(o_gameObject3->getShape());
            window.draw(o_gameObject4->getShape());
            window.display();
            o_gameObject3->collide(list);
            deltaTime = o_clock.restart().asSeconds();
    }
 }

int main()
{
    integrationTest();
    //integrationGame();

    return 0;
}