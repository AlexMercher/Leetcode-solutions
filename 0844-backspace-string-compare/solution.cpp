class Solution {
public:
    string op(string& s){
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                if(!st.empty())
                    st.pop();
            }
            else st.push(s[i]);
        }
        string a="";
        while(!st.empty()){
            a+=st.top();
            st.pop();
        }
        reverse(a.begin(),a.end());
        return a;
    }
    bool backspaceCompare(string s, string t) {
        s=op(s);
        t=op(t);
        return s==t;
    }
};