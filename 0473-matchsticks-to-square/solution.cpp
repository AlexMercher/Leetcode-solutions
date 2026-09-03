class Solution {
public:
    vector<int> memo;
    vector<int> matchsticks;
    int side;
    bool dfs(int mask,int currentside){
        if(mask==(1<<matchsticks.size())-1) return currentside==0;
        if(memo[mask]!=-1) return memo[mask];
        for(int i=0;i<matchsticks.size();i++){
            if(mask&(1<<i)) continue;
            if(currentside+matchsticks[i]>side)continue;

            int nextside=currentside+matchsticks[i];
            if(nextside==side) nextside=0;
            if(dfs(mask | (1<<i),nextside)) return memo[mask]=true;
        }
        return memo[mask]=false;
    }
    bool makesquare(vector<int>& sticks) {
        int sum=0;
        for(int x:sticks) sum+=x;
        if(sum%4!=0) return false;
        side=sum/4;

        matchsticks=sticks;
        sort(matchsticks.rbegin(),matchsticks.rend());
        if(matchsticks[0]>side) return false;
        memo.assign(1<<matchsticks.size(),-1);
        return dfs(0,0);
    }
};