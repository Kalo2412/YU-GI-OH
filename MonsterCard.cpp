/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021 *
* @author <Kaloyan Vachkov>
* @idnumber <62645>
* @task <4>
* @compiler <GCC> */


#include "MonsterCard.hpp"


MonsterCard::MonsterCard(const std::string& magic_card_name,
          const std::string& effect_name, const unsigned int& rarity,
          const unsigned int& attack_points,
                     const unsigned int& defense_points) :
    Card(magic_card_name, effect_name)
{
    this->attack_points = attack_points;
    this->defense_points = defense_points;
    this->rarity_score = rarity; 
}

unsigned int MonsterCard::get_defense_points() const{
    return defense_points;
}

unsigned int MonsterCard::get_attack_points() const{
    return attack_points;
}

void MonsterCard::set_rarity_score(const unsigned int& points){
    this->rarity_score = points; 
}

void MonsterCard::set_defense_points(const unsigned int& def_pt){
    this->defense_points = def_pt;
}

void MonsterCard::set_attack_points(const unsigned int& att_pt){
    this->attack_points = att_pt;
}

