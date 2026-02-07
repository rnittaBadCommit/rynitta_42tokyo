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
- Unix-like environment

### Build
```sh
make
```


## Resources

