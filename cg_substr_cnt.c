/***************************************************************************/
/* Function Name: cg_substr_cnt
/* Purpose      : Extract a string between left boundary and right boundary. 
/*                for the given occurrence
/* Input        : 
/* Output       : 
/************************************************************************/

char* cg_substr_cnt(char* source,char* lbound, char* rbound, int cnt)
{

	char* lposition;
    char* rposition;
	int begin,end,i,j,length;

    char* newstring;
	char* tmpstring;

	char* newstring1;
	char* tmp;
	char* temp;

    int lblength = strlen(lbound);

	lposition = (char *)strstr(source, lbound); 

    // strstr has returned the address. Now calculate * the offset from the beginning of str 

    begin = (int)(lposition - source + 1); 

	length= strlen(source);

	if(length<0)
	{
		lr_output_message("Enter string with some characters");
	}

	newstring = (char*)malloc(length+1);

	memset(newstring,'\0',length+1);

	strncpy(newstring,source,length);

	
	/* Verifying count values */

	if(cnt == 0)
	{
		lr_output_message("Enter occurrence value as 1 or >1");

		return("-1");
	}

	/* Moving begin index for the number of occurence */

	if(cnt>1)
	{
        temp = (char*)malloc(length+1);
		temp = (char*)strdup(source);

		for(j=0;j<cnt;j++)
		{
			for(i=1;i<begin;i++)
			{
				temp++;
			}

			lposition = (char *)strstr(temp, lbound);

			begin = (int)(lposition - temp + 1);

			begin = begin + lblength;
			
			length= strlen(newstring);

           	strncpy(newstring,temp,length);

			//lr_output_message("The newstring value is :%s",newstring);

        }

		/* Noting down the new begin position */

		lposition = (char *)strstr(newstring, lbound);

		begin = (int)(lposition - newstring + 1); 

		if(begin<0)
		{
			lr_output_message("The argument occurence count exceeds the left boundary occurrence count");

			return("-1");

			
		}
		
    }

        newstring1 = (char*)malloc(length+1);

		memset(newstring1,'\0',length+1);

		tmpstring = (char*)strdup(newstring);

		begin = begin + lblength;

		/* Extracting string from the new begin value */

		for(i=1;i<begin;i++)
		{
			tmpstring++;
		}

		/* Finding right boundary in the new string */

		rposition = (char *)strstr(tmpstring, rbound);

		end = (int)(rposition - tmpstring + 1);

		/* Calculating length upto the begining of right boundary*/

		length = end - 1;

		//lr_output_message("The value of length is :%d",length); to verify length

		if(length < 0)
		{
			lr_output_message("ERROR: Verify right boundary");

			//length = strlen(newstring);

			return("-1");

			
		}

		/* Copying the extracted string to newstring 1*/
        
        strncpy(newstring1,tmpstring,length);

		lr_output_message("Substring is ::>%s",newstring1);

        return newstring1;
}

