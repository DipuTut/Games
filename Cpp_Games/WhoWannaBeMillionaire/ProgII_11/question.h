//
//  question.h
//  ProgII_11
//
//  Created by Md. Asadul Haque on 9/12/11.
//  Copyright 2011 Tampere University of Technology. All rights reserved.
//

#ifndef QUESTION_H
#define QUESTION_H

#include <string> 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cctype>
#include <locale>
#include <cmath>
#include <vector>
#include "player.h"
#include "game.h"


using namespace std ;


class Question 
{
public:
    Question() ;
    Question(string question,string answerKey,string level) ;
    ~Question() ;
    
    
    
   void printQuestionSet(const char *file,string Name_) ;
   void gameLevels(unsigned LevelDef,vector<string>& vQuesLevel) ; 
   void LevelView(const char *file,string Name_,vector<string>& vQuesList,vector<string>& vAnsOption,vector<string>& vAnsKey,vector<string>& vAnsKeyFF, unsigned LevelNum) ;
    void DareDashRound(const char *file,string Name_) ;

    string convertUpper(string Ch)
    { locale loc ;
      for (size_t i=0; i<Ch.length(); ++i)
            Ch[i] = toupper(Ch[i],loc);
        return Ch ;
    }
  
    double Round(double num) {
      return ((num > 0.0) ? floor(num + 0.5) : ceil(num - 0.5));
    }

  
    
    
private:
    string question_ ;
    string answerKey_ ;
    string level_ ;    
    
    
} ;


#endif

