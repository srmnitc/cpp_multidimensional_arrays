
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
#include "multi_arrays_dim3.h"

using namespace std;

SpeedTest::SpeedTest(int nloops){
  int size = dim*dim*dim;
  test = new int[size];

  testp = new int**[dim];
  for(int i=0; i< dim; i++){
    testp[i] = new int*[dim];
    for(int j=0; j<dim; j++){
      testp[i][j] = new int[dim];
    }
  }

  this->nloops = nloops;

}

SpeedTest::~SpeedTest(){
  delete [] test;

  for(int i = 0; i < dim; ++i) {
    for(int j=0; j<dim; j++){
      delete [] testp[i][j];
    }
    delete [] testp[i];
  }
  delete [] testp;
}

void SpeedTest::speedtest_m1(){

  for(int n=0; n<nloops; n++){
    for(int i=0; i<dim; i++){
      for(int j=0; j<dim; j++){
        for(int k=0; k<dim; k++)
          test[loc(i, j, k)] = 1;
      }
    }
  }
  for(int n=0; n<nloops; n++){
    for(int i=0; i<dim; i++){
      for(int j=0; j<dim; j++){
        for(int k=0; k<dim; k++)
          test[loc(i, j, k)]-=1;
      }
    }
  }

}

void SpeedTest::speedtest_m2(){

  for(int n=0; n<nloops; n++){
    for(int i=0; i<dim; i++){
      for(int j=0; j<dim; j++){
        for(int k=0; k<dim; k++)
          test[floc(i, j, k)] = 1;
      }
    }
  }
  for(int n=0; n<nloops; n++){
    for(int i=0; i<dim; i++){
      for(int j=0; j<dim; j++){
        for(int k=0; k<dim; k++)
          test[floc(i, j, k)]-=1;;
      }
    }
  }

}

void SpeedTest::speedtest_m3(){

  for(int n=0; n<nloops; n++){
    int count = 0;
    for(int i=0; i<dim; i++){
      for(int j=0; j<dim; j++){
        for(int k=0; k<dim; k++){
          test[count] = 1;
          count++;
        }
      }
    }
  }
  for(int n=0; n<nloops; n++){
    int count = 0;
    for(int i=0; i<dim; i++){
      for(int j=0; j<dim; j++){
        for(int k=0; k<dim; k++){
          test[count]-=1;
          count++;
        }
      }
    }
  }

}

void SpeedTest::speedtest_m4(){

  vector<int> temp;
  vector<vector<int>> tempb;

  for(int n=0; n<nloops; n++){
    for(int i=0; i<dim; i++){
      tempb.clear();
      for(int j=0; j<dim; j++){
        temp.clear();
        for(int k=0; k<dim; k++){
          temp.emplace_back(1);
        }
        tempb.emplace_back(temp);
      }
      testv.emplace_back(tempb);
    }
  }
  for(int n=0; n<nloops; n++){
    for(int i=0; i<dim; i++){
      for(int j=0; j<dim; j++){
        for(int k=0; k<dim; k++)
          testv[i][j][k]-=1;
      }
    }
  }

}

void SpeedTest::speedtest_m5(){

    for(int n=0; n<nloops; n++){
      for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
          for(int k=0; k<dim; k++)
            testp[i][j][k] = 1;
        }
      }
    }
    for(int n=0; n<nloops; n++){
      for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
          for(int k=0; k<dim; k++)
            testp[i][j][k]-=1;
        }
      }
    }
}
