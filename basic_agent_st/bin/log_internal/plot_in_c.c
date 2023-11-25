#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");

    if (gnuplotPipe) {
        FILE *dataFile = fopen("PrimitivePlot.csv", "r");

        if (dataFile) {
            // Salta la prima riga (nomi delle colonne)
            fscanf(dataFile, "%*[^\n]\n");

            fprintf(gnuplotPipe, "plot '-' with linespoints title 'Dati da PrimitivePlot.csv'\n");

            double x, y;
            int readCount;

            // Leggi e invia i dati a gnuplot
            while ((readCount = fscanf(dataFile, "%lf,%lf", &x, &y)) == 2) {
                fprintf(gnuplotPipe, "%lf %lf\n", x, y);
            }

            if (readCount != EOF) {
                printf("Errore nella lettura dei dati.\n");
            }

            fprintf(gnuplotPipe, "e\n");
            fclose(dataFile);
        } else {
            printf("Errore nell'apertura del file CSV\n");
        }

        pclose(gnuplotPipe);
    } else {
        printf("Errore nell'apertura di gnuplot\n");
    }

    return 0;
}
