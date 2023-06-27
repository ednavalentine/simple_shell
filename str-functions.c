#include "main.h"
/**
 * _strlen - returns length of string
 * @s: char pointer
 * Return: len
 */
int _strlen(char *s)
{
	int i = 0;

	if (s != NULL)
	{
		while (*(s + i))
		{
			i++;
		}
	}
	return (i);
}
/**
 * _strcpy - copies the string
 * @dest: destination pointer
 * @src: source pointer
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;
	int j;

	if (src == NULL)
	{
		return (dest);
	}
	while (*(src + i) != '\0')
	{
		i++;
	}
	for (j = 0; j < i; j++)
	{
		dest[j] = src[j];
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcmp - compares two strings
 * @s1: pointer
 * @s2: pointer
 * Return: 0, <0, >0
 */
int _strcmp(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
	{
		return (-1);
	}
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/**
 * _strchr - locates a character in a string
 * @s: pointer
 * @c: char
 * Return: pointer to first occurrence of c
 */
char *_strchr(char *s, char c)
{
	if (s == NULL)
	{
		return (NULL);
	}
	while ((*s != c) && (*s != '\0'))
	{
		s++;
	}
	if (*s == c)
		return (s);
	return (NULL);
}
/**
 * _strcat - concatenates two strings
 * @dest: pointer to s1
 * @src: pointer to s2
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	if ((src == NULL && dest == NULL) || dest == NULL)
	{
		return (NULL);
	}
	if (src == NULL)
	{
		return (dest);
	}
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
