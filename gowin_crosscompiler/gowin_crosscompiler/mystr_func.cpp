#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mystr_func.h"

int strlen(char* str) {
	int i = 0;
	while (1) {
		if (str[i] == NULL) {
			return i;
		}
		i++;
	}
}

int lntrim(char* str, int len) {
	for (int i = 0; i < len; i++) {
		if (str[i] == '\n') {
			str[i] = '\0';
			return i;
		}
	}
}

int rm_comment(char* str, int len) {
	for (int i = 0; i < len; i++) {
		if (str[i] == ';') {
			str[i] = '\0';
			return i;
		}
	}
}