class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool>freq_small(26,0);
        vector<bool> freq_big(26,0);
        for(char c:word){
            if(islower(c)){
                freq_small[c-'a']=true;
            }
            if(isupper(c)) freq_big[c-'A']=true;
        }
        int count=0;
        for(int i=0;i<26;i++){
            if(freq_small[i] && freq_big[i]) count++;
        }
        return count;
    }
};