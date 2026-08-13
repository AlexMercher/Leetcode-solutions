class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int sum=0;
        int n=words.size();
        string ans="";
        for(int i=0;i<n;i++){
            string word=words[i];
            sum=0;
            for(char x:word){
                sum+=weights[x-'a'];
            }
            int div=sum%26;
            ans.push_back(char('z'-div));
        }
        return ans;
    }
};