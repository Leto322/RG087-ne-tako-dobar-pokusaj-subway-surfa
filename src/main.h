#ifndef MAIN_H
#define MAIN_H

#include <GL/glut.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#define TIMER_ID 0
#define BR 5
#define TIMER_INTERVAL 10
#define PI 3.1415926535


//Deklaracija funkcije za inicijalizaciju.
void initialize();


//Definicija strukture koja predstavlja trkaca
typedef struct {
  float xpos;
  float ypos;
  float zpos;

  float x;
  float y;
  float z;

}Runner;



//Staticke promenljive

//Promena smera kretanja delova tela.
float change;

//Parametar za pomeranje gore-dole.
float gd;

//Parametar koji odredjuje brzinu animacije
float speed;

//Parametar za koji se animacija pomera;
float param;

//Velicina ploca.
float size_floor;

//Niz pozicija delova koji cine put.
float parts[BR];

//Uglovi tela trkaca
float lower_arm;
float upper_arm;
float lowerr_leg;
float lowerl_leg;
float upperl_leg;
float upperr_leg;

//Parametri animacije.
int animation_ongoing;
float animation_parameter;

//Promenljiva trkac
Runner runner;


//Parametri kretanja trakca

//Pozicija trkaca(0-levo, 1-sredina, 2-desno)
int position;

//Da li se trkac krece levo ili desno (0-ne, 1-da)
int moving;

//Parametar koji definise za koliko se trkac krece levo i desno.
float movement;

//Da li je trkac u skoku(0-ne, 1-da);
int jumping;

//Parametar koji definise za koliko se trkac krece gore i dole
float jump;

//Smer kretanja prilikom skoka (0-gore 1-dole)
int dir;

//Smer kretanja prilikom kretanja levo-desno(0-levo 1-desno)
int direction;

#endif
