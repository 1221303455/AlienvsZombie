#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <iomanip>
#include "gameactivities.cpp"
using namespace std;

//secondfile

void gameBoard(vector < vector < char > > & map) {

    int kRows = map.size();
    int kColumns = map[0].size();

    cout << endl;
    for (int i = 0; i < kColumns; i++) {
        cout << "  ";
    }

    cout << endl;
    
    cout << " _______ _____   _______ _______ _______                       _______ _______ _______ ______ _______ _______ " << endl;
    cout << "|   _   |     |_|_     _|    ___|    |  |    .--.--.-----.    |__     |       |   |   |   __ |_     _|    ___|" << endl;
    cout << "|       |       |_|   |_|    ___|       |    |  |  |__ --|    |     __|   -   |       |   __ <_|   |_|    ___|" << endl;
    cout << "|___|___|_______|_______|_______|__|____|    |____/|_____|    |_______|_______|__|_|__|______|_______|_______|" << endl;
    cout << "                                                                                                              " << endl;
    
    cout << endl << "   |";
    for (int i = 0; i < kColumns - 1; i++) {
        cout << "-----+";
    }
    cout << "-----|" << endl;

    for (int Rows = 0; Rows < kRows; ++Rows) {
        if (Rows < 9) {
            cout << " ";
        }
        cout << Rows + 1 << " |";

        for (int Columns = 0; Columns < kColumns; ++Columns) {
            cout << "  " << map[Rows][Columns] << "  |";
        }

        cout << endl << "   |";
        for (int i = 0; i < kColumns - 1; i++) {
            cout << "-----+";
        }
        cout << "-----|" << endl;
    }

    cout << " ";
    for (int Columns = 0; Columns < kColumns; Columns++) {
        if (Columns < 9) {
            cout << "     " << Columns + 1;
        } else {
            cout << "    " << Columns + 1;
        }
    }
    cout << endl;
}