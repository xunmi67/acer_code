#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#define MAX_L 1000
#define MAX(a,b) (a>b?a:b)
/*cal continue 0 in a*/
int max_leng(int *a,int leng);
/*cal common substr length of a[as-ae] and b[bs-be]*/
int common(const char *a,int as,int ae,const char *b,int bs,int be);
/*cal common substr of a and b*/
int longest_common(char* a,int aleng,char* b,int bleng);
int main(char **agv,int agn){
    char *a = (char*)malloc(MAX_L*sizeof(char));
    char *b = (char*)malloc(MAX_L*sizeof(char));
    scanf("%999s",a);
    scanf("%999s",b);
    size_t al = strlen(a);
    size_t bl = strlen(b);
    unsigned int result = longest_common(a,al,b,bl);
    printf("%d",result);

    
    free(a);free(b);
    return 0;
}
int main_t(){
    char *a="abcdexx";
    char *b="cdeyyy";
    int r = longest_common(a,7,b,6);
    printf("%d\n",r);
    return 0;
}
void print_array(int *r,int l){
    int i=0;
    for(;i<l;i++){
	printf("%d ",r[i]);
    }
    printf("\n");
}
int longest_common(char* a,int la,char* b,int lb){
    if(la<lb){
	char *t=a;
	a=b;
	b=t;
    }
    int maxl = 0;
    int sh = 0;
    for(sh=0;sh<= la+lb-2;sh++){
	int cm=0;
	if(sh< lb-1) cm = common(a,0,sh,b,lb-1-sh,lb-1);
	else if(sh<la) cm = common(a,sh-lb+1,sh,b,0,lb-1);
	else	cm = common(a,sh-lb+1,la-1,b,0,la+lb-sh-2);
	maxl= MAX(maxl,cm);
    }
    return maxl;
}

int common(const char *a,int as,int ae,const char *b,int bs,int be){
    assert((ae-as)==(be-bs));
    static int diff = 'A'-'a';
    int *result = (int*)malloc(sizeof(int)*(ae-as+1));
    int i=0;
    for(;i<=(ae-as);i++){
	result[i] = !(a[as+i]==b[bs+i]||(a[as+i]-b[bs+i]==diff)||(b[bs+i]-a[as+i]==diff));
    }
    print_array(result,(ae-as+1));
    return max_leng(result,ae-as+1);
}
/*u can image tha a like[0,1,1,0,0,1],where 0 means char matches*/
//test ok!
int max_leng(int *a,int leng){
    int max_c = 0;
    int i=0,j=0;
    for(;j<leng;++j){
	if(a[j]==0){
	    if(a[i]!=0) i=j;
	}
	else{
	    if(a[i]==0){
		max_c=MAX(max_c,j-i);
		i=j;
	    }
	}
    }
    /*make last time judge*/
    if(a[leng-1]==0&&a[i]==0)
	max_c = MAX(max_c,j-i);
    return max_c;
}

