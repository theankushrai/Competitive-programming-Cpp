# 143. Reorder List
# Medium
# Topics
# Companies
# You are given the head of a singly linked-list. The list can be represented as:

# L0 → L1 → … → Ln - 1 → Ln
# Reorder the list to be on the following form:

# L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
# You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

# Example 1:


# Input: head = [1,2,3,4]
# Output: [1,4,2,3]
# Example 2:


# Input: head = [1,2,3,4,5]
# Output: [1,5,2,4,3]
 

# Constraints:

# The number of nodes in the list is in the range [1, 5 * 104].
# 1 <= Node.val <= 1000
# #

# brute force 
# time complexity O(n)
# space complexity O(n)

# using reverse and merge
# time complexity O(n)
# space complexity O(1)

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """

        def reverse(node):
            prev=None
            curr=node
            while curr:
                nxt=curr.next
                curr.next=prev
                prev=curr
                curr=nxt
            return prev
        
        def merge(first,second):
            
            while second:
                temp1,temp2=first.next,second.next
                first.next=second
                second.next=temp1
                first,second=temp1,temp2
            
        slow,fast=head,head.next

        while fast and fast.next:
            slow=slow.next
            fast=fast.next.next

        second=slow.next
        slow.next=None

        merge(head,reverse(second))
