#ifndef MAIN_H
#define MAIN_H

#include <GL/glut.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TIMER_ID 0
#define BR 5
#define TIMER_INTERVAL 10
#define PI 3.1415926535
#define MAX_OBSTACLES (7*BR)
#define MAX_COINS (7*BR)

//Imena fajlova sa teksturama.
#define FILENAME0 "box.bmp"
#define FILENAME1 "concrete.bmp"
#define FILENAME2 "wall.bmp"

//Deklaracija funkcije za inicijalizaciju parametara.
void initialize();

//Deklaracija funkcije za postavljanje osvetljenja i inicijalizaciju tekstura
void textures_and_lighting();


//Definicija strukture koja predstavlja trkaca
typedef struct {
  float xpos;
  float ypos;
  float zpos;


  //Dimenizje po x, y i z osi.
  float x;
  float y;
  float z;

}Runner;

//Definicija strukture koja predstavlja prepreke
typedef struct{
    float xpos;
    float ypos;
    float zpos;

    float x;
    float y;
    float z;
}Obstacle;


//Definicija strukture koja predstavlja novcice
typedef struct{
    float xpos;
    float ypos;
    float zpos;

    float r;
}Coin;



//Promenljive

//Niska koja sadrzi tekst koji se ispisuje na ekran.
char text[1000];

//Parametar tresanja ekrana.
int shake;

//Parametar koji oznacava da li je igrac izgubio.
int game_over;

//Parametar koji govori da igrac ne moze da interaguje sa novcicima i preprekama. (0 moze 1 ne moze)
int invulnerable;

//Broj sakupljenih novcica. (na svakih 10 igrac dobija nov zivot)
int num_coins;

//Broj zivota. (kada dodje do 0 gubi igru)
int num_lives;

//Identifikatori tekstura.
GLuint names[3];

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

//Niz koji sadrzi prepreke
Obstacle obstacles[MAX_OBSTACLES];

//Niz koji sadrzi novcice
Coin coins[MAX_COINS];

//Parametar rotacije novcica
float coin_rotation;

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
