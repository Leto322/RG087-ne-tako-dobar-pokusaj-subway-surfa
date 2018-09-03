#include "main.h"
#include "movement.h"
#include "drawing.h"
#include "image.h"

//Deklaracija callback funkcija.
static void on_display(void);
static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_timer(int);



int main(int argc, char** argv){

    //Inicijalizuje se GLUT.
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    //Kreira se prozor.
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100,100);
    glutCreateWindow(argv[0]);


    srand(time(NULL));

    //Inicijaliacija parametara i osvetljenja.
    initialize();
    textures_and_lighting();

    //Registruju se callback funkcije.
    glutKeyboardFunc(on_keyboard);
    glutDisplayFunc(on_display);
    glutReshapeFunc(on_reshape);




    //Obavlja se OpenGL inicijalizacija.
    glClearColor(0.52,0.81,0.92,0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //Program ulazi u glavnu petlju.
    glutMainLoop();

    return 0;
}




static void on_keyboard(unsigned char key, int x, int y){
    switch(key){
        case 27:
            //Zavrsava se program.
            exit(0);
            break;
        case 'g':
        case 'G':
            //Pogrece se animacija.
            if(!animation_ongoing && !game_over){
                animation_ongoing = 1;
                glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
            }
            break;
        case 's':
        case 'S':
            //Zaustavlja se animacija
            animation_ongoing = 0;
            break;
        case 'r':
        case 'R':
            //Restartuje se animacija
            initialize();
            glutPostRedisplay();
            break;
        case 'f':
        case 'F':
            //Otvara se igrica preko celog prozora
            glutFullScreen();
            break;
        case 'd':
        case 'D':
          //Trkac se pomera desno.
          if(moving)
             break;
          else if(position == 2)
             break;
          else{
             position+=1;
             moving=1;
             direction=1;
           }
          break;
        case 'a':
        case 'A':
          //Trkac se pomera levo.
          if(moving)
            break;
          else if(position == 0)
            break;
          else{
            position-=1;
            moving=1;
            direction=0;
          }
          break;
        case 32:
          //Trkac skace.
          if(jumping || moving)
            break;
          else{
            dir=0;
            jump=0;
            jumping = 1;
          }
          break;
    }
}


static void on_reshape(int width, int height){
    //Podesava se viewport.
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);

    //Podesava se projekcija.
    glLoadIdentity();
    gluPerspective(60, (float)width/height, 1, 1000);
}


static void on_timer(int id){

   //Proverava se da li callback dolazi od odgovarajuceg tajmera.
   if(id!=TIMER_ID)
        return;

   //Azurira se parametar animacije.
   animation_parameter += param;
   coin_rotation+=1.5;

   //U zavisnosti od parametra animacije se ubrzava animacija.
   if((int)animation_parameter%400 == 0 && animation_parameter<(int)animation_parameter+0.2 && param < 12){
         param*=2;
         speed*=1.5;
    }

    //Provera sudara. (I pre i posle pomeranja novcica se vrsi provera sudara zato sto moze da se desi da u trenutku
    //prolaska kroz novcic dodje do ubrzanja animacije i trkac protrci kroz novcic i ne pokupi ga).
    check_collisions();

    //Funkcije koje vrse promenu parametara animacije.
    update_obstacle();
    update_road();
    update_jump();
    update_movement();
    update_angles();
    update_coins();

    //Provera sudara.
    check_collisions();


    //Dekremetira se parametar drmusanja
    if(shake!=0){
        shake-=1;
    }

    //Ako je skupljeno 20 novica igrac dobija 1 zivot
    if(num_coins==20){
        num_coins=0;
        num_lives+=1;
    }

    //Ako igrac padne na 0 zivota gubi igru
    if(num_lives==0){
        game_over=1;
        animation_ongoing=0;
    }



    //Forsira se ponovno isrtavanje prozora.
    glutPostRedisplay();

    //Po potrebi se ponovo postavlja tajmer.
    if(animation_ongoing){
        glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
    }

}

void textures_and_lighting(){
    Image * image;

    glTexEnvf(GL_TEXTURE_ENV,
              GL_TEXTURE_ENV_MODE,
              GL_REPLACE);

    /*
     * Inicijalizuje se objekat koji ce sadrzati teksture ucitane iz
     * fajla.
     */
    image = image_init(0, 0);

    /* Kreira se prva tekstura. */
    image_read(image, FILENAME0);
    //
    // /* Generisu se identifikatori tekstura. */
    glGenTextures(3, names);

    glBindTexture(GL_TEXTURE_2D, names[0]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

    /* Kreira se druga tekstura. */
     image_read(image, FILENAME1);

     glBindTexture(GL_TEXTURE_2D, names[1]);
     glTexParameteri(GL_TEXTURE_2D,
                     GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                     GL_TEXTURE_WRAP_T, GL_REPEAT);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                  image->width, image->height, 0,
                  GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

                 /* Kreira se treca tekstura. */
     image_read(image, FILENAME2);

     glBindTexture(GL_TEXTURE_2D, names[2]);
     glTexParameteri(GL_TEXTURE_2D,
                     GL_TEXTURE_WRAP_S, GL_REPEAT);
     glTexParameteri(GL_TEXTURE_2D,
                     GL_TEXTURE_WRAP_T, GL_REPEAT);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                  image->width, image->height, 0,
                  GL_RGB, GL_UNSIGNED_BYTE, image->pixels);


    /* Iskljucujemo aktivnu teksturu */
    glBindTexture(GL_TEXTURE_2D, 0);

    /* Unistava se objekat za citanje tekstura iz fajla. */
    image_done(image);




      //Pozicija svetla
      GLfloat light_position[] = {1, 2, 1, 0};

      //Ambijentalna boja svetla.
      GLfloat light_ambient[] = {0.1, 0.1, 0.1, 1};

      //Difuzna boja svetla
      GLfloat light_diffuse[] = {0.7,0.7,0.7,0.7,1};

      //Spekularna boja svetla
      GLfloat light_specular[] = {0.9, 0.9, 0.9, 1};

      //Koeficijenti ambijentalne refleksije materijala.
      GLfloat ambient_coeffs[] = {0.3, 0.3, 0.3, 1};

      //Koeficijenti difuzne refleksije materijala.
      GLfloat diffuse_coeffs[] = {0.4, 0.4, 0.4, 1};

      //Koeficijenti spekularne refleksije materijala.
      GLfloat specular_coeffs[] = {1,1,1,1};

      //Koeficijent glatkosti materijala.
      GLfloat shininess = 30;

      //Podesavaju se parametri svetla.
      glLightfv(GL_LIGHT0, GL_POSITION, light_position);
      glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
      glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
      glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

      //Podesavaju se parametri materijala
      glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
      glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
      glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
      glMaterialf(GL_FRONT, GL_SHININESS, shininess);
      glEnable(GL_COLOR_MATERIAL);

}

void initialize(){
  //Inicijalizacija parametara i osvetljenja
  change = 0;

  lower_arm = 90;
  upper_arm = 0;
  lowerr_leg = 0;
  lowerl_leg = 0;
  upperr_leg = 0;
  upperl_leg = 0;

  gd = 0.02;
  speed = 2;
  size_floor = 300;
  param = 0.8;

  animation_ongoing = 0;
  animation_parameter = 0;

  moving = 0;
  position = 1;
  movement = 0;
  direction = 0;
  jumping = 0;
  jump = 0;
  dir = 0;

  coin_rotation=0;
  num_coins=0;
  num_lives=3;
  invulnerable=0;
  game_over=0;
  shake = 0;

  //Inicijalizuje se pozicija trkaca i dimenzije kvadra koji ga obuhvata.
  runner.xpos = 0;
  runner.ypos = 2.3;
  runner.zpos = 0;

  runner.x = 2.35;
  runner.y = 4.7;
  runner.z = 2.6;


  //Popunjava se niz koji sadrzi delove scene
  int i;
  for(i=0;i<BR;i++){
      parts[i] = -i*size_floor;
  }


  //Inicijalizuju se prepreke
  for(i=0;i<MAX_OBSTACLES;i++){
      obstacles[i].xpos = 0;
      obstacles[i].ypos = -1;
      obstacles[i].zpos = -(BR-1)*size_floor+size_floor/3;


      obstacles[i].x = 5;
      obstacles[i].y = 5;
      obstacles[i].z = 5;
  }

  //Inicijalizuju se novcici
  for(i=0; i<MAX_COINS;i++){
      coins[i].xpos = 0;
      coins[i].ypos = -1;
      coins[i].zpos = -(BR-1)*size_floor+size_floor/3;

      coins[i].r = 1;
  }

}

static void on_display(void){

    //Brise se prethodni sadrzaj prozora
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Podesava se vidna tacka
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //Funkcija za shake nadjena na internetu.
    gluLookAt(0,10,22,sin(2*shake)*(0.5-shake/10),sin(3*shake)*(0.5-shake/10),0,0,1,0);

    //Crta se kvadar koji okruzuje trkaca
    //draw_cube(runner.xpos,runner.ypos,runner.zpos,runner.x,runner.y,runner.z);

    //Crtanje robota.
    draw_runner();

    //Crtanje puta.
    draw_road();

    //Crtanje prepreka;
    draw_obstacles();

    //Crtanje novcica
    draw_coins();

    //Ispis teksta.
    display_text();

    glutSwapBuffers();
}
