#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include "alienzomaction.cpp"
using namespace std;

void gameSetting(vector<vector<char>> &map, int &kRows, int &kColumns, int &numZombies)
{
   int newRow;
   int newCol;
   int userZombie;
   char userDecide;

   system("CLS");

   cout << "      _             _                                 " << endl;
   cout << "  ___| |_ __ _ _ __| |_    __ _  __ _ _ __ ___   ___  " << endl;
   cout << " / __| __/ _` | '__| __|  / _` |/ _` | '_ ` _  |/ _ | " << endl;
   cout << " |__ | || (_| | |  | |_  | (_| | (_| | | | | | |  __/ " << endl;
   cout << " |___/__|__,_|_|    __|   __, ||__,_|_| |_| |_||____| " << endl;
   cout << "                          |___/                       " << endl;
   cout << "\t+=====================================+" << endl
        << "\t|        Current Settings:            |" << endl
        << "\t+=====================================+" << endl
        << "\t|                                     |" << endl
        << "\t| Rows:      " << kRows << "                        |" << endl
        << "\t| Columns:   " << kColumns << "                       |" << endl
        << "\t| Total Zombies: " << numZombies << "                    |" << endl
        << "\t|                                     |" << endl
        << "\t| Do you want to change game settings?|" << endl  
        << "\t|"
        << " Y to change game settings           |" << endl
        << "\t|"
           " N"
           " to start game                     |"
        << endl
        << "\t| (y/n)                               |" << endl
        << "\t+=====================================+" << endl;

   cout << "-> Input: ";
   cin >> userDecide;
   if (userDecide == 'y' || userDecide == 'Y')
   {
      system("CLS");
      cout << "--==+Game Configurations+==--" << endl;
      int correctInput = 0;
      while (correctInput == 0)
      {
         cout << "Enter new Row (Value of at least 5 is suggested) : ";
         cin >> newRow;

         if (newRow % 2 == 1)
         {
            kRows = newRow;
            break;
         }
         else
         {
            cout << "Your input must be an odd number! Please try again." << endl;
            cout << endl;
            newRow = 0;
         }
      }
      cout << endl;
      while (correctInput == 0)
      {
         cout << "Enter new Columns (Value of at least 5 is suggested) : ";
         cin >> newCol;

         if (newCol % 2 == 1)
         {
            kColumns = newCol;
            break;
         }
         else
         {
            cout << "Your input must be an odd number! Please try again." << endl;
            cout << endl;
            newCol = 0;
         }
      }
      cout << endl;
      while (correctInput == 0)
      {
         cout << "Enter new Zombie Count (1 ~ 10): ";
         cin >> userZombie;

         if ((userZombie >= 1) && (userZombie <= 10))
         {
            numZombies = userZombie;
            break;
         }
         else
         {
            cout << "Your input must be between 1 ~ 10!" << endl;
            userZombie = 0;
         }
      }

      system("PAUSE");
   }
}

void quitGame()
{
   char userDecision;

   text_animation("Quit the game? (y/n) : ");
   cout << endl;
   cin >> userDecision;
   if (userDecision == 'y' || userDecision == 'Y')
   {
      // Save game data
   }
   else if (userDecision == 'n' || userDecision == 'N')
   {
      // gameEnd = false;
   }
}

void restartGame(bool &gameEnd, bool &mainEnd)
{
   char userDecision;

   cout << endl;
   text_animation("Do you want to play again? (y/n) : ");
   cin >> userDecision;
   if (userDecision == 'y' || userDecision == 'Y')
   {
      gameEnd = true;
   }
   else if (userDecision == 'n' || userDecision == 'N')
   {
      text_animation("THANK YOU FOR PLAYING THE GAME! HOPE YOU ENJOY THE GAME :)");
      cout << endl;

      gameEnd = true;
      mainEnd = true;
      system("EXIT");
   }
}

void movementArrow(vector<vector<char>> &map, int kRows, int kColumns, int arrowRow, int arrowCol, string choice)
{
   if (insertItem(map, arrowRow, arrowCol) == arrow_up ||
       insertItem(map, arrowRow, arrowCol) == arrow_down ||
       insertItem(map, arrowRow, arrowCol) == arrow_left ||
       insertItem(map, arrowRow, arrowCol) == arrow_right)
   {

      cout << "\nInto what direction you want to change?" << endl;
      cout << "-> Direction: ";
      cin >> choice;

      if (choice == "up")
      {
         gameItem(map, arrowRow, arrowCol, arrow_up);
      }
      else if (choice == "down")
      {
         gameItem(map, arrowRow, arrowCol, arrow_down);
      }
      else if (choice == "left")
      {
         gameItem(map, arrowRow, arrowCol, arrow_left);
      }
      else if (choice == "right")
      {
         gameItem(map, arrowRow, arrowCol, arrow_right);
      }
      else
      {
         cout << "\nWrong Input. Please enter a valid input. :)" << endl;
      }
      gameBoard(map);
   }
   else
   {
      text_animation("\nYou can change arrow direction only!");
      cout << endl;
   }
}

void commandMenu(vector<vector<char>> &map, int kRows, int kColumns, Character &alien, vector<Character> &zombies, int numOfZombies, bool &gameEnd, bool &mainEnd)
{
   string command;
   string choice;

   cout << "\nCommands:  Move: M/m  Change Arrow: C/c  Help: H/h  Quit: Q/q \n";
   cout << "\n-> Choose an option => ";

   cin >> command;

   if ((command == "M") || (command == "m"))
   {
      cout << "\t+================================+" << endl
           << "\t|           .:COMMAND:.          |" << endl
           << "\t+================================+" << endl
           << "\t| MOVE UP    : up                |" << endl
           << "\t| MOVE DOWN  : down              |" << endl
           << "\t| MOVE RIGHT : right             |" << endl
           << "\t| MOVE LEFT  : left              |" << endl
           << "\t+================================+" << endl;

      cout << "\n-> Insert a movement => ";
      cin >> choice;

      movementAlien(map, kRows, kColumns, alien, zombies, choice);

      system("CLS");
      gameBoard(map);
      Stats(alien, zombies);
      updateTrail(map, kRows, kColumns);
      system("PAUSE");

      bool game_end;
      bool main_end;
      int counter = 0;
      for (int i = 0; i < zombies.size(); i++)
      {
         if (zombies.at(i).Health > 0)
         {
            system("CLS");
            gameBoard(map);
            Stats(alien, zombies);
            zombieAction(map, kRows, kColumns, zombies.at(i), i);
            zombieAttack(map, kRows, kColumns, numOfZombies, alien, zombies.at(i), i);
            system("PAUSE");
         }
         else
         {
            counter++;
            gameItem(map, zombies.at(i).Rows, zombies.at(i).Columns, space);
            system("CLS");
            gameBoard(map);
            Stats(alien, zombies);
            system("PAUSE");
         }
         if (alien.Health <= 0)
         {
            text_animation("ALIEN DEAD!!!");
            cout << endl;
            restartGame(game_end, main_end);
            gameEnd = game_end;
            mainEnd = main_end;
            system("PAUSE");
            break;
         }
      }
      if (zombies.size() == counter)
      {
         text_animation("ALIEN WIN!!!");
         cout << endl;
         restartGame(game_end, main_end);
         gameEnd = game_end;
         mainEnd = main_end;
         system("PAUSE");
      }
   }
   else if ((command == "C") || (command == "c"))
   {
      string decide;
      int arrowRows;
      int arrowColumns;

      cout << "\nRow: ";
      cin >> arrowRows;

      cout << "Column: ";
      cin >> arrowColumns;

      movementArrow(map, kRows, kColumns, arrowRows - 1, arrowColumns - 1, decide);
   }
   else if ((command == "H") || (command == "h"))
   {
    cout << "+================================================+" << endl
         << "|                  Help Center                   |" << endl
         << "+================================================+ " << endl
         << "| ALIEN MOVEMENT        | CHANGE ARROW DIRECTION |" << endl
         << "+-----------------------+------------------------+ " << endl
         << "| MOVE UP    : up       | ARROW UP    : up       |" << endl
         << "| MOVE DOWN  : down     | ARROW DOWN  : down     |" << endl
         << "| MOVE RIGHT : right    | ARROW RIGHT : right    |" << endl
         << "| MOVE LEFT  : left     | ARROW LEFT  : left     |" << endl
         << "+=======================+========================+\n"
         << endl;
      system("pause");
   }
   else if ((command == "Q") || (command == "q"))
   {
      text_animation("Thank you for playing!");
      cout << endl;
      gameEnd = true;
      mainEnd = true;
      system("exit");
   }
   else
   {
      cout << "Command is invalid, please try other commands" << endl;
   }
}

int main()
{
   srand(time(0)); 
   vector<vector<char>> map;
   int numOfZombies = 2;
   int rows = 5;
   int cols = 11;

   vector<Character> zombies;
   Character aliens;

   bool mainEnd = false;
   while (!mainEnd)
   {
      bool gameEnd = false;

      gameSetting(map, rows, cols, numOfZombies);

      map.clear();
      zombies.clear();

      map.resize(rows);
      for (int i = 0; i < rows; i++)
      {
         map[i].resize(cols);
      }

      aliens.Rows = rows / 2;
      aliens.Columns = cols / 2;

      randomizeAttribute(aliens.Health, 20, 20);
      gameItem(map, aliens.Rows, aliens.Columns, alien);

      for (int i = 0; i < numOfZombies; i++)
      {
         Character Zombie;
         zombies.push_back(Zombie);
         randomizeAttribute(zombies.at(i).Health, 10, 15);

         do
         {
            randomizeAttribute(zombies.at(i).Attack, 10, 25);
         } 
         while (zombies.at(i).Attack > aliens.Health);

         randomizeAttribute(zombies.at(i).Ranged, 1, rows);
         randomizeCharacter(map, rows, cols, zombie, zombies.at(i).Rows, zombies.at(i).Columns);

         gameItem(map, zombies.at(i).Rows, zombies.at(i).Columns, zombie);
      }
      randomizeItem(map, rows, cols);

      while (!gameEnd)
      {
         aliens.Attack = 0;
         system("cls");
         gameBoard(map);
         Stats(aliens, zombies);
         commandMenu(map, rows, cols, aliens, zombies, numOfZombies, gameEnd, mainEnd);
      }
   }
}