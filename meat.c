#include <stdio.h>
#include <string.h>

int main (){ 
    // one dimension array
    char *meat[5] = {"beef","chicken","goat","mutton","rabbit"};

    //loop to print the meats
for(int i = 0; i < 5; i++){
    if(strcmp(meat[i],"rabbit") == 0){
        printf("pass rabbit\n");
        break;
    }else{
        printf("smash %s\n", meat[i]);
    }
}
return 0;
}