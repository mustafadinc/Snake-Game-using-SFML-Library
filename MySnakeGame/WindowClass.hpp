#pragma once
#include <SFML/Graphics.hpp>
#include "FunctionType.hpp"
using namespace sf;
using namespace std;
class WindowClass
{
public:
	void createWindow(unsigned int genislik,
		unsigned int yukseklik,
		const sf::String& baslik = "SFML");

	void myDraw(sf::Drawable& sekil);
	void processEvent();
	bool isWindowOpen();
	void cleared();
	void show();
	void closeWdw();
	void closePencere();
	void updateImGui(const sf::Time& dt);
	void tusaBasFonkEkle(KeyboardFunctions yeniFonk);
	void m_tusuBirakFonkEkle(KeyboardFunctions yeniFonk);
	void m_addMauseMoveFunc(MauseFunctions yeniFonk);
	void m_addMauseButtonFunc(MauseButtonFunctions yeniFonk);
	void m_titleWindow(int fps);
	
private:
	RenderWindow m_pencere;
	KeyboardFunctionList m_tusaBasFonks;
	KeyboardFunctionList m_tusuBirakFonks;
	MauseFunctionsList m_mauseMoveFunctions;
	MauseButtonFunctionsList m_mauseButtonFunctions;
};