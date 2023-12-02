#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int row=1;

    while(row<=n){

        int col =1;
        int no = n-row+1;
        while(col<=no){
            cout<<col;
            
            col=col+1;
        }

        int star = row-1;
        while(star){
            cout << "*";
            star = star -1;
        }

        int star2 = row-1;
        while(star2){
            cout<< "*";
            star2 = star2 -1;
        }

        int col2 =1;
        int no2 = n-row+1;
        int value2 = n-row+1;
        while(col2<=no2){
            cout<<value2;
            value2=value2-1;
            col2=col2+1;
        }
        

        cout << endl;
        row = row+1;
    }
}