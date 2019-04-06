#include "user.h"

#ifdef DEBUG
#define Dprintf(f) printf("DEBUG :: "); f;
#else
#define Dprintf(f) ;
#endif

int load_file(LOGIN* list[], char* filename){
  Dprintf(printf("load_file(list,filename = %s)\n",filename););

  int count=0;
  FILE *datafile = fopen(filename, "r");

  while(1){
    list[count]=(LOGIN*)malloc(sizeof(LOGIN));
    fscanf(datafile,"%s %s",list[count]->id,list[count]->password);
    if(feof(datafile)) break;
    Dprintf(printf("id = %s pass = %s\n",list[count]->id,list[count]->password););
    count++;
  }

  printf("%d records read!\n",count);\
  fclose(datafile);

  return count;
}

char* create_file(){  
  Dprintf(printf("create_file()\n"););
	FILE *datafile = NULL;
  char* filename = NULL;

  //get filename
  filename = (char*) malloc(sizeof(char*)*30);
	printf("Data File Name : ");
	scanf("%s",filename);

  //make file
	datafile = fopen(filename,"w");

	fclose(datafile);
  Dprintf(printf("create_file() = filename = %s(%p);\n",filename,filename););

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
  Dprintf(printf("save_file(list,count = %d,filename = %s);\n",count,filename););
  FILE *datafile = fopen(filename, "w");
  Dprintf(if(datafile == NULL) printf("NULL pointer!\n"););

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

