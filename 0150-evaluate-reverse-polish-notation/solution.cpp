class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s:tokens){
            if(s=="+"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int expr=b+a;
                st.push(expr);
            }
            else if(s=="-"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int expr=b-a;
                st.push(expr);
            }
            else if(s=="*"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int expr=b*a;
                st.push(expr);
            }
            else if(s=="/"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int expr=b/a;
                st.push(expr);
            }else{
                int a=stoi(s);
                st.push(a);
                }
        }
        return st.top();
    }
};