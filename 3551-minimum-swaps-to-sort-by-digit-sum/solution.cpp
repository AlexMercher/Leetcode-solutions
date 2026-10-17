class Solution {
public:
    int digits(int num) {
        int sum = 0;
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        vector<int> target = nums;

        sort(target.begin(), target.end(), [this](int a, int b) {
            int da = digits(a);
            int db = digits(b);

            if (da != db) return da < db;
            return a < b;
        });
        vector<int> cur=nums;
        unordered_map<int,int> pos;
        for(int i=0;i<cur.size();i++){
            pos[cur[i]]=i;
        }
        int swaps=0;
        for(int i=0;i<cur.size();i++){
            if(cur[i]==target[i]) continue;
            int j=pos[target[i]];
            swap(cur[i],cur[j]);
            pos[cur[i]]=i;
            pos[cur[j]]=j;

            swaps++;
        }
        return swaps;
    }
};