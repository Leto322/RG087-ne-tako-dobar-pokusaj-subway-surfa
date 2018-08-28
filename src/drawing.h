#ifndef DRAWING_H
#define DRAWING_H

//Deklaracije funkcija koje iscrtavaju objekte na sceni.
void draw_robo();
void draw_road();
void draw_cube(float xpos, float ypos, float zpos, float a, float b, float c);
void draw_obstacle();

//Deklaracija funkice koja inicijalizuje prepreke;
void add_obstacles();


#endif
