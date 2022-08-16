#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _person{
    char* first_name;
    char* last_name;
    unsigned int age;
}Person;

#define LIST_SIZE 10
Person *list[LIST_SIZE];

void initialize_person(Person* person, const char* f_name, const char* l_name, unsigned int _age );
void deallocate_person(Person* person);
Person* get_Person();
Person* return_person(Person* person);
void display_person(Person* person);

int main(void)
{

    Person* ptr = get_Person(); 
    initialize_person(ptr, "Ganesh", "Ingale", 22);
    display_person(ptr);
    printf("is person allocated in pool = %p\n", return_person(ptr));
    deallocate_person(ptr);
    free(ptr);
    ptr = NULL;


}

void initialize_person(Person* person, const char* f_name, const char* l_name, unsigned int _age )
{
    person->first_name = (char*)malloc(strlen(f_name)+1);
    strcpy(person->first_name,f_name);
    person->last_name = (char*)malloc(strlen(l_name)+1);
    strcpy(person->last_name , l_name);
    person->age = _age;
}

void deallocate_person(Person* person)
{
    free(person->first_name);
    free(person->last_name);
}

//returns a person object to the user
Person* get_Person()
{
    int i = 0;
    for(i = 0 ; i < LIST_SIZE; i++ )
    {
        if(list[i] != NULL)
        {
            //As there is a pointer that already exist in our object pool
            //we dont need to allocate memory to the structure.
            //There may arise some problem in threading if an object is being used by some thread
            //we will just return a pointer to this struct that already exits in pool
            Person *ptr = list[i];
            return ptr;
        }
    }

    //else create a new object
    Person* person = (Person*)malloc(sizeof(Person));
    return person;

}

Person* return_person(Person* person)
{
    int i = 0;
    for(i = 0; i< LIST_SIZE; i++)
    {
        if(list[i] == NULL)
        {
            list[i] = person;
            return person;
        }
    }
    free(person);
    person = NULL;
    return person;
}

void display_person(Person* person)
{
    printf("first namee = %s, last_name = %s, age = %d", person->first_name,person->last_name,person->age);
}