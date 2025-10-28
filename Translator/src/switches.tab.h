/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SWITCHES_TAB_H_INCLUDED
# define YY_YY_SWITCHES_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    STRING_LITERAL = 259,          /* STRING_LITERAL  */
    F_CONSTANT = 260,              /* F_CONSTANT  */
    I_CONSTANT = 261,              /* I_CONSTANT  */
    C_DEFAULT = 262,               /* C_DEFAULT  */
    C_STATIC = 263,                /* C_STATIC  */
    _ALIGNOF = 264,                /* _ALIGNOF  */
    _ATOMIC = 265,                 /* _ATOMIC  */
    _STATIC_ASSERT = 266,          /* _STATIC_ASSERT  */
    AUTO = 267,                    /* AUTO  */
    FUNC_NAME = 268,               /* FUNC_NAME  */
    CHAR = 269,                    /* CHAR  */
    CONST = 270,                   /* CONST  */
    DOUBLE = 271,                  /* DOUBLE  */
    FLOAT = 272,                   /* FLOAT  */
    INT = 273,                     /* INT  */
    LONG = 274,                    /* LONG  */
    SHORT = 275,                   /* SHORT  */
    BOOL = 276,                    /* BOOL  */
    SIGNED = 277,                  /* SIGNED  */
    SIZEOF = 278,                  /* SIZEOF  */
    STRUCT = 279,                  /* STRUCT  */
    UNION = 280,                   /* UNION  */
    UNSIGNED = 281,                /* UNSIGNED  */
    _BOOL = 282,                   /* _BOOL  */
    _COMPLEX = 283,                /* _COMPLEX  */
    _IMAGINARY = 284,              /* _IMAGINARY  */
    VOID = 285,                    /* VOID  */
    RESTRICT = 286,                /* RESTRICT  */
    VOLATILE = 287,                /* VOLATILE  */
    _GENERIC = 288,                /* _GENERIC  */
    LE_OPERAND = 289,              /* LE_OPERAND  */
    GE_OPERAND = 290,              /* GE_OPERAND  */
    EQ_OPERAND = 291,              /* EQ_OPERAND  */
    NE_OPERAND = 292,              /* NE_OPERAND  */
    RIGHT_ASSIGN = 293,            /* RIGHT_ASSIGN  */
    LEFT_ASSIGN = 294,             /* LEFT_ASSIGN  */
    ADD_ASSIGN = 295,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 296,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 297,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 298,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 299,              /* MOD_ASSIGN  */
    AND_ASSIGN = 300,              /* AND_ASSIGN  */
    XOR_ASSIGN = 301,              /* XOR_ASSIGN  */
    OR_ASSIGN = 302,               /* OR_ASSIGN  */
    RIGHT_OPERAND = 303,           /* RIGHT_OPERAND  */
    LEFT_OPERAND = 304,            /* LEFT_OPERAND  */
    INC_OPERAND = 305,             /* INC_OPERAND  */
    DEC_OPERAND = 306,             /* DEC_OPERAND  */
    PTR_OPERAND = 307,             /* PTR_OPERAND  */
    AND_OPERAND = 308,             /* AND_OPERAND  */
    OR_OPERAND = 309,              /* OR_OPERAND  */
    PRAGMA = 310,                  /* PRAGMA  */
    OMP = 311,                     /* OMP  */
    PARALLEL = 312,                /* PARALLEL  */
    FOR = 313,                     /* FOR  */
    SECTIONS = 314,                /* SECTIONS  */
    SECTION = 315,                 /* SECTION  */
    SIMD = 316,                    /* SIMD  */
    TASK = 317,                    /* TASK  */
    SINGLE = 318,                  /* SINGLE  */
    TARGET = 319,                  /* TARGET  */
    ATOMIC = 320,                  /* ATOMIC  */
    MASTER = 321,                  /* MASTER  */
    CRITICAL = 322,                /* CRITICAL  */
    BARRIER = 323,                 /* BARRIER  */
    NUM_THREADS = 324,             /* NUM_THREADS  */
    DEFAULT = 325,                 /* DEFAULT  */
    PRIVATE = 326,                 /* PRIVATE  */
    FIRSTPRIVATE = 327,            /* FIRSTPRIVATE  */
    SHARED = 328,                  /* SHARED  */
    COPYIN = 329,                  /* COPYIN  */
    REDUCTION = 330,               /* REDUCTION  */
    NOWAIT = 331,                  /* NOWAIT  */
    DEPEND = 332,                  /* DEPEND  */
    LASTPRIVATE = 333,             /* LASTPRIVATE  */
    COPYPRIVATE = 334,             /* COPYPRIVATE  */
    LINEAR = 335,                  /* LINEAR  */
    COLLAPSE = 336,                /* COLLAPSE  */
    IF = 337,                      /* IF  */
    FINAL = 338,                   /* FINAL  */
    UNTIED = 339,                  /* UNTIED  */
    MERGEABLE = 340,               /* MERGEABLE  */
    PRIORITY = 341,                /* PRIORITY  */
    SCHEDULE = 342,                /* SCHEDULE  */
    ORDERED = 343,                 /* ORDERED  */
    GRAINSIZE = 344,               /* GRAINSIZE  */
    NUM_TASKS = 345,               /* NUM_TASKS  */
    NOGROUP = 346,                 /* NOGROUP  */
    ALIGNED = 347,                 /* ALIGNED  */
    SAFELEN = 348,                 /* SAFELEN  */
    DECLARE = 349,                 /* DECLARE  */
    SIMDLEN = 350,                 /* SIMDLEN  */
    UNIFORM = 351,                 /* UNIFORM  */
    INBRANCH = 352,                /* INBRANCH  */
    NOTINBRANCH = 353,             /* NOTINBRANCH  */
    TASKLOOP = 354,                /* TASKLOOP  */
    UPDATE = 355,                  /* UPDATE  */
    DISTRIBUTE = 356,              /* DISTRIBUTE  */
    DEVICE = 357,                  /* DEVICE  */
    TO = 358,                      /* TO  */
    FROM = 359,                    /* FROM  */
    TASKYIELD = 360,               /* TASKYIELD  */
    DATA = 361,                    /* DATA  */
    ENTER = 362,                   /* ENTER  */
    EXIT = 363,                    /* EXIT  */
    MAP = 364,                     /* MAP  */
    IS_DEVICE_PTR = 365,           /* IS_DEVICE_PTR  */
    DEFAULTMAP = 366,              /* DEFAULTMAP  */
    NUM_TEAMS = 367,               /* NUM_TEAMS  */
    THREAD_LIMIT = 368,            /* THREAD_LIMIT  */
    DIST_SCHEDULE = 369,           /* DIST_SCHEDULE  */
    TEAMS = 370,                   /* TEAMS  */
    TASKWAIT = 371,                /* TASKWAIT  */
    TASKGROUP = 372,               /* TASKGROUP  */
    READ = 373,                    /* READ  */
    WRITE = 374,                   /* WRITE  */
    CAPTURE = 375,                 /* CAPTURE  */
    FLUSH = 376,                   /* FLUSH  */
    THREADS = 377,                 /* THREADS  */
    CANCEL = 378,                  /* CANCEL  */
    CANCELLATION = 379,            /* CANCELLATION  */
    POINT = 380,                   /* POINT  */
    THREADPRIVATE = 381,           /* THREADPRIVATE  */
    IN = 382,                      /* IN  */
    OUT = 383,                     /* OUT  */
    INOUT = 384,                   /* INOUT  */
    NONE = 385,                    /* NONE  */
    PROC_BIND = 386,               /* PROC_BIND  */
    CLOSE = 387,                   /* CLOSE  */
    SPREAD = 388,                  /* SPREAD  */
    MAX = 389,                     /* MAX  */
    MIN = 390,                     /* MIN  */
    SEQ_CST = 391,                 /* SEQ_CST  */
    ALLOC = 392,                   /* ALLOC  */
    TOFROM = 393,                  /* TOFROM  */
    USE_DEVICE_PTR = 394,          /* USE_DEVICE_PTR  */
    SCALAR = 395,                  /* SCALAR  */
    GUIDED = 396,                  /* GUIDED  */
    DYNAMIC = 397,                 /* DYNAMIC  */
    STATIC = 398,                  /* STATIC  */
    RUNTIME = 399,                 /* RUNTIME  */
    CROSS = 400,                   /* CROSS  */
    ENDLN = 401,                   /* ENDLN  */
    GLOBAL = 402                   /* GLOBAL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SWITCHES_TAB_H_INCLUDED  */
