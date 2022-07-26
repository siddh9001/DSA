#include<iostream>
using namespace std;

void selectionSort(int a[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int index = i;
        for(int j = i+1; j < n; j++)
        {
            if(a[j] < a[index])   //finding smallest value's index
                index = j;
        }

        //swapping the current value with smallest value found
        int temp = a[i];
        a[i] = a[index];
        a[index] = temp;
    }

    for(int i=0;i<n;i++)
        cout << a[i] << " ";
}
int main()
{
    int n;
    cout << "Enter the number of intergers in array: ";
    cin >> n;
    int a[n];
    cout << "Enter the numbers:\n";
    for(int i=0;i<n;i++)
        cin >> a[i];

    cout << "Sorted array is:\n";
    selectionSort(a, n);
}