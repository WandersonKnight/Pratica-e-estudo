#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

int main(int argc, char** argv) {
	MPI_Init(&argc, &argv);

	int rank;
	int size;
	int x = 9;  // <-- Change this to change the factorial 
	int var = 0;
	int buffer;
	long long int resultado = 1;

	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (x == 0) {

		if (rank == 0) {

			printf("O resultado do fatorial de 0 e: 1");

		}
		
		MPI_Finalize();
		exit(1);

	}

	if (x % 2 == 1) {

		x = x - 1;
		var = 1;

	}

	if (rank != size - 1) {

		if (size < (x / 2 + 1) || size > (x / 2 + 1)) {
		
			if (rank == 0) {

				printf("Quantidade de processos recomendada: %d", (x / 2 + 1));

			}

			MPI_Finalize();
			exit(1);

		}

		else {

			buffer = (x - (rank * 2)) * (x - ((rank * 2) + 1));
			MPI_Send(&buffer, 1, MPI_INT, size - 1, 0, MPI_COMM_WORLD);

		}

	}

	else if (rank == size - 1) {

		if (size < (x / 2 + 1) || size > (x / 2 + 1)) {

			MPI_Finalize();
			exit(1);

		}

		else {

			for (int i = 0; i < size - 1; i++) {

				MPI_Recv(&buffer, 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

				resultado = resultado * buffer;

			}

			if (var == 1) {

				x = x + 1;
				resultado = resultado * x;

			}
		
			printf("O resultado do fatorial de %d e : %lld", x, resultado);

		}

	}

	MPI_Finalize();

	return 0;

}