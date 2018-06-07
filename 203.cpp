class Solution1 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
            return head;
        ListNode* tail = head;
        ListNode* pre = nullptr;
        while (tail != nullptr) {
            if (tail == head && tail->val == val) {
                tail = tail->next;
                delete head;
                head = tail;
            }
            else if (tail->val == val) {
                pre->next = pre->next->next;
                delete tail;
                tail = pre->next;
            }
            else {
                pre = tail;
                tail = pre->next;
            }
        }
        return head;
    }
};

class Solution2 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
            return head;
        ListNode* root = new ListNode(0);
        root->next = head;
        ListNode* pre = root;
        while (head != nullptr) {
            if (head->val == val) {
                pre->next = pre->next->next;
                delete head;
                head = pre->next;
            }
            else {
                pre = pre->next;
                head = head->next;
            }
        }
        head = root->next;
        delete root;
        return head;
    }
};
