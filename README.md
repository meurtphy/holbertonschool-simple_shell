![flowchart](/img/flowchart.png)



# Simple Shell
This project is a simple implementation of a shell in C. It allows you to execute basic commands, manage environment variables, and handle the `exit` command. The shell is designed to be lightweight, easy to understand, and modular.
---
## Features
The shell supports the following features:
1. **Command Execution**:
   - The shell can execute simple commands using `fork`, `execve`, and `wait`.
   - It handles commands with arguments (e.g., `ls -l`).
2. **Path Resolution**:
   - The shell resolves the full path of executables using the `PATH` environment variable.
   - If a command is provided with an absolute path (e.g., `/bin/ls`), the shell executes it directly.
3. **`exit` Command**:
   - The shell handles the `exit` command to terminate the program.
   - It supports an optional exit status (e.g., `exit 98`).
4. **Environment Variables**:
   - The shell can display environment variables using the `env` command.
5. **Command Cleaning**:
   - The shell cleans commands by removing unnecessary spaces (e.g., `ls    -l` becomes `ls -l`).
6. **Interactive and Non-Interactive Modes**:
   - The shell works in interactive mode (with a `$` prompt) and non-interactive mode (when receiving commands from a file or pipe).
---
## Usage
### Compilation
To compile the project, use the following command:
```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o shell
Author: Erwan Pasqier and Matteo Foti