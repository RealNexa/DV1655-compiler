// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 13 "parser.yy"

  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  
  BaseNode* root;
  extern int yylineno;

#line 54 "parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 127 "parser.tab.cc"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_goal: // goal
      case symbol_kind::S_main_class: // main_class
      case symbol_kind::S_n_class_declarations: // n_class_declarations
      case symbol_kind::S_class_declaration: // class_declaration
      case symbol_kind::S_n_var_declarations: // n_var_declarations
      case symbol_kind::S_var_declaration: // var_declaration
      case symbol_kind::S_n_method_declarations: // n_method_declarations
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_n_type_identifiers: // n_type_identifiers
      case symbol_kind::S_n2_type_identifiers: // n2_type_identifiers
      case symbol_kind::S_type_identifier: // type_identifier
      case symbol_kind::S_n_var_declarations_or_statements: // n_var_declarations_or_statements
      case symbol_kind::S_type: // type
      case symbol_kind::S_one_or_more_statements: // one_or_more_statements
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_else_case: // else_case
      case symbol_kind::S_n_statements: // n_statements
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_method_call1: // method_call1
      case symbol_kind::S_method_call2: // method_call2
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_identifier: // identifier
        value.YY_MOVE_OR_COPY< BaseNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_LB: // LB
      case symbol_kind::S_RB: // RB
      case symbol_kind::S_SC: // SC
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_TYPE_INT: // TYPE_INT
      case symbol_kind::S_TYPE_BOOLEAN: // TYPE_BOOLEAN
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_PRINTLN: // PRINTLN
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_LOGICAND: // LOGICAND
      case symbol_kind::S_LOGICOR: // LOGICOR
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_EQUAL: // EQUAL
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_ID: // ID
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_goal: // goal
      case symbol_kind::S_main_class: // main_class
      case symbol_kind::S_n_class_declarations: // n_class_declarations
      case symbol_kind::S_class_declaration: // class_declaration
      case symbol_kind::S_n_var_declarations: // n_var_declarations
      case symbol_kind::S_var_declaration: // var_declaration
      case symbol_kind::S_n_method_declarations: // n_method_declarations
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_n_type_identifiers: // n_type_identifiers
      case symbol_kind::S_n2_type_identifiers: // n2_type_identifiers
      case symbol_kind::S_type_identifier: // type_identifier
      case symbol_kind::S_n_var_declarations_or_statements: // n_var_declarations_or_statements
      case symbol_kind::S_type: // type
      case symbol_kind::S_one_or_more_statements: // one_or_more_statements
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_else_case: // else_case
      case symbol_kind::S_n_statements: // n_statements
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_method_call1: // method_call1
      case symbol_kind::S_method_call2: // method_call2
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_identifier: // identifier
        value.move< BaseNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_LB: // LB
      case symbol_kind::S_RB: // RB
      case symbol_kind::S_SC: // SC
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_TYPE_INT: // TYPE_INT
      case symbol_kind::S_TYPE_BOOLEAN: // TYPE_BOOLEAN
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_PRINTLN: // PRINTLN
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_LOGICAND: // LOGICAND
      case symbol_kind::S_LOGICOR: // LOGICOR
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_EQUAL: // EQUAL
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_ID: // ID
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_goal: // goal
      case symbol_kind::S_main_class: // main_class
      case symbol_kind::S_n_class_declarations: // n_class_declarations
      case symbol_kind::S_class_declaration: // class_declaration
      case symbol_kind::S_n_var_declarations: // n_var_declarations
      case symbol_kind::S_var_declaration: // var_declaration
      case symbol_kind::S_n_method_declarations: // n_method_declarations
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_n_type_identifiers: // n_type_identifiers
      case symbol_kind::S_n2_type_identifiers: // n2_type_identifiers
      case symbol_kind::S_type_identifier: // type_identifier
      case symbol_kind::S_n_var_declarations_or_statements: // n_var_declarations_or_statements
      case symbol_kind::S_type: // type
      case symbol_kind::S_one_or_more_statements: // one_or_more_statements
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_else_case: // else_case
      case symbol_kind::S_n_statements: // n_statements
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_method_call1: // method_call1
      case symbol_kind::S_method_call2: // method_call2
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_identifier: // identifier
        value.copy< BaseNode * > (that.value);
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_LB: // LB
      case symbol_kind::S_RB: // RB
      case symbol_kind::S_SC: // SC
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_TYPE_INT: // TYPE_INT
      case symbol_kind::S_TYPE_BOOLEAN: // TYPE_BOOLEAN
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_PRINTLN: // PRINTLN
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_LOGICAND: // LOGICAND
      case symbol_kind::S_LOGICOR: // LOGICOR
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_EQUAL: // EQUAL
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_ID: // ID
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_goal: // goal
      case symbol_kind::S_main_class: // main_class
      case symbol_kind::S_n_class_declarations: // n_class_declarations
      case symbol_kind::S_class_declaration: // class_declaration
      case symbol_kind::S_n_var_declarations: // n_var_declarations
      case symbol_kind::S_var_declaration: // var_declaration
      case symbol_kind::S_n_method_declarations: // n_method_declarations
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_n_type_identifiers: // n_type_identifiers
      case symbol_kind::S_n2_type_identifiers: // n2_type_identifiers
      case symbol_kind::S_type_identifier: // type_identifier
      case symbol_kind::S_n_var_declarations_or_statements: // n_var_declarations_or_statements
      case symbol_kind::S_type: // type
      case symbol_kind::S_one_or_more_statements: // one_or_more_statements
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_else_case: // else_case
      case symbol_kind::S_n_statements: // n_statements
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_method_call1: // method_call1
      case symbol_kind::S_method_call2: // method_call2
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_identifier: // identifier
        value.move< BaseNode * > (that.value);
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_LB: // LB
      case symbol_kind::S_RB: // RB
      case symbol_kind::S_SC: // SC
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_TYPE_INT: // TYPE_INT
      case symbol_kind::S_TYPE_BOOLEAN: // TYPE_BOOLEAN
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_PRINTLN: // PRINTLN
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_LOGICAND: // LOGICAND
      case symbol_kind::S_LOGICOR: // LOGICOR
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_EQUAL: // EQUAL
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_ID: // ID
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_goal: // goal
      case symbol_kind::S_main_class: // main_class
      case symbol_kind::S_n_class_declarations: // n_class_declarations
      case symbol_kind::S_class_declaration: // class_declaration
      case symbol_kind::S_n_var_declarations: // n_var_declarations
      case symbol_kind::S_var_declaration: // var_declaration
      case symbol_kind::S_n_method_declarations: // n_method_declarations
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_n_type_identifiers: // n_type_identifiers
      case symbol_kind::S_n2_type_identifiers: // n2_type_identifiers
      case symbol_kind::S_type_identifier: // type_identifier
      case symbol_kind::S_n_var_declarations_or_statements: // n_var_declarations_or_statements
      case symbol_kind::S_type: // type
      case symbol_kind::S_one_or_more_statements: // one_or_more_statements
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_else_case: // else_case
      case symbol_kind::S_n_statements: // n_statements
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_method_call1: // method_call1
      case symbol_kind::S_method_call2: // method_call2
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_identifier: // identifier
        yylhs.value.emplace< BaseNode * > ();
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_LB: // LB
      case symbol_kind::S_RB: // RB
      case symbol_kind::S_SC: // SC
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_TYPE_INT: // TYPE_INT
      case symbol_kind::S_TYPE_BOOLEAN: // TYPE_BOOLEAN
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_PRINTLN: // PRINTLN
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_LOGICAND: // LOGICAND
      case symbol_kind::S_LOGICOR: // LOGICOR
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_EQUAL: // EQUAL
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_ID: // ID
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // root: goal
#line 44 "parser.yy"
                 {root = yystack_[0].value.as < BaseNode * > ();}
#line 853 "parser.tab.cc"
    break;

  case 3: // goal: main_class n_class_declarations "end of file"
#line 47 "parser.yy"
                                           {
                          yylhs.value.as < BaseNode * > () = new GoalNode("GOAL", "", yylineno);
                          yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[2].value.as < BaseNode * > ());
                          yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[1].value.as < BaseNode * > ());
                          }
#line 863 "parser.tab.cc"
    break;

  case 4: // main_class: PUBLIC CLASS identifier LCB PUBLIC STATIC VOID MAIN LP STRING LB RB identifier RP LCB one_or_more_statements RCB RCB
#line 54 "parser.yy"
                                                                                                                                 {
  yylhs.value.as < BaseNode * > () = new MainClassNode("MAIN_CLASS", "", yylineno);
  yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[15].value.as < BaseNode * > ());
  yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[5].value.as < BaseNode * > ());
  yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[2].value.as < BaseNode * > ());
  /*$$->children.push_back($17);*/
}
#line 875 "parser.tab.cc"
    break;

  case 5: // n_class_declarations: %empty
#line 63 "parser.yy"
                             {
                   yylhs.value.as < BaseNode * > () = new NonMainClassNode("NON_MAIN_CLASSES", "", yylineno);
                }
#line 883 "parser.tab.cc"
    break;

  case 6: // n_class_declarations: n_class_declarations class_declaration
#line 66 "parser.yy"
                                                    {
              yylhs.value.as < BaseNode * > () = yystack_[1].value.as < BaseNode * > ();
              yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[0].value.as < BaseNode * > ());
            }
#line 892 "parser.tab.cc"
    break;

  case 7: // class_declaration: CLASS identifier LCB n_var_declarations n_method_declarations RCB
#line 72 "parser.yy"
                                                                                     {
                yylhs.value.as < BaseNode * > () = new ClassDeclarationNode("CLASS_DECLARATION", "", yylineno);
                yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[4].value.as < BaseNode * > ());
                yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[2].value.as < BaseNode * > ());
                yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[1].value.as < BaseNode * > ());
}
#line 903 "parser.tab.cc"
    break;

  case 8: // n_var_declarations: %empty
#line 80 "parser.yy"
                           {
                  yylhs.value.as < BaseNode * > () = new VarDeclarationsNode("VAR_DECLARATIONS", "", yylineno);
                }
#line 911 "parser.tab.cc"
    break;

  case 9: // n_var_declarations: n_var_declarations var_declaration
#line 83 "parser.yy"
                                                  {
              yylhs.value.as < BaseNode * > () = yystack_[1].value.as < BaseNode * > ();
              yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[0].value.as < BaseNode * > ());
            }
#line 920 "parser.tab.cc"
    break;

  case 10: // var_declaration: type identifier SC
#line 88 "parser.yy"
                                    {
                  yylhs.value.as < BaseNode * > () = new TypeIdNode("TYPEID", "", yylineno);
                  yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[2].value.as < BaseNode * > ());
                  yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[1].value.as < BaseNode * > ());
                }
#line 930 "parser.tab.cc"
    break;

  case 11: // n_method_declarations: %empty
#line 95 "parser.yy"
                              {
                  yylhs.value.as < BaseNode * > () = new MethodDeclarationsNode("METHOD_DECLARATIONS", "", yylineno);
                }
#line 938 "parser.tab.cc"
    break;

  case 12: // n_method_declarations: n_method_declarations method_declaration
#line 98 "parser.yy"
                                                       {
              yylhs.value.as < BaseNode * > () = yystack_[1].value.as < BaseNode * > ();
              yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[0].value.as < BaseNode * > ());
            }
#line 947 "parser.tab.cc"
    break;

  case 13: // method_declaration: PUBLIC type identifier LP n_type_identifiers RP LCB n_var_declarations_or_statements RETURN expression SC RCB
#line 103 "parser.yy"
                                                                                                                                  {
        yylhs.value.as < BaseNode * > () = new MethodDeclarationNode("METHOD_DECLARATION", "", yylineno);
        yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[10].value.as < BaseNode * > ());
        yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[9].value.as < BaseNode * > ());
        yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[7].value.as < BaseNode * > ());
        yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[4].value.as < BaseNode * > ());
        yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[2].value.as < BaseNode * > ());
      }
#line 960 "parser.tab.cc"
    break;

  case 14: // n_type_identifiers: %empty
#line 112 "parser.yy"
                           {
                  yylhs.value.as < BaseNode * > () = new ParametersNode("PARAMETERS", "", yylineno);
                }
#line 968 "parser.tab.cc"
    break;

  case 15: // n_type_identifiers: type_identifier
#line 115 "parser.yy"
                              {
              yylhs.value.as < BaseNode * > () = new ParametersNode("PARAMETERS", "", yylineno);
              yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[0].value.as < BaseNode * > ());
            }
#line 977 "parser.tab.cc"
    break;

  case 16: // n_type_identifiers: type_identifier COMMA n2_type_identifiers
#line 119 "parser.yy"
                                                        {
                          yylhs.value.as < BaseNode * > () = yystack_[0].value.as < BaseNode * > ();
                          yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[2].value.as < BaseNode * > ());
                          }
#line 986 "parser.tab.cc"
    break;

  case 17: // n2_type_identifiers: type_identifier
#line 125 "parser.yy"
                                     {
            yylhs.value.as < BaseNode * > () = new ParametersNode("PARAMETERS", "", yylineno);
            yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[0].value.as < BaseNode * > ());
}
#line 995 "parser.tab.cc"
    break;

  case 18: // n2_type_identifiers: type_identifier COMMA n2_type_identifiers
#line 129 "parser.yy"
                                            {
            yylhs.value.as < BaseNode * > () = yystack_[0].value.as < BaseNode * > ();
            yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[2].value.as < BaseNode * > ());
}
#line 1004 "parser.tab.cc"
    break;

  case 19: // type_identifier: type identifier
#line 135 "parser.yy"
                                 {
    yylhs.value.as < BaseNode * > () = new ParameterNode("PARAMETER", "", yylineno);
    yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[1].value.as < BaseNode * > ());
    yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[0].value.as < BaseNode * > ());
  }
#line 1014 "parser.tab.cc"
    break;

  case 20: // n_var_declarations_or_statements: %empty
#line 142 "parser.yy"
                                         {
                  yylhs.value.as < BaseNode * > () = new BodyNode("BODY", "", yylineno);
                }
#line 1022 "parser.tab.cc"
    break;

  case 21: // n_var_declarations_or_statements: n_var_declarations_or_statements var_declaration
#line 145 "parser.yy"
                                                                  {
                  yylhs.value.as < BaseNode * > () = yystack_[1].value.as < BaseNode * > ();
                  yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[0].value.as < BaseNode * > ());
                }
#line 1031 "parser.tab.cc"
    break;

  case 22: // n_var_declarations_or_statements: n_var_declarations_or_statements statement
#line 149 "parser.yy"
                                                             {
                  yylhs.value.as < BaseNode * > () = yystack_[1].value.as < BaseNode * > ();
                  yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[0].value.as < BaseNode * > ());
                }
#line 1040 "parser.tab.cc"
    break;

  case 23: // type: TYPE_INT LB RB
#line 155 "parser.yy"
                     {
        yylhs.value.as < BaseNode * > () = new TypeIntListNode("TYPE_INT_LIST", "", yylineno);
      }
#line 1048 "parser.tab.cc"
    break;

  case 24: // type: TYPE_BOOLEAN
#line 158 "parser.yy"
                     {
        yylhs.value.as < BaseNode * > () = new TypeBooleanNode("TYPE_BOOLEAN", "", yylineno);
      }
#line 1056 "parser.tab.cc"
    break;

  case 25: // type: TYPE_INT
#line 161 "parser.yy"
                 {
        yylhs.value.as < BaseNode * > () = new TypeIntNode("TYPE_INT", "", yylineno);
      }
#line 1064 "parser.tab.cc"
    break;

  case 26: // type: identifier
#line 164 "parser.yy"
                   {
        yylhs.value.as < BaseNode * > () = new TypeCustomNode("TYPE_CUSTOM", yystack_[0].value.as < BaseNode * > ()->value, yylineno);
        //$$->children.push_back($1);
      }
#line 1073 "parser.tab.cc"
    break;

  case 27: // one_or_more_statements: n_statements statement
#line 170 "parser.yy"
                                               {
  yylhs.value.as < BaseNode * > () = yystack_[1].value.as < BaseNode * > ();
  yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[0].value.as < BaseNode * > ());
}
#line 1082 "parser.tab.cc"
    break;

  case 28: // statement: LCB n_statements RCB
#line 176 "parser.yy"
                                {
                yylhs.value.as < BaseNode * > () = yystack_[1].value.as < BaseNode * > ();
                }
#line 1090 "parser.tab.cc"
    break;

  case 29: // statement: IF LP expression RP statement else_case
#line 179 "parser.yy"
                                                    {
                  yylhs.value.as < BaseNode * > () = new IfNode("IF", "", yylineno);
                  yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[3].value.as < BaseNode * > ());
                  yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[1].value.as < BaseNode * > ());
                  yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[0].value.as < BaseNode * > ());
                }
#line 1101 "parser.tab.cc"
    break;

  case 30: // statement: WHILE LP expression RP statement
#line 185 "parser.yy"
                                             {
                  yylhs.value.as < BaseNode * > () = new WhileNode("WHILE", "", yylineno);
                  yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[2].value.as < BaseNode * > ());
                  yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[0].value.as < BaseNode * > ());
                }
#line 1111 "parser.tab.cc"
    break;

  case 31: // statement: PRINTLN LP expression RP SC
#line 190 "parser.yy"
                                        {
                  yylhs.value.as < BaseNode * > () = new PrintLnNode("PRINTLN", "", yylineno);
                  yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[2].value.as < BaseNode * > ());
                }
#line 1120 "parser.tab.cc"
    break;

  case 32: // statement: identifier ASSIGN expression SC
#line 194 "parser.yy"
                                           {
                  yylhs.value.as < BaseNode * > () = new IdAssignNode("IDASSIGN", "", yylineno);
                  yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[3].value.as < BaseNode * > ());
                  yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[1].value.as < BaseNode * > ());
          }
#line 1130 "parser.tab.cc"
    break;

  case 33: // statement: identifier LB expression RB ASSIGN expression SC
#line 199 "parser.yy"
                                                             {
                  yylhs.value.as < BaseNode * > () = new ListAssignNode("LISTASSIGN", "", yylineno);
                  yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[6].value.as < BaseNode * > ());
                  yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[4].value.as < BaseNode * > ());
                  yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[1].value.as < BaseNode * > ());
          }
#line 1141 "parser.tab.cc"
    break;

  case 34: // else_case: %empty
#line 207 "parser.yy"
                  {
              yylhs.value.as < BaseNode * > () = new NoElseNode("NO_ELSE", "", yylineno);
            }
#line 1149 "parser.tab.cc"
    break;

  case 35: // else_case: ELSE statement
#line 210 "parser.yy"
                           {
              yylhs.value.as < BaseNode * > () = new ElseNode("ELSE", "", yylineno);
              yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[0].value.as < BaseNode * > ());
            }
#line 1158 "parser.tab.cc"
    break;

  case 36: // n_statements: %empty
#line 216 "parser.yy"
                     {
                yylhs.value.as < BaseNode * > () = new ScopeNode("SCOPE", "", yylineno);
              }
#line 1166 "parser.tab.cc"
    break;

  case 37: // n_statements: n_statements statement
#line 219 "parser.yy"
                                     {
                yylhs.value.as < BaseNode * > () = yystack_[1].value.as < BaseNode * > ();
                yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[0].value.as < BaseNode * > ());
            }
#line 1175 "parser.tab.cc"
    break;

  case 38: // expression: expression PLUSOP expression
#line 225 "parser.yy"
                                         {      /*
                                                  Create a subtree that corresponds to the AddExpression
                                                  The root of the subtree is AddExpression
                                                  The children of the AddExpression subtree are the left hand side (expression accessed through $1) and right hand side of the expression (expression accessed through $3)
                                                */
                            yylhs.value.as < BaseNode * > () = new AddExpressionNode("AddExpression", "", yylineno);
                            yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[2].value.as < BaseNode * > ());
                            yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[0].value.as < BaseNode * > ());
                            /* printf("r1 "); */
                          }
#line 1190 "parser.tab.cc"
    break;

  case 39: // expression: expression MINUSOP expression
#line 235 "parser.yy"
                                            {
                            yylhs.value.as < BaseNode * > () = new SubExpressionNode("SubExpression", "", yylineno);
                            yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[2].value.as < BaseNode * > ());
                            yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[0].value.as < BaseNode * > ());
                            /* printf("r2 "); */
                          }
#line 1201 "parser.tab.cc"
    break;

  case 40: // expression: expression MULTOP expression
#line 241 "parser.yy"
                                           {
                            yylhs.value.as < BaseNode * > () = new MultExpressionNode("MultExpression", "", yylineno);
                            yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[2].value.as < BaseNode * > ());
                            yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[0].value.as < BaseNode * > ());
                            /* printf("r3 "); */
                          }
#line 1212 "parser.tab.cc"
    break;

  case 41: // expression: expression DIVOP expression
#line 247 "parser.yy"
                                          {
                            yylhs.value.as < BaseNode * > () = new DivExpressionNode("DIVOPExpression", "", yylineno);
                            yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[2].value.as < BaseNode * > ());
                            yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[0].value.as < BaseNode * > ());
                            /* printf("r4 "); */
                          }
#line 1223 "parser.tab.cc"
    break;

  case 42: // expression: expression LOGICAND expression
#line 253 "parser.yy"
                                             {
                            yylhs.value.as < BaseNode * > () = new LogicAndExpressionNode("LOGICANDExpression", "", yylineno);
                            yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[2].value.as < BaseNode * > ());
                            yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[0].value.as < BaseNode * > ());
                            /* printf("r4 "); */
                          }
#line 1234 "parser.tab.cc"
    break;

  case 43: // expression: expression LOGICOR expression
#line 259 "parser.yy"
                                            {
                            yylhs.value.as < BaseNode * > () = new LogicOrExpressionNode("LOGICORExpression", "", yylineno);
                            yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[2].value.as < BaseNode * > ());
                            yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[0].value.as < BaseNode * > ());
                            /* printf("r4 "); */
                          }
#line 1245 "parser.tab.cc"
    break;

  case 44: // expression: expression LT expression
#line 265 "parser.yy"
                                       {
                            yylhs.value.as < BaseNode * > () = new LtExpressionNode("LTExpression", "", yylineno);
                            yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[2].value.as < BaseNode * > ());
                            yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[0].value.as < BaseNode * > ());
                            /* printf("r4 "); */
                          }
#line 1256 "parser.tab.cc"
    break;

  case 45: // expression: expression GT expression
#line 271 "parser.yy"
                                       {
                            yylhs.value.as < BaseNode * > () = new GtExpressionNode("GTExpression", "", yylineno);
                            yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[2].value.as < BaseNode * > ());
                            yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[0].value.as < BaseNode * > ());
                            /* printf("r4 "); */
                          }
#line 1267 "parser.tab.cc"
    break;

  case 46: // expression: expression EQUAL expression
#line 277 "parser.yy"
                                          {
                            yylhs.value.as < BaseNode * > () = new EqualExpressionNode("EQUALExpression", "", yylineno);
                            yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[2].value.as < BaseNode * > ());
                            yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[0].value.as < BaseNode * > ());
                            /* printf("r4 "); */
                          }
#line 1278 "parser.tab.cc"
    break;

  case 47: // expression: expression LB expression RB
#line 283 "parser.yy"
                                          {
                            yylhs.value.as < BaseNode * > () = new LBRBExpressionNode("LBRBExpression", "", yylineno);
                            yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[3].value.as < BaseNode * > ());
                            yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[1].value.as < BaseNode * > ());
                            /* printf("r4 "); */
                          }
#line 1289 "parser.tab.cc"
    break;

  case 48: // expression: expression DOT LENGTH
#line 289 "parser.yy"
                                    {
                            yylhs.value.as < BaseNode * > () = new DotLengthExpressionNode("DOTLENGTHExpression", "", yylineno);
                            yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[2].value.as < BaseNode * > ());
                            /* printf("r4 "); */
                          }
#line 1299 "parser.tab.cc"
    break;

  case 49: // expression: expression DOT identifier LP method_call1 RP
#line 294 "parser.yy"
                                                           {
                            yylhs.value.as < BaseNode * > () = new MethodCallNode("METHOD_CALL", "", yylineno);
                            yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[5].value.as < BaseNode * > ());
                            yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[3].value.as < BaseNode * > ());
                            yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[1].value.as < BaseNode * > ());
                            /* printf("r4 "); */
                          }
#line 1311 "parser.tab.cc"
    break;

  case 50: // expression: factor
#line 301 "parser.yy"
                          {yylhs.value.as < BaseNode * > () = yystack_[0].value.as < BaseNode * > (); /* printf("r5 ");*/}
#line 1317 "parser.tab.cc"
    break;

  case 51: // expression: TRUE
#line 302 "parser.yy"
                   {yylhs.value.as < BaseNode * > () = new TrueNode("TRUE", "", yylineno);}
#line 1323 "parser.tab.cc"
    break;

  case 52: // expression: FALSE
#line 303 "parser.yy"
                    {yylhs.value.as < BaseNode * > () = new FalseNode("FALSE", "", yylineno);}
#line 1329 "parser.tab.cc"
    break;

  case 53: // expression: identifier
#line 304 "parser.yy"
                         {yylhs.value.as < BaseNode * > () = yystack_[0].value.as < BaseNode * > ();}
#line 1335 "parser.tab.cc"
    break;

  case 54: // expression: THIS
#line 305 "parser.yy"
                   {yylhs.value.as < BaseNode * > () = new ThisNode("THIS", "", yylineno);}
#line 1341 "parser.tab.cc"
    break;

  case 55: // expression: NEW TYPE_INT LB expression RB
#line 306 "parser.yy"
                                            {
                            yylhs.value.as < BaseNode * > () = new NewListNode("NEW_LIST", "", yylineno);
                            yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[1].value.as < BaseNode * > ());
                          }
#line 1350 "parser.tab.cc"
    break;

  case 56: // expression: NEW identifier LP RP
#line 310 "parser.yy"
                                   {
                            yylhs.value.as < BaseNode * > () = new NewObjectNode("NEW_OBJECT", "", yylineno);
                            yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[2].value.as < BaseNode * > ());
                            }
#line 1359 "parser.tab.cc"
    break;

  case 57: // expression: NOT expression
#line 314 "parser.yy"
                             {
                            yylhs.value.as < BaseNode * > () = new NotNode("NOT", "", yylineno);
                            yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[0].value.as < BaseNode * > ());
                          }
#line 1368 "parser.tab.cc"
    break;

  case 58: // method_call1: %empty
#line 320 "parser.yy"
                     {
                  yylhs.value.as < BaseNode * > () = new NoArgumentsNode("NO_ARGUMENTS", "", yylineno);
                }
#line 1376 "parser.tab.cc"
    break;

  case 59: // method_call1: expression
#line 323 "parser.yy"
                         {
              yylhs.value.as < BaseNode * > () = new ArgumentsNode("ARGUMENTS", "", yylineno);
              yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[0].value.as < BaseNode * > ());
            }
#line 1385 "parser.tab.cc"
    break;

  case 60: // method_call1: expression COMMA method_call2
#line 327 "parser.yy"
                                            {
                          yylhs.value.as < BaseNode * > () = yystack_[0].value.as < BaseNode * > ();
                          yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[2].value.as < BaseNode * > ());
                          }
#line 1394 "parser.tab.cc"
    break;

  case 61: // method_call2: expression
#line 333 "parser.yy"
                         {
              yylhs.value.as < BaseNode * > () = new ArgumentsNode("ARGUMENTS", "", yylineno);
              yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[0].value.as < BaseNode * > ());
            }
#line 1403 "parser.tab.cc"
    break;

  case 62: // method_call2: expression COMMA method_call2
#line 337 "parser.yy"
                                            {
                          yylhs.value.as < BaseNode * > () = yystack_[0].value.as < BaseNode * > ();
                          yylhs.value.as < BaseNode * > ()->children.push_back(yystack_[2].value.as < BaseNode * > ());
                          }
#line 1412 "parser.tab.cc"
    break;

  case 63: // factor: INT
#line 343 "parser.yy"
                          {  yylhs.value.as < BaseNode * > () = new IntNode("TYPE_INT", yystack_[0].value.as < std::string > (), yylineno); /* printf("r5 ");  Here we create a leaf node Int. The value of the leaf node is $1 */}
#line 1418 "parser.tab.cc"
    break;

  case 64: // factor: LP expression RP
#line 344 "parser.yy"
                               { yylhs.value.as < BaseNode * > () = yystack_[1].value.as < BaseNode * > (); /* printf("r6 ");  simply return the expression */}
#line 1424 "parser.tab.cc"
    break;

  case 65: // identifier: ID
#line 347 "parser.yy"
               { yylhs.value.as < BaseNode * > () = new IdNode("ID", yystack_[0].value.as < std::string > (), yylineno);}
#line 1430 "parser.tab.cc"
    break;


#line 1434 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
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
              else
                goto append;

            append:
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

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -55;

  const signed char parser::yytable_ninf_ = -28;

  const short
  parser::yypact_[] =
  {
      -9,     7,    32,   -55,   -55,    17,   -55,     8,   -55,    22,
     -55,    17,   -55,    27,    39,    52,   -55,    49,    46,    51,
      58,   -55,   -55,    12,    17,   -55,    60,    71,    46,   -55,
     -55,    72,    74,   -55,    17,   -55,    89,   106,   109,    46,
      17,   115,   112,    17,   126,   136,    46,   -55,   149,   -55,
     -55,   117,   -55,   346,    46,   151,    -6,   -55,     5,   160,
     163,   165,   -55,   -55,   105,   -55,   156,   162,   105,    50,
     -55,     5,   -55,   -55,   -55,   -12,     5,   111,   -55,   -55,
       5,     5,     5,     5,     5,   -55,   -55,   -55,    23,   144,
     166,   -10,     5,     5,     5,     5,   164,     5,     5,     5,
       5,     5,     5,   -33,   121,   154,   161,   194,   201,   -55,
       5,   167,   357,   357,   -10,   234,   -55,   319,    76,   114,
     114,   324,   -10,   -55,   170,    -6,    -6,   181,   152,   -55,
     241,   -55,   -55,     5,   157,   -55,   -55,     5,   -55,   274,
     171,    -6,   -55,   281,     5,   -55,   -55,   -55,   314,   -55,
       5,   -55
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     5,     0,     1,     0,    65,     0,
       3,     0,     6,     0,     0,     0,     8,     0,    11,     0,
      25,    24,     9,     0,     0,    26,     0,     0,     0,     7,
      12,     0,     0,    23,     0,    10,     0,     0,     0,    14,
       0,     0,    15,     0,     0,     0,     0,    19,     0,    20,
      16,    17,    36,     0,     0,     0,     0,    36,     0,     0,
       0,     0,    21,    22,    26,    18,     0,    37,     0,     0,
      63,     0,    51,    52,    54,     0,     0,     0,    50,    53,
       0,     0,     0,     0,     0,     4,    28,    37,     0,     0,
       0,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    64,
       0,     0,    38,    39,    40,     0,    13,    42,    43,    44,
      45,    46,    41,    48,     0,     0,     0,     0,     0,    32,
       0,    56,    47,    58,    34,    30,    31,     0,    55,    59,
       0,     0,    29,     0,     0,    49,    35,    33,    61,    60,
       0,    62
  };

  const short
  parser::yypgoto_[] =
  {
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   128,   -55,   -55,
     -55,   147,   168,   -55,   -14,   -55,   -54,   -55,   145,     2,
     -55,    53,   -55,    -5
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     2,     3,     4,     7,    12,    18,    22,    23,    30,
      41,    50,    51,    53,    43,    55,    63,   142,    56,   148,
     140,   149,    78,    79
  };

  const short
  parser::yytable_[] =
  {
       9,     1,    67,   123,    24,    57,    14,    95,    10,     8,
      89,    70,    71,    25,    34,    87,     5,    11,    59,    31,
      60,    61,    28,    25,    29,   103,    92,    93,    94,    37,
       8,   109,     6,    13,    25,    44,     8,    15,    47,    24,
      95,    25,    72,    73,    74,    75,    76,     8,    64,    25,
      16,    68,    97,    98,    99,   100,   101,   102,   103,     8,
      77,    57,    86,    19,    68,    17,    26,    32,    20,    21,
      90,   134,   135,    88,    59,    27,    60,    61,    91,    92,
      93,    94,   104,   105,   106,   107,   108,   146,     8,    33,
      36,    35,     8,    95,   112,   113,   114,   115,   124,   117,
     118,   119,   120,   121,   122,    97,    38,    99,   100,   101,
     102,   103,   130,    39,    92,    93,    94,    92,    93,    94,
      68,    68,    83,    45,    92,    93,    94,    40,    95,   125,
      96,    95,    46,    84,    48,   139,    68,    54,    95,   143,
      97,    98,    99,   100,   101,   102,   103,    49,   102,   103,
      97,    98,    99,   100,   101,   102,   103,    92,    93,    94,
      52,   110,   126,    66,    92,    93,    94,    80,    85,   127,
      81,    95,    82,   111,   -27,   131,   116,   133,    95,   145,
     137,    62,   141,    97,    98,    99,   100,   101,   102,   103,
      97,    98,    99,   100,   101,   102,   103,    92,    93,    94,
     136,    65,    69,   151,    92,    93,    94,    42,     0,     0,
       0,    95,   128,     0,     0,     0,     0,     0,    95,     0,
     129,     0,     0,    97,    98,    99,   100,   101,   102,   103,
      97,    98,    99,   100,   101,   102,   103,    92,    93,    94,
       0,     0,     0,     0,    92,    93,    94,     0,     0,     0,
       0,    95,   132,     0,     0,     0,     0,     0,    95,   138,
       0,     0,     0,    97,    98,    99,   100,   101,   102,   103,
      97,    98,    99,   100,   101,   102,   103,    92,    93,    94,
       0,     0,     0,     0,    92,    93,    94,     0,     0,     0,
       0,    95,     0,     0,   144,     0,     0,     0,    95,     0,
     147,     0,     0,    97,    98,    99,   100,   101,   102,   103,
      97,    98,    99,   100,   101,   102,   103,    92,    93,    94,
       0,     0,    92,    93,    94,     0,     0,    92,    93,    94,
       0,    95,     0,     0,   150,     0,    95,     0,     0,     0,
       0,    95,     0,    97,    98,    99,   100,   101,   102,   103,
      99,   100,   101,   102,   103,    99,   100,    57,   102,   103,
       0,     0,    94,     0,     0,     0,     0,    58,    20,    21,
      59,     0,    60,    61,    95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     8,     0,
       0,   102,   103
  };

  const short
  parser::yycheck_[] =
  {
       5,    10,    56,    36,    18,    11,    11,    17,     0,    42,
      22,     6,     7,    18,    28,    69,     9,     9,    24,    24,
      26,    27,    10,    28,    12,    35,     3,     4,     5,    34,
      42,     8,     0,    11,    39,    40,    42,    10,    43,    53,
      17,    46,    37,    38,    39,    40,    41,    42,    53,    54,
      11,    56,    29,    30,    31,    32,    33,    34,    35,    42,
      58,    11,    12,    14,    69,    13,    15,     7,    22,    23,
      75,   125,   126,    71,    24,    17,    26,    27,    76,     3,
       4,     5,    80,    81,    82,    83,    84,   141,    42,    18,
      16,    19,    42,    17,    92,    93,    94,    95,   103,    97,
      98,    99,   100,   101,   102,    29,    17,    31,    32,    33,
      34,    35,   110,     7,     3,     4,     5,     3,     4,     5,
     125,   126,    17,     8,     3,     4,     5,    18,    17,     8,
      19,    17,    20,    28,     8,   133,   141,    20,    17,   137,
      29,    30,    31,    32,    33,    34,    35,    11,    34,    35,
      29,    30,    31,    32,    33,    34,    35,     3,     4,     5,
      11,    17,     8,    12,     3,     4,     5,     7,    12,     8,
       7,    17,     7,     7,    12,     8,    12,     7,    17,     8,
      28,    53,    25,    29,    30,    31,    32,    33,    34,    35,
      29,    30,    31,    32,    33,    34,    35,     3,     4,     5,
      19,    54,    57,   150,     3,     4,     5,    39,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      19,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      29,    30,    31,    32,    33,    34,    35,     3,     4,     5,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      29,    30,    31,    32,    33,    34,    35,     3,     4,     5,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    20,    -1,    -1,    -1,    17,    -1,
      19,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      29,    30,    31,    32,    33,    34,    35,     3,     4,     5,
      -1,    -1,     3,     4,     5,    -1,    -1,     3,     4,     5,
      -1,    17,    -1,    -1,    20,    -1,    17,    -1,    -1,    -1,
      -1,    17,    -1,    29,    30,    31,    32,    33,    34,    35,
      31,    32,    33,    34,    35,    31,    32,    11,    34,    35,
      -1,    -1,     5,    -1,    -1,    -1,    -1,    21,    22,    23,
      24,    -1,    26,    27,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    34,    35
  };

  const signed char
  parser::yystos_[] =
  {
       0,    10,    44,    45,    46,     9,     0,    47,    42,    66,
       0,     9,    48,    11,    66,    10,    11,    13,    49,    14,
      22,    23,    50,    51,    57,    66,    15,    17,    10,    12,
      52,    66,     7,    18,    57,    19,    16,    66,    17,     7,
      18,    53,    55,    57,    66,     8,    20,    66,     8,    11,
      54,    55,    11,    56,    20,    58,    61,    11,    21,    24,
      26,    27,    50,    59,    66,    54,    12,    59,    66,    61,
       6,     7,    37,    38,    39,    40,    41,    62,    65,    66,
       7,     7,     7,    17,    28,    12,    12,    59,    62,    22,
      66,    62,     3,     4,     5,    17,    19,    29,    30,    31,
      32,    33,    34,    35,    62,    62,    62,    62,    62,     8,
      17,     7,    62,    62,    62,    62,    12,    62,    62,    62,
      62,    62,    62,    36,    66,     8,     8,     8,    18,    19,
      62,     8,    18,     7,    59,    59,    19,    28,    18,    62,
      63,    25,    60,    62,    20,     8,    59,    19,    62,    64,
      20,    64
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    43,    44,    45,    46,    47,    47,    48,    49,    49,
      50,    51,    51,    52,    53,    53,    53,    54,    54,    55,
      56,    56,    56,    57,    57,    57,    57,    58,    59,    59,
      59,    59,    59,    59,    60,    60,    61,    61,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    63,    63,
      63,    64,    64,    65,    65,    66
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     3,    18,     0,     2,     6,     0,     2,
       3,     0,     2,    12,     0,     1,     3,     1,     3,     2,
       0,     2,     2,     3,     1,     1,     1,     2,     3,     6,
       5,     5,     4,     7,     0,     2,     0,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     3,     6,
       1,     1,     1,     1,     1,     5,     4,     2,     0,     1,
       3,     1,     3,     1,     3,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "PLUSOP", "MINUSOP",
  "MULTOP", "INT", "LP", "RP", "CLASS", "PUBLIC", "LCB", "RCB", "STATIC",
  "VOID", "MAIN", "STRING", "LB", "RB", "SC", "COMMA", "RETURN",
  "TYPE_INT", "TYPE_BOOLEAN", "IF", "ELSE", "WHILE", "PRINTLN", "ASSIGN",
  "LOGICAND", "LOGICOR", "LT", "GT", "EQUAL", "DIVOP", "DOT", "LENGTH",
  "TRUE", "FALSE", "THIS", "NEW", "NOT", "ID", "$accept", "root", "goal",
  "main_class", "n_class_declarations", "class_declaration",
  "n_var_declarations", "var_declaration", "n_method_declarations",
  "method_declaration", "n_type_identifiers", "n2_type_identifiers",
  "type_identifier", "n_var_declarations_or_statements", "type",
  "one_or_more_statements", "statement", "else_case", "n_statements",
  "expression", "method_call1", "method_call2", "factor", "identifier", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    44,    44,    47,    54,    63,    66,    72,    80,    83,
      88,    95,    98,   103,   112,   115,   119,   125,   129,   135,
     142,   145,   149,   155,   158,   161,   164,   170,   176,   179,
     185,   190,   194,   199,   207,   210,   216,   219,   225,   235,
     241,   247,   253,   259,   265,   271,   277,   283,   289,   294,
     301,   302,   303,   304,   305,   306,   310,   314,   320,   323,
     327,   333,   337,   343,   344,   347
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2044 "parser.tab.cc"

