#include "myfunction.h"
Action()
{

	lr_start_transaction("OpenYandex");

	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	web_add_auto_header("DNT", 
		"1");

	web_add_auto_header("UA-CPU", 
		"AMD64");	

	web_revert_auto_header("UA-CPU");
	
	// TODO: вытащить csrf_token и т.д.
	
	web_reg_save_param_regexp(
		"ParamName=CSRFToken",
		"RegExp=(?<=data-csrf=\")(.*?)(?=\")",
		SEARCH_FILTERS,
		"Scope=Body",
		"Group=1",
		LAST);
	
	web_reg_save_param_regexp(
		"ParamName=ProcessUuid",
		"RegExp=(?<=process_uuid=)(.*?)(?=&)",
		SEARCH_FILTERS,
		"Scope=Body",
		"Group=1",
		LAST);
	
	web_reg_save_param_regexp(
		"ParamName=YandexUid",
		"RegExp=(?<=yandexuid=)(.*?)(?=;)",
		SEARCH_FILTERS,
		"Group=1",
		LAST);
	
	web_reg_save_param_regexp(
		"ParamName=UniqueUid",
		"RegExp=(?<=uniqueuid=)(.*?)(?=;)",
		SEARCH_FILTERS,
		"Group=1",
		LAST);	

	web_url("lite", 
		"URL=https://mail.yandex.ru/lite", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=https://yastatic.net/passport-frontend/_/EUxceAgVsx2B01NrliHAcXRG9Hs.jpg", "Referer=https://passport.yandex.ru/passport?mode=auth&retpath=http%3A%2F%2Fmail.yandex.ru%2Flite", ENDITEM, 
		"Url=https://yastatic.net/islands/_/g0MeJlAWVRZjlLOLzhOGwwDQzKY.woff", "Referer=https://passport.yandex.ru/passport?mode=auth&retpath=http%3A%2F%2Fmail.yandex.ru%2Flite", ENDITEM, 
		"Url=https://yastatic.net/islands/_/6n8FrCwGXwQ5ZumBk1SCxOl2ec8.woff", "Referer=https://passport.yandex.ru/passport?mode=auth&retpath=http%3A%2F%2Fmail.yandex.ru%2Flite", ENDITEM, 
		"Url=https://yastatic.net/islands/_/7RkupUWVEcepjeZPFv1xCDdQFhc.woff", "Referer=https://passport.yandex.ru/passport?mode=auth&retpath=http%3A%2F%2Fmail.yandex.ru%2Flite", ENDITEM, 
		"Url=https://yastatic.net/nearest.js", "Referer=https://passport.yandex.ru/auth?mode=auth&retpath=http%3A%2F%2Fmail.yandex.ru%2Flite", ENDITEM, 
		"Url=https://yastatic.net/passport-frontend/_/xbpPHCInUPhIYlqVdb7FamxP9EE.png", "Referer=https://passport.yandex.ru/passport?mode=auth&retpath=http%3A%2F%2Fmail.yandex.ru%2Flite", ENDITEM, 
		LAST);
	
	yandexUid = lr_eval_string("{YandexUid}");
	uniqueUid = lr_eval_string("{UniqueUid}");	
	lr_output_message("%s - %s", yandexUid, uniqueUid);	

	lr_end_transaction("OpenYandex",LR_AUTO);

	web_add_header("UA-CPU", 
		"AMD64");

	lr_think_time(4);
	
	lr_start_transaction("LoginYandex");

	web_add_cookie("_ym_wasSynced=%7B%22time%22%3A1555044992777%2C%22params%22%3A%7B%22eu%22%3A0%7D%2C%22bkParams%22%3A%7B%7D%7D; DOMAIN=passport.yandex.ru");

	web_add_cookie("_ym_uid=1555044993489235821; DOMAIN=passport.yandex.ru");

	web_add_cookie("_ym_d=1555044993; DOMAIN=passport.yandex.ru");

	web_add_cookie("mda=0; DOMAIN=passport.yandex.ru");

	web_add_auto_header("Origin", 
		"https://passport.yandex.ru");

	web_submit_data("1", 
		"Action=https://mc.yandex.ru/watch/3/1?wmode=7&page-ref=https%3A%2F%2Fpassport.yandex.ru%2Fauth%3Fmode%3Dauth%26retpath%3Dhttp%253A%252F%252Fmail.yandex.ru%252Flite&charset=utf-8&ut=noindex&browser-info=ti%3A10%3Afu%3A2%3Av%3A1513%3Arqnl%3A1%3Ast%3A1555044993%3Au%3A", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://passport.yandex.ru/auth?mode=auth&retpath=http%3A%2F%2Fmail.yandex.ru%2Flite", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		EXTRARES, 
		"Url=https://passport.yandex.ru/monitoring?app=passport&page=auth.v2&event=load&tm.navigationStart=1555044963251&tm.unloadEventStart=0&tm.unloadEventEnd=0&tm.redirectStart=0&tm.redirectEnd=0&tm.fetchStart=1555044963251&tm.domainLookupStart=1555044963251&tm.domainLookupEnd=1555044963251&tm.connectStart=1555044963251&tm.connectEnd=1555044963251&tm.requestStart=1555044963251&tm.responseStart=1555044963251&tm.responseEnd=1555044963254&tm.domLoading=1555044963251&tm.domInteractive=1555044978092&"
		"tm.domContentLoadedEventStart=1555044978243&tm.domContentLoadedEventEnd=1555044978364&tm.domComplete=1555044992759&tm.loadEventStart=1555044992759&tm.loadEventEnd=1555044992761&nav.type=0&nav.redirectCount=0", "Referer=https://passport.yandex.ru/auth?mode=auth&retpath=http%3A%2F%2Fmail.yandex.ru%2Flite", ENDITEM, 
		LAST);

	web_add_cookie("_ym_wasSynced=%7B%22time%22%3A1555044992777%2C%22params%22%3A%7B%22eu%22%3A0%7D%2C%22bkParams%22%3A%7B%7D%7D; DOMAIN=mc.yandex.ru");

	web_add_cookie("_ym_uid=1555044993489235821; DOMAIN=mc.yandex.ru");

	web_add_cookie("_ym_d=1555044993; DOMAIN=mc.yandex.ru");

	web_add_cookie("mda=0; DOMAIN=mc.yandex.ru");

	web_revert_auto_header("Origin");
	
	web_submit_data("784657", 
		"Action=https://mc.yandex.ru/watch/784657?wmode=7&page-url=https%3A%2F%2Fpassport.yandex.ru%2Fauth%3Fmode%3Dauth%26retpath%3Dhttp%253A%252F%252Fmail.yandex.ru%252Flite&charset=utf-8&ut=noindex&exp=PLPv0K295hvn67OKLpgvS5QpZtnHtpLAbfzP7ywFtMHXyJ3PPFvLCHVzFhstc_GWswuiZCO5mqbEAZvNQeNglg6vs7LX7Dp2inQ8pTfoV_3u-baBJ2e1x01FrFCeVi14GNH7jebkB5g&browser-info="
		"ti%3A10%3Aj%3A1%3Ans%3A1555044963251%3As%3A1600x900x24%3Ask%3A1%3Afpr%3A216613626101%3Acn%3A1%3Aw%3A1056x523%3Az%3A240%3Ai%3A20190412085632%3Aet%3A1555044993%3Aen%3Autf-8%3Ac%3A1%3Ala%3Aru-ru%3Awh%3A1%3Apv%3A1%3Als%3A800555124832%3Arqn%3A4%3Arn%3A833549219%3Ahid%3A454492117%3Ads%3A%2C%2C%2C%2C%2C%2C%2C%2C%2C29508%2C29508%2C2%2C%3Awn%3A49688%3Ahl%3A1%3Agdpr%3A8%3Av%3A1513%3Arqnl%3A1%3Ast%3A1555044993%3Au%3A1555044993489235821%3At%3A%D0%90%D0%B2%D1%82%D0%BE%D1%80%D0%B8%D0%B7%D0%B0%D1%86%D0%B8%D1%8F", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://passport.yandex.ru/auth?mode=auth&retpath=http%3A%2F%2Fmail.yandex.ru%2Flite", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		EXTRARES, 
		"Url=../metrika/advert.gif", "Referer=https://passport.yandex.ru/auth?mode=auth&retpath=http%3A%2F%2Fmail.yandex.ru%2Flite", ENDITEM, 
		LAST);

	web_add_auto_header("Origin", 
		"https://passport.yandex.ru");

	web_custom_request("1_2", 
		"URL=https://mc.yandex.ru/watch/784657/1?page-url=https%3A%2F%2Fpassport.yandex.ru%2Fauth%3Fmode%3Dauth%26retpath%3Dhttp%253A%252F%252Fmail.yandex.ru%252Flite&charset=utf-8&ut=noindex&browser-info="
		"ti%3A7%3Aj%3A1%3Ans%3A1555044963251%3As%3A1600x900x24%3Ask%3A1%3Afpr%3A216613626101%3Acn%3A1%3Az%3A240%3Ai%3A20190412085632%3Aet%3A1555044993%3Aen%3Autf-8%3Ac%3A1%3Ala%3Aru-ru%3Aar%3A1%3Apa%3A1%3Als%3A800555124832%3Arqn%3A1%3Arn%3A665130217%3Ahid%3A454492117%3Ads%3A0%2C0%2C0%2C3%2C0%2C0%2C0%2C14841%2C121%2C%2C%2C%2C14992%3Av%3A1513%3Arqnl%3A1%3Ast%3A1555044993%3Au%3A1555044993489235821", 
		"Method=POST", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=https://passport.yandex.ru/auth?mode=auth&retpath=http%3A%2F%2Fmail.yandex.ru%2Flite", 
		"Snapshot=t8.inf", 
		"Body=site-info=%7B%22%D0%9D%D0%BE%D0%B2%D1%8B%D0%B9%20%D0%B4%D0%BE%D0%BC%D0%B8%D0%BA%20V3%22%3A%22%D0%9F%D0%BE%D0%BA%D0%B0%D0%B7%20%D0%B2%D0%B2%D0%BE%D0%B4%D0%B0%20%D0%BB%D0%BE%D0%B3%D0%B8%D0%BD%D0%B0%22%7D", 
		LAST);

	web_custom_request("1_3", 
		"URL=https://mc.yandex.ru/watch/784657/1?page-url=https%3A%2F%2Fpassport.yandex.ru%2Fauth%3Fmode%3Dauth%26retpath%3Dhttp%253A%252F%252Fmail.yandex.ru%252Flite&charset=utf-8&ut=noindex&browser-info="
		"ti%3A7%3Aj%3A1%3Ans%3A1555044963251%3As%3A1600x900x24%3Ask%3A1%3Afpr%3A216613626101%3Acn%3A1%3Az%3A240%3Ai%3A20190412085632%3Aet%3A1555044993%3Aen%3Autf-8%3Ac%3A1%3Ala%3Aru-ru%3Aar%3A1%3Apa%3A1%3Als%3A800555124832%3Arqn%3A2%3Arn%3A471991162%3Ahid%3A454492117%3Ads%3A%2C%2C%2C%2C%2C%2C%2C%2C%2C%2C%2C%2C%3Av%3A1513%3Arqnl%3A1%3Ast%3A1555044993%3Au%3A1555044993489235821", 
		"Method=POST", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=https://passport.yandex.ru/auth?mode=auth&retpath=http%3A%2F%2Fmail.yandex.ru%2Flite", 
		"Snapshot=t9.inf", 
		"Body=site-info=%7B%22%D0%9D%D0%BE%D0%B2%D1%8B%D0%B9%20%D0%B4%D0%BE%D0%BC%D0%B8%D0%BA%20V3%22%3A%22%D0%BF%D0%BE%D0%BA%D0%B0%D0%B7%20%D1%81%D1%82%D1%80%D0%B0%D0%BD%D0%B8%D1%86%D1%8B%22%7D", 
		LAST);

	web_add_cookie("_ym_visorc_784657=b; DOMAIN=mc.yandex.ru");

	web_add_cookie("_ym_isad=2; DOMAIN=mc.yandex.ru");

	web_submit_data("1_4", 
		"Action=https://mc.yandex.ru/watch/784657/1?page-ref=https%3A%2F%2Fpassport.yandex.ru%2Fauth%3Fmode%3Dauth%26retpath%3Dhttp%253A%252F%252Fmail.yandex.ru%252Flite&page-url=goal%3A%2F%2Fpassport.yandex.ru%2F2step_domik_show_login_form&charset=utf-8&ut=noindex&browser-info="
		"ti%3A7%3Aj%3A1%3Ans%3A1555044963251%3As%3A1600x900x24%3Ask%3A1%3Afpr%3A216613626101%3Acn%3A1%3Aw%3A1056x523%3Az%3A240%3Ai%3A20190412085632%3Aet%3A1555044993%3Aen%3Autf-8%3Ac%3A1%3Ala%3Aru-ru%3Aar%3A1%3Als%3A800555124832%3Arqn%3A3%3Arn%3A595675586%3Ahid%3A454492117%3Ads%3A%2C%2C%2C%2C%2C%2C%2C%2C%2C%2C%2C%2C%3Afu%3A3%3Av%3A1513%3Arqnl%3A1%3Ast%3A1555044993%3Au%3A1555044993489235821%3At%3A%D0%90%D0%B2%D1%82%D0%BE%D1%80%D0%B8%D0%B7%D0%B0%D1%86%D0%B8%D1%8F", 
		"Method=POST", 
		"RecContentType=image/gif", 
		"Referer=https://passport.yandex.ru/auth?mode=auth&retpath=http%3A%2F%2Fmail.yandex.ru%2Flite", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		EXTRARES, 
		"Url=/clmap/784657?page-url=https%3A%2F%2Fpassport.yandex.ru%2Fauth%3Fmode%3Dauth%26retpath%3Dhttp%253A%252F%252Fmail.yandex.ru%252Flite&pointer-click=rn%3A270250972%3Ax%3A-89128%3Ay%3A-793247%3At%3A46%3Ap%3A%3FA2FAAAA1A2AA1AA&browser-info=ti%3A4%3Arqnl%3A1%3Ast%3A1555044997%3Au%3A1555044993489235821", "Referer=https://passport.yandex.ru/auth?mode=auth&retpath=http%3A%2F%2Fmail.yandex.ru%2Flite", ENDITEM, 
		LAST);

	/*Possible OAUTH authorization was detected. It is recommended to correlate the authorization parameters.*/

	web_add_cookie("_ym_visorc_784657=b; DOMAIN=passport.yandex.ru");

	web_add_cookie("_ym_isad=2; DOMAIN=passport.yandex.ru");

	web_revert_auto_header("Origin");

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_reg_save_param_regexp(
		"ParamName=TrackId",
		"RegExp=(?<=track_id\":\")(.*?)(?=\")",
		SEARCH_FILTERS,
		"Scope=Body",
		"Group=1",
		LAST);
	
	web_submit_data("start", 
		"Action=https://passport.yandex.ru/registration-validations/auth/multi_step/start", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://passport.yandex.ru/auth?mode=auth&retpath=http%3A%2F%2Fmail.yandex.ru%2Flite", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=csrf_token", "Value={CSRFToken}", ENDITEM, 
		"Name=login", "Value=pflbtesttestov", ENDITEM, 
		"Name=process_uuid", "Value={ProcessUuid}", ENDITEM, 
		LAST);

	web_add_auto_header("Origin", 
		"https://passport.yandex.ru");

	web_submit_data("1_5", 
		"Action=https://mc.yandex.ru/watch/784657/1?page-ref=https%3A%2F%2Fpassport.yandex.ru%2Fauth%2Fwelcome%3Fmode%3Dauth%26retpath%3Dhttp%253A%252F%252Fmail.yandex.ru%252Flite&page-url=goal%3A%2F%2Fpassport.yandex.ru%2F2step_domik_show_pass_form&charset=utf-8&ut=noindex&browser-info="
		"ti%3A7%3Aj%3A1%3Ans%3A1555044963251%3As%3A1600x900x24%3Ask%3A1%3Aadb%3A2%3Afpr%3A216613626101%3Acn%3A1%3Aw%3A1056x523%3Az%3A240%3Ai%3A20190412085637%3Aet%3A1555044998%3Aen%3Autf-8%3Ac%3A1%3Ala%3Aru-ru%3Awh%3A1%3Aar%3A1%3Als%3A800555124832%3Arqn%3A7%3Arn%3A12514874%3Ahid%3A454492117%3Ads%3A%2C%2C%2C%2C%2C%2C%2C%2C%2C%2C%2C%2C%3Agdpr%3A8%3Afu%3A3%3Av%3A1513%3Arqnl%3A1%3Ast%3A1555044998%3Au%3A1555044993489235821%3At%3A%D0%90%D0%B2%D1%82%D0%BE%D1%80%D0%B8%D0%B7%D0%B0%D1%86%D0%B8%D1%8F", 
		"Method=POST", 
		"RecContentType=image/gif", 
		"Referer=https://passport.yandex.ru/auth/welcome?mode=auth&retpath=http%3A%2F%2Fmail.yandex.ru%2Flite", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		EXTRARES, 
		"Url=/clmap/784657?page-url=https%3A%2F%2Fpassport.yandex.ru%2Fauth%2Fwelcome%3Fmode%3Dauth%26retpath%3Dhttp%253A%252F%252Fmail.yandex.ru%252Flite&pointer-click=rn%3A717706469%3Ax%3A-89128%3Ay%3A-820553%3At%3A90%3Ap%3A%3FA1FAAA1A2AA1AA&browser-info=ti%3A4%3Arqnl%3A1%3Ast%3A1555045002%3Au%3A1555044993489235821", "Referer=https://passport.yandex.ru/auth/welcome?mode=auth&retpath=http%3A%2F%2Fmail.yandex.ru%2Flite", ENDITEM, 
		LAST);

	web_custom_request("1_6", 
		"URL=https://mc.yandex.ru/watch/784657/1?page-url=https%3A%2F%2Fpassport.yandex.ru%2Fauth%3Fmode%3Dauth%26retpath%3Dhttp%253A%252F%252Fmail.yandex.ru%252Flite&charset=utf-8&ut=noindex&browser-info="
		"ti%3A7%3Aj%3A1%3Ans%3A1555044963251%3As%3A1600x900x24%3Ask%3A1%3Aadb%3A2%3Afpr%3A216613626101%3Acn%3A1%3Az%3A240%3Ai%3A20190412085637%3Aet%3A1555044998%3Aen%3Autf-8%3Ac%3A1%3Ala%3Aru-ru%3Awh%3A1%3Aar%3A1%3Apa%3A1%3Als%3A800555124832%3Arqn%3A5%3Arn%3A114575641%3Ahid%3A454492117%3Ads%3A%2C%2C%2C%2C%2C%2C%2C%2C%2C%2C%2C%2C%3Agdpr%3A8%3Av%3A1513%3Arqnl%3A1%3Ast%3A1555044998%3Au%3A1555044993489235821", 
		"Method=POST", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=https://passport.yandex.ru/auth/welcome?mode=auth&retpath=http%3A%2F%2Fmail.yandex.ru%2Flite", 
		"Snapshot=t13.inf", 
		"Body=site-info=%7B%22%D0%9D%D0%BE%D0%B2%D1%8B%D0%B9%20%D0%B4%D0%BE%D0%BC%D0%B8%D0%BA%20V3%22%3A%7B%22%D0%9F%D0%BE%D0%BA%D0%B0%D0%B7%20%D0%B2%D0%B2%D0%BE%D0%B4%D0%B0%20%D0%BB%D0%BE%D0%B3%D0%B8%D0%BD%D0%B0%22%3A%7B%22%D0%9E%D1%82%D0%BF%D1%80%D0%B0%D0%B2%D0%BA%D0%B0%20%D1%84%D0%BE%D1%80%D0%BC%D1%8B%20%D0%BB%D0%BE%D0%B3%D0%B8%D0%BD%D0%B0%22%3A%22%D0%A3%D1%81%D0%BF%D0%B5%D1%88%D0%BD%D1%8B%D0%B9%20%D0%B2%D0%B2%D0%BE%D0%B4%22%7D%7D%7D", 
		LAST);

	web_custom_request("1_7", 
		"URL=https://mc.yandex.ru/watch/784657/1?page-url=https%3A%2F%2Fpassport.yandex.ru%2Fauth%2Fwelcome%3Fmode%3Dauth%26retpath%3Dhttp%253A%252F%252Fmail.yandex.ru%252Flite&charset=utf-8&ut=noindex&browser-info="
		"ti%3A7%3Aj%3A1%3Ans%3A1555044963251%3As%3A1600x900x24%3Ask%3A1%3Aadb%3A2%3Afpr%3A216613626101%3Acn%3A1%3Az%3A240%3Ai%3A20190412085637%3Aet%3A1555044998%3Aen%3Autf-8%3Ac%3A1%3Ala%3Aru-ru%3Awh%3A1%3Aar%3A1%3Apa%3A1%3Als%3A800555124832%3Arqn%3A6%3Arn%3A528513008%3Ahid%3A454492117%3Ads%3A%2C%2C%2C%2C%2C%2C%2C%2C%2C%2C%2C%2C%3Agdpr%3A8%3Av%3A1513%3Arqnl%3A1%3Ast%3A1555044998%3Au%3A1555044993489235821", 
		"Method=POST", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=https://passport.yandex.ru/auth/welcome?mode=auth&retpath=http%3A%2F%2Fmail.yandex.ru%2Flite", 
		"Snapshot=t14.inf", 
		"Body=site-info=%7B%22%D0%9D%D0%BE%D0%B2%D1%8B%D0%B9%20%D0%B4%D0%BE%D0%BC%D0%B8%D0%BA%20V3%22%3A%22%D0%9F%D0%BE%D0%BA%D0%B0%D0%B7%20%D1%84%D0%BE%D1%80%D0%BC%D1%8B%20%D0%B2%D0%B2%D0%BE%D0%B4%20%D0%BF%D0%B0%D1%80%D0%BE%D0%BB%D1%8F%22%7D", 
		LAST);

	web_revert_auto_header("Origin");

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_submit_data("commit_password", 
		"Action=https://passport.yandex.ru/registration-validations/auth/multi_step/commit_password", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://passport.yandex.ru/auth/welcome?mode=auth&retpath=http%3A%2F%2Fmail.yandex.ru%2Flite", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=csrf_token", "Value={CSRFToken}", ENDITEM, 
		"Name=track_id", "Value={TrackId}", ENDITEM, 
		"Name=password", "Value=ltybcrf78", ENDITEM, 
		LAST);

	web_add_auto_header("Origin", 
		"https://passport.yandex.ru");

	web_submit_data("1_8", 
		"Action=https://mc.yandex.ru/watch/784657/1?page-ref=https%3A%2F%2Fpassport.yandex.ru%2Fauth%2Fwelcome%3Fmode%3Dauth%26retpath%3Dhttp%253A%252F%252Fmail.yandex.ru%252Flite&page-url=goal%3A%2F%2Fpassport.yandex.ru%2Fone_domik_auth_sucess&charset=utf-8&ut=noindex&browser-info="
		"ti%3A7%3Aj%3A1%3Ans%3A1555044963251%3As%3A1600x900x24%3Ask%3A1%3Aadb%3A2%3Afpr%3A216613626101%3Acn%3A1%3Aw%3A1056x523%3Az%3A240%3Ai%3A20190412085642%3Aet%3A1555045002%3Aen%3Autf-8%3Ac%3A1%3Ala%3Aru-ru%3Awh%3A1%3Aar%3A1%3Als%3A800555124832%3Arqn%3A8%3Arn%3A246782495%3Ahid%3A454492117%3Ads%3A%2C%2C%2C%2C%2C%2C%2C%2C%2C%2C%2C%2C%3Agdpr%3A8%3Afu%3A3%3Av%3A1513%3Arqnl%3A1%3Ast%3A1555045002%3Au%3A1555044993489235821%3At%3A%D0%90%D0%B2%D1%82%D0%BE%D1%80%D0%B8%D0%B7%D0%B0%D1%86%D0%B8%D1%8F", 
		"Method=POST", 
		"RecContentType=image/gif", 
		"Referer=https://passport.yandex.ru/auth/welcome?mode=auth&retpath=http%3A%2F%2Fmail.yandex.ru%2Flite", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		LAST);

	web_custom_request("1_9", 
		"URL=https://mc.yandex.ru/watch/784657/1?page-url=https%3A%2F%2Fpassport.yandex.ru%2Fauth%2Fwelcome%3Fmode%3Dauth%26retpath%3Dhttp%253A%252F%252Fmail.yandex.ru%252Flite&charset=utf-8&ut=noindex&browser-info="
		"ti%3A7%3Aj%3A1%3Ans%3A1555044963251%3As%3A1600x900x24%3Ask%3A1%3Aadb%3A2%3Afpr%3A216613626101%3Acn%3A1%3Az%3A240%3Ai%3A20190412085642%3Aet%3A1555045002%3Aen%3Autf-8%3Ac%3A1%3Ala%3Aru-ru%3Awh%3A1%3Aar%3A1%3Apa%3A1%3Als%3A800555124832%3Arqn%3A9%3Arn%3A383870965%3Ahid%3A454492117%3Ads%3A%2C%2C%2C%2C%2C%2C%2C%2C%2C%2C%2C%2C%3Agdpr%3A8%3Av%3A1513%3Arqnl%3A1%3Ast%3A1555045002%3Au%3A1555044993489235821", 
		"Method=POST", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=https://passport.yandex.ru/auth/welcome?mode=auth&retpath=http%3A%2F%2Fmail.yandex.ru%2Flite", 
		"Snapshot=t17.inf", 
		"Body=site-info=%7B%22%D0%9D%D0%BE%D0%B2%D1%8B%D0%B9%20%D0%B4%D0%BE%D0%BC%D0%B8%D0%BA%20V3%22%3A%7B%22%D0%9F%D0%BE%D0%BA%D0%B0%D0%B7%20%D1%84%D0%BE%D1%80%D0%BC%D1%8B%20%D0%B2%D0%B2%D0%BE%D0%B4%20%D0%BF%D0%B0%D1%80%D0%BE%D0%BB%D1%8F%22%3A%7B%22%D0%9E%D1%82%D0%BF%D1%80%D0%B0%D0%B2%D0%BA%D0%B0%20%D1%84%D0%BE%D1%80%D0%BC%D1%8B%22%3A%22%D0%A3%D1%81%D0%BF%D0%B5%D1%88%D0%BD%D1%8B%D0%B9%20%D0%B2%D0%B2%D0%BE%D0%B4%22%7D%7D%7D", 
		LAST);

	web_add_cookie("_ym_wasSynced=%7B%22time%22%3A1555044992777%2C%22params%22%3A%7B%22eu%22%3A0%7D%2C%22bkParams%22%3A%7B%7D%7D; DOMAIN=mail.yandex.ru");

	web_add_cookie("_ym_uid=1555044993489235821; DOMAIN=mail.yandex.ru");

	web_add_cookie("_ym_d=1555044993; DOMAIN=mail.yandex.ru");

	web_add_cookie("mda=0; DOMAIN=mail.yandex.ru");

	web_add_cookie("_ym_visorc_784657=b; DOMAIN=mail.yandex.ru");

	web_add_cookie("_ym_isad=2; DOMAIN=mail.yandex.ru");

	web_revert_auto_header("Origin");
	
	// TODO: Здесь есть список входящих
	
	web_set_max_html_param_len("65536");
	
	web_reg_save_param_regexp(
		"ParamName=rLink",
		"RegExp=(?<=b-messages__from\\\" href=\\\")(.*?)(?=\\\")",
		"Ordinal=All",
		SEARCH_FILTERS,
		"Scope=Body",
		"Group=1",
		LAST);
	
	web_reg_save_param_regexp(
		"ParamName=rSubject",
		"RegExp=(?<=b-messages__subject\\\"><span>)(.*?)(?=<\\/)",
		"Ordinal=All",
		SEARCH_FILTERS,
		"Scope=Body",
		"Group=1",
		LAST);
		
	web_url("Inbox", 
		"URL=https://mail.yandex.ru/lite", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=https://yastatic.net/mail/lite/_/McavqyOT-yCT4x0wvdbDCIxIphg.png", ENDITEM, 
		"Url=https://yastatic.net/mail/lite/_/1OYsyKle3nTsnm7Dpg26_0S_iyg.png", ENDITEM, 
		"Url=https://yastatic.net/lego/_/UlfClH7m6Sj10jLQ5KxM5cSk5cc.png", ENDITEM, 
		"Url=https://mc.yandex.ru/metrika/watch.js", ENDITEM, 
		LAST);

	lr_end_transaction("LoginYandex",LR_AUTO);
	
	lr_start_transaction("ReadMessages");
	
	links_count = lr_paramarr_len("rLink");	
	
	/*for(n = 1; n <= links_count; n++){
		link = lr_paramarr_idx("rLink", n);
		subject = lr_paramarr_idx("rSubject", n);
		
		if( (strstr(link, "new")!=NULL)&&(strcmp(subject, "Test 1")==0) ){
			// TODO: тут входим в письмо и читаем отправителя и отвечаем ему.
			readAndAnswer(link);
		}
	}*/
	//readAndAnswer(lr_paramarr_idx("rLink", 1));
	web_add_cookie("i=xE1cFr8ow3XT3zZg4I/8hKJi28VQ4ubY/dCYFDX9WFLH62Un5rOk21/X+MnFr9vuk1jgJGuadRaN/IhCk4wdsbx3Lxw=; DOMAIN=mail.yandex.ru");
	web_add_cookie("yp=1870664044.yrtsi.1555304044#1870664061.udn.cDpwZmxiVGVzdFRlc3Rvdg%3D%3D; DOMAIN=an.yandex.ru");
	web_add_cookie("_skin=lite; DOMAIN=mail.yandex.ru");
	web_add_cookie("yandexuid={YandexUid}; DOMAIN=mail.yandex.ru");
	web_add_cookie("uniqueuid={UniqueUid}; DOMAIN=mail.yandex.ru");
	web_add_cookie("_ym_wasSynced=%7B%22time%22%3A1555044992777%2C%22params%22%3A%7B%22eu%22%3A0%7D%2C%22bkParams%22%3A%7B%7D%7D; DOMAIN=mail.yandex.ru");
	web_add_cookie("_ym_uid=1555044993489235821; DOMAIN=mail.yandex.ru");
	web_add_cookie("_ym_d=1555044993; DOMAIN=mail.yandex.ru");
	web_add_cookie("mda=0; DOMAIN=mail.yandex.ru");
	web_add_cookie("_ym_visorc_784657=b; DOMAIN=mail.yandex.ru");
	web_add_cookie("_ym_isad=2; DOMAIN=mail.yandex.ru");
	web_add_cookie("yandex_login=pflbTestTestov; DOMAIN=mail.yandex.ru");
	link = lr_paramarr_idx("rLink",1);

	sprintf(full_link, "URL=%s%s", host, link);
//	lr_output_message(full_link);
	
	/*web_reg_save_param_regexp(
		"ParamName=MailTo",
		"RegExp=(?<=\\&lt;mail@)(.*?)(?=\\&gt)",
		SEARCH_FILTERS,
		"Group=1",
		LAST);*/
		
	web_url("new", 
	    full_link,
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://mail.yandex.ru/lite", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		EXTRARES,
		"Url=https://an.yandex.ru/meta/92550?grab=dNCS0YXQvtC00Y_RidC40LUgKDMg0L3QvtCy0YvRhSDQv9C40YHRjNC80LApIOKAlCDQr9C90LTQtdC60YEu0J_QvtGH0YLQsAo%3D&target-ref=https%3A%2F%2Fmail.yandex.ru%2Flite%2Fmessage%2F168603511049682980%2Fnew&page-ref=https%3A%2F%2Fmail.yandex.ru%2Flite&charset=utf-8&duid=MTU1NTMwNDA0NDc4OTYxODQ1OA%3D%3D&imp-id=14&enable-flat-highlight=1&test-tag=533263139471361&ad-session-id=3541831555304078763&target-id=80107132&pcode-version=8138&flash-ver=0&available-width=817&"
		"available-height=22&partner-stat-id=14&uid=861056795&callback=Ya%5B6511594976318%5D", ENDITEM, 
		"Url=https://www.tns-counter.ru/V13b****yandex_ru/ru/UTF-8/tmsec=yandex_mail/710343857", ENDITEM, 
		"Url=https://an.yandex.ru/rtbcount/1LhjSade01K100000000U9nJ33nKplVlpr8EG_k6AJBSaYUaBFlujiGm084dJ2IqqISt9BOjav4XbH4edcdVy42F5oXUoWVarLu54gsC878g8uC0Wy1CnZDj362maD6Y2C9Q2MVjPLnuKuZXA9X_bH5at5r61X46XhbC8FPI9XqWjPRf5v2zaIamR6qho6bdcVu3mLKca7Mlc0Johdt8jszWOD1tKotkQcDb-Cl41N82CokGx6LM13c46MJON6PcaDNCJ12R6JOohxRLtiCXgsvuaXdcwwjWbNV1v4zc1oT-i4e01Kv4TW00?test-tag=533263139471362&format-type=11&actual-format=37&rnd=5298132398572&renderWidth=837&renderHeight=42", ENDITEM, 
		"Url=https://mc.yandex.ru/clmap/16082914?page-url=https%3A%2F%2Fmail.yandex.ru%2Flite%2Fmessage%2F168603511049682980%2Fnew&pointer-click=rn%3A252369833%3Ax%3A33881%3Ay%3A28159%3At%3A178%3Ap%3A%5EA1AFA1A1A1A1A&browser-info=ti%3A4%3Arqnl%3A1%3Ast%3A1555304097%3Au%3A1555304044789618458", ENDITEM, 
		"Url=https://mc.yandex.ru/clmap/16082914?page-url=https%3A%2F%2Fmail.yandex.ru%2Flite%2Fmessage%2F168603511049682980%2Fnew&pointer-click=rn%3A115808936%3Ax%3A34183%3Ay%3A29866%3At%3A239%3Ap%3A%5EA1AFA1A1A1A1A&browser-info=ti%3A4%3Arqnl%3A1%3Ast%3A1555304103%3Au%3A1555304044789618458", ENDITEM, 
		"Url=https://mc.yandex.ru/clmap/16082914?page-url=https%3A%2F%2Fmail.yandex.ru%2Flite%2Fmessage%2F168603511049682980%2Fnew&pointer-click=rn%3A1021318382%3Ax%3A42938%3Ay%3A37497%3At%3A317%3Ap%3APAA1AFA1A1A1A1A&browser-info=ti%3A4%3Arqnl%3A1%3Ast%3A1555304111%3Au%3A1555304044789618458", ENDITEM,
		LAST);	
	
	lr_output_message(full_link);
	
	lr_end_transaction("ReadMessages", LR_AUTO);
	
	return 0;
}