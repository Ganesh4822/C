#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//struct data
typedef struct _employee{
    char name[32];
    int age;
}Employee;

//struct BST
typedef struct _bst{
    void* data;
    struct _bst *left;
    struct _bst *right;
}TreeNode;

//Function pointers
typedef int (*COMPARE)(void*,void*);
typedef void (*DISPLAY)(void*);

//Employee helpers
int compareEmployee(Employee* emp,Employee* emp2);
void displayEmployee(Employee* emp);
int compareEmployeeage(Employee* emp1, Employee* emp2);

//Bst functions
void initializeBST(TreeNode* bst);
void insert(TreeNode** bst, void* data, COMPARE compare);
void preorder(TreeNode* root,DISPLAY displayfun);
void postorder(TreeNode* root,DISPLAY displayfun);
void inorder(TreeNode* root,DISPLAY displayfun);
void distroy_bst(Treenode** node);

int main()
{
    Employee *samuel = (Employee*) malloc(sizeof(Employee));
    strcpy(samuel->name, "Samuel");
    samuel->age = 32;
    Employee *sally = (Employee*) malloc(sizeof(Employee));
    strcpy(sally->name, "Sally");
    sally->age = 28;
    Employee *susan = (Employee*) malloc(sizeof(Employee));
    strcpy(susan->name, "Susan");
    susan->age = 45;
    TreeNode *tree = NULL;
    insert(&tree, samuel, (COMPARE) compareEmployeeage);
    insert(&tree, sally, (COMPARE) compareEmployeeage);
    insert(&tree, susan, (COMPARE) compareEmployeeage) ;
    inorder(tree, (DISPLAY) displayEmployee);



}

int compareEmployee(Employee* emp,Employee* emp2)
{
    return(strcmp(emp->name,emp2->name));
}

void displayEmployee(Employee* emp)
{
    printf("%s\t%d\n", emp->name, emp->age);
}

int compareEmployeeage(Employee* emp1, Employee* emp2){
    if(emp1->age > emp2->age)
    {
        return 1;
    }
    else 
    {
        return 0;    
    }
}


//BST Functions
void initializeBST(TreeNode* bst)
{
    bst->data = NULL;
    bst->left = NULL;
    bst->right = NULL;
}
void insert(TreeNode** root, void* data, COMPARE compare)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node ->data = data;
    node->left =NULL;
    node->right = NULL;
    
    if(*root == NULL)
    {
        *root = node;
        return;
    }

    while(1)
    {
        if(compare((*root)->data,data)>0)
        {
            if((*root)->left != NULL)
            {
                *root = (*root)->left;
            }
            else
            {
                (*root) ->left = node;
                break;
            }

        }
        else 
        {
            if((*root)->right != NULL)
            {
                *root = (*root)->right;
            }
            else {
                (*root)->right = node;
                break;
            }
        
        }
    }
}

void preorder(TreeNode* root,DISPLAY displayfun)
{
    if(root != NULL)
    {
        displayfun(root->data);
        preorder(root->left, displayfun);
        preorder(root->right, displayfun);
    }
    
}
void postorder(TreeNode* root,DISPLAY displayfun)
{
    if(root != NULL)
    {
    postorder(root->right, displayfun);
    postorder(root->left, displayfun);
    displayfun(root->data);
    }
}
void inorder(TreeNode* root,DISPLAY displayfun){
	if(root!= NULL)
	{
    		inorder(root->left,displayfun);
    		displayfun(root ->data);
    		inorder(root->right,displayfun);
	}
}


