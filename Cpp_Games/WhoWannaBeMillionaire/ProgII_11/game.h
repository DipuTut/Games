//
//  game.h
//  ProgII_11
//
//  Created by Md. Asadul Haque on 9/13/11.
//  Copyright 2011 Tampere University of Technology. All rights reserved.
//

#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "question.h"
#include <string> 
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std ;



class Game 
{
    public:
    
    Game() ;
    ~Game() ;
    void mainMenu(const char *file) ;
    void gameView(const char *file,string plName_) ; 
    void subMenu(const char *file,string plName_) ;
    void subMenuDareDash(const char *file,string plName_) ;
     
    
} ;

#endif