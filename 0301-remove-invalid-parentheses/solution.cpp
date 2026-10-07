class Solution {
public:
    set<string> ans;
    void dfs(string& s,int index,int leftRemove,int rightRemove,int open,string& curr){
        if(index==s.size()){
            if(leftRemove==0 && rightRemove==0 && open==0) ans.insert(curr);
            return;
        }

        char c=s[index];
        if(c=='('){
            if(leftRemove>0){
                dfs(s,index+1,leftRemove-1,rightRemove,open,curr);
            }
            curr.push_back('(');
            dfs(s,index+1,leftRemove,rightRemove,open+1,curr);
            curr.pop_back();
        }else if(c==')'){
            if(rightRemove>0){
                dfs(s,index+1,leftRemove,rightRemove-1,open,curr);
            }
            if(open>0){
                curr.push_back(')');
                dfs(s,index+1,leftRemove,rightRemove,open-1,curr);
                curr.pop_back();
            }
        }else{
            curr.push_back(c);
            dfs(s,index+1,leftRemove,rightRemove,open,curr);
            curr.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int leftRemove=0;
        int rightRemove=0;
        int balance=0;
        for(char c:s){
            if(c=='(') balance++;
            else if(c==')'){
                if(balance>0) balance--;
                else rightRemove++;
            }
        }
        leftRemove=balance;
        string curr;
        dfs(s,0,leftRemove,rightRemove,0,curr);
        return vector<string>(ans.begin(),ans.end());
    }
};