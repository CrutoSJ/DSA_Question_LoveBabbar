// #Question:-

// Link -> https://www.codingninjas.com/studio/problems/traffic_6682625

// #Solution:-

#include<bits/stdc++.h>
using namespace std;


bool isPossible(int mid, vector<int> &vehicle, int m)
{
    int zeroCount = 0;

    for (int i = 0; i < mid; i++)
    {
        if (vehicle[i] == 0)
        {
            zeroCount++;
        }
    }

    if (zeroCount <= m)
    {
        return true;
    }

    int j = 0;

    for (int i = mid; i < vehicle.size(); i++)
    {
        if (vehicle[j] == 0)
        {
            zeroCount--;
        }

        if (vehicle[i] == 0)
        {
            zeroCount++;
        }

        if (zeroCount <= m)
        {
            return true;
        }

        j++;
    }

    return false;
}

int findMaximum(vector<int> &vehicle, int n, int m)
{
    int i = 1;
    int j = n;
    int ans = 0;

    while (i <= j)
    {
        int mid = i + (j - i) / 2;

        if (isPossible(mid, vehicle, m))
        {
            ans = mid;
            i = mid + 1;
        }
        else
        {
            j = mid - 1;
        }
    }

    return ans;
}

int traffic(int n, int m, vector<int> vehicle)
{
    // Write your code here.
    return findMaximum(vehicle, n, m);
}
