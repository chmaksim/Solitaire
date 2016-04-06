#include <SFML/Graphics.hpp>

using namespace sf;
int main()
{
	bool isMove = false;//переменная для щелчка мыши по спрайту

		float dX = 0;//корректировка нажатия по х
	float dY = 0;//по у

	RenderWindow window(VideoMode(640, 480), "kosinka");
	
	Texture cardtexture;
	cardtexture.loadFromFile("images/0.bmp");

	Sprite cardsprite;
	cardsprite.setTexture(cardtexture);
	cardsprite.setPosition(50, 25);

	Texture cardtexture1;
	cardtexture1.loadFromFile("images/1.bmp");

	Sprite cardsprite1;
	cardsprite1.setTexture(cardtexture1);
	cardsprite1.setPosition(200, 25);

	Texture cardtexture2;
	cardtexture2.loadFromFile("images/2.bmp");

	Sprite cardsprite2;
	cardsprite2.setTexture(cardtexture2);
	cardsprite2.setPosition(300, 25);

	Texture cardtexture3;
	cardtexture3.loadFromFile("images/3.bmp");

	Sprite cardsprite3;
	cardsprite3.setTexture(cardtexture3);
	cardsprite3.setPosition(400, 25);

	Texture cardtexture4;
	cardtexture4.loadFromFile("images/4.bmp");

	Sprite cardsprite4;
	cardsprite4.setTexture(cardtexture4);
	cardsprite4.setPosition(500, 25);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			

			
			
			
			

			Event event;
			if (event.type == Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				cardsprite2.setColor(Color::Red);
			}
		}

		window.clear();
		window.draw(cardsprite);
		window.draw(cardsprite1);
		window.draw(cardsprite2);
		window.draw(cardsprite3);
		window.draw(cardsprite4);
		window.display();
	}

	return 0;
}