%{
    
    #include<stdio.h>
    #include "yacc.h"
    int line;
    char l_buffer[20000];
    int yywrap(void);

    void line_commet();
    void block_commet();
    int yywrap(void);
    int scanch(void);
    int  yygetchar(void);
    void redirectInput(FILE *input);
%}

num [0-9]+
char [A-Za-z]+[A-Za-z0-9]*
strb \"
eq [=]
plus [+]
minus [-]
mul [*]
dev [/]

%%
"main" {return MAIN;}
"int" {return INT;}
"char" {return CHAR;}
"const" {return CONST;}
"if" {return IF;}
"else" {return ELSE;}
"write" {return WRITE;}
"read" {return READ;}
"while" {return WHILE;}
"for" {return FOR;}
"void" {return VOID;}
"return" {return RETURN;}

"["  {return LMB;}
"]" {return RMB;}
[(] {return LP;}
[)] {return RP;}
[{] {return LB;}
[}] {return RB;}
[\n] {++line;}
"!=" {return NEQ;}
">=" {return GEQ;}
"<=" {return LEQ;}
">" {return GTR;}
"<" {return LSS;}
"=" { return EQL;}
"+" { return Plus;}
"-" {return Minus;}
"*" { return Mul;}
[/] { return Div;}
[;] {return SEMI_t;}
[,] {return COMMA;}
{strb} {
        int c;
        int idx = 0;
        memset(l_buffer, 0, sizeof(l_buffer));
        while((c =scanch()) != '"'){
            l_buffer[idx] = c;
            ++idx;
        }
        yylval.VAR = (char*)malloc(strlen(l_buffer) + 1);
        strcpy(yylval.VAR, l_buffer);
        return STRING;
    }
{num} {
    printf("get a num %d\n", atoi(yytext));
    yylval.NUM = atoi(yytext);
    return num;
    }
{char} {yylval.VAR = (char*)malloc(strlen(yytext) + 1);
        strcpy(yylval.VAR, yytext);
         return var;}
"//" {line_commet();}
"/*" {block_commet();}
%%

void redirectInput(FILE *input){
    yyin = input;
}
int  yygetchar(void){
    int ret;
    ret = getc(yyin);
    printf("%c", ret);
    return ret;
}
void line_commet(){
    char c;
    while((c = input()) != '\n'){
    }
    ++line;
}
void block_commet() {
    char c;
    while (1) {
        while ((c = input()) != '*')
            if (c == '\n') ++yylineno;

        if ((c = input()) == '/') break;
        unput(c);
    }
}
int yywrap(void)
{
    return 1;
}
int scanch(void) {
  int c;
  c = input();
  printf("c is %d\n", c);
  if (c == '\\') {
    switch (c = input()) {
      case 'a':  return '\a';
      case 'b':  return '\b';
      case 'f':  return '\f';
      case 'n':  return '\n';
      case 'r':  return '\r';
      case 't':  return '\t';
      case 'v':  return '\v';
      case '\\': return '\\';
      case '"':  return '"' ;
      case '\'': return '\'';
      default:
        printf("unknown escape sequence %c", c);
        exit(1);
    }
  }
  printf("c is %d\n", c);
  return (c);                   // Just an ordinary old character!
}