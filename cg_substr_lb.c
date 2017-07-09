/********************************************************************/
/* Function Name: cg_substr_lb
/* Purpose      : Extract a string between left boundary and end of string. 
/* Input        : 
/* Output       : 
/******************************************************************/

char* cg_substr_lb(char* src,char* lbound)
{

	char* lpos;
    char* newstring;
	char* tmpstring;

	int start,end,length,i;

    int lblength = strlen(lbound);

	lpos = (char *)strstr(src, lbound); 

    // strstr has returned the address. Now calculate * the offset from the beginning of str 

    start = (int)(lpos - src + 1); 

	lr_output_message ("The lbound \"%s\" was found at position %d", lbound, start);

	start = start + lblength;
	
   	length= strlen(src);

	if(length<0)
	{
		lr_output_message("-->Enter string with some characters<--");

        return("-1");
        
	}

    
		newstring = (char*)malloc(length+1);

		memset(newstring,'\0',length+1);

		tmpstring = (char*)strdup(src);

		for(i=1;i<start;i++)
		{
			tmpstring++;
		}

		strncpy(newstring,tmpstring,length);

		lr_output_message("Substring is ::>%s",newstring);

        return newstring;

        
}
