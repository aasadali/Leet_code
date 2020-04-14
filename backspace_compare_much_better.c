void remove_unwated_chars(char * s)
{
    int x = 0;
    int new_len = 0;
    for(x = 0; x < strlen(s); x++)
    {
        if(s[x] == '#')
        {
            if(new_len > 0)
            {
                new_len--;
            }
            
            
        }
        else
        {
           s[new_len] = s[x];
            new_len++;
            
           
        }
        printf("%s\n", s);
    }
    s[new_len] ='\0';
}
bool backspaceCompare(char * S, char * T){


    remove_unwated_chars(S);
    remove_unwated_chars(T);
    if(!strcmp(S,T))
    {
        return true;

    }

    return false;

}
