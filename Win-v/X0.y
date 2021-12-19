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
	bool is_write;
	bool is_array_element;
	
    FILE* fin = NULL;     /* input file */
    FILE* ftable = NULL;  /* the file which store the table output */
    FILE* fpcode = NULL;  /* the file which store the pcode output */
    FILE* fout = NULL;    /* output file */
    FILE* fmistake = NULL;  /* the file which store the error infomation (if had) */

    enum object 
	{
        variable,
		array,
        function
    };

	enum xtype
	{
		X0_int,
		X0_char,
		X0_bool
	};
	enum xtype xt;
    struct tablestruct
    {
        char name[var_name_length]; /* char array to store the var name*/
        enum object kind;           /* kind：const，var or procedure */
        int adr;                    /* adr: for all except const var */
        int size;                   /* size to alloc, only for procedure */
		enum xtype X0_type;         /* only for var or const */
    };

    struct tablestruct table[table_length]; 
    enum fct 
    {
        lit,     opr,     lod, 
        sto,     cal,     ini, 
        jmp,     jpc,     pop,
		ast,     ald,
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

%token PLUS DIV MINUS MUL EQL GEQ LEQ LSS GTR NEQ CHAR INT BOOL PER XOR OR AND NOT ODD
%token LP RP LB RB LSB RSB MAIN SEMI IF ELSE READ WRITE WHILE BECOMES TRUE FALSE FOR
 

%token <number> NUMBER
%token <ident> IDENT 

%type <number> type var pcode_register for_exp1 for_exp2 for_exp3

%%

main_function
	:
	pcode_register
	{
		gen(jmp, 0, 0);
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
	{
		gen(opr, 0, 0);
	}
	;


pcode_register
	:
	{
		$$ = pcode_pointer;
	}

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
		else if($1 == 2)table[table_pointer].X0_type = X0_char;
		else if($1 == 3)table[table_pointer].X0_type = X0_bool;
	}
    | type IDENT LSB NUMBER RSB SEMI
	{
		var_cnt++;
		var_size += $4;
		strcpy(id, $2);
		table_add(array);
		table[table_pointer].size = $4;
		if($1 == 1) table[table_pointer].X0_type = X0_int;
		else if($1 == 2)table[table_pointer].X0_type = X0_char;
		else if($1 == 3)table[table_pointer].X0_type = X0_bool;
	}
    ;

type
	: INT {$$ = 1;}
    | CHAR {$$ = 2;}
	| BOOL {$$ = 3;}
    ;

var	
	: IDENT 
	{
		$$ = position($1);
		xt = table[$$].X0_type;
		is_array_element = false;
	}
    | IDENT LSB expression RSB
	{
		$$ = position($1);
		xt = table[$$].X0_type;
		is_array_element = true;
		gen(lit, 0, table[$$].adr);
		gen(opr, 0, 2);
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
		if(is_array_element) gen(ast, 0, 0);
		else gen(sto, 0, table[$2].adr);
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
		gen(pop, 0, 1);
	}
    ;

expression
	: var BECOMES expression 
	{
		if(is_array_element) gen(ast, 0, 0);
		else gen(sto, 0, table[$1].adr);
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
		if(is_array_element) gen(ald, 0 ,0);
		else gen(lod, 0, table[$1].adr);
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
	//err++;
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
	is_write = false;
	is_array_element = false;
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
	strcpy(table[table_pointer].name, id);
	table[table_pointer].kind = item;
	switch(item)
	{
		case variable:
			table[table_pointer].size = 1;
			break;
		case array:
			break;
		case function:
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
		{"lit"},{"opr"},{"lod"},{"sto"},{"cal"},{"ini"},{"jmp"},{"jpc"},{"pop"},{"ast"},{"ald"}
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
	char map[][5] = {{"int "},{"char"},{"bool"}};
    printf("num    name    kind      address  size\n");
	for (i = 1; i <= table_pointer; i++)
	{   
		switch (table[i].kind)
		{
			case variable:
				printf("%3d     %s     var:%s     %3d    %3d\n",i,table[i].name,map[table[i].X0_type],table[i].adr,table[i].size);
				fprintf(ftable, "%3d     %s     var:%s     %3d    %3d\n",i,table[i].name,map[table[i].X0_type],table[i].adr,table[i].size);
				break;

			case array:
				printf("%3d     %s     ary:%s     %3d    %3d\n",i,table[i].name,map[table[i].X0_type],table[i].adr,table[i].size);
				fprintf(ftable, "%3d     %s     ary:%s     %3d    %3d\n",i,table[i].name,map[table[i].X0_type],table[i].adr,table[i].size);
				break;

			case function:
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
	int p = 0; /* 指令指针 */
	int b = 1; /* 指令基址 */
	int t = 0; /* 栈顶指针 */
	struct instruction i;
	int s[stacksize];	

	printf("Start X0\n");
	fprintf(fout,"Start X0\n");
	s[0] = 0; /* s[0]不用 */
	s[1] = 0; /* 主程序的三个联系单元均置为0 */
	s[2] = 0;
	s[3] = 0;
	do {
	    i = pcode[p];	/* 读当前指令 */
		p = p + 1;      
		switch (i.f)
		{
			case pop:
				t = t - i.a;
				break;
			case lit:	/* 将常量a的值取到栈顶 */
				t = t + 1;
				s[t] = i.a;				
				break;
			case opr:	/* 数学、逻辑运算 */
				switch (i.a)
				{
					case 0:  /* 函数调用结束后返回 */
						printf("EDNt = %d\n",t);
						t = b - 1;
						p = s[t + 3];
						b = s[t + 2];
						break;
					case 1: /* 栈顶元素取反 */
						s[t] = - s[t];
						break;
					case 2: /* 次栈顶项加上栈顶项，退两个栈元素，相加值进栈 */
						t = t - 1;
						s[t] = s[t] + s[t + 1];
						break;
					case 3:/* 次栈顶项减去栈顶项 */
						t = t - 1;
						s[t] = s[t] - s[t + 1];
						break;
					case 4:/* 次栈顶项乘以栈顶项 */
						t = t - 1;
						s[t] = s[t] * s[t + 1];
						break;
					case 5:/* 次栈顶项除以栈顶项 */
						t = t - 1;
						s[t] = s[t] / s[t + 1];
						break;
					case 6:/* 栈顶元素的奇偶判断 */
						s[t] = s[t] % 2;
						break;
					case 8:/* 次栈顶项与栈顶项是否相等 */
						t = t - 1;
						s[t] = (s[t] == s[t + 1]);
						break;
					case 9:/* 次栈顶项与栈顶项是否不等 */
						t = t - 1;
						s[t] = (s[t] != s[t + 1]);
						break;
					case 10:/* 次栈顶项是否小于栈顶项 */
						t = t - 1;
						s[t] = (s[t] < s[t + 1]);
						break;
					case 11:/* 次栈顶项是否大于等于栈顶项 */
						t = t - 1;
						s[t] = (s[t] >= s[t + 1]);
						break;
					case 12:/* 次栈顶项是否大于栈顶项 */
						t = t - 1;
						s[t] = (s[t] > s[t + 1]);
						break;
					case 13: /* 次栈顶项是否小于等于栈顶项 */
						t = t - 1;
						s[t] = (s[t] <= s[t + 1]);
						break;
					case 14:/* 栈顶值输出 */
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
					case 15:/* 输出换行符 */
						printf("\n");
						fprintf(fout,"\n");
						break;
					case 16:/* 读入一个输入置于栈顶 */
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
					case 21:
						s[t]++;
						break;
					case 22:
						s[t]--;
						break;
				}
				break;
			case lod:	/* 取相对当前过程的数据基地址为a的内存的值到栈顶 */
				t = t + 1;
				s[t] = s[i.a+1];	
				break;
			case sto:	/* 栈顶的值存到相对当前过程的数据基地址为a的内存 */
				s[1+i.a] = s[t];
				break;
			case ast:
				t = t - 1;
				s[s[t]+1] = s[t+1];
				break;
			case ald:
				s[t] = s[s[t]+1];
				break;
			case cal:	/* 调用子过程 */
				s[t + 1] = base(i.l, s, b);	/* 将父过程基地址入栈，即建立静态链 */
				s[t + 2] = b;	/* 将本过程基地址入栈，即建立动态链 */
				s[t + 3] = p;	/* 将当前指令指针入栈，即保存返回地址 */
				b = t + 1;	/* 改变基地址指针值为新过程的基地址 */
				p = i.a;	/* 跳转 */
				break;
			case ini:	/* 在数据栈中为被调用的过程开辟a个单元的数据区 */
				t = t + i.a;	
				printf("STAt = %d\n",t);
				break;
			case jmp:	/* 直接跳转 */
				p = i.a;
				break;
			case jpc:	/* 条件跳转 */
				if (s[t] == 0) 
					p = i.a;
				t = t - 1;
				break;
		}
	} while (p != 0);
	printf("End X0\n");
	fprintf(fout,"End X0\n");
}

int base(int l, int* s, int b)
{
	int b1;
	b1 = b;
	while (l > 0)
	{
		b1 = s[b1];
		l--;
	}
	return b1;
}

int main(){
    printf("Input file  ");
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
