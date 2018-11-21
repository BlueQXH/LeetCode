class Solution1
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
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

class Solution2
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
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

/**
 * Definition for singly-linked list.
 * struct ListNode
 * {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution3
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        stack<ListNode *> stack_A;
        stack<ListNode *> stack_B;
        
        ListNode *pNode = headA;
        while (pNode != nullptr)
        {
            stack_A.push(pNode);
            pNode = pNode->next;
        }
        pNode = headB;
        while (pNode != nullptr)
        {
            stack_B.push(pNode);
            pNode = pNode->next;
        }
        
        pNode = nullptr;
        while (!stack_A.empty() && !stack_B.empty())
        {
            if (stack_A.top() == stack_B.top())
            {
                pNode = stack_A.top();
                stack_A.pop();
                stack_B.pop();
            }
            else
            {
                return pNode;
            }
        }
        return pNode;
    }
};
