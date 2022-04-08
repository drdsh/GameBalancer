// SPDX-FileCopyrightText: 2022 Daniel S. Haag
//
// SPDX-License-Identifier: MIT
//
// \file Move.cpp
// \brief Compile unit defining module Move
module

#include <vector>
#include <memory>

export module GameBasics::Move;

export template <class INT>
class Move {
      INT a {0};
      std::vector<INT> b;
    public:
      INT getA() {return a;}
};
