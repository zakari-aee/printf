*This project has been created as part of the 42 curriculum by zallioua.*

# ft_printf

## Description

ft_printf is my own version of the C `printf()` function. I rebuilt it to learn how variadic functions work: functions that can take any number of arguments. It compiles into `libftprintf.a`.

## Instructions

```sh
make          # build libftprintf.a
make clean    # remove the .o files
make fclean   # remove the .o files and libftprintf.a
make re       # rebuild everything
```

To use it:

```c
#include "ft_printf.h"

ft_printf("Hello %s, you are %d\n", "Zakariae", 21);
```

```sh
cc -Wall -Wextra -Werror main.c libftprintf.a
```

## How it works

`ft_printf` reads the format string one character at a time:

1. A normal character is printed with `write`.
2. A `%` followed by a letter calls `ft_format`, which reads the next argument with `va_arg` and calls the right print function.
3. Every print function returns how many characters it printed, and `ft_printf` adds them up to get its return value.

The format string is what tells the function how many arguments there are and what type each one is.

A few choices I made:

- One small function per conversion, so the code is easy to read and easy to extend.
- I pass `&args` to `ft_format` so the argument cursor keeps moving correctly.
- `%c` is read as `int`, because a `char` is promoted to `int` when passed through `...`.
- `%p` is cast to `unsigned long`, because an address is 8 bytes and never negative.
- `ft_print_nums` uses a `long`, so `INT_MIN` works.
- Numbers are printed with recursion (`n / base` first, then `n % base`), so the digits come out in the right order without a buffer.
- One function, `ft_print_hex`, handles `%x`, `%X` and `%p` by taking the base as a string.
- No `malloc`, so no leaks.
- If a `write` fails, `ft_printf` returns `-1`, like the original.
- On undefined behavior it never crashes: a `NULL` format or a lone `%` at the end returns `-1`, and an unknown conversion like `%k` is printed as is.

## Conversions

| Conversion | What it prints |
|---|---|
| `%c` | a character |
| `%s` | a string (`(null)` if `NULL`) |
| `%p` | a pointer in hexadecimal (`(nil)` if `NULL`) |
| `%d` | a signed decimal number |
| `%i` | a signed decimal number |
| `%u` | an unsigned decimal number |
| `%x` | a number in lowercase hexadecimal |
| `%X` | a number in uppercase hexadecimal |
| `%%` | a `%` sign |

## Files

| File | What it does |
|---|---|
| `ft_printf.c` | the main loop and `ft_format` |
| `ft_print_char.c` | prints `%c` |
| `ft_print_s.c` | prints `%s` |
| `ft_print_nums.c` | prints `%d` and `%i` |
| `ft_print_unsigned.c` | prints `%u` |
| `ft_print_hex.c` | prints `%x`, `%X` and the hex part of `%p` |
| `ft_print_ptr.c` | prints `%p` |
| `ft_printf.h` | the prototypes |

## Resources

- `man 3 printf` and `man 3 stdarg`
- The 42 Norm
- Stack Overflow, GeeksforGeeks and Google, for C concepts and examples
- YouTube, for visual and deeper explanations
- AI, to deep more and practicing new things