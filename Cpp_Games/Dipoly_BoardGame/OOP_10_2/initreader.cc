/// \file  InitReader.cc
///
/// \brief InitReader -class source code
// 


#include "initreader.hh"
#include "utility.hh"

#include <fstream>
#include <cstdlib>
#include <sstream>

using std::string;
using std::ifstream;
using std::cout;
using std::endl;
using std::vector;
using  Utility::int2string;
using  Utility::removeWhiteSpace;
using  Utility::upperCase;

// init file tags, 
const string TAG_OPEN = "[";
const string TAG_CLOSED = "]";
const string ENDTAG_OPEN = "[/";

// init file key values
const string CHAMP_NAME( "name" );
const string SEED_VALUE( "seed" );
const string RACE( "track" );


// check if readD is a key  keyV, with open tag in start and close tag
// in end
// If keyV is empty, the key found is the value of it after function call
// if the readD is a key, return value is true, otherwise false.
bool keyvalue( const string& readD, string& keyvalue, 
               const string& start = TAG_OPEN,
               const string& closed = TAG_CLOSED );


InitReader::InitReader(): initdata_()
{
}


InitReader::~InitReader()
{
   // nothing to do
}


void InitReader::readFile( const string& filename )
{
   // we open the file for reading
   ifstream initFile( filename.c_str() );
   if( !initFile.is_open() )
   {
      string errMsg = "ERROR: Failed to open file \"" + 
                      filename + "\".";
      FileError fileEx( errMsg );
      throw fileEx;
   } 

   int lineNbr( 0 );

   // read the file until it ends
   while( !initFile.eof() )
   { 
      ++lineNbr;
      string  line, value, keyV, keyVClosed;
      std::getline( initFile,  line );

      if( line.empty() ){ continue; } // skip all the empty lines
      if( keyvalue( line, keyV ) )
      {
         // read the value 
         while( !initFile.eof() )
         {
            std::getline( initFile, line ); 
            ++lineNbr;
            if( keyvalue( line, keyVClosed, ENDTAG_OPEN ) )
            {
               break;
            }

            string testKey;

            // Check if a new field is opened in middle of another
            // We do not support hierarchical definitions...
            if( keyvalue(  line, testKey ) )
            {
               string errMsg = 
                  "ERROR: New tag opens before the previous was closed";
               errMsg += ". line: " + 
                            int2string( lineNbr );
               FileError fExcept( errMsg );
               throw fExcept;
            }
            if( !value.empty() ){ value += "\n"; }
            value +=  line;
         }

         // If the key opened differs from the closing key, its an error
         if( keyV != keyVClosed )
         {
            string  errMsg = 
               "ERROR: Opening and closing tag are different. line: " + 
               int2string( lineNbr );
            FileError fileExcept(  errMsg );
            throw fileExcept;
         }
      }
      else // not a key value...
      {
         string  errMsg = 
               "ERROR: Data outside tags \"" + line + "\", line " + 
               int2string( lineNbr );
            FileError fileExcept(  errMsg );
            throw fileExcept;
      }
      // Everything was fine, save the information
      initdata_.insert( std::pair< string, string >( keyV, value ) );
   }
}



void InitReader::printData( std::ostream& out ) const
{
   out << "Printing the contents of the init file..." << endl;
   for( Initdata::const_iterator it = initdata_.begin();
        it != initdata_.end(); ++it )
   {
      out << "key: " << it->first << endl
          << "value: " << it->second << endl;
   }
}


std::string InitReader::championshipName() const
{
   if( initdata_.find( CHAMP_NAME ) == initdata_.end() )
   {
      std::string errorMsg = "There was no \"" + CHAMP_NAME +
                             "\" keys/definitions in file.";
      FileError expt( errorMsg );
      throw expt;
   }

   return initdata_.find( CHAMP_NAME )->second;
}


unsigned InitReader::seed() const
{
   return getValue<unsigned>( SEED_VALUE );
}

InitReader::Tracks InitReader::getTracks() const
{
   Tracks mtracks;
   // int idcounter( 0 );
   // fetch all streets from multimap
   Initdata::const_iterator start = initdata_.lower_bound( RACE );
   Initdata::const_iterator last = initdata_.upper_bound( RACE );
   for(; start != last; ++start )
   {
      string datastring = start->second;
      try
      {
          Track rcs = Utility::string2Track( datastring );
          //rcs.id = ++idcounter;
          mtracks.push_back( rcs );
      }
      catch( TypeConversionError& )
      {         
         // Conversion failed, convert it to FileError
         FileError strErr( "Incorrect street definition: " + datastring );
         throw strErr;
      }
   }

   return mtracks;
}

bool keyvalue( const string& readD, string& keyvalue, 
                const string& start,
                const string& closed )
{
   if( readD.empty() ){ return false; }

   string keyV = removeWhiteSpace( readD );

   // check the the string we read contains start ja closed tags
   if( start == keyV.substr( 0, start.size() ) &&
       closed == keyV.substr( keyV.size() - closed.size(), keyV.size() ) )
   {
      // remove the whitespace from keyV
      keyV = keyV.substr( start.size(), keyV.size() );
      keyV = keyV.substr( 0, keyV.size() - closed.size() );

      // If we are looking for a certain keyvalue, we need to 
      // check the key we got is same as the key given as parameter
      if( !keyvalue.empty() && upperCase( keyvalue ) != upperCase( keyV  ) )
      {
         return false;
      }
      // Else we save the key we read to the keyvalue parameter
      keyvalue = keyV;
      return true;
   }
   return false;
}
