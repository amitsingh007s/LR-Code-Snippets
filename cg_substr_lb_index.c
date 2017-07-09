/********************************************************************/
/* Function Name: cg_substr_lb_index
/* Purpose      : Extracts a string between the start index and end of string. 
/* Input        : Source string and start index
/* Output       : Extracted string from start index to last.
/******************************************************************/
						
char* cg_substr_lb_index(char* src,int startIndex)
{
    char* buffer;
	char* temp;

	int cnt;

	int length = strlen(src);

	if(length<0)
	{
		return("-1");

	}

	buffer = (char*)malloc(length+1);

	memset(buffer,'\0',length+1);

	temp = (char*)strdup(src);

	for(cnt=1;cnt<startIndex;cnt++)
	{
		temp++;
	}

	strncpy(buffer,temp,length);

	lr_output_message("Substring from left boundary is ::>%s",buffer);

	return buffer;

}

