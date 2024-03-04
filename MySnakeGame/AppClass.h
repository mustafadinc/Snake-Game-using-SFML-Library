#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "WindowClass.hpp"
#include "Snake.hpp"
#include "SnakePiece.hpp"
#include "UI.hpp"
using namespace sf;
using namespace std;

class AppClass {

public:
	AppClass();    // Constructor
	void createWdv(int heigth,int width);
	void start(int fps = 60);

private:

	void CreateFrame();
	void drawFunc();
	void updateScene();
	void keyPress(sf::Keyboard::Key tus);
	void keyRelease(sf::Keyboard::Key tus);
	void mauseMove(sf::Event::MouseMoveEvent olay);
	void mauseClick(sf::Event::MouseButtonEvent olay);
	bool birKere = true;
	
	UI					my_UI;
	Snake				snake;
	WindowClass			my_window;
	Clock				time;
	Time				myFrameTime;
	Time				myElapsedTime;
	RectangleShape		m_snake;
	
	
};

