class LRUCache{
private:
    unordered_map<int, list<pair<int, int> >::iterator> _cache;        
    list<pair<int, int> > _kv; // key value list, used as a queue, but 
    int _capa;
    int _num;
public:
    LRUCache(int capacity) {
        _capa = capacity; 
        _num = 0;
    }
    
    int get(int key) {
        if (_cache.find(key) == _cache.end()) {
            return -1;
        } else {
            list<pair<int, int> >::iterator it = _cache[key];
            pair<int, int> p = *it;
            int value = p.second;
            set(key, value); // **
            return value;
        }
    }
    
    void set(int key, int value) {
        if (_cache.find(key) == _cache.end()) {
            if (_num == _capa) { // need to remove an element first
                int del_key = _kv.back().first;
                _kv.pop_back();
                _cache.erase(del_key);
            } else {
                _num++;
            }
        } else {
            list<pair<int, int> >::iterator it = _cache[key]; // **
            _kv.erase(it);
        }
        _kv.push_front(pair<int, int>(key, value)); // **
        _cache[key] = _kv.begin(); // **
    }
};
