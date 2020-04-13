#define MAX_TRIES  50

int f_n(int n)
{
    int sum = 0; 
    while(n)
    {
        int digit =  n %10;
        
        n = n/10;
        
        sum += (digit*digit);
        
        
        
    }
    return sum;
    
    
}

bool isHappy(int n){

    int num_tries = 0;
    while(num_tries < 50)
    {
        if(1 == n)
        {
            return true;

        }
        n = f_n(n);
        num_tries ++;
    }
      
    return false;
  }
    


