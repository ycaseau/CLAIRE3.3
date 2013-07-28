/***** CLAIRE Compilation of file c:\claire\v3.3\src\compile\gstat.cl 
         [version 3.3.46 / safety 5] Sun Feb 15 15:37:28 2009 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
#include <Generate.h>
list * unfold_args_list(list *v1732)
{ GC_BIND;
  { list *Result ;
    { list * v3777;
      { { list * v7376 = list::empty(Kernel.emptySet);
          { int  v1729 = 1;
            int  v6663 = v1732->length;
            { OID gc_local;
              while ((v1729 <= v6663))
              { if (c_func_any((*(v1732))[v1729]) != CTRUE)
                 v7376->addFast(v1729);
                ++v1729;
                } 
              } 
            } 
          v3777 = GC_OBJECT(list,v7376);
          } 
        GC_OBJECT(list,v3777);} 
      { bag *v_list; OID v_val;
        OID v1729,CLcount;
        v_list = v3777;
         Result = v_list->clone();
        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
        { v1729 = (*(v_list))[CLcount];
          { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
            (v2072->var = Variable_I_symbol(append_symbol(gensym_void(),_string_(copy_string("UU"))),0,GC_OBJECT(ClaireType,c_type_sort_any((*(v1732))[v1729]))));
            (v2072->value = (*(v1732))[v1729]);
            add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
            v_val = _oid_(v2072);
            } 
          
          (*((list *) Result))[CLcount] = v_val;} 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_sort_any(OID v1744)
{ GC_BIND;
  { ClaireType *Result ;
    { ClaireClass * v1741 = OBJECT(ClaireClass,(*Optimize.c_sort)(v1744));
      ClaireClass * v1740 = stupid_t_any1(v1744);
      Result = ((v1741 == Kernel._void) ?
        osort_any(GC_OID((*Optimize.c_type)(v1744))) :
        ((boolean_I_any(sort_equal_class(osort_any(_oid_(v1740)),v1741)) == CTRUE) ?
          v1740 :
          v1741 ) );
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  unfold_arg_list(list *v1732,list *v4640,OID v1744)
{ { OID Result = 0;
    { int  v1729 = 1;
      int  v1730 = 0;
      int  v1733 = v1732->length;
      { ClaireBoolean * g0030I;
        { OID v15730;{ v15730= _oid_(CFALSE);
            while ((v1729 <= v1733))
            { if (c_func_any((*(v1732))[v1729]) != CTRUE)
               { ++v1730;
                if (equal((*(v1732))[v1729],v1744) == CTRUE)
                 { v15730 = Kernel.ctrue;
                  break;} 
                } 
              else if (equal((*(v1732))[v1729],v1744) == CTRUE)
               { v15730 = Kernel.cfalse;
                break;} 
              ++v1729;
              } 
            } 
          
          g0030I=OBJECT(ClaireBoolean,v15730);} 
        
        if (g0030I == CTRUE) Result = (*Language.var)((*(v4640))[v1730]);
          else Result = (*(v1732))[v1729];
        } 
      } 
    return (Result);} 
  } 

void  unfold_use_list(list *v5825,OID v1744,OID v1741,OID v332)
{ { int  v1734 = v5825->length;
    int  v1743 = ClEnv->verbose;
    (ClEnv->verbose = 0);
    if (boolean_I_any(_oid_(v5825)) != CTRUE)
     close_exception(((general_error *) (*Core._general_error)(_string_(copy_string("[internal] design bug c_func(~S) should be true")),
      _oid_(list::alloc(1,v1744)))));
    if (equal((*Optimize.c_type)(v1744),_oid_(Kernel.emptySet)) == CTRUE)
     v1741= _oid_(Kernel._void);
    { int  v1729 = 1;
      int  v6685 = (v1734-1);
      { OID gc_local;
        while ((v1729 <= v6685))
        { write_property(Kernel.arg,OBJECT(ClaireObject,(*(v5825))[v1729]),(*(v5825))[(v1729+1)]);
          ++v1729;
          } 
        } 
      } 
    (OBJECT(Let,(*(v5825))[v1734])->arg = v1744);
    (ClEnv->verbose = v1743);
    self_statement_Let(OBJECT(Let,(*(v5825))[1]),v1741,v332);
    } 
  } 

void  statement_any(OID v2548,OID v1741,OID v332)
{ GC_BIND;
  { ClaireBoolean * v1722 = Optimize.OPT->alloc_stack;
    if ((((INHERIT(OWNER(v2548),Language._Tuple)) || 
        (INHERIT(OWNER(v2548),Language._Do))) ? CTRUE : ((INHERIT(OWNER(v2548),Language._Let)) ? CTRUE : CFALSE)) != CTRUE)
     (Optimize.OPT->alloc_stack = CFALSE);
    if (c_func_any(v2548) == CTRUE)
     { { ClaireBoolean * g0032I;
        { ClaireBoolean *v_and;
          { v_and = ((Kernel._string == OWNER(v1741)) ? CTRUE : CFALSE);
            if (v_and == CFALSE) g0032I =CFALSE; 
            else { { OID  v6399;
                { OID  v7360;
                  { if (INHERIT(OWNER(v2548),Optimize._to_CL))
                     v7360 = OBJECT(Compile_to_CL,v2548)->arg;
                    else v7360 = v2548;
                      GC_OID(v7360);} 
                  v6399 = (*Optimize.c_sort)(v7360);
                  } 
                v_and = ((v6399 != _oid_(Kernel._void)) ? CTRUE : CFALSE);
                } 
              if (v_and == CFALSE) g0032I =CFALSE; 
              else g0032I = CTRUE;} 
            } 
          } 
        
        if (g0032I == CTRUE) { (*Kernel.c_princ)(v1741);
            princ_string(copy_string(" = "));
            if (bool_exp_ask_any(v2548) == CTRUE)
             (*Generate.bool_exp_I)(Generate.PRODUCER->value,
              v2548,
              v332);
            else (*Generate.expression)(v2548,
                v332);
              princ_string(copy_string(";"));
            breakline_void();
            princ_string(copy_string(""));
            } 
          else if (INHERIT(OWNER(v2548),Language._If))
         (*Generate.self_statement)(v2548,
          v1741,
          v332);
        else if (INHERIT(OWNER(v2548),Reader._delimiter))
         close_exception(((general_error *) (*Core._general_error)(_string_(copy_string("[201] Loose delimiter in program: ~S")),
          _oid_(list::alloc(1,v2548)))));
        else (*Generate.stat_exp)(Generate.PRODUCER->value,
            v2548,
            v332);
          } 
      } 
    else if ((INHERIT(OWNER(v2548),Language._Call_method)) && 
        (((*Kernel.arg)(v2548) == Generate._starclose_exception_star->value) && 
          (c_func_any(GC_OID((*(OBJECT(bag,(*Core.args)(v2548))))[1])) == CTRUE)))
     { (*Generate.expression)(v2548,
        v332);
      princ_string(copy_string(";"));
      breakline_void();
      princ_string(copy_string(""));
      } 
    else (*Generate.self_statement)(v2548,
        v1741,
        v332);
      (Optimize.OPT->alloc_stack = v1722);
    } 
  GC_UNBIND;} 

void  self_statement_Construct(Construct *v2548,OID v1741,OID v332)
{ (*Generate.stat_construct)(Generate.PRODUCER->value,
    _oid_(v2548),
    v1741,
    v332);
  } 

void  self_statement_If(If *v2548,OID v1741,OID v332)
{ GC_BIND;
  if (c_func_any(GC_OID(v2548->test)) == CTRUE)
   { princ_string(copy_string("if "));
    (*Optimize.bool_exp)(GC_OID(v2548->test),
      Kernel.ctrue,
      v332);
    princ_string(copy_string(""));
    breakline_void();
    princ_string(copy_string(" "));
    if (INHERIT(OWNER(v2548->arg),Language._If))
     new_block_void();
    statement_any(GC_OID(v2548->arg),v1741,v332);
    if (INHERIT(OWNER(v2548->arg),Language._If))
     close_block_void();
    if ((Kernel._string == OWNER(v1741)) || 
        (boolean_I_any(v2548->other) == CTRUE))
     { OID  v5013 = GC_OID(v2548->other);
      if (inherit_ask_class(OWNER(v5013),Language._If) != CTRUE)
       (Optimize.OPT->level = (Optimize.OPT->level+1));
      princ_string(copy_string("else "));
      statement_any(v5013,v1741,v332);
      princ_string(copy_string(""));
      if (inherit_ask_class(OWNER(v5013),Language._If) != CTRUE)
       (Optimize.OPT->level = (Optimize.OPT->level-1));
      } 
    } 
  else { OID  v1743 = GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
        _oid_(append_symbol(gensym_void(),_string_(copy_string("I"))))));
      new_block_void();
      interface_I_class(Kernel._boolean);
      princ_string(copy_string(" "));
      princ_string(string_v(v1743));
      princ_string(copy_string(";"));
      breakline_void();
      statement_any(GC_OID(v2548->test),v1743,v332);
      princ_string(copy_string(""));
      breakline_void();
      (Optimize.OPT->level = (Optimize.OPT->level+1));
      princ_string(copy_string("if ("));
      princ_string(string_v(v1743));
      princ_string(copy_string(" == "));
      (*Generate.produce)(Generate.PRODUCER->value,
        Kernel.ctrue);
      princ_string(copy_string(") "));
      statement_any(GC_OID(v2548->arg),v1741,v332);
      princ_string(copy_string(""));
      (Optimize.OPT->level = (Optimize.OPT->level-1));
      if ((Kernel._string == OWNER(v1741)) || 
          (boolean_I_any(v2548->other) == CTRUE))
       { princ_string(copy_string("else "));
        statement_any(GC_OID(v2548->other),v1741,v332);
        princ_string(copy_string(""));
        } 
      close_block_void();
      } 
    GC_UNBIND;} 

void  self_statement_Do(Do *v2548,OID v1741,OID v332)
{ GC_BIND;
  if (v2548->args->length == 1)
   statement_any(GC_OID((*(v2548->args))[1]),v1741,v332);
  else { list * v1732 = GC_OBJECT(list,v2548->args);
      int  v1733 = v1732->length;
      ClaireBoolean * v1722 = Optimize.OPT->alloc_stack;
      int  v1734 = 0;
      (Optimize.OPT->alloc_stack = CFALSE);
      new_block_void();
      inner_statement_any(_oid_(v2548),v1741,v332);
      close_block_void();
      } 
    GC_UNBIND;} 

void  inner_statement_any(OID v2548,OID v1741,OID v332)
{ GC_BIND;
  if (INHERIT(OWNER(v2548),Language._Do))
   { list * v1732 = GC_OBJECT(list,OBJECT(Do,v2548)->args);
    int  v1733 = v1732->length;
    ClaireBoolean * v1722 = Optimize.OPT->alloc_stack;
    int  v1734 = 0;
    (Optimize.OPT->alloc_stack = CFALSE);
    { ITERATE(v1744);
      for (START(v1732); NEXT(v1744);)
      { ++v1734;
        if (v1734 == v1733)
         { (Optimize.OPT->alloc_stack = v1722);
          inner_statement_any(v1744,v1741,v332);
          } 
        else if (boolean_I_any(v1744) == CTRUE)
         inner_statement_any(v1744,_oid_(Kernel.emptySet),v332);
        } 
      } 
    } 
  else statement_any(v2548,v1741,v332);
    GC_UNBIND;} 

void  self_statement_Let(Let *v2548,OID v1741,OID v332)
{ (*Generate.stat_let)(Generate.PRODUCER->value,
    _oid_(v2548),
    v1741,
    v332);
  } 

void  self_statement_And(And *v2548,OID v1741,OID v332)
{ GC_BIND;
  { char * v1743 = GC_STRING(check_var_string(copy_string("v_and"),v1741,v332));
    new_block_void();
    interface_I_class(Kernel._boolean);
    princ_string(v1743);
    princ_string(copy_string(";"));
    breakline_void();
    { OID gc_local;
      ITERATE(v1744);
      bag *v1744_support;
      v1744_support = GC_OBJECT(list,v2548->args);
      for (START(v1744_support); NEXT(v1744);)
      { new_block_void();
        statement_any(v1744,_string_(v1743),v332);
        princ_string(copy_string("if ("));
        princ_string(v1743);
        princ_string(copy_string(" == "));
        (*Generate.produce)(Generate.PRODUCER->value,
          Kernel.cfalse);
        princ_string(copy_string(") "));
        if (Kernel._string == OWNER(v1741))
         { c_princ_string(string_v(v1741));
          princ_string(copy_string(" ="));
          } 
        expression_boolean(CFALSE,v332);
        princ_string(copy_string("; "));
        breakline_void();
        princ_string(copy_string("else "));
        } 
      } 
    if (Kernel._string == OWNER(v1741))
     { c_princ_string(string_v(v1741));
      princ_string(copy_string(" = "));
      expression_boolean(CTRUE,v332);
      princ_string(copy_string(";"));
      } 
    else { expression_boolean(CTRUE,v332);
        princ_string(copy_string(";"));
        } 
      { OID gc_local;
      ITERATE(v1744);
      bag *v1744_support;
      v1744_support = GC_OBJECT(list,v2548->args);
      for (START(v1744_support); NEXT(v1744);)
      close_block_void();
      } 
    close_block_void();
    } 
  GC_UNBIND;} 

void  self_statement_Or(Or *v2548,OID v1741,OID v332)
{ GC_BIND;
  { char * v1743 = GC_STRING(check_var_string(copy_string("v_or"),v1741,v332));
    new_block_void();
    interface_I_class(Kernel._boolean);
    princ_string(v1743);
    princ_string(copy_string(";"));
    breakline_void();
    { OID gc_local;
      ITERATE(v1744);
      bag *v1744_support;
      v1744_support = GC_OBJECT(list,v2548->args);
      for (START(v1744_support); NEXT(v1744);)
      { new_block_void();
        statement_any(v1744,_string_(v1743),v332);
        princ_string(copy_string("if ("));
        princ_string(v1743);
        princ_string(copy_string(" == "));
        (*Generate.produce)(Generate.PRODUCER->value,
          Kernel.ctrue);
        princ_string(copy_string(") "));
        if (Kernel._string == OWNER(v1741))
         { c_princ_string(string_v(v1741));
          princ_string(copy_string(" ="));
          } 
        expression_boolean(CTRUE,v332);
        princ_string(copy_string("; "));
        breakline_void();
        princ_string(copy_string("else "));
        } 
      } 
    if (Kernel._string == OWNER(v1741))
     { c_princ_string(string_v(v1741));
      princ_string(copy_string(" = "));
      expression_boolean(CFALSE,v332);
      princ_string(copy_string(";"));
      } 
    else { expression_boolean(CFALSE,v332);
        princ_string(copy_string(";"));
        } 
      { OID gc_local;
      ITERATE(v1744);
      bag *v1744_support;
      v1744_support = GC_OBJECT(list,v2548->args);
      for (START(v1744_support); NEXT(v1744);)
      close_block_void();
      } 
    close_block_void();
    } 
  GC_UNBIND;} 

void  self_statement_While(While *v2548,OID v1741,OID v332)
{ (*Generate.stat_while)(Generate.PRODUCER->value,
    _oid_(v2548),
    v1741,
    v332);
  } 

void  self_statement_Assign(Assign *v2548,OID v1741,OID v332)
{ GC_BIND;
  { OID  v1743 = GC_OID(v2548->var);
    OID  v1744 = GC_OID(v2548->arg);
    ClaireBoolean * v2454 = ((boolean_I_any(v332) == CTRUE) ? ((Optimize.OPT->loop_gc == CTRUE) ? ((inner2outer_ask_any(v1744) == CTRUE) ? CTRUE: CFALSE): CFALSE): CFALSE);
    OID  v1745;
    { if ((v2454 == CTRUE) && 
          (INHERIT(OWNER(v1744),Optimize._to_protect)))
       v1745 = (*Kernel.arg)(v1744);
      else v1745 = v1744;
        GC_OID(v1745);} 
    if (Kernel._string == OWNER(v1741))
     { new_block_void();
      statement_any(v1745,v1741,v332);
      princ_string(copy_string(" "));
      if (v2454 == CTRUE)
       (*Generate.gc_protection_exp)(Generate.PRODUCER->value,
        v1743,
        Kernel.cfalse,
        v1741,
        v332);
      else { ident_symbol(OBJECT(Variable,v1743)->pname);
          princ_string(copy_string(" = "));
          (*Kernel.c_princ)(v1741);
          princ_string(copy_string(""));
          } 
        princ_string(copy_string(";"));
      close_block_void();
      princ_string(copy_string(""));
      } 
    else if (v2454 == CTRUE)
     { new_block_void();
      statement_any(v1745,GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
        v1743)),v332);
      princ_string(copy_string(" "));
      (*Generate.gc_protection_exp)(Generate.PRODUCER->value,
        v1743,
        Kernel.ctrue,
        v1743,
        v332);
      princ_string(copy_string(";"));
      close_block_void();
      princ_string(copy_string(""));
      } 
    else statement_any(v1744,GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
        v1743)),v332);
      } 
  GC_UNBIND;} 

void  self_statement_Gassign(Gassign *v2548,OID v1741,OID v332)
{ (*Generate.stat_gassign)(Generate.PRODUCER->value,
    _oid_(v2548),
    v1741,
    v332);
  } 

void  self_statement_to_protect(Compile_to_protect *v2548,OID v1741,OID v332)
{ GC_BIND;
  if ((Optimize.OPT->protection == CTRUE) && 
      (Kernel._string == OWNER(v1741)))
   { ClaireClass * v1723 = OBJECT(ClaireClass,(*Optimize.c_sort)(GC_OID(v2548->arg)));
    new_block_void();
    (OBJECT(Generate_producer,Generate.PRODUCER->value)->stat = (OBJECT(Generate_producer,Generate.PRODUCER->value)->stat+1));
    statement_any(GC_OID(v2548->arg),v1741,v332);
    princ_string(gc_protect_class(v1723));
    princ_string(copy_string("("));
    if (INHERIT(v1723,Kernel._object))
     { class_princ_class(psort_any(GC_OID((*Optimize.c_type)(GC_OID(v2548->arg)))));
      princ_string(copy_string(","));
      } 
    (*Kernel.c_princ)(v1741);
    princ_string(copy_string(");"));
    close_block_void();
    } 
  else statement_any(GC_OID(v2548->arg),v1741,v332);
    GC_UNBIND;} 

void  self_statement_For(For *v2548,OID v1741,OID v332)
{ (*Generate.stat_for)(Generate.PRODUCER->value,
    _oid_(v2548),
    v1741,
    v332);
  } 

void  self_statement_Iteration(Iteration *v2548,OID v1741,OID v332)
{ (*Generate.stat_iteration)(Generate.PRODUCER->value,
    _oid_(v2548),
    v1741,
    v332);
  } 

void  self_statement_Return(Return *v2548,OID v1741,OID v332)
{ GC_BIND;
  if (v332 == CNULL)
   { new_block_void();
    statement_any(GC_OID(v2548->arg),_oid_(Kernel.emptySet),_oid_(Kernel.emptySet));
    princ_string(copy_string("break;"));
    close_block_void();
    } 
  else if (Kernel._string == OWNER(v332))
   { new_block_void();
    statement_any(GC_OID(v2548->arg),v332,_oid_(Kernel.emptySet));
    princ_string(copy_string("break;"));
    close_block_void();
    } 
  else close_exception(((general_error *) (*Core._general_error)(_string_(copy_string("[204] break not inside a For or While:~S")),
      _oid_(list::alloc(1,_oid_(v2548))))));
    GC_UNBIND;} 

void  self_statement_Call(Call *v2548,OID v1741,OID v332)
{ GC_BIND;
  { list * v1732 = GC_OBJECT(list,v2548->args);
    list * v4640 = GC_OBJECT(list,unfold_args_list(v1732));
    { OID  v539;
      { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
        (v2072->selector = v2548->selector);
        { Call * v6716 = v2072; 
          list * v6717;
          { bag *v_list; OID v_val;
            OID v1746,CLcount;
            v_list = v1732;
             v6717 = v_list->clone();
            for (CLcount= 1; CLcount <= v_list->length; CLcount++)
            { v1746 = (*(v_list))[CLcount];
              v_val = unfold_arg_list(v1732,v4640,v1746);
              
              (*((list *) v6717))[CLcount] = v_val;} 
            } 
          (v6716->args = v6717);} 
        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
        v539 = _oid_(v2072);
        } 
      unfold_use_list(v4640,v539,v1741,v332);
      } 
    } 
  GC_UNBIND;} 

void  self_statement_Call_method(Call_method *v2548,OID v1741,OID v332)
{ GC_BIND;
  { list * v1732 = GC_OBJECT(list,v2548->args);
    list * v4640 = GC_OBJECT(list,unfold_args_list(v1732));
    { OID  v3422;
      { Call_method * v2072 = ((Call_method *) GC_OBJECT(Call_method,new_object_class(Language._Call_method)));
        (v2072->arg = v2548->arg);
        { Call_method * v6720 = v2072; 
          list * v6721;
          { bag *v_list; OID v_val;
            OID v1746,CLcount;
            v_list = v1732;
             v6721 = v_list->clone();
            for (CLcount= 1; CLcount <= v_list->length; CLcount++)
            { v1746 = (*(v_list))[CLcount];
              v_val = unfold_arg_list(v1732,v4640,v1746);
              
              (*((list *) v6721))[CLcount] = v_val;} 
            } 
          (v6720->args = v6721);} 
        add_I_property(Kernel.instances,Language._Call_method,11,_oid_(v2072));
        v3422 = _oid_(v2072);
        } 
      unfold_use_list(v4640,v3422,v1741,v332);
      } 
    } 
  GC_UNBIND;} 

void  self_statement_Call_method1(Call_method1 *v2548,OID v1741,OID v332)
{ GC_BIND;
  { list * v1732 = GC_OBJECT(list,v2548->args);
    list * v4640 = GC_OBJECT(list,unfold_args_list(v1732));
    { OID  v6305;
      { Call_method1 * v2072 = ((Call_method1 *) GC_OBJECT(Call_method1,new_object_class(Language._Call_method1)));
        (v2072->arg = v2548->arg);
        { Call_method * v6723 = v2072; 
          list * v6724;
          { bag *v_list; OID v_val;
            OID v1746,CLcount;
            v_list = v1732;
             v6724 = v_list->clone();
            for (CLcount= 1; CLcount <= v_list->length; CLcount++)
            { v1746 = (*(v_list))[CLcount];
              v_val = unfold_arg_list(v1732,v4640,v1746);
              
              (*((list *) v6724))[CLcount] = v_val;} 
            } 
          (v6723->args = v6724);} 
        add_I_property(Kernel.instances,Language._Call_method1,11,_oid_(v2072));
        v6305 = _oid_(v2072);
        } 
      unfold_use_list(v4640,v6305,v1741,v332);
      } 
    } 
  GC_UNBIND;} 

void  self_statement_Call_method2(Call_method2 *v2548,OID v1741,OID v332)
{ GC_BIND;
  { list * v1732 = GC_OBJECT(list,v2548->args);
    list * v4640 = GC_OBJECT(list,unfold_args_list(v1732));
    { OID  v9188;
      { Call_method2 * v2072 = ((Call_method2 *) GC_OBJECT(Call_method2,new_object_class(Language._Call_method2)));
        (v2072->arg = v2548->arg);
        { Call_method * v6747 = v2072; 
          list * v6748;
          { bag *v_list; OID v_val;
            OID v1746,CLcount;
            v_list = v1732;
             v6748 = v_list->clone();
            for (CLcount= 1; CLcount <= v_list->length; CLcount++)
            { v1746 = (*(v_list))[CLcount];
              v_val = unfold_arg_list(v1732,v4640,v1746);
              
              (*((list *) v6748))[CLcount] = v_val;} 
            } 
          (v6747->args = v6748);} 
        add_I_property(Kernel.instances,Language._Call_method2,11,_oid_(v2072));
        v9188 = _oid_(v2072);
        } 
      unfold_use_list(v4640,v9188,v1741,v332);
      } 
    } 
  GC_UNBIND;} 

void  self_statement_Super(Super *v2548,OID v1741,OID v332)
{ (*Generate.stat_super)(Generate.PRODUCER->value,
    _oid_(v2548),
    v1741,
    v332);
  } 

void  self_statement_Cast(Cast *v2548,OID v1741,OID v332)
{ GC_BIND;
  statement_any(GC_OID(v2548->arg),v1741,v332);
  GC_UNBIND;} 

void  self_statement_Handle(ClaireHandle *v2548,OID v1741,OID v332)
{ (*Generate.stat_handle)(Generate.PRODUCER->value,
    _oid_(v2548),
    v1741,
    v332);
  } 

void  self_statement_to_CL(Compile_to_CL *v2548,OID v1741,OID v332)
{ GC_BIND;
  if (Kernel._string == OWNER(v1741))
   { Variable * v6344 = GC_OBJECT(Variable,build_Variable_string(string_I_symbol(gensym_string(copy_string("V_CL"))),_oid_(v2548->set_arg)));
    ClaireClass * v4807 = ((v2548->set_arg == Kernel._void) ?
      Kernel._any :
      v2548->set_arg );
    new_block_void();
    interface_I_class(v4807);
    princ_string(copy_string(" "));
    expression_Variable(v6344,v332);
    princ_string(copy_string(";"));
    statement_any(GC_OID(v2548->arg),GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
      _oid_(v6344))),v332);
    breakline_void();
    princ_string(string_v(v1741));
    princ_string(copy_string("="));
    (*Generate.to_cl)(Generate.PRODUCER->value,
      _oid_(v6344),
      _oid_(v2548->set_arg),
      v332);
    princ_string(copy_string(";"));
    close_block_void();
    } 
  else statement_any(GC_OID(v2548->arg),v1741,v332);
    GC_UNBIND;} 

void  self_statement_to_C(Compile_to_C *v2548,OID v1741,OID v332)
{ GC_BIND;
  if (Kernel._string == OWNER(v1741))
   { Variable * v6344 = GC_OBJECT(Variable,build_Variable_string(copy_string("V_C"),_oid_(Kernel._any)));
    new_block_void();
    (*Generate.any_interface)(Generate.PRODUCER->value);
    princ_string(copy_string(" "));
    (*Language.ident)(Generate.PRODUCER->value,
      _oid_(v6344));
    princ_string(copy_string(";"));
    statement_any(GC_OID(v2548->arg),GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
      _oid_(v6344))),v332);
    breakline_void();
    princ_string(string_v(v1741));
    princ_string(copy_string("="));
    (*Generate.to_c)(Generate.PRODUCER->value,
      _oid_(v6344),
      _oid_(v2548->set_arg),
      v332);
    princ_string(copy_string(";"));
    close_block_void();
    } 
  else statement_any(GC_OID(v2548->arg),v1741,v332);
    GC_UNBIND;} 

void  self_statement_C_cast(Compile_C_cast *v2548,OID v1741,OID v332)
{ GC_BIND;
  if (Kernel._string == OWNER(v1741))
   { char * v6344 = GC_STRING(check_var_string(copy_string("V_CC"),v1741,v332));
    ClaireClass * v4807 = v2548->set_arg;
    ClaireClass * v4808 = stupid_t_any1(GC_OID(v2548->arg));
    ClaireType * v4838 = join_class(osort_any(_oid_(v4807)),v4808);
    new_block_void();
    (*Generate.define_variable)(Generate.PRODUCER->value,
      _oid_(v4838),
      _string_(v6344));
    breakline_void();
    statement_any(GC_OID(v2548->arg),_string_(v6344),v332);
    princ_string(string_v(v1741));
    princ_string(copy_string("= "));
    (*Generate.pointer_cast)(Generate.PRODUCER->value,
      _oid_(v4807));
    princ_string(copy_string(" "));
    princ_string(v6344);
    princ_string(copy_string(";"));
    close_block_void();
    } 
  else statement_any(GC_OID(v2548->arg),v1741,v332);
    GC_UNBIND;} 

void  self_statement_Call_slot(Call_slot *v2548,OID v1741,OID v332)
{ GC_BIND;
  { char * v15708 = string_I_symbol(gensym_void());
    Variable * v6344 = GC_OBJECT(Variable,build_Variable_string(v15708,GC_OID((*Optimize.c_type)(GC_OID(v2548->arg)))));
    new_block_void();
    interface_I_class(sort_Variable(v6344));
    princ_string(copy_string(" "));
    expression_Variable(v6344,_oid_(Kernel.emptySet));
    princ_string(copy_string(";"));
    breakline_void();
    statement_any(GC_OID(v2548->arg),_string_(v15708),v332);
    breakline_void();
    if (Kernel._string == OWNER(v1741))
     { c_princ_string(string_v(v1741));
      princ_string(copy_string(" = "));
      } 
    { Call_slot * v15868;
      { Call_slot * v2072 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
        (v2072->selector = v2548->selector);
        (v2072->arg = _oid_(v6344));
        add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v2072));
        v15868 = v2072;
        } 
      expression_Call_slot(v15868,v332);
      } 
    princ_string(copy_string(";"));
    close_block_void();
    } 
  GC_UNBIND;} 

void  self_statement_Call_table(Call_table *v2548,OID v1741,OID v332)
{ GC_BIND;
  { char * v15708 = string_I_symbol(gensym_void());
    Variable * v6344 = GC_OBJECT(Variable,build_Variable_string(v15708,GC_OID((*Optimize.c_type)(GC_OID(v2548->arg)))));
    new_block_void();
    interface_I_class(sort_Variable(v6344));
    princ_string(copy_string(" "));
    expression_Variable(v6344,_oid_(Kernel.emptySet));
    princ_string(copy_string(";"));
    breakline_void();
    statement_any(GC_OID(v2548->arg),_string_(v15708),v332);
    breakline_void();
    if (Kernel._string == OWNER(v1741))
     { c_princ_string(string_v(v1741));
      princ_string(copy_string(" = "));
      } 
    { Call_table * v445;
      { Call_table * v2072 = ((Call_table *) GC_OBJECT(Call_table,new_object_class(Language._Call_table)));
        (v2072->selector = v2548->selector);
        (v2072->arg = _oid_(v6344));
        add_I_property(Kernel.instances,Language._Call_table,11,_oid_(v2072));
        v445 = v2072;
        } 
      expression_Call_table(v445,v332);
      } 
    princ_string(copy_string(";"));
    close_block_void();
    } 
  GC_UNBIND;} 

void  self_statement_Call_array(Call_array *v2548,OID v1741,OID v332)
{ GC_BIND;
  { Variable * v105 = GC_OBJECT(Variable,build_Variable_string(copy_string("va_arg1"),_oid_(Kernel._array)));
    Variable * v106 = GC_OBJECT(Variable,build_Variable_string(copy_string("va_arg2"),_oid_(Kernel._integer)));
    new_block_void();
    interface_I_class(Kernel._array);
    princ_string(copy_string(" "));
    expression_Variable(v105,_oid_(Kernel.emptySet));
    princ_string(copy_string(";"));
    breakline_void();
    interface_I_class(Kernel._integer);
    princ_string(copy_string(" "));
    expression_Variable(v106,_oid_(Kernel.emptySet));
    princ_string(copy_string(";"));
    breakline_void();
    statement_any(GC_OID(v2548->selector),_string_(copy_string("va_arg1")),v332);
    statement_any(GC_OID(v2548->arg),_string_(copy_string("va_arg2")),v332);
    if (Kernel._string == OWNER(v1741))
     { c_princ_string(string_v(v1741));
      princ_string(copy_string(" = "));
      } 
    { Call_array * v1406;
      { Call_array * v2072 = ((Call_array *) GC_OBJECT(Call_array,new_object_class(Language._Call_array)));
        (v2072->selector = _oid_(v105));
        (v2072->arg = _oid_(v106));
        (v2072->test = v2548->test);
        add_I_property(Kernel.instances,Language._Call_array,11,_oid_(v2072));
        v1406 = v2072;
        } 
      expression_Call_array(v1406,v332);
      } 
    princ_string(copy_string(";"));
    close_block_void();
    } 
  GC_UNBIND;} 

void  self_statement_Update(Update *v2548,OID v1741,OID v332)
{ GC_BIND;
  { OID  v1712 = GC_OID(v2548->var);
    OID  v1736 = GC_OID(v2548->selector);
    ClaireType * v4806;
    { if (INHERIT(OWNER(v1712),Language._Call_slot))
       v4806 = domain_I_restriction(OBJECT(Call_slot,v1712)->selector);
      else if (INHERIT(OWNER(v1712),Language._Call_array))
       v4806 = Kernel._integer;
      else v4806 = U_type(Kernel._any,GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.domain)(v1736))));
        GC_OBJECT(ClaireType,v4806);} 
    ClaireType * v4807;
    { if (INHERIT(OWNER(v1712),Language._Call_slot))
       { v4807 = ((v2548->arg == _oid_(Kernel.add)) ?
          member_type(OBJECT(Call_slot,v1712)->selector->range) :
          OBJECT(Call_slot,v1712)->selector->range );
        } 
      else if (INHERIT(OWNER(v1712),Language._Call_array))
       { v4807 = (((OBJECT(ClaireBoolean,(*Core._inf_equalt)(GC_OID(OBJECT(Call_array,v1712)->test),
          _oid_(Kernel._float)))) == CTRUE) ?
          Kernel._float :
          Kernel._any );
        } 
      else v4807 = U_type(Kernel._any,GC_OBJECT(ClaireType,((v2548->arg == _oid_(Kernel.add)) ?
          member_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.range)(v1736)))) :
          OBJECT(ClaireType,(*Kernel.range)(v1736)) )));
        GC_OBJECT(ClaireType,v4807);} 
    ClaireClass * v3625 = stupid_t_any1(GC_OID((*Kernel.arg)(v2548->var)));
    ClaireClass * v3626 = stupid_t_any1(GC_OID(v2548->value));
    OID  v1721;
    { if ((_inf_equalt_class(v3625,psort_any(_oid_(v4806))) != CTRUE) && 
          (_inf_equalt_class(v3625,Kernel._object) == CTRUE))
       { Compile_C_cast * v2072 = ((Compile_C_cast *) GC_OBJECT(Compile_C_cast,new_object_class(Optimize._C_cast)));
        (v2072->arg = (*Kernel.arg)(GC_OID(v2548->var)));
        (v2072->set_arg = psort_any(_oid_(v4806)));
        add_I_property(Kernel.instances,Optimize._C_cast,11,_oid_(v2072));
        v1721 = _oid_(v2072);
        } 
      else v1721 = (*Kernel.arg)(GC_OID(v2548->var));
        GC_OID(v1721);} 
    OID  v4372;
    { if ((_inf_equalt_class(v3626,psort_any(_oid_(v4807))) != CTRUE) && 
          (_inf_equalt_class(v3626,Kernel._object) == CTRUE))
       { Compile_C_cast * v2072 = ((Compile_C_cast *) GC_OBJECT(Compile_C_cast,new_object_class(Optimize._C_cast)));
        (v2072->arg = v2548->value);
        (v2072->set_arg = psort_any(_oid_(v4807)));
        add_I_property(Kernel.instances,Optimize._C_cast,11,_oid_(v2072));
        v4372 = _oid_(v2072);
        } 
      else v4372 = v2548->value;
        GC_OID(v4372);} 
    Variable * v105 = GC_OBJECT(Variable,Variable_I_symbol(gensym_void(),0,v4806));
    Variable * v106 = GC_OBJECT(Variable,Variable_I_symbol(gensym_void(),0,v4807));
    ClaireBoolean * v4279 = c_func_any(v1721);
    new_block_void();
    interface_I_class(psort_any(_oid_(v4806)));
    princ_string(copy_string(" "));
    expression_Variable(v105,_oid_(Kernel.emptySet));
    princ_string(copy_string(" "));
    if (v4279 == CTRUE)
     { princ_string(copy_string("= "));
      (*Generate.expression)(v1721,
        _oid_(Kernel.emptySet));
      princ_string(copy_string(""));
      } 
    princ_string(copy_string("; "));
    breakline_void();
    interface_I_class(psort_any(_oid_(v4807)));
    princ_string(copy_string(" "));
    expression_Variable(v106,_oid_(Kernel.emptySet));
    princ_string(copy_string(";"));
    breakline_void();
    if (v4279 != CTRUE)
     statement_any(v1721,GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
      _oid_(v105))),v332);
    statement_any(v4372,GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
      _oid_(v106))),v332);
    if (Kernel._string == OWNER(v1741))
     { c_princ_string(string_v(v1741));
      princ_string(copy_string(" = "));
      } 
    { Update * v2367;
      { Update * v2072 = ((Update *) GC_OBJECT(Update,new_object_class(Language._Update)));
        (v2072->selector = v1736);
        { Update * v6754 = v2072; 
          OID  v6755;
          if (v2548->arg == _oid_(Kernel.add))
           v6755 = _oid_(Kernel.add);
          else if (sort_Variable(v105) == Kernel._any)
           v6755 = _oid_(v105);
          else { Compile_to_CL * v2072 = ((Compile_to_CL *) GC_OBJECT(Compile_to_CL,new_object_class(Optimize._to_CL)));
              (v2072->arg = _oid_(v105));
              (v2072->set_arg = sort_Variable(v105));
              add_I_property(Kernel.instances,Optimize._to_CL,11,_oid_(v2072));
              v6755 = _oid_(v2072);
              } 
            (v6754->arg = v6755);} 
        (v2072->value = _oid_(v106));
        { Update * v6758 = v2072; 
          OID  v6759;
          { OID  v5032 = GC_OID((*Kernel.copy)(v1712));
            put_property2(Kernel.arg,OBJECT(ClaireObject,v5032),_oid_(v105));
            v6759 = v5032;
            } 
          (v6758->var = v6759);} 
        add_I_property(Kernel.instances,Language._Update,11,_oid_(v2072));
        v2367 = v2072;
        } 
      expression_Update(v2367,v332);
      } 
    princ_string(copy_string(";"));
    close_block_void();
    } 
  GC_UNBIND;} 

