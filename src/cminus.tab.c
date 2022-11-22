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
#line 7 "src/cminus.y"

#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "parse.h"
#include "scan.h"
#include "util.h"

#define YYSTYPE TreeNode *

static stack savedName; /* for use in assignments */
static stack savedLine; /* ditto */

static TreeNode *savedTree; /* stores syntax tree for later return */
static int yylex(void);
int yyerror(char *s);

#line 90 "src/cminus.tab.c"

#ifndef YY_CAST
    #ifdef __cplusplus
        #define YY_CAST(Type, Val) static_cast<Type>(Val)
        #define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type>(Val)
    #else
        #define YY_CAST(Type, Val) ((Type)(Val))
        #define YY_REINTERPRET_CAST(Type, Val) ((Type)(Val))
    #endif
#endif
#ifndef YY_NULLPTR
    #if defined __cplusplus
        #if 201103L <= __cplusplus
            #define YY_NULLPTR nullptr
        #else
            #define YY_NULLPTR 0
        #endif
    #else
        #define YY_NULLPTR ((void *)0)
    #endif
#endif

#include "cminus.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t {
    YYSYMBOL_YYEMPTY = -2,
    YYSYMBOL_YYEOF = 0,            /* "end of file"  */
    YYSYMBOL_YYerror = 1,          /* error  */
    YYSYMBOL_YYUNDEF = 2,          /* "invalid token"  */
    YYSYMBOL_ENDFILE = 3,          /* ENDFILE  */
    YYSYMBOL_ERROR = 4,            /* ERROR  */
    YYSYMBOL_IF = 5,               /* IF  */
    YYSYMBOL_WHILE = 6,            /* WHILE  */
    YYSYMBOL_INT = 7,              /* INT  */
    YYSYMBOL_RETURN = 8,           /* RETURN  */
    YYSYMBOL_VOID = 9,             /* VOID  */
    YYSYMBOL_ID = 10,              /* ID  */
    YYSYMBOL_NUM = 11,             /* NUM  */
    YYSYMBOL_SEMI = 12,            /* SEMI  */
    YYSYMBOL_COMMA = 13,           /* COMMA  */
    YYSYMBOL_LPAREN = 14,          /* LPAREN  */
    YYSYMBOL_RPAREN = 15,          /* RPAREN  */
    YYSYMBOL_LBRACK = 16,          /* LBRACK  */
    YYSYMBOL_RBRACK = 17,          /* RBRACK  */
    YYSYMBOL_LBRACE = 18,          /* LBRACE  */
    YYSYMBOL_RBRACE = 19,          /* RBRACE  */
    YYSYMBOL_PLUS = 20,            /* PLUS  */
    YYSYMBOL_MINUS = 21,           /* MINUS  */
    YYSYMBOL_TIMES = 22,           /* TIMES  */
    YYSYMBOL_OVER = 23,            /* OVER  */
    YYSYMBOL_LT = 24,              /* LT  */
    YYSYMBOL_LTEQ = 25,            /* LTEQ  */
    YYSYMBOL_GTEQ = 26,            /* GTEQ  */
    YYSYMBOL_EQ = 27,              /* EQ  */
    YYSYMBOL_NEQ = 28,             /* NEQ  */
    YYSYMBOL_GT = 29,              /* GT  */
    YYSYMBOL_ASSIGN = 30,          /* ASSIGN  */
    YYSYMBOL_LOWER_THAN_ELSE = 31, /* LOWER_THAN_ELSE  */
    YYSYMBOL_ELSE = 32,            /* ELSE  */
    YYSYMBOL_YYACCEPT = 33,        /* $accept  */
    YYSYMBOL_programa = 34,        /* programa  */
    YYSYMBOL_decl_lista = 35,      /* decl_lista  */
    YYSYMBOL_decl = 36,            /* decl  */
    YYSYMBOL_var_decl = 37,        /* var_decl  */
    YYSYMBOL_38_1 = 38,            /* $@1  */
    YYSYMBOL_39_2 = 39,            /* $@2  */
    YYSYMBOL_40_3 = 40,            /* $@3  */
    YYSYMBOL_tipo = 41,            /* tipo  */
    YYSYMBOL_fun_decl = 42,        /* fun_decl  */
    YYSYMBOL_43_4 = 43,            /* $@4  */
    YYSYMBOL_params = 44,          /* params  */
    YYSYMBOL_params_seq = 45,      /* params_seq  */
    YYSYMBOL_param = 46,           /* param  */
    YYSYMBOL_47_5 = 47,            /* $@5  */
    YYSYMBOL_comp_decl = 48,       /* comp_decl  */
    YYSYMBOL_local_decl = 49,      /* local_decl  */
    YYSYMBOL_stmt_lista = 50,      /* stmt_lista  */
    YYSYMBOL_stmt = 51,            /* stmt  */
    YYSYMBOL_expr_decl = 52,       /* expr_decl  */
    YYSYMBOL_selc_decl = 53,       /* selc_decl  */
    YYSYMBOL_iter_decl = 54,       /* iter_decl  */
    YYSYMBOL_retr_decl = 55,       /* retr_decl  */
    YYSYMBOL_exp = 56,             /* exp  */
    YYSYMBOL_var = 57,             /* var  */
    YYSYMBOL_58_6 = 58,            /* $@6  */
    YYSYMBOL_smp_exp = 59,         /* smp_exp  */
    YYSYMBOL_rel = 60,             /* rel  */
    YYSYMBOL_soma_exp = 61,        /* soma_exp  */
    YYSYMBOL_soma = 62,            /* soma  */
    YYSYMBOL_termo = 63,           /* termo  */
    YYSYMBOL_mult = 64,            /* mult  */
    YYSYMBOL_fator = 65,           /* fator  */
    YYSYMBOL_ativacao = 66,        /* ativacao  */
    YYSYMBOL_67_7 = 67,            /* $@7  */
    YYSYMBOL_args = 68,            /* args  */
    YYSYMBOL_arg_lista = 69        /* arg_lista  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;

#ifdef short
    #undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
    #include <limits.h> /* INFRINGES ON USER NAME SPACE */
    #if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
        #include <stdint.h> /* INFRINGES ON USER NAME SPACE */
        #define YY_STDINT_H
    #endif
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
    #undef UINT_LEAST8_MAX
    #undef UINT_LEAST16_MAX
    #define UINT_LEAST8_MAX 255
    #define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H &&                  \
       UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H &&                 \
       UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
    #if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
        #define YYPTRDIFF_T __PTRDIFF_TYPE__
        #define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
    #elif defined PTRDIFF_MAX
        #ifndef ptrdiff_t
            #include <stddef.h> /* INFRINGES ON USER NAME SPACE */
        #endif
        #define YYPTRDIFF_T ptrdiff_t
        #define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
    #else
        #define YYPTRDIFF_T long
        #define YYPTRDIFF_MAXIMUM LONG_MAX
    #endif
#endif

#ifndef YYSIZE_T
    #ifdef __SIZE_TYPE__
        #define YYSIZE_T __SIZE_TYPE__
    #elif defined size_t
        #define YYSIZE_T size_t
    #elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
        #include <stddef.h> /* INFRINGES ON USER NAME SPACE */
        #define YYSIZE_T size_t
    #else
        #define YYSIZE_T unsigned
    #endif
#endif

#define YYSIZE_MAXIMUM                                                         \
    YY_CAST(YYPTRDIFF_T, (YYPTRDIFF_MAXIMUM < YY_CAST(YYSIZE_T, -1)            \
                              ? YYPTRDIFF_MAXIMUM                              \
                              : YY_CAST(YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST(YYPTRDIFF_T, sizeof(X))

/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
    #if defined YYENABLE_NLS && YYENABLE_NLS
        #if ENABLE_NLS
            #include <libintl.h> /* INFRINGES ON USER NAME SPACE */
            #define YY_(Msgid) dgettext("bison-runtime", Msgid)
        #endif
    #endif
    #ifndef YY_
        #define YY_(Msgid) Msgid
    #endif
#endif

#ifndef YY_ATTRIBUTE_PURE
    #if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
        #define YY_ATTRIBUTE_PURE __attribute__((__pure__))
    #else
        #define YY_ATTRIBUTE_PURE
    #endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
    #if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
        #define YY_ATTRIBUTE_UNUSED __attribute__((__unused__))
    #else
        #define YY_ATTRIBUTE_UNUSED
    #endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if !defined lint || defined __GNUC__
    #define YY_USE(E) ((void)(E))
#else
    #define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && !defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
    #if __GNUC__ * 100 + __GNUC_MINOR__ < 407
        #define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
            _Pragma("GCC diagnostic push")                                     \
                _Pragma("GCC diagnostic ignored \"-Wuninitialized\"")
    #else
        #define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
            _Pragma("GCC diagnostic push")                                     \
                _Pragma("GCC diagnostic ignored \"-Wuninitialized\"") _Pragma( \
                    "GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
    #endif
    #define YY_IGNORE_MAYBE_UNINITIALIZED_END _Pragma("GCC diagnostic pop")
#else
    #define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
    #define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
    #define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
    #define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && !defined __ICC && 6 <= __GNUC__
    #define YY_IGNORE_USELESS_CAST_BEGIN                                       \
        _Pragma("GCC diagnostic push")                                         \
            _Pragma("GCC diagnostic ignored \"-Wuseless-cast\"")
    #define YY_IGNORE_USELESS_CAST_END _Pragma("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
    #define YY_IGNORE_USELESS_CAST_BEGIN
    #define YY_IGNORE_USELESS_CAST_END
#endif

#define YY_ASSERT(E) ((void)(0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

    #ifdef YYSTACK_USE_ALLOCA
        #if YYSTACK_USE_ALLOCA
            #ifdef __GNUC__
                #define YYSTACK_ALLOC __builtin_alloca
            #elif defined __BUILTIN_VA_ARG_INCR
                #include <alloca.h> /* INFRINGES ON USER NAME SPACE */
            #elif defined _AIX
                #define YYSTACK_ALLOC __alloca
            #elif defined _MSC_VER
                #include <malloc.h> /* INFRINGES ON USER NAME SPACE */
                #define alloca _alloca
            #else
                #define YYSTACK_ALLOC alloca
                #if !defined _ALLOCA_H && !defined EXIT_SUCCESS
                    #include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
                /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
                    #ifndef EXIT_SUCCESS
                        #define EXIT_SUCCESS 0
                    #endif
                #endif
            #endif
        #endif
    #endif

    #ifdef YYSTACK_ALLOC
    /* Pacify GCC's 'empty if-body' warning.  */
        #define YYSTACK_FREE(Ptr)                                              \
            do { /* empty */                                                   \
                ;                                                              \
            } while (0)
        #ifndef YYSTACK_ALLOC_MAXIMUM
        /* The OS might guarantee only one guard page at the bottom of the
           stack, and a page size can be as small as 4096 bytes.  So we cannot
           safely invoke alloca (N) if N exceeds 4096.  Use a slightly smaller
           number to allow for a few compiler-allocated temporary stack slots.
         */
            #define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
        #endif
    #else
        #define YYSTACK_ALLOC YYMALLOC
        #define YYSTACK_FREE YYFREE
        #ifndef YYSTACK_ALLOC_MAXIMUM
            #define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
        #endif
        #if (defined __cplusplus && !defined EXIT_SUCCESS &&                   \
             !((defined YYMALLOC || defined malloc) &&                         \
               (defined YYFREE || defined free)))
            #include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
            #ifndef EXIT_SUCCESS
                #define EXIT_SUCCESS 0
            #endif
        #endif
        #ifndef YYMALLOC
            #define YYMALLOC malloc
            #if !defined malloc && !defined EXIT_SUCCESS
void *malloc(YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
            #endif
        #endif
        #ifndef YYFREE
            #define YYFREE free
            #if !defined free && !defined EXIT_SUCCESS
void free(void *);      /* INFRINGES ON USER NAME SPACE */
            #endif
        #endif
    #endif
#endif /* !defined yyoverflow */

#if (!defined yyoverflow &&                                                    \
     (!defined __cplusplus ||                                                  \
      (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc {
    yy_state_t yyss_alloc;
    YYSTYPE yyvs_alloc;
};

    /* The size of the maximum gap between one aligned stack and the next.  */
    #define YYSTACK_GAP_MAXIMUM (YYSIZEOF(union yyalloc) - 1)

    /* The size of an array large to enough to hold all stacks, each with
       N elements.  */
    #define YYSTACK_BYTES(N)                                                   \
        ((N) * (YYSIZEOF(yy_state_t) + YYSIZEOF(YYSTYPE)) + YYSTACK_GAP_MAXIMUM)

    #define YYCOPY_NEEDED 1

    /* Relocate STACK from its old location to the new one.  The
       local variables YYSIZE and YYSTACKSIZE give the old and new number of
       elements in the stack, and YYPTR gives the new location of the
       stack.  Advance YYPTR to a properly aligned location for the next
       stack.  */
    #define YYSTACK_RELOCATE(Stack_alloc, Stack)                               \
        do {                                                                   \
            YYPTRDIFF_T yynewbytes;                                            \
            YYCOPY(&yyptr->Stack_alloc, Stack, yysize);                        \
            Stack = &yyptr->Stack_alloc;                                       \
            yynewbytes = yystacksize * YYSIZEOF(*Stack) + YYSTACK_GAP_MAXIMUM; \
            yyptr += yynewbytes / YYSIZEOF(*yyptr);                            \
        } while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
    /* Copy COUNT objects from SRC to DST.  The source and destination do
       not overlap.  */
    #ifndef YYCOPY
        #if defined __GNUC__ && 1 < __GNUC__
            #define YYCOPY(Dst, Src, Count)                                    \
                __builtin_memcpy(Dst, Src,                                     \
                                 YY_CAST(YYSIZE_T, (Count)) * sizeof(*(Src)))
        #else
            #define YYCOPY(Dst, Src, Count)                                    \
                do {                                                           \
                    YYPTRDIFF_T yyi;                                           \
                    for (yyi = 0; yyi < (Count); yyi++)                        \
                        (Dst)[yyi] = (Src)[yyi];                               \
                } while (0)
        #endif
    #endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL 9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST 111

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS 33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS 37
/* YYNRULES -- Number of rules.  */
#define YYNRULES 71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES 110

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK 287

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                       \
    (0 <= (YYX) && (YYX) <= YYMAXUTOK                                          \
         ? YY_CAST(yysymbol_kind_t, yytranslate[YYX])                          \
         : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] = {
    0,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
    2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
    2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
    2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
    2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
    2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
    2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
    2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
    2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
    2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
    2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
    2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
    2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
    2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
    2,  2,  2,  2,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14,
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] = {
    0,   41,  41,  45,  56,  60,  61,  66,  65,  82,  87,  81,  111, 115, 123,
    122, 143, 144, 148, 160, 164, 172, 171, 187, 191, 205, 216, 220, 231, 235,
    236, 237, 238, 239, 243, 244, 248, 254, 264, 273, 277, 285, 291, 295, 301,
    300, 318, 324, 328, 329, 330, 331, 332, 333, 337, 343, 347, 348, 352, 358,
    362, 363, 367, 368, 369, 370, 379, 378, 396, 397, 401, 413};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST(yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name(yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] = {"\"end of file\"",
                                      "error",
                                      "\"invalid token\"",
                                      "ENDFILE",
                                      "ERROR",
                                      "IF",
                                      "WHILE",
                                      "INT",
                                      "RETURN",
                                      "VOID",
                                      "ID",
                                      "NUM",
                                      "SEMI",
                                      "COMMA",
                                      "LPAREN",
                                      "RPAREN",
                                      "LBRACK",
                                      "RBRACK",
                                      "LBRACE",
                                      "RBRACE",
                                      "PLUS",
                                      "MINUS",
                                      "TIMES",
                                      "OVER",
                                      "LT",
                                      "LTEQ",
                                      "GTEQ",
                                      "EQ",
                                      "NEQ",
                                      "GT",
                                      "ASSIGN",
                                      "LOWER_THAN_ELSE",
                                      "ELSE",
                                      "$accept",
                                      "programa",
                                      "decl_lista",
                                      "decl",
                                      "var_decl",
                                      "$@1",
                                      "$@2",
                                      "$@3",
                                      "tipo",
                                      "fun_decl",
                                      "$@4",
                                      "params",
                                      "params_seq",
                                      "param",
                                      "$@5",
                                      "comp_decl",
                                      "local_decl",
                                      "stmt_lista",
                                      "stmt",
                                      "expr_decl",
                                      "selc_decl",
                                      "iter_decl",
                                      "retr_decl",
                                      "exp",
                                      "var",
                                      "$@6",
                                      "smp_exp",
                                      "rel",
                                      "soma_exp",
                                      "soma",
                                      "termo",
                                      "mult",
                                      "fator",
                                      "ativacao",
                                      "$@7",
                                      "args",
                                      "arg_lista",
                                      YY_NULLPTR};

static const char *yysymbol_name(yysymbol_kind_t yysymbol) {
    return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-91)

#define yypact_value_is_default(Yyn) ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-67)

#define yytable_value_is_error(Yyn) 0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] = {
    -6,  -91, -91, 5,   -6,  -91, -91, -2,  -91, -91, -91, 50,  -1,  8,
    26,  -91, 25,  28,  -91, -91, 40,  60,  56,  61,  -91, 58,  62,  59,
    32,  64,  63,  -91, -91, -91, -91, 65,  -6,  -91, -91, 70,  4,   67,
    71,  72,  42,  51,  -91, -91, 47,  -91, -91, -91, -91, -91, -91, -91,
    69,  54,  -91, 22,  46,  -91, -91, 47,  47,  -91, 75,  73,  74,  76,
    -91, 47,  -91, -91, -91, -91, -91, -91, -91, -91, 47,  47,  -91, -91,
    47,  77,  78,  -91, 47,  47,  -91, -91, -91, 52,  46,  -91, 20,  20,
    79,  -91, 80,  81,  66,  -91, -91, -91, 47,  20,  -91, -91};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] = {
    0,  12, 13, 0,  2,  4,  5,  0,  6,  1,  3,  7,  0,  0,  0,  8,  0,  0,  10,
    23, 13, 0,  0,  16, 19, 0,  20, 0,  0,  0,  0,  26, 15, 18, 11, 0,  28, 22,
    25, 0,  0,  7,  0,  0,  0,  43, 65, 35, 0,  24, 30, 27, 29, 31, 32, 33, 0,
    63, 42, 47, 55, 59, 64, 0,  0,  39, 0,  0,  0,  0,  34, 0,  56, 57, 49, 48,
    50, 52, 53, 51, 0,  0,  60, 61, 0,  0,  0,  40, 0,  69, 62, 41, 63, 46, 54,
    58, 0,  0,  0,  71, 0,  68, 36, 38, 45, 67, 0,  0,  70, 37};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] = {
    -91, -91, -91, 86,  68,  -91, -91, -91, -15, -91, -91, -91, -91,
    82,  -91, 84,  -91, -91, -90, -91, -91, -91, -91, -44, -21, -91,
    -91, -91, 17,  -91, 18,  -91, 16,  -91, -91, -91, -91};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] = {
    0,  3,  4,  5,  6,  12, 13, 25, 7,  8,  14, 22, 23, 24, 30, 50, 36,  40, 51,
    52, 53, 54, 55, 56, 57, 67, 58, 80, 59, 81, 60, 84, 61, 62, 68, 100, 101};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] = {
    66,  1,   21,  2,   69, 9,  102, 103, 11, 42, 43, 15, 44, 21, 45,  46,
    47,  109, 48,  85,  86, 39, 31,  49,  16, 42, 43, 91, 44, 19, 45,  46,
    47,  19,  48,  1,   18, 20, 31,  1,   17, 2,  72, 73, 98, 99, 74,  75,
    76,  77,  78,  79,  45, 46, 65,  -17, 48, 45, 46, 92, 92, 48, 108, 92,
    -14, -66, -9,  -44, 82, 83, 26,  27,  72, 73, 28, 29, 34, 31, -21, 35,
    41,  70,  37,  -9,  71, 63, 64,  87,  89, 88, 10, 90, 96, 97, 106, 105,
    104, 93,  107, 94,  95, 0,  0,   0,   38, 0,  0,  0,  0,  0,  33,  32};

static const yytype_int8 yycheck[] = {
    44, 7,   17, 9,  48, 0,  96, 97, 10, 5,  6,  12, 8,  28, 10,  11,
    12, 107, 14, 63, 64, 36, 18, 19, 16, 5,  6,  71, 8,  1,  10,  11,
    12, 1,   14, 7,  11, 9,  18, 7,  14, 9,  20, 21, 88, 89, 24,  25,
    26, 27,  28, 29, 10, 11, 12, 15, 14, 10, 11, 80, 81, 14, 106, 84,
    14, 14,  16, 16, 22, 23, 10, 15, 20, 21, 13, 17, 12, 18, 16,  16,
    10, 12,  17, 16, 30, 14, 14, 12, 14, 16, 4,  15, 15, 15, 13,  15,
    17, 80,  32, 81, 84, -1, -1, -1, 36, -1, -1, -1, -1, -1, 28,  27};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] = {
    0,  7,  9,  34, 35, 36, 37, 41, 42, 0,  36, 10, 38, 39, 43, 12, 16, 14, 11,
    1,  9,  41, 44, 45, 46, 40, 10, 15, 13, 17, 47, 18, 48, 46, 12, 16, 49, 17,
    37, 41, 50, 10, 5,  6,  8,  10, 11, 12, 14, 19, 48, 51, 52, 53, 54, 55, 56,
    57, 59, 61, 63, 65, 66, 14, 14, 12, 56, 58, 67, 56, 12, 30, 20, 21, 24, 25,
    26, 27, 28, 29, 60, 62, 22, 23, 64, 56, 56, 12, 16, 14, 15, 56, 57, 61, 63,
    65, 15, 15, 56, 56, 68, 69, 51, 51, 17, 15, 13, 32, 56, 51};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] = {
    0,  33, 34, 35, 35, 36, 36, 38, 37, 39, 40, 37, 41, 41, 43, 42, 44, 44,
    45, 45, 46, 47, 46, 46, 48, 49, 49, 50, 50, 51, 51, 51, 51, 51, 52, 52,
    53, 53, 54, 55, 55, 56, 56, 57, 58, 57, 59, 59, 60, 60, 60, 60, 60, 60,
    61, 61, 62, 62, 63, 63, 64, 64, 65, 65, 65, 65, 67, 66, 68, 68, 69, 69};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
 */
static const yytype_int8 yyr2[] = {
    0, 2, 1, 2, 1, 1, 1, 0, 4, 0, 0, 8, 1, 1, 0, 7, 1, 1, 3, 1, 2, 0, 5, 1,
    4, 2, 0, 2, 0, 1, 1, 1, 1, 1, 2, 1, 5, 7, 5, 2, 3, 3, 1, 1, 0, 5, 3, 1,
    1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1, 0, 5, 1, 0, 3, 1};

enum { YYENOMEM = -2 };

#define yyerrok (yyerrstatus = 0)
#define yyclearin (yychar = YYEMPTY)

#define YYACCEPT goto yyacceptlab
#define YYABORT goto yyabortlab
#define YYERROR goto yyerrorlab
#define YYNOMEM goto yyexhaustedlab

#define YYRECOVERING() (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                                 \
    do                                                                         \
        if (yychar == YYEMPTY) {                                               \
            yychar = (Token);                                                  \
            yylval = (Value);                                                  \
            YYPOPSTACK(yylen);                                                 \
            yystate = *yyssp;                                                  \
            goto yybackup;                                                     \
        } else {                                                               \
            yyerror(YY_("syntax error: cannot back up"));                      \
            YYERROR;                                                           \
        }                                                                      \
    while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* Enable debugging if requested.  */
#if YYDEBUG

    #ifndef YYFPRINTF
        #include <stdio.h> /* INFRINGES ON USER NAME SPACE */
        #define YYFPRINTF fprintf
    #endif

    #define YYDPRINTF(Args)                                                    \
        do {                                                                   \
            if (yydebug)                                                       \
                YYFPRINTF Args;                                                \
        } while (0)

    #define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                      \
        do {                                                                   \
            if (yydebug) {                                                     \
                YYFPRINTF(stderr, "%s ", Title);                               \
                yy_symbol_print(stderr, Kind, Value);                          \
                YYFPRINTF(stderr, "\n");                                       \
            }                                                                  \
        } while (0)

/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void yy_symbol_value_print(FILE *yyo, yysymbol_kind_t yykind,
                                  YYSTYPE const *const yyvaluep) {
    FILE *yyoutput = yyo;
    YY_USE(yyoutput);
    if (!yyvaluep)
        return;
    YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
    YY_USE(yykind);
    YY_IGNORE_MAYBE_UNINITIALIZED_END
}

/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void yy_symbol_print(FILE *yyo, yysymbol_kind_t yykind,
                            YYSTYPE const *const yyvaluep) {
    YYFPRINTF(yyo, "%s %s (", yykind < YYNTOKENS ? "token" : "nterm",
              yysymbol_name(yykind));

    yy_symbol_value_print(yyo, yykind, yyvaluep);
    YYFPRINTF(yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void yy_stack_print(yy_state_t *yybottom, yy_state_t *yytop) {
    YYFPRINTF(stderr, "Stack now");
    for (; yybottom <= yytop; yybottom++) {
        int yybot = *yybottom;
        YYFPRINTF(stderr, " %d", yybot);
    }
    YYFPRINTF(stderr, "\n");
}

    #define YY_STACK_PRINT(Bottom, Top)                                        \
        do {                                                                   \
            if (yydebug)                                                       \
                yy_stack_print((Bottom), (Top));                               \
        } while (0)

/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void yy_reduce_print(yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule) {
    int yylno = yyrline[yyrule];
    int yynrhs = yyr2[yyrule];
    int yyi;
    YYFPRINTF(stderr, "Reducing stack by rule %d (line %d):\n", yyrule - 1,
              yylno);
    /* The symbols being reduced.  */
    for (yyi = 0; yyi < yynrhs; yyi++) {
        YYFPRINTF(stderr, "   $%d = ", yyi + 1);
        yy_symbol_print(stderr, YY_ACCESSING_SYMBOL(+yyssp[yyi + 1 - yynrhs]),
                        &yyvsp[(yyi + 1) - (yynrhs)]);
        YYFPRINTF(stderr, "\n");
    }
}

    #define YY_REDUCE_PRINT(Rule)                                              \
        do {                                                                   \
            if (yydebug)                                                       \
                yy_reduce_print(yyssp, yyvsp, Rule);                           \
        } while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
    #define YYDPRINTF(Args) ((void)0)
    #define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
    #define YY_STACK_PRINT(Bottom, Top)
    #define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
    #define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
    #define YYMAXDEPTH 10000
#endif

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void yydestruct(const char *yymsg, yysymbol_kind_t yykind,
                       YYSTYPE *yyvaluep) {
    YY_USE(yyvaluep);
    if (!yymsg)
        yymsg = "Deleting";
    YY_SYMBOL_PRINT(yymsg, yykind, yyvaluep, yylocationp);

    YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
    YY_USE(yykind);
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

int yyparse(void) {
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

#define YYPOPSTACK(N) (yyvsp -= (N), yyssp -= (N))

    /* The number of symbols on the RHS of the reduced rule.
       Keep to zero when no symbol should be popped.  */
    int yylen = 0;

    YYDPRINTF((stderr, "Starting parse\n"));

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
    YYDPRINTF((stderr, "Entering state %d\n", yystate));
    YY_ASSERT(0 <= yystate && yystate < YYNSTATES);
    YY_IGNORE_USELESS_CAST_BEGIN
    *yyssp = YY_CAST(yy_state_t, yystate);
    YY_IGNORE_USELESS_CAST_END
    YY_STACK_PRINT(yyss, yyssp);

    if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
        YYNOMEM;
#else
    {
        /* Get the current used size of the three stacks, in elements.  */
        YYPTRDIFF_T yysize = yyssp - yyss + 1;

    #if defined yyoverflow
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
            yyoverflow(YY_("memory exhausted"), &yyss1,
                       yysize * YYSIZEOF(*yyssp), &yyvs1,
                       yysize * YYSIZEOF(*yyvsp), &yystacksize);
            yyss = yyss1;
            yyvs = yyvs1;
        }
    #else /* defined YYSTACK_RELOCATE */
        /* Extend the stack our own way.  */
        if (YYMAXDEPTH <= yystacksize)
            YYNOMEM;
        yystacksize *= 2;
        if (YYMAXDEPTH < yystacksize)
            yystacksize = YYMAXDEPTH;

        {
            yy_state_t *yyss1 = yyss;
            union yyalloc *yyptr = YY_CAST(
                union yyalloc *,
                YYSTACK_ALLOC(YY_CAST(YYSIZE_T, YYSTACK_BYTES(yystacksize))));
            if (!yyptr)
                YYNOMEM;
            YYSTACK_RELOCATE(yyss_alloc, yyss);
            YYSTACK_RELOCATE(yyvs_alloc, yyvs);
        #undef YYSTACK_RELOCATE
            if (yyss1 != yyssa)
                YYSTACK_FREE(yyss1);
        }
    #endif

        yyssp = yyss + yysize - 1;
        yyvsp = yyvs + yysize - 1;

        YY_IGNORE_USELESS_CAST_BEGIN
        YYDPRINTF((stderr, "Stack size increased to %ld\n",
                   YY_CAST(long, yystacksize)));
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
    if (yypact_value_is_default(yyn))
        goto yydefault;

    /* Not known => get a lookahead token if don't already have one.  */

    /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
    if (yychar == YYEMPTY) {
        YYDPRINTF((stderr, "Reading a token\n"));
        yychar = yylex();
    }

    if (yychar <= YYEOF) {
        yychar = YYEOF;
        yytoken = YYSYMBOL_YYEOF;
        YYDPRINTF((stderr, "Now at end of input.\n"));
    } else if (yychar == YYerror) {
        /* The scanner already issued an error message, process directly
           to error recovery.  But do not keep the error token as
           lookahead, it is too special and may lead us to an endless
           loop in error recovery. */
        yychar = YYUNDEF;
        yytoken = YYSYMBOL_YYerror;
        goto yyerrlab1;
    } else {
        yytoken = YYTRANSLATE(yychar);
        YY_SYMBOL_PRINT("Next token is", yytoken, &yylval, &yylloc);
    }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
        goto yydefault;
    yyn = yytable[yyn];
    if (yyn <= 0) {
        if (yytable_value_is_error(yyn))
            goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
    }

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus)
        yyerrstatus--;

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT("Shifting", yytoken, &yylval, &yylloc);
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
    yyval = yyvsp[1 - yylen];

    YY_REDUCE_PRINT(yyn);
    switch (yyn) {
    case 2: /* programa: decl_lista  */
#line 41 "src/cminus.y"
    {
        savedTree = yyvsp[0];
    }
#line 1222 "src/cminus.tab.c"
    break;

    case 3: /* decl_lista: decl_lista decl  */
#line 46 "src/cminus.y"
    {
        YYSTYPE t = yyvsp[-1];
        if (t != NULL) {
            while (t->sibling != NULL)
                t = t->sibling;
            t->sibling = yyvsp[0];
            yyval = yyvsp[-1];
        } else
            yyval = yyvsp[0];
    }
#line 1237 "src/cminus.tab.c"
    break;

    case 4: /* decl_lista: decl  */
#line 56 "src/cminus.y"
    {
        yyval = yyvsp[0];
    }
#line 1243 "src/cminus.tab.c"
    break;

    case 5: /* decl: var_decl  */
#line 60 "src/cminus.y"
    {
        yyval = yyvsp[0];
    }
#line 1249 "src/cminus.tab.c"
    break;

    case 6: /* decl: fun_decl  */
#line 61 "src/cminus.y"
    {
        yyval = yyvsp[0];
    }
#line 1255 "src/cminus.tab.c"
    break;

    case 7: /* $@1: %empty  */
#line 66 "src/cminus.y"
    {
        savedName = push(savedName, copyString(identifierString));
        savedLine = push(savedLine, (void *)lineno);
    }
#line 1264 "src/cminus.tab.c"
    break;

    case 8: /* var_decl: tipo ID $@1 SEMI  */
#line 71 "src/cminus.y"
    {
        yyval = yyvsp[-3];
        yyval->kind.decl = VarK;
        yyval->child[0] = newExpNode(IdK);
        yyval->child[0]->attr.name = front(savedName);
        yyval->child[0]->lineno = (int)front(savedLine);

        savedName = pop(savedName);
        savedLine = pop(savedLine);
    }
#line 1279 "src/cminus.tab.c"
    break;

    case 9: /* $@2: %empty  */
#line 82 "src/cminus.y"
    {
        savedName = push(savedName, copyString(identifierString));
        savedLine = push(savedLine, (void *)lineno);
    }
#line 1288 "src/cminus.tab.c"
    break;

    case 10: /* $@3: %empty  */
#line 87 "src/cminus.y"
    {
        savedName = push(savedName, copyString(numberString));
        savedLine = push(savedLine, (void *)lineno);
    }
#line 1297 "src/cminus.tab.c"
    break;

    case 11: /* var_decl: tipo ID $@2 LBRACK NUM $@3 RBRACK SEMI  */
#line 92 "src/cminus.y"
    {
        yyval = yyvsp[-7];
        yyval->kind.decl = VecK;

        yyval->child[1] = newExpNode(ConstK);
        yyval->child[1]->attr.val = atoi(front(savedName));
        yyval->child[1]->lineno = (int)front(savedLine);
        savedName = pop(savedName);
        savedLine = pop(savedLine);

        yyval->child[0] = newExpNode(IdK);
        yyval->child[0]->attr.name = front(savedName);
        yyval->child[0]->lineno = (int)front(savedLine);
        savedName = pop(savedName);
        savedLine = pop(savedLine);
    }
#line 1318 "src/cminus.tab.c"
    break;

    case 12: /* tipo: INT  */
#line 112 "src/cminus.y"
    {
        yyval = newDeclNode(Integer);
    }
#line 1326 "src/cminus.tab.c"
    break;

    case 13: /* tipo: VOID  */
#line 116 "src/cminus.y"
    {
        yyval = newDeclNode(Void);
    }
#line 1334 "src/cminus.tab.c"
    break;

    case 14: /* $@4: %empty  */
#line 123 "src/cminus.y"
    {
        savedName = push(savedName, copyString(identifierString));
        savedLine = push(savedLine, (void *)lineno);
    }
#line 1343 "src/cminus.tab.c"
    break;

    case 15: /* fun_decl: tipo ID $@4 LPAREN params RPAREN comp_decl  */
#line 128 "src/cminus.y"
    {
        yyval = yyvsp[-6];
        yyval->kind.decl = FunK;
        yyval->child[0] = newExpNode(IdK);
        yyval->child[0]->attr.name = front(savedName);
        yyval->child[0]->lineno = (int)front(savedLine);
        yyval->child[0]->child[0] = yyvsp[-2];
        yyval->child[0]->child[1] = yyvsp[0];

        savedName = pop(savedName);
        savedLine = pop(savedLine);
    }
#line 1360 "src/cminus.tab.c"
    break;

    case 16: /* params: params_seq  */
#line 143 "src/cminus.y"
    {
        yyval = yyvsp[0];
    }
#line 1366 "src/cminus.tab.c"
    break;

    case 17: /* params: VOID  */
#line 144 "src/cminus.y"
    {
        yyval = NULL;
    }
#line 1372 "src/cminus.tab.c"
    break;

    case 18: /* params_seq: params_seq COMMA param  */
#line 149 "src/cminus.y"
    {
        YYSTYPE t = yyvsp[-2];
        if (t != NULL) {
            while (t->sibling != NULL)
                t = t->sibling;
            t->sibling = yyvsp[0];
            yyval = yyvsp[-2];
        } else {
            yyval = yyvsp[0];
        }
    }
#line 1388 "src/cminus.tab.c"
    break;

    case 19: /* params_seq: param  */
#line 160 "src/cminus.y"
    {
        yyval = yyvsp[0];
    }
#line 1394 "src/cminus.tab.c"
    break;

    case 20: /* param: tipo ID  */
#line 165 "src/cminus.y"
    {
        yyval = yyvsp[-1];
        yyval->kind.decl = VarK;
        yyval->child[0] = newExpNode(IdK);
        yyval->child[0]->attr.name = copyString(identifierString);
    }
#line 1405 "src/cminus.tab.c"
    break;

    case 21: /* $@5: %empty  */
#line 172 "src/cminus.y"
    {
        savedName = push(savedName, copyString(identifierString));
        savedLine = push(savedLine, (void *)lineno);
    }
#line 1414 "src/cminus.tab.c"
    break;

    case 22: /* param: tipo ID $@5 LBRACK RBRACK  */
#line 177 "src/cminus.y"
    {
        yyval = yyvsp[-4];
        yyval->kind.decl = VecK;
        yyval->child[0] = newExpNode(IdK);
        yyval->child[0]->attr.name = front(savedName);
        yyval->child[0]->lineno = (int)front(savedLine);

        savedName = pop(savedName);
        savedLine = pop(savedLine);
    }
#line 1429 "src/cminus.tab.c"
    break;

    case 23: /* param: error  */
#line 187 "src/cminus.y"
    {
        yyval = NULL;
    }
#line 1435 "src/cminus.tab.c"
    break;

    case 24: /* comp_decl: LBRACE local_decl stmt_lista RBRACE  */
#line 192 "src/cminus.y"
    {
        YYSTYPE t = yyvsp[-2];
        if (yyvsp[-2] != NULL) {
            while (t->sibling != NULL)
                t = t->sibling;
            t->sibling = yyvsp[-1];
            yyval = yyvsp[-2];
        } else
            yyval = yyvsp[-1];
    }
#line 1450 "src/cminus.tab.c"
    break;

    case 25: /* local_decl: local_decl var_decl  */
#line 206 "src/cminus.y"
    {
        YYSTYPE t = yyvsp[-1];
        if (t != NULL) {
            while (t->sibling != NULL)
                t = t->sibling;
            t->sibling = yyvsp[0];
            yyval = yyvsp[-1];
        } else
            yyval = yyvsp[0];
    }
#line 1465 "src/cminus.tab.c"
    break;

    case 26: /* local_decl: %empty  */
#line 216 "src/cminus.y"
    {
        yyval = NULL;
    }
#line 1471 "src/cminus.tab.c"
    break;

    case 27: /* stmt_lista: stmt_lista stmt  */
#line 221 "src/cminus.y"
    {
        YYSTYPE t = yyvsp[-1];
        if (t != NULL) {
            while (t->sibling != NULL)
                t = t->sibling;
            t->sibling = yyvsp[0];
            yyval = yyvsp[-1];
        } else
            yyval = yyvsp[0];
    }
#line 1486 "src/cminus.tab.c"
    break;

    case 28: /* stmt_lista: %empty  */
#line 231 "src/cminus.y"
    {
        yyval = NULL;
    }
#line 1492 "src/cminus.tab.c"
    break;

    case 29: /* stmt: expr_decl  */
#line 235 "src/cminus.y"
    {
        yyval = yyvsp[0];
    }
#line 1498 "src/cminus.tab.c"
    break;

    case 30: /* stmt: comp_decl  */
#line 236 "src/cminus.y"
    {
        yyval = yyvsp[0];
    }
#line 1504 "src/cminus.tab.c"
    break;

    case 31: /* stmt: selc_decl  */
#line 237 "src/cminus.y"
    {
        yyval = yyvsp[0];
    }
#line 1510 "src/cminus.tab.c"
    break;

    case 32: /* stmt: iter_decl  */
#line 238 "src/cminus.y"
    {
        yyval = yyvsp[0];
    }
#line 1516 "src/cminus.tab.c"
    break;

    case 33: /* stmt: retr_decl  */
#line 239 "src/cminus.y"
    {
        yyval = yyvsp[0];
    }
#line 1522 "src/cminus.tab.c"
    break;

    case 34: /* expr_decl: exp SEMI  */
#line 243 "src/cminus.y"
    {
        yyval = yyvsp[-1];
    }
#line 1528 "src/cminus.tab.c"
    break;

    case 35: /* expr_decl: SEMI  */
#line 244 "src/cminus.y"
    {
        yyval = NULL;
    }
#line 1534 "src/cminus.tab.c"
    break;

    case 36: /* selc_decl: IF LPAREN exp RPAREN stmt  */
#line 249 "src/cminus.y"
    {
        yyval = newStmtNode(IfK);
        yyval->child[0] = yyvsp[-2];
        yyval->child[1] = yyvsp[0];
    }
#line 1544 "src/cminus.tab.c"
    break;

    case 37: /* selc_decl: IF LPAREN exp RPAREN stmt ELSE stmt  */
#line 255 "src/cminus.y"
    {
        yyval = newStmtNode(IfK);
        yyval->child[0] = yyvsp[-4];
        yyval->child[1] = yyvsp[-2];
        yyval->child[2] = yyvsp[0];
    }
#line 1555 "src/cminus.tab.c"
    break;

    case 38: /* iter_decl: WHILE LPAREN exp RPAREN stmt  */
#line 265 "src/cminus.y"
    {
        yyval = newStmtNode(RepeatK);
        yyval->child[0] = yyvsp[-2];
        yyval->child[1] = yyvsp[0];
    }
#line 1565 "src/cminus.tab.c"
    break;

    case 39: /* retr_decl: RETURN SEMI  */
#line 274 "src/cminus.y"
    {
        yyval = newStmtNode(ReturnK);
    }
#line 1573 "src/cminus.tab.c"
    break;

    case 40: /* retr_decl: RETURN exp SEMI  */
#line 278 "src/cminus.y"
    {
        yyval = newStmtNode(ReturnK);
        yyval->child[0] = yyvsp[-1];
    }
#line 1582 "src/cminus.tab.c"
    break;

    case 41: /* exp: var ASSIGN exp  */
#line 286 "src/cminus.y"
    {
        yyval = newStmtNode(AssignK);
        yyval->child[0] = yyvsp[-2];
        yyval->child[1] = yyvsp[0];
    }
#line 1592 "src/cminus.tab.c"
    break;

    case 42: /* exp: smp_exp  */
#line 291 "src/cminus.y"
    {
        yyval = yyvsp[0];
    }
#line 1598 "src/cminus.tab.c"
    break;

    case 43: /* var: ID  */
#line 296 "src/cminus.y"
    {
        yyval = newExpNode(IdK);
        yyval->attr.name = copyString(identifierString);
    }
#line 1607 "src/cminus.tab.c"
    break;

    case 44: /* $@6: %empty  */
#line 301 "src/cminus.y"
    {
        savedName = push(savedName, copyString(identifierString));
        savedLine = push(savedLine, (void *)lineno);
    }
#line 1616 "src/cminus.tab.c"
    break;

    case 45: /* var: ID $@6 LBRACK exp RBRACK  */
#line 306 "src/cminus.y"
    {
        yyval = newExpNode(IdK);
        yyval->child[0] = yyvsp[-1];
        yyval->attr.name = front(savedName);
        yyval->lineno = (int)front(savedLine);

        savedName = pop(savedName);
        savedLine = pop(savedLine);
    }
#line 1630 "src/cminus.tab.c"
    break;

    case 46: /* smp_exp: soma_exp rel soma_exp  */
#line 319 "src/cminus.y"
    {
        yyval = yyvsp[-1];
        yyval->child[0] = yyvsp[-2];
        yyval->child[1] = yyvsp[0];
    }
#line 1640 "src/cminus.tab.c"
    break;

    case 47: /* smp_exp: soma_exp  */
#line 324 "src/cminus.y"
    {
        yyval = yyvsp[0];
    }
#line 1646 "src/cminus.tab.c"
    break;

    case 48: /* rel: LTEQ  */
#line 328 "src/cminus.y"
    {
        yyval = newExpNode(OpK);
        yyval->attr.op = LTEQ;
    }
#line 1652 "src/cminus.tab.c"
    break;

    case 49: /* rel: LT  */
#line 329 "src/cminus.y"
    {
        yyval = newExpNode(OpK);
        yyval->attr.op = LT;
    }
#line 1658 "src/cminus.tab.c"
    break;

    case 50: /* rel: GTEQ  */
#line 330 "src/cminus.y"
    {
        yyval = newExpNode(OpK);
        yyval->attr.op = GTEQ;
    }
#line 1664 "src/cminus.tab.c"
    break;

    case 51: /* rel: GT  */
#line 331 "src/cminus.y"
    {
        yyval = newExpNode(OpK);
        yyval->attr.op = GT;
    }
#line 1670 "src/cminus.tab.c"
    break;

    case 52: /* rel: EQ  */
#line 332 "src/cminus.y"
    {
        yyval = newExpNode(OpK);
        yyval->attr.op = EQ;
    }
#line 1676 "src/cminus.tab.c"
    break;

    case 53: /* rel: NEQ  */
#line 333 "src/cminus.y"
    {
        yyval = newExpNode(OpK);
        yyval->attr.op = NEQ;
    }
#line 1682 "src/cminus.tab.c"
    break;

    case 54: /* soma_exp: soma_exp soma termo  */
#line 338 "src/cminus.y"
    {
        yyval = yyvsp[-1];
        yyval->child[0] = yyvsp[-2];
        yyval->child[1] = yyvsp[0];
    }
#line 1692 "src/cminus.tab.c"
    break;

    case 55: /* soma_exp: termo  */
#line 343 "src/cminus.y"
    {
        yyval = yyvsp[0];
    }
#line 1698 "src/cminus.tab.c"
    break;

    case 56: /* soma: PLUS  */
#line 347 "src/cminus.y"
    {
        yyval = newExpNode(OpK);
        yyval->attr.op = PLUS;
    }
#line 1704 "src/cminus.tab.c"
    break;

    case 57: /* soma: MINUS  */
#line 348 "src/cminus.y"
    {
        yyval = newExpNode(OpK);
        yyval->attr.op = MINUS;
    }
#line 1710 "src/cminus.tab.c"
    break;

    case 58: /* termo: termo mult fator  */
#line 353 "src/cminus.y"
    {
        yyval = yyvsp[-1];
        yyval->child[0] = yyvsp[-2];
        yyval->child[1] = yyvsp[0];
    }
#line 1720 "src/cminus.tab.c"
    break;

    case 59: /* termo: fator  */
#line 358 "src/cminus.y"
    {
        yyval = yyvsp[0];
    }
#line 1726 "src/cminus.tab.c"
    break;

    case 60: /* mult: TIMES  */
#line 362 "src/cminus.y"
    {
        yyval = newExpNode(OpK);
        yyval->attr.op = TIMES;
    }
#line 1732 "src/cminus.tab.c"
    break;

    case 61: /* mult: OVER  */
#line 363 "src/cminus.y"
    {
        yyval = newExpNode(OpK);
        yyval->attr.op = OVER;
    }
#line 1738 "src/cminus.tab.c"
    break;

    case 62: /* fator: LPAREN exp RPAREN  */
#line 367 "src/cminus.y"
    {
        yyval = yyvsp[-1];
    }
#line 1744 "src/cminus.tab.c"
    break;

    case 63: /* fator: var  */
#line 368 "src/cminus.y"
    {
        yyval = yyvsp[0];
    }
#line 1750 "src/cminus.tab.c"
    break;

    case 64: /* fator: ativacao  */
#line 369 "src/cminus.y"
    {
        yyval = yyvsp[0];
    }
#line 1756 "src/cminus.tab.c"
    break;

    case 65: /* fator: NUM  */
#line 371 "src/cminus.y"
    {
        yyval = newExpNode(ConstK);
        yyval->attr.val = atoi(numberString);
    }
#line 1765 "src/cminus.tab.c"
    break;

    case 66: /* $@7: %empty  */
#line 379 "src/cminus.y"
    {
        savedName = push(savedName, copyString(identifierString));
        savedLine = push(savedLine, (void *)lineno);
    }
#line 1774 "src/cminus.tab.c"
    break;

    case 67: /* ativacao: ID $@7 LPAREN args RPAREN  */
#line 384 "src/cminus.y"
    {
        yyval = newExpNode(IdK);
        yyval->child[0] = yyvsp[-1];
        yyval->attr.name = front(savedName);
        yyval->lineno = (int)front(savedLine);

        savedName = pop(savedName);
        savedLine = pop(savedLine);
    }
#line 1788 "src/cminus.tab.c"
    break;

    case 68: /* args: arg_lista  */
#line 396 "src/cminus.y"
    {
        yyval = yyvsp[0];
    }
#line 1794 "src/cminus.tab.c"
    break;

    case 69: /* args: %empty  */
#line 397 "src/cminus.y"
    {
        yyval = NULL;
    }
#line 1800 "src/cminus.tab.c"
    break;

    case 70: /* arg_lista: arg_lista COMMA exp  */
#line 402 "src/cminus.y"
    {
        YYSTYPE t = yyvsp[-2];
        if (t != NULL) {
            while (t->sibling != NULL)
                t = t->sibling;
            t->sibling = yyvsp[0];
            yyval = yyvsp[-2];
        } else
            yyval = yyvsp[0];

    }
#line 1816 "src/cminus.tab.c"
    break;

    case 71: /* arg_lista: exp  */
#line 413 "src/cminus.y"
    {
        yyval = yyvsp[0];
    }
#line 1822 "src/cminus.tab.c"
    break;

#line 1826 "src/cminus.tab.c"

    default:
        break;
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
    YY_SYMBOL_PRINT("-> $$ =", YY_CAST(yysymbol_kind_t, yyr1[yyn]), &yyval,
                    &yyloc);

    YYPOPSTACK(yylen);
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
    yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE(yychar);
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus) {
        ++yynerrs;
        yyerror(YY_("syntax error"));
    }

    if (yyerrstatus == 3) {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        if (yychar <= YYEOF) {
            /* Return failure if at end of input.  */
            if (yychar == YYEOF)
                YYABORT;
        } else {
            yydestruct("Error: discarding", yytoken, &yylval);
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
    YYPOPSTACK(yylen);
    yylen = 0;
    YY_STACK_PRINT(yyss, yyssp);
    yystate = *yyssp;
    goto yyerrlab1;

/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
    yyerrstatus = 3; /* Each real token shifted decrements this.  */

    /* Pop stack until we find a state that shifts the error token.  */
    for (;;) {
        yyn = yypact[yystate];
        if (!yypact_value_is_default(yyn)) {
            yyn += YYSYMBOL_YYerror;
            if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror) {
                yyn = yytable[yyn];
                if (0 < yyn)
                    break;
            }
        }

        /* Pop the current state because it cannot handle the error token.  */
        if (yyssp == yyss)
            YYABORT;

        yydestruct("Error: popping", YY_ACCESSING_SYMBOL(yystate), yyvsp);
        YYPOPSTACK(1);
        yystate = *yyssp;
        YY_STACK_PRINT(yyss, yyssp);
    }

    YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
    *++yyvsp = yylval;
    YY_IGNORE_MAYBE_UNINITIALIZED_END

    /* Shift the error token.  */
    YY_SYMBOL_PRINT("Shifting", YY_ACCESSING_SYMBOL(yyn), yyvsp, yylsp);

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
    yyerror(YY_("memory exhausted"));
    yyresult = 2;
    goto yyreturnlab;

/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
    if (yychar != YYEMPTY) {
        /* Make sure we have latest lookahead translation.  See comments at
           user semantic actions for why this is necessary.  */
        yytoken = YYTRANSLATE(yychar);
        yydestruct("Cleanup: discarding lookahead", yytoken, &yylval);
    }
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    YYPOPSTACK(yylen);
    YY_STACK_PRINT(yyss, yyssp);
    while (yyssp != yyss) {
        yydestruct("Cleanup: popping", YY_ACCESSING_SYMBOL(+*yyssp), yyvsp);
        YYPOPSTACK(1);
    }
#ifndef yyoverflow
    if (yyss != yyssa)
        YYSTACK_FREE(yyss);
#endif

    return yyresult;
}

#line 416 "src/cminus.y"

int yyerror(char *message) {
    fprintf(listing, "Syntax error at line %d: %s\n", lineno, message);
    fprintf(listing, "Current token: ");
    printToken(yychar, tokenString);
    Error = TRUE;
    return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the C- scanner
 */
static int yylex(void) { return getToken(); }

TreeNode *parse(void) {
    yyparse();
    return savedTree;
}
