
CC = gcc
CXX = g++
CFLAGS = -g -std=c++11 -O3 -lm -Wall

#paths for Benchmark framework
BENCHMARK_INCLUDE = ../utils/benchmark/include
BENCHMARK_LIB_PATH = ../utils/benchmark/build/src
BENCHMARK_LIB = $(BENCHMARK_LIB_PATH)/libbenchmark.a
#test executable filename
BENCHMARK_EXEC = main_benchmark

benchmark-2d:
	$(CXX) benchmark_2d.cpp multi_arrays_dim2.cpp $(CFLAGS) -isystem $(BENCHMARK_INCLUDE) -L $(BENCHMARK_LIB_PATH) -lbenchmark -lpthread -o $(BENCHMARK_EXEC)
	./$(BENCHMARK_EXEC)
