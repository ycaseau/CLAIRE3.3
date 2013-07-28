/***** CLAIRE Compilation of file c:\claire\v3.3\src\compile\odefine.cl 
         [version 3.3.46 / safety 5] Sun Feb 15 15:37:26 2009 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
ClaireType * c_type_List_Optimize(List *v2164)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  ;{ ClaireType *Result ;
    if (((v2164->of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
     Result = param_I_class(Kernel._list,v2164->of);
    else { OID  v899 = _oid_(Kernel.emptySet);
        { OID gc_local;
          ITERATE(v10267);
          for (START(v2164->args); NEXT(v10267);)
          { GC_LOOP;
            if (boolean_I_any(v899) == CTRUE)
             GC__OID(v899 = _oid_(meet_class(OBJECT(ClaireClass,v899),class_I_type(GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v10267))))))), 1);
            else GC__OID(v899 = _oid_(class_I_type(GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v10267)))))), 1);
              GC_UNLOOP;} 
          } 
        Result = nth_class1(Kernel._list,OBJECT(ClaireType,v899));
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  c_code_List_Optimize(List *v2164)
{ GC_BIND;
  (Optimize.OPT->allocation = CTRUE);
  { OID Result = 0;
    { List * v6224;
      { { List * v2072 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
          { Construct * v9477 = v2072; 
            list * v9478;
            { bag *v_list; OID v_val;
              OID v10267,CLcount;
              v_list = GC_OBJECT(list,v2164->args);
               v9478 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v10267 = (*(v_list))[CLcount];
                v_val = c_gc_I_any2(GC_OID((*Optimize.c_code)(v10267,
                  _oid_(Kernel._any))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v10267))));
                
                (*((list *) v9478))[CLcount] = v_val;} 
              } 
            (v9477->args = v9478);} 
          add_I_property(Kernel.instances,Language._List,11,_oid_(v2072));
          v6224 = v2072;
          } 
        GC_OBJECT(List,v6224);} 
      if (((v2164->of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
       { { ClaireBoolean * g0305I;
          { ClaireBoolean *v_or;
            { v_or = ((Optimize.compiler->safety > 4) ? CTRUE : CFALSE);
              if (v_or == CTRUE) g0305I =CTRUE; 
              else { v_or = ((equal(_oid_(v2164->of),_oid_(Kernel.emptySet)) == CTRUE) ? CTRUE : CFALSE);
                if (v_or == CTRUE) g0305I =CTRUE; 
                else { { OID  v3497;
                    { OID gc_local;
                      ITERATE(v10267);
                      v3497= Kernel.cfalse;
                      bag *v10267_support;
                      v10267_support = GC_OBJECT(list,v2164->args);
                      for (START(v10267_support); NEXT(v10267);)
                      { GC_LOOP;
                        if (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v10267))),GC_OBJECT(ClaireType,v2164->of)) != CTRUE)
                         { v3497 = Kernel.ctrue;
                          break;} 
                        GC_UNLOOP;} 
                      } 
                    v_or = not_any(v3497);
                    } 
                  if (v_or == CTRUE) g0305I =CTRUE; 
                  else g0305I = CFALSE;} 
                } 
              } 
            } 
          
          if (g0305I == CTRUE) { (v6224->of = v2164->of);
              Result = _oid_(v6224);
              } 
            else { warn_void();
            { list * v4457;
              { { OID v_bag;
                  GC_ANY(v4457= list::empty(Kernel.emptySet));
                  { { list * v11109;{ bag *v_list; OID v_val;
                        OID v10267,CLcount;
                        v_list = GC_OBJECT(list,v2164->args);
                         v11109 = v_list->clone();
                        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                        { v10267 = (*(v_list))[CLcount];
                          v_val = (*Optimize.c_type)(v10267);
                          
                          (*((list *) v11109))[CLcount] = v_val;} 
                        } 
                      
                      v_bag=_oid_(v11109);} 
                    GC_OID(v_bag);} 
                  ((list *) v4457)->addFast(v_bag);
                  ((list *) v4457)->addFast(GC_OID(_oid_(v2164->of)));} 
                GC_OBJECT(list,v4457);} 
              tformat_string(copy_string("unsafe typed list: ~S not in ~S [262]\n"),2,v4457);
              } 
            { OID  v6379;
              { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Core.check_in);
                (v2072->args = list::alloc(3,_oid_(v6224),
                  _oid_(Kernel._list),
                  GC_OID(_oid_(v2164->of))));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v6379 = _oid_(v2072);
                } 
              Result = (*Optimize.c_code)(v6379,
                _oid_(Kernel._list));
              } 
            } 
          } 
        } 
      else Result = _oid_(v6224);
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Set_Optimize(Set *v2164)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  ;{ ClaireType *Result ;
    if (((v2164->of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
     Result = param_I_class(Kernel._set,v2164->of);
    else { OID  v899 = _oid_(Kernel.emptySet);
        { OID gc_local;
          ITERATE(v10267);
          for (START(v2164->args); NEXT(v10267);)
          { GC_LOOP;
            if (boolean_I_any(v899) == CTRUE)
             GC__OID(v899 = _oid_(meet_class(OBJECT(ClaireClass,v899),class_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v10267)))))), 1);
            else GC__OID(v899 = _oid_(class_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v10267))))), 1);
              GC_UNLOOP;} 
          } 
        Result = nth_class1(Kernel._set,OBJECT(ClaireType,v899));
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  c_code_Set_Optimize(Set *v2164)
{ GC_BIND;
  (Optimize.OPT->allocation = CTRUE);
  { OID Result = 0;
    { Set * v6224;
      { { Set * v2072 = ((Set *) GC_OBJECT(Set,new_object_class(Language._Set)));
          { Construct * v9505 = v2072; 
            list * v9506;
            { bag *v_list; OID v_val;
              OID v10267,CLcount;
              v_list = GC_OBJECT(list,v2164->args);
               v9506 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v10267 = (*(v_list))[CLcount];
                v_val = c_gc_I_any2(GC_OID((*Optimize.c_code)(v10267,
                  _oid_(Kernel._any))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v10267))));
                
                (*((list *) v9506))[CLcount] = v_val;} 
              } 
            (v9505->args = v9506);} 
          add_I_property(Kernel.instances,Language._Set,11,_oid_(v2072));
          v6224 = v2072;
          } 
        GC_OBJECT(Set,v6224);} 
      if (((v2164->of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
       { { ClaireBoolean * g0312I;
          { ClaireBoolean *v_or;
            { v_or = ((Optimize.compiler->safety > 4) ? CTRUE : CFALSE);
              if (v_or == CTRUE) g0312I =CTRUE; 
              else { v_or = ((equal(_oid_(v2164->of),_oid_(Kernel.emptySet)) == CTRUE) ? CTRUE : CFALSE);
                if (v_or == CTRUE) g0312I =CTRUE; 
                else { { OID  v14020;
                    { OID gc_local;
                      ITERATE(v10267);
                      v14020= Kernel.cfalse;
                      bag *v10267_support;
                      v10267_support = GC_OBJECT(list,v2164->args);
                      for (START(v10267_support); NEXT(v10267);)
                      { GC_LOOP;
                        if (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v10267))),GC_OBJECT(ClaireType,v2164->of)) != CTRUE)
                         { v14020 = Kernel.ctrue;
                          break;} 
                        GC_UNLOOP;} 
                      } 
                    v_or = not_any(v14020);
                    } 
                  if (v_or == CTRUE) g0312I =CTRUE; 
                  else g0312I = CFALSE;} 
                } 
              } 
            } 
          
          if (g0312I == CTRUE) { (v6224->of = v2164->of);
              Result = _oid_(v6224);
              } 
            else { warn_void();
            { list * v14982;
              { { OID v_bag;
                  GC_ANY(v14982= list::empty(Kernel.emptySet));
                  { { list * v11137;{ bag *v_list; OID v_val;
                        OID v10267,CLcount;
                        v_list = GC_OBJECT(list,v2164->args);
                         v11137 = v_list->clone();
                        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                        { v10267 = (*(v_list))[CLcount];
                          v_val = (*Optimize.c_type)(v10267);
                          
                          (*((list *) v11137))[CLcount] = v_val;} 
                        } 
                      
                      v_bag=_oid_(v11137);} 
                    GC_OID(v_bag);} 
                  ((list *) v14982)->addFast(v_bag);
                  ((list *) v14982)->addFast(GC_OID(_oid_(v2164->of)));} 
                GC_OBJECT(list,v14982);} 
              tformat_string(copy_string("unsafe typed set: ~S not in ~S [262]\n"),2,v14982);
              } 
            { OID  v519;
              { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Core.check_in);
                (v2072->args = list::alloc(3,_oid_(v6224),
                  _oid_(Kernel._set),
                  GC_OID(_oid_(v2164->of))));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v519 = _oid_(v2072);
                } 
              Result = (*Optimize.c_code)(v519,
                _oid_(Kernel._set));
              } 
            } 
          } 
        } 
      else Result = _oid_(v6224);
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Tuple_Optimize(Tuple *v2164)
{ GC_BIND;
  { ClaireType *Result ;
    { list * v1481;
      { { bag *v_list; OID v_val;
          OID v6224,CLcount;
          v_list = v2164->args;
           v1481 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v6224 = (*(v_list))[CLcount];
            v_val = (*Optimize.c_type)(v6224);
            
            (*((list *) v1481))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v1481);} 
      Result = tuple_I_list(v1481);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Tuple_Optimize(Tuple *v2164)
{ GC_BIND;
  (Optimize.OPT->allocation = CTRUE);
  { OID Result = 0;
    { Tuple * v2072 = ((Tuple *) GC_OBJECT(Tuple,new_object_class(Language._Tuple)));
      { Construct * v9514 = v2072; 
        list * v9515;
        { bag *v_list; OID v_val;
          OID v10267,CLcount;
          v_list = GC_OBJECT(list,v2164->args);
           v9515 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v10267 = (*(v_list))[CLcount];
            v_val = c_gc_I_any2(GC_OID((*Optimize.c_code)(v10267,
              _oid_(Kernel._any))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v10267))));
            
            (*((list *) v9515))[CLcount] = v_val;} 
          } 
        (v9514->args = v9515);} 
      add_I_property(Kernel.instances,Language._Tuple,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Definition_Optimize(Definition *v2164)
{ { ClaireType *Result ;
    if (_inf_equalt_class(v2164->arg,Kernel._exception) == CTRUE)
     Result = Kernel.emptySet;
    else Result = v2164->arg;
      return (Result);} 
  } 

OID  c_code_Definition_Optimize(Definition *v2164,ClaireClass *v6219)
{ GC_BIND;
  { OID Result = 0;
    { ClaireClass * v10246 = v2164->arg;
      Variable * v10265;
      { { int  v9121;
          { (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+1));
            v9121 = 0;
            } 
          v10265 = Variable_I_symbol(OBJECT(symbol,Optimize._starname_star->value),v9121,v10246);
          } 
        GC_OBJECT(Variable,v10265);} 
      OID  v10267 = GC_OID(total_ask_class(v10246,GC_OBJECT(list,v2164->args)));
      if (v10246->open <= 0)
       close_exception(((general_error *) (*Core._general_error)(_string_(copy_string("[105] cannot instantiate ~S")),
        _oid_(list::alloc(1,_oid_(v10246))))));
      if (boolean_I_any(v10267) == CTRUE)
       Result = (*Optimize.c_code)(v10267,
        _oid_(v6219));
      else { OID  v10082;
          { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
            (v2072->var = v10265);
            { Let * v9539 = v2072; 
              OID  v9540;
              { Cast * v2072 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                { Cast * v9541 = v2072; 
                  OID  v9543;
                  { OID  v14887;
                    { { OID  v15848;
                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v2072->selector = Core.new_I);
                          (v2072->args = list::alloc(1,_oid_(v10246)));
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                          v15848 = _oid_(v2072);
                          } 
                        v14887 = (*Optimize.c_code)(v15848,
                          _oid_(Kernel._object));
                        } 
                      GC_OID(v14887);} 
                    v9543 = c_gc_I_any1(v14887);
                    } 
                  (v9541->arg = v9543);} 
                (v2072->set_arg = v10246);
                add_I_property(Kernel.instances,Language._Cast,11,_oid_(v2072));
                v9540 = _oid_(v2072);
                } 
              (v9539->value = v9540);} 
            { Let * v9546 = v2072; 
              OID  v9567;
              { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                store_object(v2072,
                  2,
                  Kernel._object,
                  analyze_I_class(v10246,_oid_(v10265),GC_OBJECT(list,v2164->args),list::empty()),
                  CFALSE);
                add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                v9567 = _oid_(v2072);
                } 
              (v9546->arg = v9567);} 
            add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
            v10082 = _oid_(v2072);
            } 
          Result = (*Optimize.c_code)(v10082,
            _oid_(v6219));
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  total_ask_class(ClaireClass *v2164,list *v6212)
{ GC_BIND;
  { OID Result = 0;
    { list * v12460 = GC_OBJECT(list,OBJECT(list,(*Optimize.get_indexed)(_oid_(v2164))));
      int  v6214 = v12460->length;
      { ClaireBoolean * g0332I;
        { ClaireBoolean *v_and;
          { v_and = not_any(_oid_(Optimize.compiler->diet_ask));
            if (v_and == CFALSE) g0332I =CFALSE; 
            else { v_and = ((v6212->length == (v6214-1)) ? CTRUE : CFALSE);
              if (v_and == CFALSE) g0332I =CFALSE; 
              else { v_and = ((v2164->open == ClEnv->ephemeral) ? CTRUE : ((_inf_equalt_class(v2164,Kernel._exception) == CTRUE) ? CTRUE : CFALSE));
                if (v_and == CFALSE) g0332I =CFALSE; 
                else { v_and = ((v6214 <= 4) ? CTRUE : CFALSE);
                  if (v_and == CFALSE) g0332I =CFALSE; 
                  else { { OID  v8066;
                      { int  v6209 = 2;
                        int  v9568 = v6214;
                        { v8066= _oid_(CFALSE);
                          while ((v6209 <= v9568))
                          { if ((((*Kernel.srange)((*(v12460))[v6209]) == _oid_(Kernel._integer)) ? CTRUE : (((*Kernel.srange)((*(v12460))[v6209]) == _oid_(Kernel._any)) ? CTRUE : CFALSE)) != CTRUE)
                             { v8066 = Kernel.ctrue;
                              break;} 
                            ++v6209;
                            } 
                          } 
                        } 
                      v_and = not_any(v8066);
                      } 
                    if (v_and == CFALSE) g0332I =CFALSE; 
                    else g0332I = CTRUE;} 
                  } 
                } 
              } 
            } 
          } 
        
        if (g0332I == CTRUE) { OID  v10246;
            { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = ((v6212->length == 0) ?
                  Core.new_I :
                  Optimize.anyObject_I ));
                { Call * v9571 = v2072; 
                  list * v9572;
                  { list * v10949;
                    { bag *v_list; OID v_val;
                      OID v6224,CLcount;
                      v_list = v6212;
                       v10949 = v_list->clone();
                      for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                      { v6224 = (*(v_list))[CLcount];
                        v_val = c_gc_I_any1(GC_OID((*Optimize.c_code)(GC_OID((*(OBJECT(bag,(*Core.args)(v6224))))[2]),
                          _oid_(Kernel._any))));
                        
                        (*((list *) v10949))[CLcount] = v_val;} 
                      } 
                    v9572 = cons_any(_oid_(v2164),v10949);
                    } 
                  (v9571->args = v9572);} 
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v10246 = _oid_(v2072);
                } 
              GC_OID(v10246);} 
            OID  v6213 = GC_OID(_oid_(_at_property1(Kernel.close,v2164)));
            if (_inf_equal_type(v2164,Kernel._exception) != CTRUE)
             (Optimize.OPT->allocation = CTRUE);
            if (v6212->length == 0)
             v10246= GC_OID((*Optimize.c_code)(v10246));
            if (boolean_I_any(v6213) == CTRUE)
             { Call_method1 * v2072 = ((Call_method1 *) GC_OBJECT(Call_method1,new_object_class(Language._Call_method1)));
              update_property(Kernel.arg,
                v2072,
                2,
                Kernel._object,
                v6213);
              (v2072->args = list::alloc(1,v10246));
              add_I_property(Kernel.instances,Language._Call_method1,11,_oid_(v2072));
              Result = _oid_(v2072);
              } 
            else Result = v10246;
              } 
          else Result = Kernel.cfalse;
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  analyze_I_class(ClaireClass *v6203,OID v2164,list *v10255,list *v12460)
{ GC_RESERVE(15);  // v3.0.55 optim !
  { OID Result = 0;
    { ClaireBoolean * v7993 = ((v6203->open != 4) ? ((boolean_I_any(_oid_(v12460)) != CTRUE) ? ((Optimize.compiler->class2file_ask != CTRUE) ? CTRUE: CFALSE): CFALSE): CFALSE);
      list * v6218;
      { { bag *v_list; OID v_val;
          OID v6224,CLcount;
          v_list = v10255;
           v6218 = v_list->clone(Kernel._any);
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v6224 = (*(v_list))[CLcount];
            { OID  v6216 = GC_OID((*(OBJECT(Call,v6224)->args))[1]);
              OID  v6225 = GC_OID((*(OBJECT(Call,v6224)->args))[2]);
              ClaireObject * v6219 = GC_OBJECT(ClaireObject,_at_property1(OBJECT(property,v6216),v6203));
              ClaireBoolean * v15310 = (((*Kernel.open)(v6216) == 0) ? ((Kernel._slot == v6219->isa) ? CTRUE: CFALSE): CFALSE);
              GC__ANY(v12460 = v12460->addFast(v6216), 4);
              { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = ((v15310 == CTRUE) ?
                  Kernel.put :
                  Core.write ));
                { Call * v9574 = v2072; 
                  list * v9576;
                  { OID v_bag;
                    GC_ANY(v9576= list::empty(Kernel.emptySet));
                    ((list *) v9576)->addFast(v6216);
                    ((list *) v9576)->addFast(v2164);
                    { if ((v15310 != CTRUE) || 
                          (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v6225))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.range)(_oid_(v6219))))) == CTRUE))
                       v_bag = v6225;
                      else v_bag = c_check_any(GC_OID((*Optimize.c_code)(v6225,
                          _oid_(Kernel._any))),GC_OID((*Optimize.c_code)(GC_OID((*Kernel.range)(_oid_(v6219))),
                          _oid_(Kernel._type))));
                        GC_OID(v_bag);} 
                    ((list *) v9576)->addFast(v_bag);} 
                  (v9574->args = v9576);} 
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v_val = _oid_(v2072);
                } 
              } 
            
            (*((list *) v6218))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v6218);} 
      if (v7993 == CTRUE)
       { { OID  v13832;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.add);
            (v2072->args = list::alloc(3,_oid_(Kernel.instances),
              _oid_(v6203),
              v2164));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v13832 = _oid_(v2072);
            } 
          v6218 = v6218->addFast(v13832);
          } 
        GC_OBJECT(list,v6218);} 
      if (Optimize.compiler->class2file_ask != CTRUE)
       { OID gc_local;
        ITERATE(v6219);
        bag *v6219_support;
        v6219_support = GC_OBJECT(list,OBJECT(bag,(*Optimize.get_indexed)(_oid_(v6203))));
        for (START(v6219_support); NEXT(v6219);)
        { GC_LOOP;
          { property * v6216 = OBJECT(restriction,v6219)->selector;
            OID  v6222 = GC_OID(OBJECT(slot,v6219)->DEFAULT);
            { ClaireBoolean * g0340I;
              { ClaireBoolean *v_and;
                { v_and = known_ask_any(v6222);
                  if (v_and == CFALSE) g0340I =CFALSE; 
                  else { { OID  v3167;
                      if (multi_ask_any(_oid_(v6216)) == CTRUE)
                       v3167 = v6222;
                      else v3167 = Kernel.ctrue;
                        v_and = boolean_I_any(v3167);
                      } 
                    if (v_and == CFALSE) g0340I =CFALSE; 
                    else { v_and = not_any(_oid_(v12460->memq(_oid_(v6216))));
                      if (v_and == CFALSE) g0340I =CFALSE; 
                      else { v_and = ((((v6216->inverse == (NULL)) ? CTRUE : CFALSE) != CTRUE) ? CTRUE : ((((v6216->if_write == CNULL) ? CTRUE : CFALSE) != CTRUE) ? CTRUE : (((OBJECT(slot,v6219)->srange != Kernel._object) && 
                            ((OBJECT(slot,v6219)->srange != Kernel._float) && 
                              (inherit_ask_class(OWNER(v6222),Kernel._integer) != CTRUE))) ? CTRUE : CFALSE)));
                        if (v_and == CFALSE) g0340I =CFALSE; 
                        else g0340I = CTRUE;} 
                      } 
                    } 
                  } 
                } 
              
              if (g0340I == CTRUE) { OID  v8960;
                  if (designated_ask_any(v6222) == CTRUE)
                   v8960 = v6222;
                  else { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Kernel.DEFAULT);
                      { Call * v9602 = v2072; 
                        list * v9603;
                        { OID v_bag;
                          GC_ANY(v9603= list::empty(Kernel.emptySet));
                          { { Cast * v2072 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                              { Cast * v9604 = v2072; 
                                OID  v9605;
                                { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                  (v2072->selector = Core._at);
                                  (v2072->args = list::alloc(2,_oid_(v6216),_oid_(v6203)));
                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                  v9605 = _oid_(v2072);
                                  } 
                                (v9604->arg = v9605);} 
                              (v2072->set_arg = Kernel._slot);
                              add_I_property(Kernel.instances,Language._Cast,11,_oid_(v2072));
                              v_bag = _oid_(v2072);
                              } 
                            GC_OID(v_bag);} 
                          ((list *) v9603)->addFast(v_bag);} 
                        (v9602->args = v9603);} 
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v8960 = _oid_(v2072);
                      } 
                    { { OID  v7972;
                      { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v2072->selector = Core.write);
                        (v2072->args = list::alloc(3,_oid_(v6216),
                          v2164,
                          v8960));
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                        v7972 = _oid_(v2072);
                        } 
                      v6218 = v6218->addFast(v7972);
                      } 
                     GC__ANY(v6218, 7);} 
                  } 
                } 
            } 
          GC_UNLOOP;} 
        } 
      { OID  v6213 = GC_OID(_oid_(_at_property1(Kernel.close,v6203)));
        { OID  v8933;
          if (boolean_I_any(v6213) == CTRUE)
           { Call_method1 * v2072 = ((Call_method1 *) GC_OBJECT(Call_method1,new_object_class(Language._Call_method1)));
            update_property(Kernel.arg,
              v2072,
              2,
              Kernel._object,
              v6213);
            (v2072->args = list::alloc(1,v2164));
            add_I_property(Kernel.instances,Language._Call_method1,11,_oid_(v2072));
            v8933 = _oid_(v2072);
            } 
          else v8933 = v2164;
            v6218 = v6218->addFast(v8933);
          } 
        } 
      Result = _oid_(v6218);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Defobj_Optimize(Defobj *v2164,ClaireClass *v6219)
{ GC_BIND;
  { OID Result = 0;
    { ClaireBoolean * v10244 = Optimize.OPT->allocation;
      ClaireClass * v10246 = v2164->arg;
      OID  v6215 = get_symbol(v2164->ident);
      OID  v10265;
      { if ((v6215 != CNULL) && 
            (inherit_ask_class(OWNER(v6215),Core._global_variable) != CTRUE))
         v10265 = v6215;
        else { Variable * v11256;{ int  v190;
              { (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+1));
                v190 = 0;
                } 
              v11256 = Variable_I_symbol(OBJECT(symbol,Optimize._starname_star->value),v190,v10246);
              } 
            
            v10265=_oid_(v11256);} 
          GC_OID(v10265);} 
      Call * v7061;
      { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v2072->selector = Optimize.object_I);
          (v2072->args = list::alloc(2,_oid_(v2164->ident),_oid_(v10246)));
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
          v7061 = v2072;
          } 
        GC_OBJECT(Call,v7061);} 
      OID  v7062 = GC_OID(analyze_I_class(v10246,v10265,GC_OBJECT(list,v2164->args),list::alloc(1,_oid_(Kernel.name))));
      OID  v10267;
      if (inherit_ask_class(OWNER(v10265),Language._Variable) != CTRUE)
       { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
        store_object(v2072,
          2,
          Kernel._object,
          (*Kernel.cons)(_oid_(v7061),
            v7062),
          CFALSE);
        add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
        v10267 = _oid_(v2072);
        } 
      else { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
          store_object(v2072,
            2,
            Kernel._object,
            v10265,
            CFALSE);
          (v2072->value = _oid_(v7061));
          { Let * v9631 = v2072; 
            OID  v9632;
            { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
              store_object(v2072,
                2,
                Kernel._object,
                v7062,
                CFALSE);
              add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
              v9632 = _oid_(v2072);
              } 
            (v9631->arg = v9632);} 
          add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
          v10267 = _oid_(v2072);
          } 
        if (v10246->open <= 0)
       close_exception(((general_error *) (*Core._general_error)(_string_(copy_string("[105] cannot instantiate ~S")),
        _oid_(list::alloc(1,_oid_(v10246))))));
      if (v6215 != CNULL)
       { if (contain_ask_list(Optimize.OPT->objects,v6215) != CTRUE)
         { Optimize.OPT->objects->addFast(v6215);
          (*Optimize.c_register)(v6215);
          } 
        } 
      else { warn_void();
          tformat_string(copy_string("~S is unknown [265]\n"),2,list::alloc(1,_oid_(v2164->ident)));
          } 
        v10267= GC_OID((*Optimize.c_code)(v10267,
        _oid_(v6219)));
      if (_inf_equal_type(v2164->arg,Kernel._exception) == CTRUE)
       (Optimize.OPT->allocation = v10244);
      Result = v10267;
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Defclass_Optimize(Defclass *v2164,ClaireClass *v6219)
{ GC_BIND;
  { OID Result = 0;
    { symbol * v3080 = v2164->ident;
      OID  v6215 = get_symbol(v3080);
      Call * v1849;
      { ClaireObject *V_CC ;
        if (v6215 != CNULL)
         { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v2072->selector = Core.class_I);
          (v2072->args = list::alloc(2,_oid_(v3080),_oid_(v2164->arg)));
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
          V_CC = v2072;
          } 
        else close_exception(((general_error *) (*Core._general_error)(_string_(copy_string("[internal] cannot compile unknown class ~S")),
            _oid_(list::alloc(1,_oid_(v3080))))));
          v1849= (Call *) V_CC;} 
      Do * v10267;
      { { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
          { Do * v9635 = v2072; 
            list * v9636;
            { list * v5956;
              { list * v6917;
                { bag *v_list; OID v_val;
                  OID v6224,CLcount;
                  v_list = GC_OBJECT(list,v2164->args);
                   v6917 = v_list->clone();
                  for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                  { v6224 = (*(v_list))[CLcount];
                    { OID  v6222 = CNULL;
                      if (INHERIT(OWNER(v6224),Language._Call))
                       { v6222= GC_OID((*(OBJECT(Call,v6224)->args))[2]);
                        v6224= GC_OID((*(OBJECT(Call,v6224)->args))[1]);
                        } 
                      { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v2072->selector = Kernel.add_slot);
                        (v2072->args = list::alloc(5,v6215,
                          _oid_(make_a_property_any(_oid_(OBJECT(Variable,v6224)->pname))),
                          GC_OID((*Kernel.range)(v6224)),
                          v6222,
                          0));
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                        v_val = _oid_(v2072);
                        } 
                      } 
                    
                    (*((list *) v6917))[CLcount] = v_val;} 
                  } 
                list * v7878;
                if (v2164->params->length != 0)
                 { OID v_bag;
                  GC_ANY(v7878= list::empty(Kernel.emptySet));
                  { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Kernel.put);
                      (v2072->args = list::alloc(3,_oid_(Kernel.params),
                        v6215,
                        GC_OID(_oid_(v2164->params))));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v_bag = _oid_(v2072);
                      } 
                    GC_OID(v_bag);} 
                  ((list *) v7878)->addFast(v_bag);} 
                else v7878 = list::empty();
                  v5956 = append_list(v6917,v7878);
                } 
              v9636 = cons_any(_oid_(v1849),v5956);
              } 
            (v9635->args = v9636);} 
          add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
          v10267 = v2072;
          } 
        GC_OBJECT(Do,v10267);} 
      if (contain_ask_list(Optimize.OPT->objects,v6215) != CTRUE)
       { Optimize.OPT->objects->addFast(v6215);
        (*Optimize.c_register)(v6215);
        } 
      Result = (*Optimize.c_code)(_oid_(v10267),
        _oid_(v6219));
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Defmethod_Optimize(Defmethod *v2164)
{ return (Kernel._any);} 

OID  c_code_Defmethod_Optimize(Defmethod *v2164)
{ GC_BIND;
  { OID Result = 0;
    { property * v12592 = v2164->arg->selector;
      list * v6212 = GC_OBJECT(list,v2164->arg->args);
      list * v12466 = (((v6212->length == 1) && 
          ((*(v6212))[1] == _oid_(ClEnv))) ?
        list::alloc(1,GC_OID(_oid_(Variable_I_symbol(OBJECT(symbol,Optimize._starname_star->value),0,Kernel._void)))) :
        v6212 );
      list * v12463 = GC_OBJECT(list,extract_signature_I_list(v12466));
      list * v11129 = GC_OBJECT(list,extract_range_any(GC_OID(v2164->set_arg),v12466,GC_OBJECT(list,OBJECT(list,Language.LDEF->value))));
      OID  v986;
      if ((boolean_I_any(v2164->inline_ask) == CTRUE) && 
          (Optimize.compiler->inline_ask == CTRUE))
       { print_in_string_void();
        princ_string(copy_string("lambda[("));
        ppvariable_list(v12466);
        princ_string(copy_string("),"));
        print_any(GC_OID(v2164->body));
        princ_string(copy_string("]"));
        v986 = _string_(end_of_print_void());
        } 
      else v986 = Kernel.cfalse;
        list * v4070 = GC_OBJECT(list,extract_status_new_any(GC_OID(v2164->body)));
      OID  v5375 = GC_OID((*Core._at)(_oid_(v12592),
        (*(v12463))[2]));
      method * v6213;
      { ClaireObject *V_CC ;
        if (Kernel._method == OBJECT(ClaireObject,v5375)->isa)
         V_CC = OBJECT(method,v5375);
        else close_exception(((general_error *) (*Core._general_error)(_string_(copy_string("[internal] the method ~S @ ~S is not known")),
            _oid_(list::alloc(2,_oid_(v12592),(*(v12463))[2])))));
          v6213= (method *) V_CC;} 
      OID  v4180 = v6213->status;
      ((*(v4070))[2]=get_property(Kernel.functional,v6213));
      if ((Optimize.compiler->inline_ask != CTRUE) && 
          ((v12592 == Language.Iterate) || 
              (v12592 == Language.iterate)))
       Result = Core.nil->value;
      else if (((*(v11129))[1] == _oid_(Kernel._void)) && 
          (sort_pattern_ask_list(v12466,GC_OID(v2164->body)) == CTRUE))
       Result = sort_code_Defmethod(v2164,v12466);
      else { if ((*(v4070))[3] != _oid_(Kernel.body))
           { char * v12507 = GC_STRING(string_v((*Optimize.function_name)(_oid_(v12592),
              (*(v12463))[2],
              (*(v4070))[2])));
            lambda * v12445 = GC_OBJECT(lambda,lambda_I_list(v12466,(*(v4070))[3]));
            int  v1019 = ((Optimize.OPT->recompute == CTRUE) ?
              c_status_any(GC_OID(v12445->body),GC_OBJECT(list,v12445->vars)) :
              status_I_restriction(v6213) );
            compile_lambda_string(v12507,v12445,_oid_(v6213));
            if (((*(v4070))[1] == CNULL) || 
                (Optimize.OPT->recompute == CTRUE))
             { if ((Optimize.OPT->use_nth_equal != CTRUE) && 
                  (BCONTAIN(v1019,2)))
               v1019= (v1019-exp2_integer(2));
              if ((Optimize.OPT->use_update != CTRUE) && 
                  (BCONTAIN(v1019,3)))
               v1019= (v1019-exp2_integer(3));
              if ((Optimize.OPT->allocation != CTRUE) && 
                  (BCONTAIN(v1019,1)))
               v1019= (v1019-exp2_integer(1));
              ((*(v4070))[1]=v1019);
              } 
            ((*(v4070))[2]=_oid_(make_function_string(v12507)));
            } 
          if (INHERIT(OWNER(v2164->set_arg),Core._global_variable))
           ((*(v11129))[1]=v2164->set_arg);
          else if ((INHERIT(v6213->range->isa,Kernel._class)) && 
              (inherit_ask_class(OWNER((*(v11129))[1]),Kernel._class) != CTRUE))
           ((*(v11129))[1]=_oid_(v6213->range));
          { OID  v10256 = GC_OID(add_method_I_method(v6213,
              OBJECT(list,(*(v12463))[1]),
              (*(v11129))[1],
              (*(v4070))[1],
              OBJECT(ClaireFunction,(*(v4070))[2])));
            { OID  v12636;
              if ((boolean_I_any(v2164->inline_ask) == CTRUE) && 
                  ((Optimize.compiler->inline_ask == CTRUE) && 
                    (Optimize.compiler->diet_ask != CTRUE)))
               { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Core.inlineok_ask);
                (v2072->args = list::alloc(2,v10256,v986));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v12636 = _oid_(v2072);
                } 
              else if ((boolean_I_any((*(v11129))[2]) == CTRUE) && 
                  (Optimize.compiler->diet_ask != CTRUE))
               { char * v12507 = GC_STRING(append_string(GC_STRING(string_v((*Optimize.function_name)(_oid_(v12592),
                  (*(v12463))[2],
                  (*(v4070))[2]))),copy_string("_type")));
                compile_lambda_string(v12507,OBJECT(lambda,(*(v11129))[2]),_oid_(Kernel._type));
                { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Core.write);
                  (v2072->args = list::alloc(3,Language.typing->value,
                    v10256,
                    _oid_(make_function_string(v12507))));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v12636 = _oid_(v2072);
                  } 
                } 
              else v12636 = v10256;
                Result = (*Optimize.c_code)(v12636);
              } 
            } 
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * sort_pattern_ask_list(list *v12466,OID v2847)
{ GC_BIND;
  { ClaireBoolean *Result ;
    { ClaireBoolean *v_and;
      { v_and = ((v12466->length == 1) ? CTRUE : CFALSE);
        if (v_and == CFALSE) Result =CFALSE; 
        else { if (INHERIT(OWNER(v2847),Language._Call))
           { ClaireBoolean *v_and1;
            { v_and1 = ((OBJECT(Call,v2847)->selector == Core.sort) ? CTRUE : CFALSE);
              if (v_and1 == CFALSE) v_and =CFALSE; 
              else { { OID  v12056 = GC_OID((*(OBJECT(Call,v2847)->args))[1]);
                  v_and1 = ((INHERIT(OWNER(v12056),Language._Call)) ?
                    ((OBJECT(Call,v12056)->selector == Core._at) ? ((INHERIT(OWNER((*(OBJECT(Call,v12056)->args))[1]),Kernel._property)) ? CTRUE: CFALSE): CFALSE) :
                    CFALSE );
                  } 
                if (v_and1 == CFALSE) v_and =CFALSE; 
                else { v_and1 = ((equal(lexical_build_any(GC_OID((*(OBJECT(Call,v2847)->args))[2]),v12466,0),(*(v12466))[1]) == CTRUE) ? CTRUE : CFALSE);
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

OID  sort_code_Defmethod(Defmethod *v2164,list *v12466)
{ GC_BIND;
  { OID Result = 0;
    { OID  v6212 = (*(v12466))[1];
      OID  v6206 = GC_OID((*(OBJECT(bag,(*Core.args)(GC_OID((*(OBJECT(bag,(*Core.args)(GC_OID(v2164->body)))))[1])))))[1]);
      Variable * v6213 = GC_OBJECT(Variable,Variable_I_symbol(symbol_I_string2(copy_string("m")),0,Kernel._integer));
      Variable * v6214 = GC_OBJECT(Variable,Variable_I_symbol(symbol_I_string2(copy_string("n")),0,Kernel._integer));
      Variable * v6224 = GC_OBJECT(Variable,Variable_I_symbol(symbol_I_string2(copy_string("x")),0,GC_OBJECT(ClaireType,member_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.range)(v6212)))))));
      Variable * v6216 = GC_OBJECT(Variable,Variable_I_symbol(symbol_I_string2(copy_string("p")),0,Kernel._integer));
      Variable * v1353 = GC_OBJECT(Variable,Variable_I_symbol(symbol_I_string2(copy_string("q")),0,Kernel._integer));
      Defmethod * v13812;
      { { Defmethod * v2072 = ((Defmethod *) GC_OBJECT(Defmethod,new_object_class(Language._Defmethod)));
          (v2072->arg = v2164->arg);
          (v2072->inline_ask = Kernel.cfalse);
          (v2072->set_arg = v2164->set_arg);
          { Defmethod * v9662 = v2072; 
            OID  v9663;
            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = v2164->arg->selector);
              { Call * v9664 = v2072; 
                list * v9665;
                { OID v_bag;
                  GC_ANY(v9665= list::empty(Kernel.emptySet));
                  ((list *) v9665)->addFast(1);
                  { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Kernel.length);
                      (v2072->args = list::alloc(1,(*(v12466))[1]));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v_bag = _oid_(v2072);
                      } 
                    GC_OID(v_bag);} 
                  ((list *) v9665)->addFast(v_bag);
                  ((list *) v9665)->addFast(v6212);} 
                (v9664->args = v9665);} 
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v9663 = _oid_(v2072);
              } 
            (v9662->body = v9663);} 
          add_I_property(Kernel.instances,Language._Defmethod,11,_oid_(v2072));
          v13812 = v2072;
          } 
        GC_OBJECT(Defmethod,v13812);} 
      If * v6399;
      { { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
          { If * v9666 = v2072; 
            OID  v9667;
            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Kernel._sup);
              (v2072->args = list::alloc(2,_oid_(v6213),_oid_(v6214)));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v9667 = _oid_(v2072);
              } 
            (v9666->test = v9667);} 
          { If * v9669 = v2072; 
            OID  v9671;
            { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
              (v2072->var = v6224);
              { Let * v9672 = v2072; 
                OID  v9691;
                { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Kernel.nth);
                  (v2072->args = list::alloc(2,v6212,_oid_(v6214)));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v9691 = _oid_(v2072);
                  } 
                (v9672->value = v9691);} 
              { Let * v9692 = v2072; 
                OID  v9693;
                { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                  { If * v9694 = v2072; 
                    OID  v9695;
                    { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Kernel._equal);
                      { Call * v9696 = v2072; 
                        list * v9697;
                        { OID v_bag;
                          GC_ANY(v9697= list::empty(Kernel.emptySet));
                          ((list *) v9697)->addFast(_oid_(v6213));
                          { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                              (v2072->selector = Core._plus);
                              (v2072->args = list::alloc(2,_oid_(v6214),1));
                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                              v_bag = _oid_(v2072);
                              } 
                            GC_OID(v_bag);} 
                          ((list *) v9697)->addFast(v_bag);} 
                        (v9696->args = v9697);} 
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v9695 = _oid_(v2072);
                      } 
                    (v9694->test = v9695);} 
                  { If * v9698 = v2072; 
                    OID  v9699;
                    { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                      { If * v9700 = v2072; 
                        OID  v9722;
                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          update_property(Kernel.selector,
                            v2072,
                            2,
                            Kernel._object,
                            v6206);
                          { Call * v9723 = v2072; 
                            list * v9724;
                            { OID v_bag;
                              GC_ANY(v9724= list::empty(Kernel.emptySet));
                              { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                  (v2072->selector = Kernel.nth);
                                  (v2072->args = list::alloc(2,v6212,_oid_(v6213)));
                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                  v_bag = _oid_(v2072);
                                  } 
                                GC_OID(v_bag);} 
                              ((list *) v9724)->addFast(v_bag);
                              ((list *) v9724)->addFast(_oid_(v6224));} 
                            (v9723->args = v9724);} 
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                          v9722 = _oid_(v2072);
                          } 
                        (v9700->test = v9722);} 
                      { If * v9725 = v2072; 
                        OID  v9726;
                        { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                          { Do * v9727 = v2072; 
                            list * v9728;
                            { OID v_bag;
                              GC_ANY(v9728= list::empty(Kernel.emptySet));
                              { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                  (v2072->selector = Kernel.nth_equal);
                                  { Call * v9729 = v2072; 
                                    list * v9730;
                                    { OID v_bag;
                                      GC_ANY(v9730= list::empty(Kernel.emptySet));
                                      ((list *) v9730)->addFast(v6212);
                                      ((list *) v9730)->addFast(_oid_(v6214));
                                      { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                          (v2072->selector = Kernel.nth);
                                          (v2072->args = list::alloc(2,v6212,_oid_(v6213)));
                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                          v_bag = _oid_(v2072);
                                          } 
                                        GC_OID(v_bag);} 
                                      ((list *) v9730)->addFast(v_bag);} 
                                    (v9729->args = v9730);} 
                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                  v_bag = _oid_(v2072);
                                  } 
                                GC_OID(v_bag);} 
                              ((list *) v9728)->addFast(v_bag);
                              { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                  (v2072->selector = Kernel.nth_equal);
                                  (v2072->args = list::alloc(3,v6212,
                                    _oid_(v6213),
                                    _oid_(v6224)));
                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                  v_bag = _oid_(v2072);
                                  } 
                                GC_OID(v_bag);} 
                              ((list *) v9728)->addFast(v_bag);} 
                            (v9727->args = v9728);} 
                          add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                          v9726 = _oid_(v2072);
                          } 
                        (v9725->arg = v9726);} 
                      add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                      (v2072->other = Kernel.cfalse);
                      v9699 = _oid_(v2072);
                      } 
                    (v9698->arg = v9699);} 
                  { If * v9731 = v2072; 
                    OID  v9753;
                    { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
                      (v2072->var = v6216);
                      { Let * v9754 = v2072; 
                        OID  v9755;
                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v2072->selector = Core._sup_sup);
                          { Call * v9756 = v2072; 
                            list * v9757;
                            { OID v_bag;
                              GC_ANY(v9757= list::empty(Kernel.emptySet));
                              { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                  (v2072->selector = Core._plus);
                                  (v2072->args = list::alloc(2,_oid_(v6214),_oid_(v6213)));
                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                  v_bag = _oid_(v2072);
                                  } 
                                GC_OID(v_bag);} 
                              ((list *) v9757)->addFast(v_bag);
                              ((list *) v9757)->addFast(1);} 
                            (v9756->args = v9757);} 
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                          v9755 = _oid_(v2072);
                          } 
                        (v9754->value = v9755);} 
                      { Let * v9758 = v2072; 
                        OID  v9759;
                        { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
                          (v2072->var = v1353);
                          (v2072->value = _oid_(v6214));
                          { Let * v9760 = v2072; 
                            OID  v9761;
                            { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                              { Do * v9762 = v2072; 
                                list * v10435;
                                { OID v_bag;
                                  GC_ANY(v10435= list::empty(Kernel.emptySet));
                                  { { Assign * v2072 = ((Assign *) GC_OBJECT(Assign,new_object_class(Language._Assign)));
                                      (v2072->var = _oid_(v6224));
                                      { Assign * v10437 = v2072; 
                                        OID  v10438;
                                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                          (v2072->selector = Kernel.nth);
                                          (v2072->args = list::alloc(2,v6212,_oid_(v6216)));
                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                          v10438 = _oid_(v2072);
                                          } 
                                        (v10437->arg = v10438);} 
                                      add_I_property(Kernel.instances,Language._Assign,11,_oid_(v2072));
                                      v_bag = _oid_(v2072);
                                      } 
                                    GC_OID(v_bag);} 
                                  ((list *) v10435)->addFast(v_bag);
                                  { { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                                      { If * v10439 = v2072; 
                                        OID  v10440;
                                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                          (v2072->selector = Core._I_equal);
                                          (v2072->args = list::alloc(2,_oid_(v6216),_oid_(v6214)));
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
                                              ((list *) v10444)->addFast(v6212);
                                              ((list *) v10444)->addFast(_oid_(v6216));
                                              { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                  (v2072->selector = Kernel.nth);
                                                  (v2072->args = list::alloc(2,v6212,_oid_(v6214)));
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
                                  ((list *) v10435)->addFast(v_bag);
                                  { { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                                      (v2072->var = v6216);
                                      { Iteration * v10445 = v2072; 
                                        OID  v10466;
                                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                          (v2072->selector = Kernel._dot_dot);
                                          { Call * v10467 = v2072; 
                                            list * v10468;
                                            { OID v_bag;
                                              GC_ANY(v10468= list::empty(Kernel.emptySet));
                                              { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                  (v2072->selector = Core._plus);
                                                  (v2072->args = list::alloc(2,_oid_(v6214),1));
                                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                                  v_bag = _oid_(v2072);
                                                  } 
                                                GC_OID(v_bag);} 
                                              ((list *) v10468)->addFast(v_bag);
                                              ((list *) v10468)->addFast(_oid_(v6213));} 
                                            (v10467->args = v10468);} 
                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                          v10466 = _oid_(v2072);
                                          } 
                                        (v10445->set_arg = v10466);} 
                                      { Iteration * v10469 = v2072; 
                                        OID  v10470;
                                        { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                                          { If * v10471 = v2072; 
                                            OID  v10472;
                                            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                              update_property(Kernel.selector,
                                                v2072,
                                                2,
                                                Kernel._object,
                                                v6206);
                                              { Call * v10473 = v2072; 
                                                list * v10474;
                                                { OID v_bag;
                                                  GC_ANY(v10474= list::empty(Kernel.emptySet));
                                                  { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                      (v2072->selector = Kernel.nth);
                                                      (v2072->args = list::alloc(2,v6212,_oid_(v6216)));
                                                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                                      v_bag = _oid_(v2072);
                                                      } 
                                                    GC_OID(v_bag);} 
                                                  ((list *) v10474)->addFast(v_bag);
                                                  ((list *) v10474)->addFast(_oid_(v6224));} 
                                                (v10473->args = v10474);} 
                                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                              v10472 = _oid_(v2072);
                                              } 
                                            (v10471->test = v10472);} 
                                          { If * v10475 = v2072; 
                                            OID  v10497;
                                            { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                                              { Do * v10498 = v2072; 
                                                list * v10499;
                                                { OID v_bag;
                                                  GC_ANY(v10499= list::empty(Kernel.emptySet));
                                                  { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                      (v2072->selector = Kernel.nth_equal);
                                                      { Call * v10500 = v2072; 
                                                        list * v10501;
                                                        { OID v_bag;
                                                          GC_ANY(v10501= list::empty(Kernel.emptySet));
                                                          ((list *) v10501)->addFast(v6212);
                                                          ((list *) v10501)->addFast(_oid_(v6214));
                                                          { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                              (v2072->selector = Kernel.nth);
                                                              (v2072->args = list::alloc(2,v6212,_oid_(v6216)));
                                                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                                              v_bag = _oid_(v2072);
                                                              } 
                                                            GC_OID(v_bag);} 
                                                          ((list *) v10501)->addFast(v_bag);} 
                                                        (v10500->args = v10501);} 
                                                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                                      v_bag = _oid_(v2072);
                                                      } 
                                                    GC_OID(v_bag);} 
                                                  ((list *) v10499)->addFast(v_bag);
                                                  { { Assign * v2072 = ((Assign *) GC_OBJECT(Assign,new_object_class(Language._Assign)));
                                                      (v2072->var = _oid_(v6214));
                                                      { Assign * v10502 = v2072; 
                                                        OID  v10504;
                                                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                          (v2072->selector = Core._plus);
                                                          (v2072->args = list::alloc(2,_oid_(v6214),1));
                                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                                          v10504 = _oid_(v2072);
                                                          } 
                                                        (v10502->arg = v10504);} 
                                                      add_I_property(Kernel.instances,Language._Assign,11,_oid_(v2072));
                                                      v_bag = _oid_(v2072);
                                                      } 
                                                    GC_OID(v_bag);} 
                                                  ((list *) v10499)->addFast(v_bag);
                                                  { { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                                                      { If * v10505 = v2072; 
                                                        OID  v10506;
                                                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                          (v2072->selector = Kernel._sup);
                                                          (v2072->args = list::alloc(2,_oid_(v6216),_oid_(v6214)));
                                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                                          v10506 = _oid_(v2072);
                                                          } 
                                                        (v10505->test = v10506);} 
                                                      { If * v10507 = v2072; 
                                                        OID  v10528;
                                                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                          (v2072->selector = Kernel.nth_equal);
                                                          { Call * v10529 = v2072; 
                                                            list * v10530;
                                                            { OID v_bag;
                                                              GC_ANY(v10530= list::empty(Kernel.emptySet));
                                                              ((list *) v10530)->addFast(v6212);
                                                              ((list *) v10530)->addFast(_oid_(v6216));
                                                              { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                                  (v2072->selector = Kernel.nth);
                                                                  (v2072->args = list::alloc(2,v6212,_oid_(v6214)));
                                                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                                                  v_bag = _oid_(v2072);
                                                                  } 
                                                                GC_OID(v_bag);} 
                                                              ((list *) v10530)->addFast(v_bag);} 
                                                            (v10529->args = v10530);} 
                                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                                          v10528 = _oid_(v2072);
                                                          } 
                                                        (v10507->arg = v10528);} 
                                                      add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                                                      (v2072->other = Kernel.cfalse);
                                                      v_bag = _oid_(v2072);
                                                      } 
                                                    GC_OID(v_bag);} 
                                                  ((list *) v10499)->addFast(v_bag);} 
                                                (v10498->args = v10499);} 
                                              add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                                              v10497 = _oid_(v2072);
                                              } 
                                            (v10475->arg = v10497);} 
                                          add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                                          (v2072->other = Kernel.cfalse);
                                          v10470 = _oid_(v2072);
                                          } 
                                        (v10469->arg = v10470);} 
                                      add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                                      v_bag = _oid_(v2072);
                                      } 
                                    GC_OID(v_bag);} 
                                  ((list *) v10435)->addFast(v_bag);
                                  { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                      (v2072->selector = Kernel.nth_equal);
                                      (v2072->args = list::alloc(3,v6212,
                                        _oid_(v6214),
                                        _oid_(v6224)));
                                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                      v_bag = _oid_(v2072);
                                      } 
                                    GC_OID(v_bag);} 
                                  ((list *) v10435)->addFast(v_bag);
                                  { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                      (v2072->selector = v2164->arg->selector);
                                      { Call * v10531 = v2072; 
                                        list * v10532;
                                        { OID v_bag;
                                          GC_ANY(v10532= list::empty(Kernel.emptySet));
                                          ((list *) v10532)->addFast(_oid_(v1353));
                                          { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                              (v2072->selector = Kernel._dash);
                                              (v2072->args = list::alloc(2,_oid_(v6214),1));
                                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                              v_bag = _oid_(v2072);
                                              } 
                                            GC_OID(v_bag);} 
                                          ((list *) v10532)->addFast(v_bag);
                                          ((list *) v10532)->addFast(v6212);} 
                                        (v10531->args = v10532);} 
                                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                      v_bag = _oid_(v2072);
                                      } 
                                    GC_OID(v_bag);} 
                                  ((list *) v10435)->addFast(v_bag);
                                  { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                      (v2072->selector = v2164->arg->selector);
                                      { Call * v10533 = v2072; 
                                        list * v10534;
                                        { OID v_bag;
                                          GC_ANY(v10534= list::empty(Kernel.emptySet));
                                          { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                              (v2072->selector = Core._plus);
                                              (v2072->args = list::alloc(2,_oid_(v6214),1));
                                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                              v_bag = _oid_(v2072);
                                              } 
                                            GC_OID(v_bag);} 
                                          ((list *) v10534)->addFast(v_bag);
                                          ((list *) v10534)->addFast(_oid_(v6213));
                                          ((list *) v10534)->addFast(v6212);} 
                                        (v10533->args = v10534);} 
                                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                      v_bag = _oid_(v2072);
                                      } 
                                    GC_OID(v_bag);} 
                                  ((list *) v10435)->addFast(v_bag);} 
                                (v9762->args = v10435);} 
                              add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                              v9761 = _oid_(v2072);
                              } 
                            (v9760->arg = v9761);} 
                          add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
                          v9759 = _oid_(v2072);
                          } 
                        (v9758->arg = v9759);} 
                      add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
                      v9753 = _oid_(v2072);
                      } 
                    (v9731->other = v9753);} 
                  add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                  v9693 = _oid_(v2072);
                  } 
                (v9692->arg = v9693);} 
              add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
              v9671 = _oid_(v2072);
              } 
            (v9669->arg = v9671);} 
          add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
          (v2072->other = Kernel.cfalse);
          v6399 = v2072;
          } 
        GC_OBJECT(If,v6399);} 
      Defmethod * v13813;
      { { Defmethod * v2072 = ((Defmethod *) GC_OBJECT(Defmethod,new_object_class(Language._Defmethod)));
          { Defmethod * v10535 = v2072; 
            Call * v10536;
            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = v2164->arg->selector);
              (v2072->args = list::alloc(3,_oid_(v6214),
                _oid_(v6213),
                v6212));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v10536 = v2072;
              } 
            (v10535->arg = v10536);} 
          (v2072->inline_ask = Kernel.cfalse);
          (v2072->set_arg = v2164->set_arg);
          (v2072->body = _oid_(v6399));
          add_I_property(Kernel.instances,Language._Defmethod,11,_oid_(v2072));
          v13813 = v2072;
          } 
        GC_OBJECT(Defmethod,v13813);} 
      tformat_string(copy_string("---- note: quick sort optimisation for ~S ---- \n"),2,list::alloc(1,_oid_(v2164->arg->selector)));
      OPT_EVAL(_oid_(v13813));
      { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
        (v2072->args = list::alloc(2,GC_OID((*Optimize.c_code)(_oid_(v13812))),GC_OID((*Optimize.c_code)(_oid_(v13813)))));
        add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

method * add_method_property2(property *v6216,list *v12463,ClaireType *v12637,int v12681,ClaireFunction *v12211,ClaireFunction *v12212)
{ return (add_method_property(v6216,
    v12463,
    v12637,
    v12681,
    _oid_(v12211)));} 

OID  add_method_I_method(method *v6213,list *v12463,OID v12637,OID v12924,ClaireFunction *v12279)
{ GC_BIND;
  { OID Result = 0;
    { Call_method * v10246;
      { { Call_method * v2072 = ((Call_method *) GC_OBJECT(Call_method,new_object_class(Language._Call_method)));
          (v2072->arg = ((method *) _at_property1(Kernel.add_method,Kernel._property)));
          (v2072->args = list::alloc(5,GC_OID((*Optimize.c_code)(_oid_(v6213->selector),
              _oid_(Kernel._property))),
            GC_OID((*Optimize.c_code)(_oid_(v12463),
              _oid_(Kernel._list))),
            GC_OID((*Optimize.c_code)(v12637,
              _oid_(Kernel._type))),
            v12924,
            _oid_(v12279)));
          add_I_property(Kernel.instances,Language._Call_method,11,_oid_(v2072));
          v10246 = v2072;
          } 
        GC_OBJECT(Call_method,v10246);} 
      if ((v6213->range == Kernel._float) || 
          ((v6213->domain->memq(_oid_(Kernel._float)) == CTRUE) || 
            (INHERIT(v6213->range->isa,Kernel._tuple))))
       v10246->args->addFast(_oid_(make_function_string(append_string(string_I_function(v12279),copy_string("_")))));
      Result = _oid_(v10246);
      } 
    GC_UNBIND; return (Result);} 
  } 

list * extract_status_new_any(OID v6224)
{ GC_BIND;
  { list *Result ;
    { OID  v6219 = CNULL;
      OID  v6206;
      if ((INHERIT(OWNER(v6224),Language._Call)) && (OBJECT(Call,v6224)->selector == Language.function_I))
       v6206 = v6224;
      else v6206 = CNULL;
        if (INHERIT(OWNER(v6224),Language._And))
       { OID  v6225 = (*(OBJECT(And,v6224)->args))[1];
        if ((INHERIT(OWNER(v6225),Language._Call)) && (OBJECT(Call,v6225)->selector == Language.function_I))
         { v6206= v6225;
          v6224= (*(OBJECT(And,v6224)->args))[2];
          } 
        } 
      else if (INHERIT(OWNER(v6224),Language._Call))
       { if (OBJECT(Call,v6224)->selector == Language.function_I)
         v6224= _oid_(Kernel.body);
        } 
      if (v6206 != CNULL)
       { v6224= _oid_(Kernel.body);
        if (length_bag(OBJECT(bag,(*Core.args)(v6206))) > 1)
         { ClaireHandler c_handle = ClaireHandler();
          if ERROR_IN 
          { { int  v12186;{ set * v9184;
                { set * v5398 = set::empty(Kernel.emptySet);
                  { OID gc_local;
                    ITERATE(v6221);
                    bag *v6221_support;
                    v6221_support = GC_OBJECT(list,cdr_list(OBJECT(list,(*Core.args)(v6206))));
                    for (START(v6221_support); NEXT(v6221);)
                    v5398->addFast(OPT_EVAL(v6221));
                    } 
                  v9184 = GC_OBJECT(set,v5398);
                  } 
                v12186 = integer_I_set(v9184);
                } 
              
              v6219=v12186;} 
            ClEnv->cHandle--;} 
          else if (belong_to(_oid_(ClEnv->exception_I),_oid_(Kernel._any)) == CTRUE)
          { c_handle.catchIt();{ warn_void();
              (Optimize.SHIT->value= _oid_(cdr_list(OBJECT(list,(*Core.args)(v6206)))));
              tformat_string(copy_string("wrong status ~S -> ~S [266]\n"),2,GC_OBJECT(list,list::alloc(2,v6206,_oid_(set_I_bag(cdr_list(OBJECT(list,(*Core.args)(v6206))))))));
              v6219= 0;
              } 
            } 
          else PREVIOUS_HANDLER;} 
        else v6219= 0;
          v6206= _oid_(make_function_string(string_I_symbol(extract_symbol_any((*(OBJECT(bag,(*Core.args)(v6206))))[1]))));
        } 
      Result = list::alloc(3,v6219,
        v6206,
        v6224);
      } 
    GC_UNBIND; return (Result);} 
  } 

list * extract_signature_I_list(list *v6212)
{ GC_BIND;
  (Language.LDEF->value= _oid_(list::empty(Kernel._any)));
  { list *Result ;
    { int  v6214 = 0;
      list * v12397 = list::empty(Kernel._type);
      list * v12398;
      { { bag *v_list; OID v_val;
          OID v6222,CLcount;
          v_list = v6212;
           v12398 = v_list->clone(Kernel._any);
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v6222 = (*(v_list))[CLcount];
            { OID  v6216 = GC_OID(extract_pattern_any(GC_OID(_oid_(OBJECT(Variable,v6222)->range)),list::alloc(1,v6214)));
              ++v6214;
              { { OID  v10145;
                  if (INHERIT(OBJECT(Variable,v6222)->range->isa,Core._global_variable))
                   v10145 = _oid_(OBJECT(Variable,v6222)->range);
                  else v10145 = v6216;
                    v12397 = v12397->addFast(v10145);
                  } 
                GC_OBJECT(list,v12397);} 
              (OBJECT(Variable,v6222)->range = type_I_any(v6216));
              v_val = v6216;
              } 
            
            (*((list *) v12398))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v12398);} 
      Result = list::alloc(2,_oid_(v12397),_oid_(v12398));
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * _equalsig_ask_list(list *v6224,list *v6225)
{ return (((tmatch_ask_list(v6224,v6225) == CTRUE) ? ((tmatch_ask_list(v6225,v6224) == CTRUE) ? CTRUE: CFALSE): CFALSE));} 

char * function_name_property_Optimize(property *v6216,list *v6212,OID v6224)
{ GC_BIND;
  { char *Result ;
    if (INHERIT(OWNER(v6224),Kernel._function))
     Result = string_I_function(OBJECT(ClaireFunction,v6224));
    else { int  v6214 = 0;
        int  v6213 = 0;
        module * v12479 = v6216->name->module_I;
        ClaireClass * v6203 = class_I_type(OBJECT(ClaireType,(*(v6212))[1]));
        char * v6218 = GC_STRING(append_string(GC_STRING(append_string(string_I_symbol(v6216->name),copy_string("_"))),string_I_symbol(v6203->name)));
        if ((Optimize.compiler->naming == 0) && 
            (v6216 != Core.main))
         v6218= GC_STRING(append_string(GC_STRING(append_string(string_I_symbol(v12479->name),copy_string("_"))),v6218));
        { ITERATE(v6218);
          for (START(v6216->restrictions); NEXT(v6218);)
          { if (v6203 == domain_I_restriction(OBJECT(restriction,v6218)))
             ++v6214;
            if (_equalsig_ask_list(v6212,OBJECT(restriction,v6218)->domain) == CTRUE)
             v6213= v6214;
            } 
          } 
        v6218= GC_STRING(((v6214 <= 1) ?
          v6218 :
          append_string(v6218,GC_STRING(string_I_integer (v6213))) ));
        Result = (((stable_ask_relation(v6216) == CTRUE) || 
            (v6216 == Core.main)) ?
          v6218 :
          append_string(GC_STRING(append_string(v6218,copy_string("_"))),string_I_symbol(ClEnv->module_I->name)) );
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  compile_lambda_string(char *v2164,lambda *v6212,OID v6213)
{ { OID Result = 0;
    { int  v6224 = Optimize.compiler->safety;
      lambda * v6225 = v6212;
      if (Kernel._method == OWNER(v6213))
       (Optimize.OPT->in_method = v6213);
      (Optimize.OPT->protection = CFALSE);
      (Optimize.OPT->allocation = CFALSE);
      if (Optimize.OPT->loop_index > 0)
       (Optimize.OPT->loop_index = 0);
      (Optimize.OPT->loop_gc = CFALSE);
      (Optimize.OPT->use_update = CFALSE);
      (Optimize.OPT->use_nth_equal = CFALSE);
      (Optimize.OPT->use_string_update = CFALSE);
      (Optimize.OPT->max_vars = 0);
      if (contain_ask_list(Optimize.OPT->unsure,v6213) == CTRUE)
       (Optimize.compiler->safety = 1);
      (*Optimize.make_c_function)(_oid_(v6212),
        _string_(v2164),
        v6213);
      (Optimize.OPT->in_method = CNULL);
      (Optimize.compiler->safety = v6224);
      Result = Kernel.ctrue;
      } 
    return (Result);} 
  } 

OID  c_code_Defarray_Optimize(Defarray *v2164)
{ GC_BIND;
  { OID Result = 0;
    { list * v6201 = GC_OBJECT(list,v2164->arg->args);
      OID  v10244 = get_symbol(extract_symbol_any((*(v6201))[1]));
      table * v10265;
      { ClaireObject *V_CC ;
        if (INHERIT(OWNER(v10244),Kernel._table))
         V_CC = OBJECT(table,v10244);
        else close_exception(((general_error *) (*Core._general_error)(_string_(copy_string("[internal] the table ~S is unknown")),
            _oid_(list::alloc(1,(*(v6201))[1])))));
          v10265= (table *) V_CC;} 
      OID  v6219 = GC_OID((*Kernel.domain)(v10244));
      OID  v6205;
      { { list * v6212 = GC_OBJECT(list,cdr_list(v6201));
          OID  v6202 = GC_OID(lexical_build_any(GC_OID(v2164->body),v6212,0));
          { ClaireBoolean * g0444I;
            { OID  v13028;
              { ITERATE(v12755);
                v13028= Kernel.cfalse;
                for (START(v6212); NEXT(v12755);)
                if (occurrence_any(v6202,OBJECT(Variable,v12755)) > 0)
                 { v13028 = Kernel.ctrue;
                  break;} 
                } 
              g0444I = boolean_I_any(v13028);
              } 
            
            if (g0444I == CTRUE) v6205 = _oid_(lambda_I_list(v6212,v6202));
              else v6205 = v2164->body;
            } 
          } 
        GC_OID(v6205);} 
      OID  v6204;
      { if (INHERIT(OWNER(v6205),Core._lambda))
         v6204 = CNULL;
        else v6204 = v2164->body;
          GC_OID(v6204);} 
      list * v6665;
      if (boolean_I_any(_oid_(OBJECT(ClaireRelation,v10244)->multivalued_ask)) == CTRUE)
       { OID v_bag;
        GC_ANY(v6665= list::empty(Kernel._any));
        { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.put);
            (v2072->args = list::alloc(3,_oid_(Kernel.multivalued_ask),
              _oid_(v10265),
              GC_OID(_oid_(OBJECT(ClaireRelation,v10244)->multivalued_ask))));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v_bag = _oid_(v2072);
            } 
          GC_OID(v_bag);} 
        ((list *) v6665)->addFast(v_bag);} 
      else v6665 = list::empty(Kernel._any);
        list * v6664;
      { OID v_bag;
        GC_ANY(v6664= list::empty(Kernel._any));
        { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.put);
            (v2072->args = list::alloc(3,_oid_(Kernel.range),
              _oid_(v10265),
              GC_OID((*Kernel.range)(v10244))));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v_bag = _oid_(v2072);
            } 
          GC_OID(v_bag);} 
        ((list *) v6664)->addFast(v_bag);
        { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.put);
            (v2072->args = list::alloc(3,_oid_(Kernel.params),
              _oid_(v10265),
              GC_OID((*Kernel.params)(v10244))));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v_bag = _oid_(v2072);
            } 
          GC_OID(v_bag);} 
        ((list *) v6664)->addFast(v_bag);
        { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.put);
            (v2072->args = list::alloc(3,_oid_(Kernel.domain),
              _oid_(v10265),
              v6219));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v_bag = _oid_(v2072);
            } 
          GC_OID(v_bag);} 
        ((list *) v6664)->addFast(v_bag);} 
      (OBJECT(Variable,(*(v6201))[2])->range = extract_type_any(GC_OID(_oid_(OBJECT(Variable,(*(v6201))[2])->range))));
      if (v6201->length == 2)
       { { { OID  v13989;
            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Kernel.put);
              { Call * v10566 = v2072; 
                list * v10567;
                { OID v_bag;
                  GC_ANY(v10567= list::empty(Kernel.emptySet));
                  ((list *) v10567)->addFast(_oid_(Kernel.graph));
                  ((list *) v10567)->addFast(_oid_(v10265));
                  if (INHERIT(OBJECT(ClaireObject,v6219)->isa,Core._Interval))
                   { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Core.make_copy_list);
                    (v2072->args = list::alloc(2,size_Interval(OBJECT(Interval,v6219)),v6204));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v_bag = _oid_(v2072);
                    } 
                  else { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Kernel.make_list);
                      (v2072->args = list::alloc(2,29,CNULL));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v_bag = _oid_(v2072);
                      } 
                    ((list *) v10567)->addFast(v_bag);} 
                (v10566->args = v10567);} 
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v13989 = _oid_(v2072);
              } 
            v6664 = v6664->addFast(v13989);
            } 
          GC_OBJECT(list,v6664);} 
        { { OID  v488;
            if (INHERIT(OWNER(v6205),Core._lambda))
             { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
              store_object(v2072,
                2,
                Kernel._object,
                (*(v6201))[2],
                CFALSE);
              (v2072->set_arg = v6219);
              { Iteration * v10590 = v2072; 
                OID  v10591;
                { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Kernel.nth_equal);
                  (v2072->args = list::alloc(3,_oid_(v10265),
                    (*(v6201))[2],
                    GC_OID(OBJECT(lambda,v6205)->body)));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v10591 = _oid_(v2072);
                  } 
                (v10590->arg = v10591);} 
              add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
              v488 = _oid_(v2072);
              } 
            else { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Kernel.put);
                (v2072->args = list::alloc(3,_oid_(Kernel.DEFAULT),
                  _oid_(v10265),
                  v6204));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v488 = _oid_(v2072);
                } 
              v6664 = v6664->addFast(v488);
            } 
          GC_OBJECT(list,v6664);} 
        } 
      else { ClaireType * v12615 = GC_OBJECT(ClaireType,extract_type_any(GC_OID(_oid_(OBJECT(Variable,(*(v6201))[3])->range))));
          (OBJECT(Variable,(*(v6201))[3])->range = v12615);
          { { OID  v7168;
              { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Kernel.put);
                { Call * v10593 = v2072; 
                  list * v10594;
                  { OID v_bag;
                    GC_ANY(v10594= list::empty(Kernel.emptySet));
                    ((list *) v10594)->addFast(_oid_(Kernel.graph));
                    ((list *) v10594)->addFast(_oid_(v10265));
                    { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v2072->selector = Core.make_copy_list);
                        { Call * v10595 = v2072; 
                          list * v10596;
                          { OID v_bag;
                            GC_ANY(v10596= list::empty(Kernel.emptySet));
                            ((list *) v10596)->addFast(OBJECT(table,v10244)->graph->length);
                            { if ((*Kernel.params)(v10244) == _oid_(Kernel._any))
                               v_bag = CNULL;
                              else v_bag = (*Kernel.DEFAULT)(v10244);
                                GC_OID(v_bag);} 
                            ((list *) v10596)->addFast(v_bag);} 
                          (v10595->args = v10596);} 
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                        v_bag = _oid_(v2072);
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v10594)->addFast(v_bag);} 
                  (v10593->args = v10594);} 
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v7168 = _oid_(v2072);
                } 
              v6664 = v6664->addFast(v7168);
              } 
            GC_OBJECT(list,v6664);} 
          { { OID  v11973;
              if (INHERIT(OWNER(v6205),Core._lambda))
               { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                store_object(v2072,
                  2,
                  Kernel._object,
                  (*(v6201))[2],
                  CFALSE);
                (v2072->set_arg = (*(OBJECT(bag,v6219)))[1]);
                { Iteration * v10598 = v2072; 
                  OID  v10599;
                  { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                    store_object(v2072,
                      2,
                      Kernel._object,
                      (*(v6201))[3],
                      CFALSE);
                    (v2072->set_arg = _oid_(v12615));
                    { Iteration * v10621 = v2072; 
                      OID  v10622;
                      { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v2072->selector = Kernel.nth_equal);
                        (v2072->args = list::alloc(4,_oid_(v10265),
                          (*(v6201))[2],
                          (*(v6201))[3],
                          GC_OID(OBJECT(lambda,v6205)->body)));
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                        v10622 = _oid_(v2072);
                        } 
                      (v10621->arg = v10622);} 
                    add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                    v10599 = _oid_(v2072);
                    } 
                  (v10598->arg = v10599);} 
                add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                v11973 = _oid_(v2072);
                } 
              else { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Kernel.put);
                  (v2072->args = list::alloc(3,_oid_(Kernel.DEFAULT),
                    _oid_(v10265),
                    v6204));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v11973 = _oid_(v2072);
                  } 
                v6664 = v6664->addFast(v11973);
              } 
            GC_OBJECT(list,v6664);} 
          } 
        Optimize.OPT->objects->addFast(v10244);
      (*Optimize.c_register)(v10244);
      { OID  v4191;
        { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
          { Do * v10624 = v2072; 
            list * v10625;
            { OID  v7074;
              { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Optimize.object_I);
                (v2072->args = list::alloc(2,GC_OID((*Kernel.name)(v10244)),_oid_(Kernel._table)));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v7074 = _oid_(v2072);
                } 
              v10625 = cons_any(v7074,add_star_list(v6665,v6664));
              } 
            (v10624->args = v10625);} 
          add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
          v4191 = _oid_(v2072);
          } 
        Result = (*Optimize.c_code)(v4191,
          _oid_(Kernel._any));
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

void  compute_if_write_inverse_relation2(ClaireRelation *v6186)
{ GC_BIND;
  { Variable * v6224;
    { { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
        (v2072->pname = symbol_I_string2(copy_string("XX")));
        (v2072->range = v6186->domain);
        add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
        v6224 = v2072;
        } 
      GC_OBJECT(Variable,v6224);} 
    Variable * v6225;
    { { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
        (v2072->pname = symbol_I_string2(copy_string("YY")));
        (v2072->range = ((multi_ask_any(_oid_(v6186)) == CTRUE) ?
          member_type(v6186->range) :
          v6186->range ));
        add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
        v6225 = v2072;
        } 
      GC_OBJECT(Variable,v6225);} 
    Variable * v6226;
    { { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
        (v2072->pname = symbol_I_string2(copy_string("ZZ")));
        (v2072->range = v6186->range);
        add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
        v6226 = v2072;
        } 
      GC_OBJECT(Variable,v6226);} 
    list * v12397 = list::empty(Kernel._any);
    if (multi_ask_any(_oid_(v6186)) == CTRUE)
     { v12397= list::alloc(Kernel._any,1,GC_OID((INHERIT(v6186->isa,Kernel._property) ?  Produce_put_property2((property *) OBJECT(property,_oid_(v6186)),OBJECT(Variable,_oid_(v6224)),_oid_(v6225)) :   Produce_put_table2((table *) OBJECT(table,_oid_(v6186)),OBJECT(Variable,_oid_(v6224)),_oid_(v6225)))));
      if (((v6186->inverse == (NULL)) ? CTRUE : CFALSE) != CTRUE)
       v12397= GC_OBJECT(list,v12397->addFast((INHERIT(v6186->inverse->isa,Kernel._property) ?  Produce_put_property2((property *) OBJECT(property,_oid_(v6186->inverse)),OBJECT(Variable,_oid_(v6225)),_oid_(v6224)) :   Produce_put_table2((table *) OBJECT(table,_oid_(v6186->inverse)),OBJECT(Variable,_oid_(v6225)),_oid_(v6224)))));
      { ClaireRelation * v10627 = v6186; 
        OID  v10628;
        { lambda * v12256;{ OID  v10918;
            { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
              { If * v10654 = v2072; 
                OID  v10655;
                { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Core.NOT);
                  { Call * v10656 = v2072; 
                    list * v10658;
                    { OID v_bag;
                      GC_ANY(v10658= list::empty(Kernel.emptySet));
                      { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v2072->selector = Kernel._Z);
                          (v2072->args = list::alloc(2,_oid_(v6225),GC_OID(Produce_get_relation2(v6186,v6224))));
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                          v_bag = _oid_(v2072);
                          } 
                        GC_OID(v_bag);} 
                      ((list *) v10658)->addFast(v_bag);} 
                    (v10656->args = v10658);} 
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v10655 = _oid_(v2072);
                  } 
                (v10654->test = v10655);} 
              { If * v10659 = v2072; 
                OID  v10660;
                { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                  (v2072->args = v12397);
                  add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                  v10660 = _oid_(v2072);
                  } 
                (v10659->arg = v10660);} 
              add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
              (v2072->other = Kernel.cfalse);
              v10918 = _oid_(v2072);
              } 
            v12256 = lambda_I_list(list::alloc(2,_oid_(v6224),_oid_(v6225)),v10918);
            } 
          
          v10628=_oid_(v12256);} 
        (v10627->if_write = v10628);} 
      } 
    else { v12397= list::alloc(Kernel._any,1,GC_OID((INHERIT(v6186->isa,Kernel._property) ?  Produce_put_property2((property *) OBJECT(property,_oid_(v6186)),OBJECT(Variable,_oid_(v6224)),_oid_(v6225)) :   Produce_put_table2((table *) OBJECT(table,_oid_(v6186)),OBJECT(Variable,_oid_(v6224)),_oid_(v6225)))));
        if (((v6186->inverse == (NULL)) ? CTRUE : CFALSE) != CTRUE)
         { { { OID  v5058;
              { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                { If * v10662 = v2072; 
                  OID  v10663;
                  { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Core.known_ask);
                    (v2072->args = list::alloc(1,_oid_(v6226)));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v10663 = _oid_(v2072);
                    } 
                  (v10662->test = v10663);} 
                (v2072->arg = (INHERIT(v6186->inverse->isa,Kernel._property) ?  Produce_remove_property2((property *) OBJECT(property,_oid_(v6186->inverse)),OBJECT(Variable,_oid_(v6226)),_oid_(v6224)) :   Produce_remove_table2((table *) OBJECT(table,_oid_(v6186->inverse)),OBJECT(Variable,_oid_(v6226)),_oid_(v6224))));
                add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                (v2072->other = Kernel.cfalse);
                v5058 = _oid_(v2072);
                } 
              v12397 = v12397->addFast(v5058);
              } 
            GC_OBJECT(list,v12397);} 
          v12397= GC_OBJECT(list,v12397->addFast((INHERIT(v6186->inverse->isa,Kernel._property) ?  Produce_put_property2((property *) OBJECT(property,_oid_(v6186->inverse)),OBJECT(Variable,_oid_(v6225)),_oid_(v6224)) :   Produce_put_table2((table *) OBJECT(table,_oid_(v6186->inverse)),OBJECT(Variable,_oid_(v6225)),_oid_(v6224)))));
          } 
        { ClaireRelation * v10664 = v6186; 
          OID  v10683;
          { lambda * v12311;{ OID  v14621;
              { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
                (v2072->var = v6226);
                (v2072->value = Produce_get_relation2(v6186,v6224));
                { Let * v10686 = v2072; 
                  OID  v10687;
                  { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                    { If * v10688 = v2072; 
                      OID  v10689;
                      { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v2072->selector = Core._I_equal);
                        (v2072->args = list::alloc(2,_oid_(v6225),_oid_(v6226)));
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                        v10689 = _oid_(v2072);
                        } 
                      (v10688->test = v10689);} 
                    { If * v10691 = v2072; 
                      OID  v10692;
                      { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                        (v2072->args = v12397);
                        add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                        v10692 = _oid_(v2072);
                        } 
                      (v10691->arg = v10692);} 
                    add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                    (v2072->other = Kernel.cfalse);
                    v10687 = _oid_(v2072);
                    } 
                  (v10686->arg = v10687);} 
                add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
                v14621 = _oid_(v2072);
                } 
              v12311 = lambda_I_list(list::alloc(2,_oid_(v6224),_oid_(v6225)),v14621);
              } 
            
            v10683=_oid_(v12311);} 
          (v10664->if_write = v10683);} 
        } 
      { char * v8882 = GC_STRING(append_string(string_I_symbol(v6186->name),copy_string("_write")));
      compile_lambda_string(v8882,GC_OBJECT(lambda,OBJECT(lambda,v6186->if_write)),_oid_(Kernel._void));
      } 
    } 
  GC_UNBIND;} 

OID  compute_set_write_relation2(ClaireRelation *v6186)
{ GC_BIND;
  { OID Result = 0;
    { Variable * v6224;
      { { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
          (v2072->pname = symbol_I_string2(copy_string("XX")));
          (v2072->range = v6186->domain);
          add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
          v6224 = v2072;
          } 
        GC_OBJECT(Variable,v6224);} 
      Variable * v6225;
      { { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
          (v2072->pname = symbol_I_string2(copy_string("YY")));
          (v2072->range = Kernel._bag);
          add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
          v6225 = v2072;
          } 
        GC_OBJECT(Variable,v6225);} 
      Variable * v6226;
      { { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
          (v2072->pname = symbol_I_string2(copy_string("ZZ")));
          (v2072->range = member_type(v6186->range));
          add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
          v6226 = v2072;
          } 
        GC_OBJECT(Variable,v6226);} 
      list * v12397 = list::empty(Kernel._any);
      tformat_string(copy_string("compute set_write for ~S \n"),0,list::alloc(1,_oid_(v6186)));
      if (((v6186->inverse == (NULL)) ? CTRUE : CFALSE) != CTRUE)
       { { OID  v4964;
          { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
            (v2072->var = v6226);
            (v2072->set_arg = Produce_get_relation2(v6186,v6224));
            (v2072->arg = (INHERIT(v6186->inverse->isa,Kernel._property) ?  Produce_remove_property2((property *) OBJECT(property,_oid_(v6186->inverse)),OBJECT(Variable,_oid_(v6226)),_oid_(v6224)) :   Produce_remove_table2((table *) OBJECT(table,_oid_(v6186->inverse)),OBJECT(Variable,_oid_(v6226)),_oid_(v6224))));
            add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
            v4964 = _oid_(v2072);
            } 
          v12397 = v12397->addFast(v4964);
          } 
        GC_OBJECT(list,v12397);} 
      v12397= GC_OBJECT(list,v12397->addFast(Produce_erase_property2(((property *) v6186),v6224)));
      { { OID  v9732;
          { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
            (v2072->var = v6226);
            (v2072->set_arg = _oid_(v6225));
            (v2072->arg = (INHERIT(v6186->isa,Kernel._property) ?  Produce_put_property2((property *) OBJECT(property,_oid_(v6186)),OBJECT(Variable,_oid_(v6224)),_oid_(v6226)) :   Produce_put_table2((table *) OBJECT(table,_oid_(v6186)),OBJECT(Variable,_oid_(v6224)),_oid_(v6226))));
            add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
            v9732 = _oid_(v2072);
            } 
          v12397 = v12397->addFast(v9732);
          } 
        GC_OBJECT(list,v12397);} 
      { char * v8882 = GC_STRING(append_string(string_I_symbol(v6186->name),copy_string("_set_write")));
        { lambda * v10684;
          { { OID  v11644;
              { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                (v2072->args = v12397);
                add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                v11644 = _oid_(v2072);
                } 
              v10684 = lambda_I_list(list::alloc(2,_oid_(v6224),_oid_(v6225)),v11644);
              } 
            GC_OBJECT(lambda,v10684);} 
          Result = compile_lambda_string(v8882,v10684,_oid_(Kernel._void));
          } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Produce_put_property2(property *v6218,Variable *v6224,OID v6225)
{ GC_BIND;
  { OID Result = 0;
    { list * v6212 = list::empty(Kernel._any);
      { OID gc_local;
        ITERATE(v12835);
        for (START(v6218->restrictions); NEXT(v12835);)
        { GC_LOOP;
          if ((Kernel._slot == OBJECT(ClaireObject,v12835)->isa) && 
              (boolean_I_any(_oid_(_exp_type(GC_OBJECT(ClaireType,ptype_type(v6224->range)),domain_I_restriction(OBJECT(restriction,v12835))))) == CTRUE))
           { list * v12605;
            { OID v_bag;
              GC_ANY(v12605= list::empty(Kernel.emptySet));
              ((list *) v12605)->addFast(_oid_(domain_I_restriction(OBJECT(restriction,v12835))));
              if (boolean_I_any(_oid_(v6218->multivalued_ask)) == CTRUE)
               { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Kernel.add_I);
                { Call * v10718 = v2072; 
                  list * v10719;
                  { OID v_bag;
                    GC_ANY(v10719= list::empty(Kernel.emptySet));
                    { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v2072->selector = v6218);
                        { Call * v10720 = v2072; 
                          list * v10721;
                          { OID v_bag;
                            GC_ANY(v10721= list::empty(Kernel.emptySet));
                            { { Cast * v2072 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                                (v2072->arg = _oid_(v6224));
                                (v2072->set_arg = domain_I_restriction(OBJECT(restriction,v12835)));
                                add_I_property(Kernel.instances,Language._Cast,11,_oid_(v2072));
                                v_bag = _oid_(v2072);
                                } 
                              GC_OID(v_bag);} 
                            ((list *) v10721)->addFast(v_bag);} 
                          (v10720->args = v10721);} 
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                        v_bag = _oid_(v2072);
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v10719)->addFast(v_bag);
                    ((list *) v10719)->addFast(v6225);} 
                  (v10718->args = v10719);} 
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v_bag = _oid_(v2072);
                } 
              else { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Kernel.put);
                  { Call * v10722 = v2072; 
                    list * v10723;
                    { OID v_bag;
                      GC_ANY(v10723= list::empty(Kernel.emptySet));
                      ((list *) v10723)->addFast(_oid_(v6218));
                      { { Cast * v2072 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                          (v2072->arg = _oid_(v6224));
                          (v2072->set_arg = domain_I_restriction(OBJECT(restriction,v12835)));
                          add_I_property(Kernel.instances,Language._Cast,11,_oid_(v2072));
                          v_bag = _oid_(v2072);
                          } 
                        GC_OID(v_bag);} 
                      ((list *) v10723)->addFast(v_bag);
                      ((list *) v10723)->addFast(v6225);} 
                    (v10722->args = v10723);} 
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v_bag = _oid_(v2072);
                  } 
                ((list *) v12605)->addFast(v_bag);} 
            v6212 = add_star_list(v6212,v12605);
            } 
          GC_UNLOOP;} 
        } 
      if (v6212->length == 2)
       Result = (*(v6212))[2];
      else { Case * v2072 = ((Case *) GC_OBJECT(Case,new_object_class(Language._Case)));
          (v2072->var = _oid_(v6224));
          (v2072->args = v6212);
          add_I_property(Kernel.instances,Language._Case,11,_oid_(v2072));
          Result = _oid_(v2072);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  Produce_erase_property2(property *v6218,Variable *v6224)
{ GC_BIND;
  { OID Result = 0;
    { list * v6212 = list::empty(Kernel._any);
      bag * v2297;
      if (v6218->multivalued_ask == Kernel._list)
       v2297 = list::empty(Kernel._any);
      else v2297 = set::empty(Kernel._any);
        cast_I_bag(v2297,member_type(v6218->range));
      { OID gc_local;
        ITERATE(v12835);
        for (START(v6218->restrictions); NEXT(v12835);)
        { GC_LOOP;
          if ((Kernel._slot == OBJECT(ClaireObject,v12835)->isa) && 
              (boolean_I_any(_oid_(_exp_type(GC_OBJECT(ClaireType,ptype_type(v6224->range)),domain_I_restriction(OBJECT(restriction,v12835))))) == CTRUE))
           { list * v9764;
            { OID v_bag;
              GC_ANY(v9764= list::empty(Kernel.emptySet));
              ((list *) v9764)->addFast(_oid_(domain_I_restriction(OBJECT(restriction,v12835))));
              { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Kernel.put);
                  { Call * v11397 = v2072; 
                    list * v11398;
                    { OID v_bag;
                      GC_ANY(v11398= list::empty(Kernel.emptySet));
                      ((list *) v11398)->addFast(_oid_(v6218));
                      { { Cast * v2072 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                          (v2072->arg = _oid_(v6224));
                          (v2072->set_arg = domain_I_restriction(OBJECT(restriction,v12835)));
                          add_I_property(Kernel.instances,Language._Cast,11,_oid_(v2072));
                          v_bag = _oid_(v2072);
                          } 
                        GC_OID(v_bag);} 
                      ((list *) v11398)->addFast(v_bag);
                      { if (boolean_I_any(_oid_(v6218->multivalued_ask)) == CTRUE)
                         v_bag = _oid_(v2297);
                        else v_bag = OBJECT(slot,v12835)->DEFAULT;
                          GC_OID(v_bag);} 
                      ((list *) v11398)->addFast(v_bag);} 
                    (v11397->args = v11398);} 
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v_bag = _oid_(v2072);
                  } 
                GC_OID(v_bag);} 
              ((list *) v9764)->addFast(v_bag);} 
            v6212 = add_star_list(v6212,v9764);
            } 
          GC_UNLOOP;} 
        } 
      if (v6212->length == 2)
       Result = (*(v6212))[2];
      else { Case * v2072 = ((Case *) GC_OBJECT(Case,new_object_class(Language._Case)));
          (v2072->var = _oid_(v6224));
          (v2072->args = v6212);
          add_I_property(Kernel.instances,Language._Case,11,_oid_(v2072));
          Result = _oid_(v2072);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  Produce_put_table2(table *v6218,Variable *v6224,OID v6225)
{ GC_BIND;
  { OID Result = 0;
    { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v2072->selector = Kernel.put);
      { Call * v11399 = v2072; 
        list * v11400;
        { OID v_bag;
          GC_ANY(v11400= list::empty(Kernel.emptySet));
          ((list *) v11400)->addFast(_oid_(v6218));
          ((list *) v11400)->addFast(_oid_(v6224));
          if (boolean_I_any(_oid_(v6218->multivalued_ask)) == CTRUE)
           { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.add);
            (v2072->args = list::alloc(2,_oid_(list::alloc(2,_oid_(Kernel.nth),_oid_(list::alloc(2,_oid_(v6218),_oid_(v6224))))),v6225));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v_bag = _oid_(v2072);
            } 
          else v_bag = v6225;
            ((list *) v11400)->addFast(v_bag);} 
        (v11399->args = v11400);} 
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Produce_get_relation2(ClaireRelation *v6218,Variable *v6224)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(v6218->isa,Kernel._table))
     { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v2072->selector = Kernel.nth);
      (v2072->args = list::alloc(2,_oid_(v6218),_oid_(v6224)));
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    else if (INHERIT(v6218->isa,Kernel._property))
     { list * v6212 = list::empty(Kernel._any);
      { OID gc_local;
        ITERATE(v12835);
        for (START(CLREAD(property,v6218,restrictions)); NEXT(v12835);)
        { GC_LOOP;
          if ((Kernel._slot == OBJECT(ClaireObject,v12835)->isa) && 
              (boolean_I_any(_oid_(_exp_type(GC_OBJECT(ClaireType,ptype_type(v6224->range)),domain_I_restriction(OBJECT(restriction,v12835))))) == CTRUE))
           { list * v14569;
            { OID v_bag;
              GC_ANY(v14569= list::empty(Kernel.emptySet));
              ((list *) v14569)->addFast(_oid_(domain_I_restriction(OBJECT(restriction,v12835))));
              { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = ((property *) v6218));
                  { Call * v11402 = v2072; 
                    list * v11403;
                    { OID v_bag;
                      GC_ANY(v11403= list::empty(Kernel.emptySet));
                      { { Cast * v2072 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                          (v2072->arg = _oid_(v6224));
                          (v2072->set_arg = domain_I_restriction(OBJECT(restriction,v12835)));
                          add_I_property(Kernel.instances,Language._Cast,11,_oid_(v2072));
                          v_bag = _oid_(v2072);
                          } 
                        GC_OID(v_bag);} 
                      ((list *) v11403)->addFast(v_bag);} 
                    (v11402->args = v11403);} 
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v_bag = _oid_(v2072);
                  } 
                GC_OID(v_bag);} 
              ((list *) v14569)->addFast(v_bag);} 
            v6212 = add_star_list(v6212,v14569);
            } 
          GC_UNLOOP;} 
        } 
      if (v6212->length == 2)
       Result = (*(v6212))[2];
      else { Case * v2072 = ((Case *) GC_OBJECT(Case,new_object_class(Language._Case)));
          (v2072->var = _oid_(v6224));
          (v2072->args = v6212);
          add_I_property(Kernel.instances,Language._Case,11,_oid_(v2072));
          Result = _oid_(v2072);
          } 
        } 
    else Result = Kernel.cfalse;
      GC_UNBIND; return (Result);} 
  } 

OID  Produce_remove_property2(property *v6218,Variable *v6224,OID v6225)
{ GC_BIND;
  { OID Result = 0;
    { list * v6212 = list::empty(Kernel._any);
      { OID gc_local;
        ITERATE(v12835);
        for (START(v6218->restrictions); NEXT(v12835);)
        { GC_LOOP;
          if (Kernel._slot == OBJECT(ClaireObject,v12835)->isa)
           { list * v1068;
            { OID v_bag;
              GC_ANY(v1068= list::empty(Kernel.emptySet));
              ((list *) v1068)->addFast(_oid_(domain_I_restriction(OBJECT(restriction,v12835))));
              if (boolean_I_any(_oid_(v6218->multivalued_ask)) == CTRUE)
               { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Kernel._delete);
                { Call * v11405 = v2072; 
                  list * v11428;
                  { OID v_bag;
                    GC_ANY(v11428= list::empty(Kernel.emptySet));
                    { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v2072->selector = v6218);
                        (v2072->args = list::alloc(1,_oid_(v6224)));
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                        v_bag = _oid_(v2072);
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v11428)->addFast(v_bag);
                    ((list *) v11428)->addFast(v6225);} 
                  (v11405->args = v11428);} 
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v_bag = _oid_(v2072);
                } 
              else { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Kernel.put);
                  (v2072->args = list::alloc(3,_oid_(v6218),
                    _oid_(v6224),
                    CNULL));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v_bag = _oid_(v2072);
                  } 
                ((list *) v1068)->addFast(v_bag);} 
            v6212 = add_star_list(v6212,v1068);
            } 
          GC_UNLOOP;} 
        } 
      if (v6212->length == 2)
       Result = (*(v6212))[2];
      else { Case * v2072 = ((Case *) GC_OBJECT(Case,new_object_class(Language._Case)));
          (v2072->var = _oid_(v6224));
          (v2072->args = v6212);
          add_I_property(Kernel.instances,Language._Case,11,_oid_(v2072));
          Result = _oid_(v2072);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  Produce_remove_table2(table *v6218,Variable *v6224,OID v6225)
{ GC_BIND;
  { OID Result = 0;
    { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v2072->selector = Kernel.put);
      { Call * v11429 = v2072; 
        list * v11430;
        { OID v_bag;
          GC_ANY(v11430= list::empty(Kernel.emptySet));
          ((list *) v11430)->addFast(_oid_(v6218));
          ((list *) v11430)->addFast(_oid_(v6224));
          if (boolean_I_any(_oid_(v6218->multivalued_ask)) == CTRUE)
           { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel._delete);
            (v2072->args = list::alloc(2,_oid_(list::alloc(2,_oid_(Kernel.nth),_oid_(list::alloc(2,_oid_(v6218),_oid_(v6224))))),v6225));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v_bag = _oid_(v2072);
            } 
          else v_bag = CNULL;
            ((list *) v11430)->addFast(v_bag);} 
        (v11429->args = v11430);} 
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

void  Tighten_relation2(ClaireRelation *v6218)
{ GC_RESERVE(6);  // v3.0.55 optim !
  if (INHERIT(v6218->isa,Kernel._property))
   { ClaireType * v12107 = set::empty();
    ClaireType * v12121 = set::empty();
    { OID gc_local;
      ITERATE(v6219);
      for (START(CLREAD(property,v6218,restrictions)); NEXT(v6219);)
      { GC_LOOP;
        if (Kernel._slot == OBJECT(ClaireObject,v6219)->isa)
         { GC__ANY(v12107 = U_type(v12107,domain_I_restriction(OBJECT(restriction,v6219))), 3);
          GC__ANY(v12121 = U_type(v12121,GC_OBJECT(ClaireType,((multi_ask_any(_oid_(v6218)) == CTRUE) ?
            member_type(OBJECT(restriction,v6219)->range) :
            OBJECT(restriction,v6219)->range ))), 4);
          } 
        GC_UNLOOP;} 
      } 
    (v6218->open = 1);
    (v6218->domain = class_I_type(v12107));
    (v6218->range = ((v6218->multivalued_ask == Kernel._list) ?
      param_I_class(Kernel._list,class_I_type(v12121)) :
      ((v6218->multivalued_ask == Kernel._set) ?
        param_I_class(Kernel._set,class_I_type(v12121)) :
        v12121 ) ));
    ;} 
  GC_UNBIND;} 

void  lexical_num_any2(OID v2164,int v6214)
{ GC_BIND;
  if (INHERIT(OWNER(v2164),Language._Call))
   lexical_num_any2(GC_OID(_oid_(OBJECT(Call,v2164)->args)),v6214);
  else if (INHERIT(OWNER(v2164),Language._Instruction))
   { ClaireClass * v8375 = OBJECT(ClaireObject,v2164)->isa;
    if (contain_ask_set(Language._Instruction_with_var->descendents,_oid_(v8375)) == CTRUE)
     { put_property2(Kernel.index,GC_OBJECT(ClaireObject,OBJECT(ClaireObject,(*Language.var)(v2164))),v6214);
      ++v6214;
      if (v6214 > Language._starvariable_index_star->value)
       (Language._starvariable_index_star->value= v6214);
      } 
    { ITERATE(v6219);
      for (START(v8375->slots); NEXT(v6219);)
      lexical_num_any2(get_slot(OBJECT(slot,v6219),OBJECT(ClaireObject,v2164)),v6214);
      } 
    } 
  else if (INHERIT(OWNER(v2164),Kernel._bag))
   { ITERATE(v6224);
    for (START(OBJECT(bag,v2164)); NEXT(v6224);)
    lexical_num_any2(v6224,v6214);
    } 
  else ;GC_UNBIND;} 

ClaireType * c_type_Defrule2_Optimize(Defrule *v2164)
{ return (Kernel._any);} 

OID  c_code_Defrule_Optimize(Defrule *v2164,ClaireClass *v6219)
{ GC_RESERVE(11);  // v3.0.55 optim !
  { OID Result = 0;
    { OID  v12651 = get_symbol(v2164->ident);
      list * v6212 = list::empty(Kernel._any);
      tformat_string(copy_string("compile a rule ~S \n"),0,list::alloc(1,v12651));
      { OID gc_local;
        ITERATE(v6218);
        bag *v6218_support;
        v6218_support = GC_OBJECT(set,OBJECT(bag,nth_table1(Language.relations,v12651)));
        for (START(v6218_support); NEXT(v6218);)
        if (eventMethod_ask_relation2(OBJECT(ClaireRelation,v6218)) != CTRUE)
         Tighten_relation2(OBJECT(ClaireRelation,v6218));
        } 
      { OID gc_local;
        ITERATE(v6218);
        bag *v6218_support;
        v6218_support = GC_OBJECT(set,OBJECT(bag,nth_table1(Language.relations,v12651)));
        for (START(v6218_support); NEXT(v6218);)
        { GC_LOOP;
          { if ((*Kernel.open)(v6218) < 2)
             { OID  v9673;
              { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Kernel.FINAL);
                (v2072->args = list::alloc(1,v6218));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v9673 = _oid_(v2072);
                } 
              v6212 = v6212->addFast(v9673);
              } 
            compile_if_write_relation(OBJECT(ClaireRelation,v6218));
            { OID  v8882 = GC_OID((*Kernel._7_plus)(GC_OID((*Kernel.name)(v6218)),
                _string_(copy_string("_write"))));
              char * v6219 = string_I_symbol(OBJECT(symbol,v8882));
              OID  v12446 = GC_OID((*Kernel.if_write)(v6218));
              compile_lambda_string(v6219,OBJECT(lambda,v12446),_oid_(Kernel._void));
              { OID  v10631;
                { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Kernel.put);
                  (v2072->args = list::alloc(3,Optimize.if_write->value,
                    v6218,
                    _oid_(make_function_string(v6219))));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v10631 = _oid_(v2072);
                  } 
                v6212->addFast(v10631);
                } 
              } 
            } 
          GC_UNLOOP;} 
        } 
      { OID gc_local;
        ITERATE(v6218);
        bag *v6218_support;
        v6218_support = GC_OBJECT(set,OBJECT(bag,nth_table1(Language.relations,v12651)));
        for (START(v6218_support); NEXT(v6218);)
        if (eventMethod_ask_relation2(OBJECT(ClaireRelation,v6218)) == CTRUE)
         v6212= v6212->addFast(compileEventMethod_property(OBJECT(property,v6218)));
        } 
      { OID  v11592;
        { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
          (v2072->args = v6212);
          add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
          v11592 = _oid_(v2072);
          } 
        Result = (*Optimize.c_code)(v11592,
          _oid_(v6219));
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

void  compile_if_write_relation(ClaireRelation *v6186)
{ GC_BIND;
  { OID  v6212 = GC_OID(nth_table1(Language.demons,_oid_(v6186)));
    list * v6243 = GC_OBJECT(list,OBJECT(Language_demon,(*(OBJECT(bag,v6212)))[1])->formula->vars);
    list * v12397 = list::alloc(Kernel._any,1,GC_OID((*Optimize.Produce_put)(_oid_(v6186),
      (*(v6243))[1],
      (*(v6243))[2])));
    list * v12398;
    { { bag *v_list; OID v_val;
        OID v6224,CLcount;
        v_list = OBJECT(bag,v6212);
         v12398 = v_list->clone(Kernel._any);
        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
        { v6224 = (*(v_list))[CLcount];
          v_val = substitution_any(GC_OID(substitution_any(GC_OID(substitution_any(GC_OID(OBJECT(Language_demon,v6224)->formula->body),GC_OBJECT(Variable,OBJECT(Variable,(*(OBJECT(Language_demon,v6224)->formula->vars))[3])),(*(v6243))[3])),GC_OBJECT(Variable,OBJECT(Variable,(*(OBJECT(Language_demon,v6224)->formula->vars))[1])),(*(v6243))[1])),GC_OBJECT(Variable,OBJECT(Variable,(*(OBJECT(Language_demon,v6224)->formula->vars))[2])),(*(v6243))[2]);
          
          (*((list *) v12398))[CLcount] = v_val;} 
        } 
      GC_OBJECT(list,v12398);} 
    put_property2(Kernel.range,OBJECT(ClaireObject,(*(v6243))[1]),_oid_(v6186->domain));
    put_property2(Kernel.range,OBJECT(ClaireObject,(*(v6243))[2]),_oid_(v6186->range));
    { OID gc_local;
      ITERATE(v6222);
      for (START(v6243); NEXT(v6222);)
      { GC_LOOP;
        put_property2(Kernel.range,OBJECT(ClaireObject,v6222),_oid_(class_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.range)(v6222))))));
        GC_UNLOOP;} 
      } 
    if ((INHERIT(OWNER((*(v12398))[1]),Language._If)) && 
        (eventMethod_ask_relation2(v6186) != CTRUE))
     { if (INHERIT(OWNER(OBJECT(If,(*(v12398))[1])->test),Language._And))
       { If * v11434 = OBJECT(If,(*(v12398))[1]); 
        OID  v11435;
        { And * v2072 = ((And *) GC_OBJECT(And,new_object_class(Language._And)));
          (v2072->args = cdr_list(OBJECT(list,(*Core.args)(GC_OID(OBJECT(If,(*(v12398))[1])->test)))));
          add_I_property(Kernel.instances,Language._And,11,_oid_(v2072));
          v11435 = _oid_(v2072);
          } 
        (v11434->test = v11435);} 
      else ((*(v12398))[1]=OBJECT(If,(*(v12398))[1])->arg);
        } 
    if (((v6186->inverse == (NULL)) ? CTRUE : CFALSE) != CTRUE)
     { if (multi_ask_any(_oid_(v6186)) != CTRUE)
       v12397= v12397->addFast((*Optimize.Produce_remove)(_oid_(v6186->inverse),
        (*(v6243))[3],
        (*(v6243))[1]));
      v12397= v12397->addFast((*Optimize.Produce_put)(_oid_(v6186->inverse),
        (*(v6243))[2],
        (*(v6243))[1]));
      } 
    { ClaireRelation * v11436 = v6186; 
      OID  v11437;
      { lambda * v13085;{ OID  v4771;
          if (eventMethod_ask_relation2(v6186) == CTRUE)
           { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
            (v2072->args = v12398);
            add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
            v4771 = _oid_(v2072);
            } 
          else if (multi_ask_any(_oid_(v6186)) == CTRUE)
           { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
            { If * v11460 = v2072; 
              OID  v11461;
              { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Core.NOT);
                { Call * v11462 = v2072; 
                  list * v11463;
                  { OID v_bag;
                    GC_ANY(v11463= list::empty(Kernel.emptySet));
                    { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v2072->selector = Kernel._Z);
                        (v2072->args = list::alloc(2,(*(v6243))[2],GC_OID(_oid_(readCall_relation(v6186,(*(v6243))[1])))));
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                        v_bag = _oid_(v2072);
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v11463)->addFast(v_bag);} 
                  (v11462->args = v11463);} 
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v11461 = _oid_(v2072);
                } 
              (v11460->test = v11461);} 
            { If * v11464 = v2072; 
              OID  v11465;
              { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                (v2072->args = append_list(v12397,v12398));
                add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                v11465 = _oid_(v2072);
                } 
              (v11464->arg = v11465);} 
            add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
            (v2072->other = Kernel.cfalse);
            v4771 = _oid_(v2072);
            } 
          else { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
              store_object(v2072,
                2,
                Kernel._object,
                (*(v6243))[3],
                CFALSE);
              (v2072->value = _oid_(readCall_relation(v6186,(*(v6243))[1])));
              { Let * v11466 = v2072; 
                OID  v11467;
                { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                  { If * v11489 = v2072; 
                    OID  v11490;
                    { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Core._I_equal);
                      (v2072->args = list::alloc(2,(*(v6243))[2],(*(v6243))[3]));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v11490 = _oid_(v2072);
                      } 
                    (v11489->test = v11490);} 
                  { If * v11491 = v2072; 
                    OID  v11492;
                    { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                      (v2072->args = append_list(v12397,v12398));
                      add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                      v11492 = _oid_(v2072);
                      } 
                    (v11491->arg = v11492);} 
                  add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                  (v2072->other = Kernel.cfalse);
                  v11467 = _oid_(v2072);
                  } 
                (v11466->arg = v11467);} 
              add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
              v4771 = _oid_(v2072);
              } 
            v13085 = lambda_I_list(GC_OBJECT(list,list::alloc(2,(*(v6243))[1],(*(v6243))[2])),v4771);
          } 
        
        v11437=_oid_(v13085);} 
      (v11436->if_write = v11437);} 
    } 
  GC_UNBIND;} 

OID  compileEventMethod_property(property *v6216)
{ GC_BIND;
  { OID Result = 0;
    { method * v6213 = OBJECT(method,(*(v6216->restrictions))[1]);
      char * v12507 = GC_STRING(append_string(string_I_symbol(v6216->name),copy_string("_write")));
      Result = add_method_I_method(v6213,
        list::alloc(2,_oid_(v6216->domain),_oid_(v6216->range)),
        _oid_(Kernel._void),
        0,
        make_function_string(v12507));
      } 
    GC_UNBIND; return (Result);} 
  } 

