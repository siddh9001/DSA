#include<iostream>
#include<climits>
#include<cmath>
#include<vector>
#include<map>
using namespace std;

main(){
    int n;
    cin >> n;
    int a[n];
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] > max)  // finding max Element
            max = a[i];
    }

    //counting digits if max
    int temp = max, count = 0;
    while (temp)
    {
        temp/=10;
        count++;
    }

    
    int t;

    for (int i = 0; i < count; i++)
    {
        vector<vector<int>> mp(10, vector<int>());
        for(int j=0;j<n;j++){
            int dig = ((int)(a[j]/pow(10, i)))%10;
            mp[dig].push_back(a[j]);
        }
        t=0;
        for (int k = 0; k < 10; k++)
        {
            for (int l = 0; l < mp[k].size(); l++)
            {
                a[t++] = mp[k][l];
            }
            
        }
    }
    cout << "\n The sorted array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }   
}