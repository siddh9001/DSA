#include<iostream>
using namespace std;

void bubbleSort(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
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
    bubbleSort(a, n);

    return 0;
}