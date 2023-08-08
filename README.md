# Matrix Calculator

This project is a matrix calculator that allows you to perform various operations on matrices, including finding the transpose, cofactors, adjugate, determinant, inverse, minor, and submatrix of a matrix. The calculator supports rectangular matrices and provides a command-line interface for input and output.

## Available Operations

The calculator supports the following operations:

- Transpose (trn): A^T
- Cofactors (cof): cof
- Adjugate (adj): cof(A)^T
- Determinant (det): |A|
- Inverse (inv): A^-1
- Minor (minor): Mij
- Submatrix (sub): Aij

## Project Structure

The project directory structure is organized as follows:

```bash
.
├── bin
│   ├── matrix-calculator
│   └── matrix-calculator.exe
├── build
│   ├── main.o
│   └── matrix.o
├── include
│   └── matrix.h
├── scripts
│   └── build.py
└── src
    ├── main.cpp
    └── matrix.cpp
```

> [!NOTE]
> The `bin` and `build` directories are automatically generated during the build process.

## Build

To build the project, you can use the provided `build.py` script located in the `scripts` directory. The script compiles the source code files and generates the binary executable at the `bin` directory.

Run the following command in the project root directory to compile it:

```bash
python scripts/build.py
```

## Usage

After building the project, you can run the `matrix-calculator` executable to input a matrix and automatically perform all the supported matrix operations.

### Matrix Input

The calculator prompts you to input a matrix. Enter each element of the matrix, separating elements by spaces. Press Enter after each row, and press Enter twice to finish entering the matrix.

![Alt text](/images/input_matrix.png)

## License

This project is released under the [MIT License](LICENSE).

Feel free to modify and extend this project for your own use! If you find any issues or have suggestions, please create an issue or pull request in the project repository.
