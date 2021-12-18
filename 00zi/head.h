#ifndef HEAD_H
#define HEAD_H
#define al 10
#define cxmax 2000
#define txmax 1000
#define amax 2048
#define strmax 20000
#define stacksize 3000

char fname[al];

int tx;/*table */
int cx;/* code*/
int px;/*proctable*/
int lev;
int proctable[3];
char id[al];
extern int line;
int err;
int c_num;/* use to record const */
int fortable[cxmax];
int forx;

int for_var;
int for_lev[10];
int for_lx;

int vartable[cxmax];
int  varx;
int total_var;
int tem;
int offset;
int preVar;
int preVar_cnt;
int proc_p;
int pass_cnt;
int isString;
char buffer[strmax];
char temstr[strmax];

enum fct
{
    lit,     opr,     lod,
    sto,     cal,     ini,
    jmp,     jpc,
};
struct instruction
{
    enum fct f;   /* 虚拟机代码指令 */
    int l;        /* 引用层与声明层的层次差 */
    int a;        /* 根据f的不同而不同 */
};
struct instruction code[cxmax]; /* 存放虚拟机代码的数组 */
enum object
{
    constant,
    variable,
    procedure,
};
enum type
{
    xint,
    xchar,
    xvoid
};

/* 符号表结构 */
struct tablestruct
{
char name[al];      /* 名字 */
enum object kind;   /* 类型：const，var或procedure */
int val;            /* 数值，仅const使用 */
    int level;          /* 所处层，仅const不使用 */
    int adr;            /* 地址，仅const不使用 */
    int size;           /* 需要分配的数据区空间, 仅procedure使用 */
enum type t; /* type */
int is_arry;
int parameter_cnt;
};
struct tablestruct table[txmax]; /* 符号表 */

#endif // HEAD_H
