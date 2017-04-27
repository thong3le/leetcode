class Queue(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.popstack = []
        self.pushstack = []
        
    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        self.pushstack.append(x)

    def pop(self):
        """
        :rtype: nothing
        """
        if len(self.popstack) == 0:
            while self.pushstack:
                self.popstack.append(self.pushstack.pop())
        self.popstack.pop()
        
    def peek(self):
        """
        :rtype: int
        """
        if len(self.popstack) == 0:
            while self.pushstack:
                self.popstack.append(self.pushstack.pop())
        return self.popstack[-1]

    def empty(self):
        """
        :rtype: bool
        """
        return not self.popstack and not self.pushstack 