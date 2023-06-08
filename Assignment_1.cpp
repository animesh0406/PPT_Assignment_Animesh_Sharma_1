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



/*
Q2 Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

- Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
- Return k.

Example
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_*,_*]

Explanation:Your function should return k = 2, with the first two elements of nums being 2. It does not matter what you leave beyond the returned k (hence they are underscores
*/
 int removeElement(vector<int>& nums, int val) {
         // Counter for keeping track of elements other than val
        int count = 0;
        // Loop through all the elements of the array
        for (int i = 0; i < nums.size(); i++) {
            // If the element is not val
            if (nums[i] != val) {
                nums[count++] = nums[i];
            }
        }
        return count;
    }
int main(){
    vector<int> v={22,33,2,5,2,6,2,10};
    int k=removeElement(v,2);
    cout<<k<<endl;
    return 0;
}






/*
Q3
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5

Output: 2
*/
   int searchInsert(vector<int>& nums, int target) {

        int beg = 0;
        int end = nums.size()-1;
        int mid=0;
     if(nums[nums.size()-1]<target)
            return nums.size();
        if(nums[0]>target)
            return 0;
        while(beg<=end)
        {
             mid= (beg+end)/2;
            if(nums[mid]>target) {

                if(nums[mid-1]<target)
                    return mid;
             end = mid-1;}
            if(nums[mid]<target){

                if(nums[mid+1]>target)
                    return mid+1;
             beg=mid+1;}
            if(nums[mid]==target)
                return mid;
         }
        if(nums[nums.size()-1]<target)
            return nums.size();

        return 0;

}
// Time complexity O(log n)
int main(){
    vector<int>nums={1,3,5,6};//can change the input to check the correctness of algo
    int k=searchInsert(nums,5);
    cout<<"The index is "<<k<<endl;
    return 0;
}





#include<bits/stdc++.h>
using namespace std;
/*
Q4.You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

**Example 1:**
Input: digits = [1,2,3]
Output: [1,2,4]

**Explanation:** The array represents the integer 123.

Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4]

*/
vector<int> plusOne(vector<int>& v) {
        int n = v.size();

        for(int i=n-1; i>=0; i--){
            if(v[i]<9){
                ++v[i];
                return v;
            }else{
                v[i] = 0;
            }
        }

        v.push_back(0);      // to handle '999' => 999 + 1 = 1000
        v[0] = 1;
        return v;
}
// Since iterating array only once therefore complexity(time)=O(n)
int main(){
     vector<int>ans={1,9,9,9,9};
    cout<<"Current number is"<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
    cout<<endl;

    ans=plusOne(ans);
    cout<<"Number after plus one is"<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
    return 0;


}


/*
q5. merge two sorted list
*/
#include<bits/stdc++.h>
using namespace std;
 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3(m+n);
        int i=0,j=0,k=0;


        for(i=0,j=0,k=0;i<m&&j<n;k++)
        {
            if(nums1[i]<nums2[j])
            {
                nums3[k]=nums1[i];
                i++;
            }
            else
            {
                nums3[k]=nums2[j];
                j++;
            }
        }
        while(i<m)
        {
            nums3[k]=nums1[i];
            i++;
            k++;
        }
       while(j<n)
        {
            nums3[k]=nums2[j];
           j++;
           k++;
        }
        for(int x=0;x<(m+n);x++)
        {
            nums1[x]=nums3[x];
        }

    }
    // Time complexity = O(M+N) where M and N are respective sizes
int main(){
    vector<int> nums1={1,2,3,0,0,0};
    vector<int> nums2={2,5,6};
    for(int i=0;i<nums1.size();i++){
        cout<<nums1[i]<<",";
    }
    cout<<endl;
    for(int i=0;i<nums2.size();i++){
        cout<<nums2[i]<<",";
    }
    cout<<endl;
    cout<<"After merging above 2 arrays"<<endl;
    merge(nums1,3,nums2,3);
    for(int i=0;i<nums1.size();i++){
        cout<<nums1[i]<<",";
    }

}






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



/*

Q7. Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the nonzero elements.

Note that you must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
*/
#include <bits/stdc++.h>
using namespace std;
void shifter(int *a,int size_of_array){
     int j = 0;
    for (int i = 0; i < size_of_array; i++) {
        if (a[i] != 0) {
            swap(a[j], a[i]);//taking two pointers i and j where j only moves forward when a[i]!=0 in this way the element containing zero can be shifted
            j++;
        }
    }
}
int main()
{
    int a[10];
    cout<<"Enter 10 numbers"<<endl;
    for(int i=0;i<10;i++){
        cin>>a[i];
    }

   shifter(a,10);
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " "; // Print the array
    }

    return 0;
}
// since array has to be iterated only once therefore it is




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
