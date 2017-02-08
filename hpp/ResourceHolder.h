//
// Created by valentiay on 04.02.17.
//

#ifndef GAME_RESOURCRHOLDER_H
#define GAME_RESOURCRHOLDER_H

#include "SFML/Graphics.hpp"
#include <assert.h>

template <class Identifier, class Resource>
class ResourceHolder{
public:

    void                load(Identifier id, const std::string & filename);

    Resource &          get(Identifier id);
    
    
    const Resource &    get(Identifier id) const;

private:

    std::map<Identifier, std::unique_ptr<Resource>> resourceMap_;
};



namespace Textures{
    enum class ID{
        Wall,
        Floor,
        Player,
        Enemy
    };
}

typedef ResourceHolder<Textures::ID, sf::Texture> TextureHolder;

#include "../inl/ResorceHolder.inl"

#endif //GAME_RESOURCEHOLDER_H
