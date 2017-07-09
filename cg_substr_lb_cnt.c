/********************************************************************/
/* Function Name: cg_substr_lb_cnt
/* Purpose      : Extract a string between left boundary and end of string
/*                for the given occurence.. 
/* Input        : 
/* Output       : 
/******************************************************************/
						
char* cg_substr_lb_cnt(char* src,char* lbound, int cnt)
{

	char* lpos;
    char* newstring;
	char* tmpstring;

	int start,end,length,i,j,op;

    int lblength = strlen(lbound);

	lpos = (char *)strstr(src, lbound); 

    // strstr has returned the address. Now calculate * the offset from the beginning of str 

    start = (int)(lpos - src + 1); 

	if(start<0)
	{

		lr_output_message("-->ERROR:The left boundary value'%s' - Not found in source <--",lbound);

		return("-1");
				
    }

	//lr_output_message ("The lbound \"%s\" was found at position %d", lbound, start);

	start = start + lblength; // calculate the start position
	
   	length= strlen(src);

	if(length<0)
	{
		lr_output_message("-->ERROR:Enter string with some characters<--");

        return("-1");
        
	}

    
		newstring = (char*)malloc(length+1);

		memset(newstring,'\0',length+1);

		tmpstring = (char*)strdup(src);

		/* Msg: move pointer for the number of occcurence */

		for (j=0;j<cnt;j++) 
		{
			for(i=1;i<start;i++)
			{
				tmpstring++;
			}

			strncpy(newstring,tmpstring,length);

			lpos = (char *)strstr(newstring, lbound); 

			start = (int)(lpos - newstring + 1); 

			//lr_output_message("The value of start is:%d",start);

			if(start<0)
			{
				op=j+1;

                //lr_output_message("-->Last occurence of '%s' found for occurance count %d ;the occurence value entered is %d<--",lbound,op,cnt);

				if(op<cnt)
				{
					lr_output_message("ERROR:Left boundary not found for the given occurrence count");
									  
					return("-1");
				}

				//return("-1");
        	}

			else
			{
				lr_output_message ("The lbound \"%s\" was found at position %d", lbound, start);

				/* Calculate new start position */

				start = start + lblength;
			
				length= strlen(newstring);

				if(length<0)
				{
					lr_output_message("-->ERROR:Enter string with some characters<--");

					return("-1");
        
				}
			}


		}

        lr_output_message("Substring from left boundary is ::>%s",newstring);

        return newstring;

        
}
