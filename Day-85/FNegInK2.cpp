// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

//Attempt - 02 (with sliding window approach)

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, 
                                            long long int K) {
        int r=0;
        int l=0;
        queue<long long int>q;
        vector<long long>ans;
        
        while(r<N){
            if(A[r]<0){
                q.push(A[r]);
            }
            
            if(r-l+1<K){
                r++;
            }
            
            else if(r-l+1 == K){
                if(q.empty()){
                    ans.push_back(0);
                } 
                
                else{
                    ans.push_back(q.front());
                    if(A[l]==q.front()){
                        q.pop();
                    }
                }
                l++;
                r++;
            }
        }
        return ans;
}
