/*
Date: 2023/10/14
Author: Orlando Companioni
email:companor@sheridancollege.ca

This is the header file for the soccerTeam struct
*/
#ifndef SOCCERTEAM_H
#define SOCCERTEAM_H
#pragma once
#include <iostream>
const int MAX_FOUL = 4; //maximum fouls allowed

struct soccerTeam{
    char m_teamName[41]; // 1 byte for null terminator
    int m_noFouls; // anything > than 0
    double m_fines; //it can be equal to and more than zero.
    int m_goals; //can be zero or more , used to be m_golas

    
    //member functions, setters and getters
    void setTeam(const soccerTeam& team);//receives a reference and then it copies the team name, fouls, fines and goals
    void setName(const char* tname);// name must be valid before it copies 
    void setFine(double fines, int foul); //fines and foul >0 to be valid else its 0
    void setEmpty();//sets name to empty, fouls and fines to -num,  goals to 0
    bool isEmpty() const; //true if name not null, fouls and fines >0 
    void calFines(); //If this function is called it will increases the fine by 20% of the old fine value.
    int fouls() const; //returns the number of fouls
    double getFines() const; //This is a getter made by me to get the fines
    int getGoals() const; //returns the number of goals
    std::ostream& display()const; //displays the team name, fouls, fines and goals

    //constructor
    soccerTeam(); //sets it as in setEmpty
    soccerTeam(const char* tname, double fines, int foul); //using the previous setters set the values if valid
    
    
};

#endif