/*
 * Author: Yoann Mailland
 * Date : 24 04 2010
 * Description : Declaration of the Competition class
 *
 */



#ifndef COMPETITION_HH
#define COMPETITION_HH

#include <vector>
#include "track.hh"
#include "randomizer.hh"
#include "race.hh"
#include "player.hh"

class Competition
{
  public:
    
    // Constructor
    Competition();
    Competition(Track* _track, std::vector<Player*> _players, Randomizer* _rand,
                unsigned _numberOfTheCompetition);
    
    // Destructor
    ~Competition();

    // Operator= and copy constructor
    Competition operator=(const Competition&);
    Competition(const Competition&);
    
    // Accessors
    bool getHeld() const;
    Track* getTrack() const;

    // Methods
    void setPlayers(std::vector<Player*> _players);
    void newRace();
    void freePractice();
    void startCompetition();


  private:    
    // Private data membbers
    bool held;
    std::vector<Player*> players;
    Track* track;
    Randomizer* randomizer;
    Race race;
    unsigned numberOfTheCompetition;
};

#endif
