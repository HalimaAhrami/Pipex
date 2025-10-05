
---

# 🧩 Pipex — Mandatory Part

## 📖 Overview

**Pipex** is a project designed to help you understand how data is passed between processes in Unix systems using **pipes** and **file descriptors**.
You will recreate the behavior of this shell command:

```
< infile cmd1 | cmd2 > outfile
```

Your program will read from a file, execute two commands connected by a pipe, and write the output to another file.

---

## 🎯 Objectives

* Learn how to handle **files** (`open`, `close`)
* Create and manage **processes** (`fork`)
* Connect processes through **pipes**
* Redirect **input and output** using `dup2`
* Execute commands with `execve`
* Manage **PATH** environment variable
* Handle **errors** and **memory management** properly

---

## 🧱 Program Structure

The program must be executed as follows:

```
./pipex infile cmd1 cmd2 outfile
```

It must produce the same output as this shell command:

```
< infile cmd1 | cmd2 > outfile
```

---

## ⚙️ How It Works

1. The program opens the input file (`infile`) for reading.
2. It executes the first command (`cmd1`) and redirects its output to the pipe.
3. It executes the second command (`cmd2`) and redirects its input from the pipe.
4. The final output is written into the output file (`outfile`).
5. All file descriptors must be properly closed, and no memory leaks should occur.

---

## 🧠 Technical Details

* The program must use **one pipe** only.
* Each command must be executed in a **separate child process** created with `fork`.
* Redirections are done using `dup2()` to map standard input/output to files or pipes.
* The program must find the **absolute path** of each command by parsing the `PATH` environment variable.
* It should handle **invalid commands** or **file access errors** gracefully.

---

## 🧩 Handling PATH

To execute a command like `ls`, your program must search for it inside the directories listed in the `PATH` environment variable, for example:

```
/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin
```

The first accessible executable file found should be used.

---

## ✅ Allowed Functions

You are allowed to use the following system calls and library functions:

`open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `access`, `dup`, `dup2`, `execve`, `exit`, `fork`, `pipe`, `unlink`, `wait`, `waitpid`

Additionally, you **may use your own Libft** library.

---

## 🚫 Forbidden

* `get_next_line`
* `printf` or any external library functions
* `system()`, `popen()`, or similar functions
* Global variables

---

## 🧾 Compilation

Your Makefile must include the following rules:

* `NAME`
* `all`
* `clean`
* `fclean`
* `re`

Compilation flags:

```
-Wall -Wextra -Werror
```

Unnecessary relinking is not allowed.

---

## 🧪 Example Usage

| Command                                       | Equivalent Shell Command |                  |
| --------------------------------------------- | ------------------------ | ---------------- |
| `./pipex infile "ls -l" "wc -l" outfile`      | `< infile ls -l          | wc -l > outfile` |
| `./pipex infile "grep hello" "wc -w" outfile` | `< infile grep hello     | wc -w > outfile` |

---

## ⚡ Error Handling

Your program must:

* Display an error message (via `perror` or `strerror`) when a file or command cannot be accessed.
* Exit gracefully without segmentation faults or crashes.
* Avoid any memory leaks or file descriptor leaks.

---

## 🧩 Execution Flow Summary

1. Check if the correct number of arguments is provided.
2. Open `infile` and `outfile`.
3. Create a pipe.
4. Fork a child process to execute `cmd1`.
5. Fork another child process to execute `cmd2`.
6. Close all file descriptors in the parent process.
7. Wait for both child processes to finish (`waitpid`).

---

## 🧭 Summary Table

| Item              | Description                                            |
| ----------------- | ------------------------------------------------------ |
| Program name      | `pipex`                                                |
| Commands handled  | 2                                                      |
| Pipes used        | 1                                                      |
| Input → Output    | `infile` → `cmd1` → `cmd2` → `outfile`                 |
| Allowed functions | Listed system calls + Libft                            |
| Forbidden         | `get_next_line`, `printf`, `system`                    |
| Goal              | Reproduce pipe and process behavior of a shell command |

---

## 🔍 Tips for Evaluation

* Ensure no **memory leaks** (check with `valgrind`).
* Always **close** unused file descriptors.
* Match shell behavior exactly — test your program with different files and commands.
* Be ready to explain every system call you used (`fork`, `pipe`, `dup2`, etc.) during the evaluation.
* Use meaningful error messages for invalid commands or missing files.

---
