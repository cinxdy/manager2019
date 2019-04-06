#include "user.h"

int load_file(LOGIN* list[], char* filename){
  #ifdef DEBUG
  printf("DEBUG:: load_file();\n");
  #endif

  int count=0;
  FILE *datafile = fopen(filename, "r");
  while(!feof(datafile)){
    list[count]=(LOGIN*)malloc(sizeof(LOGIN));
    fscanf(datafile,"%s %s",list[count]->id,list[count]->password);
    count++;
  }
  printf("%d records read!\n",count);\
  fclose(datafile);
  return count;
}

char* create_file(){
  
  #ifdef DEBUG
  printf("DEBUG:: create_file();\n");
  #endif

	FILE *datafile = NULL;
	char *filename = (char*) malloc(sizeof(char*)*20);
	printf("Data File Name : ");
	scanf("%s",filename);
	datafile = fopen(filename,"wt");
	fclose(datafile);
	return filename;
}

void join(LOGIN* list[], int count){
  #ifdef DEBUG
  printf("DEBUG:: join()\n");
  #endif

  char id[20], pass[20];
  while(1){
    printf("Enter new user id >> ");
    scanf("%s", id);
    int dup=0;
    for(int i=0;i<count;i++){
      if(strcmp(id, list[i]->id)==0) {
        dup=1; break;
      }
    }
    if(dup==1){
      printf("Already exist!!\n");
    }
    else{
      printf("Enter password >> ");
      scanf("%s", pass);
      list[count] = (LOGIN*)malloc(sizeof(LOGIN));
      strcpy(list[count]->id, id);
      strcpy(list[count]->password, pass);
      printf("New user added!\n");
      break;
    }
  }
}

int login(LOGIN* list[], int count){
  #ifdef DEBUG
  printf("DEBUG:: login();\n");
  #endif

  char id[20], pass[20];
  printf("Enter user id >> ");
  scanf("%s", id);
  int dup=0, found;
  for(int i=0;i<count;i++){
    if(strcmp(id, list[i]->id)==0) {
      dup=1;
      found = i;
      break;
    }
  }
  if(dup!=1){
    printf("No such user!!\n");
    return -1;
  }
  else{
    printf("Enter password >> ");
    scanf("%s", pass);
    if(strcmp(list[found]->password, pass)==0){
      printf("Welcome %s!!\n", id);
      return 1;
    }
    else{
      printf("Password incorrect!!\n");
      return 0;
    }
  }
}

void logout(int* is_login){
  #ifdef DEBUG
  printf("DEBUG:: logout();\n");
  #endif

  *is_login = 0;
  printf("Logout!!\n");
}

void save_file(LOGIN* list[], int count, char* filename){
  #ifdef DEBUG
  printf("DEBUG:: save_file();\n");
  #endif

  FILE *datafile = fopen(filename, "w");
  for(int i=0; i<count; i++){
    fprintf(datafile, "%s %s\n", list[i]->id, list[i]->password);
  }
  printf("%s Saved!\n", filename);
  fclose(datafile);
}

void printList(LOGIN* list[],int count){

  #ifdef DEBUG
  printf("DEBUG:: printList(list,count=%d);\n",count);
  #endif
	for(int i=0;i<count-1;i++){
		printf("%d\t %s\n",i+1, list[i]->id );
	}
}

