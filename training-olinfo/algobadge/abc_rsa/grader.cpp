#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

static FILE *fr, *fw;

// Declaring variables
static int N;
static int d;
static int L;
static int* messaggio;
static char* plaintext;

int fastexp(int b, int e, const int MOD) {
	if (e == 0)
		return 1;

	int t = fastexp(b, e/2, MOD);
	t = (t % MOD * t % MOD) % MOD;

	if (e % 2 == 0)
		return t;
	else
		return (t * b % MOD) % MOD;
}
// Declaring functions
void decifra(int N, int d, int L, int* messaggio, char* plaintext) {
	for (int i = 0; i < L; i++) {
		plaintext[i] = char(fastexp(messaggio[i], d, N));
	}
}

int main() {
	fr = stdin;
	fw = stdout;

	// Iterators used in for loops
	int i0;

	// Reading input
        fscanf(fr, "%d %d %d", &N, &d, &L);
	messaggio = (int*)malloc(100 * sizeof(int));
	plaintext = (char*)malloc(110 * sizeof(char));
	for (i0 = 0; i0 < L; i0++)
            fscanf(fr, "%d", &messaggio[i0]);

	// Calling functions
	decifra(N, d, L, messaggio, plaintext);

	// Writing output
        fprintf(fw, "%s\n", plaintext);

	fclose(fr);
	fclose(fw);
	return 0;
}
