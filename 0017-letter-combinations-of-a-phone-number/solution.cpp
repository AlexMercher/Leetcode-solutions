class Solution {
public:
    vector<string> ans;
    string keypad[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void backtrack(string& digits,int index, string& curr){
        if(index==digits.size()){
            ans.push_back(curr);
            return;
        }
        int digit=digits[index]-'0';
        for(char c:keypad[digit]){
            curr.push_back(c);//choose
            backtrack(digits,index+1,curr);//explore
            curr.pop_back();//undo
        }
    }
    vector<string> letterCombinations(string digits) {
        string curr="";
        backtrack(digits,0,curr);
        return ans;
    }
};