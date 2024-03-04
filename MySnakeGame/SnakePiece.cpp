#include "SnakePiece.hpp"
#include "WindowClass.hpp"
#include <iostream>
SnakePiece::SnakePiece()
{
	m_sekil.setFillColor(Color::Green);
	m_sekil.setOutlineColor(Color::Black);
	m_sekil.setOutlineThickness(1.0f);
	setSize(20);
	setVelocity(5);
	setDirection(myDIRECTION::Sag);
	m_location.x = 100;
	m_location.y = 100;
}

SnakePiece SnakePiece::addSnake()
{
	Vector2f newLocation = m_location;
	switch (m_yon)
	{
	case myDIRECTION::Sag:
		newLocation.x -= boyut;
		break;
	case myDIRECTION::Sol:
		newLocation.x += boyut;
		break;
	case myDIRECTION::Yukari:
		newLocation.y += boyut;
		break;
	case myDIRECTION::Asagi:
		newLocation.y -= boyut;
		break;
	}
	SnakePiece newPiece;
	newPiece.setLocation(newLocation);
	newPiece.setDirection(m_yon);
	return newPiece;
}


void SnakePiece::draw(WindowClass& window)
{
	m_sekil.setPosition(m_location);
	window.myDraw(m_sekil);	
}

void SnakePiece::setDirection(myDIRECTION dir)
{
	m_yon = dir;
}

void SnakePiece::setVelocity(float velocity)
{
	hiz = velocity;
}

float SnakePiece::getVelocity()
{
	return hiz;
}

void SnakePiece::setSize(int m_size)
{
	boyut = m_size;
	m_sekil.setSize(Vector2f(boyut, boyut));
}

int SnakePiece::getSize()
{
	return boyut;	
}

void SnakePiece::hareket()
{
	switch (m_yon)
	{
	case myDIRECTION::Sag:
		m_location.x += hiz;
		break;
	case myDIRECTION::Sol:
		m_location.x -= hiz;
		break;
	case myDIRECTION::Yukari:
		m_location.y -= hiz;
		break;
	case myDIRECTION::Asagi:
		m_location.y += hiz;
		break;
	}
}

myDIRECTION SnakePiece::getDirection()
{
	return m_yon;
}

void SnakePiece::boundControl()
{
	if (m_sekil.getPosition().x < 0.0f)
	{
		m_sekil.setPosition(0.f, m_sekil.getPosition().y);
		m_location.x = 0.f;
	}

	if (m_sekil.getPosition().y < 0.0f)
	{
		m_sekil.setPosition(m_sekil.getPosition().x, 0.f);
		m_location.y = 0.f;
	}

	if (m_sekil.getPosition().x + m_sekil.getGlobalBounds().width >= 600.f)
	{
		m_sekil.setPosition(600.f - m_sekil.getGlobalBounds().width, m_sekil.getPosition().y);
		m_location.x = 600.f - m_sekil.getGlobalBounds().width;
	}

	if (m_sekil.getPosition().y + m_sekil.getGlobalBounds().height >= 600.f)
	{
		m_sekil.setPosition(m_sekil.getPosition().x, 600.f - m_sekil.getGlobalBounds().height);
		m_location.y = 600.f - m_sekil.getGlobalBounds().height;
	}
}

void SnakePiece::setColor()
{	
	unsigned int seed = static_cast<unsigned int>(time(0));
	srand(seed);
	int min = 1;
	int max = 7;
	int randomNumber = rand()%max + min;

	switch (randomNumber) {
	case 1:
		color = sf::Color::Red;
		break;
	case 2:
		color = sf::Color::Green;
		break;
	case 3:
		color = sf::Color::Blue;
		break;
	case 4:
		color = sf::Color::Yellow;
		break;
	case 5:
		color = sf::Color::Magenta;
		break;
	case 6:
		color = sf::Color::Cyan;
		break;
	case 7:
		color = sf::Color::White;
		break;
	}
	
	m_sekil.setFillColor(color);
}

Color SnakePiece::getColor()
{
	return color;
}

void SnakePiece::setColorNew(Color color)
{
	m_sekil.setFillColor(color);
}





