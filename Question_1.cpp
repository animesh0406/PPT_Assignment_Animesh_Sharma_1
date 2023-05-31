#include<iostream>
#include<bits/stdc++.h>
/*
Q1. Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example:
Input: nums = [2,7,11,15], target = 9
Output0 [0,1]

Explanation:Because nums[0] + nums[1] == 9, we return [0, 1]
*/
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int>m;

        for(int i=0;i<nums.size();i++)
        {
            int val = target-nums[i];
            if(m.find(val)!=m.end()) // in case the second element is found
            {
                ans.push_back(m.find(val)->second);
                ans.push_back(i);
                break;
            }
            m.insert(pair<int,int>(nums[i],i)); // in case the above criteria is not satisfied I will keep inserting the element in the hashmap
        }
        return ans;
    }
int main(){
    vector<int> v={2,7,11,15};
    int target=9;
    vector<int> v2=twoSum(v,target);
    for(int i=0;i<v2.size();i++){
        cout<<v2[i]<<" ";
    }
    return 0;
}
// Time complexity O(n) since vector/array iterated only once.
