/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021 *
* @author <Kaloyan Vachkov>
* @idnumber <62645>
* @task <4>
* @compiler <GCC> */

#include "MagicCard.hpp"


MagicCard::MagicCard(const std::string& magic_card_name,
                     const std::string& effect_name, const unsigned int& rarity, const
                    MagicType& card_type) :
    Card(magic_card_name, effect_name),
    card_type(card_type)
{
    this->rarity_score = rarity; 
}

void MagicCard::set_rarity_score(const unsigned int& points){
    this->rarity_score = points;
}

MagicType& MagicCard::get_magic_cardtype() {
    return this->card_type;
}

void MagicCard::set_type(const MagicType& type){
    this->card_type = type;
}


