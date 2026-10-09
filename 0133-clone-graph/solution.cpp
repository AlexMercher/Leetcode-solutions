/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        unordered_map<Node*,Node*> mp;
        queue<Node*> q;
        mp[node]=new Node(node->val);
        q.push(node);

        while(!q.empty()){
            Node* curr=q.front();
            q.pop();

            for(Node* neighbour:curr->neighbors){
                if(!mp.count(neighbour)){
                    mp[neighbour]=new Node(neighbour->val);
                    q.push(neighbour);
                }
                mp[curr]->neighbors.push_back(mp[neighbour]);
            }
        }
        return mp[node];
    }
};

//DFS Approach.

class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* dfs(Node* node) {
        if(node == nullptr)
            return nullptr;

        // Already cloned this node
        if(mp.count(node))
            return mp[node];

        // Create and remember the clone
        Node* clone = new Node(node->val);
        mp[node] = clone;

        // Clone all neighbors
        for(Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor));
        }

        return clone;
    }

    Node* cloneGraph(Node* node) {
        mp.clear();
        return dfs(node);
    }
};