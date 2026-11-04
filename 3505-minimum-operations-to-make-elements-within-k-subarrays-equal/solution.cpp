class Solution {
private:
    class SlidingMedian{
        multiset<long long> left,right;
        long long sumLeft=0;
        long long sumRight=0;
        void rebalance(){
            int required=(left.size()+right.size()+1)/2;
            while(left.size()>required){
                auto it=prev(left.end());
                long long val=*it;
                left.erase(it);
                sumLeft-=val;
                right.insert(val);
                sumRight+=val;
            }
            while(left.size()<required){
                auto it=right.begin();

                long long val=*it;
                right.erase(it);
                sumRight-=val;
                left.insert(val);
                sumLeft+=val;
            }
        }
    public:
        void add(long long val){
            if(left.empty() || val<=*left.rbegin()){
                left.insert(val);
                sumLeft+=val;
            }else{
                right.insert(val);
                sumRight+=val;
            }
            rebalance();
        }
        void remove(long long val){
            auto it=left.find(val);
            if(it!=left.end()){
                left.erase(it);
                sumLeft-=val;
            }else{
                it=right.find(val);
                right.erase(it);
                sumRight-=val;
            }
            rebalance();
        }
        long long getCost(){
            long long median=*left.rbegin();
            long long leftCost=median*left.size()-sumLeft;
            long long rightCost=sumRight-median*right.size();
            return leftCost+rightCost;
        }
    };
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n=nums.size();
        const long long INF=LLONG_MAX/4;
        vector<long long> cost(n-x+1);
        SlidingMedian sm;
        for(int i=0;i<n;i++){
            sm.add(nums[i]);
            if(i>=x) sm.remove(nums[i-x]);
            if(i>=x-1){
                cost[i-x+1]=sm.getCost();
            }
        }  
        vector<long long> previous(n+1,0);
        vector<long long> current(n+1,INF);
        for(int j=1;j<=k;j++){
            fill(current.begin(),current.end(),INF);
            for(int i=1;i<=n;i++){
                current[i]=current[i-1];
                if(i>=x && previous[i-x]!=INF){
                    long long take=previous[i-x]+cost[i-x];
                    current[i]=min(current[i],take);
                }
            }
            previous.swap(current);
        }
        return previous[n];
    }
};