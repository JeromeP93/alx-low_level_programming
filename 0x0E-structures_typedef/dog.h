#ifndef DOG_H
#define DOG_H

/**
 * struct dog - Represents information about a dog
 * @name: The name of the dog
 * @age: The age of the dog
 * @owner: The owner of the dog
 *
 * Description: This structure holds information about a dog, including its
 *              name, age, and owner.
 */

struct dog
{
char *name;
float age;
char *owner;
};

/* Functions Prototype */
void init_dog(struct dog *d, char *name, float age, char *owner);

#endif /* DOG_H */
