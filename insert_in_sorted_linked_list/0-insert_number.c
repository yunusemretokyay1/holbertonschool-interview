#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - insert node into sorted linked list
 * @head: pointer to the head of the linked list
 * @number: value to be inserted
 * Return: Pointer to the new node
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *current = *head;
    listint_t *newNode;

    // Allocate memory for the new node
    newNode = malloc(sizeof(*newNode));
    if (!newNode)
        return NULL;

    // Set the value of the new node
    newNode->n = number;
    newNode->next = NULL;

    // Special case for the head end
    if (*head == NULL || (*head)->n >= newNode->n)
    {
        newNode->next = *head;
        *head = newNode;
        return newNode;
    }

    // Locate the node before the point of insertion
    while (current->next != NULL && current->next->n < newNode->n)
    {
        current = current->next;
    }

    // Insert the new node at the correct position
    newNode->next = current->next;
    current->next = newNode;

    return newNode;
}