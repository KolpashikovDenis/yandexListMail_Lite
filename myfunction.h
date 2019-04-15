#ifndef MYFUNCTION_H
#define MYFUNCTION_H

void readAndAnswer(char* _link)
{	
	strcpy(full_link, host);
	strcat(full_link, _link);
	lr_output_message(full_link);
	
	web_add_cookie("i=xE1cFr8ow3XT3zZg4I/8hKJi28VQ4ubY/dCYFDX9WFLH62Un5rOk21/X+MnFr9vuk1jgJGuadRaN/IhCk4wdsbx3Lxw=; DOMAIN=mail.yandex.ru");

	web_add_cookie("yp=1870664044.yrtsi.1555304044#1870664061.udn.cDpwZmxiVGVzdFRlc3Rvdg%3D%3D; DOMAIN=an.yandex.ru");
	
	strcpy(&content[0], "yandexuid=");
	strcat(&content[0], yandexUid);
	web_add_cookie((char*)&content);
	
	strcpy(content, "uniqueuid=");
	strcat(content, uniqueUid);
	web_add_cookie((char*)&content);
	
	web_url("new", 
		full_link,
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://mail.yandex.ru/lite", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		EXTRARES, 
		LAST);
	
	
}

#endif