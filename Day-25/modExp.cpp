// #Question:-

// https://www.codingninjas.com/studio/problems/modular-exponentiation_1082146

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	int res = 1;

	while(n>0){
		if(n&1){
			//odd wala case;
			res = ( 1LL * (res) * (x)%m)%m;
            }
		x = (1LL * (x)%m * (x)%m)%m;
		n = n>>1;
	}

	return res;
}