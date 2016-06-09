/// \file Utility.cc
///
/// \brief Utility functions, source file 

#include "utility.hh"
#include "track.hh"
#include "initexception.hh"
#include "chopper.hh"

#include <cctype>
#include <sstream>
//#include <ctime>
//#include <cstdlib>

using std::string;
using std::toupper;
using std::tolower;

namespace Utility
{   
  /// Street -struct from a string
  Track string2Track( std::string trackInfo )
  { 
    Chopper chop( trackInfo );
    string name = chop.getStr( 0 );
    unsigned difficulty = chop.getField<int>( 1 );
    //unsigned id = 0; // set only when returing the collection of tracks 
    string roadType = chop.getStr( 2 );
    unsigned idealTime = chop.getField<unsigned>( 3 );
    unsigned minPlayers = chop.getField<unsigned>( 4 );
    unsigned deadline = chop.getField<unsigned>( 5 );

    /// convert the track type forom string to unsigned value
    unsigned tempRT;
    if(roadType == "asphlt")
      tempRT = ASPHALT;
    else if(roadType == "sand")
      tempRT = SAND;
    else
      tempRT = SNOW;

    // Create the track
    return Track(name, difficulty, tempRT, idealTime, minPlayers, deadline);
  }
  
  std::ostream& operator <<( std::ostream& os,
			     const Track& tt )
  {
    os << tt.getName() << " - " << tt.getRoadType() << ", difficulty: " 
       << tt.getDifficulty() << ", idealTime: " << tt.getIdealTime()
       << ", min. Players: " << tt.getMinPlayers()
       << ", deadline: " << tt.getDeadline() <<std::flush;
    return os;
  }
  
  
  string int2string( int toString )
  {   
    std::stringstream ss;
    ss << toString;
    return ss.str();
  }
  
  
  string upperCase( const string& target )
  {     
    string rval;
    for( unsigned i = 0; i < target.size(); ++i )
    {
      switch( target.at(i) )
      {
      case 'å':
        rval += 'Å';
    	break;
      case 'ä': 
        rval += 'Ä';
    	break;
      case 'ö': 
        rval += 'Ö';
    	break;
      default: 
        rval += static_cast<char>( toupper( target.at(i) ) );
      };
    }   
    return rval;
  }
    
  
  string lowerCase( const string& target )
  {     
    string rval;
    for( unsigned i = 0; i < target.size(); ++i )
    {
       rval += static_cast<char>( tolower( target.at(i) ) );
    }   
    return rval;
  }
  /// removes white space from beginning and the end of the string
  string removeWhiteSpace( const string& target, const string& empty )
  {  
    if( target.empty() ){ return target; }
    string rval = target.substr( target.find_first_not_of( empty ) );
    return rval.substr( 0, rval.find_last_not_of( empty )+1 );
  }
}
