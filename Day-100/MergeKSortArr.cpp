// #Question:-

// Link-> https://www.naukri.com/code360/problems/merge-k-sorted-arrays_975379

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        int arrRow;
        int arrCol;

    Node(int data, int rowVal, int colVal){
        this->data = data;
        arrRow = rowVal;
        arrCol = colVal;
    }
};

class compare{
    public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<Node*, vector<Node*>, compare>minH;
    vector<int>ans;

    for(int i=0; i<k; i++){
        Node* curr = new Node(kArrays[i][0], i, 0);
        minH.push(curr);
    }

    while(!minH.empty()){
        Node* temp = minH.top();
        ans.push_back(temp->data);
        minH.pop();

        int i = temp->arrRow;
        int j = temp->arrCol;

        if(j+1 < kArrays[i].size()){
            Node* newEle = new Node(kArrays[i][j+1], i, j+1);
            minH.push(newEle);
        }
    }
    return ans;
}
