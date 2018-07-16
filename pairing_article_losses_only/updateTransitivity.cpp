#include "PairingAlgorithm.h"

void updateTransitivity(MatrixXi& M){
	int n = M.rows();
	bool h{false};
	
	do {
		h=false;
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				for(int k=0; k<n; ++k)
					if(M(i,j)==1 && M(j,k)==1 && M(i,k)==-1){
						recordResult(i, k, M);
						h = true;
					}			
	}	while ( h );
}