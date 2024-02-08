#include "lists.h"

int recursive_palindorme(listint_t **left, listint_t *right)
{
    int ispalindrome;

	if (right == NULL)
		return (1);


	ispalindrome = recursive_palindrome(left, right->next) && 
	(right->n == (*left)->n);

	if (ispalindrome == 0)
		return (0);




	*left = (*left)->next;

	return (ispalindrome);
}
int is_palindrome(listint_t **head)
{
	return (recursive_palindrome(head, *head));

}