import collections
class LRUCache(object):

def __init__(self, capacity):
    """
    :type capacity: int
    """
    self.capacity = capacity
    self.lruCache = collections.OrderedDict()
    

def get(self, key):
    """
    :type key: int
    :rtype: int
    """
    if key in self.lruCache:
        # If we are getting the value, make it a recent entry to avoid eviction.
        popped = self.lruCache.pop(key)
        self.lruCache[key] = popped 
        return popped
    else:
        return -1
    

def put(self, key, value):
    """
    :type key: int
    :type value: int
    :rtype: None
    """
    if key in self.lruCache:
        self.lruCache.pop(key) 
        # key is already present, popped the old value, that would reduce cache as well for new entry.
    elif self.capacity <= len(self.lruCache): 
        #otherwise check size of cache first and if cache is full, pop LRU item Queue cache. 
        self.lruCache.popitem(last = False) 
    # Insert new key/value pair
    self.lruCache[key] = value

