#!/bin/bash
bison -d X0.y
flex X0.l
gcc lex.yy.c x0.tab.c -o X0.exe
