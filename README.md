<p align="center">
  <a href="https://42lyon.fr/">
    <img src="https://github.com/llecoq/hack_the_bias-Hackathon/blob/main/assets/42.jpeg" alt="Hack the bias">
  </a>

  <h2 align="center">ft_printf</h2>

  <p align="center">
    Hack_the_bias Hackathon was held by Codam coding college on March 5th 2021.
    <br>
    It's purpose was to parse a set of data to find some potential bias that could affect the wage (or anything else) of a selected dev population.
    <br>
    This was our team solution to the topic, coded in C.
    <br>
  </p>
</p>


## Table of contents

- [Quick start](#quick-start)
- [What's included](#whats-included)
- [Creators](#creators)


## Quick start

/!\ REPLACE info.csv with your data set /!\

Compile :
```
gcc -Ignl -Ilibft gnl/.c libft/.c parser/* *.c hackaton.h -g3 -fsanitize=address
```
Execute only with countries : 
```
./a.out info.csv C
```
Execute with countries and devtype: 
```
./a.out info.csv D
```
Execute with countries and experience:
```
./a.out info.csv X
```
Execute with countries, experience and devtype:
```
./a.out info.csv E
```

## What's included

```
hack_the_bias-Hackathon
├── README.md
├── assets
│   └── 42.jpeg
├── find_countries.c
├── gnl
│   ├── free_split.c
│   ├── get_next_line.c
│   ├── get_next_line.h
│   └── get_next_line_utils.c
├── hackaton.h
├── key_finder.c
├── libft
│   └── [... personnal C library ...]
├── main.c
├── median_salary.c
├── parser
│   └── parser.c
└── print_data.c
```

## Creators

**grosendo**

- https://github.com/GavrielRosendorn74

**abonnel**

- https://github.com/Anyaa6

**llecoq**

- <https://github.com/llecoq>
