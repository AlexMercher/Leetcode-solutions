class Solution {
public:
    char repeatedCharacter(string s) {
        int ans=0;
        for(char c:s){
            if(ans & (1<<(c-'a'))) return c;
            ans |= (1<<(c-'a'));
        }
        return 'a';
    }
};