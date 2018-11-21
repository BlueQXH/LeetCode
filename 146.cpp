class LRUCache
{
public:
    LRUCache(int capacity) : sz(capacity) {}
    
    int get(int key)
    {
        unordered_map<int, list<pair<int, int>>::iterator>::iterator ite = m.find(key);
        if (ite != m.end())
        {
            cache.splice(cache.begin(), cache, ite->second);
            return ite->second->second;
        }
        return -1;
    }
    
    void put(int key, int value)
    {
        unordered_map<int, list<pair<int, int>>::iterator>::iterator ite = m.find(key);
        if (ite == m.end())
        {
            if (cache.size() < sz)
            {
                cache.emplace_front(make_pair(key, value));
                m.emplace(make_pair(key, cache.begin()));
            }
            else
            {
                m.erase(cache.back().first);
                cache.pop_back();             
                cache.emplace_front(make_pair(key, value));
                m.emplace(make_pair(key, cache.begin()));
            }
        }
        else
        {
            ite->second->second = value;
            cache.splice(cache.begin(), cache, ite->second);
        }
    }
private:
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    size_t sz;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
