class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int best=0;
        stack<char> st;
        for(char c:s){
            if(c=='('){
                count++;
                st.push('(');
                best=max(best,count);
            }else if(c==')'){
                count--;
                st.pop();
            }
        }
        return best;
    }
};