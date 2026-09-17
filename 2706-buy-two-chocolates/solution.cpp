class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int firstmin=INT_MAX;
        int secondmin=INT_MAX;
        for(int x:prices){
            if(x<firstmin){
                secondmin=firstmin;
                firstmin=x;
                continue;
            }
            else{
                secondmin=min(x,secondmin);
            }
        }
        int remain=money-(firstmin+secondmin);
        return remain>=0? remain:money;
    }
};