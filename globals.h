#ifndef _GLOBALS_H 
#define _GLOBALS_H

//--------------------------------------------------------------------
// Include Files
#include "lrun.h"
#include "web_api.h"
#include "lrw_custom_body.h"


//--------------------------------------------------------------------
// Global Variables
char host[]="https://mail.yandex.ru";
char content[512];
char *yandexUid;
char *uniqueUid;
char st[256];

int n;				// Счетчик
int links_count;	// количество ссылок. И тем тоже
char *link;
char *subject;
char full_link[512];
int tmpInt;

int cookie_count;
char *cookie_name;

#endif // _GLOBALS_H
