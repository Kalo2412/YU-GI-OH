/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021 *
* @author <Kaloyan Vachkov>
* @idnumber <62645>
* @task <4>
* @compiler <GCC> */

#ifndef MonsterCard_hpp
#define MonsterCard_hpp
#include "Card.hpp"

#include <string>

class MonsterCard : virtual public Card{
    
    unsigned int defense_points;
    unsigned int attack_points;

public:
    
    MonsterCard(const std::string& magic_card_name = "",
              const std::string& effect_name = "", const unsigned int& rarity = 0,
              const unsigned int& attack_points = 0,
              const unsigned int& defense_points = 0);
    
    unsigned int get_defense_points() const;
    unsigned int get_attack_points() const;
    void set_rarity_score(const unsigned int& points) override;
   
    
    void set_defense_points(const unsigned int& def_pt);
    void set_attack_points(const unsigned int& att_pt);
  
};

#endif /* MonsterCard_hpp */
