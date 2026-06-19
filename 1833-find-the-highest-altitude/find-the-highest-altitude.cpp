class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>a(n+1);
        a[0]=0;
        for(int i=1;i<=n;i++){
            a[i]=a[i-1]+gain[i-1];
        }
        int maxi=INT_MIN;
        for(int i=0;i<a.size();i++){
            maxi=max(maxi,a[i]);
        }
        return maxi;
    }
};