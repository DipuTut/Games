//
//  main.cpp
//  ProgII_11
//
//  Created by Md. Asadul Haque on 9/25/11.
//  Copyright 2011 Tampere University of Technology. All rights reserved.
//


#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "game.h"
#include "player.h"



int main (int argc, char* const argv[])
{
     const char *File = "/Users/Dipu/ProTasks/ProgII_11/ProgII_11/textFile.txt" ;
     
    Game* Start = NULL ;
    Start->mainMenu(File) ;
      
    
    
    cout << endl ;
    cout << "The program runs" << endl ;
       
    return EXIT_SUCCESS ;
}


