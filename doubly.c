#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head = NULL;
struct Node* createNode(int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev=NULL;
    return newNode;
}
void insertAtBeginning(int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        
    }
    else
    {
    newNode->next = head;
    (head)->prev = newNode;
    head = newNode;
    }
    
}
void insertAtEnd(int data)
{
    struct Node* newNode = createNode(data);
    if (head == NULL) 
        head = newNode;
    else
    {
        struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev=temp;
    newNode->next=NULL;
    }
}
void insertAtPosition(int data, int position)
{
    if (position < 1) {
        printf("Position should be >= 1.\n");
        return;
    }

    // if we are inserting at head
    if (position == 1) {
        insertAtBeginning(data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf(
            "Position greater than the number of nodes.\n");
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}
void deleteAtBeginning()
{
     if (head == NULL) {
        printf("The list is already empty.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {
        (head)->prev = NULL;
    }
    free(temp);
}
void deleteAtEnd()
{
    if (head == NULL) {
        printf("The list is already empty.\n");
        return;
    }

    struct Node* temp = head;
    if (temp->next == NULL) {
        head = NULL;
        free(temp);
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}
void deleteFromPosition(int position)
{
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
   struct Node* temp = head;
    if (position == 1) {
        deleteAtBeginning();
        return;
    }
    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position is greater than the number of "
               "nodes.\n");
        return;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
}
void displayList() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specified Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Specified Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                insertAtPosition(data, position);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(position);
                break;
            
            case 7:
                displayList();
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}