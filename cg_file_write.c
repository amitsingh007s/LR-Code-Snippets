/********************************************************************/
/* Function Name: cg_file_write
/* Purpose      : File write
/* Input        : Buffer,file name and mode. Mode can be either "a" or "w"
/* Output       : Data written to file
/******************************************************************/

int cg_file_write(char* buffer,char* filename,char* mode)
{
	int fp;

	if(mode == "w")
	{
		fp = fopen (filename,mode);

		if(fp == NULL)
		{
			lr_error_message("ERROR: Unable to open file");
		}
	}

	else if(mode == "a")
	{
		fp = fopen (filename,mode);

		if(fp == NULL)
		{
			lr_error_message("ERROR: Unable to open file");
		}

	}

	else
	{
		lr_output_message("ERROR: Enter either 'w' or 'a' for mode");

		return -1;
	}
    
    fprintf(fp,"%s",buffer);
	fclose(fp);
	
}
