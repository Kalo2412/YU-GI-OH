/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021 *
* @author <Kaloyan Vachkov>
* @idnumber <62645>
* @task <4>
* @compiler <GCC> */

#include "Deck.hpp"


Deck::Deck(const std::string& name){
    this->deck_name = name; 
}
void Deck::set_name(const std::string& name){
    this->deck_name = name;
}

std::string Deck::get_name() const { return this->deck_name; }

void Deck::add_card(Card& obj){
    this->deckCards.push_back(&obj);
}


unsigned long Deck::get_MonsterCards() const{
    unsigned long counter = 0;
    for (int i = 0; i < (int)deckCards.size(); i++){
        auto& obj = *deckCards[i];
        if(typeid(obj) == typeid(MonsterCard)){
            counter++;
        }
    }
    return counter;
}

unsigned long Deck::get_MagicCards() const {
    unsigned long counter = 0;
    for (int i = 0; i < (int)deckCards.size(); i++){
        auto& obj = *deckCards[i];
        if(typeid(obj) == typeid(MagicCard)){
            counter++;
        }
    }
    return counter;
}

unsigned long Deck::get_PendulumCards() const{
    unsigned long counter = 0;
    for (int i = 0; i < (int)deckCards.size(); i++){
        auto& obj = *deckCards[i];
        if(typeid(obj) == typeid(PendulumCard)){
            counter++;
        }
    }
    return counter;
}

unsigned long Deck::get_allCards() const{ return this->deckCards.size(); }


void Deck::change_card( Card* obj, const unsigned int& index){
    if(index <= deckCards.size() + 1){
        if(typeid(deckCards[index]) == typeid(*obj)){
            deckCards[index] = obj;
        }
    }
}

void Deck::delete_deck(){
    this->deckCards.clear();
}

void Deck::shuffle_deck(){
    std::default_random_engine rng;
    std::shuffle(std::begin(deckCards), std::end(deckCards), rng);
}

void Deck::sort_deck(){
    const int a = (int)this->get_allCards();
    for (int i = 0; i < a; i++){
        auto& obj = *deckCards[i];
        if(typeid(obj) == typeid(MonsterCard)){
            deckCards.push_back(deckCards[i]);
            
        }
    }
    for (int i = 0; i < a; i++){
        auto& obj = *deckCards[i];
        if(typeid(obj) == typeid(MagicCard)){
            deckCards.push_back(deckCards[i]);
           
        }
    }
    for (int i = 0; i < a; i++){
        auto& obj = *deckCards[i];
        if(typeid(obj) == typeid(PendulumCard)){
            deckCards.push_back(deckCards[i]);
           
        }
    }
    
 
     deckCards.erase(deckCards.begin(),deckCards.begin() + a);
      
}

std::ostream& operator<<(std::ostream& os,Deck& obj)
{
    std::string CardType[3] = {"TRAP", "BUFF", "SPELL"};
    obj.sort_deck();
    u_long a = (int)obj.get_MonsterCards();
    u_long b = (int)obj.get_MagicCards();
    u_long c = (int)obj.get_PendulumCards();
    
    for(int i = 0; i < (int)a; i++){
        os << obj.deckCards[i]->get_card_name() << "|" << obj.deckCards[i]->get_card_effect() << "|" << obj.deckCards[i]->get_rarity_score() << "|" << dynamic_cast<MonsterCard*>(obj.deckCards[i])->get_attack_points() << "|" << dynamic_cast<MonsterCard*>(obj.deckCards[i])->get_defense_points() << "\n";
    }
    
    for(int i = int(a); i < (int)obj.get_allCards() - (int)c; i++){
        os << obj.deckCards[i]->get_card_name() << "|" << obj.deckCards[i]->get_card_effect() << "|" << obj.deckCards[i]->get_rarity_score() << "|" << CardType[dynamic_cast<MagicCard*>(obj.deckCards[i])->get_magic_cardtype()] << "\n"; 
    }
    
    for(int i = int(a) + int(b); i < (int)obj.get_allCards(); i++){
        os << obj.deckCards[i]->get_card_name() << "|" << obj.deckCards[i]->get_card_effect() << "|" << obj.deckCards[i]->get_rarity_score() << "|" <<
            dynamic_cast<PendulumCard*>(obj.deckCards[i])->get_attack_points() << "|" <<
            dynamic_cast<PendulumCard*>(obj.deckCards[i])->get_defense_points() << "|" <<
            dynamic_cast<PendulumCard*>(obj.deckCards[i])->get_scale_points() << "|" <<
            CardType[dynamic_cast<PendulumCard*>(obj.deckCards[i])->get_magic_cardtype()] << "\n";
    }
    
    return os;
}

std::istream& operator>>(std::istream& in, Deck& obj){
    u_long magic_cards, monster_cards, pendulum_cards, all_cards;
    std::string name, effect;
    char b;
    MagicType a; 
    in >> name >> b >> all_cards >> b >> monster_cards >> b >> magic_cards >> b >> pendulum_cards;
    obj.set_name(name);
    
    unsigned int rarity_poi, def, att, scale_poi, mag_typ;
 
    int counter = 0;
    
    while(in >> name >> b >> effect >> b  >> rarity_poi >> b >> att >> b >> def){
        MonsterCard m1(name, effect, rarity_poi, def, att);
        obj.deckCards.push_back(&m1);
        ++counter;
        if(counter == monster_cards) break;
    }
    counter = 0;
    while(in >> name >> b >> effect >> b  >> rarity_poi >> b >> mag_typ){
        switch(mag_typ){
            case 0: a = MagicType::trap; break;
            case 1: a = MagicType::buff; break;
            case 2: a = MagicType::spell; break;
        }
        MagicCard m2(name,effect, rarity_poi, a);
        obj.deckCards.push_back(&m2);
        ++counter;
        if(counter == magic_cards) break;
    
    }
    counter = 0;
    while(in >> name >> b >> effect >> b >> rarity_poi >> b >> att >> b >> def >> b >> scale_poi >> b >> mag_typ)
    {
        switch(mag_typ){
            case 0: a = MagicType::trap; break;
            case 1: a = MagicType::buff; break;
            case 2: a = MagicType::spell; break;
        }
        PendulumCard m3(name,effect, rarity_poi, att, def, scale_poi, a);
        obj.deckCards.push_back(&m3);
        ++counter;
        if(counter == pendulum_cards) break;
    
    }
    
    return in; 
}

Card& Deck::operator[](int& index) const{
    return this->deckCards[index]; 
}

