Type

PEl = ^TEl;

TEl = record
Key : TKey;
Y: integer;
L, R : PEl;
end;
Инициализация дерева :
//Без комментариев

procedure Init(var root : PEl);
begin
root : = nil;
end;
Добавление элемента.Алгоритм следующий : найдем то поддерево, у которого он будет корнем.Процедурой Split разделим это поддерево в соответствии с ключом нового корня и сразу же подвесим все, куда необходимо.Код лучше читать снизу вверх.
//Процедура Split разбирает все дерево с корнем в pt
//в соответствии с ключом key и вешает к pR и pL
procedure Split(pt : PEl; key: TKey; var pL, pR : PEl);
begin
if pt = nil then
begin
//разбор пустого дерева
pL : = nil;
pR: = nil;
end
else
//Здесь смотрится, куда отнести корень и соответственно   вызывается
//опять процедура Split
if pt^.key < key then
	begin
	pL : = pt;
Split(pL^.R, key, pL^.R, pR);
end
else
begin
pR : = pt;
Split(pR^.L, key, pL, pR^.L);
end;
end;

procedure Add1(var p : PEl; var np : PEl);
//p – ссылка на корень поддерева, к которому идет добавление
//np – ссылка на новый элемент
begin
if p = nil then
//Добавление к пустому поддереву
p : = np
else
if np^.y < p^.y then
	//Если приоритет корня еще больше приоритета новой вершины, идем
	//дальше по дереву
	if np^.key = p^.key then
		exit
	else
		if np^.key < p^.key then
			Add1(p^.L, np)
		else
			Add1(p^.R, np)
else
begin
//Подвесим к новой вешнине все необходимое поддерево
Split(p, np^.key, np^.L, np^.R);
//И привесим эту вершину вместо поддерева
p: = np;
end;
end;

procedure Add(var root : PEl; const a : TKey);

// root – корень дерева, a – значение нового ключа

var
np : PEl;
begin

//Создание вершины

new(np);
np^.key : = a;
np^.y : = Random(maxRand);
np^.L : = nil;
np^.R : = nil;

//Вызов непосредственно процедуры добавления

Add1(root, np);
end;

//Функция возвращает указатель на искомый элемент или nil, если его нет

function Search(var p : PEl; const A : TKey) : PEl;
begin
if p = nil then
result : = nil
else
if A = p^.key then
result : = P
else
if A < p^.key then
	result : = Search(p^.L, A)
else
result : = Search(p^.R, A)
	end;

Процедура удаления находит этот элемент в дереве и удаляет его.Затем два его поддерева подвешиваются к ее родителю.

//Процедура подвешивает к p поддеревья pL и pR
procedure Merge(var p : PEl; pL, pR : PEl);
begin
//Елси одно из поддеревьев пусто, то подвешиваем другое
if pL = nil then
p : = pR
else
if pR = nil then
p : = pL
else
// Смотрим по приоритету
if pL^.y > pR^.y then
begin
p : = pL;
Merge(p^.R, p^.R, pR);
end
else
begin
p : = pR;
Merge(p^.L, pL, p^.L);
end
end;

procedure Delete(var p : PEl; const A : TKey);
begin
if p = nil then
Writeln('No such element')
else
if A = p^.key then
//Найден элемент
Merge(p, p^.L, p^.R)
//Поиск элемента
else
if A < p^.key then
	Delete(p^.L, A)
else
Delete(p^.R, A)
end;


/*if (event.type == Event::MouseButtonPressed)
{
x1 = mousePos.x;
y1 = mousePos.y;
if ((x1 > 10) && (x1 < 82) && (y1 > 10) && (y1 < 110))
{
a = e;
e--;
}
}

if (event.type == Event::MouseButtonPressed)
{

printf("%d", numbersClick);

if (numbersClick % 2 == 1)
{
x1 = mousePos.x;
y1 = mousePos.y;

if (((x1 - 9) / 100) == ((x1 + 17) / 100))
{
b1 = x1 / 100;
printf("%d", b1);

for (int i = 0; i < 13; i++)
{
if (st[i][b1].second == karta.second)
{
c1 = i;
break;
}
}
printf("%d", c1);
if (c1 != 0)
{
if ((y1 < 250 + c1 * 23) && (y1 > 150 + c1 * 23))
{
if (st[c1 - 1][b1].second.first != shirt.second.first)
{
st[c1 - 1][b1].first.setColor(Color::Yellow);
bb = 1;
numbersClick++;
}
} else
if ((y1 < ((c1-1)*23+150)) && (y1 > 150))
{
d1 = (y1 - 150) /23;
if (st[d1][b1].second.first != shirt.second.first)
{
printf("\n%d", d1);
st[d1][b1].first.setColor(Color::Yellow);
bb = 1;
numbersClick++;
}
}
}
}
}
else
x2 = mousePos.x;
y2 = mousePos.y;

if ((x1 == x2) && (y1 == y2))
{
if (((x2 - 9) / 100) == ((x2 + 17) / 100))
{
b2 = x2 / 100;
printf("%d", b2);

for (int i = 0; i < 20; i++)
{
if (st[i][b2].second == karta.second)
{
c2 = i;
break;
}
}
printf("%d", c2);
if (c2 != 0)
{
if ((y2 < 250 + c2 * 23) && (y2 > 150 + c2 * 23))
{
st[c2 - 1][b2].first.setColor(Color::White);
numbersClick++;
}
else
if ((y2 < ((c2 - 1) * 23 + 150)) && (y2 > 150))
{
d2 = (y2 - 150) / 23;
printf("\n%d", d2);
st[d2][b2].first.setColor(Color::White);
numbersClick++;
}
}
}
} else
if (((x2 - 9) / 100) == ((x2 + 17) / 100))
{
b2 = x2 / 100;
printf("%d", b2);

for (int i = 0; i < 20; i++)
{
if (st[i][b2].second == karta.second)
{
c2 = i;
break;
}
}
for (int i = 0; i < c1 - d1; i++)
{
st[c2 + i][b2] = st[d1 + i][b1];
}


}

}

printf("\n%d\n", y1);
printf("\n%d\n", x1);*/\














empty.setPosition(10, 150);
window.draw(empty);
card[24].setPosition(10, 130 + 1 * 20);
window.draw(card[24]);

empty.setPosition(110, 150);
window.draw(empty);
for (int i = 1; i < 3; i++)
{
	shirt.setPosition(110, 130 + i * 20);
	window.draw(shirt);
}
card[26].setPosition(110, 170);
window.draw(card[26]);
empty.setPosition(210, 150);
window.draw(empty);
for (int i = 1; i < 4; i++)
{
	shirt.setPosition(210, 130 + i * 20);
	window.draw(shirt);
}
card[29].setPosition(210, 190);
window.draw(card[29]);
empty.setPosition(310, 150);
window.draw(empty);
for (int i = 1; i < 5; i++)
{
	shirt.setPosition(310, 130 + i * 20);
	window.draw(shirt);
}
card[33].setPosition(310, 210);
window.draw(card[33]);
empty.setPosition(410, 150);
window.draw(empty);
for (int i = 1; i < 6; i++)
{
	shirt.setPosition(410, 130 + i * 20);
	window.draw(shirt);
}
card[38].setPosition(410, 230);
window.draw(card[38]);
empty.setPosition(510, 150);
window.draw(empty);
for (int i = 1; i < 7; i++)
{
	shirt.setPosition(510, 130 + i * 20);
	window.draw(shirt);
}
card[44].setPosition(510, 250);
window.draw(card[44]);
empty.setPosition(610, 150);
window.draw(empty);
for (int i = 1; i < 8; i++)
{
	shirt.setPosition(610, 130 + i * 20);
	window.draw(shirt);
}
card[51].setPosition(610, 270);
window.draw(card[51]);

















/*for (int i = 0; i < 13; i++)
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
}*/

//if (event.type == Event::MouseButtonReleased)
//{
//	/*if (numbersClick % 2 == 1)
//	{*/
//		x1 = mousePos.x;
//		y1 = mousePos.y;

//	/*}
//	else
//	{
//		x2 = mousePos.x;
//		y2 = mousePos.y;
//	}
//	*//*
//		if ((x1 > 100+10) && (x1 < i*100+82) && (y1 > i*200+150) && (y1 < i*200+250))
//		{*/
//			/*if (numbersClick % 2 == 1)
//			{
//				x1 = mousePos.x;
//				y1 = mousePos.y;
//			}
//			else
//			{
//				x2 = mousePos.x;
//				y2 = mousePos.y;
//			}*/
//	/*	b = ((y1 - 150) / 200);
//		bb = ((x1 - 10) / 100);
//		if (b == bb)
//		{
//			switch (bb)
//			{
//			case 0:
//			{
//				card[24].setColor(Color::Yellow);
//			}
//			case 1:
//			{
//				card[25].setColor(Color::Yellow);
//			}
//			case 2:
//			{
//				card[27].setColor(Color::Yellow);
//			}
//			case 3:
//			{
//				card[30].setColor(Color::Yellow);
//			}
//			case 4:
//			{
//				card[34].setColor(Color::Yellow);
//			}
//			case 5:
//			{
//				card[40].setColor(Color::Yellow);
//			}
//			case 6:
//			{
//				card[46].setColor(Color::Yellow);
//			}
//			}
//		}*/
//			/*	if ((x2 > 110) && (x2 < 182) && (y2 > 350) && (y2 < 450))
//			{
//				
//			}*/

//		/*}*/
////	}
//	printf("%d\n", numbersClick);
//	numbersClick++;
//}















#pragma once
//Texture cardtexture;
//	cardtexture.loadFromFile("images/0.bmp");




cardt[0].loadFromFile("images/0.bmp");
card[0].setTexture(cardt[0]);

cardt[1].loadFromFile("images/1.bmp");
card[1].setTexture(cardt[1]);

cardt[2].loadFromFile("images/2.bmp");
card[2].setTexture(cardt[2]);

cardt[3].loadFromFile("images/3.bmp");
card[3].setTexture(cardt[3]);

cardt[4].loadFromFile("images/4.bmp");
card[4].setTexture(cardt[4]);

cardt[5].loadFromFile("images/5.bmp");
card[5].setTexture(cardt[5]);

cardt[6].loadFromFile("images/6.bmp");
card[6].setTexture(cardt[6]);

cardt[7].loadFromFile("images/7.bmp");
card[7].setTexture(cardt[7]);

cardt[8].loadFromFile("images/8.bmp");
card[8].setTexture(cardt[8]);

cardt[9].loadFromFile("images/9.bmp");
card[9].setTexture(cardt[9]);

cardt[10].loadFromFile("images/10.bmp");
card[10].setTexture(cardt[10]);

cardt[11].loadFromFile("images/11.bmp");
card[11].setTexture(cardt[11]);

cardt[12].loadFromFile("images/12.bmp");
card[12].setTexture(cardt[12]);

cardt[13].loadFromFile("images/13.bmp");
card[13].setTexture(cardt[13]);

cardt[14].loadFromFile("images/14.bmp");
card[14].setTexture(cardt[14]);

cardt[15].loadFromFile("images/15.bmp");
card[15].setTexture(cardt[15]);

cardt[16].loadFromFile("images/16.bmp");
card[16].setTexture(cardt[16]);

cardt[17].loadFromFile("images/17.bmp");
card[17].setTexture(cardt[17]);

cardt[18].loadFromFile("images/18.bmp");
card[18].setTexture(cardt[18]);

cardt[19].loadFromFile("images/19.bmp");
card[19].setTexture(cardt[19]);

cardt[20].loadFromFile("images/20.bmp");
card[20].setTexture(cardt[20]);

cardt[21].loadFromFile("images/21.bmp");
card[21].setTexture(cardt[21]);

cardt[22].loadFromFile("images/22.bmp");
card[22].setTexture(cardt[22]);

cardt[23].loadFromFile("images/23.bmp");
card[23].setTexture(cardt[23]);

cardt[24].loadFromFile("images/24.bmp");
card[20].setTexture(cardt[20]);

cardt[24].loadFromFile("images/24.bmp");
card[24].setTexture(cardt[24]);

cardt[25].loadFromFile("images/25.bmp");
card[25].setTexture(cardt[25]);

cardt[26].loadFromFile("images/26.bmp");
card[26].setTexture(cardt[26]);

cardt[27].loadFromFile("images/27.bmp");
card[27].setTexture(cardt[27]);

cardt[28].loadFromFile("images/28.bmp");
card[28].setTexture(cardt[28]);

cardt[29].loadFromFile("images/29.bmp");
card[29].setTexture(cardt[29]);

cardt[30].loadFromFile("images/30.bmp");
card[30].setTexture(cardt[30]);

cardt[31].loadFromFile("images/31.bmp");
card[31].setTexture(cardt[31]);

cardt[32].loadFromFile("images/32.bmp");
card[32].setTexture(cardt[32]);

cardt[33].loadFromFile("images/33.bmp");
card[33].setTexture(cardt[33]);

cardt[34].loadFromFile("images/34.bmp");
card[34].setTexture(cardt[34]);

cardt[35].loadFromFile("images/35.bmp");
card[35].setTexture(cardt[35]);

cardt[36].loadFromFile("images/36.bmp");
card[36].setTexture(cardt[36]);

cardt[37].loadFromFile("images/37.bmp");
card[37].setTexture(cardt[37]);

cardt[38].loadFromFile("images/38.bmp");
card[38].setTexture(cardt[38]);

cardt[39].loadFromFile("images/39.bmp");
card[39].setTexture(cardt[39]);

cardt[40].loadFromFile("images/40.bmp");
card[40].setTexture(cardt[40]);

cardt[41].loadFromFile("images/41.bmp");
card[41].setTexture(cardt[41]);

cardt[42].loadFromFile("images/42.bmp");
card[42].setTexture(cardt[42]);

cardt[43].loadFromFile("images/43.bmp");
card[43].setTexture(cardt[43]);

cardt[44].loadFromFile("images/44.bmp");
card[44].setTexture(cardt[44]);

cardt[45].loadFromFile("images/45.bmp");
card[45].setTexture(cardt[45]);

cardt[46].loadFromFile("images/46.bmp");
card[46].setTexture(cardt[46]);

cardt[47].loadFromFile("images/47.bmp");
card[47].setTexture(cardt[47]);

cardt[48].loadFromFile("images/48.bmp");
card[48].setTexture(cardt[48]);

cardt[49].loadFromFile("images/49.bmp");
card[49].setTexture(cardt[49]);

cardt[50].loadFromFile("images/50.bmp");
card[50].setTexture(cardt[50]);

cardt[50].loadFromFile("images/50.bmp");
card[50].setTexture(cardt[50]);

cardt[51].loadFromFile("images/51.bmp");
card[51].setTexture(cardt[51]);




//	Sprite cardsprite;
//	cardsprite.setTexture(cardtexture);
//	cardsprite.setPosition(50, 25);

//	Texture cardtexture1;
//	cardtexture1.loadFromFile("images/1.bmp");

//	Sprite cardsprite1;
//	cardsprite1.setTexture(cardtexture1);
//	cardsprite1.setPosition(200, 25);
//
//	Texture cardtexture2;
//	cardtexture2.loadFromFile("images/2.bmp");
//
//	Sprite cardsprite2;
//	cardsprite2.setTexture(cardtexture2);
//	cardsprite2.setPosition(300, 25);
//
//	Texture cardtexture3;
//	cardtexture3.loadFromFile("images/3.bmp");
//
//	Sprite cardsprite3;
//	cardsprite3.setTexture(cardtexture3);
//	cardsprite3.setPosition(400, 25);








class cards
{
public:
	int x, y;
	string File;
	Image image;
	Texture texture;
	Sprite sprite;

	cards(String f, int X, int Y)
	{
		File = f;
		image.loadFromFile(string("images/") + File);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y;
		sprite.setPosition(x, y);
	}
};




//Texture cardtexture4;
//	cardtexture4.loadFromFile("images/4.bmp");

//Sprite cardsprite4;
//cardsprite4.setTexture(cardtexture4);
//cardsprite4.setPosition(500, 25);


Vector2i pixelPos = Mouse::getPosition(window);



//			if (cardsprite1.getGlobalBounds().contains(pixelPos.x, pixelPos.y))
//			{
//				cardsprite1.setColor(Color::Red);
//		}
//		if (cardsprite.getGlobalBounds().contains(pixelPos.x, pixelPos.y))
//		{
//				cardsprite.setColor(Color::Red);
//			}
//	if (cardsprite2.getGlobalBounds().contains(pixelPos.x, pixelPos.y))
//		{
//			cardsprite2.setColor(Color::Red);
//			}
//if (cardsprite3.getGlobalBounds().contains(pixelPos.x, pixelPos.y))
//			{
//cardsprite3.setColor(Color::Red);
//			}
//		



while (window.pollEvent(event))
{
	if (event.type == Event::Closed)
		window.close();
	for (int i = 0; i < 53; i++)
	{
		for (int i = 0; i < 53; i++)
	{
		if (event.type == Event::MouseButtonPressed)//если нажата клавиша мыши
			if (event.key.code == Mouse::Left) {//а именно левая
				if (card[i].getGlobalBounds().contains(pixelPos.x, pixelPos.y))//и при этом координата курсора попадает в спрайт
				{
					card[i].setColor(Color::Green);//красим спрайт в зеленый,тем самым говоря игроку,что он выбрал персонажа и может сделать ход
				}
	}
}




#include <SFML/Graphics.hpp>
#include <stdio.h>

		using namespace sf;
		using namespace std;
		const int koef = 75;


		Sprite add_figure(string str)
		{
			Image *checker_image = new Image();
			Texture *checker_texture = new Texture();
			Sprite *checker_sprite = new Sprite();
			checker_image->loadFromFile(str);
			checker_texture->loadFromImage(*checker_image);
			checker_sprite->setTexture(*checker_texture);
			return *checker_sprite;
		}

		bool proverka_horse(int y1, int x1, int y2, int x2)
		{
			if (((abs(x1 - x2) == 1) && ((abs(y1 - y2)) == 2)) || ((abs(x1 - x2) == 2) && ((abs(y1 - y2)) == 1)))
				return true;
			else
				return false;
		}

		bool proverka_king(int y1, int x1, int y2, int x2)
		{
			if (((abs(x1 - x2) == 0) && ((abs(y1 - y2)) == 1)) || ((abs(x1 - x2) == 1) && ((abs(y1 - y2)) == 0)) || ((abs(x1 - x2) == 1) && ((abs(y1 - y2)) == 1)))
				return true;
			else
				return false;
		}

		bool proverka_slon(int y1, int x1, int y2, int x2)
		{
			if ((abs(y1 - y2) == 0) || (abs(x1 - x2) == 0))
				return true;
			else
				return false;

		}

		bool proverka_oficer(int y1, int x1, int y2, int x2)
		{
			if (abs(y1 - y2) == abs(x1 - x2))
				return true;
			else
				return false;
		}

		bool proverka_queen(int y1, int x1, int y2, int x2)
		{
			if ((abs(y1 - y2) == abs(x1 - x2)) || ((abs(y1 - y2) == 0) || (abs(x1 - x2) == 0)))
				return true;
			else
				return false;
		}


		int main()
		{
			RenderWindow window(VideoMode(650, 650), "chess");
			RectangleShape WhiteSquare(Vector2f(koef, koef));
			RectangleShape BlackSquare(Vector2f(koef, koef));
			WhiteSquare.setFillColor(sf::Color(222, 222, 222));
			BlackSquare.setFillColor(sf::Color(41, 41, 41));

			Sprite sblackhorse = add_figure("images/blackhorse.png");
			Sprite sblackking = add_figure("images/blackqueen.png");
			Sprite sblackoficer = add_figure("images/blackoficer.png");
			Sprite sblackpeshka = add_figure("images/blackpeshka.png");
			Sprite sblackqueen = add_figure("images/blackking.png");
			Sprite sblackslon = add_figure("images/blackslon.png");
			Sprite swhitehorse = add_figure("images/whitehorse.png");
			Sprite swhiteking = add_figure("images/whitequeen.png");
			Sprite swhiteoficer = add_figure("images/whiteoficer.png");
			Sprite swhitepeshka = add_figure("images/whitepeshka.png");
			Sprite swhitequeen = add_figure("images/whiteking.png");
			Sprite swhiteslon = add_figure("images/whiteslon.png");
			Sprite sNill = add_figure("images/Null.png");
			Sprite BlackWin = add_figure("images/winblack.png");
			Sprite WhiteWin = add_figure("images/winwhite.png");
			BlackWin.setPosition(0, 0);
			WhiteWin.setPosition(0, 0);

			pair<String, String> pBlackhorse("blackhorse", "Black");
			pair<String, String> pBlackking("blackking", "Black");
			pair<String, String> pBlackoficer("blackoficer", "Black");
			pair<String, String> pBlackpeshka("blackpeshka", "Black");
			pair<String, String> pBlackqueen("blackqueen", "Black");
			pair<String, String> pBlackslon("blackslon", "Black");
			pair<String, String> pWhitehorse("whitehorse", "White");
			pair<String, String> pWhiteking("Whiteking", "White");
			pair<String, String> pWhiteoficer("Whiteoficer", "White");
			pair<String, String> pWhitepeshka("Whitepeshka", "White");
			pair<String, String> pWhitequeen("Whitequeen", "White");
			pair<String, String> pWhiteslon("Whiteslon", "White");
			pair<String, String> pNill("Nilll", "None");


			pair<Sprite, pair<String, String>> blackhorse(sblackhorse, pBlackhorse);
			pair<Sprite, pair<String, String>> blackking(sblackking, pBlackking);
			pair<Sprite, pair<String, String>> blackoficer(sblackoficer, pBlackoficer);
			pair<Sprite, pair<String, String>> blackpeshka(sblackpeshka, pBlackpeshka);
			pair<Sprite, pair<String, String>> blackqueen(sblackqueen, pBlackqueen);
			pair<Sprite, pair<String, String>> blackslon(sblackslon, pBlackslon);
			pair<Sprite, pair<String, String>> whitehorse(swhitehorse, pWhitehorse);
			pair<Sprite, pair<String, String>> whiteking(swhiteking, pWhiteking);
			pair<Sprite, pair<String, String>> whiteoficer(swhiteoficer, pWhiteoficer);
			pair<Sprite, pair<String, String>> whitepeshka(swhitepeshka, pWhitepeshka);
			pair<Sprite, pair<String, String>> whitequeen(swhitequeen, pWhitequeen);
			pair<Sprite, pair<String, String>> whiteslon(swhiteslon, pWhiteslon);
			pair<Sprite, pair<String, String>> Nill(sNill, pNill);

			pair<Sprite, pair<String, String>> arrays[8][8]
			{
				{ whiteslon, whitehorse, whiteoficer, whiteking, whitequeen, whiteoficer, whitehorse, whiteslon },
				{ whitepeshka, whitepeshka, whitepeshka, whitepeshka, whitepeshka, whitepeshka, whitepeshka, whitepeshka },
				{ Nill, Nill, Nill, Nill, Nill, Nill, Nill, Nill },
				{ Nill, Nill, Nill, Nill, Nill, Nill, Nill, Nill },
				{ Nill, Nill, Nill, Nill, Nill, Nill, Nill, Nill },
				{ Nill, Nill, Nill, Nill, Nill, Nill, Nill, Nill },
				{ blackpeshka, blackpeshka, blackpeshka, blackpeshka, blackpeshka, blackpeshka, blackpeshka, blackpeshka },
				{ blackslon, blackhorse, blackoficer, blackking, blackqueen, blackoficer, blackhorse, blackslon },
			};


			int numbersClick = 1, schyot, xk, yk;
			int x1 = 0, x2 = 0, y1 = 0, y2 = 0, chblack = 0, chwhite = 0;
			int x1q = 0, x2q = 0, y1q = 0, y2q = 0;
			bool prov;

			RenderWindow menu(VideoMode(650, 650), "menu");

			while (window.isOpen())
			{
				Vector2i mousePos1 = Mouse::getPosition(window);
				window.setFramerateLimit(24);


				window.clear();
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if ((i + j) % 2 == 0)
						{
							WhiteSquare.setPosition(i * koef + 25, j * koef + 25);
							window.draw(WhiteSquare);
						}
						else
						{
							BlackSquare.setPosition(i * koef + 25, j * koef + 25);
							window.draw(BlackSquare);
						}
					}
				}
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						arrays[j][i].first.setPosition(i*koef + 25, j*koef + 25);
						window.draw(arrays[j][i].first);
					}
				}
				Event event;

				while (window.pollEvent(event))
					if (event.type == Event::MouseButtonPressed)
					{

						if (numbersClick % 2 == 1)
						{
							x1 = mousePos1.x;
							y1 = mousePos1.y;
						}
						else
						{
							x2 = mousePos1.x;
							y2 = mousePos1.y;
						}
						

						x2q = (x2 - 25) / 75;
						y2q = (y2 - 25) / 75;
						if (((arrays[y1q][x1q].second.first != Nill.second.first) && (arrays[y1q][x1q].second.second == "White") && ((numbersClick % 4 == 1) || (numbersClick % 4 == 2))) || ((arrays[y1q][x1q].second.first != Nill.second.first) && (arrays[y1q][x1q].second.second == "Black") && ((numbersClick % 4 == 3) || (numbersClick % 4 == 0))))
						{
							arrays[y1q][x1q].first.setColor(Color::Yellow);

							if (event.key.code == Mouse::Left)
							{
								if (numbersClick % 2 == 0)
								{
									if (arrays[y1q][x1q].second.second == arrays[y2q][x2q].second.second)
									{
										x1 = x2;
										y1 = y2;
										arrays[y1q][x1q].first.setColor(Color::White);
										arrays[y2q][x2q].first.setColor(Color::Yellow);

										numbersClick--;
									}
									else
									{


										prov = false;
										if ((proverka_king(y1q, x1q, y2q, x2q) == true) && ((arrays[y1q][x1q].second.first == "Whiteking") || (arrays[y1q][x1q].second.first == "blackking")))
										{
											prov = true;
										}
										if ((proverka_horse(y1q, x1q, y2q, x2q) == true) && ((arrays[y1q][x1q].second.first == "whitehorse") || (arrays[y1q][x1q].second.first == "blackhorse")))
										{
											prov = true;
										}
										if ((proverka_slon(y1q, x1q, y2q, x2q) == true) && ((arrays[y1q][x1q].second.first == "Whiteslon") || (arrays[y1q][x1q].second.first == "blackslon")))
										{
											prov = true;
											xk = x1q;
											yk = y1q;
											while ((xk != (x2q)) || (yk != (y2q)))
											{
												xk += (xk<x2q) ? 1 : ((xk>x2q) ? -1 : 0);
												yk += (yk<y2q) ? 1 : ((yk>y2q) ? -1 : 0);
												if ((arrays[y2q][x2q].second.first != arrays[yk][xk].second.first) && (arrays[yk][xk].second.first != "Nilll"))
												{
													prov = false;
												}
											}
										}
										if ((proverka_oficer(y1q, x1q, y2q, x2q) == true) && ((arrays[y1q][x1q].second.first == "Whiteoficer") || (arrays[y1q][x1q].second.first == "blackoficer")))
										{
											prov = true;
											xk = x1q;
											yk = y1q;
											while ((xk != (x2q)) || (yk != (y2q)))
											{
												xk += (xk<x2q) ? 1 : ((xk>x2q) ? -1 : 0);
												yk += (yk<y2q) ? 1 : ((yk>y2q) ? -1 : 0);
												if ((arrays[y2q][x2q].second.first != arrays[yk][xk].second.first) && (arrays[yk][xk].second.first != "Nilll"))
												{
													prov = false;
												}
											}
										}
										if ((proverka_queen(y1q, x1q, y2q, x2q) == true) && ((arrays[y1q][x1q].second.first == "Whitequeen") || (arrays[y1q][x1q].second.first == "blackqueen")))
										{
											prov = true;
											xk = x1q;
											yk = y1q;
											while ((xk != (x2q)) || (yk != (y2q)))
											{
												xk += (xk<x2q) ? 1 : ((xk>x2q) ? -1 : 0);
												yk += (yk<y2q) ? 1 : ((yk>y2q) ? -1 : 0);
												if ((arrays[y2q][x2q].second.first != arrays[yk][xk].second.first) && (arrays[yk][xk].second.first != "Nilll"))
												{
													prov = false;
												}
											}
										}
										if (arrays[y1q][x1q].second.first == "Whitepeshka")
										{
											if ((y2q == 1 + y1q) && (x2q == x1q) && (arrays[y2q][x2q].second.first == "Nilll"))
											{
												prov = true;
											}
											if ((y2q == 1 + y1q) && (((x2q + 1) == x1q) || ((x2q - 1) == x1q)) && (arrays[y2q][x2q].second.second == "Black"))
											{
												prov = true;
											}
											if (y1q == 1)
											{
												if ((y2q == 2 + y1q) && (x2q == x1q) && (arrays[y2q][x2q].second.first == "Nilll") && (arrays[y2q - 1][x2q].second.first == "Nilll"))
												{
													prov = true;
												}
											}
											if (y2q == 7)
											{
												arrays[y1q][x1q] = whitequeen;
											}
										}
										if (arrays[y1q][x1q].second.first == "blackpeshka")
										{
											if ((1 + y2q == y1q) && (x2q == x1q) && (arrays[y2q][x2q].second.first == "Nilll"))
											{
												prov = true;
											}
											if ((1 + y2q == y1q) && (((x2q + 1) == x1q) || ((x2q - 1) == x1q)) && (arrays[y2q][x2q].second.second == "White"))
											{
												prov = true;
											}
											if (y1q == 6)
											{
												if ((y2q + 2 == y1q) && (x2q == x1q) && (arrays[y2q][x2q].second.first == "Nilll") && (arrays[y2q + 1][x2q].second.first == "Nilll"))
												{
													prov = true;
												}
											}
											if (y2q == 0)
											{
												arrays[y1q][x1q] = blackqueen;
											}
										}

										if ((arrays[y2q][x2q].second.first == blackking.second.first) && (prov == true))
										{
											chblack = 1;
										}
										if ((arrays[y2q][x2q].second.first == whiteking.second.first) && (prov == true))
										{
											chwhite = 1;
										}

										if (prov == true)
										{
											arrays[y2q][x2q] = arrays[y1q][x1q];
											arrays[y1q][x1q] = Nill;
											arrays[y2q][x2q].first.setColor(Color::White);
										}
										else
										{
											numbersClick--;
										}
									}
									for (int i = 0; i < 8; i++)
									{
										for (int j = 0; j < 8; j++)
										{
											arrays[j][i].first.setPosition(i*koef + 25, j*koef + 25);
											window.draw(arrays[i][j].first);
										}
									}


								}
								if (chblack == 1)
								{
									window.close();
								}
								if (chwhite == 1)
								{
									window.close();
								}
							}
							printf("%d %d %d %d %d\n", mousePos1.x, mousePos1.y, numbersClick, chblack, chwhite);
							numbersClick++;
						}
					}

				if (event.type == Event::Closed)
					window.close();
				window.display();
			}
			if ((chblack == 1) || (chwhite == 1))
			{
				RenderWindow window1(VideoMode(650, 650), "Win");
				while (window1.isOpen())
				{
					Event event1;
					while (window1.pollEvent(event1))
					{
						if (event1.type == Event::Closed)
							window1.close();
					}

					window1.clear();
					if (chwhite == 1)
						window1.draw(BlackWin);
					if (chblack == 1)
						window1.draw(WhiteWin);
					window1.display();
				}
			}
			return 0;
		}











































































































































































#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <cmath>

using namespace std;
using namespace sf;

const int pr = 100;

Sprite add(string str)
{
	Image *image = new Image();
	Texture *texture = new Texture();
	Sprite *sprite = new Sprite();
	image->loadFromFile(str);
	texture->loadFromImage(*image);
	sprite->setTexture(*texture);
	return *sprite;
}


/*bool check_kill_white(int x1q, int x2q, int y1q, int y2q, pair<Sprite, String> checkers[10][10])
{
String b = "black_checker";
String w = "white_checker";
String n = "null";
String bq = "black_queen";
String wq = "white_queen";
if (checkers[x2q][y2q].second == n && checkers[abs(x2q - x1q)][abs(y2q - y1q)].second == b && abs(x2q - x1q) == abs(y2q - y1q) == 2)
return true;
else
return false;
}*/
bool check_quin(int y1, int x1, int y2, int x2)
{
	if (abs(y1 - y2) == abs(x1 - x2))
		return true;
	else
		return false;
}

bool check_white_step(int x1q, int y1q, int x2q, int y2q)
{
	if (abs(x1q - x2q) == 1 && y2q == y1q - 1)
		return true;
	else
		return false;
}
bool check_black_step(int x1q, int y1q, int x2q, int y2q)
{
	if (abs(x1q - x2q) == 1 && y1q == y2q - 1)
		return true;
	else
		return false;
}

int main()
{
	RenderWindow window(sf::VideoMode(9 * pr, 9 * pr), "Checkers", Style::Close);
	Font font;
	font.loadFromFile("Nautilus.otf");
	Text text("", font, 40);
	text.setColor(Color::Yellow);

	String arrL[8] = { "A","B","C","D","E","F","G","H" };
	String arrN[8] = { "1","2","3","4","5","6","7","8" };

	Sprite background = add("images/background.png");
	Sprite black_square = add("images/black_square.png");
	Sprite white_square = add("images/white_square.png");
	Sprite field[9][9];
	for (int i = 1; i < 9; i++)
	{
		for (int j = 1; j < 9; j++)
		{
			if ((i + j) % 2 == 0)
			{
				white_square.setPosition((float)i*pr - 50, (float)j*pr - 50);
				field[i][j] = white_square;
			}
			else
			{
				black_square.setPosition((float)i*pr - 50, (float)j*pr - 50);
				field[i][j] = black_square;
			}
		}
	}


	Sprite black_checker = add("images/black_checker.png");
	Sprite white_checker = add("images/white_checker.png");
	Sprite null = add("images/null.png");
	Sprite black_queen = add("images/black_queen.png");
	Sprite white_queen = add("images/white_queen.png");
	Sprite black_is_win = add("images/black_is_win.png");
	Sprite white_is_win = add("images/white_is_win.png");
	Sprite backgr = add("images/bckgr.png");

	String b = "black_checker";
	String w = "white_checker";
	String n = "null";
	String q = "queen";
	String blackf = "black";
	String whitef = "white";

	pair<String, String> colorWq(w, q);
	pair<String, String> colorBq(b, q);
	pair<String, String> colorW(w, w);
	pair<String, String> colorB(b, b);
	pair<String, String>  nl(n, n);

	pair<Sprite, pair<String, String>> black(black_checker, colorB);
	pair<Sprite, pair<String, String>> white(white_checker, colorW);
	pair<Sprite, pair<String, String>> nill(null, nl);
	pair<Sprite, pair<String, String>> black_q(black_queen, colorBq);
	pair<Sprite, pair<String, string>> white_q(white_queen, colorWq);

	pair<Sprite, pair<String, String>> checkers[10][10];
	for (int i = 1; i < 9; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			if ((i + j) % 2 == 1)
			{
				black_checker.setPosition((float)i*pr - 50, (float)j*pr - 50);
				checkers[i][j].first = black_checker;
				checkers[i][j].second.first = b;
			}
			else
			{
				null.setPosition((float)i*pr, (float)j*pr);
				checkers[i][j].first = null;
				checkers[i][j].second.first = n;
			}
		}
		for (int j = 4; j < 6; j++)
		{
			null.setPosition((float)i*pr, (float)j*pr);
			checkers[i][j].first = null;
			checkers[i][j].second.first = n;
		}
		for (int j = 6; j < 9; j++)
		{
			if ((i + j) % 2 == 1)
			{
				white_checker.setPosition((float)i*pr - 50, (float)j*pr - 50);
				checkers[i][j].first = white_checker;
				checkers[i][j].second.first = w;
			}
			else
			{
				null.setPosition((float)i*pr, (float)j*pr);
				checkers[i][j].first = null;
				checkers[i][j].second.first = n;
			}
		}
	}

	int click = 1;
	int a = 0;
	int x1 = 0;
	int y1 = 0;

	int x2 = 0;
	int y2 = 0;

	int schW = 0;
	int schB = 0;
	int x1q = 0, x2q = 0, y1q = 0, y2q = 0;
	while (window.isOpen())
	{
		window.setFramerateLimit(60);
		schW = 0;
		schB = 0;

		for (int i = 1; i < 9; i++)
		{
			for (int j = 1; j < 9; j++)
			{
				if (checkers[i][j].second.first == w || checkers[i][j].second.second == q && checkers[i][j].second.first == w)
					schW++;
				if (checkers[i][j].second.first == b || checkers[i][j].second.second == q && checkers[i][j].second.first == b)
					schB++;
			}
		}
		if (schB == 0)
		{
			window.draw(backgr);
			white_is_win.setPosition(0, 200);
			window.draw(white_is_win);
		}
		if (schW == 0)
		{
			window.draw(backgr);
			window.draw(black_is_win);
		}
		window.display();
		Vector2i pixelPos = Mouse::getPosition(window);

		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed)
			{
				if (pixelPos.x > 50 && pixelPos.x < 850 && pixelPos.y < 850 && pixelPos.y>50)
				{
					if (click % 2 == 1)
					{
						x1 = pixelPos.x;
						y1 = pixelPos.y;
					}
					else
					{
						x2 = pixelPos.x;
						y2 = pixelPos.y;
					}

					x1q = (x1 - 50) / 100 + 1;
					y1q = (y1 - 50) / 100 + 1;

					x2q = (x2 - 50) / 100 + 1;
					y2q = (y2 - 50) / 100 + 1;
				}
				if (((checkers[x1q][y1q].second.first != n) && ((checkers[x1q][y1q].second.first == w) || (checkers[x1q][y1q].second.first == q)) && ((click % 4 == 1) || (click % 4 == 2))) || ((checkers[x1q][y1q].second.first != n) && (checkers[x1q][y1q].second.first == b || checkers[x1q][y1q].second.first == q) && ((click % 4 == 3) || (click % 4 == 0))))  //( (click % 4 == 1 && (checkers[x1q][y1q].second == w) && checkers[x2q][y2q].second == w) ||  (click % 4 == 1 && (checkers[x1q][y1q].second == w)) || ( (click % 4 == 2) && (checkers[x1q][y1q].second == w) ) || (click % 4 == 3 && (checkers[x1q][y1q].second == b)) || (click % 4 == 0 && checkers[x1q][y1q].second == b) )
				{
					if (event.key.code == Mouse::Left)
					{
						a = click % 2;
						printf(" %d %d %d %d \n", click, pixelPos.x, pixelPos.y, a);

						checkers[x1q][y1q].first.setColor(Color::Red);

						if (click % 2 == 0)
						{

							if (checkers[x2q][y2q].second.first == checkers[x1q][y1q].second.first)
							{
								x1 = x2;
								y1 = y2;
								checkers[x1q][y1q].first.setColor(Color::White);
								checkers[x2q][y2q].first.setColor(Color::Red);
								click--;
							}
							if (checkers[x2q][y2q].second.first != n && (checkers[x1q][y1q].second.first == w &&  checkers[x2q][y2q].second.first == b) || (checkers[x1q][y1q].second.first == b &&  checkers[x2q][y2q].second.first == w))
								click--;
							if (checkers[x2q][y2q].second.first == n)
							{
								if (checkers[x1q][y1q].second.first == w)
								{
									if (checkers[x1q - 1][y1q - 1].second.first == b && checkers[x1q - 2][y1q - 2].second.first == n && x2q == x1q - 2 && y2q == y1q - 2 && checkers[x1q][y1q].second.second != q)
									{

										checkers[x1q - 1][y1q - 1] = nill;
										white.first.setPosition((float)x2q * 100 - 50, (float)y2q * 100 - 50);
										checkers[x2q][y2q] = white;
										checkers[x1q][y1q] = nill;
										if (y2q == 1)
										{
											white_q.first.setPosition((float)x2q * 100 - 50, (float)y2q * 100 - 50);
											checkers[x2q][y2q] = white_q;
										}
										click++;
									}
									if (checkers[x1q + 1][y1q - 1].second.first == b && checkers[x1q + 2][y1q - 2].second.first == n && x2q == x1q + 2 && y2q == y1q - 2 && checkers[x1q][y1q].second.second != q)
									{
										checkers[x2q - 1][y2q + 1] = nill;
										white.first.setPosition((float)x2q * 100 - 50, (float)y2q * 100 - 50);
										checkers[x2q][y2q] = white;
										checkers[x1q][y1q] = nill;
										if (y2q == 1)
										{
											white_q.first.setPosition((float)x2q * 100 - 50, (float)y2q * 100 - 50);
											checkers[x2q][y2q] = white_q;
										}
										click++;
									}
									if (checkers[x1q - 1][y1q + 1].second.first == b && checkers[x1q - 2][y1q + 2].second.first == n && x2q == x1q - 2 && y2q == y1q + 2 && checkers[x1q][y1q].second.second != q)
									{
										checkers[x1q - 1][y1q + 1] = nill;
										white.first.setPosition((float)x2q * 100 - 50, (float)y2q * 100 - 50);
										checkers[x2q][y2q] = white;
										checkers[x1q][y1q] = nill;
										click++;
									}
									if (checkers[x1q + 1][y1q + 1].second.first == b && checkers[x1q + 2][y1q + 2].second.first == n && x2q == x1q + 2 && y2q == y1q + 2 && checkers[x1q][y1q].second.second != q)
									{
										checkers[x1q + 1][y1q + 1] = nill;
										white.first.setPosition((float)x2q * 100 - 50, (float)y2q * 100 - 50);
										checkers[x2q][y2q] = white;
										checkers[x1q][y1q] = nill;
										click++;
									}
									if (check_quin(x1q, y1q, x2q, y2q) == true && checkers[x1q][y1q].second.second == q)
									{
										checkers[x1q][y1q] = nill;
										white_q.first.setPosition((float)x2q * 100 - 50, (float)y2q * 100 - 50);
										checkers[x2q][y2q] = white_q;
										click++;
									}
									if (check_white_step(x1q, y1q, x2q, y2q) == true && checkers[x1q][y1q].second.second != q)
									{
										checkers[x1q][y1q] = nill;
										white.first.setPosition((float)x2q * 100 - 50, (float)y2q * 100 - 50);
										checkers[x2q][y2q] = white;
										if (y2q == 1)
										{
											white_q.first.setPosition((float)x2q * 100 - 50, (float)y2q * 100 - 50);
											checkers[x2q][y2q] = white_q;
										}
									}
									else click--;


								}
								if (checkers[x1q][y1q].second.first == b)
								{
									if (checkers[x1q - 1][y1q + 1].second.first == w && checkers[x1q - 2][y1q + 2].second.first == n && x2q == x1q - 2 && y2q == y1q + 2 && checkers[x1q][y1q].second.second != q)
									{
										checkers[x1q - 1][y1q + 1] = nill;
										black.first.setPosition((float)x2q * 100 - 50, (float)y2q * 100 - 50);
										checkers[x2q][y2q] = black;
										checkers[x1q][y1q] = nill;
										if (y2q == 8)
										{
											black_q.first.setPosition((float)x2q * 100 - 50, (float)y2q * 100 - 50);
											checkers[x2q][y2q] = black_q;
										}
										click++;
									}
									if (checkers[x1q + 1][y1q + 1].second.first == w && checkers[x1q + 2][y1q + 2].second.first == n && x2q == x1q + 2 && y2q == y1q + 2 && checkers[x1q][y1q].second.second != q)
									{
										checkers[x1q + 1][y1q + 1] = nill;
										black.first.setPosition((float)x2q * 100 - 50, (float)y2q * 100 - 50);
										checkers[x2q][y2q] = black;
										checkers[x1q][y1q] = nill;
										if (y2q == 8)
										{
											black_q.first.setPosition((float)x2q * 100 - 50, (float)y2q * 100 - 50);
											checkers[x2q][y2q] = black_q;
										}
										click++;
									}
									if (checkers[x1q - 1][y1q - 1].second.first == w && checkers[x1q - 2][y1q - 2].second.first == n && x2q == x1q - 2 && y2q == y1q - 2 && checkers[x1q][y1q].second.second != q)
									{
										checkers[x1q - 1][y1q - 1] = nill;
										black.first.setPosition((float)x2q * 100 - 50, (float)y2q * 100 - 50);
										checkers[x2q][y2q] = black;
										checkers[x1q][y1q] = nill;
										click++;
									}
									if (checkers[x1q + 1][y1q - 1].second.first == w && checkers[x1q + 2][y1q - 2].second.first == n && x2q == x1q + 2 && y2q == y1q - 2 && checkers[x1q][y1q].second.second != q)
									{
										checkers[x1q + 1][y1q - 1] = nill;
										black.first.setPosition((float)x2q * 100 - 50, (float)y2q * 100 - 50);
										checkers[x2q][y2q] = black;
										checkers[x1q][y1q] = nill;
										click++;
									}
									if (check_quin(x1q, y1q, x2q, y2q) == true && checkers[x1q][y1q].second.second == q)
									{
										checkers[x1q][y1q] = nill;
										black_q.first.setPosition((float)x2q * 100 - 50, (float)y2q * 100 - 50);
										checkers[x2q][y2q] = black_q;

										click++;
									}
									if (check_black_step(x1q, y1q, x2q, y2q) == true && checkers[x1q][y1q].second.second != q)
									{
										checkers[x1q][y1q] = nill;
										black.first.setPosition((float)x2q * 100 - 50, (float)y2q * 100 - 50);
										checkers[x2q][y2q] = black;
										if (y2q == 8)
										{
											black_q.first.setPosition((float)x2q * 100 - 50, (float)y2q * 100 - 50);
											checkers[x2q][y2q] = black_q;
										}
									}
									else click--;
								}
							}
						}
						click++;
					}

				}
			}
			if (event.type == Event::Closed)
				window.close();

		}

		window.clear();


		window.draw(background);

		for (int i = 1; i < 9; i++)
		{
			for (int j = 1; j < 9; j++)
			{
				window.draw(field[i][j]);
			}
		}

		for (int i = 1; i < 9; i++)
		{
			for (int j = 1; j < 9; j++)
			{
				window.draw(checkers[i][j].first);
			}
		}

		float x = 80;
		float y = 0;
		for (int i = 0; i < 8; i++)
		{
			text.setString(arrL[i]);
			text.setPosition(x, y);
			x = x + pr;
			window.draw(text);
		}

		x = 10;
		y = 80;
		for (int i = 0; i < 8; i++)
		{
			text.setString(arrN[i]);
			text.setPosition(x, y);
			y = y + pr;
			window.draw(text);
		}
	}

	return 0;
}
















using namespace sf;

////////////////////////////////////////////////////КЛАСС ИГРОКА////////////////////////
class Player {
	/* это задел на следующие уроки,прошу не обращать внимания)
	private: float w, h, dx, dy, x, y, speed;
	int dir, playerScore, health;
	bool life;
	*/
public:
	float w, h, dx, dy, x, y, speed;
	int dir, playerScore, health;
	bool life;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;
	Player(Sprite F, float X, float Y, float W, float H) {
		dir = 0; speed = 0; playerScore = 0; health = 100; dx = 0; dy = 0;
		life = true;
		//File = F;
		w = W; h = H;
		//image.loadFromFile("images/" + File);
		image.createMaskFromColor(Color(41, 33, 59));
		//texture.loadFromImage(image);
		//sprite.setTexture(texture);
		sprite = F;
		x = X; y = Y;
		sprite.setTextureRect(IntRect(0, 0, w, h));
	}
	void update(float time)
	{
		switch (dir)
		{
		case 0: dx = speed; dy = 0; break;
		case 1: dx = -speed; dy = 0; break;
		case 2: dx = 0; dy = speed; break;
		case 3: dx = 0; dy = -speed; break;
		}

		x += dx*time;
		y += dy*time;
		speed = 0;
		sprite.setPosition(x, y);
		sprite.setOrigin(w / 2, h / 2);
		interactionWithMap();
		if (health <= 0) { life = false; }

	}

	float getWidth() {//получить ширину объека
		return w;
	}
	void setWidth(float width) {//установить ширину объекта
		w = width;
	}

	float getHeight() {//взять ширину объекта
		return h;
	}
	void setHeight(float height) {//задать ширину объекта
		h = height;
	}

	float getplayercoordinateX() {
		return x;
	}
	float getplayercoordinateY() {
		return y;
	}




	void interactionWithMap()
	{

		for (int i = y / 32; i < (y + h) / 32; i++)
			for (int j = x / 32; j<(x + w) / 32; j++)
			{
				if (TileMap[i][j] == '0')
				{
					if (dy>0)
					{
						y = i * 32 - h;
					}
					if (dy<0)
					{
						y = i * 32 + 32;
					}
					if (dx>0)
					{
						x = j * 32 - w;
					}
					if (dx < 0)
					{
						x = j * 32 + 32;
					}
				}

				if (TileMap[i][j] == 's') {
					playerScore++;
					TileMap[i][j] = ' ';
				}

				if (TileMap[i][j] == 'f') {
					health -= 40;
					TileMap[i][j] = ' ';
				}

				if (TileMap[i][j] == 'h') {
					health += 20;
					TileMap[i][j] = ' ';
				}

			}
	}

};

class SpriteManager {//это задел на следующие уроки,прошу не обращать внимания на эти изменения)
public:
	Image image;
	Texture texture;
	Sprite sprite;
	String name;
	String file;
	int widthOfSprite;
	int heightOfSprite;
	SpriteManager(String File, String Name) {
		file = File;
		name = Name;
		image.loadFromFile("images/" + file);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
	}
};


int main()
{


	RenderWindow window(VideoMode(640, 480), "Lesson 17. kychka-pc.ru");
	view.reset(FloatRect(0, 0, 640, 480));

	Font font;
	font.loadFromFile("CyrilicOld.ttf");
	Text text("", font, 20);
	text.setColor(Color::Black);


	Image map_image;
	map_image.loadFromFile("images/map.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);

	Image quest_image;
	quest_image.loadFromFile("images/missionbg.jpg");
	quest_image.createMaskFromColor(Color(0, 0, 0));
	Texture quest_texture;
	quest_texture.loadFromImage(quest_image);
	Sprite s_quest;
	s_quest.setTexture(quest_texture);
	s_quest.setTextureRect(IntRect(0, 0, 340, 510));
	s_quest.setScale(0.6f, 0.6f);

	SpriteManager playerSprite("hero.png", "Hero");//это задел на следующие уроки,прошу не обращать внимания)

	Player p(playerSprite.sprite, 250, 250, 96.0, 96.0);

	float currentFrame = 0;
	Clock clock;
	bool isMove = false;//переменная для щелчка мыши по спрайту
	float dX = 0;//корректировка движения по х
	float dY = 0;//по у
	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMicroseconds();

		clock.restart();
		time = time / 800;

		Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
		Vector2f pos = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд окна)
		std::cout << pixelPos.x << "\n";//смотрим на координату Х позиции курсора в консоли (она не будет больше ширины окна)
		std::cout << pos.x << "\n";//смотрим на Х,которая преобразовалась в мировые координаты

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == Event::MouseButtonPressed)//если нажата клавиша мыши
				if (event.key.code == Mouse::Left)//а именно левая
					if (p.sprite.getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт
					{
						std::cout << "isClicked!\n";//выводим в консоль сообщение об этом
						dX = pos.x - p.sprite.getPosition().x;//делаем разность между позицией курсора и спрайта.для корректировки нажатия
						dY = pos.y - p.sprite.getPosition().y;//тоже самое по игреку
						isMove = true;//можем двигать спрайт							
					}
			if (event.type == Event::MouseButtonReleased)//если отпустили клавишу
				if (event.key.code == Mouse::Left) //а именно левую
					isMove = false; //то не можем двигать спрайт
			p.sprite.setColor(Color::White);//и даем ему прежний цвет
		}
		if (isMove) {//если можем двигать
			p.sprite.setColor(Color::Green);//красим спрайт в зеленый 
			p.x = pos.x - dX;//двигаем спрайт по Х
			p.y = pos.y - dY;//двигаем по Y
							 //p.sprite.setPosition(pos.x - dX, pos.y - dY);//можно и так написать,если у вас нету х и у
		}

		///////////////////////////////////////////Управление персонажем с анимацией////////////////////////////////////////////////////////////////////////
		if (p.life) {
			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				p.dir = 1; p.speed = 0.1;
				currentFrame += 0.005*time;
				if (currentFrame > 3) currentFrame -= 3;
				p.sprite.setTextureRect(IntRect(96 * int(currentFrame), 96, 96, 96));
			}

			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				p.dir = 0; p.speed = 0.1;
				currentFrame += 0.005*time;
				if (currentFrame > 3) currentFrame -= 3;
				p.sprite.setTextureRect(IntRect(96 * int(currentFrame), 192, 96, 96));
			}

			if (Keyboard::isKeyPressed(Keyboard::Up)) {
				p.dir = 3; p.speed = 0.1;
				currentFrame += 0.005*time;
				if (currentFrame > 3) currentFrame -= 3;
				p.sprite.setTextureRect(IntRect(96 * int(currentFrame), 307, 96, 96));
			}

			if (Keyboard::isKeyPressed(Keyboard::Down)) {
				p.dir = 2; p.speed = 0.1;

				currentFrame += 0.005*time;
				if (currentFrame > 3) currentFrame -= 3;
				p.sprite.setTextureRect(IntRect(96 * int(currentFrame), 0, 96, 96));
			}
			getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
		}


		p.update(time);


		window.setView(view);
		window.clear();



		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32));
				if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));
				if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32));
				if ((TileMap[i][j] == 'f')) s_map.setTextureRect(IntRect(96, 0, 32, 32));
				if ((TileMap[i][j] == 'h')) s_map.setTextureRect(IntRect(128, 0, 32, 32));
				s_map.setPosition(j * 32, i * 32);

				window.draw(s_map);
			}



		window.draw(p.sprite);


		window.display();
	}

	return 0;
}