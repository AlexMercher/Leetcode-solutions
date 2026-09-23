class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char> st;
        int i=0;
        bool isthere=false;
        for(char c:word){
            st.push(c);
            i++;
            if(c==ch){
                isthere=true;
                break;
            }
        }
        if(!isthere) return word;
        for(int j=0;j<i;j++){
            word[j]=st.top();
            st.pop();
        }
        return word;
    }
};