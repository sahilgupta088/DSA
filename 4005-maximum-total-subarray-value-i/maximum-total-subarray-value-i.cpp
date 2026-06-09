class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int num : nums){
            mini=min(mini,num);
            maxi=max(maxi,num);
        }

        return 1LL*(maxi-mini)*k;
    }
};