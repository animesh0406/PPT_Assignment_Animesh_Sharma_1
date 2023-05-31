/*
q6 Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]

Output: true

*/
#include<bits/stdc++.h>
using namespace std;

bool checker(vector<int> &v){
    sort(v.begin(),v.end());
    for(int i=0;i<v.size()-1;i++){
        if(v[i]==v[i+1])
            return true;
    }
    return false;

}
//time complexity O(nlogn) since sorting is used;

int main(){
    vector<int> nums={1,2,3,2};
    cout<<"The array is"<<endl;
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<",";
    }
    cout<<endl;
    if(checker(nums)){
        cout<<"True";
    }
    else cout<<"False";
    cout<<endl;

}
