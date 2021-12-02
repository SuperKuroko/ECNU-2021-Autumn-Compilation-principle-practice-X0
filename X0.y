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

%type <number> get_pcode_addr get_table_addr type var

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
	{
		gen(opr, 0, 0);
	}
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
	{
		$$ = position($1);
		is_array_element = false;
	}
    | IDENT LSB expression RSB
	{
		$$ = position($1);
		is_array_element = true;
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
	: WRITE var SEMI
	{
		if(is_array_element) gen(lod, -1, table[$2].adr);
		else gen(lod, lev - table[$2].level, table[$2].adr);
		gen(opr, 0, 14);
		gen(opr, 0, 15);
	}
    ;

read_stat
	: READ var SEMI
	{
		gen(opr, 0, 16);
		if(is_array_element) gen(sto, -1, table[$2].adr);
		else gen(sto, lev - table[$2].level, table[$2].adr);
	}
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
	| additive_expr EQL additive_expr
	{
		gen(opr, 0, 8);
	}
    | additive_expr NEQ additive_expr
	{
		gen(opr, 0, 9);
	}
	| additive_expr LSS additive_expr
	{
		gen(opr, 0, 10);
	}
    | additive_expr GEQ additive_expr
	{
		gen(opr, 0, 11);
	}
	| additive_expr GTR additive_expr
	{
		gen(opr, 0, 12);
	}
    | additive_expr LEQ additive_expr
	{
		gen(opr, 0, 13);
	}
    ;

additive_expr
	: term 
    | additive_expr PLUS term 
    | additive_expr MINUS term 
    ;

term
	: factor
    | term MUL factor
	{
		gen(opr, 0 ,4);
	}
    | term DIV factor
	{
		gen(opr, 0 ,5);
	}
    ;

factor
	: LP expression RP 
    | var 
    | NUMBER
	{
		gen(lit, 0, $1);
	}
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
	strcpy(table[table_pointer].name, id);
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
			case lit:	/* 将常量a的值取到栈顶 */
				t = t + 1;
				s[t] = i.a;				
				break;
			case opr:	/* 数学、逻辑运算 */
				switch (i.a)
				{
					case 0:  /* 函数调用结束后返回 */
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
						printf("%d", s[t]);
						fprintf(fout, "%d", s[t]);
						t = t - 1;
						break;
					case 15:/* 输出换行符 */
						printf("\n");
						fprintf(fout,"\n");
						break;
					case 16:/* 读入一个输入置于栈顶 */
						t = t + 1;
						printf("?");
						fprintf(fout, "?");
						scanf("%d", &(s[t]));
						fprintf(fout, "%d\n", s[t]);						
						break;
				}
				break;
			case lod:	/* 取相对当前过程的数据基地址为a的内存的值到栈顶 */
				if(i.l >= 0)
				{
					t = t + 1;
					s[t] = s[i.a+1];	
				}
				else
				{
					s[t] = s[i.a+s[t]+1];
				}
				break;
			case sto:	/* 栈顶的值存到相对当前过程的数据基地址为a的内存 */
				if(i.l >= 0)
				{
					s[1+i.a] = s[t];
					t = t - 1;
				}
				else
				{
					s[i.a+s[t-1]+1] = s[t];
					t = t - 2;
				}
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
