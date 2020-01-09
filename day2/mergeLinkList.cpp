/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* prev = NULL;

        while(p1!=NULL)
        {
            if(p2!=NULL)
            {
                if(p1->val < p2->val)
                {
                    // insert the node
                    ListNode* temp = p1->next;
                    if(prev!=NULL)
                    {
                        prev->next = p1;
                        p1->next = p2;
                        prev = p1;
                    }
                    else
                    {
                        //smaller than the first item of l2
                        l2 = p1;
                        p1->next = p2;
                        p2 = p1;
                    }
                    p1 = temp;
                }
                else
                {
                    prev = p2;
                    p2 = p2->next;
                }
            }
            else
            {
                if(prev==NULL)
                {
                    l2 = l1;
                    p1 = NULL;
                }
                else
                {
                    prev->next = p1;
                    p1 = NULL;
                }
            }
        }

        return l2;
    }
};
