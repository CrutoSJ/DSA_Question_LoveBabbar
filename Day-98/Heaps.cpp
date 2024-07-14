// #Question:-

// Implement MaxHeap - insertion, deletion, heapify, Build heap, heap Sort & it's stl(priority queue)

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
        int size;
        int arr[100];

        heap(){
            arr[0] = -1;
            size=0;
        }

        void insertion(int data){
            int index = ++size;
            arr[size] = data;

            while(index>1){
                int parent = index/2;
                if(arr[parent] > arr[index]){
                    return ;
                } else if(arr[parent] < arr[index]){
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
            }
        }

        void deletion(){
            if(size==0){
                cout << "Nothing in heap" << endl;
                return ;
            }

            arr[1] = arr[size];
            size--;

            int i=1;
            while(i<size){
                int left = 2*i;
                int right = 2*i + 1;

                if(left < size  && arr[i] < arr[left]){
                    swap(arr[i], arr[left]);
                    i  = left;
                }
                else if(right < size && arr[i] < arr[right]){
                    swap(arr[i], arr[right]);
                    i = right;
                }
                else{
                    return ;
                }
            }
        }

        void print(){
            cout << "Printing the max heap" << endl;
            for(int i=1; i<=size; i++){
                cout << arr[i] << " ";
            }cout << endl;
        }
};

void heapify(int arr[], int n, int i){
            int largest = i;
            
            int left = 2*i;
            int right = 2*i + 1;

            if(left <= n && arr[largest] < arr[left]){
                largest = left;
            }
            if(right <= n && arr[largest] < arr[right]){
                largest = right;
            }

            if(largest != i){
                swap(arr[i], arr[largest]);
                heapify(arr, n, largest);
            }

};

void heapSort(int arr[], int n){
    int size = n;

    while(size>1){
        //step 1 -> swap 1 with n-1;

        swap(arr[1], arr[size]);
        size--;

        //step 2:-
        //call the heapify function for finding the correct index
        heapify(arr, size, 1);
    }
};

int main(){

    heap h;

    h.insertion(50);
    h.insertion(55);
    h.insertion(53);
    h.insertion(52);
    h.insertion(54);

    h.print();

    h.deletion();

    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i=n/2; i>0; i--){
        heapify(arr, n, i);
    }
    cout << "printing after heapify" << endl;
    for(int i=1; i<=n; i++){
        cout << arr[i] << " ";
    } cout << endl;

    heapSort(arr,n);

    cout << "printing after heapSort" << endl;
    for(int i=1; i<=n; i++){
        cout << arr[i] << " ";
    } cout << endl;


    cout << "Printing/Using stl for heaps"<< endl;

    //max heap:-

    cout << "This is max heap" << endl;

    priority_queue<int>q;

    q.push(45);
    q.push(43);
    q.push(12);
    q.push(70);
    q.push(6);

    cout << "Top Element: " << q.top() << endl;
    q.pop();

    cout << "Top Element: " << q.top() << endl;

    if(q.empty()) cout << "Heap is empty" << endl;
    else cout << "Not empty " << endl;

    //Min Heap:-

    cout << "This is Min Heap:-" << endl;

    priority_queue<int, vector<int>, greater<int>>Minq;

    Minq.push(45);
    Minq.push(43);
    Minq.push(12);
    Minq.push(70);
    Minq.push(6);

    cout << "Top Element: " << Minq.top() << endl;
    Minq.pop();

    cout << "Top Element: " << Minq.top() << endl;

    if(q.empty()) cout << "Heap is empty" << endl;
    else cout << "Not empty " << endl;


    return 0;
}