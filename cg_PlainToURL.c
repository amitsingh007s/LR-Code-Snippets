/********************************************************************/
/* Function Name: cg_PlainToURL
/* Purpose      : converts a plain text string into URL format string
/* Input        : StrIn - Input String, 
/* Output       : URL format string (StrOut - Output buffer)
/******************************************************************/

char* cg_PlainToURL(char* strIn, char* strOut)
{
	int i;
	char curChar;
	char curStr[4] = {0};

	strOut[0] = '\0';

	for (i=0;curChar=strIn[i];i++)
	{
		if(isdigit(curChar) || isalpha(curChar)) // Verify whether the character is digit or alphabet
		{
			sprintf(curStr,"%c",curChar); // If yes, then print as such
		}

		else
		{
			sprintf(curStr,"%%%X",curChar); // else convert it into hex string
		}

		strcat(strOut,curStr); // Concatenate the output

	}

	return strOut;
}

