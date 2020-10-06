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
      //delete item from freq
      auto it = mp[key];
      int curFreq = it -> freq;
      fqMp[curFreq].erase(it);

      //increase the freq
      //insert at the last in the freq map
      fqMp[curFreq + 1].push_back({
        key,
        value,
        curFreq + 1
      });

      //update iterator in key map
      mp[key] = prev(fqMp[curFreq + 1].end());

      if (fqMp[minFreq].empty())
        minFreq++;
    } else {
      if (mp.size() >= size) {
        auto it = fqMp[minFreq].begin();
        int key = it -> key;
        //delete from mpkey first
        mp.erase(key);

        //delete from freq map
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
