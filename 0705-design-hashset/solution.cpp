class MyHashSet {
public:
    vector<bool> parent;
    MyHashSet() {
        parent.resize(1000001,false);
    }
    
    void add(int key) {
        parent[key]=true;
    }
    
    void remove(int key) {
        parent[key]=false;
    }
    
    bool contains(int key) {
        return parent[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */