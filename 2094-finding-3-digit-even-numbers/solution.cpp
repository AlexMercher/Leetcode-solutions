class Solution {
public:
    set<int> st;
    void backtrack(const vector<int>& digits,vector<bool>& used, int num,int count){
        if(count==3){
            if(num%2==0) st.insert(num);
            return;
        }
        for(int i=0;i<digits.size();i++){
            if(used[i]) continue;
            if(count==0 && digits[i]==0) continue;
            used[i]=true;
            backtrack(digits,used,num*10+digits[i],count+1);
            used[i]=false;
        }
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<bool> used(digits.size(),false);
        backtrack(digits,used,0,0);
        return vector<int>(st.begin(),st.end());
    }
};