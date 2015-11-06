#include <stdio.h>
#include <stdlib.h>

int global_var;
int global_initialized_var = 0;

int main(){
   int stack_var;
   static int static_initialized_var = 5;
   static int static_var;
   int *heap_var_ptr;

   heap_var_ptr = (int *) malloc(4);

   //in the data segment
   printf("global_initialized_var addr: 0x%08x\n", &global_initialized_var);
   printf("static_initialized_var addr: 　0x%08\n", &static_initialized_var);

   //in the bss segment
   printf("static_var addr:0x%08x\n", &static_var);
   printf("global_var addr:0x%08x\n", &global_var);

   //in the heap segment
   printf("heap_var_ptr addr:0x%08x\n", heap_var_ptr);

   //in the stack segment
   printf("stack_var addr:0x%08x\n", &stack_var);

   return 0;
}
