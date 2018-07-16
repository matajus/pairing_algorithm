#include "PairingAlgorithm.h"

tuple<int, int> roundsAndMatches(int rounds, int matches){
	return make_tuple(rounds, matches);	
}

tuple<int, int> PairingAlgorithm::topDown(VectorXi V){
	int m{0}, top_k{0};
	MatrixXi M(n, n+5); //by default initialized to 0 but for some reason it gets crazy at some point so we need to assign
						//it 0 value anyway
	
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			M(i,j) = -1;
		}
		M(i,n) = 0;		//number of losses
		M(i,n+1) = 0;	//is paired flag
		M(i,n+2) = 1;	//is active flag
		M(i,n+3) = V(i);
		M(i,n+4) = i;
	}
	
	for(int r=1; r<=n; ++r){
	//	cout << "===================================" << endl;
	//	cout << "ROUND " << r << endl;
	//	cout << "===================================" << endl;
		for(int i=0; i<n-1; ++i){
			if(M(i,n+1)==0 && M(i,n+2)==1){	//active and not yet paired
				for(int j=i+1; j<n; ++j){
					if(M(j,n+1)==0 && M(j,n+2)==1 && M(i,j)==-1){
						++m;
						M(j,n+1) = 1;
						recordResult(i,j,M);
						break;
					}
				}
			}
		}
		
		updateTransitivity(M);
		
		for(int i=0; i<n; ++i) M(i,n+1) = 0;
		sortMatrix(M);
		
		for(int i=0; i<n-1; ++i){
			if(M(i,n+2)==1){
				if(M(i,n) < M(i+1,n)){
					++top_k;
					M(i,n+2) = 0;
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


	
			
	
	
