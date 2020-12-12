#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

int main(int argc, char* argv[]) {
	MPI_Init(&argc, &argv);

	int rank;
	int size;
	int x = 10000; // <-- Digite o valor desejado para realizar o somatorio
	int y = x;
	int buffer = 0;
	int i;
	int var = 0;
	long long int resultado_1 = 0;
	long long int resultado_2 = 0;

	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (x % (size - 1) != 0) {

		x = x - (x % (size - 1));
		var = 1;

	}

	if (x < size - 1) {

		if (rank == 0) {

			printf("O numero de processos destinados ao calculo supera o valor do numero");

		}

		MPI_Finalize();
		exit(1);

	}

	if (rank != size - 1) {

		buffer = x / (size - 1);

		for (i = (rank * buffer) + 1; i <= (rank + 1) * buffer; i++) {

			resultado_1 = resultado_1 + i;

		}

		MPI_Send(&resultado_1, 1, MPI_INT, size - 1, 0, MPI_COMM_WORLD);

	}

	else if (rank == size - 1) {

		for (i = 0; i < size - 1; i++) {

			MPI_Recv(&resultado_1, 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

			resultado_2 = resultado_2 + resultado_1;

		}

		if (var == 1) {

			for (i = x + 1; i <= y; i++) {

				resultado_2 = resultado_2 + i;

			}

		}

		printf("Este programa realizara o somatorio do numero %d com o metodo MPI\n", y);
		printf("O resultado do somatorio e %lld", resultado_2);

	}

	MPI_Finalize();

	return 0;

}