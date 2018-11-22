namespace {
    enum Dimention {
        row = 5,
        col = 5
    };
}

void printSpiral(int arr[row][col], int row, int col);
void printSpiralRecursive(int arr[row][col], int rowStart, int rowEnd, int colStart, int colEnd);
