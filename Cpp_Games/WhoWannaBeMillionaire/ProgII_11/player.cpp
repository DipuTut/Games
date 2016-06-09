//
//  player.cpp
//  ProgII_11
//
//  Created by Md. Asadul Haque on 9/19/11.
//  Copyright 2011 Tampere University of Technology. All rights reserved.
//

#include "player.h"
#include <iostream>
#include <string>
#include <cstdio>



using namespace std ;


Player::Player() 
{
  head = NULL ;
}

Player::~Player()
{
    while (!isEmpty())
    deleteTop() ; 
}


void Player::deleteTop()
{
  
    if (head){
        nodePtr tempPtr = head ; // Temporary pointer
        head = head->next ;
        delete tempPtr;
    } 
}


int Player::isEmpty() //const
{
    return (head == NULL) ;
}




void Player::printList(nodePtr headRef)
{
    nodePtr currPtr = headRef ;
    while ( currPtr != NULL) {
        cout << currPtr->Name <<"         "<< currPtr->plAttempt
        <<"          "<<currPtr->Prize << "€" << endl ;
        currPtr = currPtr->next ;
    } 
}


void Player::SortList(nodePtr headRef)
{
    
    nodePtr first,second,temp;
    first = headRef ;
    
    while(first != NULL){
        second = first->next;
        
        while(second != NULL){
            if(first->Prize < second->Prize){
                temp = new node ;
                temp->Prize = first->Prize ;
                temp->Name = first->Name ;
                temp->plAttempt = first->plAttempt ;
                first->Prize = second->Prize ;
                first->Name = second->Name ;
                first->plAttempt = second->plAttempt ;
                second->Prize = temp->Prize ;
                second->Name = temp->Name;
                second->plAttempt = temp->plAttempt ;
                delete temp;
            }
            
            second = second->next ;
        }
        
        first = first->next ;
    }
}



void Player::PlayerList(const char *file ) 
{
    
    cout << "List of Players: " << endl ;
    ifstream inFile ;
    inFile.open(file,ios::in|ios::binary ) ;
    string names ;
    vector<string> vNames ;
    
    
    while (!inFile.eof() && (names != "AnsKeyFFV3"))
    {   
        getline(inFile,names);
        
        if ((names != "AnsKeyFFV3"))  {
        }
    }  
    
    while (!inFile.eof() && (names != "PlayerList"))
    {   
        getline(inFile,names) ;
        if ((names != "PlayerList"))  
        {
            vNames.push_back(names) ;
        }
    }  
    inFile.close() ;
    if (vNames.empty()) {
        cout << "There is no player registered. Create new player." << endl ;
        Player* writeName = NULL ;
        writeName->addNewName(file) ;
    }
    
    else {
        
        sort(vNames.begin(),vNames.end()) ;
        
        for (unsigned i = 0; i < vNames.size(); i++) {
            cout <<  vNames[i] << endl ; 
        }
        
        
        
        cout << endl ;
        cout<< "Choose Player: "  ;
        string plName ;
        cin >> plName ;
        
        // Searching the name in Player List
        vector<string>::iterator it = find(vNames.begin(),vNames.end(),plName);
        
        if (it!=vNames.end())
        {       cout << "Player name found" << endl ;
            Game gv ;
            gv.gameView(file,plName) ;
            
        }
        
        else 
        {   cout << "Player doesn’t exist! " << endl ; 
            Player* insertName = NULL ;
            insertName->addNewName(file) ;            
        } 
    }
}


void Player::addNewName(const char *file)
{
    vector<string> vAnsKeyFFV3 ;
    vector<string> vPlayerList ;
    vector<string> vPrizeMoney ;
    vector<string> vAttempt ;
    string Prize("0") ;
    string Attempt("0") ;
    cout<< "Enter Player Name:" ;
    string newName ;
    cin >> newName ;
    
    string Ch ; 
    
    ifstream inFile ;
    inFile.open(file) ;
    ofstream outFile ; 
    outFile.open("outfile.txt",ios::out);
    
    
    while (!inFile.eof() && Ch != "AnsKeyFFV3")
    {
        getline(inFile,Ch);
        
        if (Ch != "AnsKeyFFV3")  
        {
            vAnsKeyFFV3.push_back(Ch) ;
        }
    } 
    
    vAnsKeyFFV3.push_back("AnsKeyFFV3") ;
    
    while (!inFile.eof() && Ch != "PlayerList")
    {
        getline(inFile,Ch);
        
        if (Ch != "PlayerList")  
        {
            vPlayerList.push_back(Ch) ;
        }
    } 
    
    while (!inFile.eof() && Ch != "PrizeMoney")
    {
        getline(inFile,Ch);
        if (Ch != "PrizeMoney")  
        {
            vPrizeMoney.push_back(Ch) ;
        }
    } 
    
    while (!inFile.eof() && Ch != "Attempt")
    {
        getline(inFile,Ch);
        if (Ch != "Attempt")  
        {
            vAttempt.push_back(Ch) ;
        }
    } 
    
    vPlayerList.push_back(newName) ;
    vPlayerList.push_back("PlayerList") ;
    
    vPrizeMoney.push_back(Prize) ;
    vPrizeMoney.push_back("PrizeMoney") ;
    vAttempt.push_back(Attempt) ;
    vAttempt.push_back("Attempt") ;
    
    // write to the temp outFile from vectors
    for (unsigned i = 0; i < vAnsKeyFFV3.size(); ++i)
        outFile  << vAnsKeyFFV3[i] << endl ;
    for (unsigned i = 0; i < vPlayerList.size(); ++i)
        outFile  << vPlayerList[i] << endl ;
    for (unsigned i = 0; i < vPrizeMoney.size(); ++i)
        outFile << vPrizeMoney[i] << endl ;
    for (unsigned i = 0; i < vAttempt.size(); ++i)
        outFile << vAttempt[i] << endl ;
    
    
    inFile.close() ;
    outFile.close() ;
    remove(file); // delete original file
    rename("outfile.txt",file);  // rename old to new  
    
    Game gv ;
    gv.gameView(file,newName) ;
    
}

void Player::updatePrize(const char *file,string currName,int winMoney,int Attempt) 
{
    
    vector<string> vName ;
    vector<int> vPrize ;
    vector<int> vAttempt ;
    vector<string> vAnsKeyFFV3 ;
    
    string Ch ; 
    
    ifstream inFile ;
    inFile.open(file) ;
    ofstream outFile ; 
    outFile.open("outfile.txt",ios::out);
    
    while (!inFile.eof() && Ch != "AnsKeyFFV3")
    {
        getline(inFile,Ch);
        
        if (Ch != "AnsKeyFFV3")  
        {
            vAnsKeyFFV3.push_back(Ch) ;
        }
    } 
    
    vAnsKeyFFV3.push_back("AnsKeyFFV3") ;
    
    
    while (!inFile.eof() && Ch != "PlayerList")
    {
        getline(inFile,Ch);
        
        if (Ch != "PlayerList")  
        {
            vName.push_back(Ch) ;
        }
    } 
    
    vector<string>::iterator itr =  find(vName.begin(), vName.end(),currName) ;
    int locName = (itr - vName.begin()) ;
    
    
    while (!inFile.eof() && Ch != "PrizeMoney")
    {
        getline(inFile,Ch);
        
        if (Ch != "PrizeMoney")  
        {
            vPrize.push_back(atoi(Ch.c_str())) ;
        }
    } 
    
    while (!inFile.eof() && Ch != "Attempt")
    {
        getline(inFile,Ch);
        
        if (Ch != "Attempt")  
        {
            vAttempt.push_back(atoi(Ch.c_str())) ;
        }
    } 
    
    
    
    
    vPrize[locName] = winMoney ;
    vAttempt[locName] += Attempt ; 
    
    // write to the temp outFile from vectors
    for (unsigned i = 0; i < vAnsKeyFFV3.size(); ++i)
        outFile  << vAnsKeyFFV3[i] << endl ;
    for (unsigned i = 0; i < vName.size(); ++i)
        outFile << vName[i] << endl ;
    outFile << "PlayerList" << endl ;
    for (unsigned i = 0; i < vPrize.size(); ++i)
        outFile << vPrize[i] << endl ;
    outFile << "PrizeMoney" << endl ;
    for (unsigned i = 0; i < vAttempt.size(); ++i)
        outFile << vAttempt[i] << endl ;
    outFile << "Attempt"  ;
    

    
    inFile.close() ;
    outFile.close() ;
    remove(file); // delete original file
    rename("outfile.txt",file);  // rename old to new  
    
}




void Player::PlayerStat(const char *file) 
{
    vector<string> vName ;
    vector<int> vPrize ;
    vector<int> vPlAttempt ;
    
    string plName ;
    ifstream inFile ;
    inFile.open(file,ios::in|ios::binary ) ;
    string Ch ;
    
   
    
    while (!inFile.eof() && (Ch != "AnsKeyFFV3"))
    {   
        getline(inFile,Ch);
        
        if ((Ch != "AnsKeyFFV3"))  {
        }
    }  
    
    
    while (!inFile.eof() && Ch != "PlayerList")
    {
        getline(inFile,Ch);
        
        if (Ch != "PlayerList")  
        {
            vName.push_back(Ch) ;
        }
    } 
    
    while (!inFile.eof() && Ch != "PrizeMoney")
    {
        getline(inFile,Ch);
        
        if (Ch != "PrizeMoney")  
        {
            vPrize.push_back(atoi(Ch.c_str())) ;
        }
    } 
    
    while (!inFile.eof() && Ch != "Attempt")
    {
        getline(inFile,Ch);
        
        if (Ch != "Attempt")  
        {
            vPlAttempt.push_back(atoi(Ch.c_str())) ;
        }
    } 
    
    
    
    inFile.close() ;
    
     nodePtr headRef = NULL ;
    
    for (unsigned i = 0; i < vName.size(); ++i)
        DisplayNamePrize(headRef,vName[i],vPrize[i],vPlAttempt[i]) ;
   
    SortList(headRef) ;
    cout << "Players"<<"    " <<"Attempts" <<"    "
    << "Total Prize" << endl<<endl  ;
    printList(headRef) ;
    
    
}


void Player::DisplayNamePrize(nodePtr &headRef, string newName,int winPrize,int attempt)
{  
  
    
    if(headRef == NULL){
        node* temp = NULL ;
        temp = new node;
        temp->Name = newName ;
        temp->Prize = winPrize ;
        temp->plAttempt = attempt ;
        temp->next = NULL;
        headRef = temp ; }
    else{
        node* temp = new node;
        temp->Name = newName ;
        temp->Prize = winPrize ;
        temp->plAttempt = attempt ;
        
        temp->next = (headRef)->next;
        (headRef)->next = temp;
    }
    
}

