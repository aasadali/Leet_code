#define NULL 0
typedef struct 
{
    signed int val;
    signed int min;
    struct stackNode * prev;
    
}stackNode;

typedef struct {
  stackNode * sp; /*stack pointer*/
} MinStack;



/** initialize your data structure here. */

MinStack* minStackCreate() {
    
    MinStack *  mem_stack = malloc(sizeof(MinStack));
    mem_stack->sp = NULL;
    return mem_stack;
    
}

void minStackPush(MinStack* obj, int x) {
  
    if(NULL == obj->sp)
    {
        obj->sp = malloc(sizeof(stackNode));
        obj->sp->val = x;
        obj->sp->prev = NULL;
        obj->sp->min  = x;
        
    }
    else
    {
        int prev_val = obj->sp->min;
        stackNode * new_node = malloc(sizeof(stackNode));
        new_node->val = x;
        new_node->prev = obj->sp;
        obj->sp = new_node;
        obj->sp->min = (x < prev_val) ? x : prev_val;
        
        
    }
}

void minStackPop(MinStack* obj) {
    
    struct stackNode * node_to_pop = obj->sp;
    obj->sp = obj->sp->prev;
    free(node_to_pop);
  
}

int minStackTop(MinStack* obj) {
    
    return obj->sp->val; 
}

int minStackGetMin(MinStack* obj) {
  
   return obj->sp->min;
}

void minStackFree(MinStack* obj) {
     
    while(obj->sp != NULL)
    {
         struct stackNode * node_to_remove = obj->sp;
         obj->sp = obj->sp->prev;
         free(node_to_remove);
        
    }
    
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/