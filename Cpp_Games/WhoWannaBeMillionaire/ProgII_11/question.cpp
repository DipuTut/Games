//
//  question.cpp
//  ProgII_12
//
//  Created by Md. Asadul Haque on 9/12/11.
//  Copyright 2011 Tampere University of Technology. All rights reserved.
//

#include "question.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

using namespace std ;

 Question::Question()
 { 
 }

Question::~Question()
{
 //   cout << "Deleting" << endl ;
}




void Question:: printQuestionSet(const char *file,string Name_) 
{
    vector<string> vQuesListV1 ;
    vector<string> vQuesListV2 ;
    vector<string> vQuesListV3 ;
    vector<string> vAnsKeyV1 ;
    vector<string> vAnsKeyV2 ;
    vector<string> vAnsKeyV3 ;
    vector<string> vAnsKeyFFV1 ;
    vector<string> vAnsKeyFFV2 ;
    vector<string> vAnsKeyFFV3 ;
    
    
    
    //storing answer options to vector
    
    vector<string> vAnsOptionL1v1 ;
    vector<string> vAnsOptionL2v1 ;
    vector<string> vAnsOptionL3v1 ;
    vector<string> vAnsOptionL4v1 ;
    vector<string> vAnsOptionL5v1 ;
    vector<string> vAnsOptionL6v1 ;
    vector<string> vAnsOptionL7v1 ;
    vector<string> vAnsOptionL8v1 ;
    vector<string> vAnsOptionL9v1 ;
    vector<string> vAnsOptionL10v1 ;
    vector<string> vAnsOptionL11v1 ;
    vector<string> vAnsOptionL12v1 ;
    vector<string> vAnsOptionL1v2 ;
    vector<string> vAnsOptionL2v2 ;
    vector<string> vAnsOptionL3v2 ;
    vector<string> vAnsOptionL4v2 ;
    vector<string> vAnsOptionL5v2 ;
    vector<string> vAnsOptionL6v2 ;
    vector<string> vAnsOptionL7v2 ;
    vector<string> vAnsOptionL8v2 ;
    vector<string> vAnsOptionL9v2 ;
    vector<string> vAnsOptionL10v2 ;
    vector<string> vAnsOptionL11v2 ;
    vector<string> vAnsOptionL12v2 ;
    vector<string> vAnsOptionL1v3 ;
    vector<string> vAnsOptionL2v3 ;
    vector<string> vAnsOptionL3v3 ;
    vector<string> vAnsOptionL4v3 ;
    vector<string> vAnsOptionL5v3 ;
    vector<string> vAnsOptionL6v3 ;
    vector<string> vAnsOptionL7v3 ;
    vector<string> vAnsOptionL8v3 ;
    vector<string> vAnsOptionL9v3 ;
    vector<string> vAnsOptionL10v3 ;
    vector<string> vAnsOptionL11v3 ;
    vector<string> vAnsOptionL12v3 ;
    
    
    ifstream inFile ;
    inFile.open(file,ios::in|ios::binary) ;
    
    string Ch ;
    while (!inFile.eof() && Ch != "QuesListV1")
    {  getline(inFile,Ch);
        if (Ch != "QuesListV1")  
        {vQuesListV1.push_back(Ch) ; }
    }  
    
    while (!inFile.eof() && Ch != "QuesListV2")
    {  getline(inFile,Ch);
        if (Ch != "QuesListV2")  
        {vQuesListV2.push_back(Ch) ; }
    }  
    
    while (!inFile.eof() && Ch != "QuesListV3")
    {  getline(inFile,Ch);
        if (Ch != "QuesListV3")  
        {vQuesListV3.push_back(Ch) ; }
    }  
    
    
    while (!inFile.eof() && Ch != "AnsOptionL1v1")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL1v1")  
        {  
            vAnsOptionL1v1.push_back(Ch) ;
        }
    } 
    
    while (!inFile.eof() && Ch != "AnsOptionL2v1")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL2v1")  
        {  
            vAnsOptionL2v1.push_back(Ch) ;
        }
    } 
    
    
    while (!inFile.eof() && Ch != "AnsOptionL3v1")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL3v1")  
        {  
            vAnsOptionL3v1.push_back(Ch) ;
        }
    } 
    
    
    while (!inFile.eof() && Ch != "AnsOptionL4v1")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL4v1")  
        {  
            vAnsOptionL4v1.push_back(Ch) ;
        }
    } 
    
    while (!inFile.eof() && Ch != "AnsOptionL5v1")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL5v1")  
        {  
            vAnsOptionL5v1.push_back(Ch) ;
        }
    } 
    
    
    while (!inFile.eof() && Ch != "AnsOptionL6v1")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL6v1")  
        {  
            vAnsOptionL6v1.push_back(Ch) ;
        }
    } 
    
    
    while (!inFile.eof() && Ch != "AnsOptionL7v1")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL7v1")  
        {  
            vAnsOptionL7v1.push_back(Ch) ;
        }
    } 
    
    
    while (!inFile.eof() && Ch != "AnsOptionL8v1")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL8v1")  
        {  
            vAnsOptionL8v1.push_back(Ch) ;
        }
    } 
    
    
    while (!inFile.eof() && Ch != "AnsOptionL9v1")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL9v1")  
        {  
            vAnsOptionL9v1.push_back(Ch) ;
        }
    } 
    
    
    while (!inFile.eof() && Ch != "AnsOptionL10v1")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL10v1")  
        {  
            vAnsOptionL10v1.push_back(Ch) ;
        }
    } 
    
    while (!inFile.eof() && Ch != "AnsOptionL11v1")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL11v1")  
        {  
            vAnsOptionL11v1.push_back(Ch) ;
        }
    } 
    
    while (!inFile.eof() && Ch != "AnsOptionL12v1")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL12v1")  
        {  
            vAnsOptionL12v1.push_back(Ch) ;
        }
    } 
    
    while (!inFile.eof() && Ch != "AnsOptionL1v2")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL1v2")  
        {  
            vAnsOptionL1v2.push_back(Ch) ;
        }
    } 
    
    while (!inFile.eof() && Ch != "AnsOptionL2v2")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL2v2")  
        {  
            vAnsOptionL2v2.push_back(Ch) ;
        }
    } 
    
    while (!inFile.eof() && Ch != "AnsOptionL3v2")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL3v2")  
        {  
            vAnsOptionL3v2.push_back(Ch) ;
        }
    } 
    
    while (!inFile.eof() && Ch != "AnsOptionL4v2")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL4v2")  
        {  
            vAnsOptionL4v2.push_back(Ch) ;
        }
    } 
    
    
    while (!inFile.eof() && Ch != "AnsOptionL5v2")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL5v2")  
        {  
            vAnsOptionL5v2.push_back(Ch) ;
        }
    } 
    
    
    while (!inFile.eof() && Ch != "AnsOptionL6v2")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL6v2")  
        {  
            vAnsOptionL6v2.push_back(Ch) ;
        }
    } 
    
    while (!inFile.eof() && Ch != "AnsOptionL7v2")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL7v2")  
        {  
            vAnsOptionL7v2.push_back(Ch) ;
        }
    } 
    
    while (!inFile.eof() && Ch != "AnsOptionL8v2")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL8v2")  
        {  
            vAnsOptionL8v2.push_back(Ch) ;
        }
    } 
    
    while (!inFile.eof() && Ch != "AnsOptionL9v2")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL9v2")  
        {  
            vAnsOptionL9v2.push_back(Ch) ;
        }
    } 
    
    while (!inFile.eof() && Ch != "AnsOptionL10v2")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL10v2")  
        {  
            vAnsOptionL10v2.push_back(Ch) ;
        }
    } 
    
    while (!inFile.eof() && Ch != "AnsOptionL11v2")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL11v2")  
        {  
            vAnsOptionL11v2.push_back(Ch) ;
        }
    } 
    
    while (!inFile.eof() && Ch != "AnsOptionL12v2")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL12v2")  
        {  
            vAnsOptionL12v2.push_back(Ch) ;
        }
    } 
    
    while (!inFile.eof() && Ch != "AnsOptionL1v3")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL1v3")  
        {  
            vAnsOptionL1v3.push_back(Ch) ;
        }
    } 
    
    while (!inFile.eof() && Ch != "AnsOptionL2v3")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL2v3")  
        {  
            vAnsOptionL2v3.push_back(Ch) ;
        }
    } 
    
    while (!inFile.eof() && Ch != "AnsOptionL3v3")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL3v3")  
        {  
            vAnsOptionL3v3.push_back(Ch) ;
        }
    } 
    
    while (!inFile.eof() && Ch != "AnsOptionL4v3")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL4v3")  
        {  
            vAnsOptionL4v3.push_back(Ch) ;
        }
    } 
    
    while (!inFile.eof() && Ch != "AnsOptionL5v3")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL5v3")  
        {  
            vAnsOptionL5v3.push_back(Ch) ;
        }
    } 
    
    
    while (!inFile.eof() && Ch != "AnsOptionL6v3")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL6v3")  
        {  
            vAnsOptionL6v3.push_back(Ch) ;
        }
    } 
    
    while (!inFile.eof() && Ch != "AnsOptionL7v3")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL7v3")  
        {  
            vAnsOptionL7v3.push_back(Ch) ;
        }
    } 
    
    while (!inFile.eof() && Ch != "AnsOptionL8v3")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL8v3")  
        {  
            vAnsOptionL8v3.push_back(Ch) ;
        }
    } 
    
    while (!inFile.eof() && Ch != "AnsOptionL9v3")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL9v3")  
        {  
            vAnsOptionL9v3.push_back(Ch) ;
        }
    } 
    
    while (!inFile.eof() && Ch != "AnsOptionL10v3")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL10v3")  
        {  
            vAnsOptionL10v3.push_back(Ch) ;
        }
    } 
    
    while (!inFile.eof() && Ch != "AnsOptionL11v3")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL11v3")  
        {  
            vAnsOptionL11v3.push_back(Ch) ;
        }
    } 
    
    while (!inFile.eof() && Ch != "AnsOptionL12v3")
    {
        getline(inFile,Ch);
        if (Ch != "AnsOptionL12v3")  
        {  
            vAnsOptionL12v3.push_back(Ch) ;
        }
    } 
    
    
    while (!inFile.eof() && Ch != "AnsKeyV1")
    {
        getline(inFile,Ch);
        if (Ch != "AnsKeyV1")  
        { vAnsKeyV1.push_back(Ch) ;}
    }  
    
    while (!inFile.eof() && Ch != "AnsKeyV2")
    {
        getline(inFile,Ch);
        if (Ch != "AnsKeyV2")  
        { vAnsKeyV2.push_back(Ch) ;}
    }  
    
    while (!inFile.eof() && Ch != "AnsKeyV3")
    {
        getline(inFile,Ch);
        if (Ch != "AnsKeyV3")  
        { vAnsKeyV3.push_back(Ch) ;}
    }  
    
    
    while (!inFile.eof() && Ch != "AnsKeyFFV1")
    {
        getline(inFile,Ch);
        if (Ch != "AnsKeyFFV1")  
        {     vAnsKeyFFV1.push_back(Ch) ;}
    }  
    
    
    while (!inFile.eof() && Ch != "AnsKeyFFV2")
    {
        getline(inFile,Ch);
        if (Ch != "AnsKeyFFV2")  
        {     vAnsKeyFFV2.push_back(Ch) ;}
    }  
    
    
    while (!inFile.eof() && Ch != "AnsKeyFFV3")
    {
        getline(inFile,Ch);
        if (Ch != "AnsKeyFFV3")  
        {     vAnsKeyFFV3.push_back(Ch) ;}
    }  
    
    
    int MAX = 3 ;
    srand(time(NULL)) ;
    int Rand = rand()%MAX + 1 ;
    cout << "Question Variant No.: " << Rand << endl ;
    
    cout << endl ;
        
    
    if (Rand == 1) {
        
        Question* LevelDes = NULL ;
        LevelDes->LevelView(file,Name_,vQuesListV1,vAnsOptionL1v1,vAnsKeyV1,vAnsKeyFFV1,1) ;
        LevelDes->LevelView(file,Name_,vQuesListV1,vAnsOptionL2v1,vAnsKeyV1,vAnsKeyFFV1,2) ;
        LevelDes->LevelView(file,Name_,vQuesListV1,vAnsOptionL3v1,vAnsKeyV1,vAnsKeyFFV1,3) ;
        LevelDes->LevelView(file,Name_,vQuesListV1,vAnsOptionL4v1,vAnsKeyV1,vAnsKeyFFV1,4) ;
        LevelDes->LevelView(file,Name_,vQuesListV1,vAnsOptionL5v1,vAnsKeyV1,vAnsKeyFFV1,5) ;
        LevelDes->LevelView(file,Name_,vQuesListV1,vAnsOptionL6v1,vAnsKeyV1,vAnsKeyFFV1,6) ;
        LevelDes->LevelView(file,Name_,vQuesListV1,vAnsOptionL7v1,vAnsKeyV1,vAnsKeyFFV1,7) ;
        LevelDes->LevelView(file,Name_,vQuesListV1,vAnsOptionL8v1,vAnsKeyV1,vAnsKeyFFV1,8) ;
        LevelDes->LevelView(file,Name_,vQuesListV1,vAnsOptionL9v1,vAnsKeyV1,vAnsKeyFFV1,9) ;
        LevelDes->LevelView(file,Name_,vQuesListV1,vAnsOptionL10v1,vAnsKeyV1,vAnsKeyFFV1,10) ;
        LevelDes->LevelView(file,Name_,vQuesListV1,vAnsOptionL11v1,vAnsKeyV1,vAnsKeyFFV1,11) ;
        LevelDes->LevelView(file,Name_,vQuesListV1,vAnsOptionL12v1,vAnsKeyV1,vAnsKeyFFV1,12) ;
        Player *plPrize = NULL ;
        plPrize->updatePrize(file,Name_,1000000,1) ;
        
        Game *M = NULL ;
        M->subMenuDareDash(file,Name_) ;   
    
    }     
    
    else if (Rand == 2) {
        Question* LevelDes = NULL ;
        LevelDes->LevelView(file,Name_,vQuesListV2,vAnsOptionL1v2,vAnsKeyV2,vAnsKeyFFV2,1) ;
        LevelDes->LevelView(file,Name_,vQuesListV2,vAnsOptionL2v2,vAnsKeyV2,vAnsKeyFFV2,2) ;
        LevelDes->LevelView(file,Name_,vQuesListV2,vAnsOptionL3v2,vAnsKeyV2,vAnsKeyFFV2,3) ;
        LevelDes->LevelView(file,Name_,vQuesListV2,vAnsOptionL4v2,vAnsKeyV2,vAnsKeyFFV2,4) ;
        LevelDes->LevelView(file,Name_,vQuesListV2,vAnsOptionL5v2,vAnsKeyV2,vAnsKeyFFV2,5) ;
        LevelDes->LevelView(file,Name_,vQuesListV2,vAnsOptionL6v2,vAnsKeyV2,vAnsKeyFFV2,6) ;
        LevelDes->LevelView(file,Name_,vQuesListV2,vAnsOptionL7v2,vAnsKeyV2,vAnsKeyFFV2,7) ;
        LevelDes->LevelView(file,Name_,vQuesListV2,vAnsOptionL8v2,vAnsKeyV2,vAnsKeyFFV2,8) ;
        LevelDes->LevelView(file,Name_,vQuesListV2,vAnsOptionL9v2,vAnsKeyV2,vAnsKeyFFV2,9) ;
        LevelDes->LevelView(file,Name_,vQuesListV2,vAnsOptionL10v2,vAnsKeyV2,vAnsKeyFFV2,10) ;
        LevelDes->LevelView(file,Name_,vQuesListV2,vAnsOptionL11v2,vAnsKeyV2,vAnsKeyFFV2,11) ;
        LevelDes->LevelView(file,Name_,vQuesListV2,vAnsOptionL12v2,vAnsKeyV2,vAnsKeyFFV2,12) ;
        Player *plPrize = NULL ;
        plPrize->updatePrize(file,Name_,1000000,1) ;
        
        Game *M = NULL ;
        M->subMenuDareDash(file,Name_) ;
    }     
    
    else if (Rand == 3) {
        Question* LevelDes = NULL ;
        LevelDes->LevelView(file,Name_,vQuesListV3,vAnsOptionL1v3,vAnsKeyV3,vAnsKeyFFV3,1) ;
        LevelDes->LevelView(file,Name_,vQuesListV3,vAnsOptionL2v3,vAnsKeyV3,vAnsKeyFFV3,2) ;
        LevelDes->LevelView(file,Name_,vQuesListV3,vAnsOptionL3v3,vAnsKeyV3,vAnsKeyFFV3,3) ;
        LevelDes->LevelView(file,Name_,vQuesListV3,vAnsOptionL4v3,vAnsKeyV3,vAnsKeyFFV3,4) ;
        LevelDes->LevelView(file,Name_,vQuesListV3,vAnsOptionL5v3,vAnsKeyV3,vAnsKeyFFV3,5) ;
        LevelDes->LevelView(file,Name_,vQuesListV3,vAnsOptionL6v3,vAnsKeyV3,vAnsKeyFFV3,6) ;
        LevelDes->LevelView(file,Name_,vQuesListV3,vAnsOptionL7v3,vAnsKeyV3,vAnsKeyFFV3,7) ;
        LevelDes->LevelView(file,Name_,vQuesListV3,vAnsOptionL8v3,vAnsKeyV3,vAnsKeyFFV3,8) ;
        LevelDes->LevelView(file,Name_,vQuesListV3,vAnsOptionL9v3,vAnsKeyV3,vAnsKeyFFV3,9) ;
        LevelDes->LevelView(file,Name_,vQuesListV3,vAnsOptionL10v3,vAnsKeyV3,vAnsKeyFFV3,10) ;
        LevelDes->LevelView(file,Name_,vQuesListV3,vAnsOptionL11v3,vAnsKeyV3,vAnsKeyFFV3,11) ;
        LevelDes->LevelView(file,Name_,vQuesListV3,vAnsOptionL12v3,vAnsKeyV3,vAnsKeyFFV3,12) ;
        Player *plPrize = NULL ;
        plPrize->updatePrize(file,Name_,1000000,1) ;
        Game *M = NULL ;
        M->subMenuDareDash(file,Name_) ;
    }    
     
}



void Question::DareDashRound(const char *file,string Name_) 

{
    cout << "If you give incorrect answer all the money you won will be lost, otherwise you win the double amount.Do you want to face the Dare and Dash Round (Y/N):" ;
    string Choice ;
    cin >>Choice ;
    if (Choice == "Y" || Choice == "y") {
        cout << " *********************" << endl ;
        cout << "Dare and Dash Round!!!" << endl ;
        
        ifstream inFile ;
        inFile.open(file,ios::in|ios::binary) ;
        
        string Ch ;  
        vector<string> vQuesList ;
        vector<string> vAnsOptionDareDash ;
        vector<string>  vAnsKeyV1 ;
        string Alphabet = "ABCD" ; 
        
        // Storing Question Level to vector
        while (!inFile.eof() && Ch != "QuesListV1")
        {
            getline(inFile,Ch);
            if (Ch != "QuesListV1")  
            {
                vQuesList.push_back(Ch) ;
            }
        }  
      
        while (!inFile.eof() && Ch != "AnsOptionL11v1")
        {
            getline(inFile,Ch);
            if (Ch != "AnsOptionL11v1")  
            { }
        }  
        
              
        
        while (!inFile.eof() && Ch != "AnsOptionL12v1")
        {
            getline(inFile,Ch);
            if (Ch != "AnsOptionL12v1")  
            {
            vAnsOptionDareDash.push_back(Ch) ;
            }
        }  
        
        
        while (!inFile.eof() && Ch != "AnsOptionL12v3")
        {
            getline(inFile,Ch);
            if (Ch != "AnsOptionL12v3")  
            {
            }
        }  
        
        // Storing Answer key to vector
        while (!inFile.eof() && Ch != "AnsKeyV1")
        {
            getline(inFile,Ch);
            
            
            if (Ch != "AnsKeyV1")  
            {
                vAnsKeyV1.push_back(Ch) ;
            }
            
        }   
        
        cout << vAnsKeyV1[11] << endl ;
        cout << vQuesList[11] << endl ;  
        for (int i = 0; i<=3; i++) {
            cout << "["<< Alphabet[i]<<"] "<<vAnsOptionDareDash[i] << endl ;  
        }
        
        cout << "Your choice: "  ;
        string ansLDD ;
        cin >> ansLDD ;  
        string ansLDDup = convertUpper(ansLDD) ;            
        
        
        // When player gives the correct answer 
        if (ansLDDup == vAnsKeyV1[11])
        {
            cout << " **** Congratulations!!!! **** " << endl  ;
            cout << " You won €2,000,000! " << endl ;   
            Player *plPrize = NULL ;
            plPrize->updatePrize(file,Name_,2000000,0) ;
            Game *M = NULL ;
            M->subMenu(file,Name_) ;
        }
        else {
            cout << "You have lost all money" << endl ;
            Player *plPrize = NULL ;
            plPrize->updatePrize(file,Name_,0,0) ;
            Game *M = NULL ;
            M->subMenu(file,Name_) ;
        }
        
    }
    
    else {
        Game *M = NULL ;
        M->subMenu(file,Name_) ;
    }
}



void Question::gameLevels(unsigned LevelDef, vector<string>& vAnsOption) 
{
    
    string ABCD = "ABCD" ; 
    int MAX = 3 ;
    srand(time(NULL)) ;
    int rand1 = rand()%MAX + 1 ;
    int rand2 = rand()%MAX + 1 ;
    int rand3 = rand()%MAX + 1 ;
    int rand4 = rand()%MAX + 1 ;
    double sumRand = (rand1+rand2+rand3+rand4) ;
    double PollPer1 = Round((rand1/sumRand)*100) ;
    double PollPer2 = Round((rand2/sumRand)*100) ;
    double PollPer3 = Round((rand3/sumRand)*100) ;
    double PollPer4 = Round((rand4/sumRand)*100) ;
    
    vector<double> vPollPer ;
    vPollPer.push_back(PollPer1) ;
    vPollPer.push_back(PollPer2) ;
    vPollPer.push_back(PollPer3) ;
    vPollPer.push_back(PollPer4) ;
    
    
    switch (LevelDef) {
        case 1:
            for (unsigned i = 0; i<ABCD.size(); i++) {
                cout << "["<< ABCD[i]<<"] "<< vAnsOption[i]<< endl  ; //vAnsOptionL1v1[i] << endl ;  
            }
            cout << "*********************" << endl << endl ;
            cout << "[t] Take money and end the game" << endl << endl ;
            cout << "Your choice: "  ;
            break;
        case 2 :
            for (int i = 0; i<=1; i++) {
                cout <<"["<< ABCD[i]<<"] "<< vAnsOption[2+i] << endl ; 
            }
            cout << "*********************" << endl << endl ;
            cout << "Your choice: "  ;
            break ;
            
        case 3 :
            for (int i = 0; i<=3; i++) {   
                cout << "["<< ABCD[i]<<"] " << vAnsOption[i]<<"   "<<
                "Audience Suggestion: "<< vPollPer[i] <<"%" << endl ; 
            }
            cout << "*********************" << endl << endl ;
            cout << "Your choice: "  ; 
            break ;
            
        default:
            break;
    } 
    
}

void Question::LevelView(const char *file,string Name_, vector<string>&vQuesList,vector<string>& vAnsOption,vector<string>& vAnsKey,vector<string>& vAnsKeyFF,unsigned LevelNum)
{
    
    int arrPrize [13] = {0,500,1000,2000,4000,8000,16000,32000,64000,125000,250000,500000,1000000} ;
    int plAttempt = 1 ;
    //unsigned VarNum = 1 ;
    // Initialization of Level 1
    cout << endl ;
    cout << "Level " << LevelNum << endl ; 
    cout << "Question "<< LevelNum << endl ;
    cout << vQuesList[LevelNum-1] << endl ; 
    
    
    
    Question* S = NULL ;
    S->gameLevels(1,vAnsOption) ;
    
    string ansL1 ;
    cin >> ansL1 ;  
    string ansL1up = convertUpper(ansL1) ;
    
    // When player gives the correct answer 
    if  (ansL1up == vAnsKey[LevelNum-1])
    {
        cout << "Correct!" << endl ;
        cout << "You won " << arrPrize[LevelNum] << endl ;
    }
    
    
    else if  (ansL1up == "F")
    {
        int lifeLines = 2 ;
        cout << endl << endl ; 
        cout<< "Lifelines" << endl ;
        cout << lifeLines<< "    [f] Fifty-Fifty" << endl << endl ;
        cout << "Level " << LevelNum << endl ; 
        cout << "Question "<< LevelNum << endl ;
        cout << vQuesList[LevelNum-1] << endl ; 
        
        S->gameLevels(2,vAnsOption) ;
        
        cin >> ansL1 ;  
        ansL1up = convertUpper(ansL1) ;
        
        if  (ansL1up == vAnsKeyFF[LevelNum-1])
        {
            cout << "Correct!" << endl ;
            cout << "You won €" << arrPrize[LevelNum] << endl ;
        }
        
        else 
        {   cout << "Incorrect!" << endl ;
            cout << "You leave the game with €" << arrPrize[LevelNum-1]<< "!" << endl ;  
            Player *plPrize = NULL ;
            plPrize->updatePrize(file,Name_,arrPrize[LevelNum-1],plAttempt) ;
            
            Game *M = NULL ;
            M->subMenu(file,Name_) ;
            exit(0) ;
        }
        
        
        
    }
    
    else if (ansL1up == "P")
    {   
        cout << endl << endl ; 
        cout<< "Lifelines" << endl ;
        cout << "2   [F] Fifty-Fifty" << "   1   [P] Audience Poll" << endl << endl ;
        cout << "Level " << LevelNum << endl ; 
        cout << "Question "<< LevelNum << endl ;
        cout << vQuesList[LevelNum-1] << endl ; 
        
        S->gameLevels(3,vAnsOption) ;
        
        cin >> ansL1 ;  
        ansL1up = convertUpper(ansL1) ;
        
        if  (ansL1up == vAnsKey[LevelNum-1])
        {
            cout << "Correct!" << endl ;
            cout << "You won €" << arrPrize[LevelNum] << endl ;
        }
        else 
        {   cout << "Incorrect!" << endl ;
            cout << "You leave the game with €" << arrPrize[LevelNum-1]<< "!" << endl ;  
            Player *plPrize = NULL ;
            plPrize->updatePrize(file,Name_,arrPrize[LevelNum-1],plAttempt) ;
            
            Game *M = NULL ;
            M->subMenu(file,Name_) ;
            exit(0) ;
        }
        
    }    
    
    
    // When player takes money and end the game
    else if (ansL1up == "T" || ansL1up == "t")
    {
        cout << "You leave the game with €" << arrPrize[LevelNum-1]<< "!" << endl ; 
        Player *plPrize = NULL ;
        plPrize->updatePrize(file,Name_,arrPrize[LevelNum-1],plAttempt) ;
        
        Game *M = NULL ;
        M->subMenu(file,Name_) ;
        exit(0) ;
    }
    
    // When player gives the incorrect answer
    else 
    {   cout << "Incorrect!" << endl ;
        cout << "You leave the game with €" << arrPrize[LevelNum-1]<< "!" << endl ;  
        Player *plPrize = NULL ;
        plPrize->updatePrize(file,Name_,arrPrize[LevelNum-1],plAttempt) ;
        
        Game *M = NULL ;
        M->subMenu(file,Name_) ;
        exit(0) ;
    }
    
    
}





