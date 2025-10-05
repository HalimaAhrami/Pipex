
---

# 🧩 Pipex — Mandatory Part

## 📖 Overview

The **Pipex** project aims to help you understand and implement one of the most fundamental UNIX mechanisms — **pipes**.
Your goal is to reproduce the behavior of the following shell command inside your own C program:

```bash
< file1 cmd1 | cmd2 > file2
```

This project teaches process creation, input/output redirection, and inter-process communication using **pipes** and **forks**.

---

## ⚙️ Program Information

| Element                | Description                     |
| ---------------------- | ------------------------------- |
| **Program name**       | `pipex`                         |
| **Files to turn in**   | `Makefile`, `*.c`, `*.h`        |
| **Allowed libraries**  | `libft` (your own)              |
| **Compilation flags**  | `-Wall -Wextra -Werror`         |
| **Executable example** | `./pipex file1 cmd1 cmd2 file2` |

---

## 🧠 Project Description

Your program must reproduce the same behavior as:

```bash
< file1 cmd1 | cmd2 > file2
```

That means:

1. The program reads input from `file1`.
2. It executes `cmd1` using that input.
3. The output of `cmd1` is piped as input to `cmd2`.
4. The result of `cmd2` is written into `file2`.

### Example

```bash
./pipex infile "ls -l" "wc -l" outfile
```

is equivalent to:

```bash
< infile ls -l | wc -l > outfile
```

Another example:

```bash
./pipex infile "grep a1" "wc -w" outfile
```

is equivalent to:

```bash
< infile grep a1 | wc -w > outfile
```

---

## 🔧 Mandatory Requirements

* The program must:

  * Take **4 arguments**: `file1 cmd1 cmd2 file2`
  * Create a **pipe** to connect the two commands.
  * **Fork** child processes for each command.
  * Use **dup2()** to redirect input/output properly.
  * **Wait** for child processes to finish before exiting.
* You must handle errors exactly as the shell would do.
* The program must not crash or leak memory.

---

## 🧰 Allowed Functions

You are allowed to use only the following system functions:

```
open, close, read, write, malloc, free,
perror, strerror, access, dup, dup2,
execve, exit, fork, pipe, unlink,
wait, waitpid
```

You can also use your own implementation of `ft_printf` or equivalent, and your own `libft`.

---

## 🧱 Program Structure (Suggested)

Your program can be divided into logical parts:

| File              | Responsibility                                                |
| ----------------- | ------------------------------------------------------------- |
| **pipex.c**       | Main logic: argument parsing, fork handling, pipes setup      |
| **pipex_utils.c** | Helper functions for path resolution, string operations, etc. |
| **process.c**     | Command execution and redirection                             |
| **error.c**       | Error handling (print error messages, exit codes)             |
| **pipex.h**       | Function prototypes and struct definitions                    |

---

## 🧩 How It Works (Simplified Steps)

1. **Open input and output files**

   * `infile` with `O_RDONLY`
   * `outfile` with `O_CREAT | O_WRONLY | O_TRUNC`
2. **Create a pipe** using `pipe(fd)`.
3. **Fork** two child processes:

   * **First child:** redirects `stdin` from `file1`, and `stdout` to the pipe’s write end.
   * **Second child:** redirects `stdin` from the pipe’s read end, and `stdout` to `file2`.
4. **Execute commands** with `execve()`.
5. **Parent process:** closes all file descriptors and waits for both children using `waitpid()`.

---

## 🚫 Forbidden

* Using global variables.
* Using any other system functions not listed above.
* Using any external libraries other than your own `libft`.

---

## 🧪 Example Execution

### Command:

```bash
./pipex infile "cat -e" "wc -l" outfile
```

### Equivalent shell behavior:

```bash
< infile cat -e | wc -l > outfile
```

### Result:

* `outfile` will contain the number of lines (as counted by `wc -l`) from `infile`.

---

## 🧾 Compilation Example

```bash
make
./pipex file1 "grep test" "wc -l" file2
```

or manually:

```bash
cc -Wall -Wextra -Werror pipex.c pipex_utils.c -o pipex
```

---

## ✅ Evaluation Checklist

| Requirement                         | Status |
| ----------------------------------- | ------ |
| Handles `file1 cmd1 cmd2 file2`     | ✅      |
| No memory leaks                     | ✅      |
| Uses only allowed functions         | ✅      |
| Correct behavior identical to shell | ✅      |
| Proper error handling               | ✅      |

---

## 🧠 Tips for Defense

* Be ready to explain:

  * How `pipe()` and `fork()` work.
  * How file descriptors are duplicated with `dup2()`.
  * How `execve()` replaces the current process image.
  * Why you must close unused ends of the pipe.
* Prepare tests for:

  * Invalid commands.
  * Missing files.
  * Permission denied cases.
  * Empty input.

---

## 📚 Summary

| Aspect       | Description                              |                        |
| ------------ | ---------------------------------------- | ---------------------- |
| Project name | Pipex                                    |                        |
| Language     | C                                        |                        |
| Main concept | UNIX Pipes                               |                        |
| Commands     | `pipe()`, `fork()`, `dup2()`, `execve()` |                        |
| Goal         | Reproduce `< file1 cmd1                  | cmd2 > file2` behavior |
| Errors       | Must handle like the shell               |                        |
| Memory       | No leaks                                 |                        |
| Output       | Identical to shell redirection behavior  |                        |

---

