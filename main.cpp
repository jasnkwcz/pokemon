#include <iostream>
#include "pokemon.h"

int main() {
  Pokemon charmander("Charmander", 6, 30);
  std::cout << charmander.getName() << std::endl << charmander.getLv() << std::endl << charmander.getHp() << std::endl;
  return 0;
}