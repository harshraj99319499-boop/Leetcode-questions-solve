
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Dummy node before the head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        while (prev->next != nullptr &&
               prev->next->next != nullptr) {

            // First and second nodes of the pair
            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Swap the nodes
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move prev to the end of the swapped pair
            prev = first;
        }

        return dummy->next;
    }
};
