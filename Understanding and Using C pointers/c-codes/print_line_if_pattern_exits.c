#include<stdio.h>
#define MAXLINE 1000

int getline1(char* line, int max);
int strindex(char* source, char* dest);

char* pattern  = "ould";
int main(void)
{
	char* line;
	int found = 0;
	while(getline1(line, MAXLINE) > 0)
	{
		if(strindex(line, pattern)>0)
			printf("%s",line);
			found++;
	}

}


int getline1(char* line, int lim)
{
	int i,c;
	i = 0;
	while(--lim>0 && ((c = getchar())!= EOF) && c!= '\n')
	{
		line[i++] = c;

	}
	if(c == '\n')
		line[i++] = c;
	line[i] = '\0';
	printf("wakanda forever%s\n",line);
	return i;
}

int strindex(char* source, char* pattern)
{
	int i,j,k;
	for(i = 0; source[i] != '\0'; i++){
		for(j = i, k = 0; pattern[k]!= '\0'&& source[j] == pattern[k]; j++,k++)
			;
		if(k>0 && pattern[k] == '\0')
			return i;
	}
	return -1;
}
