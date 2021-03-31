#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include "pokemon.h"\

#define GAME true
#define PRINT_TIME 50
#define STARTERS ["Charmander", "Squirtle", "Bulbasaur"]

void println(std::string str){
  for (int c = 0; c < str.size(); c++){
    std::cout << str[c] << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(PRINT_TIME));
  }
  std::cout << std::flush;
  return;
}

void println(std::string str, int time){
  for (int c = 0; c < str.size(); c++){
    std::cout << str[c] << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
  }
  std::cout << std::endl;
  return;
}

int main() {
  std::string starters[3] = { "Charmander", "Squirtle", "Bulbasaur" };
  int start_choice;
  while (GAME)
  {
    //get trainer's name
    std::string trainer;
    println("Welcome, trainer. What is your name?: ");
    std::cin >> trainer;
    fflush(stdin);

    //respond to name
    println("Hi there " + trainer + ". Welcome to Pokemon. In this text-based game, you'll enslave small animals called Pokemon to fight each other for your own enjoyment. It's barbaric, but it's also a marketing ploy to get children to buy Pokemon cards with their parents' money. Genius, huh?");
    
    //awkward pause
    for (int i = 0; i < 5; i++){
      sleep(1);
      std::cout << ". " << std::flush;
    }

    //prompt to create pokemon
    println("Anyway! Let's get started. We have three starter Pokemon for you to choose from. \n");
    for (int p = 0; p < 3; p++){
      println(std::to_string(p) + " " + starters[p] + "\n");
    }

    println("Which of these would you like as your first Pokemon?: ");
    std::cin >> start_choice;
    exit(0);
  }
  Pokemon charmander("Charmander", 6, 30);
  std::cout << charmander.getName() << std::endl << charmander.getLv() << std::endl << charmander.getHp() << std::endl;
  return 0;
}