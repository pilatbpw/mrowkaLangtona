#include <stdio.h>
void funkcja(char *c){
	*c='b';
	printf("%c\n",*c);

}


int main(){
	char znak='a';
	funkcja(&znak);
	printf("%c\n",znak);	
       return 0;	


}
