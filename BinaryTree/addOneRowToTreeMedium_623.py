# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def addOneRow(self, root, val, depth):
        """
        :type root: TreeNode
        :type val: int
        :type depth: int
        :rtype: TreeNode
        """
        
        if not root:
            return None
        
        if depth == 1:
            return TreeNode(val=val, left=root, right=None)

        currentDepth = 1

        queue = collections.deque([root])

        while queue:
            if currentDepth == depth - 1: # depth-1: To get access to the parent
                break
            
            for _ in range(len(queue)):
                currentNode = queue.popleft()

                if currentNode.left:
                    queue.append(currentNode.left)
                
                if currentNode.right:
                    queue.append(currentNode.right)
            
            currentDepth += 1

        for node in queue:
            currentLeft = node.left
            node.left = TreeNode(val, currentLeft, None)
    
            currentRight = node.right
            node.right = TreeNode(val, None, currentRight)
        
        return root