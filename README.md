# simple-compiler

Compiler for C- language, a simplified C

## Installation instructions

This project uses flex to construct the necessary
minimized deterministic finite automata

To install it on Ubuntu:
```bash
sudo apt-get install flex
```
or, if you're on Mac:
```bash
brew install flex
```


## For contributors

We use clang-format as linter for the project. It may
be necessary:
```bash
sudo apt-get install clang-format
```
or, if you're on Mac:
```bash
brew install clang-format
```

## Execution

To generate the compiler, run:
```bash
make all
```

