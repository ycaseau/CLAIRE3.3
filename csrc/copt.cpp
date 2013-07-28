/***** CLAIRE Compilation of file c:\claire\v3.3\src\compile\copt.cl 
         [version 3.3.46 / safety 5] Sun Feb 15 15:37:28 2009 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
#include <Generate.h>
void  inline_exp_c_producer1(Generate_c_producer *v1723,Call_method1 *v2548,OID v332)
{ GC_BIND;
  { method * v1733 = v2548->arg;
    property * v1736 = v1733->selector;
    OID  v4249 = GC_OID(car_list(v2548->args));
    if ((v1736 == Kernel._dash) && 
        ((domain_I_restriction(v1733) == Kernel._integer) || 
            (domain_I_restriction(v1733) == Kernel._float)))
     { princ_string(copy_string("(-"));
      bexpression_any(v4249,v332);
      princ_string(copy_string(")"));
      } 
    else if ((v1736 == Core.owner) && 
        (designated_ask_any(v4249) == CTRUE))
     { princ_string(copy_string("OWNER("));
      (*Generate.expression)(v4249,
        v332);
      princ_string(copy_string(")"));
      } 
    else if ((v1736 == Core.sqrt) && 
        (domain_I_restriction(v1733) == Kernel._float))
     { princ_string(copy_string("sqrt("));
      (*Generate.expression)(v4249,
        v332);
      princ_string(copy_string(")"));
      } 
    else if ((v1736 == Core.eval) && 
        (designated_ask_any(v4249) == CTRUE))
     { princ_string(copy_string("OPT_EVAL("));
      (*Generate.expression)(v4249,
        v332);
      princ_string(copy_string(")"));
      } 
    else if (v1736 == Core.externC)
     (*Kernel.princ)(v4249);
    else if ((_oid_(v1733) == Generate._starlength_bag_star->value) && 
        (designated_ask_any(v4249) == CTRUE))
     { (*Generate.expression)(v4249,
        v332);
      princ_string(copy_string("->length"));
      } 
    else if ((v1736 == Kernel.integer_I) && 
        ((domain_I_restriction(v1733) == Kernel._char) && 
          (designated_ask_any(v4249) == CTRUE)))
     { (*Generate.expression)(v4249,
        v332);
      princ_string(copy_string("->ascii"));
      } 
    else if (_oid_(v1733) == Generate._starlength_array_star->value)
     { (*Generate.expression)(v4249,
        v332);
      princ_string(copy_string("[0]"));
      } 
    else if ((_oid_(v1733) == Generate._starnot_star->value) && 
        (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v4249))),Kernel._boolean) == CTRUE))
     { princ_string(copy_string("(("));
      (*Generate.expression)(v4249,
        v332);
      princ_string(copy_string(" == Kernel.ctrue) ? CFALSE : CTRUE)"));
      } 
    else print_external_call_c_producer(v1723,v2548,v332);
      } 
  GC_UNBIND;} 

void  inline_exp_c_producer2(Generate_c_producer *v1723,Call_method2 *v2548,OID v332)
{ GC_BIND;
  { method * v1733 = v2548->arg;
    property * v1736 = v1733->selector;
    OID  v4249 = GC_OID((*(v2548->args))[1]);
    OID  v4250 = GC_OID((*(v2548->args))[2]);
    if ((_oid_(v1733) == Generate._starmin_integer_star->value) && 
        ((designated_ask_any(v4249) == CTRUE) && 
          (designated_ask_any(v4250) == CTRUE)))
     { princ_string(copy_string("(("));
      (*Generate.expression)(v4249,
        v332);
      princ_string(copy_string(" <= "));
      (*Generate.expression)(v4250,
        v332);
      princ_string(copy_string(") ? "));
      (*Generate.expression)(v4249,
        v332);
      princ_string(copy_string(" : "));
      (*Generate.expression)(v4250,
        v332);
      princ_string(copy_string(")"));
      } 
    else if ((_oid_(v1733) == Generate._starmax_integer_star->value) && 
        ((designated_ask_any(v4249) == CTRUE) && 
          (designated_ask_any(v4250) == CTRUE)))
     { princ_string(copy_string("(("));
      (*Generate.expression)(v4249,
        v332);
      princ_string(copy_string(" <= "));
      (*Generate.expression)(v4250,
        v332);
      princ_string(copy_string(") ? "));
      (*Generate.expression)(v4250,
        v332);
      princ_string(copy_string(" : "));
      (*Generate.expression)(v4249,
        v332);
      princ_string(copy_string(")"));
      } 
    else if ((v1736 == Core.class_I) && 
        (INHERIT(OWNER(v4249),Kernel._symbol)))
     { princ_string(copy_string("("));
      ident_thing(defined_symbol(OBJECT(symbol,v4249)));
      princ_string(copy_string("._"));
      c_princ_string(string_v((*Kernel.string_I)(v4249)));
      princ_string(copy_string(" = ClaireClass::make("));
      print_any(GC_OID((*Kernel.string_I)(v4249)));
      princ_string(copy_string(","));
      (*Generate.expression)(v4250,
        v332);
      princ_string(copy_string(","));
      ident_thing(OBJECT(thing,(*Kernel.module_I)(v4249)));
      princ_string(copy_string(".it))"));
      } 
    else if ((v1723->open_operators->memq(_oid_(v1736)) == CTRUE) && 
        (((v1736 != Kernel._7) || 
            (5 <= Optimize.compiler->safety)) && 
          ((equal((*(v1733->domain))[1],(*(v1733->domain))[2]) == CTRUE) && 
            ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v4249))),Kernel._integer) == CTRUE) || 
                (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v4249))),Kernel._float) == CTRUE)))))
     { if ((Optimize.compiler->safety < 2) && 
          (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v4249))),Kernel._integer) == CTRUE))
       princ_string(copy_string("_integer_"));
      princ_string(copy_string("("));
      bexpression_any(v4249,v332);
      princ_string(string_I_symbol(v1736->name));
      bexpression_any(v4250,v332);
      princ_string(copy_string(")"));
      } 
    else if ((_oid_(v1733) == Generate._starcontain_star->value) && 
        (identifiable_ask_any(v4250) == CTRUE))
     { (*Generate.expression)(v4249,
        v332);
      princ_string(copy_string("->memq("));
      (*Generate.expression)(v4250,
        v332);
      princ_string(copy_string(")"));
      } 
    else if (((_oid_(v1733) == Generate._starnth_list_star->value) && 
          (2 <= Optimize.compiler->safety)) || 
        (_oid_(v1733) == Generate._starnth_1_bag_star->value))
     { princ_string(copy_string("(*("));
      (*Generate.expression)(v4249,
        v332);
      princ_string(copy_string("))["));
      (*Generate.expression)(v4250,
        v332);
      princ_string(copy_string("]"));
      } 
    else if ((v1736 == Kernel.add_I) && 
        (_inf_equal_type(domain_I_restriction(v1733),Kernel._bag) == CTRUE))
     { (*Generate.expression)(v4249,
        v332);
      princ_string(copy_string("->addFast("));
      (*Generate.expression)(v4250,
        v332);
      princ_string(copy_string(")"));
      } 
    else if ((_oid_(v1733) == Generate._starnth_string_star->value) && 
        (2 <= Optimize.compiler->safety))
     { princ_string(copy_string("_char_("));
      (*Generate.expression)(v4249,
        v332);
      princ_string(copy_string("["));
      (*Generate.expression)(v4250,
        v332);
      princ_string(copy_string(" - 1])"));
      } 
    else if (v1733->selector == Core.identical_ask)
     { princ_string(copy_string("("));
      (*Optimize.bool_exp)(_oid_(v2548),
        Kernel.ctrue,
        v332);
      princ_string(copy_string(" ? CTRUE : CFALSE)"));
      } 
    else if (v1733->selector == Core.externC)
     (*Kernel.princ)(v4249);
    else if ((v1736 == Core.inlineok_ask) && 
        (Kernel._string == OWNER(v4250)))
     { (*Generate.expression)(v4249,
        v332);
      princ_string(copy_string("->inlineDef("));
      print_any(v4250);
      princ_string(copy_string(")"));
      } 
    else print_external_call_c_producer(v1723,v2548,v332);
      } 
  GC_UNBIND;} 

void  inline_exp_c_producer3(Generate_c_producer *v1723,Call_method *v2548,OID v332)
{ GC_BIND;
  { method * v1733 = v2548->arg;
    ClaireBoolean * v1722 = Optimize.OPT->alloc_stack;
    OID  v4249 = GC_OID((*(v2548->args))[1]);
    OID  v4250 = GC_OID((*(v2548->args))[2]);
    OID  v4251 = GC_OID((*(v2548->args))[3]);
    (Optimize.OPT->alloc_stack = CFALSE);
    if ((_oid_(v1733) == Generate._starnth_equal_list_star->value) && 
        (3 <= Optimize.compiler->safety))
     { princ_string(copy_string("((*("));
      (*Generate.expression)(v4249,
        v332);
      princ_string(copy_string("))["));
      (*Generate.expression)(v4250,
        v332);
      princ_string(copy_string("]="));
      (*Generate.expression)(v4251,
        v332);
      princ_string(copy_string(")"));
      } 
    else if ((domain_I_restriction(v1733) == Kernel._string) && 
        (((v1733->selector == Kernel.nth_equal) && 
              (2 <= Optimize.compiler->safety)) || 
            (v1733->selector == Kernel.nth_put)))
     { princ_string(copy_string("("));
      (*Generate.expression)(v4249,
        v332);
      princ_string(copy_string("["));
      (*Generate.expression)(v4250,
        v332);
      princ_string(copy_string(" - 1] = (char) "));
      (*Generate.expression)(v4251,
        v332);
      princ_string(copy_string("->ascii)"));
      } 
    else if (_oid_(v1733) == Generate._starnth_1_string_star->value)
     { princ_string(copy_string("_char_("));
      (*Generate.expression)(v4249,
        v332);
      princ_string(copy_string("["));
      (*Generate.expression)(v4250,
        v332);
      princ_string(copy_string(" - 1])"));
      } 
    else if ((v1733->selector == Kernel.store) && 
        ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v4249))),Kernel._list) == CTRUE) && 
          (((v2548->args->length == 4) && 
                ((*(v2548->args))[4] == Kernel.ctrue)) || 
              (v2548->args->length == 3))))
     { princ_string(copy_string("STOREI((*"));
      (*Generate.expression)(v4249,
        v332);
      princ_string(copy_string(")["));
      (*Generate.expression)(v4250,
        v332);
      princ_string(copy_string("],"));
      (*Generate.expression)(v4251,
        v332);
      princ_string(copy_string(")"));
      } 
    else if ((v1733->selector == Kernel.store) && 
        ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v4249))),Kernel._array) == CTRUE) && 
          ((equal(_oid_(_exp_type(GC_OBJECT(ClaireType,member_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v4249))))),Kernel._float)),_oid_(Kernel.emptySet)) == CTRUE) && 
            (((v2548->args->length == 4) && 
                  ((*(v2548->args))[4] == Kernel.ctrue)) || 
                (v2548->args->length == 3)))))
     { princ_string(copy_string("STOREI("));
      (*Generate.expression)(v4249,
        v332);
      princ_string(copy_string("["));
      (*Generate.expression)(v4250,
        v332);
      princ_string(copy_string("],"));
      (*Generate.expression)(v4251,
        v332);
      princ_string(copy_string(")"));
      } 
    else if ((v1733->selector == Kernel.add_slot) && 
        (INHERIT(owner_any(getC_any(v4249)),Kernel._class)))
     { princ_string(copy_string("CL_ADD_SLOT("));
      (*Generate.expression)(v4249,
        v332);
      princ_string(copy_string(","));
      class_princ_class(OBJECT(ClaireClass,getC_any(v4249)));
      princ_string(copy_string(","));
      (*Generate.expression)(v4250,
        v332);
      princ_string(copy_string(","));
      ident_symbol(OBJECT(symbol,(*Kernel.name)(GC_OID(getC_any(v4250)))));
      princ_string(copy_string(","));
      (*Generate.expression)(GC_OID(getC_any(v4251)),
        v332);
      princ_string(copy_string(","));
      (*Generate.expression)(GC_OID((*(v2548->args))[4]),
        v332);
      princ_string(copy_string(")"));
      } 
    else if (v1733->selector == Kernel.add_method)
     { if (INHERIT(OWNER(v4249),Kernel._property))
       { (*Generate.expression)(v4249,
          v332);
        princ_string(copy_string("->add"));
        if (v2548->args->length > 5)
         princ_string(copy_string("Float"));
        princ_string(copy_string("Method("));
        signature_I_c_producer(v1723,v4250);
        princ_string(copy_string(","));
        (*Generate.expression)(v4251,
          v332);
        princ_string(copy_string(","));
        breakline_void();
        princ_string(copy_string("\t"));
        bitvector_I_c_producer(v1723,GC_OID((*(v2548->args))[4]));
        princ_string(copy_string(","));
        (*Generate.expression)(GC_OID((*(v2548->args))[5]),
          v332);
        if (v2548->args->length > 5)
         { princ_string(copy_string(","));
          (*Generate.expression)(GC_OID((*(v2548->args))[6]),
            v332);
          } 
        princ_string(copy_string(")"));
        } 
      else { princ_string(copy_string("add_method_property("));
          args_list_bag(GC_OBJECT(list,v2548->args),v332,CTRUE);
          princ_string(copy_string(")"));
          } 
        } 
    else { (Optimize.OPT->alloc_stack = v1722);
        print_external_call_c_producer(v1723,v2548,v332);
        } 
      (Optimize.OPT->alloc_stack = v1722);
    } 
  GC_UNBIND;} 

void  print_external_call_c_producer(Generate_c_producer *v1723,Call_method *v2548,OID v332)
{ GC_BIND;
  { method * v1733 = v2548->arg;
    list * v1732 = GC_OBJECT(list,v2548->args);
    int  v1734 = 1;
    list * v4640 = v1733->domain;
    c_princ_function(OBJECT(ClaireFunction,(*Optimize.functional_I)(_oid_(v1733))));
    princ_string(copy_string("("));
    if (v1732->length > 4)
     (Optimize.OPT->level = (Optimize.OPT->level+1));
    if ((v1732->length == 1) && 
        (domain_I_restriction(v1733) == Kernel._void))
     v1732= Kernel.nil;
    { ITERATE(v1744);
      for (START(v1732); NEXT(v1744);)
      { if (v1734 != 1)
         { princ_string(copy_string(","));
          if (v1732->length > 4)
           breakline_void();
          } 
        { ClaireClass * v4806 = psort_any((*(v4640))[v1734]);
          ClaireClass * v4807 = stupid_t_any1(v1744);
          if ((_inf_equalt_class(v4806,Kernel._object) == CTRUE) && 
              (_inf_equalt_class(v4807,v4806) != CTRUE))
           { princ_string(copy_string("("));
            class_princ_class(v4806);
            princ_string(copy_string(" *) "));
            } 
          } 
        (*Generate.expression)(v1744,
          v332);
        ++v1734;
        } 
      } 
    princ_string(copy_string(")"));
    if ((INHERIT(v1733->range->isa,Kernel._tuple)) && 
        (Optimize.OPT->alloc_stack != CTRUE))
     princ_string(copy_string("->copyIfNeeded()"));
    if (v1732->length > 4)
     (Optimize.OPT->level = (Optimize.OPT->level-1));
    } 
  GC_UNBIND;} 

void  inline_exp_c_producer5(Generate_c_producer *v1723,Call *v2548,OID v332)
{ GC_BIND;
  { property * v1736 = v2548->selector;
    OID  v4249 = GC_OID(car_list(v2548->args));
    int  v1734 = v2548->args->length;
    if (v1736 == Core.get_stack)
     { princ_string(copy_string("ClEnv->stack["));
      (*Generate.expression)(v4249,
        v332);
      princ_string(copy_string("]"));
      } 
    else if (v1736 == Optimize.safe)
     { int  v1745 = Optimize.compiler->safety;
      (Optimize.compiler->safety = 1);
      (*Generate.expression)((*(v2548->args))[1],
        v332);
      (Optimize.compiler->safety = v1745);
      } 
    else if (v1736 == Core.base_I)
     princ_string(copy_string("ClEnv->base"));
    else if ((v1736 == Core.index_I) && 
        (v1734 == 1))
     princ_string(copy_string("ClEnv->index"));
    else if ((v1736 == Core.push_I) && 
        (v1734 == 1))
     { princ_string(copy_string("PUSH("));
      (*Generate.expression)(v4249,
        v332);
      princ_string(copy_string(")"));
      } 
    else if (v1736 == Core.put_stack)
     { princ_string(copy_string("(ClEnv->stack["));
      (*Generate.expression)(v4249,
        v332);
      princ_string(copy_string("]="));
      (*Generate.expression)((*(v2548->args))[2],
        v332);
      princ_string(copy_string(")"));
      } 
    else if (v1736 == Core.set_base)
     { princ_string(copy_string("(ClEnv->base= "));
      (*Generate.expression)(v4249,
        v332);
      princ_string(copy_string(")"));
      } 
    else if (v1736 == Core.set_index)
     { princ_string(copy_string("(ClEnv->index= "));
      (*Generate.expression)(v4249,
        v332);
      princ_string(copy_string(")"));
      } 
    else if (v1736 == Optimize.object_I)
     { OID  v4250 = (*(v2548->args))[2];
      princ_string(copy_string("("));
      ident_thing(defined_symbol(OBJECT(symbol,v4249)));
      princ_string(copy_string("."));
      if (_inf_equal_type(OBJECT(ClaireType,v4250),Reader._reserved_keyword) == CTRUE)
       { princ_string(copy_string("_cl_"));
        c_princ_string(string_v((*Kernel.string_I)(v4249)));
        } 
      else (*Language.ident)(v4249);
        princ_string(copy_string(" = "));
      if ((v4250 == _oid_(Kernel._property)) && 
          (INHERIT(owner_any((*Kernel.value)(v4249)),Kernel._property)))
       { princ_string(copy_string("property::make("));
        print_any(GC_OID((*Kernel.string_I)(v4249)));
        princ_string(copy_string(","));
        princ_integer((*Kernel.open)(GC_OID((*Kernel.value)(v4249))));
        princ_string(copy_string(","));
        expression_thing(OBJECT(thing,(*Kernel.module_I)(v4249)),Core.nil->value);
        princ_string(copy_string(","));
        (*Generate.expression)(GC_OID((*Kernel.domain)(GC_OID((*Kernel.value)(v4249)))),
          Core.nil->value);
        princ_string(copy_string(","));
        (*Kernel.princ)(GC_OID((*Kernel.dispatcher)(GC_OID((*Kernel.value)(v4249)))));
        princ_string(copy_string(")"));
        } 
      else { princ_string(copy_string("("));
          class_princ_class(OBJECT(ClaireClass,v4250));
          princ_string(copy_string(" *) "));
          (*Generate.expression)(v4250,
            v332);
          princ_string(copy_string("->instantiate("));
          print_any(GC_OID((*Kernel.string_I)(v4249)));
          princ_string(copy_string(","));
          expression_thing(OBJECT(thing,(*Kernel.module_I)(v4249)),Core.nil->value);
          princ_string(copy_string(")"));
          } 
        princ_string(copy_string(")"));
      } 
    else if (v1736 == Optimize.anyObject_I)
     { princ_string(copy_string("(("));
      class_princ_class(OBJECT(ClaireClass,v4249));
      princ_string(copy_string(" *) (*"));
      (*Generate.expression)(v4249,
        v332);
      princ_string(copy_string(")("));
      args_list_bag(GC_OBJECT(list,cdr_list(v2548->args)),v332,_sup_integer(v2548->args->length,2));
      princ_string(copy_string("))"));
      } 
    else if ((OBJECT(ClaireBoolean,(*Generate.fcall_ask)(_oid_(v2548)))) == CTRUE)
     (*Generate.fcall_exp)(_oid_(v2548),
      v332);
    else if (v2548->args->length > 20)
     { if (v2548->selector == Kernel.store)
       { list * v1732 = GC_OBJECT(list,v2548->args);
        int  v1734 = v1732->length;
        int  v1733 = (v1734/10);
        princ_string(copy_string("("));
        { int  v1729 = 0;
          int  v6816 = v1733;
          { OID gc_local;
            while ((v1729 <= v6816))
            { GC_LOOP;
              princ_string(copy_string("(*"));
              expression_thing(Kernel.store,v332);
              princ_string(copy_string(")("));
              { list * v5015;
                { list * v267 = list::empty(Kernel.emptySet);
                  { int  v1730 = ((v1729*10)+1);
                    int  v6817 = ((v1729 == v1733) ?
                      v1734 :
                      ((v1729*10)+10) );
                    { OID gc_local;
                      while ((v1730 <= v6817))
                      { v267->addFast((*(v1732))[v1730]);
                        ++v1730;
                        } 
                      } 
                    } 
                  v5015 = GC_OBJECT(list,v267);
                  } 
                args_list_bag(v5015,v332,CTRUE);
                } 
              princ_string(copy_string(")"));
              if (v1729 != v1733)
               princ_string(copy_string(","));
              ++v1729;
              GC_UNLOOP;} 
            } 
          } 
        princ_string(copy_string(")"));
        } 
      else close_exception(((general_error *) (*Core._general_error)(_string_(copy_string("[216] ~S has more than 10 parameters")),
          _oid_(list::alloc(1,_oid_(v2548))))));
        } 
    else { princ_string(copy_string("(*"));
        expression_thing(v2548->selector,v332);
        princ_string(copy_string(")("));
        args_list_bag(GC_OBJECT(list,v2548->args),v332,_sup_integer(v2548->args->length,1));
        princ_string(copy_string(")"));
        } 
      } 
  GC_UNBIND;} 

ClaireBoolean * fcall_ask_Call2_Generate(Call *v1744)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { ClaireBoolean *Result ;
    { property * v1736 = v1744->selector;
      OID  v4249 = GC_OID((*(v1744->args))[1]);
      int  v7465;
      { list * v5976;
        { bag * v11603 = v1744->args;
          list * v5344 = ((list *) empty_bag(v11603));
          { OID gc_local;
            ITERATE(v1745);
            for (START(v11603); NEXT(v1745);)
            if ((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v1745))) == CTRUE)
             v5344->addFast(v1745);
            } 
          v5976 = GC_OBJECT(list,v5344);
          } 
        v7465 = v5976->length;
        } 
      { ClaireBoolean *v_and;
        { v_and = ((designated_ask_any(v4249) == CTRUE) ? CTRUE : ((v1736->dispatcher > 0) ? CTRUE : CFALSE));
          if (v_and == CFALSE) Result =CFALSE; 
          else { { list * v1732 = GC_OBJECT(list,cdr_list(v1744->args));
              ClaireType * v3895 = Kernel.emptySet;
              list * v4656;
              { { bag *v_list; OID v_val;
                  OID v1745,CLcount;
                  v_list = GC_OBJECT(list,v1744->args);
                   v4656 = v_list->clone();
                  for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                  { v1745 = (*(v_list))[CLcount];
                    v_val = _oid_(ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v1745))));
                    
                    (*((list *) v4656))[CLcount] = v_val;} 
                  } 
                GC_OBJECT(list,v4656);} 
              list * v13314 = GC_OBJECT(list,cdr_list(v4656));
              list * v4654 = GC_OBJECT(list,get_restrictions_Call2(v1744,v4656));
              ClaireBoolean * v12814;
              { ClaireBoolean *v_and;
                { v_and = ((v4654->length > 0) ? CTRUE : CFALSE);
                  if (v_and == CFALSE) v12814 =CFALSE; 
                  else { { ClaireBoolean *v_or;
                      { v_or = ((v7465 == 0) ? CTRUE : CFALSE);
                        if (v_or == CTRUE) v_and =CTRUE; 
                        else { { OID  v6937;
                            { OID gc_local;
                              ITERATE(v1733);
                              v6937= Kernel.cfalse;
                              for (START(v4654); NEXT(v1733);)
                              if (not_any(_oid_(nth_integer(status_I_restriction(OBJECT(restriction,v1733)),1))) != CTRUE)
                               { v6937 = Kernel.ctrue;
                                break;} 
                              } 
                            v_or = not_any(v6937);
                            } 
                          if (v_or == CTRUE) v_and =CTRUE; 
                          else v_and = CFALSE;} 
                        } 
                      } 
                    if (v_and == CFALSE) v12814 =CFALSE; 
                    else { v_and = (((v1736->dispatcher > 0) && 
                          (v1732->length <= 4)) ? CTRUE : ((v4654->length < 3) ? CTRUE : CFALSE));
                      if (v_and == CFALSE) v12814 =CFALSE; 
                      else v12814 = CTRUE;} 
                    } 
                  } 
                } 
              ClaireClass * v1741 = ((v4654->length > 0) ?
                c_srange_method(OBJECT(method,(*(v4654))[1])) :
                Kernel._void );
              ClaireBoolean * v2186;
              { OID  v7898;
                { OID gc_local;
                  ITERATE(v1738);
                  v7898= Kernel.cfalse;
                  for (START(v4654); NEXT(v1738);)
                  { GC_LOOP;
                    { ClaireBoolean * g0084I;
                      { OID  v9820;
                        { GC__ANY(v3895 = U_type(v3895,domain_I_restriction(OBJECT(restriction,v1738))), 1);
                          v9820 = _oid_(((INHERIT(OWNER((*(OBJECT(restriction,v1738)->domain))[1]),Kernel._class)) ? ((last_list(OBJECT(restriction,v1738)->domain) != _oid_(Kernel._listargs)) ? ((tmatch_ask_list(v13314,GC_OBJECT(list,cdr_list(OBJECT(restriction,v1738)->domain))) == CTRUE) ? ((c_srange_method(OBJECT(method,v1738)) == v1741) ? CTRUE: CFALSE): CFALSE): CFALSE): CFALSE));
                          } 
                        g0084I = not_any(v9820);
                        } 
                      
                      if (g0084I == CTRUE) { v7898 = Kernel.ctrue;
                          break;} 
                        } 
                    GC_UNLOOP;} 
                  } 
                v2186 = not_any(v7898);
                } 
              ClaireBoolean * v5474 = (((v1741 == Kernel._integer) || 
                  ((v1741 == Kernel._object) || 
                    ((v1741 == Kernel._any) || 
                      (v1741 == Kernel._void)))) ? ((_inf_equal_type(v3895,Kernel._object) == CTRUE) ? ((_inf_equal_type(GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v4249)))),v3895) == CTRUE) ? CTRUE: CFALSE): CFALSE): CFALSE);
              if (((OBJECT(ClaireBoolean,Generate.FCALLSTINKS->value)) == CTRUE) && 
                  ((((v12814 == CTRUE) ? ((v2186 == CTRUE) ? ((v5474 == CTRUE) ? CTRUE: CFALSE): CFALSE): CFALSE) != CTRUE) && 
                    (v1736->dispatcher > 0)))
               tformat_string(copy_string("****> fcall(~S) fails (selectorOK = ~S , lrOK = ~S, callOK = ~S)\n"),0,GC_OBJECT(list,list::alloc(4,_oid_(v1744),
                _oid_(v12814),
                _oid_(v2186),
                _oid_(v5474))));
              v_and = ((v12814 == CTRUE) ? ((v2186 == CTRUE) ? ((v5474 == CTRUE) ? CTRUE: CFALSE): CFALSE): CFALSE);
              } 
            if (v_and == CFALSE) Result =CFALSE; 
            else Result = CTRUE;} 
          } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

list * get_restrictions_Call2(Call *v1744,list *v4656)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { list *Result ;
    { property * v1736 = v1744->selector;
      ClaireBoolean * v11340 = ((class_I_type(OBJECT(ClaireType,(*(v4656))[1]))->open == ClEnv->open) ? CTRUE : CFALSE);
      list * v4654 = list::empty(Kernel._method);
      if ((v1736->dispatcher == 0) && 
          ((v11340 == CTRUE) || 
              (v1736->open == ClEnv->open)))
       ;else { OID gc_local;
          ITERATE(v1738);
          for (START(v1736->restrictions); NEXT(v1738);)
          { GC_LOOP;
            if (length_bag(_exp_list(OBJECT(restriction,v1738)->domain,v4656)) != 0)
             { if (Kernel._method == OBJECT(ClaireObject,v1738)->isa)
               GC__ANY(v4654 = v4654->addFast(v1738), 1);
              else { shrink_list(v4654,0);
                  break;} 
                } 
            GC_UNLOOP;} 
          } 
        Result = v4654;
      } 
    GC_UNBIND; return (Result);} 
  } 

void  fcall_exp_Call2_Generate(Call *v1744,OID v332)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { property * v1736 = v1744->selector;
    OID  v4249 = (*(v1744->args))[1];
    list * v4656;
    { { bag *v_list; OID v_val;
        OID v1745,CLcount;
        v_list = v1744->args;
         v4656 = v_list->clone();
        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
        { v1745 = (*(v_list))[CLcount];
          v_val = _oid_(ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v1745))));
          
          (*((list *) v4656))[CLcount] = v_val;} 
        } 
      GC_OBJECT(list,v4656);} 
    list * v4654 = GC_OBJECT(list,get_restrictions_Call2(v1744,v4656));
    method * v1733 = OBJECT(method,(*(v4654))[1]);
    ClaireClass * v1741 = c_srange_method(v1733);
    if (v1741 == Kernel._void)
     princ_string(copy_string("_void_("));
    else if (v1741 == Kernel._object)
     princ_string(copy_string("_oid_("));
    else if ((v1741 == Kernel._integer) && 
        (Optimize.compiler->safety <= 2))
     princ_string(copy_string("_integer_("));
    if ((v1736->dispatcher > 0) && 
        (v4656->length <= 4))
     { if (v1741 == Kernel._object)
       princ_string(copy_string("(ClaireObject *) "));
      expression_thing(v1736,v332);
      princ_string(copy_string("->fcall("));
      c_sorted_args_Call(v1744,v1733->srange,v332,CTRUE);
      princ_string(copy_string(")"));
      } 
    else { list * v13252;
        { { bag * v14580 = v1736->definition;
            list * v15711 = ((list *) empty_bag(v14580));
            { OID gc_local;
              ITERATE(v1744);
              for (START(v14580); NEXT(v1744);)
              if (v4654->memq(v1744) == CTRUE)
               v15711->addFast(v1744);
              } 
            v13252 = GC_OBJECT(list,v15711);
            } 
          GC_OBJECT(list,v13252);} 
        { OID gc_local;
          ITERATE(v1733);
          for (START(v13252); NEXT(v1733);)
          { GC_LOOP;
            { list * v11238;
              { { bag *v_list; OID v_val;
                  OID v1744,CLcount;
                  v_list = OBJECT(restriction,v1733)->domain;
                   v11238 = v_list->clone();
                  for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                  { v1744 = (*(v_list))[CLcount];
                    v_val = _oid_(psort_any(v1744));
                    
                    (*((list *) v11238))[CLcount] = v_val;} 
                  } 
                GC_OBJECT(list,v11238);} 
              if (v1733 != last_list(v13252))
               { princ_string(copy_string("(INHERIT("));
                if (INHERIT(OWNER(v4249),Optimize._to_CL))
                 { (*Generate.expression)(GC_OID((*Kernel.arg)(v4249)),
                    v332);
                  princ_string(copy_string("->isa"));
                  } 
                else { princ_string(copy_string("OWNER("));
                    (*Generate.expression)(v4249,
                      v332);
                    princ_string(copy_string(")"));
                    } 
                  princ_string(copy_string(","));
                expression_any(_oid_(domain_I_restriction(OBJECT(restriction,v1733))),v332);
                princ_string(copy_string(") ? "));
                if (v1741 == Kernel._object)
                 princ_string(copy_string("(ClaireObject *)"));
                princ_string(copy_string(" "));
                c_princ_function(OBJECT(ClaireFunction,(*Optimize.functional_I)(v1733)));
                princ_string(copy_string("(("));
                class_princ_class(domain_I_restriction(OBJECT(restriction,v1733)));
                princ_string(copy_string(" *) "));
                c_sorted_args_Call(v1744,v11238,v332,CFALSE);
                princ_string(copy_string(") : "));
                ;princ_string(copy_string(" "));
                } 
              else { if (v1741 == Kernel._object)
                   princ_string(copy_string("(ClaireObject *) "));
                  princ_string(copy_string(" "));
                  c_princ_function(OBJECT(ClaireFunction,(*Optimize.functional_I)(v1733)));
                  princ_string(copy_string("(("));
                  (*Generate.interface_I)(Generate.PRODUCER->value,
                    _oid_(domain_I_restriction(OBJECT(restriction,v1733))));
                  princ_string(copy_string(") "));
                  c_sorted_args_Call(v1744,v11238,v332,CFALSE);
                  princ_string(copy_string(")"));
                  { int  v1729 = 1;
                    int  v6845 = (v13252->length-1);
                    { OID gc_local;
                      while ((v1729 <= v6845))
                      { princ_string(copy_string(")"));
                        ++v1729;
                        } 
                      } 
                    } 
                  } 
                } 
            GC_UNLOOP;} 
          } 
        } 
      if ((v1741 == Kernel._void) || 
        ((v1741 == Kernel._object) || 
          ((v1741 == Kernel._float) || 
            ((v1741 == Kernel._integer) && 
                (Optimize.compiler->safety <= 2)))))
     princ_string(copy_string(")"));
    } 
  GC_UNBIND;} 

void  c_sorted_arg_any(OID v1744,ClaireClass *v1741,OID v332,ClaireBoolean *v15164)
{ GC_BIND;
  if (v15164 == CTRUE)
   princ_string(copy_string("((int) "));
  if ((INHERIT(OWNER(v1744),Optimize._to_CL)) && (osort_any(_oid_(OBJECT(Compile_to_CL,v1744)->set_arg)) == v1741))
   (*Generate.expression)(GC_OID((*Kernel.arg)(v1744)),
    v332);
  else if (v1741 == Kernel._any)
   (*Generate.expression)(v1744,
    v332);
  else (*Generate.to_c)(Generate.PRODUCER->value,
      v1744,
      _oid_(v1741),
      v332);
    if (v15164 == CTRUE)
   princ_string(copy_string(")"));
  GC_UNBIND;} 

void  c_sorted_args_Call(Call *v1744,list *v4655,OID v332,ClaireBoolean *v15164)
{ GC_BIND;
  { int  v1729 = 0;
    { OID gc_local;
      ITERATE(v1745);
      for (START(v1744->args); NEXT(v1745);)
      { if (v1729 != 0)
         princ_string(copy_string(","));
        ++v1729;
        c_sorted_arg_any(v1745,OBJECT(ClaireClass,(*(v4655))[v1729]),v332,v15164);
        } 
      } 
    } 
  GC_UNBIND;} 

void  bitvector_I_c_producer(Generate_c_producer *v1723,OID v1744)
{ GC_BIND;
  if (INHERIT(OWNER(v1744),Kernel._integer))
   bitvectorSum_integer(v1744);
  else if (INHERIT(OWNER(v1744),Optimize._to_CL))
   bitvector_I_c_producer(v1723,GC_OID(OBJECT(Compile_to_CL,v1744)->arg));
  else if (INHERIT(OWNER(v1744),Optimize._to_protect))
   bitvector_I_c_producer(v1723,GC_OID(OBJECT(Compile_to_protect,v1744)->arg));
  else (*Generate.expression)(v1744,
      Core.nil->value);
    GC_UNBIND;} 

void  bitvectorSum_integer(int v1744)
{ if (v1744 == 0)
   princ_string(copy_string("0"));
  else { ClaireBoolean * v1722 = CFALSE;
      int  v1729 = 1;
      int  v6846 = 7;
      { while ((v1729 <= v6846))
        { if (BCONTAIN(v1744,v1729))
           { if (v1722 == CTRUE)
             princ_string(copy_string("+"));
            else v1722= CTRUE;
              princ_string(string_v((*(OBJECT(bag,Generate.bitvectorList->value)))[v1729]));
            } 
          ++v1729;
          } 
        } 
      } 
    } 

void  signature_I_c_producer(Generate_c_producer *v1723,OID v1744)
{ GC_BIND;
  if (INHERIT(OWNER(v1744),Kernel._list))
   { princ_string(copy_string("list::domain("));
    princ_integer(OBJECT(bag,v1744)->length);
    princ_string(copy_string(","));
    { list * v12703;
      { { bag *v_list; OID v_val;
          OID v1745,CLcount;
          v_list = OBJECT(bag,v1744);
           v12703 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v1745 = (*(v_list))[CLcount];
            v_val = getC_any(v1745);
            
            (*((list *) v12703))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v12703);} 
      args_list_bag(v12703,Core.nil->value,_sup_integer(OBJECT(bag,v1744)->length,3));
      } 
    princ_string(copy_string(")"));
    } 
  else if (INHERIT(OWNER(v1744),Optimize._to_C))
   signature_I_c_producer(v1723,GC_OID(OBJECT(Compile_to_C,v1744)->arg));
  else if (INHERIT(OWNER(v1744),Optimize._to_protect))
   signature_I_c_producer(v1723,GC_OID(OBJECT(Compile_to_protect,v1744)->arg));
  else if (INHERIT(OWNER(v1744),Language._List))
   signature_I_c_producer(v1723,GC_OID(_oid_(OBJECT(Construct,v1744)->args)));
  else if (INHERIT(OWNER(v1744),Language._Variable))
   expression_Variable(OBJECT(Variable,v1744),Core.nil->value);
  else { princ_string(copy_string("<fucking "));
      print_any(_oid_(OWNER(v1744)));
      princ_string(copy_string(":"));
      print_any(v1744);
      princ_string(copy_string(">"));
      } 
    GC_UNBIND;} 

OID  getC_any(OID v1744)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(OWNER(v1744),Optimize._to_CL))
     Result = getC_any(GC_OID(OBJECT(Compile_to_CL,v1744)->arg));
    else if (INHERIT(OWNER(v1744),Optimize._to_protect))
     Result = getC_any(GC_OID(OBJECT(Compile_to_protect,v1744)->arg));
    else if (INHERIT(OWNER(v1744),Core._global_variable))
     { if (nativeVar_ask_global_variable(OBJECT(global_variable,v1744)) == CTRUE)
       Result = v1744;
      else { Compile_to_C * v2072 = ((Compile_to_C *) GC_OBJECT(Compile_to_C,new_object_class(Optimize._to_C)));
          (v2072->arg = v1744);
          (v2072->set_arg = Kernel._type);
          add_I_property(Kernel.instances,Optimize._to_C,11,_oid_(v2072));
          Result = _oid_(v2072);
          } 
        } 
    else Result = v1744;
      GC_UNBIND; return (Result);} 
  } 

void  gassign_c_producer(Generate_c_producer *v1723,Gassign *v2548,OID v332)
{ GC_BIND;
  if (v2548->var->store_ask == CTRUE)
   { princ_string(copy_string("(STOREI("));
    expression_global_variable(v2548->var,v332);
    princ_string(copy_string(","));
    (*Generate.expression)(v2548->arg,
      v332);
    princ_string(copy_string("))"));
    } 
  else { princ_string(copy_string("("));
      expression_global_variable(v2548->var,v332);
      princ_string(copy_string("= "));
      (*Generate.expression)(v2548->arg,
        v332);
      princ_string(copy_string(")"));
      } 
    GC_UNBIND;} 

void  call_slot_c_producer(Generate_c_producer *v1723,Call_slot *v2548,OID v332)
{ GC_BIND;
  if (v2548->test == CTRUE)
   { princ_string((((INHERIT(v2548->selector->srange,Kernel._cl_import)) || 
        ((INHERIT(v2548->selector->srange,Kernel._string)) || 
          ((INHERIT(v2548->selector->srange,Kernel._array)) || 
            (INHERIT(v2548->selector->srange,Kernel._object))))) ?
      copy_string("NOTNULL") :
      copy_string("KNOWN") ));
    princ_string(copy_string("("));
    expression_thing(v2548->selector->selector,v332);
    princ_string(copy_string(","));
    } 
  c_member_c_producer(v1723,
    GC_OID(v2548->arg),
    psort_any(_oid_(domain_I_restriction(v2548->selector))),
    v2548->selector->selector,
    v332);
  if (v2548->test == CTRUE)
   princ_string(copy_string(")"));
  GC_UNBIND;} 

void  call_table_c_producer(Generate_c_producer *v1723,Call_table *v2548,OID v332)
{ GC_BIND;
  { table * v1724 = v2548->selector;
    OID  v1736 = v1724->params;
    OID  v1732 = v2548->arg;
    if (v2548->test == CTRUE)
     { princ_string(copy_string("KNOWN("));
      expression_thing(v1724,v332);
      princ_string(copy_string(","));
      } 
    princ_string(copy_string("(*("));
    expression_thing(v1724,v332);
    princ_string(copy_string("->graph))["));
    if (INHERIT(OWNER(v1736),Kernel._integer))
     { (*Generate.expression)(v1732,
        v332);
      princ_string(copy_string(" - "));
      princ_integer(v1736);
      princ_string(copy_string(""));
      } 
    else if (INHERIT(OWNER(v1736),Kernel._list))
     { (*Generate.expression)((*(OBJECT(bag,(*Core.args)(v1732))))[1],
        v332);
      princ_string(copy_string(" * "));
      (*Kernel.princ)((*(OBJECT(bag,v1736)))[1]);
      princ_string(copy_string(" + "));
      (*Generate.expression)((*(OBJECT(bag,(*Core.args)(v1732))))[2],
        v332);
      princ_string(copy_string(" - "));
      (*Kernel.princ)((*(OBJECT(bag,v1736)))[2]);
      princ_string(copy_string(""));
      } 
    princ_string(copy_string("]"));
    if (v2548->test == CTRUE)
     princ_string(copy_string(")"));
    } 
  GC_UNBIND;} 

void  call_array_c_producer(Generate_c_producer *v1723,Call_array *v2548,OID v332)
{ GC_BIND;
  if (v2548->test == _oid_(Kernel._float))
   { princ_string("((double *) ");
    (*Generate.expression)(v2548->selector,
      v332);
    princ_string(")[");
    (*Generate.expression)(v2548->arg,
      v332);
    princ_string("]");
    } 
  else { princ_string("((OID *) ");
      (*Generate.expression)(v2548->selector,
        v332);
      princ_string(")[");
      (*Generate.expression)(v2548->arg,
        v332);
      princ_string("]");
      } 
    GC_UNBIND;} 

void  update_c_producer(Generate_c_producer *v1723,Update *v2548,OID v332)
{ GC_BIND;
  { OID  v1736 = v2548->selector;
    OID  v1724 = v2548->arg;
    OID  v1743 = v2548->value;
    OID  v1744 = v2548->var;
    ClaireClass * v1741 = OBJECT(ClaireClass,(*Optimize.c_sort)(v1743));
    if ((INHERIT(OWNER(v1736),Kernel._relation)) && ((OBJECT(ClaireRelation,v1736)->if_write != CNULL) && 
        ((v1724 != _oid_(Kernel.put)) && 
          (v1724 != _oid_(Core.put_store)))))
     { c_princ_string(string_I_symbol(OBJECT(symbol,(*Kernel.name)(v1736))));
      princ_string(copy_string("_write("));
      (*Generate.expression)(GC_OID((*Kernel.arg)(v1744)),
        v332);
      princ_string(copy_string(","));
      (*Generate.expression)(v1743,
        v332);
      princ_string(copy_string(")"));
      } 
    else if ((INHERIT(OWNER(v1736),Kernel._relation)) && ((OBJECT(ClaireRelation,v1736)->store_ask == CTRUE) || 
        (v1724 == _oid_(Core.put_store))))
     { princ_string(copy_string("STORE"));
      princ_string((((v1741 == Kernel._any) || 
          (v1741 == Kernel._integer)) ?
        copy_string("I") :
        ((v1741 == Kernel._float) ?
          copy_string("F") :
          copy_string("O") ) ));
      princ_string(copy_string("("));
      (*Generate.expression)(v1744,
        v332);
      princ_string(copy_string(","));
      (*Generate.expression)(v1743,
        v332);
      princ_string(copy_string(")"));
      } 
    else { princ_string(copy_string("("));
        (*Generate.expression)(v1744,
          v332);
        princ_string(copy_string(" = "));
        (*Generate.expression)(v1743,
          v332);
        princ_string(copy_string(")"));
        } 
      } 
  GC_UNBIND;} 

void  object_test_c_producer(Generate_c_producer *v1723,OID v4249,ClaireBoolean *v4883,OID v332)
{ princ_string("(CTAG(");
  (*Generate.expression)(v4249,
    v332);
  princ_string(") ");
  sign_equal_boolean(v4883);
  princ_string(" OBJ_CODE)");
  } 

void  exp_to_protect_c_producer(Generate_c_producer *v1723,Compile_to_protect *v2548,OID v332)
{ GC_BIND;
  { OID  v4874 = GC_OID((*Optimize.c_type)(v2548->arg));
    if ((Optimize.OPT->protection == CTRUE) && 
        ((need_protect_any(v2548->arg) == CTRUE) && 
          (((Optimize.OPT->alloc_stack == CTRUE) ? ((_inf_equal_type(OBJECT(ClaireType,v4874),Kernel._tuple) == CTRUE) ? CTRUE: CFALSE): CFALSE) != CTRUE)))
     { OID  v1744 = v2548->arg;
      ClaireClass * v1741 = OBJECT(ClaireClass,(*Optimize.c_sort)(v1744));
      princ_string(gc_protect_class(v1741));
      princ_string(copy_string("("));
      if (INHERIT(v1741,Kernel._object))
       { class_princ_class(psort_any(GC_OID((*Core.glb)(GC_OID((*Optimize.c_type)(v1744)),
          _oid_(v1741)))));
        princ_string(copy_string(","));
        (*Generate.expression)(v2548->arg,
          v332);
        princ_string(copy_string(""));
        } 
      else (*Generate.expression)(v2548->arg,
          v332);
        princ_string(copy_string(")"));
      } 
    else (*Generate.expression)(v2548->arg,
        v332);
      } 
  GC_UNBIND;} 

void  macro_c_producer(Generate_c_producer *v1723)
{ ;} 

void  init_var_c_producer(Generate_c_producer *v1723,ClaireClass *v1741)
{ ;} 

void  any_interface_c_producer(Generate_c_producer *v1723)
{ princ_string("OID");
  } 

void  pointer_cast_c_producer(Generate_c_producer *v1723,ClaireClass *v1741)
{ princ_string(copy_string("("));
  class_princ_c_producer(v1723,v1741);
  princ_string(copy_string(" *)"));
  } 

void  exp_Assign_c_producer(Generate_c_producer *v1723,Assign *v2548,OID v332)
{ GC_BIND;
  { OID  v1744 = v2548->arg;
    OID  v1743 = v2548->var;
    (*Language.ident)(Generate.PRODUCER->value,
      v1743);
    princ_string("= ");
    (*Generate.expression)(v1744,
      v332);
    princ_string("");
    } 
  GC_UNBIND;} 

void  stat_handle_c_producer(Generate_c_producer *v1723,ClaireHandle *v2548,OID v1741,OID v332)
{ GC_BIND;
  new_block_void();
  princ_string(copy_string("ClaireHandler c_handle = ClaireHandler();"));
  breakline_void();
  princ_string(copy_string("if ERROR_IN "));
  breakline_void();
  new_block_void();
  statement_any(GC_OID(v2548->arg),v1741,v332);
  princ_string(copy_string("ClEnv->cHandle--;"));
  close_block_void();
  princ_string(copy_string("else if (belong_to(_oid_(ClEnv->exception_I),"));
  (*Generate.expression)(GC_OID((*Optimize.c_code)(GC_OID(v2548->test),
      _oid_(Kernel._any))),
    _oid_(Kernel.emptySet));
  princ_string(copy_string(") == CTRUE)"));
  breakline_void();
  new_block_void();
  princ_string(copy_string("c_handle.catchIt();"));
  statement_any(GC_OID(v2548->other),v1741,v332);
  close_block_void();
  princ_string(copy_string("else PREVIOUS_HANDLER;"));
  close_block_void();
  GC_UNBIND;} 

void  stat_construct_c_producer(Generate_c_producer *v1723,Construct *v2548,OID v1741,OID v332)
{ GC_BIND;
  if (boolean_I_any(v1741) != CTRUE)
   close_exception(((general_error *) (*Core._general_error)(_string_(copy_string("[202] A do should have been used for ~S")),
    _oid_(list::alloc(1,_oid_(v2548))))));
  { char * v1743 = GC_STRING(check_var_string(copy_string("v_bag"),v1741,v332));
    bag * v2329;
    { ClaireObject *V_CC ;
      if (INHERIT(v2548->isa,Language._List))
       V_CC = list::empty();
      else if (INHERIT(v2548->isa,Language._Set))
       V_CC = set::empty();
      else if (INHERIT(v2548->isa,Language._Tuple))
       V_CC = tuple::empty();
      else close_exception(((general_error *) (*Core._general_error)(_string_(copy_string("BUG: ~S")),
          _oid_(list::alloc(1,_oid_(v2548))))));
        v2329= (bag *) V_CC;} 
    new_block_void();
    if (get_property(Kernel.of,v2548) != CNULL)
     cast_I_bag(v2329,OBJECT(ClaireType,(*Kernel.of)(_oid_(v2548))));
    { ClaireBoolean * g0090I;
      { OID  v2999;
        { OID gc_local;
          ITERATE(v1744);
          v2999= Kernel.cfalse;
          bag *v1744_support;
          v1744_support = GC_OBJECT(list,v2548->args);
          for (START(v1744_support); NEXT(v1744);)
          if (c_func_any(v1744) != CTRUE)
           { v2999 = Kernel.ctrue;
            break;} 
          } 
        g0090I = boolean_I_any(v2999);
        } 
      
      if (g0090I == CTRUE) { princ_string(copy_string("OID "));
          princ_string(v1743);
          princ_string(copy_string(";"));
          breakline_void();
          princ_string(copy_string(""));
          } 
        } 
    if (Optimize.OPT->protection == CTRUE)
     { (v1723->stat = (v1723->stat+1));
      princ_string(copy_string("GC_ANY("));
      } 
    (*Kernel.c_princ)(v1741);
    princ_string(copy_string("= "));
    (*Generate.bag_expression)(Generate.PRODUCER->value,
      _oid_(v2329->isa),
      _oid_(v2329),
      _oid_(of_bag(v2329)),
      v332);
    if (Optimize.OPT->protection == CTRUE)
     princ_string(copy_string(")"));
    princ_string(copy_string(";"));
    { OID gc_local;
      ITERATE(v1744);
      bag *v1744_support;
      v1744_support = GC_OBJECT(list,v2548->args);
      for (START(v1744_support); NEXT(v1744);)
      { ClaireBoolean * v1726 = c_func_any(v1744);
        breakline_void();
        if (v1726 != CTRUE)
         statement_any(v1744,_string_(v1743),v332);
        princ_string(copy_string("(("));
        { OID  v3960;
          if (INHERIT(v2548->isa,Language._List))
           v3960 = _oid_(Kernel._list);
          else if (INHERIT(v2548->isa,Language._Set))
           v3960 = _oid_(Kernel._set);
          else v3960 = _oid_(Kernel._tuple);
            print_any(v3960);
          } 
        princ_string(copy_string(" *) "));
        (*Kernel.c_princ)(v1741);
        princ_string(copy_string(")"));
        addFast_c_producer(v1723);
        princ_string(copy_string("("));
        if (v1726 == CTRUE)
         (*Generate.expression)(v1744,
          v332);
        else c_princ_string(v1743);
          princ_string(copy_string(");"));
        } 
      } 
    close_block_void();
    } 
  GC_UNBIND;} 

void  stat_while_c_producer(Generate_c_producer *v1723,While *v2548,OID v1741,OID v332)
{ GC_BIND;
  new_block_void();
  { ClaireBoolean * v4417 = ((c_func_any(GC_OID(v2548->test)) == CTRUE) ? ((v2548->other != CTRUE) ? ((gc_usage_any(GC_OID(v2548->test),OBJECT(ClaireBoolean,v332)) == Kernel.cfalse) ? CTRUE: CFALSE): CFALSE): CFALSE);
    char * v1743 = GC_STRING(check_var_string(copy_string("v_while"),v1741,v332));
    if (Optimize.OPT->loop_gc == CTRUE)
     { princ_string(copy_string("OID gc_local;"));
      breakline_void();
      princ_string(copy_string(""));
      } 
    if (v4417 != CTRUE)
     { interface_I_class(Kernel._boolean);
      princ_string(v1743);
      princ_string(copy_string(";"));
      breakline_void();
      princ_string(copy_string(""));
      } 
    if (Kernel._string == OWNER(v1741))
     { (*Kernel.c_princ)(v1741);
      princ_string(copy_string("= _oid_("));
      expression_boolean(CFALSE,v332);
      princ_string(copy_string(");"));
      breakline_void();
      } 
    if (v4417 == CTRUE)
     { princ_string(copy_string("while ("));
      (*Optimize.bool_exp)(GC_OID(v2548->test),
        _oid_(not_any(_oid_(v2548->other))),
        v332);
      princ_string(copy_string(")"));
      } 
    else { { OID  v4923;
          { if (v2548->other == CTRUE)
             v4923 = Kernel.cfalse;
            else v4923 = v2548->test;
              GC_OID(v4923);} 
          statement_any(v4923,_string_(v1743),Kernel.ctrue);
          } 
        breakline_void();
        princ_string(copy_string("while ("));
        princ_string(v1743);
        princ_string(copy_string(" "));
        if (v2548->other == CTRUE)
         princ_string(copy_string("!="));
        else princ_string(copy_string("=="));
          princ_string(copy_string(" CTRUE)"));
        } 
      breakline_void();
    new_block_void();
    { ClaireBoolean * v8286 = ((Optimize.OPT->loop_gc == CTRUE) ? ((gc_usage_any(GC_OID(v2548->arg),CTRUE) != Kernel.cfalse) ? CTRUE: CFALSE): CFALSE);
      if (v8286 == CTRUE)
       { princ_string(copy_string("GC_LOOP;"));
        breakline_void();
        } 
      { OID  v5882;
        if (Kernel._string == OWNER(v1741))
         v5882 = v1741;
        else v5882 = CNULL;
          inner_statement_any(GC_OID(v2548->arg),_oid_(Kernel.emptySet),v5882);
        } 
      if (v4417 != CTRUE)
       statement_any(GC_OID(v2548->test),_string_(v1743),Kernel.ctrue);
      if (v8286 == CTRUE)
       princ_string(copy_string("GC_UNLOOP;"));
      } 
    close_block_void();
    } 
  close_block_void();
  GC_UNBIND;} 

void  stat_gassign_c_producer(Generate_c_producer *v1723,Gassign *v2548,OID v1741,OID v332)
{ GC_BIND;
  new_block_void();
  interface_I_c_producer(v1723,((nativeVar_ask_global_variable(v2548->var) == CTRUE) ?
    getRange_global_variable(v2548->var) :
    Kernel._any ));
  princ_string(copy_string(" truc;"));
  statement_any(GC_OID(v2548->arg),_string_(copy_string("truc")),v332);
  princ_string(copy_string(""));
  breakline_void();
  if (v2548->var->store_ask == CTRUE)
   { princ_string(copy_string("STOREI("));
    expression_global_variable(v2548->var,v332);
    princ_string(copy_string(",truc);"));
    } 
  else { princ_string(copy_string("("));
      expression_global_variable(v2548->var,v332);
      princ_string(copy_string(" = truc);"));
      } 
    close_block_void();
  GC_UNBIND;} 

void  stat_for_c_producer(Generate_c_producer *v1723,For *v2548,OID v1741,OID v332)
{ GC_BIND;
  { char * v1743 = GC_STRING(c_string_c_producer1(v1723,GC_OBJECT(Variable,v2548->var)));
    new_block_void();
    if (Optimize.OPT->loop_gc == CTRUE)
     { princ_string(copy_string("OID gc_local;"));
      breakline_void();
      princ_string(copy_string(""));
      } 
    princ_string(copy_string("ITERATE("));
    c_princ_string(v1743);
    princ_string(copy_string(");"));
    if (Kernel._string == OWNER(v1741))
     { breakline_void();
      (*Kernel.c_princ)(v1741);
      princ_string(copy_string("= Kernel.cfalse;"));
      } 
    breakline_void();
    if ((c_func_any(GC_OID(v2548->set_arg)) == CTRUE) && 
        (designated_ask_any(GC_OID(v2548->set_arg)) == CTRUE))
     { princ_string(copy_string("for (START("));
      (*Generate.expression)(GC_OID(v2548->set_arg),
        v332);
      princ_string(copy_string("); NEXT("));
      c_princ_string(v1743);
      princ_string(copy_string(");)"));
      } 
    else { char * v4901 = GC_STRING(append_string(v1743,copy_string("_support")));
        princ_string(copy_string("bag *"));
        c_princ_string(v4901);
        princ_string(copy_string(";"));
        breakline_void();
        princ_string(copy_string(""));
        statement_any(GC_OID(v2548->set_arg),_string_(v4901),v332);
        princ_string(copy_string("for (START("));
        c_princ_string(v4901);
        princ_string(copy_string("); NEXT("));
        c_princ_string(v1743);
        princ_string(copy_string(");)"));
        } 
      breakline_void();
    { ClaireBoolean * v8286 = ((Optimize.OPT->loop_gc == CTRUE) ? ((gc_usage_any(GC_OID(v2548->arg),CTRUE) != Kernel.cfalse) ? CTRUE: CFALSE): CFALSE);
      if (v8286 == CTRUE)
       { new_block_void();
        princ_string(copy_string("GC_LOOP;"));
        breakline_void();
        } 
      if ((Optimize.OPT->profile_ask == CTRUE) && 
          (_Z_any1(Optimize.OPT->in_method,Kernel._object) == CTRUE))
       { if (v8286 != CTRUE)
         new_block_void();
        princ_string(copy_string("PRloop(PR_x);"));
        breakline_void();
        } 
      { OID  v6849;
        if (Kernel._string == OWNER(v1741))
         v6849 = v1741;
        else v6849 = CNULL;
          statement_any(GC_OID(v2548->arg),_oid_(Kernel.emptySet),v6849);
        } 
      if (v8286 == CTRUE)
       { princ_string(copy_string("GC_UNLOOP;"));
        close_block_void();
        } 
      if ((Optimize.OPT->profile_ask == CTRUE) && 
          ((_Z_any1(Optimize.OPT->in_method,Kernel._object) == CTRUE) && 
            (v8286 != CTRUE)))
       close_block_void();
      close_block_void();
      } 
    } 
  GC_UNBIND;} 

void  stat_iteration_c_producer(Generate_c_producer *v1723,Iteration *v2548,OID v1741,OID v332)
{ GC_BIND;
  if (boolean_I_any(v1741) != CTRUE)
   close_exception(((general_error *) (*Core._general_error)(_string_(copy_string("[203] you should have used a FOR here:~S")),
    _oid_(list::alloc(1,_oid_(v2548))))));
  { char * v1743 = GC_STRING(c_string_c_producer1(v1723,GC_OBJECT(Variable,v2548->var)));
    char * v14787 = GC_STRING(check_var_string(copy_string("v_val"),v1741,v332));
    char * v15839 = GC_STRING(check_var_string(copy_string("v_list"),v1741,v332));
    new_block_void();
    princ_string(copy_string("bag *"));
    princ_string(v15839);
    princ_string(copy_string("; OID "));
    princ_string(v14787);
    princ_string(copy_string(";"));
    breakline_void();
    princ_string(copy_string(""));
    princ_string(copy_string("OID "));
    c_princ_string(v1743);
    princ_string(copy_string(",CLcount;"));
    breakline_void();
    princ_string(copy_string(""));
    statement_any(GC_OID(v2548->set_arg),_string_(v15839),v332);
    princ_string(copy_string(" "));
    (*Kernel.c_princ)(v1741);
    princ_string(copy_string(" = "));
    princ_string(v15839);
    princ_string(copy_string("->clone("));
    if (get_property(Kernel.of,v2548) != CNULL)
     (*Generate.expression)(GC_OID((*Optimize.c_code)(GC_OID((*Kernel.of)(_oid_(v2548))),
        _oid_(Kernel._type))),
      Core.nil->value);
    princ_string(copy_string(")"));
    princ_string(copy_string(";"));
    breakline_void();
    princ_string(copy_string("for (CLcount= 1; CLcount <= "));
    princ_string(v15839);
    princ_string(copy_string("->length; CLcount++)"));
    breakline_void();
    new_block_void();
    c_princ_string(v1743);
    princ_string(copy_string(" = (*("));
    princ_string(v15839);
    princ_string(copy_string("))[CLcount];"));
    breakline_void();
    statement_any(GC_OID(v2548->arg),_string_(v14787),Kernel.ctrue);
    breakline_void();
    princ_string(copy_string("(*((list *) "));
    (*Kernel.princ)(v1741);
    princ_string(copy_string("))[CLcount] = "));
    princ_string(v14787);
    princ_string(copy_string(";"));
    close_block_void();
    close_block_void();
    } 
  GC_UNBIND;} 

void  stat_super_c_producer(Generate_c_producer *v1723,Super *v2548,OID v1741,OID v332)
{ GC_BIND;
  { char * v2280 = GC_STRING(check_var_string(copy_string("v_rec"),v1741,v332));
    new_block_void();
    princ_string(copy_string("OID "));
    princ_string(v2280);
    princ_string(copy_string(";"));
    breakline_void();
    { OID gc_local;
      ITERATE(v1744);
      bag *v1744_support;
      v1744_support = GC_OBJECT(list,v2548->args);
      for (START(v1744_support); NEXT(v1744);)
      { statement_any(v1744,_string_(v2280),v332);
        princ_string(copy_string("PUSH("));
        princ_string(v2280);
        princ_string(copy_string(");"));
        breakline_void();
        } 
      } 
    if (Kernel._string == OWNER(v1741))
     { c_princ_string(string_v(v1741));
      princ_string(copy_string("="));
      } 
    expression_thing(v2548->selector,v332);
    princ_string(copy_string("->super("));
    (*Generate.expression)(GC_OID(_oid_(v2548->cast_to)),
      v332);
    princ_string(copy_string(","));
    princ_integer(v2548->args->length);
    princ_string(copy_string(");"));
    close_block_void();
    } 
  GC_UNBIND;} 

void  stat_let_c_producer(Generate_c_producer *v1723,Let *v2548,OID v1741,OID v332)
{ GC_RESERVE(8);  // v3.0.55 optim !
  { char * v4717 = GC_STRING(string_v((*Generate.c_string)(Generate.PRODUCER->value,
      _oid_(v2548->var->pname))));
    if ((v4717[1 - 1] == 'C') && 
        (v4717[2 - 1] == '%'))
     (v2548->var->pname = gensym_void());
    } 
  { OID  v1743 = GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
      GC_OID(_oid_(v2548->var))));
    ClaireBoolean * v1722 = Optimize.OPT->alloc_stack;
    OID  v1744 = GC_OID(v2548->value);
    ClaireBoolean * v1726 = CTRUE;
    new_block_void();
    (Optimize.OPT->alloc_stack = CFALSE);
    { OID gc_local;
      while ((v1726 == CTRUE))
      { GC_LOOP;
        if (INHERIT(v2548->isa,Language._Let_star))
         (Optimize.OPT->alloc_stack = CTRUE);
        interface_I_class(sort_Variable(GC_OBJECT(Variable,v2548->var)));
        princ_string(copy_string(" "));
        c_princ_string(string_v(v1743));
        princ_string(copy_string(""));
        if (c_func_any(v1744) == CTRUE)
         { princ_string(copy_string(" = "));
          if (bool_exp_ask_any(v1744) == CTRUE)
           (*Generate.bool_exp_I)(Generate.PRODUCER->value,
            v1744,
            v332);
          else (*Generate.expression)(v1744,
              v332);
            princ_string(copy_string(";"));
          breakline_void();
          princ_string(copy_string(""));
          } 
        else { (*Generate.init_var)(Generate.PRODUCER->value,
              _oid_(sort_Variable(GC_OBJECT(Variable,v2548->var))));
            princ_string(copy_string(";"));
            breakline_void();
            statement_any(v1744,v1743,v332);
            princ_string(copy_string(""));
            } 
          if (INHERIT(v2548->isa,Language._Let_star))
         (Optimize.OPT->alloc_stack = CFALSE);
        if (INHERIT(OWNER(v2548->arg),Language._Let))
         { GC__ANY(v2548 = OBJECT(Let,v2548->arg), 2);
          GC__OID(v1743 = (*Generate.c_string)(Generate.PRODUCER->value,
            GC_OID(_oid_(v2548->var))), 5);
          GC__OID(v1744 = v2548->value, 7);
          } 
        else v1726= CFALSE;
          GC_UNLOOP;} 
      } 
    (Optimize.OPT->alloc_stack = v1722);
    inner_statement_any(GC_OID(v2548->arg),v1741,v332);
    princ_string(copy_string(""));
    close_block_void();
    } 
  GC_UNBIND;} 

