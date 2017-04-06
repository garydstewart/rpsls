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

#pragma once
#include <string>
#include <vector>
#include <random>
#include "display.h"

enum struct GameState
{
    // This is the game state machine to keep track of where we are in the execution of our program for flow control.
    // I am declaring constant member names as suggested in Google C++ Style Guide
    // https://google.github.io/styleguide/cppguide.html
    kTitle,
    kMenu,
    kPlayGame,
    kDisplayResult

};

class Game
{
public:
    Game();
    ~Game();
    void Reset() { winner = ""; is_tie = false; }
    auto Play(std::string string) -> void;

    

private:
    /**
     * \brief This vector holds the game pieces which should be in the following order:
     *  0 - Rock
     *  1 - Spock
     *  2 - Paper
     *  3 - Lizard
     *  4 - Scissors 
     */
    std::vector<std::string>                    game_pieces  = {"Rock","Spock","Paper","Lizard","Scissors"};

    std::random_device                          rd;

    /**
     * \brief Every game has a scoring system: here we assign the values to keep track of the wins.
     */
    int                                         player_score          = 0;
    int                                         ai_score              = 0;

    // containers for game logic
    int                                         player_choice_num     = 0;
    int                                         ai_choice_num         = 0;
    std::string                                 player_choice_str     = "";
    std::string                                 ai_choice_str         = "";
    std::string                                 winner                = "";
    bool                                        is_tie                = false;
    bool                                        banner_displayed      = false;
    /**
     * \brief  Searches for the game piece string (such as "Spock") in the vector
     * \return index of matched string
     */
    auto                                        NameToNumber(std::string name) -> int;

    /**
     * \brief Retrieves the item at index from the vector
     * \return name of game piece in "String" format
     */
    auto                                        NumberToName(int number)  -> std::string;
    auto                                        AiMakesChoice()           -> int;
    auto                                        CalculateWinner(int &ai_choice_num, int &player_choice_num)         -> void;
    auto                                        UpdateScore()             -> void;

};

