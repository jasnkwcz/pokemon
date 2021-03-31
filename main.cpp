#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include "pokemon.h"\

#define GAME true
#define PRINT_TIME 35
#define STARTERS ["Charmander", "Squirtle", "Bulbasaur"]

int battle(Pokemon trainer, Pokemon opponent);

void println(std::string str){
  for (int c = 0; c < str.size(); c++){
    std::cout << str[c] << std::flush;
    if (str[c] == '.'){
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(PRINT_TIME));
  }
  std::cout << std::flush;
  return;
}

void println(std::string str, int time){
  for (int c = 0; c < str.size(); c++){
    std::cout << str[c] << std::flush;
    if (str[c] == '.'){
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
  }
  std::cout << std::endl;
  return;
}

int main() {
  std::cout << "\x1B[2J\x1B[H";
  std::string starters[3] = { "Charmander", "Squirtle", "Bulbasaur" };
  int start_choice;
  while (GAME)
  {
    //get trainer's name
    std::string trainer;
    println("Welcome, trainer.\nWhat is your name?: ");
    std::cin >> trainer;
    fflush(stdin);

    //respond to name
    println("Welcome to Pokemon, " + trainer + "!\nIn this text-based game, you'll enslave small animals called Pokemon to fight each other for your own enjoyment.\nIt's barbaric, but it's also a marketing ploy to get children to buy Pokemon cards with their parents' money.\nGenius, huh?\n");
    
    //awkward pause
    for (int i = 0; i < 5; i++){
      sleep(1);
      std::cout << ". " << std::flush;
    }

    //prompt to create pokemon
    println("\nAnyway! Let's get started.\nWe have three starter Pokemon for you to choose from. \n");
    for (int p = 0; p < 3; p++){
      println(std::to_string(p) + " " + starters[p] + "\n");
    }

    println("Which of these would you like as your first Pokemon?: ");
    std::cin >> start_choice;

    Pokemon starter(starters[start_choice], 6, 30);

    println("Great! Your new pokemon is " + starter.getName() + ".\nCurrently he's level " + std::to_string(starter.getLv()) + " and has " + std::to_string(starter.getHp()) + " HP.\n");
    println("As you continue to battle Pokemon, they'll gain experience and level up.\nLeveling up increases your Pokemon's fight stats like HP, ATK, and DEF.\nOnce they reach a certain level, they can even evolve.\n");
    println("Let's battle your " + starter.getName() + " against " + starters[(start_choice + 2) % 3] + " so we can introduce you to battles!\n");

    Pokemon opponent(starters[(start_choice + 2) % 3], 6, 30);
    exit(0);
  }
  Pokemon charmander("Charmander", 6, 30);
  std::cout << charmander.getName() << std::endl << charmander.getLv() << std::endl << charmander.getHp() << std::endl;
  return 0;
}