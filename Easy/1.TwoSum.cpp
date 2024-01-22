#include <vector>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2); 
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    res[0] = i;
                    res[1] = j;
                    return res;
                }
            }
        }
        return res;
    }
};
//Time Complexity: O(N^2)
//Space Complexity: O(1)


//Follow-up: Can you come up with an algorithm that is less than O(N^2) time complexity?
class Solution_2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2);
        //用hashmap 建立將過去掃過的數字記住
        std::map<int, int> numsmap; //key紀錄數值，value紀錄位置
        int temp;
        for (int i = 0; i < nums.size(); i++) {
            temp = target-nums[i];
            if (numsmap.find(temp)== numsmap.end()) {
                // Element not found in the map
                numsmap.insert(std::pair<int, int>(nums[i], i));
            }else{
                res[0] = numsmap[temp];
                res[1] = i;
                return res;

            }
        }
        return res;
    }
};
//Time Complexity: O(N)
//Space Complexity: O(N)