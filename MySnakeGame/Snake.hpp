#pragma once

#include "SnakePiece.hpp"
#include "UI.hpp"
#include "WindowClass.hpp"
using namespace std;
class Snake:public myDrawable{

public:
	Snake();
	void draw(WindowClass& window) override;
	void addQueue();
	void move();
	void setDir(myDIRECTION newDir);
	bool boundControl();
	bool isSelfCollision();
	void foodControl();
	void set(float sizeFood,int width,int height);
	Color colorNew = Color::Green;
	bool isRestarting;
	bool isQuiting;
private:
	void createFood();
	vector<SnakePiece> m_pieces;
	float m_alinanMesafe;
	myDIRECTION yon;
	float m_sizeFood;
	int m_width;
	int m_height;
	SnakePiece m_food;
	Text text;
	Text scText;
	Text highScoreText;
	UI mus;
	int score;
	int highScore;
};