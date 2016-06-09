/*
 * Author: Yoann Mailland
 * Date : 24 04 2010
 * Description : Declaration of the Race class
 *
 */



#ifndef RACE_HH
#define RACE_HH

#include <vector>
#include "track.hh"
#include "randomizer.hh"
#include "player.hh"

class Race
{
  public:
    
    // Constructor
    Race();
    Race(std::vector<Player*> _players,Track* track , Randomizer* _randomizer,
         unsigned _numberOfTheCompetition);
    
    // Destructor
    ~Race();

    // Operator= and copy constructor
    Race operator=(const Race&);
    Race(const Race&);


    // Methods
    void startRace(bool realRace);
    void printResult() const;
    void findWinner() const;

  private:
    // Private data membbers
    std::vector<Player*> players;
    Track* track;
    Randomizer* randomizer;
    unsigned weather;
    unsigned numberOfTheCompetition;

};

#endif
