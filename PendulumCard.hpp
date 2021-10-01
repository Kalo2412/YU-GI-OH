/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021 *
* @author <Kaloyan Vachkov>
* @idnumber <62645>
* @task <4>
* @compiler <GCC> */
#ifndef PendulumCard_hpp
#define PendulumCard_hpp
#include "MagicCard.hpp"
#include "MonsterCard.hpp"
#include <string>


class PendulumCard : public MagicCard, public MonsterCard{
    
    unsigned int pendulum_scale;
   
    
public:
    
    PendulumCard(const std::string& name = "",const std::string& effect = "",const unsigned int& rarity = 0, const unsigned int& att_poi = 0, const unsigned int& def_poi = 0,const unsigned int& scale = 1, const MagicType a = trap);
    
    void set_scale_points(const unsigned int& pt);
    void set_rarity_score(const unsigned int& points) override;
    
    unsigned int get_scale_points() const;
    
};

#endif /* PendulumCard_hpp */
