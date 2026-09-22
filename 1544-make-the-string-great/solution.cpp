class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(char c:s){
            if(!st.empty()&&abs(c-st.top())==32){
                st.pop();
            }
            else st.push(c);
        }
        string a="";
        while(!st.empty()){
            a+=st.top();
            st.pop();
        }
        reverse(a.begin(),a.end());
        return a;
    }
};