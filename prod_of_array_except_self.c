
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
  
    int *prefix = malloc(sizeof(int)*numsSize);
    int *suffix = malloc(sizeof(int)*numsSize);
    int *self_product = malloc(sizeof(int)*numsSize);
    /*prefix products*/
    int x = 0;
    prefix[x] = 1;
    int prev_product = 1;
    for(x = 1; x < numsSize; x++)
    {
        prefix[x] = prev_product*nums[x-1];
        prev_product = prefix[x];
    }
    /*sufix products*/
    suffix[numsSize -1] = 1;
    prev_product = 1;

    for(x = numsSize -2; x >= 0; x--)
    {
        suffix[x] = prev_product*nums[x+1];
        prev_product = suffix[x];
    }
    for(x = 0; x < numsSize; x++)
    {
        self_product[x]= prefix[x]*suffix[x];
       // printf("self_product[%d]:%d", x ,self_product[x] );
        
    }
    *returnSize = numsSize;
    free(suffix);
    free(prefix);
    
    return self_product;
    

}

