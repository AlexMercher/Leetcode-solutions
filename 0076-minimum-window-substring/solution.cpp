class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(256,0);
        for(char c:t){
            need[c]++;
        }
        vector<int> have(256,0);
        int required=t.size();
        int bestLen=INT_MAX;
        int formed=0;
        int left=0;
        int bestStart=0;

        for(int right=0;right<s.size();right++){
            char c=s[right];
            have[c]++;
            if(need[c]>0 && have[c]<=need[c]) formed++;
            while(formed==required){
                if(right-left+1<bestLen){
                    bestLen=right-left+1;
                    bestStart=left;
                }
                char x=s[left];
                have[x]--;
                if(need[x]>0 && have[x]<need[x]) formed--;
                left++;
            }
        }
        if(bestLen==INT_MAX) return "";
        return s.substr(bestStart,bestLen);
    }
};