//
// Created by valentiay on 04.02.17.
//

#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include "ResourceHolder.h"
#include "SceneGraph.h"
#include "Command.h"

/******************************************************************************/

// Stores Scene Graph, responsible for updating and drawing SceneNodes
class World : private sf::NonCopyable{
public:
    // Sets world parameters
    explicit    World(sf::RenderWindow & window);


    // Updates Scene Graph
    void        update(sf::Time dt);

    // Draws Scene Graph
    void        draw();


    // Returns command queue
    // Required for transferring commands from Player class
    CommandQueue &      getCommandQueue();

private:
    // Stores Names of layers
    enum layer{
        Background,
        Characters,
        LayerCount
    };


    // Loads textures in constructor
    void        loadTextures();

    // Build scene graph
    void        buildScene();


    // Points at player Entity
    Entity *                            player_;

    // Points at Javorski Entity
    Entity *                            java_;


    // Stores textures
    TextureHolder                       textures_;

    // Stores rendering window
    sf::RenderWindow &                  window_;

    // Stores window view
    sf::View                            worldView_;

    // Stores scene graph
    SceneNode                           sceneGraph_;

    // Stores layers list
    std::array<SceneNode*, LayerCount>  layers_;


    // Stores world bounds
    sf::FloatRect                       worldBounds_;

    // Stores spawn position
    sf::Vector2f                        spawnPos_;


    // Stores command queue
    CommandQueue                        commandQueue_;

};


#endif //GAME_WORLD_H
