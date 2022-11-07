#include "sculptor.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

  Sculptor :: Sculptor(int _nx, int _ny, int _nz){
    nx = _ny;
    ny = _ny;
    nz = _nz;
    
    v = new Voxel**[nx];

    for(int i=0; i<nx; i++){
      v[i] = new Voxel*[ny];
      
      for(int j=0; j<nx; j++){
        for(int k=0; k<ny; k++){
          v[i][j] = new Voxel[nz];
        }
      }
    }
  }

  Sculptor :: ~Sculptor(){
    for(int i=0; i<nx; i++){
      for(int j=0; j<ny; j++){
        delete [] v[i][j];
      }
    }
    
    for(int i=0; i<nx; i++){
      delete [] v[i];
    }
    
    delete [] v; 
  }

  void Sculptor :: setColor(float r, float g, float b, float alpha){
    this -> r = r;
    this -> g = g;
    this -> b = b;
    this -> a = alpha; 
  }

  void Sculptor :: putVoxel(int nx, int ny, int nz){
    v[nx][ny][nz].show = true;
    v[nx][ny][nz].r = r;
    v[nx][ny][nz].g = g;
    v[nx][ny][nz].b = b;
    v[nx][ny][nz].a = a;
  }

  void Sculptor :: cutVoxel(int nx, int ny, int nz){
    v[nx][ny][nz].show = false;
  }

  void Sculptor :: putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i=x0; i<x1; i++){
      for(int j=y0; j<y1; j++){
        for(int k=z0; k<z1; k++){
          v[i][j][k].show = true;
          v[i][j][k].r = r;
          v[i][j][k].g = g;
          v[i][j][k].b = b;
          v[i][j][k].a = a;
        }
      }
    }
  }

  void Sculptor :: cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i=x0; i<x1; i++){
      for(int j=y0; j<y1; j++){
        for(int k=z0; k<z1; k++){
          v[i][j][k].show = false;
        }
      }
    }
  }
    
  void Sculptor :: putSphere(int xcenter, int ycenter, int zcenter, int radius){
    float x2, y2, z2;
    for(int i=0; i<nx; i++){
      for(int j=0; j<ny; j++){
        for(int k=0; k<nz; k++){
          
          x2 = (float)(i-xcenter)*(float)(i-xcenter);
          y2 = (float)(j-ycenter)*(float)(j-ycenter);
          z2 = (float)(k-zcenter)*(float)(k-zcenter);

          if((x2+y2+z2) < (radius*radius)){
            v[i][j][k].show = true;
            v[i][j][k].r = r;
            v[i][j][k].g = g;
            v[i][j][k].b = b;
            v[i][j][k].a = a; 
          }
        }
      }
    }
  }

  void Sculptor :: cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    float X2, Y2, Z2;
    for(int i=0; i<nx; i++){
      for(int j=0; j<ny; j++){
        for(int k=0; k<nz; k++){
          
          X2 = (float)(i-xcenter)*(float)(i-xcenter);
          Y2 = (float)(j-ycenter)*(float)(j-ycenter);
          Z2 = (float)(k-zcenter)*(float)(k-zcenter);
          
          if((X2+Y2+Z2) < (radius*radius))
            v[i][j][k].show = false;
        }
      }
    }
  }

  void Sculptor :: putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    float X, Y, Z;
    for(int i=0; i<nx; i++){
      for(int j=0; j<ny; j++){
        for(int k=0; k<nz; k++){
          
          X = ((float)(i-xcenter)*(float)(i-xcenter))/(rx*rx);
          Y = ((float)(j-ycenter)*(float)(j-ycenter))/(ry*ry);
          Z = ((float)(k-zcenter)*(float)(k-zcenter))/(rz*rz);

          if((X+Y+Z) < 1){
            v[i][j][k].show = true;
            v[i][j][k].r = r;
            v[i][j][k].g = g;
            v[i][j][k].b = b;
            v[i][j][k].a = a; 
          }
        }
      }
    }
  }

  void Sculptor :: cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    float Xe, Ye, Ze;
    for(int i=0; i<nx; i++){
      for(int j=0; j<ny; j++){
        for(int k=0; k<nz; k++){
          
          Xe = ((float)(i-xcenter)*(float)(i-xcenter))/(rx*rx);
          Ye = ((float)(j-ycenter)*(float)(j-ycenter))/(ry*ry);
          Ze = ((float)(k-zcenter)*(float)(k-zcenter))/(rz*rz);

          if((Xe+Ye+Ze) <1){
            v[i][j][k].show = false;
          }
        }
      }
    }
  }

  void Sculptor :: writeOFF(const char *filename){
    ofstream fout;
    
    fixed(fout); // para corrigir precisão de casas decimais no arquivo .OFF

    int NVertices = 0;
    int NFaces = 0;
    int aux = 0;
    fout.open(filename);

    fout<<"OFF"<<endl;

    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if(v[i][j][k].show == true){
                    NVertices = NVertices + 8;
                    NFaces = NFaces + 6;
                }
            }
        }
    }

    fout<<NVertices<<" "<<NFaces<<" "<<0<<endl;

    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if(v[i][j][k].show == true){

                        fout<< i-0.5 <<" "<< j+0.5 <<" "<< k-0.5 <<endl;
                        fout<< i-0.5 <<" "<< j-0.5 <<" "<< k-0.5 <<endl;
                        fout<< i+0.5 <<" "<< j-0.5 <<" "<< k-0.5 <<endl;
                        fout<< i+0.5 <<" "<< j+0.5 <<" "<< k-0.5 <<endl;
                        fout<< i-0.5 <<" "<< j+0.5 <<" "<< k+0.5 <<endl;
                        fout<< i-0.5 <<" "<< j-0.5 <<" "<< k+0.5 <<endl;
                        fout<< i+0.5 <<" "<< j-0.5 <<" "<< k+0.5 <<endl;
                        fout<< i+0.5 <<" "<< j+0.5 <<" "<< k+0.5 <<endl;

                }
            }
        }
    }

    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if(v[i][j][k].show == true){
                    fout<<4<<" "<<aux+0<<" "<<aux+3<<" "<<aux+2<<" "<<aux+1<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<4<<" "<<aux+4<<" "<<aux+5<<" "<<aux+6<<" "<<aux+7<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<4<<" "<<aux+0<<" "<<aux+1<<" "<<aux+5<<" "<<aux+4<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<4<<" "<<aux+0<<" "<<aux+4<<" "<<aux+7<<" "<<aux+3<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<4<<" "<<aux+3<<" "<<aux+7<<" "<<aux+6<<" "<<aux+2<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<4<<" "<<aux+1<<" "<<aux+2<<" "<<aux+6<<" "<<aux+5<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    aux = aux+8;
                }
            }
        }
    }

  fout.close();
}
