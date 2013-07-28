/***** CLAIRE Compilation of file c:\claire\v3.3\src\compile\ocall.cl 
         [version 3.3.46 / safety 5] Sun Feb 15 15:37:26 2009 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
OID  restriction_I_property(property *v2164,list *v6212,ClaireBoolean *v13003)
{ { int  v6209 = 1;
    int  v6846 = v6212->length;
    { OID gc_local;
      while ((v6209 <= v6846))
      { ((*(v6212))[v6209]=_oid_(ptype_type(OBJECT(ClaireType,(*(v6212))[v6209]))));
        ++v6209;
        } 
      } 
    } 
  return (restriction_I_list(v2164->definition,v6212,v13003));} 

OID  restriction_I_list(list *v12462,list *v6212,ClaireBoolean *v13003)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  ;{ OID Result = 0;
    { ClaireBoolean * v15820 = ((class_I_type(OBJECT(ClaireType,(*(v6212))[1]))->open == 3) ? CTRUE : CFALSE);
      OID  v14965 = _oid_(Kernel.emptySet);
      { OID gc_local;
        ITERATE(v6218);
        for (START(v12462); NEXT(v6218);)
        { GC_LOOP;
          if ((boolean_I_any(v14965) != CTRUE) && 
              (tmatch_ask_list(v6212,OBJECT(restriction,v6218)->domain) == CTRUE))
           { if (v13003 == CTRUE)
             GC__OID(v14965 = v6218, 1);
            else v14965= _oid_(OBJECT(restriction,v6218)->range);
              { ;break;} 
            } 
          else if (length_bag(_exp_list(OBJECT(restriction,v6218)->domain,v6212)) != 0)
           { if (v13003 != CTRUE)
             { GC__OID(v14965 = _oid_(U_type(OBJECT(ClaireType,v14965),OBJECT(restriction,v6218)->range)), 1);
              } 
            else if ((Optimize.compiler->safety <= 3) || 
                ((equal(v14965,_oid_(Kernel.emptySet)) != CTRUE) || 
                  (v15820 == CTRUE)))
             { v14965= _oid_(Optimize.ambiguous);
              { ;break;} 
              } 
            else GC__OID(v14965 = v6218, 1);
              } 
          GC_UNLOOP;} 
        } 
      Result = v14965;
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  restriction_I_class(ClaireClass *v6203,list *v12462,list *v6212)
{ if (Optimize.compiler->safety > 3)
   ((*(v6212))[1]=_oid_(_exp_type(v6203,OBJECT(ClaireType,(*(v6212))[1]))));
  { OID Result = 0;
    { ITERATE(v6218);
      Result= Kernel.cfalse;
      for (START(v12462); NEXT(v6218);)
      if (_inf_equalt_class(v6203,OBJECT(ClaireType,(*(OBJECT(restriction,v6218)->domain))[1])) == CTRUE)
       { if (tmatch_ask_list(v6212,OBJECT(restriction,v6218)->domain) == CTRUE)
         { Result = v6218;
          break;} 
        else if (length_bag(_exp_list(OBJECT(restriction,v6218)->domain,v6212)) != 0)
         { Result = _oid_(Optimize.ambiguous);
          break;} 
        } 
      } 
    return (Result);} 
  } 

ClaireType * use_range_method(method *v2164,list *v10255)
{ GC_BIND;
  { ClaireType *Result ;
    if ((v2164->inline_ask == CTRUE) && 
        (v2164->typing == CNULL))
     { list * v12466 = GC_OBJECT(list,v2164->formula->vars);
      ClaireType * v10263 = Kernel._any;
      list * v6664;
      { { bag *v_list; OID v_val;
          OID v6222,CLcount;
          v_list = v12466;
           v6664 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v6222 = (*(v_list))[CLcount];
            v_val = (*Kernel.range)(v6222);
            
            (*((list *) v6664))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v6664);} 
      { OID gc_local;
        ITERATE(v6222);
        for (START(v12466); NEXT(v6222);)
        put_property2(Kernel.range,OBJECT(ClaireObject,v6222),(*(v10255))[(((*Kernel.index)(v6222))+1)]);
        } 
      v10263= GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v2164->formula->body))));
      { OID gc_local;
        ITERATE(v6222);
        for (START(v12466); NEXT(v6222);)
        put_property2(Kernel.range,OBJECT(ClaireObject,v6222),(*(v6664))[(((*Kernel.index)(v6222))+1)]);
        } 
      if (INHERIT(v2164->range->isa,Kernel._type))
       v10263= GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel._exp)(_oid_(v10263),
        _oid_(v2164->range))));
      if (boolean_I_any(_oid_(v10263)) != CTRUE)
       (*Optimize.Cerror)(_string_(copy_string("[207] inline ~S: range ~S is incompatible with ~S (inferred)")),
        _oid_(v2164),
        _oid_(v2164->range),
        GC_OID((*Optimize.c_type)(GC_OID(v2164->formula->body))));
      Result = v10263;
      } 
    else { { OID  v6206 = GC_OID(v2164->typing);
          list * v6664;
          { { bag *v_list; OID v_val;
              OID v6221,CLcount;
              v_list = v10255;
               v6664 = v_list->clone(Kernel._type);
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v6221 = (*(v_list))[CLcount];
                v_val = _oid_(ptype_type(OBJECT(ClaireType,v6221)));
                
                (*((list *) v6664))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v6664);} 
          ClaireType * v6906 = v2164->range;
          ClaireType * v6907;
          { { ClaireObject *V_CC ;
              { ClaireHandler c_handle = ClaireHandler();
                if ERROR_IN 
                { if (INHERIT(OWNER(v6206),Core._lambda))
                   V_CC = OBJECT(ClaireType,apply_lambda(OBJECT(lambda,v6206),v6664));
                  else if (INHERIT(OWNER(v6206),Kernel._property))
                   V_CC = OBJECT(ClaireType,apply_property(OBJECT(property,v6206),v6664));
                  else if (INHERIT(OWNER(v6206),Kernel._function))
                   { OID v15730;{ list * v13664;
                      { list * v12433 = list::empty(Kernel.emptySet);
                        { int  v6214 = 1;
                          int  v6847 = (v10255->length+1);
                          { OID gc_local;
                            while ((v6214 <= v6847))
                            { v12433->addFast(_oid_(Kernel._object));
                              ++v6214;
                              } 
                            } 
                          } 
                        v13664 = GC_OBJECT(list,v12433);
                        } 
                      v15730 = apply_function(OBJECT(ClaireFunction,v6206),v13664,v6664);
                      } 
                    
                    V_CC=OBJECT(ClaireType,v15730);} 
                  else V_CC = v6906;
                    ClEnv->cHandle--;} 
                else if (belong_to(_oid_(ClEnv->exception_I),_oid_(Kernel._any)) == CTRUE)
                { c_handle.catchIt();{ tformat_string(copy_string("~S's 2nd-order type failed on ~S \n"),0,GC_OBJECT(list,list::alloc(2,_oid_(v2164),_oid_(v10255))));
                    V_CC = v6906;
                    } 
                  } 
                else PREVIOUS_HANDLER;} 
              v6907= (ClaireType *) V_CC;} 
            GC_OBJECT(ClaireType,v6907);} 
          if ((boolean_I_any(sort_equal_class(osort_any(_oid_(v6906)),osort_any(_oid_(v6907)))) == CTRUE) || 
              (v2164->selector == Core.externC))
           Result = v6907;
          else if (boolean_I_any(sort_equal_class(Kernel._any,osort_any(_oid_(v6906)))) == CTRUE)
           { Union * v2072 = ((Union *) GC_OBJECT(Union,new_object_class(Core._Union)));
            (v2072->t1 = Kernel._any);
            (v2072->t2 = v6907);
            Result = v2072;
            } 
          else Result = v6906;
            } 
        } 
      GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Call_Optimize(Call *v2164)
{ GC_BIND;
  { ClaireType *Result ;
    { ClaireObject *V_CC ;
      if (v2164->selector == Language.function_I)
       V_CC = Kernel._function;
      else { property * v6219 = v2164->selector;
          list * v6212 = GC_OBJECT(list,v2164->args);
          list * v8375;
          { { bag *v_list; OID v_val;
              OID v6224,CLcount;
              v_list = v6212;
               v8375 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v6224 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v6224);
                
                (*((list *) v8375))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v8375);} 
          if (v6219 == Optimize.safe)
           V_CC = OBJECT(ClaireType,(*(v8375))[1]);
          else if ((v6219 == Core.externC) && 
              ((v6212->length == 2) && 
                (INHERIT(OWNER((*(v6212))[2]),Kernel._class))))
           V_CC = OBJECT(ClaireClass,(*(v6212))[2]);
          else if ((v6219 == Core.NEW) && 
              (INHERIT(OWNER((*(v6212))[1]),Kernel._class)))
           V_CC = OBJECT(ClaireClass,(*(v6212))[1]);
          else if ((v6219 == Core.check_in) && 
              (INHERIT(OWNER((*(v6212))[2]),Kernel._type)))
           { V_CC = ((v6212->length == 2) ?
              sort_abstract_I_type(OBJECT(ClaireType,(*(v6212))[2])) :
              OBJECT(ClaireType,(*(v6212))[2]) );
            } 
          else if ((v6219 == Kernel.nth) && 
              (_inf_equal_type(OBJECT(ClaireType,(*(v8375))[1]),Kernel._array) == CTRUE))
           { if (_inf_equal_type(GC_OBJECT(ClaireType,member_type(OBJECT(ClaireType,(*(v8375))[1]))),Kernel._float) == CTRUE)
             V_CC = Kernel._float;
            else V_CC = member_type(OBJECT(ClaireType,(*(v8375))[1]));
              } 
          else if ((v6219 == Core._at) && 
              (INHERIT(OWNER((*(v6212))[1]),Kernel._property)))
           { property * v6216 = OBJECT(property,(*(v6212))[1]);
            OID  v6203 = (*(v6212))[2];
            if ((INHERIT(OWNER(v6203),Kernel._class)) && 
                (Kernel._method == owner_any((*Core._at)(_oid_(v6216),
                  v6203))))
             V_CC = set::alloc(1,GC_OID((*Core._at)(_oid_(v6216),
              v6203)));
            else V_CC = Kernel._any;
              } 
          else if ((v6219 == Kernel.get) && 
              (INHERIT(OWNER((*(v6212))[1]),Kernel._relation)))
           { ClaireRelation * v6218 = OBJECT(ClaireRelation,(*(v6212))[1]);
            if (INHERIT(v6218->isa,Kernel._property))
             { ClaireObject * v12835 = GC_OBJECT(ClaireObject,_at_property1(((property *) v6218),class_I_type(OBJECT(ClaireType,(*(v8375))[2]))));
              if (Kernel._slot == v12835->isa)
               { if ((_inf_equal_type(CLREAD(restriction,v12835,range),Kernel._bag) == CTRUE) && 
                    (Optimize.compiler->safety < 3))
                 V_CC = class_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.range)((*(v6212))[2]))));
                else V_CC = ((belong_to(CLREAD(slot,v12835,DEFAULT),_oid_(CLREAD(restriction,v12835,range))) == CTRUE) ?
                  CLREAD(restriction,v12835,range) :
                  extends_type(CLREAD(restriction,v12835,range)) );
                } 
              else V_CC = v6218->range;
                } 
            else if (INHERIT(v6218->isa,Kernel._table))
             { V_CC = ((belong_to(CLREAD(table,v6218,DEFAULT),_oid_(v6218->range)) == CTRUE) ?
                v6218->range :
                extends_type(v6218->range) );
              } 
            else V_CC = CFALSE;
              } 
          else { OID  v6218 = GC_OID(restriction_I_property(v6219,v8375,CTRUE));
              if (Kernel._slot == OWNER(v6218))
               { if ((v6219 == Kernel.instances) && 
                    (INHERIT(OWNER((*(v6212))[1]),Kernel._class)))
                 { Param * v2072 = ((Param *) GC_OBJECT(Param,new_object_class(Core._Param)));
                  (v2072->arg = Kernel._list);
                  (v2072->params = list::alloc(1,_oid_(Kernel.of)));
                  (v2072->args = list::alloc(1,_oid_(set::alloc(1,(*(v6212))[1]))));
                  V_CC = v2072;
                  } 
                else V_CC = OBJECT(restriction,v6218)->range;
                  } 
              else if (Kernel._method == OWNER(v6218))
               V_CC = use_range_method(OBJECT(method,v6218),v8375);
              else if (boolean_I_any(_oid_(v6219->restrictions)) != CTRUE)
               V_CC = selector_psort_Call(v2164);
              else V_CC = (((v6219->open == 3) || 
                  (v6218 != _oid_(Optimize.ambiguous))) ?
                sort_abstract_I_type(v6219->range) :
                sort_abstract_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,restriction_I_property(v6219,v8375,CFALSE)))) );
              } 
            } 
        Result= (ClaireType *) V_CC;} 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Call_Optimize(Call *v2164)
{ return (c_code_call_Call(v2164,Kernel._void));} 

OID  c_code_call_Call(Call *v2164,ClaireClass *v12685)
{ GC_BIND;
  ;{ OID Result = 0;
    { property * v6219 = v2164->selector;
      list * v6212 = GC_OBJECT(list,v2164->args);
      if ((INHERIT(OWNER((*(v6212))[1]),Core._global_variable)) && 
          ((equal((*Kernel.range)((*(v6212))[1]),_oid_(Kernel.emptySet)) == CTRUE) && 
            (designated_ask_any(GC_OID((*Kernel.value)((*(v6212))[1]))) == CTRUE)))
       ((*(v6212))[1]=(*Kernel.value)((*(v6212))[1]));
      { OID  v6213 = GC_OID(inline_optimize_ask_Call(v2164));
        ClaireBoolean * v6202 = inherit_ask_class(OWNER((*(v6212))[1]),Kernel._property);
        OID  v6204 = GC_OID(daccess_any(_oid_(v2164),_sup_integer(Optimize.compiler->safety,5)));
        if ((v6202 == CTRUE) && 
            (((v6219 == Kernel.put) || 
                (v6219 == Core.write)) && 
              (v6212->length == 3)))
         Result = c_code_write_Call(v2164);
        else if ((v6202 == CTRUE) && 
            ((v6219 == Core.put_store) && 
              ((v6212->length == 4) && 
                ((*(v6212))[4] == Kernel.ctrue))))
         Result = c_code_write_Call(v2164);
        else if ((v6202 == CTRUE) && 
            (v6219 == Core.unknown_ask))
         Result = c_code_hold_property(OBJECT(property,(*(v6212))[1]),(*(v6212))[2],CNULL,CTRUE);
        else if ((v6202 == CTRUE) && 
            (v6219 == Core.known_ask))
         Result = c_code_hold_property(OBJECT(property,(*(v6212))[1]),(*(v6212))[2],CNULL,CFALSE);
        else if ((v6202 == CTRUE) && 
            ((v6219 == Core.erase) && 
              (INHERIT(OWNER((*(v6212))[2]),Language._Variable))))
         Result = (*Optimize.c_code)(GC_OID(Produce_erase_property2(OBJECT(property,(*(v6212))[1]),OBJECT(Variable,(*(v6212))[2]))),
          _oid_(v12685));
        else if (v6219 == Optimize.safe)
         { int  v6225 = Optimize.compiler->safety;
          ClaireBoolean * v6202 = Optimize.compiler->overflow_ask;
          OID  v6224 = CNULL;
          (Optimize.compiler->safety = 1);
          (Optimize.compiler->overflow_ask = CTRUE);
          { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Optimize.safe);
              (v2072->args = list::alloc(1,GC_OID((*Optimize.c_code)((*(v6212))[1],
                _oid_(v12685)))));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v6224 = _oid_(v2072);
              } 
            GC_OID(v6224);} 
          (Optimize.compiler->safety = v6225);
          (Optimize.compiler->overflow_ask = v6202);
          Result = v6224;
          } 
        else if (((v6219 == Kernel.add) || 
              (v6219 == Kernel.add_I)) && 
            (v6202 == CTRUE))
         Result = c_code_add_Call(v2164);
        else if (((v6219 == Kernel.add) || 
              (v6219 == Kernel.add_I)) && 
            (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(v6212))[1]))),Kernel._bag) == CTRUE))
         Result = c_code_add_bag_Call(v2164);
        else if ((v6202 == CTRUE) && 
            (v6219 == Kernel._delete))
         Result = c_code_delete_Call(v2164);
        else if ((contain_ask_set(Optimize.OPT->to_remove,_oid_(v6219)) == CTRUE) || 
            ((v6219 == Optimize.c_interface) && 
                ((v6212->length == 2) && 
                  (contain_ask_set(GC_OBJECT(set,Optimize.OPT->legal_modules),GC_OID(get_module_object(v6219))) != CTRUE))))
         Result = Core.nil->value;
        else if (v6204 != CNULL)
         Result = v6204;
        else if (Kernel._method == OWNER(v6213))
         Result = c_inline_method1(OBJECT(method,v6213),v6212,c_srange_method(OBJECT(method,v6213)));
        else if (((v6219 == Kernel._equal) || 
              (v6219 == Core._I_equal)) && 
            (daccess_any((*(v6212))[1],CTRUE) != CNULL))
         Result = c_code_hold_property(OBJECT(property,(*(OBJECT(bag,(*Core.args)((*(v6212))[1]))))[1]),GC_OID((*(OBJECT(bag,(*Core.args)((*(v6212))[1]))))[2]),(*(v6212))[2],equal(_oid_(v6219),_oid_(Kernel._equal)));
        else if (((v6219 == Kernel._equal) || 
              (v6219 == Core._I_equal)) && 
            (daccess_any((*(v6212))[2],CTRUE) != CNULL))
         Result = c_code_hold_property(OBJECT(property,(*(OBJECT(bag,(*Core.args)((*(v6212))[2]))))[1]),GC_OID((*(OBJECT(bag,(*Core.args)((*(v6212))[2]))))[2]),(*(v6212))[1],equal(_oid_(v6219),_oid_(Kernel._equal)));
        else if (((v6219 == Kernel.nth_equal) || 
              (v6219 == Kernel.put)) && 
            ((INHERIT(OWNER((*(v6212))[1]),Kernel._table)) && 
              (v6212->length == 3)))
         Result = c_code_table_Call(v2164);
        else if (((v6219 == Kernel.nth_put) || 
              (v6219 == Kernel.nth_equal)) && 
            ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(v6212))[1]))),Kernel._array) == CTRUE) && 
              (v6212->length == 3)))
         Result = c_code_array_Call(v2164);
        else if ((v6219 == Kernel.nth) || 
            (((v6219 == Kernel.get) && 
                (INHERIT(OWNER((*(v6212))[1]),Kernel._table))) || 
              ((v6219 == Kernel.nth_get) && 
                  (Kernel._array == OWNER((*(v6212))[1])))))
         Result = c_code_nth_Call(v2164);
        else if (v6219 == Kernel._Z)
         Result = c_code_belong_Call(v2164);
        else if (v6219 == Core.Id)
         Result = (*Optimize.c_code)(GC_OID(OPT_EVAL((*(v6212))[1])));
        else if (v6219 == Language.function_I)
         Result = _oid_(make_function_string(string_I_symbol(extract_symbol_any((*(v6212))[1]))));
        else if ((v6219 == Core.NOT) && 
            (INHERIT(OWNER((*(v6212))[1]),Language._Select)))
         Result = c_code_not_Select(OBJECT(Select,(*(v6212))[1]));
        else if ((v6219 == Core.call) && 
            (INHERIT(OWNER((*(v6212))[1]),Kernel._property)))
         { OID  v2038;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            update_property(Kernel.selector,
              v2072,
              2,
              Kernel._object,
              (*(v6212))[1]);
            (v2072->args = cdr_list(v6212));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v2038 = _oid_(v2072);
            } 
          Result = (*Optimize.c_code)(v2038);
          } 
        else if (v6219->open == 3)
         { list * v2999;
          { { bag *v_list; OID v_val;
              OID v6224,CLcount;
              v_list = v6212;
               v2999 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v6224 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v6224);
                
                (*((list *) v2999))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v2999);} 
          Result = c_warn_property(v6219,v6212,v2999);
          } 
        else { ClaireBoolean * g0092I;
          { ClaireBoolean *v_and;
            { v_and = ((v6219 == Language.bit_vector) ? CTRUE : CFALSE);
              if (v_and == CFALSE) g0092I =CFALSE; 
              else { { OID  v4923;
                  { OID gc_local;
                    ITERATE(v6225);
                    v4923= Kernel.cfalse;
                    bag *v6225_support;
                    v6225_support = GC_OBJECT(list,v2164->args);
                    for (START(v6225_support); NEXT(v6225);)
                    if (inherit_ask_class(OWNER(v6225),Kernel._integer) != CTRUE)
                     { v4923 = Kernel.ctrue;
                      break;} 
                    } 
                  v_and = not_any(v4923);
                  } 
                if (v_and == CFALSE) g0092I =CFALSE; 
                else g0092I = CTRUE;} 
              } 
            } 
          
          if (g0092I == CTRUE) Result = OPT_EVAL(_oid_(v2164));
            else if ((v6219 == Optimize.anyObject_I) || 
              ((v6219 == Optimize.object_I) || 
                ((v6219 == Kernel.add_method) && 
                    (v6202 == CTRUE))))
           Result = _oid_(v2164);
          else { list * v8375;
              { { bag *v_list; OID v_val;
                  OID v6224,CLcount;
                  v_list = v6212;
                   v8375 = v_list->clone();
                  for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                  { v6224 = (*(v_list))[CLcount];
                    v_val = (*Optimize.c_type)(v6224);
                    
                    (*((list *) v8375))[CLcount] = v_val;} 
                  } 
                GC_OBJECT(list,v8375);} 
              OID  v6226 = GC_OID(restriction_I_property(v6219,v8375,CTRUE));
              if (Kernel._slot == OWNER(v6226))
               { ClaireBoolean * v3501 = ((belong_to(OBJECT(slot,v6226)->DEFAULT,_oid_(OBJECT(restriction,v6226)->range)) != CTRUE) ? ((contain_ask_set(Optimize.OPT->knowns,_oid_(v6219)) != CTRUE) ? ((Optimize.compiler->safety < 5) ? CTRUE: CFALSE): CFALSE): CFALSE);
                if ((v3501 != CTRUE) || 
                    (designated_ask_any((*(v6212))[1]) == CTRUE))
                 { Call_slot * v2072 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
                  (v2072->selector = OBJECT(slot,v6226));
                  (v2072->arg = (*Optimize.c_code)((*(v6212))[1],
                    _oid_(psort_any(_oid_(domain_I_restriction(OBJECT(restriction,v6226)))))));
                  (v2072->test = v3501);
                  add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v2072));
                  Result = _oid_(v2072);
                  } 
                else { if (Optimize.compiler->optimize_ask == CTRUE)
                     { notice_void();
                      ;} 
                    Result = c_warn_property(v6219,v6212,v8375);
                    } 
                  } 
              else if (Kernel._method == OWNER(v6226))
               { if (v6219 == Kernel.nth_equal)
                 (Optimize.OPT->use_nth_equal = CTRUE);
                if (v8375->memq(_oid_(Kernel._void)) == CTRUE)
                 (*Optimize.Cerror)(_string_(copy_string("[205] call ~S uses a void argument [~S]")),
                  _oid_(v2164),
                  _oid_(v8375));
                if (((v6219 == Kernel.begin) || 
                      (v6219 == Kernel.end)) && 
                    (INHERIT(OWNER((*(v6212))[1]),Kernel._module)))
                 OPT_EVAL(_oid_(v2164));
                if ((last_list(OBJECT(restriction,v6226)->domain) == _oid_(Kernel._listargs)) || 
                    (((*(OBJECT(restriction,v6226)->domain))[1] == _oid_(Kernel._void)) && 
                        ((*(v6212))[1] != _oid_(ClEnv))))
                 Result = _oid_(open_message_property(v6219,v6212));
                else Result = c_code_method_method2(OBJECT(method,v6226),v6212,v8375,v12685);
                  } 
              else if (INHERIT(OWNER(v6226),Kernel._keyword))
               Result = c_warn_property(v6219,v6212,v8375);
              else Result = c_warn_Call(v2164,_oid_(v8375));
                } 
            } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

Call * open_message_property(property *v2164,list *v6212)
{ GC_BIND;
  selector_register_property(v2164);
  { Call *Result ;
    { list * v1337;
      { { bag *v_list; OID v_val;
          OID v6224,CLcount;
          v_list = v6212;
           v1337 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v6224 = (*(v_list))[CLcount];
            if ((*Optimize.c_type)(v6224) != _oid_(Kernel._void))
             v_val = (*Optimize.c_code)(v6224,
              _oid_(Kernel._any));
            else v_val = (*Optimize.Cerror)(_string_(copy_string("[206] use of void ~S in ~S~S")),
                v6224,
                _oid_(v2164),
                _oid_(v6212));
              
            (*((list *) v1337))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v1337);} 
      if (Optimize.OPT->allocation == CTRUE)
       { { bag *v_list; OID v_val;
          OID v6224,CLcount;
          v_list = v1337;
           v1337 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v6224 = (*(v_list))[CLcount];
            v_val = c_gc_I_any1(v6224);
            
            (*((list *) v1337))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v1337);} 
      { ClaireBoolean * g0094I;
        { ClaireBoolean *v_and;
          { v_and = Optimize.compiler->diet_ask;
            if (v_and == CFALSE) g0094I =CFALSE; 
            else { { OID  v6849;
                { ITERATE(v6224);
                  v6849= Kernel.cfalse;
                  for (START(v6212); NEXT(v6224);)
                  if ((INHERIT(OWNER(v6224),Kernel._class)) || 
                      (INHERIT(OWNER(v6224),Kernel._property)))
                   { v6849 = Kernel.ctrue;
                    break;} 
                  } 
                v_and = boolean_I_any(v6849);
                } 
              if (v_and == CFALSE) g0094I =CFALSE; 
              else g0094I = CTRUE;} 
            } 
          } 
        
        if (g0094I == CTRUE) { warn_void();
            tformat_string(copy_string("Non diet call ~S(~A) [254]\n"),2,list::alloc(2,_oid_(v2164),_oid_(v6212)));
            } 
          } 
      { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
        (v2072->selector = v2164);
        (v2072->args = v1337);
        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
        Result = v2072;
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Call(Call *v2164)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = ((v2164->selector == Language.function_I) ? CTRUE : (((v2164->selector == Optimize.safe) ? ((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)((*(v2164->args))[1]))) == CTRUE) : (((stable_ask_relation(v2164->selector) == CTRUE) ? (((OBJECT(ClaireBoolean,_oid_((INHERIT(v2164->selector->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v2164->selector->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(v2164->selector->range))))))) == CTRUE) ? CTRUE: CFALSE): CFALSE) != CTRUE)) ? CTRUE : CFALSE));
    GC_UNBIND; return (Result);} 
  } 

OID  daccess_any(OID v2164,ClaireBoolean *v6202)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(OWNER(v2164),Language._Call))
     { list * v6212 = GC_OBJECT(list,OBJECT(Call,v2164)->args);
      ClaireObject * v12835;
      { if ((OBJECT(Call,v2164)->selector == Kernel.get) && 
            (INHERIT(OWNER((*(v6212))[1]),Kernel._property)))
         v12835 = _at_property1(OBJECT(property,(*(v6212))[1]),class_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(v6212))[2])))));
        else v12835 = CFALSE;
          GC_OBJECT(ClaireObject,v12835);} 
      if ((Kernel._slot == v12835->isa) && ((v6202 == CTRUE) || 
          ((belong_to(CLREAD(slot,v12835,DEFAULT),_oid_(CLREAD(restriction,v12835,range))) == CTRUE) || 
            ((CLREAD(slot,v12835,srange) == Kernel._any) || 
              (CLREAD(slot,v12835,srange) == Kernel._integer)))))
       { Call_slot * v2072 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
        (v2072->selector = ((slot *) v12835));
        (v2072->arg = (*Optimize.c_code)((*(v6212))[2],
          _oid_(psort_any(_oid_(domain_I_restriction(((restriction *) v12835)))))));
        (v2072->test = CFALSE);
        add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      else Result = CNULL;
        } 
    else Result = CNULL;
      GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Call_slot(Call_slot *v2164)
{ GC_BIND;
  { ClaireBoolean *Result ;
    { slot * v6219 = v2164->selector;
      OID  v6224 = v2164->arg;
      Result = ((_oid_((INHERIT(v6219->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v6219->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(v6219->range))))) != Kernel.ctrue) ? ((v6219->range != Kernel._float) ? (((1 <= v6219->selector->open) || 
          (gcsafe_ask_class(domain_I_restriction(v6219)) != CTRUE)) ? CTRUE: CFALSE): CFALSE): CFALSE);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Call_slot_Optimize(Call_slot *v2164)
{ return (v2164->selector->range);} 

ClaireType * c_type_Call_table_Optimize(Call_table *v2164)
{ return (v2164->selector->range);} 

ClaireType * c_type_Call_array_Optimize(Call_array *v2164)
{ return (OBJECT(ClaireType,v2164->test));} 

OID  c_code_write_Call(Call *v2164)
{ GC_BIND;
  { OID Result = 0;
    { OID  v6216 = GC_OID((*(v2164->args))[1]);
      OID  v6224 = GC_OID((*(v2164->args))[2]);
      OID  v6225 = GC_OID((*(v2164->args))[3]);
      OID  v12867 = GC_OID((*Optimize.c_type)(v6225));
      property * v12680 = v2164->selector;
      OID  v6219 = GC_OID((*Optimize.restriction_I)(v6216,
        _oid_(list::alloc(1,GC_OID((*Optimize.c_type)(v6224)))),
        Kernel.ctrue));
      (Optimize.OPT->use_update = CTRUE);
      if (contain_ask_set(Optimize.OPT->to_remove,v6216) == CTRUE)
       Result = Core.nil->value;
      else if ((Kernel._slot == OWNER(v6219)) && ((_inf_equal_type(OBJECT(ClaireType,v12867),OBJECT(restriction,v6219)->range) == CTRUE) || 
          (4 <= Optimize.compiler->safety)))
       { if ((v6225 != CNULL) && 
            (boolean_I_any((*Kernel._exp)(v12867,
              GC_OID((*Kernel.srange)(v6219)))) != CTRUE))
         { warn_void();
          tformat_string(copy_string("sort error in ~S: ~S is a ~S [253]\n"),2,list::alloc(3,_oid_(v2164),
            v6225,
            v12867));
          } 
        if (((_inf_equal_type(OBJECT(ClaireType,v12867),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.range)(v6219)))) == CTRUE) || 
              ((_inf_equal_type(OBJECT(ClaireType,v12867),Kernel._object) == CTRUE) || 
                (((*Kernel.srange)(v6219) != _oid_(Kernel._object)) || 
                  (v6225 == CNULL)))) && 
            ((v12680 != Core.write) || 
                ((Update_ask_relation(OBJECT(ClaireRelation,v6216),v6224,v6225) == CTRUE) && 
                    ((OBJECT(ClaireRelation,v6216)->multivalued_ask == CFALSE) || 
                        (get_property(Kernel.if_write,OBJECT(ClaireObject,v6216)) == CNULL)))))
         { OID  v10267 = GC_OID((*Optimize.c_code)(v6224,
            _oid_(psort_any(_oid_(domain_I_restriction(OBJECT(restriction,v6219)))))));
          OID  v10268 = GC_OID(c_strict_code_any(v6225,psort_any(GC_OID((*Kernel.range)(v6219)))));
          Update * v2072 = ((Update *) GC_OBJECT(Update,new_object_class(Language._Update)));
          (v2072->selector = v6216);
          (v2072->value = v10268);
          { Update * v6876 = v2072; 
            OID  v6877;
            if (v12680 != Core.write)
             v6877 = _oid_(v12680);
            else v6877 = (*Optimize.c_code)(v6224,
                _oid_(Kernel._any));
              (v6876->arg = v6877);} 
          { Update * v6878 = v2072; 
            OID  v6879;
            { Call_slot * v2072 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
              update_property(Kernel.selector,
                v2072,
                2,
                Kernel._object,
                v6219);
              (v2072->arg = v10267);
              (v2072->test = CFALSE);
              add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v2072));
              v6879 = _oid_(v2072);
              } 
            (v6878->var = v6879);} 
          add_I_property(Kernel.instances,Language._Update,11,_oid_(v2072));
          Result = _oid_(v2072);
          } 
        else if (v12680 == Kernel.put)
         { OID  v2080;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.store);
            (v2072->args = list::alloc(5,v6224,
              (*Kernel.index)(v6219),
              GC_OID((*Kernel.srange)(v6219)),
              v6225,
              GC_OID((*Kernel.store_ask)(v6216))));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v2080 = _oid_(v2072);
            } 
          Result = (*Optimize.c_code)(v2080);
          } 
        else { if (Optimize.compiler->diet_ask == CTRUE)
             { warn_void();
              tformat_string(copy_string("~S is not a diet call [254]"),2,list::alloc(1,_oid_(v2164)));
              } 
            if ((Optimize.compiler->optimize_ask == CTRUE) && 
                (v6216 != _oid_(Kernel.instances)))
             { notice_void();
              ;} 
            { OID  v3041;
              { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Core.update);
                (v2072->args = list::alloc(5,v6216,
                  v6224,
                  (*Kernel.index)(v6219),
                  GC_OID((*Kernel.srange)(v6219)),
                  v6225));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v3041 = _oid_(v2072);
                } 
              Result = (*Optimize.c_code)(v3041);
              } 
            } 
          } 
      else { list * v8375;
          { { bag *v_list; OID v_val;
              OID v6224,CLcount;
              v_list = GC_OBJECT(list,v2164->args);
               v8375 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v6224 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v6224);
                
                (*((list *) v8375))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v8375);} 
          OID  v6226 = GC_OID(restriction_I_property(v12680,v8375,CTRUE));
          if (Kernel._method == OWNER(v6226))
           Result = c_code_method_method1(OBJECT(method,v6226),GC_OBJECT(list,v2164->args),v8375);
          else Result = c_warn_Call(v2164,_oid_(v8375));
            } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_hold_property(property *v6216,OID v6224,OID v6225,ClaireBoolean *v6202)
{ GC_BIND;
  { OID Result = 0;
    { OID  v6219 = GC_OID(restriction_I_property(v6216,list::alloc(1,GC_OID((*Optimize.c_type)(v6224))),CTRUE));
      if ((Kernel._slot == OWNER(v6219)) && ((v6225 == CNULL) || 
          ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v6225))),OBJECT(slot,v6219)->srange) == CTRUE) && 
              (identifiable_ask_any(v6225) == CTRUE))))
       { Call_slot * v12184;
        { { Call_slot * v2072 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
            update_property(Kernel.selector,
              v2072,
              2,
              Kernel._object,
              v6219);
            (v2072->arg = (*Optimize.c_code)(v6224,
              _oid_(psort_any(_oid_(domain_I_restriction(OBJECT(restriction,v6219)))))));
            (v2072->test = CFALSE);
            add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v2072));
            v12184 = v2072;
            } 
          GC_OBJECT(Call_slot,v12184);} 
        Call_method2 * v12178;
        { { Call_method2 * v2072 = ((Call_method2 *) GC_OBJECT(Call_method2,new_object_class(Language._Call_method2)));
            (v2072->arg = ((method *) _at_property1(Core.identical_ask,Kernel._any)));
            (v2072->args = list::alloc(2,_oid_(v12184),GC_OID((*Optimize.c_code)(v6225,
              GC_OID((*Kernel.srange)(v6219))))));
            add_I_property(Kernel.instances,Language._Call_method2,11,_oid_(v2072));
            v12178 = v2072;
            } 
          GC_OBJECT(Call_method2,v12178);} 
        if (v6202 == CTRUE)
         Result = (*Optimize.c_code)(_oid_(v12178));
        else { OID  v4003;
            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Core.NOT);
              (v2072->args = list::alloc(1,_oid_(v12178)));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v4003 = _oid_(v2072);
              } 
            Result = (*Optimize.c_code)(v4003);
            } 
          } 
      else { list * v6212 = list::alloc(2,_oid_(Kernel._any),_oid_(Kernel._any));
          { list * v4963;
            { OID v_bag;
              GC_ANY(v4963= list::empty(Kernel.emptySet));
              { { OID  v5924;
                  { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Kernel.get);
                    (v2072->args = list::alloc(2,_oid_(v6216),v6224));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v5924 = _oid_(v2072);
                    } 
                  v_bag = (*Optimize.c_code)(v5924,
                    _oid_(Kernel._any));
                  } 
                GC_OID(v_bag);} 
              ((list *) v4963)->addFast(v_bag);
              ((list *) v4963)->addFast(GC_OID((*Optimize.c_code)(v6225,
                _oid_(Kernel._any))));} 
            Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property2(((v6202 == CTRUE) ?
              Kernel._equal :
              Core._I_equal ),v6212))),v4963,v6212);
            } 
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_add_Call(Call *v2164)
{ GC_BIND;
  { OID Result = 0;
    { property * v6216 = OBJECT(property,(*(v2164->args))[1]);
      OID  v6224 = GC_OID((*(v2164->args))[2]);
      OID  v6225 = GC_OID((*(v2164->args))[3]);
      ClaireObject * v6219 = GC_OBJECT(ClaireObject,_at_property1(v6216,class_I_type(GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v6224)))))));
      (Optimize.OPT->use_update = CTRUE);
      if ((Kernel._slot == v6219->isa) && ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v6225))),GC_OBJECT(ClaireType,member_type(CLREAD(restriction,v6219,range)))) == CTRUE) || 
          (4 <= Optimize.compiler->safety)))
       { if (Update_ask_relation2(v6216,v2164->selector) == CTRUE)
         { OID  v12770 = GC_OID((*Optimize.c_code)(v6224,
            _oid_(psort_any(_oid_(domain_I_restriction(((restriction *) v6219)))))));
          Update * v2072 = ((Update *) GC_OBJECT(Update,new_object_class(Language._Update)));
          (v2072->selector = _oid_(v6216));
          (v2072->arg = _oid_(Kernel.add));
          { Update * v7557 = v2072; 
            OID  v7558;
            { Call_slot * v2072 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
              (v2072->selector = ((slot *) v6219));
              (v2072->arg = v12770);
              (v2072->test = CFALSE);
              add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v2072));
              v7558 = _oid_(v2072);
              } 
            (v7557->var = v7558);} 
          (v2072->value = (*Optimize.c_code)(v6225,
            _oid_(psort_any(GC_OID(_oid_(member_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.range)(_oid_(v6219)))))))))));
          add_I_property(Kernel.instances,Language._Update,11,_oid_(v2072));
          Result = _oid_(v2072);
          } 
        else if ((designated_ask_any(v6224) == CTRUE) && 
            ((v6216->store_ask != CTRUE) && 
                ((v2164->selector == Kernel.add_I) || 
                    (v6216->inverse == (NULL)))))
         { OID  v12770 = GC_OID((*Optimize.c_code)(v6224,
            _oid_(psort_any(_oid_(domain_I_restriction(((restriction *) v6219)))))));
          { OID  v8807;
            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Kernel.add);
              { Call * v7560 = v2072; 
                list * v7561;
                { OID v_bag;
                  GC_ANY(v7561= list::empty(Kernel.emptySet));
                  { { Call_slot * v2072 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
                      (v2072->selector = ((slot *) v6219));
                      (v2072->arg = v12770);
                      (v2072->test = CFALSE);
                      add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v2072));
                      v_bag = _oid_(v2072);
                      } 
                    GC_OID(v_bag);} 
                  ((list *) v7561)->addFast(v_bag);
                  ((list *) v7561)->addFast(v6225);} 
                (v7560->args = v7561);} 
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v8807 = _oid_(v2072);
              } 
            Result = (*Optimize.c_code)(v8807);
            } 
          } 
        else { if (Optimize.compiler->optimize_ask == CTRUE)
             { notice_void();
              ;} 
            Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Kernel.add_I,Kernel._property))),list::alloc(4,_oid_(v6216),
              v6224,
              (*Kernel.index)(_oid_(v6219)),
              v6225),list::alloc(4,_oid_(Kernel._property),
              GC_OID((*Optimize.c_type)(v6224)),
              _oid_(Kernel._integer),
              GC_OID((*Optimize.c_type)(v6225))));
            } 
          } 
      else { list * v15487;
          { { bag *v_list; OID v_val;
              OID v6224,CLcount;
              v_list = GC_OBJECT(list,v2164->args);
               v15487 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v6224 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v6224);
                
                (*((list *) v15487))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v15487);} 
          Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Kernel.add,Kernel._property))),GC_OBJECT(list,v2164->args),v15487);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_add_bag_Call(Call *v2164)
{ GC_BIND;
  { OID Result = 0;
    { OID  v6906 = GC_OID((*Optimize.c_type)(GC_OID((*(v2164->args))[1])));
      ClaireType * v6907 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID((*(v2164->args))[2])))));
      property * v10259;
      if (((INHERIT(OBJECT(ClaireObject,v6906)->isa,Core._Param)) && 
            (_inf_equal_type(v6907,GC_OBJECT(ClaireType,member_type(OBJECT(ClaireType,v6906)))) == CTRUE)) || 
          (4 <= Optimize.compiler->safety))
       v10259 = Kernel.add_I;
      else v10259 = v2164->selector;
        list * v6089 = list::alloc(2,v6906,_oid_(v6907));
      OID  v6226 = GC_OID(restriction_I_property(v10259,v6089,CTRUE));
      if ((_inf_equal_type(v6907,GC_OBJECT(ClaireType,member_type(OBJECT(ClaireType,v6906)))) != CTRUE) && 
          (v2164->selector == Kernel.add))
       { warn_void();
        tformat_string(copy_string("the bag addition ~S is poorly typed (~S) [251] \n"),2,list::alloc(2,_oid_(v2164),GC_OID(_oid_(member_type(OBJECT(ClaireType,v6906))))));
        } 
      if (Kernel._method == OWNER(v6226))
       Result = c_code_method_method1(OBJECT(method,v6226),GC_OBJECT(list,v2164->args),v6089);
      else Result = c_warn_Call(v2164,_oid_(v6089));
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_delete_Call(Call *v2164)
{ GC_BIND;
  { OID Result = 0;
    { OID  v6216 = GC_OID((*(v2164->args))[1]);
      OID  v6224 = GC_OID((*(v2164->args))[2]);
      OID  v6225 = GC_OID((*(v2164->args))[3]);
      ClaireObject * v6219 = GC_OBJECT(ClaireObject,_at_property1(OBJECT(property,v6216),class_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v6224))))));
      (Optimize.OPT->use_update = CTRUE);
      if ((OBJECT(ClaireRelation,v6216)->inverse == (NULL)) && 
          ((designated_ask_any(v6224) == CTRUE) && 
            ((Kernel._slot == v6219->isa) && ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v6225))),GC_OBJECT(ClaireType,member_type(CLREAD(restriction,v6219,range)))) == CTRUE) || 
                (4 <= Optimize.compiler->safety)))))
       { OID  v12770 = GC_OID((*Optimize.c_code)(v6224,
          _oid_(psort_any(_oid_(domain_I_restriction(((restriction *) v6219)))))));
        { OID  v64;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel._delete);
            { Call * v7585 = v2072; 
              list * v7586;
              { OID v_bag;
                GC_ANY(v7586= list::empty(Kernel.emptySet));
                { { Call_slot * v2072 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
                    (v2072->selector = ((slot *) v6219));
                    (v2072->arg = v12770);
                    (v2072->test = CFALSE);
                    add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v2072));
                    v_bag = _oid_(v2072);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v7586)->addFast(v_bag);
                ((list *) v7586)->addFast(v6225);} 
              (v7585->args = v7586);} 
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v64 = _oid_(v2072);
            } 
          Result = (*Optimize.c_code)(v64);
          } 
        } 
      else { list * v2947;
          { { bag *v_list; OID v_val;
              OID v6224,CLcount;
              v_list = GC_OBJECT(list,v2164->args);
               v2947 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v6224 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v6224);
                
                (*((list *) v2947))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v2947);} 
          Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Kernel._delete,Kernel._property))),GC_OBJECT(list,v2164->args),v2947);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_not_Select(Select *v6224)
{ GC_BIND;
  { OID Result = 0;
    { OID  v3908;
      { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
        (v2072->selector = Core.NOT);
        { Call * v7589 = v2072; 
          list * v7591;
          { OID v_bag;
            GC_ANY(v7591= list::empty(Kernel.emptySet));
            { { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                (v2072->var = v6224->var);
                (v2072->set_arg = v6224->set_arg);
                { Iteration * v7594 = v2072; 
                  OID  v7595;
                  { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                    (v2072->test = v6224->arg);
                    { If * v7614 = v2072; 
                      OID  v7615;
                      { Return * v2072 = ((Return *) GC_OBJECT(Return,new_object_class(Language._Return)));
                        (v2072->arg = Kernel.ctrue);
                        add_I_property(Kernel.instances,Language._Return,11,_oid_(v2072));
                        v7615 = _oid_(v2072);
                        } 
                      (v7614->arg = v7615);} 
                    (v2072->other = CNULL);
                    add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                    v7595 = _oid_(v2072);
                    } 
                  (v7594->arg = v7595);} 
                add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                v_bag = _oid_(v2072);
                } 
              GC_OID(v_bag);} 
            ((list *) v7591)->addFast(v_bag);} 
          (v7589->args = v7591);} 
        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
        v3908 = _oid_(v2072);
        } 
      Result = (*Optimize.c_code)(v3908);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_belong_Call(Call *v2164)
{ GC_BIND;
  { OID Result = 0;
    { OID  v6224 = GC_OID((*(v2164->args))[1]);
      OID  v6225 = GC_OID((*(v2164->args))[2]);
      list * v8375 = list::alloc(2,GC_OID((*Optimize.c_type)(v6225)),GC_OID((*Optimize.c_type)(v6224)));
      if (Kernel._set == OWNER(v6225))
       { Or * v2072 = ((Or *) GC_OBJECT(Or,new_object_class(Language._Or)));
        { Or * v7616 = v2072; 
          list * v7617;
          { list * v2715 = list::empty(Kernel.emptySet);
            { OID gc_local;
              ITERATE(v6226);
              bag *v6226_support;
              v6226_support = GC_OBJECT(bag,enumerate_any(v6225));
              for (START(v6226_support); NEXT(v6226);)
              { GC_LOOP;
                { OID  v16354;
                  { OID  v932;
                    { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Kernel._equal);
                      (v2072->args = list::alloc(2,v6224,v6226));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v932 = _oid_(v2072);
                      } 
                    v16354 = (*Optimize.c_code)(v932,
                      _oid_(Kernel._any));
                    } 
                  v2715->addFast(v16354);
                  } 
                GC_UNLOOP;} 
              } 
            v7617 = GC_OBJECT(list,v2715);
            } 
          (v7616->args = v7617);} 
        add_I_property(Kernel.instances,Language._Or,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      else if (_inf_equal_type(OBJECT(ClaireType,(*(v8375))[1]),Kernel._list) == CTRUE)
       Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property2(Kernel.contain_ask,GC_OBJECT(list,list::alloc(2,_oid_(Kernel._list),_oid_(Kernel._any)))))),GC_OBJECT(list,list::alloc(2,v6225,v6224)),v8375);
      else if (_inf_equal_type(OBJECT(ClaireType,(*(v8375))[1]),Kernel._set) == CTRUE)
       Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property2(Kernel.contain_ask,GC_OBJECT(list,list::alloc(2,_oid_(Kernel._set),_oid_(Kernel._any)))))),GC_OBJECT(list,list::alloc(2,v6225,v6224)),v8375);
      else if (v6225 == _oid_(Kernel._object))
       Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property2(Kernel._Z,GC_OBJECT(list,list::alloc(2,_oid_(Kernel._any),_oid_(Kernel._class)))))),GC_OBJECT(list,list::alloc(2,v6224,v6225)),GC_OBJECT(list,list::alloc(2,_oid_(Kernel._any),_oid_(Kernel._class))));
      else Result = (*Optimize.member_code)(v6225,
          v6224);
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_nth_Call(Call *v2164)
{ GC_BIND;
  { OID Result = 0;
    { list * v6212 = GC_OBJECT(list,v2164->args);
      OID  v6224 = (*(v6212))[1];
      property * v6216 = v2164->selector;
      OID  v6220 = GC_OID((*Optimize.c_type)(v6224));
      ClaireType * v12495 = GC_OBJECT(ClaireType,member_type(OBJECT(ClaireType,v6220)));
      OID  v6218;
      { { list * v1892;
          { { bag *v_list; OID v_val;
              OID v6221,CLcount;
              v_list = v6212;
               v1892 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v6221 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v6221);
                
                (*((list *) v1892))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v1892);} 
          v6218 = restriction_I_property(v6216,v1892,CTRUE);
          } 
        GC_OID(v6218);} 
      if (contain_ask_set(Optimize.OPT->to_remove,v6224) == CTRUE)
       Result = Core.nil->value;
      else if (((INHERIT(OWNER(v6224),Kernel._table)) && (INHERIT(OWNER(OBJECT(table,v6224)->params),Kernel._integer))) && 
          ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(v6212))[2]))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.domain)(v6224)))) == CTRUE) || 
              ((v6216 == Kernel.nth) && 
                  (Optimize.compiler->safety > 2))))
       { Call_table * v2072 = ((Call_table *) GC_OBJECT(Call_table,new_object_class(Language._Call_table)));
        update_property(Kernel.selector,
          v2072,
          2,
          Kernel._object,
          v6224);
        (v2072->arg = (*Optimize.c_code)((*(v6212))[2],
          _oid_(Kernel._integer)));
        (v2072->test = not_any(_oid_(((belong_to(GC_OID((*Kernel.DEFAULT)(v6224)),GC_OID((*Kernel.range)(v6224))) == CTRUE) ? CTRUE : (((*Kernel.DEFAULT)(v6224) == 0) ? CTRUE : ((v6216 == Kernel.get) ? CTRUE : CFALSE))))));
        add_I_property(Kernel.instances,Language._Call_table,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      else if (((INHERIT(OWNER(v6224),Kernel._table)) && (INHERIT(OWNER(OBJECT(table,v6224)->params),Kernel._list))) && 
          ((v6212->length == 3) && 
            ((_inf_equal_type(GC_OBJECT(tuple,tuple_I_list(list::alloc(2,GC_OID((*Optimize.c_type)((*(v6212))[2])),GC_OID((*Optimize.c_type)((*(v6212))[3]))))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.domain)(v6224)))) == CTRUE) || 
                (Optimize.compiler->safety > 2))))
       { Call_table * v2072 = ((Call_table *) GC_OBJECT(Call_table,new_object_class(Language._Call_table)));
        update_property(Kernel.selector,
          v2072,
          2,
          Kernel._object,
          v6224);
        { Call_table * v7621 = v2072; 
          OID  v7623;
          { List * v2072 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
            (v2072->args = list::alloc(2,GC_OID((*Optimize.c_code)((*(v6212))[2],
              _oid_(Kernel._integer))),GC_OID((*Optimize.c_code)((*(v6212))[3],
              _oid_(Kernel._integer)))));
            add_I_property(Kernel.instances,Language._List,11,_oid_(v2072));
            v7623 = _oid_(v2072);
            } 
          (v7621->arg = v7623);} 
        (v2072->test = not_any(_oid_(((belong_to(GC_OID((*Kernel.DEFAULT)(v6224)),GC_OID((*Kernel.range)(v6224))) == CTRUE) ? CTRUE : (((*Kernel.DEFAULT)(v6224) == 0) ? CTRUE : ((v6216 == Kernel.get) ? CTRUE : CFALSE))))));
        add_I_property(Kernel.instances,Language._Call_table,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      else if ((_inf_equal_type(OBJECT(ClaireType,v6220),Kernel._array) == CTRUE) && 
          (((v6216 == Kernel.nth_get) || 
              (Optimize.compiler->safety > 2)) && 
            ((_inf_equal_type(v12495,Kernel._float) == CTRUE) || 
                (equal(_oid_(_exp_type(v12495,Kernel._float)),_oid_(Kernel.emptySet)) == CTRUE))))
       { Call_array * v2072 = ((Call_array *) GC_OBJECT(Call_array,new_object_class(Language._Call_array)));
        (v2072->selector = (*Optimize.c_code)(v6224,
          _oid_(Kernel._array)));
        (v2072->arg = (*Optimize.c_code)((*(v6212))[2],
          _oid_(Kernel._integer)));
        (v2072->test = _oid_(v12495));
        add_I_property(Kernel.instances,Language._Call_array,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      else if (Kernel._method == OWNER(v6218))
       { if ((Optimize.compiler->optimize_ask == CTRUE) && 
            ((_inf_equal_type(OBJECT(ClaireType,v6220),Kernel._array) == CTRUE) || 
                (_inf_equal_type(OBJECT(ClaireType,v6220),Kernel._table) == CTRUE)))
         { notice_void();
          ;} 
        { list * v4775;
          { { bag *v_list; OID v_val;
              OID v6224,CLcount;
              v_list = GC_OBJECT(list,v2164->args);
               v4775 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v6224 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v6224);
                
                (*((list *) v4775))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v4775);} 
          Result = c_code_method_method1(OBJECT(method,v6218),GC_OBJECT(list,v2164->args),v4775);
          } 
        } 
      else { list * v9533;
          { { bag *v_list; OID v_val;
              OID v6224,CLcount;
              v_list = GC_OBJECT(list,v2164->args);
               v9533 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v6224 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v6224);
                
                (*((list *) v9533))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v9533);} 
          Result = c_warn_property(v6216,GC_OBJECT(list,v2164->args),v9533);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_table_Call(Call *v2164)
{ GC_BIND;
  { OID Result = 0;
    { property * v12677 = v2164->selector;
      table * v6216 = OBJECT(table,(*(v2164->args))[1]);
      OID  v6224 = GC_OID((*(v2164->args))[2]);
      OID  v6225 = GC_OID((*(v2164->args))[3]);
      if (contain_ask_set(Optimize.OPT->to_remove,_oid_(v6216)) == CTRUE)
       Result = Core.nil->value;
      else if ((v12677 == Kernel.put) || 
          (((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v6224))),v6216->domain) == CTRUE) || 
                (5 <= Optimize.compiler->safety)) && 
              ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v6225))),v6216->range) == CTRUE) || 
                  (4 <= Optimize.compiler->safety))))
       { if ((Update_ask_relation(v6216,v6224,v6225) == CTRUE) && 
            ((INHERIT(OWNER(v6216->params),Kernel._list)) || 
                (INHERIT(OWNER(v6216->params),Kernel._integer))))
         { OID  v10267 = GC_OID((*Optimize.c_code)(v6224,
            _oid_(Kernel._any)));
          OID  v10268 = GC_OID((*Optimize.c_code)(v6225,
            _oid_(Kernel._any)));
          Update * v2072 = ((Update *) GC_OBJECT(Update,new_object_class(Language._Update)));
          (v2072->selector = _oid_(v6216));
          (v2072->value = v10268);
          { Update * v7646 = v2072; 
            OID  v7647;
            if (v12677 == Kernel.put)
             v7647 = _oid_(Kernel.put);
            else v7647 = v10267;
              (v7646->arg = v7647);} 
          { Update * v7648 = v2072; 
            OID  v7649;
            { Call_table * v2072 = ((Call_table *) GC_OBJECT(Call_table,new_object_class(Language._Call_table)));
              (v2072->selector = v6216);
              (v2072->arg = v10267);
              (v2072->test = CFALSE);
              add_I_property(Kernel.instances,Language._Call_table,11,_oid_(v2072));
              v7649 = _oid_(v2072);
              } 
            (v7648->var = v7649);} 
          add_I_property(Kernel.instances,Language._Update,11,_oid_(v2072));
          Result = _oid_(v2072);
          } 
        else if ((v12677 == Kernel.put) || 
            ((v6216->inverse == (NULL)) && 
                (v6216->if_write == CNULL)))
         { if (Optimize.compiler->optimize_ask == CTRUE)
           { notice_void();
            ;} 
          Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Kernel.put,Kernel._table))),GC_OBJECT(list,v2164->args),list::alloc(3,_oid_(Kernel._table),
            _oid_(Kernel._any),
            _oid_(Kernel._any)));
          } 
        else Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Kernel.nth_put,Kernel._table))),GC_OBJECT(list,v2164->args),list::alloc(3,_oid_(Kernel._table),
            _oid_(Kernel._any),
            _oid_(Kernel._any)));
          } 
      else Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Kernel.nth_equal,Kernel._table))),GC_OBJECT(list,v2164->args),list::alloc(3,_oid_(Kernel._table),
          _oid_(Kernel._any),
          _oid_(Kernel._any)));
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_array_Call(Call *v2164)
{ GC_BIND;
  { OID Result = 0;
    { property * v12677 = v2164->selector;
      OID  v6216 = GC_OID((*(v2164->args))[1]);
      OID  v12709 = GC_OID((*Optimize.c_type)(v6216));
      ClaireType * v12495 = GC_OBJECT(ClaireType,member_type(OBJECT(ClaireType,v12709)));
      OID  v6224 = GC_OID((*(v2164->args))[2]);
      OID  v6225 = GC_OID((*(v2164->args))[3]);
      ClaireBoolean * v1471 = ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v6225))),GC_OBJECT(ClaireType,member_type(OBJECT(ClaireType,v12709)))) == CTRUE) ? CTRUE : ((4 <= Optimize.compiler->safety) ? CTRUE : CFALSE));
      if (((v12677 == Kernel.nth_put) || 
            (v1471 == CTRUE)) && 
          ((_inf_equal_type(v12495,Kernel._float) == CTRUE) || 
              (equal(_oid_(_exp_type(v12495,Kernel._float)),_oid_(Kernel.emptySet)) == CTRUE)))
       { OID  v10267 = GC_OID((*Optimize.c_code)(v6224,
          _oid_(Kernel._integer)));
        OID  v10268;
        { { OID  v14338;
            if (_inf_equal_type(v12495,Kernel._float) == CTRUE)
             v14338 = _oid_(Kernel._float);
            else v14338 = _oid_(Kernel._any);
              v10268 = (*Optimize.c_code)(v6225,
              v14338);
            } 
          GC_OID(v10268);} 
        Update * v2072 = ((Update *) GC_OBJECT(Update,new_object_class(Language._Update)));
        (v2072->selector = v6216);
        (v2072->value = v10268);
        (v2072->arg = _oid_(Kernel.put));
        { Update * v7651 = v2072; 
          OID  v7652;
          { Call_array * v2072 = ((Call_array *) GC_OBJECT(Call_array,new_object_class(Language._Call_array)));
            (v2072->selector = (*Optimize.c_code)(v6216,
              _oid_(Kernel._array)));
            (v2072->arg = v10267);
            (v2072->test = _oid_(v12495));
            add_I_property(Kernel.instances,Language._Call_array,11,_oid_(v2072));
            v7652 = _oid_(v2072);
            } 
          (v7651->var = v7652);} 
        add_I_property(Kernel.instances,Language._Update,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      else { if (Optimize.compiler->optimize_ask == CTRUE)
           { notice_void();
            ;} 
          Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(((v1471 == CTRUE) ?
            Kernel.nth_put :
            v12677 ),Kernel._array))),GC_OBJECT(list,v2164->args),list::alloc(3,v12709,
            _oid_(Kernel._any),
            _oid_(Kernel._any)));
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * Update_ask_relation(ClaireRelation *v6216,OID v6224,OID v6225)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = ((v6216 != Kernel.inverse) ? ((((((v6216->if_write == CNULL) ? CTRUE : CFALSE) != CTRUE) && 
          (inherit_ask_class(OWNER(v6216->if_write),Kernel._list) != CTRUE)) || 
        ((v6216->inverse == (NULL)) && 
            (((INHERIT(v6216->isa,Kernel._table)) ? (INHERIT(OWNER(CLREAD(table,v6216,params)),Kernel._integer)) : (CTRUE == CTRUE)) && 
              ((v6216->store_ask == CTRUE) ? ((designated_ask_any(v6224) == CTRUE) && 
                  ((designated_ask_any(v6225) == CTRUE) && 
                    ((multi_ask_any(_oid_(v6216)) != CTRUE) && 
                      ((identifiable_ask_any(v6225) == CTRUE) || 
                          (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v6225))),Kernel._float) == CTRUE))))) : (CTRUE == CTRUE))))) ? CTRUE: CFALSE): CFALSE);
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * Update_ask_relation2(ClaireRelation *v6216,ClaireRelation *v6219)
{ return (((((v6216->if_write == CNULL) ? CTRUE : CFALSE) != CTRUE) ? ((inherit_ask_class(OWNER(v6216->if_write),Kernel._list) != CTRUE) ? ((v6219 == Kernel.add) ? CTRUE: CFALSE): CFALSE): CFALSE));} 

ClaireType * c_type_Update_Optimize(Update *v2164)
{ return (Kernel._void);} 

OID  c_code_method_method1(method *v2164,list *v6212,list *v8375)
{ return (c_code_method_method2(v2164,v6212,v8375,c_srange_method(v2164)));} 

OID  c_code_method_method2(method *v2164,list *v6212,list *v8375,ClaireClass *v12685)
{ GC_BIND;
  { OID Result = 0;
    if ((v2164->module_I != claire.it) || 
        ((Optimize.compiler->safety > 4) || 
          (((v2164->functional == (NULL)) ? CTRUE : CFALSE) != CTRUE)))
     { list * v12449 = v2164->domain;
      int  v6214 = v12449->length;
      if (v6214 != v6212->length)
       { list * v7517;
        { list * v15114 = list::empty(Kernel.emptySet);
          { int  v6209 = 1;
            int  v7653 = (v6214-1);
            { OID gc_local;
              while ((v6209 <= v7653))
              { v15114->addFast((*(v6212))[v6209]);
                ++v6209;
                } 
              } 
            } 
          v7517 = GC_OBJECT(list,v15114);
          } 
        OID  v8478;
        { list * v9306;{ list * v15114 = list::empty(Kernel.emptySet);
            { int  v6209 = v6214;
              int  v7654 = v6212->length;
              { OID gc_local;
                while ((v6209 <= v7654))
                { v15114->addFast((*(v6212))[v6209]);
                  ++v6209;
                  } 
                } 
              } 
            v9306 = GC_OBJECT(list,v15114);
            } 
          
          v8478=_oid_(v9306);} 
        v6212 = v7517->addFast(v8478);
        } 
      if ((v2164->inline_ask == CTRUE) && 
          (c_inline_ask_method(v2164,v6212) == CTRUE))
       Result = c_inline_method1(v2164,v6212,v12685);
      else { ClaireBoolean * v6202 = Optimize.OPT->allocation;
          OID  v6224 = Core.nil->value;
          (Optimize.OPT->allocation = CFALSE);
          { { list * v10400;
              { list * v15114 = list::empty(Kernel.emptySet);
                { int  v6209 = 1;
                  int  v7676 = v6214;
                  { OID gc_local;
                    while ((v6209 <= v7676))
                    { v15114->addFast(c_strict_code_any((*(v6212))[v6209],psort_any((*(v12449))[v6209])));
                      ++v6209;
                      } 
                    } 
                  } 
                v10400 = GC_OBJECT(list,v15114);
                } 
              v6224 = Call_method_I_method(v2164,v10400);
              } 
            GC_OID(v6224);} 
          if (Optimize.OPT->allocation != CTRUE)
           (Optimize.OPT->allocation = v6202);
          Result = v6224;
          } 
        } 
    else { if (Optimize.compiler->optimize_ask == CTRUE)
         { notice_void();
          ;} 
        Result = _oid_(open_message_property(v2164->selector,v6212));
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  Call_method_I_method(method *v2164,list *v16234)
{ GC_BIND;
  if (BCONTAIN(status_I_restriction(v2164),1))
   { (Optimize.OPT->allocation = CTRUE);
    if (nth_integer(v2164->status,5) != CTRUE)
     { { bag *v_list; OID v_val;
        OID v6224,CLcount;
        v_list = v16234;
         v16234 = v_list->clone();
        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
        { v6224 = (*(v_list))[CLcount];
          v_val = c_gc_I_any1(v6224);
          
          (*((list *) v16234))[CLcount] = v_val;} 
        } 
      GC_OBJECT(list,v16234);} 
    } 
  else { ClaireBoolean * g0145I;
    { ClaireBoolean *v_and;
      { v_and = Optimize.OPT->allocation;
        if (v_and == CFALSE) g0145I =CFALSE; 
        else { { int  v12322;
            { list * v13283;
              { bag * v14196 = v16234;
                list * v3807 = ((list *) empty_bag(v14196));
                { ITERATE(v6224);
                  for (START(v14196); NEXT(v6224);)
                  if ((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v6224))) == CTRUE)
                   v3807->addFast(v6224);
                  } 
                v13283 = GC_OBJECT(list,v3807);
                } 
              v12322 = v13283->length;
              } 
            v_and = ((v12322 > 1) ? CTRUE : CFALSE);
            } 
          if (v_and == CFALSE) g0145I =CFALSE; 
          else g0145I = CTRUE;} 
        } 
      } 
    
    if (g0145I == CTRUE) { { bag *v_list; OID v_val;
          OID v6224,CLcount;
          v_list = v16234;
           v16234 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v6224 = (*(v_list))[CLcount];
            v_val = c_gc_I_any1(v6224);
            
            (*((list *) v16234))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v16234);} 
      } 
  if (BCONTAIN(v2164->status,2))
   (Optimize.OPT->use_nth_equal = CTRUE);
  if (BCONTAIN(v2164->status,7))
   (Optimize.OPT->use_string_update = CTRUE);
  if (BCONTAIN(v2164->status,3))
   (Optimize.OPT->use_update = CTRUE);
  if (legal_ask_module(v2164->module_I,_oid_(v2164)) != CTRUE)
   tformat_string(copy_string("in call ~S~S\n"),0,list::alloc(2,_oid_(v2164->selector),_oid_(v16234)));
  { OID Result = 0;
    if (v16234->length == 1)
     { Call_method1 * v2072 = ((Call_method1 *) GC_OBJECT(Call_method1,new_object_class(Language._Call_method1)));
      (v2072->arg = v2164);
      (v2072->args = v16234);
      add_I_property(Kernel.instances,Language._Call_method1,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    else if (v16234->length == 2)
     { Call_method2 * v2072 = ((Call_method2 *) GC_OBJECT(Call_method2,new_object_class(Language._Call_method2)));
      (v2072->arg = v2164);
      (v2072->args = v16234);
      add_I_property(Kernel.instances,Language._Call_method2,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    else { Call_method * v2072 = ((Call_method *) GC_OBJECT(Call_method,new_object_class(Language._Call_method)));
        (v2072->arg = v2164);
        (v2072->args = v16234);
        add_I_property(Kernel.instances,Language._Call_method,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Call_method_Optimize(Call_method *v2164)
{ GC_BIND;
  { ClaireType *Result ;
    { list * v14244;
      { { bag *v_list; OID v_val;
          OID v6224,CLcount;
          v_list = GC_OBJECT(list,v2164->args);
           v14244 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v6224 = (*(v_list))[CLcount];
            v_val = (*Optimize.c_type)(v6224);
            
            (*((list *) v14244))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v14244);} 
      Result = use_range_method(v2164->arg,v14244);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Call_method_Optimize(Call_method *v2164)
{ return (_oid_(v2164));} 

ClaireBoolean * c_gc_ask_Call_method(Call_method *v2164)
{ GC_BIND;
  { ClaireBoolean *Result ;
    { method * v6213 = v2164->arg;
      { ClaireBoolean *v_and;
        { v_and = not_any(_oid_((INHERIT(v6213->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v6213->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(v6213->range))))));
          if (v_and == CFALSE) Result =CFALSE; 
          else { v_and = ((v6213->range != Kernel._float) ? CTRUE : CFALSE);
            if (v_and == CFALSE) Result =CFALSE; 
            else { v_and = ((nth_integer(status_I_restriction(v6213),5) != CTRUE) ? CTRUE : ((((_inf_equal_type(v6213->range,Kernel._bag) == CTRUE) ? ((Optimize.OPT->loop_gc == CTRUE) ? CTRUE: CFALSE): CFALSE) != CTRUE) ? CTRUE : CFALSE));
              if (v_and == CFALSE) Result =CFALSE; 
              else { { ClaireBoolean *v_or;
                  { v_or = nth_integer(status_I_restriction(v6213),1);
                    if (v_or == CTRUE) v_and =CTRUE; 
                    else { { ClaireBoolean *v_and;
                        { v_and = nth_integer(v6213->status,4);
                          if (v_and == CFALSE) v_or =CFALSE; 
                          else { { OID  v15205;
                              { OID gc_local;
                                ITERATE(v6224);
                                v15205= Kernel.cfalse;
                                bag *v6224_support;
                                v6224_support = GC_OBJECT(list,v2164->args);
                                for (START(v6224_support); NEXT(v6224);)
                                if ((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v6224))) == CTRUE)
                                 { v15205 = Kernel.ctrue;
                                  break;} 
                                } 
                              v_and = boolean_I_any(v15205);
                              } 
                            if (v_and == CFALSE) v_or =CFALSE; 
                            else v_or = CTRUE;} 
                          } 
                        } 
                      if (v_or == CTRUE) v_and =CTRUE; 
                      else v_and = CFALSE;} 
                    } 
                  } 
                if (v_and == CFALSE) Result =CFALSE; 
                else Result = CTRUE;} 
              } 
            } 
          } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireFunction * functional_I_method_Optimize(method *v2164)
{ GC_BIND;
  { ClaireFunction *Result ;
    { OID  v6206 = GC_OID(get_property(Kernel.functional,v2164));
      property * v6216 = v2164->selector;
      Result = ((INHERIT(OWNER(v6206),Kernel._function)) ?
        OBJECT(ClaireFunction,v6206) :
        make_function_string(string_v((*Optimize.function_name)(_oid_(v6216),
          _oid_(v2164->domain),
          v6206))) );
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  nth_type_check_type(ClaireType *v12704,ClaireType *v12701,ClaireType *v12716)
{ GC_BIND;
  if (_inf_equal_type(v12716,GC_OBJECT(ClaireType,member_type(v12704))) != CTRUE)
   { warn_void();
    tformat_string(copy_string("unsafe update on bag: type ~S into ~S [252]\n"),2,list::alloc(2,_oid_(v12716),_oid_(v12704)));
    } 
  { OID Result = 0;
    Result = _oid_(v12716);
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_inline_ask_method(method *v2164,list *v6212)
{ GC_BIND;
  { ClaireBoolean *Result ;
    { lambda * v6206 = GC_OBJECT(lambda,v2164->formula);
      list * v12445 = GC_OBJECT(list,v6206->vars);
      OID  v6224 = GC_OID(v6206->body);
      int  v6214 = 1;
      { OID  v3579;
        { OID gc_local;
          ITERATE(v6222);
          v3579= Kernel.cfalse;
          bag *v6222_support;
          v6222_support = GC_OBJECT(list,v6206->vars);
          for (START(v6222_support); NEXT(v6222);)
          if ((occurrence_any(v6224,OBJECT(Variable,v6222)) > 1) && 
              ((designated_ask_any((*(v6212))[v6214]) != CTRUE) && 
                (inherit_ask_class(owner_any((*Kernel.range)(v6222)),Optimize._Pattern) != CTRUE)))
           { v3579 = Kernel.ctrue;
            break;} 
          else ++v6214;
            } 
        Result = not_any(v3579);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  inline_optimize_ask_Call(Call *v2164)
{ GC_BIND;
  { OID Result = 0;
    { list * v6212 = GC_OBJECT(list,v2164->args);
      OID  v6213;
      { { list * v4540;
          { { bag *v_list; OID v_val;
              OID v6224,CLcount;
              v_list = v6212;
               v4540 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v6224 = (*(v_list))[CLcount];
                v_val = _oid_(set::alloc(1,v6224));
                
                (*((list *) v4540))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v4540);} 
          v6213 = restriction_I_property(v2164->selector,v4540,CTRUE);
          } 
        GC_OID(v6213);} 
      if (Kernel._method == OWNER(v6213))
       { { ClaireBoolean * g0152I;
          { ClaireBoolean *v_and;
            { v_and = OBJECT(method,v6213)->inline_ask;
              if (v_and == CFALSE) g0152I =CFALSE; 
              else { { OID  v6463;
                  { ITERATE(v6219);
                    v6463= Kernel.cfalse;
                    for (START(OBJECT(restriction,v6213)->domain); NEXT(v6219);)
                    if (INHERIT(OBJECT(ClaireObject,v6219)->isa,Optimize._Pattern))
                     { v6463 = Kernel.ctrue;
                      break;} 
                    } 
                  v_and = boolean_I_any(v6463);
                  } 
                if (v_and == CFALSE) g0152I =CFALSE; 
                else { v_and = c_inline_ask_method(OBJECT(method,v6213),v6212);
                  if (v_and == CFALSE) g0152I =CFALSE; 
                  else g0152I = CTRUE;} 
                } 
              } 
            } 
          
          if (g0152I == CTRUE) Result = v6213;
            else Result = Kernel.cfalse;
          } 
        } 
      else Result = Kernel.cfalse;
        } 
    GC_UNBIND; return (Result);} 
  } 

