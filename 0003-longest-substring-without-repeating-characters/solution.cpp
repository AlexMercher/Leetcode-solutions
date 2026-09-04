class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> charIndex;
        int start=0; int maxLen=0;
        for(int end=0;end<s.size();end++)
        {
            char ch=s[end];
            if(charIndex.count(ch) && charIndex[ch]>=start)
            {
                //If count is 0 then its false but if we have encountered it already then its > 0 and hence we need to initialize the start again.
                start=charIndex[ch]+1;
            }
            charIndex[ch]=end;//Saving the index of the char
            maxLen=max(maxLen,end-start+1);
        }
        return maxLen;
    }
};