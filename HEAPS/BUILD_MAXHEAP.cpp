#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

void MAX_HEAPIFY(int tree[], int index, int n){

    int l = 2 * index + 1;
    int r = 2 * index + 2;
    int largest;

    if(l < n && tree[l] > tree[index])
        largest = l;
    else
        largest = index;

    if(r < n && tree[r] > tree[largest])
        largest = r;

    if(largest != index){
        swap(tree[index], tree[largest]);
        MAX_HEAPIFY(tree, largest, n);
    }
}

void build_maxheap(int tree[], int n){
    int last_internal_node = floor(n/2)-1;
    for(int i = last_internal_node; i >= 0; i--){
        MAX_HEAPIFY(tree, i, n);
    }
}
int main(){

    int n;
    cout << "Enter the number of elements in tree array : ";
    cin >> n;
    /*
        if i is the parent node then its 
        left child = 2*i + 1
        right child = 2*i + 2
    */
    int tree[n];
    cout << "enter the tree elements : \n";
    for(int i=0;i<n;i++)
        cin >> tree[i];

    build_maxheap(tree, n);

    cout << "The MAX heap is : \n ";
    for(int i=0;i<n;i++)
        cout << tree[i] << " ";
}