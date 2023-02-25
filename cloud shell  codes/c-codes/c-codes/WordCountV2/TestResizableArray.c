#include "ResizableArray.h"
char *randstring(size_t length) {

    static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";        
    char *randomString = NULL;

    if (length) {
        randomString = malloc(sizeof(char) * (length +1));

        if (randomString) {            
            for (int n = 0;n < length;n++) {            
                int key = rand() % (int)(sizeof(charset) -1);
                randomString[n] = charset[key];
            }

            randomString[length] = '\0';
        }
    }

    return randomString;
}
int main()
{
    time_t start,end,delta;
    start = time(0);
    vector* vec = createVector();
    int i;
    for( i = 0 ; i < 1000000; i++)
    {
        char* rands = randstring(10);
        pushBackVersionV2(vec, rands,0);

    }
    end = time(0);
    delta = end - start;
    printf("delta = %lld\n", delta); 
   // ShowVector(vec);
    DestroyVector(vec);
    
}