struct Trienode {
    unordered_map < int, Trienode * > child;
    bool wordend = false;
};
class Trie {
    public:
        Trienode * root;
    Trie() {
        root = new Trienode();
    }

    void insert(string word) {
        Trienode * curr = root;
        for (char a: word) {
            int idx = a - 'a';
            if (curr -> child.count(idx) == 0) {
                curr -> child[idx] = new Trienode();
            }
            curr = curr -> child[idx];
        }
        curr -> wordend = true;
    }

    bool search(string word) {
        Trienode * curr = root;
        for (char a: word) {
            int idx = a - 'a';
            if (curr -> child.count(idx) == 0) return false;
            curr = curr -> child[idx];
        }
        return curr -> wordend;
    }

    bool startsWith(string prefix) {
        Trienode * curr = root;
        for (char a: prefix) {
            int idx = a - 'a';
            if (curr -> child.count(idx) == 0) return false;
            curr = curr -> child[idx];
        }
        return true;
    }
};
