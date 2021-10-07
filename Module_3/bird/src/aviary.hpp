#pragma once

#include <iostream>
#include "bird.hpp"

#include <list>

/*
 * If somebody tries to copy an instance of this class,
 * the compilation must fail i.e. TODO: disallow copying
 */
class Aviary {
public:
    Aviary() {}
    Aviary(const Aviary&) = delete;

    void Add (Bird* b);
        
    /* TODO: method SpeakAll
     * Arguments: A reference to ostream.
     * Description: Calls the Speak method with the given parameter  
     *  on all birds in the aviary
     * Returns: Nothing
     * 
     * Does not modify the object, thus it should be const
     */

    void SpeakAll (std::ostream& output) const;
    
    // Create a new type alias sizeType

    size_t Size() const;
    

    /* TODO: const and non-const versions of the indexing operator []
     * Arguments: size_t
     * Description: Returns a pointer to the bird at the index given as a parameter.
     *  If the index is out of bounds, std::out_of_range is thrown.
     * Returns: const Bird* for the const version and
     *  Bird* for the non-const version.
    */
   const Bird* operator[] (size_t i) const;
   Bird* operator[] (size_t i);

        
    /* TODO: destructor */
    ~Aviary();

private:
    // TODO: the needed variables
    std::vector<Bird*> birds_;
    Aviary& operator=(const Aviary&);
};
