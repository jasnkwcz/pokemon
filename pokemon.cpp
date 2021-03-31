#include <string>
#include <map>
#include "pokemon.h"
#include <tuple>

Pokemon::Pokemon(std::string n, unsigned short l, unsigned short h) :
      name(n),
      lv(l),
      hp(h),
      atk(this->lv * 5)
      {};
    
std::string Pokemon::getName(){
    return name;
  }

unsigned short Pokemon::getLv(){
    return lv;
  };

unsigned short Pokemon::getHp(){
  return hp;
};

unsigned short Pokemon::getAtk(){
  return atk;
}