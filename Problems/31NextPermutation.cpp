#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    vector<int> DeQuy(vector<int> nums){
        return {000};
    }
    
    bool TangDanDeu(vector<int> arr,int n){
        bool isIncreasing = true;
        for (int i = 0; i < n-1; ++i) {
            if (arr[i] > arr[i + 1]) {
                isIncreasing = false;
                break;
            }
        }
        return isIncreasing;
    }
    
    bool GiamDanDeu(vector<int> arr, int n){
        bool isDecreasing = true;
        for (int i = 0; i < n-1; ++i) {
            if (arr[i] < arr[i + 1]) {
                isDecreasing = false;
                break;
            }
        }
        return isDecreasing;        
    }
    
    // void nextPermutation(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n == 1) return ;
        
    //     if(TangDanDeu(nums,n) == true) {
    //         swap(nums[n-2],nums[n-1]);
    //         return ;
    //     }
        
    //     if(GiamDanDeu(nums,n) == true){
    //         reverse(nums.begin(), nums.end());
    //         return;
    //     }

    //     //
    //     DeQuy(nums, n);

    // }

    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), index = -1;
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        for(int i=n-1; i>=index && index != -1; i--){
            if(nums[i] > nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }
        reverse(nums.begin() + index + 1, nums.end());
    }
};

int main(){
    Solution res;
    vector<int> nums = {1,3,8,7,5};
    res.nextPermutation(nums);

    for(auto it : nums){
        cout<<it<<" ";
    }

    return 0;
}