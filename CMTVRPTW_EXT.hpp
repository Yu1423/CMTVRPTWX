//  Copyright © 2023 Yu Yang. All rights reserved.

#ifndef CMTVRPTW_EXT_H
#define CMTVRPTW_EXT_H
#include <sys/time.h>
#include <string>
#include "gurobi_c.h"


class CMTVRPTW;
class CMTVRPTW_LT;
class CMTVRPTW_R;



class CMTVRPTW_EXT
{
	std::string ProbType;
	CMTVRPTW* cmtvrp;
	CMTVRPTW_LT* cmtvrp_lt;
	CMTVRPTW_R* cmtvrp_r;

	
public:
	
	CMTVRPTW_EXT(GRBenv* env1, GRBenv* env2, bool verbose,
			std::string foldername, std::string filename,
			std::string problemtype = "CMTVRPTW",
			int numcsts = 25, int numvehs = 2, int capacity = 100,
			double loadfactor = 0.2);

	~CMTVRPTW_EXT();
	void changeThreads(int );
	void changeTimeLimit(double );
	void solve();
};


double getWallTime();
std::string getFileName(const std::string& s);
std::string addComma(int);


#endif
