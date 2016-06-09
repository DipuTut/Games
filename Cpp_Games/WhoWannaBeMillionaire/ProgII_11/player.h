//
//  player.h
//  ProgII_11
//
//  Created by Md. Asadul Haque on 9/19/11.
//  Copyright 2011 Tampere University of Technology. All rights reserved.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <string> 
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <fstream>
#include "question.h"
#include "game.h"

using namespace std ;


struct node ;
typedef node* nodePtr ;
//node* head ;
struct node { 
    string Name  ;
    int Prize  ;
    int plAttempt ;
    node* next;
};


class Player 
{   
public:
    Player() ;
    ~Player() ;
    
    
    void printList(nodePtr headRef) ;
    void PlayerList(const char *file) ;
    void addNewName(const char *file) ;
    void updatePrize(const char *file,string currName,int winMoney,int Attempt) ;
    void DisplayNamePrize(nodePtr &headRef, string newName,int winPrize,int attempt) ;
    void PlayerStat(const char *file) ;
    void SortList(nodePtr headRef) ;
    
    void deleteTop() ;
    int isEmpty() ; //const ;
        
private: 
    node* head ;
    
} ;

#endif

