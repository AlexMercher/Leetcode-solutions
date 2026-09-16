class Solution {
public:
    int maximum69Number (int num) {
        string dup=to_string(num);
        int ans=0;
        int n=dup.size();
        for(int i=0;i<n;i++){
            if(dup[i]=='6'){
                dup[i]='9';
                break;
            }
        }
        ans=stoi(dup);
        return ans;
    }
};