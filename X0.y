%{
    #define var_name_length 10
    #define table_length 1000
    #define instruction_length 200
    #include <stdio.h>
    #include <stdlib.h>
    #include <malloc.h>
    #include <memory.h>
    #include <string.h>
    #include <stdbool.h>

    enum object {
        constant, 
        variable,
        procedure
    };

    struct tablestruct
    {
        char name[var_name_length]; /* char array to store the var name*/
        enum object kind;           /* kind：const，var or procedure */
        int val;                    /* val: only for const var */
        int level;                  /* level: for all except const var */ 
        int adr;                    /* adr: for all except const var */
        int size;                   /* size to alloc, only for procedure */
    };
    struct tablestruct table[table_length]; 

    enum fct 
    {
        lit,     opr,     lod, 
        sto,     cal,     ini, 
        jmp,     jpc,      
    };

    /* vitrual machine instruction struct */
    struct instruction
    {
        enum fct f;   /* the type of instruction */
        int l;        /* the diff between reference level and declaration level */
        int a;        /* depend on the val of f */
    };
    struct instruction code[instruction_length]; /* store pcode array */

    int table_pointer;
    int instruction_pointer;
    int lev;
    char id[var_name_length];
    int num;
    bool pcode_display; /* show pcode switch */
    bool table_display; /* show table switch */

    FILE* fin;    /* input file */
    FILE* ftable; /* the file which store the table output */
    FILE* fcode;  /* the file which store the pcode output */
    FILE* fout;   /* output file */
    FILE* ferror; /* the file which store the error infomation (if had) */

%}

%union{
    int number;
    char* ident;
}

%token PLUS DIV MINUS MUL EQL GEQ LEQ LSS GTR NEQ
%token LP RP LB RB LSB RSB MAIN SEMI IF ELSE READ WRITE WHILE BECOMES

%token <number> NUMBER
%token <ident> IDENT CHAR INT 

%type <number> get_table_addr get_code_addr declaration_list VarInit Vardecl Vardef 
%type <number> block var_p var_t prevardecl prevardef pass_factor
%type statement VarInit Vardef condition defunc

%%

main_function: MAIN LB declaration_list statement_list RB;

declaration_list
	: declaration_list declaration_stat 
    | declaration_stat
    |
    ;

declaration_stat
	: type IDENT SEMI 
    | type IDENT LSB NUMBER RSB SEMI
    ;

type
	: INT
    | CHAR
    ;

var	
	: IDENT 
    | IDENT LSB expression RSB
    ;

statement_list
	: statement_list statement
    |
    ;

statement
	: if_stat 
    | while_stat 
    | read_stat 
    | write_stat 
    | compound_stat 
    | expression_stat
    ;

if_stat
	: IF LP expression RP statement 
    | IF LP expression RP statement ELSE statement
    ;

while_stat
	: WHILE LP expression RP statement
    ;

write_stat
	: WRITE expression SEMI
    ;

read_stat
	: READ var SEMI
    ;

compound_stat
	: LB statement_list RB
    ;

expression_stat
	: expression SEMI 
    | SEMI
    ;

expression
	: var BECOMES expression 
    | simple_expr
    ;

simple_expr
	: additive_expr 
    | additive_expr NEQ additive_expr
    | additive_expr GEQ additive_expr
    | additive_expr LEQ additive_expr
    | additive_expr GTR additive_expr
    | additive_expr LSS additive_expr
    | additive_expr EQL additive_expr
    ;


declaration_list
	: declaration_list declaration_stat 
    | declaration_stat
    |
    ;

additive_expr
	: term 
    | additive_expr PLUS term 
    | additive_expr MINUS term 
    ;


term
	: factor
    | term MUL factor
    | term DIV factor
    ;

factor
	: LP expression RP 
    | var 
    | NUMBER
    ;

%%

yyerror(const char *s){
    printf("error!:%s\n, located at %d line\n", s, line);
}

int main(){
    printf("Input file  ");
    scanf("%s", fname);
    if((fin = fopen(fname, "r")) == NULL)
    {
        printf("open file error!\n");
        exit(1);
    }
    /* if ((foutput = fopen("foutput.txt", "w")) == NULL)
    {
    printf("Can't open the output file!\n");
    exit(1);
  }
  if ((ftable = fopen("ftable.txt", "w")) == NULL)
  {
    printf("Can't open ftable.txt file!\n");
    exit(1);
  }
    */
    redirectInput(fin);
    init();

    yyparse();
    displaytable();
    listall();
    interpret();
    fclose(fin);
    /* fclose(ftable);
    fclose(foutput);
    */
    return 0;
}
