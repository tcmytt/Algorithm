#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l =0, r =n-1;
        
        while(r-l>=0){
            int m = (r+l)/2;
            cout<<" m = "<<m<<endl;
            if(nums[m] == target){
                return m;
            }
            if(nums[l] <= nums[m] ){
                if(nums[l] <= target && target < nums[m] ){
                    r=m-1;
                    cout<<"r = "<<r<<endl;
                }else{
                    l=m+1;
                    cout<<"l = "<<l<<endl;
                }
            }else{
                if(nums[m] < target && target <= nums[r]){
                    l=m+1;
                    cout<<"l = "<<l<<endl;
                }else{
                    r=m-1;
                    cout<<"r = "<<r<<endl;
                }
            }
        }
        
        return -1;
    }
};

int main(){
    Solution res ;
    vector<int> nums= {4,5,6,7,0,1,2};
    cout<<endl<<"Ket Qua"<<res.search(nums,0);
    return 0;
}