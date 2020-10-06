class TrieNode {
  constructor(value) {
    this.value = value
    this.children = {}
    this.end = false
  }
}

/**
 * Initialize your data structure here.
 */
var Trie = function() {
    this.root = new TrieNode('*')
};

/**
 * Inserts a word into the trie. 
 * @param {string} word
 * @return {void}
 */
Trie.prototype.insert = function(word) {
    let lastNode = this.root
    for (const char of word) {
      if (!lastNode.children[char]) {
        lastNode.children[char] = new TrieNode(char)
      }
      lastNode = lastNode.children[char]
    }
    lastNode.end = true
};

/**
 * Returns if the word is in the trie. 
 * @param {string} word
 * @return {boolean}
 */
Trie.prototype.search = function(word, prefix = false) {
    let lastNode = this.root
    for (let i = 0; i < word.length; i++) {
      const char = word.charAt(i)
      if (!lastNode.children[char]) return false
      lastNode = lastNode.children[char]
      if (i === word.length - 1 && lastNode.end) return true
    }
    return prefix
};

/**
 * Returns if there is any word in the trie that starts with the given prefix. 
 * @param {string} prefix
 * @return {boolean}
 */
Trie.prototype.startsWith = function(prefix) {
    return this.search(prefix, true)
};
