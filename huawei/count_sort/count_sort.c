#include <stdlib.h>
#include <string.h>
#include <stdio.h>
static void init(char* str, int* alp_count, int* pos);
void count_sort(char* str, char *after,int* pos);
static void insert(char *str, char *after,char* result);
#define get_low(a) ((a<='Z'&&a>='A')?'a'+a-'A':a)
static int *alp_count;//alp_count
static int *pos;//non-alpha char postion
inline static right_pos(char c){
	return alp_count[get_low(c)-'a']++;	
}


void count_sort(char* str,char* after,int * pos){
	alp_count=(int*)calloc(26,sizeof(int));
	init(str,alp_count,pos);	
	int i=0;
	int j=0;
	while(str[i]!='\0'){
		if(isalpha(str[i])) 
		{
			after[right_pos(str[i])]=str[i];
			++j;
		}
		i++;
	}
	after[j]='\0';
	free(alp_count);
}

/*pos[count_of_nonalpha] must be useful!which means that */
static void init(char* str, int* alp_count, int* pos){
	int i = 0;
	int j = 0;//record non-alph position
	while (str[i] != '\0'){
		if (isalpha(str[i])){
			alp_count[get_low(str[i]) - 'a']++;
		}
		else{
			pos[j++] = i;	
		}
		i++;
	}
	int previous = alp_count[0];
	alp_count[0] = 0;
	int temp = 0;
	for (i = 1; i < 26; i++){
		temp = alp_count[i];
		alp_count[i] = alp_count[i - 1]+previous;	
		previous = temp;
	}
	pos[j] = strlen(str);//prepare for insert()
}

static void insert(char *str,char* after,char *result){
	int i=0,j=0,k=0;
	while(i<strlen(str)){
	if(isalpha(str[i]))
			result[k++]=after[j++];
	else
		result[k++]=str[i];
	i++;
	}
	result[k]='\0';
}
/*---------------below are test functions---------------*/
void test_init(){
	char * str = "avc def Asss ";
	int alp_count[26] = { 0 };
	int *pos = (int*)calloc((strlen(str) + 1),sizeof(int));
	init(str, alp_count, pos);
	printf("a:%d,c:%d,d:%d,s:%d", alp_count[0], alp_count['c' - 'a'], alp_count['d' - 'a'], alp_count['s' - 'a']);
	free(pos);
}	

void test_count_sort(){
    char * str="aab AaB b ";
    char* after = (char*) malloc(sizeof(char)*strlen(str));
	after[strlen(str)]='\0';
	pos = (int*)calloc((strlen(str) + 1),sizeof(int));
	count_sort(str,after,pos);
    printf("before:%s\nafter:%s\n",str,after); 
	char* result= (char*) malloc(sizeof(char)*strlen(str));
	insert(str,after,result);
    printf("before:%s\nresult:%s\n",str,result); 
    free(after);
	free(pos);
	free(result);
}
#define MAXL 1000 
int main(char **agv, int agn){
	char  str[MAXL];
    char* after = (char*) malloc(sizeof(char)*MAXL);
	char tempc;
	int i=0;
	while( (tempc=getchar())!=EOF){
		str[i++]=(char)tempc;
	}
	str[i]='\0';
	pos = (int*)calloc((strlen(str)+ 1),sizeof(int));
	count_sort(str,after,pos);
	char* result= (char*) malloc(sizeof(char)*strlen(str));
	insert(str,after,result);
    printf("%s",result); 
    free(after);
	free(pos);
	free(result);
	
    return 0;
}				 
