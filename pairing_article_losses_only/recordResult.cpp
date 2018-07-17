#include "PairingAlgorithm.h"

using Eigen::VectorXi;
using Eigen::MatrixXi;
using namespace std;

void recordResult(int i, int j, vector< vector<int> >& lookup_table, MatrixXi& M, int n){
	if(M(lookup_table[i][1],n+2) < M(lookup_table[j][1],n+2)){
		M(lookup_table[i][1],lookup_table[j][1]) = 1;
		M(lookup_table[j][1],lookup_table[i][1]) = 0;
		++lookup_table[j][0];
	} else {
		M(lookup_table[j][1],lookup_table[i][1]) = 1;
		M(lookup_table[i][1],lookup_table[j][1]) = 0;
		++lookup_table[i][0];
	}
}