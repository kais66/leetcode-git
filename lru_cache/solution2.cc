class LRUCache{
private:
    unordered_map<int, list<pair<int, int> >::iterator> _hash; // provides constant time lookup
    list<pair<int, int> > _q; // provides constant time enq and deq. When de-qing, need to update hash, thus need to store a
                            // key-value pair in q;
    int _capa;
    int _cnt;
public:
    LRUCache(int capacity) : _capa(capacity), _cnt(0), _hash(), _q() {
         
    }
    
    int get(int key) {
        if (_hash.find(key) != _hash.end()) {
            pair<int, int> kv = *(_hash[key]);   
            set(key, kv.second); 
            return kv.second; 
        } else { return -1; }
    }
    
    void set(int key, int value) {
        if (_hash.find(key) != _hash.end()) {  // found 
            //_q.remove(_hash[key]);
            _q.erase(_hash[key]);
        } else {
            if (_cnt == _capa) {
                pair<int, int> dp = _q.back(); 
                _hash.erase(dp.first);
                _q.pop_back();
            } else {
                ++_cnt;
            }
        }
        _q.push_front(pair<int, int>(key, value));
        _hash[key] = _q.begin();
    }
};
