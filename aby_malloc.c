#define ALIGN 16
#define ALLOCATED 1UL
#define ALIGN_UP(x) (((x)+ALIGN-1) & ~(ALIGN-1))
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>

typedef struct block_header{
size_t size_and_flag;
}block_header_t;

static block_header_t  *heap_start = NULL;

void* aby_malloc(size_t size){
if(size == 0)
return NULL;

size_t total_size = ALIGN_UP(sizeof(block_header_t)+size);

if(!heap_start){
heap_start= sbrk(0);
}
block_header_t *curr = heap_start;
block_header_t *heap_end = sbrk(0);

while(curr<heap_end){
size_t block_size = curr-> size_and_flag & ~ALLOCATED;

if(!(curr->size_and_flag &ALLOCATED) && block_size> total_size){
curr->size_and_flag = block_size | ALLOCATED;
return (void*)(curr+1);
}
curr= (block_header_t *)((char*)curr + block_size);
}
block_header_t *block = sbrk(total_size);
if(block ==(void*)-1)
return NULL;

block->size_and_flag = total_size | ALLOCATED;
return (void *)(block+1);

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
int *q = aby_malloc(sizeof(int)*10);

my_free(p);

int *r = aby_malloc(sizeof(int)*5);

printf("p= %p\n",(void*)p);
printf("r = %p(should match p)\n",(void*)r);

my_free(q);
my_free(p);

return 0;


}

