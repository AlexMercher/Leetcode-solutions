class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(string& op:operations){
            if(op!="C" && op!="D" && op!="+"){
                st.push(stoi(op));
            }
            else if(op=="C"){
                st.pop();
            }else if(op=="D"){
                st.push(2*st.top());
            }
            else if(op=="+"){
                int first=st.top();
                st.pop();
                int sec=st.top();
                st.push(first);
                st.push(first+sec);
            }
        }
        int sum=0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};