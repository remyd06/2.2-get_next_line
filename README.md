# Get Next Line Project 📜

Welcome to the **Get Next Line** project! This project is about reading a line from a file descriptor in a single call to the function. This helps deepen your understanding of file handling and dynamic memory allocation in C. The objective is to reproduce the behavior of reading lines as efficiently as possible, taking into account all edge cases.

## Introduction 🎯

The **get_next_line** function reads a single line from a file descriptor, returning it each time it is called. It handles reading chunk by chunk and manages any leftover content to deliver a clean and complete line upon each call.

This project teaches you how to handle memory effectively while dealing with potentially large files and lines of varying sizes.

## Features ✨

- **Line-by-Line Reading**: Read a file or input stream one line at a time.
- **Multiple File Descriptors**: The **bonus** version supports reading from multiple file descriptors simultaneously.
- **Dynamic Buffer Management**: Efficient handling of reading chunks of data, storing remaining content for future use.
- **Memory Management**: Implements careful memory allocation and freeing to prevent leaks.

## Function Overview 🧩

### Main Functions

1. **`get_next_line(int fd)`**:
   - The main function that reads from the file descriptor (`fd`) and returns the next line. It uses a static variable to store leftover data from the previous read.

2. **`read_file`**:
   - Reads from the file in chunks of `BUFFER_SIZE` and joins the content to form a full line.

3. **`get_line`**:
   - Extracts the current line from the stored data, up to and including a newline character, if present.

4. **`get_backup`**:
   - Prepares leftover content after a line has been extracted, so it can be used in subsequent calls.

5. **Utility Functions**:
   - **`ft_strlen`**: Calculates the length of a string.
   - **`ft_strjoin`**: Concatenates two strings, ensuring memory allocation.
   - **`ft_strchr`**: Locates a character in a string.
   - **`ft_strdup`**: Duplicates a string with new memory allocation.

## Installation ⚙️

To install and compile the **get_next_line** library:

```bash
git clone https://github.com/yourusername/get_next_line.git
cd get_next_line
make
```
The `Makefile` will generate the `get_next_line.a` library, which you can use in your projects by linking it.

## Usage 🖥️

To use **get_next_line**, simply include the header file `get_next_line.h` in your program and link the library during compilation.
Example:
```bash
#include "get_next_line.h"
#include <fcntl.h> // For open()
#include <stdio.h> // For printf()

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}

```
Compilation:
```bash


```


