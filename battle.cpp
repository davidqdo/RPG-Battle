#include <iostream>
#include <string>
int main() {

  int playerHP = 100;
  int p_attack = 20;
  int magic = 30;
  int enemyHP = 0;
  int e_attack = 0;
  std::string choice;
  std::string action;
  std::string enemyList[6] = {"Goblin", "Slime", "Bandit", "Golem", "Knight", "Demon"};

  std::cout << "--------------------Welcome to RPG Battle--------------------\n";
  std::cout << "Choose your enemy: \n" << "Goblin\n" << "Slime\n" << "Bandit\n" << "Golem\n" << "Knight\n" << "Demon\n";
  std::getline(std::cin,choice);
  if (choice == enemyList[0]) { //Goblin
    enemyHP = 75;
    e_attack = 12;
  }
  else if (choice == enemyList[1]) { //Slime
    enemyHP = 50;
    e_attack = 10;
  }
  else if (choice == enemyList[2]) { //Bandit
    enemyHP = 100;
    e_attack = 14;
  }
  else if (choice == enemyList[3]) { //Golem
    enemyHP = 300;
    e_attack = 19;
  }
  else if (choice == enemyList[4]) { // Knight
    enemyHP = 400;
    e_attack = 20;
  }
  else if (choice == enemyList[5]) { //Demon
    enemyHP = 500;
    e_attack = 20;
  }
  else {
    std::cout << "Invalid Enemy Type please input a valid enemy." << std::endl;
    return 0;
  }
  std::cout << "You encountered a " << choice << "! "<< "Time for battle!" << std::endl;
  while (!(playerHP <= 0) && !(enemyHP <= 0)) {
    // Player's Turn
    std::cout << "Choose a move: Attack ||||| Heal\n";
    std::getline(std::cin,action);
    if (action == "Attack") { // Attack the enemy
      enemyHP -= p_attack;
      std::cout << "You attack the " << choice << ". It took " << p_attack << " damage." << std::endl;
    }
    else if (action == "Heal") { // Heal yourself
      playerHP += magic;
      std::cout << "You healed yourself and now have " << playerHP << " health" << std::endl;
    }
    else { // This happens when the user inputs an invalid string command
      std::cout << "You are confused on what to do and do nothing" << std::endl;
    }
    action.clear();
    // Enemy Turn
    playerHP -= e_attack;
    std::cout << "You got attacked by the " << choice << " and was dealt " << e_attack << " damage." << std::endl;
    // Display HP
    std::cout << "Player's Health: " << playerHP << "\nEnemy's Health: " << enemyHP << std::endl;
  }
  // Determine who won and lost
  if (playerHP <= 0 && !(enemyHP <= 0)) {
    std::cout << "You have been defeated\n" << "Game Over!" << std::endl;
  }
  else if (playerHP <= 0 && enemyHP <= 0){
    std::cout << "You and the " << choice << " are both defeated\n" << "Tie Battle!" << std::endl;
  }
  else {
    std::cout << "You have succesfully defeated the " << choice << ".\nYou Win!" << std::endl;
  }
  return 0;
}
