# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """

        def depthFirstSearch(node, minValue, maxValue):
            if not node:
                return True

            if node.val <= minValue or node.val >= maxValue:
                return False

            return (depthFirstSearch(node.left, minValue, node.val) and
                    depthFirstSearch(node.right, node.val, maxValue))

        return depthFirstSearch(root, float('-inf'), float('inf'))