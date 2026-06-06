class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n);
        vector<int>prelas(n);
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            prelas[i]=prelas[i+1]+nums[i+1];
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=abs(pre[i]-prelas[i]);
        }
        return ans;
    }
};