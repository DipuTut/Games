/// \file arpa.hh
///
/// \brief Randomizer class for random weather related to the rallies.
/// Use calculateWeather to get the next weather for the race.
/// Create Randomizer once and use the same object throughout the runtime of 
/// the application.

#ifndef RANDOMIZER_HH
#define RANDOMIZER_HH

#include "utility.hh"

class Randomizer
{
public:

  /// Constructor creates a new dice and sets the seed
  /// Number of faces the dice has (standard dice has six faces)
  Randomizer( unsigned long seed = 0 );
  ~Randomizer();

   /// Gives the weather
   Utility::Weather calculateWeather( Utility::TrackType trackType );

private:

   // No need to create copies of a die
   Randomizer( const Randomizer& );
   Randomizer& operator =( const Randomizer& );

   unsigned long rawCast();
   unsigned long int cast();

   const unsigned long faces_;
   unsigned long seed1_;
   unsigned long seed2_;
   static unsigned long const rawmax_ = 0x7FFFFFFFul;
   static unsigned long const FACES = 6;
};


#endif
