class TrieNode:
    def __init__(self):
        self.isEnding = False
        self.child = {}
        
class WordDictionary:
    def __init__(self):
        self.root = TrieNode()

    # @param {string} word
    # @return {void}
    # Adds a word into the data structure.
    def addWord(self, word):
        curNode = self.root
        for char in word:
            if char not in curNode.child:
                curNode.child[char] = TrieNode()
            curNode = curNode.child[char]
        curNode.isEnding = True

    # @param {string} word
    # @return {boolean}
    # Returns if the word is in the data structure. A word could
    # contain the dot character '.' to represent any one letter.
    def search(self, word):
        return self.searchOneLevel(word, 0, self.root)
                    
    def searchOneLevel(self, word, index, curNode):
        if index == len(word): 
            return curNode.isEnding
        char = word[index]
        if char == '.':
            for thisChild in curNode.child:
                if self.searchOneLevel(word, index+1, thisChild): return True
        elif char in curNode.child:
            return self.searchOneLevel(word, index+1, curNode.child[char])
        return False

# Your WordDictionary object will be instantiated and called as such:
wordDictionary = WordDictionary()
wordDictionary.addWord("d")
print wordDictionary.search(".")

