#include<bits/stdc++.h>
using namespace std;

int CountSetBit(int num){
    int count=0;
    while(num!=0){
        count += num & 1;
        num >>=1;
    }
    return count;
}

int TotalSetBit(int a, int b){
    return CountSetBit(a)+CountSetBit(b);
    

}

int main(){
    int a,b;
    cin >> a >> b;

    cout<< TotalSetBit(a,b);

    return 0;

}

