/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021 *
* @author <Kaloyan Vachkov>
* @idnumber <62645>
* @task <4>
* @compiler <GCC> */

#include "Card.hpp"

Card::Card(const std::string& name, const std::string& effect) : card_name(name), effect_name(effect), rarity_score(int())
{
}

unsigned int Card::get_rarity_score() const{
    return this->rarity_score;
}
std::string Card::get_card_name() const{
    return this->card_name;
}

std::string Card::get_card_effect() const{
    return this->effect_name;
}

void Card::set_card_name(const std::string& name){
    this->card_name = name;
}

void Card::set_effect_name(const std::string& name){
    this->effect_name = name;
}


bool Card::operator>(Card& obj) const{
    return this->get_rarity_score() > obj.get_rarity_score();
}
bool Card::operator<(Card& obj) const{
    return this->get_rarity_score() < obj.get_rarity_score();
}
