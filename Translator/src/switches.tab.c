/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 12 "switches.y"

    #include "definitions.h"
    
    
    /* What we need from flex */
    extern int yylex();
    extern int yyparse();
    extern FILE *yyin;
    
    /* Translator Global Variables */	
	int  line 				= 1;
	int  pass 				= 1;
    int  currentFile 		= 0;
    int  currentFunction 	= 1;
    int  currentTask 		= 1;
    int  currentFor			= -1;
    int  targetSystem 		= 0;
    int  runtimeSystem 		= RUNTIME_STATIC;
    int  printSGFlag 		= 0;
    int  assignmentPolicy 	= SCHED_RR;
    int  affinityPolicy     = AFFINITY_NONE;
   
    SG*         Graph;
    
    /* NSGA Global Variables */
    NSGA*       nsga;
    Population* parent_pop;
    Population* child_pop;
    Population* mixed_pop;
    int         totalKernels = 0;
    double*     min_var;
    double*     max_var;
    
    bool firstPass 		= TRUE;
    bool inPragmaBlock 	= FALSE;
    bool inParallelFor  = FALSE;
    bool inReduction	= FALSE;

    bool transactions 	= FALSE;
    
    
	FILE *inp, *outp_sw_main, *outp_sw_h, *outp_sw_threadpool, *outp_sw_threads, *outp_sw_tao_h;
	FILE *outp;
	
	// Local variables
	int localSimd 				= 0;
	int localKernels 			= 0;
	int localScheduling 		= 0;
	int localPriority 			= 0;
	int localStateOfDefault 	= 0;
	int localDependenceType		= 0;
	
	intStr 	localintStr;
	
	char	**stringFor;
	char	reductionType[REDUCTION_SIZE];
	
	
	dataList 		*lists[NUM_LISTS];
	arrayIndex    	*indexes;
    
    extern bool inPragmaLine;
	extern bool inPragmaFor;
	extern bool inForLine;
    extern bool bracketsEnabled;
    extern bool inMainFunction;
    extern int 	inWhichDataList;
    extern int  bracketCounter;
    
    
    
    extern int 	kernels;
    extern char **inputFiles;
    extern int 	totalInputFiles;
    
    
	void yyerror(const char *s);

#line 150 "switches.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "switches.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_STRING_LITERAL = 4,             /* STRING_LITERAL  */
  YYSYMBOL_F_CONSTANT = 5,                 /* F_CONSTANT  */
  YYSYMBOL_I_CONSTANT = 6,                 /* I_CONSTANT  */
  YYSYMBOL_C_DEFAULT = 7,                  /* C_DEFAULT  */
  YYSYMBOL_C_STATIC = 8,                   /* C_STATIC  */
  YYSYMBOL__ALIGNOF = 9,                   /* _ALIGNOF  */
  YYSYMBOL__ATOMIC = 10,                   /* _ATOMIC  */
  YYSYMBOL__STATIC_ASSERT = 11,            /* _STATIC_ASSERT  */
  YYSYMBOL_AUTO = 12,                      /* AUTO  */
  YYSYMBOL_FUNC_NAME = 13,                 /* FUNC_NAME  */
  YYSYMBOL_CHAR = 14,                      /* CHAR  */
  YYSYMBOL_CONST = 15,                     /* CONST  */
  YYSYMBOL_DOUBLE = 16,                    /* DOUBLE  */
  YYSYMBOL_FLOAT = 17,                     /* FLOAT  */
  YYSYMBOL_INT = 18,                       /* INT  */
  YYSYMBOL_LONG = 19,                      /* LONG  */
  YYSYMBOL_SHORT = 20,                     /* SHORT  */
  YYSYMBOL_BOOL = 21,                      /* BOOL  */
  YYSYMBOL_SIGNED = 22,                    /* SIGNED  */
  YYSYMBOL_SIZEOF = 23,                    /* SIZEOF  */
  YYSYMBOL_STRUCT = 24,                    /* STRUCT  */
  YYSYMBOL_UNION = 25,                     /* UNION  */
  YYSYMBOL_UNSIGNED = 26,                  /* UNSIGNED  */
  YYSYMBOL__BOOL = 27,                     /* _BOOL  */
  YYSYMBOL__COMPLEX = 28,                  /* _COMPLEX  */
  YYSYMBOL__IMAGINARY = 29,                /* _IMAGINARY  */
  YYSYMBOL_VOID = 30,                      /* VOID  */
  YYSYMBOL_RESTRICT = 31,                  /* RESTRICT  */
  YYSYMBOL_VOLATILE = 32,                  /* VOLATILE  */
  YYSYMBOL__GENERIC = 33,                  /* _GENERIC  */
  YYSYMBOL_LE_OPERAND = 34,                /* LE_OPERAND  */
  YYSYMBOL_GE_OPERAND = 35,                /* GE_OPERAND  */
  YYSYMBOL_EQ_OPERAND = 36,                /* EQ_OPERAND  */
  YYSYMBOL_NE_OPERAND = 37,                /* NE_OPERAND  */
  YYSYMBOL_RIGHT_ASSIGN = 38,              /* RIGHT_ASSIGN  */
  YYSYMBOL_LEFT_ASSIGN = 39,               /* LEFT_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 40,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 41,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 42,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 43,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 44,                /* MOD_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 45,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 46,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 47,                 /* OR_ASSIGN  */
  YYSYMBOL_RIGHT_OPERAND = 48,             /* RIGHT_OPERAND  */
  YYSYMBOL_LEFT_OPERAND = 49,              /* LEFT_OPERAND  */
  YYSYMBOL_INC_OPERAND = 50,               /* INC_OPERAND  */
  YYSYMBOL_DEC_OPERAND = 51,               /* DEC_OPERAND  */
  YYSYMBOL_PTR_OPERAND = 52,               /* PTR_OPERAND  */
  YYSYMBOL_AND_OPERAND = 53,               /* AND_OPERAND  */
  YYSYMBOL_OR_OPERAND = 54,                /* OR_OPERAND  */
  YYSYMBOL_PRAGMA = 55,                    /* PRAGMA  */
  YYSYMBOL_OMP = 56,                       /* OMP  */
  YYSYMBOL_PARALLEL = 57,                  /* PARALLEL  */
  YYSYMBOL_FOR = 58,                       /* FOR  */
  YYSYMBOL_SECTIONS = 59,                  /* SECTIONS  */
  YYSYMBOL_SECTION = 60,                   /* SECTION  */
  YYSYMBOL_SIMD = 61,                      /* SIMD  */
  YYSYMBOL_TASK = 62,                      /* TASK  */
  YYSYMBOL_SINGLE = 63,                    /* SINGLE  */
  YYSYMBOL_TARGET = 64,                    /* TARGET  */
  YYSYMBOL_ATOMIC = 65,                    /* ATOMIC  */
  YYSYMBOL_MASTER = 66,                    /* MASTER  */
  YYSYMBOL_CRITICAL = 67,                  /* CRITICAL  */
  YYSYMBOL_BARRIER = 68,                   /* BARRIER  */
  YYSYMBOL_NUM_THREADS = 69,               /* NUM_THREADS  */
  YYSYMBOL_DEFAULT = 70,                   /* DEFAULT  */
  YYSYMBOL_PRIVATE = 71,                   /* PRIVATE  */
  YYSYMBOL_FIRSTPRIVATE = 72,              /* FIRSTPRIVATE  */
  YYSYMBOL_SHARED = 73,                    /* SHARED  */
  YYSYMBOL_COPYIN = 74,                    /* COPYIN  */
  YYSYMBOL_REDUCTION = 75,                 /* REDUCTION  */
  YYSYMBOL_NOWAIT = 76,                    /* NOWAIT  */
  YYSYMBOL_DEPEND = 77,                    /* DEPEND  */
  YYSYMBOL_LASTPRIVATE = 78,               /* LASTPRIVATE  */
  YYSYMBOL_COPYPRIVATE = 79,               /* COPYPRIVATE  */
  YYSYMBOL_LINEAR = 80,                    /* LINEAR  */
  YYSYMBOL_COLLAPSE = 81,                  /* COLLAPSE  */
  YYSYMBOL_IF = 82,                        /* IF  */
  YYSYMBOL_FINAL = 83,                     /* FINAL  */
  YYSYMBOL_UNTIED = 84,                    /* UNTIED  */
  YYSYMBOL_MERGEABLE = 85,                 /* MERGEABLE  */
  YYSYMBOL_PRIORITY = 86,                  /* PRIORITY  */
  YYSYMBOL_SCHEDULE = 87,                  /* SCHEDULE  */
  YYSYMBOL_ORDERED = 88,                   /* ORDERED  */
  YYSYMBOL_GRAINSIZE = 89,                 /* GRAINSIZE  */
  YYSYMBOL_NUM_TASKS = 90,                 /* NUM_TASKS  */
  YYSYMBOL_NOGROUP = 91,                   /* NOGROUP  */
  YYSYMBOL_ALIGNED = 92,                   /* ALIGNED  */
  YYSYMBOL_SAFELEN = 93,                   /* SAFELEN  */
  YYSYMBOL_DECLARE = 94,                   /* DECLARE  */
  YYSYMBOL_SIMDLEN = 95,                   /* SIMDLEN  */
  YYSYMBOL_UNIFORM = 96,                   /* UNIFORM  */
  YYSYMBOL_INBRANCH = 97,                  /* INBRANCH  */
  YYSYMBOL_NOTINBRANCH = 98,               /* NOTINBRANCH  */
  YYSYMBOL_TASKLOOP = 99,                  /* TASKLOOP  */
  YYSYMBOL_UPDATE = 100,                   /* UPDATE  */
  YYSYMBOL_DISTRIBUTE = 101,               /* DISTRIBUTE  */
  YYSYMBOL_DEVICE = 102,                   /* DEVICE  */
  YYSYMBOL_TO = 103,                       /* TO  */
  YYSYMBOL_FROM = 104,                     /* FROM  */
  YYSYMBOL_TASKYIELD = 105,                /* TASKYIELD  */
  YYSYMBOL_DATA = 106,                     /* DATA  */
  YYSYMBOL_ENTER = 107,                    /* ENTER  */
  YYSYMBOL_EXIT = 108,                     /* EXIT  */
  YYSYMBOL_MAP = 109,                      /* MAP  */
  YYSYMBOL_IS_DEVICE_PTR = 110,            /* IS_DEVICE_PTR  */
  YYSYMBOL_DEFAULTMAP = 111,               /* DEFAULTMAP  */
  YYSYMBOL_NUM_TEAMS = 112,                /* NUM_TEAMS  */
  YYSYMBOL_THREAD_LIMIT = 113,             /* THREAD_LIMIT  */
  YYSYMBOL_DIST_SCHEDULE = 114,            /* DIST_SCHEDULE  */
  YYSYMBOL_TEAMS = 115,                    /* TEAMS  */
  YYSYMBOL_TASKWAIT = 116,                 /* TASKWAIT  */
  YYSYMBOL_TASKGROUP = 117,                /* TASKGROUP  */
  YYSYMBOL_READ = 118,                     /* READ  */
  YYSYMBOL_WRITE = 119,                    /* WRITE  */
  YYSYMBOL_CAPTURE = 120,                  /* CAPTURE  */
  YYSYMBOL_FLUSH = 121,                    /* FLUSH  */
  YYSYMBOL_THREADS = 122,                  /* THREADS  */
  YYSYMBOL_CANCEL = 123,                   /* CANCEL  */
  YYSYMBOL_CANCELLATION = 124,             /* CANCELLATION  */
  YYSYMBOL_POINT = 125,                    /* POINT  */
  YYSYMBOL_THREADPRIVATE = 126,            /* THREADPRIVATE  */
  YYSYMBOL_IN = 127,                       /* IN  */
  YYSYMBOL_OUT = 128,                      /* OUT  */
  YYSYMBOL_INOUT = 129,                    /* INOUT  */
  YYSYMBOL_NONE = 130,                     /* NONE  */
  YYSYMBOL_PROC_BIND = 131,                /* PROC_BIND  */
  YYSYMBOL_CLOSE = 132,                    /* CLOSE  */
  YYSYMBOL_SPREAD = 133,                   /* SPREAD  */
  YYSYMBOL_MAX = 134,                      /* MAX  */
  YYSYMBOL_MIN = 135,                      /* MIN  */
  YYSYMBOL_SEQ_CST = 136,                  /* SEQ_CST  */
  YYSYMBOL_ALLOC = 137,                    /* ALLOC  */
  YYSYMBOL_TOFROM = 138,                   /* TOFROM  */
  YYSYMBOL_USE_DEVICE_PTR = 139,           /* USE_DEVICE_PTR  */
  YYSYMBOL_SCALAR = 140,                   /* SCALAR  */
  YYSYMBOL_GUIDED = 141,                   /* GUIDED  */
  YYSYMBOL_DYNAMIC = 142,                  /* DYNAMIC  */
  YYSYMBOL_STATIC = 143,                   /* STATIC  */
  YYSYMBOL_RUNTIME = 144,                  /* RUNTIME  */
  YYSYMBOL_CROSS = 145,                    /* CROSS  */
  YYSYMBOL_ENDLN = 146,                    /* ENDLN  */
  YYSYMBOL_GLOBAL = 147,                   /* GLOBAL  */
  YYSYMBOL_148_ = 148,                     /* '('  */
  YYSYMBOL_149_ = 149,                     /* ')'  */
  YYSYMBOL_150_ = 150,                     /* ','  */
  YYSYMBOL_151_ = 151,                     /* ':'  */
  YYSYMBOL_152_ = 152,                     /* '['  */
  YYSYMBOL_153_ = 153,                     /* ']'  */
  YYSYMBOL_154_ = 154,                     /* '.'  */
  YYSYMBOL_155_ = 155,                     /* '{'  */
  YYSYMBOL_156_ = 156,                     /* '}'  */
  YYSYMBOL_157_ = 157,                     /* '&'  */
  YYSYMBOL_158_ = 158,                     /* '*'  */
  YYSYMBOL_159_ = 159,                     /* '+'  */
  YYSYMBOL_160_ = 160,                     /* '-'  */
  YYSYMBOL_161_ = 161,                     /* '~'  */
  YYSYMBOL_162_ = 162,                     /* '!'  */
  YYSYMBOL_163_ = 163,                     /* '/'  */
  YYSYMBOL_164_ = 164,                     /* '%'  */
  YYSYMBOL_165_ = 165,                     /* '<'  */
  YYSYMBOL_166_ = 166,                     /* '>'  */
  YYSYMBOL_167_ = 167,                     /* '^'  */
  YYSYMBOL_168_ = 168,                     /* '|'  */
  YYSYMBOL_169_ = 169,                     /* '?'  */
  YYSYMBOL_170_ = 170,                     /* '='  */
  YYSYMBOL_171_ = 171,                     /* ';'  */
  YYSYMBOL_YYACCEPT = 172,                 /* $accept  */
  YYSYMBOL_program = 173,                  /* program  */
  YYSYMBOL_omp_statement = 174,            /* omp_statement  */
  YYSYMBOL_primary_expression = 175,       /* primary_expression  */
  YYSYMBOL_constant = 176,                 /* constant  */
  YYSYMBOL_string = 177,                   /* string  */
  YYSYMBOL_generic_selection = 178,        /* generic_selection  */
  YYSYMBOL_generic_assoc_list = 179,       /* generic_assoc_list  */
  YYSYMBOL_generic_association = 180,      /* generic_association  */
  YYSYMBOL_postfix_expression = 181,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 182, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 183,         /* unary_expression  */
  YYSYMBOL_unary_operator = 184,           /* unary_operator  */
  YYSYMBOL_cast_expression = 185,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 186, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 187,      /* additive_expression  */
  YYSYMBOL_shift_expression = 188,         /* shift_expression  */
  YYSYMBOL_relational_expression = 189,    /* relational_expression  */
  YYSYMBOL_equality_expression = 190,      /* equality_expression  */
  YYSYMBOL_and_expression = 191,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 192,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 193,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 194,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 195,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 196,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 197,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 198,      /* assignment_operator  */
  YYSYMBOL_expression = 199,               /* expression  */
  YYSYMBOL_constant_expression = 200,      /* constant_expression  */
  YYSYMBOL_type_specifier = 201,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 202, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 203,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 204,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 205,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 206, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 207,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 208,        /* struct_declarator  */
  YYSYMBOL_atomic_type_specifier = 209,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 210,           /* type_qualifier  */
  YYSYMBOL_declarator = 211,               /* declarator  */
  YYSYMBOL_direct_declarator = 212,        /* direct_declarator  */
  YYSYMBOL_pointer = 213,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 214,      /* type_qualifier_list  */
  YYSYMBOL_identifier_list = 215,          /* identifier_list  */
  YYSYMBOL_type_name = 216,                /* type_name  */
  YYSYMBOL_abstract_declarator = 217,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 218, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 219,              /* initializer  */
  YYSYMBOL_initializer_list = 220,         /* initializer_list  */
  YYSYMBOL_designation = 221,              /* designation  */
  YYSYMBOL_designator_list = 222,          /* designator_list  */
  YYSYMBOL_designator = 223,               /* designator  */
  YYSYMBOL_static_assert_declaration = 224, /* static_assert_declaration  */
  YYSYMBOL_expression_statement = 225,     /* expression_statement  */
  YYSYMBOL_iteration_statement_for = 226,  /* iteration_statement_for  */
  YYSYMBOL_omp_construct = 227,            /* omp_construct  */
  YYSYMBOL_omp_directive = 228,            /* omp_directive  */
  YYSYMBOL_optional_expression = 229,      /* optional_expression  */
  YYSYMBOL_target_simd_construct = 230,    /* target_simd_construct  */
  YYSYMBOL_target_simd_directive = 231,    /* target_simd_directive  */
  YYSYMBOL_target_simd_clause_multi = 232, /* target_simd_clause_multi  */
  YYSYMBOL_target_simd_clause = 233,       /* target_simd_clause  */
  YYSYMBOL_target_parallel_for_simd_construct = 234, /* target_parallel_for_simd_construct  */
  YYSYMBOL_target_parallel_for_simd_directive = 235, /* target_parallel_for_simd_directive  */
  YYSYMBOL_target_parallel_for_simd_clause_multi = 236, /* target_parallel_for_simd_clause_multi  */
  YYSYMBOL_target_parallel_for_simd_clause = 237, /* target_parallel_for_simd_clause  */
  YYSYMBOL_target_parallel_for_construct = 238, /* target_parallel_for_construct  */
  YYSYMBOL_target_parallel_for_directive = 239, /* target_parallel_for_directive  */
  YYSYMBOL_target_parallel_for_clause_multi = 240, /* target_parallel_for_clause_multi  */
  YYSYMBOL_target_parallel_for_clause = 241, /* target_parallel_for_clause  */
  YYSYMBOL_target_parallel_construct = 242, /* target_parallel_construct  */
  YYSYMBOL_target_parallel_directive = 243, /* target_parallel_directive  */
  YYSYMBOL_target_parallel_clause_multi = 244, /* target_parallel_clause_multi  */
  YYSYMBOL_target_parallel_clause = 245,   /* target_parallel_clause  */
  YYSYMBOL_taskloop_simd_construct = 246,  /* taskloop_simd_construct  */
  YYSYMBOL_taskloop_simd_directive = 247,  /* taskloop_simd_directive  */
  YYSYMBOL_taskloop_simd_clause_multi = 248, /* taskloop_simd_clause_multi  */
  YYSYMBOL_taskloop_simd_clause = 249,     /* taskloop_simd_clause  */
  YYSYMBOL_taskloop_construct = 250,       /* taskloop_construct  */
  YYSYMBOL_taskloop_directive = 251,       /* taskloop_directive  */
  YYSYMBOL_taskloop_clause_multi = 252,    /* taskloop_clause_multi  */
  YYSYMBOL_taskloop_clause = 253,          /* taskloop_clause  */
  YYSYMBOL_declare_simd_construct = 254,   /* declare_simd_construct  */
  YYSYMBOL_declare_simd_directive = 255,   /* declare_simd_directive  */
  YYSYMBOL_declare_simd_directive_clause_multi = 256, /* declare_simd_directive_clause_multi  */
  YYSYMBOL_declare_simd_directive_clause = 257, /* declare_simd_directive_clause  */
  YYSYMBOL_taskgroup_construct = 258,      /* taskgroup_construct  */
  YYSYMBOL_taskgroup_directive = 259,      /* taskgroup_directive  */
  YYSYMBOL_target_teams_distribute_parallel_for_simd_construct = 260, /* target_teams_distribute_parallel_for_simd_construct  */
  YYSYMBOL_target_teams_distribute_parallel_for_simd_directive = 261, /* target_teams_distribute_parallel_for_simd_directive  */
  YYSYMBOL_target_teams_distribute_parallel_for_simd_clause_multi = 262, /* target_teams_distribute_parallel_for_simd_clause_multi  */
  YYSYMBOL_target_teams_distribute_parallel_for_simd_clause = 263, /* target_teams_distribute_parallel_for_simd_clause  */
  YYSYMBOL_teams_distribute_parallel_for_simd_construct = 264, /* teams_distribute_parallel_for_simd_construct  */
  YYSYMBOL_teams_distribute_parallel_for_simd_directive = 265, /* teams_distribute_parallel_for_simd_directive  */
  YYSYMBOL_teams_distribute_parallel_for_simd_clause_multi = 266, /* teams_distribute_parallel_for_simd_clause_multi  */
  YYSYMBOL_teams_distribute_parallel_for_simd_clause = 267, /* teams_distribute_parallel_for_simd_clause  */
  YYSYMBOL_target_teams_distribute_parallel_for_construct = 268, /* target_teams_distribute_parallel_for_construct  */
  YYSYMBOL_target_teams_distribute_parallel_for_directive = 269, /* target_teams_distribute_parallel_for_directive  */
  YYSYMBOL_target_teams_distribute_parallel_for_clause_multi = 270, /* target_teams_distribute_parallel_for_clause_multi  */
  YYSYMBOL_target_teams_distribute_parallel_for_clause = 271, /* target_teams_distribute_parallel_for_clause  */
  YYSYMBOL_teams_distribute_parallel_for_construct = 272, /* teams_distribute_parallel_for_construct  */
  YYSYMBOL_teams_distribute_parallel_for_directive = 273, /* teams_distribute_parallel_for_directive  */
  YYSYMBOL_teams_distribute_parallel_for_clause_multi = 274, /* teams_distribute_parallel_for_clause_multi  */
  YYSYMBOL_teams_distribute_parallel_for_clause = 275, /* teams_distribute_parallel_for_clause  */
  YYSYMBOL_target_teams_distribute_simd_construct = 276, /* target_teams_distribute_simd_construct  */
  YYSYMBOL_target_teams_distribute_simd_directive = 277, /* target_teams_distribute_simd_directive  */
  YYSYMBOL_target_teams_distribute_simd_clause_multi = 278, /* target_teams_distribute_simd_clause_multi  */
  YYSYMBOL_target_teams_distribute_simd_clause = 279, /* target_teams_distribute_simd_clause  */
  YYSYMBOL_target_teams_distribute_construct = 280, /* target_teams_distribute_construct  */
  YYSYMBOL_target_teams_distribute_directive = 281, /* target_teams_distribute_directive  */
  YYSYMBOL_target_teams_distribute_clause_multi = 282, /* target_teams_distribute_clause_multi  */
  YYSYMBOL_target_teams_distribute_clause = 283, /* target_teams_distribute_clause  */
  YYSYMBOL_teams_distribute_simd_construct = 284, /* teams_distribute_simd_construct  */
  YYSYMBOL_teams_distribute_simd_directive = 285, /* teams_distribute_simd_directive  */
  YYSYMBOL_teams_distribute_simd_clause_multi = 286, /* teams_distribute_simd_clause_multi  */
  YYSYMBOL_teams_distribute_simd_clause = 287, /* teams_distribute_simd_clause  */
  YYSYMBOL_teams_distribute_construct = 288, /* teams_distribute_construct  */
  YYSYMBOL_teams_distribute_directive = 289, /* teams_distribute_directive  */
  YYSYMBOL_teams_distribute_clause_multi = 290, /* teams_distribute_clause_multi  */
  YYSYMBOL_teams_distribute_clause = 291,  /* teams_distribute_clause  */
  YYSYMBOL_target_teams_construct = 292,   /* target_teams_construct  */
  YYSYMBOL_target_teams_directive = 293,   /* target_teams_directive  */
  YYSYMBOL_target_teams_clause_multi = 294, /* target_teams_clause_multi  */
  YYSYMBOL_target_teams_clause = 295,      /* target_teams_clause  */
  YYSYMBOL_distribute_parallel_for_simd_construct = 296, /* distribute_parallel_for_simd_construct  */
  YYSYMBOL_distribute_parallel_for_simd_directive = 297, /* distribute_parallel_for_simd_directive  */
  YYSYMBOL_distribute_parallel_for_simd_clause_multi = 298, /* distribute_parallel_for_simd_clause_multi  */
  YYSYMBOL_distribute_parallel_for_simd_clause = 299, /* distribute_parallel_for_simd_clause  */
  YYSYMBOL_distribute_parallel_for_construct = 300, /* distribute_parallel_for_construct  */
  YYSYMBOL_distribute_parallel_for_directive = 301, /* distribute_parallel_for_directive  */
  YYSYMBOL_distribute_parallel_for_clause_multi = 302, /* distribute_parallel_for_clause_multi  */
  YYSYMBOL_distribute_parallel_for_clause = 303, /* distribute_parallel_for_clause  */
  YYSYMBOL_distribute_simd_construct = 304, /* distribute_simd_construct  */
  YYSYMBOL_distribute_simd_directive = 305, /* distribute_simd_directive  */
  YYSYMBOL_distribute_simd_clause_multi = 306, /* distribute_simd_clause_multi  */
  YYSYMBOL_distribute_simd_clause = 307,   /* distribute_simd_clause  */
  YYSYMBOL_distribute_construct = 308,     /* distribute_construct  */
  YYSYMBOL_distribute_directive = 309,     /* distribute_directive  */
  YYSYMBOL_distribute_clause_multi = 310,  /* distribute_clause_multi  */
  YYSYMBOL_distribute_clause = 311,        /* distribute_clause  */
  YYSYMBOL_teams_construct = 312,          /* teams_construct  */
  YYSYMBOL_teams_directive = 313,          /* teams_directive  */
  YYSYMBOL_teams_clause_multi = 314,       /* teams_clause_multi  */
  YYSYMBOL_teams_clause = 315,             /* teams_clause  */
  YYSYMBOL_target_update_construct = 316,  /* target_update_construct  */
  YYSYMBOL_target_update_directive = 317,  /* target_update_directive  */
  YYSYMBOL_target_update_clause_seq = 318, /* target_update_clause_seq  */
  YYSYMBOL_target_update_clause = 319,     /* target_update_clause  */
  YYSYMBOL_target_construct = 320,         /* target_construct  */
  YYSYMBOL_target_directive = 321,         /* target_directive  */
  YYSYMBOL_target_clause_multi = 322,      /* target_clause_multi  */
  YYSYMBOL_target_clause = 323,            /* target_clause  */
  YYSYMBOL_target_data_construct = 324,    /* target_data_construct  */
  YYSYMBOL_target_data_directive = 325,    /* target_data_directive  */
  YYSYMBOL_target_data_clause_multi = 326, /* target_data_clause_multi  */
  YYSYMBOL_target_data_clause = 327,       /* target_data_clause  */
  YYSYMBOL_parallel_for_simd_construct = 328, /* parallel_for_simd_construct  */
  YYSYMBOL_parallel_for_simd_directive = 329, /* parallel_for_simd_directive  */
  YYSYMBOL_parallel_for_simd_clause_multi = 330, /* parallel_for_simd_clause_multi  */
  YYSYMBOL_parallel_for_simd_clause = 331, /* parallel_for_simd_clause  */
  YYSYMBOL_for_simd_construct = 332,       /* for_simd_construct  */
  YYSYMBOL_for_simd_directive = 333,       /* for_simd_directive  */
  YYSYMBOL_for_simd_clause_multi = 334,    /* for_simd_clause_multi  */
  YYSYMBOL_for_simd_clause = 335,          /* for_simd_clause  */
  YYSYMBOL_simd_construct = 336,           /* simd_construct  */
  YYSYMBOL_simd_directive = 337,           /* simd_directive  */
  YYSYMBOL_simd_clause_multi = 338,        /* simd_clause_multi  */
  YYSYMBOL_simd_clause = 339,              /* simd_clause  */
  YYSYMBOL_task_construct = 340,           /* task_construct  */
  YYSYMBOL_task_directive = 341,           /* task_directive  */
  YYSYMBOL_task_clause_multi = 342,        /* task_clause_multi  */
  YYSYMBOL_task_clause = 343,              /* task_clause  */
  YYSYMBOL_ordered_construct = 344,        /* ordered_construct  */
  YYSYMBOL_ordered_directive = 345,        /* ordered_directive  */
  YYSYMBOL_ordered_clause_multi = 346,     /* ordered_clause_multi  */
  YYSYMBOL_atomic_construct = 347,         /* atomic_construct  */
  YYSYMBOL_atomic_directive = 348,         /* atomic_directive  */
  YYSYMBOL_critical_construct = 349,       /* critical_construct  */
  YYSYMBOL_critical_directive = 350,       /* critical_directive  */
  YYSYMBOL_master_construct = 351,         /* master_construct  */
  YYSYMBOL_master_directive = 352,         /* master_directive  */
  YYSYMBOL_parallel_sections_construct = 353, /* parallel_sections_construct  */
  YYSYMBOL_parallel_sections_directive = 354, /* parallel_sections_directive  */
  YYSYMBOL_parallel_sections_clause_multi = 355, /* parallel_sections_clause_multi  */
  YYSYMBOL_parallel_sections_clause = 356, /* parallel_sections_clause  */
  YYSYMBOL_parallel_for_construct = 357,   /* parallel_for_construct  */
  YYSYMBOL_parallel_for_directive = 358,   /* parallel_for_directive  */
  YYSYMBOL_parallel_for_clause_multi = 359, /* parallel_for_clause_multi  */
  YYSYMBOL_parallel_for_clause = 360,      /* parallel_for_clause  */
  YYSYMBOL_single_construct = 361,         /* single_construct  */
  YYSYMBOL_single_directive = 362,         /* single_directive  */
  YYSYMBOL_single_clause_multi = 363,      /* single_clause_multi  */
  YYSYMBOL_single_clause = 364,            /* single_clause  */
  YYSYMBOL_sections_construct = 365,       /* sections_construct  */
  YYSYMBOL_sections_directive = 366,       /* sections_directive  */
  YYSYMBOL_sections_clause_multi = 367,    /* sections_clause_multi  */
  YYSYMBOL_sections_clause = 368,          /* sections_clause  */
  YYSYMBOL_section_construct = 369,        /* section_construct  */
  YYSYMBOL_section_directive = 370,        /* section_directive  */
  YYSYMBOL_for_construct = 371,            /* for_construct  */
  YYSYMBOL_for_directive = 372,            /* for_directive  */
  YYSYMBOL_for_clause_multi = 373,         /* for_clause_multi  */
  YYSYMBOL_for_clause = 374,               /* for_clause  */
  YYSYMBOL_parallel_construct = 375,       /* parallel_construct  */
  YYSYMBOL_parallel_directive = 376,       /* parallel_directive  */
  YYSYMBOL_parallel_clause_multi = 377,    /* parallel_clause_multi  */
  YYSYMBOL_parallel_clause = 378,          /* parallel_clause  */
  YYSYMBOL_omp_declare_reduction = 379,    /* omp_declare_reduction  */
  YYSYMBOL_omp_threadprivate = 380,        /* omp_threadprivate  */
  YYSYMBOL_omp_barrier = 381,              /* omp_barrier  */
  YYSYMBOL_omp_flush = 382,                /* omp_flush  */
  YYSYMBOL_flush_list = 383,               /* flush_list  */
  YYSYMBOL_omp_taskwait = 384,             /* omp_taskwait  */
  YYSYMBOL_omp_taskyield = 385,            /* omp_taskyield  */
  YYSYMBOL_omp_target_enter_data = 386,    /* omp_target_enter_data  */
  YYSYMBOL_omp_target_enter_data_clause_multi = 387, /* omp_target_enter_data_clause_multi  */
  YYSYMBOL_omp_target_enter_data_clause = 388, /* omp_target_enter_data_clause  */
  YYSYMBOL_omp_target_exit_data = 389,     /* omp_target_exit_data  */
  YYSYMBOL_omp_target_exit_data_clause_multi = 390, /* omp_target_exit_data_clause_multi  */
  YYSYMBOL_omp_target_exit_data_clause = 391, /* omp_target_exit_data_clause  */
  YYSYMBOL_omp_cancel = 392,               /* omp_cancel  */
  YYSYMBOL_omp_cancellation_point = 393,   /* omp_cancellation_point  */
  YYSYMBOL_grainsize_clause = 394,         /* grainsize_clause  */
  YYSYMBOL_num_tasks_clause = 395,         /* num_tasks_clause  */
  YYSYMBOL_uniform_clause = 396,           /* uniform_clause  */
  YYSYMBOL_dist_schedule_clause = 397,     /* dist_schedule_clause  */
  YYSYMBOL_num_teams_clause = 398,         /* num_teams_clause  */
  YYSYMBOL_thread_limit_clause = 399,      /* thread_limit_clause  */
  YYSYMBOL_motion_clause = 400,            /* motion_clause  */
  YYSYMBOL_device_clause = 401,            /* device_clause  */
  YYSYMBOL_map_clause = 402,               /* map_clause  */
  YYSYMBOL_map_type = 403,                 /* map_type  */
  YYSYMBOL_safe_len_clause = 404,          /* safe_len_clause  */
  YYSYMBOL_simd_len_clause = 405,          /* simd_len_clause  */
  YYSYMBOL_final_clause = 406,             /* final_clause  */
  YYSYMBOL_untied_clause = 407,            /* untied_clause  */
  YYSYMBOL_mergeable_clause = 408,         /* mergeable_clause  */
  YYSYMBOL_depend_clause = 409,            /* depend_clause  */
  YYSYMBOL_dependence_type = 410,          /* dependence_type  */
  YYSYMBOL_priority_clause = 411,          /* priority_clause  */
  YYSYMBOL_ordered_clause_opt = 412,       /* ordered_clause_opt  */
  YYSYMBOL_atomic_clause = 413,            /* atomic_clause  */
  YYSYMBOL_seq_cst_clause = 414,           /* seq_cst_clause  */
  YYSYMBOL_region_phrase = 415,            /* region_phrase  */
  YYSYMBOL_copy_private_clause = 416,      /* copy_private_clause  */
  YYSYMBOL_ordered_clause = 417,           /* ordered_clause  */
  YYSYMBOL_schedule_clause = 418,          /* schedule_clause  */
  YYSYMBOL_schedule_kind = 419,            /* schedule_kind  */
  YYSYMBOL_num_threads_clause = 420,       /* num_threads_clause  */
  YYSYMBOL_copyin_clause = 421,            /* copyin_clause  */
  YYSYMBOL_default_clause = 422,           /* default_clause  */
  YYSYMBOL_private_clause = 423,           /* private_clause  */
  YYSYMBOL_first_private_clause = 424,     /* first_private_clause  */
  YYSYMBOL_last_private_clause = 425,      /* last_private_clause  */
  YYSYMBOL_shared_clause = 426,            /* shared_clause  */
  YYSYMBOL_reduction_clause = 427,         /* reduction_clause  */
  YYSYMBOL_linear_clause = 428,            /* linear_clause  */
  YYSYMBOL_aligned_clause = 429,           /* aligned_clause  */
  YYSYMBOL_variable_array_section_list = 430, /* variable_array_section_list  */
  YYSYMBOL_array_section = 431,            /* array_section  */
  YYSYMBOL_array_section_subscript = 432,  /* array_section_subscript  */
  YYSYMBOL_array_section_plain = 433,      /* array_section_plain  */
  YYSYMBOL_collapse_clause = 434,          /* collapse_clause  */
  YYSYMBOL_variable_list = 435,            /* variable_list  */
  YYSYMBOL_type_construct_clause = 436,    /* type_construct_clause  */
  YYSYMBOL_if_clause = 437,                /* if_clause  */
  YYSYMBOL_procbind_clause = 438,          /* procbind_clause  */
  YYSYMBOL_reduction_identifier = 439      /* reduction_identifier  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  97
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4499

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  172
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  268
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1006
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1478

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   402


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   162,     2,     2,     2,   164,   157,     2,
     148,   149,   158,   159,   150,   160,   154,   163,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   151,   171,
     165,   170,   166,   169,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   152,     2,   153,   167,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   155,   168,   156,   161,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   131,   131,   132,   135,   136,   139,   140,   141,   142,
     143,   146,   147,   150,   151,   154,   157,   158,   161,   162,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     177,   178,   181,   182,   183,   184,   185,   186,   187,   190,
     191,   192,   193,   194,   195,   198,   199,   202,   203,   204,
     205,   208,   209,   210,   213,   214,   215,   218,   219,   220,
     221,   222,   225,   226,   227,   230,   231,   234,   235,   238,
     239,   242,   243,   246,   247,   250,   251,   254,   255,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     271,   272,   275,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   295,   296,
     297,   300,   301,   304,   305,   308,   309,   310,   313,   314,
     315,   316,   319,   320,   323,   324,   325,   328,   331,   332,
     333,   334,   337,   338,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   353,   354,   357,   358,   359,
     360,   363,   364,   368,   369,   372,   373,   376,   377,   378,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   400,   404,
     405,   406,   409,   410,   411,   412,   415,   418,   419,   422,
     423,   426,   430,   431,   435,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   628,   629,   630,   631,   632,
     633,   634,   635,   636,   637,   641,   642,   653,   660,   673,
     674,   675,   679,   680,   681,   682,   683,   684,   688,   689,
     690,   691,   692,   693,   694,   695,   696,   697,   705,   712,
     724,   725,   726,   730,   731,   732,   733,   734,   735,   739,
     740,   741,   742,   743,   744,   745,   746,   747,   748,   749,
     750,   751,   752,   753,   754,   762,   769,   781,   782,   783,
     787,   788,   789,   790,   791,   792,   796,   797,   798,   799,
     800,   801,   802,   803,   804,   805,   806,   807,   815,   819,
     831,   832,   833,   837,   838,   839,   840,   841,   842,   846,
     847,   848,   849,   850,   851,   852,   853,   861,   868,   881,
     882,   883,   887,   888,   889,   890,   891,   892,   893,   894,
     895,   896,   897,   898,   899,   900,   901,   902,   903,   904,
     905,   913,   920,   944,   945,   946,   950,   951,   952,   953,
     954,   955,   956,   957,   958,   959,   960,   961,   962,   963,
     965,   966,   967,   968,   976,   981,   991,   992,   993,   997,
     998,   999,  1000,  1001,  1002,  1010,  1014,  1027,  1034,  1046,
    1047,  1048,  1052,  1053,  1054,  1055,  1056,  1057,  1058,  1059,
    1060,  1061,  1062,  1063,  1064,  1065,  1066,  1067,  1068,  1069,
    1070,  1071,  1072,  1076,  1077,  1078,  1079,  1080,  1088,  1095,
    1107,  1108,  1109,  1113,  1114,  1115,  1116,  1117,  1118,  1119,
    1120,  1121,  1122,  1123,  1124,  1125,  1126,  1127,  1128,  1129,
    1130,  1131,  1132,  1133,  1137,  1138,  1139,  1140,  1141,  1149,
    1156,  1168,  1169,  1170,  1174,  1175,  1176,  1177,  1178,  1179,
    1180,  1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,
    1190,  1191,  1195,  1196,  1197,  1205,  1212,  1224,  1225,  1226,
    1230,  1231,  1232,  1233,  1234,  1235,  1236,  1237,  1238,  1239,
    1240,  1241,  1242,  1243,  1244,  1252,  1259,  1271,  1272,  1273,
    1277,  1278,  1279,  1280,  1281,  1282,  1286,  1287,  1288,  1289,
    1290,  1291,  1292,  1293,  1294,  1295,  1296,  1297,  1298,  1299,
    1300,  1308,  1315,  1327,  1328,  1329,  1333,  1334,  1335,  1336,
    1337,  1338,  1342,  1343,  1344,  1345,  1346,  1347,  1348,  1349,
    1350,  1351,  1352,  1360,  1367,  1379,  1380,  1381,  1385,  1386,
    1387,  1388,  1389,  1390,  1391,  1392,  1393,  1394,  1395,  1396,
    1397,  1398,  1406,  1413,  1425,  1426,  1427,  1431,  1432,  1433,
    1434,  1435,  1436,  1437,  1438,  1439,  1440,  1448,  1452,  1464,
    1465,  1466,  1470,  1471,  1472,  1473,  1474,  1475,  1479,  1480,
    1481,  1482,  1483,  1484,  1485,  1486,  1494,  1498,  1510,  1511,
    1512,  1516,  1517,  1518,  1519,  1520,  1521,  1522,  1523,  1524,
    1525,  1526,  1527,  1528,  1529,  1530,  1531,  1532,  1533,  1541,
    1548,  1560,  1561,  1562,  1566,  1567,  1568,  1569,  1570,  1571,
    1572,  1573,  1574,  1575,  1576,  1577,  1578,  1579,  1587,  1594,
    1606,  1607,  1608,  1612,  1613,  1614,  1615,  1616,  1617,  1618,
    1619,  1620,  1621,  1629,  1636,  1646,  1647,  1648,  1652,  1653,
    1654,  1655,  1656,  1664,  1668,  1680,  1681,  1682,  1686,  1687,
    1688,  1689,  1690,  1691,  1692,  1700,  1704,  1714,  1715,  1716,
    1720,  1721,  1722,  1723,  1724,  1732,  1736,  1746,  1747,  1748,
    1752,  1753,  1754,  1755,  1756,  1757,  1761,  1762,  1763,  1771,
    1775,  1785,  1786,  1787,  1791,  1792,  1793,  1794,  1805,  1812,
    1841,  1842,  1843,  1847,  1848,  1849,  1850,  1851,  1852,  1853,
    1854,  1855,  1856,  1857,  1858,  1859,  1860,  1861,  1862,  1863,
    1871,  1878,  1902,  1903,  1904,  1908,  1909,  1910,  1911,  1912,
    1913,  1914,  1915,  1916,  1917,  1918,  1919,  1920,  1921,  1929,
    1937,  1949,  1950,  1951,  1955,  1956,  1957,  1958,  1959,  1960,
    1961,  1962,  1970,  1974,  1992,  1993,  1994,  1998,  1999,  2000,
    2001,  2002,  2003,  2004,  2005,  2006,  2007,  2015,  2019,  2029,
    2030,  2031,  2039,  2043,  2057,  2061,  2067,  2080,  2084,  2106,
    2110,  2126,  2127,  2128,  2132,  2133,  2134,  2135,  2136,  2137,
    2138,  2139,  2140,  2141,  2149,  2156,  2186,  2187,  2188,  2192,
    2193,  2194,  2195,  2196,  2197,  2198,  2199,  2200,  2201,  2202,
    2203,  2204,  2212,  2216,  2234,  2235,  2236,  2240,  2241,  2242,
    2243,  2251,  2255,  2267,  2268,  2269,  2273,  2274,  2275,  2276,
    2277,  2284,  2288,  2304,  2308,  2333,  2334,  2335,  2339,  2340,
    2341,  2342,  2343,  2344,  2345,  2346,  2347,  2348,  2356,  2360,
    2377,  2378,  2379,  2383,  2384,  2385,  2386,  2387,  2388,  2389,
    2390,  2391,  2392,  2400,  2413,  2426,  2439,  2446,  2456,  2467,
    2480,  2492,  2502,  2503,  2504,  2508,  2509,  2510,  2511,  2512,
    2519,  2529,  2530,  2531,  2535,  2536,  2537,  2538,  2539,  2546,
    2554,  2562,  2576,  2590,  2594,  2598,  2602,  2603,  2607,  2611,
    2615,  2616,  2620,  2624,  2625,  2629,  2630,  2631,  2632,  2636,
    2641,  2648,  2652,  2656,  2660,  2668,  2669,  2670,  2671,  2676,
    2683,  2684,  2688,  2689,  2690,  2691,  2692,  2696,  2697,  2701,
    2705,  2712,  2713,  2716,  2721,  2725,  2734,  2735,  2736,  2740,
    2748,  2755,  2759,  2766,  2773,  2780,  2787,  2794,  2802,  2810,
    2818,  2822,  2823,  2828,  2832,  2839,  2840,  2846,  2851,  2856,
    2861,  2866,  2871,  2879,  2883,  2888,  2893,  2900,  2901,  2902,
    2903,  2904,  2908,  2912,  2913,  2914,  2918,  2922,  2926,  2930,
    2934,  2938,  2942,  2946,  2950,  2954,  2958
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "STRING_LITERAL", "F_CONSTANT", "I_CONSTANT", "C_DEFAULT", "C_STATIC",
  "_ALIGNOF", "_ATOMIC", "_STATIC_ASSERT", "AUTO", "FUNC_NAME", "CHAR",
  "CONST", "DOUBLE", "FLOAT", "INT", "LONG", "SHORT", "BOOL", "SIGNED",
  "SIZEOF", "STRUCT", "UNION", "UNSIGNED", "_BOOL", "_COMPLEX",
  "_IMAGINARY", "VOID", "RESTRICT", "VOLATILE", "_GENERIC", "LE_OPERAND",
  "GE_OPERAND", "EQ_OPERAND", "NE_OPERAND", "RIGHT_ASSIGN", "LEFT_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "RIGHT_OPERAND", "LEFT_OPERAND",
  "INC_OPERAND", "DEC_OPERAND", "PTR_OPERAND", "AND_OPERAND", "OR_OPERAND",
  "PRAGMA", "OMP", "PARALLEL", "FOR", "SECTIONS", "SECTION", "SIMD",
  "TASK", "SINGLE", "TARGET", "ATOMIC", "MASTER", "CRITICAL", "BARRIER",
  "NUM_THREADS", "DEFAULT", "PRIVATE", "FIRSTPRIVATE", "SHARED", "COPYIN",
  "REDUCTION", "NOWAIT", "DEPEND", "LASTPRIVATE", "COPYPRIVATE", "LINEAR",
  "COLLAPSE", "IF", "FINAL", "UNTIED", "MERGEABLE", "PRIORITY", "SCHEDULE",
  "ORDERED", "GRAINSIZE", "NUM_TASKS", "NOGROUP", "ALIGNED", "SAFELEN",
  "DECLARE", "SIMDLEN", "UNIFORM", "INBRANCH", "NOTINBRANCH", "TASKLOOP",
  "UPDATE", "DISTRIBUTE", "DEVICE", "TO", "FROM", "TASKYIELD", "DATA",
  "ENTER", "EXIT", "MAP", "IS_DEVICE_PTR", "DEFAULTMAP", "NUM_TEAMS",
  "THREAD_LIMIT", "DIST_SCHEDULE", "TEAMS", "TASKWAIT", "TASKGROUP",
  "READ", "WRITE", "CAPTURE", "FLUSH", "THREADS", "CANCEL", "CANCELLATION",
  "POINT", "THREADPRIVATE", "IN", "OUT", "INOUT", "NONE", "PROC_BIND",
  "CLOSE", "SPREAD", "MAX", "MIN", "SEQ_CST", "ALLOC", "TOFROM",
  "USE_DEVICE_PTR", "SCALAR", "GUIDED", "DYNAMIC", "STATIC", "RUNTIME",
  "CROSS", "ENDLN", "GLOBAL", "'('", "')'", "','", "':'", "'['", "']'",
  "'.'", "'{'", "'}'", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'",
  "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "'='", "';'", "$accept",
  "program", "omp_statement", "primary_expression", "constant", "string",
  "generic_selection", "generic_assoc_list", "generic_association",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "unary_operator", "cast_expression", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "atomic_type_specifier", "type_qualifier",
  "declarator", "direct_declarator", "pointer", "type_qualifier_list",
  "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "designation", "designator_list", "designator",
  "static_assert_declaration", "expression_statement",
  "iteration_statement_for", "omp_construct", "omp_directive",
  "optional_expression", "target_simd_construct", "target_simd_directive",
  "target_simd_clause_multi", "target_simd_clause",
  "target_parallel_for_simd_construct",
  "target_parallel_for_simd_directive",
  "target_parallel_for_simd_clause_multi",
  "target_parallel_for_simd_clause", "target_parallel_for_construct",
  "target_parallel_for_directive", "target_parallel_for_clause_multi",
  "target_parallel_for_clause", "target_parallel_construct",
  "target_parallel_directive", "target_parallel_clause_multi",
  "target_parallel_clause", "taskloop_simd_construct",
  "taskloop_simd_directive", "taskloop_simd_clause_multi",
  "taskloop_simd_clause", "taskloop_construct", "taskloop_directive",
  "taskloop_clause_multi", "taskloop_clause", "declare_simd_construct",
  "declare_simd_directive", "declare_simd_directive_clause_multi",
  "declare_simd_directive_clause", "taskgroup_construct",
  "taskgroup_directive",
  "target_teams_distribute_parallel_for_simd_construct",
  "target_teams_distribute_parallel_for_simd_directive",
  "target_teams_distribute_parallel_for_simd_clause_multi",
  "target_teams_distribute_parallel_for_simd_clause",
  "teams_distribute_parallel_for_simd_construct",
  "teams_distribute_parallel_for_simd_directive",
  "teams_distribute_parallel_for_simd_clause_multi",
  "teams_distribute_parallel_for_simd_clause",
  "target_teams_distribute_parallel_for_construct",
  "target_teams_distribute_parallel_for_directive",
  "target_teams_distribute_parallel_for_clause_multi",
  "target_teams_distribute_parallel_for_clause",
  "teams_distribute_parallel_for_construct",
  "teams_distribute_parallel_for_directive",
  "teams_distribute_parallel_for_clause_multi",
  "teams_distribute_parallel_for_clause",
  "target_teams_distribute_simd_construct",
  "target_teams_distribute_simd_directive",
  "target_teams_distribute_simd_clause_multi",
  "target_teams_distribute_simd_clause",
  "target_teams_distribute_construct", "target_teams_distribute_directive",
  "target_teams_distribute_clause_multi", "target_teams_distribute_clause",
  "teams_distribute_simd_construct", "teams_distribute_simd_directive",
  "teams_distribute_simd_clause_multi", "teams_distribute_simd_clause",
  "teams_distribute_construct", "teams_distribute_directive",
  "teams_distribute_clause_multi", "teams_distribute_clause",
  "target_teams_construct", "target_teams_directive",
  "target_teams_clause_multi", "target_teams_clause",
  "distribute_parallel_for_simd_construct",
  "distribute_parallel_for_simd_directive",
  "distribute_parallel_for_simd_clause_multi",
  "distribute_parallel_for_simd_clause",
  "distribute_parallel_for_construct", "distribute_parallel_for_directive",
  "distribute_parallel_for_clause_multi", "distribute_parallel_for_clause",
  "distribute_simd_construct", "distribute_simd_directive",
  "distribute_simd_clause_multi", "distribute_simd_clause",
  "distribute_construct", "distribute_directive",
  "distribute_clause_multi", "distribute_clause", "teams_construct",
  "teams_directive", "teams_clause_multi", "teams_clause",
  "target_update_construct", "target_update_directive",
  "target_update_clause_seq", "target_update_clause", "target_construct",
  "target_directive", "target_clause_multi", "target_clause",
  "target_data_construct", "target_data_directive",
  "target_data_clause_multi", "target_data_clause",
  "parallel_for_simd_construct", "parallel_for_simd_directive",
  "parallel_for_simd_clause_multi", "parallel_for_simd_clause",
  "for_simd_construct", "for_simd_directive", "for_simd_clause_multi",
  "for_simd_clause", "simd_construct", "simd_directive",
  "simd_clause_multi", "simd_clause", "task_construct", "task_directive",
  "task_clause_multi", "task_clause", "ordered_construct",
  "ordered_directive", "ordered_clause_multi", "atomic_construct",
  "atomic_directive", "critical_construct", "critical_directive",
  "master_construct", "master_directive", "parallel_sections_construct",
  "parallel_sections_directive", "parallel_sections_clause_multi",
  "parallel_sections_clause", "parallel_for_construct",
  "parallel_for_directive", "parallel_for_clause_multi",
  "parallel_for_clause", "single_construct", "single_directive",
  "single_clause_multi", "single_clause", "sections_construct",
  "sections_directive", "sections_clause_multi", "sections_clause",
  "section_construct", "section_directive", "for_construct",
  "for_directive", "for_clause_multi", "for_clause", "parallel_construct",
  "parallel_directive", "parallel_clause_multi", "parallel_clause",
  "omp_declare_reduction", "omp_threadprivate", "omp_barrier", "omp_flush",
  "flush_list", "omp_taskwait", "omp_taskyield", "omp_target_enter_data",
  "omp_target_enter_data_clause_multi", "omp_target_enter_data_clause",
  "omp_target_exit_data", "omp_target_exit_data_clause_multi",
  "omp_target_exit_data_clause", "omp_cancel", "omp_cancellation_point",
  "grainsize_clause", "num_tasks_clause", "uniform_clause",
  "dist_schedule_clause", "num_teams_clause", "thread_limit_clause",
  "motion_clause", "device_clause", "map_clause", "map_type",
  "safe_len_clause", "simd_len_clause", "final_clause", "untied_clause",
  "mergeable_clause", "depend_clause", "dependence_type",
  "priority_clause", "ordered_clause_opt", "atomic_clause",
  "seq_cst_clause", "region_phrase", "copy_private_clause",
  "ordered_clause", "schedule_clause", "schedule_kind",
  "num_threads_clause", "copyin_clause", "default_clause",
  "private_clause", "first_private_clause", "last_private_clause",
  "shared_clause", "reduction_clause", "linear_clause", "aligned_clause",
  "variable_array_section_list", "array_section",
  "array_section_subscript", "array_section_plain", "collapse_clause",
  "variable_list", "type_construct_clause", "if_clause", "procbind_clause",
  "reduction_identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-1059)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -12,     5,    76, -1059, -1059, -1059, -1059,    17, -1059,    17,
   -1059,    17, -1059, -1059, -1059,    17, -1059,    17, -1059, -1059,
   -1059, -1059, -1059,    17, -1059,    17, -1059,    17, -1059,    17,
   -1059,    17, -1059,    17, -1059,    17, -1059,    17, -1059, -1059,
   -1059, -1059, -1059,    17, -1059,    17, -1059,    17, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059,    17, -1059,    17,
   -1059,    17, -1059, -1059, -1059, -1059, -1059,  2386, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059,    17, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059,    17, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059,  3897, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059,   -61, -1059,  3281,   -25,  3302,  3302,  2694,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059,    16,    60,  3317, -1059,    -8,    -7,   276,    82,   293,
     -23,   -35,   -27,    93,   -15, -1059, -1059,   -85, -1059, -1059,
   -1059,   278,   100, -1059,    28, -1059, -1059, -1059,   725,   151,
      59,   -98,    80, -1059,    -5,   135,   140,    99,   134,   113,
     138,   -51,    26,   176,   159,  4444,  2694, -1059,  3317,  2694,
   -1059, -1059,   170, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059,   196,  4444, -1059,    30,    15, -1059,  4444,   205, -1059,
   -1059,   341,  3119,  3317,   353, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059,  3317, -1059, -1059,  3317,
    3317,  3317,  3317,  3317,  3317,  3317,  3317,  3317,  3317,  3317,
    3317,  3317,  3317,  3317,  3317,  3317,  3317,  3317,  3317, -1059,
     297, -1059,   519, -1059,  1119,   239, -1059,  1154,  2161,   201,
     306, -1059,   468, -1059,   264,   266,   275,   608, -1059, -1059,
   -1059, -1059,   242, -1059, -1059,   377,   236, -1059,   -10, -1059,
     240,   238, -1059,  3506,   339, -1059,     1, -1059,   175,   227,
   -1059, -1059, -1059,    56,   253, -1059, -1059, -1059, -1059,    -2,
      26,    56,   255,   258,   267,   262,  4444, -1059, -1059,   268,
    4421,   137,  2618,    32,   -60, -1059,    92, -1059,  3141, -1059,
   -1059,   272, -1059,   129, -1059, -1059, -1059, -1059, -1059,    -8,
      -8,    -7,    -7,   276,   276,   276,   276,    82,    82,   293,
     -23,   -35,   -27,    93,   282, -1059, -1059,  1249,   541,   281,
     286,   288,   290,   299,   301,   323,   327,   347, -1059,  1023,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059,   401, -1059,   350,   370,   381,   390, -1059,  1290, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059,   745, -1059, -1059, -1059, -1059, -1059,   398,   400,   415,
     421, -1059,  1325, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059,   428, -1059, -1059,   432, -1059,  2032, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
     436, -1059,   295, -1059, -1059, -1059, -1059,   446,  3557,  3788,
   -1059,   447,   451,   454,   653, -1059, -1059, -1059, -1059, -1059,
     -13, -1059, -1059,   204,  3007, -1059,   456,   460,   477, -1059,
    1978, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,   308,
     391, -1059, -1059, -1059, -1059,    -4, -1059,   785,   234, -1059,
    3745,   479,   489, -1059, -1059,  4408, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059,   568,   563,   499, -1059,   241, -1059,
   -1059, -1059, -1059, -1059, -1059,   591, -1059,   877,   512,   514,
   -1059,   629, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059,   303, -1059, -1059,   582,   520,   525,   318, -1059,
     531,  4372,   531,   532,  4421,   544,   495, -1059,    24, -1059,
   -1059,   548,  2518, -1059, -1059,   552,   567, -1059,  2781, -1059,
      32,    92,   566,  2812,  3063, -1059, -1059,  3317, -1059,  3317,
     486, -1059,  2661, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,  1357, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
     688,   -20,    56,    56,    56,    56,   165,  3317,   -11, -1059,
   -1059, -1059,  3902, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059,    56,  3317,   109,
    3317, -1059, -1059,    56,    56,  3317,   716, -1059,  3317,   719,
   -1059,    56, -1059, -1059,   696, -1059,   589,   599, -1059,  2220,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059,   616,   622, -1059,  4274, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059,  3317,   776,   776, -1059,   468, -1059,   633, -1059,   104,
   -1059, -1059, -1059, -1059,   250,   337,   730, -1059,  2304, -1059,
     647,   649, -1059,  1640, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059,    55,    56,   662, -1059,
   -1059, -1059, -1059,   654, -1059, -1059, -1059,   365, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059,   657, -1059, -1059,  4335, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059,   798,   813, -1059,
   -1059,  3612, -1059,  1744, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059,   681, -1059,   765,  1385, -1059,
    1412, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059,  3317,  3317, -1059, -1059,   825,   684, -1059, -1059,
     689,   686,   342, -1059,   692, -1059,  3233,  3317, -1059, -1059,
   -1059,    31,  3317, -1059,   -26, -1059,   694,   114,    33, -1059,
     695,  2518, -1059, -1059,  3317, -1059,   699, -1059, -1059, -1059,
    2518, -1059,   703,   717,  2865,  3317,   836,  3063, -1059, -1059,
    -104,  3223,    50, -1059, -1059, -1059, -1059,  3106, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,   705,   718,
     723,   354,   386,   393,   403, -1059, -1059, -1059,   764,   437,
     768,   773,   775, -1059,   448,   472, -1059, -1059,   490,   496,
     502,   502,   526,   783,   539,   790,   558,  3463, -1059,   746,
     786, -1059,  4092, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,    56,
     736, -1059,    56,   806, -1059,   562,   799,   578, -1059,   584,
   -1059,    56, -1059, -1059, -1059,    89, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059,   349, -1059, -1059, -1059, -1059, -1059,   892,
    3638, -1059,   808,   814, -1059,  4143, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059,    56,   816, -1059, -1059, -1059, -1059, -1059,   815,   590,
     595,   818,  3317, -1059,    56, -1059,   824,   827,  3530, -1059,
    3288, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059,   602, -1059,  3774,
   -1059,  1538, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,   613,   626,
   -1059, -1059, -1059,  3317, -1059,  4372,  3317, -1059, -1059,   817,
     828, -1059,    29, -1059,  3317,    27,  2944,   114, -1059,   811,
     812, -1059,   821,  2518, -1059, -1059,  3317, -1059,   826,   829,
   -1059,    62,  2886, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059,   776, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059,   261, -1059,  3317,   835,   839, -1059, -1059,
   -1059, -1059, -1059, -1059,   837,   844, -1059,  4047, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,    56,   857,
   -1059,   644,   846,   701,   848, -1059,   317,   849, -1059,   997,
   -1059,   709, -1059, -1059, -1059,  3693, -1059,   854,   855, -1059,
    4230, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
      56,   867, -1059,   711,   856,   776, -1059, -1059,   866,   714,
     726, -1059, -1059, -1059,  4117, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059,  3317,  3335, -1059,  4207,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059,  1004, -1059, -1059, -1059, -1059, -1059,   735,  2518,
   -1059,   858,   860,  2978, -1059, -1059, -1059,   861,   863, -1059,
   -1059,  3048, -1059, -1059, -1059,  3223,   738,   868,   870,   871,
   -1059, -1059,    56,   884, -1059,   741,   875, -1059,   890, -1059,
     891,   881,   883,   888,   317,   799, -1059, -1059,  3417, -1059,
     898,   900, -1059,  4162, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059,    56,   912, -1059,   743,   904, -1059,   911,
     747,   908, -1059, -1059, -1059,   751, -1059,   910,   917, -1059,
    3955, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059,   919, -1059,  1067,   918,
    2518, -1059, -1059,  3317, -1059,   920,   922, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059,   755,   928, -1059,   937,   931,   933,
     359,   392, -1059,   930, -1059,   939,   940, -1059,  4001, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059,    56,   947, -1059,   758,   938, -1059,   950,
     952, -1059, -1059, -1059,    56,   961, -1059,   936, -1059, -1059,
     949,   955, -1059, -1059, -1059,   969,   963, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059,    56,   972, -1059,   763,   962, -1059,
     976,   971, -1059,   770,   970, -1059, -1059, -1059,   973, -1059,
     778,   975, -1059,   983,   981, -1059, -1059,   991, -1059, -1059,
     992,   984, -1059,   985,   987, -1059, -1059, -1059
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     0,     2,     4,     5,   212,     0,   215,     0,
     214,     0,   213,   318,   234,     0,   233,     0,   232,   384,
     231,   395,   230,     0,   229,     0,   228,     0,   227,     0,
     226,     0,   225,     0,   224,     0,   223,     0,   222,   587,
     221,   606,   220,     0,   219,     0,   218,     0,   217,   673,
     216,   685,   211,   695,   210,   709,   209,     0,   208,     0,
     207,     0,   206,   772,   205,   787,   204,     0,   203,   794,
     202,   797,   201,   799,   200,     0,   198,   832,   197,   841,
     199,   851,   196,     0,   195,   868,   244,   243,   235,   236,
     237,   238,   241,   242,   239,   240,     0,     1,     3,   194,
     247,   268,   295,   337,   361,   397,   428,   459,   485,   505,
     531,   553,   572,   629,   648,   663,   718,   740,   759,     6,
      13,    12,    11,     0,    14,     0,     0,     0,     0,     0,
      39,    40,    41,    42,    43,    44,   192,    20,     7,     8,
      10,    32,    45,     0,    47,    51,    54,    57,    62,    65,
      67,    69,    71,    73,    75,    77,    90,     0,   792,   814,
     853,   872,   857,   845,     0,   763,   776,   836,   699,   946,
       0,     0,     0,   791,     0,   365,   667,     0,   677,     0,
       0,     0,   991,     0,     0,     0,     0,    36,     0,     0,
      33,    34,   131,    94,   128,    99,    98,    96,    97,    95,
     100,   101,   111,   112,   102,   103,   104,   105,    93,   129,
     130,     0,   119,   107,     0,   156,   106,   121,     0,    26,
      27,     0,     0,     0,     0,    86,    85,    83,    84,    80,
      81,    82,    87,    88,    89,    79,     0,    45,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   193,
     818,   803,     0,   744,     0,     0,   852,     0,     0,     0,
     322,   251,     0,   713,     0,     0,   591,     0,   944,   942,
     943,   945,   948,   798,   795,     0,     0,   885,     0,   388,
       0,     0,   341,     0,     0,   652,     0,   890,   576,     0,
     889,   396,   886,     0,     0,   987,   989,   988,   990,     0,
     991,     0,     0,     0,     0,     0,     0,     9,   118,   110,
       0,     0,     0,   150,   158,   155,   159,   120,     0,    25,
      22,     0,    30,     0,    24,    78,    48,    49,    50,    52,
      53,    56,    55,    60,    61,    58,    59,    63,    64,    66,
      68,    70,    72,    74,     0,    91,   722,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   869,     0,
     870,   875,   874,   876,   878,   879,   880,   881,   882,   873,
     877,     0,   866,     0,     0,     0,   951,   854,     0,   855,
     867,   858,   860,   859,   862,   863,   864,   865,   861,   850,
     842,     0,   843,   846,   847,   848,   849,     0,     0,     0,
       0,   760,     0,   761,   764,   765,   766,   769,   770,   767,
     768,   771,     0,   932,   933,     0,   773,     0,   774,   778,
     779,   780,   781,   782,   783,   784,   785,   786,   777,   840,
       0,   833,     0,   834,   837,   838,   839,   299,     0,     0,
     694,     0,     0,     0,     0,   687,   690,   691,   693,   692,
       0,   894,   903,   535,     0,   708,     0,     0,     0,   696,
       0,   697,   700,   701,   707,   703,   704,   702,   947,     0,
       0,   796,   941,   940,   788,     0,   789,     0,     0,   883,
       0,     0,     0,   379,   362,     0,   363,   372,   373,   375,
     377,   378,   383,   376,   381,   380,   371,   368,   369,   370,
     367,   382,   374,   366,   633,     0,     0,   664,     0,   665,
     668,   669,   670,   671,   672,     0,   557,     0,     0,     0,
     674,     0,   675,   678,   679,   680,   681,   682,   683,   684,
     985,   986,     0,   887,   909,     0,     0,     0,     0,    38,
      37,     0,     0,     0,     0,     0,     0,   113,     0,   117,
     177,     0,     0,   131,   161,    40,     0,   151,     0,   149,
     148,   157,     0,     0,     0,    46,    23,     0,    21,     0,
       0,   815,     0,   816,   828,   829,   820,   821,   823,   824,
     825,   831,   826,   827,   830,   819,   822,   800,     0,   801,
     805,   806,   808,   809,   810,   811,   812,   813,   804,   807,
       0,     0,     0,     0,     0,     0,   938,     0,     0,   871,
     757,   741,     0,   742,   747,   748,   758,   745,   751,   746,
     753,   754,   755,   756,   749,   750,   752,     0,     0,   958,
       0,   856,   844,     0,     0,     0,     0,   762,     0,     0,
     775,     0,   835,   272,     0,   336,     0,     0,   319,     0,
     320,   323,   324,   330,   331,   333,   326,   327,   334,   335,
     325,   332,   267,     0,     0,   248,     0,   249,   252,   253,
     260,   261,   259,   255,   256,   264,   265,   262,   263,   266,
     254,     0,     0,     0,   686,     0,   688,     0,   710,     0,
     711,   714,   715,   716,     0,     0,     0,   509,     0,   605,
       0,     0,   588,     0,   589,   600,   601,   592,   593,   599,
     602,   595,   596,   603,   604,   594,     0,     0,     0,   698,
     793,   949,   790,     0,   393,   394,   385,     0,   386,   392,
     389,   390,   391,   996,  1003,  1004,  1006,  1005,  1000,   998,
     997,   999,  1001,  1002,     0,   355,   338,     0,   339,   348,
     349,   356,   357,   351,   353,   354,   352,   347,   344,   345,
     346,   343,   360,   358,   359,   350,   342,     0,     0,   364,
     610,     0,   649,     0,   650,   653,   658,   659,   654,   655,
     656,   662,   660,   661,   657,     0,   666,   489,     0,   573,
       0,   574,   584,   577,   578,   579,   580,   581,   585,   582,
     583,   586,     0,     0,   676,   888,     0,     0,   910,   912,
       0,     0,     0,    16,     0,   127,     0,     0,   108,   114,
     134,     0,     0,   115,     0,   122,   126,   133,     0,   160,
       0,     0,   162,   168,     0,   167,     0,   152,   147,   178,
       0,   169,    40,     0,     0,     0,     0,     0,   181,   183,
       0,     0,     0,   187,    31,    76,   719,     0,   720,   733,
     734,   732,   737,   724,   725,   727,   728,   729,   739,   730,
     731,   735,   736,   738,   723,   726,   817,   802,     0,     0,
       0,     0,     0,     0,     0,   935,   936,   937,     0,     0,
       0,     0,     0,   743,     0,     0,   956,   957,     0,     0,
     246,   246,     0,     0,     0,     0,     0,     0,   317,     0,
       0,   296,     0,   297,   300,   301,   307,   313,   314,   308,
     310,   303,   304,   316,   311,   312,   315,   302,   309,     0,
       0,   321,     0,     0,   250,     0,   970,     0,   971,     0,
     689,     0,   712,   899,   891,     0,   892,   896,   897,   898,
     895,   908,   900,     0,   901,   905,   906,   907,   904,   463,
       0,   552,     0,     0,   532,     0,   533,   549,   544,   545,
     536,   537,   543,   546,   539,   540,   550,   547,   548,   551,
     538,     0,     0,   590,   926,   927,   925,   928,     0,     0,
       0,     0,     0,   387,     0,   340,     0,     0,     0,   630,
       0,   631,   647,   643,   644,   635,   636,   638,   639,   640,
     646,   641,   642,   645,   634,   637,   651,     0,   432,     0,
     554,     0,   555,   565,   558,   559,   568,   569,   560,   561,
     562,   566,   563,   564,   570,   571,   567,   575,     0,     0,
     984,   911,   884,     0,    15,     0,     0,   109,    92,     0,
       0,   124,     0,   116,     0,     0,     0,   132,   164,     0,
       0,   166,     0,     0,   170,   176,     0,   175,     0,     0,
     190,     0,     0,    28,   182,   186,   188,   721,   959,   961,
     962,   963,   964,   966,   960,     0,   992,   993,   994,   995,
     965,   983,   953,     0,   952,     0,     0,     0,   929,   930,
     931,   939,   950,   294,     0,     0,   269,     0,   270,   273,
     274,   287,   288,   280,   286,   291,   281,   283,   276,   277,
     293,   284,   285,   289,   290,   292,   275,   282,     0,     0,
     298,     0,     0,     0,     0,   922,     0,   974,   920,     0,
     921,     0,   893,   902,   401,     0,   530,     0,     0,   506,
       0,   507,   523,   518,   519,   510,   511,   526,   527,   517,
     520,   513,   514,   524,   521,   522,   528,   529,   525,   512,
       0,     0,   534,     0,     0,     0,   924,   705,     0,     0,
       0,   913,   914,   607,     0,   608,   611,   622,   623,   621,
     626,   613,   614,   616,   617,   618,   628,   619,   620,   624,
     625,   627,   612,   615,   632,   916,     0,     0,   486,     0,
     487,   504,   490,   491,   500,   501,   498,   492,   493,   494,
     503,   495,   496,   502,   497,   499,   556,   918,   919,    19,
      17,    18,     0,   135,   123,   125,   153,   145,     0,     0,
     136,    40,     0,     0,   163,   165,   172,     0,     0,   173,
     189,     0,   179,    29,   185,     0,     0,     0,     0,   245,
     968,   969,     0,     0,   271,     0,     0,   328,     0,   257,
       0,   977,   978,     0,     0,   972,   973,   717,     0,   484,
       0,     0,   460,     0,   461,   478,   464,   465,   479,   480,
     483,   474,   475,   472,   466,   467,   468,   477,   469,   470,
     476,   471,   473,     0,     0,   508,     0,     0,   597,     0,
       0,     0,   915,   967,   609,     0,   458,     0,     0,   429,
       0,   430,   433,   456,   457,   451,   452,   444,   445,   455,
     443,   448,   435,   436,   438,   439,   440,   450,   441,   442,
     446,   447,   449,   434,   437,   488,     0,   146,     0,     0,
       0,   137,   144,     0,   143,    40,     0,   171,   174,   180,
     184,   934,   955,   954,     0,     0,   305,     0,     0,     0,
       0,     0,   976,     0,   427,     0,     0,   398,     0,   399,
     402,   425,   426,   420,   421,   413,   414,   424,   412,   417,
     404,   405,   407,   408,   409,   419,   410,   411,   415,   416,
     418,   403,   406,     0,     0,   462,     0,     0,   541,     0,
       0,   923,   706,   917,     0,     0,   431,     0,   154,   139,
       0,     0,   140,   142,   278,     0,     0,   329,   258,   979,
     980,   981,   982,   975,     0,     0,   400,     0,     0,   515,
       0,     0,   598,     0,     0,   191,   138,   141,     0,   306,
       0,     0,   481,     0,     0,   542,   453,     0,   279,   422,
       0,     0,   516,     0,     0,   482,   454,   423
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1059, -1059,  1135, -1059, -1059, -1059, -1059, -1059,    83, -1059,
     142,  2335, -1059,  -112,   667,   693,   195,   691,   894,   887,
     896,   903,   886, -1059,  -564,  -187, -1059,   -63,  -814, -1059,
   -1059, -1059,   597,  -548,  -206, -1059,    97, -1059,  -313,   324,
     322,  -210,  -320, -1059,  -108,   841,   840,  -849,   309, -1058,
   -1059,   312, -1059, -1059,  3892, -1059, -1059,   252, -1059, -1059,
   -1059,   501, -1059, -1059, -1059,    48, -1059, -1059, -1059,   249,
   -1059, -1059, -1059,   516, -1059, -1059, -1059,   422, -1059, -1059,
   -1059,   683, -1059, -1059, -1059,   443, -1059, -1059, -1059, -1059,
   -1059,  -207, -1059, -1059, -1059,  -148, -1059, -1059, -1059,  -109,
   -1059, -1059, -1059,   -34, -1059, -1059, -1059,    38, -1059, -1059,
   -1059,   211, -1059, -1059, -1059,   158, -1059, -1059, -1059,   405,
   -1059, -1059, -1059,   497, -1059, -1059, -1059,     9, -1059, -1059,
   -1059,   182, -1059, -1059, -1059,   429, -1059, -1059, -1059,   697,
   -1059, -1059, -1059,   682, -1059, -1059, -1059,  -437, -1059, -1059,
   -1059,   748, -1059, -1059, -1059,   517, -1059, -1059, -1059,   356,
   -1059, -1059, -1059,   604, -1059, -1059, -1059,   805, -1059, -1059,
   -1059,   800, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059,   630, -1059, -1059, -1059,   655, -1059,
   -1059, -1059,   789, -1059, -1059, -1059,   842, -1059, -1059, -1059,
   -1059, -1059,   852, -1059, -1059, -1059,   872, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059,   287, -1059, -1059,   273,
   -1059, -1059,  -476,  -474, -1059,  1477,  -370,   978, -1059,   924,
    1208, -1059,   481,   116,  -273,  -271,  -267,  -239, -1059,  -256,
     766, -1059, -1059, -1059, -1059,  1210,   430, -1059,  -219,   -49,
    1006,   545,   760,   771,  1313,  -174,  1241,  1453,  -686,    96,
   -1059,   -36,   926,  -309,   942,  -249,  1232, -1059
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,   137,   138,   139,   140,   822,   823,   141,
     331,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   236,   211,  1059,   212,
     213,   214,   556,   557,   215,   834,   835,   216,   217,   836,
     837,   838,   568,  1248,   824,   325,   326,   859,   860,   861,
     862,   863,   559,   158,   100,     4,     5,  1106,     6,     7,
     449,   677,     8,     9,   917,  1118,    10,    11,   654,   923,
      12,    13,   448,   660,    14,    15,   490,   758,    16,    17,
     293,   496,    18,    19,   487,   738,    20,    21,    22,    23,
    1288,  1389,    24,    25,  1217,  1331,    26,    27,  1155,  1294,
      28,    29,  1029,  1220,    30,    31,   970,  1161,    32,    33,
     708,   976,    34,    35,   798,  1032,    36,    37,   527,   801,
      38,    39,   464,   714,    40,    41,  1008,  1195,    42,    43,
     781,  1011,    44,    45,   515,   784,    46,    47,   296,   519,
      48,    49,   299,   532,    50,    51,   454,   455,    52,    53,
     277,   471,    54,    55,   460,   700,    56,    57,   580,   868,
      58,    59,   381,   623,    60,    61,   267,   413,    62,    63,
     268,   428,    64,    65,   288,    66,    67,    68,    69,    70,
      71,    72,    73,   358,   599,    74,    75,   357,   583,    76,
      77,   269,   443,    78,    79,   265,   402,    80,    81,    82,
      83,   264,   389,    84,    85,   262,   370,    86,    87,    88,
      89,   304,    90,    91,    92,   704,   956,    93,   705,   964,
      94,    95,   497,   498,   739,   520,   533,   534,   456,   457,
     473,   998,   414,   415,   429,   430,   431,   458,   898,   433,
     486,   282,   479,   286,   444,   391,   392,   908,   372,   373,
     374,   375,   376,   396,   377,   378,   419,   420,   947,   948,
    1147,  1283,   398,   542,   309,   459,   380,   754
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     291,   314,   548,   570,   157,   324,   318,   949,   829,   567,
     567,   327,  1084,   379,   759,   865,   760,   696,  1061,   438,
     499,   218,   500,   371,  1265,   390,   501,   830,   477,   432,
    1246,   238,   830,   319,   830,   332,   830,   503,   474,   256,
     999,  1079,   563,     1,   513,   393,  1082,   194,   284,   335,
     285,   482,  1083,   889,   502,   900,   289,   482,   946,   540,
     546,    96,   541,   209,   210,   258,   219,   220,   221,   366,
     290,   355,   361,   362,   505,    99,    97,   312,   313,   383,
     366,   315,   384,   305,   306,   307,   259,   185,   321,   451,
     397,   406,   322,   418,   715,   302,   466,   303,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   595,   608,
     890,   324,   483,   569,   558,   516,   246,   247,   483,   511,
     379,   901,   902,   188,  1062,   539,   697,   336,   337,   338,
     371,     1,   253,   698,   252,   566,   484,   699,   586,   600,
     485,   254,   626,   308,   544,  1063,   255,   517,   545,   390,
     239,   518,   242,   243,   257,   240,   241,   803,   994,   995,
     333,   263,   629,   321,   222,   953,   365,   322,   223,   393,
     224,   366,   831,   323,   266,   832,  1247,   831,   438,   831,
     832,   831,   323,   593,   607,   320,   366,   323,   432,   323,
     323,   451,   996,   997,   354,   833,   292,   294,   466,   670,
     690,   295,   855,  1265,   856,   283,   451,   633,   553,   663,
     682,   703,  1261,   466,   397,   725,   575,   763,  1262,   764,
    1085,   477,   499,   765,   500,   719,   287,   406,   501,   664,
     235,   474,   525,  1264,   766,   298,   526,   743,   418,   503,
     572,   776,   841,   697,   573,   297,   513,   248,   249,   567,
    1245,   278,   906,   854,   907,   847,   502,   847,   950,   300,
     567,   706,  1065,  1058,  1267,   707,  1066,  1268,  1058,   279,
     280,   281,   361,   362,   669,   686,   505,   439,   829,   258,
     440,   759,   578,   760,   301,   321,   560,   744,   745,   322,
     724,  1058,   895,   896,   897,   323,   817,   360,   361,   362,
     363,   310,   290,   891,   892,   893,   894,   311,   587,   601,
     361,   362,   361,   362,   290,   399,   772,   383,   316,   383,
    1281,   511,   384,  1282,   244,   245,   953,   365,   904,   250,
     251,   884,   366,   595,   910,   911,   260,   261,   978,   528,
     529,   791,   916,   715,   329,   317,   258,   441,   558,   608,
     558,   442,   451,   810,   328,   516,   334,   539,   356,   466,
     848,   873,  1439,   586,   447,  1440,   361,   362,   746,   747,
     461,   439,   462,   530,   440,   840,   463,   531,   478,   600,
     480,   846,   481,   626,   489,   400,   853,   858,   488,   401,
     864,   748,   749,   750,   751,  1441,   954,   514,  1442,   543,
     955,   752,   753,   629,   549,   937,   880,   550,   593,  1266,
     670,   552,  1264,   961,   365,   926,  1370,   551,  1000,   366,
     663,   576,   577,   554,   607,   961,   365,   690,  1034,   610,
     803,   366,   258,   579,   611,   929,   612,   682,   613,   451,
     664,   343,   344,   345,   346,   407,   466,   614,   633,   615,
     703,   451,   815,   816,   730,   960,   968,   408,   466,   990,
     410,   733,   734,   735,   725,   959,   967,   820,   816,   982,
     359,   616,   361,   362,   719,   617,   290,   620,   365,   383,
     935,   407,   384,   962,   763,   669,   764,   963,   385,   386,
     765,  1054,  1055,   408,   409,   618,   410,   625,   637,  1320,
    1058,   766,   686,  1091,   816,   192,   555,   653,   776,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   638,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   847,   639,
    1073,   874,  1024,   587,   988,  1092,   816,   567,   640,   724,
     731,   847,  1093,   816,   450,   365,   643,   621,   644,   601,
     366,   622,  1094,   816,   899,   359,   360,   361,   362,   363,
     364,   290,  1015,   645,   383,   681,   407,   384,   366,   646,
     451,   452,   453,   385,   386,   905,   648,   909,   408,   409,
     649,   410,   912,   772,   651,   914,  1096,   258,   359,   360,
     361,   362,   363,   364,   290,   691,   365,  1100,   816,   692,
    1163,   366,   693,   740,   726,   978,   762,  1022,   727,   791,
     359,   360,   361,   362,   363,   364,   290,   367,   884,   383,
     558,  1101,   258,   366,  1043,   728,   810,   777,   945,   780,
    1141,   787,   866,  1143,   361,   362,   867,   778,   290,  1102,
    1103,   383,  1151,   407,   384,  1104,   258,   795,   873,   797,
     367,   828,   816,  1105,  1069,   408,   409,  1070,   410,  1222,
     812,  1034,   813,  1072,   366,   368,   818,  1078,  1136,   369,
     858,   819,   367,   937,   858,  1108,   258,   516,  1123,   361,
     362,   825,  1183,   926,   465,   365,   574,   597,  1110,   258,
     366,   598,   827,   880,   888,  1190,   870,   839,  1126,   360,
     361,   362,   363,   929,   290,   842,   960,  1112,   816,   782,
     451,  1145,   258,   783,   968,   849,   959,   466,   467,   468,
     843,  1179,   913,   504,   967,   915,   990,  1148,  1149,   450,
     365,  1169,  1016,  1150,  1149,   366,   982,   939,   625,  1186,
    1149,   528,   529,  1132,  1187,   816,  1253,   940,   935,  1048,
    1049,  1215,  1216,   567,   469,   451,   452,   453,   470,  1212,
     847,  1024,  1237,   258,   942,   359,   360,   361,   362,   363,
     943,   290,   918,   365,   383,  1238,   258,   384,   366,   946,
    1234,   951,   270,   385,   386,  1296,   271,   585,   969,  1201,
    1163,  1015,   681,  1277,   816,   991,  1175,   992,   451,   694,
    1001,   988,  1002,   695,  1006,   466,   919,   920,  1004,   394,
     403,   628,   416,   435,   445,   332,   361,   362,   874,  1007,
     290,   399,   475,   383,  1027,   272,  1028,   367,  1050,  1275,
    1051,   273,   274,   275,  1208,  1052,  1022,  1053,   507,  1080,
     276,   521,   921,  1056,   536,  1064,   922,  1333,  1068,  1222,
    1279,   816,  1071,   740,  1088,  1232,  1074,  1043,  1287,   816,
    1318,   816,   624,  1322,   577,   407,  1239,  1089,  1136,  1241,
    1075,  1316,  1090,   762,  1142,  1323,   816,   408,  1123,  1252,
     410,   733,   734,   735,  1357,  1358,  1257,  1371,  1149,  1258,
    1376,   816,  1418,   816,  1138,   858,  1421,  1149,  1126,   787,
    1423,   258,   589,   603,  1434,   816,  1311,  1449,   816,   339,
     340,  1179,  1462,   816,  1037,  1095,  1300,  1097,  1391,  1466,
     816,  1169,  1098,  1296,  1099,   504,   630,  1469,   816,  1360,
     680,   736,  1109,   394,  1139,   737,   567,   341,   342,  1111,
     847,   347,   348,  1132,  1144,  1212,   403,   360,   361,   362,
     363,  1146,   290,  1154,  1184,   383,  1180,   416,   384,  1202,
    1333,  1016,  1181,  1374,  1254,  1255,  1185,  1242,  1353,  1188,
    1234,   761,   435,  1191,  1256,  1201,  1192,  1243,  1339,  1259,
    1226,  1309,  1260,   870,  1270,  1272,  1175,   445,  1271,   528,
     529,   516,  1273,   666,   683,  1276,   786,  1278,  1342,  1280,
    1285,  1284,  1313,  1314,  1416,  1317,  1321,  1319,  1356,   721,
     872,  1361,   585,  1362,  1367,   475,  1368,  1372,  1391,  1373,
    1208,   258,  1375,   799,   395,   404,  1377,   800,   436,   446,
    1378,  1379,  1380,  1122,  1381,   768,   405,   476,   417,  1411,
     507,  1382,  1269,  1349,  1311,  1232,  1413,   847,  1414,  1397,
    1417,  1420,   628,   508,  1300,  1419,   522,  1422,  1424,   537,
     788,   869,  1359,   521,   509,  1425,  1366,   523,  1427,  1400,
    1428,  1429,   806,  1432,   858,  1433,   536,  1436,   858,  1435,
    1437,  1353,  1438,  1443,   928,  1448,  1168,  1444,  1445,  1450,
    1451,  1339,   359,   360,   361,   362,   363,   364,   290,  1454,
     365,  1452,  1456,   624,  1447,   366,  1303,  1455,  1457,  1458,
    1461,  1342,  1459,  1463,  1407,  1453,  1464,   590,   604,  1309,
    1465,  1467,  1468,  1471,  1198,   876,  1470,   589,   591,   605,
    1472,  1473,  1474,  1475,  1476,  1460,  1477,    98,  1240,  1411,
     350,   631,   353,   603,  1189,  1202,   349,  1037,   395,  1397,
     351,   826,   632,  1325,   367,  1060,  1349,   680,   352,  1244,
    1067,   404,   561,  1107,   571,  1274,  1081,   630,  1343,  1400,
    1226,  1140,   405,  1430,  1086,   941,  1431,   944,   779,  1005,
    1003,  1446,  1426,   417,  1415,  1355,  1182,   436,   359,  1236,
     361,   362,  1214,   421,   290,   382,   365,   383,  1315,   931,
     384,   472,   446,  1324,   666,  1047,   385,   386,   667,   684,
     993,  1014,  1026,   814,  1407,   796,   952,   647,   729,   512,
     685,   683,   524,  1087,   722,   361,   903,   650,   887,   290,
     476,   652,   383,  1122,   407,   384,  1153,   886,   761,  1401,
     641,   619,  1152,   642,  1303,  1286,   408,   409,  1383,   410,
     769,   732,   547,   984,     0,   508,     0,     0,   721,     0,
       0,   770,     0,     0,   786,   387,   509,     0,     0,   388,
       0,     0,     0,     0,   434,   789,  1168,     0,   522,  1036,
       0,  1343,     0,   594,     0,     0,   790,   807,     0,   523,
       0,   537,     0,     0,     0,     0,     0,   872,   808,   506,
     411,     0,   768,     0,   412,   535,     0,   636,     0,     0,
    1198,     0,     0,     0,     0,     0,     0,     0,   359,   360,
     361,   362,   363,   364,   290,     0,  1018,   383,   788,     0,
     384,   366,     0,  1338,     0,     0,   385,   386,   421,  1401,
     877,     0,   590,  1039,     0,   806,     0,  1125,   869,     0,
       0,   878,   928,   591,     0,     0,     0,     0,   604,   359,
       0,   361,   362,   588,   602,   290,   382,   365,   383,   605,
       0,   384,   661,   678,     0,   689,     0,   385,   386,     0,
     367,     0,   631,     0,   701,     0,     0,     0,   717,     0,
       0,     0,     0,   632,   472,   581,   361,     0,  1121,   582,
     290,     0,     0,   383,  1396,   407,   384,     0,     0,     0,
       0,     0,   876,     0,   932,     0,   775,   408,   409,   667,
     410,   512,     0,     0,     0,   933,   359,   360,   361,   362,
     363,   364,   290,   434,     0,   383,   684,     0,  1200,   366,
    1014,   794,   716,     0,   524,     0,  1338,   685,     0,     0,
       0,  1167,     0,   811,   665,   360,   361,   362,   363,  1225,
     290,     0,  1128,   383,     0,   407,   384,   931,   985,     0,
     720,     0,     0,   722,     0,     0,     0,   408,   409,   986,
     410,     0,   360,   361,   362,   363,     0,   290,   367,  1197,
     383,     0,     0,   384,     0,     0,   767,   528,   529,   516,
       0,   506,     0,     0,  1396,   804,   883,     0,   594,     0,
       0,     0,  1036,     0,     0,  1171,     0,   769,     0,     0,
     984,     0,     0,     0,   528,   529,   516,     0,   770,     0,
       0,  1030,     0,   805,     0,  1031,     0,   535,     0,     0,
       0,  1019,     0,   789,     0,     0,     0,  1125,   636,     0,
       0,     0,  1020,  1204,   790,  1018,     0,     0,  1040,     0,
     807,     0,     0,     0,     0,     0,     0,   584,     0,  1041,
       0,   808,     0,     0,  1228,     0,  1039,     0,   924,     0,
     936,   437,     0,   661,     0,  1302,   875,     0,   588,   596,
     609,   627,     0,     0,     0,     0,     0,     0,  1121,     0,
     678,     0,   689,     0,   602,     0,   510,     0,   360,   361,
     362,   363,   538,   290,     0,     0,   383,     0,   407,   384,
       0,     0,   634,   701,  1200,     0,     0,   877,   957,   965,
     408,   409,   980,   410,   989,     0,     0,   717,   878,     0,
       0,  1167,     0,     0,     0,     0,     0,  1341,     0,  1225,
     528,   529,   516,     0,     0,     0,   662,   679,     0,     0,
     930,     0,  1128,     0,     0,   665,     0,     0,   702,     0,
     592,   606,   718,     0,     0,  1197,     0,  1129,     0,     0,
     671,     0,   932,   775,     0,     0,   979,     0,  1130,     0,
     687,   716,     0,   933,     0,     0,     0,     0,  1337,     0,
    1305,     0,     0,     0,     0,  1171,     0,  1023,     0,   794,
     360,   361,   362,   363,   983,   290,   709,   365,  1399,   720,
       0,     0,   366,  1302,  1046,     0,   811,     0,   741,     0,
    1172,   773,     0,     0,     0,   985,     0,     0,     0,  1204,
     437,  1173,   451,     0,     0,     0,   986,     0,     0,   466,
     710,   711,   528,   529,     0,     0,   792,     0,     0,     0,
    1341,   668,  1345,   767,  1228,     0,     0,     0,  1205,  1395,
    1019,     0,     0,     0,     0,     0,  1035,   723,   804,  1206,
       0,  1020,     0,     0,     0,     0,     0,  1017,     0,  1229,
     871,  1040,   584,   883,     0,     0,     0,     0,     0,     0,
    1230,     0,  1041,   771,  1038,     0,   805,     0,   510,     0,
       0,  1337,   885,     0,   596,   361,   362,     0,  1399,   290,
       0,   881,   383,     0,   407,   384,     0,     0,     0,     0,
     609,     0,   627,  1403,   635,     0,   408,   409,  1305,   410,
     809,  1119,     0,  1135,   538,     0,   924,     0,   936,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   516,     0,
       0,     0,   925,   634,   927,     0,     0,   662,     0,  1395,
       0,     0,     0,   875,     0,  1345,     0,  1129,     0,   957,
       0,     0,     0,     0,   679,     0,   938,   965,  1130,     0,
       0,   671,     0,   879,  1165,   592,  1178,     0,     0,   980,
       0,   989,   688,     0,     0,     0,     0,   702,     0,     0,
       0,   606,   958,   966,     0,  1306,   981,   687,     0,     0,
    1172,   718,     0,  1127,     0,     0,  1307,     0,   930,     0,
       0,  1173,     0,  1403,  1211,     0,  1023,     0,     0,     0,
     742,     0,     0,   774,     0,     0,     0,     0,  1164,     0,
       0,     0,     0,   979,  1205,  1233,     0,  1046,     0,     0,
       0,     0,     0,     0,     0,  1206,     0,   934,   793,     0,
       0,     0,   668,     0,     0,     0,  1170,  1346,   741,  1229,
       0,   983,     0,     0,     0,     0,     0,     0,  1347,     0,
    1230,  1013,   785,     0,     0,     0,     0,     0,   773,     0,
       0,     0,     0,     0,   802,     0,     0,  1223,     0,  1035,
       0,     0,     0,  1025,  1203,     0,  1017,     0,     0,     0,
       0,   987,     0,     0,   792,     0,   723,     0,     0,     0,
       0,     0,     0,   882,     0,  1227,     0,  1038,     0,  1044,
       0,  1119,     0,  1135,     0,     0,     0,     0,  1404,   361,
     362,     0,     0,  1306,   465,   365,     0,     0,     0,  1405,
     366,     0,     0,     0,  1307,     0,     0,     0,     0,     0,
     771,     0,     0,     0,     0,   635,     0,   871,     0,  1298,
     451,  1310,     0,     0,  1165,     0,  1178,   466,   467,   468,
    1346,     0,     0,     0,  1021,     0,     0,     0,     0,   885,
       0,  1347,   360,   361,   362,   363,     0,     0,   881,   365,
       0,  1042,     0,   809,   366,   422,   423,   424,   425,     0,
    1211,     0,     0,  1127,     0,  1120,     0,  1124,     0,   688,
     925,     0,   927,  1297,     0,     0,     0,     0,  1164,     0,
       0,  1335,     0,  1352,     0,  1233,     0,     0,  1404,  1137,
       0,     0,     0,     0,   938,     0,     0,     0,  1133,  1405,
       0,  1304,     0,   958,     0,     0,  1170,     0,     0,     0,
       0,   966,     0,     0,     0,     0,     0,     0,  1166,     0,
     879,     0,     0,   981,     0,   977,     0,     0,     0,     0,
     742,     0,     0,     0,     0,  1334,     0,  1223,     0,     0,
    1203,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     774,  1176,  1393,     0,  1410,     0,     0,  1298,  1199,  1310,
    1013,     0,     0,  1344,     0,  1227,     0,     0,     0,     0,
    1131,   360,   361,   362,   363,   934,   793,     0,   365,  1224,
    1213,     0,  1025,   366,   422,   423,   424,   425,     0,  1209,
       0,  1045,     0,     0,  1335,     0,  1352,     0,  1012,     0,
     785,  1235,     0,     0,     0,     0,  1392,     0,     0,     0,
       0,  1297,  1044,     0,     0,  1033,     0,   802,     0,     0,
       0,     0,     0,  1174,     0,     0,     0,     0,   987,   359,
     360,   361,   362,   363,  1402,   290,   655,   365,     0,  1304,
       0,     0,   366,     0,     0,     0,     0,   426,  1334,     0,
       0,   427,  1393,     0,  1410,     0,     0,     0,     0,     0,
     882,  1207,   451,  1021,     0,  1120,     0,  1124,     0,   466,
     656,   657,     0,     0,     0,     0,  1344,     0,     0,     0,
       0,     0,  1231,     0,  1042,     0,     0,     0,     0,  1137,
       0,   367,     0,     0,     0,     0,     0,     0,  1133,     0,
       0,     0,     0,  1299,     0,  1301,  1392,     0,  1166,     0,
    1134,     0,     0,     0,   360,   361,   362,   363,     0,   290,
     971,   365,   383,     0,     0,   384,   366,  1312,     0,   119,
     120,   121,   122,     0,  1402,   123,     0,     0,     0,   124,
       0,  1176,     0,     0,  1199,     0,   451,     0,     0,   125,
       0,     0,     0,   466,   972,   973,   528,   529,   516,   126,
       0,     0,     0,  1177,     0,  1336,  1213,  1340,     0,  1224,
    1131,     0,     0,     0,     0,  1209,   127,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1162,     0,  1354,
     974,  1235,   977,     0,   975,     0,     0,     0,  1350,     0,
     187,  1210,   190,   191,     0,     0,     0,     0,  1308,     0,
       0,     0,     0,  1174,     0,     0,     0,     0,   237,     0,
       0,     0,     0,     0,  1045,  1196,     0,  1012,     0,     0,
       0,     0,     0,     0,     0,     0,  1394,     0,  1398,     0,
       0,  1299,     0,  1301,     0,     0,  1221,  1207,  1033,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1412,   119,   120,   121,   122,  1312,     0,   123,   563,  1408,
    1348,   124,  1231,   194,   129,     0,     0,     0,  1336,     0,
    1340,   125,     0,   130,   131,   132,   133,   134,   135,   209,
     210,   126,     0,     0,     0,     0,     0,   136,     0,     0,
       0,     0,  1354,     0,     0,     0,     0,     0,   127,   128,
    1134,  1350,     0,     0,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,     0,     0,     0,     0,  1394,     0,  1398,     0,
       0,  1406,     0,     0,     0,     0,  1308,     0,     0,     0,
       0,     0,     0,  1177,     0,     0,     0,     0,     0,     0,
    1412,   119,   120,   121,   122,     0,   562,   123,   563,  1408,
       0,   124,  1295,   194,     0,     0,     0,  1162,     0,     0,
       0,   125,     0,  1348,     0,     0,     0,  1210,     0,   209,
     210,   126,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   237,     0,     0,   129,     0,   127,   128,
    1351,  1196,     0,     0,     0,   130,   131,   132,   133,   134,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1332,     0,  1221,   119,   120,   121,
     122,  1406,     0,   123,   192,     0,     0,   124,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   125,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   126,     0,     0,
     359,   360,   361,   362,   363,   364,   290,     0,     0,   383,
       0,  1409,   384,   366,   127,   128,     0,     0,   385,   386,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1390,   129,     0,     0,     0,
    1295,   564,     0,     0,     0,   130,   565,   132,   133,   134,
     135,     0,     0,  1351,   119,   120,   121,   122,     0,   844,
     123,   563,   367,     0,   124,     0,   194,     0,     0,     0,
       0,     0,     0,     0,   125,     0,     0,  1332,     0,     0,
       0,     0,   209,   210,   126,   119,   120,   121,   122,     0,
     850,   123,   563,     0,     0,   124,     0,   194,     0,     0,
       0,   127,   128,     0,     0,   125,     0,     0,     0,     0,
       0,  1409,   129,   209,   210,   126,     0,     0,     0,     0,
       0,   130,   131,   132,   133,   134,   135,     0,     0,     0,
       0,     0,   127,   128,     0,  1390,     0,     0,   119,   120,
     121,   122,     0,  1076,   123,   563,     0,     0,   124,     0,
     194,     0,     0,     0,     0,     0,     0,     0,   125,   119,
     120,   121,   122,     0,     0,   123,   209,   210,   126,   124,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   125,
       0,     0,     0,     0,   237,   127,   128,     0,     0,   126,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
       0,     0,     0,     0,   845,     0,   127,   128,   130,   131,
     132,   133,   134,   135,     0,     0,     0,   119,   120,   121,
     122,     0,  1249,   123,   563,     0,     0,   124,     0,   194,
     129,     0,     0,     0,     0,   851,     0,   125,     0,   130,
     852,   132,   133,   134,   135,   209,   210,   126,     0,     0,
       0,   119,   120,   121,   122,     0,  1363,   123,   563,     0,
       0,   124,     0,   194,   127,   128,     0,     0,     0,     0,
       0,   125,     0,     0,     0,     0,     0,     0,     0,   209,
     210,   126,     0,   129,     0,     0,     0,     0,  1077,     0,
       0,     0,   130,   131,   132,   133,   134,   135,   127,   128,
       0,     0,     0,     0,   129,     0,     0,     0,   855,     0,
     856,   857,  1263,   130,   131,   132,   133,   134,   135,     0,
       0,   119,   120,   121,   122,     0,     0,   123,     0,     0,
       0,   124,     0,     0,     0,     0,   119,   120,   121,   122,
       0,   125,   123,     0,     0,     0,   124,   360,   361,   362,
     363,   126,   290,   709,   365,     0,   125,     0,     0,   366,
       0,     0,   129,     0,     0,     0,   126,  1250,   127,   128,
       0,   130,  1251,   132,   133,   134,   135,     0,     0,   451,
       0,     0,     0,   127,   128,     0,   466,   710,   711,   528,
     529,     0,   119,   120,   121,   122,   129,     0,   123,     0,
       0,  1364,   124,     0,     0,   130,  1365,   132,   133,   134,
     135,     0,   125,     0,   119,   120,   121,   122,     0,     0,
     123,     0,   126,   712,   124,     0,     0,   713,     0,     0,
       0,     0,   237,     0,   125,     0,     0,   237,     0,   127,
     128,     0,     0,     0,   126,   359,   360,   361,   362,   363,
     364,   290,     0,     0,   383,     0,   407,   384,   366,     0,
     237,   127,   128,   385,   386,     0,   129,     0,   408,   409,
     855,   410,   856,   857,  1369,   130,   131,   132,   133,   134,
     135,   129,     0,     0,     0,   855,     0,   856,   857,     0,
     130,   131,   132,   133,   134,   135,   119,   120,   121,   122,
       0,     0,   123,     0,     0,     0,   124,   367,     0,     0,
       0,     0,     0,   192,   555,     0,   125,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   126,   202,   203,   204,
     205,   206,   207,   208,   209,   210,     0,   129,   330,     0,
       0,     0,     0,   127,   128,     0,   130,   131,   132,   133,
     134,   135,     0,     0,   119,   120,   121,   122,     0,   129,
     123,     0,     0,     0,   124,     0,   574,     0,   130,   131,
     132,   133,   134,   135,   125,   119,   120,   121,   122,     0,
       0,   123,     0,     0,   126,   124,     0,     0,     0,     0,
     119,   120,   121,   122,     0,   125,   123,     0,     0,     0,
     124,   127,   128,     0,     0,   126,     0,     0,     0,     0,
     125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     126,     0,   127,   128,     0,     0,     0,   359,   360,   361,
     362,   363,   364,   290,     0,     0,   383,   127,   128,   384,
     366,   129,     0,     0,     0,   385,   386,     0,   857,     0,
     130,   131,   132,   133,   134,   135,     0,     0,     0,  1057,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   237,
       0,     0,   516,     0,   359,   360,   361,   362,   363,   364,
     290,  1326,   365,   383,     0,   407,   384,   366,     0,   367,
       0,     0,   385,   386,     0,     0,     0,   408,   409,   186,
     410,     0,     0,     0,     0,     0,     0,   451,   130,   131,
     132,   133,   134,   135,   466,  1327,  1328,   528,   529,   516,
     189,     0,     0,     0,     0,     0,     0,     0,     0,   130,
     131,   132,   133,   134,   135,   129,   367,     0,     0,     0,
       0,     0,     0,     0,   130,   131,   132,   133,   134,   135,
       0,  1329,     0,     0,     0,  1330,   359,   360,   361,   362,
     363,   364,   290,  1384,   365,   383,     0,   407,   384,   366,
       0,     0,     0,     0,   385,   386,     0,     0,     0,   408,
     409,     0,   410,     0,     0,     0,     0,     0,     0,   451,
       0,     0,     0,     0,     0,     0,   466,  1385,  1386,   528,
     529,   516,   359,   360,   361,   362,   363,     0,   290,  1113,
     365,   383,     0,   407,   384,   366,     0,     0,   367,     0,
     385,   386,     0,     0,     0,   408,   409,     0,   410,     0,
       0,     0,     0,  1387,     0,   451,     0,  1388,     0,     0,
       0,     0,   466,  1114,  1115,   359,   360,   361,   362,   363,
       0,   290,     0,   365,   383,     0,     0,   384,   366,   422,
     423,   424,   425,   385,   367,   491,   492,   493,     0,   359,
     360,   361,   362,   363,   364,   290,     0,     0,   383,  1116,
     407,   384,   366,  1117,     0,     0,     0,   385,   386,     0,
       0,     0,   408,   409,     0,   410,   359,   360,   361,   362,
     363,     0,   290,   655,   365,     0,     0,     0,     0,   366,
       0,     0,     0,     0,   516,     0,     0,     0,     0,     0,
       0,     0,   494,     0,     0,     0,   495,     0,     0,   451,
       0,   367,     0,     0,     0,     0,   466,   656,   657,     0,
       0,     0,     0,     0,     0,     0,  1193,     0,     0,     0,
    1194,   359,   360,   361,   362,   363,   364,   290,   367,     0,
     383,     0,     0,   384,   366,     0,     0,     0,     0,   385,
     386,     0,     0,   658,     0,     0,     0,   659,   360,   361,
     362,   363,     0,   290,  1156,   365,   383,     0,   407,   384,
     366,     0,     0,     0,     0,     0,   516,     0,     0,     0,
     408,   409,     0,   410,     0,     0,     0,     0,     0,     0,
     451,     0,     0,   367,     0,     0,     0,   466,  1157,  1158,
     528,   529,   516,     0,     0,     0,     0,     0,  1009,     0,
       0,     0,  1010,   360,   361,   362,   363,   364,   290,  1289,
     365,   383,     0,     0,   384,   366,     0,     0,     0,     0,
     385,   386,     0,     0,  1159,     0,     0,     0,  1160,     0,
       0,     0,     0,     0,     0,   451,     0,     0,     0,     0,
       0,     0,   466,  1290,  1291,   528,   529,   516,     0,     0,
       0,     0,     0,     0,     0,   360,   361,   362,   363,     0,
     290,     0,     0,   383,   367,   407,   384,   366,   422,   423,
     424,   425,     0,     0,   491,   492,   755,   408,   409,  1292,
     410,     0,     0,  1293,   360,   361,   362,   363,   364,   290,
       0,     0,   383,     0,     0,   384,   366,     0,     0,   361,
     362,   385,   386,   290,   672,   365,   383,     0,   407,   384,
     366,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     408,   409,     0,   410,     0,     0,   528,   529,   516,     0,
     451,   756,     0,     0,     0,   757,     0,   466,   673,   674,
       0,   101,     0,   102,     0,   367,     0,   103,     0,   104,
       0,     0,     0,     0,     0,   105,     0,   106,     0,   107,
    1218,   108,     0,   109,  1219,   110,     0,   111,     0,   112,
       0,     0,     0,     0,   675,   113,     0,   114,   676,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   116,
       0,   117,     0,   118,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,     0,   159,     0,     0,
       0,   359,     0,   361,   362,   160,     0,   290,   620,   365,
     383,     0,   407,   384,     0,   173,     0,     0,     0,   385,
     386,   174,     0,     0,   408,   409,   175,   410,   176,     0,
       0,     0,   177,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   178,   179,   180,     0,     0,     0,   181,     0,
     182,   183,     0,   184,   359,   360,   361,   362,   363,   364,
     290,  1326,   365,   383,     0,   407,   384,   366,     0,     0,
       0,     0,   385,   386,     0,     0,     0,   408,   409,     0,
     410,     0,     0,     0,     0,     0,     0,   451,     0,     0,
       0,     0,     0,     0,   466,  1327,  1328,   528,   529,   516,
     359,   360,   361,   362,   363,   364,   290,  1384,   365,   383,
       0,   407,   384,   366,     0,     0,   367,     0,   385,   386,
       0,     0,     0,   408,   409,     0,   410,     0,     0,     0,
       0,     0,     0,   451,     0,     0,     0,     0,     0,     0,
     466,  1385,  1386,   528,   529,   516,   359,   360,   361,   362,
     363,     0,   290,  1113,   365,   383,     0,   407,   384,   366,
       0,     0,   367,     0,   385,   386,     0,     0,     0,   408,
     409,     0,   410,     0,     0,     0,     0,     0,     0,   451,
       0,     0,     0,     0,     0,     0,   466,  1114,  1115,     0,
       0,   359,   360,   361,   362,   363,     0,   290,   918,   365,
     383,     0,     0,   384,   366,     0,     0,     0,   367,   385,
     386,     0,     0,     0,     0,     0,   359,   360,   361,   362,
     363,   364,   290,     0,   451,   383,     0,   407,   384,   366,
       0,   466,   919,   920,   385,   386,     0,     0,     0,   408,
     409,     0,   410,   360,   361,   362,   363,     0,   290,   971,
     365,   383,     0,   367,   384,   366,     0,     0,     0,     0,
       0,   516,   360,   361,   362,   363,   364,   290,  1289,   365,
     383,     0,     0,   384,   366,   451,     0,     0,   367,   385,
     386,     0,   466,   972,   973,   528,   529,   516,     0,     0,
       0,     0,     0,     0,   451,     0,     0,     0,     0,     0,
       0,   466,  1290,  1291,   528,   529,   516,   360,   361,   362,
     363,   364,   290,     0,     0,   383,     0,     0,   384,   366,
       0,     0,     0,   367,   385,   386,     0,     0,     0,     0,
     360,   361,   362,   363,     0,   290,  1156,   365,   383,     0,
     407,   384,   366,     0,     0,     0,     0,     0,     0,   528,
     529,   516,   408,   409,     0,   410,     0,     0,     0,     0,
       0,     0,   451,     0,     0,     0,     0,     0,   367,   466,
    1157,  1158,   528,   529,   516,   361,   362,     0,     0,   290,
     672,   365,   383,     0,   407,   384,   366,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   408,   409,     0,   410,
       0,     0,     0,     0,     0,     0,   451,     0,     0,   821,
       0,     0,   192,   466,   673,   674,   193,   194,   195,   196,
     197,   198,   199,   200,   201,     0,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   360,   361,   362,   363,     0,
     290,     0,     0,   383,     0,   407,   384,   366,   422,   423,
     424,   425,     0,     0,   491,   492,   755,   408,   409,     0,
     410,   192,   555,     0,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,     0,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   192,     0,     0,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,     0,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   359,   360,   361,
     362,   363,     0,   290,     0,   365,   383,     0,     0,   384,
     366,   422,   423,   424,   425,   385,     0,   491,   492,   493
};

static const yytype_int16 yycheck[] =
{
     174,   188,   311,   323,    67,   215,   212,   693,   556,   322,
     323,   217,   861,   262,   490,   579,   490,   454,   832,   268,
     293,   129,   293,   262,  1082,   264,   293,     3,   277,   268,
       3,   143,     3,     3,     3,   222,     3,   293,   277,    54,
     726,   855,    10,    55,   293,   264,   150,    15,   146,   236,
     148,    61,   156,    73,   293,    66,    61,    61,     3,     3,
     309,    56,     6,    31,    32,   150,    50,    51,    52,    82,
      75,   258,    71,    72,   293,    58,     0,   185,   186,    78,
      82,   189,    81,    57,    58,    59,   171,   148,   148,   102,
     264,   265,   152,   267,   464,   146,   109,   148,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,   357,   358,
     130,   321,   122,   323,   320,   114,    34,    35,   122,   293,
     369,   132,   133,   148,   150,   299,   139,   239,   240,   241,
     369,    55,   167,   146,   157,   322,   146,   150,   357,   358,
     150,   168,   381,   117,   146,   171,    53,   146,   150,   388,
     158,   150,   159,   160,   169,   163,   164,   527,   103,   104,
     223,    61,   381,   148,   148,    76,    77,   152,   152,   388,
     154,    82,   148,   158,   146,   151,   149,   148,   427,   148,
     151,   148,   158,   357,   358,   155,    82,   158,   427,   158,
     158,   102,   137,   138,   257,   171,    61,    57,   109,   448,
     449,    61,   152,  1261,   154,   146,   102,   381,   316,   448,
     449,   460,   150,   109,   388,   464,   328,   490,   156,   490,
     170,   470,   495,   490,   495,   464,   146,   401,   495,   448,
     170,   470,    57,  1082,   490,   101,    61,     3,   412,   495,
     148,   490,   562,   139,   152,   146,   495,   165,   166,   562,
    1064,   100,   143,   573,   145,   568,   495,   570,   695,   146,
     573,    57,   148,   827,     3,    61,   152,     6,   832,   118,
     119,   120,    71,    72,   448,   449,   495,    76,   826,   150,
      79,   757,   153,   757,   146,   148,   149,    53,    54,   152,
     464,   855,   127,   128,   129,   158,   545,    70,    71,    72,
      73,   125,    75,   612,   613,   614,   615,   148,   357,   358,
      71,    72,    71,    72,    75,    76,   490,    78,   148,    78,
       3,   495,    81,     6,    48,    49,    76,    77,   637,    36,
      37,   580,    82,   582,   643,   644,    58,    59,   708,   112,
     113,   515,   651,   713,     3,   149,   150,   146,   554,   598,
     556,   150,   102,   527,   149,   114,     3,   531,    61,   109,
     570,   580,     3,   582,    58,     6,    71,    72,   134,   135,
     106,    76,   106,   146,    79,   562,   101,   150,   136,   598,
       3,   568,   146,   622,   146,   146,   573,   574,   148,   150,
     577,   157,   158,   159,   160,     3,   146,    58,     6,   146,
     150,   167,   168,   622,   149,   654,   580,   149,   582,  1095,
     659,   149,  1261,    76,    77,   654,  1265,   150,   727,    82,
     659,   149,   150,   155,   598,    76,    77,   676,   798,   148,
     800,    82,   150,   151,   148,   654,   148,   676,   148,   102,
     659,   246,   247,   248,   249,    80,   109,   148,   622,   148,
     699,   102,   149,   150,   146,   704,   705,    92,   109,   708,
      95,    96,    97,    98,   713,   704,   705,   149,   150,   708,
      69,   148,    71,    72,   713,   148,    75,    76,    77,    78,
     654,    80,    81,   146,   757,   659,   757,   150,    87,    88,
     757,   149,   150,    92,    93,   148,    95,   381,   148,  1185,
    1064,   757,   676,   149,   150,    10,    11,    61,   757,    14,
      15,    16,    17,    18,    19,    20,    21,    22,   148,    24,
      25,    26,    27,    28,    29,    30,    31,    32,   841,   148,
     850,   580,   781,   582,   708,   149,   150,   850,   148,   713,
     149,   854,   149,   150,    76,    77,   148,   146,   148,   598,
      82,   150,   149,   150,   617,    69,    70,    71,    72,    73,
      74,    75,   781,   148,    78,   449,    80,    81,    82,   148,
     102,   103,   104,    87,    88,   638,   148,   640,    92,    93,
     148,    95,   645,   757,   148,   648,   149,   150,    69,    70,
      71,    72,    73,    74,    75,   148,    77,   149,   150,   148,
     970,    82,   148,   487,   148,   975,   490,   781,   148,   783,
      69,    70,    71,    72,    73,    74,    75,   131,   867,    78,
     826,   149,   150,    82,   798,   148,   800,   148,   691,    61,
     939,   515,   146,   942,    71,    72,   150,   148,    75,   149,
     150,    78,   951,    80,    81,   149,   150,   148,   867,    58,
     131,   156,   150,   151,   841,    92,    93,   844,    95,  1029,
     148,  1031,   148,   850,    82,   146,   146,   854,   917,   150,
     857,   146,   131,   922,   861,   149,   150,   114,   917,    71,
      72,   149,   991,   922,    76,    77,   155,   146,   149,   150,
      82,   150,   148,   867,     6,  1004,   580,   149,   917,    70,
      71,    72,    73,   922,    75,   153,   955,   149,   150,   146,
     102,   149,   150,   150,   963,   149,   955,   109,   110,   111,
     153,   970,     6,   293,   963,     6,   975,   149,   150,    76,
      77,   970,   781,   149,   150,    82,   975,   148,   622,   149,
     150,   112,   113,   917,   149,   150,  1066,   148,   922,   812,
     813,   149,   150,  1066,   146,   102,   103,   104,   150,  1008,
    1073,  1010,   149,   150,   148,    69,    70,    71,    72,    73,
     148,    75,    76,    77,    78,   149,   150,    81,    82,     3,
    1029,   148,    57,    87,    88,  1155,    61,   357,    58,  1008,
    1160,  1010,   676,   149,   150,   148,   970,   148,   102,   146,
     138,   975,   148,   150,     6,   109,   110,   111,   151,   264,
     265,   381,   267,   268,   269,  1002,    71,    72,   867,     6,
      75,    76,   277,    78,   143,   100,    61,   131,     3,  1138,
     146,   106,   107,   108,  1008,   146,  1010,   151,   293,     3,
     115,   296,   146,   151,   299,   151,   150,  1217,   153,  1219,
     149,   150,   153,   737,   149,  1029,   153,  1031,   149,   150,
     149,   150,   381,   149,   150,    80,  1053,   149,  1117,  1056,
     153,  1180,   149,   757,   138,   149,   150,    92,  1117,  1066,
      95,    96,    97,    98,   149,   150,  1073,   149,   150,  1076,
     149,   150,   149,   150,   148,  1082,   149,   150,  1117,   783,
     149,   150,   357,   358,   149,   150,  1155,   149,   150,   242,
     243,  1160,   149,   150,   798,   151,  1155,   149,  1288,   149,
     150,  1160,   149,  1293,   149,   495,   381,   149,   150,  1249,
     449,   146,   149,   388,   148,   150,  1249,   244,   245,   149,
    1253,   250,   251,  1117,   138,  1194,   401,    70,    71,    72,
      73,   152,    75,    61,   138,    78,   148,   412,    81,  1008,
    1330,  1010,   148,  1272,   153,   153,   151,   150,  1217,   151,
    1219,   490,   427,   149,   153,  1194,   149,   149,  1217,   153,
    1029,  1155,   153,   867,   149,   148,  1160,   442,   149,   112,
     113,   114,   148,   448,   449,   138,   515,   151,  1217,   151,
       3,   152,   148,   148,  1313,   138,   140,   151,     4,   464,
     580,   153,   582,   153,   153,   470,   153,   149,  1388,   149,
    1194,   150,   138,   146,   264,   265,   151,   150,   268,   269,
     140,   140,   151,   917,   151,   490,   265,   277,   267,  1288,
     495,   153,  1105,  1217,  1293,  1219,   148,  1360,   148,  1288,
     138,   140,   622,   293,  1293,   151,   296,   149,   148,   299,
     515,   580,  1249,   518,   293,   148,  1253,   296,   149,  1288,
       3,   153,   527,   153,  1261,   153,   531,   140,  1265,   151,
     149,  1330,   149,   153,   654,   138,   970,   148,   148,   151,
     140,  1330,    69,    70,    71,    72,    73,    74,    75,   138,
      77,   149,   153,   622,  1413,    82,  1155,   171,   153,   140,
     138,  1330,   149,   151,  1288,  1424,   140,   357,   358,  1293,
     149,   151,   149,   140,  1008,   580,   151,   582,   357,   358,
     149,   140,   140,   149,   149,  1444,   149,     2,  1055,  1388,
     253,   381,   256,   598,  1002,  1194,   252,  1031,   388,  1388,
     254,   554,   381,  1216,   131,   831,  1330,   676,   255,  1062,
     838,   401,   321,   911,   324,  1117,   857,   622,  1217,  1388,
    1219,   922,   401,  1360,   862,   659,  1363,   676,   495,   757,
     737,  1388,  1330,   412,  1293,  1219,   975,   427,    69,  1031,
      71,    72,  1010,   267,    75,    76,    77,    78,  1160,   654,
      81,   277,   442,  1194,   659,   800,    87,    88,   448,   449,
     713,   781,   783,   531,  1388,   518,   699,   412,   470,   293,
     449,   676,   296,   867,   464,    71,   622,   427,   598,    75,
     470,   442,    78,  1117,    80,    81,   963,   582,   757,  1288,
     388,   369,   955,   401,  1293,  1149,    92,    93,  1284,    95,
     490,   485,   310,   708,    -1,   495,    -1,    -1,   713,    -1,
      -1,   490,    -1,    -1,   783,   146,   495,    -1,    -1,   150,
      -1,    -1,    -1,    -1,   268,   515,  1160,    -1,   518,   798,
      -1,  1330,    -1,   357,    -1,    -1,   515,   527,    -1,   518,
      -1,   531,    -1,    -1,    -1,    -1,    -1,   867,   527,   293,
     146,    -1,   757,    -1,   150,   299,    -1,   381,    -1,    -1,
    1194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    74,    75,    -1,   781,    78,   783,    -1,
      81,    82,    -1,  1217,    -1,    -1,    87,    88,   412,  1388,
     580,    -1,   582,   798,    -1,   800,    -1,   917,   867,    -1,
      -1,   580,   922,   582,    -1,    -1,    -1,    -1,   598,    69,
      -1,    71,    72,   357,   358,    75,    76,    77,    78,   598,
      -1,    81,   448,   449,    -1,   449,    -1,    87,    88,    -1,
     131,    -1,   622,    -1,   460,    -1,    -1,    -1,   464,    -1,
      -1,    -1,    -1,   622,   470,   146,    71,    -1,   917,   150,
      75,    -1,    -1,    78,  1288,    80,    81,    -1,    -1,    -1,
      -1,    -1,   867,    -1,   654,    -1,   490,    92,    93,   659,
      95,   495,    -1,    -1,    -1,   654,    69,    70,    71,    72,
      73,    74,    75,   427,    -1,    78,   676,    -1,  1008,    82,
    1010,   515,   464,    -1,   518,    -1,  1330,   676,    -1,    -1,
      -1,   970,    -1,   527,   448,    70,    71,    72,    73,  1029,
      75,    -1,   917,    78,    -1,    80,    81,   922,   708,    -1,
     464,    -1,    -1,   713,    -1,    -1,    -1,    92,    93,   708,
      95,    -1,    70,    71,    72,    73,    -1,    75,   131,  1008,
      78,    -1,    -1,    81,    -1,    -1,   490,   112,   113,   114,
      -1,   495,    -1,    -1,  1388,   527,   580,    -1,   582,    -1,
      -1,    -1,  1031,    -1,    -1,   970,    -1,   757,    -1,    -1,
     975,    -1,    -1,    -1,   112,   113,   114,    -1,   757,    -1,
      -1,   146,    -1,   527,    -1,   150,    -1,   531,    -1,    -1,
      -1,   781,    -1,   783,    -1,    -1,    -1,  1117,   622,    -1,
      -1,    -1,   781,  1008,   783,  1010,    -1,    -1,   798,    -1,
     800,    -1,    -1,    -1,    -1,    -1,    -1,   357,    -1,   798,
      -1,   800,    -1,    -1,  1029,    -1,  1031,    -1,   654,    -1,
     654,   268,    -1,   659,    -1,  1155,   580,    -1,   582,   357,
     358,   381,    -1,    -1,    -1,    -1,    -1,    -1,  1117,    -1,
     676,    -1,   676,    -1,   598,    -1,   293,    -1,    70,    71,
      72,    73,   299,    75,    -1,    -1,    78,    -1,    80,    81,
      -1,    -1,   381,   699,  1194,    -1,    -1,   867,   704,   705,
      92,    93,   708,    95,   708,    -1,    -1,   713,   867,    -1,
      -1,  1160,    -1,    -1,    -1,    -1,    -1,  1217,    -1,  1219,
     112,   113,   114,    -1,    -1,    -1,   448,   449,    -1,    -1,
     654,    -1,  1117,    -1,    -1,   659,    -1,    -1,   460,    -1,
     357,   358,   464,    -1,    -1,  1194,    -1,   917,    -1,    -1,
     448,    -1,   922,   757,    -1,    -1,   708,    -1,   917,    -1,
     449,   713,    -1,   922,    -1,    -1,    -1,    -1,  1217,    -1,
    1155,    -1,    -1,    -1,    -1,  1160,    -1,   781,    -1,   783,
      70,    71,    72,    73,   708,    75,    76,    77,  1288,   713,
      -1,    -1,    82,  1293,   798,    -1,   800,    -1,   487,    -1,
     970,   490,    -1,    -1,    -1,   975,    -1,    -1,    -1,  1194,
     427,   970,   102,    -1,    -1,    -1,   975,    -1,    -1,   109,
     110,   111,   112,   113,    -1,    -1,   515,    -1,    -1,    -1,
    1330,   448,  1217,   757,  1219,    -1,    -1,    -1,  1008,  1288,
    1010,    -1,    -1,    -1,    -1,    -1,   798,   464,   800,  1008,
      -1,  1010,    -1,    -1,    -1,    -1,    -1,   781,    -1,  1029,
     580,  1031,   582,   867,    -1,    -1,    -1,    -1,    -1,    -1,
    1029,    -1,  1031,   490,   798,    -1,   800,    -1,   495,    -1,
      -1,  1330,   580,    -1,   582,    71,    72,    -1,  1388,    75,
      -1,   580,    78,    -1,    80,    81,    -1,    -1,    -1,    -1,
     598,    -1,   622,  1288,   381,    -1,    92,    93,  1293,    95,
     527,   917,    -1,   917,   531,    -1,   922,    -1,   922,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,
      -1,    -1,   654,   622,   654,    -1,    -1,   659,    -1,  1388,
      -1,    -1,    -1,   867,    -1,  1330,    -1,  1117,    -1,   955,
      -1,    -1,    -1,    -1,   676,    -1,   654,   963,  1117,    -1,
      -1,   659,    -1,   580,   970,   582,   970,    -1,    -1,   975,
      -1,   975,   449,    -1,    -1,    -1,    -1,   699,    -1,    -1,
      -1,   598,   704,   705,    -1,  1155,   708,   676,    -1,    -1,
    1160,   713,    -1,   917,    -1,    -1,  1155,    -1,   922,    -1,
      -1,  1160,    -1,  1388,  1008,    -1,  1010,    -1,    -1,    -1,
     487,    -1,    -1,   490,    -1,    -1,    -1,    -1,   970,    -1,
      -1,    -1,    -1,   975,  1194,  1029,    -1,  1031,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1194,    -1,   654,   515,    -1,
      -1,    -1,   659,    -1,    -1,    -1,   970,  1217,   737,  1219,
      -1,   975,    -1,    -1,    -1,    -1,    -1,    -1,  1217,    -1,
    1219,   781,   515,    -1,    -1,    -1,    -1,    -1,   757,    -1,
      -1,    -1,    -1,    -1,   527,    -1,    -1,  1029,    -1,  1031,
      -1,    -1,    -1,   781,  1008,    -1,  1010,    -1,    -1,    -1,
      -1,   708,    -1,    -1,   783,    -1,   713,    -1,    -1,    -1,
      -1,    -1,    -1,   580,    -1,  1029,    -1,  1031,    -1,   798,
      -1,  1117,    -1,  1117,    -1,    -1,    -1,    -1,  1288,    71,
      72,    -1,    -1,  1293,    76,    77,    -1,    -1,    -1,  1288,
      82,    -1,    -1,    -1,  1293,    -1,    -1,    -1,    -1,    -1,
     757,    -1,    -1,    -1,    -1,   622,    -1,   867,    -1,  1155,
     102,  1155,    -1,    -1,  1160,    -1,  1160,   109,   110,   111,
    1330,    -1,    -1,    -1,   781,    -1,    -1,    -1,    -1,   867,
      -1,  1330,    70,    71,    72,    73,    -1,    -1,   867,    77,
      -1,   798,    -1,   800,    82,    83,    84,    85,    86,    -1,
    1194,    -1,    -1,  1117,    -1,   917,    -1,   917,    -1,   676,
     922,    -1,   922,  1155,    -1,    -1,    -1,    -1,  1160,    -1,
      -1,  1217,    -1,  1217,    -1,  1219,    -1,    -1,  1388,   917,
      -1,    -1,    -1,    -1,   922,    -1,    -1,    -1,   917,  1388,
      -1,  1155,    -1,   955,    -1,    -1,  1160,    -1,    -1,    -1,
      -1,   963,    -1,    -1,    -1,    -1,    -1,    -1,   970,    -1,
     867,    -1,    -1,   975,    -1,   708,    -1,    -1,    -1,    -1,
     737,    -1,    -1,    -1,    -1,  1217,    -1,  1219,    -1,    -1,
    1194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     757,   970,  1288,    -1,  1288,    -1,    -1,  1293,  1008,  1293,
    1010,    -1,    -1,  1217,    -1,  1219,    -1,    -1,    -1,    -1,
     917,    70,    71,    72,    73,   922,   783,    -1,    77,  1029,
    1008,    -1,  1010,    82,    83,    84,    85,    86,    -1,  1008,
      -1,   798,    -1,    -1,  1330,    -1,  1330,    -1,   781,    -1,
     783,  1029,    -1,    -1,    -1,    -1,  1288,    -1,    -1,    -1,
      -1,  1293,  1031,    -1,    -1,   798,    -1,   800,    -1,    -1,
      -1,    -1,    -1,   970,    -1,    -1,    -1,    -1,   975,    69,
      70,    71,    72,    73,  1288,    75,    76,    77,    -1,  1293,
      -1,    -1,    82,    -1,    -1,    -1,    -1,   146,  1330,    -1,
      -1,   150,  1388,    -1,  1388,    -1,    -1,    -1,    -1,    -1,
     867,  1008,   102,  1010,    -1,  1117,    -1,  1117,    -1,   109,
     110,   111,    -1,    -1,    -1,    -1,  1330,    -1,    -1,    -1,
      -1,    -1,  1029,    -1,  1031,    -1,    -1,    -1,    -1,  1117,
      -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,  1117,    -1,
      -1,    -1,    -1,  1155,    -1,  1155,  1388,    -1,  1160,    -1,
     917,    -1,    -1,    -1,    70,    71,    72,    73,    -1,    75,
      76,    77,    78,    -1,    -1,    81,    82,  1155,    -1,     3,
       4,     5,     6,    -1,  1388,     9,    -1,    -1,    -1,    13,
      -1,  1160,    -1,    -1,  1194,    -1,   102,    -1,    -1,    23,
      -1,    -1,    -1,   109,   110,   111,   112,   113,   114,    33,
      -1,    -1,    -1,   970,    -1,  1217,  1194,  1217,    -1,  1219,
    1117,    -1,    -1,    -1,    -1,  1194,    50,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   970,    -1,  1217,
     146,  1219,   975,    -1,   150,    -1,    -1,    -1,  1217,    -1,
     125,  1008,   127,   128,    -1,    -1,    -1,    -1,  1155,    -1,
      -1,    -1,    -1,  1160,    -1,    -1,    -1,    -1,   143,    -1,
      -1,    -1,    -1,    -1,  1031,  1008,    -1,  1010,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1288,    -1,  1288,    -1,
      -1,  1293,    -1,  1293,    -1,    -1,  1029,  1194,  1031,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1288,     3,     4,     5,     6,  1293,    -1,     9,    10,  1288,
    1217,    13,  1219,    15,   148,    -1,    -1,    -1,  1330,    -1,
    1330,    23,    -1,   157,   158,   159,   160,   161,   162,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,   171,    -1,    -1,
      -1,    -1,  1330,    -1,    -1,    -1,    -1,    -1,    50,    51,
    1117,  1330,    -1,    -1,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,    -1,    -1,    -1,    -1,  1388,    -1,  1388,    -1,
      -1,  1288,    -1,    -1,    -1,    -1,  1293,    -1,    -1,    -1,
      -1,    -1,    -1,  1160,    -1,    -1,    -1,    -1,    -1,    -1,
    1388,     3,     4,     5,     6,    -1,     8,     9,    10,  1388,
      -1,    13,  1155,    15,    -1,    -1,    -1,  1160,    -1,    -1,
      -1,    23,    -1,  1330,    -1,    -1,    -1,  1194,    -1,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   328,    -1,    -1,   148,    -1,    50,    51,
    1217,  1194,    -1,    -1,    -1,   157,   158,   159,   160,   161,
     162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1217,    -1,  1219,     3,     4,     5,
       6,  1388,    -1,     9,    10,    -1,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,    78,
      -1,  1288,    81,    82,    50,    51,    -1,    -1,    87,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1288,   148,    -1,    -1,    -1,
    1293,   153,    -1,    -1,    -1,   157,   158,   159,   160,   161,
     162,    -1,    -1,  1330,     3,     4,     5,     6,    -1,     8,
       9,    10,   131,    -1,    13,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    -1,    -1,  1330,    -1,    -1,
      -1,    -1,    31,    32,    33,     3,     4,     5,     6,    -1,
       8,     9,    10,    -1,    -1,    13,    -1,    15,    -1,    -1,
      -1,    50,    51,    -1,    -1,    23,    -1,    -1,    -1,    -1,
      -1,  1388,   148,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,   157,   158,   159,   160,   161,   162,    -1,    -1,    -1,
      -1,    -1,    50,    51,    -1,  1388,    -1,    -1,     3,     4,
       5,     6,    -1,     8,     9,    10,    -1,    -1,    13,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,     3,
       4,     5,     6,    -1,    -1,     9,    31,    32,    33,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    -1,   579,    50,    51,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,
      -1,    -1,    -1,    -1,   153,    -1,    50,    51,   157,   158,
     159,   160,   161,   162,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    10,    -1,    -1,    13,    -1,    15,
     148,    -1,    -1,    -1,    -1,   153,    -1,    23,    -1,   157,
     158,   159,   160,   161,   162,    31,    32,    33,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,     8,     9,    10,    -1,
      -1,    13,    -1,    15,    50,    51,    -1,    -1,    -1,    -1,
      -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    -1,   148,    -1,    -1,    -1,    -1,   153,    -1,
      -1,    -1,   157,   158,   159,   160,   161,   162,    50,    51,
      -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,   152,    -1,
     154,   155,   156,   157,   158,   159,   160,   161,   162,    -1,
      -1,     3,     4,     5,     6,    -1,    -1,     9,    -1,    -1,
      -1,    13,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,    23,     9,    -1,    -1,    -1,    13,    70,    71,    72,
      73,    33,    75,    76,    77,    -1,    23,    -1,    -1,    82,
      -1,    -1,   148,    -1,    -1,    -1,    33,   153,    50,    51,
      -1,   157,   158,   159,   160,   161,   162,    -1,    -1,   102,
      -1,    -1,    -1,    50,    51,    -1,   109,   110,   111,   112,
     113,    -1,     3,     4,     5,     6,   148,    -1,     9,    -1,
      -1,   153,    13,    -1,    -1,   157,   158,   159,   160,   161,
     162,    -1,    23,    -1,     3,     4,     5,     6,    -1,    -1,
       9,    -1,    33,   146,    13,    -1,    -1,   150,    -1,    -1,
      -1,    -1,   827,    -1,    23,    -1,    -1,   832,    -1,    50,
      51,    -1,    -1,    -1,    33,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,    78,    -1,    80,    81,    82,    -1,
     855,    50,    51,    87,    88,    -1,   148,    -1,    92,    93,
     152,    95,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   148,    -1,    -1,    -1,   152,    -1,   154,   155,    -1,
     157,   158,   159,   160,   161,   162,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    -1,    -1,    13,   131,    -1,    -1,
      -1,    -1,    -1,    10,    11,    -1,    23,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    33,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,   148,   149,    -1,
      -1,    -1,    -1,    50,    51,    -1,   157,   158,   159,   160,
     161,   162,    -1,    -1,     3,     4,     5,     6,    -1,   148,
       9,    -1,    -1,    -1,    13,    -1,   155,    -1,   157,   158,
     159,   160,   161,   162,    23,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    -1,    33,    13,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,    23,     9,    -1,    -1,    -1,
      13,    50,    51,    -1,    -1,    33,    -1,    -1,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    50,    51,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    78,    50,    51,    81,
      82,   148,    -1,    -1,    -1,    87,    88,    -1,   155,    -1,
     157,   158,   159,   160,   161,   162,    -1,    -1,    -1,   156,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1064,
      -1,    -1,   114,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    -1,    80,    81,    82,    -1,   131,
      -1,    -1,    87,    88,    -1,    -1,    -1,    92,    93,   148,
      95,    -1,    -1,    -1,    -1,    -1,    -1,   102,   157,   158,
     159,   160,   161,   162,   109,   110,   111,   112,   113,   114,
     148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,
     158,   159,   160,   161,   162,   148,   131,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,   162,
      -1,   146,    -1,    -1,    -1,   150,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    -1,    80,    81,    82,
      -1,    -1,    -1,    -1,    87,    88,    -1,    -1,    -1,    92,
      93,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,   102,
      -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,   112,
     113,   114,    69,    70,    71,    72,    73,    -1,    75,    76,
      77,    78,    -1,    80,    81,    82,    -1,    -1,   131,    -1,
      87,    88,    -1,    -1,    -1,    92,    93,    -1,    95,    -1,
      -1,    -1,    -1,   146,    -1,   102,    -1,   150,    -1,    -1,
      -1,    -1,   109,   110,   111,    69,    70,    71,    72,    73,
      -1,    75,    -1,    77,    78,    -1,    -1,    81,    82,    83,
      84,    85,    86,    87,   131,    89,    90,    91,    -1,    69,
      70,    71,    72,    73,    74,    75,    -1,    -1,    78,   146,
      80,    81,    82,   150,    -1,    -1,    -1,    87,    88,    -1,
      -1,    -1,    92,    93,    -1,    95,    69,    70,    71,    72,
      73,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,    82,
      -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   146,    -1,    -1,    -1,   150,    -1,    -1,   102,
      -1,   131,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   146,    -1,    -1,    -1,
     150,    69,    70,    71,    72,    73,    74,    75,   131,    -1,
      78,    -1,    -1,    81,    82,    -1,    -1,    -1,    -1,    87,
      88,    -1,    -1,   146,    -1,    -1,    -1,   150,    70,    71,
      72,    73,    -1,    75,    76,    77,    78,    -1,    80,    81,
      82,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,
      92,    93,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,
     102,    -1,    -1,   131,    -1,    -1,    -1,   109,   110,   111,
     112,   113,   114,    -1,    -1,    -1,    -1,    -1,   146,    -1,
      -1,    -1,   150,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    -1,    81,    82,    -1,    -1,    -1,    -1,
      87,    88,    -1,    -1,   146,    -1,    -1,    -1,   150,    -1,
      -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,    -1,    -1,
      -1,    -1,   109,   110,   111,   112,   113,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    -1,
      75,    -1,    -1,    78,   131,    80,    81,    82,    83,    84,
      85,    86,    -1,    -1,    89,    90,    91,    92,    93,   146,
      95,    -1,    -1,   150,    70,    71,    72,    73,    74,    75,
      -1,    -1,    78,    -1,    -1,    81,    82,    -1,    -1,    71,
      72,    87,    88,    75,    76,    77,    78,    -1,    80,    81,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    -1,    95,    -1,    -1,   112,   113,   114,    -1,
     102,   146,    -1,    -1,    -1,   150,    -1,   109,   110,   111,
      -1,     9,    -1,    11,    -1,   131,    -1,    15,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    23,    -1,    25,    -1,    27,
     146,    29,    -1,    31,   150,    33,    -1,    35,    -1,    37,
      -1,    -1,    -1,    -1,   146,    43,    -1,    45,   150,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    59,    -1,    61,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    75,    -1,    -1,
      -1,    69,    -1,    71,    72,    83,    -1,    75,    76,    77,
      78,    -1,    80,    81,    -1,    88,    -1,    -1,    -1,    87,
      88,    94,    -1,    -1,    92,    93,    99,    95,   101,    -1,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   115,   116,   117,    -1,    -1,    -1,   121,    -1,
     123,   124,    -1,   126,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    -1,    80,    81,    82,    -1,    -1,
      -1,    -1,    87,    88,    -1,    -1,    -1,    92,    93,    -1,
      95,    -1,    -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,
      -1,    -1,    -1,    -1,   109,   110,   111,   112,   113,   114,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      -1,    80,    81,    82,    -1,    -1,   131,    -1,    87,    88,
      -1,    -1,    -1,    92,    93,    -1,    95,    -1,    -1,    -1,
      -1,    -1,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,    69,    70,    71,    72,
      73,    -1,    75,    76,    77,    78,    -1,    80,    81,    82,
      -1,    -1,   131,    -1,    87,    88,    -1,    -1,    -1,    92,
      93,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,   102,
      -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,
      -1,    69,    70,    71,    72,    73,    -1,    75,    76,    77,
      78,    -1,    -1,    81,    82,    -1,    -1,    -1,   131,    87,
      88,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    -1,   102,    78,    -1,    80,    81,    82,
      -1,   109,   110,   111,    87,    88,    -1,    -1,    -1,    92,
      93,    -1,    95,    70,    71,    72,    73,    -1,    75,    76,
      77,    78,    -1,   131,    81,    82,    -1,    -1,    -1,    -1,
      -1,   114,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    -1,    -1,    81,    82,   102,    -1,    -1,   131,    87,
      88,    -1,   109,   110,   111,   112,   113,   114,    -1,    -1,
      -1,    -1,    -1,    -1,   102,    -1,    -1,    -1,    -1,    -1,
      -1,   109,   110,   111,   112,   113,   114,    70,    71,    72,
      73,    74,    75,    -1,    -1,    78,    -1,    -1,    81,    82,
      -1,    -1,    -1,   131,    87,    88,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    -1,    75,    76,    77,    78,    -1,
      80,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,   112,
     113,   114,    92,    93,    -1,    95,    -1,    -1,    -1,    -1,
      -1,    -1,   102,    -1,    -1,    -1,    -1,    -1,   131,   109,
     110,   111,   112,   113,   114,    71,    72,    -1,    -1,    75,
      76,    77,    78,    -1,    80,    81,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    95,
      -1,    -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,     7,
      -1,    -1,    10,   109,   110,   111,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    70,    71,    72,    73,    -1,
      75,    -1,    -1,    78,    -1,    80,    81,    82,    83,    84,
      85,    86,    -1,    -1,    89,    90,    91,    92,    93,    -1,
      95,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    10,    -1,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    69,    70,    71,
      72,    73,    -1,    75,    -1,    77,    78,    -1,    -1,    81,
      82,    83,    84,    85,    86,    87,    -1,    89,    90,    91
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    55,   173,   174,   227,   228,   230,   231,   234,   235,
     238,   239,   242,   243,   246,   247,   250,   251,   254,   255,
     258,   259,   260,   261,   264,   265,   268,   269,   272,   273,
     276,   277,   280,   281,   284,   285,   288,   289,   292,   293,
     296,   297,   300,   301,   304,   305,   308,   309,   312,   313,
     316,   317,   320,   321,   324,   325,   328,   329,   332,   333,
     336,   337,   340,   341,   344,   345,   347,   348,   349,   350,
     351,   352,   353,   354,   357,   358,   361,   362,   365,   366,
     369,   370,   371,   372,   375,   376,   379,   380,   381,   382,
     384,   385,   386,   389,   392,   393,    56,     0,   174,    58,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,     3,
       4,     5,     6,     9,    13,    23,    33,    50,    51,   148,
     157,   158,   159,   160,   161,   162,   171,   175,   176,   177,
     178,   181,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   199,   225,   226,
     226,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    88,    94,    99,   101,   105,   115,   116,
     117,   121,   123,   124,   126,   148,   148,   183,   148,   148,
     183,   183,    10,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    24,    25,    26,    27,    28,    29,    30,    31,
      32,   199,   201,   202,   203,   206,   209,   210,   216,    50,
      51,    52,   148,   152,   154,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,   170,   198,   183,   185,   158,
     163,   164,   159,   160,    48,    49,    34,    35,   165,   166,
      36,    37,   157,   167,   168,    53,    54,   169,   150,   171,
      58,    59,   377,    61,   373,   367,   146,   338,   342,   363,
      57,    61,   100,   106,   107,   108,   115,   322,   100,   118,
     119,   120,   413,   146,   146,   148,   415,   146,   346,    61,
      75,   427,    61,   252,    57,    61,   310,   146,   101,   314,
     146,   146,   146,   148,   383,    57,    58,    59,   117,   436,
     125,   148,   216,   216,   197,   216,   148,   149,   206,     3,
     155,   148,   152,   158,   213,   217,   218,   206,   149,     3,
     149,   182,   197,   199,     3,   197,   185,   185,   185,   186,
     186,   187,   187,   188,   188,   188,   188,   189,   189,   190,
     191,   192,   193,   194,   199,   197,    61,   359,   355,    69,
      70,    71,    72,    73,    74,    77,    82,   131,   146,   150,
     378,   409,   420,   421,   422,   423,   424,   426,   427,   437,
     438,   334,    76,    78,    81,    87,    88,   146,   150,   374,
     409,   417,   418,   420,   423,   424,   425,   427,   434,    76,
     146,   150,   368,   423,   424,   425,   427,    80,    92,    93,
      95,   146,   150,   339,   404,   405,   423,   425,   427,   428,
     429,   434,    83,    84,    85,    86,   146,   150,   343,   406,
     407,   408,   409,   411,   422,   423,   424,   426,   437,    76,
      79,   146,   150,   364,   416,   423,   424,    58,   244,   232,
      76,   102,   103,   104,   318,   319,   400,   401,   409,   437,
     326,   106,   106,   101,   294,    76,   109,   110,   111,   146,
     150,   323,   401,   402,   409,   423,   424,   437,   136,   414,
       3,   146,    61,   122,   146,   150,   412,   256,   148,   146,
     248,    89,    90,    91,   146,   150,   253,   394,   395,   406,
     407,   408,   409,   411,   418,   420,   422,   423,   424,   425,
     426,   427,   434,   437,    58,   306,   114,   146,   150,   311,
     397,   423,   424,   425,   434,    57,    61,   290,   112,   113,
     146,   150,   315,   398,   399,   422,   423,   424,   426,   427,
       3,     6,   435,   146,   146,   150,   437,   436,   435,   149,
     149,   150,   149,   216,   155,    11,   204,   205,   206,   224,
     149,   217,     8,    10,   153,   158,   197,   210,   214,   213,
     214,   218,   148,   152,   155,   185,   149,   150,   153,   151,
     330,   146,   150,   360,   417,   418,   420,   421,   422,   423,
     424,   425,   426,   427,   434,   437,   438,   146,   150,   356,
     420,   421,   422,   423,   424,   425,   426,   427,   437,   438,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   378,
      76,   146,   150,   335,   404,   405,   409,   417,   418,   420,
     423,   424,   425,   427,   428,   429,   434,   148,   148,   148,
     148,   374,   368,   148,   148,   148,   148,   339,   148,   148,
     343,   148,   364,    61,   240,    76,   110,   111,   146,   150,
     245,   401,   402,   409,   420,   422,   423,   424,   426,   427,
     437,   438,    76,   110,   111,   146,   150,   233,   401,   402,
     404,   405,   409,   423,   424,   425,   427,   428,   429,   434,
     437,   148,   148,   148,   146,   150,   319,   139,   146,   150,
     327,   401,   402,   437,   387,   390,    57,    61,   282,    76,
     110,   111,   146,   150,   295,   398,   399,   401,   402,   409,
     422,   423,   424,   426,   427,   437,   148,   148,   148,   323,
     146,   149,   412,    96,    97,    98,   146,   150,   257,   396,
     405,   428,   429,     3,    53,    54,   134,   135,   157,   158,
     159,   160,   167,   168,   439,    91,   146,   150,   249,   394,
     395,   404,   405,   406,   407,   408,   411,   422,   423,   424,
     425,   426,   427,   428,   429,   434,   437,   148,   148,   253,
      61,   302,   146,   150,   307,   397,   404,   405,   423,   424,
     425,   427,   428,   429,   434,   148,   311,    58,   286,   146,
     150,   291,   397,   398,   399,   422,   423,   424,   425,   426,
     427,   434,   148,   148,   315,   149,   150,   437,   146,   146,
     149,     7,   179,   180,   216,   149,   204,   148,   156,   205,
       3,   148,   151,   171,   207,   208,   211,   212,   213,   149,
     197,   214,   153,   153,     8,   153,   197,   210,   213,   149,
       8,   153,   158,   197,   214,   152,   154,   155,   197,   219,
     220,   221,   222,   223,   197,   196,   146,   150,   331,   404,
     405,   417,   418,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   434,   437,   438,   360,   356,     6,    73,
     130,   435,   435,   435,   435,   127,   128,   129,   410,   199,
      66,   132,   133,   335,   435,   199,   143,   145,   419,   199,
     435,   435,   199,     6,   199,     6,   435,   236,    76,   110,
     111,   146,   150,   241,   401,   402,   409,   417,   418,   420,
     422,   423,   424,   425,   426,   427,   434,   437,   438,   148,
     148,   245,   148,   148,   233,   199,     3,   430,   431,   430,
     319,   148,   327,    76,   146,   150,   388,   401,   402,   409,
     437,    76,   146,   150,   391,   401,   402,   409,   437,    58,
     278,    76,   110,   111,   146,   150,   283,   397,   398,   399,
     401,   402,   409,   422,   423,   424,   425,   426,   427,   434,
     437,   148,   148,   295,   103,   104,   137,   138,   403,   430,
     435,   138,   148,   257,   151,   249,     6,     6,   298,   146,
     150,   303,   397,   417,   418,   420,   421,   422,   423,   424,
     425,   426,   427,   434,   437,   438,   307,   143,    61,   274,
     146,   150,   287,   397,   398,   399,   404,   405,   422,   423,
     424,   425,   426,   427,   428,   429,   434,   291,   199,   199,
       3,   146,   146,   151,   149,   150,   151,   156,   196,   200,
     211,   200,   150,   171,   151,   148,   152,   212,   153,   197,
     197,   153,   197,   214,   153,   153,     8,   153,   197,   200,
       3,   220,   150,   156,   219,   170,   223,   331,   149,   149,
     149,   149,   149,   149,   149,   151,   149,   149,   149,   149,
     149,   149,   149,   150,   149,   151,   229,   229,   149,   149,
     149,   149,   149,    76,   110,   111,   146,   150,   237,   401,
     402,   404,   405,   409,   417,   418,   420,   422,   423,   424,
     425,   426,   427,   428,   429,   434,   437,   438,   148,   148,
     241,   435,   138,   435,   138,   149,   152,   432,   149,   150,
     149,   435,   388,   391,    61,   270,    76,   110,   111,   146,
     150,   279,   397,   398,   399,   401,   402,   404,   405,   409,
     422,   423,   424,   425,   426,   427,   428,   429,   434,   437,
     148,   148,   283,   435,   138,   151,   149,   149,   151,   182,
     435,   149,   149,   146,   150,   299,   397,   404,   405,   417,
     418,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   434,   437,   438,   303,   149,   150,   266,   146,   150,
     275,   397,   398,   399,   417,   418,   421,   422,   423,   424,
     425,   426,   427,   434,   437,   438,   287,   149,   149,   197,
     180,   197,   150,   149,   208,   200,     3,   149,   215,     8,
     153,   158,   197,   214,   153,   153,   153,   197,   197,   153,
     153,   150,   156,   156,   219,   221,   430,     3,     6,   199,
     149,   149,   148,   148,   237,   435,   138,   149,   151,   149,
     151,     3,     6,   433,   152,     3,   431,   149,   262,    76,
     110,   111,   146,   150,   271,   397,   398,   399,   401,   402,
     409,   417,   418,   421,   422,   423,   424,   425,   426,   427,
     434,   437,   438,   148,   148,   279,   435,   138,   149,   151,
     430,   140,   149,   149,   299,   199,    76,   110,   111,   146,
     150,   267,   397,   398,   399,   401,   402,   404,   405,   409,
     417,   418,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   434,   437,   438,   275,     4,   149,   150,   197,
     214,   153,   153,     8,   153,   158,   197,   153,   153,   156,
     219,   149,   149,   149,   435,   138,   149,   151,   140,   140,
     151,   151,   153,   433,    76,   110,   111,   146,   150,   263,
     397,   398,   399,   401,   402,   404,   405,   409,   417,   418,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     434,   437,   438,   148,   148,   271,   435,   138,   149,   151,
     140,   149,   149,   149,   148,   148,   267,   149,     3,   153,
     197,   197,   153,   153,   149,   151,   140,   149,   149,     3,
       6,     3,     6,   153,   148,   148,   263,   435,   138,   149,
     151,   140,   149,   435,   138,   171,   153,   153,   140,   149,
     435,   138,   149,   151,   140,   149,   149,   151,   149,   149,
     151,   140,   149,   140,   140,   149,   149,   149
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   172,   173,   173,   174,   174,   175,   175,   175,   175,
     175,   176,   176,   177,   177,   178,   179,   179,   180,   180,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     182,   182,   183,   183,   183,   183,   183,   183,   183,   184,
     184,   184,   184,   184,   184,   185,   185,   186,   186,   186,
     186,   187,   187,   187,   188,   188,   188,   189,   189,   189,
     189,   189,   190,   190,   190,   191,   191,   192,   192,   193,
     193,   194,   194,   195,   195,   196,   196,   197,   197,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     199,   199,   200,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   202,   202,
     202,   203,   203,   204,   204,   205,   205,   205,   206,   206,
     206,   206,   207,   207,   208,   208,   208,   209,   210,   210,
     210,   210,   211,   211,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   213,   213,   213,
     213,   214,   214,   215,   215,   216,   216,   217,   217,   217,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   219,
     219,   219,   220,   220,   220,   220,   221,   222,   222,   223,
     223,   224,   225,   225,   226,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   229,   229,   230,   231,   232,
     232,   232,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   234,   235,
     236,   236,   236,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   238,   239,   240,   240,   240,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   242,   243,
     244,   244,   244,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   246,   247,   248,
     248,   248,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   250,   251,   252,   252,   252,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   254,   255,   256,   256,   256,   257,
     257,   257,   257,   257,   257,   258,   259,   260,   261,   262,
     262,   262,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   264,   265,
     266,   266,   266,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   268,
     269,   270,   270,   270,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   272,   273,   274,   274,   274,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   276,   277,   278,   278,   278,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   280,   281,   282,   282,   282,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   284,   285,   286,   286,   286,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   288,   289,   290,   290,   290,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   292,   293,   294,
     294,   294,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   296,   297,   298,   298,
     298,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   300,
     301,   302,   302,   302,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   304,   305,
     306,   306,   306,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   308,   309,   310,   310,   310,   311,   311,
     311,   311,   311,   312,   313,   314,   314,   314,   315,   315,
     315,   315,   315,   315,   315,   316,   317,   318,   318,   318,
     319,   319,   319,   319,   319,   320,   321,   322,   322,   322,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   324,
     325,   326,   326,   326,   327,   327,   327,   327,   328,   329,
     330,   330,   330,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     332,   333,   334,   334,   334,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   336,
     337,   338,   338,   338,   339,   339,   339,   339,   339,   339,
     339,   339,   340,   341,   342,   342,   342,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   344,   345,   346,
     346,   346,   347,   348,   349,   350,   350,   351,   352,   353,
     354,   355,   355,   355,   356,   356,   356,   356,   356,   356,
     356,   356,   356,   356,   357,   358,   359,   359,   359,   360,
     360,   360,   360,   360,   360,   360,   360,   360,   360,   360,
     360,   360,   361,   362,   363,   363,   363,   364,   364,   364,
     364,   365,   366,   367,   367,   367,   368,   368,   368,   368,
     368,   369,   370,   371,   372,   373,   373,   373,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   375,   376,
     377,   377,   377,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   379,   380,   381,   382,   382,   383,   384,
     385,   386,   387,   387,   387,   388,   388,   388,   388,   388,
     389,   390,   390,   390,   391,   391,   391,   391,   391,   392,
     392,   392,   393,   394,   395,   396,   397,   397,   398,   399,
     400,   400,   401,   402,   402,   403,   403,   403,   403,   404,
     405,   406,   407,   408,   409,   410,   410,   410,   410,   411,
     412,   412,   413,   413,   413,   413,   413,   414,   414,   415,
     416,   417,   417,   418,   418,   418,   419,   419,   419,   420,
     421,   422,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   430,   430,   430,   431,   432,   432,   433,   433,   433,
     433,   433,   433,   434,   435,   435,   435,   436,   436,   436,
     436,   436,   437,   438,   438,   438,   439,   439,   439,   439,
     439,   439,   439,   439,   439,   439,   439
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     6,     1,     3,     3,     3,
       1,     4,     3,     4,     3,     3,     2,     2,     6,     7,
       1,     3,     1,     2,     2,     2,     2,     4,     4,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     5,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     5,
       2,     1,     1,     1,     2,     2,     3,     1,     2,     1,
       2,     1,     1,     3,     2,     3,     1,     4,     1,     1,
       1,     1,     2,     1,     1,     3,     3,     4,     6,     5,
       5,     6,     5,     4,     4,     3,     4,     3,     2,     2,
       1,     1,     2,     1,     3,     2,     1,     2,     1,     1,
       3,     2,     3,     5,     4,     5,     4,     3,     3,     3,
       4,     6,     5,     5,     6,     4,     4,     2,     3,     3,
       4,     1,     2,     1,     4,     3,     2,     1,     2,     3,
       2,     7,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     0,     2,     6,     2,
       3,     0,     1,     1,     1,     1,     1,     4,     6,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     8,
       2,     3,     0,     1,     1,     1,     1,     1,     4,     6,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     7,     2,     3,     0,
       1,     1,     1,     1,     1,     4,     6,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     6,
       2,     3,     0,     1,     1,     1,     1,     1,     4,     6,
       1,     1,     1,     1,     1,     1,     1,     2,     6,     2,
       3,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     5,     2,     3,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     6,     2,     3,     0,     1,
       1,     1,     1,     1,     1,     1,     4,     2,    10,     2,
       3,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     6,     1,     1,     1,     1,     2,     9,
       2,     3,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     6,     1,     1,     1,     1,     2,
       9,     2,     3,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     6,     1,     1,     2,     8,     2,     3,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     8,     2,     3,     0,
       1,     1,     1,     1,     1,     4,     6,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     7,     2,     3,     0,     1,     1,     1,     1,
       1,     4,     6,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     7,     2,     3,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     6,     2,     3,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     6,     2,
       3,     0,     1,     1,     1,     1,     1,     4,     6,     1,
       1,     1,     1,     1,     1,     1,     1,     8,     2,     3,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       7,     2,     3,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     6,
       2,     3,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     5,     2,     3,     0,     1,     1,
       1,     1,     1,     1,     5,     2,     3,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     6,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     5,     2,     3,     0,
       1,     1,     1,     1,     1,     4,     6,     1,     1,     1,
       6,     2,     3,     0,     1,     1,     1,     4,     2,     7,
       2,     3,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     6,     2,     3,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       5,     2,     3,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     2,     3,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     2,
       3,     0,     2,     6,     1,     4,     5,     1,     4,     1,
       6,     2,     3,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     6,     2,     3,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     2,     3,     0,     1,     1,     1,
       1,     1,     5,     2,     3,     0,     1,     1,     1,     1,
       1,     1,     4,     2,     5,     2,     3,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       2,     3,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     7,     4,     4,     5,     3,     4,
       4,     7,     2,     3,     0,     1,     1,     1,     1,     1,
       7,     2,     3,     0,     1,     1,     1,     1,     1,     5,
       6,     7,     6,     4,     4,     4,     4,     6,     4,     4,
       4,     4,     4,     6,     4,     1,     1,     1,     1,     4,
       4,     4,     1,     1,     6,     1,     1,     1,     0,     4,
       1,     1,     1,     1,     1,     1,     0,     1,     0,     3,
       4,     1,     4,     4,     6,     6,     1,     1,     0,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     5,     5,
       1,     1,     3,     3,     2,     4,     3,     1,     1,     3,
       3,     3,     3,     4,     3,     1,     1,     1,     1,     1,
       1,     0,     4,     4,     4,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 194: /* iteration_statement_for: FOR  */
#line 436 "switches.y"
                {
			if(!firstPass)
				WRITE("%s", "    for");
				
		}
#line 3414 "switches.tab.c"
    break;

  case 247: /* target_simd_construct: target_simd_directive iteration_statement_for  */
#line 654 "switches.y"
                {
			
		}
#line 3422 "switches.tab.c"
    break;

  case 248: /* target_simd_directive: PRAGMA OMP TARGET SIMD target_simd_clause_multi ENDLN  */
#line 661 "switches.y"
                {
			if(!firstPass)
				WRITE("%s", "FOUND PRAGMA [ target simd ]\n");
			
			inReduction = FALSE;
			line++;
			
			
		}
#line 3436 "switches.tab.c"
    break;

  case 257: /* target_simd_clause: IS_DEVICE_PTR '(' variable_list ')'  */
#line 685 "switches.y"
                {
			inWhichDataList = 0;
		}
#line 3444 "switches.tab.c"
    break;

  case 268: /* target_parallel_for_simd_construct: target_parallel_for_simd_directive iteration_statement_for  */
#line 706 "switches.y"
                {
			
		}
#line 3452 "switches.tab.c"
    break;

  case 269: /* target_parallel_for_simd_directive: PRAGMA OMP TARGET PARALLEL FOR SIMD target_parallel_for_simd_clause_multi ENDLN  */
#line 713 "switches.y"
                {
			if(!firstPass)
				WRITE("%s", "FOUND PRAGMA [ target parallel for simd ]\n");
				
			inReduction = FALSE;
			line++;
			
		}
#line 3465 "switches.tab.c"
    break;

  case 278: /* target_parallel_for_simd_clause: IS_DEVICE_PTR '(' variable_list ')'  */
#line 736 "switches.y"
                {
			inWhichDataList = 0;
		}
#line 3473 "switches.tab.c"
    break;

  case 295: /* target_parallel_for_construct: target_parallel_for_directive iteration_statement_for  */
#line 763 "switches.y"
                {
			
		}
#line 3481 "switches.tab.c"
    break;

  case 296: /* target_parallel_for_directive: PRAGMA OMP TARGET PARALLEL FOR target_parallel_for_clause_multi ENDLN  */
#line 770 "switches.y"
                {
			if(!firstPass)
				WRITE("%s", "FOUND PRAGMA [ target parallel for ]\n");
				
			inReduction = FALSE;
			line++;
			
		}
#line 3494 "switches.tab.c"
    break;

  case 305: /* target_parallel_for_clause: IS_DEVICE_PTR '(' variable_list ')'  */
#line 793 "switches.y"
                {
			inWhichDataList = 0;
		}
#line 3502 "switches.tab.c"
    break;

  case 319: /* target_parallel_directive: PRAGMA OMP TARGET PARALLEL target_parallel_clause_multi ENDLN  */
#line 820 "switches.y"
                {
			if(!firstPass)
				WRITE("%s", "FOUND PRAGMA [ target parallel  ]\n");
				
			inReduction = FALSE;
			line++;
			
		}
#line 3515 "switches.tab.c"
    break;

  case 328: /* target_parallel_clause: IS_DEVICE_PTR '(' variable_list ')'  */
#line 843 "switches.y"
                {
			inWhichDataList = 0;
		}
#line 3523 "switches.tab.c"
    break;

  case 337: /* taskloop_simd_construct: taskloop_simd_directive iteration_statement_for  */
#line 862 "switches.y"
                {
			
		}
#line 3531 "switches.tab.c"
    break;

  case 338: /* taskloop_simd_directive: PRAGMA OMP TASKLOOP SIMD taskloop_simd_clause_multi ENDLN  */
#line 869 "switches.y"
                {
			if(!firstPass)
				WRITE("%s", "FOUND PRAGMA [ taskloop simd ]\n");
				
			inReduction = FALSE;
			line++;
			
		}
#line 3544 "switches.tab.c"
    break;

  case 361: /* taskloop_construct: taskloop_directive iteration_statement_for  */
#line 914 "switches.y"
                {
			
		}
#line 3552 "switches.tab.c"
    break;

  case 362: /* taskloop_directive: PRAGMA OMP TASKLOOP taskloop_clause_multi ENDLN  */
#line 921 "switches.y"
                {
			if(inReduction)
				handlePragma_taskConstruct(&Graph, lists, TASK_REDUCTION, localKernels, localStateOfDefault, localPriority, localScheduling, localintStr, localSimd, currentFunction-1, currentTask);
			else
				handlePragma_taskConstruct(&Graph, lists, TASK_LOOP, localKernels, localStateOfDefault, localPriority, localScheduling, localintStr, localSimd, currentFunction-1, currentTask);
			
			if(!firstPass)
				bracketsEnabled = TRUE;
			localDependenceType = 0;
			localKernels = 0;
			localPriority = 0;
			localStateOfDefault = 0;
			localScheduling = 0;
			localintStr.localInt = 0;
			localintStr.localStr = NULL;
			localSimd = 0;
			inReduction = FALSE;
			currentTask++;
			line++;			
		}
#line 3577 "switches.tab.c"
    break;

  case 385: /* declare_simd_directive: PRAGMA OMP DECLARE SIMD declare_simd_directive_clause_multi ENDLN  */
#line 982 "switches.y"
                {
			if(!firstPass)
				WRITE("%s", "FOUND PRAGMA [ declare simd ]\n");
			line++;
			
		}
#line 3588 "switches.tab.c"
    break;

  case 396: /* taskgroup_directive: PRAGMA OMP TASKGROUP ENDLN  */
#line 1015 "switches.y"
                {
			if(!firstPass)
				WRITE("%s", "FOUND PRAGMA [ taskgroup ]\n");
			line++;
			
		}
#line 3599 "switches.tab.c"
    break;

  case 397: /* target_teams_distribute_parallel_for_simd_construct: target_teams_distribute_parallel_for_simd_directive iteration_statement_for  */
#line 1028 "switches.y"
                {
			
		}
#line 3607 "switches.tab.c"
    break;

  case 398: /* target_teams_distribute_parallel_for_simd_directive: PRAGMA OMP TARGET TEAMS DISTRIBUTE PARALLEL FOR SIMD target_teams_distribute_parallel_for_simd_clause_multi ENDLN  */
#line 1035 "switches.y"
                {
			if(!firstPass)
				WRITE("%s", "FOUND PRAGMA [ target teams distribute parallel for simd ]\n");
			
			inReduction = FALSE;
			line++;
			
		}
#line 3620 "switches.tab.c"
    break;

  case 422: /* target_teams_distribute_parallel_for_simd_clause: IS_DEVICE_PTR '(' variable_list ')'  */
#line 1073 "switches.y"
                {
			inWhichDataList = 0;
		}
#line 3628 "switches.tab.c"
    break;

  case 428: /* teams_distribute_parallel_for_simd_construct: teams_distribute_parallel_for_simd_directive iteration_statement_for  */
#line 1089 "switches.y"
                {
			
		}
#line 3636 "switches.tab.c"
    break;

  case 429: /* teams_distribute_parallel_for_simd_directive: PRAGMA OMP TEAMS DISTRIBUTE PARALLEL FOR SIMD teams_distribute_parallel_for_simd_clause_multi ENDLN  */
#line 1096 "switches.y"
                {
			if(!firstPass)
				WRITE("%s", "FOUND PRAGMA [ teams distribute parallel for simd ]\n");
				
			inReduction = FALSE;
			line++;
			
		}
#line 3649 "switches.tab.c"
    break;

  case 453: /* teams_distribute_parallel_for_simd_clause: IS_DEVICE_PTR '(' variable_list ')'  */
#line 1134 "switches.y"
                {
			inWhichDataList = 0;
		}
#line 3657 "switches.tab.c"
    break;

  case 459: /* target_teams_distribute_parallel_for_construct: target_teams_distribute_parallel_for_directive iteration_statement_for  */
#line 1150 "switches.y"
                {
			
		}
#line 3665 "switches.tab.c"
    break;

  case 460: /* target_teams_distribute_parallel_for_directive: PRAGMA OMP TARGET TEAMS DISTRIBUTE PARALLEL FOR target_teams_distribute_parallel_for_clause_multi ENDLN  */
#line 1157 "switches.y"
                {
			if(!firstPass)
				WRITE("%s", "FOUND PRAGMA [ target teams distribute parallel for ]\n");
				
			inReduction = FALSE;
			line++;
			
		}
#line 3678 "switches.tab.c"
    break;

  case 481: /* target_teams_distribute_parallel_for_clause: IS_DEVICE_PTR '(' variable_list ')'  */
#line 1192 "switches.y"
                {
			inWhichDataList = 0;
		}
#line 3686 "switches.tab.c"
    break;

  case 485: /* teams_distribute_parallel_for_construct: teams_distribute_parallel_for_directive iteration_statement_for  */
#line 1206 "switches.y"
                {
			
		}
#line 3694 "switches.tab.c"
    break;

  case 486: /* teams_distribute_parallel_for_directive: PRAGMA OMP TEAMS DISTRIBUTE PARALLEL FOR teams_distribute_parallel_for_clause_multi ENDLN  */
#line 1213 "switches.y"
                {
			if(!firstPass)
				WRITE("%s", "FOUND PRAGMA [ teams distribute parallel for ]\n");
				
			inReduction = FALSE;
			line++;
			
		}
#line 3707 "switches.tab.c"
    break;

  case 505: /* target_teams_distribute_simd_construct: target_teams_distribute_simd_directive iteration_statement_for  */
#line 1253 "switches.y"
                {
			
		}
#line 3715 "switches.tab.c"
    break;

  case 506: /* target_teams_distribute_simd_directive: PRAGMA OMP TARGET TEAMS DISTRIBUTE SIMD target_teams_distribute_simd_clause_multi ENDLN  */
#line 1260 "switches.y"
                {
			if(!firstPass)
				WRITE("%s", "FOUND PRAGMA [ target teams distribute simd ]\n");
				
			inReduction = FALSE;
			line++;
			
		}
#line 3728 "switches.tab.c"
    break;

  case 515: /* target_teams_distribute_simd_clause: IS_DEVICE_PTR '(' variable_list ')'  */
#line 1283 "switches.y"
                {
			inWhichDataList = 0;
		}
#line 3736 "switches.tab.c"
    break;

  case 531: /* target_teams_distribute_construct: target_teams_distribute_directive iteration_statement_for  */
#line 1309 "switches.y"
                {
			
		}
#line 3744 "switches.tab.c"
    break;

  case 532: /* target_teams_distribute_directive: PRAGMA OMP TARGET TEAMS DISTRIBUTE target_teams_distribute_clause_multi ENDLN  */
#line 1316 "switches.y"
                {
			if(!firstPass)
				WRITE("%s", "FOUND PRAGMA [ target teams distribute ]\n");
				
			inReduction = FALSE;
			line++;
			
		}
#line 3757 "switches.tab.c"
    break;

  case 541: /* target_teams_distribute_clause: IS_DEVICE_PTR '(' variable_list ')'  */
#line 1339 "switches.y"
                {
			inWhichDataList = 0;
		}
#line 3765 "switches.tab.c"
    break;

  case 553: /* teams_distribute_simd_construct: teams_distribute_simd_directive iteration_statement_for  */
#line 1361 "switches.y"
                {
			
		}
#line 3773 "switches.tab.c"
    break;

  case 554: /* teams_distribute_simd_directive: PRAGMA OMP TEAMS DISTRIBUTE SIMD teams_distribute_simd_clause_multi ENDLN  */
#line 1368 "switches.y"
                {
			if(!firstPass)
				WRITE("%s", "FOUND PRAGMA [ teams distribute simd ]\n");
				
			inReduction = FALSE;
			line++;
			
		}
#line 3786 "switches.tab.c"
    break;

  case 572: /* teams_distribute_construct: teams_distribute_directive iteration_statement_for  */
#line 1407 "switches.y"
                {
			
		}
#line 3794 "switches.tab.c"
    break;

  case 573: /* teams_distribute_directive: PRAGMA OMP TEAMS DISTRIBUTE teams_distribute_clause_multi ENDLN  */
#line 1414 "switches.y"
                {
			if(!firstPass)
				WRITE("%s", "FOUND PRAGMA [ teams distribute ]\n");
				
			inReduction = FALSE;
			line++;
			
		}
#line 3807 "switches.tab.c"
    break;

  case 588: /* target_teams_directive: PRAGMA OMP TARGET TEAMS target_teams_clause_multi ENDLN  */
#line 1453 "switches.y"
                {
			if(!firstPass)
				WRITE("%s", "FOUND PRAGMA [ target teams ]\n");
				
			inReduction = FALSE;
			line++;
			
		}
#line 3820 "switches.tab.c"
    break;

  case 597: /* target_teams_clause: IS_DEVICE_PTR '(' variable_list ')'  */
#line 1476 "switches.y"
                {
			inWhichDataList = 0;
		}
#line 3828 "switches.tab.c"
    break;

  case 607: /* distribute_parallel_for_simd_directive: PRAGMA OMP DISTRIBUTE PARALLEL FOR SIMD distribute_parallel_for_simd_clause_multi ENDLN  */
#line 1499 "switches.y"
                {
			if(!firstPass)
				WRITE("%s", "FOUND PRAGMA [ distribute parallel for simd ]\n");
				
			inReduction = FALSE;
			line++;
			
		}
#line 3841 "switches.tab.c"
    break;

  case 629: /* distribute_parallel_for_construct: distribute_parallel_for_directive iteration_statement_for  */
#line 1542 "switches.y"
                {
			
		}
#line 3849 "switches.tab.c"
    break;

  case 630: /* distribute_parallel_for_directive: PRAGMA OMP DISTRIBUTE PARALLEL FOR distribute_parallel_for_clause_multi ENDLN  */
#line 1549 "switches.y"
                {
			if(!firstPass)
				WRITE("%s", "FOUND PRAGMA [ distribute parallel for ]\n");
				
			inReduction = FALSE;
			line++;
			
		}
#line 3862 "switches.tab.c"
    break;

  case 648: /* distribute_simd_construct: distribute_simd_directive iteration_statement_for  */
#line 1588 "switches.y"
                {
			
		}
#line 3870 "switches.tab.c"
    break;

  case 649: /* distribute_simd_directive: PRAGMA OMP DISTRIBUTE SIMD distribute_simd_clause_multi ENDLN  */
#line 1595 "switches.y"
                {
			if(!firstPass)
				WRITE("%s", "FOUND PRAGMA [ distribute simd ]\n");
				
			inReduction = FALSE;
			line++;
			
		}
#line 3883 "switches.tab.c"
    break;

  case 663: /* distribute_construct: distribute_directive iteration_statement_for  */
#line 1630 "switches.y"
                {
			
		}
#line 3891 "switches.tab.c"
    break;

  case 664: /* distribute_directive: PRAGMA OMP DISTRIBUTE distribute_clause_multi ENDLN  */
#line 1637 "switches.y"
                {
			if(!firstPass)
				WRITE("%s", "FOUND PRAGMA [ distribute ]\n");
			line++;
			
		}
#line 3902 "switches.tab.c"
    break;

  case 674: /* teams_directive: PRAGMA OMP TEAMS teams_clause_multi ENDLN  */
#line 1669 "switches.y"
                {
			if(!firstPass)
				WRITE("%s", "FOUND PRAGMA [ teams ]\n");
				
			inReduction = FALSE;
			line++;
			
		}
#line 3915 "switches.tab.c"
    break;

  case 686: /* target_update_directive: PRAGMA OMP TARGET UPDATE target_update_clause_seq ENDLN  */
#line 1705 "switches.y"
                {
			if(!firstPass)
				WRITE("%s", "FOUND PRAGMA [ target update ]\n");
			line++;
			
		}
#line 3926 "switches.tab.c"
    break;

  case 696: /* target_directive: PRAGMA OMP TARGET target_clause_multi ENDLN  */
#line 1737 "switches.y"
                {
			if(!firstPass)
				WRITE("%s", "FOUND PRAGMA [ target ]\n");
			line++;
			
		}
#line 3937 "switches.tab.c"
    break;

  case 705: /* target_clause: IS_DEVICE_PTR '(' variable_list ')'  */
#line 1758 "switches.y"
                {
			inWhichDataList = 0;
		}
#line 3945 "switches.tab.c"
    break;

  case 710: /* target_data_directive: PRAGMA OMP TARGET DATA target_data_clause_multi ENDLN  */
#line 1776 "switches.y"
                {
			if(!firstPass)
				WRITE("%s", "FOUND PRAGMA [ target data ]\n");
			line++;
			
		}
#line 3956 "switches.tab.c"
    break;

  case 717: /* target_data_clause: USE_DEVICE_PTR '(' variable_list ')'  */
#line 1795 "switches.y"
                {
			inWhichDataList = 0;
		}
#line 3964 "switches.tab.c"
    break;

  case 718: /* parallel_for_simd_construct: parallel_for_simd_directive iteration_statement_for  */
#line 1806 "switches.y"
                {
			
		}
#line 3972 "switches.tab.c"
    break;

  case 719: /* parallel_for_simd_directive: PRAGMA OMP PARALLEL FOR SIMD parallel_for_simd_clause_multi ENDLN  */
#line 1813 "switches.y"
                {
			handlePragma_parallelConstruct(&Graph, localKernels, localStateOfDefault, lists, currentFunction);
			if(inReduction)
				handlePragma_taskConstruct(&Graph, lists, TASK_REDUCTION, localKernels, localStateOfDefault, localPriority, localScheduling, localintStr, localSimd, currentFunction, currentTask);
			else
				handlePragma_taskConstruct(&Graph, lists, TASK_LOOP, localKernels, localStateOfDefault, localPriority, localScheduling, localintStr, localSimd, currentFunction, currentTask);
			
			if(!firstPass)
			{
				bracketsEnabled = TRUE;
				inParallelFor = TRUE;
			}
			localKernels = 0;
			localPriority = 0;
			localStateOfDefault = 0;
			localScheduling = 0;
			localintStr.localInt = 0;
			localintStr.localStr = NULL;
			localSimd = 0;
			inReduction = FALSE;
			currentFunction++;
			currentTask++;
			line++;
			
		}
#line 4002 "switches.tab.c"
    break;

  case 740: /* for_simd_construct: for_simd_directive iteration_statement_for  */
#line 1872 "switches.y"
                {
			
		}
#line 4010 "switches.tab.c"
    break;

  case 741: /* for_simd_directive: PRAGMA OMP FOR SIMD for_simd_clause_multi ENDLN  */
#line 1879 "switches.y"
                {
			if(inReduction)
				handlePragma_taskConstruct(&Graph, lists, TASK_REDUCTION, localKernels, localStateOfDefault, localPriority, localScheduling, localintStr, localSimd, currentFunction-1, currentTask);
			else
				handlePragma_taskConstruct(&Graph, lists, TASK_LOOP, localKernels, localStateOfDefault, localPriority, localScheduling, localintStr, localSimd, currentFunction-1, currentTask);
			if(!firstPass)
				bracketsEnabled = TRUE;
			localDependenceType = 0;
			localKernels = 0;
			localPriority = 0;
			localStateOfDefault = 0;
			localScheduling = 0;
			localintStr.localInt = 0;
			localintStr.localStr = NULL;
			localSimd = 0;
			inReduction = FALSE;
			currentTask++;
			line++;
			
		}
#line 4035 "switches.tab.c"
    break;

  case 759: /* simd_construct: simd_directive iteration_statement_for  */
#line 1930 "switches.y"
                {
			
		}
#line 4043 "switches.tab.c"
    break;

  case 760: /* simd_directive: PRAGMA OMP SIMD simd_clause_multi ENDLN  */
#line 1938 "switches.y"
                {
			if(!firstPass)
				WRITE("%s", "FOUND PRAGMA [ simd ]\n");
				
			inReduction = FALSE;
			line++;
			
		}
#line 4056 "switches.tab.c"
    break;

  case 773: /* task_directive: PRAGMA OMP TASK task_clause_multi ENDLN  */
#line 1975 "switches.y"
                {
			handlePragma_taskConstruct(&Graph, lists, TASK_SIMPLE, 1, localStateOfDefault, localPriority, localScheduling, localintStr, localSimd, currentFunction-1, currentTask);
			if(!firstPass)
				bracketsEnabled = TRUE;
			localDependenceType = 0;
			localStateOfDefault = 0;
			localScheduling = 0;
			localintStr.localInt = 0;
			localintStr.localStr = NULL;
			localPriority = 0;
			localSimd = 0;
			currentTask++;
			line++;
		}
#line 4075 "switches.tab.c"
    break;

  case 788: /* ordered_directive: PRAGMA OMP ORDERED ordered_clause_multi ENDLN  */
#line 2020 "switches.y"
                {
			if(!firstPass)
				WRITE("%s", "FOUND PRAGMA [ ordered ]\n");
			line++;
			
		}
#line 4086 "switches.tab.c"
    break;

  case 793: /* atomic_directive: PRAGMA OMP ATOMIC atomic_clause seq_cst_clause ENDLN  */
#line 2044 "switches.y"
                {
			if(!firstPass)
				WRITE("%s", "FOUND PRAGMA [ atomic ]\n");
			line++;
			
		}
#line 4097 "switches.tab.c"
    break;

  case 795: /* critical_directive: PRAGMA OMP CRITICAL ENDLN  */
#line 2062 "switches.y"
                {
			if(!firstPass)
				WRITE("%s", "FOUND PRAGMA [ critical ]\n");
			line++;
		}
#line 4107 "switches.tab.c"
    break;

  case 796: /* critical_directive: PRAGMA OMP CRITICAL region_phrase ENDLN  */
#line 2068 "switches.y"
                {
			if(!firstPass)
				WRITE("%s", "FOUND PRAGMA [ critical (...) ]\n");
			line++;
		}
#line 4117 "switches.tab.c"
    break;

  case 798: /* master_directive: PRAGMA OMP MASTER ENDLN  */
#line 2085 "switches.y"
                {
			handlePragma_taskConstruct(&Graph, lists, TASK_MASTER, 1, localStateOfDefault, localPriority, localScheduling, localintStr, localSimd, currentFunction-1, currentTask);
			if(!firstPass)
				bracketsEnabled = TRUE;
			localDependenceType = 0;
			localStateOfDefault = 0;
			localScheduling = 0;
			localintStr.localInt = 0;
			localintStr.localStr = NULL;
			localPriority = 0;
			localSimd = 0;
			currentTask++;
			line++;
		}
#line 4136 "switches.tab.c"
    break;

  case 800: /* parallel_sections_directive: PRAGMA OMP PARALLEL SECTIONS parallel_sections_clause_multi ENDLN  */
#line 2111 "switches.y"
                {
			handlePragma_parallelConstruct(&Graph, localKernels, localStateOfDefault, lists, currentFunction);
			handlePragma_sectionsConstruct(&Graph, lists);
			if(!firstPass)
				bracketsEnabled = TRUE;
			localKernels = 0;
			localStateOfDefault = 0;
			inReduction = FALSE;
			currentFunction++;
			line++;
			
		}
#line 4153 "switches.tab.c"
    break;

  case 814: /* parallel_for_construct: parallel_for_directive iteration_statement_for  */
#line 2150 "switches.y"
                {
			
		}
#line 4161 "switches.tab.c"
    break;

  case 815: /* parallel_for_directive: PRAGMA OMP PARALLEL FOR parallel_for_clause_multi ENDLN  */
#line 2157 "switches.y"
                {
			handlePragma_parallelConstruct(&Graph, localKernels, localStateOfDefault, lists, currentFunction);
			
			if(inReduction)
				handlePragma_taskConstruct(&Graph, lists, TASK_REDUCTION, localKernels, localStateOfDefault, localPriority, localScheduling, localintStr, localSimd, currentFunction, currentTask);
			else
				handlePragma_taskConstruct(&Graph, lists, TASK_LOOP, localKernels, localStateOfDefault, localPriority, localScheduling, localintStr, localSimd, currentFunction, currentTask);
			
			if(!firstPass)
			{
				bracketsEnabled = TRUE;
				inParallelFor = TRUE;
			}
			localKernels = 0;
			localPriority = 0;
			localStateOfDefault = 0;
			localScheduling = 0;
			localintStr.localInt = 0;
			localintStr.localStr = NULL;
			localSimd = 0;
			inReduction = FALSE;
			currentFunction++;
			currentTask++;
			line++;
			
		}
#line 4192 "switches.tab.c"
    break;

  case 833: /* single_directive: PRAGMA OMP SINGLE single_clause_multi ENDLN  */
#line 2217 "switches.y"
                {
			handlePragma_taskConstruct(&Graph, lists, TASK_SIMPLE, 1, localStateOfDefault, localPriority, localScheduling, localintStr, localSimd, currentFunction-1, currentTask);
			if(!firstPass)
				bracketsEnabled = TRUE;
			localDependenceType = 0;
			localStateOfDefault = 0;
			localScheduling = 0;
			localintStr.localInt = 0;
			localintStr.localStr = NULL;
			localPriority = 0;
			localSimd = 0;
			currentTask++;
			line++;
		}
#line 4211 "switches.tab.c"
    break;

  case 842: /* sections_directive: PRAGMA OMP SECTIONS sections_clause_multi ENDLN  */
#line 2256 "switches.y"
                {
			handlePragma_sectionsConstruct(&Graph, lists);
			if(!firstPass)
				bracketsEnabled = TRUE;
				
			inReduction = FALSE;
			line++;	
		}
#line 4224 "switches.tab.c"
    break;

  case 852: /* section_directive: PRAGMA OMP SECTION ENDLN  */
#line 2289 "switches.y"
                {
			handlePragma_sectionDirective(&Graph, lists, currentFunction -1, currentTask);
			if(!firstPass)
				bracketsEnabled = TRUE;
			currentTask++;
			line++;
			
		}
#line 4237 "switches.tab.c"
    break;

  case 854: /* for_directive: PRAGMA OMP FOR for_clause_multi ENDLN  */
#line 2309 "switches.y"
                {
			if(inReduction)
				handlePragma_taskConstruct(&Graph, lists, TASK_REDUCTION, localKernels, localStateOfDefault, localPriority, localScheduling, localintStr, localSimd, currentFunction-1, currentTask);
			else
				handlePragma_taskConstruct(&Graph, lists, TASK_LOOP, localKernels, localStateOfDefault, localPriority, localScheduling, localintStr, localSimd, currentFunction-1, currentTask);
			
			if(!firstPass)
				bracketsEnabled = TRUE;
			localDependenceType = 0;
			localKernels = 0;
			localPriority = 0;
			localStateOfDefault = 0;
			localScheduling = 0;
			localintStr.localInt = 0;
			localintStr.localStr = NULL;
			localSimd = 0;
			inReduction = FALSE;
			currentTask++;
			line++;
			
		}
#line 4263 "switches.tab.c"
    break;

  case 869: /* parallel_directive: PRAGMA OMP PARALLEL parallel_clause_multi ENDLN  */
#line 2361 "switches.y"
                {
			handlePragma_parallelConstruct(&Graph, localKernels, localStateOfDefault, lists, currentFunction);
			
			if(!firstPass)
				bracketsEnabled = TRUE;
			localKernels = 0;
			localStateOfDefault = 0;
			inReduction = FALSE;
			currentFunction++;
			line++;
			
			
		}
#line 4281 "switches.tab.c"
    break;

  case 883: /* omp_declare_reduction: PRAGMA OMP DECLARE reduction_clause ENDLN  */
#line 2401 "switches.y"
        {
        if(!firstPass)
			WRITE("%s", "FOUND PRAGMA [ declare reduction ]\n");
        line++;

    }
#line 4292 "switches.tab.c"
    break;

  case 884: /* omp_threadprivate: PRAGMA OMP THREADPRIVATE '(' variable_list ')' ENDLN  */
#line 2414 "switches.y"
        {
        handlePragma_threadPrivateDirective(&Graph, lists);    
        line++;
        inWhichDataList = 0;
    }
#line 4302 "switches.tab.c"
    break;

  case 885: /* omp_barrier: PRAGMA OMP BARRIER ENDLN  */
#line 2427 "switches.y"
        {
        if(!firstPass)
			WRITE("%s", "FOUND PRAGMA [ barrier ]\n");
        line++;
    }
#line 4312 "switches.tab.c"
    break;

  case 886: /* omp_flush: PRAGMA OMP FLUSH ENDLN  */
#line 2440 "switches.y"
        {
        if(!firstPass)
			WRITE("%s", "FOUND PRAGMA [ flush ]\n");
        line++;
    }
#line 4322 "switches.tab.c"
    break;

  case 887: /* omp_flush: PRAGMA OMP FLUSH flush_list ENDLN  */
#line 2447 "switches.y"
        {
        if(!firstPass)
			WRITE("%s", "FOUND PRAGMA [ flush ]\n");
        line++;

    }
#line 4333 "switches.tab.c"
    break;

  case 888: /* flush_list: '(' variable_list ')'  */
#line 2457 "switches.y"
    {
		inWhichDataList = 0;
    }
#line 4341 "switches.tab.c"
    break;

  case 889: /* omp_taskwait: PRAGMA OMP TASKWAIT ENDLN  */
#line 2468 "switches.y"
        {
        if(!firstPass)
			WRITE("%s", "FOUND PRAGMA [ taskwait ]\n");
        line++;
    }
#line 4351 "switches.tab.c"
    break;

  case 890: /* omp_taskyield: PRAGMA OMP TASKYIELD ENDLN  */
#line 2481 "switches.y"
        {
        if(!firstPass)
			WRITE("%s", "FOUND PRAGMA [ taskyield ]\n");
        line++;
    }
#line 4361 "switches.tab.c"
    break;

  case 891: /* omp_target_enter_data: PRAGMA OMP TARGET ENTER DATA omp_target_enter_data_clause_multi ENDLN  */
#line 2493 "switches.y"
        {
        if(!firstPass)
			WRITE("%s", "FOUND PRAGMA [ target enter data ]\n");
        line++;

    }
#line 4372 "switches.tab.c"
    break;

  case 900: /* omp_target_exit_data: PRAGMA OMP TARGET EXIT DATA omp_target_exit_data_clause_multi ENDLN  */
#line 2520 "switches.y"
        {
        if(!firstPass)
			WRITE("%s", "FOUND PRAGMA [ target exit data ]\n");
        line++;

    }
#line 4383 "switches.tab.c"
    break;

  case 909: /* omp_cancel: PRAGMA OMP CANCEL type_construct_clause ENDLN  */
#line 2547 "switches.y"
        {
        if(!firstPass)
			WRITE("%s", "FOUND PRAGMA [ cancel ]\n");
        line++;

    }
#line 4394 "switches.tab.c"
    break;

  case 910: /* omp_cancel: PRAGMA OMP CANCEL type_construct_clause if_clause ENDLN  */
#line 2555 "switches.y"
        {
        if(!firstPass)
			WRITE("%s", "FOUND PRAGMA [ cancel ]\n");
        line++;

    }
#line 4405 "switches.tab.c"
    break;

  case 911: /* omp_cancel: PRAGMA OMP CANCEL type_construct_clause ',' if_clause ENDLN  */
#line 2563 "switches.y"
        {
        if(!firstPass)
			WRITE("%s", "FOUND PRAGMA [ cancel ]\n");
        line++;

    }
#line 4416 "switches.tab.c"
    break;

  case 912: /* omp_cancellation_point: PRAGMA OMP CANCELLATION POINT type_construct_clause ENDLN  */
#line 2577 "switches.y"
        {
        if(!firstPass)
			WRITE("%s", "FOUND PRAGMA [ cancellation point ]\n");
        line++;

    }
#line 4427 "switches.tab.c"
    break;

  case 930: /* simd_len_clause: SIMDLEN '(' I_CONSTANT ')'  */
#line 2642 "switches.y"
                {
			localSimd = yyvsp[-1];
		}
#line 4435 "switches.tab.c"
    break;

  case 934: /* depend_clause: DEPEND '(' dependence_type ':' variable_array_section_list ')'  */
#line 2661 "switches.y"
                {
			
			inWhichDataList = 0;
		}
#line 4444 "switches.tab.c"
    break;

  case 935: /* dependence_type: IN  */
#line 2668 "switches.y"
                                        { inWhichDataList = IN_DEPEND_IN; 	 }
#line 4450 "switches.tab.c"
    break;

  case 936: /* dependence_type: OUT  */
#line 2669 "switches.y"
                                        { inWhichDataList = IN_DEPEND_OUT;	 }
#line 4456 "switches.tab.c"
    break;

  case 937: /* dependence_type: INOUT  */
#line 2670 "switches.y"
                                { inWhichDataList = IN_DEPEND_INOUT; }
#line 4462 "switches.tab.c"
    break;

  case 938: /* dependence_type: %empty  */
#line 2671 "switches.y"
                                        { yyerror("Dependence type not recognized"); }
#line 4468 "switches.tab.c"
    break;

  case 939: /* priority_clause: PRIORITY '(' I_CONSTANT ')'  */
#line 2677 "switches.y"
                {
			localPriority = yyvsp[-1];
		}
#line 4476 "switches.tab.c"
    break;

  case 950: /* copy_private_clause: COPYPRIVATE '(' variable_list ')'  */
#line 2706 "switches.y"
                {
			inWhichDataList = 0;
		}
#line 4484 "switches.tab.c"
    break;

  case 953: /* schedule_clause: SCHEDULE '(' schedule_kind ')'  */
#line 2717 "switches.y"
                {
			localintStr.localInt = 0;
			localintStr.localStr = NULL;
		}
#line 4493 "switches.tab.c"
    break;

  case 954: /* schedule_clause: SCHEDULE '(' schedule_kind ',' I_CONSTANT ')'  */
#line 2722 "switches.y"
                {
			localintStr.localInt = yyvsp[-1];
		}
#line 4501 "switches.tab.c"
    break;

  case 955: /* schedule_clause: SCHEDULE '(' schedule_kind ',' IDENTIFIER ')'  */
#line 2726 "switches.y"
                {	
			localintStr.localStr = (char *)malloc(sizeof(char)*strlen((char*)yyvsp[-1]));
			strcpy(localintStr.localStr, (char*)yyvsp[-1]);
		}
#line 4510 "switches.tab.c"
    break;

  case 956: /* schedule_kind: STATIC  */
#line 2734 "switches.y"
                                { localScheduling = LOOP_SCHED_STATIC;  }
#line 4516 "switches.tab.c"
    break;

  case 957: /* schedule_kind: CROSS  */
#line 2735 "switches.y"
                                { localScheduling = LOOP_SCHED_CROSS;   }
#line 4522 "switches.tab.c"
    break;

  case 958: /* schedule_kind: %empty  */
#line 2736 "switches.y"
                                        { yyerror("Scheduling policy not recognized"); }
#line 4528 "switches.tab.c"
    break;

  case 959: /* num_threads_clause: NUM_THREADS '(' I_CONSTANT ')'  */
#line 2742 "switches.y"
                {
			localKernels = yyvsp[-1];
		}
#line 4536 "switches.tab.c"
    break;

  case 960: /* copyin_clause: COPYIN '(' variable_list ')'  */
#line 2749 "switches.y"
                {
			inWhichDataList = 0;
		}
#line 4544 "switches.tab.c"
    break;

  case 961: /* default_clause: DEFAULT '(' SHARED ')'  */
#line 2756 "switches.y"
                {
			localStateOfDefault = DEFAULT_SHARED;
		}
#line 4552 "switches.tab.c"
    break;

  case 962: /* default_clause: DEFAULT '(' NONE ')'  */
#line 2760 "switches.y"
                {
			localStateOfDefault = DEFAULT_NONE;
		}
#line 4560 "switches.tab.c"
    break;

  case 963: /* private_clause: PRIVATE '(' variable_list ')'  */
#line 2767 "switches.y"
                {
			inWhichDataList = 0;
		}
#line 4568 "switches.tab.c"
    break;

  case 964: /* first_private_clause: FIRSTPRIVATE '(' variable_list ')'  */
#line 2774 "switches.y"
                {
			inWhichDataList = 0;
		}
#line 4576 "switches.tab.c"
    break;

  case 965: /* last_private_clause: LASTPRIVATE '(' variable_list ')'  */
#line 2781 "switches.y"
                {
			inWhichDataList = 0;
		}
#line 4584 "switches.tab.c"
    break;

  case 966: /* shared_clause: SHARED '(' variable_list ')'  */
#line 2788 "switches.y"
                {
			inWhichDataList = 0;
		}
#line 4592 "switches.tab.c"
    break;

  case 967: /* reduction_clause: REDUCTION '(' reduction_identifier ':' variable_list ')'  */
#line 2795 "switches.y"
                {
			bzero(reductionType, sizeof(reductionType));
			inWhichDataList = 0;
		}
#line 4601 "switches.tab.c"
    break;

  case 968: /* linear_clause: LINEAR '(' variable_list optional_expression ')'  */
#line 2803 "switches.y"
                {
			inWhichDataList = 0;
		}
#line 4609 "switches.tab.c"
    break;

  case 969: /* aligned_clause: ALIGNED '(' variable_list optional_expression ')'  */
#line 2811 "switches.y"
                {
			inWhichDataList = 0;
		}
#line 4617 "switches.tab.c"
    break;

  case 970: /* variable_array_section_list: IDENTIFIER  */
#line 2819 "switches.y"
                {
			handlePragma_variableList(inWhichDataList, lists, (char *)yyvsp[0], NULL, reductionType, NULL);
		}
#line 4625 "switches.tab.c"
    break;

  case 972: /* variable_array_section_list: variable_array_section_list ',' IDENTIFIER  */
#line 2824 "switches.y"
                {
			handlePragma_variableList(inWhichDataList, lists, (char *)yyvsp[0], NULL, reductionType, NULL);
		
		}
#line 4634 "switches.tab.c"
    break;

  case 974: /* array_section: IDENTIFIER array_section_subscript  */
#line 2833 "switches.y"
                {
			handlePragma_variableList(inWhichDataList, lists, (char *)yyvsp[-1], NULL, reductionType, &indexes);
		}
#line 4642 "switches.tab.c"
    break;

  case 977: /* array_section_plain: IDENTIFIER  */
#line 2847 "switches.y"
                {
			if(firstPass)
				addToIndexes(&indexes, -1, -1, (char*)yyvsp[0], NULL);
		}
#line 4651 "switches.tab.c"
    break;

  case 978: /* array_section_plain: I_CONSTANT  */
#line 2852 "switches.y"
                {
			if(firstPass)
				addToIndexes(&indexes, yyvsp[0], -1, NULL, NULL);
		}
#line 4660 "switches.tab.c"
    break;

  case 979: /* array_section_plain: IDENTIFIER ':' IDENTIFIER  */
#line 2857 "switches.y"
                {
			if(firstPass)
				addToIndexes(&indexes, -1, -1, (char*)yyvsp[-2], (char*)yyvsp[0]);
		}
#line 4669 "switches.tab.c"
    break;

  case 980: /* array_section_plain: IDENTIFIER ':' I_CONSTANT  */
#line 2862 "switches.y"
                {
			if(firstPass)
				addToIndexes(&indexes, -1, yyvsp[0], (char*)yyvsp[-2], NULL);
		}
#line 4678 "switches.tab.c"
    break;

  case 981: /* array_section_plain: I_CONSTANT ':' IDENTIFIER  */
#line 2867 "switches.y"
                {
			if(firstPass)
				addToIndexes(&indexes, yyvsp[-2], -1, NULL, (char*)yyvsp[0]);
		}
#line 4687 "switches.tab.c"
    break;

  case 982: /* array_section_plain: I_CONSTANT ':' I_CONSTANT  */
#line 2872 "switches.y"
                {
			if(firstPass)
				addToIndexes(&indexes, yyvsp[-2], yyvsp[0], NULL, NULL);
		}
#line 4696 "switches.tab.c"
    break;

  case 984: /* variable_list: variable_list ',' IDENTIFIER  */
#line 2884 "switches.y"
    {
		handlePragma_variableList(inWhichDataList, lists, (char *)yyvsp[0], NULL, reductionType, NULL);
    }
#line 4704 "switches.tab.c"
    break;

  case 985: /* variable_list: IDENTIFIER  */
#line 2889 "switches.y"
    {
		handlePragma_variableList(inWhichDataList, lists, (char *)yyvsp[0], NULL, reductionType, NULL);
    }
#line 4712 "switches.tab.c"
    break;

  case 986: /* variable_list: I_CONSTANT  */
#line 2894 "switches.y"
    {
		handlePragma_variableList(inWhichDataList, lists, (char *)yyvsp[0], NULL, reductionType, NULL);
    }
#line 4720 "switches.tab.c"
    break;

  case 991: /* type_construct_clause: %empty  */
#line 2904 "switches.y"
        { yyerror("Construct type not recognized"); }
#line 4726 "switches.tab.c"
    break;

  case 996: /* reduction_identifier: IDENTIFIER  */
#line 2919 "switches.y"
                {
			strcpy(reductionType, (char*)yyvsp[0]);
		}
#line 4734 "switches.tab.c"
    break;

  case 997: /* reduction_identifier: '+'  */
#line 2923 "switches.y"
                {
			strcpy(reductionType, "+");
		}
#line 4742 "switches.tab.c"
    break;

  case 998: /* reduction_identifier: '*'  */
#line 2927 "switches.y"
                {
			strcpy(reductionType, "*");
		}
#line 4750 "switches.tab.c"
    break;

  case 999: /* reduction_identifier: '-'  */
#line 2931 "switches.y"
                {
			strcpy(reductionType, "-");
		}
#line 4758 "switches.tab.c"
    break;

  case 1000: /* reduction_identifier: '&'  */
#line 2935 "switches.y"
                {
			strcpy(reductionType, "&");
		}
#line 4766 "switches.tab.c"
    break;

  case 1001: /* reduction_identifier: '^'  */
#line 2939 "switches.y"
                {
			strcpy(reductionType, "^");
		}
#line 4774 "switches.tab.c"
    break;

  case 1002: /* reduction_identifier: '|'  */
#line 2943 "switches.y"
                {
			strcpy(reductionType, "|");
		}
#line 4782 "switches.tab.c"
    break;

  case 1003: /* reduction_identifier: AND_OPERAND  */
#line 2947 "switches.y"
                {
			strcpy(reductionType, "&&");
		}
#line 4790 "switches.tab.c"
    break;

  case 1004: /* reduction_identifier: OR_OPERAND  */
#line 2951 "switches.y"
                {
			strcpy(reductionType, "||");
		}
#line 4798 "switches.tab.c"
    break;

  case 1005: /* reduction_identifier: MIN  */
#line 2955 "switches.y"
                {
			strcpy(reductionType, "min");
		}
#line 4806 "switches.tab.c"
    break;

  case 1006: /* reduction_identifier: MAX  */
#line 2959 "switches.y"
                {
			strcpy(reductionType, "max");
		}
#line 4814 "switches.tab.c"
    break;


#line 4818 "switches.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 2964 "switches.y"


int main(int argc, char *argv[]){
    
    int i = 0, j = 0, k = 0, dum;
    char outputFile[INPUT_SIZE];
        
    
    /*** Recognize & store command line arguments in global variables ***/
    recognizeCommandlineArguments(argc, argv);
    
    /*** Initialize the SG ***/
    addSynchronizationGraph(&Graph);
    
    /*** Initialize stringFor array ***/
    stringFor = (char**)malloc(sizeof(char*) * SIZE);
    for(i = 0; i < SIZE; i++)
		stringFor[i] = (char*)malloc(sizeof(char) * SIZE);
    
    for(i = 0; i < SIZE; i++)
		bzero(stringFor[i], sizeof(stringFor[i]));		
    
    /*** Temp descriptor to stdout ***/
    __OUTP_IS_NOW_STDOUT
   
   /*** Start multiple parsing of files ***/
   do
   { 
	    /*** Start parsing once all input files ***/
	    do
	    {	
			line = 1;
			        
	        // Open Input File
	        inp = fopen(inputFiles[currentFile], "r");
	        if(!inp){
	            ERROR_COMMANDS("File [ %s ] not found!", inputFiles[currentFile])
	            exit(-1);
	        }
	        
	        // Open Main Output File and start printing parallel source 
	        if(!firstPass)
	        {
				// Open [ sw_*.c ] Main Output Files
		        if(strlen(inputFiles[currentFile]) > INPUT_SIZE){
		            ERROR_COMMANDS("Input file name [ %s ] is too large", inputFiles[currentFile]);
		            exit(-1);
		        }
		        bzero(outputFile, sizeof(outputFile));
		        
                if(runtimeSystem == RUNTIME_TAO || runtimeSystem == RUNTIME_TAOSW){
                    sprintf(outputFile, "sw_%sxx", inputFiles[currentFile]);
                }
                else{
                    sprintf(outputFile, "sw_%s", inputFiles[currentFile]);
                }                
		        
		        outp_sw_main = fopen(outputFile, "w");
		        if(!outp_sw_main){
		            ERROR_COMMANDS("File [ %s ] not created!", outputFile)
		            exit(-1);
		        }
		        __OUTP_IS_NOW_MAIN_FILE
                if(runtimeSystem == RUNTIME_STATIC){
                    WRITE("%s", "#include \"sw.h\"\n");
                }
                else{
                    WRITE("%s", "#include \"sw_tao.h\"\n");
                }
			}
	        
	        yyin = inp;         // Set input stream to be the input file
	        yyparse();          // Parse of input file
	        
	        fclose(inp);        		// Close input file
	        if(!firstPass)
			{
				__OUTP_IS_NOW_STDOUT
				fclose(outp_sw_main);       // Close output file
			}
				
	        // Move to next file
	        currentFile++;
	        bracketCounter = 0;
	        
	    }while(currentFile < totalInputFiles);
	       
	    
	    // Set Dependencies, Kernels to Functions, Scheduling, V-Kernels, etc.
		 
		if(firstPass)
		{
            // Define Assignment/Scheduling Policy here
            switch(assignmentPolicy){
                
                case SCHED_RR:
                                offlineScheduling_AssignKernelsToParallelFunctions(&Graph);
                                offlineScheduling_AssignKernelsToTasks_RoundRobin(&Graph);
                                break;
                                
                case SCHED_RANDOM:
                                offlineScheduling_AssignKernelsToParallelFunctions(&Graph);
                                offlineScheduling_AssignKernelsToTasks_Random(&Graph);
                                break;
                        
                case SCHED_FILE:
                                /* This assumes that the file is created by the GA
                                 *   - Kernels per parallel function are assumed to be the full number of the machine
                                 *   - If you need to load a scheduling policy from a file otherwise you must implement it here
                                 */
                                offlineScheduling_AssignKernelsToParallelFunctionsFromFile(&Graph);
                                offlineScheduling_AssignKernelsToTasks_File(&Graph);
                                break;
                                
                case SCHED_NSGA:
                                /* Assign Kernels to Parallel Functions and Count total kernels assigned */
                                totalKernels = offlineScheduling_CountKernelsToTasks_NSGA(&Graph);
                                
                                /* Allocate Memory for the parent, child and mixed populations */
                                allocatePopulation(&parent_pop, nsga->population);
                                allocatePopulation(&child_pop, nsga->population);
                                allocatePopulation(&mixed_pop, 2*(nsga->population));
                                
                                /* Randomly Initialize Generation 1 */
                                randomize();
                                NSGA_initializePopulation(&Graph, &parent_pop);
                                                                
                                /* Print Generation 1 to scheduling files and Evaluate Generation 1 */
                                NSGA_printPopulationToFiles(&parent_pop, 1);
                                NSGA_evaluatePopulation(&parent_pop, 1);
                                
                                /* Assign Rank and Crowding Distance */
                                NSGA_assign_rank_and_crowding_distance(&parent_pop);
                                
                                
                                /* Start Genetic Algorithm for all Generations */
                                for(i = 2; i <= nsga->generations; i++)
                                {
                                    /** Selection Process **/
                                    NSGA_selection(parent_pop, child_pop);
                                    
                                    /** Mutation Process **/
                                    NSGA_mutation(&child_pop);
                                    
                                    /** Print Generation to scheduling files and Evaluate Generation **/
                                    NSGA_printPopulationToFiles(&child_pop, i);
                                    NSGA_evaluatePopulation(&child_pop, i);
                                    
                                    /** Merge Parent with Child Generations **/
                                    NSGA_merge(&parent_pop, &child_pop, &mixed_pop);
                                    
                                    /** Fill Non-dominated Sorting **/
                                    NSGA_fill_nondominated_sort(&mixed_pop, &parent_pop);    
                                }

                                // End the process of the NSGA algorithm as soon as all generations are finished
                                exit(-1);
                                break;
                                
                default:
                    
                        ERROR_COMMANDS("Scheduling Policy [ %d ] not recognized!", assignmentPolicy)
                        exit(-1);
            }
            
			offlineScheduling_AssignVirtualKernelsToTasks(&Graph);			
			offlineScheduling_CreateDependencies(&Graph);
			offlineScheduling_TransitiveReductionOfConsumers(&Graph);
			offlineScheduling_TransitiveReductionOfProducers(&Graph);
		}
	    
	    
	    /*** Start printing in output files ***/
	    
	    if(firstPass)
	    {
            
            switch(runtimeSystem){
                
                case RUNTIME_STATIC:
                
                        // Open [ sw_threadpool.c ] Output File
                        bzero(outputFile, sizeof(outputFile));
                        sprintf(outputFile, "sw_threadpool.c");
                        outp_sw_threadpool = fopen(outputFile, "w");
                        if(!outp_sw_threadpool){
                            ERROR_COMMANDS("File [ %s ] not created!", outputFile)
                            exit(-1);
                        }
                        
                        // Print source code of [ sw_threadpool.c ]
                        printInThreadpoolFile(&Graph);
                        
                        
                        // Open [ sw.h ] Output File
                        bzero(outputFile, sizeof(outputFile));
                        sprintf(outputFile, "sw.h");
                        outp_sw_h = fopen(outputFile, "w");
                        if(!outp_sw_h){
                            ERROR_COMMANDS("File [ %s ] not created!", outputFile)
                            exit(-1);
                        }
                        
                        // Print source code of [ sw.h ]
                        printInSwFile(&Graph);
                        
                        
                        // Open [ sw_threads.c ] Output File
                        bzero(outputFile, sizeof(outputFile));
                        sprintf(outputFile, "sw_threads.c");
                        outp_sw_threads = fopen(outputFile, "w");
                        if(!outp_sw_threads){
                            ERROR_COMMANDS("File [ %s ] not created!", outputFile)
                            exit(-1);
                        }
                        
                        printInThreadsFile_headerSourceCode(&Graph);				// Print header source code of [ sw_threads.c ]
                        printInThreadsFile_SwitchesDeclaration(&Graph);				// Print switches in [ sw_threads.c ]
                        printInThreadsFile_taskCounters(&Graph);				    // Print taskCounters in [ sw_threads.c ]
                        printInThreadsFile_ResetSwitchesFunctions(&Graph);			// Print Reset Switches functions in [ sw_threads.c ]
                        printInThreadsFile_JobsThreadsFunction_SWITCHES(&Graph);	// Print Jobs Threads Function in [ sw_threads.c ]

                        break;
                        
                case RUNTIME_TAO:
                        
                        // Open [ sw.h ] Output File
                        bzero(outputFile, sizeof(outputFile));
                        sprintf(outputFile, "sw.h");
                        outp_sw_h = fopen(outputFile, "w");
                        if(!outp_sw_h){
                            ERROR_COMMANDS("File [ %s ] not created!", outputFile)
                            exit(-1);
                        }
                        
                        // Print source code of [ sw.h ]
                        printInSwFile(&Graph);
                        
                        
                        // Open [ sw_tao.h ] Output File -- TAO Classes
                        bzero(outputFile, sizeof(outputFile));
                        sprintf(outputFile, "sw_tao.h");
                        outp_sw_tao_h = fopen(outputFile, "w");
                        if(!outp_sw_tao_h){
                            ERROR_COMMANDS("File [ %s ] not created!", outputFile)
                            exit(-1);
                        }
                        
                        // Print source code of [ sw_tao.h ]
                        printInTaoFile(&Graph);
                        
                        
                        // Open [ sw_threads.c ] Output File
                        bzero(outputFile, sizeof(outputFile));
                        sprintf(outputFile, "sw_threads.c");
                        outp_sw_threads = fopen(outputFile, "w");
                        if(!outp_sw_threads){
                            ERROR_COMMANDS("File [ %s ] not created!", outputFile)
                            exit(-1);
                        }
                        
                        printInThreadsFile_headerSourceCode(&Graph);				// Print header source code of [ sw_threads.c ]
                        printInThreadsFile_JobsThreadsFunction_TAO(&Graph);		    // Print Jobs Threads Function in [ sw_threads.c ]
                        break;
                        
                case RUNTIME_TAOSW:
                
                        // Open [ sw.h ] Output File
                        bzero(outputFile, sizeof(outputFile));
                        sprintf(outputFile, "sw.h");
                        outp_sw_h = fopen(outputFile, "w");
                        if(!outp_sw_h){
                            ERROR_COMMANDS("File [ %s ] not created!", outputFile)
                            exit(-1);
                        }
                        
                        // Print source code of [ sw.h ]
                        printInSwFile(&Graph);
                        
                        
                        // Open [ sw_tao.h ] Output File -- TAO Classes
                        bzero(outputFile, sizeof(outputFile));
                        sprintf(outputFile, "sw_tao.h");
                        outp_sw_tao_h = fopen(outputFile, "w");
                        if(!outp_sw_tao_h){
                            ERROR_COMMANDS("File [ %s ] not created!", outputFile)
                            exit(-1);
                        }
                        
                        // Print source code of [ sw_tao.h ]
                        printInTaoFile(&Graph);
                        
                        
                        // Open [ sw_threads.c ] Output File
                        bzero(outputFile, sizeof(outputFile));
                        sprintf(outputFile, "sw_threads.c");
                        outp_sw_threads = fopen(outputFile, "w");
                        if(!outp_sw_threads){
                            ERROR_COMMANDS("File [ %s ] not created!", outputFile)
                            exit(-1);
                        }
                        
                        printInThreadsFile_headerSourceCode(&Graph);				// Print header source code of [ sw_threads.c ]
                        printInThreadsFile_SwitchesDeclaration(&Graph);				// Print switches in [ sw_threads.c ]
                        printInThreadsFile_taskCounters(&Graph);				    // Print taskCounters in [ sw_threads.c ]
                        printInThreadsFile_ResetSwitchesFunctions(&Graph);			// Print Reset Switches functions in [ sw_threads.c ]
                        printInThreadsFile_JobsThreadsFunction_TAO(&Graph);		// Print Jobs Threads Function in [ sw_threads.c ]
                
                        break;
                
                default:
                    ERROR_COMMANDS("[ %s ] not recognized!", "Runtime System")
                    exit(-1);
            }
		}
		
		
		if(!firstPass)
		{
            switch(runtimeSystem){
                
                case RUNTIME_STATIC:
                        fclose(outp_sw_h);       	// Close output file [ sw.h ]
                        fclose(outp_sw_threads);    // Close output file [ sw_threads.c ]
                        fclose(outp_sw_threadpool); // Close output file [ sw_threadpool.c ]
                        break;
                        
                case RUNTIME_TAO:
                        fclose(outp_sw_h);       	// Close output file [ sw.h ]
                        fclose(outp_sw_threads);    // Close output file [ sw_threads.c ]
                        break;
                        
                case RUNTIME_TAOSW:
                        fclose(outp_sw_h);       	// Close output file [ sw.h ]
                        fclose(outp_sw_threads);    // Close output file [ sw_threads.c ]
                        break;
                
                default:
                    ERROR_COMMANDS("[ %s ] not recognized!", "Runtime System")
                    exit(-1);
            }
		}
			
		pass++;
	    firstPass = FALSE;
	    currentFile = 0;
	    currentTask = 1;
	    currentFor  = 0;
	    currentFunction = 1;
	    
    }while(pass <= PARSES);
    
    
    printSG(&Graph, printSGFlag);
    printErrorMessages(); 
    return 0;
    
}


void yyerror(const char *s){
	
    ERROR("[ %s ]", line, s)
    exit(-1);					/* Return when you find an error in a file.
								 * Because when you check the next file it 
								 * will always find an error even if there
								 * isn't one.
								 */
}

