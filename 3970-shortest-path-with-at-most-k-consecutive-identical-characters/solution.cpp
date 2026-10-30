class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        const long long INF = LLONG_MAX;

        // dist[node][consecutive_count]
        // Flattened 2D array
        vector<long long> dist((size_t)n * (k + 1), INF);

        // Encode state as node * (k + 1) + count
        using State = pair<long long, int>;

        priority_queue<State, vector<State>, greater<State>> pq;

        // Starting node has a consecutive count of 1
        dist[1] = 0;
        pq.push({0, 1});

        while (!pq.empty()) {

            auto [cost, id] = pq.top();
            pq.pop();

            int u = id / (k + 1);
            int cnt = id % (k + 1);

            if (cost != dist[id])
                continue;

            if (u == n - 1)
                return (int)cost;

            for (auto &[v, w] : adj[u]) {

                int newCnt;

                if (labels[u] == labels[v])
                    newCnt = cnt + 1;
                else
                    newCnt = 1;

                if (newCnt > k)
                    continue;

                long long newCost = cost + w;

                int newId = v * (k + 1) + newCnt;

                if (newCost < dist[newId]) {

                    dist[newId] = newCost;

                    pq.push({newCost, newId});
                }
            }
        }

        return -1;
    }
};