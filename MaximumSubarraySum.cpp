/*
    This program will find the maximum subaaray sum in an given array

    Problem Statement:
    Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.


Approch 1 : Brute force algorithm
    for each subarray from size 1 to n-1:
        sum of subarray
        if(max_sum < sum)
            max_sum = sum
    return max_sum

Approach 2 : Use the previously calculated values of sum
            change the order of processes i.e calculate all possible subarray sum from the start index

            for each index in arr:
                for subarray size 1 to n:
                    sum += arr[index+subarray size - 1]
                    ans = max(ans, sum);
            return ans;

Approach 3 : Divide and Conqurer 
    we divide the array in two parts and our and our answer's may lie between completely
    in left half or completely in right half or start index can be left half and end index can be 
    right half

    then our ans will be max of left_MSS, right_MSS and leftsum+rightsum

Approach 4:
    if the sum of previous subarray gives us negative value the discard it and again calculate the 
    maximum sum from the current sum


*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// O(n^3) solution
int bruteForce_maxsubarraysum(int ar[], int n){

    int max_sum = INT_MIN;
    for(int subarray_size = 1; subarray_size <= n; subarray_size++){
        for(int index = 0; index < n; index++){
            int sum = 0;
            if(index+subarray_size > n) break;

            for(int i = index; i < index+subarray_size; i++)
                sum += ar[i];

            if(max_sum < sum)
                max_sum = sum;
        }
    }

    return max_sum;
}

//O(n^2) solution
bigohNsqaure_maxSubarraySum(int ar[], int n){
    int max_sum = INT_MIN;
    for(int index = 0; index < n ;index++){
        int sum = 0;
        for(int subarray_size = 1; subarray_size <= n; subarray_size++){
            if(index+subarray_size > n) break;

            sum += ar[index + subarray_size - 1];
            max_sum = max(max_sum, sum);
        }

    }

    return max_sum;
}
//O(n log n) solution
int divideAndConqurer_maxSubarraySum(int ar[], int n){
    if(n == 1)
        return ar[0];

    int mid = n/2;
    int left_MSS = divideAndConqurer_maxSubarraySum(ar, mid);
    int right_MSS = divideAndConqurer_maxSubarraySum(ar+mid, n-mid);
    int leftsum = INT_MIN, rightsum = INT_MIN, sum = 0;

    for(int i = mid; i < n ; i++){
        sum += ar[i];
        rightsum = max(rightsum, sum);
    }
    sum = 0;
    for(int i=mid-1;i>=0;i--){
        sum += ar[i];
        leftsum = max(leftsum, sum);
    }
    return max(leftsum+rightsum, max(left_MSS, right_MSS));

}

//O(n) Solution
int KadaneAlgorithm_maxSubarraySum(int ar[], int n){
    int max_sum = INT_MIN, sum = 0;
    for(int i=0;i<n;i++){
        if(sum + ar[i] > 0)
            sum += ar[i];
        else
            sum = 0;

        max_sum = max(max_sum, sum);
    }

    return max_sum;
}

main(){
    int n;
    cout << "Enter the no. of element :";
    cin >> n;
    int a[n];
    cout << "Enter the array elements :";
    for(int i=0;i<n;i++)
        cin >> a[i];

    cout << "Maximum subarray sum is : ";
    //cout << bruteForce_maxsubarraysum(a, n);
    // cout << bigohNsqaure_maxSubarraySum(a, n);
    //cout << divideAndConqurer_maxSubarraySum(a, n);
     cout << KadaneAlgorithm_maxSubarraySum(a, n);


}