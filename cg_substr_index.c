/********************************************************************/
/* Function Name: cg_substr_index
/* Purpose      : Extracts a string between the start index and end index. 
/* Input        : Source string, Stat index and end index
/* Output       : Extracted sting between the start and end index
/******************************************************************/

char* cg_substr_index(char* source,int begin, int end)
{
	int length = end-begin;

	char* newstring;
	char* tmpstring;

	int i, len;

	len = strlen(source);

	if(end>len)
	{
		lr_output_message("ERROR:Verify right bound index");

		return("-1");
	}

    if(length<=0)
	{
		lr_output_message("ERROR: Enter start and end index value to extract atleast 1 character");

		return("-1");

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


