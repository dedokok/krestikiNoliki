#include <iostream>
#include <windows.h>
#include <string>

//kusok coda iz interneta dlya ochistki consoli
void cls(HANDLE hConsole)
{
    COORD coordScreen = { 0, 0 };    // home for the cursor
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;

    // Get the number of character cells in the current buffer.
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
    {
        return;
    }

    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    // Fill the entire screen with blanks.
    if (!FillConsoleOutputCharacter(hConsole,        // Handle to console screen buffer
        (TCHAR)' ',      // Character to write to the buffer
        dwConSize,       // Number of cells to write
        coordScreen,     // Coordinates of first cell
        &cCharsWritten)) // Receive number of characters written
    {
        return;
    }

    // Get the current text attribute.
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
    {
        return;
    }

    // Set the buffer's attributes accordingly.
    if (!FillConsoleOutputAttribute(hConsole,         // Handle to console screen buffer
        csbi.wAttributes, // Character attributes to use
        dwConSize,        // Number of cells to set attribute
        coordScreen,      // Coordinates of first cell
        &cCharsWritten))  // Receive number of characters written
    {
        return;
    }

    // Put the cursor at its home coordinates.
    SetConsoleCursorPosition(hConsole, coordScreen);
}


void proverka(char(&obama)[4][4], bool &igra){
    char pobeda = '#';
    std::cout << std::endl << "Proverka" << std::endl;

    for (int i = 1; i < 4; i++) {
        (obama[i][1] == obama[i][2] and obama[i][1] == obama[i][3] and obama[i][1] != '#') ? pobeda = obama[1][1] : 1 == 1;
    }



    for (int i = 1; i < 4; i++) {
        (obama[1][i] == obama[2][i] and obama[1][i] == obama[3][i] and obama[1][i] != '#') ? pobeda = obama[1][i] : 1 == 1;
    }

 

    (obama[1][1] == obama[2][2] and obama[1][1] == obama[3][3] and obama[1][1] != '#') ? pobeda = obama[1][1] : 1 == 1;
    (obama[3][1] == obama[2][2] and obama[3][1] == obama[1][3] and obama[3][1] != '#') ? pobeda = obama[3][1] : 1 == 1;



    if (pobeda != '#') {
        pobeda == '+' ? (std::cout << "Pobedili krestiki" << std::endl, igra = false) : (std::cout << "Pobedili noliki" << std::endl , igra = false);
    }

}



//void printKN(char(&obama)[4][4]) {
//    for (int i = 0; i < 4; i++) {
//        for (int j = 0; j < 4; j++) {
//            std::cout << obama[i][j];
//        }
//        std::cout << std::endl;
//    }
//    std::cout << std::endl;
//}



void ustanovka(char(&obama)[4][4], int vibor,bool &krestik,bool&igra,int&popitka) {
    char bukva;
    if (obama[vibor / 10][vibor % 10] == '#') {
        krestik == true ? (bukva = '+', krestik = false) : (bukva = 'o', krestik = true);
        obama[vibor / 10][vibor % 10] = bukva;
        proverka(obama, igra);
        popitka++;
    }
    else {
        std::cout << "Oshibka" << std::endl;
    }
}

void printPole(char(&obama)[4][4]) {
    std::string krestikStr_1 = "xxx     xxx ";
    std::string krestikStr_2 = " xxx   xxx  ";
    std::string krestikStr_3 = "  xxx xxx   ";
    std::string krestikStr_4 = "   xxxxx    ";
    std::string krestikStr_5 = "  xxx xxx   ";
    std::string krestikStr_6 = " xxx   xxx  ";
    std::string krestikStr_7 = "xxx     xxx ";
    std::string krestikMass[7] = { krestikStr_1,krestikStr_2,krestikStr_3,krestikStr_4,krestikStr_5,krestikStr_6,krestikStr_7 };

    std::string nolikStr_1 = "  ooooooo   ";
    std::string nolikStr_2 = " ooooooooo  ";
    std::string nolikStr_3 = "ooo     ooo ";
    std::string nolikStr_4 = "ooo     ooo ";
    std::string nolikStr_5 = "ooo     ooo ";
    std::string nolikStr_6 = " ooooooooo  ";
    std::string nolikStr_7 = "  ooooooo   ";
    std::string nolikMass[7] = { nolikStr_1,nolikStr_2,nolikStr_3,nolikStr_4,nolikStr_5,nolikStr_6,nolikStr_7 };

    std::string pustoStr_1 = "            ";
    std::string pustoStr_2 = "            ";
    std::string pustoStr_3 = "            ";
    std::string pustoStr_4 = "            ";
    std::string pustoStr_5 = "            ";
    std::string pustoStr_6 = "            ";
    std::string pustoStr_7 = "            ";
    std::string pustoMass[7] = { pustoStr_1,pustoStr_2,pustoStr_3,pustoStr_4,pustoStr_5,pustoStr_6,pustoStr_7 };


    std::string stroka_1 = "";

    for (int i = 1; i < 4; i++) {
        for (int g = 0; g < 7; g++) {
            for (int j = 1; j < 4; j++) {

                if (obama[i][j] == '#') {
                    std::cout << pustoMass[g];
                }
                
                if (obama[i][j] == '+') {
                    std::cout << krestikMass[g];
                }
                
                if (obama[i][j] == 'o') {
                    std::cout << nolikMass[g];
                }
                if (j < 3) {
                    std::cout << " |";
                }
                
                
            }
            std::cout << std::endl;
        }
        if (i < 3) {
            std::cout << "_____________" << "_____________" << "_____________" << std::endl;
        }

    }
}

int main() {
    HANDLE hStdout;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    char obama[4][4];
    bool igra = true, krestik = true;
    int vibor, popitka = 0;
    std::string krestikStr = "xxx\txxx\n xxx   xxx\n  xxx xxx\n   xxxxx\n  xxx xxx\n xxx   xxx\nxxx\txxx\n";
    std::string nolikStr = "  ooooooo\n ooooooooo\nooo     ooo\nooo     ooo\nooo     ooo\n ooooooooo\n  ooooooo\n";
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            obama[i][j] = '#';
        }
    }
    for (int i = 0; i < 4; i++) {
        obama[i][0] = i + '0';
        obama[0][i] = i + '0';
    }
    printPole(obama);
    //printKN(obama);
    //std::cout << krestikStr << "\t" << std::endl << nolikStr << std::endl;
    while (igra) {
        if (popitka == 8) { std::cout << "Nichya" << std::endl; igra = false; }
        krestik ? std::cout << "Krestik: " : std::cout << "Nolik: ";
        std::cin >> vibor;
        std::cout << std::endl;
        ustanovka(obama, vibor, krestik, igra, popitka);
        cls(hStdout);
        printPole(obama);
        //printKN(obama);
    }
    
}