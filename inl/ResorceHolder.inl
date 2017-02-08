template <class Identifier, class Resource>
void ResourceHolder<Identifier, Resource>::
load(Identifier id, const std::string & filename){
    std::unique_ptr<Resource> resource(new Resource);
    if(!resource->loadFromFile(filename))
        throw std::runtime_error("Resource " + filename + " not found");
    auto inserted = resourceMap_.insert(std::make_pair(id,
                                                       std::move(resource)));
    assert(inserted.second);
}



template <class Identifier, class Resource>
Resource & ResourceHolder<Identifier, Resource>::
get(Identifier id){
    auto found = resourceMap_.find(id);
    assert(found != resourceMap_.end());
    return *(found->second);
}



template <class Identifier, class Resource>
const Resource & ResourceHolder<Identifier, Resource>::
get(Identifier id) const{
    auto found = resourceMap_.find(id);
    assert(found != resourceMap_.end());
    return *(found->second);
}