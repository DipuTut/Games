
// car.cc

/*
 * Author: Asadul Haque
 * Date : 22 04 2010
 * Description : Definition of Car class
 * 
 */

#include <string>
#include "car.hh"

using namespace std;

//Constructor
Car::Car():steering(),driveWheel(),tireType(),tunned()
{
}

Car::Car(unsigned _steering, unsigned _driveWheel,
                    unsigned _tireType, bool _tunned)

{
   steering = _steering;
   driveWheel = _driveWheel;
   tireType = _tireType;
   tunned = _tunned;
   
}

// Copy constructor
Car::Car(const Car& car)
{
  this->steering = car.getSteering();
  this->driveWheel = car.getDriveWheel();
  this->tireType = car.getTireType();
  this->tunned = car.getTunned();
}

Car Car::operator=(const Car& car)
{
  Car c;
   c.steering = car.getSteering();
   c.driveWheel = car.getDriveWheel();
   c.tireType = car.getTireType();
   c.tunned = car.getTunned();
   return c;
}

// Destructor
Car::~Car()
{
}

// Getter (Accessors)
unsigned Car::getSteering() const
{
  return steering;
}

unsigned Car::getDriveWheel() const
{
  return driveWheel;
}

unsigned Car::getTireType() const
{
  return tireType;
}

bool Car::getTunned() const
{
  return tunned;
}

//Setter (Mutators)

void Car::setSteering(unsigned _steering)
{
  steering = _steering ;
}

void Car::setDriveWheel(unsigned _driveWheel)
{
  driveWheel = _driveWheel ;
}

void Car::setTireType(unsigned _tireType)
{
  tireType = _tireType ;
}

void Car::setTunned(bool _tunned)
{
  tunned  = _tunned ;
}
