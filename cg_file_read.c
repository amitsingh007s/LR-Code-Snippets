/********************************************************************/
/* Function Name: cg_file_read
/* Purpose      : File read
/* Input        : file name
/* Output       : 
/******************************************************************/

int cg_file_read(char* filename,char* strOut)
{
    char data[1000];

    int fp;
    
    int i=1;

	strOut[0] = '\0';

    fp = fopen(filename,"r");

	if(fp == NULL)
	{
		lr_error_message("Cannot open %s", filename); 

		return -1;
	}

	else
	{
		//strcpy(strOut,"");

		while(! feof(fp))
		{
            while(fgets(data, 1000, fp)!=NULL) 
				{ 
					/* keep looping until NULL pointer... */

					/* print the file one line at a time  */

					lr_output_message( "The line %d is ==> \"%s\"",i, data);

					/* Concatenate the data */

                    strcat(strOut,data);

                    i++;
                  					
				}

            
              if (ferror(fp)) 
			  { 

                     lr_output_message ("Error reading file %s", filename); 

                     break;
			  }

		}
	}


   fclose(fp);

   if (ferror(fp)) 
   {
		lr_error_message("Error closing file %s", filename); 
	}

}


