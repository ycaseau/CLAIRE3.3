/***** CLAIRE Compilation of file c:\claire\v3.3\src\compile\odefine.cl 
         [version 3.3.34 / safety 5] Sun Mar 07 10:46:38 2004 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
ClaireType * c_type_List_Optimize(List *v9268)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  ;{ ClaireType *Result ;
    if (((v9268->of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
     Result = param_I_class(Kernel._list,v9268->of);
    else { OID  v8003 = _oid_(Kernel.emptySet);
        { OID gc_local;
          ITERATE(v13275);
          for (START(v9268->args); NEXT(v13275);)
          { GC_LOOP;
            if (boolean_I_any(v8003) == CTRUE)
             GC__OID(v8003 = _oid_(meet_class(OBJECT(ClaireClass,v8003),class_I_type(GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v13275))))))), 1);
            else GC__OID(v8003 = _oid_(class_I_type(GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v13275)))))), 1);
              GC_UNLOOP;} 
          } 
        Result = nth_class1(Kernel._list,OBJECT(ClaireType,v8003));
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  c_code_List_Optimize(List *v9268)
{ GC_BIND;
  (Optimize.OPT->allocation = CTRUE);
  { OID Result = 0;
    { List * v5264;
      { { List * v2072 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
          { Construct * v9475 = v2072; 
            list * v9476;
            { bag *v_list; OID v_val;
              OID v13275,CLcount;
              v_list = GC_OBJECT(list,v9268->args);
               v9476 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v13275 = (*(v_list))[CLcount];
                v_val = c_gc_I_any2(GC_OID((*Optimize.c_code)(v13275,
                  _oid_(Kernel._any))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v13275))));
                
                (*((list *) v9476))[CLcount] = v_val;} 
              } 
            (v9475->args = v9476);} 
          add_I_property(Kernel.instances,Language._List,11,_oid_(v2072));
          v5264 = v2072;
          } 
        GC_OBJECT(List,v5264);} 
      if (((v9268->of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
       { { ClaireBoolean * g0303I;
          { ClaireBoolean *v_or;
            { v_or = ((Optimize.compiler->safety > 4) ? CTRUE : CFALSE);
              if (v_or == CTRUE) g0303I =CTRUE; 
              else { v_or = ((equal(_oid_(v9268->of),_oid_(Kernel.emptySet)) == CTRUE) ? CTRUE : CFALSE);
                if (v_or == CTRUE) g0303I =CTRUE; 
                else { { OID  v1574;
                    { OID gc_local;
                      ITERATE(v13275);
                      v1574= _oid_(CFALSE);
                      bag *v13275_support;
                      v13275_support = GC_OBJECT(list,v9268->args);
                      for (START(v13275_support); NEXT(v13275);)
                      { GC_LOOP;
                        if (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v13275))),GC_OBJECT(ClaireType,v9268->of)) != CTRUE)
                         { v1574 = Kernel.ctrue;
                          break;} 
                        GC_UNLOOP;} 
                      } 
                    v_or = not_any(v1574);
                    } 
                  if (v_or == CTRUE) g0303I =CTRUE; 
                  else g0303I = CFALSE;} 
                } 
              } 
            } 
          
          if (g0303I == CTRUE) { (v5264->of = v9268->of);
              Result = _oid_(v5264);
              } 
            else { warn_void();
            { list * v2535;
              { { OID v_bag;
                  GC_ANY(v2535= list::empty(Kernel.emptySet));
                  { { list * v11107;{ bag *v_list; OID v_val;
                        OID v13275,CLcount;
                        v_list = GC_OBJECT(list,v9268->args);
                         v11107 = v_list->clone();
                        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                        { v13275 = (*(v_list))[CLcount];
                          v_val = (*Optimize.c_type)(v13275);
                          
                          (*((list *) v11107))[CLcount] = v_val;} 
                        } 
                      
                      v_bag=_oid_(v11107);} 
                    GC_OID(v_bag);} 
                  ((list *) v2535)->addFast(v_bag);
                  ((list *) v2535)->addFast(GC_OID(_oid_(v9268->of)));} 
                GC_OBJECT(list,v2535);} 
              tformat_string("unsafe typed list: ~S not in ~S [262]\n",2,v2535);
              } 
            { OID  v4457;
              { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Core.check_in);
                (v2072->args = list::alloc(3,_oid_(v5264),
                  _oid_(Kernel._list),
                  GC_OID(_oid_(v9268->of))));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v4457 = _oid_(v2072);
                } 
              Result = (*Optimize.c_code)(v4457,
                _oid_(Kernel._list));
              } 
            } 
          } 
        } 
      else Result = _oid_(v5264);
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Set_Optimize(Set *v9268)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  ;{ ClaireType *Result ;
    if (((v9268->of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
     Result = param_I_class(Kernel._set,v9268->of);
    else { OID  v8003 = _oid_(Kernel.emptySet);
        { OID gc_local;
          ITERATE(v13275);
          for (START(v9268->args); NEXT(v13275);)
          { GC_LOOP;
            if (boolean_I_any(v8003) == CTRUE)
             GC__OID(v8003 = _oid_(meet_class(OBJECT(ClaireClass,v8003),class_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v13275)))))), 1);
            else GC__OID(v8003 = _oid_(class_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v13275))))), 1);
              GC_UNLOOP;} 
          } 
        Result = nth_class1(Kernel._set,OBJECT(ClaireType,v8003));
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  c_code_Set_Optimize(Set *v9268)
{ GC_BIND;
  (Optimize.OPT->allocation = CTRUE);
  { OID Result = 0;
    { Set * v5264;
      { { Set * v2072 = ((Set *) GC_OBJECT(Set,new_object_class(Language._Set)));
          { Construct * v9483 = v2072; 
            list * v9484;
            { bag *v_list; OID v_val;
              OID v13275,CLcount;
              v_list = GC_OBJECT(list,v9268->args);
               v9484 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v13275 = (*(v_list))[CLcount];
                v_val = c_gc_I_any2(GC_OID((*Optimize.c_code)(v13275,
                  _oid_(Kernel._any))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v13275))));
                
                (*((list *) v9484))[CLcount] = v_val;} 
              } 
            (v9483->args = v9484);} 
          add_I_property(Kernel.instances,Language._Set,11,_oid_(v2072));
          v5264 = v2072;
          } 
        GC_OBJECT(Set,v5264);} 
      if (((v9268->of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
       { { ClaireBoolean * g0310I;
          { ClaireBoolean *v_or;
            { v_or = ((Optimize.compiler->safety > 4) ? CTRUE : CFALSE);
              if (v_or == CTRUE) g0310I =CTRUE; 
              else { v_or = ((equal(_oid_(v9268->of),_oid_(Kernel.emptySet)) == CTRUE) ? CTRUE : CFALSE);
                if (v_or == CTRUE) g0310I =CTRUE; 
                else { { OID  v12098;
                    { OID gc_local;
                      ITERATE(v13275);
                      v12098= _oid_(CFALSE);
                      bag *v13275_support;
                      v13275_support = GC_OBJECT(list,v9268->args);
                      for (START(v13275_support); NEXT(v13275);)
                      { GC_LOOP;
                        if (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v13275))),GC_OBJECT(ClaireType,v9268->of)) != CTRUE)
                         { v12098 = Kernel.ctrue;
                          break;} 
                        GC_UNLOOP;} 
                      } 
                    v_or = not_any(v12098);
                    } 
                  if (v_or == CTRUE) g0310I =CTRUE; 
                  else g0310I = CFALSE;} 
                } 
              } 
            } 
          
          if (g0310I == CTRUE) { (v5264->of = v9268->of);
              Result = _oid_(v5264);
              } 
            else { warn_void();
            { list * v13060;
              { { OID v_bag;
                  GC_ANY(v13060= list::empty(Kernel.emptySet));
                  { { list * v11135;{ bag *v_list; OID v_val;
                        OID v13275,CLcount;
                        v_list = GC_OBJECT(list,v9268->args);
                         v11135 = v_list->clone();
                        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                        { v13275 = (*(v_list))[CLcount];
                          v_val = (*Optimize.c_type)(v13275);
                          
                          (*((list *) v11135))[CLcount] = v_val;} 
                        } 
                      
                      v_bag=_oid_(v11135);} 
                    GC_OID(v_bag);} 
                  ((list *) v13060)->addFast(v_bag);
                  ((list *) v13060)->addFast(GC_OID(_oid_(v9268->of)));} 
                GC_OBJECT(list,v13060);} 
              tformat_string("unsafe typed set: ~S not in ~S [262]\n",2,v13060);
              } 
            { OID  v14982;
              { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Core.check_in);
                (v2072->args = list::alloc(3,_oid_(v5264),
                  _oid_(Kernel._set),
                  GC_OID(_oid_(v9268->of))));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v14982 = _oid_(v2072);
                } 
              Result = (*Optimize.c_code)(v14982,
                _oid_(Kernel._set));
              } 
            } 
          } 
        } 
      else Result = _oid_(v5264);
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Tuple_Optimize(Tuple *v9268)
{ GC_BIND;
  { ClaireType *Result ;
    { list * v15942;
      { { bag *v_list; OID v_val;
          OID v5264,CLcount;
          v_list = v9268->args;
           v15942 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v5264 = (*(v_list))[CLcount];
            v_val = (*Optimize.c_type)(v5264);
            
            (*((list *) v15942))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v15942);} 
      Result = tuple_I_list(v15942);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Tuple_Optimize(Tuple *v9268)
{ GC_BIND;
  (Optimize.OPT->allocation = CTRUE);
  { OID Result = 0;
    { Tuple * v2072 = ((Tuple *) GC_OBJECT(Tuple,new_object_class(Language._Tuple)));
      { Construct * v9511 = v2072; 
        list * v9512;
        { bag *v_list; OID v_val;
          OID v13275,CLcount;
          v_list = GC_OBJECT(list,v9268->args);
           v9512 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v13275 = (*(v_list))[CLcount];
            v_val = c_gc_I_any2(GC_OID((*Optimize.c_code)(v13275,
              _oid_(Kernel._any))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v13275))));
            
            (*((list *) v9512))[CLcount] = v_val;} 
          } 
        (v9511->args = v9512);} 
      add_I_property(Kernel.instances,Language._Tuple,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Definition_Optimize(Definition *v9268)
{ { ClaireType *Result ;
    if (_inf_equalt_class(v9268->arg,Kernel._exception) == CTRUE)
     Result = Kernel.emptySet;
    else Result = v9268->arg;
      return (Result);} 
  } 

OID  c_code_Definition_Optimize(Definition *v9268,ClaireClass *v5259)
{ GC_BIND;
  { OID Result = 0;
    { ClaireClass * v13254 = v9268->arg;
      Variable * v13274;
      { { int  v3402;
          { (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+1));
            v3402 = 0;
            } 
          v13274 = Variable_I_symbol(OBJECT(symbol,Optimize._starname_star->value),v3402,v13254);
          } 
        GC_OBJECT(Variable,v13274);} 
      OID  v13275 = GC_OID(total_ask_class(v13254,GC_OBJECT(list,v9268->args)));
      if (v13254->open <= 0)
       close_exception(((general_error *) (*Core._general_error)(_string_("[105] cannot instantiate ~S"),
        _oid_(list::alloc(1,_oid_(v13254))))));
      if (boolean_I_any(v13275) == CTRUE)
       Result = (*Optimize.c_code)(v13275,
        _oid_(v5259));
      else { OID  v8160;
          { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
            (v2072->var = v13274);
            { Let * v9537 = v2072; 
              OID  v9538;
              { Cast * v2072 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                { Cast * v9539 = v2072; 
                  OID  v9540;
                  { OID  v12965;
                    { { OID  v13926;
                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v2072->selector = Core.new_I);
                          (v2072->args = list::alloc(1,_oid_(v13254)));
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                          v13926 = _oid_(v2072);
                          } 
                        v12965 = (*Optimize.c_code)(v13926,
                          _oid_(Kernel._object));
                        } 
                      GC_OID(v12965);} 
                    v9540 = c_gc_I_any1(v12965);
                    } 
                  (v9539->arg = v9540);} 
                (v2072->set_arg = v13254);
                add_I_property(Kernel.instances,Language._Cast,11,_oid_(v2072));
                v9538 = _oid_(v2072);
                } 
              (v9537->value = v9538);} 
            { Let * v9544 = v2072; 
              OID  v9545;
              { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                store_object(v2072,
                  2,
                  Kernel._object,
                  analyze_I_class(v13254,_oid_(v13274),GC_OBJECT(list,v9268->args),list::empty()),
                  CFALSE);
                add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                v9545 = _oid_(v2072);
                } 
              (v9544->arg = v9545);} 
            add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
            v8160 = _oid_(v2072);
            } 
          Result = (*Optimize.c_code)(v8160,
            _oid_(v5259));
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  total_ask_class(ClaireClass *v9268,list *v5252)
{ GC_BIND;
  { OID Result = 0;
    { list * v15468 = GC_OBJECT(list,OBJECT(list,(*Optimize.get_indexed)(_oid_(v9268))));
      int  v5254 = v15468->length;
      { ClaireBoolean * g0330I;
        { ClaireBoolean *v_and;
          { v_and = not_any(_oid_(Optimize.compiler->diet_ask));
            if (v_and == CFALSE) g0330I =CFALSE; 
            else { v_and = ((v5252->length == (v5254-1)) ? CTRUE : CFALSE);
              if (v_and == CFALSE) g0330I =CFALSE; 
              else { v_and = ((v9268->open == ClEnv->ephemeral) ? CTRUE : ((_inf_equalt_class(v9268,Kernel._exception) == CTRUE) ? CTRUE : CFALSE));
                if (v_and == CFALSE) g0330I =CFALSE; 
                else { v_and = ((v5254 <= 4) ? CTRUE : CFALSE);
                  if (v_and == CFALSE) g0330I =CFALSE; 
                  else { { OID  v6144;
                      { int  v5249 = 2;
                        int  v9546 = v5254;
                        { OID gc_local;
                          v6144= _oid_(CFALSE);
                          while ((v5249 <= v9546))
                          { if ((((*Kernel.srange)((*(v15468))[v5249]) == _oid_(Kernel._integer)) ? CTRUE : (((*Kernel.srange)((*(v15468))[v5249]) == _oid_(Kernel._any)) ? CTRUE : CFALSE)) != CTRUE)
                             { v6144 = Kernel.ctrue;
                              break;} 
                            ++v5249;
                            } 
                          } 
                        } 
                      v_and = not_any(v6144);
                      } 
                    if (v_and == CFALSE) g0330I =CFALSE; 
                    else g0330I = CTRUE;} 
                  } 
                } 
              } 
            } 
          } 
        
        if (g0330I == CTRUE) { OID  v13254;
            { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = ((v5252->length == 0) ?
                  Core.new_I :
                  Optimize.anyObject_I ));
                { Call * v9569 = v2072; 
                  list * v9570;
                  { list * v9027;
                    { { bag *v_list; OID v_val;
                        OID v5264,CLcount;
                        v_list = v5252;
                         v9027 = v_list->clone();
                        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                        { v5264 = (*(v_list))[CLcount];
                          v_val = c_gc_I_any1(GC_OID((*Optimize.c_code)(GC_OID((*(OBJECT(bag,(*Core.args)(v5264))))[2]),
                            _oid_(Kernel._any))));
                          
                          (*((list *) v9027))[CLcount] = v_val;} 
                        } 
                      GC_OBJECT(list,v9027);} 
                    v9570 = cons_any(_oid_(v9268),v9027);
                    } 
                  (v9569->args = v9570);} 
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v13254 = _oid_(v2072);
                } 
              GC_OID(v13254);} 
            OID  v5253 = GC_OID(_oid_(_at_property1(Kernel.close,v9268)));
            if (_inf_equal_type(v9268,Kernel._exception) != CTRUE)
             (Optimize.OPT->allocation = CTRUE);
            if (v5252->length == 0)
             v13254= GC_OID((*Optimize.c_code)(v13254));
            if (boolean_I_any(v5253) == CTRUE)
             { Call_method1 * v2072 = ((Call_method1 *) GC_OBJECT(Call_method1,new_object_class(Language._Call_method1)));
              update_property(Kernel.arg,
                v2072,
                2,
                Kernel._object,
                v5253);
              (v2072->args = list::alloc(1,v13254));
              add_I_property(Kernel.instances,Language._Call_method1,11,_oid_(v2072));
              Result = _oid_(v2072);
              } 
            else Result = v13254;
              } 
          else Result = Kernel.cfalse;
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  analyze_I_class(ClaireClass *v5243,OID v9268,list *v13263,list *v15468)
{ GC_RESERVE(15);  // v3.0.55 optim !
  { OID Result = 0;
    { ClaireBoolean * v15097 = ((v5243->open != 4) ? ((boolean_I_any(_oid_(v15468)) != CTRUE) ? ((Optimize.compiler->class2file_ask != CTRUE) ? CTRUE: CFALSE): CFALSE): CFALSE);
      list * v5258;
      { { bag *v_list; OID v_val;
          OID v5264,CLcount;
          v_list = v13263;
           v5258 = v_list->clone(Kernel._any);
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v5264 = (*(v_list))[CLcount];
            { OID  v5256 = GC_OID((*(OBJECT(Call,v5264)->args))[1]);
              OID  v5265 = GC_OID((*(OBJECT(Call,v5264)->args))[2]);
              ClaireObject * v5259 = GC_OBJECT(ClaireObject,_at_property1(OBJECT(property,v5256),v5243));
              ClaireBoolean * v14222 = (((*Kernel.open)(v5256) == 0) ? ((Kernel._slot == v5259->isa) ? CTRUE: CFALSE): CFALSE);
              GC__ANY(v15468 = v15468->addFast(v5256), 4);
              { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = ((v14222 == CTRUE) ?
                  Kernel.put :
                  Core.write ));
                { Call * v9572 = v2072; 
                  list * v9573;
                  { OID v_bag;
                    GC_ANY(v9573= list::empty(Kernel.emptySet));
                    ((list *) v9573)->addFast(v5256);
                    ((list *) v9573)->addFast(v9268);
                    { if ((v14222 != CTRUE) || 
                          (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v5265))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.range)(_oid_(v5259))))) == CTRUE))
                       v_bag = v5265;
                      else v_bag = c_check_any(GC_OID((*Optimize.c_code)(v5265,
                          _oid_(Kernel._any))),GC_OID((*Optimize.c_code)(GC_OID((*Kernel.range)(_oid_(v5259))),
                          _oid_(Kernel._type))));
                        GC_OID(v_bag);} 
                    ((list *) v9573)->addFast(v_bag);} 
                  (v9572->args = v9573);} 
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v_val = _oid_(v2072);
                } 
              } 
            
            (*((list *) v5258))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v5258);} 
      if (v15097 == CTRUE)
       { { OID  v11910;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.add);
            (v2072->args = list::alloc(3,_oid_(Kernel.instances),
              _oid_(v5243),
              v9268));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v11910 = _oid_(v2072);
            } 
          v5258 = v5258->addFast(v11910);
          } 
        GC_OBJECT(list,v5258);} 
      if (Optimize.compiler->class2file_ask != CTRUE)
       { OID gc_local;
        ITERATE(v5259);
        bag *v5259_support;
        v5259_support = GC_OBJECT(list,OBJECT(bag,(*Optimize.get_indexed)(_oid_(v5243))));
        for (START(v5259_support); NEXT(v5259);)
        { GC_LOOP;
          { property * v5256 = OBJECT(restriction,v5259)->selector;
            OID  v5263 = GC_OID(OBJECT(slot,v5259)->DEFAULT);
            { ClaireBoolean * g0338I;
              { ClaireBoolean *v_and;
                { v_and = known_ask_any(v5263);
                  if (v_and == CFALSE) g0338I =CFALSE; 
                  else { { OID  v13832;
                      if (multi_ask_any(_oid_(v5256)) == CTRUE)
                       v13832 = v5263;
                      else v13832 = Kernel.ctrue;
                        v_and = boolean_I_any(v13832);
                      } 
                    if (v_and == CFALSE) g0338I =CFALSE; 
                    else { v_and = not_any(_oid_(v15468->memq(_oid_(v5256))));
                      if (v_and == CFALSE) g0338I =CFALSE; 
                      else { v_and = ((((v5256->inverse == (NULL)) ? CTRUE : CFALSE) != CTRUE) ? CTRUE : ((((v5256->if_write == CNULL) ? CTRUE : CFALSE) != CTRUE) ? CTRUE : (((OBJECT(slot,v5259)->srange != Kernel._object) && 
                            ((OBJECT(slot,v5259)->srange != Kernel._float) && 
                              (inherit_ask_class(OWNER(v5263),Kernel._integer) != CTRUE))) ? CTRUE : CFALSE)));
                        if (v_and == CFALSE) g0338I =CFALSE; 
                        else g0338I = CTRUE;} 
                      } 
                    } 
                  } 
                } 
              
              if (g0338I == CTRUE) { OID  v3776;
                  if (designated_ask_any(v5263) == CTRUE)
                   v3776 = v5263;
                  else { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Kernel.DEFAULT);
                      { Call * v9598 = v2072; 
                        list * v9599;
                        { OID v_bag;
                          GC_ANY(v9599= list::empty(Kernel.emptySet));
                          { { Cast * v2072 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                              { Cast * v9600 = v2072; 
                                OID  v9602;
                                { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                  (v2072->selector = Core._at);
                                  (v2072->args = list::alloc(2,_oid_(v5256),_oid_(v5243)));
                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                  v9602 = _oid_(v2072);
                                  } 
                                (v9600->arg = v9602);} 
                              (v2072->set_arg = Kernel._slot);
                              add_I_property(Kernel.instances,Language._Cast,11,_oid_(v2072));
                              v_bag = _oid_(v2072);
                              } 
                            GC_OID(v_bag);} 
                          ((list *) v9599)->addFast(v_bag);} 
                        (v9598->args = v9599);} 
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v3776 = _oid_(v2072);
                      } 
                    { { OID  v6050;
                      { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v2072->selector = Core.write);
                        (v2072->args = list::alloc(3,_oid_(v5256),
                          v9268,
                          v3776));
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                        v6050 = _oid_(v2072);
                        } 
                      v5258 = v5258->addFast(v6050);
                      } 
                     GC__ANY(v5258, 7);} 
                  } 
                } 
            } 
          GC_UNLOOP;} 
        } 
      { OID  v5253 = GC_OID(_oid_(_at_property1(Kernel.close,v5243)));
        { OID  v7011;
          if (boolean_I_any(v5253) == CTRUE)
           { Call_method1 * v2072 = ((Call_method1 *) GC_OBJECT(Call_method1,new_object_class(Language._Call_method1)));
            update_property(Kernel.arg,
              v2072,
              2,
              Kernel._object,
              v5253);
            (v2072->args = list::alloc(1,v9268));
            add_I_property(Kernel.instances,Language._Call_method1,11,_oid_(v2072));
            v7011 = _oid_(v2072);
            } 
          else v7011 = v9268;
            v5258 = v5258->addFast(v7011);
          } 
        } 
      Result = _oid_(v5258);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Defobj_Optimize(Defobj *v9268,ClaireClass *v5259)
{ GC_BIND;
  { OID Result = 0;
    { ClaireBoolean * v13253 = Optimize.OPT->allocation;
      ClaireClass * v13254 = v9268->arg;
      OID  v5255 = get_symbol(v9268->ident);
      OID  v13274;
      { if ((v5255 != CNULL) && 
            (inherit_ask_class(OWNER(v5255),Core._global_variable) != CTRUE))
         v13274 = v5255;
        else { Variable * v11234;{ int  v10855;
              { (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+1));
                v10855 = 0;
                } 
              v11234 = Variable_I_symbol(OBJECT(symbol,Optimize._starname_star->value),v10855,v13254);
              } 
            
            v13274=_oid_(v11234);} 
          GC_OID(v13274);} 
      Call * v2005;
      { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v2072->selector = Optimize.object_I);
          (v2072->args = list::alloc(2,_oid_(v9268->ident),_oid_(v13254)));
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
          v2005 = v2072;
          } 
        GC_OBJECT(Call,v2005);} 
      OID  v2006 = GC_OID(analyze_I_class(v13254,v13274,GC_OBJECT(list,v9268->args),list::alloc(1,_oid_(Kernel.name))));
      OID  v13275;
      if (inherit_ask_class(OWNER(v13274),Language._Variable) != CTRUE)
       { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
        store_object(v2072,
          2,
          Kernel._object,
          (*Kernel.cons)(_oid_(v2005),
            v2006),
          CFALSE);
        add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
        v13275 = _oid_(v2072);
        } 
      else { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
          store_object(v2072,
            2,
            Kernel._object,
            v13274,
            CFALSE);
          (v2072->value = _oid_(v2005));
          { Let * v9630 = v2072; 
            OID  v9631;
            { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
              store_object(v2072,
                2,
                Kernel._object,
                v2006,
                CFALSE);
              add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
              v9631 = _oid_(v2072);
              } 
            (v9630->arg = v9631);} 
          add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
          v13275 = _oid_(v2072);
          } 
        if (v13254->open <= 0)
       close_exception(((general_error *) (*Core._general_error)(_string_("[105] cannot instantiate ~S"),
        _oid_(list::alloc(1,_oid_(v13254))))));
      if (v5255 != CNULL)
       { if (contain_ask_list(Optimize.OPT->objects,v5255) != CTRUE)
         { GC_OBJECT(list,Optimize.OPT->objects)->addFast(v5255);
          (*Optimize.c_register)(v5255);
          } 
        } 
      else { warn_void();
          tformat_string("~S is unknown [265]\n",2,list::alloc(1,_oid_(v9268->ident)));
          } 
        v13275= GC_OID((*Optimize.c_code)(v13275,
        _oid_(v5259)));
      if (_inf_equal_type(v9268->arg,Kernel._exception) == CTRUE)
       (Optimize.OPT->allocation = v13253);
      Result = v13275;
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Defclass_Optimize(Defclass *v9268,ClaireClass *v5259)
{ GC_BIND;
  { OID Result = 0;
    { symbol * v10312 = v9268->ident;
      OID  v5255 = get_symbol(v10312);
      Call * v4985;
      { ClaireObject *V_CC ;
        if (v5255 != CNULL)
         { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v2072->selector = Core.class_I);
          (v2072->args = list::alloc(2,_oid_(v10312),_oid_(v9268->arg)));
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
          V_CC = v2072;
          } 
        else close_exception(((general_error *) (*Core._general_error)(_string_("[internal] cannot compile unknown class ~S"),
            _oid_(list::alloc(1,_oid_(v10312))))));
          v4985= (Call *) V_CC;} 
      Do * v13275;
      { { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
          { Do * v9633 = v2072; 
            list * v9634;
            { list * v4034;
              { { list * v4995;
                  { { bag *v_list; OID v_val;
                      OID v5264,CLcount;
                      v_list = GC_OBJECT(list,v9268->args);
                       v4995 = v_list->clone();
                      for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                      { v5264 = (*(v_list))[CLcount];
                        { OID  v5263 = CNULL;
                          if (INHERIT(OWNER(v5264),Language._Call))
                           { v5263= GC_OID((*(OBJECT(Call,v5264)->args))[2]);
                            v5264= GC_OID((*(OBJECT(Call,v5264)->args))[1]);
                            } 
                          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                            (v2072->selector = Kernel.add_slot);
                            (v2072->args = list::alloc(5,v5255,
                              _oid_(make_a_property_any(_oid_(OBJECT(Variable,v5264)->pname))),
                              GC_OID((*Kernel.range)(v5264)),
                              v5263,
                              0));
                            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                            v_val = _oid_(v2072);
                            } 
                          } 
                        
                        (*((list *) v4995))[CLcount] = v_val;} 
                      } 
                    GC_OBJECT(list,v4995);} 
                  list * v5956;
                  if (v9268->params->length != 0)
                   { OID v_bag;
                    GC_ANY(v5956= list::empty(Kernel.emptySet));
                    { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v2072->selector = Kernel.put);
                        (v2072->args = list::alloc(3,_oid_(Kernel.params),
                          v5255,
                          GC_OID(_oid_(v9268->params))));
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                        v_bag = _oid_(v2072);
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v5956)->addFast(v_bag);} 
                  else v5956 = list::empty();
                    v4034 = append_list(v4995,v5956);
                  } 
                GC_OBJECT(list,v4034);} 
              v9634 = cons_any(_oid_(v4985),v4034);
              } 
            (v9633->args = v9634);} 
          add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
          v13275 = v2072;
          } 
        GC_OBJECT(Do,v13275);} 
      if (contain_ask_list(Optimize.OPT->objects,v5255) != CTRUE)
       { GC_OBJECT(list,Optimize.OPT->objects)->addFast(v5255);
        (*Optimize.c_register)(v5255);
        } 
      Result = (*Optimize.c_code)(_oid_(v13275),
        _oid_(v5259));
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Defmethod_Optimize(Defmethod *v9268)
{ return (Kernel._any);} 

OID  c_code_Defmethod_Optimize(Defmethod *v9268)
{ GC_BIND;
  { OID Result = 0;
    { property * v15600 = v9268->arg->selector;
      list * v5252 = GC_OBJECT(list,v9268->arg->args);
      list * v15474 = (((v5252->length == 1) && 
          ((*(v5252))[1] == _oid_(ClEnv))) ?
        list::alloc(1,GC_OID(_oid_(Variable_I_symbol(OBJECT(symbol,Optimize._starname_star->value),0,Kernel._void)))) :
        v5252 );
      list * v15471 = GC_OBJECT(list,extract_signature_I_list(v15474));
      list * v5945 = GC_OBJECT(list,extract_range_any(GC_OID(v9268->set_arg),v15474,GC_OBJECT(list,OBJECT(list,Language.LDEF->value))));
      OID  v8090;
      if ((boolean_I_any(v9268->inline_ask) == CTRUE) && 
          (Optimize.compiler->inline_ask == CTRUE))
       { print_in_string_void();
        princ_string("lambda[(");
        ppvariable_list(v15474);
        princ_string("),");
        print_any(GC_OID(v9268->body));
        princ_string("]");
        v8090 = _string_(end_of_print_void());
        } 
      else v8090 = Kernel.cfalse;
        list * v11302 = GC_OBJECT(list,extract_status_new_any(GC_OID(v9268->body)));
      OID  v12479 = GC_OID((*Core._at)(_oid_(v15600),
        (*(v15471))[2]));
      method * v5253;
      { ClaireObject *V_CC ;
        if (Kernel._method == OBJECT(ClaireObject,v12479)->isa)
         V_CC = OBJECT(method,v12479);
        else close_exception(((general_error *) (*Core._general_error)(_string_("[internal] the method ~S @ ~S is not known"),
            _oid_(list::alloc(2,_oid_(v15600),(*(v15471))[2])))));
          v5253= (method *) V_CC;} 
      OID  v11284 = v5253->status;
      ((*(v11302))[2]=get_property(Kernel.functional,v5253));
      if ((Optimize.compiler->inline_ask != CTRUE) && 
          ((v15600 == Language.Iterate) || 
              (v15600 == Language.iterate)))
       Result = Core.nil->value;
      else if (((*(v5945))[1] == _oid_(Kernel._void)) && 
          (sort_pattern_ask_list(v15474,GC_OID(v9268->body)) == CTRUE))
       Result = sort_code_Defmethod(v9268,v15474);
      else { if ((*(v11302))[3] != _oid_(Kernel.body))
           { char * v15515 = GC_STRING(string_v((*Optimize.function_name)(_oid_(v15600),
              (*(v15471))[2],
              (*(v11302))[2])));
            lambda * v15453 = GC_OBJECT(lambda,lambda_I_list(v15474,(*(v11302))[3]));
            int  v8123 = ((Optimize.OPT->recompute == CTRUE) ?
              c_status_any(GC_OID(v15453->body),GC_OBJECT(list,v15453->vars)) :
              status_I_restriction(v5253) );
            compile_lambda_string(v15515,v15453,_oid_(v5253));
            if (((*(v11302))[1] == CNULL) || 
                (Optimize.OPT->recompute == CTRUE))
             { if ((Optimize.OPT->use_nth_equal != CTRUE) && 
                  (BCONTAIN(v8123,2)))
               v8123= (v8123-exp2_integer(2));
              if ((Optimize.OPT->use_update != CTRUE) && 
                  (BCONTAIN(v8123,3)))
               v8123= (v8123-exp2_integer(3));
              if ((Optimize.OPT->allocation != CTRUE) && 
                  (BCONTAIN(v8123,1)))
               v8123= (v8123-exp2_integer(1));
              ((*(v11302))[1]=v8123);
              } 
            ((*(v11302))[2]=_oid_(make_function_string(v15515)));
            } 
          if (INHERIT(OWNER(v9268->set_arg),Core._global_variable))
           ((*(v5945))[1]=v9268->set_arg);
          else if ((INHERIT(v5253->range->isa,Kernel._class)) && 
              (inherit_ask_class(OWNER((*(v5945))[1]),Kernel._class) != CTRUE))
           ((*(v5945))[1]=_oid_(v5253->range));
          { OID  v13264 = GC_OID(add_method_I_method(v5253,
              OBJECT(list,(*(v15471))[1]),
              (*(v5945))[1],
              (*(v11302))[1],
              OBJECT(ClaireFunction,(*(v11302))[2])));
            { OID  v6917;
              if ((boolean_I_any(v9268->inline_ask) == CTRUE) && 
                  ((Optimize.compiler->inline_ask == CTRUE) && 
                    (Optimize.compiler->diet_ask != CTRUE)))
               { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Core.inlineok_ask);
                (v2072->args = list::alloc(2,v13264,v8090));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v6917 = _oid_(v2072);
                } 
              else if ((boolean_I_any((*(v5945))[2]) == CTRUE) && 
                  (Optimize.compiler->diet_ask != CTRUE))
               { char * v15515 = GC_STRING(append_string(GC_STRING(string_v((*Optimize.function_name)(_oid_(v15600),
                  (*(v15471))[2],
                  (*(v11302))[2]))),"_type"));
                compile_lambda_string(v15515,OBJECT(lambda,(*(v5945))[2]),_oid_(Kernel._type));
                { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Core.write);
                  (v2072->args = list::alloc(3,Language.typing->value,
                    v13264,
                    _oid_(make_function_string(v15515))));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v6917 = _oid_(v2072);
                  } 
                } 
              else v6917 = v13264;
                Result = (*Optimize.c_code)(v6917);
              } 
            } 
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * sort_pattern_ask_list(list *v15474,OID v10079)
{ GC_BIND;
  { ClaireBoolean *Result ;
    { ClaireBoolean *v_and;
      { v_and = ((v15474->length == 1) ? CTRUE : CFALSE);
        if (v_and == CFALSE) Result =CFALSE; 
        else { if (INHERIT(OWNER(v10079),Language._Call))
           { ClaireBoolean *v_and1;
            { v_and1 = ((OBJECT(Call,v10079)->selector == Core.sort) ? CTRUE : CFALSE);
              if (v_and1 == CFALSE) v_and =CFALSE; 
              else { { OID  v15065 = GC_OID((*(OBJECT(Call,v10079)->args))[1]);
                  v_and1 = ((INHERIT(OWNER(v15065),Language._Call)) ?
                    ((OBJECT(Call,v15065)->selector == Core._at) ? ((INHERIT(OWNER((*(OBJECT(Call,v15065)->args))[1]),Kernel._property)) ? CTRUE: CFALSE): CFALSE) :
                    CFALSE );
                  } 
                if (v_and1 == CFALSE) v_and =CFALSE; 
                else { v_and1 = ((equal(lexical_build_any(GC_OID((*(OBJECT(Call,v10079)->args))[2]),v15474,0),(*(v15474))[1]) == CTRUE) ? CTRUE : CFALSE);
                  if (v_and1 == CFALSE) v_and =CFALSE; 
                  else v_and = CTRUE;} 
                } 
              } 
            } 
          else v_and = CFALSE;
            if (v_and == CFALSE) Result =CFALSE; 
          else Result = CTRUE;} 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  sort_code_Defmethod(Defmethod *v9268,list *v15474)
{ GC_BIND;
  { OID Result = 0;
    { OID  v5252 = (*(v15474))[1];
      OID  v5246 = GC_OID((*(OBJECT(bag,(*Core.args)(GC_OID((*(OBJECT(bag,(*Core.args)(GC_OID(v9268->body)))))[1])))))[1]);
      Variable * v5253 = GC_OBJECT(Variable,Variable_I_symbol(symbol_I_string2("m"),0,Kernel._integer));
      Variable * v5254 = GC_OBJECT(Variable,Variable_I_symbol(symbol_I_string2("n"),0,Kernel._integer));
      Variable * v5264 = GC_OBJECT(Variable,Variable_I_symbol(symbol_I_string2("x"),0,GC_OBJECT(ClaireType,member_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.range)(v5252)))))));
      Variable * v5256 = GC_OBJECT(Variable,Variable_I_symbol(symbol_I_string2("p"),0,Kernel._integer));
      Variable * v1353 = GC_OBJECT(Variable,Variable_I_symbol(symbol_I_string2("q"),0,Kernel._integer));
      Defmethod * v4532;
      { { Defmethod * v2072 = ((Defmethod *) GC_OBJECT(Defmethod,new_object_class(Language._Defmethod)));
          (v2072->arg = v9268->arg);
          (v2072->inline_ask = Kernel.cfalse);
          (v2072->set_arg = v9268->set_arg);
          { Defmethod * v9640 = v2072; 
            OID  v9661;
            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = v9268->arg->selector);
              { Call * v9662 = v2072; 
                list * v9663;
                { OID v_bag;
                  GC_ANY(v9663= list::empty(Kernel.emptySet));
                  ((list *) v9663)->addFast(1);
                  { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Kernel.length);
                      (v2072->args = list::alloc(1,(*(v15474))[1]));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v_bag = _oid_(v2072);
                      } 
                    GC_OID(v_bag);} 
                  ((list *) v9663)->addFast(v_bag);
                  ((list *) v9663)->addFast(v5252);} 
                (v9662->args = v9663);} 
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v9661 = _oid_(v2072);
              } 
            (v9640->body = v9661);} 
          add_I_property(Kernel.instances,Language._Defmethod,11,_oid_(v2072));
          v4532 = v2072;
          } 
        GC_OBJECT(Defmethod,v4532);} 
      If * v1343;
      { { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
          { If * v9664 = v2072; 
            OID  v9665;
            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Kernel._sup);
              (v2072->args = list::alloc(2,_oid_(v5253),_oid_(v5254)));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v9665 = _oid_(v2072);
              } 
            (v9664->test = v9665);} 
          { If * v9666 = v2072; 
            OID  v9667;
            { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
              (v2072->var = v5264);
              { Let * v9668 = v2072; 
                OID  v9669;
                { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Kernel.nth);
                  (v2072->args = list::alloc(2,v5252,_oid_(v5254)));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v9669 = _oid_(v2072);
                  } 
                (v9668->value = v9669);} 
              { Let * v9670 = v2072; 
                OID  v9691;
                { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                  { If * v9692 = v2072; 
                    OID  v9693;
                    { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Kernel._equal);
                      { Call * v9694 = v2072; 
                        list * v9696;
                        { OID v_bag;
                          GC_ANY(v9696= list::empty(Kernel.emptySet));
                          ((list *) v9696)->addFast(_oid_(v5253));
                          { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                              (v2072->selector = Core._plus);
                              (v2072->args = list::alloc(2,_oid_(v5254),1));
                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                              v_bag = _oid_(v2072);
                              } 
                            GC_OID(v_bag);} 
                          ((list *) v9696)->addFast(v_bag);} 
                        (v9694->args = v9696);} 
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v9693 = _oid_(v2072);
                      } 
                    (v9692->test = v9693);} 
                  { If * v9697 = v2072; 
                    OID  v9698;
                    { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                      { If * v9699 = v2072; 
                        OID  v9700;
                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          update_property(Kernel.selector,
                            v2072,
                            2,
                            Kernel._object,
                            v5246);
                          { Call * v9701 = v2072; 
                            list * v9722;
                            { OID v_bag;
                              GC_ANY(v9722= list::empty(Kernel.emptySet));
                              { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                  (v2072->selector = Kernel.nth);
                                  (v2072->args = list::alloc(2,v5252,_oid_(v5253)));
                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                  v_bag = _oid_(v2072);
                                  } 
                                GC_OID(v_bag);} 
                              ((list *) v9722)->addFast(v_bag);
                              ((list *) v9722)->addFast(_oid_(v5264));} 
                            (v9701->args = v9722);} 
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                          v9700 = _oid_(v2072);
                          } 
                        (v9699->test = v9700);} 
                      { If * v9723 = v2072; 
                        OID  v9724;
                        { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                          { Do * v9725 = v2072; 
                            list * v9727;
                            { OID v_bag;
                              GC_ANY(v9727= list::empty(Kernel.emptySet));
                              { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                  (v2072->selector = Kernel.nth_equal);
                                  { Call * v9728 = v2072; 
                                    list * v9729;
                                    { OID v_bag;
                                      GC_ANY(v9729= list::empty(Kernel.emptySet));
                                      ((list *) v9729)->addFast(v5252);
                                      ((list *) v9729)->addFast(_oid_(v5254));
                                      { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                          (v2072->selector = Kernel.nth);
                                          (v2072->args = list::alloc(2,v5252,_oid_(v5253)));
                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                          v_bag = _oid_(v2072);
                                          } 
                                        GC_OID(v_bag);} 
                                      ((list *) v9729)->addFast(v_bag);} 
                                    (v9728->args = v9729);} 
                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                  v_bag = _oid_(v2072);
                                  } 
                                GC_OID(v_bag);} 
                              ((list *) v9727)->addFast(v_bag);
                              { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                  (v2072->selector = Kernel.nth_equal);
                                  (v2072->args = list::alloc(3,v5252,
                                    _oid_(v5253),
                                    _oid_(v5264)));
                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                  v_bag = _oid_(v2072);
                                  } 
                                GC_OID(v_bag);} 
                              ((list *) v9727)->addFast(v_bag);} 
                            (v9725->args = v9727);} 
                          add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                          v9724 = _oid_(v2072);
                          } 
                        (v9723->arg = v9724);} 
                      add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                      (v2072->other = Kernel.cfalse);
                      v9698 = _oid_(v2072);
                      } 
                    (v9697->arg = v9698);} 
                  { If * v9730 = v2072; 
                    OID  v9731;
                    { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
                      (v2072->var = v5256);
                      { Let * v9732 = v2072; 
                        OID  v9753;
                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v2072->selector = Core._sup_sup);
                          { Call * v9755 = v2072; 
                            list * v9756;
                            { OID v_bag;
                              GC_ANY(v9756= list::empty(Kernel.emptySet));
                              { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                  (v2072->selector = Core._plus);
                                  (v2072->args = list::alloc(2,_oid_(v5254),_oid_(v5253)));
                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                  v_bag = _oid_(v2072);
                                  } 
                                GC_OID(v_bag);} 
                              ((list *) v9756)->addFast(v_bag);
                              ((list *) v9756)->addFast(1);} 
                            (v9755->args = v9756);} 
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                          v9753 = _oid_(v2072);
                          } 
                        (v9732->value = v9753);} 
                      { Let * v9757 = v2072; 
                        OID  v9758;
                        { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
                          (v2072->var = v1353);
                          (v2072->value = _oid_(v5254));
                          { Let * v9759 = v2072; 
                            OID  v9760;
                            { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                              { Do * v9761 = v2072; 
                                list * v9762;
                                { OID v_bag;
                                  GC_ANY(v9762= list::empty(Kernel.emptySet));
                                  { { Assign * v2072 = ((Assign *) GC_OBJECT(Assign,new_object_class(Language._Assign)));
                                      (v2072->var = _oid_(v5264));
                                      { Assign * v9763 = v2072; 
                                        OID  v10438;
                                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                          (v2072->selector = Kernel.nth);
                                          (v2072->args = list::alloc(2,v5252,_oid_(v5256)));
                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                          v10438 = _oid_(v2072);
                                          } 
                                        (v9763->arg = v10438);} 
                                      add_I_property(Kernel.instances,Language._Assign,11,_oid_(v2072));
                                      v_bag = _oid_(v2072);
                                      } 
                                    GC_OID(v_bag);} 
                                  ((list *) v9762)->addFast(v_bag);
                                  { { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                                      { If * v10439 = v2072; 
                                        OID  v10440;
                                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                          (v2072->selector = Core._I_equal);
                                          (v2072->args = list::alloc(2,_oid_(v5256),_oid_(v5254)));
                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                          v10440 = _oid_(v2072);
                                          } 
                                        (v10439->test = v10440);} 
                                      { If * v10441 = v2072; 
                                        OID  v10442;
                                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                          (v2072->selector = Kernel.nth_equal);
                                          { Call * v10443 = v2072; 
                                            list * v10444;
                                            { OID v_bag;
                                              GC_ANY(v10444= list::empty(Kernel.emptySet));
                                              ((list *) v10444)->addFast(v5252);
                                              ((list *) v10444)->addFast(_oid_(v5256));
                                              { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                  (v2072->selector = Kernel.nth);
                                                  (v2072->args = list::alloc(2,v5252,_oid_(v5254)));
                                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                                  v_bag = _oid_(v2072);
                                                  } 
                                                GC_OID(v_bag);} 
                                              ((list *) v10444)->addFast(v_bag);} 
                                            (v10443->args = v10444);} 
                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                          v10442 = _oid_(v2072);
                                          } 
                                        (v10441->arg = v10442);} 
                                      add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                                      (v2072->other = Kernel.cfalse);
                                      v_bag = _oid_(v2072);
                                      } 
                                    GC_OID(v_bag);} 
                                  ((list *) v9762)->addFast(v_bag);
                                  { { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                                      (v2072->var = v5256);
                                      { Iteration * v10445 = v2072; 
                                        OID  v10446;
                                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                          (v2072->selector = Kernel._dot_dot);
                                          { Call * v10447 = v2072; 
                                            list * v10466;
                                            { OID v_bag;
                                              GC_ANY(v10466= list::empty(Kernel.emptySet));
                                              { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                  (v2072->selector = Core._plus);
                                                  (v2072->args = list::alloc(2,_oid_(v5254),1));
                                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                                  v_bag = _oid_(v2072);
                                                  } 
                                                GC_OID(v_bag);} 
                                              ((list *) v10466)->addFast(v_bag);
                                              ((list *) v10466)->addFast(_oid_(v5253));} 
                                            (v10447->args = v10466);} 
                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                          v10446 = _oid_(v2072);
                                          } 
                                        (v10445->set_arg = v10446);} 
                                      { Iteration * v10467 = v2072; 
                                        OID  v10468;
                                        { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                                          { If * v10469 = v2072; 
                                            OID  v10470;
                                            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                              update_property(Kernel.selector,
                                                v2072,
                                                2,
                                                Kernel._object,
                                                v5246);
                                              { Call * v10471 = v2072; 
                                                list * v10472;
                                                { OID v_bag;
                                                  GC_ANY(v10472= list::empty(Kernel.emptySet));
                                                  { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                      (v2072->selector = Kernel.nth);
                                                      (v2072->args = list::alloc(2,v5252,_oid_(v5256)));
                                                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                                      v_bag = _oid_(v2072);
                                                      } 
                                                    GC_OID(v_bag);} 
                                                  ((list *) v10472)->addFast(v_bag);
                                                  ((list *) v10472)->addFast(_oid_(v5264));} 
                                                (v10471->args = v10472);} 
                                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                              v10470 = _oid_(v2072);
                                              } 
                                            (v10469->test = v10470);} 
                                          { If * v10473 = v2072; 
                                            OID  v10474;
                                            { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                                              { Do * v10475 = v2072; 
                                                list * v10497;
                                                { OID v_bag;
                                                  GC_ANY(v10497= list::empty(Kernel.emptySet));
                                                  { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                      (v2072->selector = Kernel.nth_equal);
                                                      { Call * v10498 = v2072; 
                                                        list * v10499;
                                                        { OID v_bag;
                                                          GC_ANY(v10499= list::empty(Kernel.emptySet));
                                                          ((list *) v10499)->addFast(v5252);
                                                          ((list *) v10499)->addFast(_oid_(v5254));
                                                          { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                              (v2072->selector = Kernel.nth);
                                                              (v2072->args = list::alloc(2,v5252,_oid_(v5256)));
                                                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                                              v_bag = _oid_(v2072);
                                                              } 
                                                            GC_OID(v_bag);} 
                                                          ((list *) v10499)->addFast(v_bag);} 
                                                        (v10498->args = v10499);} 
                                                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                                      v_bag = _oid_(v2072);
                                                      } 
                                                    GC_OID(v_bag);} 
                                                  ((list *) v10497)->addFast(v_bag);
                                                  { { Assign * v2072 = ((Assign *) GC_OBJECT(Assign,new_object_class(Language._Assign)));
                                                      (v2072->var = _oid_(v5254));
                                                      { Assign * v10500 = v2072; 
                                                        OID  v10501;
                                                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                          (v2072->selector = Core._plus);
                                                          (v2072->args = list::alloc(2,_oid_(v5254),1));
                                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                                          v10501 = _oid_(v2072);
                                                          } 
                                                        (v10500->arg = v10501);} 
                                                      add_I_property(Kernel.instances,Language._Assign,11,_oid_(v2072));
                                                      v_bag = _oid_(v2072);
                                                      } 
                                                    GC_OID(v_bag);} 
                                                  ((list *) v10497)->addFast(v_bag);
                                                  { { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                                                      { If * v10502 = v2072; 
                                                        OID  v10504;
                                                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                          (v2072->selector = Kernel._sup);
                                                          (v2072->args = list::alloc(2,_oid_(v5256),_oid_(v5254)));
                                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                                          v10504 = _oid_(v2072);
                                                          } 
                                                        (v10502->test = v10504);} 
                                                      { If * v10505 = v2072; 
                                                        OID  v10506;
                                                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                          (v2072->selector = Kernel.nth_equal);
                                                          { Call * v10507 = v2072; 
                                                            list * v10528;
                                                            { OID v_bag;
                                                              GC_ANY(v10528= list::empty(Kernel.emptySet));
                                                              ((list *) v10528)->addFast(v5252);
                                                              ((list *) v10528)->addFast(_oid_(v5256));
                                                              { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                                  (v2072->selector = Kernel.nth);
                                                                  (v2072->args = list::alloc(2,v5252,_oid_(v5254)));
                                                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                                                  v_bag = _oid_(v2072);
                                                                  } 
                                                                GC_OID(v_bag);} 
                                                              ((list *) v10528)->addFast(v_bag);} 
                                                            (v10507->args = v10528);} 
                                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                                          v10506 = _oid_(v2072);
                                                          } 
                                                        (v10505->arg = v10506);} 
                                                      add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                                                      (v2072->other = Kernel.cfalse);
                                                      v_bag = _oid_(v2072);
                                                      } 
                                                    GC_OID(v_bag);} 
                                                  ((list *) v10497)->addFast(v_bag);} 
                                                (v10475->args = v10497);} 
                                              add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                                              v10474 = _oid_(v2072);
                                              } 
                                            (v10473->arg = v10474);} 
                                          add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                                          (v2072->other = Kernel.cfalse);
                                          v10468 = _oid_(v2072);
                                          } 
                                        (v10467->arg = v10468);} 
                                      add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                                      v_bag = _oid_(v2072);
                                      } 
                                    GC_OID(v_bag);} 
                                  ((list *) v9762)->addFast(v_bag);
                                  { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                      (v2072->selector = Kernel.nth_equal);
                                      (v2072->args = list::alloc(3,v5252,
                                        _oid_(v5254),
                                        _oid_(v5264)));
                                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                      v_bag = _oid_(v2072);
                                      } 
                                    GC_OID(v_bag);} 
                                  ((list *) v9762)->addFast(v_bag);
                                  { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                      (v2072->selector = v9268->arg->selector);
                                      { Call * v10529 = v2072; 
                                        list * v10530;
                                        { OID v_bag;
                                          GC_ANY(v10530= list::empty(Kernel.emptySet));
                                          ((list *) v10530)->addFast(_oid_(v1353));
                                          { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                              (v2072->selector = Kernel._dash);
                                              (v2072->args = list::alloc(2,_oid_(v5254),1));
                                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                              v_bag = _oid_(v2072);
                                              } 
                                            GC_OID(v_bag);} 
                                          ((list *) v10530)->addFast(v_bag);
                                          ((list *) v10530)->addFast(v5252);} 
                                        (v10529->args = v10530);} 
                                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                      v_bag = _oid_(v2072);
                                      } 
                                    GC_OID(v_bag);} 
                                  ((list *) v9762)->addFast(v_bag);
                                  { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                      (v2072->selector = v9268->arg->selector);
                                      { Call * v10531 = v2072; 
                                        list * v10532;
                                        { OID v_bag;
                                          GC_ANY(v10532= list::empty(Kernel.emptySet));
                                          { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                              (v2072->selector = Core._plus);
                                              (v2072->args = list::alloc(2,_oid_(v5254),1));
                                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                              v_bag = _oid_(v2072);
                                              } 
                                            GC_OID(v_bag);} 
                                          ((list *) v10532)->addFast(v_bag);
                                          ((list *) v10532)->addFast(_oid_(v5253));
                                          ((list *) v10532)->addFast(v5252);} 
                                        (v10531->args = v10532);} 
                                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                      v_bag = _oid_(v2072);
                                      } 
                                    GC_OID(v_bag);} 
                                  ((list *) v9762)->addFast(v_bag);} 
                                (v9761->args = v9762);} 
                              add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                              v9760 = _oid_(v2072);
                              } 
                            (v9759->arg = v9760);} 
                          add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
                          v9758 = _oid_(v2072);
                          } 
                        (v9757->arg = v9758);} 
                      add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
                      v9731 = _oid_(v2072);
                      } 
                    (v9730->other = v9731);} 
                  add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                  v9691 = _oid_(v2072);
                  } 
                (v9670->arg = v9691);} 
              add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
              v9667 = _oid_(v2072);
              } 
            (v9666->arg = v9667);} 
          add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
          (v2072->other = Kernel.cfalse);
          v1343 = v2072;
          } 
        GC_OBJECT(If,v1343);} 
      Defmethod * v4533;
      { { Defmethod * v2072 = ((Defmethod *) GC_OBJECT(Defmethod,new_object_class(Language._Defmethod)));
          { Defmethod * v10533 = v2072; 
            Call * v10534;
            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = v9268->arg->selector);
              (v2072->args = list::alloc(3,_oid_(v5254),
                _oid_(v5253),
                v5252));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v10534 = v2072;
              } 
            (v10533->arg = v10534);} 
          (v2072->inline_ask = Kernel.cfalse);
          (v2072->set_arg = v9268->set_arg);
          (v2072->body = _oid_(v1343));
          add_I_property(Kernel.instances,Language._Defmethod,11,_oid_(v2072));
          v4533 = v2072;
          } 
        GC_OBJECT(Defmethod,v4533);} 
      tformat_string("---- note: quick sort optimisation for ~S ---- \n",2,list::alloc(1,_oid_(v9268->arg->selector)));
      OPT_EVAL(_oid_(v4533));
      { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
        (v2072->args = list::alloc(2,GC_OID((*Optimize.c_code)(_oid_(v4532))),GC_OID((*Optimize.c_code)(_oid_(v4533)))));
        add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

method * add_method_property2(property *v5256,list *v15471,ClaireType *v15645,int v15689,ClaireFunction *v15219,ClaireFunction *v15220)
{ return (add_method_property(v5256,
    v15471,
    v15645,
    v15689,
    _oid_(v15219)));} 

OID  add_method_I_method(method *v5253,list *v15471,OID v15645,OID v12924,ClaireFunction *v15287)
{ GC_BIND;
  { OID Result = 0;
    { Call_method * v13254;
      { { Call_method * v2072 = ((Call_method *) GC_OBJECT(Call_method,new_object_class(Language._Call_method)));
          (v2072->arg = ((method *) _at_property1(Kernel.add_method,Kernel._property)));
          (v2072->args = list::alloc(5,GC_OID((*Optimize.c_code)(_oid_(v5253->selector),
              _oid_(Kernel._property))),
            GC_OID((*Optimize.c_code)(_oid_(v15471),
              _oid_(Kernel._list))),
            GC_OID((*Optimize.c_code)(v15645,
              _oid_(Kernel._type))),
            v12924,
            _oid_(v15287)));
          add_I_property(Kernel.instances,Language._Call_method,11,_oid_(v2072));
          v13254 = v2072;
          } 
        GC_OBJECT(Call_method,v13254);} 
      if ((v5253->range == Kernel._float) || 
          ((v5253->domain->memq(_oid_(Kernel._float)) == CTRUE) || 
            (INHERIT(v5253->range->isa,Kernel._tuple))))
       GC_OBJECT(list,v13254->args)->addFast(_oid_(make_function_string(append_string(string_I_function(v15287),"_"))));
      Result = _oid_(v13254);
      } 
    GC_UNBIND; return (Result);} 
  } 

list * extract_status_new_any(OID v5264)
{ GC_BIND;
  { list *Result ;
    { OID  v5259 = CNULL;
      OID  v5246;
      if ((INHERIT(OWNER(v5264),Language._Call)) && (OBJECT(Call,v5264)->selector == Language.function_I))
       v5246 = v5264;
      else v5246 = CNULL;
        if (INHERIT(OWNER(v5264),Language._And))
       { OID  v5265 = (*(OBJECT(And,v5264)->args))[1];
        if ((INHERIT(OWNER(v5265),Language._Call)) && (OBJECT(Call,v5265)->selector == Language.function_I))
         { v5246= v5265;
          v5264= (*(OBJECT(And,v5264)->args))[2];
          } 
        } 
      else if (INHERIT(OWNER(v5264),Language._Call))
       { if (OBJECT(Call,v5264)->selector == Language.function_I)
         v5264= _oid_(Kernel.body);
        } 
      if (v5246 != CNULL)
       { v5264= _oid_(Kernel.body);
        if (length_bag(OBJECT(bag,(*Core.args)(v5246))) > 1)
         { ClaireHandler c_handle = ClaireHandler();
          if ERROR_IN 
          { { int  v12163;{ set * v3465;
                { set * v12630 = set::empty(Kernel.emptySet);
                  { OID gc_local;
                    ITERATE(v5261);
                    bag *v5261_support;
                    v5261_support = GC_OBJECT(list,cdr_list(GC_OBJECT(list,OBJECT(list,(*Core.args)(v5246)))));
                    for (START(v5261_support); NEXT(v5261);)
                    { GC_LOOP;
                      v12630->addFast(GC_OID(OPT_EVAL(v5261)));
                      GC_UNLOOP;} 
                    } 
                  v3465 = GC_OBJECT(set,v12630);
                  } 
                v12163 = integer_I_set(v3465);
                } 
              
              v5259=v12163;} 
            ClEnv->cHandle--;} 
          else if (belong_to(_oid_(ClEnv->exception_I),_oid_(Kernel._any)) == CTRUE)
          { c_handle.catchIt();{ warn_void();
              (Optimize.SHIT->value= _oid_(cdr_list(GC_OBJECT(list,OBJECT(list,(*Core.args)(v5246))))));
              tformat_string("wrong status ~S -> ~S [266]\n",2,GC_OBJECT(list,list::alloc(2,v5246,_oid_(set_I_bag(cdr_list(GC_OBJECT(list,OBJECT(list,(*Core.args)(v5246)))))))));
              v5259= 0;
              } 
            } 
          else PREVIOUS_HANDLER;} 
        else v5259= 0;
          v5246= _oid_(make_function_string(string_I_symbol(extract_symbol_any((*(OBJECT(bag,(*Core.args)(v5246))))[1]))));
        } 
      Result = list::alloc(3,v5259,
        v5246,
        v5264);
      } 
    GC_UNBIND; return (Result);} 
  } 

list * extract_signature_I_list(list *v5252)
{ GC_BIND;
  (Language.LDEF->value= _oid_(list::empty(Kernel._any)));
  { list *Result ;
    { int  v5254 = 0;
      list * v15405 = list::empty(Kernel._type);
      list * v15406;
      { { bag *v_list; OID v_val;
          OID v5263,CLcount;
          v_list = v5252;
           v15406 = v_list->clone(Kernel._any);
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v5263 = (*(v_list))[CLcount];
            { OID  v5256 = GC_OID(extract_pattern_any(GC_OID(_oid_(OBJECT(Variable,v5263)->range)),list::alloc(1,v5254)));
              ++v5254;
              { { OID  v8223;
                  { if (INHERIT(OBJECT(Variable,v5263)->range->isa,Core._global_variable))
                     v8223 = _oid_(OBJECT(Variable,v5263)->range);
                    else v8223 = v5256;
                      GC_OID(v8223);} 
                  v15405 = v15405->addFast(v8223);
                  } 
                GC_OBJECT(list,v15405);} 
              (OBJECT(Variable,v5263)->range = type_I_any(v5256));
              v_val = v5256;
              } 
            
            (*((list *) v15406))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v15406);} 
      Result = list::alloc(2,_oid_(v15405),_oid_(v15406));
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * _equalsig_ask_list(list *v5264,list *v5265)
{ return (((tmatch_ask_list(v5264,v5265) == CTRUE) ? ((tmatch_ask_list(v5265,v5264) == CTRUE) ? CTRUE: CFALSE): CFALSE));} 

char * function_name_property_Optimize(property *v5256,list *v5252,OID v5264)
{ GC_BIND;
  { char *Result ;
    if (INHERIT(OWNER(v5264),Kernel._function))
     Result = string_I_function(OBJECT(ClaireFunction,v5264));
    else { int  v5254 = 0;
        int  v5253 = 0;
        module * v15487 = v5256->name->module_I;
        ClaireClass * v5243 = class_I_type(OBJECT(ClaireType,(*(v5252))[1]));
        char * v5258 = GC_STRING(append_string(GC_STRING(append_string(string_I_symbol(v5256->name),"_")),string_I_symbol(v5243->name)));
        if ((Optimize.compiler->naming == 0) && 
            (v5256 != Core.main))
         v5258= GC_STRING(append_string(GC_STRING(append_string(string_I_symbol(v15487->name),"_")),v5258));
        { ITERATE(v5258);
          for (START(v5256->restrictions); NEXT(v5258);)
          { if (v5243 == domain_I_restriction(OBJECT(restriction,v5258)))
             ++v5254;
            if (_equalsig_ask_list(v5252,OBJECT(restriction,v5258)->domain) == CTRUE)
             v5253= v5254;
            } 
          } 
        v5258= GC_STRING(((v5254 <= 1) ?
          v5258 :
          append_string(v5258,GC_STRING(string_I_integer (v5253))) ));
        Result = (((stable_ask_relation(v5256) == CTRUE) || 
            (v5256 == Core.main)) ?
          v5258 :
          append_string(GC_STRING(append_string(v5258,"_")),string_I_symbol(ClEnv->module_I->name)) );
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  compile_lambda_string(char *v9268,lambda *v5252,OID v5253)
{ { OID Result = 0;
    { int  v5264 = Optimize.compiler->safety;
      lambda * v5265 = v5252;
      if (Kernel._method == OWNER(v5253))
       (Optimize.OPT->in_method = v5253);
      (Optimize.OPT->protection = CFALSE);
      (Optimize.OPT->allocation = CFALSE);
      if (Optimize.OPT->loop_index > 0)
       (Optimize.OPT->loop_index = 0);
      (Optimize.OPT->loop_gc = CFALSE);
      (Optimize.OPT->use_update = CFALSE);
      (Optimize.OPT->use_nth_equal = CFALSE);
      (Optimize.OPT->max_vars = 0);
      if (contain_ask_list(Optimize.OPT->unsure,v5253) == CTRUE)
       (Optimize.compiler->safety = 1);
      (*Optimize.make_c_function)(_oid_(v5252),
        _string_(v9268),
        v5253);
      (Optimize.OPT->in_method = CNULL);
      (Optimize.compiler->safety = v5264);
      Result = Kernel.ctrue;
      } 
    return (Result);} 
  } 

OID  c_code_Defarray_Optimize(Defarray *v9268)
{ GC_BIND;
  { OID Result = 0;
    { list * v5241 = GC_OBJECT(list,v9268->arg->args);
      OID  v13253 = get_symbol(extract_symbol_any((*(v5241))[1]));
      table * v13274;
      { ClaireObject *V_CC ;
        if (INHERIT(OWNER(v13253),Kernel._table))
         V_CC = OBJECT(table,v13253);
        else close_exception(((general_error *) (*Core._general_error)(_string_("[internal] the table ~S is unknown"),
            _oid_(list::alloc(1,(*(v5241))[1])))));
          v13274= (table *) V_CC;} 
      OID  v5259 = GC_OID((*Kernel.domain)(v13253));
      OID  v5245;
      { { list * v5252 = GC_OBJECT(list,cdr_list(v5241));
          OID  v5242 = GC_OID(lexical_build_any(GC_OID(v9268->body),v5252,0));
          { ClaireBoolean * g0442I;
            { OID  v11106;
              { ITERATE(v15763);
                v11106= _oid_(CFALSE);
                for (START(v5252); NEXT(v15763);)
                if (occurrence_any(v5242,OBJECT(Variable,v15763)) > 0)
                 { v11106 = Kernel.ctrue;
                  break;} 
                } 
              g0442I = boolean_I_any(v11106);
              } 
            
            if (g0442I == CTRUE) v5245 = _oid_(lambda_I_list(v5252,v5242));
              else v5245 = v9268->body;
            } 
          } 
        GC_OID(v5245);} 
      OID  v5244;
      { if (INHERIT(OWNER(v5245),Core._lambda))
         v5244 = CNULL;
        else v5244 = v9268->body;
          GC_OID(v5244);} 
      list * v1602;
      if (boolean_I_any(_oid_(OBJECT(ClaireRelation,v13253)->multivalued_ask)) == CTRUE)
       { OID v_bag;
        GC_ANY(v1602= list::empty(Kernel._any));
        { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.put);
            (v2072->args = list::alloc(3,_oid_(Kernel.multivalued_ask),
              _oid_(v13274),
              GC_OID(_oid_(OBJECT(ClaireRelation,v13253)->multivalued_ask))));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v_bag = _oid_(v2072);
            } 
          GC_OID(v_bag);} 
        ((list *) v1602)->addFast(v_bag);} 
      else v1602 = list::empty(Kernel._any);
        list * v1603;
      { OID v_bag;
        GC_ANY(v1603= list::empty(Kernel._any));
        { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.put);
            (v2072->args = list::alloc(3,_oid_(Kernel.range),
              _oid_(v13274),
              GC_OID((*Kernel.range)(v13253))));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v_bag = _oid_(v2072);
            } 
          GC_OID(v_bag);} 
        ((list *) v1603)->addFast(v_bag);
        { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.put);
            (v2072->args = list::alloc(3,_oid_(Kernel.params),
              _oid_(v13274),
              GC_OID((*Kernel.params)(v13253))));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v_bag = _oid_(v2072);
            } 
          GC_OID(v_bag);} 
        ((list *) v1603)->addFast(v_bag);
        { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.put);
            (v2072->args = list::alloc(3,_oid_(Kernel.domain),
              _oid_(v13274),
              v5259));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v_bag = _oid_(v2072);
            } 
          GC_OID(v_bag);} 
        ((list *) v1603)->addFast(v_bag);} 
      (OBJECT(Variable,(*(v5241))[2])->range = extract_type_any(GC_OID(_oid_(OBJECT(Variable,(*(v5241))[2])->range))));
      if (v5241->length == 2)
       { { { OID  v12067;
            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Kernel.put);
              { Call * v10564 = v2072; 
                list * v10565;
                { OID v_bag;
                  GC_ANY(v10565= list::empty(Kernel.emptySet));
                  ((list *) v10565)->addFast(_oid_(Kernel.graph));
                  ((list *) v10565)->addFast(_oid_(v13274));
                  if (INHERIT(OBJECT(ClaireObject,v5259)->isa,Core._Interval))
                   { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Core.make_copy_list);
                    (v2072->args = list::alloc(2,size_Interval(OBJECT(Interval,v5259)),v5244));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v_bag = _oid_(v2072);
                    } 
                  else { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Kernel.make_list);
                      (v2072->args = list::alloc(2,29,CNULL));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v_bag = _oid_(v2072);
                      } 
                    ((list *) v10565)->addFast(v_bag);} 
                (v10564->args = v10565);} 
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v12067 = _oid_(v2072);
              } 
            v1603 = v1603->addFast(v12067);
            } 
          GC_OBJECT(list,v1603);} 
        { { OID  v14950;
            if (INHERIT(OWNER(v5245),Core._lambda))
             { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
              store_object(v2072,
                2,
                Kernel._object,
                (*(v5241))[2],
                CFALSE);
              (v2072->set_arg = v5259);
              { Iteration * v10569 = v2072; 
                OID  v10570;
                { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Kernel.nth_equal);
                  (v2072->args = list::alloc(3,_oid_(v13274),
                    (*(v5241))[2],
                    GC_OID(OBJECT(lambda,v5245)->body)));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v10570 = _oid_(v2072);
                  } 
                (v10569->arg = v10570);} 
              add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
              v14950 = _oid_(v2072);
              } 
            else { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Kernel.put);
                (v2072->args = list::alloc(3,_oid_(Kernel.DEFAULT),
                  _oid_(v13274),
                  v5244));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v14950 = _oid_(v2072);
                } 
              v1603 = v1603->addFast(v14950);
            } 
          GC_OBJECT(list,v1603);} 
        } 
      else { ClaireType * v15623 = GC_OBJECT(ClaireType,extract_type_any(GC_OID(_oid_(OBJECT(Variable,(*(v5241))[3])->range))));
          (OBJECT(Variable,(*(v5241))[3])->range = v15623);
          { { OID  v5247;
              { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Kernel.put);
                { Call * v10591 = v2072; 
                  list * v10592;
                  { OID v_bag;
                    GC_ANY(v10592= list::empty(Kernel.emptySet));
                    ((list *) v10592)->addFast(_oid_(Kernel.graph));
                    ((list *) v10592)->addFast(_oid_(v13274));
                    { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v2072->selector = Core.make_copy_list);
                        { Call * v10593 = v2072; 
                          list * v10594;
                          { OID v_bag;
                            GC_ANY(v10594= list::empty(Kernel.emptySet));
                            ((list *) v10594)->addFast(OBJECT(table,v13253)->graph->length);
                            { if ((*Kernel.params)(v13253) == _oid_(Kernel._any))
                               v_bag = CNULL;
                              else v_bag = (*Kernel.DEFAULT)(v13253);
                                GC_OID(v_bag);} 
                            ((list *) v10594)->addFast(v_bag);} 
                          (v10593->args = v10594);} 
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                        v_bag = _oid_(v2072);
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v10592)->addFast(v_bag);} 
                  (v10591->args = v10592);} 
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v5247 = _oid_(v2072);
                } 
              v1603 = v1603->addFast(v5247);
              } 
            GC_OBJECT(list,v1603);} 
          { { OID  v10051;
              if (INHERIT(OWNER(v5245),Core._lambda))
               { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                store_object(v2072,
                  2,
                  Kernel._object,
                  (*(v5241))[2],
                  CFALSE);
                (v2072->set_arg = (*(OBJECT(bag,v5259)))[1]);
                { Iteration * v10596 = v2072; 
                  OID  v10597;
                  { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                    store_object(v2072,
                      2,
                      Kernel._object,
                      (*(v5241))[3],
                      CFALSE);
                    (v2072->set_arg = _oid_(v15623));
                    { Iteration * v10598 = v2072; 
                      OID  v10599;
                      { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v2072->selector = Kernel.nth_equal);
                        (v2072->args = list::alloc(4,_oid_(v13274),
                          (*(v5241))[2],
                          (*(v5241))[3],
                          GC_OID(OBJECT(lambda,v5245)->body)));
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                        v10599 = _oid_(v2072);
                        } 
                      (v10598->arg = v10599);} 
                    add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                    v10597 = _oid_(v2072);
                    } 
                  (v10596->arg = v10597);} 
                add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                v10051 = _oid_(v2072);
                } 
              else { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Kernel.put);
                  (v2072->args = list::alloc(3,_oid_(Kernel.DEFAULT),
                    _oid_(v13274),
                    v5244));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v10051 = _oid_(v2072);
                  } 
                v1603 = v1603->addFast(v10051);
              } 
            GC_OBJECT(list,v1603);} 
          } 
        GC_OBJECT(list,Optimize.OPT->objects)->addFast(v13253);
      (*Optimize.c_register)(v13253);
      { OID  v2269;
        { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
          { Do * v10622 = v2072; 
            list * v10623;
            { OID  v5152;
              { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Optimize.object_I);
                (v2072->args = list::alloc(2,GC_OID((*Kernel.name)(v13253)),_oid_(Kernel._table)));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v5152 = _oid_(v2072);
                } 
              v10623 = cons_any(v5152,GC_OBJECT(list,add_star_list(v1602,v1603)));
              } 
            (v10622->args = v10623);} 
          add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
          v2269 = _oid_(v2072);
          } 
        Result = (*Optimize.c_code)(v2269,
          _oid_(Kernel._any));
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

void  compute_if_write_inverse_relation2(ClaireRelation *v5226)
{ GC_BIND;
  { Variable * v5264;
    { { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
        (v2072->pname = symbol_I_string2("XX"));
        (v2072->range = v5226->domain);
        add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
        v5264 = v2072;
        } 
      GC_OBJECT(Variable,v5264);} 
    Variable * v5265;
    { { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
        (v2072->pname = symbol_I_string2("YY"));
        (v2072->range = ((multi_ask_any(_oid_(v5226)) == CTRUE) ?
          member_type(v5226->range) :
          v5226->range ));
        add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
        v5265 = v2072;
        } 
      GC_OBJECT(Variable,v5265);} 
    Variable * v5266;
    { { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
        (v2072->pname = symbol_I_string2("ZZ"));
        (v2072->range = v5226->range);
        add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
        v5266 = v2072;
        } 
      GC_OBJECT(Variable,v5266);} 
    list * v15405 = list::empty(Kernel._any);
    if (multi_ask_any(_oid_(v5226)) == CTRUE)
     { v15405= list::alloc(Kernel._any,1,GC_OID((INHERIT(v5226->isa,Kernel._property) ?  Produce_put_property2((property *) OBJECT(property,_oid_(v5226)),OBJECT(Variable,_oid_(v5264)),_oid_(v5265)) :   Produce_put_table2((table *) OBJECT(table,_oid_(v5226)),OBJECT(Variable,_oid_(v5264)),_oid_(v5265)))));
      if (((v5226->inverse == (NULL)) ? CTRUE : CFALSE) != CTRUE)
       v15405= GC_OBJECT(list,v15405->addFast(GC_OID((INHERIT(v5226->inverse->isa,Kernel._property) ?  Produce_put_property2((property *) OBJECT(property,_oid_(v5226->inverse)),OBJECT(Variable,_oid_(v5265)),_oid_(v5264)) :   Produce_put_table2((table *) OBJECT(table,_oid_(v5226->inverse)),OBJECT(Variable,_oid_(v5265)),_oid_(v5264))))));
      { ClaireRelation * v10625 = v5226; 
        OID  v10626;
        { lambda * v12254;{ OID  v8996;
            { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
              { If * v10629 = v2072; 
                OID  v10630;
                { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Core.NOT);
                  { Call * v10652 = v2072; 
                    list * v10653;
                    { OID v_bag;
                      GC_ANY(v10653= list::empty(Kernel.emptySet));
                      { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v2072->selector = Kernel._Z);
                          (v2072->args = list::alloc(2,_oid_(v5265),GC_OID(Produce_get_relation2(v5226,v5264))));
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                          v_bag = _oid_(v2072);
                          } 
                        GC_OID(v_bag);} 
                      ((list *) v10653)->addFast(v_bag);} 
                    (v10652->args = v10653);} 
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v10630 = _oid_(v2072);
                  } 
                (v10629->test = v10630);} 
              { If * v10654 = v2072; 
                OID  v10655;
                { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                  (v2072->args = v15405);
                  add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                  v10655 = _oid_(v2072);
                  } 
                (v10654->arg = v10655);} 
              add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
              (v2072->other = Kernel.cfalse);
              v8996 = _oid_(v2072);
              } 
            v12254 = lambda_I_list(list::alloc(2,_oid_(v5264),_oid_(v5265)),v8996);
            } 
          
          v10626=_oid_(v12254);} 
        (v10625->if_write = v10626);} 
      } 
    else { v15405= list::alloc(Kernel._any,1,GC_OID((INHERIT(v5226->isa,Kernel._property) ?  Produce_put_property2((property *) OBJECT(property,_oid_(v5226)),OBJECT(Variable,_oid_(v5264)),_oid_(v5265)) :   Produce_put_table2((table *) OBJECT(table,_oid_(v5226)),OBJECT(Variable,_oid_(v5264)),_oid_(v5265)))));
        if (((v5226->inverse == (NULL)) ? CTRUE : CFALSE) != CTRUE)
         { { { OID  v3136;
              { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                { If * v10658 = v2072; 
                  OID  v10659;
                  { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Core.known_ask);
                    (v2072->args = list::alloc(1,_oid_(v5266)));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v10659 = _oid_(v2072);
                    } 
                  (v10658->test = v10659);} 
                (v2072->arg = (INHERIT(v5226->inverse->isa,Kernel._property) ?  Produce_remove_property2((property *) OBJECT(property,_oid_(v5226->inverse)),OBJECT(Variable,_oid_(v5266)),_oid_(v5264)) :   Produce_remove_table2((table *) OBJECT(table,_oid_(v5226->inverse)),OBJECT(Variable,_oid_(v5266)),_oid_(v5264))));
                add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                (v2072->other = Kernel.cfalse);
                v3136 = _oid_(v2072);
                } 
              v15405 = v15405->addFast(v3136);
              } 
            GC_OBJECT(list,v15405);} 
          v15405= GC_OBJECT(list,v15405->addFast(GC_OID((INHERIT(v5226->inverse->isa,Kernel._property) ?  Produce_put_property2((property *) OBJECT(property,_oid_(v5226->inverse)),OBJECT(Variable,_oid_(v5265)),_oid_(v5264)) :   Produce_put_table2((table *) OBJECT(table,_oid_(v5226->inverse)),OBJECT(Variable,_oid_(v5265)),_oid_(v5264))))));
          } 
        { ClaireRelation * v10660 = v5226; 
          OID  v10661;
          { lambda * v12288;{ OID  v12699;
              { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
                (v2072->var = v5266);
                (v2072->value = Produce_get_relation2(v5226,v5264));
                { Let * v10684 = v2072; 
                  OID  v10685;
                  { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                    { If * v10686 = v2072; 
                      OID  v10688;
                      { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v2072->selector = Core._I_equal);
                        (v2072->args = list::alloc(2,_oid_(v5265),_oid_(v5266)));
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                        v10688 = _oid_(v2072);
                        } 
                      (v10686->test = v10688);} 
                    { If * v10689 = v2072; 
                      OID  v10690;
                      { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                        (v2072->args = v15405);
                        add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                        v10690 = _oid_(v2072);
                        } 
                      (v10689->arg = v10690);} 
                    add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                    (v2072->other = Kernel.cfalse);
                    v10685 = _oid_(v2072);
                    } 
                  (v10684->arg = v10685);} 
                add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
                v12699 = _oid_(v2072);
                } 
              v12288 = lambda_I_list(list::alloc(2,_oid_(v5264),_oid_(v5265)),v12699);
              } 
            
            v10661=_oid_(v12288);} 
          (v10660->if_write = v10661);} 
        } 
      { char * v8882 = GC_STRING(append_string(string_I_symbol(v5226->name),"_write"));
      compile_lambda_string(v8882,GC_OBJECT(lambda,OBJECT(lambda,v5226->if_write)),_oid_(Kernel._void));
      } 
    } 
  GC_UNBIND;} 

OID  compute_set_write_relation2(ClaireRelation *v5226)
{ GC_BIND;
  { OID Result = 0;
    { Variable * v5264;
      { { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
          (v2072->pname = symbol_I_string2("XX"));
          (v2072->range = v5226->domain);
          add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
          v5264 = v2072;
          } 
        GC_OBJECT(Variable,v5264);} 
      Variable * v5265;
      { { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
          (v2072->pname = symbol_I_string2("YY"));
          (v2072->range = Kernel._bag);
          add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
          v5265 = v2072;
          } 
        GC_OBJECT(Variable,v5265);} 
      Variable * v5266;
      { { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
          (v2072->pname = symbol_I_string2("ZZ"));
          (v2072->range = member_type(v5226->range));
          add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
          v5266 = v2072;
          } 
        GC_OBJECT(Variable,v5266);} 
      list * v15405 = list::empty(Kernel._any);
      tformat_string("compute set_write for ~S \n",0,list::alloc(1,_oid_(v5226)));
      if (((v5226->inverse == (NULL)) ? CTRUE : CFALSE) != CTRUE)
       { { OID  v3042;
          { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
            (v2072->var = v5266);
            (v2072->set_arg = Produce_get_relation2(v5226,v5264));
            (v2072->arg = (INHERIT(v5226->inverse->isa,Kernel._property) ?  Produce_remove_property2((property *) OBJECT(property,_oid_(v5226->inverse)),OBJECT(Variable,_oid_(v5266)),_oid_(v5264)) :   Produce_remove_table2((table *) OBJECT(table,_oid_(v5226->inverse)),OBJECT(Variable,_oid_(v5266)),_oid_(v5264))));
            add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
            v3042 = _oid_(v2072);
            } 
          v15405 = v15405->addFast(v3042);
          } 
        GC_OBJECT(list,v15405);} 
      v15405= GC_OBJECT(list,v15405->addFast(GC_OID(Produce_erase_property2(((property *) v5226),v5264))));
      { { OID  v4004;
          { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
            (v2072->var = v5266);
            (v2072->set_arg = _oid_(v5265));
            (v2072->arg = (INHERIT(v5226->isa,Kernel._property) ?  Produce_put_property2((property *) OBJECT(property,_oid_(v5226)),OBJECT(Variable,_oid_(v5264)),_oid_(v5266)) :   Produce_put_table2((table *) OBJECT(table,_oid_(v5226)),OBJECT(Variable,_oid_(v5264)),_oid_(v5266))));
            add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
            v4004 = _oid_(v2072);
            } 
          v15405 = v15405->addFast(v4004);
          } 
        GC_OBJECT(list,v15405);} 
      { char * v8882 = GC_STRING(append_string(string_I_symbol(v5226->name),"_set_write"));
        { lambda * v4964;
          { { OID  v9733;
              { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                (v2072->args = v15405);
                add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                v9733 = _oid_(v2072);
                } 
              v4964 = lambda_I_list(list::alloc(2,_oid_(v5264),_oid_(v5265)),v9733);
              } 
            GC_OBJECT(lambda,v4964);} 
          Result = compile_lambda_string(v8882,v4964,_oid_(Kernel._void));
          } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Produce_put_property2(property *v5258,Variable *v5264,OID v5265)
{ GC_BIND;
  { OID Result = 0;
    { list * v5252 = list::empty(Kernel._any);
      { OID gc_local;
        ITERATE(v15843);
        for (START(v5258->restrictions); NEXT(v15843);)
        { GC_LOOP;
          if ((Kernel._slot == OBJECT(ClaireObject,v15843)->isa) && 
              (boolean_I_any(_oid_(_exp_type(GC_OBJECT(ClaireType,ptype_type(v5264->range)),domain_I_restriction(OBJECT(restriction,v15843))))) == CTRUE))
           { list * v10696;
            { { OID v_bag;
                GC_ANY(v10696= list::empty(Kernel.emptySet));
                ((list *) v10696)->addFast(_oid_(domain_I_restriction(OBJECT(restriction,v15843))));
                if (boolean_I_any(_oid_(v5258->multivalued_ask)) == CTRUE)
                 { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Kernel.add_I);
                  { Call * v10716 = v2072; 
                    list * v10717;
                    { OID v_bag;
                      GC_ANY(v10717= list::empty(Kernel.emptySet));
                      { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v2072->selector = v5258);
                          { Call * v10718 = v2072; 
                            list * v10719;
                            { OID v_bag;
                              GC_ANY(v10719= list::empty(Kernel.emptySet));
                              { { Cast * v2072 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                                  (v2072->arg = _oid_(v5264));
                                  (v2072->set_arg = domain_I_restriction(OBJECT(restriction,v15843)));
                                  add_I_property(Kernel.instances,Language._Cast,11,_oid_(v2072));
                                  v_bag = _oid_(v2072);
                                  } 
                                GC_OID(v_bag);} 
                              ((list *) v10719)->addFast(v_bag);} 
                            (v10718->args = v10719);} 
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                          v_bag = _oid_(v2072);
                          } 
                        GC_OID(v_bag);} 
                      ((list *) v10717)->addFast(v_bag);
                      ((list *) v10717)->addFast(v5265);} 
                    (v10716->args = v10717);} 
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v_bag = _oid_(v2072);
                  } 
                else { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Kernel.put);
                    { Call * v10720 = v2072; 
                      list * v10721;
                      { OID v_bag;
                        GC_ANY(v10721= list::empty(Kernel.emptySet));
                        ((list *) v10721)->addFast(_oid_(v5258));
                        { { Cast * v2072 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                            (v2072->arg = _oid_(v5264));
                            (v2072->set_arg = domain_I_restriction(OBJECT(restriction,v15843)));
                            add_I_property(Kernel.instances,Language._Cast,11,_oid_(v2072));
                            v_bag = _oid_(v2072);
                            } 
                          GC_OID(v_bag);} 
                        ((list *) v10721)->addFast(v_bag);
                        ((list *) v10721)->addFast(v5265);} 
                      (v10720->args = v10721);} 
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v_bag = _oid_(v2072);
                    } 
                  ((list *) v10696)->addFast(v_bag);} 
              GC_OBJECT(list,v10696);} 
            v5252 = add_star_list(v5252,v10696);
            } 
          GC_UNLOOP;} 
        } 
      if (v5252->length == 2)
       Result = (*(v5252))[2];
      else { Case * v2072 = ((Case *) GC_OBJECT(Case,new_object_class(Language._Case)));
          (v2072->var = _oid_(v5264));
          (v2072->args = v5252);
          add_I_property(Kernel.instances,Language._Case,11,_oid_(v2072));
          Result = _oid_(v2072);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  Produce_erase_property2(property *v5258,Variable *v5264)
{ GC_BIND;
  { OID Result = 0;
    { list * v5252 = list::empty(Kernel._any);
      bag * v13625;
      if (v5258->multivalued_ask == Kernel._list)
       v13625 = list::empty(Kernel._any);
      else v13625 = set::empty(Kernel._any);
        cast_I_bag(v13625,member_type(v5258->range));
      { OID gc_local;
        ITERATE(v15843);
        for (START(v5258->restrictions); NEXT(v15843);)
        { GC_LOOP;
          if ((Kernel._slot == OBJECT(ClaireObject,v15843)->isa) && 
              (boolean_I_any(_oid_(_exp_type(GC_OBJECT(ClaireType,ptype_type(v5264->range)),domain_I_restriction(OBJECT(restriction,v15843))))) == CTRUE))
           { list * v1026;
            { { OID v_bag;
                GC_ANY(v1026= list::empty(Kernel.emptySet));
                ((list *) v1026)->addFast(_oid_(domain_I_restriction(OBJECT(restriction,v15843))));
                { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Kernel.put);
                    { Call * v10723 = v2072; 
                      list * v11396;
                      { OID v_bag;
                        GC_ANY(v11396= list::empty(Kernel.emptySet));
                        ((list *) v11396)->addFast(_oid_(v5258));
                        { { Cast * v2072 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                            (v2072->arg = _oid_(v5264));
                            (v2072->set_arg = domain_I_restriction(OBJECT(restriction,v15843)));
                            add_I_property(Kernel.instances,Language._Cast,11,_oid_(v2072));
                            v_bag = _oid_(v2072);
                            } 
                          GC_OID(v_bag);} 
                        ((list *) v11396)->addFast(v_bag);
                        { if (boolean_I_any(_oid_(v5258->multivalued_ask)) == CTRUE)
                           v_bag = _oid_(v13625);
                          else v_bag = OBJECT(slot,v15843)->DEFAULT;
                            GC_OID(v_bag);} 
                        ((list *) v11396)->addFast(v_bag);} 
                      (v10723->args = v11396);} 
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v_bag = _oid_(v2072);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v1026)->addFast(v_bag);} 
              GC_OBJECT(list,v1026);} 
            v5252 = add_star_list(v5252,v1026);
            } 
          GC_UNLOOP;} 
        } 
      if (v5252->length == 2)
       Result = (*(v5252))[2];
      else { Case * v2072 = ((Case *) GC_OBJECT(Case,new_object_class(Language._Case)));
          (v2072->var = _oid_(v5264));
          (v2072->args = v5252);
          add_I_property(Kernel.instances,Language._Case,11,_oid_(v2072));
          Result = _oid_(v2072);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  Produce_put_table2(table *v5258,Variable *v5264,OID v5265)
{ GC_BIND;
  { OID Result = 0;
    { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v2072->selector = Kernel.put);
      { Call * v11397 = v2072; 
        list * v11398;
        { OID v_bag;
          GC_ANY(v11398= list::empty(Kernel.emptySet));
          ((list *) v11398)->addFast(_oid_(v5258));
          ((list *) v11398)->addFast(_oid_(v5264));
          if (boolean_I_any(_oid_(v5258->multivalued_ask)) == CTRUE)
           { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.add);
            (v2072->args = list::alloc(2,_oid_(list::alloc(2,_oid_(Kernel.nth),_oid_(list::alloc(2,_oid_(v5258),_oid_(v5264))))),v5265));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v_bag = _oid_(v2072);
            } 
          else v_bag = v5265;
            ((list *) v11398)->addFast(v_bag);} 
        (v11397->args = v11398);} 
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Produce_get_relation2(ClaireRelation *v5258,Variable *v5264)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(v5258->isa,Kernel._table))
     { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v2072->selector = Kernel.nth);
      (v2072->args = list::alloc(2,_oid_(v5258),_oid_(v5264)));
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    else if (INHERIT(v5258->isa,Kernel._property))
     { list * v5252 = list::empty(Kernel._any);
      { OID gc_local;
        ITERATE(v15843);
        for (START(CLREAD(property,v5258,restrictions)); NEXT(v15843);)
        { GC_LOOP;
          if ((Kernel._slot == OBJECT(ClaireObject,v15843)->isa) && 
              (boolean_I_any(_oid_(_exp_type(GC_OBJECT(ClaireType,ptype_type(v5264->range)),domain_I_restriction(OBJECT(restriction,v15843))))) == CTRUE))
           { list * v12647;
            { { OID v_bag;
                GC_ANY(v12647= list::empty(Kernel.emptySet));
                ((list *) v12647)->addFast(_oid_(domain_I_restriction(OBJECT(restriction,v15843))));
                { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = ((property *) v5258));
                    { Call * v11400 = v2072; 
                      list * v11401;
                      { OID v_bag;
                        GC_ANY(v11401= list::empty(Kernel.emptySet));
                        { { Cast * v2072 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                            (v2072->arg = _oid_(v5264));
                            (v2072->set_arg = domain_I_restriction(OBJECT(restriction,v15843)));
                            add_I_property(Kernel.instances,Language._Cast,11,_oid_(v2072));
                            v_bag = _oid_(v2072);
                            } 
                          GC_OID(v_bag);} 
                        ((list *) v11401)->addFast(v_bag);} 
                      (v11400->args = v11401);} 
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v_bag = _oid_(v2072);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v12647)->addFast(v_bag);} 
              GC_OBJECT(list,v12647);} 
            v5252 = add_star_list(v5252,v12647);
            } 
          GC_UNLOOP;} 
        } 
      if (v5252->length == 2)
       Result = (*(v5252))[2];
      else { Case * v2072 = ((Case *) GC_OBJECT(Case,new_object_class(Language._Case)));
          (v2072->var = _oid_(v5264));
          (v2072->args = v5252);
          add_I_property(Kernel.instances,Language._Case,11,_oid_(v2072));
          Result = _oid_(v2072);
          } 
        } 
    else Result = Kernel.cfalse;
      GC_UNBIND; return (Result);} 
  } 

OID  Produce_remove_property2(property *v5258,Variable *v5264,OID v5265)
{ GC_BIND;
  { OID Result = 0;
    { list * v5252 = list::empty(Kernel._any);
      { OID gc_local;
        ITERATE(v15843);
        for (START(v5258->restrictions); NEXT(v15843);)
        { GC_LOOP;
          if (Kernel._slot == OBJECT(ClaireObject,v15843)->isa)
           { list * v15530;
            { { OID v_bag;
                GC_ANY(v15530= list::empty(Kernel.emptySet));
                ((list *) v15530)->addFast(_oid_(domain_I_restriction(OBJECT(restriction,v15843))));
                if (boolean_I_any(_oid_(v5258->multivalued_ask)) == CTRUE)
                 { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Kernel._delete);
                  { Call * v11403 = v2072; 
                    list * v11404;
                    { OID v_bag;
                      GC_ANY(v11404= list::empty(Kernel.emptySet));
                      { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v2072->selector = v5258);
                          (v2072->args = list::alloc(1,_oid_(v5264)));
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                          v_bag = _oid_(v2072);
                          } 
                        GC_OID(v_bag);} 
                      ((list *) v11404)->addFast(v_bag);
                      ((list *) v11404)->addFast(v5265);} 
                    (v11403->args = v11404);} 
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v_bag = _oid_(v2072);
                  } 
                else { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Kernel.put);
                    (v2072->args = list::alloc(3,_oid_(v5258),
                      _oid_(v5264),
                      CNULL));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v_bag = _oid_(v2072);
                    } 
                  ((list *) v15530)->addFast(v_bag);} 
              GC_OBJECT(list,v15530);} 
            v5252 = add_star_list(v5252,v15530);
            } 
          GC_UNLOOP;} 
        } 
      if (v5252->length == 2)
       Result = (*(v5252))[2];
      else { Case * v2072 = ((Case *) GC_OBJECT(Case,new_object_class(Language._Case)));
          (v2072->var = _oid_(v5264));
          (v2072->args = v5252);
          add_I_property(Kernel.instances,Language._Case,11,_oid_(v2072));
          Result = _oid_(v2072);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  Produce_remove_table2(table *v5258,Variable *v5264,OID v5265)
{ GC_BIND;
  { OID Result = 0;
    { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v2072->selector = Kernel.put);
      { Call * v11405 = v2072; 
        list * v11427;
        { OID v_bag;
          GC_ANY(v11427= list::empty(Kernel.emptySet));
          ((list *) v11427)->addFast(_oid_(v5258));
          ((list *) v11427)->addFast(_oid_(v5264));
          if (boolean_I_any(_oid_(v5258->multivalued_ask)) == CTRUE)
           { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel._delete);
            (v2072->args = list::alloc(2,_oid_(list::alloc(2,_oid_(Kernel.nth),_oid_(list::alloc(2,_oid_(v5258),_oid_(v5264))))),v5265));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v_bag = _oid_(v2072);
            } 
          else v_bag = CNULL;
            ((list *) v11427)->addFast(v_bag);} 
        (v11405->args = v11427);} 
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

void  Tighten_relation2(ClaireRelation *v5258)
{ GC_RESERVE(6);  // v3.0.55 optim !
  if (INHERIT(v5258->isa,Kernel._property))
   { ClaireType * v15115 = set::empty();
    ClaireType * v15129 = set::empty();
    { OID gc_local;
      ITERATE(v5259);
      for (START(CLREAD(property,v5258,restrictions)); NEXT(v5259);)
      { GC_LOOP;
        if (Kernel._slot == OBJECT(ClaireObject,v5259)->isa)
         { GC__ANY(v15115 = U_type(v15115,domain_I_restriction(OBJECT(restriction,v5259))), 3);
          GC__ANY(v15129 = U_type(v15129,GC_OBJECT(ClaireType,((multi_ask_any(_oid_(v5258)) == CTRUE) ?
            member_type(OBJECT(restriction,v5259)->range) :
            OBJECT(restriction,v5259)->range ))), 4);
          } 
        GC_UNLOOP;} 
      } 
    (v5258->open = 1);
    (v5258->domain = class_I_type(v15115));
    (v5258->range = ((v5258->multivalued_ask == Kernel._list) ?
      param_I_class(Kernel._list,class_I_type(v15129)) :
      ((v5258->multivalued_ask == Kernel._set) ?
        param_I_class(Kernel._set,class_I_type(v15129)) :
        v15129 ) ));
    ;} 
  GC_UNBIND;} 

void  lexical_num_any2(OID v9268,int v5254)
{ GC_BIND;
  if (INHERIT(OWNER(v9268),Language._Call))
   lexical_num_any2(GC_OID(_oid_(OBJECT(Call,v9268)->args)),v5254);
  else if (INHERIT(OWNER(v9268),Language._Instruction))
   { ClaireClass * v15607 = OBJECT(ClaireObject,v9268)->isa;
    if (contain_ask_set(Language._Instruction_with_var->descendents,_oid_(v15607)) == CTRUE)
     { put_property2(Kernel.index,GC_OBJECT(ClaireObject,OBJECT(ClaireObject,(*Language.var)(v9268))),v5254);
      ++v5254;
      if (v5254 > Language._starvariable_index_star->value)
       (Language._starvariable_index_star->value= v5254);
      } 
    { ITERATE(v5259);
      for (START(v15607->slots); NEXT(v5259);)
      lexical_num_any2(get_slot(OBJECT(slot,v5259),OBJECT(ClaireObject,v9268)),v5254);
      } 
    } 
  else if (INHERIT(OWNER(v9268),Kernel._bag))
   { ITERATE(v5264);
    for (START(OBJECT(bag,v9268)); NEXT(v5264);)
    lexical_num_any2(v5264,v5254);
    } 
  else ;GC_UNBIND;} 

ClaireType * c_type_Defrule2_Optimize(Defrule *v9268)
{ return (Kernel._any);} 

OID  c_code_Defrule_Optimize(Defrule *v9268,ClaireClass *v5259)
{ GC_RESERVE(11);  // v3.0.55 optim !
  { OID Result = 0;
    { OID  v15659 = get_symbol(v9268->ident);
      list * v5252 = list::empty(Kernel._any);
      tformat_string("compile a rule ~S \n",0,list::alloc(1,v15659));
      { OID gc_local;
        ITERATE(v5258);
        bag *v5258_support;
        v5258_support = OBJECT(bag,nth_table1(Language.relations,v15659));
        for (START(v5258_support); NEXT(v5258);)
        if (eventMethod_ask_relation2(OBJECT(ClaireRelation,v5258)) != CTRUE)
         Tighten_relation2(OBJECT(ClaireRelation,v5258));
        } 
      { OID gc_local;
        ITERATE(v5258);
        bag *v5258_support;
        v5258_support = OBJECT(bag,nth_table1(Language.relations,v15659));
        for (START(v5258_support); NEXT(v5258);)
        { GC_LOOP;
          { if ((*Kernel.open)(v5258) < 2)
             { { OID  v7748;
                { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Kernel.FINAL);
                  (v2072->args = list::alloc(1,v5258));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v7748 = _oid_(v2072);
                  } 
                v5252 = v5252->addFast(v7748);
                } 
               GC__ANY(v5252, 5);} 
            compile_if_write_relation(OBJECT(ClaireRelation,v5258));
            { OID  v8882 = GC_OID((*Kernel._7_plus)(GC_OID((*Kernel.name)(v5258)),
                _string_("_write")));
              char * v5259 = string_I_symbol(OBJECT(symbol,v8882));
              OID  v15454 = GC_OID((*Kernel.if_write)(v5258));
              compile_lambda_string(v5259,OBJECT(lambda,v15454),_oid_(Kernel._void));
              { OID  v8710;
                { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Kernel.put);
                  (v2072->args = list::alloc(3,Optimize.if_write->value,
                    v5258,
                    _oid_(make_function_string(v5259))));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v8710 = _oid_(v2072);
                  } 
                v5252->addFast(v8710);
                } 
              } 
            } 
          GC_UNLOOP;} 
        } 
      { OID gc_local;
        ITERATE(v5258);
        bag *v5258_support;
        v5258_support = OBJECT(bag,nth_table1(Language.relations,v15659));
        for (START(v5258_support); NEXT(v5258);)
        { GC_LOOP;
          if (eventMethod_ask_relation2(OBJECT(ClaireRelation,v5258)) == CTRUE)
           v5252= v5252->addFast(GC_OID(compileEventMethod_property(OBJECT(property,v5258))));
          GC_UNLOOP;} 
        } 
      { OID  v9671;
        { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
          (v2072->args = v5252);
          add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
          v9671 = _oid_(v2072);
          } 
        Result = (*Optimize.c_code)(v9671,
          _oid_(v5259));
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

void  compile_if_write_relation(ClaireRelation *v5226)
{ GC_BIND;
  { OID  v5252 = nth_table1(Language.demons,_oid_(v5226));
    list * v13347 = GC_OBJECT(list,OBJECT(Language_demon,(*(OBJECT(bag,v5252)))[1])->formula->vars);
    list * v15405 = list::alloc(Kernel._any,1,GC_OID((*Optimize.Produce_put)(_oid_(v5226),
      (*(v13347))[1],
      (*(v13347))[2])));
    list * v15406;
    { { bag *v_list; OID v_val;
        OID v5264,CLcount;
        v_list = OBJECT(bag,v5252);
         v15406 = v_list->clone(Kernel._any);
        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
        { v5264 = (*(v_list))[CLcount];
          v_val = substitution_any(GC_OID(substitution_any(GC_OID(substitution_any(GC_OID(OBJECT(Language_demon,v5264)->formula->body),GC_OBJECT(Variable,OBJECT(Variable,(*(OBJECT(Language_demon,v5264)->formula->vars))[3])),(*(v13347))[3])),GC_OBJECT(Variable,OBJECT(Variable,(*(OBJECT(Language_demon,v5264)->formula->vars))[1])),(*(v13347))[1])),GC_OBJECT(Variable,OBJECT(Variable,(*(OBJECT(Language_demon,v5264)->formula->vars))[2])),(*(v13347))[2]);
          
          (*((list *) v15406))[CLcount] = v_val;} 
        } 
      GC_OBJECT(list,v15406);} 
    put_property2(Kernel.range,OBJECT(ClaireObject,(*(v13347))[1]),_oid_(v5226->domain));
    put_property2(Kernel.range,OBJECT(ClaireObject,(*(v13347))[2]),_oid_(v5226->range));
    { OID gc_local;
      ITERATE(v5263);
      for (START(v13347); NEXT(v5263);)
      { GC_LOOP;
        put_property2(Kernel.range,OBJECT(ClaireObject,v5263),_oid_(class_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.range)(v5263))))));
        GC_UNLOOP;} 
      } 
    if ((INHERIT(OWNER((*(v15406))[1]),Language._If)) && 
        (eventMethod_ask_relation2(v5226) != CTRUE))
     { if (INHERIT(OWNER(OBJECT(If,(*(v15406))[1])->test),Language._And))
       { If * v11431 = OBJECT(If,(*(v15406))[1]); 
        OID  v11432;
        { And * v2072 = ((And *) GC_OBJECT(And,new_object_class(Language._And)));
          (v2072->args = cdr_list(GC_OBJECT(list,OBJECT(list,(*Core.args)(GC_OID(OBJECT(If,(*(v15406))[1])->test))))));
          add_I_property(Kernel.instances,Language._And,11,_oid_(v2072));
          v11432 = _oid_(v2072);
          } 
        (v11431->test = v11432);} 
      else ((*(v15406))[1]=OBJECT(If,(*(v15406))[1])->arg);
        } 
    if (((v5226->inverse == (NULL)) ? CTRUE : CFALSE) != CTRUE)
     { if (multi_ask_any(_oid_(v5226)) != CTRUE)
       v15405= v15405->addFast(GC_OID((*Optimize.Produce_remove)(_oid_(v5226->inverse),
        (*(v13347))[3],
        (*(v13347))[1])));
      v15405= v15405->addFast(GC_OID((*Optimize.Produce_put)(_oid_(v5226->inverse),
        (*(v13347))[2],
        (*(v13347))[1])));
      } 
    { ClaireRelation * v11433 = v5226; 
      OID  v11434;
      { lambda * v13062;{ OID  v15438;
          if (eventMethod_ask_relation2(v5226) == CTRUE)
           { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
            (v2072->args = v15406);
            add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
            v15438 = _oid_(v2072);
            } 
          else if (multi_ask_any(_oid_(v5226)) == CTRUE)
           { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
            { If * v11458 = v2072; 
              OID  v11459;
              { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Core.NOT);
                { Call * v11460 = v2072; 
                  list * v11461;
                  { OID v_bag;
                    GC_ANY(v11461= list::empty(Kernel.emptySet));
                    { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v2072->selector = Kernel._Z);
                        (v2072->args = list::alloc(2,(*(v13347))[2],GC_OID(_oid_(readCall_relation(v5226,(*(v13347))[1])))));
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                        v_bag = _oid_(v2072);
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v11461)->addFast(v_bag);} 
                  (v11460->args = v11461);} 
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v11459 = _oid_(v2072);
                } 
              (v11458->test = v11459);} 
            { If * v11462 = v2072; 
              OID  v11463;
              { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                (v2072->args = append_list(v15405,v15406));
                add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                v11463 = _oid_(v2072);
                } 
              (v11462->arg = v11463);} 
            add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
            (v2072->other = Kernel.cfalse);
            v15438 = _oid_(v2072);
            } 
          else { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
              store_object(v2072,
                2,
                Kernel._object,
                (*(v13347))[3],
                CFALSE);
              (v2072->value = _oid_(readCall_relation(v5226,(*(v13347))[1])));
              { Let * v11464 = v2072; 
                OID  v11465;
                { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                  { If * v11466 = v2072; 
                    OID  v11467;
                    { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Core._I_equal);
                      (v2072->args = list::alloc(2,(*(v13347))[2],(*(v13347))[3]));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v11467 = _oid_(v2072);
                      } 
                    (v11466->test = v11467);} 
                  { If * v11489 = v2072; 
                    OID  v11490;
                    { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                      (v2072->args = append_list(v15405,v15406));
                      add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                      v11490 = _oid_(v2072);
                      } 
                    (v11489->arg = v11490);} 
                  add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                  (v2072->other = Kernel.cfalse);
                  v11465 = _oid_(v2072);
                  } 
                (v11464->arg = v11465);} 
              add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
              v15438 = _oid_(v2072);
              } 
            v13062 = lambda_I_list(GC_OBJECT(list,list::alloc(2,(*(v13347))[1],(*(v13347))[2])),v15438);
          } 
        
        v11434=_oid_(v13062);} 
      (v11433->if_write = v11434);} 
    } 
  GC_UNBIND;} 

OID  compileEventMethod_property(property *v5256)
{ GC_BIND;
  { OID Result = 0;
    { method * v5253 = OBJECT(method,(*(v5256->restrictions))[1]);
      char * v15515 = GC_STRING(append_string(string_I_symbol(v5256->name),"_write"));
      Result = add_method_I_method(v5253,
        list::alloc(2,_oid_(v5256->domain),_oid_(v5256->range)),
        _oid_(Kernel._void),
        0,
        make_function_string(v15515));
      } 
    GC_UNBIND; return (Result);} 
  } 

