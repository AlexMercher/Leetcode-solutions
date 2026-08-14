class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> sTot(256,-1);
        vector<int> tTos(256,-1);
        int n=s.size();
        for(int i=0;i<n;i++){
            int a=s[i];
            int b=t[i];
            if(sTot[a]==-1 && tTos[b]==-1){
                sTot[a]=b;
                tTos[b]=a;
            }
            else{
                if(sTot[a]!=b || tTos[b]!=a) return false;
            }
        }
        return true;
    }
};