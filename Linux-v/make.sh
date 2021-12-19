#!/bin/bash
yacc -d X0.y
lex X0.l
cc lex.yy.c y.tab.c -o X0
