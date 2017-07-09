/********************************************************************/
/* Function Name: cg_LTrim
/* Purpose      : Trims spaces on the left of the string
/* Input        : source string and the string to be trimmed
/* Output       : left trimmed string
/* Created by   : V.M.Guruprasath
/* Date created : December 16, 2008
/******************************************************************/

char* cg_ltrim(char *string, char junk)
{    
	char* original = string;
	char *p = original;
	int trimmed = 0;
	do 
		{       
		  if (*original != junk || trimmed) 
			  {           
			     trimmed = 1; 
				 *p++ = *original;
			  } 
	    }

	    while (*original++ != '\0');

		return string;
}
