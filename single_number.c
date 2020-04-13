/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){

    struct ListNode * pTemp = head;
    int totalNodes = 0;
    int middleNode = 0;
    int x = 0;
    while(pTemp != NULL)
    {
        pTemp= pTemp->next;
        totalNodes ++;
        
    }
    middleNode = totalNodes/2;
    pTemp = head;
    while(x < middleNode)
    {
       pTemp = pTemp->next;
        x++;
    }
    
    return pTemp;

    
}

