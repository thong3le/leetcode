class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        strs = [x for x in path.split('/') if x and x != '.']
        stack = []
        for p in strs:
            if p == '..' and stack:
                stack.pop()
            elif p != '..':
                stack.append(p)
        
        return "".join(map(lambda x: '/' + x, stack)) if stack else '/'
