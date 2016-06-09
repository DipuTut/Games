
// userInterface.cc

/*
 * Author: Asadul Haque
 * Date : 04 05 2010
 * Description : Definition of UserInterface class
 * 
 */
 
#include <string>
#include "userInterface.hh"

using namespace std;

// Constructor
UserInterface::UserInterface():players(),competitions(),quit(false)
{
}

UserInterface::UserInterface(vector<Player*> _players,
                             vector<Competition*> _competitions):quit(false)
{
  competitions = _competitions;
  players = _players;
}

// Destructor
UserInterface::~UserInterface()
{
}




// Methods

bool UserInterface::cli()
{
  // For eacch player in the players vector
  for(unsigned i = 0; i < players.size()
                      && quit == false ; i++)
  {
    playerTurn(players.at(i));
  }
  return quit;
}


void UserInterface::playerTurn(Player* player)
{
  // Used to know when the user has finnish
  bool next = false;

  do 
  {
    // Used to read the user command
    string str;
    // Used to store each words of the command line
    vector <string> vec;

    // Show the command prompt
    cout << player->getName() << " > ";
    getline(cin,str);
    
    // Decompose the command line to interpret each word
    string::size_type st = str.find(' ');

    // In case there is no space
    if( st == string::npos)
      vec.push_back(str); 
    // Otherwise
    else
    {
      while (st != string::npos)
      {
        vec.push_back(str.substr(0,st));
        str = str.substr(st+1);
        st = str.find(' ');
      }
      // Finally, add the last part
      vec.push_back(str);
    }
    

    // To test if the command has been executed
    bool success = false ;

    // The user want to tune is car
    if (vec.at(0) == "tune" )
    { 
      if(vec.size() == 4)
      {
        if (vec.at(1) == "1")
        {
          if(vec.at(2) == "tires")
          {
            if (vec.at(3) == "normal")
            {
              player->car1.setTireType(NORMAL);
              success = true;
            }

            if (vec.at(3) == "rain")
            {
              player->car1.setTireType(RAIN);
              success = true;
            }

            if (vec.at(3) == "studded")
            {
              player->car1.setTireType(STUDDED);
              success = true;
            }
          }
          if(vec.at(2) == "drive-wheel")
          {
            if(vec.at(3) == "2")
            {
              player->car1.setDriveWheel(1);
              success = true;
            }

            if(vec.at(3) == "4")
            {
              player->car1.setDriveWheel(0);
              success = true;
            }
          }
          if(vec.at(2) == "steering")
          {
            unsigned steering = strtounsigned(vec.at(3));
            if (steering >= 10 || steering <= 100)
            {
              player->car1.setSteering(steering);
              success = true;
            }
          }

          if (success)
          {
            player->car1.setTunned(true);
            cout << "Car 1 has been successfully tuned!" << endl ;
          }
        }

        else if (vec.at(1) == "2")
        {
          if(vec.at(2) == "tires")
          {
            if (vec.at(3) == "normal")
            {
              player->car2.setTireType(NORMAL);
              success = true;
            }

            if (vec.at(3) == "rain")
            {
              player->car2.setTireType(RAIN);
              success = true;
            }

            if (vec.at(3) == "studded")
            {
              player->car2.setTireType(STUDDED);
              success = true;
            }
          }

          if(vec.at(2) == "drive-wheel")
          {
            if(vec.at(3) == "2")
            {
              player->car2.setDriveWheel(1);
              success = true;
            }

            if(vec.at(3) == "4")
            {
              player->car2.setDriveWheel(0);
              success = true;
            }
          }
          if(vec.at(2) == "steering")
          {
            unsigned steering = strtounsigned(vec.at(3));
            if (steering >= 10 || steering <= 100)
            {
              player->car2.setSteering(steering);
              success = true;
            }  
          }
       

          if(success)
            cout << "Car 2 has been successfully tuned!" << endl ;

        }
      }

    }

    // Set the participation of player
    else if(vec.at(0) == "participate")
    {
      // Used to get the value of steering
      unsigned  number = strtounsigned(vec.at(1));
      // Decrease the number by 1 because
      // Competition start at 1 and vertor at 0
      --number;

      if (vec.size() == 3 )
      {
        if (number < competitions.size())
        {
          if(vec.at(2) == "on")
          {
            vector<bool> participate(player->getParticipate());
            participate.at(number) = true;
            player->setParticipate(participate);
            success = true ;
          }

          if(vec.at(2) == "off")
          {
            vector<bool> participate(player->getParticipate());
            participate.at(number) = false;
            player->setParticipate(participate);
            success = true ;
          }
        }
      }

      if (success)
      {
        cout << "Participation to the race number " 
           << number
           << " has been successfully changed."
           << endl;
      }
    }
    
    // The user want to print score result
    else if (vec.at(0) == "score")
    {
      if (vec.size() == 1)
      {
        for (unsigned i = 0; i < players.size(); i++)
        {
          cout << players.at(i)->getName()
             << ": "
             << players.at(i)->getPoints()
             << endl;
        }
        success = true;
      }
    }

    // The player want to know consist of the competition
    else if (vec.at(0) == "competition")
    {
      if (vec.size() == 1)
      {
        for (unsigned i = 0; i < competitions.size(); i++)
        {
          cout << i << " - "  << competitions.at(i)->getTrack()->getName() ;
          if (competitions.at(i)->getHeld())
          {
            cout << " - has been held"; 
          }
          else 
          {
            cout << " - has not been held";
          }
          cout << " min:" << competitions.at(i)->getTrack()->getMinPlayers()
               << " deadline:" << competitions.at(i)->getTrack()->getDeadline()
               << endl;
        }
        success = true;
      }
    }

    // The player want to participate to the practice turn
    else if (vec.at(0) == "practice")
    {
      if (vec.size() == 2)
      {
        player->setPracticeParticipate(true);
        next = true ;
        success = true;
      }
      else
      {
        cout << CMD_CANT_BE_PROCESSED_MSG ;
      }
    }

    // The user ask for the next player
    else if (vec.at(0) == "tunnings")
    {
      if(vec.size() == 1)
      {
        cout << "Car 1 - ";
        if(player->car1.getDriveWheel() == FOUR_WHEEL)
          cout << 4;
        else
          cout << 2;

        cout << " - " << player->car1.getSteering() << " - ";

        if(player->car1.getTireType() == NORMAL)
          cout << "normal";
        else if(player->car1.getTireType() == STUDDED)
          cout << "studded";
        else
          cout << "rain";

        // Same thing for the second car
        cout << "Car 2 - ";
        if(player->car2.getDriveWheel() == FOUR_WHEEL)
          cout << 4;
        else
          cout << 2;

        cout << " - " << player->car2.getSteering() << " - ";

        if(player->car2.getTireType() == NORMAL)
          cout << "normal";
        else if(player->car2.getTireType() == STUDDED)
          cout << "studded";
        else
          cout << "rain";
      }
    }

    // The user ask for the next player
    else if (vec.at(0) == "next")
    {
      if (vec.size() == 1)
      {
        next = true ;
        success = true;
      }
    }

    else if (vec.at(0) == "quit")
    {
      if (vec.size() == 1)
      {
        quit = true ;
        success = true;
      }
    }

    else
    {
      cout << UNKNOWN_CMD_MSG;
      success = true;
    }


    // Unreconized command line
    if(!success)
    {
      cout << CMD_CANT_BE_EXECUTED_MSG;
    }
  } while(!quit && !next);

}



unsigned UserInterface::strtounsigned(const string& num)
{
  istringstream instr(num);
  unsigned val = 0;
  instr >> val ;
  return val ;
}
