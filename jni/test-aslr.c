#include <stdio.h>
#include <stdlib.h>

#define HEAP_VAR_PTR_NUM  8

int global_var;
int global_initialized_var = 0;

int main(){
   int stack_var;
   static int static_initialized_var = 5;
   static int static_var;
   int *heap_var_ptr0;
   int *heap_var_ptr1[HEAP_VAR_PTR_NUM];

   heap_var_ptr0 = (unsigned int *) malloc(8);

   heap_var_ptr1[0] = (unsigned int *) malloc(8);
   heap_var_ptr1[1] = (unsigned int *) malloc(8);
   heap_var_ptr1[2] = (unsigned int *) malloc(16);
   heap_var_ptr1[3] = (unsigned int *) malloc(16);
   heap_var_ptr1[4] = (unsigned int *) malloc(1024);//0x0400
   heap_var_ptr1[5] = (unsigned int *) malloc(1024);//0x0400
   heap_var_ptr1[6] = (unsigned int *) malloc(16384);//0x4000
   heap_var_ptr1[7] = (unsigned int *) malloc(16384);//0x4000

   //in the data segment
   printf("global_initialized_var addr: 0x%08x\n", (unsigned int)&global_initialized_var);
   printf("static_initialized_var addr: 0x%08x\n", (unsigned int)&static_initialized_var);

   //in the bss segment
   printf("global_var addr:0x%08x\n", (unsigned int)&global_var);
   printf("static_var addr:0x%08x\n", (unsigned int)&static_var);

   //in the heap segment
   printf("heap_var_ptr addr:0x%08x\n", (unsigned int)heap_var_ptr0);

   int i;
   for (i=0; i<HEAP_VAR_PTR_NUM; i++) {
     printf("heap_var_ptr addr[%d]:0x%08x\n", i, (unsigned int)heap_var_ptr1[i]);
   }
   for (i=0; i<HEAP_VAR_PTR_NUM-1; i++) {
     printf("heap_var_ptr addr diff[%d]-[%d]:%d\n", i+1, i, (unsigned int)heap_var_ptr1[i+1]-(unsigned int)heap_var_ptr1[i]);
   }

   //in the stack segment
   printf("stack_var addr:0x%08x\n", (unsigned int)&stack_var);

   return 0;
}
