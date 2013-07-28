/***** CLAIRE Compilation of file c:\claire\v3.3\src\compile\gexp.cl 
         [version 3.3.46 / safety 5] Sun Feb 15 15:37:28 2009 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
#include <Generate.h>
ClaireBoolean * c_func_any(OID v2548)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v2548),Kernel._bag))
     { OID  v4715;
      { OID gc_local;
        ITERATE(v1744);
        v4715= Kernel.cfalse;
        for (START(OBJECT(bag,v2548)); NEXT(v1744);)
        if (c_func_any(v1744) != CTRUE)
         { v4715 = Kernel.ctrue;
          break;} 
        else ;} 
      Result = not_any(v4715);
      } 
    else if (INHERIT(OWNER(v2548),Language._Construct))
     { if (((INHERIT(OBJECT(ClaireObject,v2548)->isa,Language._Set)) || 
            (INHERIT(OBJECT(ClaireObject,v2548)->isa,Language._List))) || 
          (INHERIT(OBJECT(ClaireObject,v2548)->isa,Language._Tuple)))
       { ClaireBoolean *v_and;
        { v_and = ((OBJECT(Construct,v2548)->args->length < 15) ? CTRUE : CFALSE);
          if (v_and == CFALSE) Result =CFALSE; 
          else { { OID  v9470;
              { ClaireBoolean * v8250;{ OID  v11392;
                  { set * v8252;{ set * v15711 = set::empty(Kernel.emptySet);
                      { OID gc_local;
                        ITERATE(v1744);
                        bag *v1744_support;
                        v1744_support = GC_OBJECT(list,OBJECT(Construct,v2548)->args);
                        for (START(v1744_support); NEXT(v1744);)
                        if (c_func_any(v1744) != CTRUE)
                         v15711->addFast(v1744);
                        } 
                      v8252 = GC_OBJECT(set,v15711);
                      } 
                    
                    v11392=_oid_(v8252);} 
                  v8250 = boolean_I_any(v11392);
                  } 
                
                v9470=_oid_(v8250);} 
              v_and = ((v9470 != Kernel.ctrue) ? CTRUE : CFALSE);
              } 
            if (v_and == CFALSE) Result =CFALSE; 
            else Result = CTRUE;} 
          } 
        } 
      else Result = CFALSE;
        } 
    else if (INHERIT(OWNER(v2548),Language._If))
     { ClaireBoolean *v_and;
      { v_and = c_func_any(GC_OID(OBJECT(If,v2548)->test));
        if (v_and == CFALSE) Result =CFALSE; 
        else { v_and = c_func_any(GC_OID(OBJECT(If,v2548)->arg));
          if (v_and == CFALSE) Result =CFALSE; 
          else { v_and = c_func_any(GC_OID(OBJECT(If,v2548)->other));
            if (v_and == CFALSE) Result =CFALSE; 
            else { v_and = stupid_t_any2(GC_OID(OBJECT(If,v2548)->arg),GC_OID(OBJECT(If,v2548)->other));
              if (v_and == CFALSE) Result =CFALSE; 
              else { { int  v1734 = 4;
                  OID  v1744 = GC_OID(OBJECT(If,v2548)->other);
                  { OID v15730;{ OID gc_local;
                      v15730= _oid_(CFALSE);
                      while ((v1734 > 0))
                      { GC_LOOP;
                        if (INHERIT(OWNER(v1744),Language._If))
                         { GC__OID(v1744 = OBJECT(If,v1744)->other, 1);
                          v1734= (v1734-1);
                          } 
                        else { v15730 = Kernel.ctrue;
                            break;} 
                          GC_UNLOOP;} 
                      } 
                    
                    v_and=OBJECT(ClaireBoolean,v15730);} 
                  } 
                if (v_and == CFALSE) Result =CFALSE; 
                else Result = CTRUE;} 
              } 
            } 
          } 
        } 
      } 
    else if (INHERIT(OWNER(v2548),Language._Assign))
     Result = c_func_any(GC_OID(OBJECT(Assign,v2548)->arg));
    else if (INHERIT(OWNER(v2548),Language._Gassign))
     Result = c_func_any(GC_OID(OBJECT(Gassign,v2548)->arg));
    else if (INHERIT(OWNER(v2548),Optimize._to_protect))
     Result = c_func_any(GC_OID(OBJECT(Compile_to_protect,v2548)->arg));
    else if (INHERIT(OWNER(v2548),Language._And))
     Result = c_func_any(GC_OID(_oid_(OBJECT(And,v2548)->args)));
    else if (INHERIT(OWNER(v2548),Language._Or))
     Result = c_func_any(GC_OID(_oid_(OBJECT(Or,v2548)->args)));
    else if (INHERIT(OWNER(v2548),Language._Call))
     Result = c_func_any(GC_OID(_oid_(OBJECT(Call,v2548)->args)));
    else if (INHERIT(OWNER(v2548),Language._Call_method))
     Result = ((c_func_any(GC_OID(_oid_(OBJECT(Call_method,v2548)->args))) == CTRUE) ? ((_oid_(OBJECT(Call_method,v2548)->arg) != Generate._starclose_exception_star->value) ? CTRUE: CFALSE): CFALSE);
    else if (INHERIT(OWNER(v2548),Language._Call_slot))
     Result = c_func_any(GC_OID(OBJECT(Call_slot,v2548)->arg));
    else if (INHERIT(OWNER(v2548),Language._Call_table))
     Result = c_func_any(GC_OID(OBJECT(Call_table,v2548)->arg));
    else if (INHERIT(OWNER(v2548),Language._Call_array))
     Result = c_func_any(GC_OID(OBJECT(Call_array,v2548)->arg));
    else Result = ((INHERIT(OWNER(v2548),Language._Update)) ?
      ((c_func_any(GC_OID(OBJECT(Update,v2548)->value)) == CTRUE) ? ((c_func_any(GC_OID(OBJECT(Update,v2548)->arg)) == CTRUE) ? CTRUE: CFALSE): CFALSE) :
      ((INHERIT(OWNER(v2548),Language._Cast)) ?
        c_func_any(GC_OID(OBJECT(Cast,v2548)->arg)) :
        ((INHERIT(OWNER(v2548),Optimize._to_C)) ?
          c_func_any(GC_OID(OBJECT(Compile_to_C,v2548)->arg)) :
          ((INHERIT(OWNER(v2548),Optimize._to_CL)) ?
            c_func_any(GC_OID(OBJECT(Compile_to_CL,v2548)->arg)) :
            ((INHERIT(OWNER(v2548),Kernel._thing)) ? CTRUE : 
            ((INHERIT(OWNER(v2548),Kernel._integer)) ? CTRUE : 
            ((Kernel._string == OWNER(v2548)) ? CTRUE : 
            ((INHERIT(OWNER(v2548),Kernel._char)) ? CTRUE : 
            ((Kernel._float == OWNER(v2548)) ? CTRUE : 
            ((INHERIT(OWNER(v2548),Language._Variable)) ? CTRUE : 
            ((INHERIT(OWNER(v2548),Core._global_variable)) ? CTRUE : 
            ((INHERIT(OWNER(v2548),Kernel._function)) ? CTRUE : 
            ((INHERIT(OWNER(v2548),Kernel._symbol)) ? CTRUE : 
            ((v2548 == CNULL) ? CTRUE : 
            ((Kernel._boolean == OWNER(v2548)) ? CTRUE : 
            ((INHERIT(OWNER(v2548),Kernel._class)) ? CTRUE : 
            ((INHERIT(OWNER(v2548),Kernel._environment)) ? CTRUE : 
            CFALSE))))))))))))) ) ) ) );
    GC_UNBIND; return (Result);} 
  } 

void  expression_thing(thing *v2548,OID v332)
{ (*Generate.produce)(Generate.PRODUCER->value,
    _oid_(v2548));
  } 

void  expression_integer(int v2548,OID v332)
{ princ_integer(v2548);
  } 

void  expression_any(OID v2548,OID v332)
{ (*Generate.produce)(Generate.PRODUCER->value,
    v2548);
  } 

void  expression_string(char *v2548,OID v332)
{ (*Generate.produce)(Generate.PRODUCER->value,
    _string_(v2548));
  } 

void  expression_float_(OID v6626,OID v6627)
{ expression_float(float_v(v6626),v6627);} 

void  expression_float(double v2548,OID v332)
{ princ_float(v2548);
  } 

void  expression_boolean(ClaireBoolean *v2548,OID v332)
{ (*Generate.produce)(Generate.PRODUCER->value,
    _oid_(v2548));
  } 

void  expression_environment(ClaireEnvironment *v2548,OID v332)
{ (*Generate.produce)(Generate.PRODUCER->value,
    _oid_(v2548));
  } 

void  expression_Variable(Variable *v2548,OID v332)
{ (*Language.ident)(Generate.PRODUCER->value,
    _oid_(v2548));
  } 

void  expression_global_variable(global_variable *v2548,OID v332)
{ (*Generate.produce)(Generate.PRODUCER->value,
    _oid_(v2548));
  } 

void  expression_Set(Set *v2548,OID v332)
{ GC_BIND;
  { OID  v15236;
    { if (((v2548->of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
       v15236 = _oid_(v2548->of);
      else v15236 = _oid_(Kernel._void);
        GC_OID(v15236);} 
    (*Generate.bag_expression)(Generate.PRODUCER->value,
      _oid_(Kernel._set),
      GC_OID(_oid_(v2548->args)),
      v15236,
      v332);
    } 
  GC_UNBIND;} 

void  expression_set2(set *v2548,OID v332)
{ if ((v2548->length == 0) && 
      (equal(_oid_(of_bag(v2548)),_oid_(Kernel.emptySet)) == CTRUE))
   princ_string("Kernel.emptySet");
  else (*Generate.bag_expression)(Generate.PRODUCER->value,
      _oid_(Kernel._set),
      _oid_(v2548),
      _oid_(of_bag(v2548)),
      v332);
    } 

void  expression_Tuple(Tuple *v2548,OID v332)
{ GC_BIND;
  (*Generate.bag_expression)(Generate.PRODUCER->value,
    _oid_(Kernel._tuple),
    GC_OID(_oid_(v2548->args)),
    _oid_(Kernel._void),
    v332);
  GC_UNBIND;} 

void  expression_tuple(tuple *v2548,OID v332)
{ (*Generate.bag_expression)(Generate.PRODUCER->value,
    _oid_(Kernel._tuple),
    _oid_(v2548),
    _oid_(Kernel._void),
    v332);
  } 

void  expression_List(List *v2548,OID v332)
{ GC_BIND;
  { OID  v16197;
    { if (((v2548->of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
       v16197 = _oid_(v2548->of);
      else v16197 = _oid_(Kernel._void);
        GC_OID(v16197);} 
    (*Generate.bag_expression)(Generate.PRODUCER->value,
      _oid_(Kernel._list),
      GC_OID(_oid_(v2548->args)),
      v16197,
      v332);
    } 
  GC_UNBIND;} 

void  expression_list(list *v2548,OID v332)
{ if ((v2548->length == 0) && 
      (equal(_oid_(of_bag(v2548)),_oid_(Kernel.emptySet)) == CTRUE))
   princ_string("Kernel.nil");
  else (*Generate.bag_expression)(Generate.PRODUCER->value,
      _oid_(Kernel._list),
      _oid_(v2548),
      _oid_(of_bag(v2548)),
      v332);
    } 

void  expression_Call2(Call *v2548,OID v332)
{ (*Generate.inline_exp)(Generate.PRODUCER->value,
    _oid_(v2548),
    v332);
  } 

void  expression_Call_method12(Call_method1 *v2548,OID v332)
{ (*Generate.inline_exp)(Generate.PRODUCER->value,
    _oid_(v2548),
    v332);
  } 

void  expression_Call_method22(Call_method2 *v2548,OID v332)
{ (*Generate.inline_exp)(Generate.PRODUCER->value,
    _oid_(v2548),
    v332);
  } 

void  expression_Call_method2(Call_method *v2548,OID v332)
{ (*Generate.inline_exp)(Generate.PRODUCER->value,
    _oid_(v2548),
    v332);
  } 

void  bexpression_any(OID v2548,OID v332)
{ if (INHERIT(OWNER(v2548),Language._Assign))
   { princ_string(copy_string("("));
    expression_Assign(OBJECT(Assign,v2548),v332);
    princ_string(copy_string(")"));
    } 
  else if (INHERIT(OWNER(v2548),Optimize._to_C))
   { princ_string(copy_string("("));
    (*Generate.expression)(v2548,
      v332);
    princ_string(copy_string(")"));
    } 
  else if (INHERIT(OWNER(v2548),Kernel._integer))
   { if (v2548 < 0)
     { princ_string(copy_string("("));
      expression_integer(v2548,v332);
      princ_string(copy_string(")"));
      } 
    else expression_integer(v2548,v332);
      } 
  else if (Kernel._float == OWNER(v2548))
   { if (float_v(v2548) < 0.0)
     { princ_string(copy_string("("));
      expression_float(float_v(v2548),v332);
      princ_string(copy_string(")"));
      } 
    else expression_float(float_v(v2548),v332);
      } 
  else (*Generate.expression)(v2548,
      v332);
    } 

void  expression_If(If *v2548,OID v332)
{ GC_BIND;
  princ_string("(");
  (*Optimize.bool_exp)(GC_OID(v2548->test),
    Kernel.ctrue,
    v332);
  princ_string(" ?");
  (Optimize.OPT->level = (Optimize.OPT->level+1));
  breakline_void();
  (*Generate.expression)(GC_OID(v2548->arg),
    v332);
  princ_string(" :");
  breakline_void();
  (*Generate.expression)(GC_OID(v2548->other),
    v332);
  princ_string(" )");
  (Optimize.OPT->level = (Optimize.OPT->level-1));
  GC_UNBIND;} 

void  expression_Assign(Assign *v2548,OID v332)
{ GC_BIND;
  { OID  v1744 = v2548->arg;
    OID  v1743 = v2548->var;
    if ((INHERIT(OWNER(v1744),Language._Call_method2)) && ((_oid_(OBJECT(Call_method,v1744)->arg) == Generate._star_plus_integer_star->value) && 
        ((equal((*(OBJECT(Call_method,v1744)->args))[1],v2548->var) == CTRUE) && 
          ((*(OBJECT(Call_method,v1744)->args))[2] == 1))))
     { princ_string(copy_string("++"));
      (*Generate.expression)(v1743,
        v332);
      princ_string(copy_string(""));
      } 
    else if ((boolean_I_any(v332) == CTRUE) && 
        ((Optimize.OPT->loop_gc == CTRUE) && 
          (inner2outer_ask_any(v1744) == CTRUE)))
     { OID  v6493;
      { if (INHERIT(OWNER(v1744),Optimize._to_protect))
         v6493 = OBJECT(Compile_to_protect,v1744)->arg;
        else v6493 = v1744;
          GC_OID(v6493);} 
      (*Generate.gc_protection_exp)(Generate.PRODUCER->value,
        v1743,
        Kernel.ctrue,
        v6493,
        v332);
      } 
    else (*Generate.exp_Assign)(Generate.PRODUCER->value,
        _oid_(v2548),
        v332);
      } 
  GC_UNBIND;} 

void  expression_to_protect(Compile_to_protect *v2548,OID v332)
{ (*Generate.exp_to_protect)(Generate.PRODUCER->value,
    _oid_(v2548),
    v332);
  } 

char * gc_protect_class(ClaireClass *v1723)
{ { char *Result ;
    Result = ((v1723 == Kernel._any) ?
      copy_string("GC_OID") :
      ((v1723 == Kernel._string) ?
        copy_string("GC_STRING") :
        ((v1723 == Kernel._array) ?
          copy_string("GC_ARRAY") :
          ((INHERIT(v1723,Kernel._object)) ?
            copy_string("GC_OBJECT") :
            copy_string("") ) ) ) );
    return (Result);} 
  } 

void  expression_Gassign(Gassign *v2548,OID v332)
{ (*Generate.gassign)(Generate.PRODUCER->value,
    _oid_(v2548),
    v332);
  } 

void  expression_And(And *v2548,OID v332)
{ GC_BIND;
  { ClaireBoolean * v1722 = ((v2548->args->length > 5) ? CTRUE : CFALSE);
    { OID gc_local;
      ITERATE(v1744);
      for (START(v2548->args); NEXT(v1744);)
      { princ_string(copy_string("("));
        (*Optimize.bool_exp)(v1744,
          Kernel.ctrue,
          v332);
        princ_string(copy_string(" ? "));
        if (v1722 == CTRUE)
         breakline_void();
        } 
      } 
    expression_boolean(CTRUE,v332);
    { OID gc_local;
      ITERATE(v1744);
      for (START(v2548->args); NEXT(v1744);)
      { princ_string(copy_string(": "));
        expression_boolean(CFALSE,v332);
        princ_string(copy_string(")"));
        } 
      } 
    } 
  GC_UNBIND;} 

void  expression_Or(Or *v2548,OID v332)
{ GC_BIND;
  { ClaireBoolean * v1722 = ((v2548->args->length > 5) ? CTRUE : CFALSE);
    { OID gc_local;
      ITERATE(v1744);
      for (START(v2548->args); NEXT(v1744);)
      { princ_string(copy_string("("));
        (*Optimize.bool_exp)(v1744,
          Kernel.ctrue,
          v332);
        princ_string(copy_string(" ? "));
        expression_boolean(CTRUE,v332);
        princ_string(copy_string(" : "));
        if (v1722 == CTRUE)
         breakline_void();
        } 
      } 
    expression_boolean(CFALSE,v332);
    { OID gc_local;
      ITERATE(v1744);
      for (START(v2548->args); NEXT(v1744);)
      princ_string(copy_string(")"));
      } 
    } 
  GC_UNBIND;} 

void  expression_to_CL(Compile_to_CL *v2548,OID v332)
{ GC_BIND;
  (*Generate.to_cl)(Generate.PRODUCER->value,
    v2548->arg,
    _oid_(v2548->set_arg),
    v332);
  GC_UNBIND;} 

void  expression_to_C(Compile_to_C *v2548,OID v332)
{ GC_BIND;
  (*Generate.to_c)(Generate.PRODUCER->value,
    v2548->arg,
    _oid_(v2548->set_arg),
    v332);
  GC_UNBIND;} 

void  expression_C_cast(Compile_C_cast *v2548,OID v332)
{ (*Kernel.cast_I)(Generate.PRODUCER->value,
    _oid_(v2548),
    v332);
  } 

void  expression_Call_slot(Call_slot *v2548,OID v332)
{ (*Generate.call_slot)(Generate.PRODUCER->value,
    _oid_(v2548),
    v332);
  } 

void  expression_Call_table(Call_table *v2548,OID v332)
{ (*Generate.call_table)(Generate.PRODUCER->value,
    _oid_(v2548),
    v332);
  } 

void  expression_Call_array(Call_array *v2548,OID v332)
{ (*Generate.call_array)(Generate.PRODUCER->value,
    _oid_(v2548),
    v332);
  } 

void  expression_Update(Update *v2548,OID v332)
{ (*Generate.update)(Generate.PRODUCER->value,
    _oid_(v2548),
    v332);
  } 

void  sign_equal_boolean(ClaireBoolean *v2548)
{ if (v2548 == CTRUE)
   princ_string("==");
  else princ_string("!=");
    } 

void  sign_or_boolean(ClaireBoolean *v2548)
{ if (v2548 == CTRUE)
   princ_string("||");
  else princ_string("&&");
    } 

void  bool_exp_any_Generate(OID v2548,ClaireBoolean *v4883,OID v332)
{ any_bool_exp_any(v2548,v4883,v332,not_any(_oid_(((INHERIT(OWNER(v2548),Core._global_variable)) ? ((nativeVar_ask_global_variable(OBJECT(global_variable,v2548)) != CTRUE) ? CTRUE: CFALSE): CFALSE))));
  } 

void  any_bool_exp_any(OID v2548,ClaireBoolean *v4883,OID v332,ClaireBoolean *v13798)
{ princ_string(copy_string("("));
  bexpression_any(v2548,v332);
  princ_string(copy_string(" "));
  if (v4883 != CTRUE)
   princ_string(copy_string("!="));
  else princ_string(copy_string("=="));
    princ_string(copy_string(" "));
  if (v13798 != CTRUE)
   (*Generate.to_cl)(Generate.PRODUCER->value,
    Kernel.ctrue,
    _oid_(Kernel._boolean),
    v332);
  else expression_boolean(CTRUE,v332);
    princ_string(copy_string(")"));
  } 

void  bool_exp_to_CL_Generate(Compile_to_CL *v2548,ClaireBoolean *v4883,OID v332)
{ GC_BIND;
  (*Optimize.bool_exp)(v2548->arg,
    _oid_(v4883),
    v332);
  GC_UNBIND;} 

void  bool_exp_If_Generate(If *v2548,ClaireBoolean *v4883,OID v332)
{ GC_BIND;
  if (boolean_I_any(v2548->other) == CTRUE)
   { princ_string("(");
    (*Optimize.bool_exp)(v2548->test,
      Kernel.ctrue,
      v332);
    princ_string(" ? ");
    (*Optimize.bool_exp)(v2548->arg,
      _oid_(v4883),
      v332);
    princ_string(" : ");
    (*Optimize.bool_exp)(v2548->other,
      _oid_(v4883),
      v332);
    princ_string(")");
    } 
  else { princ_string("(");
      (*Optimize.bool_exp)(v2548->test,
        _oid_(v4883),
        v332);
      princ_string(" ");
      sign_or_boolean(not_any(_oid_(v4883)));
      princ_string(" ");
      (*Optimize.bool_exp)(v2548->arg,
        _oid_(v4883),
        v332);
      princ_string(")");
      } 
    GC_UNBIND;} 

void  bool_exp_And_Generate(And *v2548,ClaireBoolean *v4883,OID v332)
{ GC_BIND;
  { list * v1732 = GC_OBJECT(list,v2548->args);
    int  v1733 = v1732->length;
    int  v1734 = 0;
    int  v2447 = Optimize.OPT->level;
    (Optimize.OPT->level = (Optimize.OPT->level+1));
    { OID gc_local;
      ITERATE(v1744);
      for (START(v1732); NEXT(v1744);)
      { ++v1734;
        if (v1734 == v1733)
         (*Optimize.bool_exp)(v1744,
          _oid_(v4883),
          v332);
        else { princ_string(copy_string("("));
            (*Optimize.bool_exp)(v1744,
              _oid_(v4883),
              v332);
            princ_string(copy_string(" "));
            sign_or_boolean(not_any(_oid_(v4883)));
            princ_string(copy_string(" "));
            (Optimize.OPT->level = (Optimize.OPT->level+1));
            breakline_void();
            } 
          } 
      } 
    { int  v1744 = 2;
      int  v6657 = v1733;
      { OID gc_local;
        while ((v1744 <= v6657))
        { princ_string(copy_string(")"));
          ++v1744;
          } 
        } 
      } 
    (Optimize.OPT->level = v2447);
    } 
  GC_UNBIND;} 

void  bool_exp_Or_Generate(Or *v2548,ClaireBoolean *v4883,OID v332)
{ GC_BIND;
  { list * v1732 = GC_OBJECT(list,v2548->args);
    int  v1733 = v1732->length;
    int  v1734 = 0;
    int  v2447 = Optimize.OPT->level;
    (Optimize.OPT->level = (Optimize.OPT->level+1));
    { OID gc_local;
      ITERATE(v1744);
      for (START(v1732); NEXT(v1744);)
      { ++v1734;
        if (v1734 == v1733)
         (*Optimize.bool_exp)(v1744,
          _oid_(v4883),
          v332);
        else { princ_string(copy_string("("));
            (*Optimize.bool_exp)(v1744,
              _oid_(v4883),
              v332);
            princ_string(copy_string(" "));
            sign_or_boolean(v4883);
            princ_string(copy_string(" "));
            (Optimize.OPT->level = (Optimize.OPT->level+1));
            breakline_void();
            } 
          } 
      } 
    { int  v1744 = 2;
      int  v6660 = v1733;
      { OID gc_local;
        while ((v1744 <= v6660))
        { princ_string(copy_string(")"));
          ++v1744;
          } 
        } 
      } 
    (Optimize.OPT->level = v2447);
    } 
  GC_UNBIND;} 

void  bool_exp_Call_method1_Generate(Call_method1 *v2548,ClaireBoolean *v4883,OID v332)
{ GC_BIND;
  { method * v1733 = v2548->arg;
    OID  v4249 = (*(v2548->args))[1];
    if (_oid_(v1733) == Generate._starnot_star->value)
     { if (INHERIT(OWNER(v4249),Optimize._to_CL))
       any_bool_exp_any(GC_OID((*Kernel.arg)(v4249)),not_any(_oid_(v4883)),v332,CTRUE);
      else any_bool_exp_any(v4249,not_any(_oid_(v4883)),v332,CFALSE);
        } 
    else if (_oid_(v1733) == Generate._starknown_star->value)
     (*Generate.equal_exp)(Generate.PRODUCER->value,
      v4249,
      _oid_(not_any(_oid_(v4883))),
      CNULL,
      v332);
    else if (_oid_(v1733) == Generate._starunknown_star->value)
     (*Generate.equal_exp)(Generate.PRODUCER->value,
      v4249,
      _oid_(v4883),
      CNULL,
      v332);
    else if (_inf_equal_type(v1733->range,Kernel._boolean) == CTRUE)
     { princ_string(copy_string("("));
      expression_Call_method12(v2548,v332);
      princ_string(copy_string(" "));
      sign_equal_boolean(v4883);
      princ_string(copy_string(" "));
      expression_boolean(CTRUE,v332);
      princ_string(copy_string(")"));
      } 
    else { OID v_rec;
        v_rec = _oid_(v2548);
        PUSH(v_rec);
        v_rec = _oid_(v4883);
        PUSH(v_rec);
        v_rec = v332;
        PUSH(v_rec);
        Optimize.bool_exp->super(Kernel._any,3);} 
      } 
  GC_UNBIND;} 

void  bool_exp_Call_method2_Generate(Call_method2 *v2548,ClaireBoolean *v4883,OID v332)
{ GC_BIND;
  { method * v1733 = v2548->arg;
    property * v1736 = v1733->selector;
    list * v13221 = GC_OBJECT(list,OBJECT(Generate_producer,Generate.PRODUCER->value)->open_comparators);
    OID  v4249 = (*(v2548->args))[1];
    OID  v4250 = (*(v2548->args))[2];
    if (v1736 == Core._I_equal)
     (*Generate.equal_exp)(Generate.PRODUCER->value,
      v4249,
      _oid_(not_any(_oid_(v4883))),
      v4250,
      Core.nil->value);
    else if (v1736 == Core.identical_ask)
     (*Generate.equal_exp)(Generate.PRODUCER->value,
      v4249,
      _oid_(v4883),
      v4250,
      Kernel.ctrue);
    else if (v1736 == Kernel._equal)
     (*Generate.equal_exp)(Generate.PRODUCER->value,
      v4249,
      _oid_(v4883),
      v4250,
      Core.nil->value);
    else if ((v13221->memq(_oid_(v1736)) == CTRUE) && 
        ((domain_I_restriction(v1733) == Kernel._integer) || 
            (domain_I_restriction(v1733) == Kernel._float)))
     { princ_string(copy_string("("));
      (*Generate.expression)(v4249,
        v332);
      princ_string(copy_string(" "));
      if (v4883 == CTRUE)
       print_any(_oid_(v1736));
      else print_any((*(v13221))[(mod_integer((index_list(v13221,_oid_(v1736))+1),4)+1)]);
        princ_string(copy_string(" "));
      (*Generate.expression)(v4250,
        v332);
      princ_string(copy_string(")"));
      } 
    else if (_oid_(v1733) == Generate._starnth_integer_star->value)
     { princ_string(copy_string("("));
      if (v4883 != CTRUE)
       princ_string(copy_string("!"));
      (*Generate.bitvector_exp)(Generate.PRODUCER->value,
        v4249,
        v4250,
        v332);
      princ_string(copy_string(")"));
      } 
    else if ((v1736 == Core.inherit_ask) && 
        (domain_I_restriction(v1733) == Kernel._class))
     { princ_string(copy_string("("));
      if (v4883 != CTRUE)
       princ_string(copy_string("!"));
      (*Generate.inherit_exp)(Generate.PRODUCER->value,
        v4249,
        v4250,
        v332);
      princ_string(copy_string(")"));
      } 
    else if (_inf_equal_type(v1733->range,Kernel._boolean) == CTRUE)
     { princ_string(copy_string("("));
      expression_Call_method22(v2548,v332);
      princ_string(copy_string(" "));
      sign_equal_boolean(v4883);
      princ_string(copy_string(" "));
      expression_boolean(CTRUE,v332);
      princ_string(copy_string(")"));
      } 
    else { OID v_rec;
        v_rec = _oid_(v2548);
        PUSH(v_rec);
        v_rec = _oid_(v4883);
        PUSH(v_rec);
        v_rec = v332;
        PUSH(v_rec);
        Optimize.bool_exp->super(Kernel._any,3);} 
      } 
  GC_UNBIND;} 

ClaireBoolean * bool_exp_ask_any(OID v1744)
{ GC_BIND;
  { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v1744),Optimize._to_CL))
     Result = bool_exp_ask_any(OBJECT(Compile_to_CL,v1744)->arg);
    else if (INHERIT(OWNER(v1744),Language._Call_method))
     { property * v1736 = OBJECT(Call_method,v1744)->arg->selector;
      Result = (((OBJECT(Call_method,v1744)->arg->range == Kernel._boolean) && 
          ((v1736 == Kernel._equal) || 
              ((v1736 == Core._I_equal) || 
                ((v1736 == Kernel._sup) || 
                  ((v1736 == Kernel._sup_equal) || 
                    ((v1736 == Kernel._inf) || 
                      (v1736 == Kernel._inf_equal))))))) ? CTRUE : (((v1736 == Core.NOT) && 
          (bool_exp_ask_any((*(OBJECT(Call_method,v1744)->args))[1]) == CTRUE)) ? CTRUE : CFALSE));
      } 
    else Result = CFALSE;
      GC_UNBIND; return (Result);} 
  } 

void  args_list_bag(bag *v2548,OID v332,ClaireBoolean *v3438)
{ { ClaireBoolean * v4691 = CTRUE;
    if (v3438 == CTRUE)
     (Optimize.OPT->level = (Optimize.OPT->level+1));
    { ITERATE(v1744);
      for (START(v2548); NEXT(v1744);)
      if (v4691 == CTRUE)
       { (*Generate.expression)(v1744,
          v332);
        v4691= CFALSE;
        } 
      else { princ_string(",");
          if (v3438 == CTRUE)
           breakline_void();
          (*Generate.expression)(v1744,
            v332);
          princ_string("");
          } 
        } 
    if (v3438 == CTRUE)
     (Optimize.OPT->level = (Optimize.OPT->level-1));
    } 
  } 

char * check_var_string(char *v2548,OID v1741,OID v332)
{ { char *Result ;
    Result = (((equal(_string_(v2548),v1741) == CTRUE) || 
        (equal(_string_(v2548),v332) == CTRUE)) ?
      append_string(v2548,"1") :
      v2548 );
    return (Result);} 
  } 

Variable * build_Variable_string(char *v1741,OID v1740)
{ return (Variable_I_symbol(symbol_I_string2(v1741),0,OBJECT(ClaireType,v1740)));} 

