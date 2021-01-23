# ft_printf

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/07483a7ff4ec4de497d8cdfb509dd3bc)](https://www.codacy.com/manual/jebae/ft_printf?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=jebae/ft_printf&amp;utm_campaign=Badge_Grade)

This project is made to school project. 

<br><br>

## Requirements

This library is using [libft](https://github.com/jebae/libft), [libbigint](https://github.com/jebae/libbigint) and [libfixedpoint](https://github.com/jebae/libfixedpoint).

```
# download libft
git clone https://github.com/jebae/libft.git

# download libbigint
git clone https://github.com/jebae/libbigint.git

# download libfixedpoint
git clone https://github.com/jebae/libfixedpoint.git

# directory structure of libft and libbigint
root/
  libft/
  libbigint/
  libfixedpoint/
  ft_printf/
```

Instead of put required libraries as above, you can modify [Makefile](./Makefile) with macro below.

```
LIBFT_PATH = $(LIBDIR)/libft

LIBBIGINT_PATH = $(LIBDIR)/libbigint

LIBFIXEDPOINT_PATH = $(LIBDIR)/libfixedpoint
```

<br><br>

## Installation

```
make
```

Built library name is `libftprintf.a`

<br><br>

## Features

`ft_printf` is supporting mandatory part of `printf` in `stdio.h`.

**specifier**

| specifier| description|
|---------|----------------------------------------------------|
| d  or i | Signed decimal integer|
| u       | Unsigned decimal integer|
| o       | Unsigned octal|
| x       | Unsigned hexadecimal integer|
| X       | Unsigned hexadecimal integer (uppercase)|
| f       | Decimal floating point, lowercase|
| e       | Scientific notation (mantissa/exponent), lowercase|
| s       | String of characters|
| c       | Character|
| p       | Pointer address|
| %       | % character|

<br>

**flags**

| flags | description |
|-------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| +     | Forces to preceed the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a - sign.|
| space | If no sign is going to be written, a blank space is inserted before the value.|
| #     | Used with o, x or X specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero. Used with e, f it forces the written output to contain a decimal point even if no more,digits follow. By default, if no digits follow, no decimal point is written.|
| 0     | Left-pads the number with zeroes (0) instead of spaces when padding is specified|

<br>

**width**

|width|description|
|-----|----------|
|number|Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger.|
|*|The width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.|

<br>

**precision**

|precision|description|
|---------|-----------|
|number|For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. <br> For e, f specifiers: this is the number of digits to be printed after the decimal point (by default, this is 6). <br> For s: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered.|
|*|The precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.|

<br>

**length**

|length|d i|u o x X|f e|s
|------|-----------|--------|--------|-------|
|hh|char|unsigned char|||
|h|short|unsigned short|||
|l|long|unsigned long||wchar_t *|
|ll|long long| unsigned long long|||
|L|||long double||