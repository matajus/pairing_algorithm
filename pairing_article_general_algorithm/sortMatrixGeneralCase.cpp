#include "PairingAlgorithm.h"

void sortRowsGC(MatrixXi &M, const VectorXi &V){
	int n=M.rows();
	VectorXi pom(n);
	for(int i=0; i<n; ++i) pom[i] = i; 
	
	for(int i=0; i<n; ++i){
		int j=i;
		while(V[i] != pom[j]) ++j;
		if(i == j) continue;
		M.row(i).swap(M.row(j));
		pom.row(i).swap(pom.row(j));	
	}
}

void sortColumnsGC(MatrixXi &M, const VectorXi &V){
	int n=M.rows();
	VectorXi pom(n);
	for(int i=0; i<n; ++i) pom[i] = i; 
	
	for(int i=0; i<n; ++i){
		int j=i;
		while(V[i] != pom[j]) ++j;
		if(i == j) continue;
		M.col(i).swap(M.col(j));
		pom.row(i).swap(pom.row(j));	
	}
}

VectorXi sortIndicesGC(const VectorXi &comparison_vector, int order) {
	int size = comparison_vector.size();
	VectorXi index(size);
	for(int i=0; i<size; ++i){
		index[i] = i;
	}
	
	switch(order){
		case ascending 	:	sort(index.data(), index.data()+index.size(),
								[&comparison_vector, &index, &size](int i1, int i2) {
									if(i1 < size && i2 < size){
										return comparison_vector[i1] < comparison_vector[i2];
									}
								});
							break;
			
		case descending :	sort(index.data(), index.data()+index.size(),
								[&comparison_vector, &index, &size](int i1, int i2) {
									if(i1 < size && i2 < size){
										return comparison_vector[i1] > comparison_vector[i2];
									}
								});
							break;
	}
	return index;
}

void sortMatrixGeneralCase(MatrixXi &M, int comparison_column, int order){
	VectorXi V(M.rows());
	V = sortIndicesGC(M.col(comparison_column), order);
	sortColumnsGC(M, V);
	sortRowsGC(M, V);
}