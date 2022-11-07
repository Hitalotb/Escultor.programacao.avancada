#include <iostream>
#include "sculptor.h"
#include <fstream>

using namespace std;

int main(){
///*
  Sculptor toto(40,40,40);

  //cabeca
  toto.setColor(1.0,1.0,0.0,1.0);
  toto.putSphere(19,35,19,5);
  //pescoco
  toto.putEllipsoid(19,32,19,3,5,3);
  //corpo
  toto.setColor(1.0,0.0,0.0,1.0);
  toto.putBox(13,26,20,30,13,26);
  //coxas
  toto.putEllipsoid(17,18,19,3,5,4);
  toto.putEllipsoid(21,18,19,3,5,4);
  //joelho
  toto.setColor(1.0,1.0,0.0,1.0);
  toto.putBox(15,24,12,15,16,23);
  //pernas
  toto.setColor(1.0,0.0,0.0,1.0);
  toto.putEllipsoid(17,8,19,2,5,2);
  toto.putEllipsoid(21,8,19,2,5,2);
  //chute
  toto.setColor(0.0,0.0,0.0,1.0);
  toto.putBox(15,24,1,7,15,24);
  //bastao
  toto.putEllipsoid(19,25,19,39,3,3);
  //bola
  toto.setColor(1.0,1.0,1.0,1.0);
  toto.putSphere(4,4,4,5);
  //número "11" frente
  toto.putVoxel(21,25,13);
  toto.putBox(20,21,23,27,13,14);
  toto.putVoxel(18,25,13);
  toto.putBox(17,18,23,27,13,14);
  //número "11" atrás
  toto.putVoxel(20,25,25);
  toto.putBox(21,22,23,27,25,26);
  toto.putVoxel(17,25,25);
  toto.putBox(18,19,23,27,25,26);
  
  toto.writeOFF((const char*)"toto.off");
  
  return 0;
}
//*/

/*
  Sculptor teste(20,20,20);

  teste.setColor(1.0,1.0,1.0,1.0);
  teste.putBox(0,5,0,5,0,5);
  teste.cutBox(1,4,1,5,1,5);
  teste.setColor(1.0,0.0,0.0,0.1);
  teste.putVoxel(0,0,5);
  teste.cutVoxel(0,0,0);
  teste.setColor(0.0,0.0,0.5,0.5);
  teste.putSphere(14,14,14,5);
  teste.cutSphere(16,14,14,3);
  teste.setColor(0.0,1.0,0.0,1.0);
  teste.putEllipsoid(11,4,11,4,3,4);
  teste.cutEllipsoid(11,4,11,3,3,5);
  
  teste.writeOFF((const char*)"teste.off");

  return 0;
}
*/
