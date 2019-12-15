
/**
In this file, speed tests for various approaches in C++ for multidimensional
arrays are tested.

1. Mapping to 1D - preprocessor directive
2. Mapping to 1D - inline function
3. Packing and unpacking
4. Vector
5. Array of pointers
*/

#include <iostream>
#include <vector>
#include <chrono>
#include "multi_arrays_dim2.h"

using namespace std;

SpeedTest::SpeedTest(int nloops){
  int size = dim*dim;
  test = new int[size];

  testp = new int*[dim];
  for(int i = 0; i < dim; ++i)
    testp[i] = new int[dim];

  this->nloops = nloops;

}

SpeedTest::~SpeedTest(){
  delete [] test;

  for(int i = 0; i < dim; ++i) {
      delete [] testp[i];
  }
  delete [] testp;
}

void SpeedTest::speedtest2d_m1(){

  for(int n=0; n<nloops; n++){
    for(int i=0; i<dim; i++){
      for(int j=0; j<dim; j++){
        test[loc(i, j)] = 1;
      }
    }
  }
  for(int n=0; n<nloops; n++){
    for(int i=0; i<dim; i++){
      for(int j=0; j<dim; j++){
        test[loc(i, j)]-=1;
      }
    }
  }

}

void SpeedTest::speedtest2d_m2(){

  for(int n=0; n<nloops; n++){
    for(int i=0; i<dim; i++){
      for(int j=0; j<dim; j++){
        test[floc(i, j)] = 1;
      }
    }
  }
  for(int n=0; n<nloops; n++){
    for(int i=0; i<dim; i++){
      for(int j=0; j<dim; j++){
        test[floc(i, j)]-=1;;
      }
    }
  }

}

void SpeedTest::speedtest2d_m3(){

  for(int n=0; n<nloops; n++){
    int count = 0;
    for(int i=0; i<dim; i++){
      for(int j=0; j<dim; j++){
        test[count] = 1;
        count++;
      }
    }
  }
  for(int n=0; n<nloops; n++){
    int count = 0;
    for(int i=0; i<dim; i++){
      for(int j=0; j<dim; j++){
        test[count]-=1;
        count++;
      }
    }
  }

}

void SpeedTest::speedtest2d_m4(){

  vector<int> temp;

  for(int n=0; n<nloops; n++){
    temp.clear();
    for(int i=0; i<dim; i++){
      for(int j=0; j<dim; j++){
        temp.emplace_back(1);
      }
      testv.emplace_back(temp);
    }
  }
  for(int n=0; n<nloops; n++){
    for(int i=0; i<dim; i++){
      for(int j=0; j<dim; j++){
        testv[i][j]-=1;
      }
    }
  }

}

void SpeedTest::speedtest2d_m5(){

    for(int n=0; n<nloops; n++){
      for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
          testp[i][j] = 1;
        }
      }
    }
    for(int n=0; n<nloops; n++){
      for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
          testp[i][j]-=1;
        }
      }
    }
}
