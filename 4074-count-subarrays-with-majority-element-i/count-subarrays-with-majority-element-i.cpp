class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        vector<int>ans=nums;
        int n=ans.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int target_len=0;
            int length=0;
            for(int j=i;j<n;j++){
                length++;
                if(ans[j]==target){
                    target_len++;
                }
                if(target_len*2>length){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};