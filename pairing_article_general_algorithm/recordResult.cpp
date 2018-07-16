#include "PairingAlgorithm.h"

using Eigen::VectorXi;
using Eigen::MatrixXi;
using namespace std;

/*void recordResult(int i, int j, MatrixXi& M){
	int n = M.rows();
	
	if(M(i,n+3) < M(j,n+3)){
		M(i,j) = 1;
		M(j,i) = 0;
		++M(j,n);
	} else {
		M(j,i) = 1;
		M(i,j) = 0;
		++M(i,n);
	}
} */

//WINS AND BUCHHOLZ INCLUDED
void recordResult(int i, int j, MatrixXi& M){
	int n = M.rows();
	
	if(M(i,n+5) < M(j,n+5)){
		M(i,j) = 1;
		M(j,i) = 0;
		++M(i,n);
		++M(j,n+1);
	} else {
		M(j,i) = 1;
		M(i,j) = 0;
		++M(j,n);
		++M(i,n+1);
	}
}