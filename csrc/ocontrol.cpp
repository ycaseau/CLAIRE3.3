/***** CLAIRE Compilation of file c:\claire\v3.3\src\compile\ocontrol.cl 
         [version 3.3.34 / safety 5] Sun Mar 07 10:46:38 2004 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
ClaireType * c_type_Assign_Optimize(Assign *v9268)
{ GC_BIND;
  { ClaireType *Result ;
    Result = OBJECT(ClaireType,(*Optimize.c_type)(v9268->arg));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Assign_Optimize(Assign *v9268)
{ GC_BIND;
  { OID Result = 0;
    { OID  v5263 = GC_OID(v9268->var);
      OID  v5264 = GC_OID(v9268->arg);
      ClaireType * v15607 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v5264))));
      if (inherit_ask_class(OWNER(v5263),Language._Variable) != CTRUE)
       (*Optimize.Cerror)(_string_("[213] ~S is not a variable"),
        v5263);
      if (_oid_((ClaireObject *) Core._inf_equalt->fcall(((int) v15607),((int) OBJECT(ClaireObject,GC_OID((*Kernel.range)(v5263)))))) != Kernel.ctrue)
       v5264= GC_OID((*Optimize.c_warn)(GC_OID(v9268->var),
        v5264,
        _oid_(v15607)));
      { OID  v8441 = GC_OID(c_gc_I_any2(GC_OID(c_strict_code_any(v5264,psort_any(GC_OID((*Kernel.range)(v5263))))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel._exp)(GC_OID((*Kernel.range)(v5263)),
          _oid_(v15607))))));
        gc_register_Variable2(OBJECT(Variable,v5263),v8441);
        { Assign * v2072 = ((Assign *) GC_OBJECT(Assign,new_object_class(Language._Assign)));
          (v2072->var = v5263);
          (v2072->arg = v8441);
          add_I_property(Kernel.instances,Language._Assign,11,_oid_(v2072));
          Result = _oid_(v2072);
          } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Assign(Assign *v9268)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v9268->arg));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Gassign_Optimize(Gassign *v9268)
{ GC_BIND;
  { ClaireType *Result ;
    Result = OBJECT(ClaireType,(*Optimize.c_type)(v9268->arg));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Gassign_Optimize(Gassign *v9268)
{ GC_BIND;
  { OID Result = 0;
    { OID  v13274 = GC_OID(v9268->arg);
      ClaireType * v15607 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v13274))));
      if (boolean_I_any(_oid_(v9268->var->range)) != CTRUE)
       (*Optimize.Cerror)(_string_("[214] cannot assign ~S"),
        _oid_(v9268));
      if (_oid_((ClaireObject *) Core._inf_equalt->fcall(((int) v15607),((int) v9268->var->range))) != Kernel.ctrue)
       v13274= GC_OID(c_check_any(GC_OID((*Optimize.c_code)(v13274,
        _oid_(Kernel._any))),GC_OID((*Optimize.c_code)(_oid_(v9268->var->range),
        _oid_(Kernel._type)))));
      { Gassign * v2072 = ((Gassign *) GC_OBJECT(Gassign,new_object_class(Language._Gassign)));
        store_object(v2072,
          2,
          Kernel._object,
          (*Optimize.c_code)(_oid_(v9268->var)),
          CFALSE);
        { Gassign * v7709 = v2072; 
          OID  v7711;
          if (nativeVar_ask_global_variable(v9268->var) == CTRUE)
           v7711 = c_strict_code_any(v13274,psort_any(_oid_(v9268->var->range)));
          else v7711 = (*Optimize.c_code)(v13274,
              _oid_(Kernel._any));
            (v7709->arg = v7711);} 
        add_I_property(Kernel.instances,Language._Gassign,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Gassign(Gassign *v9268)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v9268->arg));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_And_Optimize(And *v9268)
{ return (Kernel._boolean);} 

OID  c_code_And_Optimize(And *v9268)
{ GC_BIND;
  { OID Result = 0;
    { And * v2072 = ((And *) GC_OBJECT(And,new_object_class(Language._And)));
      { And * v7712 = v2072; 
        list * v7713;
        { bag *v_list; OID v_val;
          OID v5264,CLcount;
          v_list = GC_OBJECT(list,v9268->args);
           v7713 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v5264 = (*(v_list))[CLcount];
            { if ((*Optimize.c_type)(v5264) == _oid_(Kernel._void))
               (*Optimize.Cerror)(_string_("[206] void ~S in ~S"),
                v5264,
                _oid_(v9268));
              v_val = c_boolean_any(v5264);
              } 
            
            (*((list *) v7713))[CLcount] = v_val;} 
          } 
        (v7712->args = v7713);} 
      add_I_property(Kernel.instances,Language._And,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Or_Optimize(Or *v9268)
{ return (Kernel._boolean);} 

OID  c_code_Or_Optimize(Or *v9268)
{ GC_BIND;
  { OID Result = 0;
    { Or * v2072 = ((Or *) GC_OBJECT(Or,new_object_class(Language._Or)));
      { Or * v7714 = v2072; 
        list * v7715;
        { bag *v_list; OID v_val;
          OID v5264,CLcount;
          v_list = GC_OBJECT(list,v9268->args);
           v7715 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v5264 = (*(v_list))[CLcount];
            { if ((*Optimize.c_type)(v5264) == _oid_(Kernel._void))
               (*Optimize.Cerror)(_string_("[206] void ~S in ~S"),
                v5264,
                _oid_(v9268));
              v_val = c_boolean_any(v5264);
              } 
            
            (*((list *) v7715))[CLcount] = v_val;} 
          } 
        (v7714->args = v7715);} 
      add_I_property(Kernel.instances,Language._Or,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Quote_Optimize(Quote *v9268)
{ return (OWNER(v9268->arg));} 

void  c_code_Quote_Optimize(Quote *v9268)
{ (*Optimize.Cerror)(_string_("[internal] optimization of quote not implemented yet! ~S"),
    _oid_(v9268));
  } 

ClaireType * c_type_to_protect_Optimize(Compile_to_protect *v9268)
{ GC_BIND;
  { ClaireType *Result ;
    Result = OBJECT(ClaireType,(*Optimize.c_type)(v9268->arg));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_to_protect_Optimize(Compile_to_protect *v9268)
{ return (_oid_(v9268));} 

ClaireBoolean * c_gc_ask_to_protect(Compile_to_protect *v9268)
{ return (CFALSE);} 

ClaireType * c_type_Return_Optimize(Return *v9268)
{ return (Kernel._any);} 

OID  c_code_Return_Optimize(Return *v9268)
{ GC_BIND;
  { OID Result = 0;
    { Return * v2072 = ((Return *) GC_OBJECT(Return,new_object_class(Language._Return)));
      (v2072->arg = (*Optimize.c_code)(GC_OID(v9268->arg),
        _oid_(Kernel._any)));
      add_I_property(Kernel.instances,Language._Return,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Handle_Optimize(ClaireHandle *v9268)
{ GC_BIND;
  { ClaireType *Result ;
    Result = U_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9268->arg)))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9268->other)))));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Handle_Optimize(ClaireHandle *v9268,ClaireClass *v5259)
{ GC_BIND;
  { OID Result = 0;
    { ClaireHandle * v5264;
      { { ClaireHandle * v2072 = ((ClaireHandle *) GC_OBJECT(ClaireHandle,new_object_class(Language._Handle)));
          (v2072->test = _oid_(Kernel._any));
          (v2072->arg = (*Optimize.c_code)(GC_OID(v9268->arg),
            _oid_(v5259)));
          (v2072->other = (*Optimize.c_code)(GC_OID(v9268->other),
            _oid_(v5259)));
          add_I_property(Kernel.instances,Language._Handle,11,_oid_(v2072));
          v5264 = v2072;
          } 
        GC_OBJECT(ClaireHandle,v5264);} 
      if (v9268->test != _oid_(Core._contradiction))
       (Optimize.OPT->allocation = CTRUE);
      (v5264->test = v9268->test);
      Result = _oid_(v5264);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Handle(ClaireHandle *v9268)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = (((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v9268->arg))) == CTRUE) ? CTRUE : (((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v9268->other))) == CTRUE) ? CTRUE : CFALSE));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Cast_Optimize(Cast *v9268)
{ return (v9268->set_arg);} 

OID  c_code_Cast_Optimize(Cast *v9268)
{ GC_BIND;
  { OID Result = 0;
    { ClaireType * v5265 = GC_OBJECT(ClaireType,v9268->set_arg);
      ClaireClass * v13496 = psort_any(_oid_(v5265));
      if ((INHERIT(v5265->isa,Core._Param)) && (((CLREAD(Param,v5265,arg) == Kernel._list) || 
            (CLREAD(Param,v5265,arg) == Kernel._set)) && 
          (Kernel._set == OWNER((*(CLREAD(Param,v5265,args)))[1]))))
       { OID  v5447 = GC_OID((*(OBJECT(set,(*(CLREAD(Param,v5265,args)))[1])))[1]);
        if ((equal(_oid_(_at_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9268->arg)))),Kernel.of)),v5447) == CTRUE) || 
            (Optimize.compiler->safety > 4))
         Result = (*Optimize.c_code)(GC_OID(v9268->arg),
          _oid_(v13496));
        else { OID  v11267;
            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Core.check_in);
              (v2072->args = list::alloc(3,GC_OID(v9268->arg),
                _oid_(CLREAD(Param,v5265,arg)),
                v5447));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v11267 = _oid_(v2072);
              } 
            Result = (*Optimize.c_code)(v11267,
              _oid_(v13496));
            } 
          } 
      else if ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9268->arg)))),v5265) == CTRUE) || 
          (Optimize.compiler->safety > 1))
       Result = (*Optimize.c_code)(GC_OID(v9268->arg),
        _oid_(v13496));
      else { OID  v12228;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Core.check_in);
            (v2072->args = list::alloc(2,GC_OID(v9268->arg),_oid_(v5265)));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v12228 = _oid_(v2072);
            } 
          Result = (*Optimize.c_code)(v12228,
            _oid_(v13496));
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Super_Optimize(Super *v9268)
{ GC_BIND;
  { ClaireType *Result ;
    { list * v15607;
      { { bag *v_list; OID v_val;
          OID v5264,CLcount;
          v_list = GC_OBJECT(list,v9268->args);
           v15607 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v5264 = (*(v_list))[CLcount];
            v_val = (*Optimize.c_type)(v5264);
            
            (*((list *) v15607))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v15607);} 
      property * v5259 = v9268->selector;
      ((*(v15607))[1]=_oid_(v9268->cast_to));
      { OID  v14411;
        { if (v5259->open == 3)
           v14411 = Core.nil->value;
          else v14411 = restriction_I_class(class_I_type(GC_OBJECT(ClaireType,v9268->cast_to)),v5259->definition,v15607);
            GC_OID(v14411);} 
        Result = ((Kernel._slot == OWNER(v14411)) ?
          OBJECT(restriction,v14411)->range :
          ((Kernel._method == OWNER(v14411)) ?
            use_range_method(OBJECT(method,v14411),v15607) :
            v5259->range ) );
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Super_Optimize(Super *v9268)
{ GC_BIND;
  { OID Result = 0;
    { property * v5259 = v9268->selector;
      list * v5252 = GC_OBJECT(list,v9268->args);
      list * v15607;
      { { bag *v_list; OID v_val;
          OID v5264,CLcount;
          v_list = GC_OBJECT(list,v9268->args);
           v15607 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v5264 = (*(v_list))[CLcount];
            v_val = (*Optimize.c_type)(v5264);
            
            (*((list *) v15607))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v15607);} 
      OID  v14411;
      { if (v5259->open == 3)
         v14411 = Core.nil->value;
        else v14411 = restriction_I_class(class_I_type(GC_OBJECT(ClaireType,v9268->cast_to)),v5259->definition,v15607);
          GC_OID(v14411);} 
      if (Kernel._slot == OWNER(v14411))
       { Call_slot * v2072 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
        (v2072->selector = OBJECT(slot,v14411));
        (v2072->arg = (*Optimize.c_code)((*(v5252))[1],
          _oid_(psort_any(_oid_(domain_I_restriction(OBJECT(restriction,v14411)))))));
        (v2072->test = ((belong_to(OBJECT(slot,v14411)->DEFAULT,_oid_(OBJECT(restriction,v14411)->range)) != CTRUE) ? ((Optimize.compiler->safety < 5) ? CTRUE: CFALSE): CFALSE));
        add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      else if (Kernel._method == OWNER(v14411))
       Result = c_code_method_method1(OBJECT(method,v14411),v5252,v15607);
      else Result = c_warn_Super(v9268,_oid_(v15607));
        } 
    GC_UNBIND; return (Result);} 
  } 

void  self_print_Call_function2(Optimize_Call_function2 *v9268)
{ print_any(_oid_(v9268->arg));
  princ_string("(");
  princ_bag(v9268->args);
  princ_string(")");
  } 

ClaireType * c_type_Call_function2_Optimize(Optimize_Call_function2 *v9268)
{ return (Kernel._any);} 

OID  c_code_Call_function2_Optimize(Optimize_Call_function2 *v9268)
{ GC_BIND;
  { OID Result = 0;
    { Optimize_Call_function2 * v2072 = ((Optimize_Call_function2 *) GC_OBJECT(Optimize_Call_function2,new_object_class(Optimize._Call_function2)));
      (v2072->arg = v9268->arg);
      { Optimize_Call_function2 * v7738 = v2072; 
        list * v7739;
        { bag *v_list; OID v_val;
          OID v5264,CLcount;
          v_list = v9268->args;
           v7739 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v5264 = (*(v_list))[CLcount];
            v_val = (*Optimize.c_code)(v5264,
              _oid_(Kernel._any));
            
            (*((list *) v7739))[CLcount] = v_val;} 
          } 
        (v7738->args = v7739);} 
      add_I_property(Kernel.instances,Optimize._Call_function2,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Assert_Optimize(Assert *v9268)
{ if (Optimize.OPT->online_ask == CTRUE) 
  { { OID Result = 0;
      Result = _oid_(v9268);
      return (Result);} 
     } 
  else{ GC_BIND;
    { OID Result = 0;
      if ((Optimize.compiler->safety == 0) || 
          (Optimize.compiler->debug_ask->length != 0))
       { OID  v2524;
        { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
          { If * v7741 = v2072; 
            OID  v7742;
            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Core.NOT);
              (v2072->args = list::alloc(1,GC_OID((*(v9268->args))[1])));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v7742 = _oid_(v2072);
              } 
            (v7741->test = v7742);} 
          { If * v7743 = v2072; 
            OID  v7744;
            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Core.tformat);
              { Call * v7745 = v2072; 
                list * v7746;
                { OID v_bag;
                  GC_ANY(v7746= list::empty(Kernel.emptySet));
                  ((list *) v7746)->addFast(_string_("Assertion violation in ~A line ~A\n"));
                  ((list *) v7746)->addFast(0);
                  { { List * v2072 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
                      (v2072->args = list::alloc(2,GC_OID(_string_(v9268->external)),v9268->index));
                      add_I_property(Kernel.instances,Language._List,11,_oid_(v2072));
                      v_bag = _oid_(v2072);
                      } 
                    GC_OID(v_bag);} 
                  ((list *) v7746)->addFast(v_bag);} 
                (v7745->args = v7746);} 
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v7744 = _oid_(v2072);
              } 
            (v7743->arg = v7744);} 
          (v2072->other = Kernel.cfalse);
          add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
          v2524 = _oid_(v2072);
          } 
        Result = (*Optimize.c_code)(v2524,
          _oid_(Kernel._any));
        } 
      else Result = Kernel.cfalse;
        GC_UNBIND; return (Result);} 
    } 
  } 

OID  c_code_Trace_Optimize(Trace *v9268)
{ GC_BIND;
  { OID Result = 0;
    { list * v5241 = GC_OBJECT(list,v9268->args);
      if (Optimize.OPT->online_ask == CTRUE)
       Result = _oid_(v9268);
      else if ((v5241->length == 1) && 
          (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(v5241))[1]))),Kernel._integer) == CTRUE))
       { OID  v9251;
        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v2072->selector = Core.write);
          (v2072->args = list::alloc(3,_oid_(Kernel.verbose),
            _oid_(ClEnv),
            (*(v5241))[1]));
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
          v9251 = _oid_(v2072);
          } 
        Result = (*Optimize.c_code)(v9251);
        } 
      else { ClaireBoolean * g0170I;
        { ClaireBoolean *v_and;
          { v_and = ((v5241->length > 1) ? CTRUE : CFALSE);
            if (v_and == CFALSE) g0170I =CFALSE; 
            else { v_and = ((Kernel._string == OWNER((*(v5241))[2])) ? CTRUE : CFALSE);
              if (v_and == CFALSE) g0170I =CFALSE; 
              else { { ClaireBoolean *v_or;
                  { v_or = ((Optimize.compiler->debug_ask->length != 0) ? CTRUE : CFALSE);
                    if (v_or == CTRUE) v_and =CTRUE; 
                    else { { ClaireObject *V_CC ;
                        { ClaireHandler c_handle = ClaireHandler();
                          if ERROR_IN 
                          { V_CC = ((OPT_EVAL((*(v5241))[1]) <= ClEnv->verbose) ? CTRUE : CFALSE);
                            ClEnv->cHandle--;} 
                          else if (belong_to(_oid_(ClEnv->exception_I),_oid_(Kernel._any)) == CTRUE)
                          { c_handle.catchIt();V_CC = CTRUE;
                            } 
                          else PREVIOUS_HANDLER;} 
                        v_or= (ClaireBoolean *) V_CC;} 
                      if (v_or == CTRUE) v_and =CTRUE; 
                      else v_and = CFALSE;} 
                    } 
                  } 
                if (v_and == CFALSE) g0170I =CFALSE; 
                else g0170I = CTRUE;} 
              } 
            } 
          } 
        
        if (g0170I == CTRUE) { Call * v13254;
            { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Core.tformat);
                { Call * v7770 = v2072; 
                  list * v7771;
                  { OID v_bag;
                    GC_ANY(v7771= list::empty(Kernel.emptySet));
                    ((list *) v7771)->addFast((*(v5241))[2]);
                    ((list *) v7771)->addFast((*(v5241))[1]);
                    { { List * v2072 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
                        (v2072->args = skip_list(((list *) copy_bag(v5241)),2));
                        add_I_property(Kernel.instances,Language._List,11,_oid_(v2072));
                        v_bag = _oid_(v2072);
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v7771)->addFast(v_bag);} 
                  (v7770->args = v7771);} 
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v13254 = v2072;
                } 
              GC_OBJECT(Call,v13254);} 
            { OID  v508;
              if (inherit_ask_class(OWNER((*(v5241))[1]),Kernel._integer) != CTRUE)
               { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                { If * v7773 = v2072; 
                  OID  v7774;
                  { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Kernel._inf_equal);
                    { Call * v7775 = v2072; 
                      list * v7777;
                      { OID v_bag;
                        GC_ANY(v7777= list::empty(Kernel.emptySet));
                        ((list *) v7777)->addFast((*(v5241))[1]);
                        { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                            (v2072->selector = Kernel.verbose);
                            (v2072->args = list::alloc(1,_oid_(ClEnv)));
                            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                            v_bag = _oid_(v2072);
                            } 
                          GC_OID(v_bag);} 
                        ((list *) v7777)->addFast(v_bag);} 
                      (v7775->args = v7777);} 
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v7774 = _oid_(v2072);
                    } 
                  (v7773->test = v7774);} 
                (v2072->arg = _oid_(v13254));
                (v2072->other = Kernel.cfalse);
                add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                v508 = _oid_(v2072);
                } 
              else v508 = _oid_(v13254);
                Result = (*Optimize.c_code)(v508,
                _oid_(Kernel._any));
              } 
            } 
          else Result = Kernel.cfalse;
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Assert_Optimize(Assert *v9268)
{ return (Kernel._any);} 

ClaireType * c_type_Trace_Optimize(Trace *v9268)
{ return (Kernel._any);} 

ClaireType * c_type_Branch_Optimize(Branch *v9268)
{ return (Kernel._boolean);} 

OID  c_code_Branch_Optimize(Branch *v9268)
{ GC_BIND;
  { OID Result = 0;
    { OID  v5313;
      { ClaireHandle * v2072 = ((ClaireHandle *) GC_OBJECT(ClaireHandle,new_object_class(Language._Handle)));
        { ClaireHandle * v7779 = v2072; 
          OID  v7800;
          { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
            { Do * v7801 = v2072; 
              list * v7802;
              { OID v_bag;
                GC_ANY(v7802= list::empty(Kernel.emptySet));
                { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Kernel.choice);
                    (v2072->args = list::alloc(1,_oid_(ClEnv)));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v_bag = _oid_(v2072);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v7802)->addFast(v_bag);
                { { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                    (v2072->test = (*(v9268->args))[1]);
                    (v2072->arg = Kernel.ctrue);
                    { If * v7803 = v2072; 
                      OID  v7804;
                      { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                        { Do * v7805 = v2072; 
                          list * v7806;
                          { OID v_bag;
                            GC_ANY(v7806= list::empty(Kernel.emptySet));
                            { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                (v2072->selector = Kernel.backtrack);
                                (v2072->args = list::alloc(1,_oid_(ClEnv)));
                                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                v_bag = _oid_(v2072);
                                } 
                              GC_OID(v_bag);} 
                            ((list *) v7806)->addFast(v_bag);
                            ((list *) v7806)->addFast(Kernel.cfalse);} 
                          (v7805->args = v7806);} 
                        add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                        v7804 = _oid_(v2072);
                        } 
                      (v7803->other = v7804);} 
                    add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                    v_bag = _oid_(v2072);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v7802)->addFast(v_bag);} 
              (v7801->args = v7802);} 
            add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
            v7800 = _oid_(v2072);
            } 
          (v7779->arg = v7800);} 
        (v2072->test = _oid_(Core._contradiction));
        { ClaireHandle * v7807 = v2072; 
          OID  v7808;
          { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
            { Do * v7809 = v2072; 
              list * v7831;
              { OID v_bag;
                GC_ANY(v7831= list::empty(Kernel.emptySet));
                { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Kernel.backtrack);
                    (v2072->args = list::alloc(1,_oid_(ClEnv)));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v_bag = _oid_(v2072);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v7831)->addFast(v_bag);
                ((list *) v7831)->addFast(Kernel.cfalse);} 
              (v7809->args = v7831);} 
            add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
            v7808 = _oid_(v2072);
            } 
          (v7807->other = v7808);} 
        add_I_property(Kernel.instances,Language._Handle,11,_oid_(v2072));
        v5313 = _oid_(v2072);
        } 
      Result = (*Optimize.c_code)(v5313,
        _oid_(Kernel._any));
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Macro_Optimize(Macro *v9268,ClaireClass *v5259)
{ GC_BIND;
  { OID Result = 0;
    Result = (*Optimize.c_code)(GC_OID((*Language.macroexpand)(_oid_(v9268))),
      _oid_(v5259));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Macro_Optimize(Macro *v9268)
{ GC_BIND;
  { ClaireType *Result ;
    Result = OBJECT(ClaireType,(*Optimize.c_type)(GC_OID((*Language.macroexpand)(_oid_(v9268)))));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Printf_Optimize(Printf *v9268)
{ return (Kernel._any);} 

OID  c_code_Printf_Optimize(Printf *v9268)
{ GC_RESERVE(10);  // v3.0.55 optim !
  { OID Result = 0;
    { list * v5252 = GC_OBJECT(list,v9268->args);
      OID  v5259 = (*(v5252))[1];
      if (equal(_oid_(Kernel._string),_oid_(OWNER(v5259))) != CTRUE)
       Result = (*Optimize.Cerror)(_string_("[209] the first argument in ~S must be a string"),
        _oid_(v9268));
      else { int  v5249 = 1;
          OID  v5254 = GC_OID((*Kernel.get)(v5259,
            _oid_(_char_('~'))));
          list * v5258 = list::empty(Kernel._any);
          { OID gc_local;
            while ((equal(v5254,0) != CTRUE))
            { GC_LOOP;
              { OID  v5253 = GC_OID((*Kernel.nth)(v5259,
                  ((v5254)+1)));
                if (v5249 < v5252->length)
                 ++v5249;
                else (*Optimize.Cerror)(_string_("[210] not enough arguments in ~S"),
                    _oid_(v9268));
                  if ((OBJECT(ClaireBoolean,(*Kernel._sup)(v5254,
                  1))) == CTRUE)
                 { { OID  v9016;
                    { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Kernel.princ);
                      (v2072->args = list::alloc(1,GC_OID(_string_(substring_string(string_v(v5259),1,((v5254)-1))))));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v9016 = _oid_(v2072);
                      } 
                    v5258 = v5258->addFast(v9016);
                    } 
                   GC__ANY(v5258, 7);} 
                { { OID  v9977;
                    if (_oid_(_char_('A')) == v5253)
                     { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Kernel.princ);
                      (v2072->args = list::alloc(1,(*(v5252))[v5249]));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v9977 = _oid_(v2072);
                      } 
                    else if (_oid_(_char_('S')) == v5253)
                     { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Kernel.print);
                      (v2072->args = list::alloc(1,(*(v5252))[v5249]));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v9977 = _oid_(v2072);
                      } 
                    else if (_oid_(_char_('I')) == v5253)
                     v9977 = (*(v5252))[v5249];
                    else v9977 = Kernel.cfalse;
                      v5258 = v5258->addFast(v9977);
                    } 
                   GC__ANY(v5258, 7);} 
                GC__OID(v5259 = _string_(substring_string(string_v(v5259),((v5254)+2),1000)), 4);
                GC__OID(v5254 = (*Kernel.get)(v5259,
                  _oid_(_char_('~'))), 6);
                } 
              GC_UNLOOP;} 
            } 
          if (boolean_I_any(v5259) == CTRUE)
           { OID  v10938;
            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Kernel.princ);
              (v2072->args = list::alloc(1,v5259));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v10938 = _oid_(v2072);
              } 
            v5258 = v5258->addFast(v10938);
            } 
          { OID  v11899;
            { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
              (v2072->args = v5258);
              add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
              v11899 = _oid_(v2072);
              } 
            Result = (*Optimize.c_code)(v11899,
              _oid_(Kernel._any));
            } 
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Error_Optimize(Error *v9268)
{ return (Kernel.emptySet);} 

OID  c_code_Error_Optimize(Error *v9268)
{ GC_BIND;
  { OID Result = 0;
    { ClaireBoolean * v5264 = Optimize.OPT->allocation;
      OID  v5265;
      { { OID  v12860;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.close);
            { Call * v7838 = v2072; 
              list * v7840;
              { OID v_bag;
                GC_ANY(v7840= list::empty(Kernel.emptySet));
                { { Cast * v2072 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                    { Cast * v7841 = v2072; 
                      OID  v7842;
                      { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v2072->selector = Optimize.anyObject_I);
                        { Call * v8513 = v2072; 
                          list * v8514;
                          { OID v_bag;
                            GC_ANY(v8514= list::empty(Kernel.emptySet));
                            ((list *) v8514)->addFast(_oid_(Core._general_error));
                            ((list *) v8514)->addFast(GC_OID((*Optimize.c_code)(GC_OID(car_list(v9268->args)),
                              _oid_(Kernel._any))));
                            { { OID  v10019;
                                if (v9268->args->length != 1)
                                 { List * v2072 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
                                  (v2072->args = cdr_list(GC_OBJECT(list,v9268->args)));
                                  add_I_property(Kernel.instances,Language._List,11,_oid_(v2072));
                                  v10019 = _oid_(v2072);
                                  } 
                                else v10019 = Core.nil->value;
                                  v_bag = (*Optimize.c_code)(v10019,
                                  _oid_(Kernel._any));
                                } 
                              GC_OID(v_bag);} 
                            ((list *) v8514)->addFast(v_bag);} 
                          (v8513->args = v8514);} 
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                        v7842 = _oid_(v2072);
                        } 
                      (v7841->arg = v7842);} 
                    (v2072->set_arg = Kernel._exception);
                    add_I_property(Kernel.instances,Language._Cast,11,_oid_(v2072));
                    v_bag = _oid_(v2072);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v7840)->addFast(v_bag);} 
              (v7838->args = v7840);} 
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v12860 = _oid_(v2072);
            } 
          v5265 = (*Optimize.c_code)(v12860,
            _oid_(Kernel._void));
          } 
        GC_OID(v5265);} 
      (Optimize.OPT->allocation = v5264);
      Result = v5265;
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * extendedTest_ask_If(If *v9268)
{ GC_BIND;
  { ClaireType *Result ;
    { OID  v13271 = v9268->test;
      if (INHERIT(OWNER(v13271),Language._Call))
       { if ((INHERIT(OWNER((*(OBJECT(Call,v13271)->args))[1]),Language._Variable)) && 
            (OBJECT(Call,v13271)->selector == Core.known_ask))
         Result = OBJECT(ClaireType,(*Kernel.range)((*(OBJECT(Call,v13271)->args))[1]));
        else Result = Kernel._any;
          } 
      else Result = Kernel._any;
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_If_Optimize(If *v9268)
{ GC_BIND;
  { ClaireType *Result ;
    { ClaireType * v13269 = GC_OBJECT(ClaireType,extendedTest_ask_If(v9268));
      if (extended_ask_type(v13269) == CTRUE)
       range_sets_any(GC_OID((*(OBJECT(bag,(*Core.args)(GC_OID(v9268->test)))))[1]),GC_OBJECT(ClaireType,sort_abstract_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Core.t1)(_oid_(v13269)))))));
      { ClaireType * v773 = GC_OBJECT(ClaireType,U_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9268->arg)))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9268->other))))));
        if (extended_ask_type(v13269) == CTRUE)
         put_property2(Kernel.range,GC_OBJECT(ClaireObject,OBJECT(ClaireObject,(*(OBJECT(bag,(*Core.args)(GC_OID(v9268->test)))))[1])),_oid_(v13269));
        Result = v773;
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_If_Optimize(If *v9268,ClaireClass *v5259)
{ GC_BIND;
  { OID Result = 0;
    { ClaireType * v13269 = GC_OBJECT(ClaireType,extendedTest_ask_If(v9268));
      if (extended_ask_type(v13269) == CTRUE)
       range_sets_any(GC_OID((*(OBJECT(bag,(*Core.args)(GC_OID(v9268->test)))))[1]),GC_OBJECT(ClaireType,sort_abstract_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Core.t1)(_oid_(v13269)))))));
      if ((_inf_equal_type(GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9268->test))))),Kernel._boolean) != CTRUE) && 
          (Optimize.PENIBLE->value == Kernel.ctrue))
       { warn_void();
        tformat_string("CLAIRE 3.3 SYNTAX - Test in ~S should be a boolean [260]\n",2,list::alloc(1,_oid_(v9268)));
        } 
      { If * v773;
        { { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
            (v2072->test = c_boolean_any(GC_OID(v9268->test)));
            (v2072->arg = (*Optimize.c_code)(GC_OID(v9268->arg),
              _oid_(v5259)));
            (v2072->other = (*Optimize.c_code)(GC_OID(v9268->other),
              _oid_(v5259)));
            add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
            v773 = v2072;
            } 
          GC_OBJECT(If,v773);} 
        if (extended_ask_type(v13269) == CTRUE)
         put_property2(Kernel.range,GC_OBJECT(ClaireObject,OBJECT(ClaireObject,(*(OBJECT(bag,(*Core.args)(GC_OID(v9268->test)))))[1])),_oid_(v13269));
        Result = _oid_(v773);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_If(If *v9268)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = (((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v9268->arg))) == CTRUE) ? CTRUE : (((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v9268->other))) == CTRUE) ? CTRUE : CFALSE));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Case_Optimize(Case *v9268)
{ GC_RESERVE(6);  // v3.0.55 optim !
  { ClaireType *Result ;
    { OID  v11722 = GC_OID(v9268->var);
      OID  v15607;
      { if (INHERIT(OWNER(v11722),Language._Variable))
         v15607 = get_property(Kernel.range,OBJECT(ClaireObject,v11722));
        else v15607 = _oid_(Kernel._any);
          GC_OID(v15607);} 
      list * v5252 = ((list *) copy_bag(v9268->args));
      ClaireType * v3781 = Kernel.emptySet;
      ClaireType * v5447 = Kernel.emptySet;
      { OID gc_local;
        while ((v5252->length > 0))
        { GC_LOOP;
          if (INHERIT(OWNER((*(v5252))[1]),Kernel._type))
           { GC__ANY(v5447 = U_type(v5447,OBJECT(ClaireType,(*(v5252))[1])), 6);
            if (osort_any(v15607) == osort_any((*(v5252))[1]))
             range_sets_any(v11722,OBJECT(ClaireType,(*(v5252))[1]));
            else if (osort_any(v15607) == Kernel._any)
             range_sets_any(v11722,GC_OBJECT(ClaireType,sort_abstract_I_type(OBJECT(ClaireType,(*(v5252))[1]))));
            } 
          else (*Optimize.Cerror)(_string_("[208] wrong type declaration for case: ~S in ~S"),
              car_list(v5252),
              _oid_(v9268));
            GC__ANY(v3781 = U_type(v3781,GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(v5252))[2])))), 5);
          if (INHERIT(OWNER(v11722),Language._Variable))
           store_object(OBJECT(ClaireObject,v11722),
            3,
            Kernel._object,
            v15607,
            CFALSE);
          v5252= skip_list(v5252,2);
          GC_UNLOOP;} 
        } 
      if (_inf_equal_type(OBJECT(ClaireType,v15607),v5447) == CTRUE)
       Result = v3781;
      else Result = ((_inf_equal_type(v3781,Kernel._boolean) == CTRUE) ?
        Kernel._boolean :
        Kernel._any );
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Case_Optimize(Case *v9268,ClaireClass *v5259)
{ GC_RESERVE(13);  // v3.0.55 optim !
  { OID Result = 0;
    { OID  v11722 = GC_OID(v9268->var);
      OID  v15607;
      { if (INHERIT(OWNER(v11722),Language._Variable))
         v15607 = get_property(Kernel.range,OBJECT(ClaireObject,v11722));
        else v15607 = _oid_(Kernel._any);
          GC_OID(v15607);} 
      list * v5252 = ((list *) copy_bag(v9268->args));
      OID  v5447 = _oid_(Kernel.emptySet);
      OID  v3652;
      { { OID  v10980;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel._Z);
            (v2072->args = list::alloc(2,v11722,(*(v5252))[1]));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v10980 = _oid_(v2072);
            } 
          v3652 = c_boolean_any(v10980);
          } 
        GC_OID(v3652);} 
      range_sets_any(v11722,OBJECT(ClaireType,(*(v5252))[1]));
      { If * v9909;
        { { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
            (v2072->test = v3652);
            (v2072->arg = (*Optimize.c_code)((*(v5252))[2],
              _oid_(v5259)));
            (v2072->other = (*Optimize.c_code)(Kernel.cfalse,
              _oid_(v5259)));
            add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
            v9909 = v2072;
            } 
          GC_OBJECT(If,v9909);} 
        If * v8277 = v9909;
        if (INHERIT(OWNER(v11722),Language._Variable))
         store_object(OBJECT(ClaireObject,v11722),
          3,
          Kernel._object,
          v15607,
          CFALSE);
        v5252= skip_list(v5252,2);
        { OID gc_local;
          while ((v5252->length > 0))
          { GC_LOOP;
            GC__OID(v5447 = _oid_(U_type(OBJECT(ClaireType,v5447),OBJECT(ClaireType,(*(v5252))[1]))), 7);
            if (_inf_equal_type(OBJECT(ClaireType,v15607),OBJECT(ClaireType,v5447)) == CTRUE)
             { if (osort_any(v15607) == osort_any((*(v5252))[1]))
               range_sets_any(v11722,OBJECT(ClaireType,(*(v5252))[1]));
              else if (osort_any(v15607) == Kernel._any)
               range_sets_any(v11722,GC_OBJECT(ClaireType,sort_abstract_I_type(OBJECT(ClaireType,(*(v5252))[1]))));
              (v8277->other = (*Optimize.c_code)((*(v5252))[2],
                _oid_(v5259)));
              if (INHERIT(OWNER(v11722),Language._Variable))
               store_object(OBJECT(ClaireObject,v11722),
                3,
                Kernel._object,
                v15607,
                CFALSE);
              { ;break;} 
              } 
            else { OID  v9101;
                { { OID  v11941;
                    { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Kernel._Z);
                      (v2072->args = list::alloc(2,v11722,(*(v5252))[1]));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v11941 = _oid_(v2072);
                      } 
                    v9101 = c_boolean_any(v11941);
                    } 
                  GC_OID(v9101);} 
                range_sets_any(v11722,OBJECT(ClaireType,(*(v5252))[1]));
                { If * v8518 = v8277; 
                  OID  v8519;
                  { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                    (v2072->test = v9101);
                    (v2072->arg = (*Optimize.c_code)((*(v5252))[2],
                      _oid_(v5259)));
                    (v2072->other = (*Optimize.c_code)(Kernel.cfalse,
                      _oid_(v5259)));
                    add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                    v8519 = _oid_(v2072);
                    } 
                  (v8518->other = v8519);} 
                GC__ANY(v8277 = OBJECT(If,v8277->other), 10);
                } 
              if (INHERIT(OWNER(v11722),Language._Variable))
             store_object(OBJECT(ClaireObject,v11722),
              3,
              Kernel._object,
              v15607,
              CFALSE);
            v5252= skip_list(v5252,2);
            GC_UNLOOP;} 
          } 
        if ((INHERIT(OWNER(v11722),Language._Definition)) && (INHERIT(OBJECT(Definition,v11722)->arg->isa,Kernel._exception)))
         Result = v11722;
        else Result = _oid_(v9909);
          } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Do_Optimize(Do *v9268)
{ GC_BIND;
  { ClaireType *Result ;
    Result = OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(last_list(v9268->args))));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Do_Optimize(Do *v9268,ClaireClass *v5259)
{ GC_BIND;
  { OID Result = 0;
    { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
      { Do * v8520 = v2072; 
        list * v8521;
        { int  v5253 = v9268->args->length;
          int  v5254 = 0;
          { bag *v_list; OID v_val;
            OID v5264,CLcount;
            v_list = GC_OBJECT(list,v9268->args);
             v8521 = v_list->clone();
            for (CLcount= 1; CLcount <= v_list->length; CLcount++)
            { v5264 = (*(v_list))[CLcount];
              { ++v5254;
                { OID  v362;
                  if (v5254 == v5253)
                   v362 = _oid_(v5259);
                  else v362 = _oid_(Kernel._void);
                    v_val = (*Optimize.c_code)(v5264,
                    v362);
                  } 
                } 
              
              (*((list *) v8521))[CLcount] = v_val;} 
            } 
          } 
        (v8520->args = v8521);} 
      add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Do(Do *v9268)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(GC_OID(last_list(v9268->args))));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Let_Optimize(Let *v9268)
{ GC_BIND;
  range_infers_Variable(GC_OBJECT(Variable,v9268->var),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9268->value)))));
  { ClaireType *Result ;
    Result = OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9268->arg)));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Let_Optimize(Let *v9268,ClaireClass *v5259)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID Result = 0;
    { OID  v13274 = GC_OID(v9268->value);
      ClaireType * v15607 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v13274))));
      range_infers_Variable(GC_OBJECT(Variable,v9268->var),v15607);
      if (_inf_equal_type(v15607,GC_OBJECT(ClaireType,v9268->var->range)) != CTRUE)
       v13274= GC_OID(c_warn_Variable(GC_OBJECT(Variable,v9268->var),v13274,v15607));
      { Let * v5264;
        { { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
            (v2072->var = v9268->var);
            (v2072->value = c_gc_I_any2(GC_OID(c_strict_code_any(v13274,psort_any(GC_OID(_oid_(v9268->var->range))))),v15607));
            (v2072->arg = (*Optimize.c_code)(GC_OID(v9268->arg),
              _oid_(v5259)));
            add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
            v5264 = v2072;
            } 
          GC_OBJECT(Let,v5264);} 
        (v5264->isa = v9268->isa);
        if ((INHERIT(v5264->isa,Language._Let_star)) && 
            ((INHERIT(v15607->isa,Kernel._tuple)) && 
              (BCONTAIN(c_status_any(GC_OID(v9268->value),Kernel.nil),1))))
         { int  v5249 = 1;
          OID  v5266 = GC_OID(v5264->arg);
          { OID gc_local;
            while (((INHERIT(OWNER(v5266),Language._Let)) && 
                (v5249 <= ((bag *) v15607)->length)))
            { GC_LOOP;
              if ((((OBJECT(ClaireBoolean,(*Optimize.gcsafe_ask)((*(((bag *) v15607)))[v5249]))) == CTRUE) ? CTRUE : ((INHERIT(owner_any((*Kernel.value)(v5266)),Optimize._to_protect)) ? CTRUE : CFALSE)) != CTRUE)
               { (Optimize.OPT->protection = CTRUE);
                { OID  v5120;
                  { Compile_to_protect * v2072 = ((Compile_to_protect *) GC_OBJECT(Compile_to_protect,new_object_class(Optimize._to_protect)));
                    (v2072->arg = (*Kernel.value)(v5266));
                    add_I_property(Kernel.instances,Optimize._to_protect,11,_oid_(v2072));
                    v5120 = _oid_(v2072);
                    } 
                  write_property(Kernel.value,OBJECT(ClaireObject,v5266),v5120);
                  } 
                } 
              ++v5249;
              GC__OID(v5266 = (*Kernel.arg)(v5266), 8);
              GC_UNLOOP;} 
            } 
          } 
        Result = _oid_(v5264);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_When_Optimize(When *v9268)
{ GC_BIND;
  { ClaireType *Result ;
    { OID  v13274 = GC_OID(v9268->value);
      Variable * v5263 = GC_OBJECT(Variable,v9268->var);
      OID  v5244 = GC_OID(daccess_any(v13274,CTRUE));
      OID  v15607;
      { if (v5244 != CNULL)
         v15607 = (*Optimize.c_type)(v5244);
        else v15607 = (*Optimize.c_type)(v13274);
          GC_OID(v15607);} 
      if (extended_ask_type(OBJECT(ClaireType,v15607)) == CTRUE)
       v15607= GC_OID((*Core.t1)(v15607));
      range_infers_Variable(v5263,OBJECT(ClaireType,v15607));
      Result = U_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9268->arg)))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9268->other)))));
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_When_Optimize(When *v9268,ClaireClass *v5259)
{ GC_BIND;
  { OID Result = 0;
    { OID  v13274 = GC_OID(v9268->value);
      Variable * v5263 = GC_OBJECT(Variable,v9268->var);
      OID  v5244 = GC_OID(daccess_any(v13274,CTRUE));
      Variable * v15716 = GC_OBJECT(Variable,Variable_I_symbol(append_symbol(v9268->var->pname,_string_("test")),v9268->var->index,Kernel._any));
      OID  v15607;
      { if (v5244 != CNULL)
         v15607 = (*Optimize.c_type)(v5244);
        else v15607 = (*Optimize.c_type)(v13274);
          GC_OID(v15607);} 
      if (extended_ask_type(OBJECT(ClaireType,v15607)) == CTRUE)
       v15607= GC_OID((*Core.t1)(v15607));
      range_infers_Variable(v5263,OBJECT(ClaireType,v15607));
      if ((v5244 != CNULL) && 
          (extended_ask_type(OBJECT(ClaireType,(*Kernel.range)(GC_OID((*Kernel.selector)(v5244))))) != CTRUE))
       { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
        (v2072->var = v5263);
        (v2072->value = c_gc_I_any2(v5244,OBJECT(ClaireType,v15607)));
        { Let * v8545 = v2072; 
          OID  v8546;
          { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
            { If * v8547 = v2072; 
              OID  v8549;
              { Call_method2 * v2072 = ((Call_method2 *) GC_OBJECT(Call_method2,new_object_class(Language._Call_method2)));
                (v2072->arg = ((method *) _at_property1(Core.identical_ask,Kernel._any)));
                (v2072->args = list::alloc(2,_oid_(v5263),GC_OID((*Optimize.c_code)(CNULL,
                  GC_OID((*Optimize.c_sort)(_oid_(v5263)))))));
                add_I_property(Kernel.instances,Language._Call_method2,11,_oid_(v2072));
                v8549 = _oid_(v2072);
                } 
              (v8547->test = v8549);} 
            (v2072->arg = (*Optimize.c_code)(GC_OID(v9268->other),
              _oid_(v5259)));
            (v2072->other = (*Optimize.c_code)(GC_OID(v9268->arg),
              _oid_(v5259)));
            add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
            v8546 = _oid_(v2072);
            } 
          (v8545->arg = v8546);} 
        add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      else if (((*Optimize.c_sort)(_oid_(v5263)) == _oid_(Kernel._any)) && 
          ((_inf_equal_type(OBJECT(ClaireType,v15607),GC_OBJECT(ClaireType,v5263->range)) == CTRUE) && 
            (3 <= Optimize.compiler->safety)))
       { OID  v9925;
        { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
          (v2072->var = v5263);
          (v2072->value = v13274);
          { Let * v8551 = v2072; 
            OID  v8552;
            { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
              { If * v8554 = v2072; 
                OID  v8556;
                { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Core._I_equal);
                  (v2072->args = list::alloc(2,_oid_(v5263),CNULL));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v8556 = _oid_(v2072);
                  } 
                (v8554->test = v8556);} 
              (v2072->arg = v9268->arg);
              (v2072->other = v9268->other);
              add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
              v8552 = _oid_(v2072);
              } 
            (v8551->arg = v8552);} 
          add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
          v9925 = _oid_(v2072);
          } 
        Result = (*Optimize.c_code)(v9925,
          _oid_(v5259));
        } 
      else { OID  v2143;
          { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
            (v2072->var = v15716);
            (v2072->value = v13274);
            { Let * v8576 = v2072; 
              OID  v8577;
              { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                { If * v8579 = v2072; 
                  OID  v8580;
                  { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Core._I_equal);
                    (v2072->args = list::alloc(2,_oid_(v15716),CNULL));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v8580 = _oid_(v2072);
                    } 
                  (v8579->test = v8580);} 
                { If * v8581 = v2072; 
                  OID  v8582;
                  { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
                    (v2072->var = v5263);
                    { Let * v8583 = v2072; 
                      OID  v8584;
                      { Cast * v2072 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                        (v2072->arg = _oid_(v15716));
                        (v2072->set_arg = OBJECT(ClaireType,v15607));
                        add_I_property(Kernel.instances,Language._Cast,11,_oid_(v2072));
                        v8584 = _oid_(v2072);
                        } 
                      (v8583->value = v8584);} 
                    (v2072->arg = v9268->arg);
                    add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
                    v8582 = _oid_(v2072);
                    } 
                  (v8581->arg = v8582);} 
                (v2072->other = (*Optimize.c_code)(GC_OID(v9268->other),
                  _oid_(v5259)));
                add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                v8577 = _oid_(v2072);
                } 
              (v8576->arg = v8577);} 
            add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
            v2143 = _oid_(v2072);
            } 
          Result = (*Optimize.c_code)(v2143,
            _oid_(v5259));
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Let(Let *v9268)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v9268->arg));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_For_Optimize(For *v9268)
{ GC_BIND;
  { ClaireType *Result ;
    Result = infers_from_type2(GC_OBJECT(ClaireType,return_type_any(GC_OID(v9268->arg))),_oid_(v9268));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * infers_from_type2(ClaireType *v5260,OID v9268)
{ GC_BIND;
  { ClaireType *Result ;
    if (equal(_oid_(v5260),_oid_(Kernel.emptySet)) == CTRUE)
     Result = sort_abstract_I_type(Kernel._boolean);
    else if (Optimize.compiler->safety > 3)
     { tformat_string("... c_type(~S) -> ~S - ~S \n",2,list::alloc(3,v9268,
        _oid_(v5260),
        GC_OID(_oid_(sort_abstract_I_type(v5260)))));
      Result = sort_abstract_I_type(v5260);
      } 
    else Result = Kernel._any;
      GC_UNBIND; return (Result);} 
  } 

OID  c_code_For_Optimize(For *v9268,ClaireClass *v5259)
{ GC_BIND;
  { OID Result = 0;
    { OID  v15693 = GC_OID(v9268->set_arg);
      ClaireBoolean * v5242 = Optimize.OPT->protection;
      int  v15533 = Optimize.compiler->safety;
      Variable * v9945 = GC_OBJECT(Variable,v9268->var);
      Variable * v5263;
      { { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
          (v2072->pname = v9945->pname);
          (v2072->range = v9945->range);
          (v2072->index = v9945->index);
          add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
          v5263 = v2072;
          } 
        GC_OBJECT(Variable,v5263);} 
      OID  v4112 = GC_OID(substitution_any(GC_OID(v9268->arg),v9945,_oid_(v5263)));
      OID  v10811 = GC_OID(c_inline_arg_ask_any(v15693));
      (Optimize.OPT->protection = CFALSE);
      if (INHERIT(OWNER(v15693),Core._global_variable))
       { if (boolean_I_any(_oid_(OBJECT(global_variable,v15693)->range)) != CTRUE)
         { (v9268->set_arg = OBJECT(global_variable,v15693)->value);
          v15693= GC_OID(OBJECT(global_variable,v15693)->value);
          } 
        } 
      else if (INHERIT(OWNER(v15693),Language._Select))
       { ClaireType * v13271 = GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v15693)));
        if ((_inf_equal_type(v13271,Kernel._bag) != CTRUE) || 
            (_inf_equal_type(v13271,Kernel._set) == CTRUE))
         { v9268= GC_OBJECT(For,((For *) copy_object(v9268)));
          (v9268->isa = Language._Select);
          } 
        } 
      else if (INHERIT(OWNER(v15693),Kernel._class))
       { if ((OBJECT(ClaireClass,v15693)->open <= 1) && 
            (boolean_I_any(_oid_(OBJECT(ClaireClass,v15693)->subclass)) != CTRUE))
         { Iteration * v8585 = v9268; 
          OID  v8606;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.instances);
            (v2072->args = list::alloc(1,v15693));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v8606 = _oid_(v2072);
            } 
          (v8585->set_arg = v8606);} 
        } 
      { OID  v13271 = GC_OID((*Optimize.c_type)(GC_OID(v9268->set_arg)));
        ClaireType * v1851 = GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v13271)));
        ClaireType * v1852;
        { { ClaireType * v127;
            { { OID v15730;{ OID  v1088;
                  { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Kernel.set_I);
                    (v2072->args = list::alloc(1,v15693));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v1088 = _oid_(v2072);
                    } 
                  v15730 = (*Optimize.c_type)(v1088);
                  } 
                
                v127=OBJECT(ClaireType,v15730);} 
              GC_OBJECT(ClaireType,v127);} 
            v1852 = pmember_type(v127);
            } 
          GC_OBJECT(ClaireType,v1852);} 
        if (_inf_equal_type(v1852,v1851) == CTRUE)
         v1851= v1852;
        range_infers_for_Variable(v5263,v1851,OBJECT(ClaireType,v13271));
        (Optimize.compiler->safety = 1);
        v1851= GC_OBJECT(ClaireType,v5263->range);
        (v5263->range = ptype_type(v1851));
        { OID  v5253 = GC_OID(Iterate_I_Iteration(v9268));
          if (equal(_oid_(Kernel._method),_oid_(OWNER(v5253))) != CTRUE)
           { OID  v15437 = GC_OID(restriction_I_property(Language.iterate,list::alloc(3,v13271,
              _oid_(set::alloc(1,_oid_(v5263))),
              _oid_(Kernel._any)),CTRUE));
            if (Kernel._method == OWNER(v15437))
             v5253= v15437;
            } 
          (Optimize.compiler->safety = v15533);
          (v5263->range = v1851);
          { OID  v5258;
            { if ((Kernel._method == OWNER(v5253)) && (OBJECT(method,v5253)->inline_ask == CTRUE))
               { if ((Optimize.compiler->safety < 6) && 
                    (BCONTAIN(c_status_any(v4112,Kernel.nil),1)))
                 (Optimize.OPT->loop_gc = CTRUE);
                if (sort_abstract_ask_type(v5263->range) == CTRUE)
                 (v5263->range = CLREAD(Union,v5263->range,t2));
                v5258 = c_inline_method1(OBJECT(method,v5253),list::alloc(3,GC_OID(instruction_copy_any(GC_OID(v9268->set_arg))),
                  _oid_(v5263),
                  v4112),v5259);
                } 
              else if (boolean_I_any(v10811) == CTRUE)
               { OID  v2049;
                { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                  (v2072->var = v5263);
                  (v2072->set_arg = v10811);
                  (v2072->arg = v4112);
                  add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                  v2049 = _oid_(v2072);
                  } 
                v5258 = (*Optimize.c_code)(v2049,
                  _oid_(v5259));
                } 
              else if ((INHERIT(OWNER(v15693),Language._Call)) && (OBJECT(Call,v15693)->selector == Core.Id))
               v5258 = c_code_multiple_For(v9268,OBJECT(ClaireType,v13271),v5259);
              else { For * v15592;
                  { { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                      (v2072->var = v5263);
                      (v2072->set_arg = c_gc_I_any1(GC_OID(enumerate_code_any(GC_OID(v9268->set_arg),OBJECT(ClaireType,v13271)))));
                      (v2072->arg = (*Optimize.c_code)(v4112,
                        _oid_(Kernel._void)));
                      add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                      v15592 = v2072;
                      } 
                    GC_OBJECT(For,v15592);} 
                  if (v5259 == Kernel._any)
                   v5258 = _oid_(v15592);
                  else { Compile_to_C * v2072 = ((Compile_to_C *) GC_OBJECT(Compile_to_C,new_object_class(Optimize._to_C)));
                      (v2072->arg = _oid_(v15592));
                      (v2072->set_arg = v5259);
                      add_I_property(Kernel.instances,Optimize._to_C,11,_oid_(v2072));
                      v5258 = _oid_(v2072);
                      } 
                    } 
                GC_OID(v5258);} 
            if ((Optimize.OPT->protection == CTRUE) && 
                ((0 <= Optimize.OPT->loop_index) && 
                  (Optimize.compiler->safety < 6)))
             (Optimize.OPT->loop_gc = CTRUE);
            (Optimize.OPT->protection = ((Optimize.OPT->protection == CTRUE) ? CTRUE : ((v5242 == CTRUE) ? CTRUE : CFALSE)));
            Result = v5258;
            } 
          } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_multiple_For(For *v9268,ClaireType *v13271,ClaireClass *v5259)
{ GC_RESERVE(14);  // v3.0.55 optim !
  { OID Result = 0;
    { Variable * v5263 = GC_OBJECT(Variable,v9268->var);
      OID  v15693 = GC_OID((*(OBJECT(Call,v9268->set_arg)->args))[1]);
      Variable * v15716 = GC_OBJECT(Variable,Variable_I_symbol(append_symbol(v5263->pname,_string_("test")),v9268->var->index,v13271));
      Let * v5254;
      { { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
          (v2072->var = v15716);
          (v2072->value = v15693);
          { Let * v8610 = v2072; 
            OID  v8611;
            { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
              (v2072->var = v9268->var);
              (v2072->set_arg = enumerate_code_any(v15693,v13271));
              (v2072->arg = v9268->arg);
              add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
              v8611 = _oid_(v2072);
              } 
            (v8610->arg = v8611);} 
          add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
          v5254 = v2072;
          } 
        GC_OBJECT(Let,v5254);} 
      tformat_string("---- note: use an expended iteration for {~S} \n",0,list::alloc(1,_oid_(v9268)));
      { OID gc_local;
        ITERATE(v5258);
        for (START(Language.iterate->restrictions); NEXT(v5258);)
        { GC_LOOP;
          if ((_inf_equalt_class(domain_I_restriction(OBJECT(restriction,v5258)),v13271) == CTRUE) && 
              ((_inf_equalt_class(domain_I_restriction(OBJECT(restriction,v5258)),Kernel._collection) == CTRUE) && 
                ((OBJECT(method,v5258)->inline_ask == CTRUE) && 
                  (belong_to(_oid_(v5263),(*(OBJECT(restriction,v5258)->domain))[2]) == CTRUE))))
           { Variable * v8786;
            { { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
                (v2072->pname = v5263->pname);
                (v2072->range = v5263->range);
                (v2072->index = v5263->index);
                add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
                v8786 = v2072;
                } 
              GC_OBJECT(Variable,v8786);} 
            OID  v4112 = GC_OID(substitution_any(GC_OID(v9268->arg),v5263,_oid_(v8786)));
            { Let * v8612 = v5254; 
              OID  v8613;
              { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                { If * v8614 = v2072; 
                  OID  v8615;
                  { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Kernel._Z);
                    (v2072->args = list::alloc(2,_oid_(v15716),(*(OBJECT(restriction,v5258)->domain))[1]));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v8615 = _oid_(v2072);
                    } 
                  (v8614->test = v8615);} 
                { If * v8637 = v2072; 
                  OID  v8638;
                  { if ((Optimize.compiler->safety < 6) && 
                        (BCONTAIN(c_status_any(GC_OID(v9268->arg),Kernel.nil),1)))
                     (Optimize.OPT->loop_gc = CTRUE);
                    if (sort_abstract_ask_type(v8786->range) == CTRUE)
                     (v8786->range = CLREAD(Union,v5263->range,t2));
                    v8638 = c_inline_method1(OBJECT(method,v5258),GC_OBJECT(list,list::alloc(3,_oid_(v15716),
                      _oid_(v8786),
                      v4112)),v5259);
                    } 
                  (v8637->arg = v8638);} 
                (v2072->other = v5254->arg);
                add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                v8613 = _oid_(v2072);
                } 
              (v8612->arg = v8613);} 
            } 
          GC_UNLOOP;} 
        } 
      Result = (*Optimize.c_code)(_oid_(v5254),
        _oid_(v5259));
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Iteration(Iteration *v9268)
{ return (CTRUE);} 

ClaireType * c_type_Iteration_Optimize(Iteration *v9268)
{ GC_BIND;
  { ClaireType *Result ;
    { OID  v13271 = GC_OID((*Optimize.c_type)(GC_OID(v9268->set_arg)));
      range_infers_for_Variable(GC_OBJECT(Variable,v9268->var),GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v13271))),OBJECT(ClaireType,v13271));
      Result = ((get_property(Kernel.of,v9268) != CNULL) ?
        param_I_class((((INHERIT(v9268->isa,Language._Select)) || 
            (INHERIT(v9268->isa,Language._Image))) ?
          Kernel._set :
          Kernel._list ),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.of)(_oid_(v9268))))) :
        nth_class1((((INHERIT(v9268->isa,Language._Select)) || 
            (INHERIT(v9268->isa,Language._Image))) ?
          Kernel._set :
          Kernel._list ),GC_OBJECT(ClaireType,(((INHERIT(v9268->isa,Language._Select)) || 
            (INHERIT(v9268->isa,Language._Lselect))) ?
          pmember_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9268->set_arg))))) :
          ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9268->arg)))) ))) );
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Iteration_Optimize(Iteration *v9268)
{ GC_BIND;
  { OID Result = 0;
    { OID  v15693 = GC_OID(v9268->set_arg);
      OID  v13271 = GC_OID((*Optimize.c_type)(v15693));
      if (INHERIT(v9268->isa,Language._For))
       Result = (*Optimize.c_code)(_oid_(v9268),
        _oid_(Kernel._any));
      else if ((INHERIT(v9268->isa,Language._Collect)) && (_inf_equal_type(OBJECT(ClaireType,v13271),Kernel._bag) == CTRUE))
       { (Optimize.OPT->allocation = CTRUE);
        range_infers_for_Variable(GC_OBJECT(Variable,v9268->var),GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v13271))),OBJECT(ClaireType,v13271));
        { ClaireType * v15725 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9268->arg)))));
          Collect * v5264;
          { { Collect * v2072 = ((Collect *) GC_OBJECT(Collect,new_object_class(Language._Collect)));
              (v2072->var = v9268->var);
              (v2072->set_arg = c_gc_I_any1(GC_OID(c_strict_code_any(v15693,Kernel._bag))));
              (v2072->arg = (*Optimize.c_code)(GC_OID(v9268->arg),
                _oid_(Kernel._any)));
              add_I_property(Kernel.instances,Language._Collect,11,_oid_(v2072));
              v5264 = v2072;
              } 
            GC_OBJECT(Collect,v5264);} 
          if (v15725 == Kernel._void)
           (*Optimize.Cerror)(_string_("[205] use of void expression ~S in ~S"),
            GC_OID(v9268->arg),
            _oid_(v9268));
          if (get_property(Kernel.of,v9268) != CNULL)
           { if ((Optimize.compiler->safety > 4) || 
                (_inf_equal_type(v15725,GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.of)(_oid_(v9268))))) == CTRUE))
             { update_property(Kernel.of,
                v5264,
                5,
                Kernel._object,
                GC_OID((*Kernel.of)(_oid_(v9268))));
              Result = _oid_(v5264);
              } 
            else { warn_void();
                tformat_string("unsafe typed collect (~S): ~S not in ~S [261]\n",2,list::alloc(3,_oid_(v9268),
                  GC_OID((*Optimize.c_type)(GC_OID(v9268->arg))),
                  GC_OID((*Kernel.of)(_oid_(v9268)))));
                { OID  v15457;
                  { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Core.check_in);
                    (v2072->args = list::alloc(3,_oid_(v5264),
                      _oid_(Kernel._list),
                      GC_OID((*Kernel.of)(_oid_(v9268)))));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v15457 = _oid_(v2072);
                    } 
                  Result = (*Optimize.c_code)(v15457,
                    _oid_(Kernel._list));
                  } 
                } 
              } 
          else Result = _oid_(v5264);
            } 
        } 
      else { OID  v13625;
          if (INHERIT(v9268->isa,Language._Image))
           v13625 = _oid_(set::empty());
          else v13625 = _oid_(list::empty());
            Variable * v5263;
          { { int  v33;
              { (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+1));
                v33 = 0;
                } 
              v5263 = Variable_I_symbol(append_symbol(v9268->var->pname,_string_("_bag")),v33,((INHERIT(v9268->isa,Language._Image)) ?
                Kernel._set :
                Kernel._list ));
              } 
            GC_OBJECT(Variable,v5263);} 
          if (get_property(Kernel.of,v9268) != CNULL)
           { ClaireType * v9340 = GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9268->arg))));
            if ((_inf_equal_type(ptype_type(v9340),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.of)(_oid_(v9268))))) != CTRUE) && 
                (Optimize.compiler->safety <= 4))
             { warn_void();
              tformat_string("unsafe bag construction (~S) : a ~S is not a ~S [262]\n",2,list::alloc(3,GC_OID(_oid_(v9268->var)),
                _oid_(v9340),
                GC_OID((*Kernel.of)(_oid_(v9268)))));
              } 
            cast_I_bag(OBJECT(bag,v13625),OBJECT(ClaireType,(*Kernel.of)(_oid_(v9268))));
            (v5263->range = param_I_class(GC_OBJECT(ClaireClass,((ClaireClass *) v5263->range)),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.of)(_oid_(v9268))))));
            } 
          else if (Kernel._set == OWNER(v13625))
             { Set * v2072 = ((Set *) GC_OBJECT(Set,new_object_class(Language._Set)));
              (v2072->of = Kernel.emptySet);
              add_I_property(Kernel.instances,Language._Set,11,_oid_(v2072));
              v13625 = _oid_(v2072);
              } 
            else { List * v2072 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
                (v2072->of = Kernel.emptySet);
                add_I_property(Kernel.instances,Language._List,11,_oid_(v2072));
                v13625 = _oid_(v2072);
                } 
              { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
            (v2072->var = v5263);
            (v2072->value = v13625);
            { Let * v8642 = v2072; 
              OID  v8643;
              { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                { Do * v8644 = v2072; 
                  list * v8645;
                  { OID v_bag;
                    GC_ANY(v8645= list::empty(Kernel.emptySet));
                    { { OID  v4838;
                        { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                          (v2072->var = v9268->var);
                          (v2072->set_arg = v15693);
                          { Iteration * v8668 = v2072; 
                            OID  v8669;
                            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                              (v2072->selector = Kernel.add_I);
                              (v2072->args = list::alloc(2,_oid_(v5263),GC_OID(v9268->arg)));
                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                              v8669 = _oid_(v2072);
                              } 
                            (v8668->arg = v8669);} 
                          add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                          v4838 = _oid_(v2072);
                          } 
                        v_bag = (*Optimize.c_code)(v4838,
                          _oid_(Kernel._any));
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v8645)->addFast(v_bag);
                    if (Optimize.OPT->online_ask != CTRUE)
                     { (Optimize.OPT->protection = CTRUE);
                      { Compile_to_protect * v2072 = ((Compile_to_protect *) GC_OBJECT(Compile_to_protect,new_object_class(Optimize._to_protect)));
                        (v2072->arg = _oid_(v5263));
                        add_I_property(Kernel.instances,Optimize._to_protect,11,_oid_(v2072));
                        v_bag = _oid_(v2072);
                        } 
                      } 
                    else v_bag = _oid_(v5263);
                      ((list *) v8645)->addFast(v_bag);} 
                  (v8644->args = v8645);} 
                add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                v8643 = _oid_(v2072);
                } 
              (v8642->arg = v8643);} 
            add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
            Result = _oid_(v2072);
            } 
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Select_Optimize(Select *v9268)
{ return (c_code_select_Iteration(v9268,Kernel._set));} 

OID  c_code_Lselect_Optimize(Lselect *v9268)
{ return (c_code_select_Iteration(v9268,Kernel._list));} 

OID  c_code_select_Iteration(Iteration *v9268,ClaireClass *v5264)
{ GC_BIND;
  { OID Result = 0;
    { OID  v15693 = GC_OID(v9268->set_arg);
      OID  v13271 = GC_OID((*Optimize.c_type)(v15693));
      OID  v15689 = GC_OID(enumerate_code_any(v15693,OBJECT(ClaireType,v13271)));
      bag * v13625;
      if (v5264 == Kernel._set)
       v13625 = set::empty();
      else v13625 = list::empty();
        Variable * v15715;
      { { int  v13440;
          { (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+1));
            v13440 = 0;
            } 
          v15715 = Variable_I_symbol(append_symbol(v9268->var->pname,_string_("_in")),v13440,Kernel._bag);
          } 
        GC_OBJECT(Variable,v15715);} 
      Variable * v15716;
      { { int  v14402;
          { (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+1));
            v14402 = 0;
            } 
          v15716 = Variable_I_symbol(append_symbol(v9268->var->pname,_string_("_out")),v14402,v5264);
          } 
        GC_OBJECT(Variable,v15716);} 
      if (get_property(Kernel.of,v9268) != CNULL)
       { ClaireType * v9340 = GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v13271)));
        if ((_inf_equal_type(ptype_type(v9340),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.of)(_oid_(v9268))))) != CTRUE) && 
            (Optimize.compiler->safety <= 4))
         { warn_void();
          tformat_string("unsafe bag construction (~S) : a ~S is not a ~S [262]\n",2,list::alloc(3,GC_OID(_oid_(v9268->var)),
            _oid_(v9340),
            GC_OID((*Kernel.of)(_oid_(v9268)))));
          } 
        cast_I_bag(v13625,OBJECT(ClaireType,(*Kernel.of)(_oid_(v9268))));
        (v15716->range = param_I_class(v5264,GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.of)(_oid_(v9268))))));
        Result = inner_select_Iteration(v9268,_oid_(v15716),v15693,_oid_(v13625));
        } 
      else if (_inf_equal_type(OBJECT(ClaireType,v13271),v5264) == CTRUE)
       { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
        (v2072->var = v15715);
        (v2072->value = v15689);
        { Let * v8674 = v2072; 
          OID  v8675;
          { OID  v900;
            { Compile_C_cast * v2072 = ((Compile_C_cast *) GC_OBJECT(Compile_C_cast,new_object_class(Optimize._C_cast)));
              { Compile_to_C * v8677 = v2072; 
                OID  v8699;
                { OID  v7580;
                  { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Kernel.empty);
                    (v2072->args = list::alloc(1,_oid_(v15715)));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v7580 = _oid_(v2072);
                    } 
                  v8699 = (*Optimize.c_code)(v7580,
                    _oid_(Kernel._bag));
                  } 
                (v8677->arg = v8699);} 
              (v2072->set_arg = v5264);
              add_I_property(Kernel.instances,Optimize._C_cast,11,_oid_(v2072));
              v900 = _oid_(v2072);
              } 
            v8675 = inner_select_Iteration(v9268,_oid_(v15716),_oid_(v15715),v900);
            } 
          (v8674->arg = v8675);} 
        add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      else { OID  v8541;
          if (v5264 == Kernel._set)
           { Set * v2072 = ((Set *) GC_OBJECT(Set,new_object_class(Language._Set)));
            (v2072->of = Kernel.emptySet);
            add_I_property(Kernel.instances,Language._Set,11,_oid_(v2072));
            v8541 = _oid_(v2072);
            } 
          else { List * v2072 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
              (v2072->of = Kernel.emptySet);
              add_I_property(Kernel.instances,Language._List,11,_oid_(v2072));
              v8541 = _oid_(v2072);
              } 
            Result = inner_select_Iteration(v9268,_oid_(v15716),v15693,v8541);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  inner_select_Iteration(Iteration *v9268,OID v15716,OID v15693,OID v13625)
{ GC_BIND;
  { OID Result = 0;
    { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
      store_object(v2072,
        2,
        Kernel._object,
        v15716,
        CFALSE);
      (v2072->value = v13625);
      { Let * v8703 = v2072; 
        OID  v8704;
        { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
          { Do * v8705 = v2072; 
            list * v8706;
            { OID v_bag;
              GC_ANY(v8706= list::empty(Kernel.emptySet));
              { { OID  v13346;
                  { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                    (v2072->var = v9268->var);
                    (v2072->set_arg = v15693);
                    { Iteration * v8708 = v2072; 
                      OID  v8709;
                      { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                        (v2072->test = v9268->arg);
                        { If * v8730 = v2072; 
                          OID  v8732;
                          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                            (v2072->selector = Kernel.add_I);
                            (v2072->args = list::alloc(2,v15716,GC_OID(_oid_(v9268->var))));
                            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                            v8732 = _oid_(v2072);
                            } 
                          (v8730->arg = v8732);} 
                        add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                        (v2072->other = Kernel.cfalse);
                        v8709 = _oid_(v2072);
                        } 
                      (v8708->arg = v8709);} 
                    add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                    v13346 = _oid_(v2072);
                    } 
                  v_bag = (*Optimize.c_code)(v13346,
                    _oid_(Kernel._any));
                  } 
                GC_OID(v_bag);} 
              ((list *) v8706)->addFast(v_bag);
              if (Optimize.OPT->online_ask != CTRUE)
               { (Optimize.OPT->protection = CTRUE);
                { Compile_to_protect * v2072 = ((Compile_to_protect *) GC_OBJECT(Compile_to_protect,new_object_class(Optimize._to_protect)));
                  (v2072->arg = v15716);
                  add_I_property(Kernel.instances,Optimize._to_protect,11,_oid_(v2072));
                  v_bag = _oid_(v2072);
                  } 
                } 
              else v_bag = v15716;
                ((list *) v8706)->addFast(v_bag);} 
            (v8705->args = v8706);} 
          add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
          v8704 = _oid_(v2072);
          } 
        (v8703->arg = v8704);} 
      add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Exists_Optimize(Exists *v9268)
{ GC_BIND;
  { ClaireType *Result ;
    { OID  v13271 = GC_OID((*Optimize.c_type)(GC_OID(v9268->set_arg)));
      range_infers_for_Variable(GC_OBJECT(Variable,v9268->var),GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v13271))),OBJECT(ClaireType,v13271));
      if (v9268->other == CNULL)
       Result = extends_type(GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v13271))));
      else Result = Kernel._boolean;
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Exists_Optimize(Exists *v9268,ClaireClass *v5259)
{ GC_BIND;
  { OID Result = 0;
    { OID  v13271 = GC_OID((*Optimize.c_type)(GC_OID(v9268->set_arg)));
      range_infers_for_Variable(GC_OBJECT(Variable,v9268->var),GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v13271))),OBJECT(ClaireType,v13271));
      if (v9268->other == Kernel.ctrue)
       { OID  v6525;
        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v2072->selector = Core.NOT);
          { Call * v8735 = v2072; 
            list * v8736;
            { OID v_bag;
              GC_ANY(v8736= list::empty(Kernel.emptySet));
              { { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                  (v2072->var = v9268->var);
                  (v2072->set_arg = v9268->set_arg);
                  { Iteration * v8737 = v2072; 
                    OID  v8738;
                    { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                      { If * v8739 = v2072; 
                        OID  v8740;
                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v2072->selector = Core.NOT);
                          (v2072->args = list::alloc(1,GC_OID(v9268->arg)));
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                          v8740 = _oid_(v2072);
                          } 
                        (v8739->test = v8740);} 
                      { If * v8762 = v2072; 
                        OID  v8763;
                        { Return * v2072 = ((Return *) GC_OBJECT(Return,new_object_class(Language._Return)));
                          (v2072->arg = Kernel.ctrue);
                          add_I_property(Kernel.instances,Language._Return,11,_oid_(v2072));
                          v8763 = _oid_(v2072);
                          } 
                        (v8762->arg = v8763);} 
                      add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                      (v2072->other = Kernel.cfalse);
                      v8738 = _oid_(v2072);
                      } 
                    (v8737->arg = v8738);} 
                  add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                  v_bag = _oid_(v2072);
                  } 
                GC_OID(v_bag);} 
              ((list *) v8736)->addFast(v_bag);} 
            (v8735->args = v8736);} 
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
          v6525 = _oid_(v2072);
          } 
        Result = (*Optimize.c_code)(v6525,
          _oid_(v5259));
        } 
      else if (v9268->other == CNULL)
       { Variable * v5263;
        { { int  v2587;
            { (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+1));
              v2587 = 0;
              } 
            v5263 = Variable_I_symbol(append_symbol(v9268->var->pname,_string_("_some")),v2587,GC_OBJECT(ClaireType,extends_type(GC_OBJECT(ClaireType,v9268->var->range))));
            } 
          GC_OBJECT(Variable,v5263);} 
        { OID  v3548;
          { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
            (v2072->var = v5263);
            (v2072->value = CNULL);
            { Let * v8766 = v2072; 
              OID  v8767;
              { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                { Do * v8768 = v2072; 
                  list * v8769;
                  { OID v_bag;
                    GC_ANY(v8769= list::empty(Kernel.emptySet));
                    { { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                        (v2072->var = v9268->var);
                        (v2072->set_arg = v9268->set_arg);
                        { Iteration * v8770 = v2072; 
                          OID  v8771;
                          { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                            (v2072->test = v9268->arg);
                            { If * v8792 = v2072; 
                              OID  v8793;
                              { Return * v2072 = ((Return *) GC_OBJECT(Return,new_object_class(Language._Return)));
                                { Return * v8796 = v2072; 
                                  OID  v8797;
                                  { Assign * v2072 = ((Assign *) GC_OBJECT(Assign,new_object_class(Language._Assign)));
                                    (v2072->var = _oid_(v5263));
                                    (v2072->arg = _oid_(v9268->var));
                                    add_I_property(Kernel.instances,Language._Assign,11,_oid_(v2072));
                                    v8797 = _oid_(v2072);
                                    } 
                                  (v8796->arg = v8797);} 
                                add_I_property(Kernel.instances,Language._Return,11,_oid_(v2072));
                                v8793 = _oid_(v2072);
                                } 
                              (v8792->arg = v8793);} 
                            add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                            (v2072->other = Kernel.cfalse);
                            v8771 = _oid_(v2072);
                            } 
                          (v8770->arg = v8771);} 
                        add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                        v_bag = _oid_(v2072);
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v8769)->addFast(v_bag);
                    ((list *) v8769)->addFast(_oid_(v5263));} 
                  (v8768->args = v8769);} 
                add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                v8767 = _oid_(v2072);
                } 
              (v8766->arg = v8767);} 
            add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
            v3548 = _oid_(v2072);
            } 
          Result = (*Optimize.c_code)(v3548,
            _oid_(v5259));
          } 
        } 
      else { OID  v1532;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.boolean_I);
            { Call * v8800 = v2072; 
              list * v8801;
              { OID v_bag;
                GC_ANY(v8801= list::empty(Kernel.emptySet));
                { { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                    (v2072->var = v9268->var);
                    (v2072->set_arg = v9268->set_arg);
                    { Iteration * v8802 = v2072; 
                      OID  v8803;
                      { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                        (v2072->test = v9268->arg);
                        { If * v8804 = v2072; 
                          OID  v9474;
                          { Return * v2072 = ((Return *) GC_OBJECT(Return,new_object_class(Language._Return)));
                            (v2072->arg = Kernel.ctrue);
                            add_I_property(Kernel.instances,Language._Return,11,_oid_(v2072));
                            v9474 = _oid_(v2072);
                            } 
                          (v8804->arg = v9474);} 
                        add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                        (v2072->other = Kernel.cfalse);
                        v8803 = _oid_(v2072);
                        } 
                      (v8802->arg = v8803);} 
                    add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                    v_bag = _oid_(v2072);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v8801)->addFast(v_bag);} 
              (v8800->args = v8801);} 
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v1532 = _oid_(v2072);
            } 
          Result = (*Optimize.c_code)(v1532,
            _oid_(v5259));
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Image_Optimize(Image *v9268)
{ GC_BIND;
  { ClaireType *Result ;
    { ClaireType * v13271 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9268->set_arg)))));
      range_infers_for_Variable(GC_OBJECT(Variable,v9268->var),GC_OBJECT(ClaireType,pmember_type(v13271)),v13271);
      Result = ((((v9268->of == (NULL)) ? CTRUE : CFALSE) != CTRUE) ?
        param_I_class(Kernel._set,GC_OBJECT(ClaireType,v9268->of)) :
        nth_class1(Kernel._set,GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9268->arg))))) );
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Select_Optimize(Select *v9268)
{ GC_BIND;
  { ClaireType *Result ;
    { OID  v13271 = GC_OID((*Optimize.c_type)(GC_OID(v9268->set_arg)));
      range_infers_for_Variable(GC_OBJECT(Variable,v9268->var),GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v13271))),OBJECT(ClaireType,v13271));
      Result = ((((v9268->of == (NULL)) ? CTRUE : CFALSE) != CTRUE) ?
        param_I_class(Kernel._set,GC_OBJECT(ClaireType,v9268->of)) :
        nth_class1(Kernel._set,GC_OBJECT(ClaireType,pmember_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9268->set_arg))))))) );
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Lselect_Optimize(Lselect *v9268)
{ GC_BIND;
  { ClaireType *Result ;
    { OID  v13271 = GC_OID((*Optimize.c_type)(GC_OID(v9268->set_arg)));
      range_infers_for_Variable(GC_OBJECT(Variable,v9268->var),GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v13271))),OBJECT(ClaireType,v13271));
      Result = ((((v9268->of == (NULL)) ? CTRUE : CFALSE) != CTRUE) ?
        param_I_class(Kernel._list,GC_OBJECT(ClaireType,v9268->of)) :
        nth_class1(Kernel._list,GC_OBJECT(ClaireType,pmember_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9268->set_arg))))))) );
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_While_Optimize(While *v9268)
{ GC_BIND;
  { ClaireType *Result ;
    Result = infers_from_type2(GC_OBJECT(ClaireType,return_type_any(GC_OID(v9268->arg))),_oid_(v9268));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_While_Optimize(While *v9268,ClaireClass *v5259)
{ GC_BIND;
  { OID Result = 0;
    { ClaireBoolean * v5242 = Optimize.OPT->protection;
      (Optimize.OPT->protection = CFALSE);
      { While * v5258;
        { { While * v2072 = ((While *) GC_OBJECT(While,new_object_class(Language._While)));
            (v2072->test = c_boolean_any(GC_OID(v9268->test)));
            (v2072->arg = (*Optimize.c_code)(GC_OID(v9268->arg),
              _oid_(Kernel._void)));
            (v2072->other = v9268->other);
            add_I_property(Kernel.instances,Language._While,11,_oid_(v2072));
            v5258 = v2072;
            } 
          GC_OBJECT(While,v5258);} 
        if ((Optimize.OPT->protection == CTRUE) && 
            (0 <= Optimize.OPT->loop_index))
         (Optimize.OPT->loop_gc = CTRUE);
        (Optimize.OPT->protection = ((Optimize.OPT->protection == CTRUE) ? CTRUE : ((v5242 == CTRUE) ? CTRUE : CFALSE)));
        if ((v5259 != Kernel._void) && 
            (v5259 != Kernel._any))
         { { Compile_to_C * v2072 = ((Compile_to_C *) GC_OBJECT(Compile_to_C,new_object_class(Optimize._to_C)));
            (v2072->arg = _oid_(v5258));
            (v2072->set_arg = v5259);
            add_I_property(Kernel.instances,Optimize._to_C,11,_oid_(v2072));
            Result = _oid_(v2072);
            } 
          } 
        else Result = _oid_(v5258);
          } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Iterate_I_Iteration(Iteration *v9268)
{ GC_BIND;
  { OID Result = 0;
    Result = restriction_I_property(Language.Iterate,list::alloc(3,_oid_(set::alloc(1,GC_OID(v9268->set_arg))),
      _oid_(set::alloc(1,GC_OID(_oid_(v9268->var)))),
      _oid_(Kernel._any)),CTRUE);
    GC_UNBIND; return (Result);} 
  } 

OID  iterate_Interval(Interval *v5264,Variable *v5263,OID v5245)
{ GC_BIND;
  { OID Result = 0;
    { OID  v5263 = GC_OID(eval_any2(v5264->arg1,Core._Interval));
      int  v3080 = eval_any2(v5264->arg2,Core._Interval);
      { Result= _oid_(CFALSE);
        while ((v5263 <= v3080))
        { ;v5263= ((v5263)+1);
          } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  iterate_array(OID *v5264,Variable *v5263,OID v5245)
{ { OID Result = 0;
    { int  v13260 = 1;
      OID * v13253 = v5264;
      int  v3080 = v13253[0];
      { Result= _oid_(CFALSE);
        while ((v13260 <= v3080))
        { { OID  v5263 = nth_array(v13253,v13260);
            ;++v13260;
            } 
          } 
        } 
      } 
    return (Result);} 
  } 

OID  Iterate_class(ClaireClass *v5264,Variable *v5263,OID v5245)
{ { OID Result = 0;
    { ITERATE(v11595);
      Result= _oid_(CFALSE);
      for (START(v5264->descendents); NEXT(v11595);)
      { ClaireBoolean * v11596;
        { OID v15730;{ ITERATE(v5263);
            v15730= _oid_(CFALSE);
            for (START(OBJECT(ClaireClass,v11595)->instances); NEXT(v5263);)
            ;} 
          
          v11596=OBJECT(ClaireBoolean,v15730);} 
        if (v11596 == CTRUE)
         { Result = _oid_(v11596);
          break;} 
        } 
      } 
    return (Result);} 
  } 

OID  Iterate_any1(OID v5264,Variable *v5263,OID v5245)
{ GC_BIND;
  { OID Result = 0;
    { OID  v5263 = GC_OID(OPT_EVAL((*(OBJECT(Call,v5264)->args))[1]));
      OID  v3080 = GC_OID(OPT_EVAL((*(OBJECT(Call,v5264)->args))[2]));
      { Result= _oid_(CFALSE);
        while (((OBJECT(ClaireBoolean,(*Kernel._inf_equal)(v5263,
          v3080))) == CTRUE))
        { ;v5263= ((v5263)+1);
          } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Iterate_Lselect(Lselect *v5264,Variable *v5263,OID v5245)
{ GC_BIND;
  { OID Result = 0;
    { OID gc_local;
      ITERATE(v5263);
      Result= _oid_(CFALSE);
      bag *v5263_support;
      v5263_support = GC_OBJECT(bag,enumerate_any(GC_OID(eval_any(GC_OID(v5264->set_arg)))));
      for (START(v5263_support); NEXT(v5263);)
      { GC_LOOP;
        if (boolean_I_any(eval_any(GC_OID(substitution_any(GC_OID(v5264->arg),GC_OBJECT(Variable,v5264->var),v5263)))) == CTRUE)
         ;GC_UNLOOP;} 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Iterate_Select(Select *v5264,Variable *v5263,OID v5245)
{ GC_BIND;
  { OID Result = 0;
    { OID gc_local;
      ITERATE(v5263);
      Result= _oid_(CFALSE);
      bag *v5263_support;
      v5263_support = GC_OBJECT(bag,enumerate_any(GC_OID(eval_any(GC_OID(v5264->set_arg)))));
      for (START(v5263_support); NEXT(v5263);)
      { GC_LOOP;
        if (boolean_I_any(eval_any(GC_OID(substitution_any(GC_OID(v5264->arg),GC_OBJECT(Variable,v5264->var),v5263)))) == CTRUE)
         ;GC_UNLOOP;} 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Iterate_Collect(Collect *v5264,Variable *v5263,OID v5245)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID Result = 0;
    { OID gc_local;
      ITERATE(v11916);
      Result= _oid_(CFALSE);
      bag *v11916_support;
      v11916_support = GC_OBJECT(bag,enumerate_any(GC_OID(eval_any(GC_OID(v5264->set_arg)))));
      for (START(v11916_support); NEXT(v11916);)
      { GC_LOOP;
        { OID  v5263 = GC_OID(eval_any(GC_OID(substitution_any(GC_OID(v5264->arg),GC_OBJECT(Variable,v5264->var),v11916))));
          ;} 
        GC_UNLOOP;} 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Iterate_any2(OID v5264,Variable *v5263,OID v5245)
{ GC_BIND;
  { OID Result = 0;
    { OID gc_local;
      ITERATE(v5263);
      Result= _oid_(CFALSE);
      bag *v5263_support;
      v5263_support = GC_OBJECT(bag,enumerate_any(GC_OID(OPT_EVAL((*(OBJECT(Call,v5264)->args))[1]))));
      for (START(v5263_support); NEXT(v5263);)
      { GC_LOOP;
        if (equal(v5263,OPT_EVAL((*(OBJECT(Call,v5264)->args))[2])) != CTRUE)
         ;GC_UNLOOP;} 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Iterate_any3(OID v5264,Variable *v5263,OID v5245)
{ GC_BIND;
  { OID gc_local;
    ITERATE(v5263);
    bag *v5263_support;
    v5263_support = GC_OBJECT(bag,enumerate_any(GC_OID(OPT_EVAL((*(OBJECT(Call,v5264)->args))[1]))));
    for (START(v5263_support); NEXT(v5263);)
    ;} 
  { OID Result = 0;
    { OID gc_local;
      ITERATE(v5263);
      Result= _oid_(CFALSE);
      bag *v5263_support;
      v5263_support = GC_OBJECT(bag,enumerate_any(GC_OID(OPT_EVAL((*(OBJECT(Call,v5264)->args))[2]))));
      for (START(v5263_support); NEXT(v5263);)
      ;} 
    GC_UNBIND; return (Result);} 
  } 

