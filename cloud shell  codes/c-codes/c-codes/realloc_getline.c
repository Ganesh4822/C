#include<stdio.h>
#include<stdlib.h>

char* getlineV2(void);

int main()
{
	
	char* bufferedd = getlineV2();
	printf("buffer is = %s\n",bufferedd);
	printf("size of buffer(int main) = %d\n",sizeof(bufferedd));
	free(bufferedd);
	bufferedd = NULL;

}

char* getlineV2(void)
{
	const size_t size_increament = 10;
	char* buffer = malloc(10);
	printf("size of buffer(etline 1) = %d\n",sizeof(buffer));
	int character;
	char* current_position = buffer;
	size_t max_size_buffer  = size_increament;
	int length = 0;
	while(1)
	{	
		character = fgetc(stdin);
		if(character == '\n'){break;}

		if(++length >= max_size_buffer)
		{
			max_size_buffer = max_size_buffer + size_increament;
			char* new_buffer = realloc(buffer, max_size_buffer);
			printf("size of buffer (getline2) = %d\n",sizeof(new_buffer));
			if(new_buffer == NULL)
			{
				free(buffer);
				return NULL;
			}
			buffer = new_buffer;
			current_position = new_buffer + (current_position - buffer);			

		}
		*current_position++ = character;
		
	}
	*current_position = '\0';
	//printf("Buffer is = %s",buffer);
	return buffer;
}
