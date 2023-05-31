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
