//
// Created by valentiay on 04.02.17.
//

#ifndef GAME_RESOURCRHOLDER_H
#define GAME_RESOURCRHOLDER_H

#include "SFML/Graphics.hpp"
#include <assert.h>

/******************************************************************************/

// Stores resources like textures, sounds ect.
template <class Identifier, class Resource>
class ResourceHolder{
public:
    // Assigns resource to id
    void                load(Identifier id, const std::string & filename);

    // Returns resource by id
    Resource &          get(Identifier id);
    const Resource &    get(Identifier id) const;

private:
    // Stores resources
    std::map<Identifier, std::unique_ptr<Resource>> resourceMap_;

};

/******************************************************************************/

// Stores texture names
namespace Textures{
    enum class ID{
        Wall,
        Floor,
        Player,
        Enemy
    };
}

// Defines texture holder
typedef ResourceHolder<Textures::ID, sf::Texture> TextureHolder;

#include "../inl/ResorceHolder.inl"

#endif //GAME_RESOURCEHOLDER_H
