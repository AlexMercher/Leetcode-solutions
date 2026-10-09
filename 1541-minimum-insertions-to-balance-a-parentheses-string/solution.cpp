class Solution {
public:
    int minInsertions(string s) {
        int ans=0;
        int need=0;
        for(char c:s){
            if(c=='('){
                if(need%2!=0){
                    need--;
                    ans++;
                }
                need+=2;
            }else{
                need--;
                if(need<0){
                    ans++;//Needed for a (
                    need=1;//Need is reassigned to one so that we take the ) into account the next time.
                }
            }
        }
        return ans+need;
    }
};