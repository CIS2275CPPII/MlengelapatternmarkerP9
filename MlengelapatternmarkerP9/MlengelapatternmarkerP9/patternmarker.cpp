/************************************************************************************
* Program: Pattern Marker
* Programmer: Daudi Mlengela(dmlengela@cnm.edu)
* Date: November 22, 2022
* Purpose: To create pattern marker for the Game of life
*************************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::vector;
using std::string;

static const int ROWS = 45;
static const int COLUMNS = 78;

//const string fileName = "blinker.txt";
//const string fileName = "cross.txt";
//const string fileName = "glider.txt";
//const string fileName = "pulsar.txt";
//const string fileName = "x.txt";


int main()
{
    vector<string> pattern;
    for (int i = 0; i < ROWS; i++)
    pattern.push_back(string(COLUMNS, '.'));

    std::cout << "Welcome to Pattern Maker!\n";
    std::cout << "The pattern is " << ROWS << " rows x " << COLUMNS << " columns\n";
    std::cout << "You'll enter the row and column of each live cell\n\n";

    do
    {
        int row = 0;
        int column = 0;

        std::cout << "Enter row, 1 - " << ROWS << " or -1 to quit: ";
        std::cin >> row;

        if (row == -1)
            break;

        if (row < 1 || row > ROWS)
            continue;

        std::cout << "Enter column, 1 - " << COLUMNS << ": ";
        std::cin >> column;

        if (column < 1 || column > COLUMNS)
            continue;

        pattern[row - 1][column - 1] = '*';


    } while (true);
    

    //std::ifstream input;
    //input.open("x.txt");

    string fileName;
    std::cout << "Enter file name: ";
    std::cin >> fileName;

    std::ofstream out(fileName);

    if (!out)
    {
        std::cout << "Could not open: " << fileName << "\n";
    }
    else
    {
        bool arrayOutput = false;
        if (!arrayOutput)
        {
            out << ROWS << " " << COLUMNS << "\n";

            for (int i = 0; i < ROWS; i++)
                out << pattern[i] << "\n";
        }
        else
        {
            out << "const char *pattern[] = {\n";

            for (int j = 0; j < COLUMNS; j++)
                out << "   \"" << pattern[j] << "\",\n";

            out << "};\n";
        }
    }
}