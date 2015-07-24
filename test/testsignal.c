#include <stdio.h>
#include <signal.h>
void test_psignal(){
    int i=0;
    for(;i<90;i++){
	printf("%d:%s\n",i,sys_siglist[i]);
    }
}
int main(int argn,char ** argv){
    test_psignal();
    return 0;
}
