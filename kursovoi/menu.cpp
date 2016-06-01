#include <SFML/Graphics.hpp>
#include <cstdio>


using namespace sf;
using namespace std;


void menu(RenderWindow & window)
{
	Texture tplay, texit;
	tplay.loadFromFile("images/play.png");
	texit.loadFromFile("images/exit.png");
	Sprite play, sexit;
	play.setTexture(tplay);
	sexit.setTexture(texit);
	bool isMenu = true;
	int menuNum = 0;
	play.setPosition(300, 300);
	sexit.setPosition(300, 400);

	//////////MENU///////////////
	while (isMenu)
	{
		Vector2i pos = Mouse::getPosition(window);

		play.setColor(Color::White);
		sexit.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(128, 200, 128));

		if (pos.x>300 && pos.x<470 && pos.y>300 && pos.y<340) { play.setColor(Color::Blue); menuNum = 1; }
		if (pos.x>300 && pos.x<470 && pos.y>400 && pos.y<440) { sexit.setColor(Color::Blue); menuNum = 2; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { window.close(); exit(1); }

		}

		window.draw(play);
		window.draw(sexit);

		window.display();
	}
	////////////////////////////////////////////////////
}