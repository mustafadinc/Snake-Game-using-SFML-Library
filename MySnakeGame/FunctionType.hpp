#pragma once
#include <functional>
#include <SFML/Window/Event.hpp>
#include <vector>
using namespace std;

typedef function <void(sf::Keyboard::Key )> KeyboardFunctions;
typedef vector<KeyboardFunctions> KeyboardFunctionList;

typedef function <void(sf::Event::MouseMoveEvent)> MauseFunctions;
typedef vector<MauseFunctions> MauseFunctionsList;

typedef function <void(sf::Event::MouseButtonEvent)> MauseButtonFunctions;
typedef vector<MauseButtonFunctions> MauseButtonFunctionsList;
