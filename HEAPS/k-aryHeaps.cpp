#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

void MAX_HEAPIFY(int nary_tree[], int index, int size, int no_of_children){

    int largest = index;
    int start = no_of_children*index+1, end = no_of_children*index+no_of_children;

    if(start < size && end < size){
        for(int i=start;i<=end;i++){
            if(nary_tree[i] > nary_tree[largest])
                largest = i;
        }
    }

    if(largest != index){
        swap(nary_tree[index], nary_tree[largest]);
        MAX_HEAPIFY(nary_tree, largest, size, no_of_children);
    }
}

void BUILD_MAXHEAP(int nary_tree[], int size, int no_of_children){

    if(size < 1){
        cout << "\nHeap UnderFlow!..\n";
        return;
    }

    for(int i=0;i<size;i++){
        MAX_HEAPIFY(nary_tree, i, size, no_of_children);
    }

}

void insert(int nary_tree[], int &size, int no_of_children, int value, int total_possible_nodes){
    if(size+1 > total_possible_nodes){
            cout << "Tree full for the given height\nCannot Insert new Element!!..";
            return;
    }

    size += 1;
    nary_tree[size-1] = value;

    //percolate up
    int i = size-1;
    int parent = (i - 1)/no_of_children;
    while(i > 0  and nary_tree[parent] < nary_tree[i]){
        swap(nary_tree[parent], nary_tree[i]);
        i = parent;
        parent = (i - 1)/no_of_children;
    }

}

int popmax(int nary_tree[], int &size, int no_of_children){
    if(size < 1){
        cout << "\n\tHeap UnderFlow!!..\n\t";
        return -1;
    }

    int max_ele = nary_tree[size-1];
    nary_tree[0] = nary_tree[size-1];
    size = size - 1;
    MAX_HEAPIFY(nary_tree, 0, size, no_of_children);

    return max_ele;

}

int main(){
    int n, x, no_of_children, height;
    cout << "Enter the height of the tree : ";
    cin >> height;

    cout << "Enter total number of nodes in tree : ";
    cin >> n;

    cout << "Enter the sqaure root of children to be needed : ";
    cin >> x;

    no_of_children = pow(2,x);

    int total_possible_nodes = (pow(no_of_children, height+1) - 1)/(no_of_children - 1);
    int nary_tree[total_possible_nodes];

    cout << "Enter the node values : \n";
    for(int i=0;i<n;i++)
        cin >> nary_tree[i];

    BUILD_MAXHEAP(nary_tree, n, no_of_children);
    cout << "\nBuilt Heap : \n";
    for(int i=0;i<n;i++)
        cout << nary_tree[i] << " ";

    int ele = 40;
    insert(nary_tree, n, no_of_children, ele, total_possible_nodes);
    cout << "\nUpdated Heap : \n";
    for(int i=0;i<n;i++)
        cout << nary_tree[i] << " ";

    cout << "\nMaximum element : " << popmax(nary_tree, n, no_of_children);
    cout << "\nUpdated Heap : \n";
    for(int i=0;i<n;i++)
        cout << nary_tree[i] << " ";

    
    //cout << height << " " << n <<  " " << x << " " << no_of_children << " " << total_possible_nodes;
 }