/*
Date: 2023/10/14
Author:Orlando Companioni
email:companor@sheridancollege.ca

This is the file where all the member functions that work on soccerTeam are implemented

*/
#include <iostream>
#include <cstring>
#include "soccerTeam.h"

using namespace std;

void soccerTeam::setName(const char* tname){ //cannot be null
    if(tname!=nullptr){
        strcpy(m_teamName, tname);
    }
}//end of setName

void soccerTeam::setFine(double fines, int foul){ //fines and foul >=0 to be valid else set the soccerTeam object to an empty state
    if (fines>=0 && foul>=0){
        m_noFouls=foul;
        m_fines=fines;
    }
    else{
        setEmpty();
    }
}//end of setFine

void soccerTeam::setEmpty(){//sets name to empty, fouls and fines to -num,  goals to 0
    m_teamName[0] = '\0'; //checking if its empty
    m_noFouls=-1;
    m_fines=-1;
    m_goals=0;
}//end of setEmpty

bool soccerTeam::isEmpty() const{ //true if name not null, fouls and fines >0
    return (m_teamName[0] != '\0' && m_noFouls>=0 && m_fines>=0);
}//end of isEmpty

void soccerTeam::calFines(){ //If this function is called it will increases the fine by 20% of the old fine value
    m_fines = m_fines + (m_fines * 0.2);
}//end of calFines

int soccerTeam::fouls() const{ //returns the number of fouls
    return m_noFouls;
}//end of fouls

double soccerTeam::getFines() const{ //This is a getter made by me to get the fines
    return m_fines;
}//end of getFines

void soccerTeam::setTeam(const soccerTeam& team){//sets the team name, fouls, fines and goals
    setName(team.m_teamName);
    setFine(team.m_fines, team.m_noFouls);
}//end of setTeam

int soccerTeam::getGoals() const{ //returns the number of goals
    return m_goals;
}//end of getGoals

soccerTeam::soccerTeam(){ //sets it as in setEmpty
    setEmpty();
}//end of soccerTeam


soccerTeam::soccerTeam(const char* tname, double fines, int foul){ //using the previous setters set the values if valid
    setName(tname); //send it to setName to validate 
    setFine(fines, foul); //send it to setFine to validate
    m_goals=0;
}//end of soccerTeam2

std::ostream& soccerTeam::display()const{
    std::ostream& print=std::cout; //making an object if class ostream called print
    if (isEmpty()){
        print.width(30);
        print << std::left << m_teamName;
        print << std::right;
        print.width(6);
        print.setf(ios::fixed);
        print.precision(2);
        print<<m_fines;
        print.unsetf(ios::fixed);
        print.width(6);
        print<<m_noFouls;
        print.width(10);
        if(m_goals>0){
            print<<m_goals<<'w'<<endl;
        }
        else{
            print<<m_goals<<endl;
        }
    }
    else{
        print<<"Invalid Team!"<<endl;
    }
    return print;
}//end of display
