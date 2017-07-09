/********************************************************************/
/* Function Name: cg_rtrim
/* Purpose      : Trims spaces on the right of the string
/* Input        : source string and the string to be trimmed
/* Output       : right trimmed string
/******************************************************************/

char* cg_rtrim(char* string, char junk)
{    
	char* original = string + strlen(string);
	while(*--original == junk);
	*(original + 1) = '\0';
	return string;
}
