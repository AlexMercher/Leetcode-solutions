class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask=0;
        for(char c:allowed) mask |= 1<<(c-'a');

        int ans=0;
        for(string& word:words){
            bool consistent=true;
            for(char c:word){
                int bit=1<<(c-'a');
                if((mask & bit)==0){
                    consistent=false;
                    break;
                }
            }
            if(consistent) ans++;
        }
        return ans;
    }
};