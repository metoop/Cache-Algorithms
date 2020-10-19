lass LFUCache {
  struct LFU {
    int key, value, freq;
    LFU(int k, int v, int f): key(k), value(v), freq(f) {}
  };

  unordered_map < int, list < LFU > ::iterator > mp; //key  -->iterator
  unordered_map < int, list < LFU >> fqMp; //freq -> struct 
  int size;
  int minFreq;

  public:
    LFUCache(int capacity) {
      size = capacity;
      minFreq = 0;
    }

  int get(int key) {
    if (mp.find(key) == mp.end()) {
      return -1;
    }

    int val = mp[key] -> value;
    put(key, val);
    return val;
  }

  void put(int key, int value) {
    if (size <= 0) return;
    if (mp.find(key) != mp.end()) {
      
      auto it = mp[key];
      int curFreq = it -> freq;
      fqMp[curFreq].erase(it);


      fqMp[curFreq + 1].push_back({
        key,
        value,
        curFreq + 1
      });

      
      mp[key] = prev(fqMp[curFreq + 1].end());

      if (fqMp[minFreq].empty())
        minFreq++;
    } else {
      if (mp.size() >= size) {
        auto it = fqMp[minFreq].begin();
        int key = it -> key;
        mp.erase(key);

        fqMp[minFreq].pop_front();
      }

      minFreq = 1;
      fqMp[minFreq].push_back({
        key,
        value,
        minFreq
      });
      mp[key] = prev(fqMp[minFreq].end());
    }
  }

};
