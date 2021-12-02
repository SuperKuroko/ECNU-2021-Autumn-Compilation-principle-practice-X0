%{
    #define var_name_length 10
    #define table_length 1000
    #define pcode_length 200
	#define address_max 2048
	#define stacksize 3000

    #include <stdio.h>
    #include <stdlib.h>
    #include <malloc.h>
    #include <memory.h>
    #include <string.h>
    #include <stdbool.h>

	int table_pointer;
    int pcode_pointer;
    int lev;
    char id[var_name_length];
    int num;

    FILE* fin;    /* input file */
    FILE* ftable; /* the file which store the table output */
    FILE* fpcode;  /* the file which store the pcode output */
    FILE* fout;   /* output file */
    FILE* ferror; /* the file which store the error infomation (if had) */

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
    struct instruction pcode[pcode_length]; /* store pcode array */

	void init();
	void enter(enum object k);
	void _enter(enum object k, int IsArray);
	void setdx(int n);
	void gen(enum fct x, int y, int z);
    void display_table();
    void display_pcode();
    void interpret();
    int base(int l, int* s, int b);
%}

%union{
    int number;
    char* ident;
}

%token PLUS DIV MINUS MUL EQL GEQ LEQ LSS GTR NEQ
%token LP RP LB RB LSB RSB MAIN SEMI IF ELSE READ WRITE WHILE BECOMES

%token <number> NUMBER
%token <ident> IDENT CHAR INT 

%type <number> get_table_addr get_pcode_addr declaration_list VarInit Vardecl Vardef 
%type <number> block var_p var_t prevardecl prevardef pass_factor
%type statement VarInit Vardef condition defunc

%%

main_function
	: MAIN LB declaration_list statement_list RB
	;

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

void init()
{
	table_pointer = 0;
	pcode_pointer = 0l
	lev = 0;
	err = 0;
	total_var = 0;
}

int position(char* a)
{
    int i;
    strcpy(table[0].name, a);
    i = table_pointer;
    while(strcmp(table[i].name, a) != 0) --i;
    return i;
}

void gen(enum fct x, int y, int z)
{
	if (pcode_pointer >= pcode_length)
	{
		printf("Program is too long!\n");
		exit(1);
	}
	if (z >= address_max)
	{
		printf("Displacement address is too big!\n");
		exit(1);
	}
	pcode[pcode_pointer].f = x;
	pcode[pcode_pointer].l = y;
	pcode[pcode_pointer].a = z;
	pcode_pointer++;
}


void display_pcode()
{
	int i;
	char name[][5]=
	{
		{"lit"},{"opr"},{"lod"},{"sto"},{"cal"},{"int"},{"jmp"},{"jpc"},
	};
	
    for (i = 0; i < pcode_pointer; i++)
    {
        printf("%d %s %d %d\n", i, name[code[i].f], code[i].l, code[i].a);
        fprintf(fpcode,"%d %s %d %d\n", i, name[code[i].f], code[i].l, code[i].a);
    }
}

void display_table()
{
	int i;
    /* 输出符号表 */
	printf("tx : %d\n", tx);
	for (i = 1; i <= tx; i++)
		{
            printf("kind : %d\n", table[i].kind);         
			switch (table[i].kind)
			{
				case constant:
					printf("    %d const %s ", i, table[i].name);
					printf("val=%d\n", table[i].val);
					/* fprintf(ftable, "    %d const %s ", i, table[i].name);
					fprintf(ftable, "val=%d\n", table[i].val); */
					break;
				case variable:
					printf("    %d var   %s ", i, table[i].name);
					printf("lev=%d addr=%d ", table[i].level, table[i].adr);
                    if(table[i].t == xint) printf("type = int \n");
                    else printf("type = char \n");
					/* fprintf(ftable, "    %d var   %s ", i, table[i].name);
					fprintf(ftable, "lev=%d addr=%d\n", table[i].level, table[i].adr);
                    */
					break;
				case procedure:
					printf("    %d proc  %s ", i, table[i].name);
					printf("lev=%d addr=%d size=%d\n", table[i].level, table[i].adr, table[i].size);
                    /*
					fprintf(ftable,"    %d proc  %s ", i, table[i].name);
					fprintf(ftable,"lev=%d addr=%d size=%d\n", table[i].level, table[i].adr, table[i].size);
                    */
					break;
			}
		}
		printf("\n");
		/* fprintf(ftable, "\n"); */
}
int main(){
    printf("Input file  ");
    scanf("%s", fname);
    if((fin = fopen(fname, "r")) == NULL)
    {
        printf("open file error!\n");
        exit(1);
    }

	if ((ferror = fopen("error.txt", "w")) == NULL)
  	{
		printf("Can't open the output file!\n");
		exit(1);
	}

	if ((ftable = fopen("table.txt", "w")) == NULL)
	{
		printf("Can't open table.txt file!\n");
		exit(1);
	}	

	if ((fpcode = fopen("code.txt", "w")) == NULL)
	{
		printf("Can't open code.txt file!\n");
		exit(1);
	}		

	if ((fout = fopen("out.txt", "w")) == NULL)
	{
		printf("Can't open out.txt file!\n");
		exit(1);
	}

    redirectInput(fin);
    init();
    yyparse();

	if(err == 0)
	{
		printf("\n===Parsing success!===\n");
		fprintf(ferror, "\n===Parsing success!===\n");

		display_table();
		fclose(ftable);

		display_pcode();
		fclose(fpcode);
		
		interpret();      	
		fclose(fout);
	}
	
  	else
	{
		printf("%d errors in X0 program\n", err);
		fprintf(ferror, "%d errors in X0 program\n", err);
	}

	fclose(fin);
    return 0;
}
