#ifndef HOME_MATEJ_PAIRINGARTICLE_PAIRING_ALGORITHM_H_
#define HOME_MATEJ_PAIRINGARTICLE_PAIRING_ALGORITHM_H_

#include <iostream>
#include <tuple>
#include <vector> // for 2D vector
#include <algorithm> // for sort()
#include <Eigen/Dense>

using Eigen::VectorXi;
using Eigen::MatrixXi;
using namespace std;

class PairingAlgorithm{
	int n, k;
	friend void recordResult(int, int, vector< vector<int> >&, MatrixXi&, int); 
	friend void updateTransitivity(vector< vector<int> >&, MatrixXi&, int);
	// friend void sortMatrix(MatrixXi&, int);
	friend void sortLookup(vector< vector<int> >&);
	
	public:
	PairingAlgorithm(int _n = 0, int _k = 0) : n{_n}, k{_k}{}
	tuple<int, int> topDown(VectorXi);
};

void recordResult(int, int, vector< vector<int> >&, MatrixXi&, int);
void updateTransitivity(vector< vector<int> >&, MatrixXi&, int);
//void sortMatrix(MatrixXi&, int);
void sortLookup(vector< vector<int> >&);

#endif