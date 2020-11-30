//Врабий Артем, Домалега Владимир, Майненгер Герман ИП-915

#include <iostream>
#include <SFML/Graphics.hpp>
#include <conio.h>
#include "windows.h"
#include <string>

using namespace std;

using namespace sf;

class tPoint {
private:
	int x;
	int y;
	int dx;
	int dy;
	int direction;
	int color;
	
public:
	void set_x(int a) {
		x = a;
	}
	void set_y(int a) {
		y = a;
	}
	void set_dx(int a) {
		dx = a;
	}
	void set_dy(int a) {
		dy = a;
	}
	void set_dir(int a) {
		direction = a;
	}
	void set_color(int a) {
		color = a;
	}
	float get_x() {
		return x;
	}
	float get_y() {
		return y;
	}
	int get_dx() {
		return dx;
	}
	int get_dy() {
		return dy;
	}
	int get_dir() {
		return direction;
	}
	int get_color() {
		return color;
	}

	void str_moving() {


		if (get_dir() == 1) {
			set_x(get_x() + 1);
			if (get_x() > 1270) 
				set_dir(2);			
		} 
		else if (get_dir() == 2){
			set_x(get_x() - 1);
			if (get_x() < 0) 
				set_dir(1);
		}
		else if (get_dir() == 3) {
			set_y(get_y() + 1);
			if (get_y() > 710) 
				set_dir(4);
		}
		else {		
			set_y(get_y() - 1);
			if (get_y() < 10) 
				set_dir(3);

		}
		

	}

	void rand_moving() {

		if (get_dx() == 1)
		{
			set_x(get_x() + 1);
			if (get_x() > 1270)
				set_dx(2);
			int a = rand() % 200;
			if (a == 1)
				set_dx(2);
			if (a == 2)
				set_dx(0);
		}
		if (get_dx() == 2)
		{
			set_x(get_x() - 1);
			if (get_x() < 0)
				set_dx(1);
			int a = rand() % 200;
			if (a == 1)
				set_dx(1);
			if (a == 2)
				set_dx(0);
		}
		if (get_dx() == 0)
		{
			int a = rand() % 200;
			if (a == 1)
				set_dx(1);
			if (a == 2)
				set_dx(2);
			
		}

		if (get_dy() == 1)
		{
			set_y(get_y() + 1);
			if (get_y() > 710)
				set_dy(2);
			int a = rand() % 200;
			if (a == 1)
				set_dy(2);
			if (a == 2)
				set_dy(0);
		}
		if (get_dy() == 2)
		{
			set_y(get_y() - 1);
			if (get_y() < 0)
				set_dy(1);
			int a = rand() % 200;
			if (a == 1)
				set_dy(1);
			if (a == 2)
				set_dy(0);
		}
		if (get_dy() == 0)
		{
			int a = rand() % 200;
			if (a == 1)
				set_dy(1);
			if (a == 2)
				set_dy(2);
		}

		


	}
};

int main()
{
	srand(time(NULL));
	int a;
	string color = "Red";
	tPoint first;
	tPoint mas[100];
	first.set_x(100);
	first.set_y(15);
	first.set_dir(4);
	for (int i = 0; i < 100; i++)
	{
		mas[i].set_x(rand() % 1270);
		mas[i].set_y(rand() % 700+10);
		mas[i].set_dir(rand() % 3 + 1);
		mas[i].set_dx(rand() % 2 + 1);
		mas[i].set_dy(rand() % 2 + 1);
		mas[i].set_color(rand() % 3 + 1);

	}

	
	setlocale(LC_ALL, "Russian");
	while (1) {
		system("cls");
		cout << "Пункт-1" << endl << "Пункт-2" << endl << "Выход-3";
		a = _getch();

		if (a == 49) {
			RenderWindow window(VideoMode(1280, 720), "1");
			CircleShape circle[100];
			for (int i = 0; i < 100; i++) {
				circle[i].setRadius(5.f);
				if (mas[i].get_color() == 1)
					circle[i].setFillColor(Color::Red);
				if (mas[i].get_color() == 2)
					circle[i].setFillColor(Color::Blue);
				if (mas[i].get_color() == 3)
					circle[i].setFillColor(Color::Yellow);
				if (mas[i].get_color() == 4)
					circle[i].setFillColor(Color::Magenta);
				circle[i].setPosition(rand()%500+200, rand()%200+150);
			}
			
				
			while (window.isOpen())
			{
				Event event;
				while (window.pollEvent(event))
				{
					if (event.type == Event::Closed)
						window.close();
				}
				window.clear();
				for (int i = 0; i < 100; i++) {
					
					mas[i].str_moving();
					float x = mas[i].get_x();
					float y = mas[i].get_y();
					circle[i].setPosition(x, y);	

					window.draw(circle[i]);
				}
				window.display();
			}
		}
		else if (a == 50) {
			RenderWindow window(VideoMode(1280, 720), "1");
			CircleShape circle[100];
			for (int i = 0; i < 100; i++) {
				circle[i].setRadius(5.f);
				if (mas[i].get_color() == 1)
				circle[i].setFillColor(Color::Red);
				if (mas[i].get_color() == 2)
					circle[i].setFillColor(Color::Blue);
				if (mas[i].get_color() == 3)
					circle[i].setFillColor(Color::Yellow);
				if (mas[i].get_color() == 4)
					circle[i].setFillColor(Color::Magenta);

				circle[i].setPosition(rand() % 500 + 200, rand() % 200 + 150);
			}


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
				for (int i = 0; i < 100; i++) {

					mas[i].rand_moving();
					float x = mas[i].get_x();
					float y = mas[i].get_y();
					circle[i].setPosition(x, y);

					window.draw(circle[i]);
				}
				window.display();
			}
		}
		else
			break;

	}


}

