// This is max heap implementation with binary trees.

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

class Heap{
    public:
    void MAX_HEAPIFY(int binary_tree[], int index, int size);
    void BUILD_MAXHEAP(int binary_tree[], int size);
    void heap_insert_element(int binary_tree[], int ele, int &size);
    int heap_extract_max(int binary_tree[], int &size);
    void heap_increase_key(int bianry_tree[], int index, int key, int size);
    void heap_decrease_key(int bianry_tree[], int index, int key, int size);
}h;

//Function to perform the heapify operation
void Heap :: MAX_HEAPIFY(int binary_tree[], int index, int size){
    int l = 2 * index + 1;
    int r = 2 * index + 2;
    int largest;

    if(l < size && binary_tree[l] > binary_tree[index])
        largest = l;
    else
        largest = index;

    if(r < size && binary_tree[r] > binary_tree[largest])
        largest = r;

    if(largest != index){
        swap(binary_tree[index], binary_tree[largest]);
        MAX_HEAPIFY(binary_tree, largest, size);
    }
}

void Heap :: BUILD_MAXHEAP(int binary_tree[], int size){
    int last_internal_node = floor(size/2)-1;
    for(int i = last_internal_node; i >= 0; i--){
        MAX_HEAPIFY(binary_tree, i, size);
    }
}

void Heap :: heap_insert_element(int binary_tree[], int ele, int &size){
    size += 1;
    binary_tree[size-1] = ele;
    int i = size - 1;
    while(i > 0 and binary_tree[i/2] < binary_tree[i]){
        swap(binary_tree[i/2], binary_tree[i]);
        i = i/2;
    }
}

int Heap ::heap_extract_max(int binary_tree[], int &size){

    if(size < 1){
        cout << "\n\tHeap UnderFlow !!!..\t\n";
        return -1;
    }

    int max_ele = binary_tree[0];
    binary_tree[0] = binary_tree[size-1];
    size = size-1;
    MAX_HEAPIFY(binary_tree, 0, size);
    return max_ele;

}

void Heap :: heap_increase_key(int bianry_tree[], int index, int key, int size){

    if(key < bianry_tree[index] ){
        cout << "\n\tWrong Operation!!..\t\n";
        return;
    }

    bianry_tree[index] = key;
    int i = index;

    //percolate up in order to maintain heapify property
    while(i > 0 and bianry_tree[i/2] < bianry_tree[i]){
        swap(bianry_tree[i/2], bianry_tree[i]);
        i = i/2;
    }
}

void Heap ::heap_decrease_key(int bianry_tree[], int index, int key, int size){
    if(key >= bianry_tree[index]){
        cout << "\n\tWrong Operation!!..\t\n";
        return;
    }

    bianry_tree[index] = key;
    MAX_HEAPIFY(bianry_tree, index, size);
}

int main(){
    int height;
    cout << "Enter the height of the tree : ";
    cin >> height;

    int total_possible_nodes = pow(2, height+1) - 1;
    int binary_tree[total_possible_nodes];

    int n;
    cout << "Enter the number of nodes in the tree : ";
    cin >> n;

    /*
        if i is the parent node then its 
        left child = 2*i + 1
        right child = 2*i + 2
    */

    cout << "Enter the values of nodes in the tree : ";
    for(int i=0;i<n;i++)
        cin >> binary_tree[i];


    h.BUILD_MAXHEAP(binary_tree, n);

    int option;
    cout << "\n\n\t\t ----HEAP Operations---- \n\n";
    cout << "1. Insert value in heap (enter 1)\n";
    cout << "2. Extract the maximum value from heap (heap pop) (enter 2)\n";
    cout << "3. Increase a node value (enter 3)\n";
    cout << "4. Decrease a node value (enter 4)\n";
    cout << "Enter option : ";
    cin >> option;

    int index, key, ele;
    switch (option)
    {
    case 1:
        cout << "\n\nEnter the element to be inserted";
        cin >> ele;
        h.heap_insert_element(binary_tree, ele, n);
        cout << "\n\tElement inserted sucessfully\t\n";
        break;
    case 2:
        cout << "Maximum Element is : " <<  h.heap_extract_max(binary_tree, n);
        break;
    case 3:
        cout << "\nEnter the index of key whoose value is to be increased : ";
        cin >> index;
        cout << "\nEnter the new value for the index : ";
        cin >> key;
        h.heap_increase_key(binary_tree, index, key, n);
        break;
    case 4:
        cout << "\nEnter the index of key whoose value is to be decreased : ";
        cin >> index;
        cout << "\nEnter the new value for the index : ";
        cin >> key;
        h.heap_decrease_key(binary_tree, index, key, n);
        break;
    
    default:
        break;
    }
    cout << "\nTotal number of elements in heap is : ";
    cout << n;
    cout<<"\nThe current heap is : \n";
    for(int i=0;i<n;i++)
        cout << binary_tree[i] << " ";

}