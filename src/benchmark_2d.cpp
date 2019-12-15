#include <iostream>
#include "multi_arrays_dim2.h"
#include <benchmark/benchmark.h>

void b_speedtest2d_m1(benchmark::State& state){
  SpeedTest bst = SpeedTest(10);
  for (auto _: state){
    bst.speedtest2d_m1();
  }
}

void b_speedtest2d_m2(benchmark::State& state){
  SpeedTest bst = SpeedTest(10);
  for (auto _: state){
    bst.speedtest2d_m2();
  }
}

void b_speedtest2d_m3(benchmark::State& state){
  SpeedTest bst = SpeedTest(10);
  for (auto _: state){
    bst.speedtest2d_m3();
  }
}

void b_speedtest2d_m4(benchmark::State& state){
  SpeedTest bst = SpeedTest(10);
  for (auto _: state){
    bst.speedtest2d_m4();
  }
}

void b_speedtest2d_m5(benchmark::State& state){
  SpeedTest bst = SpeedTest(10);
  for (auto _: state){
    bst.speedtest2d_m5();
  }
}


BENCHMARK(b_speedtest2d_m1);
BENCHMARK(b_speedtest2d_m2);
BENCHMARK(b_speedtest2d_m3);
BENCHMARK(b_speedtest2d_m4);
BENCHMARK(b_speedtest2d_m5);
//print_methods();
//BENCHMARK_MAIN();

int main()
{
  cout<<"---------------------------------------------------------"<<endl;
  cout<<"Methods"<<endl;
  cout<<"---------------------------------------------------------"<<endl;
  cout<<"m1: Mapping to a 1D array using pre-processor directive"<<endl;
  cout<<"m2: Mapping to a 1D array using inline function"<<endl;
  cout<<"m3: Packing and unpacking 1D array in same order"<<endl;
  cout<<"m4: Using vectors"<<endl;
  cout<<"m5: Using multi-dimensional pointers"<<endl;
  cout<<"---------------------------------------------------------"<<endl;
   //::benchmark::Initialize(&argc, argv);
   ::benchmark::RunSpecifiedBenchmarks();
}
