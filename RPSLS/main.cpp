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

/*
 * Rock Paper Scissors Lizard Spock is an extension of the well known game Rock Paper Scissors made popular by Sheldon on Big Bang Theory.
 * 
 * In the traditional game, Rock Paper Scissors, players would often tie. This introduces two new elements, Lizard, and Spock
 * 
 *  Players pick one of the items simultaneously and then compare the results to determine the winner.
 * The winning combinations are as follows as told by Sheldon:
 *  
 * The rules are simple:
 * 
 * Scissors cuts Paper
 * Paper covers Rock
 * Rock crushes Lizard
 * Lizard poisons Spock
 * Spock smashes Scissors
 * Scissors decapitates Lizard
 * Lizard eats Paper
 * Paper disproves Spock
 * Spock vaporizes Rock
 * and as it always has, Rock crushes scissors
 * 
 */

// 0 - Rock
// 1 - Spock
// 2 - Paper
// 3 - Lizard
// 4 - Scissors

#include <memory>
#include "game.h"
auto main() -> void
{
    auto game = std::make_shared<Game>();
    game->Play("Rock");
    game->Play("Paper");
    game->Play("Scissors");
    game->Play("Lizard");
    game->Play("Spock");
    
}
