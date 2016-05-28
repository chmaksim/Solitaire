#include <cstdio>
#include <SFML/Graphics.hpp>
#include <ctime>

#include <iostream>
#include <sstream>

using namespace sf;
using namespace std;


//процедура проверки хода
bool provk(int a, int b, int c, int d)
{
	if ((a + b) % 2 == 1)
		if (c - d == 1)
		{
			return true;
		}
	return false;
}

//разложение в основную клоду
bool provka(int a, int b, int c, int d)
{
	if (a == b)
		if (d - c == 1)
		{
			return true;
		}
	return false;
}

//c1
int pust(int a)
{
	if (a == 0)
		return a;
}



int main()
{
	RenderWindow window(VideoMode(700, 700), "kosinka");
	int a = 24;
	int b1, c2, d1, b2, c1, d2, c3, dd;
	int bb;
	int sek = 0, seko = 0;
	int p = 23;

	Texture cardt[53];
	Sprite scard[53];

	for (int i = 0; i < 52; i++)
	{
		char *path_str = new char[32];
		sprintf_s(path_str, 32, "images/%d.bmp", i);
		string path(path_str);
		cardt[i].loadFromFile(path);
		scard[i].setTexture(cardt[i]);
		delete path_str;
	}

	Texture emptyt;
	Sprite empty;

	emptyt.loadFromFile("images/53.bmp");
	empty.setTexture(emptyt);

	Texture shirtt;
	Sprite sshirt;

	shirtt.loadFromFile("images/52.bmp");
	sshirt.setTexture(shirtt);

	Texture font;
	Sprite fon;

	font.loadFromFile("images/fon.bmp");
	fon.setTexture(font);

	Texture kartat;
	Sprite skarta;

	kartat.loadFromFile("images/karta.png");
	skarta.setTexture(kartat);

	pair<int, int> pbrooda(1, 1);
	pair<int, int> pbrood2(2, 1);
	pair<int, int> pbrood3(3, 1);
	pair<int, int> pbrood4(4, 1);
	pair<int, int> pbrood5(5, 1);
	pair<int, int> pbrood6(6, 1);
	pair<int, int> pbrood7(7, 1);
	pair<int, int> pbrood8(8, 1);
	pair<int, int> pbrood9(9, 1);
	pair<int, int> pbrood10(10, 1);
	pair<int, int> pbroodv(11, 1);
	pair<int, int> pbroodd(12, 1);
	pair<int, int> pbroodk(13, 1);

	pair<int, int> pbubaa(1, 3);
	pair<int, int> pbuba2(2, 3);
	pair<int, int> pbuba3(3, 3);
	pair<int, int> pbuba4(4, 3);
	pair<int, int> pbuba5(5, 3);
	pair<int, int> pbuba6(6, 3);
	pair<int, int> pbuba7(7, 3);
	pair<int, int> pbuba8(8, 3);
	pair<int, int> pbuba9(9, 3);
	pair<int, int> pbuba10(10, 3);
	pair<int, int> pbubav(11, 3);
	pair<int, int> pbubad(12, 3);
	pair<int, int> pbubak(13, 3);

	pair<int, int> pcrossa(1, 2);
	pair<int, int> pcross2(2, 2);
	pair<int, int> pcross3(3, 2);
	pair<int, int> pcross4(4, 2);
	pair<int, int> pcross5(5, 2);
	pair<int, int> pcross6(6, 2);
	pair<int, int> pcross7(7, 2);
	pair<int, int> pcross8(8, 2);
	pair<int, int> pcross9(9, 2);
	pair<int, int> pcross10(10, 2);
	pair<int, int> pcrossv(11, 2);
	pair<int, int> pcrossd(12, 2);
	pair<int, int> pcrossk(13, 2);

	pair<int, int> ppeaka(1, 4);
	pair<int, int> ppeak2(2, 4);
	pair<int, int> ppeak3(3, 4);
	pair<int, int> ppeak4(4, 4);
	pair<int, int> ppeak5(5, 4);
	pair<int, int> ppeak6(6, 4);
	pair<int, int> ppeak7(7, 4);
	pair<int, int> ppeak8(8, 4);
	pair<int, int> ppeak9(9, 4);
	pair<int, int> ppeak10(10, 4);
	pair<int, int> ppeakv(11, 4);
	pair<int, int> ppeakd(12, 4);
	pair<int, int> ppeakk(13, 4);

	pair<int, int> pkarta(0, 0);

	pair<int, int> pshirt(-1, -1);

	pair<Sprite, pair<int, int>> brooda(scard[26], pbrooda);
	pair<Sprite, pair<int, int>> brood2(scard[27], pbrood2);
	pair<Sprite, pair<int, int>> brood3(scard[28], pbrood3);
	pair<Sprite, pair<int, int>> brood4(scard[29], pbrood4);
	pair<Sprite, pair<int, int>> brood5(scard[30], pbrood5);
	pair<Sprite, pair<int, int>> brood6(scard[31], pbrood6);
	pair<Sprite, pair<int, int>> brood7(scard[32], pbrood7);
	pair<Sprite, pair<int, int>> brood8(scard[33], pbrood8);
	pair<Sprite, pair<int, int>> brood9(scard[34], pbrood9);
	pair<Sprite, pair<int, int>> brood10(scard[35], pbrood10);
	pair<Sprite, pair<int, int>> broodv(scard[36], pbroodv);
	pair<Sprite, pair<int, int>> broodd(scard[37], pbroodd);
	pair<Sprite, pair<int, int>> broodk(scard[38], pbroodk);

	pair<Sprite, pair<int, int>> bubaa(scard[13], pbubaa);
	pair<Sprite, pair<int, int>> buba2(scard[14], pbuba2);
	pair<Sprite, pair<int, int>> buba3(scard[15], pbuba3);
	pair<Sprite, pair<int, int>> buba4(scard[16], pbuba4);
	pair<Sprite, pair<int, int>> buba5(scard[17], pbuba5);
	pair<Sprite, pair<int, int>> buba6(scard[18], pbuba6);
	pair<Sprite, pair<int, int>> buba7(scard[19], pbuba7);
	pair<Sprite, pair<int, int>> buba8(scard[20], pbuba8);
	pair<Sprite, pair<int, int>> buba9(scard[21], pbuba9);
	pair<Sprite, pair<int, int>> buba10(scard[22], pbuba10);
	pair<Sprite, pair<int, int>> bubav(scard[23], pbubav);
	pair<Sprite, pair<int, int>> bubad(scard[24], pbubad);
	pair<Sprite, pair<int, int>> bubak(scard[25], pbubak);

	pair<Sprite, pair<int, int>> crossa(scard[0], pcrossa);
	pair<Sprite, pair<int, int>> cross2(scard[1], pcross2);
	pair<Sprite, pair<int, int>> cross3(scard[2], pcross3);
	pair<Sprite, pair<int, int>> cross4(scard[3], pcross4);
	pair<Sprite, pair<int, int>> cross5(scard[4], pcross5);
	pair<Sprite, pair<int, int>> cross6(scard[5], pcross6);
	pair<Sprite, pair<int, int>> cross7(scard[6], pcross7);
	pair<Sprite, pair<int, int>> cross8(scard[7], pcross8);
	pair<Sprite, pair<int, int>> cross9(scard[8], pcross9);
	pair<Sprite, pair<int, int>> cross10(scard[9], pcross10);
	pair<Sprite, pair<int, int>> crossv(scard[10], pcrossv);
	pair<Sprite, pair<int, int>> crossd(scard[11], pcrossd);
	pair<Sprite, pair<int, int>> crossk(scard[12], pcrossk);

	pair<Sprite, pair<int, int>> peaka(scard[39], ppeaka);
	pair<Sprite, pair<int, int>> peak2(scard[40], ppeak2);
	pair<Sprite, pair<int, int>> peak3(scard[41], ppeak3);
	pair<Sprite, pair<int, int>> peak4(scard[42], ppeak4);
	pair<Sprite, pair<int, int>> peak5(scard[43], ppeak5);
	pair<Sprite, pair<int, int>> peak6(scard[44], ppeak6);
	pair<Sprite, pair<int, int>> peak7(scard[45], ppeak7);
	pair<Sprite, pair<int, int>> peak8(scard[46], ppeak8);
	pair<Sprite, pair<int, int>> peak9(scard[47], ppeak9);
	pair<Sprite, pair<int, int>> peak10(scard[48], ppeak10);
	pair<Sprite, pair<int, int>> peakv(scard[49], ppeakv);
	pair<Sprite, pair<int, int>> peakd(scard[50], ppeakd);
	pair<Sprite, pair<int, int>> peakk(scard[51], ppeakk);

	pair<Sprite, pair<int, int>> karta(skarta, pkarta);

	pair<Sprite, pair<int, int>> shirt(sshirt, pshirt);

	pair<Sprite, pair<int, int>> card[52]
	{ crossa, cross2, cross3, cross4, cross5, cross6, cross7, cross8, cross9, cross10, crossv, crossd, crossk, bubaa, buba2, buba3, buba4, buba5, buba6, buba7, buba8, buba9, buba10, bubav, bubad, bubak, brooda, brood2, brood3, brood4, brood5, brood6, brood7, brood8, brood9, brood10, broodv, broodd, broodk, peaka, peak2, peak3, peak4, peak5, peak6, peak7, peak8, peak9, peak10, peakv, peakd, peakk };

	srand(time(NULL));
	random_shuffle(card, card + 52);

	pair<Sprite, pair<int, int>> st[24][7]//[12]
	{
		{ card[24] , shirt , shirt, shirt, shirt , shirt, shirt },// , karta, karta, karta, karta, karta },
		{ karta, card[26],shirt , shirt, shirt, shirt , shirt },//, karta, karta, karta, karta, karta },
		{ karta, karta, card[29], shirt, shirt, shirt , shirt },//, karta, karta, karta, karta, karta },
		{ karta, karta, karta, card[33], shirt, shirt, shirt },//, karta, karta, karta, karta , karta },
		{ karta, karta, karta, karta, card[38], shirt, shirt },//, karta, karta, karta, karta , karta },
		{ karta, karta, karta, karta, karta, card[44], shirt },//, karta, karta, karta, karta , karta },
		{ karta, karta, karta, karta, karta, karta, card[51] },//, karta, karta, karta, karta, karta },
		{ karta, karta, karta, karta, karta, karta, karta },//, karta, karta, karta, karta, karta },
		{ karta, karta, karta, karta, karta, karta, karta },//, karta, karta, karta, karta, karta },
		{ karta, karta, karta, karta, karta, karta, karta },//, karta, karta, karta, karta, karta },
		{ karta, karta, karta, karta, karta, karta, karta },//, karta, karta, karta, karta, karta },
		{ karta, karta, karta, karta, karta, karta, karta },//, karta, karta, karta, karta, karta },
		{ karta, karta, karta, karta, karta, karta, karta },//, karta, karta, karta, karta, karta },
		{ karta, karta, karta, karta, karta, karta, karta },//, karta, karta, karta, karta, karta },
		{ karta, karta, karta, karta, karta, karta, karta },// , karta, karta, karta, karta, karta },
		{ karta, karta, karta, karta, karta, karta, karta },//, karta, karta, karta, karta, karta },
		{ karta, karta, karta, karta, karta, karta, karta },//, karta, karta, karta, karta , karta },
		{ karta, karta, karta, karta, karta, karta, karta },//, karta, karta, karta, karta , karta },
		{ karta, karta, karta, karta, karta, karta, karta },//, karta, karta, karta, karta , karta },
		{ karta, karta, karta, karta, karta, karta, karta },//, karta, karta, karta, karta, karta },
		{ karta, karta, karta, karta, karta, karta, karta },// , karta, karta, karta, karta, karta },
		{ karta, karta, karta, karta, karta, karta, karta },// , karta, karta, karta, karta , karta },
		{ karta, karta, karta, karta, karta, karta, karta },//, karta, karta, karta, karta, karta },
		{ karta, karta, karta, karta, karta, karta, karta },//, karta, karta, karta, karta , karta },
	};

	pair<Sprite, pair<int, int>> kol[24]
	{ card[0],card[1],card[2],card[3],card[4],card[5],card[6],card[7],card[8],card[9],card[10],card[11],card[12],card[13],card[14],card[15],card[16],card[17],card[18],card[19],card[20],card[21],card[22],card[23] };

	pair<Sprite, pair<int, int>> osn[13][4]
	{
		{ karta, karta, karta, karta },
		{ karta, karta, karta, karta },
		{ karta, karta, karta, karta },
		{ karta, karta, karta, karta },
		{ karta, karta, karta, karta },
		{ karta, karta, karta, karta },
		{ karta, karta, karta, karta },
		{ karta, karta, karta, karta },
		{ karta, karta, karta, karta },
		{ karta, karta, karta, karta },
		{ karta, karta, karta, karta },
		{ karta, karta, karta, karta },
		{ karta, karta, karta, karta },
	};

	bool isMove = false;//переменная для щелчка мыши по спрайту
	bool moved = false;//верно ли совершено движение
	float dX[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };//корректировка движения по х
	float dY[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };//по у

	bool pres = true;

	int kk;//количество выбраных карт
	int qq;


	bool mooo[3] = { false, false, false };


	while (window.isOpen())
	{

		Vector2i pos = Mouse::getPosition(window);

		window.clear(Color(0, 128, 0));
		//создание пустых ячеек
		empty.setPosition(310, 10);
		window.draw(empty);
		empty.setPosition(410, 10);
		window.draw(empty);
		empty.setPosition(510, 10);
		window.draw(empty);
		empty.setPosition(610, 10);
		window.draw(empty);

		empty.setPosition(10, 150);
		window.draw(empty);
		empty.setPosition(110, 150);
		window.draw(empty);
		empty.setPosition(210, 150);
		window.draw(empty);
		empty.setPosition(310, 150);
		window.draw(empty);
		empty.setPosition(410, 150);
		window.draw(empty);
		empty.setPosition(510, 150);
		window.draw(empty);
		empty.setPosition(610, 150);
		window.draw(empty);
		//рисовка начальной заготовки 
		for (int i = 0; i < 24; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				st[i][j].first.setPosition(j * 100 + 10, i * 23 + 150);
			}
		}

		for (int i = 0; i < 24; i++)
		{
			kol[i].first.setPosition(110, 10);
		}

		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				osn[i][j].first.setPosition(j * 100 + 310, 10);
			}
		}

		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			//	std::cout << pos.x << "\n";
			//	std::cout << pos.y << "\n";

			for (int i = 0; i < 3; i++)
			{
				mooo[i] = false;
			}



			if (event.type == Event::MouseButtonPressed)//если нажата клавиша мыши
				if (event.key.code == Mouse::Left)//а именно левая
					if ((((pos.x - 9) / 100) == ((pos.x + 17) / 100)) && (pos.y > 150))//и при этом координата курсора попадает в спрайт
					{
						b1 = pos.x / 100;
						printf("%d", b1);

						for (int i = 0; i < 20; i++)
						{
							if (st[i][b1].second == karta.second)
							{
								c1 = i;
								break;
							}
						}
						if (c1 != 0)
						{
							if (pos.y > 136 + 24 * c1)
							{
								dX[1] = pos.x - st[c1 - 1][b1].first.getPosition().x;//делаем разность между позицией курсора и спрайта.для корректировки нажатия
								dY[1] = pos.y - st[c1 - 1][b1].first.getPosition().y;//тоже самое по игреку
								isMove = true;//можем двигать спрайт
								moved = false;
								kk = 1;
								sek = 1;
							}
							else
							{
								kk = ((c1 - 1) * 24 + 150 - pos.y) / 24 + 2;
								if (st[c1 - kk][b1].second.first != -1)
								{
									for (int i = 0; i < kk; i++)
									{
										dX[i] = pos.x - st[c1 - 1 - i][b1].first.getPosition().x;//делаем разность между позицией курсора и спрайта.для корректировки нажатия
										dY[i] = pos.y - st[c1 - 1 - i][b1].first.getPosition().y;//тоже самое по игреку
									}
									isMove = true;//можем двигать спрайт
									moved = false;
									sek = 1;

								}
							}
						}
					}
					else if ((pos.x > 110) && (pos.x < 182) && (pos.y > 10) && (pos.y < 110) && (a - p != 1))//и при этом координата курсора попадает в спрайт
					{
						dX[1] = pos.x - kol[a].first.getPosition().x;//делаем разность между позицией курсора и спрайта.для корректировки нажатия
						dY[1] = pos.y - kol[a].first.getPosition().y;//тоже самое по игреку
						isMove = true;//можем двигать спрайт
						sek = 2;
					}
					else if ((((pos.x - 9) / 100) == ((pos.x + 17) / 100)) && (pos.y < 110) && (pos.x > 310))//и при этом координата курсора попадает в спрайт
					{
						qq = pos.x / 100;
						dX[1] = pos.x - osn[c2][qq].first.getPosition().x;//делаем разность между позицией курсора и спрайта.для корректировки нажатия
						dY[1] = pos.y - osn[c2][qq].first.getPosition().y;//тоже самое по игреку
						isMove = true;//можем двигать спрайт
						sek = 3;
					}

					if (event.type == Event::MouseButtonReleased)//если отпустили клавишу
						if (event.key.code == Mouse::Left) //а именно левую
						{
							isMove = false; //то не можем двигать спрайт
							b2 = pos.x / 100;
							if (sek == 1)
							{
								if (pos.y > 150)
								{
									for (int i = 0; i < 20; i++)
									{
										if (st[i][b2].second == karta.second)
										{
											c2 = i;
											break;
										}
									}
									if (kk == 1)
									{
										if ((provk(st[c2 - 1][b2].second.second, st[c1 - 1][b1].second.second, st[c2 - 1][b2].second.first, st[c1 - 1][b1].second.first)) || (c2 == 0 && st[c1 - 1][b1].second.first == 13))
										{
											st[c2][b2] = st[c1 - 1][b1];
											st[c1 - 1][b1] = karta;
											window.draw(st[c2][b2].first);
											moved = true;
										}
									}
									else
									{
										if ((provk(st[c2 - 1][b2].second.second, st[c1 - kk][b1].second.second, st[c2 - 1][b2].second.first, st[c1 - kk][b1].second.first)) || (c2 == 0 && st[c1 - kk][b1].second.first == 13))
										{
											for (int i = 0; i < kk; i++)
											{
												st[c2 + i][b2] = st[c1 - kk + i][b1];
												st[c1 - kk + i][b1] = karta;
												window.draw(st[c2 + i][b2].first);
											}
											moved = true;
										}
									}
								}
								else if (pos.x > 310)
								{
									b2 = b2 - 3;
									for (int i = 0; i < 13; i++)
									{
										if (osn[i][b2].second == karta.second)
										{
											c2 = i;
											break;
										}
									}
									if ((provka(osn[c2 - 1][b2].second.second, st[c1 - 1][b1].second.second, osn[c2 - 1][b2].second.first, st[c1 - 1][b1].second.first)) || (c2 == 0 && st[c1 - 1][b1].second.first == 1))
									{
										osn[c2][b2] = st[c1 - 1][b1];
										st[c1 - 1][b1] = karta;
										window.draw(osn[c2][b2].first);
										moved = true;
									}
								}
							}
							else if (sek == 2)
							{
								if (pos.y > 150)
								{
									for (int i = 0; i < 20; i++)
									{
										if (st[i][b2].second == karta.second)
										{
											c2 = i;
											break;
										}
									}
									if ((provk(st[c2 - 1][b2].second.second, kol[a].second.second, st[c2 - 1][b2].second.first, kol[a].second.first)) || (c2 == 0 && kol[a].second.first == 13))
									{
										st[c2][b2] = kol[a];
										for (int i = a; i < p; i++)
										{
											kol[i] = kol[i + 1];
										}
										window.draw(st[c2][b2].first);
									
										p--;
										moved = true;
									}
								}
								else if (pos.x > 310)
								{
									b2 = b2 - 3;
									for (int i = 0; i < 13; i++)
									{
										if (osn[i][b2].second == karta.second)
										{
											c2 = i;
											break;
										}
									}
									if ((provka(osn[c2 - 1][b2].second.second, kol[a].second.second, osn[c2 - 1][b2].second.first, kol[a].second.first)) || (c2 == 0 && kol[a].second.first == 1))
									{
										osn[c2][b2] = kol[a];
										kol[a] = karta;
										window.draw(osn[c2][b2].first);

										p--;
										moved = true;
									}
								}
							}
						}
		}
		if (isMove) {//если можем двигать
			if (sek == 1)
			{
				if (kk == 1)
				{
					st[c1 - 1][b1].first.setPosition(pos.x - dX[1], pos.y - dY[1]);//можно и так написать,если у вас нету х и у
					window.draw(st[c1 - 1][b1].first);
				}
				else
				{
					for (int i = 0; i < kk; i++)
					{
						st[c1 - 1 - i][b1].first.setPosition(pos.x - dX[i], pos.y - dY[i]);//можно и так написать,если у вас нету х и у
						window.draw(st[c1 - 1 - i][b1].first);
					}
				}
			}
			if (sek == 2)
			{
				mooo[2] = true;
				kol[a].first.setPosition(pos.x - dX[1], pos.y - dY[1]);//можно и так написать,если у вас нету х и у
				window.draw(kol[a].first);
			}
			if (sek == 3)
			{
				osn[c2][qq].first.setPosition(pos.x - dX[1], pos.y - dY[1]);
				window.draw(osn[c2][qq].first);
			}
		}

		for (int i = 0; i < 20; i++)
		{
			if (st[i][b1].second == karta.second)
			{
				bb = i;
				break;
			}
		}


		if (st[bb - 1][b1].second == shirt.second && bb != 0 && moved) //îňâĺ÷ŕĺň çŕ ňî, ÷ňîáű âĺńňî đóáŕřęč ďî˙âë˙ëčńü ęŕđňű
		{
			if (b1 == 1)
				st[bb - 1][b1] = card[25];
			if (b1 == 2)
				st[bb - 1][b1] = card[29 - bb];
			if (b1 == 3)
				st[bb - 1][b1] = card[33 - bb];
			if (b1 == 4)
				st[bb - 1][b1] = card[38 - bb];
			if (b1 == 5)
				st[bb - 1][b1] = card[44 - bb];
			if (b1 == 6)
				st[bb - 1][b1] = card[51 - bb];
		}


		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				window.draw(osn[i][j].first);
			}
		}

		for (int i = 0; i < 24; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				window.draw(st[i][j].first);
			}
		}

		if (event.type == Event::MouseButtonPressed)
		{
			pres = true;
		}

		if (event.type == Event::MouseButtonReleased && pres == true)
			if ((pos.x > 10) && (pos.x < 82) && (pos.y > 10) && (pos.y < 110))
			{
				a--;
				pres = false;
			}
		
		if (a == 0)
		{
			empty.setPosition(10, 10);
			window.draw(empty);
			a = p;
		}
		else
		{

			sshirt.setPosition(10, 10);
			window.draw(sshirt);
		}

		for (int i = p; i >= a; i--)
		{
		//	kol[a].first.setPosition(110, 10);
			window.draw(kol[i].first);
		}

	/*	if (event.type == Event::MouseButtonPressed)
		{
			pres = true;
		}

		if (event.type == Event::MouseButtonReleased && pres == true)
			if ((pos.x > 10) && (pos.x < 82) && (pos.y > 10) && (pos.y < 110))
			{
				a = e;
				e--;
				pres = false;
			}

		if (e == 0)
		{
			empty.setPosition(10, 10);
			window.draw(empty);
			e = p;
		}
		else
		{
			sshirt.setPosition(10, 10);
			window.draw(sshirt);
		}

		if (a != 666)
		{
			kol[a] = card[a];
			kol[a].first.setPosition(110, 10);
			window.draw(kol[a].first);
		}*/


		window.display();


	}

	return 0;
}