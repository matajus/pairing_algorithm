#include "PairingAlgorithm.h"

void updateBuchholz(MatrixXi& M){
	int n = M.rows();
	
	for(int i=0; i<n; ++i){
		M(i,n+2)=0;
		for(int j=0; j<n; ++j){
			if(M(i,j) == 1){
				M(i,n+2) += M(j,n);
			}
		}
	}
}