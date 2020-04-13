/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

void simplify_string(char * S){

    int  charIndex = 0;
    int  bspaceIndex = 0;
    int  bspaceCount = 0;

    while(S[charIndex] != '\0' || (bspaceCount != 0))
    {
        if(S[charIndex] == '#')
        {

           bspaceCount ++;
          // S[charIndex] = ' ';
           //charIndex++;
           memmove(&S[charIndex], &S[charIndex + 1], strlen(S) - charIndex);
        }
        else if(S[charIndex] != '#')
        {
           if(bspaceCount > 0)
           {
               if(bspaceIndex == 0)
               {
                   bspaceIndex = ++charIndex;
                   bspaceCount = 0;
                   continue;

               }
               else
               {
                  bspaceIndex = (bspaceIndex != 0) ? --bspaceIndex : bspaceIndex;
                  charIndex = (charIndex != 0) ? --charIndex : charIndex;
               }
               while(bspaceCount != 0)
               {
                   memmove(&S[bspaceIndex], &S[bspaceIndex + 1], strlen(S) - bspaceIndex);
                   if(bspaceIndex == 0)
                   {
                       bspaceCount = 0;
                       break;
                   }
                   else
                   {
                      bspaceIndex--;
                      charIndex--;
                   }
                   bspaceCount --;
               }



           }

           bspaceIndex = ++charIndex;
        }


    }

}
bool backspaceCompare(char * S, char * T){


    simplify_string(S);
    simplify_string(T);
    if(!strcmp(S,T))
    {
        return true;

    }

    return false;

}
