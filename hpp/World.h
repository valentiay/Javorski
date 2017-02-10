//
// Created by valentiay on 04.02.17.
//

#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include "ResourceHolder.h"
#include "SceneGraph.h"
#include "Command.h"

class World : private sf::NonCopyable{
public:

    explicit    World(sf::RenderWindow & window);


    void        update(sf::Time dt);

    void        draw();


    CommandQueue &      getCommandQueue();


    bool        isMovingUp;

    bool        isMovingLeft;

    bool        isMovingDown;

    bool        isMovingRight;


    float       playerSpeed;

private:

    enum layer{
        Background,
        Characters,
        LayerCount
    };


    void        loadTextures();

    void        buildScene();


    Entity *                            player_;

    Entity *                            java_;


    TextureHolder                       textures_;

    sf::RenderWindow &                  window_;

    sf::View                            worldView_;

    SceneNode                           sceneGraph_;

    std::array<SceneNode*, LayerCount>  layers_;


    sf::FloatRect                       worldBounds_;

    sf::Vector2f                        spawnPos_;


    CommandQueue                        commandQueue_;

};


#endif //GAME_WORLD_H
