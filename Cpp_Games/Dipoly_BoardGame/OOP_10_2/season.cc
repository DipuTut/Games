
  //season.cc                                                                   
                                                                                  
  /*                                                                              
   *   Author: Asadul Haque                                                         
   *   Date: 01.05.2010                                                             
   *   Description: Defination of the Season class                                 
   *  
   */                            
                                                                                     
#include <string>
#include <vector>
#include <cstdlib>

#include "competition.hh"
#include "player.hh"
#include "randomizer.hh"
#include "season.hh"
#include "initreader.hh"
#include "track.hh"
#include "utility.hh"
#include "userInterface.hh"


using namespace std;

const string WEATHER[] = { "sunny", "rainy", "snowy" };



// Constructor
Season::Season():competitions(),
                 players(),
                 fileName(),
                 name(),
                 randomizer(),
                 seed(),
                 numberOfPlayers()

{
}

Season::Season(unsigned _seed, unsigned _numberOfPlayers, string _fileName)
{
   numberOfPlayers = _numberOfPlayers;
   seed = _seed;
   fileName = _fileName;
}

// Destructor
Season::~Season()
{
  for(unsigned i = 0; i < players.size(); i++)
    delete players[i];
  players.clear();
}

// Methods
void Season::setCompetition(std::vector<Competition*> _competitions)
{
  competitions = _competitions;
}

void Season::setPlayers()
{
  // For each player set the size of the vector participation
  // to the same size of the number of competition
  for(unsigned i = 0; i < numberOfPlayers; i++)
  {
    string str;           // To get the name of the player
    bool found =  false;  

    do{
      cout << "Player " << i+1 << " name:";
      getline(cin,str);
    } while(exist(str));
    // Create the player

    players.push_back(new Player(str));

    // Initialize the participate vector
    vector<bool> vec;

    // We don't know the number of competition yet
    // It's not a problem since participate is only
    // a vecto of bool 8 values / octet
    // here vector participate will be 16 octets 
    for(unsigned j = 0; j < 128; j++)//competitions.size(); j++)
      vec.push_back(true);

    players.back()->setParticipate(vec);
  }
}


// To check is the name is already took
bool Season::exist(string _name) const
{
  bool found = false;

  for(unsigned i = 0; i < players.size(); i++)
  {
    if(players[i]->getName() == _name)
      found = true;
  }

  return found;
}



void Season::printFinalResult()
{
  // print final points
  for(unsigned i = 0; i < players.size(); i++)
  {
    cout << players[i]->getName() << ":" <<  players[i]->getPoints() << endl;
  }
}

//  
unsigned Season::getNumberOfCompetitions() const
{
  return competitions.size();
}
  
void Season::startSeason()
{
  // Ask for players names
  setPlayers();

  // Load the track file
  try
  {
    InitReader reader;
    reader.readFile(fileName);
    //reader.printData(cout);
    //cout << "seed value: " << reader.seed() << endl;
    name =  reader.championshipName() ;

    // create a randomizer and initialize it with the seed
    // seed value took into the file
    randomizer = new Randomizer( reader.seed() );
    //randomizer = new Randomizer( seed );

    // read the streets from init reader
    InitReader::Tracks tracks = reader.getTracks();

    unsigned count = 0;
    // iterate the vector using an iterator
    for( InitReader::Tracks::iterator it = tracks.begin(); 
        it != tracks.end(); ++it )
    {
      competitions.push_back(new Competition(new Track((*it)), players, randomizer,count));
      ++count;
    }

  }
  catch( FileError& fe )
  {
    cout << fe.description() << endl;
  }
  catch( ... )
  {
    cout << "An exception..." << endl;
  }


  // Create a CLI object
  UserInterface cli = UserInterface(players, competitions);
  
  bool quit = false;
  // Start cli and start each competitioin
  for( vector<Competition*>::iterator it = competitions.begin(); 
      it != competitions.end()
      && !quit;
      ++it )
  {
    // Start the user interface
    quit = cli.cli();

    // Start the competition
    if(!quit)
      (*it)->startCompetition();

  }
}
