class Solution {
public:
    int minDeletion(string s, int k) {
        int ans=0;int count=0;
        vector<int> freq(26,0);
        for(char c:s){
            int x=c-'a';
            freq[x]++;
            if(freq[x]==1) count++;
        }
        if(count<=k) return 0;
        sort(freq.begin(),freq.end());
        int diff=count-k;
        for(int i=0;i<26;i++){
            ans+=freq[i];
            if(freq[i]>0 && diff>0) diff--;
            if(diff==0) break;
        }
        return ans;
    }
};