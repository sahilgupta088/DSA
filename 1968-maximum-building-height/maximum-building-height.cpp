class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& rst) {
        rst.push_back({1,0});
        sort(rst.begin(),rst.end());

        for(int i=1;i<rst.size();i++){
            int dist = rst[i][0]-rst[i-1][0];
            rst[i][1] = min(rst[i][1],rst[i-1][1] + dist);
        }
        
        for(int i=rst.size()-2;i>=0;i--){
            int dist = rst[i+1][0]-rst[i][0];
            rst[i][1] = min(rst[i][1],rst[i+1][1] + dist);
        }
        int ans = 0;
        for(int i=1;i<rst.size();i++){
            int x1 = rst[i-1][0];
            int h1 = rst[i-1][1];

            int x2 = rst[i][0];
            int h2 = rst[i][1];
            int mx = max(h1,h2) + ((x2-x1)-abs(h1-h2))/2;
            ans = max(ans,mx);
        }

        ans = max(ans,rst.back()[1] + (n-rst.back()[0]));

        return ans;

    }
};