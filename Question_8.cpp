/*
Q8. You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]

*/
#include<bits/stdc++.h>
using namespace std;
vector<int> findErrorNums(vector<int>& nums)
    {
       vector<int> ans;
       int n = nums.size();
       sort(nums.begin() , nums.end());
       long int sum = 0;
       for(int i = 0 ; i < n-1 ; i++)
       {
           sum+=nums[i];
            if(nums[i] == nums[i+1])
            {
                sum-=nums[i];
                     ans.push_back(nums[i]);
            }
       }
       sum+=nums[n-1];
       long int temp = n*(n+1)/2;
       ans.push_back(temp-sum);
        return ans;
    }
//since iterating whole array therefore complexity O(n)

int main(){
    vector<int>v={1,2,2,4};
    cout<<"Given array"<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<"Required Ans"<<endl;
    vector<int>ans=findErrorNums(v);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }


}
