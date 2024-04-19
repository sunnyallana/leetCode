# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """

        ans = []

        def depthFirstSearch(root):
            if not root:
                return None

            depthFirstSearch(root.left)
            ans.append(root.val)
            depthFirstSearch(root.right)
        
        depthFirstSearch(root)
        return ans