#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int row=1;
    while(row<=n){
        int space = row-1;
        while(space--){
            cout << " ";
        }
        
        int star=n-row+1;
        int col=1;
        while(col<=star){
            cout <<"*";
            col=col+1;

        }
        cout <<endl;
        row=row+1;
    }
}