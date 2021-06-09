/*  KEERTI GUPTA , 1900320130082 , IT-B

DS HOMEWORK1.2 : 30 APRIL, - C program to find union   and intersection of two unsorted linked lists*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

/* function to insert a
   node at the beginning of a linked list*/
void push(struct Node** head_ref, int new_data);

/* function to check if
   given data is present in a list */
bool isPresent(struct Node* head, int data);

/* Function to get union of two
   linked lists head1 and head2 */
struct Node* getUnion(
    struct Node* head1,
    struct Node* head2)
{
    struct Node* result = NULL;
    struct Node *t1 = head1, *t2 = head2;

    // Insert all elements of
    // list1 to the result list
    while (t1 != NULL) {
        push(&result, t1->data);
        t1 = t1->next;
    }

    // Insert those elements of list2
    // which are not present in result list
    while (t2 != NULL) {
        if (!isPresent(result, t2->data))
            push(&result, t2->data);
        t2 = t2->next;
    }

    return result;
}
/*  function to insert a
   node at the beginning of a linked list*/
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node
        = (struct Node*)malloc(
            sizeof(struct Node));

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* function to print a linked list*/
void printList(struct Node* node)
{
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

/* function that returns true if data is
   present in linked list else return false */
bool isPresent(struct Node* head, int data)
{
    struct Node* t = head;
    while (t != NULL) {
        if (t->data == data)
            return 1;
        t = t->next;
    }
    return 0;
}

/* program to test above function*/
int main()
{
    /* Start with the empty list */
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* intersecn = NULL;
    struct Node* unin = NULL;

    /*create a linked lits 10->15->5->20 */
    push(&head1, 20);
    push(&head1, 4);
    push(&head1, 15);
    push(&head1, 10);

    /*create a linked lits 8->4->2->10 */
    push(&head2, 10);
    push(&head2, 2);
    push(&head2, 4);
    push(&head2, 8);
    unin = getUnion(head1, head2);

    printf("\n First list is \n");
    printList(head1);

    printf("\n Second list is \n");
    printList(head2);


    printf("\n Union list is \n");
    printList(unin);

    return 0;
}

