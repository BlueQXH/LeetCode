/**
 * Definition for singly-linked list.
 * struct ListNode
 * {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (head != nullptr && k > 0)
        {
            ListNode *pEnd = head;
            int len = 1;
            while (pEnd->next != nullptr)
            {
                ++len;
                pEnd = pEnd->next;
            }
            k %= len;
            if (k != 0)
            {
                ListNode *pHead = head;
                for (int i = 0; i < len-k-1; ++i)
                {
                    pHead = pHead->next;
                }
                pEnd->next = head;
                head = pHead->next;
                pHead->next = nullptr;
            }
        }
        return head;
    }
};
