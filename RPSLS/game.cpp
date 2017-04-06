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

#include "game.h"
#include <algorithm>


Game::Game()
{
    
}


Game::~Game()
{
}


auto Game::Play(std::string string) -> void
{
    player_choice_str = string;
    
    // obtain numerical representation of game pieces
    player_choice_num       = NameToNumber(player_choice_str);
    ai_choice_num           = AiMakesChoice();
 
    // display player's choice
    Display::DisplayChoice("Player", player_choice_str);

    // get string representation of Ai choice
    ai_choice_str           = NumberToName(ai_choice_num);

    // display Ai's choice
    Display::DisplayChoice("Ai", ai_choice_str);

    CalculateWinner(ai_choice_num, player_choice_num);

    Display::DisplayWinner(winner, is_tie);

    UpdateScore();

    // todo: refactor and make it display at end of game rounds

    Display::DisplayScore(player_score, ai_score);

    // todo: update game state and menu
    Reset();

}

int mod(int k, int n) { return ((k %= n) < 0) ? k + n : k; }

auto Game::CalculateWinner(int &ai_choice_num, int &player_choice_num) -> void
{
    int result = mod((ai_choice_num - player_choice_num),5);
    if(result == 0)
    {
        this->is_tie = true;
    }
    else if(result <= 2)
    {
        this->winner = "Ai";
    }
    else if (result >= 3)
    {
        this->winner = "Player";
    }
}

auto Game::UpdateScore() -> void
{
    //todo: a bit messy. probably a cleaner, simpler way to do this
    if(!is_tie && winner == "Player")
    {
        player_score += 1;
    }
    else if(!is_tie && winner == "Ai")
    {
        ai_score += 1;
    }

    // if tie, do nothing. dont even need to check for condition here
}

auto Game::NameToNumber(std::string name) -> int
{
    auto game_piece_iter = find(game_pieces.begin(), game_pieces.end(), name);
    if(game_piece_iter != game_pieces.end())
    {
        return distance(game_pieces.begin(), game_piece_iter);
    }
    else
    {
        throw "INVALID_GAME_PIECE";
    }
}

auto Game::NumberToName(int number) -> std::string
{
    return game_pieces[number];
}

auto Game::AiMakesChoice() -> int
{
    /**
    * \brief This is by default the mersenne twister engine that we will use to determine the roll results.
    * We will use it to pick a value between (incuding) 0 and 4.
    */
    
    // this generates a random seed, we do it a few times to make sure it is warmed up
    std::seed_seq seed{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
    std::mt19937_64 mt(seed);
    // pick a random index of game_pieces vector. scope is set by game_pieces.size
    std::uniform_int_distribution<int> distribution(0,game_pieces.size() -1);
    return distribution(mt);
}

