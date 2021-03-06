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
	char bug[100];
	char fname[20];
    char id[var_name_length];
	char function_name[var_name_length];
	int err;
	int var_cnt;
	int var_size;
	int line;
	bool is_write;
	bool is_return;
	bool has_return;
	int pidx;
    FILE* fin = NULL;    
    FILE* ftable = NULL; 
    FILE* fpcode = NULL; 
    FILE* fout = NULL;    
    FILE* fmistake = NULL;  

    enum object 
	{
        variable,
		array,
        function
    };
	enum object Kind;

	enum xtype
	{
		X0_int,
		X0_char,
		X0_bool
	};
	enum xtype xt;

    struct tablestruct
    {
        char name[var_name_length]; 
        enum object kind;           
        int adr;                   
        int size;
		int count;                   
		enum xtype X0_type;
		char master[var_name_length];
    };
    struct tablestruct table[table_length]; 

    enum fct 
    {
        lit,     opr,     lod, 
        sto,     cal,     ini, 
        jmp,     jpc,     pop,
		ast,     ald,     stv,
    };

    struct instruction
    {
        enum fct f;   
        int l;        
        int a;        
    };
    struct instruction pcode[pcode_length];

	void init();
	void table_add(enum object item, int type_id, int size);
	void set_address(int n);
	void gen(enum fct x, int y, int z);
    void display_table();
    void display_pcode();
    void interpret();
	void reset();
	void myerror();
	int position_fun(char* a);
%}

%union{
    int number;
    char* ident;
}

%token PLUS DIV MINUS MUL EQL GEQ LEQ LSS GTR NEQ CHAR INT BOOL PER XOR OR AND NOT ODD COMMA
%token LP RP LB RB LSB RSB MAIN SEMI IF ELSE READ WRITE WHILE BECOMES TRUE FALSE FOR RETURN 
 

%token <number> NUMBER
%token <ident> IDENT 

%type <number> type var pcode_register table_register for_exp1 for_exp2 for_exp3 parameters

%%

main_function
	:
	pcode_register
	{
		gen(jmp, 0, 0);
	} 
	def_function
	MAIN
	{
		strcpy(function_name,"main");
		strcpy(id, "main");
		table_add(function, 0, 0);
		table[table_pointer].adr = pcode_pointer;
		pcode[$1].a = pcode_pointer;
		reset();
	} table_register
	LB 
	declaration_list
	{
		table[$6].size = var_size;
		table[$6].count = var_cnt;
		set_address(var_cnt);
		gen(ini, 0 ,var_size+3);
	}
	statement_list RB
	{
		gen(opr, 0, 0);
	}
	;

def_function
	: type IDENT LP 
	{
		strcpy(function_name,$2);
		strcpy(id, $2);
		table_add(function, $1, 0);
		table[table_pointer].adr = pcode_pointer;
		reset();
	}table_register parameters RP
	LB declaration_list
	{
		table[$5].size = var_size;
		table[$5].count = var_cnt;
		set_address(var_cnt);
		gen(ini, 0 ,var_size+3);
	} statement_list
	RB 
	{
		if(has_return == false)
		{
			gen(opr, 1 , 0);
		}
	}def_function
	| 
	;

parameters
	: type IDENT 
	{
		var_size++;
		var_cnt++;
		strcpy(id, $2);
		table_add(variable, $1, 1);
	} parameter
	| {}
	;

parameter
	: COMMA type IDENT 
	{
		var_size++;
		var_cnt++;
		strcpy(id, $3);
		table_add(variable, $2, 1);
	} parameter
	|
	;

call_parameters
	: expression 
	{
		gen(sto, 1, pidx);
		gen(pop, 0 , 1);
		pidx++;
	} call_parameter
	| {}
	;

call_parameter
	: COMMA expression 
	{
		gen(sto, 1, pidx);
		gen(pop, 0 , 1);
		pidx++;
	}call_parameter
	| {}
	;
	    
return_stat
	: RETURN
	{
		if(strcmp(function_name,"main") == 0) yyerror("can't use return in main function");
		is_return = true;
		has_return = true;
	} expression_stat
	;

pcode_register
	:
	{
		$$ = pcode_pointer;
	}
	;

table_register
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
		table_add(variable, $1, 1);
	}
    | type IDENT LSB NUMBER RSB SEMI
	{
		var_cnt++;
		var_size += $4;
		strcpy(id, $2);
		table_add(array, $1, $4);
	}
    ;

type
	: INT {$$ = 0;}
    | CHAR {$$ = 1;}
	| BOOL {$$ = 2;}
    ;

var	
	: IDENT 
	{
		$$ = position($1);
		if(table[$$].kind == array) yyerror("can't use array directly");
		if(table[$$].kind == function) yyerror("can't use function directly");
		xt = table[$$].X0_type;
		Kind = table[$$].kind;
		printf("%s: %d",$1,Kind);
	}
    | IDENT LSB expression RSB
	{
		$$ = position($1);
		if(table[$$].kind == variable) yyerror("can't use variable with []");
		if(table[$$].kind == function) yyerror("can't use function with []");
		xt = table[$$].X0_type;
		Kind = table[$$].kind;
		gen(lit, 0, table[$$].adr);
		gen(opr, 0, 2);
	}
	| IDENT 
	{
		pidx = 3;
	}LP call_parameters RP 
	{
		$$ = position_fun($1);
		if(table[$$].kind != function) myerror("%s is not a function",$1);
		Kind = table[$$].kind;
		has_return = false;
		gen(cal, 0, table[$$].adr);
	}

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
	| for_stat
    | expression_stat
	| return_stat
	| SEMI
    ;

if_stat
	:
    IF LP expression RP pcode_register
	{
		gen(jpc, 0, 0);
	}statement pcode_register
	{
		gen(jmp, 0, 0);
		pcode[$5].a = pcode_pointer;
	}
	else_stat
	{
		pcode[$8].a = pcode_pointer;
	}
    ;

else_stat
	: ELSE statement
	|
	;
	
while_stat
	: WHILE LP pcode_register expression RP pcode_register
	{
		gen(jpc, 0, 0);
	} 
	 statement
	{
		gen(jmp, 0, $3);
		pcode[$6].a = pcode_pointer;
	}
    ;
	
for_stat
	: FOR LP for_exp1 SEMI
	{
		if($3 == 0) gen(pop, 0, 1);
	} pcode_register for_exp2 SEMI pcode_register  
	{
		gen(jpc, 0, 0);
		gen(jmp, 0, 0);
	}
 	for_exp3  
	{
		if($11 == 0) gen(pop, 0, 1);
		gen(jmp, 0, $6);
	}
    RP pcode_register statement
	{
		gen(jmp, 0, $9+2);
		pcode[$9].a = pcode_pointer;
		pcode[$9+1].a = $14;
	}
	;

for_exp1
	: expression {$$ = 0;}
    | {$$ = 1;}
    ;

for_exp2
	: simple_expr {$$ = 0;}
    | {$$ = 1;}
    ;

for_exp3
	: expression {$$ = 0;}
    | {$$ = 1;}
    ;

write_stat
	: WRITE 
	{
		is_write = true;
	}expression_stat
    ;

read_stat
	: READ var SEMI
	{
		gen(opr, xt, 16);
		if(Kind == array) gen(ast, 0, 0);
		else if(Kind == variable) gen(sto, 0, table[$2].adr);
		else yyerror("can't read a function");
		gen(pop, 0 ,1);
	}
    ;

compound_stat
	: LB statement_list RB
    ;

expression_stat
	: expression SEMI
	{
		if(is_write)
		{
			gen(opr, xt, 14);
			gen(opr, 0, 15);
			is_write = false;
		}
		if(is_return)
		{
			gen(stv, 0, 0);
			gen(opr, 1, 0);
			Kind = function;
			is_return = false;
		}
		gen(pop, 0, 1);
	}
    ;

expression
	: var BECOMES expression 
	{
		if(Kind == array) gen(ast, 0, 0);
		else if (Kind == variable) gen(sto, 0, table[$1].adr);
		else yyerror("can't allocate a value to a function");
	}
    | simple_expr
    ;



simple_expr
	: logic_expr
	| logic_expr EQL logic_expr
	{
		gen(opr, 0, 8);
	}
    | logic_expr NEQ logic_expr
	{
		gen(opr, 0, 9);
	}
	| logic_expr LSS logic_expr
	{
		gen(opr, 0, 10);
	}
    | logic_expr GEQ logic_expr
	{
		gen(opr, 0, 11);
	}
	| logic_expr GTR logic_expr
	{
		gen(opr, 0, 12);
	}
    | logic_expr LEQ logic_expr
	{
		gen(opr, 0, 13);
	}
    ;


logic_expr
	: additive_expr
	| NOT additive_expr
	{
		gen(opr, 0, 19);
	}
	| logic_expr AND additive_expr
	{
		gen(opr, 0, 18);
	}
	| logic_expr OR additive_expr
	{
		gen(opr, 1, 18);
	}
	| logic_expr XOR additive_expr
	{
		gen(opr, 2, 18);
	}

additive_expr
	: term 
	| ODD term
	{
		gen(opr, 0, 20);
	}
    | additive_expr PLUS term 
	{
		gen(opr, 0, 2);
	}
    | additive_expr MINUS term 
	{
		gen(opr, 0, 3);
	}
    ;

term
	: factor
    | term MUL factor
	{
		gen(opr, 0, 4);
	}
    | term DIV factor
	{
		gen(opr, 0, 5);
	}
	| term PER factor
	{
		gen(opr, 0, 17);
	}
    ;

factor
	: LP expression RP 
    | var
	{
		if(Kind == array) gen(ald, 0 ,0);
		else if(Kind == variable) gen(lod, 0, table[$1].adr);
	}
    | NUMBER
	{
		gen(lit, 0, $1);
	}
	| TRUE
	{
		gen(lit, 0 ,1);
	}
	| FALSE
	{
		gen(lit, 0, 0);
	} 
    ;

%%

void yyerror(const char *s){
	err++;
	printf("error:%s! located at %d line\n", s, line);
	fprintf(fmistake, "error:%s! located at %d line\n", s, line);
}

void myerror(const char *s, const char *a)
{
	sprintf(bug,s,a);
	yyerror(bug);
}

void init()
{
	table_pointer = 0;
	pcode_pointer = 0;
	err = 0;
	var_cnt = 0;
	var_size = 0;
	is_write = false;
	is_return = false;
	has_return = false;
	line = 1;
}

void reset()
{
	var_cnt = 0;
	var_size = 0;
}

int position(char* a)
{
    int i;
    strcpy(table[0].name, a);
	strcpy(table[0].master, function_name);
    i = table_pointer;
    while(strcmp(table[i].name, a) != 0 || strcmp(table[i].master,function_name)) --i;
	if(i == 0) myerror("%s is not declared",a);
    return i;
}

int position_fun(char* a)
{
    int i;
    strcpy(table[0].name, a);
    i = table_pointer;
    while(strcmp(table[i].name, a) != 0) --i;
	if(i == 0) myerror("%s function is not declared",a);
    return i;
}

void table_add(enum object item, int type_id, int size)
{
	enum xtype map[3] = {X0_int, X0_char, X0_bool};
	table_pointer++;
	strcpy(table[table_pointer].name, id);
	strcpy(table[table_pointer].master, function_name);
	table[table_pointer].kind = item;
	table[table_pointer].size = size;
	table[table_pointer].X0_type = map[type_id];
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
		{"lit"},{"opr"},{"lod"},{"sto"},{"cal"},{"ini"},{"jmp"},{"jpc"},{"pop"},{"ast"},{"ald"},{"stv"}
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
	char m1[][5] = {{"int "},{"char"},{"bool"}};
	char m2[][10] = {{"variable"},{"  array "},{"function"}};
    printf("num    name       kind       type     master   address   size\n");
	
	for (i = 1; i <= table_pointer; i++)
	{   
		if(table[i].kind == function && i > 1)
		{
			printf("\n",table[i].name);
			fprintf(ftable,"\n",table[i].name);
		}
		printf("%2d     %4s     %s     %s     %4s      %3d      %3d\n",i,table[i].name,m2[table[i].kind],m1[table[i].X0_type],table[i].master,table[i].adr,table[i].size);
		fprintf(ftable,"%2d     %4s     %s     %s     %4s      %3d      %3d\n",i,table[i].name,m2[table[i].kind],m1[table[i].X0_type],table[i].master,table[i].adr,table[i].size);
	}
	printf("\n");
	fprintf(ftable, "\n");
}

void interpret()
{
	int p = 0; /* ???????????? */
	int b = 1; /* ???????????? */
	int t = 0; /* ???????????? */
	struct instruction i;
	int s[stacksize];	

	printf("Start X0\n");
	fprintf(fout,"Start X0\n");
	s[0] = 0; /* s[0]?????? */
	s[1] = 0; /* SL */
	s[2] = 0; /* DL */
	s[3] = 0; /* RA */
	do {
	    i = pcode[p];	
		p = p + 1;      
		switch (i.f)
		{
			case pop:
				t = t - i.a;
				break;
			case lit:	
				t = t + 1;
				s[t] = i.a;				
				break;
			case opr:	
				switch (i.a)
				{
					case 0:  
						t = b - 1;
						p = s[t + 3];
						b = s[t + 2];
						t += i.l;
						break;
					case 1:
						s[t] = - s[t];
						break;
					case 2: 
						t = t - 1;
						s[t] = s[t] + s[t + 1];
						break;
					case 3:
						t = t - 1;
						s[t] = s[t] - s[t + 1];
						break;
					case 4:
						t = t - 1;
						s[t] = s[t] * s[t + 1];
						break;
					case 5:
						t = t - 1;
						s[t] = s[t] / s[t + 1];
						break;
					case 6:
						s[t] = s[t] % 2;
						break;
					case 8:
						t = t - 1;
						s[t] = (s[t] == s[t + 1]);
						break;
					case 9:
						t = t - 1;
						s[t] = (s[t] != s[t + 1]);
						break;
					case 10:
						t = t - 1;
						s[t] = (s[t] < s[t + 1]);
						break;
					case 11:
						t = t - 1;
						s[t] = (s[t] >= s[t + 1]);
						break;
					case 12:
						t = t - 1;
						s[t] = (s[t] > s[t + 1]);
						break;
					case 13: 
						t = t - 1;
						s[t] = (s[t] <= s[t + 1]);
						break;
					case 14:
						if(i.l == 0)
						{
							printf("%d", s[t]);
							fprintf(fout, "%d", s[t]);
						}
						else if(i.l == 1)
						{
							printf("%c",s[t]);
							fprintf(fout,"%c",s[t]);
						}
						else if(i.l == 2)
						{
							printf("%s",(s[t]==0)?"false":"true");
							fprintf(fout,"%s",(s[t]==0)?"false":"true");
						}
						break;
					case 15:
						printf("\n");
						fprintf(fout,"\n");
						break;
					case 16:
						t = t + 1;
						printf("?");
						fprintf(fout, "?");
						if(i.l == 0)
						{
							scanf("%d", &(s[t]));
							fprintf(fout, "%d\n", s[t]);	
						}
						else if(i.l == 1)
						{
							scanf(" %c", &(s[t]));
							fprintf(fout, "%c\n", s[t]);	
						}
						else
						{
							scanf("%d", &(s[t]));
							fprintf(fout, "%d\n", s[t]);
							if(s[t] != 0) s[t] = 1;
						}
						break;
					case 17:
						t = t - 1;
						s[t] = s[t] % s[t + 1];
						break;
					case 18:
						t = t - 1;
						if(s[t] != 0) s[t] = 1;
						if(s[t+1] != 0) s[t+1] = 1;
						if(i.l == 0) s[t] = s[t]&s[t+1];
						else if(i.l == 1) s[t] = s[t]|s[t+1];
						else if(i.l == 2) s[t] = s[t]^s[t+1];
						break;
					case 19:
						if(s[t] != 0) s[t] = 0;
						else s[t] = 1;
						break;
					case 20:
						s[t] = s[t]%2;
						break;
				}
				break;
			case lod:	
				t = t + 1;
				s[t] = s[i.a+b];	
				break;
			case sto:	
				if(i.l == 0) s[b+i.a] = s[t];
				else if(i.l == 1) s[t+i.a] = s[t];
				break;
			case stv:
				s[b] = s[t];
				break;
			case ast:
				t = t - 1;
				s[s[t]+b] = s[t+1];
				s[t] = s[t+1];
				break;
			case ald:
				s[t] = s[s[t]+b];
				break;
			case cal:	        /* ??????????????? */
				s[t + 1] = 0;
				s[t + 2] = b;	/* ???????????????????????????????????????????????? */
				s[t + 3] = p;	/* ??????????????????????????????????????????????????? */
				b = t + 1;	    /* ???????????????????????????????????????????????? */
				p = i.a;	    /* ?????? */
				break;
			case ini:	
				t = t + i.a;	
				break;
			case jmp:	
				p = i.a;
				break;
			case jpc:	
				if (s[t] == 0) 
					p = i.a;
				t = t - 1;
				break;
		}
	} while (p != 0);
	printf("End X0\n");
	fprintf(fout,"End X0\n");
}


int main(){
	strcpy(fname,"test.txt");
    scanf("%s", fname);
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
	fclose(fmistake);
	fclose(fin);
    return 0;
}
