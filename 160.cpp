class Solution1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode* tmpA = headA;
        ListNode* tmpB = headB;
        while (tmpA != nullptr || tmpB != nullptr) {
            if (tmpA == tmpB)
                return tmpA;
            tmpA = tmpA->next;
            tmpB = tmpB->next;
            if (tmpA == nullptr && tmpB != nullptr)
                tmpA = headB;
            else if (tmpB == nullptr && tmpA != nullptr)
                tmpB = headA;
        }
        return nullptr;
    }
};

class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        if (headA == headB)
            return headA;
        ListNode* tmpA = headA;
        ListNode* tmpB = headB;
        ptrdiff_t lenA = 1;
        ptrdiff_t lenB = 1;
        while (tmpA->next != nullptr) {
            tmpA = tmpA->next;
            ++lenA;
        }
        while (tmpB->next != nullptr) {
            tmpB = tmpB->next;
            ++lenB;
        }
        if (tmpA != tmpB)
            return nullptr;
        tmpA = headA;
        tmpB = headB;
        if (lenA < lenB) {
            ptrdiff_t n = lenB - lenA;
            while (n > 0) {
                tmpB = tmpB->next;
                --n;
            }
        }
        else if (lenB < lenA) {
            ptrdiff_t n = lenA - lenB;
            while (n > 0) {
                tmpA = tmpA->next;
                --n;
            }
        }
        while (tmpA != tmpB) {
            if (tmpA == tmpB)
                return tmpA;
            tmpA = tmpA->next;
            tmpB = tmpB->next;
        }
        return tmpA;
    }
};
