%{
    #include <stdio.h>
    #include "y.tab.h"
    int line;
    void yyerror(char*);
    int yywrap(void);
    void redirectInput(FILE *input);
    void line_commet();
    void block_commet();
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
"%"  {return PER;}

"!=" {return NEQ;}
">=" {return GEQ;}
"<=" {return LEQ;}
">"  {return GTR;}
"<"  {return LSS;}
"==" {return EQL;}
";"  {return SEMI;}

"//" {line_commet();}
"/*" {block_commet();}

[0-9]+ {
    yylval.number = atoi(yytext);
    return NUMBER;
}

[A-Za-z]([A-Za-z]|[0-9])* {
    yylval.ident = (char *)malloc(strlen(yytext)+1);
    strcpy(yylval.ident,yytext);
    return IDENT;
}

%%
void redirectInput(FILE *input){
    yyin = input;
}

int yygetchar(void)
{
    int ret;
    ret = getc(yyin);
    printf("%c", ret);
    return ret;
}

void line_commet()
{
    char c;
    while(c = input() != '\n'){}
    ++line;
}

void block_commet() {
    char c;
    while (1) 
    {
        while ((c = input()) != '*')
            if (c == '\n') 
                ++line;
                
        if ((c = input()) == '/') break;
        unput(c);
    }
}


int yywrap(void)
{
    //这一函数在文件（或输入）的末尾调用。如果函数的返回值是1，就停止解析
    return 1;
}


