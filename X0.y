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
	char fname[20];
    char id[var_name_length];
    int num;
	int array_size;
	int err;
	int var_cnt;
	int var_size;
	int line;

    FILE* fin = NULL;     /* input file */
    FILE* ftable = NULL;  /* the file which store the table output */
    FILE* fpcode = NULL;  /* the file which store the pcode output */
    FILE* fout = NULL;    /* output file */
    FILE* fmistake = NULL;  /* the file which store the error infomation (if had) */

    enum object 
	{
        variable,
		array,
        procedure
    };

	enum xtype
	{
		X0_int,
		X0_char
	};

    struct tablestruct
    {
        char name[var_name_length]; /* char array to store the var name*/
        enum object kind;           /* kind：const，var or procedure */
        int level;                  /* level: for all except const var */ 
        int adr;                    /* adr: for all except const var */
        int size;                   /* size to alloc, only for procedure */
		enum xtype X0_type;         /* only for var or const */
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
	void table_add(enum object item);
	void set_address(int n);
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

%type <number> get_pcode_addr get_table_addr type

%%

main_function
	:
	get_pcode_addr
	{
		gen(jmp, 0 ,0);
	} 
	MAIN
	{
		pcode[$1].a = pcode_pointer;
	}
	LB 
	declaration_list
	{
		set_address(var_cnt);
		gen(ini, 0 ,var_size+3);
	}
	statement_list RB
	;

get_pcode_addr
	:
	{
		$$ = pcode_pointer;
	}
	;

get_table_addr
	:
	{
		$$ = table_pointer;
	}
	;

declaration_list
	: declaration_list declaration_stat 
    | declaration_stat
    |
    ;

declaration_stat
	: type IDENT SEMI 
	{
		var_size++;
		var_cnt++;
		strcpy(id, $2);
		table_add(variable);
		if($1 == 1) table[table_pointer].X0_type = X0_int;
		else table[table_pointer].X0_type = X0_char;
	}
    | type IDENT LSB NUMBER RSB SEMI
	{
		var_cnt++;
		var_size += $4;
		strcpy(id, $2);
		table_add(array);
		table[table_pointer].size = $4;
		if($1 == 1) table[table_pointer].X0_type = X0_int;
		else table[table_pointer].X0_type = X0_char;
	}
    ;

type
	: INT {$$ = 1;}
    | CHAR {$$ = 2;}
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

void yyerror(const char *s){
    printf("error!:%s\n, located at %d line\n", s, line);
}

void init()
{
	table_pointer = 0;
	pcode_pointer = 0;
	lev = 0;
	err = 0;
	var_cnt = 0;
	var_size = 0;
}

int position(char* a)
{
    int i;
    strcpy(table[0].name, a);
    i = table_pointer;
    while(strcmp(table[i].name, a) != 0) --i;
    return i;
}

void table_add(enum object item)
{
	table_pointer++;
	printf("id = %s\n",id);
	strcpy(table[table_pointer].name, id);
	printf("name = %s\n",table[table_pointer].name);
	table[table_pointer].kind = item;
	switch(item)
	{
		case variable:
			table[table_pointer].level = lev;
			table[table_pointer].size = 1;
			break;
		case array:
			table[table_pointer].level = lev;
			break;
		case procedure:
			break;
	}
}

void set_address(int n)
{
	int i,idx;
	int tar = 3+var_size;
	for(i = 1;i <= n;i++)
	{
		idx = table_pointer - i + 1;
		tar -= table[idx].size;
		table[idx].adr = tar;
	}
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
        printf("%d %s %d %d\n", i, name[pcode[i].f], pcode[i].l, pcode[i].a);
        fprintf(fpcode,"%d %s %d %d\n", i, name[pcode[i].f], pcode[i].l, pcode[i].a);
    }
}

void display_table()
{
	int i;
	char map[][5] = {{"int "},{"char"}};
    printf("num    name    kind      level  address  size\n");
	for (i = 1; i <= table_pointer; i++)
	{   
		switch (table[i].kind)
		{
			case variable:
				printf("%3d     %s     var:%s    %2d      %3d    %3d\n",i,table[i].name,map[table[i].X0_type],table[i].level,table[i].adr,table[i].size);
				fprintf(ftable, "%3d     %s     var:%s    %2d      %3d    %3d\n",i,table[i].name,map[table[i].X0_type],table[i].level,table[i].adr,table[i].size);
				break;

			case array:
				printf("%3d     %s     ary:%s    %2d      %3d    %3d\n",i,table[i].name,map[table[i].X0_type],table[i].level,table[i].adr,table[i].size);
				fprintf(ftable, "%3d     %s     ary:%s    %2d      %3d    %3d\n",i,table[i].name,map[table[i].X0_type],table[i].level,table[i].adr,table[i].size);
				break;

			case procedure:
				/*
				printf("    %d proc  %s ", i, table[i].name);
				printf("lev=%d addr=%d size=%d\n", table[i].level, table[i].adr, table[i].size);

				fprintf(ftable,"    %d proc  %s ", i, table[i].name);
				fprintf(ftable,"lev=%d addr=%d size=%d\n", table[i].level, table[i].adr, table[i].size);
				*/
				break;
		}
	}
	printf("\n");
	fprintf(ftable, "\n");
}

void interpret()
{

}

int main(){
    printf("Input file  ");
	strcpy(fname,"test.txt");
    //scanf("%s", fname);
    if((fin = fopen(fname, "r")) == NULL)
    {
        printf("open file error!\n");
        exit(1);
    }

	if ((fmistake= fopen("error.txt", "w")) == NULL)
  	{
		printf("Can't open the error.txt file!\n");
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
		fprintf(fmistake, "\n===Parsing success!===\n");

		display_pcode();
		fclose(fpcode);

		display_table();
		fclose(ftable);
		
		interpret();      	
		fclose(fout);
	}

  	else
	{
		printf("%d errors in X0 program\n", err);
		fprintf(fmistake, "%d errors in X0 program\n", err);
	}

	fclose(fin);
    return 0;
}
