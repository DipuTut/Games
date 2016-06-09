//
//  game.cpp
//  ProgII_11
//
//  Created by Md. Asadul Haque on 9/13/11.
//  Copyright 2011 Tampere University of Technology. All rights reserved.
//



#include "game.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std ;


Game::Game()
{
}

void Game::mainMenu(const char *file)
{
    cout << "********************************" << endl ;
    cout << " WHO WANTS TO BE A MILLIONAIRE? " << endl ;
    cout << "********************************" << endl << endl ;
    cout <<"[1] Start Game" << endl ;
    cout <<"[2] Instructions" << endl ;
    cout <<"[3] Player Statistics" << endl ; 
    cout <<"[4] Quit" << endl ;
    cout << endl ;
    cout << "Your Choice: "  ;
    unsigned int Selected ;
    
    cin >> Selected ;
    
    switch (Selected)
    {
       case 1: cout << "[1] Select Player" << endl ;
               cout << "[2] New Player" << endl ;
            cout << endl ;
            cout << "Your Choice: "  ;
            unsigned int Selected2 ;
            cin >> Selected2 ;
            switch (Selected2)
        {
                case 1:
                {  Player* pList = NULL ;
                   pList->PlayerList(file) ;
                   break;
                }
            
                case 2:
              {   
                Player* addName = NULL ;
                addName->addNewName(file) ;
                break ;
               }
            default: cout <<"Not a Valid choice" << endl ;
                    break;
        }            
            
            
            break ;
		case 2: cout << "INSTRUCTIONS FOR THE GAME: " << endl ;
                cout << " The player answers the asked questions one by one. Questions are multiple choice questions with four answer options (labelled A, B, C and D) and only one option is correct. There is no time limit to answer a question. Each question has a difficulty level and a corresponding prize. The player gets one question from each difficulty level. There are 13 levels." << endl << endl ; 
			return mainMenu(file) ;	
        case 3: 
        { cout << "PLAYER STATISTICS: " << endl<< endl ;
            Player* plStat = NULL ;
            plStat->PlayerStat(file) ;  
            cout << endl ;
            return mainMenu(file) ;
        }
        case 4: cout << "Quit from the Game" << endl ;
            
        //    gameOn = false ;
            break ;
        default: cout << "Not a Valid Choice" << endl  ;
           return mainMenu(file) ;     
           
    }

}



void Game::gameView(const char *file,string plName_)
{
    // int lifeLines = 3 ;
    cout << endl << endl ; 
    cout<< "Lifelines" << endl ;
    cout << "2   [F] Fifty-Fifty" << "   2   [P] Audience Poll" << endl ;
    
    cout << "*********************" << endl ; 
    cout << "Levels and Prizes" << endl << endl ;
  
    
    cout << endl ; 
    cout << "13 Dare and Dash Round!!" << endl ;
    cout << "12  €1,000,000" << endl ;
    cout << "11  €500,000" << endl ;
    cout << "10  €250,000" << endl ;
    cout << " 9  €125,000" << endl ;
    cout << " 8  €64,000" << endl ;
    cout << " 7  €32,000" << endl ;
    cout << " 6  €16,000" << endl ;
    cout << " 5  €8,000" << endl ;
    cout << " 4  €4,000" << endl ;
    cout << " 3  €2,000" << endl ;
    cout << " 2  €1,000" << endl ;
    cout << "> 1 €500" << endl ; 
    cout << "*********************" << endl ;
    
    
    Question* quesSet = NULL ;
    quesSet->printQuestionSet(file,plName_) ;

    
    
}

void Game::subMenu(const char *file,string plName_)
{
    cout << "[1] Play again" << endl ;
    cout << "[2] Return to main menu" << endl ; 
    int Select ;
    cout << "Your choice: "  ;
    cin >> Select ;
    
    if (Select == 1) {
        Question* prQues = NULL ;
        prQues->printQuestionSet(file,plName_) ;
    }
    
    else  if(Select == 2)
    {
        Game* gm = NULL ;
        gm->mainMenu(file) ;
    }
    else
    { cout << "Invalid choice" << endl ; }
    
}

void Game::subMenuDareDash(const char *file,string plName_)
{
    cout<< "[1] Play again " << endl ;
    cout<< "[2] Dare and Dash Round!! " << endl ;
    cout<< "[3] Return to main menu " << endl ;
    int Select ;
    cout << "Your choice: "  ;
    cin >> Select ;
    
    if (Select == 1) {
        Question* prQues = NULL ;
        prQues->printQuestionSet(file,plName_) ;
    }
    else  if(Select == 2)
    {
        Question* DDround = NULL ;
        DDround->DareDashRound(file,plName_) ;
    }
    
    
    else  if(Select == 3)
    {
        Game* gm = NULL ;
        gm->mainMenu(file) ;
    }
    else
    { cout << "Invalid choice" << endl ; }
    
}





Game::~Game()
{
}



