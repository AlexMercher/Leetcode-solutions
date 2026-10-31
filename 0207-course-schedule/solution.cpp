class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);

        for(auto& p:prerequisites){
            int course=p[0];
            int prerequisite=p[1];
            adj[prerequisite].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        int completed=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();

            completed++;
            for(int neighbour:adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0)q.push(neighbour);
            }
        }
        return completed==numCourses;
    }
};