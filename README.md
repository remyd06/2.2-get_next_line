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
```

## Usage 🖥️

To use **get_next_line**, simply enable the main in `get_next_line.c`.
Example:
```bash
#include "get_next_line.h"
int	main(void)
{
	char *line;
	int fd;

	fd = open("./montexte.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error while trying to open file");
		return (1);
	}

	printf("Contenu du fichier :\n");

	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("-------\n");
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}

	close(fd);
	return (0);
}
```
Compilation:
```bash
gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c
```
## Bonus Features 🌟

In the **bonus** part of the project, the function handles multiple file descriptors at once. Each file descriptor maintains its own static storage, so you can switch between reading different files without losing track of where you are in any given file.
- **Multiple File Descriptors Support**: You can call `get_next_line` on multiple files or input streams, and it will return lines independently from each.

## Understanding the Codebase 🧠

**Key Concepts** 
- **Static Variables**: The project leverages static variables to store the current state of the read operation, allowing it to manage leftover data between calls to `get_next_line`.
- **Buffer Management**: Each read operation uses a buffer of size `BUFFER_SIZE`, defined during compilation, allowing the function to read chunks of data efficiently.
- **Memory Handling**: Each line read from the file is dynamically allocated. It is important to free the memory after each use to avoid memory leaks.

## Testing 🧪

Create a .txt file at the root of get_next_line, simple text with new lines and include the file path in the main.
Example, at this line:
```bash
fd = open("./montexte.txt", O_RDONLY);
```
