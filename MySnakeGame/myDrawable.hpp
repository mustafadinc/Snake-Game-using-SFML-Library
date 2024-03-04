#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class WindowClass; //SADECE compiler� susturmak i�in yapt�m daha sonra include edicem zaten
class myDrawable{

public:
	virtual void draw(WindowClass& window) = 0;
	Vector2f getLocation();
	void setLocation(const Vector2f& konum);
protected:
	Vector2f m_location;
	
};