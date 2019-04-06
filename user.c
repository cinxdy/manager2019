#include "user.h"

#ifdef DEBUG
#define Dprintf(f) printf("DEBUG :: "); f;
#else
#define Dprintf(f) ;
#endif

int load_file(LOGIN* list[], char* filename){
  Dprintf(printf("load_file();\n"););
  char id[20],pass[20];

  int count=0;
  FILE *datafile = fopen(filename, "r");

  while(!feof(datafile)){
    fscanf(datafile,"%s %s\n",id,pass);
    Dprintf(printf("id = %s pass = %s\n",id,pass););

    if(strlen(id)!=0 && strlen(pass)!=0){
      list[count]=(LOGIN*)malloc(sizeof(LOGIN));
      strcpy(list[count]->id,id);
      strcpy(list[count]->password,pass);
      count++;
    }
  }

  printf("%d records read!\n",count);\
  fclose(datafile);

  return count;
}

char* create_file(){  
  Dprintf(printf("create_file();\n"););

	FILE *datafile = NULL;
	char *filename = (char*) malloc(sizeof(char*)*20);

	printf("Data File Name : ");
	scanf("%s",filename);
	datafile = fopen(filename,"wt");
	fclose(datafile);
	return filename;
}

void join(LOGIN* list[], int count){
  Dprintf(printf("join()\n"););
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
  Dprintf(printf("login();\n"););

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
  Dprintf(printf("logout();\n"););

  *is_login = 0;
  printf("Logout!!\n");
}

void save_file(LOGIN* list[], int count, char* filename){
  Dprintf(printf("save_file();\n"););
  FILE *datafile = fopen(filename, "w");

  for(int i=0; i<count; i++){
    fprintf(datafile, "%s %s\n", list[i]->id, list[i]->password);
  }
  printf("%s Saved!\n", filename);
  fclose(datafile);
}

void printList(LOGIN* list[],int count){
  Dprintf(printf("printList(list,count=%d);\n",count););

	for(int i=0;i<count;i++){
		printf("%d\t %s\n",i+1, list[i]->id);
	}
}

