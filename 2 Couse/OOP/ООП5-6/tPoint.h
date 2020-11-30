#pragma once
#include <iostream>

using namespace std;

class tPoint {
private:
	int x;
	int y;
	int dx;
	int dy;
	int direction;
	int color;
public:
	tPoint(int Vx, int Vy, int Vdx, int Vdy, int Vdirection, int Vcolor);
	tPoint();
	void set_x(int a);
	void set_y(int a);
	void set_dx(int a);
	void set_dy(int a);
	void set_dir(int a);
	void set_color(int a);
	float get_x();
	float get_y();
	int get_dx();
	int get_dy();
	int get_dir();
	int get_color();
	virtual void str_moving();
	virtual void rand_moving();
};

class circle : public tPoint {
private:
	int OLcolor;
public:
	circle(int Vx, int Vy, int Vdx, int Vdy, int Vdirection, int Vcolor,int VOLcolor);
	circle();
	void set_OLcolor(int a);
	int get_OLcolor();
};

class ellipce : public circle {
	private:
		float smaxis;
		float sminaxis;
	public:
		ellipce(int Vx, int Vy, int Vdx, int Vdy, int Vdirection, int Vcolor, int VOLcolor, float Vsmaxis, float Vsminaxis);
		ellipce();
		void set_smaxis(float a);
		void set_sminaxis(float a);
		float get_smaxis();
		float get_sminaxis();



};

class section : public tPoint {
private:
	int length;
	int rotate;
public:
	section(int Vx, int Vy, int Vdx, int Vdy, int Vdirection, int Vcolor, int Vlength, int Vrotate);
	section();
	
	void set_length(int a);
	void set_rotate(int a);	
	int get_length();
	int get_rotate();

};

class rectangle : public section {
	private:
		int width;
	public:
		rectangle(int Vx, int Vy, int Vdx, int Vdy, int Vdirection, int Vcolor, int Vlength, int Vrotate, int Vwidth);
		rectangle();

		void set_width(int a);
		int get_width();


};

class rhombus : public tPoint {
private:
	float dxcor;
	float dycor;
public:
	rhombus(int Vx, int Vy, int Vdx, int Vdy, int Vdirection, int Vcolor, float vdxcor, float vdycor);
	rhombus();
	void set_dxcor(float a);
	void set_dycor(float a);
	float get_dxcor();
	float get_dycor();

};

class triangle : public rhombus {
private:
	float dxcor2;
	float dycor2;
public:
	triangle(int Vx, int Vy, int Vdx, int Vdy, int Vdirection, int Vcolor, float vdxcor, float vdycor, float vdxcor2, float vdycor2);
	triangle();
	void set_dxcor2(float a);
	void set_dycor2(float a);
	float get_dxcor2();
	float get_dycor2();


};