/*
Date: 2023/10/14
Author:Orlando Companioni
email:companor@sheridancollege.ca

This is the implementation file for the Tournament class
*/
#include <iostream>
#include "Tournament.h"


using namespace std;
int counter=0;

namespace fast{
void Tournament::setEmpty(){
    m_name=nullptr;
    m_soccer=nullptr;
    m_num=0;
} //end of setEmpty

void Tournament::setTournament(const char* name, int noOfteam,const soccerTeam* soccer){
    if (name!=nullptr && noOfteam>0){
        m_num=noOfteam;
        m_name=new char[strlen(name)+1]; //+1 because of the null character
        strcpy(m_name, name);
        m_soccer=new soccerTeam[m_num];
        for (int i=0; i<m_num; i++){
            m_soccer[i]=soccer[i]; //copying the soccerTeam object to m_soccer
        }
    }
    else{
        setEmpty();
    }
}//end of setTournament

Tournament::Tournament(){
    setEmpty();
}//end of no arg constructor

Tournament::Tournament(const char* name, int noOfteam,const soccerTeam* soccer){//exactly the same as setTournament
    setTournament(name, noOfteam, soccer);
}//end of overloaded constructor


bool Tournament::isEmpty() const{
    return (m_name!=nullptr && m_soccer!=nullptr && m_num>0);
}//end of isEmpty

Tournament::~Tournament(){
    delete [] m_name;
    delete [] m_soccer;
    m_name=nullptr;
    m_soccer=nullptr;
}//end of destructor

Tournament& Tournament::match(const soccerTeam* ls){ //ls is the list of soccerTeam objects
    int newfouls=0;
    int newfine=0;
    int newGoals=0;
    int size=m_num;
    
    if(counter<1){
        for(int i=0; i<size-1; i++){ //This will run initially
            if(ls[i].fouls()<ls[i+1].fouls()){
                newfouls=(ls[i+1].fouls())*2;
                newfine=ls[i+1].getFines()+(ls[i+1].getFines()*0.20); //20% of the old fine value 
                newGoals=ls[i].getGoals()+1;
                if(newfouls>MAX_FOUL){
                    newfouls=-1;
                }
            m_soccer[i+1].setFine(newfine, newfouls);
            m_soccer[i].m_goals=newGoals;
            counter++;
            }
        }
    }
    else{
        for(int i=0; i<size-1; i++){ //This is using the member variables of the soccerTeam object
            if(ls[i].fouls()<ls[i+1].fouls()){
                newfouls=(ls[i+1].fouls())*2+(m_soccer[i+1].fouls());
                // newfine=m_soccer[i+1].getFines()+(m_soccer[i+1].getFines()*0.20); //20% of the old fine value 
                m_soccer[i+1].calFines();
                newfine=m_soccer[i+1].getFines();
                newGoals=ls[i].getGoals()+1+(m_soccer[i].getGoals());
                if(newfouls>MAX_FOUL){
                    newfouls=-1;
                }
            m_soccer[i+1].setFine(newfine, newfouls);
            m_soccer[i].m_goals=newGoals;
            }
        }
    }
    return *this;

}//end of match

std::ostream& Tournament::display() const{
    std::ostream& outPrint=std::cout;
    if (isEmpty()){
        outPrint<<"Tournament Name: "<<m_name<<endl;
        outPrint<<"List of Teams: "<<endl;
        outPrint.width(45);
        outPrint<<"Fines";
        outPrint.width(10);
        outPrint<<"Fouls";
        outPrint.width(10);
        outPrint<<"Goals"<<endl;
        for (int i=0; i<m_num; i++){
            outPrint<<"Team ["<<i+1<<']'<<" :";
            m_soccer[i].display();
        }

    }
    else{
        outPrint<<"Invalid Tournament!"<<endl;
    }
    return outPrint;
}

}//end of namespace fast