# DeLuxing
The libcmtvrptwX.a is linkable C++ library compiled for Linux to solve the capacitated multi-trip vehicle routing problem with time windows (CMTVRPTW), CMTVRPTW with loading times (CMTVRPTW-LT), and CMTVRPTW with release dates (CMTVRPTW-R). It applies the novel variable fixing method as well as several extensions developed in the paper titled [_DeLuxing: Deep Lagrangian Underestimate Fixing for
Column-Generation-Based Exact Methods_](https://optimization-online.org/?p=24217). CVRPSEP (an open-source cut separation package) and Gurobi (a third-party commercial MIP solver) are required. Please cite our paper if you use the library for your research. Please cite our paper if you use the library for your research.

An example main.cpp is included to show how to use the library. Depending on which variant you would like to solve, different arguments should be fed into the class constructor. The first 6 arguments are universal for all variants. The first 2 are the two Gurobi environment pointers which should be initialized by the GRBloadenv function first. The 3rd is a boolean variable controlling the output, and detailed information in the solution process will be printed out if it's set to true. The next two arguments are the folder name that contains the instances to be solved and the file name of the instance. The 6th one is a string that specifies the problem type, whose possible options are "CMTVRPTW", "CMTVRPTW-LT", and "CMTVRPTW-R". For the CMTVRPTW and the CMTVRPTW-R, the 7th to 9th arguments are the number of customers, the number of vehicles, and the vehicle capacity. For the CMTVRPTW-LT, it has an extra argument, i.e., the 10th, is the loadfactor which is the proportion of the loading time to the service time, and is set to 0.2 by default. 

Once an object is initialized, the problem can be solved by calling the solve() method. The source code can be compiled by the following g++ command on Linux.

_g++ -I full/path/to/your/Gurobi/header/folder main.cpp CMTVRPTW_EXT.hpp -L full/path/to/your/Gurobi/lib/folder -L full/path/to/your/libcmtvrptwX.a/folder -lgurobi91 -lcmtvrptwX -lcvrpsep -O3 -std=c++11 -o run_

All instances used in the paper are provided here. When the problem type is one of "CMTVRPTW", and "CMTVRPTW-LT", the corresponding instances are in the folder named "Data/Solomon" or "Data/Homberger". When it's "CMTVRPTW-R", the folder named "Data/Release" or "Data/Release_Large" should be used.
