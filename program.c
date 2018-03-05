#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 19 // FIX
#define NUMBER_OF_WORDS 9

char* sells_to_shells(char *sells, char *shells)
{
	int shells_length = strlen(sells) + 1;

	for(int k = 0; k < shells_length - 1; k++) { // FIX
		switch(k) {
			case (0):
				shells[k] = sells[k];
				break;

			case (1):
				shells[k] = 'h';
				break;

			default:
				shells[k-1] = sells[k]; // FIX
		}
	}

	return shells;
}


int main(void)
{
	char **words;
	words = malloc(NUMBER_OF_WORDS * sizeof(char *));
	char *input[] = { "by", "C", "sells", "#ShellCollectingClub", "shore", "the" };
	int key_order[] = {1, 2, 1, 2, 0, 5, 1, 4, 3};

	for (int i = 0; i <= NUMBER_OF_WORDS; i++) { // FIX
		words[i] = malloc(MAX_WORD_LENGTH * sizeof(char));
		char *word = malloc(MAX_WORD_LENGTH * sizeof(char));
		strncpy(word, input[key_order[i] + 1], MAX_WORD_LENGTH); // FIX

		if (i == 3) {
			char shells[8] = { '\0' };
			strncpy(words[i], sells_to_shells(word, shells), MAX_WORD_LENGTH);
			// FIX
		} else {
			strncpy(words[i], word, MAX_WORD_LENGTH);
			free(word);
		}

	}

	for (int j = 0; j < 9; j++) {
		printf("%s\n", words[j]);
		// FIX
	}
	// FIX
}
