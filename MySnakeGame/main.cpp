#include <iostream>
#include <string>
#include "AppClass.h"


using namespace std;
using namespace sf;


int main()
{	
	AppClass uygulama;
	uygulama.createWdv(800, 600);
	uygulama.start(60);
	
}
