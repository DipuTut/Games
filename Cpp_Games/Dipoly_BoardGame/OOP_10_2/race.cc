/*
* Author: Yoann Mailland
* Date : 24 04 2010
* Description : Definition of the Race class
*
*/




#include <vector>
#include <cmath>
#include "track.hh"
#include "randomizer.hh"
#include "race.hh"
#include "player.hh"
#include "utility.hh"
using namespace std;


// Constructor
Race::Race():players(),
             track(),
             weather(),
             randomizer()
{       
}

Race::Race(vector<Player*> _players, Track* _track, Randomizer* _randomizer,
           unsigned _numberOfTheCompetition):
numberOfTheCompetition(_numberOfTheCompetition)
{
  players = _players;
  track = _track;
  randomizer = _randomizer;
}
          
// Destructor
Race::~Race()
{
}

// Methods
void Race::startRace(bool realRace)
{

  // In the case of a free practice
  if(!realRace)
  {
    for(unsigned i = 0; i < players.size(); i++)
    {
      if(players.at(i)->getPracticeParticipate())
      {
        unsigned result = 0; // Result (race time)
        unsigned trackFactor = (unsigned) abs((double)(track->getDifficulty() 
                                    - 2*players.at(i)->getCar(1).getSteering()))
                               + 5 ;
        // Calculate the result of the player
        result = track->getIdealTime()
                       * trackFactor
                       * DRIVE_WHEEL_FACTOR
                                    [track->getRoadType()]
                                    [ players.at(i)->getCar(1).getDriveWheel()]
                       * 2;   // Car time factor (here car 1)

        players.at(i)->setRaceTime1(result);

        // Calcul of the result for the second car
        trackFactor = (unsigned) abs((double)(track->getDifficulty() 
                                      - 2*players.at(i)->getCar(2).getSteering()))
                                 + 5 ;
        // Calculate the result of the player
        result = track->getIdealTime()
                       * trackFactor
                       * DRIVE_WHEEL_FACTOR
                                    [track->getRoadType()]
                                    [ players.at(i)->getCar(2).getDriveWheel()];

        players.at(i)->setRaceTime2(result);
      }

    }
    
    // Print results
    cout << "\n\nTrack " << track->getName() 
         << " free practice has been held." << endl;

    printResult();

  }

  // In the  case of e real race

  else
  {
    unsigned numberOfParticipant = 0;
    // count the number of participant
    for(unsigned i = 0; i < players.size(); i++)
    {
      if(players.at(i)->getRaceParticipate(numberOfTheCompetition))
        ++numberOfParticipant;
    }

    // In the case of insufisant number of players
    if(numberOfParticipant < track->getMinPlayers()
       || numberOfParticipant < 2)
    {
      cout << "\n\n /!\\There is not enouth players in the race ! \n";
    }
    else
    {
      Utility::Weather resWeather;
      string strWeather("\"no information\"");

      // Calculate the weather
      switch(track->getRoadType())
      {
        case 0:
          resWeather = randomizer->calculateWeather(Utility::ASPHALT);
        break;
        case 1:
          resWeather = randomizer->calculateWeather(Utility::SAND);
        break;
        default:
          resWeather = randomizer->calculateWeather(Utility::SNOW);
        break;
      }

      // Set the weather value
      if(resWeather == Utility::SUNNY)
      {
        weather = SUNNY;
        strWeather = "sunny";
      }
      else if(resWeather == Utility::RAINY)
      {
        weather = RAIN;
        strWeather = "rainy";
      }
      else if(resWeather == Utility::SNOWY)
      {
        weather = SNOWY;
        strWeather = "snowy";
      }

      for(unsigned i = 0; i < players.size(); i++)
      {
        unsigned result;
        unsigned trackFactor = (unsigned) abs((double)(track->getDifficulty() 
                                    - 2*players.at(i)->getCar(1).getSteering()))
                               + 5 ;
        // Calculate the result of the player
        result = track->getIdealTime()
                       * trackFactor
                       * DRIVE_WHEEL_FACTOR
                                    [track->getRoadType()]
                                    [players.at(i)->getCar(1).getDriveWheel()]
                       * WEATHER_TIRE_FACTOR[players.at(i)->getCar(1).getTireType()]
                                            [weather]
                       * 2;   // Car time factor (here car 1)

        players.at(i)->setRaceTime1(result);

        // Calcul of the result for the second car
        trackFactor = (unsigned) abs((double)(track->getDifficulty() 
                                      - 2*players.at(i)->getCar(2).getSteering()))
                                 + 5 ;

        // Calculate the result of the player
        result = track->getIdealTime()
                       * trackFactor
                       * DRIVE_WHEEL_FACTOR
                                    [track->getRoadType()]
                                    [players.at(i)->getCar(2).getDriveWheel()]
                       * WEATHER_TIRE_FACTOR[players.at(i)->getCar(2).getTireType()]
                                            [weather];

        players.at(i)->setRaceTime2(result);
      }
      
      // Print results
      cout << "\n\nRace " << track->getName() 
           << " was driven in " << strWeather
           << " weather." << endl;

      printResult();

      // Find the winner and second and add points
      findWinner();
    }
  }
}

// Print result of the race / free practice
void Race::printResult() const
{
  cout << "Number of players in the race:"<<players.size()<< endl;
  for(unsigned i = 0; i < players.size(); i++)
  {
    cout << players.at(i)->getName() << ":1: " << players.at(i)->getRaceTime1() << endl;
    cout << players.at(i)->getName() << ":2: " << players.at(i)->getRaceTime2() << endl;
  }
}

// Find the winner and the second
void Race::findWinner() const
{
  Player* winner;
  Player* second;
  // We compare the 2 first players
  if(players.at(0)->getBestTime() > players.at(1)->getBestTime())
  {
    // The first one is the winner
    winner = players.at(0);
    second = players.at(1);
  }
  else
  {
    // The second one is the winner
    winner = players.at(1);
    second = players.at(0);
  }

  // For other players we compare their best time
  for(unsigned i = 2; i < players.size(); i++)
  {
    if(players.at(i)->getBestTime() > winner->getBestTime())
    {
      second = winner;
      winner = players.at(i);
    }
    else if(players.at(i)->getBestTime() > second->getBestTime())
      second = players.at(i);
  }

  // Then add points to the winner and the second
  winner->addPoints(2);
  second->addPoints(1);
}
