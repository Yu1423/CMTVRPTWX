//  Copyright © 2023 Yu Yang. All rights reserved.


#include <iostream>
#include <iomanip>
#include "CMTVRPTW_EXT.hpp" 
#define PRINTDEC 2




int main(){
	

	GRBenv* env1;
	GRBenv* env2;
	GRBloadenv(&env1, NULL);
	GRBloadenv(&env2, NULL);
	std::cout << std::setprecision(PRINTDEC) << std::fixed << "\n" << std::endl;


	// use this constructor if it's a CMTVRPTW instance
//	CMTVRPTW_EXT  mtvrp(env1, env2, true, "./Solomon/", "C201.txt", "CMTVRPTW", 100, 8, 100);


	// use this constructor if it's a CMTVRPTW-LT instance
	CMTVRPTW_EXT  mtvrp(env1, env2, true, "./Solomon/", "C201.txt", "CMTVRPTW-LT", 70, 6, 100, 0.2);
//
//
//	// use this constructor if it's a CMTVRPTW-R instance
//	CMTVRPTW_EXT  mtvrp(env1, env2, true, "./Release/", "C201R0.25.txt", "CMTVRPTW-R", 70,  6, 100);
//
//
//	// default is 3h, i.e, 10800s, change if you would like to use a different time limit
//	mtvrp.changeTimeLimit(10800);
//
//
//	// default is 8 threads, change if you would like to more or fewer threads
//	mtvrp.changeThreads(8);
//

	// call this method function to solve the instance
	mtvrp.solve();


	GRBfreeenv(env1);
	GRBfreeenv(env2);
	return 0;
}

