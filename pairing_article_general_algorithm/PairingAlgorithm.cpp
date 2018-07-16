#include "PairingAlgorithm.h"

tuple<int, int> roundsAndMatches(int rounds, int matches){
	return make_tuple(rounds, matches);	
}

/*tuple<int, int> PairingAlgorithm::topDown(VectorXi V){
	int m{0}, top_k{0};
	MatrixXi M(n, n+5); //by default initialized to 0
	
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			M(i,j) = -1;
		}
		M(i,n) = 0;		//number of losses
		M(i,n+1) = 0;	//is paired flag
		M(i,n+2) = 1;	//is active flag
		M(i,n+3) = V(i);
		M(i,n+4) = i;	//original indices
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
		sortMatrix(M);	//sort by losses ascending

		
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
} */

//IN CASE WE WANT TO USE WINS AND BUCHHOLZ WE SHOULD REMOVE THE COMMENT AND USE THIS.
//ABOVE CODE IS MISSING A FEW COLUMNS TO MAKE COMPUTATION MORE EFFICIENT

tuple<int, int> PairingAlgorithm::topDown(VectorXi V){
	int m{0}, top_k{0};
	MatrixXi M(n, n+7), N(n, n+7); //by default initialized to 0
	
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			M(i,j) = -1;
		}
		M(i,n) = 0;  //number of wins
		M(i,n+1) = 0; //number of losses
		M(i,n+2) = 0; //Buchholz
		M(i,n+3) = 0; //is paired flag
		M(i,n+4) = 1; //is active flat
		M(i,n+5) = V(i); 
		M(i,n+6) = i;	//original indices
	}
	
	for(int r=1; r<=n; ++r){
	//	cout << "===================================" << endl;
	//	cout << "ROUND " << r << endl;
	//	cout << "===================================" << endl;
		for(int i=0; i<n-1; ++i){
			if(M(i,n+3)==0 && M(i,n+4)==1){	//active and not yet paired
				for(int j=i+1; j<n; ++j){
					if(M(j,n+3)==0 && M(j,n+4)==1 && M(i,j)==-1){
						++m;
						M(j,n+3) = 1;
						recordResult(i,j,M);
						break;
					}
				}
			}
		}
		
		updateTransitivity(M);
		updateBuchholz(M);
		for(int i=0; i<n; ++i) M(i,n+3) = 0;
		sortMatrixGeneralCase(M, n+2, order::descending);	//sort by Buchholz
		sortMatrixGeneralCase(M, n, order::descending);	//sort by total score
		sortMatrixGeneralCase(M, n+1, order::ascending);	//sort by losses
		for(int i=0; i<n-1; ++i){
			if(M(i,n+4)==1){
				if(M(i,n+1) < M(i+1,n+1)){
					++top_k;
					M(i,n+4) = 0;
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



	
			
	
	