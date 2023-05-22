#include <stdio.h>
#include "dog.h"
/**
 * print_dog - Prints the details of a struct dog
 * @d: Pointer to the struct dog
 *
 * This function prints the name, age, and owner of a struct dog.
 * If an element is NULL, it prints "(nil)" instead of the actual value.
 * If @d is NULL, it does nothing.
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;

	printf("Name: %s\n", (d->name != NULL) ? d->name : "(nil)");
	printf("Age: %.2f\n", d->age);
	printf("Owner: %s\n", (d->owner != NULL) ? d->owner : "(nil)");
}
