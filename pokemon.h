#include <string>
#include <map>
#include <tuple>

class Pokemon
{
  private:
    std::string name;
    unsigned short lv;
    unsigned short hp;
    unsigned short atk;
    float chanceOfCrit;
    float chanceOfDodge;
    unsigned short defend();

  public:
    Pokemon(std::string n, unsigned short l, unsigned short h);
    
    std::string getName();

    unsigned short getLv();

    unsigned short getHp();

    unsigned short getAtk();

    unsigned short getDefend();

};