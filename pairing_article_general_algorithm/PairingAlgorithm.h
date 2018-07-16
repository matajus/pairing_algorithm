#ifndef HOME_MATEJ_PAIRINGARTICLE_PAIRING_ALGORITHM_H_
#define HOME_MATEJ_PAIRINGARTICLE_PAIRING_ALGORITHM_H_

#include <iostream>
#include <tuple>
#include <Eigen/Dense>

using Eigen::VectorXi;
using Eigen::MatrixXi;
using namespace std;

enum order {ascending, descending};

class PairingAlgorithm{
	int n, k;
	friend void recordResult(int, int, MatrixXi&); 
	friend void updateTransitivity(MatrixXi&);
	friend void sortMatrix(MatrixXi&);
    friend void updateBuchholz(MatrixXi&);
	friend void sortMatrixGeneralCase(MatrixXi&, int, int);
	
	public:
	PairingAlgorithm(int _n = 0, int _k = 0) : n{_n}, k{_k}{}
	tuple<int, int> topDown(VectorXi);
};

void recordResult(int, int, MatrixXi&);
void updateTransitivity(MatrixXi&);
void sortMatrix(MatrixXi&);
void updateBuchholz(MatrixXi&);
void sortMatrixGeneralCase(MatrixXi&, int, int);

#endif