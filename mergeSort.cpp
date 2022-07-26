#include<iostream>
using namespace std;
void merge(int L[], int nL, int R[], int nR, int a[])
{
   
    int i =0, j =0, k = 0;

    while(i < nL && j < nR)
    {
        if(L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }

        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < nL)
        a[k++] = L[i++];

    while(j < nR)
        a[k++] = R[j++];
}
void mergeSort(int a[], int n)
{
    if(n < 2)
        return;

    int mid = n/2;
    int L[mid];
    int R[n-mid];

    for(int i=0;i<mid;i++)
        L[i] = a[i];
    for(int i=mid;i<n;i++)
        R[i-mid] = a[i];

    mergeSort(L, mid);
    mergeSort(R, n-mid);
    merge(L, mid, R, n-mid, a);

    for(int i=0;i<n;i++)
        cout << a[i] << " ";
    cout << endl;
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
    mergeSort(a, n);

    cout << endl;
    for(int i=0;i<n;i++)
        cout << a[i] << " ";

}