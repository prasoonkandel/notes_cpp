# Notes Cpp

**Notes Cpp** is a simple terminal-based notes app built with C++.

### Latest Release: v1.0

## Features

- Create a new file if it does not already exist
- Write content to an existing file (overwrite mode)
- Read and display saved file content in the terminal
- List all files currently stored in the notes directory

## Requirements

- Linux/macOS/Windows
- C++17 compatible compiler (`g++` recommended)

## Storage Location

The app stores notes in a folder named `notes_cpp` inside your home directory:

- Linux/macOS: `~/notes_cpp/`
- Windows: `%USERPROFILE%\notes_cpp\`

The base folder is created automatically on first run.

## Usage

Use the main menu to choose one of the following options:

1. Create New File
2. Write File
3. Read File
4. List Files
5. Exit

**Note**: Enter the complete file name, for example `new.txt`, not only `new`.
