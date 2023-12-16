// #Question:-

// https://www.codingninjas.com/studio/problems/painter's-partition-problem_1089557

// #Solution:-


#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &boards, int k, int mid){

    int Painter = 1;
    int PaintSum = 0;

    for(int i=0; i<boards.size(); i++){
        if(PaintSum + boards[i] <= mid){
            PaintSum += boards[i];
        }

        // this else would do s++ & if() would check all constraints, at the end we
        // paintsum with boards[i]; 
        else{
            Painter++;

            if(Painter > k || boards[i]> mid){
                return false;
            }

            PaintSum = boards[i];
        }
    }

    return true;

}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int s = 0;
    int sum = 0;

    for(int i=0; i<boards.size(); i++){
        sum = sum + boards[i];
    }

    int e = sum;

    int mid = s + (e-s)/2;

    int ans = -1;

    while(s<=e){
        if(isPossible(boards, k, mid)){
            ans = mid;
            e = mid-1;
        }

        else{
            s = mid+1;
        }

        mid = s + (e-s)/2;


    }

    return ans;
}