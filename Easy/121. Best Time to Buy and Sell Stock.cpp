class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, minPrice;

        minPrice = prices[0];
        for(int i = 1; i < prices.size(); i++){
            if(minPrice > prices[i]){
                minPrice = prices[i];
            }else{
                res = max(res, prices[i]-minPrice);
            }
        }
        return res;
    }
};
//Time Complexity: O(N)
//Space Complexity: O(1)