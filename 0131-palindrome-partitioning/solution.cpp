class Solution {
public:
    vector<vector<string>> ans;
    vector<string> current;

    bool isPalindrome(const string& s,int l, int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void backtrack(const string&s, int start){
        if(start==s.size()){
            ans.push_back(current);
            return;
        }
        int n=s.size();
        for(int end=start;end<n;end++){
            if(!isPalindrome(s,start,end)) continue;

            current.push_back(s.substr(start,end-start+1));//choose

            backtrack(s,end+1);//explore

            current.pop_back();//delete
        }
    }
    vector<vector<string>> partition(string s) {
        backtrack(s,0);
        return ans;
    }
};