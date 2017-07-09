/********************************************************************/
/* Function Name: cg_trim
/* Purpose      : Trims spaces/characters on the left & right of the string
/* Input        : source string and the string to be trimmed
/* Output       : left& right trimmed string
/******************************************************************/
char* cg_trim(char* string,char ljunk,char rjunk)
{
	cg_rtrim(string,rjunk);
	cg_ltrim(string,ljunk);

	return string;

}