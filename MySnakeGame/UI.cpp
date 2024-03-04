#include "UI.hpp"
#include "WindowClass.hpp"
#include "imgui.h"
#include "imgui-SFML.h"
#include <iostream>
UI::UI()
{
	isStartGame = false;
	isQuit = false;
}

void UI::draw(WindowClass& window)
{
	window.myDraw(m_Text);
}

Text UI::setText(Text text,
				 string name,
				 Color color,
				 Text::Style style,
				 int chr_Size,
				 int m_width,
				 int m_height)
{

	font.loadFromFile("Ghost Of The Wild West.ttf");
	text.setFont(font);
	text.setString(name);
	text.setFillColor(color);
	text.setStyle(style);
	text.setCharacterSize(chr_Size);
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	text.setPosition(m_width, m_height);
	return text;
}

void UI::drawHighScoreText(WindowClass& window)
{
	window.myDraw(m_ScoreText);
}

void UI::setWindow(int m_height, int m_width)
{
		my_width = m_width;
		my_height = m_height;
}

void UI::startButton()
{
	if (!isStartGame)
	{
		//ImGui::SetWindowSize(ImVec2(my_width, my_height));
		ImGui::Begin("Game Panel", NULL, ImGuiWindowFlags_NoMove);
		ImVec4 textColor = ImVec4(0.0f, 1.0f, 0.0f, 1.0f);
		ImGui::PushStyleColor(ImGuiCol_Button, textColor);
		ImGui::SetWindowFontScale(2.0f);
		if (ImGui::Button("START", ImVec2(200, 30)))
			isStartGame = true;

		ImGui::PopStyleColor();
		ImGui::End();	
	}
}

void UI::isQuitButton()
{
	if (!isQuit)
	{
		ImGui::Begin("Game Panel", NULL, ImGuiWindowFlags_NoMove);
		ImVec4 textColor = ImVec4(0.0f, 1.0f, 0.0f, 1.0f);
		ImGui::PushStyleColor(ImGuiCol_Button, textColor);
		ImGui::SetWindowFontScale(2.0f);
		if (ImGui::Button("QUIT", ImVec2(200, 30)))
			isQuit = true;

		ImGui::PopStyleColor();
		ImGui::End();

	}
}


