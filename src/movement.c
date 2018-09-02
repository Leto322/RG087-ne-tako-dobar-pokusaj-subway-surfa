#include "main.h"
#include "movement.h"


//Funkcija koja je zaduzena za poziciju trkaca prilikom skoka   (y-osa).
void updateJump(){

  //U zavisnosti od toga da li je trkac u skoku i da li ide gore ili dole podesavaju se parametri.
  if(jumping){
    if(dir == 0){
    //Ukoliko ide nagore
      if(jump<7){
        jump+=0.3;
        runner.ypos+=0.3;
        if(jump>7){
          jump=7;
          runner.ypos-=(jump-7);
        }
      }
      else{
        dir = 1;
      }
    }
    else{
    //Ukoliko ide nadole
      if(jump>0){
        jump-=0.3;
        runner.ypos-=0.3;
        if(jump<0){
          jump=0;
          runner.ypos+=-jump;
        }
      }
      else{
        jumping = 0;
        dir=0;
      }
    }
  }
}

//Funkcija koja je zaduzena za poziciju trkaca pri kretanju levo-desno  (x-osa).
void updateMovement(){

  //U zavistnosti od toga da li se trakac krece levo-desno i smera kretanja se podesavaju parametri
  if(moving){
    if(direction==1){
      //Ako se krece desno i nova pozicija mu je 1(sredina).
      if(position==1){
        if(movement<0){
          movement+=0.1*speed;
          runner.xpos += 0.1*speed;
          if(movement>0){
            movement=0;
            runner.xpos -= movement;
          }
        }
        else{
          moving = 0;
        }
      }
      //Ako se krece desno i nova pozicija mu je 2(skroz desno).
      else{
        if(movement<10){
          movement+=0.1*speed;
          runner.xpos+=0.1*speed;
          if(movement>10){
            movement=10;
            runner.xpos-=(movement-10);
          }
        }
        else{
          moving = 0;
        }
      }
    }
    else{
      //Ako se krece levo i nova pozicija mu je 0(skroz levo).
      if(position==0){
        if(movement>-10){
          movement-=0.1*speed;
          runner.xpos-=0.1*speed;
          if(movement<-10){
            movement=-10;
            runner.xpos+=-(movement+10);
          }
        }
        else{
          moving = 0;
        }
    }
    else{
        //Ako se krece levo i nova pozicija mu je 1(sredina).
        if(movement>0){
          movement-=0.1*speed;
          runner.xpos-=0.1*speed;
          if(movement<0){
            movement=0;
            runner.xpos+=-movement;
          }
        }
        else{
          moving = 0;
        }
      }
    }
  }
}

//Funkcija koja menja uglove delova tela trkaca.
void updateAngles(){

  //U zavisnosti od strane u koju ide gornji deo ruke se podesava novi ugao.
  if(change==0){
      if(upper_arm<40){
          upper_arm+=1*speed;
          if(upper_arm>40)
              upper_arm=40;
      }else{
          upper_arm-=1*speed;
          gd*=-1;
          change = 1;
          if(upper_arm<-40){
              upper_arm=-40;
              change=0;
          }
      }
  }
  else{
      if(upper_arm>-40){
          upper_arm-=1*speed;
          if(upper_arm<-40)
              upper_arm=-40;
      }else{
          upper_arm+=1*speed;
          gd*=-1;
          change = 0;
          if(upper_arm>40){
              upper_arm=40;
              change=1;
            }
      }
  }

  //U zavisnosti od strane u koju ide donji deo ruke se podesava novi ugao.
  if(change==0){
      if(lower_arm<118){
          lower_arm+=0.3*speed;
          if(lower_arm>118)
              lower_arm=118;
      }else
          lower_arm-=0.3*speed;
          if(lower_arm<90)
              lower_arm=90;

      }
  else{
      if(lower_arm>90){
          lower_arm-=0.3*speed;
          if(lower_arm<90)
              lower_arm=90;
      }else
          lower_arm+=0.3*speed;
          if(lower_arm>118)
              lower_arm=118;
      }

  //U zavisnosti od smera u koji ide gornji deo desne noge se podesava novi ugao.
  if(change==0){
      if(upperr_leg<40){
          upperr_leg+=0.75*speed;
          if(upperr_leg>40)
              upperr_leg=40;
      }else
          upperr_leg-=0.75*speed;
          if(upperr_leg<-20)
              upperr_leg=-20;
      }
  else{
      if(upperr_leg>-20){
          upperr_leg-=0.75*speed;
          if(upperr_leg<-20)
              upperr_leg=-20;
      }else
          upperr_leg+=0.75*speed;
          if(upperr_leg>40)
              upperr_leg=40;
      }

  //U zavisnosti od smera u koji ide gornji deo leve noge se podesava novi ugao.
  if(change==1){
      if(upperl_leg<40){
          upperl_leg+=0.75*speed;
          if(upperl_leg>40)
              upperl_leg=40;
      }else
          upperl_leg-=0.75*speed;
          if(upperl_leg<-20)
              upperl_leg=-20;
      }
  else{
      if(upperl_leg>-20){
          upperl_leg-=0.75*speed;
          if(upperl_leg<-20)
              upperl_leg=-20;
      }else
          upperl_leg+=0.75*speed;
          if(upperl_leg>40)
              upperl_leg=40;
      }
  //U zavisnosti od smera u koji ide donji deo leve noge se podesava novi ugao.
  if(change==1){
      if(lowerl_leg<0){
          lowerl_leg+=1.25*speed;
          if(lowerl_leg>0)
              lowerl_leg=0;
      }else
          lowerl_leg-=1.25*speed;
          if(lowerl_leg<-100)
              lowerl_leg=-100;
  }
  else{
      if(lowerl_leg>-100){
          lowerl_leg-=1.25*speed;
          if(lowerl_leg<-100)
              lowerl_leg=-100;
      }else
          lowerl_leg+=1.25*speed;
          if(lowerl_leg>0)
              lowerl_leg=0;
  }

  //U zavisnosti od smera u koji ide donji deo desne noge se podesava novi ugao.
  if(change==0){
      if(lowerr_leg<0){
          lowerr_leg+=1.25*speed;
          if(lowerr_leg>0)
              lowerr_leg=0;
      }else
          lowerr_leg-=1.25*speed;
          if(lowerr_leg<-100)
              lowerr_leg=-100;
  }
  else{
      if(lowerr_leg>-100){
          lowerr_leg-=1.25*speed;
          if(lowerr_leg<-100)
              lowerr_leg=-100;
      }else
          lowerr_leg+=1.25*speed;
          if(lowerr_leg>0)
              lowerr_leg=0;
  }
}

//Funkcija zaduzena za podesavanje parametra kretanja puta i zidova.
void updateRoad(){
  int i;

  for(i=0;i<BR;i++){
    parts[i]+=param;
  }
}

void updateObstacle(){
    int i;
    for(i=0;i<MAX_OBSTACLES;i++){
        if(obstacles[i].ypos!=-1)
            obstacles[i].zpos+=param;
    }
}

void updateCoins(){
    int i;
    for(i=0;i<MAX_COINS;i++){
        if(coins[i].ypos!=-1)
            coins[i].zpos+=param;
    }

}
