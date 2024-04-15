# Intuition

To find the sum of all root-to-leaf numbers, we can perform a depth-first search (DFS) traversal of the binary tree. At each node, we can accumulate the current number by multiplying the previous number by 10 and adding the current node's value. When we reach a leaf node, we return the accumulated number.

# Approach
1) Implement a depth-first search (DFS) function that takes the current node and the current sum as arguments.
2) If the current node is None, return 0.
3) Update the current sum by multiplying it by 10 and adding the value of the current node.
4) If the current node is a leaf node (i.e., it has no left or right child), return the current sum.
5) Recursively call the DFS function for the left and right child nodes, passing the updated current sum.
6) Return the sum of the results from the left and right child nodes.

# Complexity
Time complexity: O(n)
Space complexity: O(h)

# Code
```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def depthFirstSearch(currentNode, Sum):
            if not currentNode:
                return 0
            Sum = (Sum * 10) + currentNode.val
            if not currentNode.left and not currentNode.right:
                return Sum
            return depthFirstSearch(currentNode.left, Sum) + depthFirstSearch(currentNode.right, Sum)

        return depthFirstSearch(root, 0) 





```