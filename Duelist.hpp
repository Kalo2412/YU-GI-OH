/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021 *
* @author <Kaloyan Vachkov>
* @idnumber <62645>
* @task <4>
* @compiler <GCC> */

#ifndef Duelist_hpp
#define Duelist_hpp

#include "Deck.hpp"
#include <fstream>

class Duelist {
    Deck d1;
    std::string duelist_name;
    
public:
    Duelist(const std::string& name = "");
    void setName(const std::string& name = "");
    Deck& getDeck();
    bool save_deck(std::string& outfileName);
    bool load_deck(std::string& infileName);
     friend std::ostream& operator<<(std::ostream& os, Duelist& obj);
     friend std::istream& operator>>(std::istream& os, Duelist& obj);
    void duel(Duelist& number2); 
    
};

#endif /* Duelist_hpp */
