class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        vector<int> freq(n+1,0);
        for(auto& item:items){
            freq[item[0]]++;
        }
        vector<int> total(n + 1, 0);
        for (int f = 1; f <= n; f++) {
            for (int j = f; j <= n; j += f) {
                total[f] += freq[j];
            }
        }
        long long minPrice = LLONG_MAX;//Cheapest price
        for (auto& item : items) {
            minPrice = min(minPrice, (long long)item[1]);
        }
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);

        ranges::sort(order, {}, [&](int i) {
            return items[i][1];
        });
        long long ans=0;
        long long remaining=budget;
        for(int i:order){
            long long price=items[i][1];
            if(price>=2*minPrice){
                break;
            }
            long long bonus=total[items[i][0]]-1;
            long long take=min(bonus,remaining/price);//If divisible then take=0;
            remaining-=take*price;
            ans+=2*take;
        }
        ans+=remaining/minPrice;
        return (int)ans;
    }
};