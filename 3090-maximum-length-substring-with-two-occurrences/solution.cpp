class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left=0;
        int count=0;
        vector<int> freq(26,0);
        int n=s.size();
        for(int right=0;right<n;right++){
            freq[s[right]-'a']++;
            while(freq[s[right]-'a']>2){
                freq[s[left]-'a']--;
                left++;
            }
            count=max(count,right-left+1);
        }
        return count;
    }
};