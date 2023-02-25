#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _person{
    char* first_name;
    char* last_name;
    unsigned int age;
}Person;

int main(void)
{
    //method 1
    Person person;
    person.first_name = (char*)malloc(strlen("Ganesh")+1);
    printf("memoory allocated\n");
    strcpy(person.first_name,"Ganesh");
    person.age = 22;

    //method 2
    Person *personptr;
    personptr = (Person*)malloc(sizeof(Person));
    personptr->first_name = (char*)malloc(strlen("Yooboy")+1);
    printf("memoory allocated\n");
    strcpy(personptr->first_name,"Yooboy");
    personptr->age = 22;

    //Can be also written as but not an reccomended way 
    //alternate syntax
    // (*personptr).first_name = (char*)malloc(strlen("Yooboy")+1);
    // strcpy((*personptr).first_name,"Yooboy");

    printf("persson name = %s\n", person.first_name);
    printf("persson2 name = %s\n", personptr->first_name);

    free(personptr->first_name);
    free(person.first_name);
    free(personptr);

}