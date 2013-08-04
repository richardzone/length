#ifndef LENGTH_H
#define LENGTH_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cassert>
#include <map>

inline void assure(std::ifstream& in, 
	const std::string& filename = "") {
		using namespace std;
		if(!in) {
			fprintf(stderr, "Could not open file %s\n",
				filename.c_str());
			exit(EXIT_FAILURE);
		}
}

inline void assure(std::ofstream& out, 
	const std::string& filename = "") {
		using namespace std;
		if(!out) {
			fprintf(stderr, "Could not open file %s\n", 
				filename.c_str());
			exit(EXIT_FAILURE);
		}
}

#endif