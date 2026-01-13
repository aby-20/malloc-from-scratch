#define ALIGN 16
#define ALLOCATED 1UL
#define ALIGN_UP(x) (((x)+ALIGN-1) & ~(ALIGN-1))
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>

typedef struct block_header{
size_t size_and_flag;
}block_header_t;

void* aby_malloc(size_t size){
if(size == 0)
return NULL;

size_t total_size = ALIGN_UP(sizeof(block_header_t)+size);

block_header_t *block = sbrk(total_size);

if(block == (void*)-1)
return NULL;

block -> size_and_flag = total_size | ALLOCATED;

return (void *)(block +1);
}

void my_free(void *ptr){
if(!ptr)
return;

block_header_t *block = ((block_header_t*)ptr)-1;

if(!(block->size_and_flag &ALLOCATED))
return;

block->size_and_flag &= ~ALLOCATED;

}

int main(void){
int *p = aby_malloc(sizeof(int)*10);

if(!p){
printf("allocation failed\n");
return 1;
}

p[0] = 41;
p[9] = 99;

printf("p[0] = %d\n",p[0]);
printf("p[9] = %d\n",p[9]);

my_free(p);
my_free(NULL);
my_free(p);

return 0;
}

