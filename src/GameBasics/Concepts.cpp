// SPDX-FileCopyrightText: 2022 Daniel S. Haag
//
// SPDX-License-Identifier: MIT
//
// \file Concepts.cpp
// \brief Compile unit defining module Concepts
//
// This is the major content of GameBasics, it defines most of the vocabulary
// and makes the creation of custom games possible without interfaces or
// abstract classes
module;

#include <concepts>
#include <type_traits>
#include <array>
#include <exception>
#include <iterator>

export module GameBasicsConcepts;

///===================================
//HELPERS AND EXAMPLES

//Helper to check that some size_t is constexpr
template<size_t> using checkTemplate = void;

//Examples
class ExampleInputOutput {
    double someDoubleValue {1.};
    int someIntValue {2};
  public:
    constexpr static size_t size {2};

    //Implementations should provide iterator concepts for floating_point_iterator
    void copyTo(auto from, auto to) {
      if (from == to) {
        throw std::range_error("ExampleInputOutput::copyTo: invalid range provided");
      }
      *from = static_cast<std::iter_value_t<decltype(from)>>(someDoubleValue);
      if (++from == to) {
        throw std::range_error("ExampleInputOutput::copyTo: invalid range provided");
      }
      *from = static_cast<std::iter_value_t<decltype(from)>>(someIntValue);
      if (++from != to) {
        throw std::range_error("ExampleInputOutput::copyTo: invalid range provided");
      }
    }

    //Implementations should provide iterator concepts for floating_point_iterator
    ExampleInputOutput(auto from, auto to):
      someDoubleValue {static_cast<double>(*from)},
      someIntValue {static_cast<int>(*++from)} {}
};

class ExampleMove: public ExampleInputOutput {
  public:
    ExampleMove(auto from, auto to):
      ExampleInputOutput(from, to) {}
};

class ExampleGameView: public ExampleInputOutput {
  public:
    ExampleGameView(auto from, auto to):
      ExampleInputOutput(from, to) {}
};
///===================================

export namespace GameBasics {
  
template<typename T>
concept isInputOutput = requires
    (T t, std::array<float, 10> floatArray, std::array<double, 10> doubleArray) {
  //size, which is the number of parameters the input output object maps to can
  //be used in templates (is constexpr and convertible to size_t)
  typename checkTemplate<T::size>;

  //there must be a copy_to function to an iterator type of float and double
  t.copyTo(floatArray.begin(), floatArray.end());
  t.copyTo(doubleArray.begin(), doubleArray.end());

  //there must be a constructor from an iterator type of float and double
  T(floatArray.begin(), floatArray.end());
  T(doubleArray.begin(), doubleArray.end());
};
static_assert(isInputOutput<ExampleInputOutput>);

//Move is the output of a players call to move (output object)
template<typename T>
concept isMove = isInputOutput<T>;
static_assert(isMove<ExampleMove>);

//Move is the input of a players call to move (input object)
template<typename T>
concept isGameView = isInputOutput<T>;
static_assert(isGameView<ExampleGameView>);

template<typename T>
concept isPlayer = requires (T t, ExampleGameView gameView) {
  //A player is an object that provides a move depending on a gameView
  { t.getMove(gameView) } -> isMove;
};

}

