// SPDX-FileCopyrightText: 2022 Daniel S. Haag
//
// SPDX-License-Identifier: MIT
//
// \file Game.cpp
// \brief Compile unit defining module Game
//
// This is the base class of any game.
// It provides the basic idea of rounds, moves and players using
// the vocabulary of the concepts module.
module;

#include <concepts>
#include <type_traits>
#include <memory>
#include <array>

export module GameBasicsGame;

import GameBasicsConcepts;

export namespace GameBasics {
 
class Game {
  public:
    //===================================
    //RULE OF FIVE 
    Game(const Game&) = default;
    Game(Game&&) = default;
    Game& operator=(const Game&) = default;
    Game& operator=(Game&&) = default;
    virtual ~Game() = default;
    //===================================

    Game() = default;
};

}
