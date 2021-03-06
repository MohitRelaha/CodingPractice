/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 * 
 * typedef struct TreeNode treenode;
 * 
 * treenode* treenode_new(int val) {
 *     treenode* node = (treenode *) malloc(sizeof(treenode));
 *     node->val = val;
 *     node->left = NULL;
 *     node->right = NULL;
 *     return node;
 * }
 */

 
struct stack{
  treenode* data;
  struct stack* next;
};

typedef struct stack st;

void push(st** top,treenode* val)
{
    st* temp = (st*)malloc(sizeof(st));
    temp->data = val;
    temp->next = *top;
    *top = temp;
}

void pop(st** top)
{
    if(*top == NULL)
        return;
    
    st* temp = *top;
    *top = (*top)->next ;
    free(temp);
    temp = NULL;
}
 
treenode* peek(st* top)
{
    if(top == NULL)
        return top;
        
    return top->data;
}

int empty(st* top)
{
    if(top == NULL)
        return 1;
    
    return 0;
}


int* inorderTraversal(treenode* A, int *len1) {
    
    int* arr = (int*)malloc(sizeof(int)*0);
    int count = 0;
    
    st* s = NULL;
    
    treenode* cur = A;
    
    while(cur || !empty(s))
    {
        while(cur)
        {
            push(&s,cur);
            cur = cur->left;
        }
        
        treenode* temp = peek(s);
        if(temp)
        {
            pop(&s);
            
            count++;
            arr = (int*)realloc(arr,sizeof(int)*count);
            arr[count-1] = temp->val;
            
            cur = temp->right;
        }
        
        
    }
    
    
    *len1 = count;
    return arr;
}

