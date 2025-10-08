### 1.)

**Getting Matrix Dimensions** - I decided to create a separate function for getting the matrix dimensions rather than including it in the `create_matrix_dimensions` function. Each function then had only a single responsibility.  Because I needed to return two values (for rows and columns), I decided to pass these by reference so that I could modify them within the function. The return value is then used as an error code.

**Creating Matrices** - I created a pointer to a series of arrays based on the dimensions the user specified and then returned it. A `NULL` value would indicate that memory allocation was unsuccessful.

**Reading and Printing Matrix Data** - These functions both had a similar structure. Each involved nested loops to iterate through each element in the matrix.  Reading matrix data and printing matrix data was straightforward.  

**Matrix Multiplication** - The algorithm for matrix multiplication was provided to us, so this was relatively straightforward as well.  The only challenge was ensuring the right values were being used (since we were handling three sets of matrix dimensions)

### 2.) 

Allocating memory for the matrices was the most challenging part of this assignment.  The syntax for using `malloc` is a little challenging, as is dealing with pointers to other pointers.  However, once this was functioning correctly, the rest of the program was fairly easy to implement.

### 3.)

I did not use AI tools.

### 4.)

I did not use ChatGPT.