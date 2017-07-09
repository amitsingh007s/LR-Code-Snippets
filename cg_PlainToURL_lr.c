/********************************************************************/
/* Function Name: cg_PlainToURL_lr
/* Purpose      : converts a plain text string into URL format string
/* Input        : sIn - String which needs to be converted to URL format
/* Output       : URL formatted string
/******************************************************************/
cg_PlainToURL_lr(char* sIn,char* sOut)
{
	sOut[0] = '\0';

	lr_save_string(sIn, "InputParam");

	web_convert_param("InputParam", 
				  "SourceEncoding=PLAIN",
				  "TargetEncoding=URL", 
				  LAST);

	//lr_output_message("%s", lr_eval_string("{InputParam}"));

	strcpy(sOut,lr_eval_string("{InputParam}"));

    
}
