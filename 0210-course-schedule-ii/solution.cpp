class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);

        for(auto& p:prerequisites){
            int course=p[0];
            int prerequisite=p[1];
            indegree[course]++;
            adj[prerequisite].push_back(course);
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }

        vector<int> completed;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            completed.push_back(node);
            for(int neighbour:adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0) q.push(neighbour);
            }
        }
        return completed.size()==numCourses?completed:vector<int> {};
    }
};