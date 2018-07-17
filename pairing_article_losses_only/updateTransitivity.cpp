#include "PairingAlgorithm.h"

void updateTransitivity(vector< vector<int> >& lookup_table, MatrixXi& M, int n){
	bool h{false};
	
	do {
		h=false;
		for(int i=0; i<n-2; ++i)
			for(int j=0; j<n-1; ++j)
				for(int k=0; k<n; ++k)
					if (M(lookup_table[i][1],lookup_table[j][1])==1 && M(lookup_table[j][1],lookup_table[k][1])==1 && M(lookup_table[i][1],lookup_table[k][1])==-1){
						recordResult(i, k, lookup_table, M, n);
						h = true;
		}
	} while ( h );
}