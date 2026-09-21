class Solution {
public:
    int firstUniqChar(string s) {
        queue<pair<int,int>> q;
        int freq[26];
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
            q.push({s[i],i});
        }
        while(!q.empty()){
            char ch=q.front().first;
            int index=q.front().second;
            if(freq[ch-'a']==1) return index;
            q.pop();
        }
        return -1;
    }
};