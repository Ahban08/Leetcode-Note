class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool res = false;
        map<int, bool>count;

        for(int i= 0; i < nums.size(); i++){
            if( count[nums[i]] ){
                // cout<<"count[nums[i]]:nums[i]"<<count[nums[i]]<<":"<<nums[i];
                res = true;
                return res;
            }else{
                count[nums[i]] = 1;
            }
        }
        return res;
    }
};
//Time Complexity: O(N)
//Space Complexity: O(N)

class Solution_2 {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool res = false;
        set<int> count; //用set儲存陣列掃過的值

        for(int i= 0; i < nums.size(); i++){
            if( count.find(nums[i]) != count.end()){
                // cout<<"count[nums[i]]:nums[i]"<<count[nums[i]]<<":"<<nums[i];
                res = true;
                return res;
            }else{
                count.insert(nums[i]);
            }
        }
        return res;
    }
};
//Time Complexity: O(N)
//Space Complexity: O(N)