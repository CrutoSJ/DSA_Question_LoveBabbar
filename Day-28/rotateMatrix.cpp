// #Question:-

// https://www.codingninjas.com/studio/problems/rotate-the-matrix_6825090

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &mat){
	int n = mat.size();
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            swap(mat[i][j], mat[j][i]);
        }
    }

    for(int i=0; i<n; i++){
        reverse(mat[i].begin(), mat[i].end());
    }
	
}