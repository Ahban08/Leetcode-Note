#include <iostream>
#include <cmath>
#include <Vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int res, root, left, right;

        left = 0;
        right = nums.size()-1;
        root = ceil((right+left)/2);
        
        while( root != left && root!=right){
            if(nums[root] < nums[right]){
                right = root;
                root = ceil((right+left)/2);
            }else{
                left = root;
                root = ceil((right+left)/2);
            }
        }
        res = min(nums[left], nums[right]);
        return res;
    }
};
//Time Complexity: O(logN)
//Space Complexity: O(1)

class Solution_1 {
public:
    int findMin(vector<int>& nums) {
        int res, left, right;

        left = 0;
        right = nums.size()-1;
        
        while( left < right){
            if(nums[left] < nums[right]){
                break;
            }
            int mid = (right+left)/2;
            if(nums[mid] < nums[right]){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        res = nums[left];
        return res;
    }
};
//Time Complexity: O(logN)
//Space Complexity: O(1)

int main() {
    Solution sol;
    vector<int> input = {3,4,5,1,2};
    cout << "Output: " << sol.findMin(input) << endl;
    return 0;
}