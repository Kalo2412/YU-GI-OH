/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021 *
* @author <Kaloyan Vachkov>
* @idnumber <62645>
* @task <4>
* @compiler <GCC> */

#ifndef Card_hpp
#define Card_hpp

#include <string>

class Card {
    std::string card_name;
    std::string effect_name;
protected:
    unsigned int rarity_score;
public:
    Card(const std::string& name = "",const std::string& effect = "");
    
    std::string get_card_name() const;
    std::string get_card_effect() const;
    unsigned int get_rarity_score() const;
    
    void set_card_name(const std::string& name);
    void set_effect_name(const std::string& name);
    virtual void set_rarity_score(const unsigned int& points) = 0;
    
    bool operator>(Card&) const;
    bool operator<(Card&) const;
    
};

#endif /* Card_hpp */
*
