

// car.hh
 
  /*
   * Author: Asadul Haque
   * Date : 22 04 2010
   * Description : Declaration of the Car class
   *
   */
  
#ifndef CAR_HH
# define CAR_HH

#include <string>
#include "utility.hh" // For drive wheel and tyre constants

class Car
{
   
 public: 
   
   // Constructor
   Car();
   Car(unsigned _steering, unsigned _driveWheel,
       unsigned _tireType, bool _tunned);
   
   // Destructor
   ~Car() ;
   
   // Operator =
   Car operator=(const Car&) ;
   // Copy constructor
   Car (const Car&) ; 
   
   // Getter (Accessors)
   unsigned getSteering() const;
   unsigned getDriveWheel() const;
   unsigned getTireType() const;
   bool getTunned() const;

   // Setters (Mutators)
   void setSteering(unsigned _steering);
   void setDriveWheel(unsigned _driveWheel);
   void setTireType(unsigned _tireType);
   void setTunned(bool _tunned);
   
 private:
   
   // Private data members
   unsigned steering;
   unsigned driveWheel;
   unsigned tireType;
   bool tunned ;
   
   };
   
 #endif 
