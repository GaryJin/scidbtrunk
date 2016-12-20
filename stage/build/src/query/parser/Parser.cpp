
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
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
/* "%code top" blocks.  */

/* Line 304 of lalr1.cc  */
#line 260 "parser/Parser.yy"

#include <query/ParsingContext.h>                        // For parsing context
#include "query/parser/Lexer.h"                          // For lexical analyzer
#include "query/parser/AST.h"                            // For abstract syntax



/* Line 304 of lalr1.cc  */
#line 47 "/home/gary/programmer/scidbtrunk/stage/build/src/query/parser/Parser.cpp"


/* First part of user declarations.  */


/* Line 311 of lalr1.cc  */
#line 54 "/home/gary/programmer/scidbtrunk/stage/build/src/query/parser/Parser.cpp"


#include "Parser.hpp"

/* User implementation prologue.  */


/* Line 317 of lalr1.cc  */
#line 63 "/home/gary/programmer/scidbtrunk/stage/build/src/query/parser/Parser.cpp"

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


/* Line 380 of lalr1.cc  */
#line 29 "parser/Parser.yy"
namespace scidb { namespace parser {

/* Line 380 of lalr1.cc  */
#line 131 "/home/gary/programmer/scidbtrunk/stage/build/src/query/parser/Parser.cpp"
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  Parser::Parser (Factory&  _fac_yyarg, Log&      _log_yyarg, Node*&    _ast_yyarg, Lexer&   yylex_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      _fac (_fac_yyarg),
      _log (_log_yyarg),
      _ast (_ast_yyarg),
      yylex (yylex_yyarg)
  {
  }

  Parser::~Parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  Parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  Parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  Parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  Parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  int
  Parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:

/* Line 678 of lalr1.cc  */
#line 270 "parser/Parser.yy"
    {_ast = (yysemantic_stack_[(2) - (2)].node);}
    break;

  case 3:

/* Line 678 of lalr1.cc  */
#line 271 "parser/Parser.yy"
    {_ast = (yysemantic_stack_[(2) - (2)].node);}
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 272 "parser/Parser.yy"
    {_ast = (yysemantic_stack_[(2) - (2)].node);}
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 273 "parser/Parser.yy"
    {_ast = (yysemantic_stack_[(2) - (2)].node);}
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 277 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 278 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 279 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 280 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 281 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 282 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 283 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 284 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 285 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 286 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 287 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 288 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 292 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 293 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 297 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 301 "parser/Parser.yy"
    {(yyval.node) = _fac.newNode(module,(yyloc),_fac.newList((yyloc),(yysemantic_stack_[(1) - (1)].list)));}
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 307 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 308 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(2) - (2)].node);}
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 309 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(2) - (1)]),"-",  (yysemantic_stack_[(2) - (2)].node));}
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 310 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(3) - (2)]),"+",  (yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 311 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(3) - (2)]),"-",  (yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 312 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(3) - (2)]),"*",  (yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 313 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(3) - (2)]),"^",  (yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 314 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(3) - (2)]),"=",  (yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 315 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(3) - (2)]),"/",  (yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 316 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(3) - (2)]),"%",  (yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 317 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(3) - (2)]),"<",  (yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 318 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(3) - (2)]),">",  (yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 319 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(3) - (2)]),"<>", (yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 320 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(3) - (2)]),"<=", (yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 321 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(3) - (2)]),">=", (yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 322 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(2) - (1)]),"not",(yysemantic_stack_[(2) - (2)].node));}
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 323 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(3) - (2)]),"and",(yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 324 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(3) - (2)]),"or", (yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 325 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(3) - (3)]),"is_null",(yysemantic_stack_[(3) - (1)].node));}
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 326 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(4) - (3)]),"not",_fac.newApp((yylocation_stack_[(4) - (4)]),"is_null",(yysemantic_stack_[(4) - (1)].node)));}
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 328 "parser/Parser.yy"
    {
        (yyval.node) = _fac.newApp((yyloc),"and",
             _fac.newApp((yyloc),">=" ,(yysemantic_stack_[(5) - (1)].node),(yysemantic_stack_[(5) - (3)].node)),
             _fac.newApp((yyloc),"<=" ,_fac.newCopy((yysemantic_stack_[(5) - (1)].node)),(yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 333 "parser/Parser.yy"
    {(yyval.node) = setAlias((yysemantic_stack_[(3) - (1)].node),_fac.newCopy((yysemantic_stack_[(3) - (3)].node)));}
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 334 "parser/Parser.yy"
    {(yyval.node) = _fac.newFix((yyloc),_fac.newList((yylocation_stack_[(6) - (3)]),(yysemantic_stack_[(6) - (3)].list)),(yysemantic_stack_[(6) - (6)].node));}
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 335 "parser/Parser.yy"
    {(yyval.node) = _fac.newAbs((yyloc),_fac.newList((yylocation_stack_[(7) - (3)]),(yysemantic_stack_[(7) - (3)].list)),(yysemantic_stack_[(7) - (6)].node));}
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 339 "parser/Parser.yy"
    {(yyval.node) = _fac.newNode(binding,(yyloc),(yysemantic_stack_[(4) - (1)].node),_fac.newFix((yylocation_stack_[(4) - (4)]),(yysemantic_stack_[(4) - (4)].node),(yysemantic_stack_[(4) - (3)].node)));}
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 340 "parser/Parser.yy"
    {(yyval.node) = _fac.newNode(binding,(yyloc),(yysemantic_stack_[(7) - (1)].node),_fac.newAbs((yylocation_stack_[(7) - (3)]),_fac.newList((yylocation_stack_[(7) - (3)]),(yysemantic_stack_[(7) - (3)].list)),_fac.newFix((yylocation_stack_[(7) - (7)]),(yysemantic_stack_[(7) - (7)].node),(yysemantic_stack_[(7) - (6)].node))));}
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 344 "parser/Parser.yy"
    {(yyval.node) = _fac.newNode(binding,(yyloc),(yysemantic_stack_[(1) - (1)].node),0);}
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 348 "parser/Parser.yy"
    {(yyval.node) = _fac.newList((yylocation_stack_[(4) - (3)]),(yysemantic_stack_[(4) - (3)].list));}
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 349 "parser/Parser.yy"
    {(yyval.node) = _fac.newList((yyloc),0);}
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 357 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 358 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(2) - (2)].node);}
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 359 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(2) - (1)]),"-",  (yysemantic_stack_[(2) - (2)].node));}
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 360 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(3) - (2)]),"+",  (yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 361 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(3) - (2)]),"-",  (yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 362 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(3) - (2)]),"*",  (yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 363 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(3) - (2)]),"^",  (yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 364 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(3) - (2)]),"=",  (yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 365 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(3) - (2)]),"/",  (yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 366 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(3) - (2)]),"%",  (yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 367 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(3) - (2)]),"<",  (yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 368 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(3) - (2)]),">",  (yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 369 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(3) - (2)]),"<>", (yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 370 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(3) - (2)]),"<=", (yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 371 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(3) - (2)]),">=", (yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 372 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(3) - (3)]),"is_null",(yysemantic_stack_[(3) - (1)].node));}
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 373 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(4) - (3)]),"not",_fac.newApp((yylocation_stack_[(4) - (4)]),"is_null",(yysemantic_stack_[(4) - (1)].node)));}
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 374 "parser/Parser.yy"
    {(yyval.node) = setAlias((yysemantic_stack_[(3) - (1)].node),_fac.newCopy((yysemantic_stack_[(3) - (3)].node)));}
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 378 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 379 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 380 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 381 "parser/Parser.yy"
    {(yyval.node) = _fac.newNode(olapAggregate,(yyloc),(yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 382 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(3) - (2)].node);}
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 386 "parser/Parser.yy"
    {(yyval.node) = _fac.newRef((yyloc),(yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (2)].node),(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 387 "parser/Parser.yy"
    {(yyval.node) = _fac.newRef((yyloc),(yysemantic_stack_[(4) - (3)].node),(yysemantic_stack_[(4) - (1)].node),(yysemantic_stack_[(4) - (4)].node));}
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 391 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yyloc),(yysemantic_stack_[(4) - (1)].node),(yysemantic_stack_[(4) - (3)].node));}
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 392 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yyloc),(yysemantic_stack_[(4) - (1)].node),_fac.pop((yysemantic_stack_[(4) - (3)].list)));}
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 396 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 397 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 398 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 402 "parser/Parser.yy"
    {(yyval.node) = 0;}
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 403 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(2) - (2)].node);}
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 404 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(2) - (2)].node);}
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 408 "parser/Parser.yy"
    {(yyval.lexicon) = yylex.setLexicon(AQL);}
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 409 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(4) - (3)].node);      yylex.setLexicon((yysemantic_stack_[(4) - (2)].lexicon));}
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 413 "parser/Parser.yy"
    {(yyval.node) = 0;}
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 414 "parser/Parser.yy"
    {(yyval.node) = _fac.newInteger((yyloc),ascending);}
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 415 "parser/Parser.yy"
    {(yyval.node) = _fac.newInteger((yyloc),descending);}
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 419 "parser/Parser.yy"
    {(yyval.node) = _fac.newNode(asterisk,(yyloc));}
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 425 "parser/Parser.yy"
    {}
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 431 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 432 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 433 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 434 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 435 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 439 "parser/Parser.yy"
    {(yyval.node) = _fac.newNull((yyloc));}
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 443 "parser/Parser.yy"
    {(yyval.node) = _fac.newReal((yyloc),(yysemantic_stack_[(1) - (1)].real));}
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 447 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].string));}
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 451 "parser/Parser.yy"
    {(yyval.node) = _fac.newBoolean((yyloc),(yysemantic_stack_[(1) - (1)].boolean));}
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 455 "parser/Parser.yy"
    {(yyval.node) = _fac.newInteger((yyloc),(yysemantic_stack_[(1) - (1)].integer));}
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 461 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].string));}
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 463 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 464 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 465 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 466 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 467 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 468 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 469 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 470 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 471 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 472 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 473 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 474 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 476 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 477 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 478 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 479 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 480 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 481 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 482 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 483 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 484 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 485 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 486 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 487 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 488 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 489 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 490 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 491 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 492 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 493 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 494 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 495 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 496 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),(yysemantic_stack_[(1) - (1)].keyword));}
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 502 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yyloc),"Create_Array",(yysemantic_stack_[(5) - (4)].node),(yysemantic_stack_[(5) - (5)].node),(yysemantic_stack_[(5) - (2)].node));}
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 503 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yyloc),"Create_Array",(yysemantic_stack_[(8) - (4)].node),(yysemantic_stack_[(8) - (5)].node),(yysemantic_stack_[(8) - (2)].node),(yysemantic_stack_[(8) - (8)].node),(yysemantic_stack_[(8) - (6)].node));}
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 507 "parser/Parser.yy"
    {(yyval.node) = _fac.newNode(schema,(yyloc),_fac.newList((yylocation_stack_[(6) - (2)]),(yysemantic_stack_[(6) - (2)].list)),_fac.newList((yylocation_stack_[(6) - (5)]),(yysemantic_stack_[(6) - (5)].list)),0);}
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 511 "parser/Parser.yy"
    {(yyval.node) = _fac.newNode(attribute,(yyloc),(yysemantic_stack_[(7) - (1)].node),(yysemantic_stack_[(7) - (3)].node),(yysemantic_stack_[(7) - (4)].node),(yysemantic_stack_[(7) - (5)].node),(yysemantic_stack_[(7) - (6)].node),(yysemantic_stack_[(7) - (7)].node));}
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 515 "parser/Parser.yy"
    {(yyval.node) = _fac.newNode(dimension,(yyloc),(yysemantic_stack_[(9) - (1)].node),(yysemantic_stack_[(9) - (3)].node),(yysemantic_stack_[(9) - (5)].node),(yysemantic_stack_[(9) - (7)].node),(yysemantic_stack_[(9) - (9)].node));}
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 516 "parser/Parser.yy"
    {(yyval.node) = _fac.newNode(dimension,(yyloc),(yysemantic_stack_[(9) - (1)].node),(yysemantic_stack_[(9) - (3)].node),(yysemantic_stack_[(9) - (5)].node),(yysemantic_stack_[(9) - (7)].node),(yysemantic_stack_[(9) - (9)].node));}
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 517 "parser/Parser.yy"
    {(yyval.node) = _fac.newNode(dimension,(yyloc),(yysemantic_stack_[(1) - (1)].node),0,0,0,0);}
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 521 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 522 "parser/Parser.yy"
    {(yyval.node) = 0;}
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 526 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 527 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(2) - (2)].node);}
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 528 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(2) - (1)]),"-",(yysemantic_stack_[(2) - (2)].node));}
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 529 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 530 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(2) - (2)].node);}
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 531 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yylocation_stack_[(2) - (1)]),"-",(yysemantic_stack_[(2) - (2)].node));}
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 532 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(3) - (2)].node);}
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 536 "parser/Parser.yy"
    {(yyval.node) = _fac.newBoolean((yyloc),true);}
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 537 "parser/Parser.yy"
    {(yyval.node) = _fac.newBoolean((yyloc),false);}
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 538 "parser/Parser.yy"
    {(yyval.node) = _fac.newBoolean((yyloc),false);}
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 542 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(2) - (2)].node);}
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 543 "parser/Parser.yy"
    {(yyval.node) = 0;}
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 547 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(2) - (2)].node);}
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 548 "parser/Parser.yy"
    {(yyval.node) = 0;}
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 552 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(2) - (2)].node);}
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 553 "parser/Parser.yy"
    {(yyval.node) = 0;}
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 556 "parser/Parser.yy"
    {(yyval.node) = _fac.newBoolean((yyloc),true);}
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 557 "parser/Parser.yy"
    {(yyval.node) = _fac.newBoolean((yyloc),false);}
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 561 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(3) - (2)].node);}
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 562 "parser/Parser.yy"
    {(yyval.node) = _fac.newInteger((yyloc),1000000);}
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 569 "parser/Parser.yy"
    {
        if ((yysemantic_stack_[(8) - (8)].node) == 0)
        {
            (yyval.node) = _fac.newApp((yyloc),"Load",(yysemantic_stack_[(8) - (2)].node),(yysemantic_stack_[(8) - (5)].node),(yysemantic_stack_[(8) - (4)].node),(yysemantic_stack_[(8) - (6)].node),(yysemantic_stack_[(8) - (7)].node));
        }
        else
        {
            (yyval.node) = _fac.newApp((yyloc),"Load",(yysemantic_stack_[(8) - (2)].node),(yysemantic_stack_[(8) - (5)].node),(yysemantic_stack_[(8) - (4)].node),(yysemantic_stack_[(8) - (6)].node),(yysemantic_stack_[(8) - (7)].node),(yysemantic_stack_[(8) - (8)].node));
        }
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 582 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(2) - (2)].node);}
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 583 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),"");}
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 587 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(2) - (2)].node);}
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 588 "parser/Parser.yy"
    {(yyval.node) = _fac.newInteger((yyloc),0);}
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 592 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(3) - (3)].node);}
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 593 "parser/Parser.yy"
    {(yyval.node) = 0;}
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 598 "parser/Parser.yy"
    {
        (yyval.node) = _fac.newApp((yyloc),"Save",(yysemantic_stack_[(6) - (2)].node),(yysemantic_stack_[(6) - (5)].node),(yysemantic_stack_[(6) - (4)].node),(yysemantic_stack_[(6) - (6)].node));
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 604 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(2) - (2)].node);}
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 605 "parser/Parser.yy"
    {(yyval.node) = _fac.newString((yyloc),"auto");}
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 609 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 610 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(2) - (2)].node);}
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 611 "parser/Parser.yy"
    {(yyval.node) = _fac.newInteger((yyloc),allInstances);}
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 612 "parser/Parser.yy"
    {(yyval.node) = _fac.newInteger((yyloc),thisInstance);}
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 613 "parser/Parser.yy"
    {(yyval.node) = _fac.newInteger((yyloc),thisInstance);}
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 617 "parser/Parser.yy"
    {(yyval.node) = _fac.newNode(updateArray,(yyloc),(yysemantic_stack_[(5) - (2)].node),_fac.newList((yylocation_stack_[(5) - (4)]),(yysemantic_stack_[(5) - (4)].list)),(yysemantic_stack_[(5) - (5)].node));}
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 621 "parser/Parser.yy"
    {(yyval.node) = _fac.newNode(update,(yyloc),(yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 625 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yyloc),"Remove",(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 629 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yyloc),"Rename",(yysemantic_stack_[(5) - (3)].node),(yysemantic_stack_[(5) - (5)].node));}
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 633 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yyloc),"Load_Library",(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 637 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yyloc),"Unload_Library",(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 641 "parser/Parser.yy"
    {(yyval.node) = _fac.newApp((yyloc),"Cancel",(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 645 "parser/Parser.yy"
    {(yyval.node) = _fac.newNode(insertArray,(yyloc),(yysemantic_stack_[(4) - (3)].node),(yysemantic_stack_[(4) - (4)].node));}
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 646 "parser/Parser.yy"
    {(yyval.node) = _fac.newNode(insertArray,(yyloc),(yysemantic_stack_[(4) - (3)].node),(yysemantic_stack_[(4) - (4)].node));}
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 653 "parser/Parser.yy"
    {
        (yyval.node) = _fac.newNode(selectArray,(yyloc),_fac.newList((yylocation_stack_[(2) - (2)]),(yysemantic_stack_[(2) - (2)].list)),0,0,0,0,0);
    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 657 "parser/Parser.yy"
    {
        (yyval.node) = _fac.newNode(selectArray,(yyloc),_fac.newList((yylocation_stack_[(7) - (2)]),(yysemantic_stack_[(7) - (2)].list)),0,_fac.newList((yylocation_stack_[(7) - (4)]),(yysemantic_stack_[(7) - (4)].list)),(yysemantic_stack_[(7) - (5)].node),(yysemantic_stack_[(7) - (6)].node),(yysemantic_stack_[(7) - (7)].node));
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 664 "parser/Parser.yy"
    {
        (yyval.node) = _fac.newNode(selectArray,(yyloc),_fac.newList((yylocation_stack_[(4) - (2)]),(yysemantic_stack_[(4) - (2)].list)),(yysemantic_stack_[(4) - (4)].node),0,0,0,0);
    }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 668 "parser/Parser.yy"
    {
        (yyval.node) = _fac.newNode(selectArray,(yyloc),_fac.newList((yylocation_stack_[(9) - (2)]),(yysemantic_stack_[(9) - (2)].list)),(yysemantic_stack_[(9) - (4)].node),_fac.newList((yylocation_stack_[(9) - (6)]),(yysemantic_stack_[(9) - (6)].list)),(yysemantic_stack_[(9) - (7)].node),(yysemantic_stack_[(9) - (8)].node),(yysemantic_stack_[(9) - (9)].node));
    }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 674 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 675 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 679 "parser/Parser.yy"
    {(yyval.node) =  0;}
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 680 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(2) - (2)].node);}
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 684 "parser/Parser.yy"
    {(yyval.node) =  0;}
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 685 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 686 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 687 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 688 "parser/Parser.yy"
    {(yyval.node) = _fac.newList((yyloc),(yysemantic_stack_[(1) - (1)].list));}
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 692 "parser/Parser.yy"
    {(yyval.node) = _fac.newNode(groupByClause,(yyloc),_fac.newList((yylocation_stack_[(3) - (3)]),(yysemantic_stack_[(3) - (3)].list)));}
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 696 "parser/Parser.yy"
    {(yyval.node) = _fac.newNode(redimensionClause,(yyloc),_fac.newList((yylocation_stack_[(5) - (4)]),(yysemantic_stack_[(5) - (4)].list)));}
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 700 "parser/Parser.yy"
    {(yyval.node) = _fac.newNode(regridClause,(yyloc),_fac.newList((yylocation_stack_[(7) - (6)]),(yysemantic_stack_[(7) - (6)].list)));}
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 704 "parser/Parser.yy"
    {(yyval.node) = _fac.newNode(regridDimension,(yyloc),(yysemantic_stack_[(2) - (1)].node),(yysemantic_stack_[(2) - (2)].node));}
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 705 "parser/Parser.yy"
    {(yyval.node) = _fac.newNode(regridDimension,(yyloc),(yysemantic_stack_[(2) - (1)].node),_fac.newInteger((yyloc),1));}
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 710 "parser/Parser.yy"
    {
        (yyval.node) = _fac.newNode(windowClause,(yyloc),_fac.newString((yyloc),""),_fac.newList((yylocation_stack_[(8) - (7)]),(yysemantic_stack_[(8) - (7)].list)),(yysemantic_stack_[(8) - (1)].node));
	printf("got window_clause\n");
	std::cout<<"got window_clause"<<std::endl;
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 716 "parser/Parser.yy"
    {
        (yyval.node) = _fac.newNode(windowClause,(yyloc),(yysemantic_stack_[(9) - (3)].node),_fac.newList((yylocation_stack_[(9) - (8)]),(yysemantic_stack_[(9) - (8)].list)),(yysemantic_stack_[(9) - (1)].node));
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 722 "parser/Parser.yy"
    {(yyval.node) = _fac.newBoolean((yyloc),true);std::cout<<"got variable"<<std::endl;}
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 723 "parser/Parser.yy"
    {(yyval.node) = _fac.newBoolean((yyloc),true);std::cout<<"got variable"<<std::endl;}
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 724 "parser/Parser.yy"
    {(yyval.node) = _fac.newBoolean((yyloc),false);}
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 725 "parser/Parser.yy"
    {(yyval.node) = _fac.newBoolean((yyloc),false);}
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 730 "parser/Parser.yy"
    {
        (yyval.node) = _fac.newNode(windowDimensionRange,(yyloc),(yysemantic_stack_[(6) - (1)].node),(yysemantic_stack_[(6) - (2)].node),(yysemantic_stack_[(6) - (5)].node));
    }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 734 "parser/Parser.yy"
    {
        (yyval.node) = _fac.newNode(windowDimensionRange,(yyloc),(yysemantic_stack_[(2) - (1)].node),_fac.newInteger((yylocation_stack_[(2) - (2)]),0),_fac.newInteger((yylocation_stack_[(2) - (2)]),0));
    }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 740 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 741 "parser/Parser.yy"
    {(yyval.node) = _fac.newInteger((yyloc),-1);}
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 745 "parser/Parser.yy"
    {(yyval.node) =  0;}
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 746 "parser/Parser.yy"
    {(yyval.node) = _fac.newList((yylocation_stack_[(3) - (3)]),(yysemantic_stack_[(3) - (3)].list));}
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 751 "parser/Parser.yy"
    {
     // lift an optional alias up from the expression to the namedExpr - todo: jab: move this into the translator
        (yyval.node) = _fac.newNode(namedExpr,(yyloc),(yysemantic_stack_[(1) - (1)].node),_fac.newCopy(getAlias((yysemantic_stack_[(1) - (1)].node))));
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 758 "parser/Parser.yy"
    {(yyval.node) = _fac.newNode(namedExpr,(yyloc),(yysemantic_stack_[(1) - (1)].node),0);}
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 759 "parser/Parser.yy"
    {(yyval.node) = _fac.newNode(namedExpr,(yyloc),(yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node));}
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 760 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 761 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 765 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 766 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 767 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 768 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 773 "parser/Parser.yy"
    {
        (yyval.node) = _fac.newApp((yyloc),"Build",(yysemantic_stack_[(6) - (3)].node),(yysemantic_stack_[(6) - (5)].node),_fac.newBoolean((yylocation_stack_[(6) - (1)]),true));
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 779 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 780 "parser/Parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 784 "parser/Parser.yy"
    {(yyval.node) = _fac.newNode(joinClause,(yyloc),(yysemantic_stack_[(5) - (1)].node),(yysemantic_stack_[(5) - (3)].node),(yysemantic_stack_[(5) - (5)].node));}
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 785 "parser/Parser.yy"
    {(yyval.node) = _fac.newNode(joinClause,(yyloc),(yysemantic_stack_[(4) - (1)].node),(yysemantic_stack_[(4) - (4)].node),0);}
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 790 "parser/Parser.yy"
    {
        (yyval.node) = _fac.newNode(thinClause,(yyloc),(yysemantic_stack_[(6) - (2)].node),_fac.newList((yylocation_stack_[(6) - (5)]),(yysemantic_stack_[(6) - (5)].list)));
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 797 "parser/Parser.yy"
    {
        (yyval.node) = _fac.newNode(thinDimension,(yyloc),(yysemantic_stack_[(5) - (1)].node),(yysemantic_stack_[(5) - (3)].node),(yysemantic_stack_[(5) - (5)].node));
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 810 "parser/Parser.yy"
    {(yyval.list) = 0;                 }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 811 "parser/Parser.yy"
    {(yyval.list) = 1;   _fac.push((yysemantic_stack_[(1) - (1)].node));}
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 812 "parser/Parser.yy"
    {(yyval.list) = (yysemantic_stack_[(2) - (1)].list);                }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 813 "parser/Parser.yy"
    {(yyval.list) = (yysemantic_stack_[(3) - (1)].list)+1;_fac.push((yysemantic_stack_[(3) - (3)].node));}
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 817 "parser/Parser.yy"
    {(yyval.list) = 0;                 }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 818 "parser/Parser.yy"
    {(yyval.list) = 1;   _fac.push((yysemantic_stack_[(1) - (1)].node));}
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 819 "parser/Parser.yy"
    {(yyval.list) = (yysemantic_stack_[(3) - (1)].list)+1;_fac.push((yysemantic_stack_[(3) - (3)].node));}
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 823 "parser/Parser.yy"
    {(yyval.list) = 0;                 }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 824 "parser/Parser.yy"
    {(yyval.list) = 1;   _fac.push((yysemantic_stack_[(1) - (1)].node));}
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 825 "parser/Parser.yy"
    {(yyval.list) = (yysemantic_stack_[(3) - (1)].list)+1;_fac.push((yysemantic_stack_[(3) - (3)].node));}
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 829 "parser/Parser.yy"
    {(yyval.list) = 1;   _fac.push((yysemantic_stack_[(1) - (1)].node));}
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 830 "parser/Parser.yy"
    {(yyval.list) = (yysemantic_stack_[(3) - (1)].list)+1;_fac.push((yysemantic_stack_[(3) - (3)].node));}
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 834 "parser/Parser.yy"
    {(yyval.list) = 1;   _fac.push((yysemantic_stack_[(1) - (1)].node));}
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 835 "parser/Parser.yy"
    {(yyval.list) = (yysemantic_stack_[(3) - (1)].list)+1;_fac.push((yysemantic_stack_[(3) - (3)].node));}
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 839 "parser/Parser.yy"
    {(yyval.list) = 1;   _fac.push((yysemantic_stack_[(1) - (1)].node));}
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 840 "parser/Parser.yy"
    {(yyval.list) = (yysemantic_stack_[(3) - (1)].list)+1;_fac.push((yysemantic_stack_[(3) - (3)].node));}
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 844 "parser/Parser.yy"
    {(yyval.list) =  1;  _fac.push((yysemantic_stack_[(1) - (1)].node));}
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 845 "parser/Parser.yy"
    {(yyval.list) = (yysemantic_stack_[(3) - (1)].list)+1;_fac.push((yysemantic_stack_[(3) - (3)].node));}
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 849 "parser/Parser.yy"
    {(yyval.list) = 1;   _fac.push((yysemantic_stack_[(1) - (1)].node));}
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 850 "parser/Parser.yy"
    {(yyval.list) = (yysemantic_stack_[(3) - (1)].list)+1;_fac.push((yysemantic_stack_[(3) - (3)].node));}
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 854 "parser/Parser.yy"
    {(yyval.list) = 1;   _fac.push((yysemantic_stack_[(1) - (1)].node));}
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 855 "parser/Parser.yy"
    {(yyval.list) = (yysemantic_stack_[(3) - (1)].list)+1;_fac.push((yysemantic_stack_[(3) - (3)].node));}
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 859 "parser/Parser.yy"
    {(yyval.list) = 1;   _fac.push((yysemantic_stack_[(1) - (1)].node));}
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 860 "parser/Parser.yy"
    {(yyval.list) = (yysemantic_stack_[(3) - (1)].list)+1;_fac.push((yysemantic_stack_[(3) - (3)].node));}
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 864 "parser/Parser.yy"
    {(yyval.list) = 1;   _fac.push((yysemantic_stack_[(1) - (1)].node));}
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 865 "parser/Parser.yy"
    {(yyval.list) = (yysemantic_stack_[(3) - (1)].list)+1;_fac.push((yysemantic_stack_[(3) - (3)].node));}
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 869 "parser/Parser.yy"
    {(yyval.list) = 1;   _fac.push((yysemantic_stack_[(1) - (1)].node));}
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 870 "parser/Parser.yy"
    {(yyval.list) = (yysemantic_stack_[(3) - (1)].list)+1;_fac.push((yysemantic_stack_[(3) - (3)].node));}
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 874 "parser/Parser.yy"
    {(yyval.list) = 1;   _fac.push((yysemantic_stack_[(1) - (1)].node));}
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 875 "parser/Parser.yy"
    {(yyval.list) = (yysemantic_stack_[(3) - (1)].list)+1;_fac.push((yysemantic_stack_[(3) - (3)].node));}
    break;



/* Line 678 of lalr1.cc  */
#line 2301 "/home/gary/programmer/scidbtrunk/stage/build/src/query/parser/Parser.cpp"
	default:
          break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate));
      }

    yyerror_range[0] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[0] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (int yystate)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const short int Parser::yypact_ninf_ = -433;
  const short int
  Parser::yypact_[] =
  {
       284,   246,  1488,   994,  1540,    23,   -17,   -25,    22,    60,
    1592,   112,  1540,   840,   103,  1540,  -433,  -433,  -433,  -433,
    -433,  -433,  -433,  -433,  -433,  -433,  -433,  -433,  -433,  -433,
    -433,  -433,  -433,  -433,  -433,  -433,  -433,   -53,  -433,  -433,
    -433,  -433,  -433,  -433,  -433,  -433,  -433,  -433,  -433,  -433,
    -433,  -433,  -433,  -433,  -433,  -433,  -433,  -433,  -433,  -433,
    -433,  -433,  -433,  -433,  -433,    76,  -433,   994,   994,   994,
    -433,  -433,  -433,  -433,  -433,    77,    98,  -433,   994,  -433,
    1722,  -433,  -433,   101,  -433,  -433,  -433,  -433,  -433,  -433,
      13,  -433,  -433,    17,   105,  -433,   195,  -433,  -433,   198,
    1540,  1540,   200,   187,     8,  1540,   186,  -433,  1722,  -433,
    -433,  -433,    91,   200,   173,   763,  1751,   194,   194,  1540,
    1540,   164,  1540,   994,   994,   994,   994,   994,   994,   994,
     994,  1063,   994,   994,   994,   994,   994,   994,    34,  1540,
     840,  1540,   -15,   994,  1540,  1540,  -433,  1540,  -433,     6,
    -433,     5,   185,     5,  1185,  1540,   840,  -433,  1540,  1540,
     994,  1722,  -433,  -433,   159,  -433,   -46,  -433,  -433,   127,
      74,  -433,  -433,  1353,  1751,   283,   283,   283,   283,   283,
     283,  1063,  1063,   188,  -433,   170,   170,   172,   172,   172,
     172,   212,  -433,  -433,  1738,  -433,   -15,  -433,  -433,  -433,
    1338,   142,  -433,   263,   840,  -433,  -433,   222,   225,   195,
    -433,  -433,   200,  1540,   200,   196,  1238,  -433,  -433,  -433,
    -433,    95,   285,  -433,  -433,  -433,   -45,   243,  -433,   278,
    -433,    57,   216,  -433,    10,   223,  -433,  -433,   917,   226,
    1540,   310,   261,   261,  1540,  1063,  1063,  1063,  1063,  1063,
    1063,  1063,  1063,  1063,  1063,  1063,  1063,  1063,    35,  -433,
    -433,   231,  -433,  -433,   311,    11,    12,  -433,  -433,  -433,
     317,  -433,   318,  1436,   287,   269,  1185,  1540,   994,  1185,
     167,  1185,   994,  1540,  -433,  1540,   236,  1540,   245,  -433,
     994,  -433,   994,  -433,   314,   314,   314,   314,   314,   314,
     314,   238,   238,   190,   190,   190,   190,   277,  -433,  1540,
     994,   994,  -433,   257,   200,  -433,   298,   200,  -433,  -433,
    -433,  -433,   249,   256,  1185,    -8,  -433,  1722,    95,  -433,
     312,   313,   343,  -433,  -433,  -433,   289,  -433,  -433,  -433,
    -433,   265,   258,   -45,  1722,  -433,    36,  1540,  -433,  -433,
    1320,  1722,  -433,   132,  1338,    56,  1540,  -433,   195,  -433,
     281,  -433,   200,  1540,    95,   994,  1540,   264,   266,   322,
    -433,  1644,    75,   167,   299,  -433,  -433,   319,   353,  -433,
     169,  -433,  -433,  -433,  -433,  -433,  -433,   330,  -433,   274,
     291,  -433,   148,  1722,  -433,   276,  1540,   306,  1540,   286,
     370,  -433,   289,  -433,  1132,  -433,   337,   656,  -433,  1540,
    1540,  -433,   195,  -433,  1540,  1540,   175,   344,   276,   315,
     292,  -433,  1384,  1384,   994,  -433,  -433,  -433,   200,  -433,
     316,  -433,  1722,   288,  -433,  -433,   308,  -433,  -433,  -433,
    1540,   349,   323,  -433,  -433,  -433,  -433,   745,  -433,   195,
    -433,  -433,   546,   195,   183,  -433,   151,  1540,   352,  -433,
    -433,   293,   294,  -433,  -433,  -433,  -433,  1540,    68,  -433,
     157,  1540,   656,   656,  -433,  -433,  -433,  -433,   326,  -433,
    1540,   171,   296,   300,   387,  -433,  -433,   656,   656,    33,
    -433,  -433,   350,  -433
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  Parser::yydefact_[] =
  {
         0,     0,     0,     0,   234,     0,     0,    90,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     6,     7,     8,
      15,     9,    10,    11,    12,    13,    14,    16,    17,   103,
     105,   101,   114,   102,   104,   115,   106,    90,   116,   109,
     108,   117,   118,   119,   120,   121,   110,   122,   123,   124,
     125,   126,   127,   111,   128,   129,   130,   131,   112,   132,
     133,   134,   113,     3,    19,     0,    18,     0,     0,     0,
      97,    98,    99,   100,   107,     0,     0,    96,     0,     4,
      20,    22,    70,    71,    69,    91,    92,    93,    94,    95,
      81,     5,   235,     0,    21,     1,     0,   160,   161,     0,
       0,     0,   122,     0,    81,     0,     0,    89,   218,   193,
     252,   192,   188,     0,     0,   238,    37,    23,    24,   241,
     234,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    86,     0,   241,   236,   185,     0,   181,     0,
     183,    90,     0,    90,     0,     0,     0,   184,     0,     0,
      84,    78,   239,    80,     0,    79,     0,   242,    48,     0,
       0,    73,    43,    39,    38,    29,    32,    33,    36,    35,
      34,     0,     0,     0,    51,    25,    26,    27,    30,    31,
      28,     0,    40,    72,    82,    83,    86,    87,    88,    74,
      90,     0,   237,     0,     0,   186,   187,     0,     0,     0,
     178,   174,     0,     0,     0,   102,   132,    84,   223,   224,
     226,   254,   219,   225,   221,   222,   194,   190,   253,     0,
     250,   194,     0,   246,     0,     0,    76,    77,     0,     0,
       0,     0,    52,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    41,
      75,     0,    46,    50,     0,    90,   188,   176,   177,   175,
      90,   182,    90,     0,     0,     0,     0,     0,     0,     0,
     196,     0,     0,     0,   179,     0,     0,     0,     0,   240,
       0,   243,     0,    68,    42,    58,    61,    62,    65,    64,
      63,    54,    55,    56,    59,    60,    57,     0,    66,   234,
       0,     0,   163,     0,     0,   166,    90,     0,   173,   171,
     228,   229,     0,     0,     0,     0,   220,   195,   255,   210,
       0,     0,     0,   208,   209,   211,   216,   197,   198,   199,
     262,     0,   200,   194,   180,   251,    90,     0,   247,    85,
       0,    44,    67,     0,    90,     0,     0,   165,     0,   168,
     170,   172,     0,     0,   231,     0,     0,     0,     0,     0,
     189,     0,    90,   196,     0,   151,   153,    90,   141,   248,
       0,    45,    49,    47,   162,   136,   167,     0,   164,     0,
       0,   258,     0,   230,   244,   201,     0,     0,     0,   103,
       0,   263,   216,   152,     0,   155,    90,     0,   137,     0,
       0,   227,     0,   232,     0,     0,     0,     0,   217,     0,
       0,   191,     0,     0,     0,   147,   144,   154,     0,   157,
      90,   143,   142,     0,   249,   169,     0,   259,   245,   202,
       0,     0,     0,   148,   145,   149,   146,     0,   156,     0,
     159,   138,     0,     0,     0,   256,     0,     0,     0,   150,
     158,     0,     0,   233,   205,   204,   203,     0,     0,   260,
       0,     0,     0,     0,   257,   213,   215,   214,     0,   206,
       0,     0,     0,     0,     0,   261,   207,     0,     0,     0,
     140,   139,     0,   212
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
      -433,  -433,  -433,  -433,  -433,  -433,   365,   253,   160,    47,
    -164,  -122,    16,     1,   166,  -433,  -100,  -433,   210,  -110,
      -3,  -264,  -433,  -433,  -101,  -433,    70,    -2,   407,  -179,
     123,     2,  -432,  -433,  -433,  -433,  -433,  -433,  -433,  -433,
    -433,  -433,  -433,  -433,  -433,  -433,   262,  -433,   133,  -433,
    -433,  -433,  -433,  -433,  -433,  -133,  -433,   273,  -224,    44,
    -433,  -433,  -433,   -49,    50,  -433,   -61,   -64,    37,  -433,
    -244,   219,  -433,  -433,  -433,  -433,    26,  -114,  -433,   297,
      38,  -433,    41,  -433,   240,   161,  -433,  -433,   -26,  -433
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,     5,    16,    63,    79,    91,   432,    92,   167,   262,
     183,    81,    82,    83,   162,   142,   220,   235,   199,   109,
     335,    84,    85,    86,    87,    88,    89,    90,    17,   165,
     233,   379,   433,   427,   377,   406,   430,   451,    99,   313,
      18,   316,   360,   388,    19,   319,   212,    20,   230,    21,
      22,    23,    24,    25,    26,    27,    28,   110,   280,   336,
     337,   338,   339,   455,   340,   341,   469,   478,   370,   111,
     221,   222,   223,   322,   224,   225,   391,    94,   166,   169,
     395,   234,   380,   231,   112,   226,   456,   392,   470,   342
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int Parser::yytable_ninf_ = -136;
  const short int
  Parser::yytable_[] =
  {
        65,   150,    93,    64,    98,   164,   170,   284,   104,   184,
     104,  -135,   157,   104,   140,   163,   206,   242,   243,   140,
     462,   197,   286,    95,   265,    97,   103,   143,   106,   198,
     195,   114,   325,   275,    98,   328,    71,    73,  -107,   207,
     482,   483,   278,   191,   307,   374,   237,   208,   205,   276,
      96,   238,   279,    97,   365,   490,   491,   100,   209,   184,
     184,   122,   154,   123,   124,    73,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   204,
     364,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   321,   192,   308,   375,   104,   149,
      73,   141,   288,   104,   115,   311,   141,   287,   144,   156,
     475,   270,   138,   272,   476,   101,   148,   168,    93,   373,
     172,   152,   329,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   275,   193,   163,   196,
     426,   154,   168,    93,   278,   104,   155,   105,   210,   476,
     210,   384,   276,   227,   283,   219,   229,   232,   444,   446,
     333,   334,   113,   203,   241,   139,   146,   115,   119,   122,
     218,   123,   124,   145,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   120,   156,   134,
     135,   136,   137,   244,   137,   353,   245,   263,   246,   247,
     248,   249,   250,   251,   145,   252,   253,   254,   255,   256,
     257,   104,   257,   357,   329,    73,   361,   219,   330,   239,
     138,   211,   382,   211,   240,   464,   138,    73,   138,   271,
      71,   145,   218,   147,   264,   331,   332,   151,   168,   240,
     413,   153,   293,   466,   258,   414,   258,   158,   467,   479,
     138,   236,   333,   334,   480,   -90,   171,   254,   255,   256,
     257,   389,   312,   486,   408,   213,   409,   315,   480,   318,
     439,   104,   409,   259,   159,   326,   267,   219,   268,   269,
     219,   229,   219,   346,     6,   232,     7,   273,   282,   320,
     277,     8,   218,   281,   258,   218,   204,   218,     9,   131,
     132,   133,   134,   135,   136,   137,    10,    93,     1,     2,
       3,     4,   285,   359,   292,   290,    11,   258,    12,    13,
     309,   310,   314,   317,   323,   219,   324,   448,    14,    15,
     347,   252,   253,   254,   255,   256,   257,   349,   352,   138,
     218,   356,   461,   376,   358,   378,   362,   363,   368,   366,
     367,   263,   369,   371,   104,   372,   387,   397,   396,   398,
     403,   104,   404,   407,   104,   410,   411,   412,    80,   400,
     258,   417,   385,   415,   405,   420,   428,   419,   108,   390,
     441,   440,   394,   442,   452,   453,   457,   449,   458,   471,
     472,   473,   484,   487,   378,   489,   104,   488,   202,   493,
     291,   383,    65,   429,   289,   425,   260,   378,   104,    66,
     348,   434,   104,   104,   394,   214,   345,   402,   474,   485,
      65,    65,   401,   443,   445,   492,   435,   450,   386,   228,
     390,   438,   116,   117,   118,   274,   418,   416,   104,   421,
     437,   201,   343,   121,   266,   481,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,   454,     0,     0,     0,
       0,     0,     0,     0,     0,   104,     0,     0,     0,   104,
       0,     0,     0,   468,     0,     0,     0,     0,   104,     0,
     161,     0,   436,   454,     0,     0,     0,   468,   173,   174,
     175,   176,   177,   178,   179,   180,   468,   185,   186,   187,
     188,   189,   190,     0,     0,   194,     0,     0,   200,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   460,
       0,   108,     0,   463,   465,   121,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   477,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    29,     0,     0,     0,    67,     0,     0,     0,   477,
       0,     0,    30,    68,    69,   107,     0,     0,     0,   108,
       0,     0,     0,     0,     0,    70,    71,    72,    73,    31,
      32,    33,    34,    35,     0,    36,    74,     0,    38,    39,
      40,    41,    42,     0,    75,    43,     0,     0,     0,    44,
      45,     0,    46,   161,    76,    47,    48,    77,     0,     0,
      49,    50,    51,    52,     0,     0,     0,    53,    54,     0,
       0,    55,    56,    57,    58,    59,    60,    61,     0,     0,
      62,     0,     0,     0,     0,     0,     0,    78,     0,     0,
       0,     0,     0,   327,   431,     0,     0,   344,     0,     0,
       0,     0,     0,     0,     0,   350,     0,   351,     0,     0,
       0,    29,     0,     0,     0,    67,     0,     0,     0,     0,
       0,     0,    30,    68,    69,   354,   355,     0,     0,     0,
       0,     0,     0,     0,     0,    70,    71,    72,    73,    31,
      32,    33,    34,    35,     0,    36,    74,     0,    38,    39,
      40,    41,    42,     0,    75,    43,     0,     0,     0,    44,
      45,     0,    46,     0,    76,    47,    48,    77,     0,     0,
      49,    50,    51,    52,     0,     0,     0,    53,    54,     0,
     393,    55,    56,    57,    58,    59,    60,    61,     0,     0,
      62,     0,     0,     0,     0,     0,     0,    78,     0,     0,
     122,     0,   123,   124,   431,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,    29,     0,
       0,     0,    67,     0,   159,     0,     0,     0,     0,    30,
      68,    69,   107,     0,     0,     0,     0,     0,     0,   447,
       0,     0,    70,    71,    72,    73,    31,    32,    33,    34,
      35,   138,    36,    74,     0,    38,    39,    40,    41,    42,
       0,    75,    43,     0,     0,     0,    44,    45,     0,    46,
       0,    76,    47,    48,    77,     0,     0,    49,    50,    51,
      52,     0,     0,     0,    53,    54,     0,   459,    55,    56,
      57,    58,    59,    60,    61,    29,     0,    62,     0,    67,
       0,     0,     0,     0,   160,     0,    30,    68,    69,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
      71,    72,    73,    31,    32,    33,    34,    35,     0,    36,
      74,     0,    38,    39,    40,    41,    42,     0,    75,    43,
       0,     0,     0,    44,    45,     0,    46,     0,    76,    47,
      48,    77,     0,     0,    49,    50,    51,    52,     0,     0,
       0,    53,    54,     0,     0,    55,    56,    57,    58,    59,
      60,    61,    29,     0,    62,     0,    67,     0,   159,     0,
       0,    78,     0,    30,    68,    69,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,    71,    72,    73,
      31,    32,    33,    34,    35,     0,    36,    74,     0,    38,
      39,    40,    41,    42,     0,    75,    43,     0,     0,     0,
      44,    45,     0,    46,     0,    76,    47,    48,    77,     0,
       0,    49,    50,    51,    52,     0,     0,     0,    53,    54,
       0,     0,    55,    56,    57,    58,    59,    60,    61,    29,
       0,    62,     0,    67,     0,     0,     0,     0,   160,     0,
      30,    68,    69,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,    71,    72,    73,    31,    32,    33,
      34,    35,     0,    36,    74,     0,    38,    39,    40,    41,
      42,     0,    75,    43,     0,     0,     0,    44,    45,     0,
      46,     0,    76,    47,    48,    77,     0,     0,    49,    50,
      51,    52,     0,     0,     0,    53,    54,     0,    29,    55,
      56,    57,    58,    59,    60,    61,     0,     0,    62,    30,
     181,   182,     0,     0,     0,    78,     0,     0,     0,     0,
       0,     0,    70,    71,    72,    73,    31,    32,    33,    34,
      35,     0,    36,    74,     0,    38,    39,    40,    41,    42,
       0,     0,    43,     0,     0,     0,    44,    45,     0,    46,
       0,     0,    47,    48,    77,     0,     0,    49,    50,    51,
      52,     0,     0,     0,    53,    54,     0,    29,    55,    56,
      57,    58,    59,    60,    61,     0,     0,    62,    30,   422,
     423,     0,     0,     0,    78,     0,     0,     0,     0,     0,
       0,    70,    71,    72,    73,    31,    32,    33,    34,    35,
       0,    36,    74,     0,    38,    39,    40,    41,    42,     0,
       0,    43,     0,     0,     0,    44,    45,     0,    46,     0,
      29,    47,    48,    77,     0,     0,    49,    50,    51,    52,
       0,    30,     0,    53,    54,     0,     0,    55,    56,    57,
      58,    59,    60,    61,     0,     0,    62,     0,    31,    32,
     215,    34,    35,   424,    36,    74,     0,    38,    39,    40,
      41,    42,     0,     0,    43,     0,     0,     0,    44,    45,
       0,    46,     0,    29,    47,    48,     0,     0,     0,    49,
      50,    51,    52,     0,    30,     0,    53,    54,     0,     0,
      55,    56,    57,    58,   216,    60,    61,     0,     0,    62,
       0,    31,    32,   215,    34,    35,   217,    36,    74,     0,
      38,    39,    40,    41,    42,     0,     0,    43,     0,     0,
       0,    44,    45,     0,    46,     0,     0,    47,    48,     0,
       0,     0,    49,    50,    51,    52,     0,     0,     0,    53,
      54,     0,     0,    55,    56,    57,    58,    59,    60,    61,
       0,     0,    62,     0,     0,   122,     0,   123,   124,   217,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   122,     0,   123,   124,     0,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   124,     0,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
       0,     0,     0,     0,   138,     0,     0,     0,     0,     0,
      30,     0,     0,     0,     0,     0,     0,     0,     0,   138,
     381,     0,     0,    70,    71,    72,    73,    31,    32,    33,
      34,    35,     0,    36,    74,   261,    38,    39,    40,    41,
      42,     0,     0,    43,     0,     0,     0,    44,    45,     0,
      46,    29,     0,    47,    48,    77,     0,   159,    49,    50,
      51,    52,    30,     0,     0,    53,    54,     0,     0,    55,
      56,    57,    58,    59,    60,    61,     0,     0,    62,    31,
      32,    33,    34,    35,     0,    36,    74,     0,    38,    39,
      40,    41,    42,     0,     0,    43,     0,     0,     0,    44,
      45,     0,    46,    29,     0,    47,    48,     0,     0,     0,
      49,    50,    51,    52,    30,     0,     0,    53,    54,     0,
       0,    55,    56,    57,    58,    59,    60,    61,     0,     0,
      62,    31,    32,    33,    34,    35,     0,    36,    37,     0,
      38,    39,    40,    41,    42,     0,     0,    43,     0,     0,
       0,    44,    45,     0,    46,    29,     0,    47,    48,     0,
       0,     0,    49,    50,    51,    52,    30,     0,     0,    53,
      54,     0,     0,    55,    56,    57,    58,    59,    60,    61,
       0,     0,    62,    31,    32,    33,    34,    35,     0,    36,
      74,     0,    38,    39,    40,    41,    42,     0,     0,    43,
       0,     0,     0,    44,    45,     0,    46,    29,     0,    47,
      48,     0,     0,     0,    49,    50,    51,    52,    30,     0,
       0,    53,    54,     0,     0,    55,    56,    57,    58,    59,
      60,    61,     0,     0,    62,    31,    32,    33,    34,    35,
       0,    36,    74,     0,    38,    39,    40,    41,    42,     0,
       0,    43,     0,     0,     0,    44,    45,     0,    46,   399,
       0,   102,    48,     0,     0,     0,    49,    50,    51,    52,
      30,     0,     0,    53,    54,     0,     0,    55,    56,    57,
      58,    59,    60,    61,     0,     0,    62,    31,    32,    33,
      34,    35,     0,    36,    74,     0,    38,    39,    40,    41,
      42,     0,     0,    43,     0,     0,     0,    44,    45,     0,
      46,     0,     0,    47,    48,     0,     0,     0,    49,    50,
      51,    52,     0,     0,     0,    53,    54,     0,     0,    55,
      56,    57,    58,    59,    60,    61,     0,   122,    62,   123,
     124,     0,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   123,   124,     0,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,     0,     0,     0,     0,   138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   138,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         2,   102,     4,     2,     7,   115,   120,   231,    10,   131,
      12,     0,   113,    15,     6,   115,   149,   181,   182,     6,
     452,    36,    12,     0,   203,    78,    10,    10,    12,    44,
     140,    15,   276,    41,    37,   279,    30,    32,    91,    34,
     472,   473,    87,     9,     9,     9,    92,    42,   149,    57,
      67,    97,    97,    78,    62,   487,   488,    35,    53,   181,
     182,     5,    50,     7,     8,    32,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    73,
     324,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   273,    61,    61,    61,   100,   101,
      32,    93,   235,   105,    91,    94,    93,    97,    91,    97,
      42,   212,    56,   214,    81,    55,   100,   119,   120,   343,
     122,   105,    47,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    41,   139,   238,   141,
     404,    50,   144,   145,    87,   147,    55,    35,   151,    81,
     153,    95,    57,   155,    97,   154,   158,   159,   422,   423,
      85,    86,    59,   147,    90,    64,    96,    91,    91,     5,
     154,     7,     8,    99,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    89,    97,    19,
      20,    21,    22,     5,    22,   309,     8,   200,    10,    11,
      12,    13,    14,    15,    99,    17,    18,    19,    20,    21,
      22,   213,    22,   314,    47,    32,   317,   216,    51,    92,
      56,   151,    90,   153,    97,    42,    56,    32,    56,   213,
      30,    99,   216,    35,    92,    68,    69,    50,   240,    97,
      92,    55,   244,    92,    56,    97,    56,    74,    97,    92,
      56,    92,    85,    86,    97,    88,    92,    19,    20,    21,
      22,   362,   265,    92,    95,    80,    97,   270,    97,   272,
      95,   273,    97,    61,    11,   277,    54,   276,    53,   209,
     279,   283,   281,   285,    38,   287,    40,    91,    10,   273,
       5,    45,   276,    50,    56,   279,    73,   281,    52,    16,
      17,    18,    19,    20,    21,    22,    60,   309,    24,    25,
      26,    27,    96,   316,     4,    89,    70,    56,    72,    73,
      89,    10,     5,     5,    37,   324,    57,   428,    82,    83,
      94,    17,    18,    19,    20,    21,    22,    92,    61,    56,
     324,    84,   452,   346,    46,   347,    97,    91,     5,    37,
      37,   354,    63,    88,   356,    97,    75,    91,    94,    37,
      61,   363,    43,    10,   366,    35,    92,    76,     3,   371,
      56,    65,   356,    97,   377,     5,    39,    91,    13,   363,
      65,    37,   366,    91,    96,    77,    37,    71,    65,    37,
      97,    97,    66,    97,   396,     8,   398,    97,   145,    49,
     240,   354,   404,   406,   238,   404,   196,   409,   410,     2,
     287,   409,   414,   415,   398,   153,   283,   373,   467,   480,
     422,   423,   372,   422,   423,   489,   410,   430,   358,   156,
     414,   415,    67,    68,    69,   216,   398,   396,   440,   402,
     414,   144,   281,    78,   204,   471,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   457,   440,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   467,    -1,    -1,    -1,   471,
      -1,    -1,    -1,   457,    -1,    -1,    -1,    -1,   480,    -1,
     115,    -1,   412,   467,    -1,    -1,    -1,   471,   123,   124,
     125,   126,   127,   128,   129,   130,   480,   132,   133,   134,
     135,   136,   137,    -1,    -1,   140,    -1,    -1,   143,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   449,
      -1,   156,    -1,   453,   454,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   468,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     5,    -1,    -1,    -1,     9,    -1,    -1,    -1,   489,
      -1,    -1,    16,    17,    18,    19,    -1,    -1,    -1,   204,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    39,    40,    -1,    42,    43,
      44,    45,    46,    -1,    48,    49,    -1,    -1,    -1,    53,
      54,    -1,    56,   238,    58,    59,    60,    61,    -1,    -1,
      64,    65,    66,    67,    -1,    -1,    -1,    71,    72,    -1,
      -1,    75,    76,    77,    78,    79,    80,    81,    -1,    -1,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,
      -1,    -1,    -1,   278,    98,    -1,    -1,   282,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   290,    -1,   292,    -1,    -1,
      -1,     5,    -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    18,   310,   311,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    39,    40,    -1,    42,    43,
      44,    45,    46,    -1,    48,    49,    -1,    -1,    -1,    53,
      54,    -1,    56,    -1,    58,    59,    60,    61,    -1,    -1,
      64,    65,    66,    67,    -1,    -1,    -1,    71,    72,    -1,
     365,    75,    76,    77,    78,    79,    80,    81,    -1,    -1,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,
       5,    -1,     7,     8,    98,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,     5,    -1,
      -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,   424,
      -1,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    56,    39,    40,    -1,    42,    43,    44,    45,    46,
      -1,    48,    49,    -1,    -1,    -1,    53,    54,    -1,    56,
      -1,    58,    59,    60,    61,    -1,    -1,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    -1,    92,    75,    76,
      77,    78,    79,    80,    81,     5,    -1,    84,    -1,     9,
      -1,    -1,    -1,    -1,    91,    -1,    16,    17,    18,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    39,
      40,    -1,    42,    43,    44,    45,    46,    -1,    48,    49,
      -1,    -1,    -1,    53,    54,    -1,    56,    -1,    58,    59,
      60,    61,    -1,    -1,    64,    65,    66,    67,    -1,    -1,
      -1,    71,    72,    -1,    -1,    75,    76,    77,    78,    79,
      80,    81,     5,    -1,    84,    -1,     9,    -1,    11,    -1,
      -1,    91,    -1,    16,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    39,    40,    -1,    42,
      43,    44,    45,    46,    -1,    48,    49,    -1,    -1,    -1,
      53,    54,    -1,    56,    -1,    58,    59,    60,    61,    -1,
      -1,    64,    65,    66,    67,    -1,    -1,    -1,    71,    72,
      -1,    -1,    75,    76,    77,    78,    79,    80,    81,     5,
      -1,    84,    -1,     9,    -1,    -1,    -1,    -1,    91,    -1,
      16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    39,    40,    -1,    42,    43,    44,    45,
      46,    -1,    48,    49,    -1,    -1,    -1,    53,    54,    -1,
      56,    -1,    58,    59,    60,    61,    -1,    -1,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    72,    -1,     5,    75,
      76,    77,    78,    79,    80,    81,    -1,    -1,    84,    16,
      17,    18,    -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    40,    -1,    42,    43,    44,    45,    46,
      -1,    -1,    49,    -1,    -1,    -1,    53,    54,    -1,    56,
      -1,    -1,    59,    60,    61,    -1,    -1,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    -1,     5,    75,    76,
      77,    78,    79,    80,    81,    -1,    -1,    84,    16,    17,
      18,    -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    39,    40,    -1,    42,    43,    44,    45,    46,    -1,
      -1,    49,    -1,    -1,    -1,    53,    54,    -1,    56,    -1,
       5,    59,    60,    61,    -1,    -1,    64,    65,    66,    67,
      -1,    16,    -1,    71,    72,    -1,    -1,    75,    76,    77,
      78,    79,    80,    81,    -1,    -1,    84,    -1,    33,    34,
      35,    36,    37,    91,    39,    40,    -1,    42,    43,    44,
      45,    46,    -1,    -1,    49,    -1,    -1,    -1,    53,    54,
      -1,    56,    -1,     5,    59,    60,    -1,    -1,    -1,    64,
      65,    66,    67,    -1,    16,    -1,    71,    72,    -1,    -1,
      75,    76,    77,    78,    79,    80,    81,    -1,    -1,    84,
      -1,    33,    34,    35,    36,    37,    91,    39,    40,    -1,
      42,    43,    44,    45,    46,    -1,    -1,    49,    -1,    -1,
      -1,    53,    54,    -1,    56,    -1,    -1,    59,    60,    -1,
      -1,    -1,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    -1,    -1,    75,    76,    77,    78,    79,    80,    81,
      -1,    -1,    84,    -1,    -1,     5,    -1,     7,     8,    91,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,     5,    -1,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,
      -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      90,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    39,    40,    87,    42,    43,    44,    45,
      46,    -1,    -1,    49,    -1,    -1,    -1,    53,    54,    -1,
      56,     5,    -1,    59,    60,    61,    -1,    11,    64,    65,
      66,    67,    16,    -1,    -1,    71,    72,    -1,    -1,    75,
      76,    77,    78,    79,    80,    81,    -1,    -1,    84,    33,
      34,    35,    36,    37,    -1,    39,    40,    -1,    42,    43,
      44,    45,    46,    -1,    -1,    49,    -1,    -1,    -1,    53,
      54,    -1,    56,     5,    -1,    59,    60,    -1,    -1,    -1,
      64,    65,    66,    67,    16,    -1,    -1,    71,    72,    -1,
      -1,    75,    76,    77,    78,    79,    80,    81,    -1,    -1,
      84,    33,    34,    35,    36,    37,    -1,    39,    40,    -1,
      42,    43,    44,    45,    46,    -1,    -1,    49,    -1,    -1,
      -1,    53,    54,    -1,    56,     5,    -1,    59,    60,    -1,
      -1,    -1,    64,    65,    66,    67,    16,    -1,    -1,    71,
      72,    -1,    -1,    75,    76,    77,    78,    79,    80,    81,
      -1,    -1,    84,    33,    34,    35,    36,    37,    -1,    39,
      40,    -1,    42,    43,    44,    45,    46,    -1,    -1,    49,
      -1,    -1,    -1,    53,    54,    -1,    56,     5,    -1,    59,
      60,    -1,    -1,    -1,    64,    65,    66,    67,    16,    -1,
      -1,    71,    72,    -1,    -1,    75,    76,    77,    78,    79,
      80,    81,    -1,    -1,    84,    33,    34,    35,    36,    37,
      -1,    39,    40,    -1,    42,    43,    44,    45,    46,    -1,
      -1,    49,    -1,    -1,    -1,    53,    54,    -1,    56,     5,
      -1,    59,    60,    -1,    -1,    -1,    64,    65,    66,    67,
      16,    -1,    -1,    71,    72,    -1,    -1,    75,    76,    77,
      78,    79,    80,    81,    -1,    -1,    84,    33,    34,    35,
      36,    37,    -1,    39,    40,    -1,    42,    43,    44,    45,
      46,    -1,    -1,    49,    -1,    -1,    -1,    53,    54,    -1,
      56,    -1,    -1,    59,    60,    -1,    -1,    -1,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    72,    -1,    -1,    75,
      76,    77,    78,    79,    80,    81,    -1,     5,    84,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,    24,    25,    26,    27,   101,    38,    40,    45,    52,
      60,    70,    72,    73,    82,    83,   102,   128,   140,   144,
     147,   149,   150,   151,   152,   153,   154,   155,   156,     5,
      16,    33,    34,    35,    36,    37,    39,    40,    42,    43,
      44,    45,    46,    49,    53,    54,    56,    59,    60,    64,
      65,    66,    67,    71,    72,    75,    76,    77,    78,    79,
      80,    81,    84,   103,   113,   127,   128,     9,    17,    18,
      29,    30,    31,    32,    40,    48,    58,    61,    91,   104,
     106,   111,   112,   113,   121,   122,   123,   124,   125,   126,
     127,   105,   107,   127,   177,     0,    67,    78,   120,   138,
      35,    55,    59,   112,   127,    35,   112,    19,   106,   119,
     157,   169,   184,    59,   112,    91,   106,   106,   106,    91,
      89,   106,     5,     7,     8,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    56,    64,
       6,    93,   115,    10,    91,    99,   126,    35,   112,   127,
     124,    50,   112,    55,    50,    55,    97,   124,    74,    11,
      91,   106,   114,   116,   119,   129,   178,   108,   127,   179,
     177,    92,   127,   106,   106,   106,   106,   106,   106,   106,
     106,    17,    18,   110,   111,   106,   106,   106,   106,   106,
     106,     9,    61,   127,   106,   119,   127,    36,    44,   118,
     106,   179,   107,   112,    73,   124,   155,    34,    42,    53,
     120,   126,   146,    80,   146,    35,    79,    91,   112,   113,
     116,   170,   171,   172,   174,   175,   185,   127,   157,   127,
     148,   183,   127,   130,   181,   117,    92,    92,    97,    92,
      97,    90,   110,   110,     5,     8,    10,    11,    12,    13,
      14,    15,    17,    18,    19,    20,    21,    22,    56,    61,
     118,    87,   109,   120,    92,   129,   184,    54,    53,   126,
     124,   112,   124,    91,   171,    41,    57,     5,    87,    97,
     158,    50,    10,    97,   158,    96,    12,    97,   155,   114,
      89,   108,     4,   127,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,     9,    61,    89,
      10,    94,   120,   139,     5,   120,   141,     5,   120,   145,
     112,   129,   173,    37,    57,   170,   127,   106,   170,    47,
      51,    68,    69,    85,    86,   120,   159,   160,   161,   162,
     164,   165,   189,   185,   106,   148,   127,    94,   130,    92,
     106,   106,    61,   177,   106,   106,    84,   124,    46,   120,
     142,   124,    97,    91,   170,    62,    37,    37,     5,    63,
     168,    88,    97,   158,     9,    61,   120,   134,   127,   131,
     182,    90,    90,   109,    95,   112,   126,    75,   143,   124,
     112,   176,   187,   106,   112,   180,    94,    91,    37,     5,
     127,   164,   159,    61,    43,   120,   135,    10,    95,    97,
      35,    92,    76,    92,    97,    97,   182,    65,   180,    91,
       5,   168,    17,    18,    91,   113,   121,   133,    39,   120,
     136,    98,   106,   132,   131,   112,   126,   176,   112,    95,
      37,    65,    91,   113,   121,   113,   121,   106,   124,    71,
     120,   137,    96,    77,   112,   163,   186,    37,    65,    92,
     126,   119,   132,   126,    42,   126,    92,    97,   112,   166,
     188,    37,    97,    97,   163,    42,    81,   126,   167,    92,
      97,   188,   132,   132,    66,   166,    92,    97,    97,     8,
     132,   132,   167,    49
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  Parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,    64,   261,   262,   263,
      61,    60,    62,   264,   265,   266,   267,    43,    45,    42,
      47,    37,    94,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   123,
     125,    40,    41,    46,    91,    93,    58,    44,    63,    59
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Parser::yyr1_[] =
  {
         0,   100,   101,   101,   101,   101,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   103,   103,
     104,   105,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   107,   107,   108,   109,
     109,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   111,
     111,   111,   111,   111,   112,   112,   113,   113,   114,   114,
     114,   115,   115,   115,   117,   116,   118,   118,   118,   119,
     120,   121,   121,   121,   121,   121,   122,   123,   124,   125,
     126,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   128,   128,   129,   130,   131,
     131,   131,   132,   132,   133,   133,   133,   133,   133,   133,
     133,   134,   134,   134,   135,   135,   136,   136,   137,   137,
     138,   138,   139,   139,   140,   141,   141,   142,   142,   143,
     143,   144,   145,   145,   146,   146,   146,   146,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   154,   155,   155,
     156,   156,   157,   157,   158,   158,   159,   159,   159,   159,
     159,   160,   161,   162,   163,   163,   164,   164,   165,   165,
     165,   165,   166,   166,   167,   167,   168,   168,   169,   170,
     170,   170,   170,   171,   171,   171,   171,   172,   173,   173,
     174,   174,   175,   176,   177,   177,   177,   177,   178,   178,
     178,   179,   179,   179,   180,   180,   181,   181,   182,   182,
     183,   183,   184,   184,   185,   185,   186,   186,   187,   187,
     188,   188,   189,   189
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     4,     5,     3,     6,     7,     4,     7,     1,     4,
       1,     1,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     3,     1,
       1,     1,     3,     3,     3,     4,     4,     4,     1,     1,
       1,     0,     2,     2,     0,     4,     0,     1,     1,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     8,     6,     7,     9,
       9,     1,     1,     1,     1,     2,     2,     1,     2,     2,
       3,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       1,     1,     3,     1,     8,     2,     1,     2,     1,     3,
       0,     6,     2,     1,     1,     2,     2,     2,     1,     5,
       3,     3,     5,     3,     3,     3,     4,     4,     2,     7,
       4,     9,     1,     1,     0,     2,     0,     1,     1,     1,
       1,     3,     5,     7,     2,     2,     8,     9,     1,     1,
       1,     1,     6,     2,     1,     1,     0,     3,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     6,     1,     1,
       5,     4,     6,     5,     0,     1,     2,     3,     0,     1,
       3,     0,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Parser::yytname_[] =
  {
    "$end", "error", "$undefined", "MIN", "IN", "AS", "'@'", "OR", "AND",
  "NOT", "'='", "'<'", "'>'", "GTEQ", "LSEQ", "NEQ", "BETWEEN", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'^'", "MAX", "AQL_STATEMENT",
  "AFL_STATEMENT", "AFL_EXPRESSION", "AFL_MODULE", "LEXICAL_ERROR", "REAL",
  "STRING", "BOOLEAN", "INTEGER", "IDENTIFIER", "ALL", "ARRAY", "ASC",
  "BY", "CANCEL", "COMPRESSION", "CREATE", "CROSS", "CURRENT", "DEFAULT",
  "DESC", "DROP", "ERRORS", "FIXED", "FN", "FOLLOWING", "FROM", "GROUP",
  "INSERT", "INSTANCE", "INSTANCES", "INTO", "IS", "JOIN", "LET",
  "LIBRARY", "LOAD", "NULL_VALUE", "ON", "ORDER", "OVER", "PARTITION",
  "PRECEDING", "QUERY", "REDIMENSION", "REGRID", "RENAME", "RESERVE",
  "SAVE", "SELECT", "SET", "SHADOW", "START", "STEP", "TEMP", "THIN", "TO",
  "UNBOUND", "UNLOAD", "UPDATE", "USING", "VARIABLE", "CICULAR", "WHERE",
  "WINDOW", "'{'", "'}'", "'('", "')'", "'.'", "'['", "']'", "':'", "','",
  "'?'", "';'", "$accept", "start", "aql_statement", "afl_statement",
  "afl_expression", "afl_module", "exp", "binding", "parameter",
  "where_group", "reduced_exp", "atomic_exp", "reference", "application",
  "operand", "version_clause", "select_exp", "@1", "order", "asterisk",
  "blank", "constant", "constant_null", "constant_real", "constant_string",
  "constant_boolean", "constant_integer", "identifier",
  "create_array_statement", "schema", "attribute", "dimension", "dexp",
  "default_value", "nullable", "default", "compression", "reserve", "temp",
  "cells", "load_array_statement", "load_format", "load_errors",
  "load_shadow", "save_array_statement", "save_format", "instances",
  "update_array_statement", "update", "drop_array_statement",
  "rename_array_statement", "load_library_statement",
  "unload_library_statement", "cancel_query_statement",
  "insert_array_statement", "select_array_statement",
  "select_into_statement", "select_item", "where_clause", "grw_as_clause",
  "group_by_clause", "redimension_clause", "regrid_clause",
  "regrid_dimension", "window_clause", "window_noise", "window_dimension",
  "window_value", "order_by_clause", "named_exp", "reference_input",
  "array_source", "array_literal", "array_literal_schema", "joined_input",
  "thin_clause", "thin_dimension", "bindings", "operands", "parameters",
  "references", "attributes", "dimensions", "updates", "select_items",
  "reference_inputs", "regrid_dimensions", "thin_dimensions",
  "window_dimensions", "window_clauses", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
       101,     0,    -1,    24,   102,    -1,    25,   103,    -1,    26,
     104,    -1,    27,   105,    -1,   128,    -1,   140,    -1,   144,
      -1,   149,    -1,   150,    -1,   151,    -1,   152,    -1,   153,
      -1,   154,    -1,   147,    -1,   155,    -1,   156,    -1,   128,
      -1,   113,    -1,   106,    -1,   177,    -1,   111,    -1,    17,
     106,    -1,    18,   106,    -1,   106,    17,   106,    -1,   106,
      18,   106,    -1,   106,    19,   106,    -1,   106,    22,   106,
      -1,   106,    10,   106,    -1,   106,    20,   106,    -1,   106,
      21,   106,    -1,   106,    11,   106,    -1,   106,    12,   106,
      -1,   106,    15,   106,    -1,   106,    14,   106,    -1,   106,
      13,   106,    -1,     9,   106,    -1,   106,     8,   106,    -1,
     106,     7,   106,    -1,   106,    56,    61,    -1,   106,    56,
       9,    61,    -1,   106,    16,   110,     8,   110,    -1,   106,
       5,   127,    -1,    58,    89,   177,    90,     4,   106,    -1,
      48,    91,   179,    92,    89,   106,    90,    -1,   127,    10,
     106,   109,    -1,   127,    91,   179,    92,    10,   106,   109,
      -1,   127,    -1,    87,    89,   177,    90,    -1,   120,    -1,
     111,    -1,    17,   110,    -1,    18,   110,    -1,   110,    17,
     110,    -1,   110,    18,   110,    -1,   110,    19,   110,    -1,
     110,    22,   110,    -1,   110,    10,   110,    -1,   110,    20,
     110,    -1,   110,    21,   110,    -1,   110,    11,   110,    -1,
     110,    12,   110,    -1,   110,    15,   110,    -1,   110,    14,
     110,    -1,   110,    13,   110,    -1,   110,    56,    61,    -1,
     110,    56,     9,    61,    -1,   110,     5,   127,    -1,   121,
      -1,   112,    -1,   113,    -1,   113,    64,   127,    -1,    91,
     106,    92,    -1,   127,   115,   118,    -1,   127,    93,   127,
     118,    -1,   127,    91,   119,    92,    -1,   127,    91,   178,
      92,    -1,   106,    -1,   129,    -1,   116,    -1,    -1,     6,
     106,    -1,     6,   119,    -1,    -1,    91,   117,   155,    92,
      -1,    -1,    36,    -1,    44,    -1,    19,    -1,    -1,   122,
      -1,   123,    -1,   124,    -1,   125,    -1,   126,    -1,    61,
      -1,    29,    -1,    30,    -1,    31,    -1,    32,    -1,    33,
      -1,    35,    -1,     5,    -1,    36,    -1,    16,    -1,    39,
      -1,    40,    -1,    44,    -1,    43,    -1,    56,    -1,    71,
      -1,    78,    -1,    84,    -1,    34,    -1,    37,    -1,    42,
      -1,    45,    -1,    46,    -1,    49,    -1,    53,    -1,    54,
      -1,    59,    -1,    60,    -1,    64,    -1,    65,    -1,    66,
      -1,    67,    -1,    72,    -1,    75,    -1,    76,    -1,    77,
      -1,    79,    -1,    80,    -1,    81,    -1,    40,   138,    35,
     112,   129,    -1,    40,   138,    35,   112,   129,   139,    84,
     112,    -1,    11,   181,    12,    94,   182,    95,    -1,   127,
      96,   127,   134,   135,   136,   137,    -1,   127,    10,   132,
      96,   132,    97,   132,    97,   132,    -1,   127,    10,   132,
      96,   119,    97,   132,    97,   132,    -1,   127,    -1,   106,
      -1,    98,    -1,   121,    -1,    17,   121,    -1,    18,   121,
      -1,   113,    -1,    17,   113,    -1,    18,   113,    -1,    91,
     106,    92,    -1,    61,    -1,     9,    61,    -1,   120,    -1,
      43,   133,    -1,   120,    -1,    39,   124,    -1,   120,    -1,
      71,   126,    -1,   120,    -1,    78,    -1,   120,    -1,    94,
     106,    95,    -1,   120,    -1,    60,   112,    50,   146,   124,
     141,   142,   143,    -1,     5,   124,    -1,   120,    -1,    46,
     126,    -1,   120,    -1,    75,    35,   112,    -1,    -1,    72,
     112,    55,   146,   124,   145,    -1,     5,   124,    -1,   120,
      -1,   126,    -1,    53,   126,    -1,    34,    54,    -1,    42,
      53,    -1,   120,    -1,    83,   112,    74,   183,   158,    -1,
     127,    10,   106,    -1,    45,    35,   112,    -1,    70,    35,
     112,    80,   112,    -1,    60,    59,   124,    -1,    82,    59,
     124,    -1,    38,    67,   126,    -1,    52,    55,   127,   124,
      -1,    52,    55,   127,   155,    -1,    73,   184,    -1,    73,
     184,    50,   185,   158,   159,   168,    -1,    73,   184,    55,
     127,    -1,    73,   184,    55,   127,    50,   185,   158,   159,
     168,    -1,   169,    -1,   119,    -1,    -1,    87,   106,    -1,
      -1,   160,    -1,   161,    -1,   162,    -1,   189,    -1,    51,
      37,   180,    -1,    68,    37,    94,   182,    95,    -1,    69,
       5,    91,    65,    37,   186,    92,    -1,   112,   126,    -1,
     112,    42,    -1,   165,    88,     5,    91,    65,    37,   188,
      92,    -1,   165,    88,   127,     5,    91,    65,    37,   188,
      92,    -1,    85,    -1,    86,    -1,    47,    -1,   120,    -1,
     112,   167,    66,     8,   167,    49,    -1,   112,    42,    -1,
     126,    -1,    81,    -1,    -1,    63,    37,   180,    -1,   106,
      -1,   171,    -1,   171,     5,   127,    -1,   174,    -1,   175,
      -1,   112,    -1,   113,    -1,   172,    -1,   116,    -1,    35,
      91,   173,    97,   124,    92,    -1,   112,    -1,   129,    -1,
     170,    57,   170,    62,   106,    -1,   170,    41,    57,   170,
      -1,    79,   171,    37,    91,   187,    92,    -1,   112,    76,
     126,    77,   126,    -1,    -1,   107,    -1,   177,    99,    -1,
     177,    99,   107,    -1,    -1,   114,    -1,   178,    97,   114,
      -1,    -1,   108,    -1,   179,    97,   108,    -1,   112,    -1,
     180,    97,   112,    -1,   130,    -1,   181,    97,   130,    -1,
     131,    -1,   182,    97,   131,    -1,   148,    -1,   183,    97,
     148,    -1,   157,    -1,   184,    97,   157,    -1,   170,    -1,
     185,    97,   170,    -1,   163,    -1,   186,    97,   163,    -1,
     176,    -1,   187,    97,   176,    -1,   166,    -1,   188,    97,
     166,    -1,   164,    -1,   189,    97,   164,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Parser::yyprhs_[] =
  {
         0,     0,     3,     6,     9,    12,    15,    17,    19,    21,
      23,    25,    27,    29,    31,    33,    35,    37,    39,    41,
      43,    45,    47,    49,    52,    55,    59,    63,    67,    71,
      75,    79,    83,    87,    91,    95,    99,   103,   106,   110,
     114,   118,   123,   129,   133,   140,   148,   153,   161,   163,
     168,   170,   172,   175,   178,   182,   186,   190,   194,   198,
     202,   206,   210,   214,   218,   222,   226,   230,   235,   239,
     241,   243,   245,   249,   253,   257,   262,   267,   272,   274,
     276,   278,   279,   282,   285,   286,   291,   292,   294,   296,
     298,   299,   301,   303,   305,   307,   309,   311,   313,   315,
     317,   319,   321,   323,   325,   327,   329,   331,   333,   335,
     337,   339,   341,   343,   345,   347,   349,   351,   353,   355,
     357,   359,   361,   363,   365,   367,   369,   371,   373,   375,
     377,   379,   381,   383,   385,   387,   393,   402,   409,   417,
     427,   437,   439,   441,   443,   445,   448,   451,   453,   456,
     459,   463,   465,   468,   470,   473,   475,   478,   480,   483,
     485,   487,   489,   493,   495,   504,   507,   509,   512,   514,
     518,   519,   526,   529,   531,   533,   536,   539,   542,   544,
     550,   554,   558,   564,   568,   572,   576,   581,   586,   589,
     597,   602,   612,   614,   616,   617,   620,   621,   623,   625,
     627,   629,   633,   639,   647,   650,   653,   662,   672,   674,
     676,   678,   680,   687,   690,   692,   694,   695,   699,   701,
     703,   707,   709,   711,   713,   715,   717,   719,   726,   728,
     730,   736,   741,   748,   754,   755,   757,   760,   764,   765,
     767,   771,   772,   774,   778,   780,   784,   786,   790,   792,
     796,   798,   802,   804,   808,   810,   814,   816,   820,   822,
     826,   828,   832,   834
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   270,   270,   271,   272,   273,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   292,   293,
     297,   301,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   333,   334,   335,   339,   340,   344,   348,
     349,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   378,
     379,   380,   381,   382,   386,   387,   391,   392,   396,   397,
     398,   402,   403,   404,   408,   408,   413,   414,   415,   419,
     425,   431,   432,   433,   434,   435,   439,   443,   447,   451,
     455,   461,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   502,   503,   507,   511,   515,
     516,   517,   521,   522,   526,   527,   528,   529,   530,   531,
     532,   536,   537,   538,   542,   543,   547,   548,   552,   553,
     556,   557,   561,   562,   568,   582,   583,   587,   588,   592,
     593,   597,   604,   605,   609,   610,   611,   612,   613,   617,
     621,   625,   629,   633,   637,   641,   645,   646,   652,   656,
     663,   667,   674,   675,   679,   680,   684,   685,   686,   687,
     688,   692,   696,   700,   704,   705,   709,   715,   722,   723,
     724,   725,   729,   733,   740,   741,   745,   746,   750,   758,
     759,   760,   761,   765,   766,   767,   768,   772,   779,   780,
     784,   785,   789,   796,   810,   811,   812,   813,   817,   818,
     819,   823,   824,   825,   829,   830,   834,   835,   839,   840,
     844,   845,   849,   850,   854,   855,   859,   860,   864,   865,
     869,   870,   874,   875
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    21,     2,     2,
      91,    92,    19,    17,    97,    18,    93,    20,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    96,    99,
      11,    10,    12,    98,     6,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    94,     2,    95,    22,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    89,     2,    90,     2,     2,     2,     2,
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
       5,     7,     8,     9,    13,    14,    15,    16,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 1807;
  const int Parser::yynnts_ = 90;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 95;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 100;

  const unsigned int Parser::yyuser_token_number_max_ = 333;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 29 "parser/Parser.yy"
} } // scidb::parser

/* Line 1054 of lalr1.cc  */
#line 3468 "/home/gary/programmer/scidbtrunk/stage/build/src/query/parser/Parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 879 "parser/Parser.yy"

/****************************************************************************/
namespace scidb { namespace parser {
/****************************************************************************/

void Parser::error(const location_type& w,const string& s)
{
    _log.fail(SCIDB_LE_QUERY_PARSING_ERROR,w,s.c_str()); // Log a syntax error
}

/****************************************************************************/
}}
/****************************************************************************/

