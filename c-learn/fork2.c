#include <stdio.h>
#include <unistd.h>

void doit(){
    fork();
    fork();
    printf("hello!\n");
}

int main(void){
    
    doit();
    printf("hello!\n");
    
	
    return 0;
}



