////Врабий Артем, Домалега Владимир, Майненгер Герман ИП-915

#include <iostream>
#include <SFML/Graphics.hpp>
#include <conio.h>
#include "windows.h"
#include <string>
#include "tPoint.h"
#include <math.h>

using namespace std;

using namespace sf;



int main()
{



	srand(time(NULL));
	int a;
	tPoint Point(rand() % 1270, rand() % 700 + 10, rand() % 3 + 1, rand() % 2 + 1, rand() % 2 + 1, rand() % 3 + 1);
	circle round(rand() % 600+200, rand() % 300 + 100, rand() % 3 + 1, rand() % 2 + 1, rand() % 2 + 1, rand() % 3 + 1, rand() % 3 + 1);
	ellipce ellips(rand() % 600 + 200, rand() % 300 + 100, rand() % 3 + 1, rand() % 2 + 1, rand() % 2 + 1, rand() % 3 + 1, rand() % 3 + 1, rand() % 100, rand() % 100);
	section section(rand() % 600 + 200, rand() % 300 + 100, rand() % 3 + 1, rand() % 2 + 1, rand() % 2 + 1, rand() % 3 + 1, rand() % 100 + 20, rand() % 180);
	rectangle rectangle(rand() % 600 + 200, rand() % 300 + 100, rand() % 3 + 1, rand() % 2 + 1, rand() % 2 + 1, rand() % 3 + 1, rand() % 100 + 20, rand() % 180, rand() % 100 + 20);
	rhombus rhombus(rand() % 600 + 200, rand() % 300 + 100, rand() % 3 + 1, rand() % 2 + 1, rand() % 2 + 1, rand() % 3 + 1, rand() % 45 + 10, rand() % 45 + 10);
	triangle triangle(rand() % 600 + 200, rand() % 300 + 100, rand() % 3 + 1, rand() % 2 + 1, rand() % 2 + 1, rand() % 3 + 1, rand() % 45 + 10, rand() % 45 + 10, rand() % 45 + 10, rand() % 45 + 10);


	CircleShape dot;
	CircleShape Circle;
	ConvexShape ellipse;
	RectangleShape line(Vector2f(section.get_length(), 5));
	RectangleShape rectangl(Vector2f(rectangle.get_length(), rectangle.get_width()));
	ConvexShape rhomb;
	ConvexShape triangl;

	triangl.setPointCount(3);
	triangl.setPoint(0, Vector2f(triangle.get_x(), triangle.get_y()));
	triangl.setPoint(1, Vector2f(triangle.get_x()+ triangle.get_dxcor(), triangle.get_y()+ triangle.get_dycor()));
	triangl.setPoint(2, Vector2f(triangle.get_x()+ triangle.get_dxcor2(), triangle.get_y()+ triangle.get_dycor2()));
	if (triangle.get_color() == 1)
		triangl.setFillColor(Color::Red);
	if (triangle.get_color() == 2)
		triangl.setFillColor(Color::Blue);
	if (triangle.get_color() == 3)
		triangl.setFillColor(Color::Yellow);
	if (triangle.get_color() == 4)
		triangl.setFillColor(Color::Magenta);
	triangl.setPosition(triangle.get_x(), triangle.get_y());

	rhomb.setPointCount(4);
	rhomb.setPoint(0, Vector2f(rhombus.get_x(), rhombus.get_y()));
	rhomb.setPoint(1, Vector2f(rhombus.get_x()+rhombus.get_dxcor(), rhombus.get_y()+rhombus.get_dycor()));
	rhomb.setPoint(2, Vector2f(rhombus.get_x()+2*rhombus.get_dxcor(), rhombus.get_y()));
	rhomb.setPoint(3, Vector2f(rhombus.get_x()+rhombus.get_dxcor(), rhombus.get_y()-rhombus.get_dycor()));
	if (rhombus.get_color() == 1)
		rhomb.setFillColor(Color::Red);
	if (rhombus.get_color() == 2)
		rhomb.setFillColor(Color::Blue);
	if (rhombus.get_color() == 3)
		rhomb.setFillColor(Color::Yellow);
	if (rhombus.get_color() == 4)
		rhomb.setFillColor(Color::Magenta);
	rhomb.setPosition(rhombus.get_x(), rhombus.get_y());
	
	line.rotate(section.get_rotate());
	if (section.get_color() == 1)
		line.setFillColor(Color::Red);
	if (section.get_color() == 2)
		line.setFillColor(Color::Blue);
	if (section.get_color() == 3)
		line.setFillColor(Color::Yellow);
	if (section.get_color() == 4)
		line.setFillColor(Color::Magenta);
	line.setPosition(section.get_x(), section.get_y());

	if (rectangle.get_color() == 1)
		rectangl.setFillColor(Color::Red);
	if (rectangle.get_color() == 2)
		rectangl.setFillColor(Color::Blue);
	if (rectangle.get_color() == 3)
		rectangl.setFillColor(Color::Yellow);
	if (rectangle.get_color() == 4)
		rectangl.setFillColor(Color::Magenta);
	rectangl.setPosition(rectangle.get_x(), rectangle.get_y());

	ellipse.setPointCount(70);
	if (ellips.get_color() == 1)
		ellipse.setFillColor(Color::Red);
	if (ellips.get_color() == 2)
		ellipse.setFillColor(Color::Blue);
	if (ellips.get_color() == 3)
		ellipse.setFillColor(Color::Yellow);
	if (ellips.get_color() == 4)
		ellipse.setFillColor(Color::Magenta);
	for (unsigned short i = 0; i < 70; ++i) {
		float rad = (360 / 70 * i) / (360 / 3.14 / 2);
		float x = cos(rad) * ellips.get_smaxis();
		float y = sin(rad) * ellips.get_sminaxis();
		ellipse.setPoint(i, Vector2f(x, y));
	}
	ellipse.setPosition(ellips.get_x(), ellips.get_y());



	dot.setRadius(5.f);
	if (Point.get_color() == 1)
		dot.setFillColor(Color::Red);
	if (Point.get_color() == 2)
		dot.setFillColor(Color::Blue);
	if (Point.get_color() == 3)
		dot.setFillColor(Color::Yellow);
	if (Point.get_color() == 4)
		dot.setFillColor(Color::Magenta);
	dot.setPosition(Point.get_x(),Point.get_y());

	Circle.setRadius(15.f);
	Circle.setOutlineThickness(3.f);
	Circle.setFillColor(Color::Black);
	if (round.get_OLcolor() == 1)
		Circle.setOutlineColor(Color::Red);
	if (round.get_OLcolor() == 2)
		Circle.setOutlineColor(Color::Blue);
	if (round.get_OLcolor() == 3)
		Circle.setOutlineColor(Color::Yellow);
	if (round.get_OLcolor() == 4)
		Circle.setOutlineColor(Color::Magenta);
	Circle.setPosition(round.get_x(),round.get_y());


	
	





	setlocale(LC_ALL, "Russian");
	while (1) {
		system("cls");
		cout << "Пункт-1" << endl << "Пункт-2" << endl << "Выход-3";
		a = _getch();

		if (a == 49) {
			RenderWindow window(VideoMode(1280, 720), "1");

			while (window.isOpen())
			{
				Event event;
				while (window.pollEvent(event))
				{
					if (event.type == Event::Closed)
						window.close();
				}
				window.clear();

				
				Sleep(0.5);

				Point.str_moving();
				float x = Point.get_x();
				float y = Point.get_y();
				dot.setPosition(x, y);
				window.draw(dot);

				round.str_moving();
				float x2 = round.get_x();
				float y2 = round.get_y();
				Circle.setPosition(x2, y2);
				window.draw(Circle);

				ellips.str_moving();
				float x3 = ellips.get_x();
				float y3 = ellips.get_y();
				ellipse.setPosition(x3, y3);
				window.draw(ellipse);

				section.str_moving();
				float x4 = section.get_x();
				float y4 = section.get_y();
				line.setPosition(x4, y4);
				window.draw(line);

				rectangle.str_moving();
				float x5 = rectangle.get_x();
				float y5 = rectangle.get_y();
				rectangl.setPosition(x5, y5);
				window.draw(rectangl);

				rhombus.str_moving();
				float x6 = rhombus.get_x();
				float y6 = rhombus.get_y();
				rhomb.setPosition(x6, y6);
				window.draw(rhomb);

				triangle.str_moving();
				float x7 = triangle.get_x();
				float y7 = triangle.get_y();
				triangl.setPosition(x7, y7);
				window.draw(triangl);

				window.display();

			}
		}
		else if (a == 50) {
			RenderWindow window(VideoMode(1280, 720), "1");
			while (window.isOpen())
			{
				Event event;
				while (window.pollEvent(event))
				{
					if (event.type == Event::Closed)
						window.close();
				}
				Sleep(0.5);
				window.clear();


				Point.rand_moving();
				float x = Point.get_x();
				float y = Point.get_y();
				dot.setPosition(x, y);
				window.draw(dot);

				round.rand_moving();
				float x2 = round.get_x();
				float y2 = round.get_y();
				Circle.setPosition(x2, y2);
				window.draw(Circle);

				ellips.rand_moving();
				float x3 = ellips.get_x();
				float y3 = ellips.get_y();
				ellipse.setPosition(x3, y3);
				window.draw(ellipse);

				section.rand_moving();
				float x4 = section.get_x();
				float y4 = section.get_y();
				line.setPosition(x4, y4);
				window.draw(line);

				rectangle.rand_moving();
				float x5 = rectangle.get_x();
				float y5 = rectangle.get_y();
				rectangl.setPosition(x5, y5);
				window.draw(rectangl);

				rhombus.rand_moving();
				float x6 = rhombus.get_x();
				float y6 = rhombus.get_y();
				rhomb.setPosition(x6, y6);
				window.draw(rhomb);
				
				triangle.rand_moving();
				float x7 = triangle.get_x();
				float y7 = triangle.get_y();
				triangl.setPosition(x7, y7);
				window.draw(triangl);

				window.display();
			}
		}
		else
			break;

	}


}

