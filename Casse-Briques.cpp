#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameObject.h"
#include "Math.h"
#include "FileReader.h"
#include "Test.h"
#include "Cannon.h"
#include "Ball.h"
#include "GameManager.h"

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

    //Cannon* o_cannon = new Cannon(50.f, 100.f, 500.f, 500.f, 90.f);
    //Ball* o_ball = new Ball(20.f, 500.f - 10.f, 500.f - 10.f, 300.f);

    //GameObject* o_ball2 = new GameObject(30.f, 100.f, 100.f, 90.f);
    GameObject* o_ball2 = new GameObject(100.f, 100.f, 100.f, 100.f, 90.f);

    //GameObject* o_gameObject5 = new GameObject(200.f, 100.f, 50.f, 70.f, 90.f);

    //GameObject* o_gameObject2 = new GameObject(100.f, 100.f, 100.f, 100.f, 90.f);
    //GameObject* o_gameObject7 = new GameObject(100.f, 100.f, 50.f, 150.f, 90.f);

    //GameObject* o_gameObject3 = new GameObject(100.f, 100.f, 1400.f, 300.f, 90.f);
    GameObject* o_gameObject3 = new GameObject(20.f, 1400.f, 300.f, 90.f);

    //GameObject* o_gameObject3 = new GameObject(50.f, 1400.f, 300.f, 90.f);
    GameObject* o_gameObject4 = new GameObject(100.f, 50.f, 1000.f, 500.f, 90.f);
    //GameObject* o_gameObject6 = new GameObject(100.f, 100.f, 10.f, 50.f, 90.f);
    GameObject* test = new GameObject(100.f, 100.f, 10.f, 50.f, 90.f);

    std::vector<GameObject*> list = { o_gameObject3, o_gameObject4 };



    Math::Vector2 vector1 = Math::Vector2(2.f, 1.f);
    Math::Vector2 vector2 = Math::Vector2(-1.f, -1.f);

    vector1.normalizeVector();
    vector2.normalizeVector();

    sf::Vector2i mousePos;
    sf::Vector2i mousePos2;
    o_gameObject3->setVector(-1.f, -1.f);
    //o_gameObject7->setVector(-1.f, -1.f);
    //o_ball->setOriginPointCircle();

    while (window.isOpen())
    {
        // EVENT 
        sf::Event event;
        while (window.pollEvent(event))
        {
            mousePos = sf::Mouse::getPosition(window);

            o_ball2->setPos(mousePos.x, mousePos.y);
            /*Math::Vector2 mouseVector = Math::Vector2::createVector(o_cannon->getPos(), mousePos.x, mousePos.y).getNormalizeVector();*/
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            /*
            if (mouseVector.y < 0 && Math::Vector2::leftVector.getAngle(mouseVector) >= 30 && Math::Vector2::leftVector.getAngle(mouseVector) <= 150)
            {
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    o_cannon->fire(mouseVector, o_ball);
                }
                o_cannon->move(mouseVector);

            }
            o_ball2->setPos(mousePos2.x, mousePos2.y);*/
        }
            // UPDATE
            //o_gameObject3->collide(list);
            //o_gameObject2->moveShape(deltaTime, vector1);
            //o_gameObject3->moveShape(deltaTime, o_gameObject3->getVect());
            //o_gameObject7->moveShape(deltaTime, vector1);

            /*o_ball->collide(list);
            o_ball->moveShape(deltaTime, o_ball->getVect());*/

            o_ball2->collide(list);
            o_ball2->moveShape(deltaTime, o_ball2->getVect());

 /*           test->collide(list);
            test->moveShape(deltaTime, test->getVect());*/
            // DRAW
            window.clear();
            //window.draw(test->getShape());
            //window.draw(o_gameObject2->getShape());
            //window.draw(o_cannon->getShape());
            //window.draw(o_ball->getShape());
            //window.draw(o_gameObject5->getShape());
            window.draw(o_ball2->getShape());
            window.draw(o_gameObject3->getShape());
            window.draw(o_gameObject4->getShape());
            //window.draw(o_gameObject6->getShape());
            //window.draw(o_gameObject7->getShape());
            window.display();
            deltaTime = o_clock.restart().asSeconds();
    }
 }

//void integrationFile()
//{
//    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
//
//    FileReader* o_file = new FileReader();
//
//    GameManager* o_manager = new GameManager(true);
//
//    o_file->readFile("Files/test.txt");
//
//    // EVENT 
//    sf::Event event;
//    while (window.isOpen())
//    {
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//            {
//                window.close();
//            }
//        }
//        window.clear();
//        o_manager->initBrickFromTxt(100.f, 50.f, 20.f, 20.f, 10.f, &window, o_file);
//
//        o_manager->displayBricks(&window, o_manager->_listBricks);
//        window.display();
//    }
//}

void Game()
{
    GameManager::Get()->launchGame();
}

int main()
{
  /*  EventManager::Initialize();
    GameManager::Initialize();
    Game();*/

    //integrationTest();
    integrationGame();
    //integrationFile();



    return 0;
}