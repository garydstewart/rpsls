/*
* Rock Paper Scissors Lizard Spock
* Copyright(c) 2017 Gary D Stewart
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files(the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions :
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
*/

#include "display.h"

auto Display::Clear() -> void
{
#ifdef _WIN32
    HANDLE hConsole = nullptr;
    COORD coordScreen = { 0, 0 };    /* here's where we'll home the cursor */
    BOOL bSuccess;
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */
    DWORD dwConSize;                 /* number of character cells in the current buffer */

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    /* get the number of character cells in the current buffer */
    bSuccess = GetConsoleScreenBufferInfo(hConsole, &csbi);
    PERR(bSuccess, "GetConsoleScreenBufferInfo");
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    /* fill the entire screen with blanks */
    bSuccess = FillConsoleOutputCharacter(hConsole, TCHAR(' '),
        dwConSize, coordScreen, &cCharsWritten);
    PERR(bSuccess, "FillConsoleOutputCharacter");

    /* get the current text attribute */
    bSuccess = GetConsoleScreenBufferInfo(hConsole, &csbi);
    PERR(bSuccess, "ConsoleScreenBufferInfo");

    /* now set the buffer's attributes accordingly */
    bSuccess = FillConsoleOutputAttribute(hConsole, csbi.wAttributes,
        dwConSize, coordScreen, &cCharsWritten);
    PERR(bSuccess, "FillConsoleOutputAttribute");

    /* put the cursor at (0, 0) */
    bSuccess = SetConsoleCursorPosition(hConsole, coordScreen);
    PERR(bSuccess, "SetConsoleCursorPosition");
#endif
}

auto Display::DisplayChoice(std::string player_name, std::string game_piece_str) -> void
{
    std::cout << player_name.c_str() << " chooses " << game_piece_str.c_str() << std::endl;
}

auto Display::DisplayWinner(std::string winner, bool is_tie) -> void
{
    if(is_tie)
    {
        std::cout << "Player and Ai tie!" << std::endl;
    }
    else
    {
        std::cout << winner.c_str() << " wins!" << std::endl;
    }
}

auto Display::DisplayScore(int player_score, int ai_score) -> void
{ 
    std::cout << "********************"     << std::endl;
    std::cout << "Player: " << player_score << std::endl;
    std::cout << "Ai    : " << ai_score     << std::endl;
    std::cout                               << std::endl;
}
