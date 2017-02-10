//
// Created by valentiay on 07.02.17.
//

#include <assert.h>
#include "../hpp/SceneGraph.h"

/****************************SCENENODE*****************************************/

SceneNode::SceneNode():
    category_(Category::Type::Scene)
{}



void SceneNode::attachChild(NodePtr child){
    child->father_ = this;
    children_.push_back(std::move(child));
}



SceneNode::NodePtr SceneNode::detachChild(const SceneNode &node){
    auto found = std::find_if(children_.begin(), children_.end(),
    [&] (NodePtr & p) -> bool { return p.get() == &node;});
    assert(found != children_.end());
    NodePtr result = std::move(*found);
    result->father_ = nullptr;
    children_.erase(found);
    return result;
}



void SceneNode::update(sf::Time dt){
    updateCurrent(dt);
    for(const NodePtr & child : children_)
        child->update(dt);
};



void SceneNode::updateCurrent(sf::Time dt){}



void SceneNode::draw(sf::RenderTarget & target, sf::RenderStates states) const{
    states.transform *= getTransform();
    drawCurrent(target, states);
    for(const NodePtr & child : children_)
        child->draw(target, states);
}



void SceneNode::onCommand(const Command & command, sf::Time dt){
    if(command.category & category_)
        command.action(this, dt); // TODO: Check

    for(const NodePtr & child : children_)
        child->onCommand(command, dt);
}



void SceneNode::drawCurrent(sf::RenderTarget & target,
                                    sf::RenderStates states) const
{}

/****************************ENTITY********************************************/

Entity::Entity(const sf::Texture & texture){
    sprite_.setTexture(texture);
}



Entity::Entity(const sf::Texture & texture, const sf::IntRect & rect){
    sprite_.setTexture(texture);
    sprite_.setTextureRect(rect);
}



void Entity::setVelocity(float vx, float vy){
    sf::Vector2f velocity(vx, vy);
    velocity_ = velocity;
}



void Entity::setVelocity(sf::Vector2f velocity){
    velocity_ = velocity;
}



sf::Vector2f Entity::getVelocity() const{
    return velocity_;
}



void Entity::drawCurrent(sf::RenderTarget & target,
                         sf::RenderStates states) const{
    target.draw(sprite_, states);
}



void Entity::updateCurrent(sf::Time dt){
    move(velocity_ * dt.asSeconds());
}



void Entity::setCategory(Category::Type category){
    category_ = category;
}

/****************************SPRITENODE****************************************/

SpriteNode::SpriteNode(const sf::Texture & texture){
    sprite_.setTexture(texture);
}



SpriteNode::SpriteNode(const sf::Texture & texture,
                       const sf::IntRect & rect){
    sprite_.setTexture(texture);
    sprite_.setTextureRect(rect);
}



void SpriteNode::drawCurrent(sf::RenderTarget & target,
                             sf::RenderStates states) const{
    target.draw(sprite_, states);
}