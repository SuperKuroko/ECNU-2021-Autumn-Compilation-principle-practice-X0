#ifdef __cplusplus
extern "C" {
#endif
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
#define	COMMA	276
#define	LP	277
#define	RP	278
#define	LB	279
#define	RB	280
#define	LSB	281
#define	RSB	282
#define	MAIN	283
#define	SEMI	284
#define	IF	285
#define	ELSE	286
#define	READ	287
#define	WRITE	288
#define	WHILE	289
#define	BECOMES	290
#define	TRUE	291
#define	FALSE	292
#define	FOR	293
#define	RETURN	294
#define	NUMBER	295
#define	IDENT	296


extern YYSTYPE yylval;
#ifdef __cplusplus
}
#endif
