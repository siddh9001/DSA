#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

void MIN_HEAPIFY(int tree[], int index, int n){

    int l = 2 * index + 1;
    int r = 2 * index + 2;
    int smallest;

    if(l < n && tree[l] < tree[index])
        smallest = l;
    else
        smallest = index;

    if(r < n && tree[r] < tree[smallest])
        smallest = r;

    if(smallest != index){
        swap(tree[index], tree[smallest]);
        MIN_HEAPIFY(tree, smallest, n);
    }
}

void build_minheap(int tree[], int n){
    int last_internal_node = floor(n/2)-1;
    for(int i = last_internal_node; i >= 0; i--){
        MIN_HEAPIFY(tree, i, n);
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

    build_minheap(tree, n);

    cout << "The MIN heap is : \n ";
    for(int i=0;i<n;i++)
        cout << tree[i] << " ";
}