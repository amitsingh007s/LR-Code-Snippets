/********************************************************************/
/* Function Name: cg_substr
/* Purpose      : Extract a string between left boundary and right boundary. 
/* Input        : 
/* Output       : 
/******************************************************************/
						
char* cg_substr(char* source,char* lbound, char* rbound)
{

	char* lposition;
	char* rposition;
	int begin,end;

    

	int length;

	char* newstring;
	char* tmpstring;

    char* tmp;

	int i;

	int lblength = strlen(lbound);

	lposition = (char *)strstr(source, lbound); 

    // strstr has returned the address. Now calculate * the offset from the beginning of str 

    begin = (int)(lposition - source + 1); 

	//lr_output_message ("The lbound \"%s\" was found at position %d", lbound, begin);

	if(begin<0)
	{
		lr_output_message("ERROR:Verify Left boundary");

		return("-1");
	}

	begin = begin + lblength;

	rposition = (char *)strstr(source, rbound); 
    // strstr has returned the address. Now calculate * the offset from the beginning of str 
    end = (int)(rposition - source + 1); 

     
    //lr_output_message ("The rbound \"%s\" was found at position %d", rbound, end); 

	length= end-begin;

	if(length<0)
	{
        tmp = (char*)malloc(length + 1);

		tmp = (char*)strdup(source);

		for(i=1;i<begin;i++)
		{
			tmp++;
		}

		rposition = (char *)strstr(tmp, rbound);

		end = (int)(rposition - tmp + 1);

		//lr_output_message ("The new rbound \"%s\" was found at position %d", rbound, end);

        length= end - 1;

		if(length<0)
		{
			lr_output_message("ERROR: Verify right boundary value");

			return("-1");
		}

        
	}

    
		newstring = (char*)malloc(length+1);

		memset(newstring,'\0',length+1);

		tmpstring = (char*)strdup(source);

		for(i=1;i<begin;i++)
		{
			tmpstring++;
		}

		strncpy(newstring,tmpstring,length);

		lr_output_message("Substring is ::>%s",newstring);

        return newstring;
        
}

