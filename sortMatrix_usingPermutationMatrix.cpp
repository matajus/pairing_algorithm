#include "PairingAlgorithm.h"

using Eigen::PermutationWrapper;

//this logic is nice if you really have permutations
//it is hard to utilize it in our case when the number of losses can be the same
//and even in nice examples it is slower than my algorithm so it is not worth to develop it any further
//anyway, it is nice to keep it in mind for the future reference
MatrixXi sortUsingPermutationMatrix(const MatrixXi &M){
	int rows = M.rows();
	int cols = M.cols()-rows;
	VectorXi V(rows);
	V = M.col(rows);
	PermutationWrapper<VectorXi> P = PermutationWrapper<VectorXi> (V);
	MatrixXi sorted(rows,rows+cols);
	sorted << M.block(0,0,rows,rows)*P.transpose(), M.block(0,rows,rows,cols);
	return P * sorted;
}	