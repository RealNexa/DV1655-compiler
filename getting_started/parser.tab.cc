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
  
  Node* root;
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
        value.YY_MOVE_OR_COPY< Node * > (YY_MOVE (that.value));
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
        value.move< Node * > (YY_MOVE (that.value));
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
        value.copy< Node * > (that.value);
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
        value.move< Node * > (that.value);
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
        yylhs.value.emplace< Node * > ();
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
#line 43 "parser.yy"
                 {root = yystack_[0].value.as < Node * > ();}
#line 848 "parser.tab.cc"
    break;

  case 3: // goal: main_class n_class_declarations "end of file"
#line 46 "parser.yy"
                                           {
                          yylhs.value.as < Node * > () = new Node("GOAL", "", yylineno);
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                          }
#line 858 "parser.tab.cc"
    break;

  case 4: // main_class: PUBLIC CLASS identifier LCB PUBLIC STATIC VOID MAIN LP STRING LB RB identifier RP LCB one_or_more_statements RCB RCB
#line 53 "parser.yy"
                                                                                                                                 {
  yylhs.value.as < Node * > () = new Node("MAIN_CLASS", "", yylineno);
  yylhs.value.as < Node * > ()->children.push_back(yystack_[15].value.as < Node * > ());
  yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
  yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  /*$$->children.push_back($17);*/
}
#line 870 "parser.tab.cc"
    break;

  case 5: // n_class_declarations: %empty
#line 63 "parser.yy"
                             {
                   yylhs.value.as < Node * > () = new Node("NON_MAIN_CLASSES", "", yylineno);
                }
#line 878 "parser.tab.cc"
    break;

  case 6: // n_class_declarations: n_class_declarations class_declaration
#line 66 "parser.yy"
                                                    {
              yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 887 "parser.tab.cc"
    break;

  case 7: // class_declaration: CLASS identifier LCB n_var_declarations n_method_declarations RCB
#line 71 "parser.yy"
                                                                                     {
                yylhs.value.as < Node * > () = new Node("CLASS_DECLARATION", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
}
#line 898 "parser.tab.cc"
    break;

  case 8: // n_var_declarations: %empty
#line 79 "parser.yy"
                           {
                  yylhs.value.as < Node * > () = new Node("VAR_DECLARATIONS", "", yylineno);
                }
#line 906 "parser.tab.cc"
    break;

  case 9: // n_var_declarations: n_var_declarations var_declaration
#line 82 "parser.yy"
                                                  {
              yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 915 "parser.tab.cc"
    break;

  case 10: // var_declaration: type identifier SC
#line 87 "parser.yy"
                                    {
                  yylhs.value.as < Node * > () = new Node("TYPEID", "", yylineno);
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                }
#line 925 "parser.tab.cc"
    break;

  case 11: // n_method_declarations: %empty
#line 94 "parser.yy"
                              {
                  yylhs.value.as < Node * > () = new Node("METHOD_DECLARATIONS", "", yylineno);
                }
#line 933 "parser.tab.cc"
    break;

  case 12: // n_method_declarations: n_method_declarations method_declaration
#line 97 "parser.yy"
                                                       {
              yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 942 "parser.tab.cc"
    break;

  case 13: // method_declaration: PUBLIC type identifier LP n_type_identifiers RP LCB n_var_declarations_or_statements RETURN expression SC RCB
#line 102 "parser.yy"
                                                                                                                                  {
        yylhs.value.as < Node * > () = new Node("METHOD_DECLARATION", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[10].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[9].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[7].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
      }
#line 955 "parser.tab.cc"
    break;

  case 14: // n_type_identifiers: %empty
#line 111 "parser.yy"
                           {
                  yylhs.value.as < Node * > () = new Node("PARAMETERS", "", yylineno);
                }
#line 963 "parser.tab.cc"
    break;

  case 15: // n_type_identifiers: type_identifier
#line 114 "parser.yy"
                              {
              yylhs.value.as < Node * > () = new Node("PARAMETERS", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());

            }
#line 973 "parser.tab.cc"
    break;

  case 16: // n_type_identifiers: type_identifier COMMA n_type_identifiers
#line 119 "parser.yy"
                                                       {
                          yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                          }
#line 982 "parser.tab.cc"
    break;

  case 17: // type_identifier: type identifier
#line 125 "parser.yy"
                                 {
    yylhs.value.as < Node * > () = new Node("PARAMETER", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 992 "parser.tab.cc"
    break;

  case 18: // n_var_declarations_or_statements: %empty
#line 132 "parser.yy"
                                         {
                  yylhs.value.as < Node * > () = new Node("BODY", "", yylineno);
                }
#line 1000 "parser.tab.cc"
    break;

  case 19: // n_var_declarations_or_statements: n_var_declarations_or_statements var_declaration
#line 135 "parser.yy"
                                                                  {
                  yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                }
#line 1009 "parser.tab.cc"
    break;

  case 20: // n_var_declarations_or_statements: n_var_declarations_or_statements statement
#line 139 "parser.yy"
                                                             {
                  yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                }
#line 1018 "parser.tab.cc"
    break;

  case 21: // type: TYPE_INT LB RB
#line 145 "parser.yy"
                     {
        yylhs.value.as < Node * > () = new Node("TYPE_INT_LIST", "", yylineno);
      }
#line 1026 "parser.tab.cc"
    break;

  case 22: // type: TYPE_BOOLEAN
#line 148 "parser.yy"
                     {
        yylhs.value.as < Node * > () = new Node("TYPE_BOOLEAN", "", yylineno);
      }
#line 1034 "parser.tab.cc"
    break;

  case 23: // type: TYPE_INT
#line 151 "parser.yy"
                 {
        yylhs.value.as < Node * > () = new Node("TYPE_INT", "", yylineno);
      }
#line 1042 "parser.tab.cc"
    break;

  case 24: // type: identifier
#line 154 "parser.yy"
                   {
        yylhs.value.as < Node * > () = new Node("TYPE_CUSTOM", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 1051 "parser.tab.cc"
    break;

  case 25: // one_or_more_statements: n_statements statement
#line 160 "parser.yy"
                                               {
  yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
  yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1060 "parser.tab.cc"
    break;

  case 26: // statement: LCB n_statements RCB
#line 166 "parser.yy"
                                {
                yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
                }
#line 1068 "parser.tab.cc"
    break;

  case 27: // statement: IF LP expression RP statement else_case
#line 169 "parser.yy"
                                                    {
                  yylhs.value.as < Node * > () = new Node("IF", "", yylineno);
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                }
#line 1079 "parser.tab.cc"
    break;

  case 28: // statement: WHILE LP expression RP statement
#line 175 "parser.yy"
                                             {
                  yylhs.value.as < Node * > () = new Node("WHILE", "", yylineno);
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                }
#line 1089 "parser.tab.cc"
    break;

  case 29: // statement: PRINTLN LP expression RP SC
#line 180 "parser.yy"
                                        {
                  yylhs.value.as < Node * > () = new Node("PRINTLN", "", yylineno);
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                }
#line 1098 "parser.tab.cc"
    break;

  case 30: // statement: identifier ASSIGN expression SC
#line 184 "parser.yy"
                                           {
                  yylhs.value.as < Node * > () = new Node("IDASSIGN", "", yylineno);
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          }
#line 1108 "parser.tab.cc"
    break;

  case 31: // statement: identifier LB expression RB ASSIGN expression SC
#line 189 "parser.yy"
                                                             {
                  yylhs.value.as < Node * > () = new Node("LISTASSIGN", "", yylineno);
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          }
#line 1119 "parser.tab.cc"
    break;

  case 32: // else_case: %empty
#line 197 "parser.yy"
                  {
              yylhs.value.as < Node * > () = new Node("NO_ELSE", "", yylineno);
            }
#line 1127 "parser.tab.cc"
    break;

  case 33: // else_case: ELSE statement
#line 200 "parser.yy"
                           {
              yylhs.value.as < Node * > () = new Node("ELSE", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1136 "parser.tab.cc"
    break;

  case 34: // n_statements: %empty
#line 206 "parser.yy"
                     {
                yylhs.value.as < Node * > () = new Node("SCOPE", "", yylineno);
              }
#line 1144 "parser.tab.cc"
    break;

  case 35: // n_statements: n_statements statement
#line 209 "parser.yy"
                                     {
                yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1153 "parser.tab.cc"
    break;

  case 36: // expression: expression PLUSOP expression
#line 215 "parser.yy"
                                         {      /*
                                                  Create a subtree that corresponds to the AddExpression
                                                  The root of the subtree is AddExpression
                                                  The children of the AddExpression subtree are the left hand side (expression accessed through $1) and right hand side of the expression (expression accessed through $3)
                                                */
                            yylhs.value.as < Node * > () = new Node("AddExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r1 "); */
                          }
#line 1168 "parser.tab.cc"
    break;

  case 37: // expression: expression MINUSOP expression
#line 225 "parser.yy"
                                            {
                            yylhs.value.as < Node * > () = new Node("SubExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r2 "); */
                          }
#line 1179 "parser.tab.cc"
    break;

  case 38: // expression: expression MULTOP expression
#line 231 "parser.yy"
                                           {
                            yylhs.value.as < Node * > () = new Node("MultExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r3 "); */
                          }
#line 1190 "parser.tab.cc"
    break;

  case 39: // expression: expression DIVOP expression
#line 237 "parser.yy"
                                          {
                            yylhs.value.as < Node * > () = new Node("DIVOPExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r4 "); */
                          }
#line 1201 "parser.tab.cc"
    break;

  case 40: // expression: expression LOGICAND expression
#line 243 "parser.yy"
                                             {
                            yylhs.value.as < Node * > () = new Node("LOGICANDExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r4 "); */
                          }
#line 1212 "parser.tab.cc"
    break;

  case 41: // expression: expression LOGICOR expression
#line 249 "parser.yy"
                                            {
                            yylhs.value.as < Node * > () = new Node("LOGICORExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r4 "); */
                          }
#line 1223 "parser.tab.cc"
    break;

  case 42: // expression: expression LT expression
#line 255 "parser.yy"
                                       {
                            yylhs.value.as < Node * > () = new Node("LTExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r4 "); */
                          }
#line 1234 "parser.tab.cc"
    break;

  case 43: // expression: expression GT expression
#line 261 "parser.yy"
                                       {
                            yylhs.value.as < Node * > () = new Node("GTExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r4 "); */
                          }
#line 1245 "parser.tab.cc"
    break;

  case 44: // expression: expression EQUAL expression
#line 267 "parser.yy"
                                          {
                            yylhs.value.as < Node * > () = new Node("EQUALExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r4 "); */
                          }
#line 1256 "parser.tab.cc"
    break;

  case 45: // expression: expression LB expression RB
#line 273 "parser.yy"
                                          {
                            yylhs.value.as < Node * > () = new Node("LBRBExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            /* printf("r4 "); */
                          }
#line 1267 "parser.tab.cc"
    break;

  case 46: // expression: expression DOT LENGTH
#line 279 "parser.yy"
                                    {
                            yylhs.value.as < Node * > () = new Node("DOTLENGTHExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            /* printf("r4 "); */
                          }
#line 1277 "parser.tab.cc"
    break;

  case 47: // expression: expression DOT identifier LP method_call1 RP
#line 284 "parser.yy"
                                                           {
                            yylhs.value.as < Node * > () = new Node("METHOD_CALL", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            /* printf("r4 "); */
                          }
#line 1289 "parser.tab.cc"
    break;

  case 48: // expression: factor
#line 291 "parser.yy"
                          {yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); /* printf("r5 ");*/}
#line 1295 "parser.tab.cc"
    break;

  case 49: // expression: TRUE
#line 292 "parser.yy"
                   {yylhs.value.as < Node * > () = new Node("TRUE", "", yylineno);}
#line 1301 "parser.tab.cc"
    break;

  case 50: // expression: FALSE
#line 293 "parser.yy"
                    {yylhs.value.as < Node * > () = new Node("FALSE", "", yylineno);}
#line 1307 "parser.tab.cc"
    break;

  case 51: // expression: identifier
#line 294 "parser.yy"
                         {yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();}
#line 1313 "parser.tab.cc"
    break;

  case 52: // expression: THIS
#line 295 "parser.yy"
                   {yylhs.value.as < Node * > () = new Node("THIS", "", yylineno);}
#line 1319 "parser.tab.cc"
    break;

  case 53: // expression: NEW TYPE_INT LB expression RB
#line 296 "parser.yy"
                                            {
                            yylhs.value.as < Node * > () = new Node("NEW_LIST", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                          }
#line 1328 "parser.tab.cc"
    break;

  case 54: // expression: NEW identifier LP RP
#line 300 "parser.yy"
                                   {
                            yylhs.value.as < Node * > () = new Node("NEW_OBJECT", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            }
#line 1337 "parser.tab.cc"
    break;

  case 55: // expression: NOT expression
#line 304 "parser.yy"
                             {
                            yylhs.value.as < Node * > () = new Node("NOT", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                          }
#line 1346 "parser.tab.cc"
    break;

  case 56: // method_call1: %empty
#line 310 "parser.yy"
                     {
                  yylhs.value.as < Node * > () = new Node("NO_ARGUMENTS", "", yylineno);
                }
#line 1354 "parser.tab.cc"
    break;

  case 57: // method_call1: expression
#line 313 "parser.yy"
                         {
              yylhs.value.as < Node * > () = new Node("ARGUMENS", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1363 "parser.tab.cc"
    break;

  case 58: // method_call1: expression COMMA method_call2
#line 317 "parser.yy"
                                            {
                          yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                          }
#line 1372 "parser.tab.cc"
    break;

  case 59: // method_call2: expression
#line 323 "parser.yy"
                         {
              yylhs.value.as < Node * > () = new Node("ARGUMENTS", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1381 "parser.tab.cc"
    break;

  case 60: // method_call2: expression COMMA method_call2
#line 327 "parser.yy"
                                            {
                          yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                          }
#line 1390 "parser.tab.cc"
    break;

  case 61: // factor: INT
#line 333 "parser.yy"
                          {  yylhs.value.as < Node * > () = new Node("Int", yystack_[0].value.as < std::string > (), yylineno); /* printf("r5 ");  Here we create a leaf node Int. The value of the leaf node is $1 */}
#line 1396 "parser.tab.cc"
    break;

  case 62: // factor: LP expression RP
#line 334 "parser.yy"
                               { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); /* printf("r6 ");  simply return the expression */}
#line 1402 "parser.tab.cc"
    break;

  case 63: // identifier: ID
#line 337 "parser.yy"
               { yylhs.value.as < Node * > () = new Node("ID", yystack_[0].value.as < std::string > (), yylineno);}
#line 1408 "parser.tab.cc"
    break;


#line 1412 "parser.tab.cc"

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


  const signed char parser::yypact_ninf_ = -53;

  const signed char parser::yytable_ninf_ = -26;

  const short
  parser::yypact_[] =
  {
       8,    19,    31,   -53,   -53,     1,   -53,     7,   -53,    39,
     -53,     1,   -53,    47,    51,    56,   -53,    50,    37,    63,
      48,   -53,   -53,    -9,     1,   -53,    75,    65,    37,   -53,
     -53,    68,    80,   -53,     1,   -53,    88,    90,    97,    37,
       1,   105,    96,     1,   113,   111,    37,   -53,   112,   -53,
     -53,   -53,   337,   119,     6,   -53,    14,   130,   133,   134,
     -53,   -53,   -13,   126,   132,   -13,     0,   -53,    14,   -53,
     -53,   -53,   -17,    14,    95,   -53,   -53,    14,    14,    14,
      14,    14,   -53,   -53,   -53,   131,   128,   136,    46,    14,
      14,    14,    14,   135,    14,    14,    14,    14,    14,    14,
      52,   150,   169,   188,   207,   226,   -53,    14,   143,   115,
     115,    46,   245,   -53,    41,   340,   230,   230,     5,    46,
     -53,   145,     6,     6,   137,   129,   -53,   264,   -53,   -53,
      14,   144,   -53,   -53,    14,   -53,   283,   151,     6,   -53,
     302,    14,   -53,   -53,   -53,   321,   -53,    14,   -53
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     5,     0,     1,     0,    63,     0,
       3,     0,     6,     0,     0,     0,     8,     0,    11,     0,
      23,    22,     9,     0,     0,    24,     0,     0,     0,     7,
      12,     0,     0,    21,     0,    10,     0,     0,     0,    14,
       0,     0,    15,     0,     0,     0,    14,    17,     0,    18,
      16,    34,     0,     0,     0,    34,     0,     0,     0,     0,
      19,    20,    24,     0,    35,     0,     0,    61,     0,    49,
      50,    52,     0,     0,     0,    48,    51,     0,     0,     0,
       0,     0,     4,    26,    35,     0,     0,     0,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    62,     0,     0,    36,
      37,    38,     0,    13,    40,    41,    42,    43,    44,    39,
      46,     0,     0,     0,     0,     0,    30,     0,    54,    45,
      56,    32,    28,    29,     0,    53,    57,     0,     0,    27,
       0,     0,    47,    33,    31,    59,    58,     0,    60
  };

  const signed char
  parser::yypgoto_[] =
  {
     -53,   -53,   -53,   -53,   -53,   -53,   -53,   116,   -53,   -53,
     124,   -53,   -53,    38,   -53,   -52,   -53,   120,    12,   -53,
      24,   -53,    -5
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     2,     3,     4,     7,    12,    18,    22,    23,    30,
      41,    42,    52,    24,    53,    61,   139,    54,   145,   137,
     146,    75,    76
  };

  const short
  parser::yytable_[] =
  {
       9,    28,    64,    29,    80,    86,    14,    10,    89,    90,
      91,    55,    83,    25,    84,    81,    11,    55,     1,    31,
      67,    68,    92,    25,    57,     8,    58,    59,     5,    37,
      57,     6,    58,    59,    25,    44,    96,    97,    47,    99,
     100,    25,     8,     8,    89,    90,    91,    62,     8,    65,
      13,    69,    70,    71,    72,    73,     8,    15,    92,    20,
      21,    65,    16,    92,    19,    27,    34,    87,    74,    17,
     131,   132,    96,    97,    98,    99,   100,    43,    26,     8,
      85,   100,    32,    33,    43,    88,   143,    35,   120,   101,
     102,   103,   104,   105,     8,   121,    36,    39,    89,    90,
      91,   109,   110,   111,   112,    38,   114,   115,   116,   117,
     118,   119,    92,    45,    93,    40,    46,    65,    65,   127,
      91,    48,    49,    51,    94,    95,    96,    97,    98,    99,
     100,    63,    92,    65,    89,    90,    91,    77,    82,   106,
      78,    79,   136,   108,   -25,   107,   140,   113,    92,    99,
     100,   128,   130,    89,    90,    91,   133,   134,   122,   142,
      94,    95,    96,    97,    98,    99,   100,    92,    60,   138,
      50,   148,    89,    90,    91,    66,     0,   123,     0,    94,
      95,    96,    97,    98,    99,   100,    92,     0,     0,     0,
       0,    89,    90,    91,     0,     0,   124,     0,    94,    95,
      96,    97,    98,    99,   100,    92,     0,     0,     0,     0,
      89,    90,    91,     0,     0,     0,     0,    94,    95,    96,
      97,    98,    99,   100,    92,   125,     0,     0,     0,    89,
      90,    91,     0,    89,    90,    91,    94,    95,    96,    97,
      98,    99,   100,    92,     0,   126,     0,    92,    89,    90,
      91,     0,     0,     0,     0,    94,    95,    96,    97,    98,
      99,   100,    92,   129,    99,   100,     0,    89,    90,    91,
       0,     0,     0,     0,    94,    95,    96,    97,    98,    99,
     100,    92,   135,     0,     0,     0,    89,    90,    91,     0,
       0,     0,     0,    94,    95,    96,    97,    98,    99,   100,
      92,     0,     0,   141,     0,    89,    90,    91,     0,     0,
       0,     0,    94,    95,    96,    97,    98,    99,   100,    92,
       0,   144,     0,     0,    89,    90,    91,     0,     0,     0,
       0,    94,    95,    96,    97,    98,    99,   100,    92,     0,
       0,   147,     0,    89,    90,    91,     0,     0,    55,     0,
      94,    95,    96,    97,    98,    99,   100,    92,    56,    20,
      21,    57,     0,    58,    59,     0,     0,     0,     0,    94,
       0,    96,    97,    98,    99,   100,     0,     0,     0,     8
  };

  const short
  parser::yycheck_[] =
  {
       5,    10,    54,    12,    17,    22,    11,     0,     3,     4,
       5,    11,    12,    18,    66,    28,     9,    11,    10,    24,
       6,     7,    17,    28,    24,    42,    26,    27,     9,    34,
      24,     0,    26,    27,    39,    40,    31,    32,    43,    34,
      35,    46,    42,    42,     3,     4,     5,    52,    42,    54,
      11,    37,    38,    39,    40,    41,    42,    10,    17,    22,
      23,    66,    11,    17,    14,    17,    28,    72,    56,    13,
     122,   123,    31,    32,    33,    34,    35,    39,    15,    42,
      68,    35,     7,    18,    46,    73,   138,    19,    36,    77,
      78,    79,    80,    81,    42,   100,    16,     7,     3,     4,
       5,    89,    90,    91,    92,    17,    94,    95,    96,    97,
      98,    99,    17,     8,    19,    18,    20,   122,   123,   107,
       5,     8,    11,    11,    29,    30,    31,    32,    33,    34,
      35,    12,    17,   138,     3,     4,     5,     7,    12,     8,
       7,     7,   130,     7,    12,    17,   134,    12,    17,    34,
      35,     8,     7,     3,     4,     5,    19,    28,     8,     8,
      29,    30,    31,    32,    33,    34,    35,    17,    52,    25,
      46,   147,     3,     4,     5,    55,    -1,     8,    -1,    29,
      30,    31,    32,    33,    34,    35,    17,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,    -1,     8,    -1,    29,    30,
      31,    32,    33,    34,    35,    17,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,    -1,    -1,    -1,    29,    30,    31,
      32,    33,    34,    35,    17,    18,    -1,    -1,    -1,     3,
       4,     5,    -1,     3,     4,     5,    29,    30,    31,    32,
      33,    34,    35,    17,    -1,    19,    -1,    17,     3,     4,
       5,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      34,    35,    17,    18,    34,    35,    -1,     3,     4,     5,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      35,    17,    18,    -1,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      17,    -1,    -1,    20,    -1,     3,     4,     5,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    34,    35,    17,
      -1,    19,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    17,    -1,
      -1,    20,    -1,     3,     4,     5,    -1,    -1,    11,    -1,
      29,    30,    31,    32,    33,    34,    35,    17,    21,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    -1,    29,
      -1,    31,    32,    33,    34,    35,    -1,    -1,    -1,    42
  };

  const signed char
  parser::yystos_[] =
  {
       0,    10,    44,    45,    46,     9,     0,    47,    42,    65,
       0,     9,    48,    11,    65,    10,    11,    13,    49,    14,
      22,    23,    50,    51,    56,    65,    15,    17,    10,    12,
      52,    65,     7,    18,    56,    19,    16,    65,    17,     7,
      18,    53,    54,    56,    65,     8,    20,    65,     8,    11,
      53,    11,    55,    57,    60,    11,    21,    24,    26,    27,
      50,    58,    65,    12,    58,    65,    60,     6,     7,    37,
      38,    39,    40,    41,    61,    64,    65,     7,     7,     7,
      17,    28,    12,    12,    58,    61,    22,    65,    61,     3,
       4,     5,    17,    19,    29,    30,    31,    32,    33,    34,
      35,    61,    61,    61,    61,    61,     8,    17,     7,    61,
      61,    61,    61,    12,    61,    61,    61,    61,    61,    61,
      36,    65,     8,     8,     8,    18,    19,    61,     8,    18,
       7,    58,    58,    19,    28,    18,    61,    62,    25,    59,
      61,    20,     8,    58,    19,    61,    63,    20,    63
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    43,    44,    45,    46,    47,    47,    48,    49,    49,
      50,    51,    51,    52,    53,    53,    53,    54,    55,    55,
      55,    56,    56,    56,    56,    57,    58,    58,    58,    58,
      58,    58,    59,    59,    60,    60,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    62,    62,    62,    63,
      63,    64,    64,    65
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     3,    18,     0,     2,     6,     0,     2,
       3,     0,     2,    12,     0,     1,     3,     2,     0,     2,
       2,     3,     1,     1,     1,     2,     3,     6,     5,     5,
       4,     7,     0,     2,     0,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     3,     6,     1,     1,
       1,     1,     1,     5,     4,     2,     0,     1,     3,     1,
       3,     1,     3,     1
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
  "method_declaration", "n_type_identifiers", "type_identifier",
  "n_var_declarations_or_statements", "type", "one_or_more_statements",
  "statement", "else_case", "n_statements", "expression", "method_call1",
  "method_call2", "factor", "identifier", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    43,    43,    46,    53,    63,    66,    71,    79,    82,
      87,    94,    97,   102,   111,   114,   119,   125,   132,   135,
     139,   145,   148,   151,   154,   160,   166,   169,   175,   180,
     184,   189,   197,   200,   206,   209,   215,   225,   231,   237,
     243,   249,   255,   261,   267,   273,   279,   284,   291,   292,
     293,   294,   295,   296,   300,   304,   310,   313,   317,   323,
     327,   333,   334,   337
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
#line 2015 "parser.tab.cc"

