//
// Created by valentiay on 06.02.17.
//

#include "../hpp/Game.h"

Game::Game():
    window_(sf::VideoMode(1366, 768), "Javorski"),
    world_(window_),
    timePerFrame_(sf::seconds(1.f / 60.f))
{}



void Game::run(){
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while(window_.isOpen()){
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > timePerFrame_){
            timeSinceLastUpdate -= timePerFrame_;
            processPlayerInput();
            world_.update(timePerFrame_);
        }
        render();
    }
}



void Game::processPlayerInput(){
    sf::Event event;
    while(window_.pollEvent(event))
        if(event.type == sf::Event::Closed)
            window_.close();
        else
            player_.handleEvent(event, world_.getCommandQueue());

    player_.handleRealTimeInput(world_.getCommandQueue());
}



void Game::render(){
    window_.clear();
    world_.draw();
    window_.display();
}