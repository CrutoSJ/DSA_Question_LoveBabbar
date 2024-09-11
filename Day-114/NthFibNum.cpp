// #Question:-

// Link-> https://www.naukri.com/code360/problems/nth-fibonacci-number_74156

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int num1 = 0;
    int num2 = 1;

    for(int i=2; i<=n; i++){
        int curr = num1+num2;
        num1 = num2;
        num2 = curr;
    }

    cout << num2;
    return 0;
}