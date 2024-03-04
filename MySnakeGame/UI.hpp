#pragma once
#include "myDrawable.hpp"

class UI: public myDrawable{

public:
	UI();
	void draw(WindowClass& window) override;
	Text setText(Text text,
		string name,
		Color color,
		Text::Style style,
		int chr_Size,
		int m_width,
		int m_height);
	Text m_Text;
	Text m_ScoreText;
	int highScore;
	void drawHighScoreText(WindowClass& window);
	void setWindow(int m_height, int m_width );
	void startButton();
	void isQuitButton();
	bool isStartGame;
	bool isQuit;
private:
	Text text;
	sf::Font font;
	int my_width;
	int my_height;

};