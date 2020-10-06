class Trie(object):

    def __init__(self):
        self.root = {}
        

    def insert(self, word):
        curr = self.root
        for c in word:
            curr = curr.setdefault(c,{})
        curr["_end"] = "_end"

    def search(self, word):
        curr = self.root
        for c in word:
            if not c in curr: return False
            curr = curr[c]
        return "_end" in curr

    def startsWith(self, prefix):
        curr = self.root
        for c in prefix:
            if not c in curr: return False
            curr = curr[c]
        return True

