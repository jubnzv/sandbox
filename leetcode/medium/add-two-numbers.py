# https://leetcode.com/explore/interview/card/top-interview-questions-medium/107/linked-list/783/
#
# You are given two non-empty linked lists representing two non-negative
# integers. The digits are stored in reverse order and each of their nodes
# contain a single digit. Add the two numbers and return it as a linked list.
#
# You may assume the two numbers do not contain any leading zero, except the
# number 0 itself.
#
# Example:
#
# Input: (2 -> 4 -> 3) + (5 -> 6 -> 4) Output: 7 -> 0 -> 8 Explanation: 342 +
# 465 = 807.
from itertools import zip_longest


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        # Okay, it doesn't work with non-iterable ListNode objects
        # for values in zip_longest(l1, l2, fillvalue=0):
        s = l1.val + l2.val
        acc = s//10
        head = ListNode(s % 10)
        cursor = head
        while l1.next or l2.next:
            l1val = 0
            l2val = 0
            if l1.next:
                l1 = l1.next
                l1val = l1.val
            if l2.next:
                l2 = l2.next
                l2val = l2.val
            s = l1val + l2val + acc
            acc = s//10
            cursor.next = ListNode(s % 10)
            cursor = cursor.next
        if acc > 0:
            cursor.next = ListNode(acc)
        return head
