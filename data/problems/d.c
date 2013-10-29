#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INFINITE 100001

int main () {
	int i, j;
	int _attacks = 0;
	int _defenders = 0;
	int *attacks;
	int *defenders;
	
	char *total, *aux;
	int tam = 0;

	total = (char *) malloc (sizeof(char) * 1);
	aux = (char *) malloc (sizeof(char) * 1);

	while (1) {
		scanf("%d %d", &_attacks, &_defenders);

		if (_attacks == 0 && _defenders == 0) {
			printf("%s", total);
			exit(0);
		}

		attacks = (int *) malloc (sizeof(int) * _attacks);
		defenders = (int *) malloc (sizeof(int) * _defenders);

		for (i = 0; i < _attacks; i++) {
			scanf("%d", &attacks[i]);
		}
		for (j = 0; j < _defenders; j++) {
			scanf("%d", &defenders[j]);
		}

		tam += 2;
		strcpy (aux, total);
		total = (char *) malloc (sizeof(char) * tam);
		strcpy (total, aux);
		aux = (char *) malloc (sizeof(char) * tam);

		if (isNotOffside(attacks, _attacks, defenders, _defenders) == 1) {
			strcat(total, "N\n");
		} else {
			strcat(total, "Y\n");
		}
	}
}

int isNotOffside (int *atts, int _atts, int *defs, int _defs) {
	int lastdef1 = INFINITE;
	int lastdef2 = INFINITE;
	int lastatt = INFINITE;

	int c, i, j, k;

	for (c = 0; c < _defs; c++) {
		if (lastdef1 > defs[c]) {
			lastdef1 = defs[c];
			i = c;
		}
	}
	defs[i] = INFINITE;
	//printf("el menor defensor esta en %d ", lastdef1);

	for (c = 0; c < _defs; c++) {
		if (lastdef2 > defs[c]) {
			lastdef2 = defs[c];
			i = c;
		}
	}
	defs[i] = INFINITE;
	//printf("el segundo menor defensor esta en %d ", lastdef2);

	for (j = 0; j < _atts; j++) {
		if (lastatt > atts[j]) {
			lastatt = atts[j];
		}
	}
	//printf("el menor atacante esta en %d ", lastatt);

	if (lastatt > lastdef2) {
		return 1;
	} else {
		if (lastatt == lastdef1 && lastatt == lastdef2) {
			return 1;
		}
	}
	return 0;
}

