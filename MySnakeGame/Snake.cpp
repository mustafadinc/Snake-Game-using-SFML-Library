#include "Snake.hpp"

#include <random>
#include <iostream>
Snake::Snake()
{
	yon = myDIRECTION::Sag;
	m_alinanMesafe = 0;	
	score = 0;
	highScore = 0;
	isRestarting = false;
	isQuiting = false;
}

void Snake::draw(WindowClass& window)
{
	mus.draw(window);
	m_food.draw(window);
	for (auto& siradaki : m_pieces)
	{
		siradaki.draw(window);
	}
	if (!(boundControl()))
	{	
		mus.draw(window);
		mus.drawHighScoreText(window);		
	}
	if (isSelfCollision())
	{
		mus.drawHighScoreText(window);
		mus.draw(window);
	}
}

void Snake::addQueue()
{

	//pushback 
	SnakePiece newSnake;	
	if (m_pieces.size())
	{		
		newSnake  = m_pieces.back().addSnake();
		newSnake.setColorNew(colorNew);
		m_pieces.push_back(newSnake);
	}
	else
	{
		m_pieces.push_back(SnakePiece());
	}
	newSnake.setSize(m_sizeFood);
}

void Snake::move()
{
	if (!(boundControl()))
	{
		mus.isQuitButton();
		
		mus.m_Text = mus.setText(text,
								"GAME OVER!",
								sf::Color::Red,
								sf::Text::Style::Bold,
								100,
								m_width/2,
								m_height/2);
		highScore = score;
		mus.m_ScoreText = mus.setText(highScoreText, 
									"Score  " + to_string(highScore),
									sf::Color::Green, 
									sf::Text::Style::Italic,
									100,

									m_width/2,
									m_height / 4);

		isQuiting = mus.isQuit;
		return;
	}
	if (isSelfCollision())
	{
		mus.isQuitButton();
		mus.m_Text = mus.setText(text,
								"GAME OVER!",
								sf::Color::Red,
								sf::Text::Style::Bold,
								100,
								m_width / 2,
								m_height / 2);
		highScore = score;
		mus.m_ScoreText = mus.setText(highScoreText,
									"Score " + to_string(highScore),
									sf::Color::Green,
									sf::Text::Style::Italic,
									100,
									m_width / 2,
									m_height / 4);	
		isQuiting = mus.isQuit;
		return;
	}
	m_alinanMesafe += m_pieces[0].getVelocity();
	for (auto& siradaki : m_pieces)
	{
		siradaki.hareket();
	}
	if (m_alinanMesafe == m_pieces[0].getSize())
	{
		foodControl();
		for (int i = m_pieces.size() - 1; i > 0; i--)
		{
			m_pieces[i].setDirection(m_pieces[i - 1].getDirection());
		}
		m_alinanMesafe = 0;
		m_pieces[0].setDirection(yon);
	}	
}

void Snake::setDir(myDIRECTION newDir)
{
	if (newDir == myDIRECTION::Sol && yon == myDIRECTION::Sag)
		return;
	if (newDir == myDIRECTION::Sag && yon == myDIRECTION::Sol)
		return;
	if (newDir == myDIRECTION::Yukari && yon == myDIRECTION::Asagi)
		return;
	if (newDir == myDIRECTION::Asagi && yon == myDIRECTION::Yukari)
		return;
	yon = newDir;
}

bool Snake::boundControl()
{
	if (m_pieces[0].getLocation().x < 0 ||
		m_pieces[0].getLocation().x + m_sizeFood > m_width ||
		m_pieces[0].getLocation().y < 0 ||
		m_pieces[0].getLocation().y + m_sizeFood > m_height)
		return false;
	return true;
}

bool Snake::isSelfCollision()
{
	int numberOfcell = m_pieces.size();

	for (int i = 2; i < numberOfcell; i++)
	{
		if (m_pieces[0].getLocation() == m_pieces[i].getLocation())
			return true;
	}
	return false;
}

void Snake::foodControl()
{
	if (m_pieces[0].getLocation() == m_food.getLocation())
	{
		colorNew = m_food.getColor();
		createFood();		
		addQueue();
		score += 1;
		mus.m_Text = mus.setText(scText,
						 to_string(score), 
						 sf::Color::Red, 
						 sf::Text::Style::Bold,
						 100,
						 7*m_width/8,
						 1*m_height/8);
	
		bool isCollision = true;
		do
		{
			isCollision = false;
			for (auto& i : m_pieces)
			{
				if (i.getLocation() == m_food.getLocation())
				{
					foodControl();
					isCollision = true;
					break;
				}
			}
		} while (isCollision);		
	}
}

void Snake::createFood()
{	
	int numberCol = m_width / m_sizeFood;
	int numberRow = m_height / m_sizeFood;
	float x = (rand()% numberCol) * m_sizeFood;
	float y = (rand() % numberRow) * m_sizeFood;
	m_food.setLocation(sf::Vector2f(x, y));
	m_food.setSize(m_sizeFood);
	m_food.setColor();
}

void Snake::set(float sizeFood, int width, int height)
{
	m_width = width;
	m_height = height;
	m_sizeFood = sizeFood;
	createFood();
	addQueue();
	addQueue();	
	addQueue();
	addQueue();
}


