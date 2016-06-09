
// season.hh

/*
 * Author: Asadul Haque
 * Date: 01.05.2010
 * Description: Declaration of the Season class
 */
 
 #ifndef SEASON_HH
 #define SEASON_HH

#include <string>
#include <vector>
#include "competition.hh"
#include "player.hh"
#include "randomizer.hh"

class Season
{
 public:
   
   // Constructor
   Season();
   Season(unsigned _seed, unsigned _numberOfPlayers, std::string _fileName);
   
   // Destructor
   ~Season();
     
   // Operator=
   Season operator=(const Season&);
     // copy constructor
   Season(const Season&); 
  
   
   // Method
   void setCompetition(std::vector<Competition*> _competition);
   void setPlayers();
   void printFinalResult();
   void startSeason();
   unsigned getNumberOfCompetitions() const;
   bool exist(std::string _name) const;
   
 private:
   // Private data members
   std::vector<Competition*> competitions;
   std::vector<Player*> players;
   std::string fileName;
   std::string name;
   Randomizer* randomizer;
   unsigned numberOfPlayers;
   unsigned seed;
};

#endif



