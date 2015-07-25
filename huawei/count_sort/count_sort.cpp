#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
static void init(char* str, int* alp_count, int* pos);
void count_sort(char* str, char *after);
static void insert(char *str, char *after, int *pos);
#define get_low(a) ((a<='Z'&&a>='A')?'a'+a-'A':a)
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

/*---------------below are test functions---------------*/
void test_init(){
	char * str = "avc def Asss ";
	int alp_count[26] = { 0 };
	int *pos = (int*)calloc((strlen(str) + 1),sizeof(int));
	init(str, alp_count, pos);
	printf("a:%d,c:%d,d:%d,s:%d", alp_count[0], alp_count['c' - 'a'], alp_count['d' - 'a'], alp_count['s' - 'a']);
	free(pos);
}	
int main(char **agv, int agn){
	test_init();
	getchar();
}				 