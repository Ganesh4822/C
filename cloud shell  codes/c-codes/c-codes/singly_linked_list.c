#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//struct data
typedef struct _employee{
    char name[32];
    unsigned int age;

}Employee;

//struct list
typedef struct _node{
    void* data;
    struct _node* next;
}Node;

typedef struct _list{
    Node* head;
    Node* tail;
}List;

//function pointers
typedef int (*COMPARE)(void*,void*);
typedef void (*DISPLAY)(void*);
typedef void (*DEALLOCATEOBJECT)(void*);

//Employee helper Routines

int compareEmployee(Employee* emp,Employee* emp2);
void displayEmployee(Employee* emp);
void deallocateEmployee(Employee* employee);

//linked List routines
void initializeList(List*);
void addHead(List*,void*);
void addTail(List*,void*);
Node* searchNode(List*,void*,COMPARE);
void delete(List*,Node*);
void displayList(List*,DISPLAY);
void free_linked(List*);

int main(void)
{
    List linkedList ;

    Employee *samuel = (Employee*) malloc(sizeof(Employee));
    strcpy(samuel->name, "Samuel");
    samuel->age = 32;
    Employee *sally = (Employee*) malloc(sizeof(Employee));
    strcpy(sally->name, "Sally");
    sally->age = 28;
    Employee *susan = (Employee*) malloc(sizeof(Employee));
    strcpy(susan->name, "Susan");
    susan->age = 45;
    initializeList(&linkedList);
    addHead(&linkedList, samuel);
    addHead(&linkedList, sally);
    addHead(&linkedList, susan);
    displayList(&linkedList, (DISPLAY)displayEmployee);
    Node* node = searchNode(&linkedList,sally,(COMPARE)compareEmployee);
    delete(&linkedList,node);
    displayList(&linkedList, (DISPLAY)displayEmployee);
    free_linked(&linkedList);
    
    deallocateEmployee(samuel);
    deallocateEmployee(sally);
    deallocateEmployee(susan);

}

//definations
//Employee helper Routines

int compareEmployee(Employee* emp,Employee* emp2)
{
    return(strcmp(emp->name,emp2->name));
}

void displayEmployee(Employee* employee) {
 printf("%s\t%d\n", employee->name, employee->age);
}

void deallocateEmployee(Employee* employee)
{
    free(employee);
    employee = NULL;
}

//List functios
void initializeList(List* list)
{
    list->head = NULL;
    list->tail = NULL;
}

void addHead(List* list,void* data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    if(list->head == NULL)
    {
        list->tail = node;
        node->next = NULL;
    }else {
        node->next = list->head;
    }
    list->head = node;
}

void addTail(List* list,void* data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node ->data = data;
    if(list->head == NULL)
    {
        list->head = node;
        node->next = NULL;
    }else{
        list->tail->next = node;
        
    }
    list->tail = node; 
}

Node* searchNode(List* list,void* data,COMPARE compare)
{
    //Node* node = (Node*)malloc(sizeof(Node));
    Node* node = list->head;
    while(node->next != NULL)
    {
        if(compare(data,node->data) == 0)
        {
            return node;
        }
        node = node ->next;
    }
    return NULL;
}

void delete(List* list,Node* node)
{
    if(node == list->head)
    {
    
        if(list->head->next == NULL)
        {
            list->tail = list->head = NULL;
        }else {
            list->head = list->head->next;
        }
        
    }else{
       
        Node* tmp = list->head;
        while(tmp != NULL && tmp->next != node )
        {
            tmp = tmp ->next;
        }
        if(tmp != NULL)
        {
            tmp->next = node->next;
        }
        
    }

    free(node);
    node = NULL;
    printf("deletion successful\n");

}

void displayList(List* list,DISPLAY display)
{
    printf("\nLinked List\n");
    Node *current = list->head;
    while (current != NULL) {
    display(current->data);
    current = current->next;
    }

}

void free_linked(List* list)
{
    Node* tmp = list->head;
    Node* nodeToFree = tmp;;
    while(tmp != NULL)
    {
        nodeToFree = tmp;
        tmp = tmp->next;
        free(nodeToFree);
    }
    printf("All nodes are deleted");
}

