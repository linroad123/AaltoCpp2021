#pragma once
#include <list>
#include "dragon.hpp"
/* TODO: class DragonCave
 * Description:
 * ------------
 * The DragonCave class is a sort of storage class for Dragons. The class
 * stores pointers of Dragon objects in a list. The class allows basic
 * manipulation of the Dragon pointer list through the functions described
 * below.
 *
 * Functions:
 * -----------
 *
 * Other:
 * -----------
 * The class obviously has a list of Dragon pointers as a private member. This class is not
 * copyable (also means not assignable), so copy and assignment operations for this
 * class should be prevented.
 */

/* TODO: operator <<
 * ------------
 * Description:
 * An overloaded << stream operator for printing DragonCaves to parameter ostreams.
 * The DragonCave should be printed to the parameter ostream in the following format:
DragonCave dwellers:\n
\n
<First Dragon in the dragons list>\n
<Second Dragon in the dragons list>\n
...
<Last Dragon in the dragons list>
 *
 * NOTE: The dragons in the dragon list are printed in the same format as the overloaded
 *       << stream operator for Dragons prints them. Also note that there is an additional
 *       end line character after each dragon except for the last one.
 * ------------
 * Parameters:
 * - the output stream to which the information is printed (ostream).
 * - the DragonCave whose information should be printed (const DragonCave&).
 * ------------
 * Returns:
 * The parameter output stream.
 */

class DragonCave
{
public:
    DragonCave() = default;
    ~DragonCave();

    DragonCave(const DragonCave &) = delete;

    const std::list<Dragon *> &GetDragons() const;
    void Accommodate(Dragon *dragon);
    void Evict(const std::string &name);
	friend std::ostream &operator<<(std::ostream &out,const DragonCave& dragon);
private:
    std::list<Dragon *> dragons_;
};