# Author: Thong Le
# Date: 
#
# LeetCode 211 - Add and Search Word - Data structure design
#
# Solution Approach: 
#
#
#

from collections import deque
class Node(object):
    def __init__(self):
        self.isWord = False
        self.children = {}
        
class WordDictionary(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = Node()
        

    def addWord(self, word):
        """
        Adds a word into the data structure.
        :type word: str
        :rtype: void
        """
        node = self.root
        for c in word:
            if c not in node.children:
                node.children[c] = Node()
            node = node.children[c]
        node.isWord = True
        

    def search(self, word):
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        :type word: str
        :rtype: bool
        """
        queue = deque([self.root])
        i = 0
        while i < len(word) and queue:
            m = len(queue)
            print "size = ", m
            for _ in range(m):
                node = queue.popleft()
                if word[i] == '.':
                    for c in node.children:
                        queue.append(node.children[c])
                else:
                    if word[i] in node.children:
                        queue.append(node.children[word[i]])
            	print i, word[i], queue
            i += 1
        for node in queue:
            if node.isWord:
                return True
        return False
            
                
d = WordDictionary()
d.addWord("bad")
d.addWord("dad")
d.addWord("mad")
print d.root.children['m'].children.keys()
print d.search(".ad")