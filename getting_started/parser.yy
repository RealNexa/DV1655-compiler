%skeleton "lalr1.cc" 
%defines
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor

%code requires{
  #include <string>
  #include "Node.h"
  #define USE_LEX_ONLY false //change this macro to true if you want to isolate the lexer from the parser.
}

%code{
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  
  Node* root;
  extern int yylineno;
}

// definition of set of tokens. All tokens are of type string
%token <std::string> PLUSOP MINUSOP MULTOP INT LP RP CLASS PUBLIC LCB RCB STATIC VOID MAIN STRING LB RB SC COMMA RETURN TYPE_INT TYPE_BOOLEAN IF ELSE WHILE PRINTLN ASSIGN LOGICAND LOGICOR LT GT EQUAL DIVOP DOT LENGTH TRUE FALSE THIS NEW NOT ID 
%token END 0 "end of file"

//definition of operator precedence. See https://www.gnu.org/software/bison/manual/bison.html#Precedence-Decl
%left LOGICOR
%left LOGICAND
%left EQUAL
%left LT GT
%left PLUSOP MINUSOP
%left MULTOP DIVOP

// definition of the production rules. All production rules are of type Node
%type <Node *> root expression factor method_call1 method_call2 identifier n_statements statement goal main_class n_class_declarations class_declaration else_case type n_var_declarations var_declaration n_method_declarations method_declaration n_type_identifiers n_var_declarations_or_statements

%%
root:       goal {root = $1;};


goal:  main_class n_class_declarations END {
                          $$ = new Node("GOAL", "", yylineno);
                          $$->children.push_back($1);
                          $$->children.push_back($2);
                          }
                          ;

main_class: PUBLIC CLASS identifier LCB PUBLIC STATIC VOID MAIN LP STRING LB RB identifier RP LCB statement n_statements RCB RCB {
  $$ = new Node("MAIN_CLASS", "", yylineno);
  $$->children.push_back($3);
  $$->children.push_back($13);
  $$->children.push_back($16);
  $$->children.push_back($17);
}
;

n_class_declarations: %empty {
                  $$ = new Node("CLASS_DECLARATION_EMPTY", "", yylineno);
                }
            | class_declaration n_class_declarations {
              $$ = new Node("CLASS_DECLARATION_NONEMPTY", "", yylineno);
              $$->children.push_back($1);
            };

class_declaration: CLASS identifier LCB n_var_declarations n_method_declarations RCB {
                $$ = new Node("CLASS_DECLARATION", "", yylineno);
                $$->children.push_back($2);
                $$->children.push_back($4);
                $$->children.push_back($5);
}
;

n_var_declarations: %empty {
                  $$ = new Node("VAR_DECLARATION_EMPTY", "", yylineno);
                }
            | var_declaration n_var_declarations {
              $$ = new Node("VAR_DECLARATION_NONEMPTY", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back($2);
            };

var_declaration: type identifier SC {
                  $$ = new Node("TYPEID;", "", yylineno);
                  $$->children.push_back($1);
                  $$->children.push_back($2);
                }
                ;

n_method_declarations: %empty {
                  $$ = new Node("METHOD_DECLARATION_EMPTY", "", yylineno);
                }
            | method_declaration n_method_declarations {
              $$ = new Node("METHOD_DECLARATION_NONEMPTY", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back($2);
            };

method_declaration: PUBLIC type identifier LP n_type_identifiers RP LCB n_var_declarations_or_statements RETURN expression SC RCB {
        $$ = new Node("METHOD_DECLARATION", "", yylineno);
        $$->children.push_back($2);
        $$->children.push_back($3);
        $$->children.push_back($5);
        $$->children.push_back($8);
        $$->children.push_back($10);
      };

n_type_identifiers: %empty {
                  $$ = new Node("TYPE_IDENTIFIERS_EMPTY", "", yylineno);
                }
            | type identifier {
              $$ = new Node("TYPE_IDENTIFIERS_NONEMPTY", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back($2);
            }
            | type identifier COMMA n_type_identifiers {
                          $$ = new Node("TYPE_IDENTIFIERS_NONEMPTY", "", yylineno);
                          $$->children.push_back($1);
                          $$->children.push_back($2);
                          $$->children.push_back($4);
                          }
            ;

n_var_declarations_or_statements: %empty {
                  $$ = new Node("VAR_DECLARATION_OR_STATEMENT_EMPTY", "", yylineno);
                }
                | var_declaration n_var_declarations_or_statements {
                  $$ = new Node("VAR_DECLARATION_NONEMPTY", "", yylineno);
                  $$->children.push_back($1);
                  $$->children.push_back($2);
                }
                | statement n_var_declarations_or_statements {
                  $$ = new Node("STATEMENT_NOEMPTY", "", yylineno);
                  $$->children.push_back($1);
                  $$->children.push_back($2);
                }
      ;

type: TYPE_INT LB RB {
        $$ = new Node("TYPE_INT_LIST", "", yylineno);
      }
      | TYPE_BOOLEAN {
        $$ = new Node("TYPE_BOOLEAN", "", yylineno);
      }
      | TYPE_INT {
        $$ = new Node("TYPE_INT", "", yylineno);
      }
      | identifier {
        $$ = new Node("TYPE_CUSTOM", "", yylineno);
        $$->children.push_back($1);
      }
      ;

statement: LCB n_statements RCB {
                $$ = new Node("BODY", "", yylineno);
                $$->children.push_back($2);
                }
          | IF LP expression RP statement else_case {
                  $$ = new Node("IF", "", yylineno);
                  $$->children.push_back($3);
                  $$->children.push_back($5);
                  $$->children.push_back($6);
                } 
          | WHILE LP expression RP statement {
                  $$ = new Node("WHILE", "", yylineno);
                  $$->children.push_back($3);
                  $$->children.push_back($5);
                }
          | PRINTLN LP expression RP SC {
                  $$ = new Node("PRINTLN", "", yylineno);
                  $$->children.push_back($3);
                }
          | identifier ASSIGN expression SC{
                  $$ = new Node("IDASSIGN", "", yylineno);
                  $$->children.push_back($1);
                  $$->children.push_back($3);
          }
          | identifier LB expression RB ASSIGN expression SC {
                  $$ = new Node("LISTASSIGN", "", yylineno);
                  $$->children.push_back($1);
                  $$->children.push_back($3);
                  $$->children.push_back($6);
          }
          ;

else_case: %empty {
              $$ = new Node("NO_ELSE", "", yylineno);
            }
          | ELSE statement {
              $$ = new Node("ELSE", "", yylineno);
              $$->children.push_back($2);
            }
          ;

n_statements: %empty {
                $$ = new Node("STATEMENT_EMPTY", "", yylineno);
              }
            | statement n_statements {
                $$ = new Node("STATEMENT_NONEMPTY", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back($2);
            }
            ;

expression: expression PLUSOP expression {      /*
                                                  Create a subtree that corresponds to the AddExpression
                                                  The root of the subtree is AddExpression
                                                  The children of the AddExpression subtree are the left hand side (expression accessed through $1) and right hand side of the expression (expression accessed through $3)
                                                */
                            $$ = new Node("AddExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            /* printf("r1 "); */
                          }
            | expression MINUSOP expression {
                            $$ = new Node("SubExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            /* printf("r2 "); */
                          }
            | expression MULTOP expression {
                            $$ = new Node("MultExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            /* printf("r3 "); */
                          }
            | expression DIVOP expression {
                            $$ = new Node("DIVOPExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            /* printf("r4 "); */
                          }
            | expression LOGICAND expression {
                            $$ = new Node("LOGICANDExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            /* printf("r4 "); */
                          }
            | expression LOGICOR expression {
                            $$ = new Node("LOGICORExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            /* printf("r4 "); */
                          }
            | expression LT expression {
                            $$ = new Node("LTExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            /* printf("r4 "); */
                          }
            | expression GT expression {
                            $$ = new Node("GTExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            /* printf("r4 "); */
                          }
            | expression EQUAL expression {
                            $$ = new Node("EQUALExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            /* printf("r4 "); */
                          }
            | expression LB expression RB {
                            $$ = new Node("LBRBExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            /* printf("r4 "); */
                          }
            | expression DOT LENGTH {
                            $$ = new Node("DOTLENGTHExpression", "", yylineno);
                            $$->children.push_back($1);
                            /* printf("r4 "); */
                          }
            | expression DOT identifier LP method_call1 RP {
                            $$ = new Node("DOTIDExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($5);
                            /* printf("r4 "); */
                          }
            | factor      {$$ = $1; /* printf("r5 ");*/}
            | TRUE {$$ = new Node("TRUE", "", yylineno);}
            | FALSE {$$ = new Node("FALSE", "", yylineno);}
            | identifier {$$ = $1;}
            | THIS {$$ = new Node("THIS", "", yylineno);}
            | NEW TYPE_INT LB expression RB {
                            $$ = new Node("NEW_LIST", "", yylineno);
                            $$->children.push_back($4);
                          }
            | NEW identifier LP RP {
                            $$ = new Node("NEW_OBJECT", "", yylineno);
                            $$->children.push_back($2);
                            }
            | NOT expression {
                            $$ = new Node("NOT", "", yylineno);
                            $$->children.push_back($2);
                          }
            ;

method_call1: %empty {
                  $$ = new Node("MethodCall_EMPTY", "", yylineno);
                }
            | expression {
              $$ = new Node("MethodCall_NONEMPTY", "", yylineno);
              $$->children.push_back($1);
            }
            | expression COMMA method_call2 {
                          $$ = new Node("MethodCall_1_NONEMPTY", "", yylineno);
                          $$->children.push_back($1);
                          $$->children.push_back($3);
                          }
            ;

method_call2: expression {
              $$ = new Node("MethodCall_NONEMPTY", "", yylineno);
              $$->children.push_back($1);
            }
            | expression COMMA method_call2 {
                          $$ = new Node("MethodCall_NONEMPTY", "", yylineno);
                          $$->children.push_back($1);
                          $$->children.push_back($3);
                          }
            ;
            
            
factor:     INT           {  $$ = new Node("Int", $1, yylineno); /* printf("r5 ");  Here we create a leaf node Int. The value of the leaf node is $1 */}
            | LP expression RP { $$ = $2; /* printf("r6 ");  simply return the expression */}
    ;

identifier: ID { $$ = new Node("ID", $1, yylineno);};