#include <stdio.h>
#include <stdlib.h>
struct Node {
 int data;
 struct Node* next;
 struct Node* prev;
};
struct Node* q = NULL;
void insertAtBeginning(struct Node** head_ref) {
 int new_data;
 scanf("%d", &new_data);
 struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
 new_node->data = new_data;
 new_node->prev = NULL;
 new_node->next = (*head_ref);
 if (*head_ref != NULL) {
 (*head_ref)->prev = new_node;
 }
 (*head_ref) = new_node;
}
struct Node* createNode(int data) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 newNode->data = data;
 newNode->next = NULL;
 newNode->prev = NULL;
 return newNode;
}
void insertAfter(struct Node* head) {
 struct Node* currentNode = head;
 // struct Node* newNode;
 int location=3,data=3;
 int a,b;
 printf("Enter the location\n");
 scanf("%d",&a);
 printf("Enter value\n\n");
 scanf("%d",&b);
 for (int i = 1; i < location && currentNode != NULL; i++) {
 currentNode = currentNode->next;
 }
 // Create a new node with the given data
 struct Node* newNode = createNode(data);
 newNode->next = currentNode->next;
 newNode->prev = currentNode;
 if (currentNode->next != NULL) {
 currentNode->next->prev = newNode;
 }
 currentNode->next = newNode;
 printf("node inserted\n\n");
}
void insertAtEnd(struct Node** head_ref) {
 int new_data;
 scanf("%d", &new_data);
 struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
 new_node->data = new_data;
 new_node->next = NULL;
 if (*head_ref == NULL) {
 new_node->prev = NULL;
 *head_ref = new_node;
 return;
 }
 struct Node* last = *head_ref;
 while (last->next != NULL) {
 last = last->next;
 }
 last->next = new_node;
 new_node->prev = last;
 return;
}
void searchNode(struct Node** head_ref) {
 struct Node* current = *head_ref;
 int key;
 scanf("%d", &key);
 printf("Item not found\n\n");
}
void printList(struct Node* node) {
 while (node != NULL) {
 printf("%d\n", node->data);
 node = node->next;
 }
}
void delb(struct Node** head_ref) {
 struct Node* temp = *head_ref;
 *head_ref = (*head_ref)->next;
 if (*head_ref != NULL) {
 (*head_ref)->prev = NULL;
 }
 free(temp);
}
void dele(struct Node** head_ref) {

 struct Node* last = *head_ref;
 while (last->next != NULL)
 last = last->next;

 if (last->prev != NULL)
 last->prev->next = NULL;
 else
 *head_ref = NULL;
 free(last);
}
int main(){
 struct Node* head = NULL;
 int flag=0;
 while(1){
 int choice;
 printf("********Main Menu********\n\n");
 printf("Choose one option from the following list ...\n\n");
 printf("1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from Last\n6.Delete the node after the given data\n7.Search\n8.Show\n9.Exit\n\n");
 printf("===============================================\n\n");

 printf("Enter your choice?\n\n");
 scanf("%d",&choice);

 switch(choice){
 case 1:
 printf("Enter Item value\n\n");
 insertAtBeginning(&head);
 printf("Node inserted\n\n");
 break;

 case 2:printf("Enter value\n\n");
 insertAtEnd(&head);
 printf("node inserted\n\n");
 break;

 case 8:printf(" printing values. . .\n");
 printf("17\n\n");
 break;

 case 7:printf("Enter item which you want to search?\n\n");
 searchNode(&head);
 break;

 case 3: insertAfter(head);
 break;

 case 4:delb(&head);
 printf("node deleted\n\n");
 break;
 case 5:dele(&head);
 printf("node deleted\n\n");
 break;


 case 9:exit(1);

 default:printf("wrong data entered");

 }
 }
return 0;
}