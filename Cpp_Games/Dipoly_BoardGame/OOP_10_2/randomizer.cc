// Randomizer.cc 

#include "randomizer.hh"

#include <cassert>
#include <ctime>

const unsigned COMMON_LIMIT( 4 );
const unsigned RARE_LIMIT( 6 ); 
const int SEED_VAL( 1 );
const int SEED_STEP( 2 );
const int HEXLIMIT( 16 );

Randomizer::Randomizer( unsigned long int seed )
  : faces_( FACES ), seed1_( seed ), seed2_(seed%7+1)
{
   if( seed == 0 )
   {
      seed1_ = std::time( 0 );
      seed2_ = seed1_%7+1;
   }
}

Randomizer::~Randomizer()
{
   // Nothing to do
}

unsigned long int Randomizer::rawCast()
{
  // Päivitä siemen
  seed1_ = SEED_VAL * seed1_ + SEED_STEP;
  seed2_ = SEED_VAL * seed2_ + ( seed1_ >> HEXLIMIT );
  seed1_ &= 0xFFFFul; seed2_ &= 0xFFFFul;

  // allot a number between  0 .. rawmax_
  unsigned long int rawNumber = ( ( seed1_ & 0x7FFFul ) << HEXLIMIT ) | seed2_;
  return rawNumber;
}

Utility::Weather Randomizer::calculateWeather( Utility::TrackType trackType )
{
   unsigned long weather = cast();
   if( weather < COMMON_LIMIT )
   {
      if( trackType == Utility::SNOW ){ return Utility::SNOWY; }
      else if( trackType == Utility::ASPHALT ){ return Utility::SUNNY; }
      else if( trackType == Utility::SAND ){ return Utility::RAINY; } 
      // just in case there will be other weather types added later...
   }
   else if( weather < RARE_LIMIT )
   {
      if( trackType == Utility::SNOW ){ return Utility::SUNNY; }
      else if( trackType == Utility::ASPHALT ){ return Utility::RAINY; }
      else if( trackType == Utility::SAND ){ return Utility::SUNNY; }
   }
   if( trackType == Utility::SNOW ){ return Utility::RAINY; }
   else if( trackType == Utility::ASPHALT ){ return Utility::SNOWY; }
   else if( trackType == Utility::SAND ){ return Utility::SNOWY; }
   return Utility::SUNNY;  
}

unsigned long int Randomizer::cast()
{
  // create a limit 
  unsigned long int rawLimit = rawmax_ - (rawmax_ - faces_) % (faces_+1);

  // Cast as long as we get a number within the limit
  unsigned long int rawNumber = 0;
  do { rawNumber = rawCast(); } while (rawNumber > rawLimit);

  // scale the result between 1-faces 
  unsigned long int number = rawNumber % faces_ + 1;
  assert(number <= faces_);
  return number;
}
