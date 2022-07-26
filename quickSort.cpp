#include<iostream>
#include<algorithm>
using namespace std;

//considering First Element as pivot
int partition(int a[], int start, int end)
{
    int pivot = a[start];
    int pIndex = start + 1;
    for(int i = start + 1; i <= end;i++)
    {
        if(a[i] <= pivot)
        {
            if(i != pIndex)
            {
                swap(a[i], a[pIndex]);
            }
            pIndex++;
        }
    }
    swap(a[pIndex-1], a[start]);
    return pIndex-1;
}

//considering last element as pivot
// int partition(int a[], int start, int end)
// {
//     int pivot = a[end];
//     int pIndex = start;

//     for(int i = start; i < end; i++)
//     {
//         if(a[i] <= pivot)
//         {
//             swap(a[i], a[pIndex]);
//             pIndex++;
//         }
//     }
//     swap(a[pIndex], a[end]);
//     return pIndex;
// }

void quickSort(int a[], int start, int end)
{
    if(start < end)
    {
        int pIndex = partition(a, start, end);
        quickSort(a, start, pIndex - 1);
        quickSort(a, pIndex + 1, end);
    }
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
    quickSort(a, 0, n-1);

    for(int i=0;i<n;i++)
        cout << a[i] << " ";
}