class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n=encoded.size();
        vector<int> real(n+1);
        int last=first;
        real[0]=first;
        for(int i=0;i<n;i++){
            int r=last^encoded[i];
            real[i+1]=r;
            last=r;
        }
        return real;
    }
};