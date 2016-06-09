/// \file utility.hh
///
/// \brief Utility functions for Dipoly init file reader etc.

#ifndef UTILITY_HH
#define UTILITY_HH

#include <string>
#include <iostream>
#include "track.hh"


// Weather const
const unsigned SUNNY(0);
const unsigned RAINY(1);
const unsigned SNOWY(2);

// Road type const
const unsigned ASPHALT(0);
const unsigned SAND(1);
const unsigned SNOW(2);

//Tire type
const unsigned NORMAL(0);
const unsigned RAIN(1);
const unsigned STUDDED(2);

// Four/Back Wheel
const unsigned FOUR_WHEEL(0);
const unsigned BACK_WHEEL(1);


// drive Wheel Factor [ROAD TYPE] [FOUR/BACK WHEEL]
const unsigned DRIVE_WHEEL_FACTOR[3][2] = {
               { 12, 14 },
               { 16, 12 },
               { 20, 16 } };

// Weather/Tire Factor [TIRE TYPE] [WEATHER]
const unsigned WEATHER_TIRE_FACTOR[3][3] = {
               { 10, 13, 19 },
               { 16, 10, 17 },
               { 18, 17, 10 } };



namespace Utility
{
   const std::string WHITE_SPACE = " \t";
   enum Weather{ SUNNY, RAINY, SNOWY };
   enum TrackType{ ASPHALT, SNOW, SAND };
 
   /// converts integer to string
   std::string int2string( int toString );

   /// change string into UPPER case
   std::string upperCase( const std::string& target );
   /// change string into lower case
   std::string lowerCase( const std::string& target );

   /// removes whitespace from beginning and end of the string
   std::string removeWhiteSpace( const std::string& target, 
                                 const std::string& empty = WHITE_SPACE );


  /// Creating a card from a string
  /// Throws: InitExceptions, if streetinfo is invalid
  Track string2Track( std::string raceInfo );

  /// Printing Track datatype on screen
  std::ostream& operator <<( std::ostream& os, 
                           const Track& tt );
}



#endif
