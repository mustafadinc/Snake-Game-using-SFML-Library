#include "AppClass.h"
#include "SnakePiece.hpp"
#include <iostream>
#include "imgui.h"
#include "imgui-SFML.h"

AppClass::AppClass()
{

}

void AppClass::createWdv(int heigth, int width)
{
	my_window.createWindow(heigth,width);
	snake.set(20, heigth, width);
	
	my_UI.setWindow(heigth, width);
	my_window.m_addMauseMoveFunc(
		std::bind(&AppClass::mauseMove, this, std::placeholders::_1)
	);
	my_window.m_addMauseButtonFunc(
		std::bind(&AppClass::mauseClick, this, std::placeholders::_1)
	);
	my_window.tusaBasFonkEkle(
		std::bind(&AppClass::keyPress, this, std::placeholders::_1)
	);
	my_window.m_tusuBirakFonkEkle(
		std::bind(&AppClass::keyRelease, this, std::placeholders::_1)
	);
}

void AppClass::start(int fps)
{
	float frmTime = 1.0f / fps;
	myFrameTime = sf::seconds(frmTime);
	while (my_window.isWindowOpen())
	{
		my_window.processEvent();
		myElapsedTime = time.getElapsedTime();
		if (myElapsedTime >= myFrameTime)
		{
			CreateFrame();
			
			myElapsedTime = sf::seconds(0.0f);
			my_window.m_titleWindow(fps);
			time.restart();
		}
		else
		{
			sf::sleep(myElapsedTime -myFrameTime);
		}
	}

	my_window.closeWdw();

}

void AppClass::CreateFrame()
{
	
	updateScene();
	drawFunc();
	  
}

void AppClass::drawFunc()
{
	my_window.cleared();
	my_UI.startButton();
	
	if (my_UI.isStartGame == true)
	{
		snake.draw(my_window);
	
	}

	if (snake.isQuiting == true)
	{
		my_window.closePencere();
		
	}

	my_window.show();	
}

void AppClass::updateScene()
{
	my_window.updateImGui(myFrameTime);
	if (my_UI.isStartGame == true)
	{
		snake.move();	
	}
}

void AppClass::keyPress(sf::Keyboard::Key tus)
{
	if (tus == Keyboard::Left)
		snake.setDir(myDIRECTION::Sol);

	if (tus == Keyboard::Right)
		snake.setDir(myDIRECTION::Sag);

	if (tus == Keyboard::Up)
		snake.setDir(myDIRECTION::Yukari);

	if (tus == Keyboard::Down)
		snake.setDir(myDIRECTION::Asagi);
}

void AppClass::keyRelease(sf::Keyboard::Key tus)
{


}

void AppClass::mauseMove(sf::Event::MouseMoveEvent olay)
{

}

void AppClass::mauseClick(sf::Event::MouseButtonEvent olay)
{
	
}

