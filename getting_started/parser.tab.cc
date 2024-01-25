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
      case symbol_kind::S_n_var_declarations_or_statements: // n_var_declarations_or_statements
      case symbol_kind::S_type: // type
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
      case symbol_kind::S_n_var_declarations_or_statements: // n_var_declarations_or_statements
      case symbol_kind::S_type: // type
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
      case symbol_kind::S_n_var_declarations_or_statements: // n_var_declarations_or_statements
      case symbol_kind::S_type: // type
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
      case symbol_kind::S_n_var_declarations_or_statements: // n_var_declarations_or_statements
      case symbol_kind::S_type: // type
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
      case symbol_kind::S_n_var_declarations_or_statements: // n_var_declarations_or_statements
      case symbol_kind::S_type: // type
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
#line 37 "parser.yy"
                 {root = yystack_[0].value.as < Node * > ();}
#line 838 "parser.tab.cc"
    break;

  case 3: // goal: main_class n_class_declarations "end of file"
#line 40 "parser.yy"
                                           {
                          yylhs.value.as < Node * > () = new Node("GOAL", "", yylineno);
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                          }
#line 848 "parser.tab.cc"
    break;

  case 4: // main_class: PUBLIC CLASS identifier LCB PUBLIC STATIC VOID MAIN LP STRING LB RB identifier RP LCB statement n_statements RCB RCB
#line 47 "parser.yy"
                                                                                                                                 {
  yylhs.value.as < Node * > () = new Node("MAIN_CLASS", "", yylineno);
  yylhs.value.as < Node * > ()->children.push_back(yystack_[16].value.as < Node * > ());
  yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
  yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
  yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
}
#line 860 "parser.tab.cc"
    break;

  case 5: // n_class_declarations: %empty
#line 56 "parser.yy"
                             {
                  yylhs.value.as < Node * > () = new Node("CLASS_DECLARATION_EMPTY", "", yylineno);
                }
#line 868 "parser.tab.cc"
    break;

  case 6: // n_class_declarations: class_declaration n_class_declarations
#line 59 "parser.yy"
                                                     {
              yylhs.value.as < Node * > () = new Node("CLASS_DECLARATION_NONEMPTY", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 877 "parser.tab.cc"
    break;

  case 7: // class_declaration: CLASS identifier LCB n_var_declarations n_method_declarations RCB
#line 64 "parser.yy"
                                                                                     {
                yylhs.value.as < Node * > () = new Node("CLASS_DECLARATION", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
}
#line 888 "parser.tab.cc"
    break;

  case 8: // n_var_declarations: %empty
#line 72 "parser.yy"
                           {
                  yylhs.value.as < Node * > () = new Node("VAR_DECLARATION_EMPTY", "", yylineno);
                }
#line 896 "parser.tab.cc"
    break;

  case 9: // n_var_declarations: var_declaration n_var_declarations
#line 75 "parser.yy"
                                                 {
              yylhs.value.as < Node * > () = new Node("VAR_DECLARATION_NONEMPTY", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 906 "parser.tab.cc"
    break;

  case 10: // var_declaration: type identifier SC
#line 81 "parser.yy"
                                    {
                  yylhs.value.as < Node * > () = new Node("TYPEID;", "", yylineno);
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                }
#line 916 "parser.tab.cc"
    break;

  case 11: // n_method_declarations: %empty
#line 88 "parser.yy"
                              {
                  yylhs.value.as < Node * > () = new Node("METHOD_DECLARATION_EMPTY", "", yylineno);
                }
#line 924 "parser.tab.cc"
    break;

  case 12: // n_method_declarations: method_declaration n_method_declarations
#line 91 "parser.yy"
                                                       {
              yylhs.value.as < Node * > () = new Node("METHOD_DECLARATION_NONEMPTY", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 934 "parser.tab.cc"
    break;

  case 13: // method_declaration: PUBLIC type identifier LP n_type_identifiers RP LCB n_var_declarations_or_statements RETURN expression SC RCB
#line 97 "parser.yy"
                                                                                                                                  {
        yylhs.value.as < Node * > () = new Node("METHOD_DECLARATION", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[10].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[9].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[7].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
      }
#line 947 "parser.tab.cc"
    break;

  case 14: // n_type_identifiers: %empty
#line 106 "parser.yy"
                           {
                  yylhs.value.as < Node * > () = new Node("TYPE_IDENTIFIERS_EMPTY", "", yylineno);
                }
#line 955 "parser.tab.cc"
    break;

  case 15: // n_type_identifiers: type identifier
#line 109 "parser.yy"
                              {
              yylhs.value.as < Node * > () = new Node("TYPE_IDENTIFIERS_NONEMPTY", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 965 "parser.tab.cc"
    break;

  case 16: // n_type_identifiers: type identifier COMMA n_type_identifiers
#line 114 "parser.yy"
                                                       {
                          yylhs.value.as < Node * > () = new Node("TYPE_IDENTIFIERS_NONEMPTY", "", yylineno);
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                          }
#line 976 "parser.tab.cc"
    break;

  case 17: // n_var_declarations_or_statements: %empty
#line 122 "parser.yy"
                                         {
                  yylhs.value.as < Node * > () = new Node("VAR_DECLARATION_OR_STATEMENT_EMPTY", "", yylineno);
                }
#line 984 "parser.tab.cc"
    break;

  case 18: // n_var_declarations_or_statements: var_declaration n_var_declarations_or_statements
#line 125 "parser.yy"
                                                                   {
                  yylhs.value.as < Node * > () = new Node("VAR_DECLARATION_NONEMPTY", "", yylineno);
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                }
#line 994 "parser.tab.cc"
    break;

  case 19: // n_var_declarations_or_statements: statement n_var_declarations_or_statements
#line 130 "parser.yy"
                                                             {
                  yylhs.value.as < Node * > () = new Node("STATEMENT_NOEMPTY", "", yylineno);
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                }
#line 1004 "parser.tab.cc"
    break;

  case 20: // type: TYPE_INT LB RB
#line 137 "parser.yy"
                     {
        yylhs.value.as < Node * > () = new Node("TYPE_INT_LIST", "", yylineno);
      }
#line 1012 "parser.tab.cc"
    break;

  case 21: // type: TYPE_BOOLEAN
#line 140 "parser.yy"
                     {
        yylhs.value.as < Node * > () = new Node("TYPE_BOOLEAN", "", yylineno);
      }
#line 1020 "parser.tab.cc"
    break;

  case 22: // type: TYPE_INT
#line 143 "parser.yy"
                 {
        yylhs.value.as < Node * > () = new Node("TYPE_INT", "", yylineno);
      }
#line 1028 "parser.tab.cc"
    break;

  case 23: // type: identifier
#line 146 "parser.yy"
                   {
        yylhs.value.as < Node * > () = new Node("TYPE_CUSTOM", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 1037 "parser.tab.cc"
    break;

  case 24: // statement: LCB n_statements RCB
#line 152 "parser.yy"
                                {
                yylhs.value.as < Node * > () = new Node("BODY", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                }
#line 1046 "parser.tab.cc"
    break;

  case 25: // statement: IF LP expression RP statement else_case
#line 156 "parser.yy"
                                                    {
                  yylhs.value.as < Node * > () = new Node("IF", "", yylineno);
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                }
#line 1057 "parser.tab.cc"
    break;

  case 26: // statement: WHILE LP expression RP statement
#line 162 "parser.yy"
                                             {
                  yylhs.value.as < Node * > () = new Node("WHILE", "", yylineno);
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                }
#line 1067 "parser.tab.cc"
    break;

  case 27: // statement: PRINTLN LP expression RP SC
#line 167 "parser.yy"
                                        {
                  yylhs.value.as < Node * > () = new Node("PRINTLN", "", yylineno);
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                }
#line 1076 "parser.tab.cc"
    break;

  case 28: // statement: identifier ASSIGN expression SC
#line 171 "parser.yy"
                                           {
                  yylhs.value.as < Node * > () = new Node("IDASSIGN", "", yylineno);
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          }
#line 1086 "parser.tab.cc"
    break;

  case 29: // statement: identifier LB expression RB ASSIGN expression SC
#line 176 "parser.yy"
                                                             {
                  yylhs.value.as < Node * > () = new Node("LISTASSIGN", "", yylineno);
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          }
#line 1097 "parser.tab.cc"
    break;

  case 30: // else_case: %empty
#line 184 "parser.yy"
                  {
              yylhs.value.as < Node * > () = new Node("NO_ELSE", "", yylineno);
            }
#line 1105 "parser.tab.cc"
    break;

  case 31: // else_case: ELSE statement
#line 187 "parser.yy"
                           {
              yylhs.value.as < Node * > () = new Node("ELSE", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1114 "parser.tab.cc"
    break;

  case 32: // n_statements: %empty
#line 193 "parser.yy"
                     {
                yylhs.value.as < Node * > () = new Node("STATEMENT_EMPTY", "", yylineno);
              }
#line 1122 "parser.tab.cc"
    break;

  case 33: // n_statements: statement n_statements
#line 196 "parser.yy"
                                     {
                yylhs.value.as < Node * > () = new Node("STATEMENT_NONEMPTY", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1132 "parser.tab.cc"
    break;

  case 34: // expression: expression PLUSOP expression
#line 203 "parser.yy"
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
#line 1147 "parser.tab.cc"
    break;

  case 35: // expression: expression MINUSOP expression
#line 213 "parser.yy"
                                            {
                            yylhs.value.as < Node * > () = new Node("SubExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r2 "); */
                          }
#line 1158 "parser.tab.cc"
    break;

  case 36: // expression: expression MULTOP expression
#line 219 "parser.yy"
                                           {
                            yylhs.value.as < Node * > () = new Node("MultExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r3 "); */
                          }
#line 1169 "parser.tab.cc"
    break;

  case 37: // expression: expression DIVOP expression
#line 225 "parser.yy"
                                          {
                            yylhs.value.as < Node * > () = new Node("DIVOPExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r4 "); */
                          }
#line 1180 "parser.tab.cc"
    break;

  case 38: // expression: expression LOGICAND expression
#line 231 "parser.yy"
                                             {
                            yylhs.value.as < Node * > () = new Node("LOGICANDExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r4 "); */
                          }
#line 1191 "parser.tab.cc"
    break;

  case 39: // expression: expression LOGICOR expression
#line 237 "parser.yy"
                                            {
                            yylhs.value.as < Node * > () = new Node("LOGICORExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r4 "); */
                          }
#line 1202 "parser.tab.cc"
    break;

  case 40: // expression: expression LT expression
#line 243 "parser.yy"
                                       {
                            yylhs.value.as < Node * > () = new Node("LTExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r4 "); */
                          }
#line 1213 "parser.tab.cc"
    break;

  case 41: // expression: expression GT expression
#line 249 "parser.yy"
                                       {
                            yylhs.value.as < Node * > () = new Node("GTExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r4 "); */
                          }
#line 1224 "parser.tab.cc"
    break;

  case 42: // expression: expression EQUAL expression
#line 255 "parser.yy"
                                          {
                            yylhs.value.as < Node * > () = new Node("EQUALExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r4 "); */
                          }
#line 1235 "parser.tab.cc"
    break;

  case 43: // expression: expression LB expression RB
#line 261 "parser.yy"
                                          {
                            yylhs.value.as < Node * > () = new Node("LBRBExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            /* printf("r4 "); */
                          }
#line 1246 "parser.tab.cc"
    break;

  case 44: // expression: expression DOT LENGTH
#line 267 "parser.yy"
                                    {
                            yylhs.value.as < Node * > () = new Node("DOTLENGTHExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            /* printf("r4 "); */
                          }
#line 1256 "parser.tab.cc"
    break;

  case 45: // expression: expression DOT identifier LP method_call1 RP
#line 272 "parser.yy"
                                                           {
                            yylhs.value.as < Node * > () = new Node("DOTIDExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            /* printf("r4 "); */
                          }
#line 1267 "parser.tab.cc"
    break;

  case 46: // expression: factor
#line 278 "parser.yy"
                          {yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); /* printf("r5 ");*/}
#line 1273 "parser.tab.cc"
    break;

  case 47: // expression: TRUE
#line 279 "parser.yy"
                   {yylhs.value.as < Node * > () = new Node("TRUE", "", yylineno);}
#line 1279 "parser.tab.cc"
    break;

  case 48: // expression: FALSE
#line 280 "parser.yy"
                    {yylhs.value.as < Node * > () = new Node("FALSE", "", yylineno);}
#line 1285 "parser.tab.cc"
    break;

  case 49: // expression: identifier
#line 281 "parser.yy"
                         {yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();}
#line 1291 "parser.tab.cc"
    break;

  case 50: // expression: THIS
#line 282 "parser.yy"
                   {yylhs.value.as < Node * > () = new Node("THIS", "", yylineno);}
#line 1297 "parser.tab.cc"
    break;

  case 51: // expression: NEW TYPE_INT LB expression RB
#line 283 "parser.yy"
                                            {
                            yylhs.value.as < Node * > () = new Node("NEW_LIST", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                          }
#line 1306 "parser.tab.cc"
    break;

  case 52: // expression: NEW identifier LP RP
#line 287 "parser.yy"
                                   {
                            yylhs.value.as < Node * > () = new Node("NEW_OBJECT", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            }
#line 1315 "parser.tab.cc"
    break;

  case 53: // expression: NOT expression
#line 291 "parser.yy"
                             {
                            yylhs.value.as < Node * > () = new Node("NOT", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                          }
#line 1324 "parser.tab.cc"
    break;

  case 54: // method_call1: %empty
#line 297 "parser.yy"
                     {
                  yylhs.value.as < Node * > () = new Node("MethodCall_EMPTY", "", yylineno);
                }
#line 1332 "parser.tab.cc"
    break;

  case 55: // method_call1: expression
#line 300 "parser.yy"
                         {
              yylhs.value.as < Node * > () = new Node("MethodCall_NONEMPTY", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1341 "parser.tab.cc"
    break;

  case 56: // method_call1: expression COMMA method_call2
#line 304 "parser.yy"
                                            {
                          yylhs.value.as < Node * > () = new Node("MethodCall_1_NONEMPTY", "", yylineno);
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                          }
#line 1351 "parser.tab.cc"
    break;

  case 57: // method_call2: expression
#line 311 "parser.yy"
                         {
              yylhs.value.as < Node * > () = new Node("MethodCall_NONEMPTY", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1360 "parser.tab.cc"
    break;

  case 58: // method_call2: expression COMMA method_call2
#line 315 "parser.yy"
                                            {
                          yylhs.value.as < Node * > () = new Node("MethodCall_NONEMPTY", "", yylineno);
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                          }
#line 1370 "parser.tab.cc"
    break;

  case 59: // factor: INT
#line 323 "parser.yy"
                          {  yylhs.value.as < Node * > () = new Node("Int", yystack_[0].value.as < std::string > (), yylineno); /* printf("r5 ");  Here we create a leaf node Int. The value of the leaf node is $1 */}
#line 1376 "parser.tab.cc"
    break;

  case 60: // factor: LP expression RP
#line 324 "parser.yy"
                               { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); /* printf("r6 ");  simply return the expression */}
#line 1382 "parser.tab.cc"
    break;

  case 61: // identifier: ID
#line 327 "parser.yy"
               { yylhs.value.as < Node * > () = new Node("ID", yystack_[0].value.as < std::string > (), yylineno);}
#line 1388 "parser.tab.cc"
    break;


#line 1392 "parser.tab.cc"

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


  const signed char parser::yypact_ninf_ = -59;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
       4,    14,    45,   -59,    42,    12,   -59,    12,    55,    42,
     -59,    47,    60,   -59,   -59,    67,    64,    68,    63,   -59,
      73,    64,    12,   -59,    74,    72,    64,    79,    73,   -59,
      96,    77,   -59,    12,   -59,   -59,   -59,   110,   111,   100,
      64,   102,   112,    12,   103,   116,   113,    12,   365,    64,
     121,    -2,   123,   125,   134,   365,   117,   365,   -16,   -59,
     135,    -2,   130,   -16,    23,    23,    23,   -59,    23,   -59,
      23,    23,    -2,   -59,   -59,   -59,    23,   -59,   -59,   -59,
      17,    23,   120,   -59,   -59,   131,   164,   154,   173,   206,
      -2,   213,   128,   149,   333,    23,    23,    23,    -2,    23,
      23,    23,    23,    23,    23,    23,     5,    -2,   151,   162,
     147,   -59,   167,   -59,    23,   172,   109,   109,    -9,   157,
     246,   366,    65,   369,   369,     2,    -9,   -59,   185,   -59,
     -59,   -59,    23,   188,   253,   -59,    -2,   -59,   -59,    23,
     286,   -59,   -59,   -59,   293,   193,   -59,    23,   -59,   326,
     -59,    23,   -59
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     5,     0,     1,     0,     0,     5,
      61,     0,     0,     3,     6,     0,     8,     0,    22,    21,
      11,     8,     0,    23,     0,     0,     0,     0,    11,     9,
       0,     0,    20,     0,     7,    12,    10,     0,     0,     0,
      14,     0,     0,     0,     0,     0,    15,     0,    17,    14,
       0,    32,     0,     0,     0,    17,     0,    17,    23,    16,
       0,    32,     0,     0,     0,     0,     0,    18,     0,    19,
       0,     0,     0,    33,    24,    59,     0,    47,    48,    50,
       0,     0,     0,    46,    49,     0,     0,     0,     0,     0,
      32,     0,     0,     0,    53,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,     0,    60,     0,     0,    34,    35,    36,    30,
       0,    38,    39,    40,    41,    42,    37,    44,     0,    26,
      27,    13,     0,     0,     0,    52,     0,    25,    43,    54,
       0,     4,    51,    31,    55,     0,    29,     0,    45,    57,
      56,     0,    58
  };

  const short
  parser::yypgoto_[] =
  {
     -59,   -59,   -59,   -59,   203,   -59,   192,    32,   186,   -59,
     166,   -42,   -22,   -41,   -59,   -58,     8,   -59,    69,   -59,
      -5
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     2,     3,     4,     8,     9,    20,    55,    27,    28,
      42,    56,    22,    57,   137,    62,   149,   145,   150,    83,
      84
  };

  const unsigned char
  parser::yytable_[] =
  {
      11,    70,    12,    73,    33,    95,    96,    97,    99,    51,
      61,    23,    71,    67,     1,    69,    23,    30,    43,    99,
      61,    23,    52,     5,    53,    54,   106,    43,    38,    75,
      76,    90,   112,   102,   103,    23,   105,   106,    46,    92,
      10,   127,    50,    58,    23,     6,    63,    10,    21,    61,
      58,     7,    58,    21,    10,    13,    63,   119,    15,    10,
      77,    78,    79,    80,    81,    10,   129,    63,    95,    96,
      97,    16,    82,    85,    86,    93,    87,    17,    88,    89,
      25,    24,    99,    26,    91,    63,    18,    19,    31,    94,
      32,    34,    37,    63,   100,   143,   102,   103,   104,   105,
     106,   128,    63,   116,   117,   118,    10,   120,   121,   122,
     123,   124,   125,   126,    97,    36,    41,    39,    40,    44,
      45,    47,   134,    95,    96,    97,    99,    48,    98,    60,
      64,    63,    65,    49,    95,    96,    97,    99,    68,   107,
     140,    66,    74,   105,   106,   114,    72,   144,    99,   100,
     101,   102,   103,   104,   105,   106,   115,    95,    96,    97,
     100,   101,   102,   103,   104,   105,   106,    95,    96,    97,
     130,    99,   108,   109,   131,   132,    95,    96,    97,   133,
     135,    99,   136,   100,   101,   102,   103,   104,   105,   106,
      99,   110,   139,   100,   101,   102,   103,   104,   105,   106,
     141,   148,   100,   101,   102,   103,   104,   105,   106,    95,
      96,    97,    14,    29,    35,    59,    95,    96,    97,     0,
     152,   113,     0,    99,     0,   111,     0,     0,     0,     0,
      99,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   100,   101,   102,   103,   104,   105,   106,    95,
      96,    97,     0,     0,     0,     0,    95,    96,    97,     0,
       0,     0,     0,    99,   138,     0,     0,     0,     0,     0,
      99,   142,     0,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   100,   101,   102,   103,   104,   105,   106,    95,
      96,    97,     0,     0,     0,     0,    95,    96,    97,     0,
       0,     0,     0,    99,     0,   146,     0,     0,     0,     0,
      99,     0,     0,   147,     0,   100,   101,   102,   103,   104,
     105,   106,   100,   101,   102,   103,   104,   105,   106,    95,
      96,    97,     0,     0,     0,     0,    95,    96,    97,     0,
       0,     0,     0,    99,     0,     0,   151,     0,     0,     0,
      99,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   100,   101,   102,   103,   104,   105,   106,    95,
      96,    97,    95,    96,    97,     0,    51,     0,     0,     0,
       0,     0,     0,    99,     0,     0,    99,    18,    19,    52,
       0,    53,    54,     0,     0,     0,     0,   102,   103,   104,
     105,   106,     0,   105,   106,     0,     0,    10
  };

  const short
  parser::yycheck_[] =
  {
       5,    17,     7,    61,    26,     3,     4,     5,    17,    11,
      51,    16,    28,    55,    10,    57,    21,    22,    40,    17,
      61,    26,    24,     9,    26,    27,    35,    49,    33,     6,
       7,    72,    90,    31,    32,    40,    34,    35,    43,    22,
      42,    36,    47,    48,    49,     0,    51,    42,    16,    90,
      55,     9,    57,    21,    42,     0,    61,    98,    11,    42,
      37,    38,    39,    40,    41,    42,   107,    72,     3,     4,
       5,    11,    64,    65,    66,    80,    68,    10,    70,    71,
      17,    13,    17,    10,    76,    90,    22,    23,    14,    81,
      18,    12,    15,    98,    29,   136,    31,    32,    33,    34,
      35,   106,   107,    95,    96,    97,    42,    99,   100,   101,
     102,   103,   104,   105,     5,    19,    16,     7,     7,    17,
       8,    18,   114,     3,     4,     5,    17,    11,     8,     8,
       7,   136,     7,    20,     3,     4,     5,    17,    21,     8,
     132,     7,    12,    34,    35,    17,    11,   139,    17,    29,
      30,    31,    32,    33,    34,    35,     7,     3,     4,     5,
      29,    30,    31,    32,    33,    34,    35,     3,     4,     5,
      19,    17,     8,    19,    12,    28,     3,     4,     5,    12,
       8,    17,    25,    29,    30,    31,    32,    33,    34,    35,
      17,    18,     7,    29,    30,    31,    32,    33,    34,    35,
      12,     8,    29,    30,    31,    32,    33,    34,    35,     3,
       4,     5,     9,    21,    28,    49,     3,     4,     5,    -1,
     151,     8,    -1,    17,    -1,    19,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      34,    35,    29,    30,    31,    32,    33,    34,    35,     3,
       4,     5,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      34,    35,    29,    30,    31,    32,    33,    34,    35,     3,
       4,     5,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,    -1,    17,    -1,    19,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    20,    -1,    29,    30,    31,    32,    33,
      34,    35,    29,    30,    31,    32,    33,    34,    35,     3,
       4,     5,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,    -1,    17,    -1,    -1,    20,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      34,    35,    29,    30,    31,    32,    33,    34,    35,     3,
       4,     5,     3,     4,     5,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    -1,    -1,    17,    22,    23,    24,
      -1,    26,    27,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    -1,    34,    35,    -1,    -1,    42
  };

  const signed char
  parser::yystos_[] =
  {
       0,    10,    44,    45,    46,     9,     0,     9,    47,    48,
      42,    63,    63,     0,    47,    11,    11,    10,    22,    23,
      49,    50,    55,    63,    13,    17,    10,    51,    52,    49,
      63,    14,    18,    55,    12,    51,    19,    15,    63,     7,
       7,    16,    53,    55,    17,     8,    63,    18,    11,    20,
      63,    11,    24,    26,    27,    50,    54,    56,    63,    53,
       8,    56,    58,    63,     7,     7,     7,    54,    21,    54,
      17,    28,    11,    58,    12,     6,     7,    37,    38,    39,
      40,    41,    59,    62,    63,    59,    59,    59,    59,    59,
      56,    59,    22,    63,    59,     3,     4,     5,     8,    17,
      29,    30,    31,    32,    33,    34,    35,     8,     8,    19,
      18,    19,    58,     8,    17,     7,    59,    59,    59,    56,
      59,    59,    59,    59,    59,    59,    59,    36,    63,    56,
      19,    12,    28,    12,    59,     8,    25,    57,    18,     7,
      59,    12,    18,    56,    59,    60,    19,    20,     8,    59,
      61,    20,    61
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    43,    44,    45,    46,    47,    47,    48,    49,    49,
      50,    51,    51,    52,    53,    53,    53,    54,    54,    54,
      55,    55,    55,    55,    56,    56,    56,    56,    56,    56,
      57,    57,    58,    58,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    60,    60,    60,    61,    61,    62,
      62,    63
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     3,    19,     0,     2,     6,     0,     2,
       3,     0,     2,    12,     0,     2,     4,     0,     2,     2,
       3,     1,     1,     1,     3,     6,     5,     5,     4,     7,
       0,     2,     0,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     3,     6,     1,     1,     1,     1,
       1,     5,     4,     2,     0,     1,     3,     1,     3,     1,
       3,     1
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
  "method_declaration", "n_type_identifiers",
  "n_var_declarations_or_statements", "type", "statement", "else_case",
  "n_statements", "expression", "method_call1", "method_call2", "factor",
  "identifier", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    37,    37,    40,    47,    56,    59,    64,    72,    75,
      81,    88,    91,    97,   106,   109,   114,   122,   125,   130,
     137,   140,   143,   146,   152,   156,   162,   167,   171,   176,
     184,   187,   193,   196,   203,   213,   219,   225,   231,   237,
     243,   249,   255,   261,   267,   272,   278,   279,   280,   281,
     282,   283,   287,   291,   297,   300,   304,   311,   315,   323,
     324,   327
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
#line 2004 "parser.tab.cc"

