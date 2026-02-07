*This project has been created as part of the 42 curriculum by rnitta.*

# ft_printf

## Description
**ft_printf** is a re-implements of the standard `printf()` function.

### Goal
- Recode `printf()` from libc
- Learn and practice **variadic functions** (`va_start`, `va_arg`, `va_end`, etc.)

### Supported conversions (Mandatory)
| Specifier | Meaning              |
| --------- | -------------------- |
| `%c`      | character            |
| `%s`      | string               |
| `%p`      | pointer (hex format) |
| `%d`      | signed decimal       |
| `%i`      | signed integer       |
| `%u`      | unsigned decimal     |
| `%x`      | lowercase hex        |
| `%X`      | uppercase hex        |
| `%%`      | percent sign         |

### Supported flag (Bonus)
| flag | Meaning              |
| ---- | -------------------- |
| `-`  | character            |
| `0`  | string               |
| `.`  | pointer (hex format) |
| `#`  | signed decimal       |
| ` `  | signed integer       |
| `+`  | unsigned decimal     |


## Instructions

### Requirements
- C compiler (`cc`, `clang`, or `gcc`)
- `make`

### Build
```sh
make
```


## Resources

### Documantation
- attribute for format specifiers
https://gcc.gnu.org/onlinedocs/gcc/Common-Function-Attributes.html
```
 format (archetype, string-index, first-to-check)

    The format attribute specifies that a function takes printf, scanf, strftime or strfmon style arguments that should be type-checked against a format string. For example, the declaration:

    extern int
    my_printf (void *my_object, const char *my_format, ...)
          __attribute__ ((format (printf, 2, 3)));

    causes the compiler to check the arguments in calls to my_printf for consistency with the printf style format string argument my_format. 
```

### AI Usage
AI was used only for this README.md


## Algorithm and Data Structure
I used static variable for managing a buffer for characters to print.
It is because we can reduce the number of write system call.
