/*
* Author: Yoann Mailland
* Date : 24 04 2010
* Description : Definition of the Competition class
*
*/




#include <vector>
#include "track.hh"
#include "randomizer.hh"
#include "race.hh"
#include "player.hh"
#include "competition.hh"

using namespace std;


// Constructor
Competition::Competition():players(),
   	       	       	   track(),
    	     	           randomizer(),
    	    	           race(),
                       held(),
                       numberOfTheCompetition()
{
  held = false;
}

Competition::Competition(Track* _track, vector<Player*> _players, Randomizer* _rand,
                         unsigned _numberOfTheCompetition):
race(_players, _track, _rand, _numberOfTheCompetition),
numberOfTheCompetition(_numberOfTheCompetition)
{
  players = _players;
  track = _track;
  randomizer = _rand;
  held = false;
}
          
// Destructor
Competition::~Competition()
{
}

// Accessors
bool Competition::getHeld() const
{
  return held;
}

Track* Competition::getTrack() const
{
  return track;
}


// Methods
void Competition::setPlayers(vector<Player*> _players)
{
  players = _players;
}

void Competition::newRace()
{
  race.startRace(true);  // True to count points
}

void Competition::freePractice()
{
  race.startRace(false);  // False to not count points 
}

void Competition::startCompetition()
{
  // Player customisation should be added
  freePractice();
  newRace();
  held = true;
}
