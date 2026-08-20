class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> prev={1};
        ans.push_back(prev);
        for(int row=1;row<numRows;row++){
            vector<int> curr(row+1,1);
            for(int j=1;j<row;j++){
                curr[j]=prev[j-1]+prev[j];
            }
            ans.push_back(curr);
            prev=curr;
        }
        return ans;
    }
};