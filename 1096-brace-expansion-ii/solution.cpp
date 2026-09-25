class Solution {
public:
    set<string> parse(string& s,int& i){
        set<string> res;
        while(i<s.size()&&s[i]!='}'){
            if(s[i]==','){
                i++;
                continue;
            }
            set<string> curr={""};
            while(i<s.size()&& s[i]!=',' && s[i]!='}'){
                set<string> part;
                if(s[i]=='{'){
                    i++;
                    part=parse(s,i);
                    i++;
                }
                else{
                    part.insert(string(1,s[i]));
                    i++;
                }
                set<string> next;
                for(string a:curr){
                    for(string b:part){
                        next.insert(a+b);
                    }
                }
                curr=next;
            }
            for(string x:curr){
                res.insert(x);
            }
        }
        return res;
    }
    vector<string> braceExpansionII(string expression) {
        int i=0;
        set<string> st=parse(expression,i);
        return vector<string>(st.begin(),st.end());
    }
};