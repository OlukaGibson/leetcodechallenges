class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: Optional[ListNode]
        :type l2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        # Initialize a dummy node to simplify result construction
        dummy = ListNode(0)
        current = dummy
        carry = 0

        # Traverse both linked lists until both are exhausted
        while l1 or l2 or carry:
            # Get values from current nodes, or 0 if the list is exhausted
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0
            
            # Compute sum and carry
            total = val1 + val2 + carry
            carry = total // 10  # Carry for the next digit
            current.next = ListNode(total % 10)  # Add new digit to result
            
            # Move to the next nodes in l1 and l2
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
            current = current.next

        # Return the next node of the dummy, which is the head of the result
        return dummy.next
