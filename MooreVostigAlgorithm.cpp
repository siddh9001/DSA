//Moore Voting algorithm is used to find the majority element in the array
#include<iostream>
using namespace std;
int MajorityELe(int arr[], int n){
    int maj_idx = 0, count = 1;

    //step 1. finding the majority candidate
    for (int i = 1; i < n; i++)
    {
        if(arr[maj_idx] == arr[i])
            count++;
        else
            count--;

        if(count == 0){
            maj_idx = i;
            count = 1;
        }
    }

    //step 2. Verifying the majority candidate
    count = 0;
    for(int i=0;i<n;i++)
        if(arr[maj_idx] == arr[i])
            count++;

    if(count > n/2)
        return arr[maj_idx];
    return -1;
    
}
int main(){
    int n;
    cout << "Enter the number of array elements : ";
    cin >> n;
    int a[n];
    cout << "Enter elements : \n";
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int res = MajorityELe(a, n);
    if(res != -1)
        cout << "Majority element in the array is : " << res;
    else
        cout << "No Majority Eelement..";
    
}