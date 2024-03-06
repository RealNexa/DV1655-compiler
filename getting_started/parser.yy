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
  
  BaseNode* root;
  extern int yylineno;
}

// definition of set of tokens. All tokens are of type string
%token <std::string> PLUSOP MINUSOP MULTOP INT LP RP CLASS PUBLIC LCB RCB STATIC VOID MAIN STRING LB RB SC COMMA RETURN TYPE_INT TYPE_BOOLEAN IF ELSE WHILE PRINTLN ASSIGN LOGICAND LOGICOR LT GT EQUAL DIVOP DOT LENGTH TRUE FALSE THIS NEW NOT ID 
%token END 0 "end of file"

//definition of operator precedence. See https://www.gnu.org/software/bison/manual/bison.html#Preced1ence-Decl
%left COMMA
%right ASSIGN
%left LOGICOR
%left LOGICAND
%left EQUAL
%left LT GT
%left PLUSOP MINUSOP
%left MULTOP DIVOP
%right NEW
%right NOT
%left DOT LB RB


// definition of the production rules. All production rules are of type Node
%type <BaseNode *> root
%type <BaseNode *> expression factor method_call1 method_call2 identifier n_statements statement goal main_class n_class_declarations class_declaration else_case type n_var_declarations var_declaration n_method_declarations method_declaration n_type_identifiers n_var_declarations_or_statements type_identifier one_or_more_statements n2_type_identifiers

%%
root:       goal {root = $1;};


goal:  main_class n_class_declarations END {
                          $$ = new GoalNode("GOAL", "", yylineno);
                          $$->children.push_back($1);
                          $$->children.push_back($2);
                          }
                          ;

main_class: PUBLIC CLASS identifier LCB PUBLIC STATIC VOID MAIN LP STRING LB RB identifier RP LCB one_or_more_statements RCB RCB {
  $$ = new MainClassNode("MAIN_CLASS", "", yylineno);
  $$->children.push_back($3);
  $$->children.push_back($13);
  $$->children.push_back($16);
  /*$$->children.push_back($17);*/
}
;

n_class_declarations: %empty {
                   $$ = new NonMainClassNode("NON_MAIN_CLASSES", "", yylineno);
                }
            | n_class_declarations class_declaration{
              $$ = $1;
              $$->children.push_back($2);
            }
;

class_declaration: CLASS identifier LCB n_var_declarations n_method_declarations RCB {
                $$ = new ClassDeclarationNode("CLASS_DECLARATION", "", yylineno);
                $$->children.push_back($2);
                $$->children.push_back($4);
                $$->children.push_back($5);
}
;

n_var_declarations: %empty {
                  $$ = new VarDeclarationsNode("VAR_DECLARATIONS", "", yylineno);
                }
            | n_var_declarations var_declaration  {
              $$ = $1;
              $$->children.push_back($2);
            };

var_declaration: type identifier SC {
                  $$ = new TypeIdNode("TYPEID", "", yylineno);
                  $$->children.push_back($1);
                  $$->children.push_back($2);
                }
                ;

n_method_declarations: %empty {
                  $$ = new MethodDeclarationsNode("METHOD_DECLARATIONS", "", yylineno);
                }
            | n_method_declarations method_declaration {
              $$ = $1;
              $$->children.push_back($2);
            };

method_declaration: PUBLIC type identifier LP n_type_identifiers RP LCB n_var_declarations_or_statements RETURN expression SC RCB {
        $$ = new MethodDeclarationNode("METHOD_DECLARATION", "", yylineno);
        $$->children.push_back($2);
        $$->children.push_back($3);
        $$->children.push_back($5);
        $$->children.push_back($8);
        $$->children.push_back($10);
      };

n_type_identifiers: %empty {
                  $$ = new ParametersNode("PARAMETERS", "", yylineno);
                }
            | type_identifier {
              $$ = new ParametersNode("PARAMETERS", "", yylineno);
              $$->children.push_back($1);
            }
            | type_identifier COMMA n2_type_identifiers {
                          $$ = $3;
                          $$->children.push_back($1);
                          }
            ;

n2_type_identifiers: type_identifier {
            $$ = new ParametersNode("PARAMETERS", "", yylineno);
            $$->children.push_back($1);
}
| type_identifier COMMA n2_type_identifiers {
            $$ = $3;
            $$->children.push_back($1);
}
;

type_identifier: type identifier {
    $$ = new ParameterNode("PARAMETER", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
  }
;

n_var_declarations_or_statements: %empty {
                  $$ = new BodyNode("BODY", "", yylineno);
                }
                | n_var_declarations_or_statements var_declaration{
                  $$ = $1;
                  $$->children.push_back($2);
                }
                | n_var_declarations_or_statements statement {
                  $$ = $1;
                  $$->children.push_back($2);
                }
      ;

type: TYPE_INT LB RB {
        $$ = new TypeIntListNode("TYPE_INT_LIST", "", yylineno);
      }
      | TYPE_BOOLEAN {
        $$ = new TypeBooleanNode("TYPE_BOOLEAN", "", yylineno);
      }
      | TYPE_INT {
        $$ = new TypeIntNode("TYPE_INT", "", yylineno);
      }
      | identifier {
        $$ = new TypeCustomNode("TYPE_CUSTOM", $1->value, yylineno);
        //$$->children.push_back($1);
      }
      ;

one_or_more_statements: n_statements statement {
  $$ = $1;
  $$->children.push_back($2);
}
;

statement: LCB n_statements RCB {
                $$ = $2;
                }
          | IF LP expression RP statement else_case {
                  $$ = new IfNode("IF", "", yylineno);
                  $$->children.push_back($3);
                  $$->children.push_back($5);
                  $$->children.push_back($6);
                } 
          | WHILE LP expression RP statement {
                  $$ = new WhileNode("WHILE", "", yylineno);
                  $$->children.push_back($3);
                  $$->children.push_back($5);
                }
          | PRINTLN LP expression RP SC {
                  $$ = new PrintLnNode("PRINTLN", "", yylineno);
                  $$->children.push_back($3);
                }
          | identifier ASSIGN expression SC{
                  $$ = new IdAssignNode("IDASSIGN", "", yylineno);
                  $$->children.push_back($1);
                  $$->children.push_back($3);
          }
          | identifier LB expression RB ASSIGN expression SC {
                  $$ = new ListAssignNode("LISTASSIGN", "", yylineno);
                  $$->children.push_back($1);
                  $$->children.push_back($3);
                  $$->children.push_back($6);
          }
          ;

else_case: %empty {
              $$ = new NoElseNode("NO_ELSE", "", yylineno);
            }
          | ELSE statement {
              $$ = new ElseNode("ELSE", "", yylineno);
              $$->children.push_back($2);
            }
          ;

n_statements: %empty {
                $$ = new ScopeNode("SCOPE", "", yylineno);
              }
            | n_statements statement {
                $$ = $1;
                $$->children.push_back($2);
            }
            ;

expression: expression PLUSOP expression {      /*
                                                  Create a subtree that corresponds to the AddExpression
                                                  The root of the subtree is AddExpression
                                                  The children of the AddExpression subtree are the left hand side (expression accessed through $1) and right hand side of the expression (expression accessed through $3)
                                                */
                            $$ = new AddExpressionNode("AddExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            /* printf("r1 "); */
                          }
            | expression MINUSOP expression {
                            $$ = new SubExpressionNode("SubExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            /* printf("r2 "); */
                          }
            | expression MULTOP expression {
                            $$ = new MultExpressionNode("MultExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            /* printf("r3 "); */
                          }
            | expression DIVOP expression {
                            $$ = new DivExpressionNode("DIVOPExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            /* printf("r4 "); */
                          }
            | expression LOGICAND expression {
                            $$ = new LogicAndExpressionNode("LOGICANDExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            /* printf("r4 "); */
                          }
            | expression LOGICOR expression {
                            $$ = new LogicOrExpressionNode("LOGICORExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            /* printf("r4 "); */
                          }
            | expression LT expression {
                            $$ = new LtExpressionNode("LTExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            /* printf("r4 "); */
                          }
            | expression GT expression {
                            $$ = new GtExpressionNode("GTExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            /* printf("r4 "); */
                          }
            | expression EQUAL expression {
                            $$ = new EqualExpressionNode("EQUALExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            /* printf("r4 "); */
                          }
            | expression LB expression RB {
                            $$ = new LBRBExpressionNode("LBRBExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            /* printf("r4 "); */
                          }
            | expression DOT LENGTH {
                            $$ = new DotLengthExpressionNode("DOTLENGTHExpression", "", yylineno);
                            $$->children.push_back($1);
                            /* printf("r4 "); */
                          }
            | expression DOT identifier LP method_call1 RP {
                            $$ = new MethodCallNode("METHOD_CALL", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            $$->children.push_back($5);
                            /* printf("r4 "); */
                          }
            | factor      {$$ = $1; /* printf("r5 ");*/}
            | TRUE {$$ = new TrueNode("TRUE", "", yylineno);}
            | FALSE {$$ = new FalseNode("FALSE", "", yylineno);}
            | identifier {$$ = $1;}
            | THIS {$$ = new ThisNode("THIS", "", yylineno);}
            | NEW TYPE_INT LB expression RB {
                            $$ = new NewListNode("NEW_LIST", "", yylineno);
                            $$->children.push_back($4);
                          }
            | NEW identifier LP RP {
                            $$ = new NewObjectNode("NEW_OBJECT", "", yylineno);
                            $$->children.push_back($2);
                            }
            | NOT expression {
                            $$ = new NotNode("NOT", "", yylineno);
                            $$->children.push_back($2);
                          }
            ;

method_call1: %empty {
                  $$ = new NoArgumentsNode("NO_ARGUMENTS", "", yylineno);
                }
            | expression {
              $$ = new ArgumentsNode("ARGUMENTS", "", yylineno);
              $$->children.push_back($1);
            }
            | expression COMMA method_call2 {
                          $$ = $3;
                          $$->children.push_back($1);
                          }
            ;

method_call2: expression {
              $$ = new ArgumentsNode("ARGUMENTS", "", yylineno);
              $$->children.push_back($1);
            }
            | expression COMMA method_call2 {
                          $$ = $3;
                          $$->children.push_back($1);
                          }
            ;
            
factor:     INT           {  $$ = new IntNode("TYPE_INT", $1, yylineno); /* printf("r5 ");  Here we create a leaf node Int. The value of the leaf node is $1 */}
            | LP expression RP { $$ = $2; /* printf("r6 ");  simply return the expression */}
    ;

identifier: ID { $$ = new IdNode("ID", $1, yylineno);};