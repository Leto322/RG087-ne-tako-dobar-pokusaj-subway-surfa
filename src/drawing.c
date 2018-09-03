#include "main.h"


//Funkcija iscrtava kvadar oko trkaca(Pomocna za kolizije).
void draw_cube(float xpos, float ypos, float zpos, float a, float b, float c){
  glPushMatrix();
    glDisable(GL_LIGHTING);
    glColor3f(1,1,1);
    glTranslatef(xpos,ypos,zpos);
    glScalef(a,b,c);
    glutWireCube(1);
    glEnable(GL_LIGHTING);
  glPopMatrix();
}

//Funkcija koja crta trkaca.
void draw_runner(void){
  GLUquadricObj *quad;
  quad = gluNewQuadric();
  glPushMatrix();

  //gd pomera trkaca gore-dole za male vrednosti.
  glTranslatef(0, gd, 0);

  //Postavlja se pozicija trkaca.
  glTranslatef(runner.xpos, runner.ypos, runner.zpos);
  glTranslatef(0,0.6,0);


  //Rotira se da bi trkac gledao ka -z.
  glRotatef(180,0,1,0);


  //Gornji deo.
  {
        glPushMatrix();
            glRotatef(15*sin(animation_parameter*0.1),0,1,0);
            //Gornji deo tela.
            glPushMatrix();
                glColor4f(1,0,0,1);
                glScalef(1.3,1.6,0.6);
                glutSolidCube(1);
            glPopMatrix();
            //Glava.
            glPushMatrix();
                glColor4f(1,1,0,1);
                glTranslatef(0, 1.2,0);
                glutSolidSphere(0.5, 40, 40);
            glPopMatrix();
            //Ruke.
            //Leva ruka.
            glPushMatrix();
            //Rame.
                glColor4f(1,0,0,1);
                glTranslatef(-0.85,0.7,0);
                glRotatef(upper_arm, 1, -1, 0);
                glutSolidSphere(0.2, 40, 40);
                glPushMatrix();
                //Nadlaktica.
                    glTranslatef(0, -0.19, 0);
                    glRotatef(90, 1, 0, 0);
                    gluCylinder(quad, 0.1, 0.1, 0.5, 50, 50);
                glPopMatrix();
                //Lakat.
                    glTranslatef(0, -0.75, 0);
                    glRotatef(-lower_arm, 1, 0, 0);
                    glutSolidSphere(0.13, 40, 40);
                glPushMatrix();
                //Podlaktica.
                    glTranslatef(0, -0.1,0);
                    glRotatef(90, 1, 0, 0);
                    gluCylinder(quad, 0.1, 0.1, 0.46, 50, 50);
                glPopMatrix();
                glPushMatrix();
                    glColor4f(1,1,0,1);
                    glTranslatef(0, -0.65, 0);
                    glScalef(1.2, 1, 1.4);
                    glutSolidCube(0.2);
                glPopMatrix();
            glPopMatrix();
            //Desna ruka.
            glPushMatrix();
            //Rame.
                glColor4f(1,0,0,1);
                glTranslatef(0.85,0.7,0);
                glRotatef(-upper_arm, 1, 1, 0);
                glutSolidSphere(0.2, 40, 40);
                glPushMatrix();
                //Nadlaktica.
                    glTranslatef(0, -0.19, 0);
                    glRotatef(90, 1, 0, 0);
                    gluCylinder(quad, 0.1, 0.1, 0.5, 50, 50);
                glPopMatrix();
                //Lakat.
                    glTranslatef(0, -0.75, 0);
                    glRotatef(-lower_arm, 1, 0, 0);
                    glutSolidSphere(0.13, 40, 40);
                glPushMatrix();
                //Podlaktica.
                    glTranslatef(0, -0.1,0);
                    glRotatef(90, 1, 0, 0);
                    gluCylinder(quad, 0.1, 0.1, 0.46, 50, 50);
                glPopMatrix();
                glPushMatrix();
                    glColor4f(1,1,0,1);
                    glTranslatef(0, -0.65, 0);
                    glScalef(1.2, 1, 1.4);
                    glutSolidCube(0.2);
                glPopMatrix();
            glPopMatrix();

        glPopMatrix();

    }


    //Donji deo tela.
  {
    glPushMatrix();
    glColor4f(0,0,1,1);
    glPushMatrix();
            glTranslatef(0, -1, 0);
            glScalef(0.5, 0.4, 0.6);
            glutSolidCube(1);
    glPopMatrix();
    //Leva noga.
        glPushMatrix();
        glColor4f(0,0,1,1);
            glTranslatef(-0.450, -1.1, 0);
            glRotatef(-upperr_leg, 1,0,0);
            glutSolidSphere(0.2, 40, 40);
                glPushMatrix();
                //Iznad kolena.
                glTranslatef(0, -0.15, 0);
                glRotatef(90, 1, 0, 0);
                gluCylinder(quad, 0.15,0.15, 0.7,50,50);
                glPopMatrix();
                glPushMatrix();
                //Koleno + potkolenica.
                glTranslatef(0, -0.95, 0);
                glRotatef(-lowerr_leg, 1, 0, 0);
                glutSolidSphere(0.16, 40, 40);
                    glPushMatrix();
                        glTranslatef(0, -0.12,0);
                        glRotatef(90, 1, 0, 0);
                        gluCylinder(quad, 0.12,0.12, 0.575,50,50);
                    glPopMatrix();
                    glPushMatrix();
                        glColor4f(1,1,1,1);
                        glTranslatef(0,-0.8,0);
                        glScalef(1.2, 1, 2);
                        glutSolidCube(0.2);
                    glPopMatrix();
                glPopMatrix();
        glPopMatrix();

        //Desna noga.
        glPushMatrix();
        glColor4f(0,0,1,1);
            glTranslatef(0.450, -1.1, 0);
            glRotatef(-upperl_leg, 1,0,0);
            glutSolidSphere(0.2, 40, 40);
                glPushMatrix();
                //Iznad kolena.
                glTranslatef(0, -0.15, 0);
                glRotatef(90, 1, 0, 0);
                gluCylinder(quad, 0.15,0.15, 0.7,50,50);
                glPopMatrix();
                glPushMatrix();
                //Koleno + potkolenica.
                glTranslatef(0, -0.95, 0);
                glRotatef(-lowerl_leg, 1, 0, 0);
                glutSolidSphere(0.16, 40, 40);
                    glPushMatrix();
                        glTranslatef(0, -0.12,0);
                        glRotatef(90, 1, 0, 0);
                        gluCylinder(quad, 0.12,0.12, 0.575,50,50);
                    glPopMatrix();
                    glPushMatrix();
                        glColor4f(1,1,1,1);
                        glTranslatef(0,-0.8,0);
                        glScalef(1.2, 1, 2);
                        glutSolidCube(0.2);
                    glPopMatrix();
                glPopMatrix();
        glPopMatrix();
    glPopMatrix();
  }

    //Senka trkaca
    glTranslatef(0,-runner.ypos+2.4,0);
    glTranslatef(0,-gd,0);
    glPushMatrix();
        glColor4f(0.3,0.3,0.3,0.8);//-(jump/7)*0.8);

        glTranslatef(0.17,-3.01,0.4);
        glRotatef(90,1,0,0);
        glRotatef(-15,0,0,1);
        glScalef(0.75,1.1,1);
        gluQuadricDrawStyle(quad,GLU_FILL);
        gluDisk(quad, 0,1.2,30,30);
    glPopMatrix();


    glPopMatrix();
}

//Funkcija koja crta prepreke
void draw_obstacles(void){
    int i;
    for(i=0;i<MAX_OBSTACLES;i++){
        if(obstacles[i].ypos!=-1){
            glPushMatrix();
                //Svaka kutija se iscrtava pomocu 6 teksturisanih
                glTranslatef(obstacles[i].xpos, obstacles[i].ypos, obstacles[i].zpos);
                glScalef(obstacles[i].x,obstacles[i].y,obstacles[i].z);
                glBindTexture(GL_TEXTURE_2D, names[0]);
                glDisable(GL_BLEND);
                glBegin(GL_QUADS);
                    glNormal3f(0,0,1);
                    glTexCoord2f(0,0);
                    glVertex3f(-0.5,-0.5,0.5);
                    glTexCoord2f(1,0);
                    glVertex3f(0.5,-0.5,0.5);
                    glTexCoord2f(1,1);
                    glVertex3f(0.5,0.5,0.5);
                    glTexCoord2f(0,1);
                    glVertex3f(-0.5,0.5,0.5);

                    glNormal3f(0,-1,0);
                    glTexCoord2f(0,0);
                    glVertex3f(-0.5,-0.5,0.5);
                    glTexCoord2f(1,0);
                    glVertex3f(0.5,-0.5,0.5);
                    glTexCoord2f(1,1);
                    glVertex3f(0.5,-0.5,-0.5);
                    glTexCoord2f(0,1);
                    glVertex3f(-0.5,-0.5,-0.5);

                    glNormal3f(-1,0,0);
                    glTexCoord2f(0,0);
                    glVertex3f(-0.5,-0.5,0.5);
                    glTexCoord2f(1,0);
                    glVertex3f(-0.5,0.5,0.5);
                    glTexCoord2f(1,1);
                    glVertex3f(-0.5,0.5,-0.5);
                    glTexCoord2f(0,1);
                    glVertex3f(-0.5,-0.5,-0.5);

                    glNormal3f(1,0,0);
                    glTexCoord2f(0,0);
                    glVertex3f(0.5,-0.5,0.5);
                    glTexCoord2f(1,0);
                    glVertex3f(0.5,-0.5,-0.5);
                    glTexCoord2f(1,1);
                    glVertex3f(0.5,0.5,-0.5);
                    glTexCoord2f(0,1);
                    glVertex3f(0.5,0.5,0.5);

                    glNormal3f(0,1,0);
                    glTexCoord2f(0,0);
                    glVertex3f(-0.5,0.5,-0.5);
                    glTexCoord2f(1,0);
                    glVertex3f(0.5,0.5,-0.5);
                    glTexCoord2f(1,1);
                    glVertex3f(0.5,0.5,0.5);
                    glTexCoord2f(0,1);
                    glVertex3f(-0.5,0.5,0.5);


                    glNormal3f(0,0,-1);
                    glTexCoord2f(0,0);
                    glVertex3f(-0.5,-0.5,-0.5);
                    glTexCoord2f(1,0);
                    glVertex3f(0.5,-0.5,-0.5);
                    glTexCoord2f(1,1);
                    glVertex3f(0.5,0.5,-0.5);
                    glTexCoord2f(0,1);
                    glVertex3f(-0.5,0.5,-0.5);
                glEnd();
                glEnable(GL_BLEND);
                glBindTexture(GL_TEXTURE_2D, 0);
            glPopMatrix();
        }
    }
}

//Dodajemo od 0 do 2 prepreke i 3-prepreke novcica na svakih 100 unita na poslednjoj ploci
void add_obstacles_and_coins(void){
    //Pomocne brojacke promenljive
    int i;
    int j;
    int r;
    int k;
    //Pozicija na koju se stavlja prepreka ili novcic
    int place;
    //Prethodna pozicija na koju je stavljena prepreka
    int previous;

    //Pozicije na koje su eventualno stavljeni novcici
    int previous1;
    int previous2;

    //Pozicije na koje su eventualno stavljene prepreke
    int position1;
    int position2;


    //Za jednu plocu imamo tri reda na koje mogu doci prepreke i novcici(za plocu velicine 300 imamo na 50, 150 i 250 po jednu liniju)
    for(i=0;i<3;i++){
        r = rand()%3; //Broj prepreka u datom redu
        previous = -1;
        position1=-1;
        position2=-1;
        for(k=0;k<r;k++){
            place = rand()%3; //Mesto u redu gde ide prepreka
            if(place == previous){ //Ako je vec tu  stavljena prepreka
                place = (previous+1)%3;
            }
            if(position1==-1)
                position1=place;
            else{
                position2=place;
            }
            for(j=0;j<MAX_OBSTACLES;j++){
                if(obstacles[j].ypos==-1){
                    switch(place){
                        case 0:
                            obstacles[j].xpos = -10;
                            obstacles[j].ypos = 2.5;
                            obstacles[j].zpos -= i*(size_floor/3);
                            break;
                        case 1:
                            obstacles[j].xpos = 0;
                            obstacles[j].ypos = 2.5;
                            obstacles[j].zpos -= i*(size_floor/3);
                            break;
                        case 2:
                            obstacles[j].xpos = 10;
                            obstacles[j].ypos = 2.5;
                            obstacles[j].zpos -= i*(size_floor/3);
                            break;
                    }
                    break;
                }
            }
            previous=place;
        }


        //Iste oznake kao za prepreke samo sto imamo moguca tri novcica u redu dok za prerpeke imamo maksimum dve
        r = rand()%(3-r);
        previous1=-1;
        previous2=-1;
        for(k=0;k<=r;k++){
            place = rand()%3;

            while(place == position1 || place == position2 || place == previous1 || place == previous2){
                place = rand()%3;
            }
            if(previous1==-1){
                previous1=place;
            }else{
                previous2=place;
            }
            for(j=0;j<MAX_COINS;j++){
                if(coins[j].ypos==-1){
                    switch(place){
                        case 0:
                            coins[j].xpos = -10;
                            coins[j].ypos = 2.5;
                            coins[j].zpos -= i*(size_floor/3);
                            break;
                        case 1:
                            coins[j].xpos = 0;
                            coins[j].ypos = 2.5;
                            coins[j].zpos -= i*(size_floor/3);
                            break;
                        case 2:
                            coins[j].xpos = 10;
                            coins[j].ypos = 2.5;
                            coins[j].zpos -= i*(size_floor/3);
                            break;
                    }
                    break;
                }
            }
        }
    }
}

//Iscrtavanje okruzenja
void draw_road(void){
    //Pomocni parametar
    int i;
    int j;
    //Iscrtava se BR delova koji se sastoje od podne ploce i po dva zida
    for(i=0;i<BR;i++){

            glPushMatrix();
            //Ukoliko deo ode iza trkaca vraca se na kraj staze
            if(parts[i]>size_floor){
                parts[i]-=BR*size_floor;

                //Prekida se sa iscrtavanjem prepreka koje su prosle iza igraca;
                for(j=0;j<MAX_OBSTACLES;j++){
                    if(obstacles[i].zpos>size_floor/2){
                        obstacles[i].ypos = -1;
                        obstacles[i].zpos = -(BR-1)*size_floor+size_floor/3;
                    }
                }
                //Prekida se sa iscrtavanjem novcica koji su prosli iza igraca;
                for(j=0;j<MAX_COINS;j++){
                    if(coins[i].zpos>size_floor/2){
                        coins[i].ypos = -1;
                        coins[i].zpos = -(BR-1)*size_floor+size_floor/3;
                    }
                }

                add_obstacles_and_coins();


            }



            //Crta se podna ploca i ukljucuje textura
            glTranslatef(0, 0, parts[i]);
            glBindTexture(GL_TEXTURE_2D, names[1]);
            glBegin(GL_QUADS);
                glNormal3f(0, 1, 0);

                glTexCoord2f(0,15);
                glVertex3f(-15,0,size_floor/2);

                glTexCoord2f(1, 15);
                glVertex3f(15,0,size_floor/2);

                glTexCoord2f(1,-15);
                glVertex3f(15,0,-size_floor/2);

                glTexCoord2f(0, -15);
                glVertex3f(-15,0,-size_floor/2);
            glEnd();




            //Crta se levi zid i ukljucuje textura
            glPushMatrix();
            glTranslatef(-15,0,0);
            glBindTexture(GL_TEXTURE_2D, names[2]);
            glBegin(GL_QUADS);
                glNormal3f(1, 0,0);

                glTexCoord2f(5, 1);
                glVertex3f(0,20,size_floor/2);

                glTexCoord2f(5,0);
                glVertex3f(0,0,size_floor/2);

                glTexCoord2f(0, 0);
                glVertex3f(0,0,-size_floor/2);

                glTexCoord2f(0,1);
                glVertex3f(0,20,-size_floor/2);
            glEnd();
            glPopMatrix();


            //Crta se desni zid
            glPushMatrix();
            glTranslatef(15, 0, 0);
            glBegin(GL_QUADS);
                glNormal3f(-1, 0, 0);

                glTexCoord2f(5, 1);
                glVertex3f(0,20,size_floor/2);

                glTexCoord2f(5,0);
                glVertex3f(0,0,size_floor/2);

                glTexCoord2f(0, 0);
                glVertex3f(0,0,-size_floor/2);

                glTexCoord2f(0,1);
                glVertex3f(0,20,-size_floor/2);
            glEnd();
            glPopMatrix();

            //Iskljucuje se textura
            glBindTexture(GL_TEXTURE_2D, 0);

        glPopMatrix();

    }

}

//Iscrtavanje novcica
void draw_coins(void){
    GLUquadricObj *quad;
    quad = gluNewQuadric();
    int i;

    for(i=0;i<MAX_COINS;i++){
        if(coins[i].ypos!=-1){
            glPushMatrix();
                glTranslatef(coins[i].xpos, coins[i].ypos, coins[i].zpos);
                glColor4f(1,1,0,1);
                glRotatef(coin_rotation,0,1,0);
                glTranslatef(0,0,-0.25);
                gluCylinder(quad, coins[i].r, coins[i].r, 0.5, 50, 50);
                glRotatef(180,0,1,0);
                gluDisk(quad, 0,coins[i].r,30,30);
                glRotatef(-180,0,1,0);
                glTranslatef(0,0,0.5);
                gluDisk(quad, 0,coins[i].r,30,30);
            glPopMatrix();
        }
    }



}


//Funkcija koja ispisuje tekst na ekranu
void display_text(void){
    glPopMatrix();
    glDisable(GL_LIGHTING);
    glColor4f(1,1,1,1);
    if(game_over){
        sprintf(text, "GAME OVER    (Press r/R to restart.)\nScore: %d", (int)animation_parameter);
    }
    else{
        sprintf(text, "Score: %d    Coins: %d   Lives: %d", (int)animation_parameter, num_coins, num_lives);
    }
    glRasterPos3f(-1.5,1,15);
    glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,text);
    glEnable(GL_LIGHTING);
    glPushMatrix();
}
