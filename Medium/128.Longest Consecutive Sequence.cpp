class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0, tmpRes = 0;
        int tmp;
        std::map<int, int> numsmap;//key紀錄nums數值，value紀錄出現次數

        for(int i = 0; i < nums.size(); i++ ){
            numsmap[nums[i]]++;
        }
        for(auto pair : numsmap){
            if( pair.second > 0){
                //cout<<"pair"<< pair.first<<":"<<pair.second<<"\n";
                if ( !res ){
                    tmp = pair.first;
                    tmpRes++;
                    res = tmpRes;
                }else if(tmp == pair.first-1){
                    tmp = pair.first;
                    if( ++tmpRes > res){
                        res = tmpRes;
                    }
                }else{
                    tmp = pair.first;
                    tmpRes = 1;
                }
            }
        }
        return res;
    }
};

//Time Complexity: O(N)
//Space Complexity: O(N)