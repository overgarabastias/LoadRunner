char *borrarBasura(char *strSource, char *szParamName)
{	
	char strTemp[1024];
	char *s = (char*)strSource;
	int i=0;
 
	while(*s)
	{
	    strTemp[i++] = *s;
	    if (strncmp(s,"&amp;amp;",9) == 0)
	    {
	        s += 9;
	    }
	    else{
	        s++;
	    }
	}
	strTemp[i] = 0;
	    
    return strTemp;
 
}

Action()
{
	int i=1;
	int count = 0;
	char getParameter[100];
	char saveParemater[100];
	char *tempString;

	web_set_sockets_option("SSL_VERSION", "2&3");

	web_add_cookie("NID=100=iA_RHhBt6ErEklfwoRrl3hBwgeDsUNjaxnZ5Za6k-fLu5Nmx5QLeIuAaXW4E_B8i9AX2bIlPAAjOWkUpm-82U1ZAu5L-xfXFDSPZNmsnOUD6oEoOtKQBjM46MPc214Fr; DOMAIN=safebrowsing.google.com");

	lr_start_transaction("getCountries");
	
	web_reg_save_param_ex(
		"ParamName=pais",
		"LB=&lt;Name&gt;",
		"RB=&lt;/Name&gt;",
		"Ordinal=all",
		SEARCH_FILTERS,
		LAST);
	
	lr_output_message( "cantidad de paises %s","{pais_1}");

	web_url("GetCountries", 
		"URL=http://www.webservicex.net/country.asmx/GetCountries?", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);
	
	count = atoi(lr_eval_string("{pais_count}"));
	
	for(i;i<=count;i++){
		
		sprintf(getParameter, "{pais_%d}", i);
		sprintf(saveParemater, "pais_%d", i);
		
		tempString = borrarBasura(lr_eval_string(getParameter), getParameter);
		
		lr_save_string(tempString , saveParemater);
		
	}

	lr_end_transaction("getCountries",LR_AUTO);

	lr_start_transaction("getGMTbyCountry");
	
	lr_save_string(lr_eval_string(lr_eval_string("{pais_{ramdom}}")), "pais_final");
	
	web_submit_data("GetGMTbyCountry", 
		"Action=http://www.webservicex.net/country.asmx/GetGMTbyCountry", 
		"Method=POST", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=CountryName", "Value={pais_final}", ENDITEM, 
		LAST);

	lr_end_transaction("getGMTbyCountry",LR_AUTO);

	return 0;
}