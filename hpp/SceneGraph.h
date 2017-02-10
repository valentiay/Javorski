//
// Created by valentiay on 06.02.17.
//

#ifndef GAME_SCENENODE_H
#define GAME_SCENENODE_H

#include "SFML/Graphics.hpp"
#include "Command.h"

/******************************************************************************/

// Base class for scene graph nodes
class SceneNode: public sf::Transformable,
                 public sf::Drawable,
                 private sf::NonCopyable{
public:
    // Defines smart pointer to SceneNode
    typedef std::unique_ptr<SceneNode> NodePtr;


    // Sets category
                SceneNode();


    // Attaches a child node
    void        attachChild(NodePtr child);

    // Detaches child
    NodePtr     detachChild(const SceneNode &node);


    // Recursively updates scene graph
    void        update(sf::Time dt);

    // Recursively sends commands
    void        onCommand(const Command & command, sf::Time);

private:
    // Recursively draws scene graph
    virtual void            draw(sf::RenderTarget & target,
                                 sf::RenderStates states) const final;

    // Draws only current node
    virtual void            drawCurrent(sf::RenderTarget & target,
                                        sf::RenderStates states) const;


    // Updates only current node
    virtual void            updateCurrent(sf::Time dt);


    // Stores pointer to father
    SceneNode *             father_;

    std::vector<NodePtr>    children_;

protected:
    // Stores category of node
    Category::Type          category_;

};

/******************************************************************************/

// TODO: Comment
class Entity: public SceneNode{
public:

    explicit        Entity(const sf::Texture & texture);

                    Entity(const sf::Texture & texture,
                           const sf::IntRect & rect);


    void            setVelocity(sf::Vector2f velocity);

    void            setVelocity(float vx, float vy);


    sf::Vector2f    getVelocity() const;


    // TODO: Remove, debug function
    void            setCategory(Category::Type category);

private:

    void    drawCurrent(sf::RenderTarget & target,
                        sf::RenderStates states) const override final;

    void    updateCurrent(sf::Time dt) override final;


    sf::Vector2f    velocity_;

    sf::Sprite      sprite_;

};

/******************************************************************************/

// Scene Node containing sprite
class SpriteNode: public SceneNode{
public:
    // Sets texture to a sprite
    explicit        SpriteNode(const sf::Texture & texture);

    // Sets texture and texture rectangle to a sprite
                    SpriteNode(const sf::Texture & texture,
                               const sf::IntRect & rect);

private:
    // Draws sprite
    void    drawCurrent(sf::RenderTarget & target,
                        sf::RenderStates states) const override final;


    // Stores sprite
    sf::Sprite sprite_;
};

#endif //GAME_SCENENODE_H