class Solution {
public:
    unordered_map<string,vector<int>> memo;
    vector<int> solve(string expression){
        if(memo.count(expression)) return memo[expression];
        vector<int> result;
        int n=expression.size();
        for(int i=0;i<n;i++){
            char op=expression[i];

            if(op=='+'||op=='-'||op=='*'){
                string left=expression.substr(0,i);
                string right=expression.substr(i+1);

                vector<int> leftresults=solve(left);
                vector<int> rightresults=solve(right);

                for(int a:leftresults){
                    for(int b:rightresults){
                        if(op=='+') result.push_back(a+b);
                        else if(op=='-') result.push_back(a-b);
                        else result.push_back(a*b);
                    }
                }
            }
        }
        if(result.empty()) result.push_back(stoi(expression));
        memo[expression]=result;
        return result;
    }
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};