
// userInterface.hh

/*
 * Author: Asadul Haque
 * Date: 04 05 2010
 * Description : Declaration of UserInterface class
 * 
 */
 
#ifndef USERINTERFACE_HH
#define USERINTERFACE_HH

#include <string>
#include <sstream>
#include <vector>
#include "utility.hh"
#include "car.hh"
#include "competition.hh"
#include "player.hh"

const std::string UNKNOWN_CMD_MSG("ERROR: Unknown command.\n");
const std::string INVALID_PARAM_MSG("ERROR: Invalid command parameters.\n");
const std::string CMD_CANT_BE_PROCESSED_MSG("ERROR: The command can not be processed.\n");
const std::string CMD_CANT_BE_EXECUTED_MSG("ERROR: The command can not be executed.\n");


class UserInterface
{
 public:
  
  //Constructor
  UserInterface();
  UserInterface(std::vector<Player*> _players, std::vector<Competition*> _competitions);
  
  // Destructor
  ~UserInterface();
  
  // Operator=
  UserInterface operator=(const UserInterface&);
  // copy constructor
  UserInterface(const UserInterface&);
  
  
  // Method
  // Command line interface
  bool cli();
  void playerTurn(Player* player);
  // To convert a std::string to a unsigned value
  unsigned strtounsigned(const std::string& num);
  
  
 private:
  
  // Private data members
  std::vector<Competition*> competitions;
  std::vector<Player*> players;
  bool quit;

};

#endif
