#define MOVING_ELEMENT  0
void moveZeroes (int *nums, int numsSize)
{

  int x, y= 0;
  int  last_zero_pos = numsSize;
  char non_zero_element = 0;
  
    for(x= 0; x < numsSize; x++)
    {
          if(nums[x] > 0)
          {
              non_zero_element = 1;
              break;
          }
    }
    if(non_zero_element == 1)
    {
      for(x= 0; x < numsSize; x++)
      {
        if(last_zero_pos <= x)
        {
                break;
        }
        while((MOVING_ELEMENT == nums[x]))
        {
          /*shift elements */
            for(y = x; y < numsSize - 1; y++)
            {
              nums[y] = nums[y + 1];
            }
              nums[numsSize - 1] = MOVING_ELEMENT;
              last_zero_pos--;    
            if(last_zero_pos <= x)
            {
              break;
            } 
        }



      } 
    }
}
