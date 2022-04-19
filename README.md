<!--
SPDX-FileCopyrightText: 2022 Daniel S. Haag

SPDX-License-Identifier: MIT
-->

# GameBalancer
## Purpose
The purpose of this project is to get a new crasp at c++20 as a syntax training
and deep learning as a method training.

The idea is to build a compact, monolithic tool that evaluates a specific
game known at compile time, while providing strong modularisation on an
architectural level to increase the scope of game concepts available.

The behavioral training of the playing agent is done using reinforcment
learning.
At the time of the project start, it is unclear how the best procedure is to
train the net.
However, the idea is that a game is considered balanced if the accessable range
(possible or probable outputs) of a well trained net at different rounds of a
game is big, i.e., many, most, or all moves can make sense at all times
depending on the state of the game.


## First idea
Implement a very simple game of chance with two players.
Each turn, each player can decide to roll a natural number of dice.
The sum of the result is devided by the number of dice.
The player with the most points wins.

At every time all players know the score of each player and the number of
rounds to go.

Advantages:
1. It is completely stable: Only the variance is reduced by the decision how
   many dice to roll.
   No chaotic regimes occur and an a randomly initialized net will perform all
   right.
2. It contains enough randomness that the learning process should not overfit.
3. It is very simple to train the agent against a number of dumb AIs, i.e.,
   players who make the same move every turn.

Disadvantages:
1. This example probably does not need a deep net, any simple regression should
   do the trick of increasing the variance depending on the scoredifference and
   the remaining rounds.
2. The immediate return of a move probably is not well defined and will not
   converge all that neatly.


