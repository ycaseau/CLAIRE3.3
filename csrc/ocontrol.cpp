/***** CLAIRE Compilation of file c:\claire\v3.3\src\compile\ocontrol.cl 
         [version 3.3.46 / safety 5] Sun Feb 15 15:37:26 2009 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
ClaireType * c_type_Assign_Optimize(Assign *v2164)
{ GC_BIND;
  { ClaireType *Result ;
    Result = OBJECT(ClaireType,(*Optimize.c_type)(v2164->arg));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Assign_Optimize(Assign *v2164)
{ GC_BIND;
  { OID Result = 0;
    { OID  v6222 = GC_OID(v2164->var);
      OID  v6224 = GC_OID(v2164->arg);
      ClaireType * v8375 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v6224))));
      if (inherit_ask_class(OWNER(v6222),Language._Variable) != CTRUE)
       (*Optimize.Cerror)(_string_(copy_string("[213] ~S is not a variable")),
        v6222);
      if (_oid_((ClaireObject *) Core._inf_equalt->fcall(((int) v8375),((int) OBJECT(ClaireObject,GC_OID((*Kernel.range)(v6222)))))) != Kernel.ctrue)
       v6224= GC_OID((*Optimize.c_warn)(GC_OID(v2164->var),
        v6224,
        _oid_(v8375)));
      { OID  v1337 = GC_OID(c_gc_I_any2(GC_OID(c_strict_code_any(v6224,psort_any(GC_OID((*Kernel.range)(v6222))))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel._exp)(GC_OID((*Kernel.range)(v6222)),
          _oid_(v8375))))));
        gc_register_Variable2(OBJECT(Variable,v6222),v1337);
        { Assign * v2072 = ((Assign *) GC_OBJECT(Assign,new_object_class(Language._Assign)));
          (v2072->var = v6222);
          (v2072->arg = v1337);
          add_I_property(Kernel.instances,Language._Assign,11,_oid_(v2072));
          Result = _oid_(v2072);
          } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Assign(Assign *v2164)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v2164->arg));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Gassign_Optimize(Gassign *v2164)
{ GC_BIND;
  { ClaireType *Result ;
    Result = OBJECT(ClaireType,(*Optimize.c_type)(v2164->arg));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Gassign_Optimize(Gassign *v2164)
{ GC_BIND;
  { OID Result = 0;
    { OID  v10265 = GC_OID(v2164->arg);
      ClaireType * v8375 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v10265))));
      if (boolean_I_any(_oid_(v2164->var->range)) != CTRUE)
       (*Optimize.Cerror)(_string_(copy_string("[214] cannot assign ~S")),
        _oid_(v2164));
      if (_oid_((ClaireObject *) Core._inf_equalt->fcall(((int) v8375),((int) v2164->var->range))) != Kernel.ctrue)
       v10265= GC_OID(c_check_any(GC_OID((*Optimize.c_code)(v10265,
        _oid_(Kernel._any))),GC_OID((*Optimize.c_code)(_oid_(v2164->var->range),
        _oid_(Kernel._type)))));
      { Gassign * v2072 = ((Gassign *) GC_OBJECT(Gassign,new_object_class(Language._Gassign)));
        store_object(v2072,
          2,
          Kernel._object,
          (*Optimize.c_code)(_oid_(v2164->var)),
          CFALSE);
        { Gassign * v7711 = v2072; 
          OID  v7712;
          if (nativeVar_ask_global_variable(v2164->var) == CTRUE)
           v7712 = c_strict_code_any(v10265,psort_any(_oid_(v2164->var->range)));
          else v7712 = (*Optimize.c_code)(v10265,
              _oid_(Kernel._any));
            (v7711->arg = v7712);} 
        add_I_property(Kernel.instances,Language._Gassign,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Gassign(Gassign *v2164)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v2164->arg));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_And_Optimize(And *v2164)
{ return (Kernel._boolean);} 

OID  c_code_And_Optimize(And *v2164)
{ GC_BIND;
  { OID Result = 0;
    { And * v2072 = ((And *) GC_OBJECT(And,new_object_class(Language._And)));
      { And * v7713 = v2072; 
        list * v7714;
        { bag *v_list; OID v_val;
          OID v6224,CLcount;
          v_list = GC_OBJECT(list,v2164->args);
           v7714 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v6224 = (*(v_list))[CLcount];
            { if ((*Optimize.c_type)(v6224) == _oid_(Kernel._void))
               (*Optimize.Cerror)(_string_(copy_string("[206] void ~S in ~S")),
                v6224,
                _oid_(v2164));
              v_val = c_boolean_any(v6224);
              } 
            
            (*((list *) v7714))[CLcount] = v_val;} 
          } 
        (v7713->args = v7714);} 
      add_I_property(Kernel.instances,Language._And,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Or_Optimize(Or *v2164)
{ return (Kernel._boolean);} 

OID  c_code_Or_Optimize(Or *v2164)
{ GC_BIND;
  { OID Result = 0;
    { Or * v2072 = ((Or *) GC_OBJECT(Or,new_object_class(Language._Or)));
      { Or * v7715 = v2072; 
        list * v7716;
        { bag *v_list; OID v_val;
          OID v6224,CLcount;
          v_list = GC_OBJECT(list,v2164->args);
           v7716 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v6224 = (*(v_list))[CLcount];
            { if ((*Optimize.c_type)(v6224) == _oid_(Kernel._void))
               (*Optimize.Cerror)(_string_(copy_string("[206] void ~S in ~S")),
                v6224,
                _oid_(v2164));
              v_val = c_boolean_any(v6224);
              } 
            
            (*((list *) v7716))[CLcount] = v_val;} 
          } 
        (v7715->args = v7716);} 
      add_I_property(Kernel.instances,Language._Or,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Quote_Optimize(Quote *v2164)
{ return (OWNER(v2164->arg));} 

void  c_code_Quote_Optimize(Quote *v2164)
{ (*Optimize.Cerror)(_string_("[internal] optimization of quote not implemented yet! ~S"),
    _oid_(v2164));
  } 

ClaireType * c_type_to_protect_Optimize(Compile_to_protect *v2164)
{ GC_BIND;
  { ClaireType *Result ;
    Result = OBJECT(ClaireType,(*Optimize.c_type)(v2164->arg));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_to_protect_Optimize(Compile_to_protect *v2164)
{ return (_oid_(v2164));} 

ClaireBoolean * c_gc_ask_to_protect(Compile_to_protect *v2164)
{ return (CFALSE);} 

ClaireType * c_type_Return_Optimize(Return *v2164)
{ return (Kernel._any);} 

OID  c_code_Return_Optimize(Return *v2164)
{ GC_BIND;
  (Optimize.OPT->loop_gc = CFALSE);
  { OID Result = 0;
    { Return * v2072 = ((Return *) GC_OBJECT(Return,new_object_class(Language._Return)));
      (v2072->arg = (*Optimize.c_code)(GC_OID(v2164->arg),
        _oid_(Kernel._any)));
      add_I_property(Kernel.instances,Language._Return,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Handle_Optimize(ClaireHandle *v2164)
{ GC_BIND;
  { ClaireType *Result ;
    Result = U_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v2164->arg)))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v2164->other)))));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Handle_Optimize(ClaireHandle *v2164,ClaireClass *v6219)
{ GC_BIND;
  { OID Result = 0;
    { ClaireHandle * v6224;
      { { ClaireHandle * v2072 = ((ClaireHandle *) GC_OBJECT(ClaireHandle,new_object_class(Language._Handle)));
          (v2072->test = _oid_(Kernel._any));
          (v2072->arg = (*Optimize.c_code)(GC_OID(v2164->arg),
            _oid_(v6219)));
          (v2072->other = (*Optimize.c_code)(GC_OID(v2164->other),
            _oid_(v6219)));
          add_I_property(Kernel.instances,Language._Handle,11,_oid_(v2072));
          v6224 = v2072;
          } 
        GC_OBJECT(ClaireHandle,v6224);} 
      if (v2164->test != _oid_(Core._contradiction))
       (Optimize.OPT->allocation = CTRUE);
      (v6224->test = v2164->test);
      Result = _oid_(v6224);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Handle(ClaireHandle *v2164)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = (((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v2164->arg))) == CTRUE) ? CTRUE : (((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v2164->other))) == CTRUE) ? CTRUE : CFALSE));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Cast_Optimize(Cast *v2164)
{ return (v2164->set_arg);} 

OID  c_code_Cast_Optimize(Cast *v2164)
{ GC_BIND;
  { OID Result = 0;
    { ClaireType * v6225 = GC_OBJECT(ClaireType,v2164->set_arg);
      ClaireClass * v6265 = psort_any(_oid_(v6225));
      if ((INHERIT(v6225->isa,Core._Param)) && (((CLREAD(Param,v6225,arg) == Kernel._list) || 
            (CLREAD(Param,v6225,arg) == Kernel._set)) && 
          (Kernel._set == OWNER((*(CLREAD(Param,v6225,args)))[1]))))
       { OID  v14599 = GC_OID((*(OBJECT(set,(*(CLREAD(Param,v6225,args)))[1])))[1]);
        if ((equal(_oid_(_at_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v2164->arg)))),Kernel.of)),v14599) == CTRUE) || 
            (Optimize.compiler->safety > 4))
         Result = (*Optimize.c_code)(GC_OID(v2164->arg),
          _oid_(v6265));
        else { OID  v602;
            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Core.check_in);
              (v2072->args = list::alloc(3,GC_OID(v2164->arg),
                _oid_(CLREAD(Param,v6225,arg)),
                v14599));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v602 = _oid_(v2072);
              } 
            Result = (*Optimize.c_code)(v602,
              _oid_(v6265));
            } 
          } 
      else if ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v2164->arg)))),v6225) == CTRUE) || 
          (Optimize.compiler->safety > 1))
       Result = (*Optimize.c_code)(GC_OID(v2164->arg),
        _oid_(v6265));
      else { OID  v1563;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Core.check_in);
            (v2072->args = list::alloc(2,GC_OID(v2164->arg),_oid_(v6225)));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v1563 = _oid_(v2072);
            } 
          Result = (*Optimize.c_code)(v1563,
            _oid_(v6265));
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Super_Optimize(Super *v2164)
{ GC_BIND;
  { ClaireType *Result ;
    { list * v8375;
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
      property * v6219 = v2164->selector;
      ((*(v8375))[1]=_oid_(v2164->cast_to));
      { OID  v7307;
        { if (v6219->open == 3)
           v7307 = Core.nil->value;
          else v7307 = restriction_I_class(class_I_type(GC_OBJECT(ClaireType,v2164->cast_to)),v6219->definition,v8375);
            GC_OID(v7307);} 
        Result = ((Kernel._slot == OWNER(v7307)) ?
          OBJECT(restriction,v7307)->range :
          ((Kernel._method == OWNER(v7307)) ?
            use_range_method(OBJECT(method,v7307),v8375) :
            v6219->range ) );
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Super_Optimize(Super *v2164)
{ GC_BIND;
  { OID Result = 0;
    { property * v6219 = v2164->selector;
      list * v6212 = GC_OBJECT(list,v2164->args);
      list * v8375;
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
      OID  v7307;
      { if (v6219->open == 3)
         v7307 = Core.nil->value;
        else v7307 = restriction_I_class(class_I_type(GC_OBJECT(ClaireType,v2164->cast_to)),v6219->definition,v8375);
          GC_OID(v7307);} 
      if (Kernel._slot == OWNER(v7307))
       { Call_slot * v2072 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
        (v2072->selector = OBJECT(slot,v7307));
        (v2072->arg = (*Optimize.c_code)((*(v6212))[1],
          _oid_(psort_any(_oid_(domain_I_restriction(OBJECT(restriction,v7307)))))));
        (v2072->test = ((belong_to(OBJECT(slot,v7307)->DEFAULT,_oid_(OBJECT(restriction,v7307)->range)) != CTRUE) ? ((Optimize.compiler->safety < 5) ? CTRUE: CFALSE): CFALSE));
        add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      else if (Kernel._method == OWNER(v7307))
       Result = c_code_method_method1(OBJECT(method,v7307),v6212,v8375);
      else Result = c_warn_Super(v2164,_oid_(v8375));
        } 
    GC_UNBIND; return (Result);} 
  } 

void  self_print_Call_function2(Optimize_Call_function2 *v2164)
{ print_any(_oid_(v2164->arg));
  princ_string(copy_string("("));
  princ_bag(v2164->args);
  princ_string(copy_string(")"));
  } 

ClaireType * c_type_Call_function2_Optimize(Optimize_Call_function2 *v2164)
{ return (Kernel._any);} 

OID  c_code_Call_function2_Optimize(Optimize_Call_function2 *v2164)
{ GC_BIND;
  { OID Result = 0;
    { Optimize_Call_function2 * v2072 = ((Optimize_Call_function2 *) GC_OBJECT(Optimize_Call_function2,new_object_class(Optimize._Call_function2)));
      (v2072->arg = v2164->arg);
      { Optimize_Call_function2 * v7741 = v2072; 
        list * v7742;
        { bag *v_list; OID v_val;
          OID v6224,CLcount;
          v_list = v2164->args;
           v7742 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v6224 = (*(v_list))[CLcount];
            v_val = (*Optimize.c_code)(v6224,
              _oid_(Kernel._any));
            
            (*((list *) v7742))[CLcount] = v_val;} 
          } 
        (v7741->args = v7742);} 
      add_I_property(Kernel.instances,Optimize._Call_function2,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Assert_Optimize(Assert *v2164)
{ if (Optimize.OPT->online_ask == CTRUE) 
  { { OID Result = 0;
      Result = _oid_(v2164);
      return (Result);} 
     } 
  else{ GC_BIND;
    { OID Result = 0;
      if ((Optimize.compiler->safety == 0) || 
          (Optimize.compiler->debug_ask->length != 0))
       { OID  v4446;
        { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
          { If * v7744 = v2072; 
            OID  v7745;
            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Core.NOT);
              (v2072->args = list::alloc(1,GC_OID((*(v2164->args))[1])));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v7745 = _oid_(v2072);
              } 
            (v7744->test = v7745);} 
          { If * v7746 = v2072; 
            OID  v7747;
            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Core.tformat);
              { Call * v7748 = v2072; 
                list * v7769;
                { OID v_bag;
                  GC_ANY(v7769= list::empty(Kernel.emptySet));
                  ((list *) v7769)->addFast(_string_(copy_string("Assertion violation in ~A line ~A\n")));
                  ((list *) v7769)->addFast(0);
                  { { List * v2072 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
                      (v2072->args = list::alloc(2,GC_OID(_string_(v2164->external)),v2164->index));
                      add_I_property(Kernel.instances,Language._List,11,_oid_(v2072));
                      v_bag = _oid_(v2072);
                      } 
                    GC_OID(v_bag);} 
                  ((list *) v7769)->addFast(v_bag);} 
                (v7748->args = v7769);} 
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v7747 = _oid_(v2072);
              } 
            (v7746->arg = v7747);} 
          (v2072->other = Kernel.cfalse);
          add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
          v4446 = _oid_(v2072);
          } 
        Result = (*Optimize.c_code)(v4446,
          _oid_(Kernel._any));
        } 
      else Result = Kernel.cfalse;
        GC_UNBIND; return (Result);} 
    } 
  } 

OID  c_code_Trace_Optimize(Trace *v2164)
{ GC_BIND;
  { OID Result = 0;
    { list * v6201 = GC_OBJECT(list,v2164->args);
      if (Optimize.OPT->online_ask == CTRUE)
       Result = _oid_(v2164);
      else if ((v6201->length == 1) && 
          (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(v6201))[1]))),Kernel._integer) == CTRUE))
       { OID  v14970;
        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v2072->selector = Core.write);
          (v2072->args = list::alloc(3,_oid_(Kernel.verbose),
            _oid_(ClEnv),
            (*(v6201))[1]));
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
          v14970 = _oid_(v2072);
          } 
        Result = (*Optimize.c_code)(v14970);
        } 
      else { ClaireBoolean * g0172I;
        { ClaireBoolean *v_and;
          { v_and = ((v6201->length > 1) ? CTRUE : CFALSE);
            if (v_and == CFALSE) g0172I =CFALSE; 
            else { v_and = ((Kernel._string == OWNER((*(v6201))[2])) ? CTRUE : CFALSE);
              if (v_and == CFALSE) g0172I =CFALSE; 
              else { { ClaireBoolean *v_or;
                  { v_or = ((Optimize.compiler->debug_ask->length != 0) ? CTRUE : CFALSE);
                    if (v_or == CTRUE) v_and =CTRUE; 
                    else { { ClaireObject *V_CC ;
                        { ClaireHandler c_handle = ClaireHandler();
                          if ERROR_IN 
                          { V_CC = ((OPT_EVAL((*(v6201))[1]) <= ClEnv->verbose) ? CTRUE : CFALSE);
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
                if (v_and == CFALSE) g0172I =CFALSE; 
                else g0172I = CTRUE;} 
              } 
            } 
          } 
        
        if (g0172I == CTRUE) { Call * v10246;
            { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Core.tformat);
                { Call * v7772 = v2072; 
                  list * v7773;
                  { OID v_bag;
                    GC_ANY(v7773= list::empty(Kernel.emptySet));
                    ((list *) v7773)->addFast((*(v6201))[2]);
                    ((list *) v7773)->addFast((*(v6201))[1]);
                    { { List * v2072 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
                        (v2072->args = skip_list(((list *) copy_bag(v6201)),2));
                        add_I_property(Kernel.instances,Language._List,11,_oid_(v2072));
                        v_bag = _oid_(v2072);
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v7773)->addFast(v_bag);} 
                  (v7772->args = v7773);} 
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v10246 = v2072;
                } 
              GC_OBJECT(Call,v10246);} 
            { OID  v2430;
              if (inherit_ask_class(OWNER((*(v6201))[1]),Kernel._integer) != CTRUE)
               { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                { If * v7775 = v2072; 
                  OID  v7777;
                  { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Kernel._inf_equal);
                    { Call * v7778 = v2072; 
                      list * v7779;
                      { OID v_bag;
                        GC_ANY(v7779= list::empty(Kernel.emptySet));
                        ((list *) v7779)->addFast((*(v6201))[1]);
                        { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                            (v2072->selector = Kernel.verbose);
                            (v2072->args = list::alloc(1,_oid_(ClEnv)));
                            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                            v_bag = _oid_(v2072);
                            } 
                          GC_OID(v_bag);} 
                        ((list *) v7779)->addFast(v_bag);} 
                      (v7778->args = v7779);} 
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v7777 = _oid_(v2072);
                    } 
                  (v7775->test = v7777);} 
                (v2072->arg = _oid_(v10246));
                (v2072->other = Kernel.cfalse);
                add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                v2430 = _oid_(v2072);
                } 
              else v2430 = _oid_(v10246);
                Result = (*Optimize.c_code)(v2430,
                _oid_(Kernel._any));
              } 
            } 
          else Result = Kernel.cfalse;
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Assert_Optimize(Assert *v2164)
{ return (Kernel._any);} 

ClaireType * c_type_Trace_Optimize(Trace *v2164)
{ return (Kernel._any);} 

ClaireType * c_type_Branch_Optimize(Branch *v2164)
{ return (Kernel._boolean);} 

OID  c_code_Branch_Optimize(Branch *v2164)
{ GC_BIND;
  { OID Result = 0;
    { OID  v11032;
      { ClaireHandle * v2072 = ((ClaireHandle *) GC_OBJECT(ClaireHandle,new_object_class(Language._Handle)));
        { ClaireHandle * v7801 = v2072; 
          OID  v7802;
          { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
            { Do * v7803 = v2072; 
              list * v7804;
              { OID v_bag;
                GC_ANY(v7804= list::empty(Kernel.emptySet));
                { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Kernel.choice);
                    (v2072->args = list::alloc(1,_oid_(ClEnv)));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v_bag = _oid_(v2072);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v7804)->addFast(v_bag);
                { { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                    (v2072->test = (*(v2164->args))[1]);
                    (v2072->arg = Kernel.ctrue);
                    { If * v7805 = v2072; 
                      OID  v7806;
                      { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                        { Do * v7807 = v2072; 
                          list * v7808;
                          { OID v_bag;
                            GC_ANY(v7808= list::empty(Kernel.emptySet));
                            { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                (v2072->selector = Kernel.backtrack);
                                (v2072->args = list::alloc(1,_oid_(ClEnv)));
                                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                v_bag = _oid_(v2072);
                                } 
                              GC_OID(v_bag);} 
                            ((list *) v7808)->addFast(v_bag);
                            ((list *) v7808)->addFast(Kernel.cfalse);} 
                          (v7807->args = v7808);} 
                        add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                        v7806 = _oid_(v2072);
                        } 
                      (v7805->other = v7806);} 
                    add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                    v_bag = _oid_(v2072);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v7804)->addFast(v_bag);} 
              (v7803->args = v7804);} 
            add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
            v7802 = _oid_(v2072);
            } 
          (v7801->arg = v7802);} 
        (v2072->test = _oid_(Core._contradiction));
        { ClaireHandle * v7809 = v2072; 
          OID  v7831;
          { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
            { Do * v7832 = v2072; 
              list * v7833;
              { OID v_bag;
                GC_ANY(v7833= list::empty(Kernel.emptySet));
                { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Kernel.backtrack);
                    (v2072->args = list::alloc(1,_oid_(ClEnv)));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v_bag = _oid_(v2072);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v7833)->addFast(v_bag);
                ((list *) v7833)->addFast(Kernel.cfalse);} 
              (v7832->args = v7833);} 
            add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
            v7831 = _oid_(v2072);
            } 
          (v7809->other = v7831);} 
        add_I_property(Kernel.instances,Language._Handle,11,_oid_(v2072));
        v11032 = _oid_(v2072);
        } 
      Result = (*Optimize.c_code)(v11032,
        _oid_(Kernel._any));
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Macro_Optimize(Macro *v2164,ClaireClass *v6219)
{ GC_BIND;
  { OID Result = 0;
    Result = (*Optimize.c_code)(GC_OID((*Language.macroexpand)(_oid_(v2164))),
      _oid_(v6219));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Macro_Optimize(Macro *v2164)
{ GC_BIND;
  { ClaireType *Result ;
    Result = OBJECT(ClaireType,(*Optimize.c_type)(GC_OID((*Language.macroexpand)(_oid_(v2164)))));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Printf_Optimize(Printf *v2164)
{ return (Kernel._any);} 

OID  c_code_Printf_Optimize(Printf *v2164)
{ GC_RESERVE(10);  // v3.0.55 optim !
  { OID Result = 0;
    { list * v6212 = GC_OBJECT(list,v2164->args);
      OID  v6219 = (*(v6212))[1];
      if (equal(_oid_(Kernel._string),_oid_(OWNER(v6219))) != CTRUE)
       Result = (*Optimize.Cerror)(_string_(copy_string("[209] the first argument in ~S must be a string")),
        _oid_(v2164));
      else { int  v6209 = 1;
          OID  v6214 = GC_OID((*Kernel.get)(v6219,
            _oid_(_char_('~'))));
          list * v6218 = list::empty(Kernel._any);
          { OID gc_local;
            while ((equal(v6214,0) != CTRUE))
            { GC_LOOP;
              { OID  v6213 = GC_OID((*Kernel.nth)(v6219,
                  GC_OID((*Core._plus)(v6214,
                    1))));
                if (v6209 < v6212->length)
                 ++v6209;
                else (*Optimize.Cerror)(_string_(copy_string("[210] not enough arguments in ~S")),
                    _oid_(v2164));
                  if ((OBJECT(ClaireBoolean,(*Kernel._sup)(v6214,
                  1))) == CTRUE)
                 { { OID  v10938;
                    { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Kernel.princ);
                      (v2072->args = list::alloc(1,GC_OID(_string_(substring_string(string_v(v6219),1,(*Kernel._dash)(v6214,
                        1))))));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v10938 = _oid_(v2072);
                      } 
                    v6218 = v6218->addFast(v10938);
                    } 
                   GC__ANY(v6218, 7);} 
                { { OID  v11899;
                    if (_oid_(_char_('A')) == v6213)
                     { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Kernel.princ);
                      (v2072->args = list::alloc(1,(*(v6212))[v6209]));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v11899 = _oid_(v2072);
                      } 
                    else if (_oid_(_char_('S')) == v6213)
                     { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Kernel.print);
                      (v2072->args = list::alloc(1,(*(v6212))[v6209]));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v11899 = _oid_(v2072);
                      } 
                    else if (_oid_(_char_('I')) == v6213)
                     v11899 = (*(v6212))[v6209];
                    else v11899 = Kernel.cfalse;
                      v6218 = v6218->addFast(v11899);
                    } 
                   GC__ANY(v6218, 7);} 
                GC__OID(v6219 = _string_(substring_string(string_v(v6219),(*Core._plus)(v6214,
                  2),1000)), 4);
                GC__OID(v6214 = (*Kernel.get)(v6219,
                  _oid_(_char_('~'))), 6);
                } 
              GC_UNLOOP;} 
            } 
          if (boolean_I_any(v6219) == CTRUE)
           { OID  v12861;
            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Kernel.princ);
              (v2072->args = list::alloc(1,v6219));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v12861 = _oid_(v2072);
              } 
            v6218 = v6218->addFast(v12861);
            } 
          { OID  v13822;
            { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
              (v2072->args = v6218);
              add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
              v13822 = _oid_(v2072);
              } 
            Result = (*Optimize.c_code)(v13822,
              _oid_(Kernel._any));
            } 
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Error_Optimize(Error *v2164)
{ return (Kernel.emptySet);} 

OID  c_code_Error_Optimize(Error *v2164)
{ GC_BIND;
  { OID Result = 0;
    { ClaireBoolean * v6224 = Optimize.OPT->allocation;
      OID  v6225;
      { { OID  v14782;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.close);
            { Call * v7839 = v2072; 
              list * v7840;
              { OID v_bag;
                GC_ANY(v7840= list::empty(Kernel.emptySet));
                { { Cast * v2072 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                    { Cast * v8513 = v2072; 
                      OID  v8514;
                      { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v2072->selector = Optimize.anyObject_I);
                        { Call * v8515 = v2072; 
                          list * v8516;
                          { OID v_bag;
                            GC_ANY(v8516= list::empty(Kernel.emptySet));
                            ((list *) v8516)->addFast(_oid_(Core._general_error));
                            ((list *) v8516)->addFast(GC_OID((*Optimize.c_code)(GC_OID(car_list(v2164->args)),
                              _oid_(Kernel._any))));
                            { { OID  v11941;
                                if (v2164->args->length != 1)
                                 { List * v2072 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
                                  (v2072->args = cdr_list(v2164->args));
                                  add_I_property(Kernel.instances,Language._List,11,_oid_(v2072));
                                  v11941 = _oid_(v2072);
                                  } 
                                else v11941 = Core.nil->value;
                                  v_bag = (*Optimize.c_code)(v11941,
                                  _oid_(Kernel._any));
                                } 
                              GC_OID(v_bag);} 
                            ((list *) v8516)->addFast(v_bag);} 
                          (v8515->args = v8516);} 
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                        v8514 = _oid_(v2072);
                        } 
                      (v8513->arg = v8514);} 
                    (v2072->set_arg = Kernel._exception);
                    add_I_property(Kernel.instances,Language._Cast,11,_oid_(v2072));
                    v_bag = _oid_(v2072);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v7840)->addFast(v_bag);} 
              (v7839->args = v7840);} 
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v14782 = _oid_(v2072);
            } 
          v6225 = (*Optimize.c_code)(v14782,
            _oid_(Kernel._void));
          } 
        GC_OID(v6225);} 
      (Optimize.OPT->allocation = v6224);
      Result = v6225;
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * extendedTest_ask_If(If *v2164)
{ GC_BIND;
  { ClaireType *Result ;
    { OID  v10263 = v2164->test;
      if (INHERIT(OWNER(v10263),Language._Call))
       { if ((INHERIT(OWNER((*(OBJECT(Call,v10263)->args))[1]),Language._Variable)) && 
            (OBJECT(Call,v10263)->selector == Core.known_ask))
         Result = OBJECT(ClaireType,(*Kernel.range)((*(OBJECT(Call,v10263)->args))[1]));
        else Result = Kernel._any;
          } 
      else Result = Kernel._any;
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_If_Optimize(If *v2164)
{ GC_BIND;
  { ClaireType *Result ;
    { ClaireType * v10261 = GC_OBJECT(ClaireType,extendedTest_ask_If(v2164));
      if (extended_ask_type(v10261) == CTRUE)
       range_sets_any(GC_OID((*(OBJECT(bag,(*Core.args)(GC_OID(v2164->test)))))[1]),GC_OBJECT(ClaireType,sort_abstract_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Core.t1)(_oid_(v10261)))))));
      { ClaireType * v5957 = GC_OBJECT(ClaireType,U_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v2164->arg)))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v2164->other))))));
        if (extended_ask_type(v10261) == CTRUE)
         put_property2(Kernel.range,GC_OBJECT(ClaireObject,OBJECT(ClaireObject,(*(OBJECT(bag,(*Core.args)(GC_OID(v2164->test)))))[1])),_oid_(v10261));
        Result = v5957;
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_If_Optimize(If *v2164,ClaireClass *v6219)
{ GC_BIND;
  { OID Result = 0;
    { ClaireType * v10261 = GC_OBJECT(ClaireType,extendedTest_ask_If(v2164));
      if (extended_ask_type(v10261) == CTRUE)
       range_sets_any(GC_OID((*(OBJECT(bag,(*Core.args)(GC_OID(v2164->test)))))[1]),GC_OBJECT(ClaireType,sort_abstract_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Core.t1)(_oid_(v10261)))))));
      if ((_inf_equal_type(GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v2164->test))))),Kernel._boolean) != CTRUE) && 
          (Optimize.PENIBLE->value == Kernel.ctrue))
       { warn_void();
        tformat_string(copy_string("CLAIRE 3.3 SYNTAX - Test in ~S should be a boolean [260]\n"),2,list::alloc(1,_oid_(v2164)));
        } 
      { If * v5957;
        { { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
            (v2072->test = c_boolean_any(GC_OID(v2164->test)));
            (v2072->arg = (*Optimize.c_code)(GC_OID(v2164->arg),
              _oid_(v6219)));
            (v2072->other = (*Optimize.c_code)(GC_OID(v2164->other),
              _oid_(v6219)));
            add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
            v5957 = v2072;
            } 
          GC_OBJECT(If,v5957);} 
        if (extended_ask_type(v10261) == CTRUE)
         put_property2(Kernel.range,GC_OBJECT(ClaireObject,OBJECT(ClaireObject,(*(OBJECT(bag,(*Core.args)(GC_OID(v2164->test)))))[1])),_oid_(v10261));
        Result = _oid_(v5957);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_If(If *v2164)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = (((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v2164->arg))) == CTRUE) ? CTRUE : (((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v2164->other))) == CTRUE) ? CTRUE : CFALSE));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Case_Optimize(Case *v2164)
{ GC_RESERVE(6);  // v3.0.55 optim !
  { ClaireType *Result ;
    { OID  v4618 = GC_OID(v2164->var);
      OID  v8375;
      { if (INHERIT(OWNER(v4618),Language._Variable))
         v8375 = get_property(Kernel.range,OBJECT(ClaireObject,v4618));
        else v8375 = _oid_(Kernel._any);
          GC_OID(v8375);} 
      list * v6212 = ((list *) copy_bag(v2164->args));
      ClaireType * v12932 = Kernel.emptySet;
      ClaireType * v14599 = Kernel.emptySet;
      { OID gc_local;
        while ((v6212->length > 0))
        { GC_LOOP;
          if (INHERIT(OWNER((*(v6212))[1]),Kernel._type))
           { GC__ANY(v14599 = U_type(v14599,OBJECT(ClaireType,(*(v6212))[1])), 6);
            if (osort_any(v8375) == osort_any((*(v6212))[1]))
             range_sets_any(v4618,OBJECT(ClaireType,(*(v6212))[1]));
            else if (osort_any(v8375) == Kernel._any)
             range_sets_any(v4618,GC_OBJECT(ClaireType,sort_abstract_I_type(OBJECT(ClaireType,(*(v6212))[1]))));
            } 
          else (*Optimize.Cerror)(_string_(copy_string("[208] wrong type declaration for case: ~S in ~S")),
              car_list(v6212),
              _oid_(v2164));
            GC__ANY(v12932 = U_type(v12932,GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(v6212))[2])))), 5);
          if (INHERIT(OWNER(v4618),Language._Variable))
           store_object(OBJECT(ClaireObject,v4618),
            3,
            Kernel._object,
            v8375,
            CFALSE);
          v6212= skip_list(v6212,2);
          GC_UNLOOP;} 
        } 
      if (_inf_equal_type(OBJECT(ClaireType,v8375),v14599) == CTRUE)
       Result = v12932;
      else Result = ((_inf_equal_type(v12932,Kernel._boolean) == CTRUE) ?
        Kernel._boolean :
        Kernel._any );
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Case_Optimize(Case *v2164,ClaireClass *v6219)
{ GC_RESERVE(13);  // v3.0.55 optim !
  { OID Result = 0;
    { OID  v4618 = GC_OID(v2164->var);
      OID  v8375;
      { if (INHERIT(OWNER(v4618),Language._Variable))
         v8375 = get_property(Kernel.range,OBJECT(ClaireObject,v4618));
        else v8375 = _oid_(Kernel._any);
          GC_OID(v8375);} 
      list * v6212 = ((list *) copy_bag(v2164->args));
      OID  v14599 = _oid_(Kernel.emptySet);
      OID  v8836;
      { { OID  v12902;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel._Z);
            (v2072->args = list::alloc(2,v4618,(*(v6212))[1]));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v12902 = _oid_(v2072);
            } 
          v8836 = c_boolean_any(v12902);
          } 
        GC_OID(v8836);} 
      range_sets_any(v4618,OBJECT(ClaireType,(*(v6212))[1]));
      { If * v14965;
        { { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
            (v2072->test = v8836);
            (v2072->arg = (*Optimize.c_code)((*(v6212))[2],
              _oid_(v6219)));
            (v2072->other = (*Optimize.c_code)(Kernel.cfalse,
              _oid_(v6219)));
            add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
            v14965 = v2072;
            } 
          GC_OBJECT(If,v14965);} 
        If * v5141 = v14965;
        if (INHERIT(OWNER(v4618),Language._Variable))
         store_object(OBJECT(ClaireObject,v4618),
          3,
          Kernel._object,
          v8375,
          CFALSE);
        v6212= skip_list(v6212,2);
        { OID gc_local;
          while ((v6212->length > 0))
          { GC_LOOP;
            GC__OID(v14599 = _oid_(U_type(OBJECT(ClaireType,v14599),OBJECT(ClaireType,(*(v6212))[1]))), 7);
            if (_inf_equal_type(OBJECT(ClaireType,v8375),OBJECT(ClaireType,v14599)) == CTRUE)
             { if (osort_any(v8375) == osort_any((*(v6212))[1]))
               range_sets_any(v4618,OBJECT(ClaireType,(*(v6212))[1]));
              else if (osort_any(v8375) == Kernel._any)
               range_sets_any(v4618,GC_OBJECT(ClaireType,sort_abstract_I_type(OBJECT(ClaireType,(*(v6212))[1]))));
              (v5141->other = (*Optimize.c_code)((*(v6212))[2],
                _oid_(v6219)));
              if (INHERIT(OWNER(v4618),Language._Variable))
               store_object(OBJECT(ClaireObject,v4618),
                3,
                Kernel._object,
                v8375,
                CFALSE);
              { ;break;} 
              } 
            else { OID  v1869;
                { { OID  v13863;
                    { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Kernel._Z);
                      (v2072->args = list::alloc(2,v4618,(*(v6212))[1]));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v13863 = _oid_(v2072);
                      } 
                    v1869 = c_boolean_any(v13863);
                    } 
                  GC_OID(v1869);} 
                range_sets_any(v4618,OBJECT(ClaireType,(*(v6212))[1]));
                { If * v8520 = v5141; 
                  OID  v8521;
                  { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                    (v2072->test = v1869);
                    (v2072->arg = (*Optimize.c_code)((*(v6212))[2],
                      _oid_(v6219)));
                    (v2072->other = (*Optimize.c_code)(Kernel.cfalse,
                      _oid_(v6219)));
                    add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                    v8521 = _oid_(v2072);
                    } 
                  (v8520->other = v8521);} 
                GC__ANY(v5141 = OBJECT(If,v5141->other), 10);
                } 
              if (INHERIT(OWNER(v4618),Language._Variable))
             store_object(OBJECT(ClaireObject,v4618),
              3,
              Kernel._object,
              v8375,
              CFALSE);
            v6212= skip_list(v6212,2);
            GC_UNLOOP;} 
          } 
        if ((INHERIT(OWNER(v4618),Language._Definition)) && (INHERIT(OBJECT(Definition,v4618)->arg->isa,Kernel._exception)))
         Result = v4618;
        else Result = _oid_(v14965);
          } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Do_Optimize(Do *v2164)
{ GC_BIND;
  { ClaireType *Result ;
    Result = OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(last_list(v2164->args))));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Do_Optimize(Do *v2164,ClaireClass *v6219)
{ GC_BIND;
  { OID Result = 0;
    { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
      { Do * v8522 = v2072; 
        list * v8544;
        { int  v6213 = v2164->args->length;
          int  v6214 = 0;
          { bag *v_list; OID v_val;
            OID v6224,CLcount;
            v_list = GC_OBJECT(list,v2164->args);
             v8544 = v_list->clone();
            for (CLcount= 1; CLcount <= v_list->length; CLcount++)
            { v6224 = (*(v_list))[CLcount];
              { ++v6214;
                { OID  v6081;
                  if (v6214 == v6213)
                   v6081 = _oid_(v6219);
                  else v6081 = _oid_(Kernel._void);
                    v_val = (*Optimize.c_code)(v6224,
                    v6081);
                  } 
                } 
              
              (*((list *) v8544))[CLcount] = v_val;} 
            } 
          } 
        (v8522->args = v8544);} 
      add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Do(Do *v2164)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(GC_OID(last_list(v2164->args))));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Let_Optimize(Let *v2164)
{ GC_BIND;
  range_infers_Variable(GC_OBJECT(Variable,v2164->var),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v2164->value)))));
  { ClaireType *Result ;
    Result = OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v2164->arg)));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Let_Optimize(Let *v2164,ClaireClass *v6219)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID Result = 0;
    { OID  v10265 = GC_OID(v2164->value);
      ClaireType * v8375 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v10265))));
      range_infers_Variable(GC_OBJECT(Variable,v2164->var),v8375);
      if (_inf_equal_type(v8375,GC_OBJECT(ClaireType,v2164->var->range)) != CTRUE)
       v10265= GC_OID(c_warn_Variable(GC_OBJECT(Variable,v2164->var),v10265,v8375));
      { Let * v6224;
        { { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
            (v2072->var = v2164->var);
            (v2072->value = c_gc_I_any2(GC_OID(c_strict_code_any(v10265,psort_any(GC_OID(_oid_(v2164->var->range))))),v8375));
            (v2072->arg = (*Optimize.c_code)(GC_OID(v2164->arg),
              _oid_(v6219)));
            add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
            v6224 = v2072;
            } 
          GC_OBJECT(Let,v6224);} 
        (v6224->isa = v2164->isa);
        if ((INHERIT(v6224->isa,Language._Let_star)) && 
            ((INHERIT(v8375->isa,Kernel._tuple)) && 
              (BCONTAIN(c_status_any(GC_OID(v2164->value),Kernel.nil),1))))
         { int  v6209 = 1;
          OID  v6226 = GC_OID(v6224->arg);
          { OID gc_local;
            while (((INHERIT(OWNER(v6226),Language._Let)) && 
                (v6209 <= ((bag *) v8375)->length)))
            { GC_LOOP;
              if ((((OBJECT(ClaireBoolean,(*Optimize.gcsafe_ask)((*(((bag *) v8375)))[v6209]))) == CTRUE) ? CTRUE : ((INHERIT(owner_any((*Kernel.value)(v6226)),Optimize._to_protect)) ? CTRUE : CFALSE)) != CTRUE)
               { (Optimize.OPT->protection = CTRUE);
                { OID  v7042;
                  { Compile_to_protect * v2072 = ((Compile_to_protect *) GC_OBJECT(Compile_to_protect,new_object_class(Optimize._to_protect)));
                    (v2072->arg = (*Kernel.value)(v6226));
                    add_I_property(Kernel.instances,Optimize._to_protect,11,_oid_(v2072));
                    v7042 = _oid_(v2072);
                    } 
                  write_property(Kernel.value,OBJECT(ClaireObject,v6226),v7042);
                  } 
                } 
              ++v6209;
              GC__OID(v6226 = (*Kernel.arg)(v6226), 8);
              GC_UNLOOP;} 
            } 
          } 
        Result = _oid_(v6224);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_When_Optimize(When *v2164)
{ GC_BIND;
  { ClaireType *Result ;
    { OID  v10265 = GC_OID(v2164->value);
      Variable * v6222 = GC_OBJECT(Variable,v2164->var);
      OID  v6204 = GC_OID(daccess_any(v10265,CTRUE));
      OID  v8375;
      { if (v6204 != CNULL)
         v8375 = (*Optimize.c_type)(v6204);
        else v8375 = (*Optimize.c_type)(v10265);
          GC_OID(v8375);} 
      if (extended_ask_type(OBJECT(ClaireType,v8375)) == CTRUE)
       v8375= GC_OID((*Core.t1)(v8375));
      range_infers_Variable(v6222,OBJECT(ClaireType,v8375));
      Result = U_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v2164->arg)))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v2164->other)))));
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_When_Optimize(When *v2164,ClaireClass *v6219)
{ GC_BIND;
  { OID Result = 0;
    { OID  v10265 = GC_OID(v2164->value);
      Variable * v6222 = GC_OBJECT(Variable,v2164->var);
      OID  v6204 = GC_OID(daccess_any(v10265,CTRUE));
      Variable * v12708 = GC_OBJECT(Variable,Variable_I_symbol(append_symbol(v2164->var->pname,_string_(copy_string("test"))),v2164->var->index,Kernel._any));
      OID  v8375;
      { if (v6204 != CNULL)
         v8375 = (*Optimize.c_type)(v6204);
        else v8375 = (*Optimize.c_type)(v10265);
          GC_OID(v8375);} 
      if (extended_ask_type(OBJECT(ClaireType,v8375)) == CTRUE)
       v8375= GC_OID((*Core.t1)(v8375));
      range_infers_Variable(v6222,OBJECT(ClaireType,v8375));
      if ((v6204 != CNULL) && 
          (extended_ask_type(OBJECT(ClaireType,(*Kernel.range)(GC_OID((*Kernel.selector)(v6204))))) != CTRUE))
       { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
        (v2072->var = v6222);
        (v2072->value = c_gc_I_any2(v6204,OBJECT(ClaireType,v8375)));
        { Let * v8547 = v2072; 
          OID  v8548;
          { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
            { If * v8550 = v2072; 
              OID  v8551;
              { Call_method2 * v2072 = ((Call_method2 *) GC_OBJECT(Call_method2,new_object_class(Language._Call_method2)));
                (v2072->arg = ((method *) _at_property1(Core.identical_ask,Kernel._any)));
                (v2072->args = list::alloc(2,_oid_(v6222),GC_OID((*Optimize.c_code)(CNULL,
                  GC_OID((*Optimize.c_sort)(_oid_(v6222)))))));
                add_I_property(Kernel.instances,Language._Call_method2,11,_oid_(v2072));
                v8551 = _oid_(v2072);
                } 
              (v8550->test = v8551);} 
            (v2072->arg = (*Optimize.c_code)(GC_OID(v2164->other),
              _oid_(v6219)));
            (v2072->other = (*Optimize.c_code)(GC_OID(v2164->arg),
              _oid_(v6219)));
            add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
            v8548 = _oid_(v2072);
            } 
          (v8547->arg = v8548);} 
        add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      else if (((*Optimize.c_sort)(_oid_(v6222)) == _oid_(Kernel._any)) && 
          ((_inf_equal_type(OBJECT(ClaireType,v8375),GC_OBJECT(ClaireType,v6222->range)) == CTRUE) && 
            (3 <= Optimize.compiler->safety)))
       { OID  v11847;
        { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
          (v2072->var = v6222);
          (v2072->value = v10265);
          { Let * v8556 = v2072; 
            OID  v8557;
            { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
              { If * v8575 = v2072; 
                OID  v8577;
                { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Core._I_equal);
                  (v2072->args = list::alloc(2,_oid_(v6222),CNULL));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v8577 = _oid_(v2072);
                  } 
                (v8575->test = v8577);} 
              (v2072->arg = v2164->arg);
              (v2072->other = v2164->other);
              add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
              v8557 = _oid_(v2072);
              } 
            (v8556->arg = v8557);} 
          add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
          v11847 = _oid_(v2072);
          } 
        Result = (*Optimize.c_code)(v11847,
          _oid_(v6219));
        } 
      else { OID  v4065;
          { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
            (v2072->var = v12708);
            (v2072->value = v10265);
            { Let * v8579 = v2072; 
              OID  v8580;
              { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                { If * v8581 = v2072; 
                  OID  v8582;
                  { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Core._I_equal);
                    (v2072->args = list::alloc(2,_oid_(v12708),CNULL));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v8582 = _oid_(v2072);
                    } 
                  (v8581->test = v8582);} 
                { If * v8583 = v2072; 
                  OID  v8584;
                  { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
                    (v2072->var = v6222);
                    { Let * v8585 = v2072; 
                      OID  v8606;
                      { Cast * v2072 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                        (v2072->arg = _oid_(v12708));
                        (v2072->set_arg = OBJECT(ClaireType,v8375));
                        add_I_property(Kernel.instances,Language._Cast,11,_oid_(v2072));
                        v8606 = _oid_(v2072);
                        } 
                      (v8585->value = v8606);} 
                    (v2072->arg = v2164->arg);
                    add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
                    v8584 = _oid_(v2072);
                    } 
                  (v8583->arg = v8584);} 
                (v2072->other = (*Optimize.c_code)(GC_OID(v2164->other),
                  _oid_(v6219)));
                add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                v8580 = _oid_(v2072);
                } 
              (v8579->arg = v8580);} 
            add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
            v4065 = _oid_(v2072);
            } 
          Result = (*Optimize.c_code)(v4065,
            _oid_(v6219));
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Let(Let *v2164)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v2164->arg));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_For_Optimize(For *v2164)
{ GC_BIND;
  { ClaireType *Result ;
    Result = infers_from_type2(GC_OBJECT(ClaireType,return_type_any(GC_OID(v2164->arg))),_oid_(v2164));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * infers_from_type2(ClaireType *v6220,OID v2164)
{ GC_BIND;
  { ClaireType *Result ;
    if (equal(_oid_(v6220),_oid_(Kernel.emptySet)) == CTRUE)
     Result = sort_abstract_I_type(Kernel._boolean);
    else if (Optimize.compiler->safety > 3)
     { tformat_string(copy_string("... c_type(~S) -> ~S - ~S \n"),2,list::alloc(3,v2164,
        _oid_(v6220),
        GC_OID(_oid_(sort_abstract_I_type(v6220)))));
      Result = sort_abstract_I_type(v6220);
      } 
    else Result = Kernel._any;
      GC_UNBIND; return (Result);} 
  } 

OID  c_code_For_Optimize(For *v2164,ClaireClass *v6219)
{ GC_BIND;
  { OID Result = 0;
    { OID  v12685 = GC_OID(v2164->set_arg);
      ClaireBoolean * v6202 = Optimize.OPT->protection;
      int  v12525 = Optimize.compiler->safety;
      Variable * v2841 = GC_OBJECT(Variable,v2164->var);
      Variable * v6222;
      { { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
          (v2072->pname = v2841->pname);
          (v2072->range = v2841->range);
          (v2072->index = v2841->index);
          add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
          v6222 = v2072;
          } 
        GC_OBJECT(Variable,v6222);} 
      OID  v13392 = GC_OID(substitution_any(GC_OID(v2164->arg),v2841,_oid_(v6222)));
      OID  v15867 = GC_OID(c_inline_arg_ask_any(v12685));
      (Optimize.OPT->protection = CFALSE);
      if (INHERIT(OWNER(v12685),Core._global_variable))
       { if (boolean_I_any(_oid_(OBJECT(global_variable,v12685)->range)) != CTRUE)
         { (v2164->set_arg = OBJECT(global_variable,v12685)->value);
          v12685= GC_OID(OBJECT(global_variable,v12685)->value);
          } 
        } 
      else if (INHERIT(OWNER(v12685),Language._Select))
       { ClaireType * v10263 = GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v12685)));
        if ((_inf_equal_type(v10263,Kernel._bag) != CTRUE) || 
            (_inf_equal_type(v10263,Kernel._set) == CTRUE))
         { v2164= GC_OBJECT(For,((For *) copy_object(v2164)));
          (v2164->isa = Language._Select);
          } 
        } 
      else if (INHERIT(OWNER(v12685),Kernel._class))
       { if ((OBJECT(ClaireClass,v12685)->open <= 1) && 
            (boolean_I_any(_oid_(OBJECT(ClaireClass,v12685)->subclass)) != CTRUE))
         { Iteration * v8607 = v2164; 
          OID  v8608;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.instances);
            (v2072->args = list::alloc(1,v12685));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v8608 = _oid_(v2072);
            } 
          (v8607->set_arg = v8608);} 
        } 
      { OID  v10263 = GC_OID((*Optimize.c_type)(GC_OID(v2164->set_arg)));
        ClaireType * v6907 = GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v10263)));
        ClaireType * v6908;
        { { ClaireType * v2049;
            { { OID v15730;{ OID  v3010;
                  { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Kernel.set_I);
                    (v2072->args = list::alloc(1,v12685));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v3010 = _oid_(v2072);
                    } 
                  v15730 = (*Optimize.c_type)(v3010);
                  } 
                
                v2049=OBJECT(ClaireType,v15730);} 
              GC_OBJECT(ClaireType,v2049);} 
            v6908 = pmember_type(v2049);
            } 
          GC_OBJECT(ClaireType,v6908);} 
        if (_inf_equal_type(v6908,v6907) == CTRUE)
         v6907= v6908;
        range_infers_for_Variable(v6222,v6907,OBJECT(ClaireType,v10263));
        (Optimize.compiler->safety = 1);
        v6907= GC_OBJECT(ClaireType,v6222->range);
        (v6222->range = ptype_type(v6907));
        { OID  v6213 = GC_OID(Iterate_I_Iteration(v2164));
          if (equal(_oid_(Kernel._method),_oid_(OWNER(v6213))) != CTRUE)
           { OID  v12429 = GC_OID(restriction_I_property(Language.iterate,list::alloc(3,v10263,
              _oid_(set::alloc(1,_oid_(v6222))),
              _oid_(Kernel._any)),CTRUE));
            if (Kernel._method == OWNER(v12429))
             v6213= v12429;
            } 
          (Optimize.compiler->safety = v12525);
          (v6222->range = v6907);
          { OID  v6218;
            { if ((Kernel._method == OWNER(v6213)) && (OBJECT(method,v6213)->inline_ask == CTRUE))
               { if ((Optimize.compiler->safety < 6) && 
                    (BCONTAIN(c_status_any(v13392,Kernel.nil),1)))
                 (Optimize.OPT->loop_gc = CTRUE);
                if (sort_abstract_ask_type(v6222->range) == CTRUE)
                 (v6222->range = CLREAD(Union,v6222->range,t2));
                v6218 = c_inline_method1(OBJECT(method,v6213),list::alloc(3,GC_OID(instruction_copy_any(GC_OID(v2164->set_arg))),
                  _oid_(v6222),
                  v13392),v6219);
                } 
              else if (boolean_I_any(v15867) == CTRUE)
               { OID  v3971;
                { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                  (v2072->var = v6222);
                  (v2072->set_arg = v15867);
                  (v2072->arg = v13392);
                  add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                  v3971 = _oid_(v2072);
                  } 
                v6218 = (*Optimize.c_code)(v3971,
                  _oid_(v6219));
                } 
              else if ((INHERIT(OWNER(v12685),Language._Call)) && (OBJECT(Call,v12685)->selector == Core.Id))
               v6218 = c_code_multiple_For(v2164,OBJECT(ClaireType,v10263),v6219);
              else { For * v12584;
                  { { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                      (v2072->var = v6222);
                      (v2072->set_arg = c_gc_I_any1(GC_OID(enumerate_code_any(GC_OID(v2164->set_arg),OBJECT(ClaireType,v10263)))));
                      (v2072->arg = (*Optimize.c_code)(v13392,
                        _oid_(Kernel._void)));
                      add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                      v12584 = v2072;
                      } 
                    GC_OBJECT(For,v12584);} 
                  if (v6219 == Kernel._any)
                   v6218 = _oid_(v12584);
                  else { Compile_to_C * v2072 = ((Compile_to_C *) GC_OBJECT(Compile_to_C,new_object_class(Optimize._to_C)));
                      (v2072->arg = _oid_(v12584));
                      (v2072->set_arg = v6219);
                      add_I_property(Kernel.instances,Optimize._to_C,11,_oid_(v2072));
                      v6218 = _oid_(v2072);
                      } 
                    } 
                GC_OID(v6218);} 
            if ((Optimize.OPT->protection == CTRUE) && 
                ((0 <= Optimize.OPT->loop_index) && 
                  (Optimize.compiler->safety < 6)))
             (Optimize.OPT->loop_gc = CTRUE);
            (Optimize.OPT->protection = ((Optimize.OPT->protection == CTRUE) ? CTRUE : ((v6202 == CTRUE) ? CTRUE : CFALSE)));
            Result = v6218;
            } 
          } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_multiple_For(For *v2164,ClaireType *v10263,ClaireClass *v6219)
{ GC_RESERVE(14);  // v3.0.55 optim !
  { OID Result = 0;
    { Variable * v6222 = GC_OBJECT(Variable,v2164->var);
      OID  v12685 = GC_OID((*(OBJECT(Call,v2164->set_arg)->args))[1]);
      Variable * v12708 = GC_OBJECT(Variable,Variable_I_symbol(append_symbol(v6222->pname,_string_(copy_string("test"))),v2164->var->index,v10263));
      Let * v6214;
      { { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
          (v2072->var = v12708);
          (v2072->value = v12685);
          { Let * v8612 = v2072; 
            OID  v8613;
            { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
              (v2072->var = v2164->var);
              (v2072->set_arg = enumerate_code_any(v12685,v10263));
              (v2072->arg = v2164->arg);
              add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
              v8613 = _oid_(v2072);
              } 
            (v8612->arg = v8613);} 
          add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
          v6214 = v2072;
          } 
        GC_OBJECT(Let,v6214);} 
      tformat_string(copy_string("---- note: use an expended iteration for {~S} \n"),0,list::alloc(1,_oid_(v2164)));
      { OID gc_local;
        ITERATE(v6218);
        for (START(Language.iterate->restrictions); NEXT(v6218);)
        { GC_LOOP;
          if ((_inf_equalt_class(domain_I_restriction(OBJECT(restriction,v6218)),v10263) == CTRUE) && 
              ((_inf_equalt_class(domain_I_restriction(OBJECT(restriction,v6218)),Kernel._collection) == CTRUE) && 
                ((OBJECT(method,v6218)->inline_ask == CTRUE) && 
                  (belong_to(_oid_(v6222),(*(OBJECT(restriction,v6218)->domain))[2]) == CTRUE))))
           { Variable * v1682;
            { { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
                (v2072->pname = v6222->pname);
                (v2072->range = v6222->range);
                (v2072->index = v6222->index);
                add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
                v1682 = v2072;
                } 
              GC_OBJECT(Variable,v1682);} 
            OID  v13392 = GC_OID(substitution_any(GC_OID(v2164->arg),v6222,_oid_(v1682)));
            { Let * v8614 = v6214; 
              OID  v8615;
              { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                { If * v8637 = v2072; 
                  OID  v8638;
                  { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Kernel._Z);
                    (v2072->args = list::alloc(2,_oid_(v12708),(*(OBJECT(restriction,v6218)->domain))[1]));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v8638 = _oid_(v2072);
                    } 
                  (v8637->test = v8638);} 
                { If * v8639 = v2072; 
                  OID  v8640;
                  { if ((Optimize.compiler->safety < 6) && 
                        (BCONTAIN(c_status_any(GC_OID(v2164->arg),Kernel.nil),1)))
                     (Optimize.OPT->loop_gc = CTRUE);
                    if (sort_abstract_ask_type(v1682->range) == CTRUE)
                     (v1682->range = CLREAD(Union,v6222->range,t2));
                    v8640 = c_inline_method1(OBJECT(method,v6218),GC_OBJECT(list,list::alloc(3,_oid_(v12708),
                      _oid_(v1682),
                      v13392)),v6219);
                    } 
                  (v8639->arg = v8640);} 
                (v2072->other = v6214->arg);
                add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                v8615 = _oid_(v2072);
                } 
              (v8614->arg = v8615);} 
            } 
          GC_UNLOOP;} 
        } 
      Result = (*Optimize.c_code)(_oid_(v6214),
        _oid_(v6219));
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Iteration(Iteration *v2164)
{ return (CTRUE);} 

ClaireType * c_type_Iteration_Optimize(Iteration *v2164)
{ GC_BIND;
  { ClaireType *Result ;
    { OID  v10263 = GC_OID((*Optimize.c_type)(GC_OID(v2164->set_arg)));
      range_infers_for_Variable(GC_OBJECT(Variable,v2164->var),GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v10263))),OBJECT(ClaireType,v10263));
      Result = ((get_property(Kernel.of,v2164) != CNULL) ?
        param_I_class((((INHERIT(v2164->isa,Language._Select)) || 
            (INHERIT(v2164->isa,Language._Image))) ?
          Kernel._set :
          Kernel._list ),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.of)(_oid_(v2164))))) :
        nth_class1((((INHERIT(v2164->isa,Language._Select)) || 
            (INHERIT(v2164->isa,Language._Image))) ?
          Kernel._set :
          Kernel._list ),GC_OBJECT(ClaireType,(((INHERIT(v2164->isa,Language._Select)) || 
            (INHERIT(v2164->isa,Language._Lselect))) ?
          pmember_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v2164->set_arg))))) :
          ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v2164->arg)))) ))) );
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Iteration_Optimize(Iteration *v2164)
{ GC_BIND;
  { OID Result = 0;
    { OID  v12685 = GC_OID(v2164->set_arg);
      OID  v10263 = GC_OID((*Optimize.c_type)(v12685));
      if (INHERIT(v2164->isa,Language._For))
       Result = (*Optimize.c_code)(_oid_(v2164),
        _oid_(Kernel._any));
      else if ((INHERIT(v2164->isa,Language._Collect)) && (_inf_equal_type(OBJECT(ClaireType,v10263),Kernel._bag) == CTRUE))
       { (Optimize.OPT->allocation = CTRUE);
        range_infers_for_Variable(GC_OBJECT(Variable,v2164->var),GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v10263))),OBJECT(ClaireType,v10263));
        { ClaireType * v12717 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v2164->arg)))));
          Collect * v6224;
          { { Collect * v2072 = ((Collect *) GC_OBJECT(Collect,new_object_class(Language._Collect)));
              (v2072->var = v2164->var);
              (v2072->set_arg = c_gc_I_any1(GC_OID(c_strict_code_any(v12685,Kernel._bag))));
              (v2072->arg = (*Optimize.c_code)(GC_OID(v2164->arg),
                _oid_(Kernel._any)));
              add_I_property(Kernel.instances,Language._Collect,11,_oid_(v2072));
              v6224 = v2072;
              } 
            GC_OBJECT(Collect,v6224);} 
          if (v12717 == Kernel._void)
           (*Optimize.Cerror)(_string_(copy_string("[205] use of void expression ~S in ~S")),
            GC_OID(v2164->arg),
            _oid_(v2164));
          if (get_property(Kernel.of,v2164) != CNULL)
           { if ((Optimize.compiler->safety > 4) || 
                (_inf_equal_type(v12717,GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.of)(_oid_(v2164))))) == CTRUE))
             { update_property(Kernel.of,
                v6224,
                5,
                Kernel._object,
                GC_OID((*Kernel.of)(_oid_(v2164))));
              Result = _oid_(v6224);
              } 
            else { warn_void();
                tformat_string(copy_string("unsafe typed collect (~S): ~S not in ~S [261]\n"),2,list::alloc(3,_oid_(v2164),
                  GC_OID((*Optimize.c_type)(GC_OID(v2164->arg))),
                  GC_OID((*Kernel.of)(_oid_(v2164)))));
                { OID  v994;
                  { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Core.check_in);
                    (v2072->args = list::alloc(3,_oid_(v6224),
                      _oid_(Kernel._list),
                      GC_OID((*Kernel.of)(_oid_(v2164)))));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v994 = _oid_(v2072);
                    } 
                  Result = (*Optimize.c_code)(v994,
                    _oid_(Kernel._list));
                  } 
                } 
              } 
          else Result = _oid_(v6224);
            } 
        } 
      else { OID  v2297;
          if (INHERIT(v2164->isa,Language._Image))
           v2297 = _oid_(set::empty());
          else v2297 = _oid_(list::empty());
            Variable * v6222;
          { { int  v1955;
              { (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+1));
                v1955 = 0;
                } 
              v6222 = Variable_I_symbol(append_symbol(v2164->var->pname,_string_(copy_string("_bag"))),v1955,((INHERIT(v2164->isa,Language._Image)) ?
                Kernel._set :
                Kernel._list ));
              } 
            GC_OBJECT(Variable,v6222);} 
          if (get_property(Kernel.of,v2164) != CNULL)
           { ClaireType * v6207 = GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v2164->arg))));
            if ((_inf_equal_type(ptype_type(v6207),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.of)(_oid_(v2164))))) != CTRUE) && 
                (Optimize.compiler->safety <= 4))
             { warn_void();
              tformat_string(copy_string("unsafe bag construction (~S) : a ~S is not a ~S [262]\n"),2,list::alloc(3,GC_OID(_oid_(v2164->var)),
                _oid_(v6207),
                GC_OID((*Kernel.of)(_oid_(v2164)))));
              } 
            cast_I_bag(OBJECT(bag,v2297),OBJECT(ClaireType,(*Kernel.of)(_oid_(v2164))));
            (v6222->range = param_I_class(GC_OBJECT(ClaireClass,((ClaireClass *) v6222->range)),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.of)(_oid_(v2164))))));
            } 
          else if (Kernel._set == OWNER(v2297))
             { Set * v2072 = ((Set *) GC_OBJECT(Set,new_object_class(Language._Set)));
              (v2072->of = Kernel.emptySet);
              add_I_property(Kernel.instances,Language._Set,11,_oid_(v2072));
              v2297 = _oid_(v2072);
              } 
            else { List * v2072 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
                (v2072->of = Kernel.emptySet);
                add_I_property(Kernel.instances,Language._List,11,_oid_(v2072));
                v2297 = _oid_(v2072);
                } 
              { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
            (v2072->var = v6222);
            (v2072->value = v2297);
            { Let * v8644 = v2072; 
              OID  v8645;
              { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                { Do * v8647 = v2072; 
                  list * v8668;
                  { OID v_bag;
                    GC_ANY(v8668= list::empty(Kernel.emptySet));
                    { { OID  v10557;
                        { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                          (v2072->var = v2164->var);
                          (v2072->set_arg = v12685);
                          { Iteration * v8670 = v2072; 
                            OID  v8671;
                            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                              (v2072->selector = Kernel.add_I);
                              (v2072->args = list::alloc(2,_oid_(v6222),GC_OID(v2164->arg)));
                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                              v8671 = _oid_(v2072);
                              } 
                            (v8670->arg = v8671);} 
                          add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                          v10557 = _oid_(v2072);
                          } 
                        v_bag = (*Optimize.c_code)(v10557,
                          _oid_(Kernel._any));
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v8668)->addFast(v_bag);
                    if (Optimize.OPT->online_ask != CTRUE)
                     { (Optimize.OPT->protection = CTRUE);
                      { Compile_to_protect * v2072 = ((Compile_to_protect *) GC_OBJECT(Compile_to_protect,new_object_class(Optimize._to_protect)));
                        (v2072->arg = _oid_(v6222));
                        add_I_property(Kernel.instances,Optimize._to_protect,11,_oid_(v2072));
                        v_bag = _oid_(v2072);
                        } 
                      } 
                    else v_bag = _oid_(v6222);
                      ((list *) v8668)->addFast(v_bag);} 
                  (v8647->args = v8668);} 
                add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                v8645 = _oid_(v2072);
                } 
              (v8644->arg = v8645);} 
            add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
            Result = _oid_(v2072);
            } 
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Select_Optimize(Select *v2164)
{ return (c_code_select_Iteration(v2164,Kernel._set));} 

OID  c_code_Lselect_Optimize(Lselect *v2164)
{ return (c_code_select_Iteration(v2164,Kernel._list));} 

OID  c_code_select_Iteration(Iteration *v2164,ClaireClass *v6224)
{ GC_BIND;
  { OID Result = 0;
    { OID  v12685 = GC_OID(v2164->set_arg);
      OID  v10263 = GC_OID((*Optimize.c_type)(v12685));
      OID  v12681 = GC_OID(enumerate_code_any(v12685,OBJECT(ClaireType,v10263)));
      bag * v2297;
      if (v6224 == Kernel._set)
       v2297 = set::empty();
      else v2297 = list::empty();
        Variable * v12707;
      { { int  v15362;
          { (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+1));
            v15362 = 0;
            } 
          v12707 = Variable_I_symbol(append_symbol(v2164->var->pname,_string_(copy_string("_in"))),v15362,Kernel._bag);
          } 
        GC_OBJECT(Variable,v12707);} 
      Variable * v12708;
      { { int  v16323;
          { (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+1));
            v16323 = 0;
            } 
          v12708 = Variable_I_symbol(append_symbol(v2164->var->pname,_string_(copy_string("_out"))),v16323,v6224);
          } 
        GC_OBJECT(Variable,v12708);} 
      if (get_property(Kernel.of,v2164) != CNULL)
       { ClaireType * v6207 = GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v10263)));
        if ((_inf_equal_type(ptype_type(v6207),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.of)(_oid_(v2164))))) != CTRUE) && 
            (Optimize.compiler->safety <= 4))
         { warn_void();
          tformat_string(copy_string("unsafe bag construction (~S) : a ~S is not a ~S [262]\n"),2,list::alloc(3,GC_OID(_oid_(v2164->var)),
            _oid_(v6207),
            GC_OID((*Kernel.of)(_oid_(v2164)))));
          } 
        cast_I_bag(v2297,OBJECT(ClaireType,(*Kernel.of)(_oid_(v2164))));
        (v12708->range = param_I_class(v6224,GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.of)(_oid_(v2164))))));
        Result = inner_select_Iteration(v2164,_oid_(v12708),v12685,_oid_(v2297));
        } 
      else if (_inf_equal_type(OBJECT(ClaireType,v10263),v6224) == CTRUE)
       { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
        (v2072->var = v12707);
        (v2072->value = v12681);
        { Let * v8676 = v2072; 
          OID  v8677;
          { OID  v6619;
            { Compile_C_cast * v2072 = ((Compile_C_cast *) GC_OBJECT(Compile_C_cast,new_object_class(Optimize._C_cast)));
              { Compile_to_C * v8700 = v2072; 
                OID  v8701;
                { OID  v9502;
                  { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Kernel.empty);
                    (v2072->args = list::alloc(1,_oid_(v12707)));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v9502 = _oid_(v2072);
                    } 
                  v8701 = (*Optimize.c_code)(v9502,
                    _oid_(Kernel._bag));
                  } 
                (v8700->arg = v8701);} 
              (v2072->set_arg = v6224);
              add_I_property(Kernel.instances,Optimize._C_cast,11,_oid_(v2072));
              v6619 = _oid_(v2072);
              } 
            v8677 = inner_select_Iteration(v2164,_oid_(v12708),_oid_(v12707),v6619);
            } 
          (v8676->arg = v8677);} 
        add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      else { OID  v10463;
          if (v6224 == Kernel._set)
           { Set * v2072 = ((Set *) GC_OBJECT(Set,new_object_class(Language._Set)));
            (v2072->of = Kernel.emptySet);
            add_I_property(Kernel.instances,Language._Set,11,_oid_(v2072));
            v10463 = _oid_(v2072);
            } 
          else { List * v2072 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
              (v2072->of = Kernel.emptySet);
              add_I_property(Kernel.instances,Language._List,11,_oid_(v2072));
              v10463 = _oid_(v2072);
              } 
            Result = inner_select_Iteration(v2164,_oid_(v12708),v12685,v10463);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  inner_select_Iteration(Iteration *v2164,OID v12708,OID v12685,OID v2297)
{ GC_BIND;
  { OID Result = 0;
    { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
      store_object(v2072,
        2,
        Kernel._object,
        v12708,
        CFALSE);
      (v2072->value = v2297);
      { Let * v8706 = v2072; 
        OID  v8707;
        { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
          { Do * v8708 = v2072; 
            list * v8709;
            { OID v_bag;
              GC_ANY(v8709= list::empty(Kernel.emptySet));
              { { OID  v15268;
                  { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                    (v2072->var = v2164->var);
                    (v2072->set_arg = v12685);
                    { Iteration * v8730 = v2072; 
                      OID  v8731;
                      { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                        (v2072->test = v2164->arg);
                        { If * v8732 = v2072; 
                          OID  v8733;
                          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                            (v2072->selector = Kernel.add_I);
                            (v2072->args = list::alloc(2,v12708,GC_OID(_oid_(v2164->var))));
                            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                            v8733 = _oid_(v2072);
                            } 
                          (v8732->arg = v8733);} 
                        add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                        (v2072->other = Kernel.cfalse);
                        v8731 = _oid_(v2072);
                        } 
                      (v8730->arg = v8731);} 
                    add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                    v15268 = _oid_(v2072);
                    } 
                  v_bag = (*Optimize.c_code)(v15268,
                    _oid_(Kernel._any));
                  } 
                GC_OID(v_bag);} 
              ((list *) v8709)->addFast(v_bag);
              if (Optimize.OPT->online_ask != CTRUE)
               { (Optimize.OPT->protection = CTRUE);
                { Compile_to_protect * v2072 = ((Compile_to_protect *) GC_OBJECT(Compile_to_protect,new_object_class(Optimize._to_protect)));
                  (v2072->arg = v12708);
                  add_I_property(Kernel.instances,Optimize._to_protect,11,_oid_(v2072));
                  v_bag = _oid_(v2072);
                  } 
                } 
              else v_bag = v12708;
                ((list *) v8709)->addFast(v_bag);} 
            (v8708->args = v8709);} 
          add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
          v8707 = _oid_(v2072);
          } 
        (v8706->arg = v8707);} 
      add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Exists_Optimize(Exists *v2164)
{ GC_BIND;
  { ClaireType *Result ;
    { OID  v10263 = GC_OID((*Optimize.c_type)(GC_OID(v2164->set_arg)));
      range_infers_for_Variable(GC_OBJECT(Variable,v2164->var),GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v10263))),OBJECT(ClaireType,v10263));
      if (v2164->other == CNULL)
       Result = extends_type(GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v10263))));
      else Result = Kernel._boolean;
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Exists_Optimize(Exists *v2164,ClaireClass *v6219)
{ GC_BIND;
  { OID Result = 0;
    { OID  v10263 = GC_OID((*Optimize.c_type)(GC_OID(v2164->set_arg)));
      range_infers_for_Variable(GC_OBJECT(Variable,v2164->var),GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v10263))),OBJECT(ClaireType,v10263));
      if (v2164->other == Kernel.ctrue)
       { OID  v8447;
        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v2072->selector = Core.NOT);
          { Call * v8736 = v2072; 
            list * v8737;
            { OID v_bag;
              GC_ANY(v8737= list::empty(Kernel.emptySet));
              { { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                  (v2072->var = v2164->var);
                  (v2072->set_arg = v2164->set_arg);
                  { Iteration * v8738 = v2072; 
                    OID  v8739;
                    { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                      { If * v8762 = v2072; 
                        OID  v8763;
                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v2072->selector = Core.NOT);
                          (v2072->args = list::alloc(1,GC_OID(v2164->arg)));
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                          v8763 = _oid_(v2072);
                          } 
                        (v8762->test = v8763);} 
                      { If * v8764 = v2072; 
                        OID  v8765;
                        { Return * v2072 = ((Return *) GC_OBJECT(Return,new_object_class(Language._Return)));
                          (v2072->arg = Kernel.ctrue);
                          add_I_property(Kernel.instances,Language._Return,11,_oid_(v2072));
                          v8765 = _oid_(v2072);
                          } 
                        (v8764->arg = v8765);} 
                      add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                      (v2072->other = Kernel.cfalse);
                      v8739 = _oid_(v2072);
                      } 
                    (v8738->arg = v8739);} 
                  add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                  v_bag = _oid_(v2072);
                  } 
                GC_OID(v_bag);} 
              ((list *) v8737)->addFast(v_bag);} 
            (v8736->args = v8737);} 
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
          v8447 = _oid_(v2072);
          } 
        Result = (*Optimize.c_code)(v8447,
          _oid_(v6219));
        } 
      else if (v2164->other == CNULL)
       { Variable * v6222;
        { { int  v4509;
            { (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+1));
              v4509 = 0;
              } 
            v6222 = Variable_I_symbol(append_symbol(v2164->var->pname,_string_(copy_string("_some"))),v4509,GC_OBJECT(ClaireType,extends_type(GC_OBJECT(ClaireType,v2164->var->range))));
            } 
          GC_OBJECT(Variable,v6222);} 
        { OID  v5470;
          { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
            (v2072->var = v6222);
            (v2072->value = CNULL);
            { Let * v8768 = v2072; 
              OID  v8769;
              { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                { Do * v8770 = v2072; 
                  list * v8771;
                  { OID v_bag;
                    GC_ANY(v8771= list::empty(Kernel.emptySet));
                    { { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                        (v2072->var = v2164->var);
                        (v2072->set_arg = v2164->set_arg);
                        { Iteration * v8792 = v2072; 
                          OID  v8793;
                          { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                            (v2072->test = v2164->arg);
                            { If * v8796 = v2072; 
                              OID  v8797;
                              { Return * v2072 = ((Return *) GC_OBJECT(Return,new_object_class(Language._Return)));
                                { Return * v8798 = v2072; 
                                  OID  v8799;
                                  { Assign * v2072 = ((Assign *) GC_OBJECT(Assign,new_object_class(Language._Assign)));
                                    (v2072->var = _oid_(v6222));
                                    (v2072->arg = _oid_(v2164->var));
                                    add_I_property(Kernel.instances,Language._Assign,11,_oid_(v2072));
                                    v8799 = _oid_(v2072);
                                    } 
                                  (v8798->arg = v8799);} 
                                add_I_property(Kernel.instances,Language._Return,11,_oid_(v2072));
                                v8797 = _oid_(v2072);
                                } 
                              (v8796->arg = v8797);} 
                            add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                            (v2072->other = Kernel.cfalse);
                            v8793 = _oid_(v2072);
                            } 
                          (v8792->arg = v8793);} 
                        add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                        v_bag = _oid_(v2072);
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v8771)->addFast(v_bag);
                    ((list *) v8771)->addFast(_oid_(v6222));} 
                  (v8770->args = v8771);} 
                add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                v8769 = _oid_(v2072);
                } 
              (v8768->arg = v8769);} 
            add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
            v5470 = _oid_(v2072);
            } 
          Result = (*Optimize.c_code)(v5470,
            _oid_(v6219));
          } 
        } 
      else { OID  v3454;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.boolean_I);
            { Call * v8801 = v2072; 
              list * v8802;
              { OID v_bag;
                GC_ANY(v8802= list::empty(Kernel.emptySet));
                { { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                    (v2072->var = v2164->var);
                    (v2072->set_arg = v2164->set_arg);
                    { Iteration * v8803 = v2072; 
                      OID  v9474;
                      { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                        (v2072->test = v2164->arg);
                        { If * v9475 = v2072; 
                          OID  v9476;
                          { Return * v2072 = ((Return *) GC_OBJECT(Return,new_object_class(Language._Return)));
                            (v2072->arg = Kernel.ctrue);
                            add_I_property(Kernel.instances,Language._Return,11,_oid_(v2072));
                            v9476 = _oid_(v2072);
                            } 
                          (v9475->arg = v9476);} 
                        add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                        (v2072->other = Kernel.cfalse);
                        v9474 = _oid_(v2072);
                        } 
                      (v8803->arg = v9474);} 
                    add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                    v_bag = _oid_(v2072);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v8802)->addFast(v_bag);} 
              (v8801->args = v8802);} 
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v3454 = _oid_(v2072);
            } 
          Result = (*Optimize.c_code)(v3454,
            _oid_(v6219));
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Image_Optimize(Image *v2164)
{ GC_BIND;
  { ClaireType *Result ;
    { ClaireType * v10263 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v2164->set_arg)))));
      range_infers_for_Variable(GC_OBJECT(Variable,v2164->var),GC_OBJECT(ClaireType,pmember_type(v10263)),v10263);
      Result = ((((v2164->of == (NULL)) ? CTRUE : CFALSE) != CTRUE) ?
        param_I_class(Kernel._set,GC_OBJECT(ClaireType,v2164->of)) :
        nth_class1(Kernel._set,GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v2164->arg))))) );
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Select_Optimize(Select *v2164)
{ GC_BIND;
  { ClaireType *Result ;
    { OID  v10263 = GC_OID((*Optimize.c_type)(GC_OID(v2164->set_arg)));
      range_infers_for_Variable(GC_OBJECT(Variable,v2164->var),GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v10263))),OBJECT(ClaireType,v10263));
      Result = ((((v2164->of == (NULL)) ? CTRUE : CFALSE) != CTRUE) ?
        param_I_class(Kernel._set,GC_OBJECT(ClaireType,v2164->of)) :
        nth_class1(Kernel._set,GC_OBJECT(ClaireType,pmember_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v2164->set_arg))))))) );
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Lselect_Optimize(Lselect *v2164)
{ GC_BIND;
  { ClaireType *Result ;
    { OID  v10263 = GC_OID((*Optimize.c_type)(GC_OID(v2164->set_arg)));
      range_infers_for_Variable(GC_OBJECT(Variable,v2164->var),GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v10263))),OBJECT(ClaireType,v10263));
      Result = ((((v2164->of == (NULL)) ? CTRUE : CFALSE) != CTRUE) ?
        param_I_class(Kernel._list,GC_OBJECT(ClaireType,v2164->of)) :
        nth_class1(Kernel._list,GC_OBJECT(ClaireType,pmember_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v2164->set_arg))))))) );
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_While_Optimize(While *v2164)
{ GC_BIND;
  { ClaireType *Result ;
    Result = infers_from_type2(GC_OBJECT(ClaireType,return_type_any(GC_OID(v2164->arg))),_oid_(v2164));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_While_Optimize(While *v2164,ClaireClass *v6219)
{ GC_BIND;
  { OID Result = 0;
    { ClaireBoolean * v6202 = Optimize.OPT->protection;
      (Optimize.OPT->protection = CFALSE);
      { While * v6218;
        { { While * v2072 = ((While *) GC_OBJECT(While,new_object_class(Language._While)));
            (v2072->test = c_boolean_any(GC_OID(v2164->test)));
            (v2072->arg = (*Optimize.c_code)(GC_OID(v2164->arg),
              _oid_(Kernel._void)));
            (v2072->other = v2164->other);
            add_I_property(Kernel.instances,Language._While,11,_oid_(v2072));
            v6218 = v2072;
            } 
          GC_OBJECT(While,v6218);} 
        if ((Optimize.OPT->protection == CTRUE) && 
            (0 <= Optimize.OPT->loop_index))
         (Optimize.OPT->loop_gc = CTRUE);
        (Optimize.OPT->protection = ((Optimize.OPT->protection == CTRUE) ? CTRUE : ((v6202 == CTRUE) ? CTRUE : CFALSE)));
        if ((v6219 != Kernel._void) && 
            (v6219 != Kernel._any))
         { { Compile_to_C * v2072 = ((Compile_to_C *) GC_OBJECT(Compile_to_C,new_object_class(Optimize._to_C)));
            (v2072->arg = _oid_(v6218));
            (v2072->set_arg = v6219);
            add_I_property(Kernel.instances,Optimize._to_C,11,_oid_(v2072));
            Result = _oid_(v2072);
            } 
          } 
        else Result = _oid_(v6218);
          } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Iterate_I_Iteration(Iteration *v2164)
{ GC_BIND;
  { OID Result = 0;
    Result = restriction_I_property(Language.Iterate,list::alloc(3,_oid_(set::alloc(1,GC_OID(v2164->set_arg))),
      _oid_(set::alloc(1,GC_OID(_oid_(v2164->var)))),
      _oid_(Kernel._any)),CTRUE);
    GC_UNBIND; return (Result);} 
  } 

OID  iterate_Interval(Interval *v6224,Variable *v6222,OID v6205)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID Result = 0;
    { OID  v6222 = GC_OID(eval_any2(v6224->arg1,Core._Interval));
      int  v12359 = eval_any2(v6224->arg2,Core._Interval);
      { OID gc_local;
        Result= _oid_(CFALSE);
        while ((v6222 <= v12359))
        { GC_LOOP;
          ;GC__OID(v6222 = (*Core._plus)(v6222,
            1), 1);
          GC_UNLOOP;} 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  iterate_array(OID *v6224,Variable *v6222,OID v6205)
{ { OID Result = 0;
    { int  v10252 = 1;
      OID * v10244 = v6224;
      int  v12359 = v10244[0];
      { Result= _oid_(CFALSE);
        while ((v10252 <= v12359))
        { { OID  v6222 = nth_array(v10244,v10252);
            ;++v10252;
            } 
          } 
        } 
      } 
    return (Result);} 
  } 

OID  Iterate_class(ClaireClass *v6224,Variable *v6222,OID v6205)
{ { OID Result = 0;
    { ITERATE(v4491);
      Result= Kernel.cfalse;
      for (START(v6224->descendents); NEXT(v4491);)
      { ClaireBoolean * v4492;
        { OID v15730;{ ITERATE(v6222);
            v15730= Kernel.cfalse;
            for (START(OBJECT(ClaireClass,v4491)->instances); NEXT(v6222);)
            ;} 
          
          v4492=OBJECT(ClaireBoolean,v15730);} 
        if (v4492 == CTRUE)
         { Result = _oid_(v4492);
          break;} 
        } 
      } 
    return (Result);} 
  } 

OID  Iterate_any1(OID v6224,Variable *v6222,OID v6205)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID Result = 0;
    { OID  v6222 = GC_OID(OPT_EVAL((*(OBJECT(Call,v6224)->args))[1]));
      OID  v12359 = GC_OID(OPT_EVAL((*(OBJECT(Call,v6224)->args))[2]));
      { OID gc_local;
        Result= _oid_(CFALSE);
        while (((OBJECT(ClaireBoolean,(*Kernel._inf_equal)(v6222,
          v12359))) == CTRUE))
        { GC_LOOP;
          ;GC__OID(v6222 = (*Core._plus)(v6222,
            1), 1);
          GC_UNLOOP;} 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Iterate_Lselect(Lselect *v6224,Variable *v6222,OID v6205)
{ GC_BIND;
  { OID Result = 0;
    { OID gc_local;
      ITERATE(v6222);
      Result= Kernel.cfalse;
      bag *v6222_support;
      v6222_support = GC_OBJECT(bag,enumerate_any(GC_OID(eval_any(GC_OID(v6224->set_arg)))));
      for (START(v6222_support); NEXT(v6222);)
      { GC_LOOP;
        if (boolean_I_any(eval_any(GC_OID(substitution_any(GC_OID(v6224->arg),GC_OBJECT(Variable,v6224->var),v6222)))) == CTRUE)
         ;GC_UNLOOP;} 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Iterate_Select(Select *v6224,Variable *v6222,OID v6205)
{ GC_BIND;
  { OID Result = 0;
    { OID gc_local;
      ITERATE(v6222);
      Result= Kernel.cfalse;
      bag *v6222_support;
      v6222_support = GC_OBJECT(bag,enumerate_any(GC_OID(eval_any(GC_OID(v6224->set_arg)))));
      for (START(v6222_support); NEXT(v6222);)
      { GC_LOOP;
        if (boolean_I_any(eval_any(GC_OID(substitution_any(GC_OID(v6224->arg),GC_OBJECT(Variable,v6224->var),v6222)))) == CTRUE)
         ;GC_UNLOOP;} 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Iterate_Collect(Collect *v6224,Variable *v6222,OID v6205)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID Result = 0;
    { OID gc_local;
      ITERATE(v588);
      Result= Kernel.cfalse;
      bag *v588_support;
      v588_support = GC_OBJECT(bag,enumerate_any(GC_OID(eval_any(GC_OID(v6224->set_arg)))));
      for (START(v588_support); NEXT(v588);)
      { GC_LOOP;
        { OID  v6222 = GC_OID(eval_any(GC_OID(substitution_any(GC_OID(v6224->arg),GC_OBJECT(Variable,v6224->var),v588))));
          ;} 
        GC_UNLOOP;} 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Iterate_any2(OID v6224,Variable *v6222,OID v6205)
{ GC_BIND;
  { OID Result = 0;
    { OID gc_local;
      ITERATE(v6222);
      Result= Kernel.cfalse;
      bag *v6222_support;
      v6222_support = GC_OBJECT(bag,enumerate_any(GC_OID(OPT_EVAL((*(OBJECT(Call,v6224)->args))[1]))));
      for (START(v6222_support); NEXT(v6222);)
      { GC_LOOP;
        if (equal(v6222,OPT_EVAL((*(OBJECT(Call,v6224)->args))[2])) != CTRUE)
         ;GC_UNLOOP;} 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Iterate_any3(OID v6224,Variable *v6222,OID v6205)
{ GC_BIND;
  { OID gc_local;
    ITERATE(v6222);
    bag *v6222_support;
    v6222_support = GC_OBJECT(bag,enumerate_any(GC_OID(OPT_EVAL((*(OBJECT(Call,v6224)->args))[1]))));
    for (START(v6222_support); NEXT(v6222);)
    ;} 
  { OID Result = 0;
    { OID gc_local;
      ITERATE(v6222);
      Result= Kernel.cfalse;
      bag *v6222_support;
      v6222_support = GC_OBJECT(bag,enumerate_any(GC_OID(OPT_EVAL((*(OBJECT(Call,v6224)->args))[2]))));
      for (START(v6222_support); NEXT(v6222);)
      ;} 
    GC_UNBIND; return (Result);} 
  } 

