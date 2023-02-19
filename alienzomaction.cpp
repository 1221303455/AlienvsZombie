#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <iomanip>
#include "gameboard.cpp"
//thirdfile

using namespace std;

void podDamage(vector<vector<char>> board, Character &zombie, int damage, int counter)
{
   zombie.Health -= damage;

   if (zombie.Health <= 0)
   {
      cout << endl;
      text_animation("Zombie ");
      cout << ++counter;
      text_animation(" was killed by Pod.");
      cout << endl;
   }
}

void alienAttack(vector<vector<char>> &map, Character &alien, vector<Character> &zombies, bool &isEnding)
{
   for (int i = 0; i < zombies.size(); i++)
   {
      if ((abs((zombies.at(i).Rows - alien.Rows) + (zombies.at(i).Columns - alien.Columns)) == 1) &&
          ((zombies.at(i).Rows == alien.Rows) || (zombies.at(i).Columns == alien.Columns)))
      {
         zombies.at(i).Health -= alien.Attack;
         text_animation("You inflicted ");
         cout << alien.Attack;
         text_animation(" damage on Zombie ");
         cout << i + 1 << endl;
         if (zombies.at(i).Health <= 0)
         {
            gameItem(map, zombies.at(i).Rows, zombies.at(i).Columns, space);
            cout << endl;
            text_animation("Zombie ");
            cout << i + 1;
            text_animation(" is dead.");
            cout << endl;
            isEnding = false;
         }
         else if (zombies.at(i).Health > 0)
         {
            isEnding = true;
         }
      }
   }
}

void zombieAttack(vector<vector<char>> map, int kRows, int kColumns, int numOfZombies, Character &alien, Character &zombie, int counter)
{
   if (((zombie.Rows == alien.Rows) && ((zombie.Columns - zombie.Ranged <= alien.Columns) && (zombie.Columns + zombie.Ranged >= alien.Columns))) ||
       ((zombie.Columns == alien.Columns) && ((zombie.Rows - zombie.Ranged <= alien.Rows) && (zombie.Rows + zombie.Ranged >= alien.Rows))))
   {
      alien.Health -= zombie.Attack;
      text_animation("You have been attacked by Zombie ");
      cout << ++counter;
      text_animation(" for ");
      cout << zombie.Attack;
      text_animation(" damage.");
      cout << endl;
      cout << endl;
   }
}

void movementAlien(vector<vector<char>> &map, int kRows, int kColumns, Character &aliens, vector<Character> &zombies, string command)
{
   bool isEnding = false;
   int futRow = aliens.Rows;
   int futCol = aliens.Columns;

   while (!isEnding)
   {
      system("CLS");
      gameBoard(map);
      Stats(aliens, zombies);

      gameItem(map, futRow, futCol, trail);
      if (command == "up")
      {
         futRow--;
      }
      else if (command == "down")
      {
         futRow++;
      }
      else if (command == "left")
      {
         futCol--;
      }
      else if (command == "right")
      {
         futCol++;
      }

      if (insideBoard(kRows, kColumns, futRow, futCol))
      {
         if (insertItem(map, futRow, futCol) == arrow_down)
         {
            command = "down"; 
            aliens.Attack += 20;
            cout << endl;
            text_animation("DOWN ARROW AHEAD!");
            cout << endl;
            text_animation("Alien will move down and gain 20 attack!");
            cout << endl;
            cout << endl;
         }

         else if (insertItem(map, futRow, futCol) == arrow_up)
         {
            command = "up";
            aliens.Attack += 20;
            cout << endl;
            text_animation("UP ARROW AHEAD!");
            cout << endl;
            text_animation("Alien will move up and gain 20 attack!");
            cout << endl;
            cout << endl;
         }

         else if (insertItem(map, futRow, futCol) == arrow_left)
         {
            command = "left";
            aliens.Attack += 20;
            cout << endl;
            text_animation("LEFT ARROW AHEAD!");
            cout << endl;
            text_animation("Alien will move left and gain 20 attack!");
            cout << endl;
            cout << endl;
         }

         else if (insertItem(map, futRow, futCol) == arrow_right)
         {
            command = "right";
            aliens.Attack += 20;
            cout << endl;
            text_animation("RIGHT ARROW AHEAD!");
            cout << endl;
            text_animation("Alien will move right and gain 20 attack!");
            cout << endl;
            cout << endl;
         }

         else if (insertItem(map, futRow, futCol) == health)
         {
            aliens.Health += 20;
            cout << endl;
            text_animation("Alien found HEALTH BOOST!");
            cout << endl;
            text_animation("Alien Health +20");
            cout << endl;
            cout << endl;
         }

         else if (insertItem(map, futRow, futCol) == pod)
         {
            cout << endl;
            text_animation("Alien found POD!");
            cout << endl;
            text_animation("Every Zombie Health -10");
            cout << endl;
            for (int i = 0; i < zombies.size(); i++) 
            {
               podDamage(map, zombies.at(i), 10, i);
            }
            cout << endl;
         }

         else if (insertItem(map, futRow, futCol) == zombie)
         {
            bool ensure;
            text_animation("WATCH OUT! ZOMBIE AHEAD!");
            cout << endl;
            alienAttack(map, aliens, zombies, ensure);
            isEnding = ensure;
         }

         if (!(insertItem(map, futRow, futCol) == rock || insertItem(map, futRow, futCol) == zombie))
         {
            aliens.Rows = futRow;
            aliens.Columns = futCol;
         }

         if (insertItem(map, futRow, futCol) == rock)
         {
            do
            {
               dropItem(map, futRow, futCol);
            } while (insertItem(map, futRow, futCol) == rock);

            cout << endl;
            text_animation("THERE'S ROCK AHEAD!");
            cout << endl;
            text_animation("You found something lies behind it!");
            cout << endl;
            cout << endl;
            isEnding = true;
         }
         gameItem(map, aliens.Rows, aliens.Columns, alien);
      }
      else
      {
         cout << endl;
         text_animation("Alien hit the border!");
         cout << endl;
         cout << endl;
         isEnding = true;
      }
      gameItem(map, aliens.Rows, aliens.Columns, alien);
      system("PAUSE");
   }
}

void zombieAction(vector<vector<char>> &map, int kRows, int kColumns, Character &zombies, int counter)
{
   srand(time(0));
   int futRow = zombies.Rows;
   int futCol = zombies.Columns;
   int item = rand() % 3;

   gameItem(map, zombies.Rows, zombies.Columns, space);

   if (item == 0)
   {
      futRow--;
   }
   else if (item == 1)
   {
      futRow++;
   }
   else if (item == 2)
   {
      futCol--;
   }
   else if (item == 3)
   {
      futCol++;
   }

   if ((insideBoard(kRows, kColumns, futRow, futCol)) &&
       (insertItem(map, futRow, futCol) != rock) &&
       (insertItem(map, futRow, futCol) != zombie) &&
       (insertItem(map, futRow, futCol) != alien) &&
       (zombieAlive(zombies)))
   {
      if (item == 0)
      {
         zombies.Rows--;
         text_animation("Zombie ");
         cout << ++counter;
         text_animation(" moves up.");
         cout << endl;
      }
      else if (item == 1)
      {
         zombies.Rows++;
         text_animation("Zombie ");
         cout << ++counter;
         text_animation(" moves down.");
         cout << endl;
      }
      else if (item == 2)
      {
         zombies.Columns--;
         text_animation("Zombie ");
         cout << ++counter;
         text_animation(" moves left.");
         cout << endl;
      }
      else if (item == 3)
      {
         zombies.Columns++;
         text_animation("Zombie ");
         cout << ++counter;
         text_animation(" moves right.");
         cout << endl;
      }
   }
   else
   {
      text_animation("Zombie ");
      cout << ++counter;
      text_animation(" decided to stay stationary.");
      cout << endl;
   }
   gameItem(map, zombies.Rows, zombies.Columns, zombie);
}