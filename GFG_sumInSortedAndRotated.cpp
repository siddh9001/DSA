
// Given an array that is sorted and then rotated around an unknown point. Find if the array has a pair with a given sum ‘x’. It may be assumed that all elements in the array are distinct.

// Examples : 

// Input: arr[] = {11, 15, 6, 8, 9, 10}, x = 16
// Output: true
// There is a pair (6, 10) with sum 16

// Input: arr[] = {11, 15, 26, 38, 9, 10}, x = 35
// Output: true
// There is a pair (26, 9) with sum 35

// Input: arr[] = {11, 15, 26, 38, 9, 10}, x = 45
// Output: false
// There is no pair with sum 45.

#include <iostream>
using namespace std;
int binarysearch(int a[], int l, int h, int target){
    if(h < l)
        return -1;
    
    int mid = (l+h)/2;
    
    if(a[mid] == target)
        return mid;
        
    if(a[l] <= a[mid]){
        if(target >= a[l] && target <= a[mid])
            return binarysearch(a, l, mid-1, target);
        else
            return binarysearch(a, mid+1, h, target);
    }
    if(target >= a[mid] && target <= a[h])
        return binarysearch(a, mid+1, h, target);
        
    return binarysearch(a, l, mid-1, target);
}
int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
	    cin >> a[i];
	    
	int x;
	cin >> x;
	
	for(int i=0;i<n;i++){
	    int target = x - a[i];
	    int res = binarysearch(a, 0, n-1, target);
	    if(res != -1){
	        cout << true;
	        return 0;
	    }
	}
	cout << false;
	return 0;
}