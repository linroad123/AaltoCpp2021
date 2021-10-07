#include "pokemon.hpp"
#include <algorithm>
#include <vector>

    /* Add:
    * adds a pokemon to the end of the collection, takes the following parameters:
    *  - the pokemon's name, 
    *  - the pokemon's id, 
    *  adds a new Pokemon with given name/id pair at the end of list pokemon_.
    */ 
void PokemonCollection::Add(const std::string& name, size_t id) {
    pokemons_.push_back(std::make_pair(name,id));
}
    
    /* Remove:
    * removes a pokemon to the collection, takes the following parameters:
    *  - the pokemon's name, 
    *  - the pokemon's id
    * returns true if the pokemon was found and removed, false otherwise
    */ 
bool PokemonCollection::Remove(const std::string& name, size_t id) {
    std::pair<std::string, size_t> compare = {name,id};
    for (auto it=pokemons_.begin(); it!=pokemons_.end();) {
            if (*it == compare){
                pokemons_.erase(it);
                return true;
            } else {
                it++;
            }
    }
    return false;
}

    /* Print:
    * Prints the collection to the standard output stream. 
    * The format of the print should be as below: 
id: <id>, name: <name>\n
id: <id>, name: <name>\n
    */ 
void PokemonCollection::Print() const {
    for (auto it=pokemons_.begin(); it!=pokemons_.end(); it++) {
        std::cout << "id: " << it -> second << ", "
            << "name: " << it -> first << std::endl;
    }
}

    /* SortByName:
    * sorts the collection by name.
    * If two names are equal, their order is determined by their ids
    * Hint: A list only has bidirectional iterators, which might narrow your sorting solutions down a bit.
    * However a valid and easy solution does exist!
    */ 
bool sortbyfirstdesc(const std::pair<std::string, size_t> &a,
                   const std::pair<std::string, size_t> &b)
{   
    if (a.first == b.first) {
        return a.second < b.second;
    } else {
        return a.first<b.first;
    }
}

void PokemonCollection::SortByName() {
    std::vector<std::pair<std::string,size_t>> vect;
    for (auto it=pokemons_.begin(); it!=pokemons_.end(); it++) {
        vect.push_back(*it);
    } 
    std::sort(vect.begin(),vect.end(),sortbyfirstdesc);
    pokemons_.clear();

    for (auto it=vect.begin(); it!=vect.end(); it++) {
        pokemons_.push_back(*it);
    } 
}
    
    /* SortById:
    * sorts the collection by id
    * If two ids are equal, their order is determined by their names
    * Hint: A list only has bidirectional iterators, which might narrow your sorting solutions down a bit.
    * However a valid and easy solution does exist!
    */ 

bool sortbysecdesc(const std::pair<std::string, size_t> &a,
                   const std::pair<std::string, size_t> &b)
{   
    if (a.second == b.second) {
        return a.first < b.first;
    } else {
        return a.second<b.second;
    }
}

void PokemonCollection::SortById() {
    std::vector<std::pair<std::string,size_t>> vect;
    for (auto it=pokemons_.begin(); it!=pokemons_.end(); it++) {
        vect.push_back(*it);
    } 
    std::sort(vect.begin(),vect.end(),sortbysecdesc);
    pokemons_.clear();

    for (auto it=vect.begin(); it!=vect.end(); it++) {
        pokemons_.push_back(*it);
    } 
}

    /* constuctor
    * initializes the collection to contain all the pokemons from the two 
    * collections given as parameters and removes all duplicates, takes the following parameters:
    *  - collection: a PokemonCollection
    *  - collection2: a PokemonCollection
    * Hint: sorting at some point would probably help
    * 
    * All the other functions must get full points before this is tested.
    */
PokemonCollection::PokemonCollection(PokemonCollection collection, PokemonCollection collection2) {

    collection.pokemons_.unique();
    collection2.pokemons_.unique(); 
    

    pokemons_.merge(collection2.pokemons_);
    pokemons_.merge(collection.pokemons_);
    pokemons_.sort();
    pokemons_.unique();

    // for (auto it=collection.pokemons_.begin(); it != collection.pokemons_.end();) {
    //     for (auto it2=collection2.pokemons_.begin(); it2 != collection2.pokemons_.end(); ) {
    //         if (*it2 == *it){
    //             collection.pokemons_.erase(it);
    //             collection2.pokemons_.erase(it2);
    //         }
    //         else {
    //             it++;
    //             it2++;
    //             continue;
    //         }
    //     }
    // }
}