#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000 // Maximum size for the signal array

// Function to detect maxima and minima in a signal
void detect_extrema(float signal[], int size, int maxima[], int minima[], int *max_count, int *min_count) {
    *max_count = 0;
    *min_count = 0;

    for (int i = 1; i < size - 1; i++) {
        if (signal[i - 1] < signal[i] && signal[i] > signal[i + 1]) {
            maxima[(*max_count)++] = i; // Maxima
        } else if (signal[i - 1] > signal[i] && signal[i] < signal[i + 1]) {
            minima[(*min_count)++] = i; // Minima
        }
    }
    
}

// Function to print extrema indices
void print_extrema(const char *label, int indices[], int count) {
    printf("%s indices: ", label);
    for (int i = 0; i < count; i++) {
        printf("%d ", indices[i]);
    }
    printf("\n");
}

// Function to load signal data from a .txt file
int load_signal(const char *filename, float signal[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return -1;
    }

    int size = 0;
    while (fscanf(file, "%f", &signal[size]) != EOF) {
        size++;
        if (size >= MAX_SIZE) {
            printf("Error: Signal size exceeds maximum limit.\n");
            fclose(file);
            return -1;
        }
    }

    fclose(file);
    return size;
}

int main() {
    // Arrays to store the signal data from files
    float signal_1[MAX_SIZE], signal_2[MAX_SIZE];

    // Arrays to store the indices of maxima and minima
    int maxima_1[MAX_SIZE], minima_1[MAX_SIZE];
    int maxima_2[MAX_SIZE], minima_2[MAX_SIZE];

    int size_1, size_2;
    int max_count_1, min_count_1;
    int max_count_2, min_count_2;

    // Load signal data from files
    size_1 = load_signal("Data_1.txt", signal_1);
    size_2 = load_signal("Data_2.txt", signal_2);

    if (size_1 == -1 || size_2 == -1) {
        printf("Failed to load signal data.\n");
        return 1;
    }

    // Detect extrema for signal_1
    detect_extrema(signal_1, size_1, maxima_1, minima_1, &max_count_1, &min_count_1);
    // Detect extrema for signal_2
    detect_extrema(signal_2, size_2, maxima_2, minima_2, &max_count_2, &min_count_2);

    // Print the maxima and minima indices for signal_1
    printf("Signal 1:\n");
    print_extrema("Maxima", maxima_1, max_count_1);
    print_extrema("Minima", minima_1, min_count_1);

    // Print the maxima and minima indices for signal_2
    printf("Signal 2:\n");
    print_extrema("Maxima", maxima_2, max_count_2);
    print_extrema("Minima", minima_2, min_count_2);

    return 0;
}
