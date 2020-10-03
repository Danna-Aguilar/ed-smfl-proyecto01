#include<iostream>
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

#include "Inputs.hh"
#include "Character.hh"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define GAME_NAME "Roguelike game"
#define TILES1 "assets/sprites/tiles1.png"
#define TILES2 "assets/sprites/tiles2.png"
#define TILES3 "assets/sprites/tiles3.png"
#define SPRITE_SCALE 4.f
#define FPS 120
#define PLAYER_MOVESPEED 3.0f

int main()
{
    //esto es la ventana de tu grafico
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_NAME);
    //aqui vas a guardar los eventos dentro de la ventana, eje: teclado, mouse, etc.
    sf::Event event;

    //physics declaration
    b2Vec2* gravity{new b2Vec2(0.f, 0.f)};
    b2World* world{new b2World(*gravity)}; 

    sf::Clock* clock{new sf::Clock()};
    float deltaTime{};

    window->setFramerateLimit(FPS);
    //Game inputs
    Inputs* inputs{new Inputs()};
    //Textures
    sf::Texture* tilesTexture1{new sf::Texture()};
    tilesTexture1->loadFromFile(TILES1);
    sf::Texture* tilesTexture2{new sf::Texture()};
    tilesTexture2->loadFromFile(TILES2);
    sf::Texture* tilesTexture3{new sf::Texture()};
    tilesTexture3->loadFromFile(TILES3);

    const float tileBaseWidth{16 * SPRITE_SCALE};
    const float tileBaseHeight{16 * SPRITE_SCALE};

    //TILES

    sf::Sprite* tileWall_1_1{new sf::Sprite(*tilesTexture3, *(new sf::IntRect(16 * 1, 16 * 1, 16, 16)))};
    tileWall_1_1->setScale(SPRITE_SCALE, SPRITE_SCALE);

    sf::Sprite* tileWall_1_2{new sf::Sprite(*tilesTexture3, *(new sf::IntRect(16 * 1, 16 * 2, 16, 16)))};
    tileWall_1_2->setScale(SPRITE_SCALE, SPRITE_SCALE);
 
    sf::Sprite* tileWall_1_3{new sf::Sprite(*tilesTexture3, *(new sf::IntRect(16 * 1, 16 * 3, 16, 16)))};
    tileWall_1_3->setScale(SPRITE_SCALE, SPRITE_SCALE);

     sf::Sprite* tileWall_1_7{new sf::Sprite(*tilesTexture3, *(new sf::IntRect(16 * 2, 16 * 2, 16, 16)))};
    tileWall_1_7->setScale(SPRITE_SCALE, SPRITE_SCALE);

    sf::Sprite* tileWall_1_8{new sf::Sprite(*tilesTexture3, *(new sf::IntRect(16 * 2, 16 * 3, 16, 16)))};
    tileWall_1_8->setScale(SPRITE_SCALE, SPRITE_SCALE);                    //horiz            //vert

    sf::Sprite* tileGround_1_4{new sf::Sprite(*tilesTexture3, *(new sf::IntRect(16 * 1, 16 * 4, 16, 16)))};
    tileGround_1_4->setScale(SPRITE_SCALE, SPRITE_SCALE);

    //fuegoazul
    sf::Sprite* tileGround_1_9{new sf::Sprite(*tilesTexture3, *(new sf::IntRect(16 * 4, 16 * 4, 16, 16)))};
    tileGround_1_9->setScale(SPRITE_SCALE, SPRITE_SCALE);
    sf::Sprite* tileGround_1_99{new sf::Sprite(*tilesTexture3, *(new sf::IntRect(16 * 4, 16 * 3, 16, 16)))};
    tileGround_1_99->setScale(SPRITE_SCALE, SPRITE_SCALE);

    //fuegorojo
     sf::Sprite* tileGround_1_88{new sf::Sprite(*tilesTexture3, *(new sf::IntRect(16 * 4, 16 * 1, 16, 16)))};
    tileGround_1_88->setScale(SPRITE_SCALE, SPRITE_SCALE);
    sf::Sprite* tileGround_1_888{new sf::Sprite(*tilesTexture3, *(new sf::IntRect(16 * 4, 16 * 2, 16, 16)))};
    tileGround_1_888->setScale(SPRITE_SCALE, SPRITE_SCALE);

    sf::Sprite* tileGround_2_4{new sf::Sprite(*tilesTexture3, *(new sf::IntRect(16 * 2, 16 * 4, 16, 16)))};
    tileGround_2_4->setScale(SPRITE_SCALE, SPRITE_SCALE);

    //poste
    sf::Sprite* tileGround_2_55{new sf::Sprite(*tilesTexture3, *(new sf::IntRect(16 * 5, 16 * 5, 16, 16)))};
    tileGround_2_55->setScale(SPRITE_SCALE, SPRITE_SCALE);
    sf::Sprite* tileGround_2_555{new sf::Sprite(*tilesTexture3, *(new sf::IntRect(16 * 5, 16 * 6, 16, 16)))};
    tileGround_2_555->setScale(SPRITE_SCALE, SPRITE_SCALE);
      sf::Sprite* tileGround_2_5555{new sf::Sprite(*tilesTexture3, *(new sf::IntRect(16 * 5, 16 * 7, 16, 16)))};
    tileGround_2_5555->setScale(SPRITE_SCALE, SPRITE_SCALE);


    sf::Sprite* tileGround_3_4{new sf::Sprite(*tilesTexture3, *(new sf::IntRect(16 * 3, 16 * 4, 16, 16)))};
    tileGround_3_4->setScale(SPRITE_SCALE, SPRITE_SCALE);

    sf::Sprite* tileGround_1_5{new sf::Sprite(*tilesTexture3, *(new sf::IntRect(16 * 1, 16 * 5, 16, 16)))};
    tileGround_1_5->setScale(SPRITE_SCALE, SPRITE_SCALE);

    sf::Sprite* tileGround_2_5{new sf::Sprite(*tilesTexture3, *(new sf::IntRect(16 * 2, 16 * 5, 16, 16)))};
    tileGround_2_5->setScale(SPRITE_SCALE, SPRITE_SCALE);

    sf::Sprite* tileGround_3_5{new sf::Sprite(*tilesTexture3, *(new sf::IntRect(16 * 3, 16 * 5, 16, 16)))};
    tileGround_3_5->setScale(SPRITE_SCALE, SPRITE_SCALE);

    sf::Sprite* tileGround_1_6{new sf::Sprite(*tilesTexture3, *(new sf::IntRect(16 * 1, 16 * 6, 16, 16)))};
    tileGround_1_6->setScale(SPRITE_SCALE, SPRITE_SCALE);

    sf::Sprite* tileGround_2_6{new sf::Sprite(*tilesTexture3, *(new sf::IntRect(16 * 2, 16 * 6, 16, 16)))};
    tileGround_2_6->setScale(SPRITE_SCALE, SPRITE_SCALE);

    sf::Sprite* tileGround_3_6{new sf::Sprite(*tilesTexture3, *(new sf::IntRect(16 * 3, 16 * 6, 16, 16)))};
    tileGround_3_6->setScale(SPRITE_SCALE, SPRITE_SCALE);

    //w = tileWall_1_1  q = tileWall_1_2    e =  tileWall_1_3   

    //g = tileGround_1_4    f = tileGround_2_4  d = tileGround_3_4
      sf::Sprite* treasureSprite{new sf::Sprite(*tilesTexture3, *(new sf::IntRect(16 * 19, 16 * 19, 16, 16)))};
    treasureSprite->setScale(SPRITE_SCALE, SPRITE_SCALE);
    treasureSprite->setPosition(400, 400);

    BoxCollider* treasureCollider = new BoxCollider(300, 250, new sf::Color(0, 255, 0, 255), 16, 16,
    new Rigidbody(world, b2BodyType::b2_staticBody, new b2Vec2(400, 400), tileBaseWidth / 2, tileBaseHeight / 2, 1, 0, 0),
    treasureSprite);

    treasureCollider->GetBoxShape()->setScale(SPRITE_SCALE, SPRITE_SCALE);

    treasureCollider->GetBoxShape()->setPosition(treasureSprite->getPosition());

  char** tiles 
    {
        new char*[10]
        {
            new char[13]{'w', 'q', 'e', 'p', 'z', 'x', '1', 'q', 'e', 'p', 'z', 'w','w'},
            new char[13]{'g', 'g', 'd', 'g', 'g', 'm', '2', 'g', 'd', 'b', 'c', 'k','g'},
            new char[13]{'g', 'a', 'b', 'c', 'k', 'l', 'g', 'g', 'g', 'g', 'g', 'g','g'},
            new char[13]{'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g','g'},
            new char[13]{'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g','f'},
            new char[13]{'g', 'b', 'c', 'k', 'l', 'g', 'g', 'g', 'g', 'g', 'g', 'g','g'},
            new char[13]{'g', 'g', 'g', 'g', 'g', 'g', 'n', 'g', 'g', 'g', 'g', 'g','g'},
            new char[13]{'g', 'g', 'g', 'g', 'g', 'g', 'b', 'c', 'k', 'l', 'g', 'g','g'},
            new char[13]{'a', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'n','g'},
            new char[13]{'g', 'f', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g','g'}
        }
    };
//n : escalera 
    std::vector<sf::Sprite> maze;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 13; j++)
        {
            char& tile = *(*(tiles + i) + j);

            switch (tile)
            {
                case 'w':
                    maze.push_back(*tileWall_1_1);
        
                    break;
                case 'q':
                    maze.push_back(*tileWall_1_2);
            
                    break;
                case 'e':
                    maze.push_back(*tileWall_1_3);
                   
                    break;
                case 'g':
                    maze.push_back(*tileGround_1_4);
                   
                    break;
                case 'f':
                    maze.push_back(*tileGround_2_4);
                  
                    break;
                case 'd':
                    maze.push_back(*tileGround_3_4);
                
                    break;       
                case 'a':
                    maze.push_back(*tileGround_1_5);
                
                    break;      
                    case 'b':
                    maze.push_back(*tileGround_2_5);
                
                    break; 
                    case 'c':
                    maze.push_back(*tileGround_3_5);
                
                    break;    
                    case 'k':
                    maze.push_back(*tileGround_1_6);
                
                    break;   
                    case 'l':
                    maze.push_back(*tileGround_2_6);
                
                    break;   
                    case 'n':
                    maze.push_back(*tileGround_3_6);
                
                    break;   
                     case 'p':
                    maze.push_back(*tileWall_1_7);
                
                    break;   
                    case 'z':
                    maze.push_back(*tileWall_1_8);
                
                    break; 
                     case 'm':
                    maze.push_back(*tileGround_1_9);
                
                    break; 
                     case 'x':
                    maze.push_back(*tileGround_1_99);
                    break; 
                    case '1':
                    maze.push_back(*tileGround_1_88);
                    break; 
                    case '2':
                    maze.push_back(*tileGround_1_888);
                    break; 
                     case '3':
                    maze.push_back(*tileGround_2_55);
                    break; 
                     case '4':
                    maze.push_back(*tileGround_2_555);
                    break; 
                     case '5':
                    maze.push_back(*tileGround_2_5555);
                    break; 

                default:
                    break;
            }
            maze.back().move(tileBaseWidth * j, tileBaseHeight * i);
        }
    }

   //Main player
    Character* character1{new Character(tilesTexture2, 16 * 1, 16 * 5, 16, 16, SPRITE_SCALE, SPRITE_SCALE, world)};
    character1->SetAnimations(
        new Animation*[2]
        {
            new Animation(5, 0, 5, character1->GetSprite(), 40.f),
            new Animation(6, 0, 5, character1->GetSprite(), 80.f)
        }
    );

    character1->GetSprite()->setPosition(400, 300);

    /*BoxCollider* character1Collider = new BoxCollider(400, 300, new sf::Color(0, 255, 0, 255), 16, 16,
    new Rigidbody(world, b2BodyType::b2_dynamicBody, new b2Vec2(400, 300), tileBaseWidth / 2, tileBaseHeight / 2, 1, 0, 0),
    character1->GetSprite());
    character1Collider->GetBoxShape()->setScale(SPRITE_SCALE, SPRITE_SCALE);*/


    //esto es el loop principal, mientras la ventana este abierta, esto se va ejecutar.
    while (window->isOpen())
    {
        //mientras se esten ejecutando eventos dentro de la ventana, esto se va repetir eje: teclado, joystick, mouse, etc
        while (window->pollEvent(event))
        {
            //si el evento fue la acción de cerrar la ventana, entonces termina la aplicación.
            if(event.type == sf::Event::Closed)
            {
                window->close();
            }
        }
        
        Vec2* keyboardAxis{inputs->GetKeyboardAxis()};
        Vec2* joystickAxis{inputs->GetJoystickAxis()};
   
        //player sigue la posicion del cuerpo de física}
        //character1Collider->UpdatePhysics();
        treasureCollider->UpdatePhysics();


        if(sf::Joystick::isConnected(0))
        {
            character1->Move(new b2Vec2(joystickAxis->x * deltaTime * PLAYER_MOVESPEED, joystickAxis->y * deltaTime * PLAYER_MOVESPEED));
            character1->FlipSpriteX(joystickAxis->x);

            if(std::abs(joystickAxis->x) > 0 || std::abs(joystickAxis->y) > 0)
            {
                //run
                character1->GetAnimation(1)->Play(deltaTime);
            }
            else
            {
                //idle
                character1->GetAnimation(0)->Play(deltaTime);
            }
        }
        else
        {
            character1->Move(new b2Vec2(keyboardAxis->x * deltaTime * PLAYER_MOVESPEED, keyboardAxis->y * deltaTime * PLAYER_MOVESPEED));
            character1->FlipSpriteX(keyboardAxis->x);

            if(std::abs(keyboardAxis->x) > 0 || std::abs(keyboardAxis->y) > 0)
            {
                //run
                character1->GetAnimation(1)->Play(deltaTime);
            }
            else
            {
                //idle
                character1->GetAnimation(0)->Play(deltaTime);
            }
        }


        window->clear(*(new sf::Color(150, 100, 0, 255)));//lipiar la pantalla

        for(auto& mazeTile : maze)
        {
            window->draw(mazeTile);
        }

        //character1Collider->GetBoxShape()->setPosition(character1->GetSprite()->getPosition());
        
        window->draw(*character1->GetSprite());
        window->draw(*character1->GetCollider()->GetBoxShape());
        window->draw(*treasureSprite);
        window->draw(*treasureCollider->GetBoxShape());
        window->display(); //mostrar en pantalla lo que se va dibujar

        sf::Time timeElapsed = clock->getElapsedTime();
        deltaTime = timeElapsed.asMilliseconds();
        world->ClearForces();
        world->Step(1.f / 100 * deltaTime, 8, 8);
        clock->restart();
        
        //std::cout << playerBody->GetPosition().x << " " << playerBody->GetPosition().y << std::endl; 

        //std::cout << "delta time: " << deltaTime << std::endl;

        delete keyboardAxis;
        delete joystickAxis;
    }
    
    return 0;
}