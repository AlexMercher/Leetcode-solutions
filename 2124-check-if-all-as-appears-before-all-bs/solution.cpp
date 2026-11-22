class Solution {
public:
    bool checkString(string s) {
        bool foundB=false;
        for(char c:s){
            if(c-'a'==0 && foundB) return false;
            if(c-'a'==1) foundB=true;
        }
        return true;
    }
};