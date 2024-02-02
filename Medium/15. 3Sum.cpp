#include <iostream>
#include <algorithm>
#include <Vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; i++){
            int target = nums[i];
            if( target > 0)
                break;
            if( i > 0 && target == nums[i-1]){
                continue;
            }
            int front = i+1, tail = nums.size()-1;
            int frontNum = nums[front], tailNum = nums[tail];
            while(front < tail){

                int sum = target + frontNum + tailNum;
                if(sum < 0){
                    front++;
                    while(frontNum == nums[front] && front < tail){
                        front++;
                    }
                    frontNum = nums[front];
                }else if(sum > 0){
                    tail--;
                    while(tailNum == nums[tail]  && front < tail){
                        tail--;
                    }
                    tailNum = nums[tail];
                }else{
                    res.push_back({target, nums[front], nums[tail]});
                    front++;
                    while(frontNum == nums[front] && front < tail){
                        front++;
                    }
                    frontNum = nums[front];
                    tail--;
                    while(tailNum == nums[tail]  && front < tail){
                        tail--;
                    }
                    tailNum = nums[tail];
                } 
            }
        }
        return res;
    }
};
//Time Complexity: O(N^2)
//Space Complexity: O(N)

int main() {
    Solution sol;
    vector<int> input = {-1,0,1,2,-1,-4};
    sol.threeSum(input);
    return 0;
}