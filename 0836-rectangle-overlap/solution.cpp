class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool widthoverlap=min(rec1[2],rec2[2]) > max(rec1[0],rec2[0]);
        bool heightoverlap=min(rec1[3],rec2[3]) > max(rec1[1],rec2[1]);
        return widthoverlap && heightoverlap;
    }
};