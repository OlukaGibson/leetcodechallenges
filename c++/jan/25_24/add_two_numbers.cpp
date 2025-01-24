class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy node to simplify the implementation
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;

        // Traverse both linked lists
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry; // Start with the carry value

            if (l1 != nullptr) {
                sum += l1->val; // Add l1's value if it exists
                l1 = l1->next;  // Move to the next node
            }

            if (l2 != nullptr) {
                sum += l2->val; // Add l2's value if it exists
                l2 = l2->next;  // Move to the next node
            }

            carry = sum / 10; // Calculate the new carry
            current->next = new ListNode(sum % 10); // Add the digit to the result
            current = current->next; // Move to the next node
        }

        return dummy->next; // Return the result list, skipping the dummy node
    }
};
