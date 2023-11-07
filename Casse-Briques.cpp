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
}

void integrationGame()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    sf::Clock o_clock;
    float deltaTime = 0.f;

    GameObject o_gameObject = GameObject(100.f, 100.f, 100.f, 100.f, 90.f);
    GameObject o_gameObject2 = GameObject(50.0, 100.f, 100.f, 90.f);
    GameObject o_gameObject3 = GameObject();
    GameObject o_gameObject4 = GameObject(100.f, 100.f, 1000.f, 50.f, 90.f);
    std::vector<GameObject> list = { o_gameObject,o_gameObject4 };
    o_gameObject.setOriginPointOnBase();

    std::vector<float> direction = Math::transformVector2ToVector(Math::normalizeVector(Math::Vector2(1.f, 1.f)));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
               // UPDATE
              o_gameObject2.moveShape(deltaTime, Math::normalizeVector({ 1.f, 1.f }));
              //o_gameObject.rotateShape(deltaTime, 45.f);
              o_gameObject3.moveShape(deltaTime, Math::normalizeVector({ 2.f, 0 }));

              // DRAW
              window.clear();
              window.draw(o_gameObject2.getShape());
              window.draw(o_gameObject.getShape());
              window.draw(o_gameObject3.getShape());
              window.draw(o_gameObject4.getShape());
              window.display();
              o_gameObject3.collide(list);
              deltaTime = o_clock.restart().asSeconds();
            // EVENT 
            if (event.type == sf::Event::Closed)
            {
                window.close();        
      }
  }
 }

int main()
{
    integrationTest();
    //integrationGame();

    return 0;
}