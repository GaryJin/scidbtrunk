
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* C++ LALR(1) parser skeleton written by Akim Demaille.  */

#ifndef PARSER_HEADER_H
# define PARSER_HEADER_H

/* "%code requires" blocks.  */

/* Line 35 of lalr1.cc  */
#line 246 "parser/Parser.yy"

#include "query/parser/ParserDetails.h"                  // For parser details



/* Line 35 of lalr1.cc  */
#line 51 "/home/gary/programmer/scidbtrunk/stage/build/src/query/parser/Parser.hpp"


#include <string>
#include <iostream>
#include "stack.hh"


/* Line 35 of lalr1.cc  */
#line 29 "parser/Parser.yy"
namespace scidb { namespace parser {

/* Line 35 of lalr1.cc  */
#line 64 "/home/gary/programmer/scidbtrunk/stage/build/src/query/parser/Parser.hpp"
  class position;
  class location;

/* Line 35 of lalr1.cc  */
#line 29 "parser/Parser.yy"
} } // scidb::parser

/* Line 35 of lalr1.cc  */
#line 73 "/home/gary/programmer/scidbtrunk/stage/build/src/query/parser/Parser.hpp"

#include "location.hh"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)		\
do {							\
  if (N)						\
    {							\
      (Current).begin = (Rhs)[1].begin;			\
      (Current).end   = (Rhs)[N].end;			\
    }							\
  else							\
    {							\
      (Current).begin = (Current).end = (Rhs)[0].end;	\
    }							\
} while (false)
#endif


/* Line 35 of lalr1.cc  */
#line 29 "parser/Parser.yy"
namespace scidb { namespace parser {

/* Line 35 of lalr1.cc  */
#line 120 "/home/gary/programmer/scidbtrunk/stage/build/src/query/parser/Parser.hpp"

  /// A Bison parser.
  class Parser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 35 of lalr1.cc  */
#line 47 "parser/Parser.yy"

    parser::Node*   node;                                // Arena allocated
    parser::real    real;                                // Passed by value
    parser::chars   string;                              // Arena allocated
    parser::chars   keyword;                             // Arena allocated
    parser::boolean boolean;                             // Passed by value
    parser::integer integer;                             // Passed by value
    parser::lexicon lexicon;                             // Passed by value
    size_t          list;                                // Shadow stack size



/* Line 35 of lalr1.cc  */
#line 146 "/home/gary/programmer/scidbtrunk/stage/build/src/query/parser/Parser.hpp"
    };
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;
    /// Tokens.
    struct token
    {
      /* Tokens.  */
   enum yytokentype {
     MIN = 258,
     IN = 259,
     AS = 260,
     OR = 261,
     AND = 262,
     NOT = 263,
     GTEQ = 264,
     LSEQ = 265,
     NEQ = 266,
     BETWEEN = 267,
     MAX = 268,
     AQL_STATEMENT = 269,
     AFL_STATEMENT = 270,
     AFL_EXPRESSION = 271,
     AFL_MODULE = 272,
     LEXICAL_ERROR = 273,
     REAL = 274,
     STRING = 275,
     BOOLEAN = 276,
     INTEGER = 277,
     IDENTIFIER = 278,
     ALL = 279,
     ARRAY = 280,
     ASC = 281,
     BY = 282,
     CANCEL = 283,
     COMPRESSION = 284,
     CREATE = 285,
     CROSS = 286,
     CURRENT = 287,
     DEFAULT = 288,
     DESC = 289,
     DROP = 290,
     ERRORS = 291,
     FIXED = 292,
     FN = 293,
     FOLLOWING = 294,
     FROM = 295,
     GROUP = 296,
     INSERT = 297,
     INSTANCE = 298,
     INSTANCES = 299,
     INTO = 300,
     IS = 301,
     JOIN = 302,
     LET = 303,
     LIBRARY = 304,
     LOAD = 305,
     NULL_VALUE = 306,
     ON = 307,
     ORDER = 308,
     OVER = 309,
     PARTITION = 310,
     PRECEDING = 311,
     QUERY = 312,
     REDIMENSION = 313,
     REGRID = 314,
     RENAME = 315,
     RESERVE = 316,
     SAVE = 317,
     SELECT = 318,
     SET = 319,
     SHADOW = 320,
     START = 321,
     STEP = 322,
     TEMP = 323,
     THIN = 324,
     TO = 325,
     UNBOUND = 326,
     UNLOAD = 327,
     UPDATE = 328,
     USING = 329,
     VARIABLE = 330,
     CICULAR = 331,
     WHERE = 332,
     WINDOW = 333
   };

    };
    /// Token type.
    typedef token::yytokentype token_type;

    /// Build a parser object.
    Parser (Factory&  _fac_yyarg, Log&      _log_yyarg, Node*&    _ast_yyarg, Lexer&   yylex_yyarg);
    virtual ~Parser ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

  private:
    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Generate an error message.
    /// \param state   the state where the error occurred.
    /// \param tok     the lookahead token.
    virtual std::string yysyntax_error_ (int yystate);

#if YYDEBUG
    /// \brief Report a symbol value on the debug stream.
    /// \param yytype       The token type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    virtual void yy_symbol_value_print_ (int yytype,
					 const semantic_type* yyvaluep,
					 const location_type* yylocationp);
    /// \brief Report a symbol on the debug stream.
    /// \param yytype       The token type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    virtual void yy_symbol_print_ (int yytype,
				   const semantic_type* yyvaluep,
				   const location_type* yylocationp);
#endif


    /// State numbers.
    typedef int state_type;
    /// State stack type.
    typedef stack<state_type>    state_stack_type;
    /// Semantic value stack type.
    typedef stack<semantic_type> semantic_stack_type;
    /// location stack type.
    typedef stack<location_type> location_stack_type;

    /// The state stack.
    state_stack_type yystate_stack_;
    /// The semantic value stack.
    semantic_stack_type yysemantic_stack_;
    /// The location stack.
    location_stack_type yylocation_stack_;

    /// Internal symbol numbers.
    typedef unsigned char token_number_type;
    /* Tables.  */
    /// For a state, the index in \a yytable_ of its portion.
    static const short int yypact_[];
    static const short int yypact_ninf_;

    /// For a state, default rule to reduce.
    /// Unless\a  yytable_ specifies something else to do.
    /// Zero means the default is an error.
    static const unsigned short int yydefact_[];

    static const short int yypgoto_[];
    static const short int yydefgoto_[];

    /// What to do in a state.
    /// \a yytable_[yypact_[s]]: what to do in state \a s.
    /// - if positive, shift that token.
    /// - if negative, reduce the rule which number is the opposite.
    /// - if zero, do what YYDEFACT says.
    static const short int yytable_[];
    static const short int yytable_ninf_;

    static const short int yycheck_[];

    /// For a state, its accessing symbol.
    static const unsigned char yystos_[];

    /// For a rule, its LHS.
    static const unsigned char yyr1_[];
    /// For a rule, its RHS length.
    static const unsigned char yyr2_[];

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif

#if YYERROR_VERBOSE
    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    virtual std::string yytnamerr_ (const char *n);
#endif

#if YYDEBUG
    /// A type to store symbol numbers and -1.
    typedef short int rhs_number_type;
    /// A `-1'-separated list of the rules' RHS.
    static const rhs_number_type yyrhs_[];
    /// For each rule, the index of the first RHS symbol in \a yyrhs_.
    static const unsigned short int yyprhs_[];
    /// For each rule, its source line number.
    static const unsigned short int yyrline_[];
    /// For each scanner token number, its symbol number.
    static const unsigned short int yytoken_number_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    /* Debugging.  */
    int yydebug_;
    std::ostream* yycdebug_;
#endif

    /// Convert a scanner token number \a t to a symbol number.
    token_number_type yytranslate_ (int t);

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg        Why this token is reclaimed.
    /// \param yytype       The symbol type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    inline void yydestruct_ (const char* yymsg,
			     int yytype,
			     semantic_type* yyvaluep,
			     location_type* yylocationp);

    /// Pop \a n symbols the three stacks.
    inline void yypop_ (unsigned int n = 1);

    /* Constants.  */
    static const int yyeof_;
    /* LAST_ -- Last index in TABLE_.  */
    static const int yylast_;
    static const int yynnts_;
    static const int yyempty_;
    static const int yyfinal_;
    static const int yyterror_;
    static const int yyerrcode_;
    static const int yyntokens_;
    static const unsigned int yyuser_token_number_max_;
    static const token_number_type yyundef_token_;

    /* User arguments.  */
    Factory&  _fac;
    Log&      _log;
    Node*&    _ast;
    Lexer&   yylex;
  };

/* Line 35 of lalr1.cc  */
#line 29 "parser/Parser.yy"
} } // scidb::parser

/* Line 35 of lalr1.cc  */
#line 412 "/home/gary/programmer/scidbtrunk/stage/build/src/query/parser/Parser.hpp"


/* "%code provides" blocks.  */

/* Line 35 of lalr1.cc  */
#line 251 "parser/Parser.yy"

namespace scidb {namespace parser {
    typedef Parser::token           Token;               // For token numbers
    typedef Parser::semantic_type   semantic_type;       // The type of $i
    typedef Parser::location_type   location_type;       // The type of @i
}}



/* Line 35 of lalr1.cc  */
#line 429 "/home/gary/programmer/scidbtrunk/stage/build/src/query/parser/Parser.hpp"

#endif /* ! defined PARSER_HEADER_H */
