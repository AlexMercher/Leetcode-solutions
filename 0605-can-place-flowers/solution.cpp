class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int bed_len=flowerbed.size();
        if(n==0) return true;
        for(int i=0;i<bed_len;i++){
            int prev=(i==0)?0:flowerbed[i-1];
            int next=(i==bed_len-1)?0:flowerbed[i+1];
            if(flowerbed[i]==0 && prev==0 && next==0){
                flowerbed[i]=1;
                n--;
            }
            if(n==0) return true;
        }
        return n==0;
    }
};