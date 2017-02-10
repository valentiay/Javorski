//
// Created by valentiay on 06.02.17.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H

#include "SFML/Graphics.hpp"
#include "World.h"
#include "Player.h"

/******************************************************************************/

// Responsible for game tick and sending events to Player class
class Game{
public:
    // Constructs Render Window and sets parameters
                    Game();

    // Starts game tick
    void            run();

private:

    // Launches processing events and real time input in Player class
    void            processPlayerInput();


    // Launches drawing the world
    void            render();


    // Stores SFML Render Window object
    sf::RenderWindow    window_;

    // Stores the world
    World               world_;

    // Stores period of updating world
    sf::Time            timePerFrame_;

    // Stores Player class
    Player              player_;
};

#endif //GAME_GAME_H
