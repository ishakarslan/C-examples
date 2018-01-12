#include <stdio.h>
#include <stdlib.h>
#include <error.h> /* for exit argument */
#include <ctype.h>

#define IN 0
#define OUT 1

void count_obj(char *filename);

int main(int argc, char *argv[])
{
	FILE *ptr1, *ptr2;
	char c;

	if(argc < 3){
		fprintf(stderr, "Usage: %s [srcfile]  [dstfile]\n", argv[0] );
		exit(EXIT_FAILURE);
	}

	ptr1 = fopen(argv[1], "r"); /* argument 1 to pointer */
	if (ptr1 == NULL) {
		printf("Could not open file");
		exit (EXIT_FAILURE);
	}

	ptr2 = fopen(argv[2], "w"); /* argument 2 to pointer */

	c = fgetc(ptr1);
	while(c != EOF){ /* get file content until end of file */
		fputc(c, ptr2); /* put file content to pointer */
		c = fgetc(ptr1);
	}

	printf("\n %s copied to %s file\n", argv[1], argv[2]);
	count_obj(argv[1]); /* call count_obj function */

	fclose(ptr1);
	fclose(ptr2);
	return 0;
}

void count_obj(char *filename)
{
        int c, nd, nl, nw, nc, state, len;
        FILE *file;
        state = OUT;

        nl = nw = nc = nd = len = 0;
	file = fopen(filename, "r");

        while ((c = fgetc(file)) != EOF) {
                ++nc;
                if(c =='\n')
                        ++nl;
                if(c >= '0' && c <= '9' ) /* can use if(isdigit(c))*/
                        ++nd;
                if(c == ' ' || c == '\n'  || c == '\t')
                        state = OUT;
                else if (state == OUT) {
                        state = IN;
                        ++nw;
                }
        }

	fclose(file);
        printf("\n  Line  :%d\n  Word  :%d\n  Char  :%d\n  Digit :%d\n\n", nl, nw, nc, nd);
}
