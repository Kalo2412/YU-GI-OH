/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021 *
* @author <Kaloyan Vachkov>
* @idnumber <62645>
* @task <4>
* @compiler <GCC> */

#ifndef Deck_hpp
#define Deck_hpp
#include <vector>
#include <string>
#include <iostream>
#include <typeinfo>
#include <random>
#include "PendulumCard.hpp"

class Deck {
    std::string deck_name;
protected:
    std::vector<Card*> deckCards;
public:
    Deck(const std::string& name = "");
    void set_name(const std::string& name);
    std::string get_name() const; 
    void add_card(Card&);
    unsigned long get_MonsterCards() const;
    unsigned long get_MagicCards() const;
    unsigned long get_PendulumCards() const;
    unsigned long get_allCards() const; 
    void change_card( Card* obj, const unsigned int& index);
    void delete_deck();
    void shuffle_deck();
    void sort_deck();
    friend std::ostream& operator<<(std::ostream& os,Deck& obj);
    friend std::istream& operator>>(std::istream& in, Deck& obj);
    Card& operator[](int) const; 
};





#endif /* Deck_hpp */
