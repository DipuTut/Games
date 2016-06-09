/*
* Author: Yoann Mailland
* Date : 19 04 2010
* Description : Definition of the Track class
*
*/


#include <string>
#include "track.hh"
#include "utility.hh"


using namespace std;


// Constructor
Track::Track():name("No name"),
               difficulty(),
               roadType(),
               idealTime(),
               minPlayer(),
               deadline()
{
}

Track::Track(string _name, unsigned _difficulty,
             unsigned _roadType, unsigned _idealTime,
             unsigned _minPlayer, unsigned _deadline)
{
  name = _name;
  difficulty = _difficulty;
  roadType = _roadType;
  idealTime = _idealTime;
  minPlayer = _minPlayer;
  deadline = _deadline;
}

// Copy constructor
Track::Track(const Track& track)
{
  this->difficulty = track.getDifficulty();
  this->roadType = track.getRoadType();
  this->name = track.getName();
  this->idealTime = track.getIdealTime();
  this->minPlayer = track.getMinPlayers();
  this->deadline = track.getDeadline();
}

Track Track::operator=(const Track& track)
{
  Track t;
  t.difficulty = track.getDifficulty();
  t.roadType = track.getRoadType();
  t.name = track.getName();
  t.idealTime = track.getIdealTime();
  t.minPlayer = track.getMinPlayers();
  t.deadline = track.getDeadline();
  return t;
}


// Destructor
Track::~Track()
{
}

// Accessors
string Track::getName() const
{
  return name;
}

unsigned Track::getDifficulty() const
{
  return difficulty;
}

unsigned Track::getRoadType() const
{
  return roadType;
}

unsigned Track::getIdealTime() const
{
  return idealTime;
}

unsigned Track::getMinPlayers() const
{
  return minPlayer;
}

unsigned Track::getDeadline() const
{
  return deadline;
}
