%{
    #include <stdio.h>
    #include "y.tab.h"
    int line;
    void yyerror(char*);
    int yywrap(void);
%}


%%
[\n]    {++line;}
[\t]	{;}
"main"  {return MAIN;}
"int"   {return INT;}
"char"  {return CHAR;}
"if"    {return IF;}
"else"  {return ELSE;}
"write" {return WRITE;}
"read"  {return READ;}
"while" {return WHILE;}
"for"   {return FOR;}

"="  {return BECOMES;}
"+"  {return PLUS;}
"-"  {return MINUS;}
"*"  {return MUL;}
"("  {return LP;}
")"  {return RP;}
"/"  {return DIV;}
"["  {return LSB;}
"]"  {return RSB;}
"{"  {return LB;}
"}"  {return RB;}

"!=" {return NEQ;}
">=" {return GEQ;}
"<=" {return LEQ;}
">"  {return GTR;}
"<"  {return LSS;}
"==" {return EQL;}
";"  {return SEMI;}

[0-9]+ {
    printf("get a num %d\n", atoi(yytext));
    yylval.num = atoi(yytext);
    return NUM;
}

[A-Za-z]([A-Za-z]|[0-9])* {
    yylval.ident = (char *)malloc(strlen(yytext)+1);
    strcpy(yylval.ident,yytext);
    return IDENT;
}
.	{yyerror("Unknown character!");}

%%
void redirectInput(FILE *input){
    yyin = input;
}
int yygetchar(void){
    int ret;
    ret = getc(yyin);
    printf("%c", ret);
    return ret;
}

void line_commet(){
    char c;
    while(c = input() != '\n'){
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
    //这一函数在文件（或输入）的末尾调用。如果函数的返回值是1，就停止解析
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
        printf("unknown escape sequence %s", c);
        exit(1);
    }
  }
  printf("c is %d\n", c);
  return (c);                   // Just an ordinary old character!
}
