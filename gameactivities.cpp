#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <iomanip>
#include "variable.h"
#include "datastruc.h"
#include "animation.cpp"
using namespace std;

//first file
void text_animation(char a[100]);

bool insideBoard(int kRows, int kColumns, int Rows, int Columns) //rows, cols, row, col
{
   return Columns < kColumns && Columns >= 0 && Rows < kRows && Rows >= 0;
}

bool avoidCharacter(vector< vector<char> >& map, int Rows, int Columns, char Character) 
{
   for(int i = -1; i <= 1; i++) 
   {
      for(int j = -1; j <= 1; j++) 
      {
        if ((insideBoard(map.size(), map[0].size(), Rows + i,Columns + j)) && (map[Rows + i][Columns + j] == Character))
        {
            return false;
        }     
      }
   }
   return true;
}

bool zombieAlive(Character Zombie)
{
   return Zombie.Health > 0;
}
void gameItem(vector<vector<char>>& map, int Rows, int Columns, char Element)
{
   map[Rows][Columns] = Element;
}

char insertItem(vector<vector<char>> map, int Rows, int Columns)  
{
   return map[Rows][Columns];
}

void Stats(Character alien, vector<Character> zombies)
{
   cout << endl;
   if (alien.Health > 0)
   {
      cout << "Alien      :"
           << "Life   " << alien.Health << ", "
           << "Attack   " << alien.Attack << endl;
   }
   else if (alien.Health <= 0)
   {
      cout << "Alien      :"
           << "DEAD   " << endl;
   }

   for (int i = 0; i < zombies.size(); i++)
   {
      if (zombies.at(i).Health > 0)
      {
         cout << "Zombie " << i + 1 << "   :"
              << "Life   " << zombies.at(i).Health << ", "
              << "Attack   " << zombies.at(i).Attack << ", "
              << "Range   " << zombies.at(i).Ranged << endl;
      }
   }
   cout << endl;
}

void dropItem(vector<vector<char>> &map, int Rows, int Columns)
{
   int item = 1 + (rand() % 100);

   if (item > 0 && item <= 15 && avoidCharacter(map, Rows, Columns, alien) && avoidCharacter(map, Rows, Columns, zombie))
   {
      gameItem(map, Rows, Columns, rock);
   }
   else
   {
      gameItem(map, Rows, Columns, space);
   }

   if (item > 15 && item <= 25)
   {
      gameItem(map, Rows, Columns, arrow_up);
   }
   else if (item > 26 && item <= 35)
   {
      gameItem(map, Rows, Columns, arrow_down);
   }
   else if (item > 36 && item <= 45)
   {
      gameItem(map, Rows, Columns, arrow_left);
   }
   else if (item > 46 && item <= 55 )
   {
      gameItem(map, Rows, Columns, arrow_right);
   }
   else if (item > 56 && item <= 65)
   {
      gameItem(map, Rows, Columns, space);
   }
   else if (item > 66 && item <= 80)
   {
      gameItem(map, Rows, Columns, pod);
   }
   else if (item > 81 && item <= 100)
   {
      gameItem(map, Rows, Columns, health);
   }
}

void randomizeAttribute(int &attribute, int offset, int base)
{
   attribute = rand() % base + offset;
}

void randomizeItem(vector<vector<char>> &map, int kRows, int kColumns)
{
   for (int i = 0; i < kRows; i++)
   {
      for (int j = 0; j < kColumns; j++)
      {
         if ((insertItem(map, i, j) != alien) && (insertItem(map, i, j) != zombie))
         {
            dropItem(map, i, j);
         }
      }
   }
}

void randomizeCharacter(vector<vector<char>> &map, int kRows, int kColumns, char character, int &Rows, int &Columns) // pass by reference untuk pass value dari function ni ke main
{
   do
   {
      Rows = rand() % kRows;
      Columns = rand() % kColumns;
   } while ((insertItem(map, Rows, Columns) == alien) || (insertItem(map, Rows, Columns) == zombie) || (!avoidCharacter(map, Rows, Columns, alien)));

   gameItem(map, Rows, Columns, character);
}

void updateTrail(vector<vector<char>> &map, int kRows, int kColumns)
{
   for (int i = 0; i < kRows; i++)
   {
      for (int j = 0; j < kColumns; j++)
      {
         if (insertItem(map, i, j) == trail)
         {
            dropItem(map, i, j);
         }
      }
   }
   text_animation("Alien turn is over. Trail is reset");
   cout << endl;
}

