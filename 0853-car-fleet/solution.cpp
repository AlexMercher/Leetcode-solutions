class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        for(int i=0;i<position.size();i++){
            cars.push_back({position[i],speed[i]});
        }

        sort(cars.rbegin(),cars.rend());
        stack<double> st;
        for(auto [pos,spd]:cars){
            double time=double(target-pos)/spd;
            if(st.empty()||time>st.top()){
                st.push(time);
            }
        }
        return st.size();
    }
};