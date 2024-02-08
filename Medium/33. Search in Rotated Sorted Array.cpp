class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = -1, left, right;

        left = 0;
        right =nums.size()-1;
        while(left <= right){
            int mid = (left + right)/2;
            if(nums[mid] == target){
                res = mid;
                break;
            }
            

            if(nums[mid] < target && target <= nums[right]){
                left = mid + 1;
            }else if(nums[left] <= target && target < nums[mid]){
                right = mid - 1;
            }else{
                if(nums[left] < nums[right]){
                    break;
                }else if( nums[mid] < nums[right]){ //target在左亂序
                    right = mid - 1;
                }else if( nums[left] < nums[mid]){ //target在右亂序
                    left = mid + 1;
                }else{
                    left++;
                }
                
            }
            // cout<<"left"<<left<<"right"<<right<<"\n";
        }
        return res;
    }
};
//Time Complexity: O(logN)
//Space Complexity: O(1)

class Solution_1 {
public:
    int search(vector<int>& nums, int target) {
        int res = -1, left, right;

        left = 0;
        right =nums.size()-1;
        while(left <= right){
            int mid = (left + right)/2;
            if(nums[mid] == target){
                res = mid;
                break;
            }
            
            if( nums[mid] <= nums[right]){ //右有序
                if(nums[mid] < target && target <= nums[right]){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }else{ //左有序
                if(nums[left] <= target && target < nums[mid]){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }

        }
        return res;
    }
};
//Time Complexity: O(logN)
//Space Complexity: O(1)