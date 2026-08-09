class Solution {
public:
    int distMoney(int money, int children) {
        if(money<children) return -1;
        if(money==8*children) return children;
        money-=children;
        vector<int> ans(children,1);
        int i=0;
        while(money>=7 && i<children){
            ans[i++]+=7;
            money-=7;
        }
        if(i==children) return children-1;
        while(money>0){
            for(int j=i;j<children && money>0;j++){
                if(ans[j]==3){
                    if(money>=2){
                        ans[j]+=2;
                        money-=2;
                    }
                    else{
                        if(j+1<children)
                            ans[j+1]+=money;
                        else
                            ans[0]+=money;
                        money=0;
                    }
                }
                else{
                    ans[j]++;
                    money--;
                }
            }
        }
        int count=0;
        for(int x:ans){
            if(x==8) count++;
        }
        return count;
    }
};