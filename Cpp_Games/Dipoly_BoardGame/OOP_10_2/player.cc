/*
* Author: Yoann Mailland
* Date : 04 05 2010
* Description : Definition of the Player class
*
*/


#include <string>
#include <vector>

#include "player.hh"
#include "car.hh"

using namespace std;


// Constructor
Player::Player():name("No name"),
                 car1(),
                 car2(),
            		 points(0),
                 raceTime1(0),
                 raceTime2(0),
                 participate(),
                 practiceParticipate(true)
{
}

          
Player::Player(string _name):name(_name),
                             car1(),
                             car2(),
                             points(0),
                             raceTime1(0),
                             raceTime2(0),
                             participate(),
                             practiceParticipate(true)
{
}

Player::Player(string _name, Car _car1, Car _car2,
               unsigned _points, unsigned _raceTime1,
               unsigned _raceTime2,
               vector<bool> _participate)
  
{
   name = _name;
   car1 = _car1;
   car2 = _car2;
   points = _points;
   raceTime1 = _raceTime1;
   raceTime2 = _raceTime2;
   participate = _participate;
}


// Destructor
Player::~Player()
{
}

// Accessors
unsigned Player::getPoints() const
{
  return points;
}


unsigned Player::getRaceTime1() const
{
  return raceTime1;
}

unsigned Player::getRaceTime2() const
{
  return raceTime2;
}

string Player::getName() const
{
  return name;
}

vector<bool> Player::getParticipate() const
{
  return participate;
}


Car Player::getCar(unsigned carNumber) const
{
  if(carNumber == 2)
    return car2;
  else
    return car1;
}

bool Player::getPracticeParticipate()
{
  return practiceParticipate;
}

bool Player::getRaceParticipate(unsigned numOfRace) const
{
  if(numOfRace < participate.size())
    return participate.at(numOfRace);
 
  // Otherwise
  return true;  // Return the default value
}

// Mutators
void Player::setName(std::string _name)
{
  name = _name;
}

void Player::addPoints(unsigned _points)
{
  points = _points;
}

void Player::setRaceTime1(unsigned _time)
{
  raceTime1 = _time;
}

void Player::setRaceTime2(unsigned _time)
{
  raceTime2 = _time;
}

void Player::setParticipate(vector<bool> _participate)
{
  participate = _participate;
}

void Player::setPracticeParticipate(bool _practiceParticipate)
{
  practiceParticipate = _practiceParticipate;
}





// Methods
unsigned Player::getBestTime() const
{
  if(raceTime1 > raceTime2)
    return raceTime1;
  else
    return raceTime2;
}
