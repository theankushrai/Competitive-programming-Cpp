# You are given the heads of two sorted linked lists list1 and list2.

# Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

# Return the head of the merged linked list.

 

# Example 1:


# Input: list1 = [1,2,4], list2 = [1,3,4]
# Output: [1,1,2,3,4,4]
# Example 2:

# Input: list1 = [], list2 = []
# Output: []
# Example 3:

# Input: list1 = [], list2 = [0]
# Output: [0]
 

# Constraints:

# The number of nodes in both lists is in the range [0, 50].
# -100 <= Node.val <= 100
# Both list1 and list2 are sorted in non-decreasing order.

# 1. put both elements in array sort and create a linked list 
# time complexity nm log mn 
# space complexity mn

#2 using new list
# time compleixty m+n
#space complexity M+n
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        # Create a dummy node to simplify list creation
        dummy = ListNode()
        newcurr = dummy

        # Merge the two lists
        while list1 and list2:
            if list1.val <= list2.val:
                # Create a new node with the smaller value
                newcurr.next = ListNode(list1.val)
                list1 = list1.next
            else:
                newcurr.next = ListNode(list2.val)
                list2 = list2.next
            # Move the pointer in the new list
            newcurr = newcurr.next

        # Add remaining nodes from list1
        while list1:
            newcurr.next = ListNode(list1.val)
            list1 = list1.next
            newcurr = newcurr.next

        # Add remaining nodes from list2
        while list2:
            newcurr.next = ListNode(list2.val)
            list2 = list2.next
            newcurr = newcurr.next

        return dummy.next

#3using dummy node 
#time complexity m+n
#space compleixtyy linear

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1:
            return list2
        if not list2:
            return list1

        dummy = ListNode() #dummy empty node . then returning dummy.next
        newcurr = dummy

        while list1 and list2:
            if list1.val <= list2.val:
                newcurr.next = list1
                list1 = list1.next
            else:
                newcurr.next = list2
                list2 = list2.next
            newcurr = newcurr.next

        # Append the remaining nodes of list1 or list2
        if list1:
            newcurr.next = list1
        elif list2:
            newcurr.next = list2

        return dummy.next

#using same logic but recursion

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1:
            return list2
        if not list2:
            return list1

        if list2.val<list1.val:
            list2.next=self.mergeTwoLists(list1,list2.next)
            return list2

        list1.next=self.mergeTwoLists(list1.next,list2)
        return list1