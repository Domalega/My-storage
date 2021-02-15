#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h> 

using namespace sf;
using namespace std;

// Базовый абстрактный полиморфный класс небесных тел
class CelestialBody {

public:
	CircleShape celestialBodyForm = CircleShape();

	void SetName(string _name) {
		name = _name;
	}

	void IncreaseAngle() {
		angle += deltaAngle;
	}

	float GetX() {
		return x;
	}

	float GetY() {
		return y;
	}

protected:
	float radiusPlanet, x, y, xOrigin, yOrigin, rOrbit, deltaAngle, angle = 0, radianAngle;
	string name;

protected:
	//Конструктор
	CelestialBody(Color color, float _radiusPlanet, float _xOrigin, float _yOrigin, float _rOrbit, float _x, float _y, float _deltaAngle) {
		x = _x;
		y = _y;
		xOrigin = _xOrigin; 
		yOrigin = _yOrigin;
		rOrbit = _rOrbit;
		radiusPlanet = _radiusPlanet;
		deltaAngle = _deltaAngle;
		celestialBodyForm.setOrigin(_radiusPlanet / 2, _radiusPlanet / 2);
		celestialBodyForm.setPosition(_x, _y);
		celestialBodyForm.setRadius(_radiusPlanet);
		celestialBodyForm.setFillColor(color);
	}

	virtual void GetValue() = 0;
};

// Производный класс звезд
class Star : public CelestialBody {

public:
	//Конструктор
	Star(Color color, float radius, float xOrigin, float yOrigin, float rOrbit, float x, float y, float deltaAngle) : CelestialBody(color, radius, xOrigin, yOrigin, rOrbit, x, y, deltaAngle) {}

	//Реализация вертуального метода
	void GetValue() {
		cout << "Radius of " << name << " " << radiusPlanet << " and angle change rate is " << deltaAngle << endl;
	}
	
	void UpdateCoordinates() {
		x = xOrigin + -radiusPlanet / 2;
		y = yOrigin + -radiusPlanet / 2;
		celestialBodyForm.setPosition(x, y);
	}
};

// Производный класс планет
class Planet : public CelestialBody {

public:
	//Конструктор
	Planet(Color color, float radius, float xOrigin, float yOrigin, float rOrbit, float x, float y, float deltaAngle) : CelestialBody(color, radius, xOrigin, yOrigin, rOrbit, x, y, deltaAngle) {}

	//Реализация вертуального метода
	void GetValue() {
		cout << "Radius of " << name << " " <<  radiusPlanet << " and angle change rate is " << deltaAngle << endl;
	}

	//Метод передвижения для планет
	void UpdateCoordinates() {
		radianAngle = angle / 100;
		x = xOrigin + (rOrbit * sin(radianAngle)) - radiusPlanet / 2;
		y = yOrigin + (rOrbit * cos(radianAngle)) - radiusPlanet / 2;
		celestialBodyForm.setPosition(x, y);
	}
};

// Производный класс спутников
class Satellite : public CelestialBody {

public:
	//Конструктор
	Satellite(Color color, float radius, float xOrigin, float yOrigin, float rOrbit, float x, float y, float deltaAngle) : CelestialBody(color, radius, xOrigin, yOrigin, rOrbit, x, y, deltaAngle) {}

	//Реализация вертуального метода
	void GetValue() {
		cout << "Radius of " << name << " " << radiusPlanet << " and angle change rate is " << deltaAngle << endl;
	}

	//Метод передвижения для спутников
	void UpdateCoordinates(Planet planet) {
		radianAngle = -angle / 100;
		x = planet.GetX() + (rOrbit * cos(radianAngle)) + radiusPlanet;
		y = planet.GetY() + (rOrbit * sin(radianAngle)) + radiusPlanet;
		celestialBodyForm.setPosition(x, y);
	}
};

// Класс орбит
class Orbit {

public:
	CircleShape orbitForm = CircleShape();

	//Конструктор
	Orbit(float _xOrigin, float _yOrigin, float _rOrbit) {
		xOrigin = _xOrigin; 
		yOrigin = _yOrigin;
		rOrbit = _rOrbit;
		orbitForm.setOrigin(rOrbit / 2, rOrbit / 2);
		orbitForm.setPosition(xOrigin - rOrbit / 2, xOrigin - rOrbit / 2);
		orbitForm.setRadius(rOrbit);
		orbitForm.setOutlineThickness(1);
		orbitForm.setFillColor(Color::Black);
		orbitForm.setOutlineColor(Color::White);
	}

	float GetRadius() {
		return rOrbit;
	}

protected:
	float xOrigin, yOrigin, rOrbit;
};

// Производный класс орбит спутников
class SateliteOrbit : public Orbit {

public:
	//Конструктор
	SateliteOrbit(float _xOrigin, float _yOrigin, float _rOrbit) : Orbit(_xOrigin, _yOrigin, _rOrbit) {}

	//Метод для передвижения спутников по орбитам
	void Update(Planet planet) {
		orbitForm.setPosition(planet.GetX() - rOrbit / 5, planet.GetY() - rOrbit / 5);
	}
};

int main() {

	float centerOfScreen[2] = {500, 500};
	RenderWindow window(VideoMode(1000, 1000), "Solar system");

	Star sun = Star(Color(170, 170, 0, 255), 10.f, centerOfScreen[0], centerOfScreen[1], 0, 0, 0, 0);
	sun.SetName("sun");
	sun.GetValue();

	Orbit mercuryOrbit = Orbit(centerOfScreen[0], centerOfScreen[1], 20.f);
	Planet mercury = Planet(Color(170, 170, 170, 255), 6.f, centerOfScreen[0], centerOfScreen[1], mercuryOrbit.GetRadius(), centerOfScreen[0] + mercuryOrbit.GetRadius() - 8.f / 2, centerOfScreen[1], 0.038);
	mercury.SetName("mercury");
	mercury.GetValue();

	Orbit venusOrbit = Orbit(centerOfScreen[0], centerOfScreen[1], 40.f);
	Planet venus = Planet(Color(0, 0, 255, 255), 8.f, centerOfScreen[0], centerOfScreen[1], venusOrbit.GetRadius(), centerOfScreen[0] + venusOrbit.GetRadius() - 12.f / 2, centerOfScreen[1], 0.033);
	venus.SetName("venus");
	venus.GetValue();

	Orbit earthOrbit = Orbit(centerOfScreen[0], centerOfScreen[1], 80.f);
	Planet earth = Planet(Color(70, 153, 70, 255), 15.f, centerOfScreen[0], centerOfScreen[1], earthOrbit.GetRadius(), centerOfScreen[0] + earthOrbit.GetRadius() - 20.f / 2, centerOfScreen[1], 0.026);
	earth.SetName("earth");
	earth.GetValue();

	SateliteOrbit moonOrbit = SateliteOrbit(earth.GetX(), earth.GetY(), 30.f);
	Satellite moon = Satellite(Color(170, 170, 170, 255), 6, earth.GetX(), earth.GetY(), moonOrbit.GetRadius(), earth.GetX() + moonOrbit.GetRadius() - 6 / 2, earth.GetY() + moonOrbit.GetRadius() - 6 / 2, 0.055);
	moon.SetName("moon");
	moon.GetValue();

	Orbit marsOrbit = Orbit(centerOfScreen[0], centerOfScreen[1], 160.f);
	Planet mars = Planet(Color(240, 100, 80, 255), 13.f, centerOfScreen[0], centerOfScreen[1], marsOrbit.GetRadius(), centerOfScreen[0] + marsOrbit.GetRadius() - 15.f / 2, centerOfScreen[1], 0.021);
	mars.SetName("mars");
	mars.GetValue();

	SateliteOrbit fobosOrbit = SateliteOrbit(mars.GetX(), mars.GetY(), 35.f);
	Satellite fobos = Satellite(Color(170, 170, 170, 255), 6, mars.GetX(), mars.GetY(), fobosOrbit.GetRadius(), mars.GetX() + fobosOrbit.GetRadius() - 6 / 2, mars.GetY() + fobosOrbit.GetRadius() - 6 / 2, 0.085);
	fobos.SetName("fobos");
	fobos.GetValue();

	SateliteOrbit deimosOrbit = SateliteOrbit(mars.GetX(), mars.GetY(), 20.f);
	Satellite deimos = Satellite(Color(170, 170, 170, 255), 4, mars.GetX(), mars.GetY(), deimosOrbit.GetRadius(), mars.GetX() + deimosOrbit.GetRadius() - 4 / 2, mars.GetY() + deimosOrbit.GetRadius() - 4 / 2, 0.045);
	deimos.SetName("deimos");
	deimos.GetValue();

	Orbit jupiterOrbit = Orbit(centerOfScreen[0], centerOfScreen[1], 240.f);
	Planet jupiter = Planet(Color(180, 135, 60, 255), 30.f, centerOfScreen[0], centerOfScreen[1], jupiterOrbit.GetRadius(), centerOfScreen[0] + jupiterOrbit.GetRadius() - 15.f / 2, centerOfScreen[1], 0.012);
	jupiter.SetName("jupiter");
	jupiter.GetValue();

	Orbit saturnOrbit = Orbit(centerOfScreen[0], centerOfScreen[1], 300.f);
	Planet saturn = Planet(Color(220, 165, 80, 255), 25.f, centerOfScreen[0], centerOfScreen[1], saturnOrbit.GetRadius(), centerOfScreen[0] + saturnOrbit.GetRadius() - 15.f / 2, centerOfScreen[1], 0.013);
	saturn.SetName("saturn");
	saturn.GetValue();

	Orbit uranusOrbit = Orbit(centerOfScreen[0], centerOfScreen[1], 360.f);
	Planet uranus = Planet(Color(170, 245, 245, 255), 20.f, centerOfScreen[0], centerOfScreen[1], uranusOrbit.GetRadius(), centerOfScreen[0] + uranusOrbit.GetRadius() - 15.f / 2, centerOfScreen[1], 0.016);
	uranus.SetName("uranus");
	uranus.GetValue();

	Orbit neptuneOrbit = Orbit(centerOfScreen[0], centerOfScreen[1], 405.f);
	Planet neptune = Planet(Color(70, 100, 175, 255), 15.f, centerOfScreen[0], centerOfScreen[1], neptuneOrbit.GetRadius(), centerOfScreen[0] + neptuneOrbit.GetRadius() - 15.f / 2, centerOfScreen[1], 0.017);
	neptune.SetName("neptune");
	neptune.GetValue();

	Orbit plutoOrbit = Orbit(centerOfScreen[0], centerOfScreen[1], 480.f);
	Planet pluto = Planet(Color(195, 160, 130, 255), 6.f, centerOfScreen[0], centerOfScreen[1], plutoOrbit.GetRadius(), centerOfScreen[0] + plutoOrbit.GetRadius() - 15.f / 2, centerOfScreen[1], 0.014);
	pluto.SetName("pluto");
	pluto.GetValue();

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed ||
				(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
				window.close();
		}
		window.clear();

		// Рисуем орбиты
		window.draw(plutoOrbit.orbitForm); 
		window.draw(neptuneOrbit.orbitForm);
		window.draw(uranusOrbit.orbitForm);
		window.draw(saturnOrbit.orbitForm);
		window.draw(jupiterOrbit.orbitForm);
		window.draw(marsOrbit.orbitForm);
		window.draw(fobosOrbit.orbitForm);
		window.draw(deimosOrbit.orbitForm);
		window.draw(earthOrbit.orbitForm);
		window.draw(moonOrbit.orbitForm);
		window.draw(venusOrbit.orbitForm);
		window.draw(mercuryOrbit.orbitForm);

		// Рисуем планеты, спутники и солнце 
		window.draw(sun.celestialBodyForm);
		window.draw(mercury.celestialBodyForm);
		window.draw(venus.celestialBodyForm);
		window.draw(moon.celestialBodyForm);
		window.draw(earth.celestialBodyForm);
		window.draw(fobos.celestialBodyForm);
		window.draw(deimos.celestialBodyForm);
		window.draw(mars.celestialBodyForm);
		window.draw(jupiter.celestialBodyForm);
		window.draw(saturn.celestialBodyForm);
		window.draw(uranus.celestialBodyForm);
		window.draw(neptune.celestialBodyForm);
		window.draw(pluto.celestialBodyForm);

		// Выставляем планеты на правильные позиции
		sun.UpdateCoordinates();
		earth.UpdateCoordinates();
		mercury.UpdateCoordinates();
		venus.UpdateCoordinates();
		mars.UpdateCoordinates();
		moonOrbit.Update(earth);
		moon.UpdateCoordinates(earth);
		fobosOrbit.Update(mars);
		fobos.UpdateCoordinates(mars);
		deimosOrbit.Update(mars);
		deimos.UpdateCoordinates(mars);
		jupiter.UpdateCoordinates();
		saturn.UpdateCoordinates();
		uranus.UpdateCoordinates();
		neptune.UpdateCoordinates();
		pluto.UpdateCoordinates();

		// Двигаем планеты по траекториям
		mars.IncreaseAngle();
		fobos.IncreaseAngle();
		deimos.IncreaseAngle();
		mercury.IncreaseAngle();
		venus.IncreaseAngle();
		earth.IncreaseAngle();
		moon.IncreaseAngle();
		jupiter.IncreaseAngle();
		saturn.IncreaseAngle();
		uranus.IncreaseAngle();
		neptune.IncreaseAngle();
		pluto.IncreaseAngle();

		window.display();
	}
	return 0;
}
