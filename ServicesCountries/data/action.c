Action()
{

	web_set_sockets_option("SSL_VERSION", "2&3");

	web_add_cookie("NID=100=iA_RHhBt6ErEklfwoRrl3hBwgeDsUNjaxnZ5Za6k-fLu5Nmx5QLeIuAaXW4E_B8i9AX2bIlPAAjOWkUpm-82U1ZAu5L-xfXFDSPZNmsnOUD6oEoOtKQBjM46MPc214Fr; DOMAIN=safebrowsing.google.com");

	web_custom_request("gethash", 
		"URL=https://safebrowsing.google.com/safebrowsing/gethash?client=googlechrome&appver=57.0.2987.133&pver=3.0&key=AIzaSyBOti4mM-6x9WDnZIjIeyEU21OpBXqWBgw&ext=0", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/octet-stream", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		"EncType=text/plain", 
		"Body=4:4\naicm", 
		EXTRARES, 
		"Url=https://translate.googleapis.com/translate_a/l?client=chrome&hl=es&key=AIzaSyBOti4mM-6x9WDnZIjIeyEU21OpBXqWBgw&alpha=1", "Referer=", ENDITEM, 
		"Url=https://clients4.google.com/chrome-variations/seed?osname=win", "Referer=", ENDITEM, 
		LAST);

	lr_think_time(5);

	web_url("smp_21_", 
		"URL=http://192.168.17.33:7676/smp_21_", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=https://ssl.gstatic.com/safebrowsing/csd/client_model_v5_variation_0.pb", "Referer=", ENDITEM, 
		"Url=https://ssl.gstatic.com/safebrowsing/csd/client_model_v5_ext_variation_0.pb", "Referer=", ENDITEM, 
		LAST);

	web_add_cookie("PHPSESSID=okalg8pjlo0qqq0ho4t2su1eo3; DOMAIN=app.getpostman.com");

	web_add_cookie("AWSELB=E50729191E80E38155F514DEB48F993F393C1568D80BD1226828138C947DDCDA938F83654A235B403E1FE95AE50975FA03AE147EC55226919B86A00EC9079273772BA40D3F; DOMAIN=app.getpostman.com");

	web_url("smp_21__2", 
		"URL=http://192.168.17.33:7676/smp_21_", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=https://app.getpostman.com/api/app_broadcasts?user_id=0&access_token=&count=10&app_version=4.10.7&app_platform=chrome", "Referer=", ENDITEM, 
		LAST);

	web_submit_data("collect", 
		"Action=https://www.google-analytics.com/collect", 
		"Method=POST", 
		"RecContentType=image/gif", 
		"Referer=", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=_v", "Value=ca1", ENDITEM, 
		"Name=ul", "Value=en-US", ENDITEM, 
		"Name=sd", "Value=24-bit", ENDITEM, 
		"Name=v", "Value=1", ENDITEM, 
		"Name=tid", "Value=UA-43979731-6", ENDITEM, 
		"Name=cid", "Value=a4f356ea-bb69-5b0b-f12b-3e6bf00d2d50", ENDITEM, 
		"Name=an", "Value=Postman", ENDITEM, 
		"Name=av", "Value=4.10.7", ENDITEM, 
		"Name=cd", "Value=MainView", ENDITEM, 
		"Name=sr", "Value=1366x768", ENDITEM, 
		"Name=vp", "Value=1226x698", ENDITEM, 
		"Name=t", "Value=appview", ENDITEM, 
		LAST);

	web_submit_data("collect_2", 
		"Action=https://www.google-analytics.com/collect", 
		"Method=POST", 
		"RecContentType=image/gif", 
		"Referer=", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=_v", "Value=ca1", ENDITEM, 
		"Name=ul", "Value=en-US", ENDITEM, 
		"Name=sd", "Value=24-bit", ENDITEM, 
		"Name=v", "Value=1", ENDITEM, 
		"Name=tid", "Value=UA-43979731-6", ENDITEM, 
		"Name=cid", "Value=a4f356ea-bb69-5b0b-f12b-3e6bf00d2d50", ENDITEM, 
		"Name=an", "Value=Postman", ENDITEM, 
		"Name=av", "Value=4.10.7", ENDITEM, 
		"Name=cd", "Value=MainView", ENDITEM, 
		"Name=sr", "Value=1366x768", ENDITEM, 
		"Name=vp", "Value=1226x698", ENDITEM, 
		"Name=t", "Value=timing", ENDITEM, 
		"Name=utc", "Value=performance", ENDITEM, 
		"Name=utv", "Value=pageload", ENDITEM, 
		"Name=utt", "Value=7011", ENDITEM, 
		LAST);

	lr_think_time(32);

	lr_start_transaction("getCountries");

	web_url("GetCountries", 
		"URL=http://www.webservicex.net/country.asmx/GetCountries?", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("getCountries",LR_AUTO);

	web_custom_request("events", 
		"URL=https://analytics.getpostman.com/events", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		"EncType=text/plain", 
		"Body="
		"eyJ0eXBlIjoiZXZlbnRzLWdlbmVyYWwiLCJpbmRleFR5cGUiOiJjbGllbnQtZXZlbnRzIiwiZW52IjoicHJvZHVjdGlvbiIsInByb3BlcnR5VmVyc2lvbiI6IjQuMTAuNyIsInByb3BlcnR5SWQiOiJhNGYzNTZlYS1iYjY5LTViMGItZjEyYi0zZTZiZjAwZDJkNTAiLCJ1c2VySWQiOiIwIiwidGVhbUlkIjoiIiwicHJvcGVydHkiOiJjaHJvbWVfYXBwIiwiY2F0ZWdvcnkiOiJhcHAiLCJ0aW1lc3RhbXAiOiIyMDE3LTA1LTA5VDE4OjUwOjQwLjc4OVoiLCJhY3Rpb24iOiJsb2FkIn0KeyJ0eXBlIjoiZXZlbnRzLWdlbmVyYWwiLCJpbmRleFR5cGUiOiJjbGllbnQtZXZlbnRzIiwiZW52IjoicHJvZHVjdGlvbiIsInByb3BlcnR5VmVyc2lvbiI6IjQuMTAuNyIsInByb3"
		"BlcnR5SWQiOiJhNGYzNTZlYS1iYjY5LTViMGItZjEyYi0zZTZiZjAwZDJkNTAiLCJ1c2VySWQiOiIwIiwidGVhbUlkIjoiIiwicHJvcGVydHkiOiJjaHJvbWVfYXBwIiwiY2F0ZWdvcnkiOiJoaXN0b3J5IiwidGltZXN0YW1wIjoiMjAxNy0wNS0wOVQxODo1MToxMi44MDZaIiwiYWN0aW9uIjoiY3JlYXRlIn0K", 
		LAST);

	lr_think_time(11);

	lr_start_transaction("getGMTbyCountry");

	web_submit_data("GetGMTbyCountry", 
		"Action=http://www.webservicex.net/country.asmx/GetGMTbyCountry", 
		"Method=POST", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=CountryName", "Value=chile", ENDITEM, 
		LAST);

	lr_end_transaction("getGMTbyCountry",LR_AUTO);

	return 0;
}