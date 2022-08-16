#include <stdio.h>
#include<stdlib.h>

int main(){
	int nwhite,nother,ndigit[10],c,i;
	for(i=0;i<10;i++){
		ndigit[i]=0;
	}
	printf("Hello\n");
	while((c=getchar())!= EOF){

		switch(c){
			case '0':case '1':case '2':case '3' :case '4': case '5' :case '6':
			case '7':case '9': 
				ndigit[c-'0']++;
				break;
			case ' ':
			case '\t':
			case '\n':
				nwhite++;
				break;
			default:
				nother++;
				break;

		
		}
	}

	printf("ndigits = ");
	for(i=0;i<10;i++){
		printf("%d ,  %d\n",i,ndigit[i]);
	}
	printf("nspace : %d, nother : %d",nwhite,nother);
	exit(0);




}
