typedef union{
    int number;
    char* ident;
} YYSTYPE;
#define	PLUS	257
#define	DIV	258
#define	MINUS	259
#define	MUL	260
#define	EQL	261
#define	GEQ	262
#define	LEQ	263
#define	LSS	264
#define	GTR	265
#define	NEQ	266
#define	CHAR	267
#define	INT	268
#define	BOOL	269
#define	PER	270
#define	XOR	271
#define	OR	272
#define	AND	273
#define	NOT	274
#define	ODD	275
#define	LP	276
#define	RP	277
#define	LB	278
#define	RB	279
#define	LSB	280
#define	RSB	281
#define	MAIN	282
#define	SEMI	283
#define	IF	284
#define	ELSE	285
#define	READ	286
#define	WRITE	287
#define	WHILE	288
#define	BECOMES	289
#define	TRUE	290
#define	FALSE	291
#define	FOR	292
#define	RETURN	293
#define	NUMBER	294
#define	IDENT	295


extern YYSTYPE yylval;
