
/**
In this file, speed tests for various approaches in C++ for multidimensional
arrays are tested.

1. Mapping to 1D - preprocessor directive
2. Mapping to 1D - inline function
3. Vector
4. Array of pointers
*/

#ifndef MULTI_ARRAYS_H_
#define MULTI_ARRAYS_H_

#include <iostream>
#include <vector>
#include <chrono>

#define loc(l, m) ((50)*(l) + (m))

using namespace std;

inline int floc(int &l, int &m){
  return (50*l + m);
}


class SpeedTest{
public:
  int dim = 50;
  int nloops;
  int *test;
  vector<vector<int>> testv;
  int **testp;

  //methods to create arrays
  //in Constructor
  SpeedTest(int);
  ~SpeedTest();

  //speedtest methods
  void speedtest2d_m1();
  void speedtest2d_m2();
  void speedtest2d_m3();
  void speedtest2d_m4();
  void speedtest2d_m5();

};

#endif
