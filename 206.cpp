class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* root = new ListNode(0);
        ListNode* tail = nullptr;
        ListNode* tmp;
        do {
            tmp = head;
            head = head->next;
            root->next = tmp;
            tmp->next = tail;
            tail = tmp;
        } while (head != nullptr);
        tail = root->next;
        delete root;
        return tail;
    }
};

class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode *tail = head->next, *tmp;
        head->next = nullptr; //这一行代码非常重要，不将head->next置为空会形成环路
        while (tail != nullptr) {
            tmp = tail->next;
            tail->next = head;
            head = tail;
            tail = tmp;
        }
        return head;
    }
};

class Solution3 {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* result = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return result;
    }
};
