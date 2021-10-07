#include "aviary.hpp"

/* TODO: method Add
     * Arguments: A pointer to bird.
     * Description: Adds the given bird to the aviary.
     *  If the pointer is NULL, std::logic_error is thrown.
     * Returns: Nothing
     * 
     * When a bird is added to the aviary, it's ownership
     * is transferred. When the aviary is destroyed, all
     * the birds are destroyed too.
     */
void Aviary::Add(Bird *b)
{
    if (NULL == b)
    {
        std::logic_error("");
    }
    else
    {
        birds_.push_back(b);
    }
}

/* TODO: method SpeakAll
     * Arguments: A reference to ostream.
     * Description: Calls the Speak method with the given parameter  
     *  on all birds in the aviary
     * Returns: Nothing
     * 
     * Does not modify the object, thus it should be const
     */
void Aviary::SpeakAll(std::ostream &output) const
{
    for (auto bird : birds_)
    {
        bird->Speak(output);
    }
}

// Returns how many birds there are in the aviary.
/* TODO: method Size
     * Arguments: None.
     * Description: Returns the number of birds in the aviary
     * Returns: size_t
     * 
     * Does not modify the object, thus it should be const
     */
size_t Aviary::Size() const
{
    return birds_.size();
}

/* TODO: const and non-const versions of the indexing operator []
     * Arguments: size_t
     * Description: Returns a pointer to the bird at the index given as a parameter.
     *  If the index is out of bounds, std::out_of_range is thrown.
     * Returns: const Bird* for the const version and
     *  Bird* for the non-const version.
    */
const Bird *Aviary::operator[](size_t i) const
{
    if (i >= birds_.size())
    {
        throw std::out_of_range("");
    }
    else
    {
        return birds_[i];
    }
}

Bird *Aviary::operator[](size_t i)
{

    if (i >= birds_.size())
    {
        throw std::out_of_range("");
    }
    else
    {
        return birds_[i];
    }
}

Aviary::~Aviary() {
    for (auto i : birds_) {
        delete i;
    }
}