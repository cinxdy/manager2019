#include "menu.h"

int ask_menu(int is_login){
// 파라미터 : 로그인여부 (0 No, 1Yes)
// 리턴값 : 선택한 메뉴번호
// 메뉴번호 : 1. Sign up 2. Log in 3. Log out 0. Exit
  
  #ifdef DEBUG
  printf("DEBUG:: ask_menu();\n");
  #endif

  int menu;
  if(is_login!=1)
    printf("Choose menu : 1. Sign up 2. Log in 3. Print List 0. Exit >> ");
  else
    printf("Choose menu : 1. Log out 0. Exit >> ");
  scanf("%d", &menu);
  return menu;
}
