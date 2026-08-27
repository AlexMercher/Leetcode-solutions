class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n=s.size();
        vector<int> freq(26,0);
        for(char c:s){
            freq[c-'a']++;
        }
        string ans="";
        for(int i=0;i<n;i++){
            int cur=target[i]-'a';
            if(freq[cur]>0){
                ans.push_back(target[i]);
                freq[cur]--;
                continue;
            }
            for(int c=cur+1;c<26;c++){
                if(freq[c]==0) continue;

                ans.push_back('a'+c);
                freq[c]--;
                for(int x=0;x<26;x++){
                    ans+=string(freq[x],'a'+x);
                }
                return ans;
            }
           break; 
        }

        for(int i=min(int(ans.size()),n)-1;i>=0;i--){
            int cur=target[i]-'a';
            freq[cur]++;
            for(int c=cur+1;c<26;c++){
                if(freq[c]==0) continue;
                string res=target.substr(0,i);
                res.push_back('a'+c);
                freq[c]--;

                for(int x=0;x<26;x++) res+=string(freq[x],'a'+x);
                return res;
            }
        }
        return "";
    }
};