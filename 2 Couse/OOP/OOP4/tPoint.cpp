#include "tPoint.h"

void tPoint::set_x(int a) { x = a; }
void tPoint::set_y(int a) { y = a; }
void tPoint::set_dx(int a) { dx = a; }
void tPoint::set_dy(int a) { dy = a; }
void tPoint::set_dir(int a) { direction = a; }
void tPoint::set_color(int a) { color = a; }
float tPoint::get_x() { return x; }
float tPoint::get_y() { return y; }
int tPoint::get_dx() { return dx; }
int tPoint::get_dy() { return dy; }
int tPoint::get_dir() { return direction; }
int tPoint::get_color() { return color; }
tPoint::tPoint(int Vx, int Vy, int Vdx, int Vdy, int Vdirection, int Vcolor) {
    x = Vx;
    y = Vy;
    dx = Vdx;
    dy = Vdy;
    direction = Vdirection;
    color = Vcolor;
}
tPoint::tPoint() {}
void tPoint::str_moving() {

    if (get_dir() == 1) {
        set_x(get_x() + 1);
        if (get_x() > 1270)
            set_dir(2);
    }
    else if (get_dir() == 2) {
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
void tPoint::rand_moving() {

    if (get_dx() == 1) {
        set_x(get_x() + 1);
        if (get_x() > 1270)
            set_dx(2);
        int a = rand() % 200;
        if (a == 1)
            set_dx(2);
        if (a == 2)
            set_dx(0);
    }
    if (get_dx() == 2) {
        set_x(get_x() - 1);
        if (get_x() < 0)
            set_dx(1);
        int a = rand() % 200;
        if (a == 1)
            set_dx(1);
        if (a == 2)
            set_dx(0);
    }
    if (get_dx() == 0) {
        int a = rand() % 200;
        if (a == 1)
            set_dx(1);
        if (a == 2)
            set_dx(2);
    }

    if (get_dy() == 1) {
        set_y(get_y() + 1);
        if (get_y() > 710)
            set_dy(2);
        int a = rand() % 200;
        if (a == 1)
            set_dy(2);
        if (a == 2)
            set_dy(0);
    }
    if (get_dy() == 2) {
        set_y(get_y() - 1);
        if (get_y() < 0)
            set_dy(1);
        int a = rand() % 200;
        if (a == 1)
            set_dy(1);
        if (a == 2)
            set_dy(0);
    }
    if (get_dy() == 0) {
        int a = rand() % 200;
        if (a == 1)
            set_dy(1);
        if (a == 2)
            set_dy(2);
    }
}



void circle::set_OLcolor(int a) { OLcolor = a; }
int circle::get_OLcolor() { return OLcolor; }
circle::circle(int Vx, int Vy, int Vdx, int Vdy, int Vdirection,int Vcolor, int VOLcolor) : tPoint(Vx,Vy,Vdx,Vdy,Vdirection,Vcolor) {

    OLcolor = VOLcolor;
}
circle::circle() {}



void section::set_length(int a) { length = a; }
void section::set_rotate(int a) { rotate = a; }

int section::get_length() { return length; };
int section::get_rotate() { return rotate; };
section::section(int Vx, int Vy, int Vdx, int Vdy, int Vdirection, int Vcolor, int Vlength, int Vrotate) : tPoint(Vx, Vy, Vdx, Vdy, Vdirection, Vcolor) {

    length = Vlength;
    rotate = Vrotate;
}
section::section() {}

void rectangle::set_width(int a) { width = a; }
int rectangle::get_width() { return width; }
rectangle::rectangle(int Vx, int Vy, int Vdx, int Vdy, int Vdirection, int Vcolor, int Vlength, int Vrotate, int Vwidth) : section(Vx,Vy,Vdx,Vdy,Vdirection,Vcolor,Vlength,Vrotate) {
    width = Vwidth;
}
rectangle::rectangle() {};

ellipce::ellipce(int Vx, int Vy, int Vdx, int Vdy, int Vdirection, int Vcolor, int VOLcolor, float Vsmaxis, float Vsminaxis) : circle(Vx, Vy, Vdx, Vdy, Vdirection, Vcolor,VOLcolor) {
    smaxis = Vsmaxis;
    sminaxis = Vsminaxis;
}
ellipce::ellipce() {};
void ellipce:: set_smaxis(float a) { smaxis = a; };
void ellipce::set_sminaxis(float a) { sminaxis = a; };
float ellipce::get_smaxis() { return smaxis; };
float ellipce::get_sminaxis() { return sminaxis; };

rhombus::rhombus(int Vx, int Vy, int Vdx, int Vdy, int Vdirection, int Vcolor, float vdxcor, float vdycor) : tPoint(Vx, Vy, Vdx, Vdy, Vdirection, Vcolor) {

    dxcor = vdxcor;
    dycor = vdycor;
};
rhombus :: rhombus() {};

void rhombus:: set_dxcor(float a) { dxcor = a; };
void rhombus:: set_dycor(float a) { dycor = a; };

float rhombus::get_dxcor() { return dxcor; };
float rhombus::get_dycor() { return dycor; };

triangle::triangle(int Vx, int Vy, int Vdx, int Vdy, int Vdirection, int Vcolor, float vdxcor, float vdycor, float vdxcor2, float vdycor2) : rhombus(Vx, Vy, Vdx, Vdy, Vdirection, Vcolor,vdxcor,vdycor) {
    dxcor2 = vdxcor2;
    dycor2 = vdycor2;
};
triangle::triangle() {};
void triangle::set_dxcor2(float a) { dxcor2 = a; };
void triangle::set_dycor2(float a) { dycor2 = a; };
float triangle::get_dxcor2() { return dxcor2; };
float triangle::get_dycor2() { return dycor2; };