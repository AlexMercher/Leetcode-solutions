class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end());
        int total=0;
        for(int x:apple){
            total+=x;
        }
        int cap=0;
        int count=0;
        for(int i=capacity.size()-1;i>=0;i--){
            cap+=capacity[i];
            count++;
            if(cap>=total) return count;
        }
        return count;
    }
};