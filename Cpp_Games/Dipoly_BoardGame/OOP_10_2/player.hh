/*
 * Author: Yoann Mailland
 * Date : 04 05 2010
 * Description : Declaration of the Player class
 *
 */



#ifndef PLAYER_HH
#define PLAYER_HH

#include <string>
#include <vector>

#include "car.hh"

class Player
{
  public:
    
    // Constructor
    Player();
    Player(std::string _name, Car _car1, Car _car2,
           unsigned _points, unsigned _raceTime1,
           unsigned _raceTime2,
	         std::vector<bool> _participate);


    Player(std::string _name);

    // Destructor
    ~Player();

    // Operator= and copy constructor
    Player operator=(const Player&);
    Player(const Player&);

    // Accessors
    unsigned getPoints() const;
    unsigned getRaceTime1() const;
    unsigned getRaceTime2() const;
    std::string getName() const;
    std::vector<bool> getParticipate() const;
    Car getCar(unsigned carNumber) const;
    bool getPracticeParticipate();
    bool getRaceParticipate(unsigned numOfRace) const;

    // Mutators
    void setName(std::string _name);
    void addPoints(unsigned _points);
    void setRaceTime1(unsigned _points);
    void setRaceTime2(unsigned _points);
    void setParticipate(std::vector<bool> _participate);
    void setPracticeParticipate(bool _practiceParticipate);

    // Methods
    unsigned getBestTime() const;
    
    // car1 and 2 are public to cimplify the user interface
    Car car1, car2;

  private:
    
    // Private data membbers
    std::string name;
    unsigned points;
    unsigned raceTime1;
    unsigned raceTime2;
    bool practiceParticipate;
    std::vector<bool> participate;
};

#endif
