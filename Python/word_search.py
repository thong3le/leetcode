class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        if not word:
            return True
        if not board:
            return False
        for i in range(len(board)):
            for j in range(len(board[0])):
                if self.exist_helper(board, word, i, j):
                    return True
        return False
        
    def exist_helper(self, board, word, i, j):
        m, n = len(board), len(board[0])
        if i < 0 or i >= m or j < 0 or j >= n:
            return False
        if board[i][j] != word[0]:
            return False
        if not word[1:]:
            return True
        board[i][j] = ' '
        if self.exist_helper(board, word[1:], i-1, j) or \
            self.exist_helper(board, word[1:], i+1, j) or \
            self.exist_helper(board, word[1:], i, j-1) or \
            self.exist_helper(board, word[1:], i, j+1):
                return True
        board[i][j] = word[0]
        return False