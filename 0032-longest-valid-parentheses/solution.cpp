class Solution {
public:
    int longestValidParentheses(string s) {
        if(s=="") return 0;
        int n=s.size();
        stack<int> st;
        int best=INT_MIN;
        st.push(-1);
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    best=max(best,i-st.top());
                }
            }
        }
        return best==INT_MIN?0:best;
    }
};