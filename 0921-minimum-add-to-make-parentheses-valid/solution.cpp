class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        stack<int> st;

        for(char c : s){
            if(st.empty() && c == ')')
                ans++;
            else if(c == ')')
                st.pop();

            if(c == '(')
                st.push(c);
        }

        while(!st.empty()){
            st.pop();
            ans++;
        }

        return ans;
    }
};