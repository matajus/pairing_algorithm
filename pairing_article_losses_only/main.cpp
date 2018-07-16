#include <ctime>
#include <algorithm>
#include <vector>
#include "PairingAlgorithm.h"

double meanForHugeValues(vector<int> const& v) { //if we deal with more than 23mil. ints in our vector
    int n = 0;
    double mean = 0.0;
    for (auto x : v) {
        double delta = x - mean;
        mean += delta/++n;
    }
    return mean;
}

double mean(vector<int> const& v) {
    return (double) std::accumulate(v.begin(), v.end(), 0LL) / v.size();
}

int main(){
	clock_t start = clock();
	int n{0}, k{0}, rounds{0}, matches{0};
	vector<int> rounds_vector, matches_vector;
	cout << "Enter the number of players:" << endl;
	cin >> n;
	cout << "Enter the number of winners:" << endl;
	cin >> k;
	PairingAlgorithm pairing_algorithm{n, k};
	
	VectorXi V;
	V.setLinSpaced(n,0,n-1); //(size, beginning, end)
	//sort(V.data(),V.data()+V.size());  //we don't need this since it is already sorted
	//int i{0};
	do {
//		++i;
		tie(rounds, matches) = pairing_algorithm.topDown(V);
		rounds_vector.push_back(rounds);
		matches_vector.push_back(matches);
	} while ( next_permutation(V.data(),V.data()+V.size()) );
	//cout << "The number of permutations is: " << i << endl;
    
	auto min_max_rounds = minmax_element(rounds_vector.begin(), rounds_vector.end()); 
	auto min_max_matches = minmax_element(matches_vector.begin(), matches_vector.end()); 
	cout << "===========================" << endl;
	cout << "n = " << n << " k = " << k << endl;
	cout << "ROUNDS:" << endl;
	cout << "min = " << *min_max_rounds.first << endl;
	cout << "max = " << *min_max_rounds.second << endl;
	cout << "avg = " << mean(rounds_vector) << endl;
//	cout << "MATCHES:" << endl;
//	cout << "min = " << *min_max_matches.first << endl;
//	cout << "max = " << *min_max_matches.second << endl;
//	cout << "avg = " << mean(matches_vector) << endl;
	
	cout << "Execution took: " << (clock() - start) / (double) CLOCKS_PER_SEC << endl;
	return 0;
}
