class Solution {
public:
    int minimumSum(int num) {
        string c=to_string(num);
        sort(c.begin(),c.end());
        vector<int> cal(4,0);
        for(int i=0;i<4;i++){
            cal[i]=c[i]-'0';
        }
        return 10*(cal[0]+cal[1])+cal[2]+cal[3];
    }
};