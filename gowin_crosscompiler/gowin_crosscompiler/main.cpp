#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mystr_func.h"
#define D_IN_FILENAME  "./source.asm"
#define D_OUT_FILENAME "./rom_init.mif"
#define D_MAX_DEPTH 256
#define D_MAX_SIZE  16
#define D_MAXLEN_ASSEMBLA_CODE 1000

/* OP Codes */
#define NOP 0
#define ADD 1
#define SUB 2
#define AND 3
#define OR  4
#define SL  5
#define SR  6
#define SRA 7
#define LDL 8
#define LDH 9
#define CMP A
#define JE  B
#define JMP C
#define LD  D
#define ST  E
#define MOV F

int main() {
	//アセンブリコードを読み込む。
	FILE* fp;
	int no = 0;
	int len_one_code = 0;
	char one_code [D_MAXLEN_ASSEMBLA_CODE];
	char last_moji [D_MAXLEN_ASSEMBLA_CODE] ="EOF";

	// ソースファイルのopen
	no = fopen_s(&fp, D_IN_FILENAME, "r");
	if (no != 0) {printf("ファイルが開けませんでした。\n");return -1;}
	for (int i = 0; (fgets(one_code, D_MAXLEN_ASSEMBLA_CODE, fp) != NULL); i++) {
		len_one_code = strlen(one_code);
		len_one_code = lntrim(one_code, len_one_code);
		len_one_code = rm_comment(one_code, len_one_code);
		if (strcmp(one_code, last_moji) != 0 && strcmp(one_code,"") != 0) {
			printf("%s\n", one_code);
		}
	}
	fclose(fp);
	printf("\n========================\n");
	printf("cross assembla finish!");
	printf("\n========================\n");
}