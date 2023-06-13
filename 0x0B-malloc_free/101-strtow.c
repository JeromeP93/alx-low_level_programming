#include "main.h"
#include <stdlib.h>

/**
 * count_words - Counts the number of words in a string.
 * @str: The input string.
 *
 * Return: The number of words in the string.
 */
int count_words(char *str);

/**
 * get_word_length - Computes the length of a word starting
 * from a given position.
 * @str: The input string.
 * @start: The starting position of the word.
 *
 * Return: The length of the word.
 */
int get_word_length(char *str, int start);

/**
 * free_words - Frees the memory allocated for the array of words.
 * @words: The array of words.
 * @count: The number of words in the array.
 */
void free_words(char **words, int count);

/**
 * copy_word - Copies a word from the input string to a new memory location.
 * @str: The input string.
 * @start: The starting position of the word.
 * @length: The length of the word.
 *
 * Return: The pointer to the newly allocated memory containing the word.
 */
char *copy_word(char *str, int start, int length);

/**
 * count_words - Counts the number of words in a string.
 * @str: The input string.
 *
 * Return: The number of words.
 */
int count_words(char *str)
{
int count = 0;
int i = 0;

while (str[i] != '\0')
{
if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
count++;
i++;
}

return (count);
}

/**
 * get_word_length - Calculates the length of a word starting
 * from a given position.
 * @str: The input string.
 * @start: The starting position of the word.
 *
 * Return: The length of the word.
 */
int get_word_length(char *str, int start)
{
int length = 0;

while (str[start] != ' ' && str[start] != '\0')
{
length++;
start++;
}

return (length);
}

/**
 * free_words - Frees the memory allocated for an array of words.
 * @words: The array of words.
 * @count: The number of words.
 *
 * Return: Nothing.
 */
void free_words(char **words, int count)
{
int i;

for (i = 0; i < count; i++)
{
free(words[i]);
}
free(words);
}

/**
 * copy_word - Copies a word from a string into a new dynamically
 * allocated string.
 * @str: The input string.
 * @start: The starting position of the word.
 * @length: The length of the word.
 *
 * Return: A pointer to the newly allocated string containing the word.
 */
char *copy_word(char *str, int start, int length)
{
char *word = malloc(sizeof(char) * (length + 1));
int i;

if (word == NULL)
return (NULL);

for (i = 0; i < length; i++, start++)
{
word[i] = str[start];
}
word[length] = '\0';

return (word);
}

/**
 * strtow - Splits a string into words.
 * @str: The input string.
 *
 * Return: A pointer to an array of strings (words).
 *         Each element of the array contains a single word, null-terminated.
 *         The last element of the array is NULL.
 *         Returns NULL if str == NULL or str == "" or if the function fails.
 */
char **strtow(char *str)
{
char **words;
int word_count, word_index = 0;
int str_index = 0;

if (str == NULL || *str == '\0')
return (NULL);

word_count = count_words(str);
words = malloc(sizeof(char *) * (word_count + 1));
if (words == NULL)
return (NULL);

while (str[str_index] != '\0')
{
if (str[str_index] != ' ')
{
int word_length = get_word_length(str, str_index);
words[word_index] = copy_word(str, str_index, word_length);
if (words[word_index] == NULL)
{
free_words(words, word_index);
return (NULL);
}
str_index += word_length;
word_index++;
}
else
{
str_index++;
}
}
words[word_index] = NULL;

return (words);
}
