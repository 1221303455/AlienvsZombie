#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

void text_animation(char a[100])
{
   int i;
   double k;
   for (i = 0; a[i] != '\0'; ++i)
   {
      for (k = 0; k < 30000000; ++k)
         ;
      cout << a[i];
   }
}