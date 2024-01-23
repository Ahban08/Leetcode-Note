class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0, tmpRes = 0;
        int value;
        std::map<int, int> numsmap;//key紀錄nums數值，value紀錄出現次數

        for(int i = 0; i < nums.size(); i++ ){
            numsmap[nums[i]]++;
        }
        for(auto pair : numsmap){
            if( pair.second > 0){
                //cout<<"pair"<< pair.first<<":"<<pair.second<<"\n";
                if ( !res ){
                    value = pair.first;
                    tmpRes++;
                    res = tmpRes;
                }else if(value == pair.first-1){
                    value = pair.first;
                    res = max(++tmpRes,res);
                }else{
                    value = pair.first;
                    tmpRes = 1;
                }
            }
        }
        return res;
    }
};

//Time Complexity: O(N)
//Space Complexity: O(N)

class Solution_2 {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0, tmpRes = 0;
        std::set<int> numsSet(nums.begin(), nums.end()); //std::set是一種有序不重複的容器，允許快速查找和插入，並且在插入時會自動進行排序。
        for(int value : numsSet){
            if( numsSet.find(value-1) == numsSet.end()){
                tmpRes = 0;
                while( numsSet.find(value+tmpRes) != numsSet.end()){
                    res = max(++tmpRes,res);
                }
            }
        }
        return res;
    }
};

//Time Complexity: O(N)
//Space Complexity: O(N)