#include "PairingAlgorithm.h"

tuple<int, int> roundsAndMatches(int rounds, int matches){
	return make_tuple(rounds, matches);	
}

tuple<int, int> PairingAlgorithm::topDown(VectorXi V){
	int m{0}, top_k{0};
	MatrixXi M(n, n+3); //by default initialized to 0 but for some reason it gets crazy at some point so we need to assign
						//it 0 value anyway
	vector< vector<int> > lookup_table(n, vector<int>(2, 0)); 
	
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			M(i,j) = -1;
		}
		M(i,n) = 0;		//is paired flag
		M(i,n+1) = 1;	//is active flag
		M(i,n+2) = V(i);
		// lookup_table[i][0] = 0; //number of losses
		lookup_table[i][1] = i; //starting position		
	}

	for(int r=1; r<=n; ++r){
	//	cout << "===================================" << endl;
	//	cout << "ROUND " << r << endl;
	//	cout << "===================================" << endl;
		for(int i=0; i<n-1; ++i){
			if(M(lookup_table[i][1],n)==0 && M(lookup_table[i][1],n+1)==1){	//active and not yet paired
				for(int j=i+1; j<n; ++j){
					if(M(lookup_table[j][1],n)==0 && M(lookup_table[j][1],n+1)==1 && M(lookup_table[i][1],lookup_table[j][1])==-1){
						++m;
						M(lookup_table[j][1],n) = 1;
						recordResult(i,j,lookup_table,M,n);
						break;
					}
				}
			}
		}
		
		sortLookup(lookup_table);
		updateTransitivity(lookup_table, M, n);	
		sortLookup(lookup_table);	
		for(int i=0; i<n; ++i) M(i,n) = 0;
		
		for(int i=0; i<n-1; ++i){
			if(M(lookup_table[i][1],n+1)==1){
				if(lookup_table[i][0] < lookup_table[i+1][0]){
					++top_k;
					M(lookup_table[i][1],n+1) = 0;
					if(top_k==k){
						return roundsAndMatches(r, m);
					}
				} else { break;	}
			}
		}

		if(top_k==n-1){
			return roundsAndMatches(r, m);		
		}
	}
}


	
			
	
	
