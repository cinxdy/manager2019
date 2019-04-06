#include "menu.h"

#ifdef DEBUG
#define Dprintf(f) printf("DEBUG :: "); f;
#else
#define Dprintf(f) ;
#endif

int ask_menu(int is_login){
// 파라미터 : 로그인여부 (0 No, 1Yes)
// 리턴값 : 선택한 메뉴번호
// 메뉴번호 : 1. Sign up 2. Log in 3. Log out 0. Exit
  Dprintf(printf("ask_menu();\n"););
  
  int menu;

  #ifdef SHELL
  char prompt[20];
  int ox=0;
  

  do{
    if(is_login!=1) printf(">");
    else printf("#");
    
    ox = 0;
    scanf("%s",prompt);
    if(!strcmp(prompt,"join") || !strcmp(prompt,"logout")) menu = 1;
    else if(!strcmp(prompt,"login")) menu = 2;
    else if(!strcmp(prompt,"print")) menu = 3;
    else if(!strcmp(prompt,"exit")) menu = 0;
    else {
      printf("ERROR!\n"); 
      ox = 1;
    }
  } while(ox == 1);
  
  #else
  if(is_login!=1)
    printf("Choose menu : 1. Sign up 2. Log in 3. Print List 0. Exit >> ");
  else
    printf("Choose menu : 1. Log out 0. Exit >> ");
  scanf("%d", &menu);
  #endif

  return menu;
  
}
