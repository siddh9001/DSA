#include<iostream>
using namespace std;

void insertionSort(int a[], int n)
{
    int val, j;
    for(int i = 1; i < n; i++)
    {
        val = a[i];
        j = i-1;

        while(a[j] > val)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j+1] = val;

        for(int k =0;k < n;k++)
            cout << a[k] << " ";

        cout << endl;
    }
    cout << endl;
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
    insertionSort(a, n);

    return 0;
}