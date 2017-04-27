
class Stack(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []

    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        self.stack.append(x)

    def pop(self):
        """
        :rtype: nothing
        """
        n = len(self.stack)
        for _ in range(n - 1):
            tmp = self.stack.pop(0)
            self.stack.append(tmp)
        self.stack.pop(0)

    def top(self):
        """
        :rtype: int
        """
        n = len(self.stack)
        for _ in range(n):
            tmp = self.stack.pop(0)
            self.stack.append(tmp)
        return tmp

    def empty(self):
        """
        :rtype: bool
        """
        return len(self.stack) == 0