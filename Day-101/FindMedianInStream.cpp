// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    
    double median = 0;
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int>>minHeap;
    
    public:
    int signum(int a, int b){
        if(a==b){
            return 0;
        } else if(a>b){
            return 1;
        } else{
            return -1;
        }
    }
    
    //Function to insert heap.
    void insertHeap(int &x)
    {
        switch(signum(maxHeap.size(), minHeap.size())){
            case 0:
                if(x>median){
                    minHeap.push(x);
                    median = getMedian();
                } else{
                    maxHeap.push(x);
                    median = getMedian();
                }
                break;
                
            case 1:
                if(x>median){
                    minHeap.push(x);
                    median = getMedian();
                }
                else{
                    balanceHeaps();
                    maxHeap.push(x);
                    median = getMedian(); 
                }
                break;
                
            case -1:
                if(x>median){
                    balanceHeaps();
                    minHeap.push(x);
                    median = getMedian();
                }
                else{
                    maxHeap.push(x);
                    median = getMedian();
                }
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        switch(signum(maxHeap.size(), minHeap.size())){
            case 1:
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                break;
                
            case -1:
                maxHeap.push(minHeap.top());
                minHeap.pop();
                break;
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        switch(signum(maxHeap.size(), minHeap.size())){
            case 0:
                return (minHeap.top() + maxHeap.top())/2;
                break;
                
            case 1:
                return maxHeap.top();
                break;
                
            case -1:
                return minHeap.top();
                break;
        }
        
    }
};

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}