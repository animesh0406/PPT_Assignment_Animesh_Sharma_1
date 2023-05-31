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
