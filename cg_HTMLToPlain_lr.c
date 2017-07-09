/********************************************************************/
/* Function Name: cg_HTMLToPlain_lr
/* Purpose      : converts a URL format string into plain text string
/* Input        : sIn1 - HTML string which needs to be converted to Plain format
/* Output       : Plain formatted string
/******************************************************************/
cg_HTMLToPlain_lr(char* sIn1,char* sOut)
{
	sOut[0] = '\0';

    lr_save_string(sIn1, "InputParam");

	web_convert_param("InputParam", 
					  "SourceEncoding=HTML",
					  "TargetEncoding=PLAIN",
					  LAST);

	//lr_output_message("%s", lr_eval_string("{InputParam}"));

	strcpy(sOut,lr_eval_string("{InputParam}"));


}
