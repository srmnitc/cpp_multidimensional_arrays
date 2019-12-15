#!/bin/bash
git clone https://github.com/google/benchmark.git
git clone https://github.com/google/googletest.git benchmark/googletest

#make benchmark
cd benchmark
if [ ! -d "build" ]
then
  mkdir build
fi
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make -j

#make google test separately
cd ../googletest
if [ ! -d "build" ]
then
  mkdir build
fi
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make -j
