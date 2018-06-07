class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* tail = head;
        ListNode* tmp = nullptr;
        while (tail->next != nullptr) {
            if (tail->val == tail->next->val) {
                ListNode* del = nullptr;
                if (tail->next->next != nullptr) {
                    tmp = tail->next->next;
                    tail->next->next = nullptr;
                    del = tail->next;
                    tail->next = tmp;
                    delete del;
                    continue;
                }
                else {
                    del = tail->next;
                    tail->next = nullptr;
                    delete del;
                    continue;
                }
            }
            tail = tail->next;
        }
        return head;
    }
};
