/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021 *
* @author <Kaloyan Vachkov>
* @idnumber <62645>
* @task <4>
* @compiler <GCC> */
#include "Duelist.hpp"


Duelist::Duelist(const std::string& name) : duelist_name(name), d1("")
{
}

void Duelist::setName(const std::string& name){
    this->duelist_name = name; 
}

Deck& Duelist::getDeck(){
    return this->d1;
}



std::ostream& operator<<(std::ostream& os, Duelist& obj){
    Deck d = obj.getDeck();
    os << d.get_name() << "|" << d.get_MonsterCards() << "|" << d.get_MagicCards()<< "|" << d.get_PendulumCards() << "\n";
    os << d;
    return os;
}

std::istream& operator>>(std::istream& in, Duelist& obj){
    in >> obj.getDeck();
    return in;
}

bool Duelist::save_deck(std::string& outfileName){
    std::ofstream newFile (outfileName);
    if(newFile.is_open()){
        newFile << this;
        return true;
    }
    else return false;
}

bool Duelist::load_deck(std::string& infileName){
    std::ifstream new_file;
    new_file.open(infileName);
    if(new_file.is_open()){
        new_file >> *this;
        return true;
    }
    else return false;
}

void Duelist::duel(Duelist& number2){
    int score1, score2;
    if(this->getDeck().get_allCards() != number2.getDeck().get_allCards()) { return; }
    else {
    this->getDeck().shuffle_deck();
    number2.getDeck().shuffle_deck();
        for(int i = 0; i < this->getDeck().get_allCards(); i++){
            if (this->getDeck().operator[](i) > number2.getDeck().operator[](i)){
                score1++;
            }
            else if (this->getDeck().operator[](i) < number2.getDeck().operator[](i)){
                score2++;
            }
        }
}
}
