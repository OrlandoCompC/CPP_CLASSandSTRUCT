/*
Date: 2023/10/14
Author:Orlando Companioni
email:companor@sheridancollege.ca

This is Tournament.h the header file for the Tournament class
*/
#ifndef TOURNAMENT_H
#define TOURNAMENT_H
#pragma once
#include <iostream>
#include <cstring>
#include "soccerTeam.h"

namespace fast{
    
class Tournament{
    char* m_name;
    int m_num;
    soccerTeam* m_soccer=nullptr;

    public:
    void setTournament(const char* name, int noOfteam,const soccerTeam* soccer); //noOFteam >0 and name must be valid
    void setEmpty(); //setting the m_name and m_soccer to null and m_num to 0.
    bool isEmpty() const; //Returns true if m_name and m_soccer is not null and m_num is grater than 0.
    std::ostream& display() const; 
    Tournament& match(const soccerTeam* ls);
    

    Tournament();
    Tournament(const char* name, int noOfteam,const soccerTeam* soccer);
    ~Tournament();
    
};//end of Tournament class

}//end of namespace fast

#endif


