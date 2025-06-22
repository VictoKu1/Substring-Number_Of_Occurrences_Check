# Substring Frequency Counter

A C program that builds a trie (prefix tree) data structure to count the occurrences of words from input text. The program reads words from standard input and outputs each unique word along with its frequency count.

## Features

- **Trie Data Structure**: Efficiently stores and counts word occurrences using a tree structure
- **Case Insensitive**: Converts all input to lowercase for consistent counting
- **Lexicographic Output**: Displays results in alphabetical order
- **Reverse Lexicographic Option**: Can display results in reverse alphabetical order
- **Memory Efficient**: Uses dynamic memory allocation with proper cleanup
- **Robust Error Handling**: Handles memory allocation failures gracefully

## How It Works

1. **Word Reading**: Reads words from standard input, separated by whitespace
2. **Character Processing**: Converts uppercase letters to lowercase and filters out non-alphabetic characters
3. **Trie Construction**: Builds a trie where each path from root to leaf represents a word
4. **Frequency Counting**: Increments a counter at the end of each word path
5. **Output**: Traverses the trie to display all words with their frequencies

## Data Structure

The program uses a trie (prefix tree) with the following structure:
- Each node represents a character
- Children array of size 27 (26 letters + 1 for word endings)
- Special '$' character marks the end of words
- Count field stores the frequency of each word

## Compilation

### Prerequisites
- GCC compiler (or compatible C compiler)
- Make utility

### Build Commands
```bash
# Clean previous builds
make clean

# Build the program
make

# Or build directly with gcc
gcc -g -Wall -c frequency.c
gcc -g -Wall frequency.o -o frequency
```

## Usage

### Basic Usage
```bash
# Run the program and type words
./frequency

# Example input:
hello world hello there world
```

### Reverse Lexicographic Order
```bash
# Display results in reverse alphabetical order
./frequency r
```

### Input/Output Examples

**Input:**
```
hello world hello there world
```

**Output (normal order):**
```
hello 2
there 1
world 2
```

**Output (reverse order with `./frequency r`):**
```
world 2
there 1
hello 2
```

## Program Structure

- `frequency.h`: Header file with function declarations and data structures
- `frequency.c`: Main implementation file
- `makefile`: Build configuration

### Key Functions

- `get_word()`: Reads and processes input words
- `tree_builder()`: Constructs the trie data structure
- `node_builder()`: Creates new trie nodes
- `hash_func()`: Maps characters to array indices
- `Lexicographic()`: Outputs words in alphabetical order
- `Lexicographic_R()`: Outputs words in reverse alphabetical order
- `free_tree()`: Cleans up allocated memory

## Recent Fixes and Improvements

### Memory Management
- **Fixed memory leak** in main() function where initial word allocation wasn't properly managed
- **Improved realloc handling** in get_word() with proper error checking
- **Added memory allocation checks** in tree_builder() function

### Code Robustness
- **Eliminated variable length arrays** that could cause stack overflow with large words
- **Added input validation** to prevent crashes with NULL pointers or invalid input
- **Improved error handling** for memory allocation failures

### Build System
- **Fixed makefile** to properly compile only source files, not headers
- **Added proper dependency tracking** for clean builds

## Technical Details

- **Character Encoding**: ASCII-based (a-z, A-Z)
- **Memory Allocation**: Dynamic with bounds checking
- **Data Structure**: Trie with 27-way branching (26 letters + end marker)
- **Time Complexity**: O(L) per word where L is word length
- **Space Complexity**: O(N×L) where N is number of unique words

## Limitations

- Only handles ASCII alphabetic characters (a-z, A-Z)
- Maximum word length limited by available memory
- Case-insensitive processing only
- No support for Unicode or special characters

## Testing

The program has been tested with:
- Empty input
- Single characters
- Long words
- Mixed case input
- Special characters (filtered out)
- Memory stress scenarios

## License

This project was created as part of a B.Sc Computer Science and Mathematics course. The code is provided for educational purposes
