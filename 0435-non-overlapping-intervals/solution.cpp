class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),
        [](const vector<int> a, const vector<int> b){
            return a[1]<b[1];
        });//Sort them as per their starting time.
        int removed=0;
        int lastend=intervals[0][1];//Ending of the first event;
        int n=intervals.size();
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=lastend) lastend=intervals[i][1];//If another starts when one ends then make it possible.
            else removed++;
        }
        return removed;
    }
};