/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 * sortedInsert - inserts a node to sorted list into correct position
 * @sortedHead: pointer to start of the sorted list
 * @curr: the node tobe inserted
 * Return: pointer to start of sorted list
 */

struct ListNode* sortedInsert(struct ListNode** sortedHead, struct ListNode *curr){
    if (*sortedHead == NULL || (*sortedHead)->val >= curr->val){
        curr->next = *sortedHead;
        *sortedHead = curr;
        return (*sortedHead);
    }
    else{
        struct ListNode *temp = *sortedHead;
        while (temp->next != NULL && curr->val> temp->next->val){
            temp = temp->next;
        }
        curr->next = temp->next;
        temp->next=curr;
    }
    return (*sortedHead);
}

/**
 * insertionSort - sorts a given singly-linked-list
 * @head: pointer to the start of a list
 * Return: pointer to start of the sorted list
 */
struct ListNode* insertionSortList(struct ListNode* head){
    struct ListNode *curr = head;
    struct ListNode *sortedHead = NULL;
    
    while (curr != NULL)
    {
        struct ListNode *curNext = curr->next;
        sortedHead = sortedInsert(&sortedHead, curr);
        curr = curNext;
    }
    return (sortedHead);
}
