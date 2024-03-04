
#include "WindowClass.hpp"
#include <iostream>
#include "imgui.h"
#include "imgui-SFML.h"
void WindowClass::createWindow(unsigned int genislik, unsigned int yukseklik, const sf::String& baslik)
{
	m_pencere.create(VideoMode(genislik, yukseklik), baslik);
	ImGui::SFML::Init(m_pencere);
}

void WindowClass::myDraw(sf::Drawable& sekil)
{
	m_pencere.draw(sekil);
}

void WindowClass::processEvent()
{
	Event olay;
	
	while (m_pencere.pollEvent(olay))
	{
		ImGui::SFML::ProcessEvent(olay);
		if (olay.type == Event::Closed)
		{
			closePencere();
		}
		if (olay.type == Event::KeyPressed)
		{	

			for (auto siradaki : m_tusaBasFonks)
			{
				siradaki(olay.key.code);
			}

		}
		if (olay.type == Event::KeyReleased)
		{
			for (auto siradaki : m_tusuBirakFonks)
			{
				siradaki(olay.key.code);
			}
		}
		if (olay.type == Event::MouseMoved)
		{
			for (auto siradaki : m_mauseMoveFunctions)
			{
				siradaki(olay.mouseMove);
			}
		}
	}
}

bool WindowClass::isWindowOpen()
{
	return m_pencere.isOpen();
}

void WindowClass::cleared()
{
	m_pencere.clear();
}

void WindowClass::show()
{
	ImGui::SFML::Render(m_pencere);
	m_pencere.display();
}

void WindowClass::closeWdw()
{
	ImGui::SFML::Shutdown();

}

void WindowClass::closePencere()
{
	m_pencere.close();
}

void WindowClass::updateImGui(const sf::Time& dt)
{
	ImGui::SFML::Update(m_pencere,dt);
}

void WindowClass::tusaBasFonkEkle(KeyboardFunctions yeniFonk)
{
	m_tusaBasFonks.push_back(yeniFonk);
}

void WindowClass::m_tusuBirakFonkEkle(KeyboardFunctions yeniFonk)
{
	m_tusuBirakFonks.push_back(yeniFonk);
}

void WindowClass::m_addMauseMoveFunc(MauseFunctions yeniFonk)
{
	m_mauseMoveFunctions.push_back(yeniFonk);
}

void WindowClass::m_addMauseButtonFunc(MauseButtonFunctions yeniFonk)
{
	m_mauseButtonFunctions.push_back(yeniFonk);
}

void WindowClass::m_titleWindow(int fps)
{
	m_pencere.setTitle("Snake Game    fps : " + to_string(fps));  // saniyede ne kadar kare var
}


