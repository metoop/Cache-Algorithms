#include "bits/stdc++.h"
using namespace std;

class LRUCache {
    int capacity;
    unordered_map<int, pair<int, list<int>::iterator> > *cache;
    list<int> *cache_list;
    public:

    LRUCache(int capacity) {
        this->capacity = capacity;
        cache = new unordered_map<int,pair<int, list<int>::iterator> >();
        cache_list = new list<int>();
    }
    

    int get(int key) {
        auto iter = cache->find(key);
        if(iter==cache->end())
            return -1;
        int val = iter->second.first;
        cache_list->erase(iter->second.second);
        cache->erase(iter);
        cache_list->push_front(key);
        cache->insert( { key, {val, cache_list->begin()} } );
        
        if(cache_list->size() > this->capacity){
            int k = cache_list->back();
            cache->erase(k);
            cache_list->pop_back();
        }
        return val;
    }
    
    void put(int key, int value) {
        auto iter = cache->find(key);
        if(iter!=cache->end()){
            cache_list->erase(iter->second.second);
            cache->erase(iter);
        }
        cache_list->push_front(key);
        cache->insert( { key, {value, cache_list->begin()} } );            

        if(cache_list->size() > this->capacity){
            int k = cache_list->back();
            cache->erase(k);
            cache_list->pop_back();
        }                
    }
};

int main(){
    auto lru = new LRUCache(10);
    lru->put(1, 100);
    cout << lru->get(1) << " ";

}