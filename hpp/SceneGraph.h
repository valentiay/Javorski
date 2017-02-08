//
// Created by valentiay on 06.02.17.
//

#ifndef GAME_SCENENODE_H
#define GAME_SCENENODE_H

#include "SFML/Graphics.hpp"

class SceneNode: public sf::Transformable,
                 public sf::Drawable,
                 private sf::NonCopyable{
public:

    typedef std::unique_ptr<SceneNode> NodePtr;


    void        attachChild(NodePtr child);

    NodePtr     detatchChild(const SceneNode & node);

    void        update(sf::Time dt);

private:

    virtual void            draw(sf::RenderTarget & target,
                                 sf::RenderStates states) const final;

    virtual void            drawCurrent(sf::RenderTarget & target,
                                        sf::RenderStates states) const;


    virtual void            updateCurrent(sf::Time dt);


    SceneNode *             father_;

    std::vector<NodePtr>    children_;

};



class Entity: public SceneNode{
public:

    explicit        Entity(const sf::Texture & texture);

                    Entity(const sf::Texture & texture,
                           const sf::IntRect & rect);


    void            setVelocity(sf::Vector2f velocity);

    void            setVelocity(float vx, float vy);


    sf::Vector2f    getVelocity() const;

private:

    void    drawCurrent(sf::RenderTarget & target,
                        sf::RenderStates states) const override final;

    void    updateCurrent(sf::Time dt) override final;


    sf::Vector2f    velocity_;

    sf::Sprite      sprite_;

};



class SpriteNode: public SceneNode{
public:

    explicit        SpriteNode(const sf::Texture & texture);

                    SpriteNode(const sf::Texture & texture,
                               const sf::IntRect & rect);

private:

    void    drawCurrent(sf::RenderTarget & target,
                        sf::RenderStates states) const override final;


    sf::Sprite sprite_;
};

#endif //GAME_SCENENODE_H