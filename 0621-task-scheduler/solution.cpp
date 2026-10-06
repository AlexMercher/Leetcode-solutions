class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(char c:tasks){
            freq[c-'A']++;
        }
        priority_queue<int> pq;
        for(int f:freq){
            if(f>0) pq.push(f);
        }
        int time=0;
        while(!pq.empty()){
            vector<int> used;
            int slots=n+1;
            while(slots>0 && !pq.empty()){
                int f=pq.top();
                pq.pop();
                f--;
                if(f>0){
                    used.push_back(f);
                }
                time++;
                slots--;
            }
            
            for(int f:used){
                pq.push(f);
            }
            if(!pq.empty()) time+=slots;
        }
        return time;
    }
};