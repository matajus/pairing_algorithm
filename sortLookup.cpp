#include "PairingAlgorithm.h"

bool sortByLosses( const vector<int>& v1, const vector<int>& v2) {
 return v1[0] < v2[0];
}

void sortLookup(vector< vector<int> >& lookup_table){
	sort(lookup_table.begin(), lookup_table.end(), sortByLosses);
}
