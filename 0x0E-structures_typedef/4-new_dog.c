#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - Creates a new dog
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Owner of the dog
 *
 * Return: Pointer to the newly created dog, or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *new_dog;
    int name_len = 0;
    int owner_len = 0;
    int i;

    while (name[name_len])
        name_len++;

    while (owner[owner_len])
        owner_len++;

    new_dog = malloc(sizeof(dog_t));
    if (new_dog == NULL)
        return (NULL);

    new_dog->name = malloc(sizeof(char) * (name_len + 1));
    if (new_dog->name == NULL)
    {
        free(new_dog);
        return (NULL);
    }

    new_dog->owner = malloc(sizeof(char) * (owner_len + 1));
    if (new_dog->owner == NULL)
    {
        free(new_dog->name);
        free(new_dog);
        return (NULL);
    }

    for (i = 0; i <= name_len; i++)
        new_dog->name[i] = name[i];

    for (i = 0; i <= owner_len; i++)
        new_dog->owner[i] = owner[i];

    new_dog->age = age;

    return (new_dog);
}
