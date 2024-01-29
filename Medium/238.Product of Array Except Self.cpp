class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;
        int productAll = 1;
        int zero = 0;

        for( int i = 0; i < nums.size(); i++){
            if( nums[i] != 0){
                productAll = productAll*nums[i];
                //cout<<"productAll:"<<productAll;
            }else{
                zero++;
            }
        }
        answer.resize(nums.size());
        for( int i = 0; i < nums.size(); i++){
            if( zero > 1){
                answer[i] = 0;
            }else if( zero == 1){
                if( nums[i] ){
                    answer[i] = 0;
                }else{
                    answer[i] = productAll;   
                }
            }else{
                answer[i] = productAll/nums[i];


            }
        }
        return answer;
    }
};
//Time Complexity: O(N)
//Space Complexity: O(N)
//此方法不符合題目要求: without using the division operation.

class Solution_2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(),1), right(nums.size(),1), answer(nums.size(),1);
        // vector<int> left, right, answer;

        // left.resize(nums.size());
        // right.resize(nums.size());
        // answer.resize(nums.size());
        for( int i = 0; i < nums.size(); i++){
            if( i == 0){
                left[i] = 1;
                right[nums.size()-1-i] = 1;
            }else{
                left[i] = left[i-1]*nums[i-1];
                right[nums.size()-1-i] = right[nums.size()-i]*nums[nums.size()-i];
            }
        }
        for( int i = 0; i < nums.size(); i++){
            answer[i] = left[i]*right[i];
        }
        return answer;
    }
};
//Time Complexity: O(N)
//Space Complexity: O(N)