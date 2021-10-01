/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021 *
* @author <Kaloyan Vachkov>
* @idnumber <62645>
* @task <4>
* @compiler <GCC> */

#include "PendulumCard.hpp"


PendulumCard::PendulumCard(const std::string& name,const std::string& effect ,const unsigned int& rarity, const unsigned int& att_poi, const unsigned int& def_poi ,const unsigned int& scale, const MagicType a) : Card(name, effect)
{
    MonsterCard::set_attack_points(att_poi);
    MonsterCard::set_defense_points(def_poi); 
    MagicCard::set_type(a);
    this->set_scale_points(scale);
    this->rarity_score = rarity; 
}

void PendulumCard::set_scale_points(const unsigned int& pt){
    if(pt > 0 && pt < 14){
        this->pendulum_scale = pt;
    }
}

unsigned int PendulumCard::get_scale_points() const{
    return pendulum_scale;
}

void PendulumCard::set_rarity_score(const unsigned int& points){
    this->rarity_score = points;
}
