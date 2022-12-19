// Practica1IS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h >
#include <conio.h>

using namespace std;


int main()
{
    char array[20];
    const int array_size = sizeof(array) / sizeof(char);
    for (int i = 0; i < array_size; i++)
    {
        array[i] = ' ';
    }
    array[0] = 'A';

    unsigned int i_pos_o = 0;
    unsigned int i_pos_e = 255;
    unsigned int i_counter = 0;
    bool end_game = false;

    while (!end_game)
    {
        system("cls");
        array[0] = 'A';

        
        if (i_pos_o != 0)
        {
             i_pos_o++;

            array[i_pos_o-1] = ' ';
            array[i_pos_o] = 'o';
        }
        
        else if (GetKeyState(VK_RETURN) < 0 && i_pos_o == 0)
        {
            i_pos_o = 1;
        }        

        if (i_pos_e != 255)
        {
            i_pos_e--;

            array[i_pos_e + 1] = ' ';
            array[i_pos_e] = 'E';
        }
        else
        {
            i_pos_e = array_size - 1;
        }


        if (i_pos_e <= i_pos_o) 
        {
            array[i_pos_e] = ' ';
            i_pos_e = 255;
            i_pos_o = 0;
            i_counter++;
        }
        if (i_pos_e <= 1)
        {
            printf("GAME OVER");
            end_game = true;
        }
        else
        {
            for (int i = 0; i < sizeof(array) / sizeof(char); i++)
            {
                printf("%c", array[i]);
            }
            printf("\nCounter: %d", i_counter);
        }
        
        
        Sleep(200);
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
