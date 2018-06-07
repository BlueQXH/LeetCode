class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode *tail = head->next, *tmp;
        head->next = nullptr;
        while (tail != NULL) {
            tmp = tail->next;
            tail->next = head;
            head = tail;
            tail = tmp;
        }
        return head;
    }
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;
        ListNode *slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = reverseList(slow->next);
        while (slow != nullptr) {
            if (slow->val != head->val)
                return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};
