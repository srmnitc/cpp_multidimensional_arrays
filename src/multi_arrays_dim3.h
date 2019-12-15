
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

#define loc(l, m, n) ((50)*(50)*(l) + (50)*(m) + (n))

using namespace std;

inline int floc(int &l, int &m, int &n){
  return (50*50*l + 50*m + n);
}


class SpeedTest{
public:
  int dim = 50;
  int nloops;
  int *test;
  vector<vector<vector<int>>> testv;
  int ***testp;

  //methods to create arrays
  //in Constructor
  SpeedTest(int);
  ~SpeedTest();

  //speedtest methods
  void speedtest_m1();
  void speedtest_m2();
  void speedtest_m3();
  void speedtest_m4();
  void speedtest_m5();

};

#endif
