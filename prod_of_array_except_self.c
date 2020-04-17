

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int mul_num(int * arr, int size, int skip_num)
{
    static int ans = 0;
    if(size == 0)
    {
      
        return arr[size];
    
    }
    else
    {
           if(size != skip_num)
              ans = arr[size]* mul_num(arr,(size -1),skip_num);
            else
            {
                if((size -1) == 0)
                {
                    ans = arr[size]* mul_num(arr,(size -1),skip_num);
                }
                else
                {
                     ans = arr[size]* mul_num(arr,(size -2),skip_num);
                }
            }
        
        
    }
   return ans;
}

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

