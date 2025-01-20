class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to serve as the head of the merged list
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;

        // Traverse both lists and merge them in sorted order
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        // Attach the remaining nodes of the non-empty list
        if (list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }

        // Return the head of the merged list
        ListNode* mergedHead = dummy->next;
        delete dummy; // Clean up the dummy node
        return mergedHead;
    }
};
