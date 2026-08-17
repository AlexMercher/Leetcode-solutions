class Solution {
public:
    string addStrings(string num1, string num2) {
        int n=max(num1.size(),num2.size());
        int carry=0;
        string ans="";
        for(int i=0;i<n;i++){
            int i1=num1.size()-1-i;
            int i2=num2.size()-1-i;
            int n1=(i1>=0)?num1[i1]-'0':0;
            int n2=(i2>=0)?num2[i2]-'0':0;
            int sum=n1+n2+carry;
            ans.push_back((sum%10)+'0');
            carry=sum/10;
        }
        if(carry) ans.push_back(carry+'0');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};