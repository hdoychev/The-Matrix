#include <iostream>
#include <windows.h>
#include <string>
#include <stdlib.h>


using namespace std;
int Size(char*);
int main() 
{
    HANDLE  H_Console;//color
    H_Console = GetStdHandle(STD_OUTPUT_HANDLE);//color of output
    SetConsoleTextAttribute(H_Console, 2);//color
    char abc[38]= { '!','@','#','$','%','^','&','*',' ','(',')','_','+','=',' ','-','0','9','8','7',' ','6','5','4','3','2',' ','1','\\',']',' ','[',';','\'','/','.',',' };
    char previous[101] = { 0 };
    int log[101] = { 0 };


    int abcSize = Size(abc) -1;//len array
    while (true)
    {
        cout << "       ";
        for (int c = 0; c < 100; c++)
        {
            int randomSpace = rand() % 20 + 7;
            int randomNo = rand() % 38;
            if (previous[c] == ' ' && log[c] < randomSpace)//interval na random princip
            {
                cout<< " ";
                log[c]++;
            }
            else
            {
                int random = rand() % abcSize/*+1*/;
                if (rand() % 50 == 0)//color white
                {
                    SetConsoleTextAttribute(H_Console, 7);
                    cout << abc[random];
                    SetConsoleTextAttribute(H_Console, 10);
                }
                else if (rand() % 100 == 0)//color grey
                {
                    SetConsoleTextAttribute(H_Console, 8);
                    cout << abc[random];
                    SetConsoleTextAttribute(H_Console, 2);
                }
                else if (rand() % 200 == 0)//color grey
                {
                    SetConsoleTextAttribute(H_Console, 15);
                    cout << abc[random];
                    SetConsoleTextAttribute(H_Console, 2);
                }
                else
                {
                    cout << abc[random];//just green
                }
                previous[c] = abc[random];//predishen element
                log[c] = 1;//intervali v kolona random
            }
        }
        Sleep(66);
        cout <<'\n';
    }
    return 0;
}

int Size(char*arr)
{
    int len = 0;
    while (arr[len] != '\0')
    {
        ++len;

    }
    return len;
}