////Врабий Артем, Домалега Владимир, Майненгер Герман ИП-915
//
//#include <iostream>
//#include <SFML/Graphics.hpp>
//#include <conio.h>
//#include "windows.h"
//#include <string>
//#include "tPoint.h"
//
//using namespace std;
//
//using namespace sf;
//
//
//
//int main()
//{
//	srand(time(NULL));
//	int a;
//	string color = "Red";
//	tPoint first;
//	tPoint mas[100];
//	first.set_x(100);
//	first.set_y(15);
//	first.set_dir(4);
//	for (int i = 0; i < 100; i++)
//	{
//		mas[i].set_x(rand() % 1270);
//		mas[i].set_y(rand() % 700+10);
//		mas[i].set_dir(rand() % 3 + 1);
//		mas[i].set_dx(rand() % 2 + 1);
//		mas[i].set_dy(rand() % 2 + 1);
//		mas[i].set_color(rand() % 3 + 1);
//
//	}
//
//	
//	setlocale(LC_ALL, "Russian");
//	while (1) {
//		system("cls");
//		cout << "Пункт-1" << endl << "Пункт-2" << endl << "Выход-3";
//		a = _getch();
//
//		if (a == 49) {
//			RenderWindow window(VideoMode(1280, 720), "1");
//			CircleShape circle[100];
//			for (int i = 0; i < 100; i++) {
//				circle[i].setRadius(5.f);
//				if (mas[i].get_color() == 1)
//					circle[i].setFillColor(Color::Red);
//				if (mas[i].get_color() == 2)
//					circle[i].setFillColor(Color::Blue);
//				if (mas[i].get_color() == 3)
//					circle[i].setFillColor(Color::Yellow);
//				if (mas[i].get_color() == 4)
//					circle[i].setFillColor(Color::Magenta);
//				circle[i].setPosition(rand()%500+200, rand()%200+150);
//			}
//			
//				
//			while (window.isOpen())
//			{
//				Event event;
//				while (window.pollEvent(event))
//				{
//					if (event.type == Event::Closed)
//						window.close();
//				}
//				window.clear();
//				for (int i = 0; i < 100; i++) {
//					
//					mas[i].str_moving();
//					float x = mas[i].get_x();
//					float y = mas[i].get_y();
//					circle[i].setPosition(x, y);	
//
//					window.draw(circle[i]);
//				}
//				window.display();
//			}
//		}
//		else if (a == 50) {
//			RenderWindow window(VideoMode(1280, 720), "1");
//			CircleShape circle[100];
//			for (int i = 0; i < 100; i++) {
//				circle[i].setRadius(5.f);
//				if (mas[i].get_color() == 1)
//				circle[i].setFillColor(Color::Red);
//				if (mas[i].get_color() == 2)
//					circle[i].setFillColor(Color::Blue);
//				if (mas[i].get_color() == 3)
//					circle[i].setFillColor(Color::Yellow);
//				if (mas[i].get_color() == 4)
//					circle[i].setFillColor(Color::Magenta);
//
//				circle[i].setPosition(rand() % 500 + 200, rand() % 200 + 150);
//			}
//
//
//			while (window.isOpen())
//			{
//				Event event;
//				while (window.pollEvent(event))
//				{
//					if (event.type == Event::Closed)
//						window.close();
//				}
//				Sleep(0.5);
//				window.clear();
//				for (int i = 0; i < 100; i++) {
//
//					mas[i].rand_moving();
//					float x = mas[i].get_x();
//					float y = mas[i].get_y();
//					circle[i].setPosition(x, y);
//
//					window.draw(circle[i]);
//				}
//				window.display();
//			}
//		}
//		else
//			break;
//
//	}
//
//
//}
//


//tPoint Point(rand() % 1270, rand() % 700 + 10, rand() % 3 + 1, rand() % 2 + 1, rand() % 2 + 1, rand() % 3 + 1);
//circle round(rand() % 600 + 200, rand() % 300 + 100, rand() % 3 + 1, rand() % 2 + 1, rand() % 2 + 1, rand() % 3 + 1, rand() % 3 + 1);
//ellipce ellips(rand() % 600 + 200, rand() % 300 + 100, rand() % 3 + 1, rand() % 2 + 1, rand() % 2 + 1, rand() % 3 + 1, rand() % 3 + 1, rand() % 100, rand() % 100);
//section section(rand() % 600 + 200, rand() % 300 + 100, rand() % 3 + 1, rand() % 2 + 1, rand() % 2 + 1, rand() % 3 + 1, rand() % 100 + 20, rand() % 180);
//rectangle rectangle(rand() % 600 + 200, rand() % 300 + 100, rand() % 3 + 1, rand() % 2 + 1, rand() % 2 + 1, rand() % 3 + 1, rand() % 100 + 20, rand() % 180, rand() % 100 + 20);
//rhombus rhombus(rand() % 600 + 200, rand() % 300 + 100, rand() % 3 + 1, rand() % 2 + 1, rand() % 2 + 1, rand() % 3 + 1, rand() % 45 + 10, rand() % 45 + 10);
//triangle triangle(rand() % 600 + 200, rand() % 300 + 100, rand() % 3 + 1, rand() % 2 + 1, rand() % 2 + 1, rand() % 3 + 1, rand() % 45 + 10, rand() % 45 + 10, rand() % 45 + 10, rand() % 45 + 10);