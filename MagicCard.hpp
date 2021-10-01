/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021 *
* @author <Kaloyan Vachkov>
* @idnumber <62645>
* @task <4>
* @compiler <GCC> */


#ifndef MagicCard_hpp
#define MagicCard_hpp
#include "Card.hpp"

#include <string>

enum MagicType {
    trap = 0, buff = 1 , spell = 2
};

class MagicCard : virtual public Card {
    MagicType card_type;

public:
    MagicCard(const std::string& magic_card_name = "",
              const std::string& effect_name = "", const unsigned int& rarity = 0,
              const MagicType& card_type = trap);
    
    MagicType& get_magic_cardtype();
    void set_rarity_score(const unsigned int& points) override;

    
    void set_type(const MagicType& type);
   
};

#endif /* MagicCard_hpp */
