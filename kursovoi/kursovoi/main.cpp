#include <cstdio>
#include <SFML/Graphics.hpp>
#include <ctime>

using namespace sf;
using namespace std;



int main()
{
	RenderWindow window(VideoMode(700, 500), "kosinka");
	int a = 666;
	int b = 10;
	int j = 23;


	Texture cardt[53];
	Sprite card[53];

	for (int i = 0; i < 52; i++)
	{
		char *path_str = new char[32];
		sprintf_s(path_str, 32, "images/%d.bmp", i);
		string path(path_str);
		cardt[i].loadFromFile(path);
		card[i].setTexture(cardt[i]);
		delete path_str;
	}

	Texture shirtt;
	Texture emptyt;
	Sprite shirt;
	Sprite empty;
	Texture font;
	Sprite fon;

	font.loadFromFile("images/fon.bmp");
	fon.setTexture(font);
	shirtt.loadFromFile("images/52.bmp");
	shirt.setTexture(shirtt);
	emptyt.loadFromFile("images/53.bmp");
	empty.setTexture(emptyt);

	Texture kartat;
	Sprite karta;

	kartat.loadFromFile("images/karta.png");
	karta.setTexture(kartat);


	pair<String, String> pbrooda("a", "brood");
	pair<String, String> pbrood2("2", "brood");
	pair<String, String> pbrood3("3", "brood");
	pair<String, String> pbrood4("4", "brood");
	pair<String, String> pbrood5("5", "brood");
	pair<String, String> pbrood6("6", "brood");
	pair<String, String> pbrood7("7", "brood");
	pair<String, String> pbrood8("8", "brood");
	pair<String, String> pbrood9("9", "brood");
	pair<String, String> pbrood10("10", "brood");
	pair<String, String> pbroodv("v", "brood");
	pair<String, String> pbroodd("d", "brood");
	pair<String, String> pbroodk("k", "brood");

	pair<String, String> pbubaa("a", "buba");
	pair<String, String> pbuba2("2", "buba");
	pair<String, String> pbuba3("3", "buba");
	pair<String, String> pbuba4("4", "buba");
	pair<String, String> pbuba5("5", "buba");
	pair<String, String> pbuba6("6", "buba");
	pair<String, String> pbuba7("7", "buba");
	pair<String, String> pbuba8("8", "buba");
	pair<String, String> pbuba9("9", "buba");
	pair<String, String> pbuba10("10", "buba");
	pair<String, String> pbubav("v", "buba");
	pair<String, String> pbubad("d", "buba");
	pair<String, String> pbubak("k", "buba");

	pair<String, String> pcrossa("a", "cross");
	pair<String, String> pcross2("2", "cross");
	pair<String, String> pcross3("3", "cross");
	pair<String, String> pcross4("4", "cross");
	pair<String, String> pcross5("5", "cross");
	pair<String, String> pcross6("6", "cross");
	pair<String, String> pcross7("7", "cross");
	pair<String, String> pcross8("8", "cross");
	pair<String, String> pcross9("9", "cross");
	pair<String, String> pcross10("10", "cross");
	pair<String, String> pcrossv("v", "cross");
	pair<String, String> pcrossd("d", "cross");
	pair<String, String> pcrossk("k", "cross");

	pair<String, String> ppeaka("a", "peak");
	pair<String, String> ppeak2("2", "peak");
	pair<String, String> ppeak3("3", "peak");
	pair<String, String> ppeak4("4", "peak");
	pair<String, String> ppeak5("5", "peak");
	pair<String, String> ppeak6("6", "peak");
	pair<String, String> ppeak7("7", "peak");
	pair<String, String> ppeak8("8", "peak");
	pair<String, String> ppeak9("9", "peak");
	pair<String, String> ppeak10("10", "peak");
	pair<String, String> ppeakv("v", "peak");
	pair<String, String> ppeakd("d", "peak");
	pair<String, String> ppeakk("k", "peak");

	pair<String, String> pkarta("karta", "karta");

	pair<Sprite, pair<String, String>> brooda(card[26], pbrooda);
	pair<Sprite, pair<String, String>> brood2(card[27], pbrood2);
	pair<Sprite, pair<String, String>> brood3(card[28], pbrood3);
	pair<Sprite, pair<String, String>> brood4(card[29], pbrood4);
	pair<Sprite, pair<String, String>> brood5(card[30], pbrood5);
	pair<Sprite, pair<String, String>> brood6(card[31], pbrood6);
	pair<Sprite, pair<String, String>> brood7(card[32], pbrood7);
	pair<Sprite, pair<String, String>> brood8(card[33], pbrood8);
	pair<Sprite, pair<String, String>> brood9(card[34], pbrood9);
	pair<Sprite, pair<String, String>> brood10(card[35], pbrood10);
	pair<Sprite, pair<String, String>> broodv(card[36], pbroodv);
	pair<Sprite, pair<String, String>> broodd(card[37], pbroodd);
	pair<Sprite, pair<String, String>> broodk(card[38], pbroodk);

	pair<Sprite, pair<String, String>> bubaa(card[13], pbubaa);
	pair<Sprite, pair<String, String>> buba2(card[14], pbuba2);
	pair<Sprite, pair<String, String>> buba3(card[15], pbuba3);
	pair<Sprite, pair<String, String>> buba4(card[16], pbuba4);
	pair<Sprite, pair<String, String>> buba5(card[17], pbuba5);
	pair<Sprite, pair<String, String>> buba6(card[18], pbuba6);
	pair<Sprite, pair<String, String>> buba7(card[19], pbuba7);
	pair<Sprite, pair<String, String>> buba8(card[20], pbuba8);
	pair<Sprite, pair<String, String>> buba9(card[21], pbuba9);
	pair<Sprite, pair<String, String>> buba10(card[22], pbuba10);
	pair<Sprite, pair<String, String>> bubav(card[23], pbubav);
	pair<Sprite, pair<String, String>> bubad(card[24], pbubad);
	pair<Sprite, pair<String, String>> bubak(card[25], pbubak);

	pair<Sprite, pair<String, String>> crossa(card[0], pcrossa);
	pair<Sprite, pair<String, String>> cross2(card[1], pcross2);
	pair<Sprite, pair<String, String>> cross3(card[2], pcross3);
	pair<Sprite, pair<String, String>> cross4(card[3], pcross4);
	pair<Sprite, pair<String, String>> cross5(card[4], pcross5);
	pair<Sprite, pair<String, String>> cross6(card[5], pcross6);
	pair<Sprite, pair<String, String>> cross7(card[6], pcross7);
	pair<Sprite, pair<String, String>> cross8(card[7], pcross8);
	pair<Sprite, pair<String, String>> cross9(card[8], pcross9);
	pair<Sprite, pair<String, String>> cross10(card[9], pcross10);
	pair<Sprite, pair<String, String>> crossv(card[10], pcrossv);
	pair<Sprite, pair<String, String>> crossd(card[11], pcrossd);
	pair<Sprite, pair<String, String>> crossk(card[12], pcrossk);

	pair<Sprite, pair<String, String>> peaka(card[39], ppeaka);
	pair<Sprite, pair<String, String>> peak2(card[41], ppeak2);
	pair<Sprite, pair<String, String>> peak3(card[42], ppeak3);
	pair<Sprite, pair<String, String>> peak4(card[43], ppeak4);
	pair<Sprite, pair<String, String>> peak5(card[44], ppeak5);
	pair<Sprite, pair<String, String>> peak6(card[45], ppeak6);
	pair<Sprite, pair<String, String>> peak7(card[46], ppeak7);
	pair<Sprite, pair<String, String>> peak8(card[47], ppeak8);
	pair<Sprite, pair<String, String>> peak9(card[48], ppeak9);
	pair<Sprite, pair<String, String>> peak10(card[49], ppeak10);
	pair<Sprite, pair<String, String>> peakv(card[50], ppeakv);
	pair<Sprite, pair<String, String>> peakd(card[51], ppeakd);
	pair<Sprite, pair<String, String>> peakk(card[52], ppeakk);

	pair<Sprite, pair<String, String>> qkarta(karta, pkarta);

	//pair<Sprite, pair<String, String>> st[13][7]
	//{card[24], }
	//{}
	//{}
	//{}
	//{}
	//{}
	//{}

	Texture st1t[13], st2t[13], st3t[13], st4t[13], st5t[13], st6t[13], st7t[13];
	Sprite st1[13], st2[13], st3[13], st4[13], st5[13], st6[13], st7[13];

	int numbersClick = 1;
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0;

	srand(time(NULL));
	random_shuffle(card, card + 52);

	while (window.isOpen())
	{
		Vector2i pixelPos = Mouse::getPosition(window);

		window.clear();
		window.draw(fon);

		shirt.setPosition(10, 10);
		window.draw(shirt);

		if (j == 0)
		{
			empty.setPosition(10, 10);
			window.draw(empty);
			j = 23;
		}

		Event event;
		while (window.pollEvent(event))
		{
			Vector2i mousePos = Mouse::getPosition(window);

			shirt.setPosition(10, 10);
			window.draw(shirt);

			if (event.type == Event::MouseButtonReleased)
			{
				x1 = mousePos.x;
				y1 = mousePos.y;
				if ((x1 > 10) && (x1 < 82) && (y1 > 10) && (y1 < 110))
				{
					a = j;
					j--;
				}
			}

			if (j == 0)
			{
				empty.setPosition(10, 10);
				window.draw(empty);
				j = 23;
			}
			if (a != 666)
			{
				card[a].setPosition(110, 10);
				window.draw(card[a]);
			}

			empty.setPosition(300, 10);
			window.draw(empty);
			empty.setPosition(400, 10);
			window.draw(empty);
			empty.setPosition(500, 10);
			window.draw(empty);
			empty.setPosition(600, 10);
			window.draw(empty);
			
			for (int i = 0; i < 13; i++)
			{	
				if (i == 0)
				{
					st1[i] = card[24];
				}
				else
					st1[i] = karta;
				st1[i].setPosition(10, 150 + i * 20);
				window.draw(st1[i]);
			}

			for (int i = 0; i < 13; i++)
			{
				if (i == 1)
				{
					st2[i] = card[25];
				}
				else if (i < 1)
				{
					st2[i] = shirt;
				}
				else
					st2[i] = karta;
				st2[i].setPosition(110, 150 + i * 20);
				window.draw(st2[i]);
			}

			for (int i = 0; i < 13; i++)
			{
				if (i == 2)
				{
					st3[i] = card[27];
				}
				else if (i < 2)
				{
					st3[i] = shirt;
				}
				else
					st3[i] = karta;
				st3[i].setPosition(210, 150 + i * 20);
				window.draw(st3[i]);
			}

			for (int i = 0; i < 13; i++)
			{
				if (i == 3)
				{
					st4[i] = card[30];
				}
				else if (i < 3)
				{
					st4[i] = shirt;
				}
				else 
					st4[i] = karta;
				st4[i].setPosition(310, 150 + i * 20);
				window.draw(st4[i]);
			}

			for (int i = 0; i < 13; i++)
			{
				if (i == 4)
				{
					st5[i] = card[34];
				}
				else if (i < 4)
				{
					st5[i] = shirt;
				}
				else 
					st5[i] = karta;
				st5[i].setPosition(410, 150 + i * 20);
				window.draw(st5[i]);
			}

			for (int i = 0; i < 13; i++)
			{
				if (i == 5)
				{
					st6[i] = card[40];
				}
				else if (i < 5)
				{
					st6[i] = shirt;
				}
				else
					st6[i] = karta;
				st6[i].setPosition(510, 150 + i * 20);
				window.draw(st6[i]);
			}

			for (int i = 0; i < 13; i++)
			{
				if (i == 6)
				{
					st7[i] = card[46];
				}
				else if (i < 6)
				{
					st7[i] = shirt;
				}
				else
					st7[i] = karta;
				st7[i].setPosition(610, 150 + i * 20);
				window.draw(st7[i]);
			}
			
			if (event.type == Event::MouseButtonReleased)
			{
				if (numbersClick % 2 == 1)
				{
					x1 = mousePos.x;
					y1 = mousePos.y;

				}
				else
				{
					x2 = mousePos.x;
					y2 = mousePos.y;
				}

				if ((x1 > 10) && (x1 < 82) && (y1 > 150) && (y1 < 250))
				{
					if (numbersClick % 2 == 1)
					{
						x1 = mousePos.x;
						y1 = mousePos.y;
					}
					else
					{
						x2 = mousePos.x;
						y2 = mousePos.y;
					}
			
						if ((x2 > 110) && (x2 < 182) && (y2 > 350) && (y2 < 450))
						{
							st2[2] = card[24];
							st2[2].setPosition(110, 190);
							st1[0] = empty;
							st1[0].setPosition(10, 150);
							window.draw(st1[0]);
							window.draw(st2[2]);
						}
						
				}
				printf("%d\n", numbersClick);
				numbersClick++;
			}
			
			window.display();
			
		}
		
	}

	return 0;
}