#pragma once
#include "myDrawable.hpp"

enum class myDIRECTION {
	Sol,
	Sag,
	Yukari,
	Asagi
};


class SnakePiece:public myDrawable {
public:
	SnakePiece();
	SnakePiece addSnake();
	void draw(WindowClass& window) override;
	void setDirection(myDIRECTION dir);
	void setVelocity(float velocity);
	float getVelocity();
	void setSize(int m_size);
	int getSize();
	void hareket();
	myDIRECTION getDirection();
	void boundControl();
	void setColor();
	Color getColor();
	void setColorNew(Color color);

	Color color;
private:
	myDIRECTION m_yon;
	float hiz;
	int boyut;
	sf::RectangleShape m_sekil;

};
