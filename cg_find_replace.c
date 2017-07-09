/********************************************************************/
/* Function Name: cg_find_replace
/* Purpose      : Finds a string/character from the source and replaces with
/*                the specified replace string/character. 
/* Input        : source string, search string, replace string
/* Output       : 
/******************************************************************/

char* cg_replace(const char* src,const char* search,const char* replace)
{
    /* We need to find the length of the source string, seach and replace string*/

	size_t size       = strlen(src) + 1;
	size_t searchlen  = strlen(search);
	size_t replacelen = strlen(replace);

	/* Allocate memory to values */

	char* value = (char*)malloc(size);

    /* defining return value */

	char* ret = value;

	ret = value;

	/* Verify Malloc */

	if (value != NULL)
    {
		/* loop untill no match is found */
		for(;;)
		{
			/* Find the search string */

			const char* match = (char*)strstr(src,search);

			if(match != NULL)
			{
				/* Found search text at location match,
				 * Find how many characters to copy in match */

				size_t count = match - src;

				/* Re-allocate memory, use a temp variable for pointer */

				char* temp;

				/* Calculating the total length of the string after allocation */

				size += replacelen - searchlen;

				/* realloc memory*/

				temp = (char*)realloc(value,size);

				if(temp == NULL)
				{
					/* Re allocation of memory failed so free the malloc'd memory*/

					free(value);

					return NULL;
				}

				/* Re-allocation successful. Now point the pointer to value */

				ret = temp + (ret - value);

				value = temp;

				/* copy from the source to where we matched.
				 * Then move the source pointer to this point and move the 
				 * destination pointer ahead by same amount */

				memmove(ret,src,count);

				src += count;
				ret += count;

				/* Now copy the replacement text 'replace' at the position of match.
				* Adjust the source pointer by the text we replaced 
				* Adjust the destination pointer with the amount of replacement */

				memmove(ret,replace,replacelen);

				src += searchlen;
				ret += replacelen;

			}

			else /* No Match found */
			{
				/* Copy the remaining part of the string */

				strcpy(ret,src);

				break;
			}


		}
	}

	return value;
}

const char* cg_find_replace(const char* source,const char* str,const char* repl)
{
	const char* after;

	after = cg_replace(source,str,repl);

	lr_output_message("The find string is: '%s' and replace string is '%s'",str,repl);

	if(after != NULL)
	{
		//lr_output_message("The string after replacement::> %s",after);

		strcpy(source,after);
		
	}

	else
	{
		lr_output_message("ERROR: String replace problem");
	}

	//strcpy(source,after);

	return source;
}

