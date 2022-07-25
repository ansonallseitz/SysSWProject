/*
*******************************************************
PROGRAM NAME - AdventureGame

PROGRAMMERS - Logan Durham
              Stephanie Livengood
              Oussama Aireche
              Anson Allseitz

DESCRIPTION - This is text based adventure game in which players will choose a
character to play as, they will also have certain attacks they can use. If the
player has 0 health at any point they lose. If they go through all of the
encounters with health points above 0 they win.

DATE - Started 07 / 05 / 2022
DATE - Last Update  07 / 24 / 2022
* ******************************************************
*/

#include "character.h"
#include "item.h"
#include "player.h"
#include "room.cpp"
#include <iostream>
#include <limits>
using namespace std;

// function templates
player createNewPlayer();
void startGame(player player1);
void exitGame();
void loseGame(player player1);
void winGame(player player1);
void roomOne(player player1);
void roomTwo(player player1);
void roomThree(player player1);
void roomThreePartTwo(player player1);
void roomFour(player player1);
void roomFive(player player1);
void roomSix(player player1);
void bag(player thePlayer);

// this is a function for the first riddle in room 2
void firstRiddle(player player1) {
  cout << "In the box there is an tablet with text carved into it, along with "
          "4 blocks.\n";
  cout << "Each of the blocks has a word on it, and there is a space under\n";
  cout << "The inscription  that looks like a block fits in.\n";
  cout << "The tablet reads:\n\n";
  cout << "It cannot be seen, cannot be felt\n, Cannot be heard, cannot be "
          "smelt.\n ";
  cout << "It lies behind stars and under hills,\n And empty holes it fills.\n";
  cout << "It comes out first and follows after, Ends life, kills laughter.\n";
  cout << "What is it? \n";
  cout << "1. Roots\n";
  cout << "2. Death\n";
  cout << "3. Darkness\n";
  cout << "4. The Night\n\n";
  int riddleChoice;
  cin >> riddleChoice;
  while (riddleChoice <= 0 || riddleChoice > 4) {
    cout << "Please choose '1' for Roots, '2' for Death, '3' for Darkness, or "
            "'4' for The Night.\n";
    cin >> riddleChoice;
  }
  if (riddleChoice == 3) {
    cout << "you put the, Darkness block into the hole\n";
    cout << "you hear a rumbling noise and a large door opens\n\n";
    roomThree(player1);
  } else if (riddleChoice == 1) {
    // creative death
    cout << "You put the roots block into the hole.\n"
         << "You feel a massivea rumbling and the ceiling starts to cave in!\n"
         << "You're crushed by the dungeon.\n";
    loseGame(player1);

  } else if (riddleChoice == 2) {
    // creative death
    cout << "You put the roots block into the hole.\n"
         << "You feel a massivea rumbling and the ceiling starts to cave in!\n"
         << "You're crushed by the dungeon.\n";
    loseGame(player1);
  } else if (riddleChoice == 4) {
    // creative death
    cout << "You put the roots block into the hole.\n"
         << "You feel a massivea rumbling and the ceiling starts to cave in!\n"
         << "You're crushed by the dungeon.\n";
    loseGame(player1);
  }
}
void thirdRiddle(player player1) {
  // Also from the hobbit.
  cout << "------------------------------\n";
  cout << "------------------------------\n";
  cout << "------------------------------\n";
  cout << "------------------------------\n";
  cout << "The voice on the right says,\"this is the second riddle\".\n";
  cout << "This thing all things devours\n";
  cout << "Birds, beasts, trees, flowers\n";
  cout << "Gnaws iron, bites steel\n";
  cout << "Grinds hard stones to meal\n";
  cout << "Slays king, ruins town,\n";
  cout << "And beats mountain down.\n, what am I?\n";
  cout << "1. Time\n";
  cout << "2. Water\n";
  int riddleChoice;
  cin >> riddleChoice;
  while (riddleChoice <= 0 || riddleChoice > 2) {
    cout << "Please choose '1' for Time, '2' for Water , \n";
    cin >> riddleChoice;
  }

  if (riddleChoice == 1) {
    // right Answer
    cout << "You chose Time \n";
    cout << "Congradulations! says the voice on the left.\n";
    player1.setAddHP(50);

  } else if (riddleChoice == 2) {
    // wrong answer, you get shocked
    cout << "You chose Water\n";
    cout << "A bolt of electricity jumps out of the left pannel, giving you a "
            "painful shock.\n";
    cout << "Congradulations! says the voice on the left.";
  }
  // win or lose

  if (player1.getHP() > 0) {

    winGame(player1);
  } else {
    loseGame(player1);
  }
}

// this is a function for the first riddle in room 6
// answer is fish, from the hobbit.
void secondRiddle(player player1) {
  cout << "The voice on the left says,\"this is the first riddle\".\n";
  cout << "Alive without breath\n";
  cout << "As cold as death;\n";
  cout << "Never thirsty, ever drinking,\n";
  cout << "All in mail never clinking.\n, what am I?\n ";
  cout << "1. A Knight\n";
  cout << "2. Fish\n";
  int riddleChoice;
  cin >> riddleChoice;
  while (riddleChoice <= 0 || riddleChoice > 2) {
    cout << "Please choose '1' A Knight, '2' for Fish, \n";
    cin >> riddleChoice;
  }

  if (riddleChoice == 1) {
    // Wrong answer, you get shocked, loose 50 HP
    cout << "You chose A knight\n";
    cout << "A bolt of electricity jumps out of the left pannel, giving you a "
            "painful shock.\n";
    player1.setAddHP(50);

  } else if (riddleChoice == 2) {
    // right answer, you don't get shocked.
    cout << "You chose Fish\n";
    cout << "Congradulations! says the voice on the left.\n";
    thirdRiddle(player1);
  }
}

// main function
int main() {
  // create the player
  player player1 = createNewPlayer();

  /*
I have added a simple menu to control the processes of the game and keep looping
until the player exits the game
- aireche
*/
  int mainMenuChoice = 0;
  while (mainMenuChoice != 2) { // Main menu

    cout << "\n\nSelect an operation (use '1' or '2')...\n\n"

         << "1. Start game.\n"
         << "2. Exit game.\n\n";

    // data validation for main menu choice
    while (true) {
      cin >> mainMenuChoice;
      if (!cin) {
        cout << "Wrong Choice. Enter choice number again " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
      } else
        break;
    }
    while (mainMenuChoice <= 0 || mainMenuChoice > 2) {
      cout << "Please enter 1 for 'Start Game' or 2 for 'Save and Exit'\n";
      while (true) {
        cin >> mainMenuChoice;
        if (!cin) {
          cout << "Wrong Choice. Enter choice number again " << endl;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          continue;
        } else
          break;
      }
    }

    switch (mainMenuChoice) {

    case 1:
      startGame(player1);
      break;
    case 2:
      exitGame();
      break;
    }
  }
}

// here is the function for making a new player (aka giving your name)
player createNewPlayer() {

  string name;
  cout << "Enter your name: ";
  // cin >> name;
  getline(cin, name);
  player player1(name, 100, 0, 0, 1);

  cout << "Welcome ";
  cout << player1.getName();

  return player1;
}

// function to start the actual game play
void startGame(player player1) {

  cout << "You start with " << player1.getHP() << " health.\n";

  // display health

  cout << "You've been kidnapped by an evil wizard! \n He's locked you in his "
          "dungeon and tells you there is no escape.\n Unfortunately for him, "
          "you've got a plan.\n You decide to sneak through the hole in the "
          "floor and out into a hidden hallway with doors on each side. \n "
          "What will happen next?...\n";
  // call for first room here
  roomOne(player1);
  // while player is still alive they will go through each room in order.
}

// function to end the game
void exitGame() { cout << "Thank you for playing!"; }

// Rooms to choose from
void roomOne(player player1) {

  // create enemy
  character enemy1("Rat", 100, 15, 0);

  // this room will be a physical attack
  cout << "------------------------------\n";
  cout << "\n\nYou try the red door. The room is dark but you stumble towards "
          "the wall and find a heavy switch. \n"
       << "The lights flicker on and you see a large rat! Not just large, "
          "GIANT!";
  while (player1.getHP() > 0 && enemy1.getHP() > 0) {
    int gamePlayChoice;
    cout << "Choose your move: \n";
    cout << "1. Attack\n";
    cout << "2. Defend\n";
    cout << "3. Use item\n";
    while (true) {
      cin >> gamePlayChoice;
      if (!cin) {
        cout << "Wrong Choice. Enter choice number again " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
      } else
        break;
    }
    while (gamePlayChoice <= 0 || gamePlayChoice > 3) {
      cout << "Please enter '1' for attack, '2' for defend, or '3' for use "
              "item.\n";
      while (true) {
        cin >> gamePlayChoice;
        if (!cin) {
          cout << "Wrong Choice. Enter choice number again " << endl;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          continue;
        } else
          break;
      }
    }

    // player chooses to attack
    if (gamePlayChoice == 1) {
      // generate random number to take away from enemy HP
      cout << "\nYou attack!\n";
      int playerdamage = player1.character::getAttack();
      enemy1.setHP(playerdamage);
      cout << "Enemy HP: " << enemy1.getHP() << "\n";
      // use enemies predefined attackDamage to take away HP points from player
      int enemydamage = enemy1.getEnemyAttack();
      player1.setHP(enemydamage);
      cout << "Player HP: " << player1.getHP() << "\n\n";

    } // enemy defends with smaller damage to creature
    else if (gamePlayChoice == 2) {
      cout << "\nYou defend!\n";
      int playerdefense = player1.character::getDefense();

      enemy1.setHP(playerdefense);
      cout << "Enemy HP: " << enemy1.getHP() << "\n";

      // enemy deals attack damage
      int enemydamage = enemy1.getEnemyDefenseAttack();
      player1.setHP(enemydamage);
      cout << "Player HP: " << player1.getHP() << "\n\n";

    } else if (gamePlayChoice == 3) {
      bag(player1);
    }
  }
  if (player1.getHP() > 0) {

    roomTwo(player1);
  } else {
    loseGame(player1);
  }
}

void roomTwo(player player1) {
  // this room will be a riddle

  cout << "------------------------------\n";
  cout << player1.getName() << "s health regenerates!\n";
  player1.fullHealth(100);
  cout << "Player HP: " << player1.getHP() << "\n\n";
  cout << "You try the door with a gold handle. This room is brightly lit by "
          "candles everywhere. \n"
       << "An giant pipe organ plays ominous music off in the distance. \n"
       << "You look all around and find in the corner of the room a chest.\n";
  // set up the first decision tree -AA 07.20.22
  cout << "do you open the box? \n";
  int roomTwoChoiceOne;
  cout << "1.Yes \n";
  cout << "2. No \n";
  cin >> roomTwoChoiceOne;
  while (roomTwoChoiceOne <= 0 || roomTwoChoiceOne > 2) {
    cout << "Please choose '1' for yes or '2' for no.\n";
    cin >> roomTwoChoiceOne;
  }
  // the box plays a riddle, but you die if you don't open it.
  // inside of this chest will be a riddle, if they solve it they pass, if they
  // dont choose the right answer they automatically lose and end game

  if (roomTwoChoiceOne == 1) {
    // write dialogue here
    firstRiddle(player1);
  } else if (roomTwoChoiceOne == 2) {
    cout << "You start to hear a hissing noise, and a cloudy white mist fills "
            "the room\n";
    cout << "You get the urge to cough, and suddenly your hands are covered in "
            "blood.\n";
    cout << "The dizziness overwhelms  you, everything goes black.\n";
    loseGame(player1);
    return;
  }
}

void roomThree(player player1) {
  // set player HP back to 100
  player1.fullHealth(100);
  cout << player1.getName() << "s health regenerates!\n";
  cout << "Player HP: " << player1.getHP() << "\n\n";
  // create enemy
  character enemy2("Goblin", 100, 20, 0);
  // this room has a physical attack
  cout << "------------------------------\n";
  cout << "You step through the black door into another dark room. \nBut alas! "
          "You see a light peeking through a crack in the back wall. \nYou "
          "kick at the crumbling bricks and the wall gives way, but out jumps "
          "the ugliest Goblin you've ever seen! \nHe's snarling and ready to "
          "attack.";
  while (player1.getHP() > 0 && enemy2.getHP() > 0) {
    int gamePlayChoice;
    cout << "Choose your move: \n";
    cout << "1. Attack\n";
    cout << "2. Defend\n";
    cout << "3. Use item\n";
    while (true) {
      cin >> gamePlayChoice;
      if (!cin) {
        cout << "Wrong Choice. Enter choice number again " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
      } else
        break;
    }
    while (gamePlayChoice <= 0 || gamePlayChoice > 3) {
      cout << "Please enter '1' for attack, '2' for defend, or '3' for use "
              "item.\n";
      while (true) {
        cin >> gamePlayChoice;
        if (!cin) {
          cout << "Wrong Choice. Enter choice number again " << endl;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          continue;
        } else
          break;
      }
    }

    // player chooses to attack
    if (gamePlayChoice == 1) {
      // generate random number to take away from enemy HP
      cout << "\nYou attack!\n";
      int playerdamage = player1.character::getAttack();
      enemy2.setHP(playerdamage);
      cout << "Enemy HP: " << enemy2.getHP() << "\n";
      // use enemies predefined attackDamage to take away HP points from player
      int enemydamage = enemy2.getEnemyAttack();
      player1.setHP(enemydamage);
      cout << "Player HP: " << player1.getHP() << "\n\n";

    } // enemy defends with smaller damage to creature
    else if (gamePlayChoice == 2) {
      cout << "\nYou defend!\n";
      int playerdefense = player1.character::getDefense();

      enemy2.setHP(playerdefense);
      cout << "Enemy HP: " << enemy2.getHP() << "\n";

      // enemy deals attack damage
      int enemydamage = enemy2.getEnemyDefenseAttack();
      player1.setHP(enemydamage);
      cout << "Player HP: " << player1.getHP() << "\n\n";

    } else if (gamePlayChoice == 3) {
      bag(player1);
    }
  }
  if (player1.getHP() > 0) {

    roomFour(player1);
  } else {
    loseGame(player1);
  }
}

void roomThreePartTwo(player player1) {
  cout << "------------------------------\n";
  // reset health
  player1.fullHealth(100);
  cout << player1.getName() << "s health regenerates!\n";
  cout << "Player HP: " << player1.getHP() << "\n\n";
  // We can make the player head back to room three from room 4, and this will
  // be the second part of the fight in room 3.

  character enemy5("Big Goblin", 100, 28, 0);

  cout << "You reach a fork in the hallway and get turned around, you're back "
          "in room 3! The Goblin you just killed, well, his friend has found "
          "him and he's a lot bigger than he was.";
  while (player1.getHP() > 0 && enemy5.getHP() > 0) {
    int gamePlayChoice;
    cout << "Choose your move: \n";
    cout << "1. Attack\n";
    cout << "2. Defend\n";
    cout << "3. Use item\n";
    while (true) {
      cin >> gamePlayChoice;
      if (!cin) {
        cout << "Wrong Choice. Enter choice number again " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
      } else
        break;
    }
    while (gamePlayChoice <= 0 || gamePlayChoice > 3) {
      cout << "Please enter '1' for attack, '2' for defend, or '3' for use "
              "item.\n";
      while (true) {
        cin >> gamePlayChoice;
        if (!cin) {
          cout << "Wrong Choice. Enter choice number again " << endl;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          continue;
        } else
          break;
      }
    }
    // player chooses to attack
    if (gamePlayChoice == 1) {
      // generate random number to take away from enemy HP
      cout << "\nYou attack!\n";
      int playerdamage = player1.character::getAttack();
      enemy5.setHP(playerdamage);
      cout << "Enemy HP: " << enemy5.getHP() << "\n";
      // use enemies predefined attackDamage to take away HP points from player
      int enemydamage = enemy5.getEnemyAttack();
      player1.setHP(enemydamage);
      cout << "Player HP: " << player1.getHP() << "\n\n";

    } // enemy defends with smaller damage to creature
    else if (gamePlayChoice == 2) {
      cout << "\nYou defend!\n";
      int playerdefense = player1.character::getDefense();

      enemy5.setHP(playerdefense);
      cout << "Enemy HP: " << enemy5.getHP() << "\n";

      // enemy deals attack damage
      int enemydamage = enemy5.getEnemyDefenseAttack();
      player1.setHP(enemydamage);
      cout << "Player HP: " << player1.getHP() << "\n\n";

    } else if (gamePlayChoice == 3) {
      bag(player1);
    }
  }
  if (player1.getHP() > 0) {

    roomFive(player1);
  } else {
    loseGame(player1);
  }
}

void roomFour(player player1) {
  cout << "------------------------------\n";
  // reset health
  player1.fullHealth(100);
  cout << player1.getName() << "s health regenerates!\n";
  cout << "Player HP: " << player1.getHP() << "\n\n";
  // create enemy
  character enemy3("Robot", 100, 25, 0);
  // this room has a physical attack

  cout << "You step through the door with water drops painted on it and "
          "immediately fall through the floor and into an underground tunnel. "
          "The water is up to your waist but you must push forward. Finally "
          "you find a ladder that leads to another door. Inside that room is a "
          "robot...WITH GLOWING RED EYES! That can't be good.";
  while (player1.getHP() > 0 && enemy3.getHP() > 0) {
    int gamePlayChoice;
    cout << "Choose your move: \n";
    cout << "1. Attack\n";
    cout << "2. Defend\n";
    cout << "3. Use item\n";
    while (true) {
      cin >> gamePlayChoice;
      if (!cin) {
        cout << "Wrong Choice. Enter choice number again " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
      } else
        break;
    }
    while (gamePlayChoice <= 0 || gamePlayChoice > 3) {
      cout << "Please enter '1' for attack, '2' for defend, or '3' for use "
              "item.\n";
      while (true) {
        cin >> gamePlayChoice;
        if (!cin) {
          cout << "Wrong Choice. Enter choice number again " << endl;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          continue;
        } else
          break;
      }
    }
    // player chooses to attack
    if (gamePlayChoice == 1) {
      // generate random number to take away from enemy HP
      cout << "\nYou attack!\n";
      int playerdamage = player1.character::getAttack();
      enemy3.setHP(playerdamage);
      cout << "Enemy HP: " << enemy3.getHP() << "\n";
      // use enemies predefined attackDamage to take away HP points from player
      int enemydamage = enemy3.getEnemyAttack();
      player1.setHP(enemydamage);
      cout << "Player HP: " << player1.getHP() << "\n\n";

    } // enemy defends with smaller damage to creature
    else if (gamePlayChoice == 2) {
      cout << "\nYou defend!\n";
      int playerdefense = player1.character::getDefense();

      enemy3.setHP(playerdefense);
      cout << "Enemy HP: " << enemy3.getHP() << "\n";

      // enemy deals attack damage
      int enemydamage = enemy3.getEnemyDefenseAttack();
      player1.setHP(enemydamage);
      cout << "Player HP: " << player1.getHP() << "\n\n";

    } else if (gamePlayChoice == 3) {
      bag(player1);
    }
  }
  if (player1.getHP() > 0) {

    roomThreePartTwo(player1);
  } else {
    loseGame(player1);
  }
}

void roomFive(player player1) {
  cout << "------------------------------\n";
  // reset health
  player1.fullHealth(100);
  cout << player1.getName() << "s health regenerates!\n";
  cout << "Player HP: " << player1.getHP() << "\n\n";
  // create enemy
  character enemy4("Dragon", 100, 30, 0);
  // This room has a physical attack

  cout << "Once you make your way through the door with leaves poking through "
          "the cracks, you realize you are outside! Are you free? Was it all a "
          "dream? Of course it wasn't that easy. You see a sign and read 'Beware Dragons!'. Suddenly a dragon burst out from the tree line!";
  while (player1.getHP() > 0 && enemy4.getHP() > 0) {
    int gamePlayChoice;
    cout << "Choose your move: \n";
    cout << "1. Attack\n";
    cout << "2. Defend\n";
    cout << "3. Use item\n";
    while (true) {
      cin >> gamePlayChoice;
      if (!cin) {
        cout << "Wrong Choice. Enter choice number again " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
      } else
        break;
    }
    while (gamePlayChoice <= 0 || gamePlayChoice > 3) {
      cout << "Please enter '1' for attack, '2' for defend, or '3' for use "
              "item.\n";
      while (true) {
        cin >> gamePlayChoice;
        if (!cin) {
          cout << "Wrong Choice. Enter choice number again " << endl;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          continue;
        } else
          break;
      }
    }
    // player chooses to attack
    if (gamePlayChoice == 1) {
      // generate random number to take away from enemy HP
      cout << "\nYou attack!\n";
      int playerdamage = player1.character::getAttack();
      enemy4.setHP(playerdamage);
      cout << "Enemy HP: " << enemy4.getHP() << "\n";
      // use enemies predefined attackDamage to take away HP points from player
      int enemydamage = enemy4.getEnemyAttack();
      player1.setHP(enemydamage);
      cout << "Player HP: " << player1.getHP() << "\n\n";

    } // enemy defends with smaller damage to creature
    else if (gamePlayChoice == 2) {
      cout << "\nYou defend!\n";
      int playerdefense = player1.character::getDefense();

      enemy4.setHP(playerdefense);
      cout << "Enemy HP: " << enemy4.getHP() << "\n";

      // enemy deals attack damage
      int enemydamage = enemy4.getEnemyDefenseAttack();
      player1.setHP(enemydamage);
      cout << "Player HP: " << player1.getHP() << "\n\n";

    } else if (gamePlayChoice == 3) {
      bag(player1);
    }
  }
  if (player1.getHP() > 0) {

    roomSix(player1);
  } else {
    loseGame(player1);
  }
}

void roomSix(player player1) {
  cout << "------------------------------\n";
  // reset health
  player1.fullHealth(100);
  cout << player1.getName() << "s health regenerates!\n";
  cout << "Player HP: " << player1.getHP() << "\n\n";
  // This room is a riddle
  // added AA 07.23.22

  cout << "As you pass through the door, you see a glimse of sunlinght \n";
  cout << "A second later, the sunlight is gone as the door slams behind you\n";
  cout << "You find yourself in a long hallway, a heavy metal door stands shut "
          "at the end of the hallway.\n";
  cout << "------------------------------\n";
  cout << "------------------------------\n";
  cout << "------------------------------\n";
  cout << "------------------------------\n";
  cout << "to your left and right, small pannels open up, two voices call out "
          "in unison.\n";
  cout << "\"Answer our riddles and you can pass, but if you get both wrong, "
          "you can't.\" \n";
  secondRiddle(player1);

  // win or lose
  // I have to move the win or lose calculations to thirdRiddle() -AA.
}

void bag(player thePlayer) {
  item sword("Sword", 5, "Weapon");
  item helmet("Helmet", 5, "Armor");
  item potion("Potion", 10, "Potion");
  thePlayer.addToBag(sword);
  thePlayer.addToBag(helmet);
  thePlayer.addToBag(potion);

  int userChoice;
  cout << endl;

  if (thePlayer.bagSize() <= 0) {
    cout << "Bag is empty!" << endl;
  } else {
    try {
      thePlayer.displayBag();
    } catch (exception &e) {
      cout << e.what() << endl;
    }

    cout << endl;
    cin >> userChoice;

    while (userChoice <= 0 || userChoice > thePlayer.bagSize()) {
      cout << "Invalid input. Please try again: ";
      cin >> userChoice;
    }

    thePlayer.useItem(userChoice - 1);
    cout << "\nPlayer HP: " << thePlayer.getHP() << "\n";
  }
}

// End of game functions
void loseGame(player player1) {
  // dialogue for if the player loses
  cout << "You have fought rigorously through the challenges "
       << player1.getName()
       << "\n, but you have lost! Better luck next time.\n\n";
}

void winGame(player player1) {
  // dioalogue for when the player wins
  cout << "Congratulations " << player1.getName()
       << ". \nYou beat all of the evil scientists riddles and creatures! "
          "\nYou have bested the Genius at his own game. \nYOU WIN!\n\n";
}
