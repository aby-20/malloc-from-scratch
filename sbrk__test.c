#include <stdio.h>
#include <unistd.h>
int main(void){
void *before;
void *after;

before = sbrk(0);

after = sbrk(4096);

if(after == (void *)-1){
perror("sbrk failed");
return 1;
}

printf("Program break before sbrk is %p\n",before);
printf("Program break after sbrk is %p\n",after);
printf("New program break: %p\n", sbrk(0));
return 0;
}