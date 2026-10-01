class DetectSquares {
public:
    unordered_map<int,unordered_map<int,int>> mp;
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int x=point[0];
        int y=point[1];

        int ans=0;
        for(auto &[y2,cnt]:mp[x]){
            if(y2==y) continue;
            int d=abs(y2-y);

            int rightX=d+x;
            ans+=cnt*mp[rightX][y]*mp[rightX][y2];

            int leftX=x-d;
            ans+=cnt*mp[leftX][y]*mp[leftX][y2];
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */