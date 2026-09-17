class Solution {
public:
    int fillCups(vector<int>& amount) {
        int sum=0; int mx;
        for(int x:amount) {
            sum+=x;
            mx=max(mx,x);
        }
        return max(mx,(sum+1)/2);
    }
};