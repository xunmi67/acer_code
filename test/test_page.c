#include <unistd.h>
#include <stdio.h>

int main(int n,char** v){
    size_t si= getpagesize();
    printf("size is:%d\n",si);
    return 0;
}
