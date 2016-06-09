/*
 * Author: Yoann Mailland
 * Date : 19 04 2010
 * Description : Declaration of the Track class
 *
 */



#include <string>
#include "utility.hh"

#ifndef TRACK_HH
#define TRACK_HH


class Track
{
  public:
    
    // Constructor
    Track();
    Track(std::string _name, unsigned _difficulty,
          unsigned  _roadType, unsigned _idealTime,
          unsigned _minPlayer, unsigned _deadLine);
    
    // Destructor
    ~Track();

    // Operator= and copy constructor
    Track operator=(const Track&);
    Track(const Track&);

    // Accessors
    std::string getName() const;
    unsigned getDifficulty() const;
    unsigned getRoadType() const;
    unsigned getIdealTime() const;
    unsigned getMinPlayers() const;
    unsigned getDeadline() const;

  private:
    
    // Private data membbers
    std::string name;
    unsigned difficulty;
    unsigned roadType;
    unsigned idealTime;
    unsigned minPlayer;
    unsigned deadline;
};

#endif
