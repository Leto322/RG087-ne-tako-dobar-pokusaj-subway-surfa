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
void draw_robo(void){
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
            glTranslatef(0, -1.1, 0);
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
    glPushMatrix();
        glColor4f(0.3,0.3,0.3,0.8);//-(jump/7)*0.8);

        glTranslatef(0.17,-2.93,0.4);
        glRotatef(90,1,0,0);
        glRotatef(-15,0,0,1);
        glScalef(0.75,1.1,1);
        gluQuadricDrawStyle(quad,GLU_FILL);
        gluDisk(quad, 0,1.2,30,30);
    glPopMatrix();


    glPopMatrix();
}

//Iscrtavanje scene
void draw_road(void){
    //Pomocni parametar
    int i;

    //Iscrtava se BR delova koji se sastoje od podne ploce i po dva zida
    for(i=0;i<BR;i++){
        glPushMatrix();
            glScalef(0.3,0.3,1);

            //Ukoliko deo ode iza trkaca vraca se na kraj staze
            if(parts[i]>size_floor){
                parts[i]-=BR*size_floor;
            }

            //Razlicitih su boja zbog testiranja a planiram da stavim teksturu
            switch(i){
              case 0:
                glColor4f(1,0,0,1);
                break;
              case 1:
                glColor4f(0,1,0,1);
                break;
              case 2:
                glColor4f(0,0,1,1);
                break;
              case 3:
                glColor4f(1,1,0,1);
                break;
              case 4:
                glColor4f(1,0,1,1);
                break;
            }


            //Crta se podna ploca
            glScalef(0.3, 0.001, 1);
            glTranslatef(0, 0, parts[i]);
            glutSolidCube(size_floor);
            glScalef((float)10/3, 1000, 1);


            glScalef(3,3,1);

            //Crta se levi zid
            glPushMatrix();
            glTranslatef(-16, 10, 0);
            glScalef(2,20, size_floor);
            glutSolidCube(1);
            glPopMatrix();

            //Crta se desni zid
            glPushMatrix();
            glTranslatef(16, 10, 0);
            glScalef(2,20, size_floor);
            glutSolidCube(1);
            glPopMatrix();



        glPopMatrix();

    }

}
