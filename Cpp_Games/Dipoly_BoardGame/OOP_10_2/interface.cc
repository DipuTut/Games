#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>



using namespace std;


int main()
{

    // Used to read the user command
    string str;
    // Used to store each words of the command line
    vector <string> vec;
    vec.clear();
    // Used to know when the user has finnish
    bool next = false;

    // To check if the user want to quit the game
    bool quit = false;
    cout << player->getName() << " > ";
    getline(cin,str);
    string::size_type st = str.find(' ');
    
    // Decompose the command line to interpret each word
    while (st != string::npos)
    {
      vec.push_back(str.substr(0,st));
      str = str.substr(st+1);
      st = str.find(' ');
    }
    
    // To test if the command has been executed
    bool success = false ;

    // The user want to tune is car
    if (vec[0] == "tune" )
    { 
      if (vec[1] == "1")
      {
        if(vec[2] == "tires")
        {
          if (vec[3] == "normal")
          {
            player->car1.setTire(NORMAL);
            success = true;
          }

          if (vec[3] == "rain")
          {
            player->car1.setTire(RAIN);
            success = true;
          }

          if (vec[3] == "studded")
          {
            player->car1.setTire(STUDDED);
            success = true;
          }
        }
        if(vec[2] == "drive-wheel")
        {
          if(vec[3] == "2")
          {
            player->car1.setDriveWheel(1);
            success = true;
          }

          if(vec[3] == "4")
          {
            player->car1.setDriveWheel(0);
            success = true;
          }
        }
        if(vec[2] == "steering")
        {
          unsigned steering = strtounsigned(vec[3]);
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

      else if (vec[1] == "2")
      {
        if(vec[2] == "tires")
        {
          if (vec[3] == "normal")
          {
            player->car2.setTire(NORMAL);
            success = true;
          }

          if (vec[3] == "rain")
          {
            player->car2.setTire(RAIN);
            success = true;
          }

          if (vec[3] == "studded")
          {
            player->car2.setTire(STUDDED);
            success = true;
          }
        }

        if(vec[2] == "drive-wheel")
        {
          if(vec[3] == "2")
          {
            player->car2.setDriveWheel(1);
            success = true;
          }

          if(vec[3] == "4")
          {
            player->car2.setDriveWheel(0);
            success = true;
          }
        }
        if(vec[2] == "steering")
        {
          unsigned steering = strtounsigned(vec[3]);
          if (steering >= 10 || steering <= 100)
          {
            player->car2.setSteering(steering);
            success = true;
          }  
        }

        if (success)
          cout << "Car 2 has been successfully tuned!" << endl ;
      }
    }

    // Set the participation of player
    else if(vec[0] == "participate")
    {
      if (vec.size() = 3 )
      {
        unsigned  number = strtounsigned(vec[1]);
        if (number < numberOfCompetitions)
        {
          if(vec[2] == "on")
          {
            vector<bool> participate(player->getParticipate());
            participate[number] = true;
            player->setParticipate(participate);
            success = true ;
          }

          if(vec[2] == "off")
          {
            vector<bool> participate(player->getParticipate());
            participate[number] = false;
            player->setParticipate(participate);
            success = true ;
          }
        }
      }

      if (success)
      {
        cout << "Participation to the race number " 
           << number
           << " has been successfully changed.";
      }
    }
    
    // The user want to print score result
    else if (vec[0] == "score")
    {
      if (vec.size() == 1)
      {
        for (unsigned i = 0; i < players.size(); i++)
        {
          cout << players[i]->getName()
             << " "
             <<  players[i]->getScore();
        }
      }
    }

    // The player want to know consist of the competition
    else if (vec[0] == "competition")
    {
       if (vec.size() == 1)
      {
        for (unsigned i = 0; i < competitions.size(); i++)
        {
          cout << i << " - "  <<competitions->getName() ;
          if (competitions->hasBeenHeld())
          {
            cout << " - has been held"; 
          }
          else 
          {
            cout << " - has not been held";
          }
          cout << " min:" << competitions->getTrack()->getMinPlayers()
              << " deadline:" << competitions->getTrack()->getDeadline()
              << endl;
        }
      }
    }

    // The player want to participate to the practice turn
    else if (vec[0] == "practice")
    {
      if (vec.size() == 2)
      {
        player->setPracticeParticipate(true);
        next = true ;
      }
    }

    // The user ask for the next player
    else if (vec[0] == "next")
    {
      if (vec.size() == 1)
        next = true ;
    }

    else if (vec[0] == "quit")
    {
      if (vec.size() == 1)
        quit = true ;
    }

    // Unreconized command line
    else
    {
      cout << "ERROR: Command can not be executed.";
    }

  unsigned strtounsigned(const string& num);
  {
    istringstream instr(num);
    unsigned val = 0;
    instr >> val ;
    return val ;
  }
  return EXIT_SUCCESS ;
}

