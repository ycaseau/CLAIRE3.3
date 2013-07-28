/***** CLAIRE Compilation of file c:\claire\v3.3\src\compile\osystem.cl 
         [version 3.3.46 / safety 5] Sun Feb 15 15:37:26 2009 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
char * home_void()
{ return (getenv_string("CLAIRE3_HOME"));} 

OID  safe_any2(OID v6224)
{ return (v6224);} 

ClaireType * safe_any2_type(ClaireType *v6224)
{ return (v6224);} 

ClaireType * c_type_any_Optimize(OID v2164)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { ClaireType *Result ;
    { ClaireObject *V_CC ;
      if (INHERIT(OWNER(v2164),Language._Variable))
       { OID  v6218 = GC_OID(get_property(Kernel.range,OBJECT(ClaireObject,v2164)));
        if (v6218 == CNULL)
         V_CC = Kernel._any;
        else V_CC = (((INHERIT(OWNER(v6218),Core._Union)) && (equal(_oid_(OBJECT(Union,v6218)->t1),_oid_(Kernel.emptySet)) == CTRUE)) ?
          CLREAD(Union,OBJECT(Union,v6218)->t2,t2) :
          ptype_type(OBJECT(ClaireType,v6218)) );
        } 
      else if (INHERIT(OWNER(v2164),Core._global_variable))
       { ClaireType * v6218 = OBJECT(global_variable,v2164)->range;
        if (boolean_I_any(_oid_(v6218)) == CTRUE)
         V_CC = v6218;
        else V_CC = set::alloc(1,OBJECT(global_variable,v2164)->value);
          } 
      else if (INHERIT(OWNER(v2164),Kernel._unbound_symbol))
       V_CC = OBJECT(ClaireType,(*Optimize.Cerror)(_string_(copy_string("[215] the symbol ~A is unbound_symbol")),
        _oid_(OBJECT(unbound_symbol,v2164)->name)));
      else if (INHERIT(OWNER(v2164),Kernel._error))
       V_CC = Kernel.emptySet;
      else if (INHERIT(OWNER(v2164),Language._Update))
       V_CC = OBJECT(ClaireType,(*Optimize.c_type)(OBJECT(Update,v2164)->value));
      else if (INHERIT(OWNER(v2164),Language._Construct))
       { if (((INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._List)) ? CTRUE : ((INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Set)) ? CTRUE : CFALSE)) != CTRUE)
         V_CC = Kernel._any;
        else { ClaireType * v899 = Kernel.emptySet;
            { OID gc_local;
              ITERATE(v10267);
              for (START(OBJECT(Construct,v2164)->args); NEXT(v10267);)
              { GC_LOOP;
                if (boolean_I_any(_oid_(v899)) == CTRUE)
                 GC__ANY(v899 = meet_class(((ClaireClass *) v899),class_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v10267))))), 1);
                else GC__ANY(v899 = class_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v10267)))), 1);
                  GC_UNLOOP;} 
              } 
            V_CC = nth_class1(((INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Set)) ?
              Kernel._set :
              Kernel._list ),v899);
            } 
          } 
      else if (INHERIT(OWNER(v2164),Language._Instruction))
       close_exception(((general_error *) (*Core._general_error)(_string_(copy_string("c_type of ~S is not defined")),
        _oid_(list::alloc(1,_oid_(OWNER(v2164)))))));
      else V_CC = set::alloc(1,v2164);
        Result= (ClaireType *) V_CC;} 
    GC_UNBIND; return (Result);} 
  } 

OID  c_strict_code_any(OID v6224,ClaireClass *v6219)
{ GC_BIND;
  { OID Result = 0;
    Result = (*Optimize.c_strict_check)(GC_OID((*Optimize.c_code)(v6224,
        _oid_(v6219))),
      _oid_(v6219));
    GC_UNBIND; return (Result);} 
  } 

OID  c_strict_check_any_Optimize(OID v6224,ClaireClass *v6219)
{ GC_BIND;
  { OID Result = 0;
    if ((Optimize.OPT->online_ask != CTRUE) && 
        ((INHERIT(v6219,Kernel._object)) && 
          (inherit_ask_class(stupid_t_any1(v6224),v6219) != CTRUE)))
     { if ((*Optimize.c_type)(v6224) == _oid_(Kernel._any))
       (*Optimize.Cerror)(_string_(copy_string("Need explict cast: ~S is not a ~S")),
        v6224,
        _oid_(v6219));
      { Compile_C_cast * v2072 = ((Compile_C_cast *) GC_OBJECT(Compile_C_cast,new_object_class(Optimize._C_cast)));
        (v2072->arg = v6224);
        (v2072->set_arg = v6219);
        add_I_property(Kernel.instances,Optimize._C_cast,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      } 
    else Result = v6224;
      GC_UNBIND; return (Result);} 
  } 

OID  c_code_any1_Optimize(OID v6224,ClaireClass *v6219)
{ GC_BIND;
  { OID Result = 0;
    { OID  v6225;
      { if (INHERIT(OWNER(v6224),Language._Call))
         v6225 = c_code_call_Call(OBJECT(Call,v6224),v6219);
        else v6225 = (*Optimize.c_code)(v6224);
          GC_OID(v6225);} 
      ClaireClass * v6226 = OBJECT(ClaireClass,(*Optimize.c_sort)(v6225));
      if ((v6219 == Kernel._void) || 
          ((v6226 == v6219) || 
            (Optimize.OPT->online_ask == CTRUE)))
       { if ((v6219 == Kernel._void) && 
            ((INHERIT(OWNER(v6224),Language._Call)) && (OBJECT(Call,v6224)->selector == Kernel._equal)))
         { warn_void();
          tformat_string(copy_string("-- Equality meant as an assignment: ~S [264]\n"),2,list::alloc(1,v6224));
          } 
        Result = v6225;
        } 
      else if (v6219 == Kernel._any)
       { if ((v6226 == Kernel._integer) && 
            ((INHERIT(OWNER(v6225),Language._Call_slot)) && 
              (((Optimize.compiler->overflow_ask == CTRUE) ? ((Optimize.compiler->class2file_ask == CTRUE) ? CTRUE: CFALSE): CFALSE) != CTRUE)))
         Result = v6225;
        else if (INHERIT(OWNER(v6225),Optimize._to_C))
         Result = OBJECT(Compile_to_C,v6225)->arg;
        else { if (v6226 == Kernel._float)
             { (Optimize.OPT->protection = CTRUE);
              (Optimize.OPT->allocation = CTRUE);
              } 
            { Compile_to_CL * v2072 = ((Compile_to_CL *) GC_OBJECT(Compile_to_CL,new_object_class(Optimize._to_CL)));
              (v2072->arg = v6225);
              (v2072->set_arg = psort_any(GC_OID((*Optimize.c_type)(v6225))));
              add_I_property(Kernel.instances,Optimize._to_CL,11,_oid_(v2072));
              Result = _oid_(v2072);
              } 
            } 
          } 
      else if (v6226 == Kernel._any)
       { Compile_to_C * v2072 = ((Compile_to_C *) GC_OBJECT(Compile_to_C,new_object_class(Optimize._to_C)));
        (v2072->arg = v6225);
        (v2072->set_arg = v6219);
        add_I_property(Kernel.instances,Optimize._to_C,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      else Result = v6225;
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_any2_Optimize(OID v2164)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(OWNER(v2164),Kernel._unbound_symbol))
     Result = (*Optimize.Cerror)(_string_(copy_string("[215] the symbol ~A is unbound_symbol")),
      _oid_(OBJECT(unbound_symbol,v2164)->name));
    else if (INHERIT(OWNER(v2164),Language._Variable))
     Result = v2164;
    else if (INHERIT(OWNER(v2164),Core._global_variable))
     { c_register_object(OBJECT(ClaireObject,v2164));
      Result = v2164;
      } 
    else if (INHERIT(OWNER(v2164),Language._Optimized_instruction))
     Result = v2164;
    else if (INHERIT(OWNER(v2164),Language._Instruction))
     Result = (*Optimize.Cerror)(_string_(copy_string("[internal] c_code(~S) should have a parameter")),
      v2164);
    else if (Kernel._set == OWNER(v2164))
     { if (OBJECT(bag,v2164)->length != 0)
       { Set * v6224;
        { { Set * v2072 = ((Set *) GC_OBJECT(Set,new_object_class(Language._Set)));
            (v2072->args = list_I_set(OBJECT(set,v2164)));
            add_I_property(Kernel.instances,Language._Set,11,_oid_(v2072));
            v6224 = v2072;
            } 
          GC_OBJECT(Set,v6224);} 
        if (of_bag(OBJECT(bag,v2164)) != Kernel._void)
         (v6224->of = of_bag(OBJECT(bag,v2164)));
        Result = (*Optimize.c_code)(_oid_(v6224));
        } 
      else Result = v2164;
        } 
    else if (INHERIT(OWNER(v2164),Kernel._list))
     { if (OBJECT(bag,v2164)->length != 0)
       { List * v6224;
        { { List * v2072 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
            (v2072->args = OBJECT(list,v2164));
            add_I_property(Kernel.instances,Language._List,11,_oid_(v2072));
            v6224 = v2072;
            } 
          GC_OBJECT(List,v6224);} 
        if (of_bag(OBJECT(bag,v2164)) != Kernel._void)
         (v6224->of = of_bag(OBJECT(bag,v2164)));
        Result = (*Optimize.c_code)(_oid_(v6224));
        } 
      else Result = v2164;
        } 
    else if (INHERIT(OWNER(v2164),Kernel._tuple))
     { OID  v14369;
      { Tuple * v2072 = ((Tuple *) GC_OBJECT(Tuple,new_object_class(Language._Tuple)));
        (v2072->args = OBJECT(list,v2164));
        add_I_property(Kernel.instances,Language._Tuple,11,_oid_(v2072));
        v14369 = _oid_(v2072);
        } 
      Result = (*Optimize.c_code)(v14369);
      } 
    else { if (INHERIT(OWNER(v2164),Kernel._thing))
         (*Optimize.c_register)(v2164);
        if ((Kernel._float == OWNER(v2164)) || 
            (INHERIT(OWNER(v2164),Kernel._function)))
         (Optimize.OPT->allocation = CTRUE);
        Result = v2164;
        } 
      GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_any(OID v2164)
{ { ClaireBoolean *Result ;
    Result = ((INHERIT(OWNER(v2164),Language._Variable)) ?
      CFALSE :
      ((INHERIT(OWNER(v2164),Core._global_variable)) ?
        not_any(_oid_((INHERIT(OBJECT(global_variable,v2164)->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(OBJECT(global_variable,v2164)->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(OBJECT(global_variable,v2164)->range)))))) :
        ((INHERIT(OWNER(v2164),Language._Construct)) ?
          ((Optimize.OPT->loop_gc == CTRUE) ? (((INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._List)) || 
              (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Set))) ? CTRUE: CFALSE): CFALSE) :
          ((INHERIT(OWNER(v2164),Language._Instruction)) ?
            CFALSE :
            CFALSE ) ) ) );
    return (Result);} 
  } 

ClaireClass * c_sort_any_Optimize(OID v2164)
{ GC_BIND;
  { ClaireClass *Result ;
    { ClaireObject *V_CC ;
      if (INHERIT(OWNER(v2164),Core._global_variable))
       { V_CC = ((nativeVar_ask_global_variable(OBJECT(global_variable,v2164)) == CTRUE) ?
          ((equal(_oid_(OBJECT(global_variable,v2164)->range),_oid_(Kernel.emptySet)) == CTRUE) ?
            osort_any(_oid_(OWNER(OBJECT(global_variable,v2164)->value))) :
            osort_any(_oid_(OBJECT(global_variable,v2164)->range)) ) :
          Kernel._any );
        } 
      else if (INHERIT(OWNER(v2164),Language._Instruction))
       { if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Variable))
         V_CC = sort_Variable(OBJECT(Variable,v2164));
        else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Assign))
         V_CC = sort_Variable(GC_OBJECT(Variable,OBJECT(Variable,OBJECT(Assign,v2164)->var)));
        else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Call))
         V_CC = osort_any(_oid_(selector_psort_Call(OBJECT(Call,v2164))));
        else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Call_method))
         { V_CC = (((OBJECT(Call_method,v2164)->arg->selector == Core.externC) && 
              (OBJECT(Call_method,v2164)->args->length == 2)) ?
            psort_any((*(OBJECT(Call_method,v2164)->args))[2]) :
            c_srange_method(OBJECT(Call_method,v2164)->arg) );
          } 
        else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Call_slot))
         V_CC = OBJECT(Call_slot,v2164)->selector->srange;
        else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Call_table))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Call_array))
         { V_CC = ((OBJECT(Call_array,v2164)->test == _oid_(Kernel._float)) ?
            Kernel._float :
            Kernel._any );
          } 
        else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Definition))
         V_CC = Kernel._object;
        else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Optimize._to_C))
         V_CC = OBJECT(Compile_to_C,v2164)->set_arg;
        else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Optimize._to_protect))
         V_CC = OBJECT(ClaireClass,(*Optimize.c_sort)(OBJECT(Compile_to_protect,v2164)->arg));
        else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Update))
         V_CC = OBJECT(ClaireClass,(*Optimize.c_sort)(OBJECT(Update,v2164)->value));
        else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._If))
         V_CC = psort_any(_oid_(meet_class(OBJECT(ClaireClass,(*Optimize.c_sort)(OBJECT(If,v2164)->arg)),OBJECT(ClaireClass,(*Optimize.c_sort)(OBJECT(If,v2164)->other)))));
        else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Handle))
         V_CC = psort_any(_oid_(meet_class(OBJECT(ClaireClass,(*Optimize.c_sort)(OBJECT(ClaireHandle,v2164)->arg)),OBJECT(ClaireClass,(*Optimize.c_sort)(OBJECT(ClaireHandle,v2164)->other)))));
        else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Let))
         V_CC = OBJECT(ClaireClass,(*Optimize.c_sort)(OBJECT(Let,v2164)->arg));
        else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Optimize._to_CL))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Return))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._List))
         V_CC = Kernel._object;
        else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Set))
         V_CC = Kernel._object;
        else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Tuple))
         V_CC = Kernel._object;
        else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Construct))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Gassign))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Super))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._For))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Exists))
         { V_CC = ((OBJECT(Exists,v2164)->other == CNULL) ?
            Kernel._any :
            Kernel._object );
          } 
        else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Iteration))
         V_CC = Kernel._object;
        else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._And))
         V_CC = Kernel._boolean;
        else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Or))
         V_CC = Kernel._boolean;
        else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._While))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Do))
         V_CC = OBJECT(ClaireClass,(*Optimize.c_sort)(GC_OID(last_list(OBJECT(Do,v2164)->args))));
        else close_exception(((general_error *) (*Core._general_error)(_string_(copy_string("[internal] c_sort is not implemented for ~S")),
            _oid_(list::alloc(1,_oid_(OWNER(v2164)))))));
          } 
      else V_CC = ((Kernel._float == OWNER(v2164)) ?
        Kernel._float :
        psort_any(GC_OID((*Optimize.c_type)(v2164))) );
      Result= (ClaireClass *) V_CC;} 
    GC_UNBIND; return (Result);} 
  } 

ClaireClass * selector_psort_Call(Call *v2164)
{ { ClaireClass *Result ;
    { property * v6216 = v2164->selector;
      Result = (((v6216 == Core.base_I) || 
          (v6216 == Core.index_I)) ?
        Kernel._integer :
        ((v6216 == Optimize.anyObject_I) ?
          OBJECT(ClaireClass,(*(v2164->args))[1]) :
          ((v6216 == Optimize.object_I) ?
            OBJECT(ClaireClass,(*(v2164->args))[2]) :
            Kernel._any ) ) );
      } 
    return (Result);} 
  } 

int  c_status_any(OID v2164,list *v6212)
{ GC_BIND;
  { int Result = 0;
    if (INHERIT(OWNER(v2164),Language._Instruction))
     { if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Variable))
       { Result = (((OBJECT(Variable,v2164)->range == (NULL)) || 
            ((*Optimize.gcsafe_ask)(GC_OID(_oid_(OBJECT(Variable,v2164)->range))) != Kernel.ctrue)) ?
          ((contain_ask_list(v6212,v2164) == CTRUE) ?
            16 :
            (((((OBJECT(Variable,v2164)->range == (NULL)) ? CTRUE : CFALSE) != CTRUE) && 
                (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(Variable,v2164)->range),Kernel._float) == CTRUE)) ?
              2 :
              0 ) ) :
          32 );
        } 
      else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Error))
       Result = 32;
      else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Printf))
       { int  v10337;
        { int  v6594 = 0;
          { OID gc_local;
            ITERATE(v6596);
            bag *v6596_support;
            v6596_support = GC_OBJECT(list,OBJECT(Construct,v2164)->args);
            for (START(v6596_support); NEXT(v6596);)
            { int  v6595 = c_status_any(v6596,v6212);
              v6594= c_or_integer(v6594,v6595);
              } 
            } 
          v10337 = v6594;
          } 
        Result = c_return_integer(0,v10337);
        } 
      else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Construct))
       Result = 2;
      else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Definition))
       Result = 2;
      else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Call))
       { int  v12583 = c_status_property(OBJECT(Call,v2164)->selector);
        int  v12584;
        { int  v6597 = 0;
          { OID gc_local;
            ITERATE(v6599);
            bag *v6599_support;
            v6599_support = GC_OBJECT(list,OBJECT(Call,v2164)->args);
            for (START(v6599_support); NEXT(v6599);)
            { int  v6598 = c_status_any(v6599,v6212);
              v6597= c_or_integer(v6597,v6598);
              } 
            } 
          v12584 = v6597;
          } 
        Result = c_return_integer(v12583,v12584);
        } 
      else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._If))
       { int  v12583 = c_status_any(GC_OID(OBJECT(If,v2164)->arg),v6212);
        int  v12584 = c_status_any(GC_OID(OBJECT(If,v2164)->other),v6212);
        Result = c_return_integer(c_or_integer(v12583,v12584),c_status_any(GC_OID(OBJECT(If,v2164)->test),v6212));
        } 
      else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Do))
       { OID  v6225 = GC_OID(last_list(OBJECT(Do,v2164)->args));
        int  v12583 = c_status_any(v6225,v6212);
        int  v12584;
        { int  v6600 = 0;
          { OID gc_local;
            ITERATE(v6623);
            bag *v6623_support;
            v6623_support = GC_OBJECT(list,OBJECT(Do,v2164)->args);
            for (START(v6623_support); NEXT(v6623);)
            if (equal(v6623,v6225) != CTRUE)
             { int  v6622 = c_status_any(v6623,v6212);
              v6600= c_or_integer(v6600,v6622);
              } 
            } 
          v12584 = v6600;
          } 
        Result = c_return_integer(v12583,v12584);
        } 
      else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._For))
       Result = c_return_integer(c_status_any(GC_OID(OBJECT(Iteration,v2164)->arg),v6212),c_status_any(GC_OID(OBJECT(Iteration,v2164)->set_arg),v6212));
      else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Iteration))
       Result = c_return_integer(2,c_status_any(GC_OID(OBJECT(Iteration,v2164)->arg),v6212));
      else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Let))
       Result = c_return_integer(c_status_any(GC_OID(OBJECT(Let,v2164)->arg),v6212),c_status_any(GC_OID(OBJECT(Let,v2164)->value),v6212));
      else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Assign))
       Result = c_status_any(GC_OID(OBJECT(Assign,v2164)->arg),v6212);
      else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Gassign))
       Result = c_status_any(GC_OID(OBJECT(Gassign,v2164)->arg),v6212);
      else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._And))
       { int  v11298;
        { int  v6624 = 0;
          { OID gc_local;
            ITERATE(v6626);
            bag *v6626_support;
            v6626_support = GC_OBJECT(list,OBJECT(And,v2164)->args);
            for (START(v6626_support); NEXT(v6626);)
            { int  v6625 = c_status_any(v6626,v6212);
              v6624= c_or_integer(v6624,v6625);
              } 
            } 
          v11298 = v6624;
          } 
        Result = c_return_integer(0,v11298);
        } 
      else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Or))
       { int  v12259;
        { int  v6627 = 0;
          { OID gc_local;
            ITERATE(v6629);
            bag *v6629_support;
            v6629_support = GC_OBJECT(list,OBJECT(Or,v2164)->args);
            for (START(v6629_support); NEXT(v6629);)
            { int  v6628 = c_status_any(v6629,v6212);
              v6627= c_or_integer(v6627,v6628);
              } 
            } 
          v12259 = v6627;
          } 
        Result = c_return_integer(0,v12259);
        } 
      else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Cast))
       Result = c_status_any(GC_OID(OBJECT(Cast,v2164)->arg),v6212);
      else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Super))
       { int  v12583 = c_status_property(OBJECT(Super,v2164)->selector);
        int  v12584;
        { int  v6630 = 0;
          { OID gc_local;
            ITERATE(v6654);
            bag *v6654_support;
            v6654_support = GC_OBJECT(list,OBJECT(Super,v2164)->args);
            for (START(v6654_support); NEXT(v6654);)
            { int  v6631 = c_status_any(v6654,v6212);
              v6630= c_or_integer(v6630,v6631);
              } 
            } 
          v12584 = v6630;
          } 
        Result = c_return_integer(v12583,v12584);
        } 
      else if (INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Case))
       { int  v6655 = 0;
        { OID gc_local;
          ITERATE(v6657);
          bag *v6657_support;
          v6657_support = GC_OBJECT(list,OBJECT(Case,v2164)->args);
          for (START(v6657_support); NEXT(v6657);)
          { int  v6656 = c_status_any(v6657,v6212);
            v6655= c_or_integer(v6655,v6656);
            } 
          } 
        Result = v6655;
        } 
      else Result = ((INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._While)) ?
        c_return_integer(c_status_any(GC_OID(OBJECT(While,v2164)->arg),v6212),c_status_any(GC_OID(OBJECT(While,v2164)->test),v6212)) :
        ((INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Return)) ?
          c_status_any(GC_OID(OBJECT(Return,v2164)->arg),v6212) :
          ((INHERIT(OBJECT(ClaireObject,v2164)->isa,Language._Handle)) ?
            c_return_integer(c_or_integer(c_status_any(GC_OID(OBJECT(ClaireHandle,v2164)->arg),v6212),c_status_any(GC_OID(OBJECT(ClaireHandle,v2164)->other),v6212)),c_status_any(GC_OID(OBJECT(ClaireHandle,v2164)->test),v6212)) :
            ((INHERIT(OBJECT(ClaireObject,v2164)->isa,Kernel._unbound_symbol)) ?
              0 :
              (*Optimize.Cerror)(_string_(copy_string("[internal] oops .. I forgot ~S")),
                _oid_(OWNER(v2164))) ) ) ) );
      } 
    else Result = ((Kernel._float == OWNER(v2164)) ?
      2 :
      ((Kernel._string == OWNER(v2164)) ?
        2 :
        ((INHERIT(OWNER(v2164),Kernel._function)) ?
          2 :
          ((INHERIT(OWNER(v2164),Core._Type)) ?
            2 :
            0 ) ) ) );
    GC_UNBIND; return (Result);} 
  } 

int  c_or_integer(int v6224,int v6225)
{ { int Result = 0;
    { int  v6204 = or_integer(v6224,v6225);
      if ((BCONTAIN(v6204,5)) && 
          (((BCONTAIN(v6224,5)) ? ((BCONTAIN(v6225,5)) ? CTRUE: CFALSE): CFALSE) != CTRUE))
       v6204= (v6204-exp2_integer(5));
      if ((BCONTAIN(v6204,5)) && 
          (((BCONTAIN(v6224,5)) ? ((BCONTAIN(v6225,5)) ? CTRUE: CFALSE): CFALSE) != CTRUE))
       v6204= (v6204-exp2_integer(5));
      Result = v6204;
      } 
    return (Result);} 
  } 

int  c_or_list(list *v6212)
{ { int Result = 0;
    { int  v6204 = 0;
      { ITERATE(v6224);
        for (START(v6212); NEXT(v6224);)
        v6204= c_or_integer(v6204,v6224);
        } 
      Result = v6204;
      } 
    return (Result);} 
  } 

int  status_I_restriction(restriction *v2164)
{ GC_BIND;
  { int Result = 0;
    if (Kernel._method == v2164->isa)
     { if (((CLREAD(method,v2164,status) == (CNULL)) ? CTRUE : CFALSE) != CTRUE)
       Result = CLREAD(method,v2164,status);
      else if (CLREAD(method,v2164,formula) == (NULL))
       { (CLREAD(method,v2164,status) = 0);
        Result = 0;
        } 
      else { (CLREAD(method,v2164,status) = 0);
          (CLREAD(method,v2164,status) = c_status_any(GC_OID(CLREAD(method,v2164,formula)->body),GC_OBJECT(list,CLREAD(method,v2164,formula)->vars)));
          Result = CLREAD(method,v2164,status);
          } 
        } 
    else Result = 0;
      GC_UNBIND; return (Result);} 
  } 

int  c_return_integer(int v6224,int v6225)
{ { int Result = 0;
    { int  v6204 = or_integer(v6224,v6225);
      if ((nth_integer(v6224,5) != CTRUE) && 
          (BCONTAIN(v6225,5)))
       v6204= (v6204-exp2_integer(5));
      if ((nth_integer(v6224,4) != CTRUE) && 
          (BCONTAIN(v6225,4)))
       v6204= (v6204-exp2_integer(4));
      Result = v6204;
      } 
    return (Result);} 
  } 

int  c_status_property(property *v2164)
{ { int Result = 0;
    { int  v6218 = ((stable_ask_relation(v2164) == CTRUE) ?
        0 :
        (*Language.bit_vector)(1,
          2,
          3) );
      { ITERATE(v6224);
        for (START(v2164->restrictions); NEXT(v6224);)
        { if ((((*Kernel.srange)(v6224) == _oid_(Kernel._integer)) ? CTRUE : (((*Kernel.srange)(v6224) == _oid_(Kernel._object)) ? CTRUE : (((*Kernel.srange)(v6224) == _oid_(Kernel._any)) ? CTRUE : CFALSE))) != CTRUE)
           v6218= c_or_integer(v6218,2);
          if (Kernel._method == OBJECT(ClaireObject,v6224)->isa)
           v6218= c_or_integer(v6218,status_I_restriction(OBJECT(restriction,v6224)));
          else if (Kernel._slot == OBJECT(ClaireObject,v6224)->isa)
           v6218= c_or_integer(v6218,exp2_integer(4));
          } 
        } 
      Result = v6218;
      } 
    return (Result);} 
  } 

OID  showstatus_method2(method *v6213)
{ { OID Result = 0;
    { list * v12397 = list::alloc(7,_string_(copy_string("NEW_ALLOC")),
        _string_(copy_string("BAG_UPDATE")),
        _string_(copy_string("SLOT_UPDATE")),
        _string_(copy_string("RETURN_ARG")),
        _string_(copy_string("SAFE_RESULT")),
        _string_(copy_string("SAFE_GC")),
        _string_(copy_string("STRING_UPDATE")));
      list * v6212 = list::empty(Kernel._any);
      int  v6219 = v6213->status;
      { int  v6209 = 1;
        int  v6661 = 7;
        { OID gc_local;
          while ((v6209 <= v6661))
          { if (BCONTAIN(v6219,v6209))
             v6212= v6212->addFast((*(v12397))[v6209]);
            ++v6209;
            } 
          } 
        } 
      Result = _oid_(v6212);
      } 
    return (Result);} 
  } 

void  s_test_method2(method *v6213)
{ GC_BIND;
  { lambda * v12445 = GC_OBJECT(lambda,v6213->formula);
    int  v1019 = c_status_any(GC_OID(v12445->body),GC_OBJECT(list,v12445->vars));
    tformat_string(copy_string("status(~S) := ~S \n"),0,list::alloc(2,_oid_(v6213),v1019));
    (v6213->status = v1019);
    showstatus_method2(v6213);
    } 
  GC_UNBIND;} 

ClaireBoolean * legal_ask_module(module *v2164,OID v6224)
{ if ((v6224 == _oid_(Optimize.object_I)) || 
      (v6224 == _oid_(Optimize.anyObject_I))) 
  { { ClaireBoolean *Result ;
      Result = CTRUE;
      return (Result);} 
     } 
  else{ GC_BIND;
    { ClaireBoolean *Result ;
      if (Optimize.OPT->legal_modules->length != 0)
       { if ((contain_ask_set(Optimize.OPT->legal_modules,_oid_(v2164)) != CTRUE) && 
            ((Kernel._method == OWNER(v6224)) && ((OBJECT(method,v6224)->inline_ask == CFALSE) || 
                (Optimize.compiler->inline_ask != CTRUE))))
         { tformat_string(copy_string("legal_modules = ~S\n"),0,list::alloc(1,GC_OID(_oid_(Optimize.OPT->legal_modules))));
          tformat_string(copy_string("---- ERROR: ~S implies using ~S !\n\n"),0,list::alloc(2,v6224,_oid_(v2164)));
          Result = CFALSE;
          } 
        else Result = CTRUE;
          } 
      else { Optimize.OPT->need_modules->addFast(_oid_(v2164));
          Result = CTRUE;
          } 
        GC_UNBIND; return (Result);} 
    } 
  } 

OID  legal_ask_environment(ClaireEnvironment *v2164,OID v6224)
{ return (Kernel.ctrue);} 

OID  c_register_object(ClaireObject *v2164)
{ GC_BIND;
  { OID Result = 0;
    { OID  v6224 = GC_OID(get_module_object(v2164));
      if (v6224 != _oid_(ClEnv))
       Result = (*Optimize.legal_ask)(v6224,
        _oid_(v2164));
      else Result = Kernel.ctrue;
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_register_property(property *v2164)
{ GC_BIND;
  { OID Result = 0;
    { module * v6213 = ClEnv->module_I;
      OID  v12429 = GC_OID(get_module_object(v2164));
      if (((v12429 == _oid_(claire.it)) || 
            (v12429 == _oid_(v6213))) && 
          (Optimize.OPT->objects->memq(_oid_(v2164)) != CTRUE))
       Optimize.OPT->properties->addFast(_oid_(v2164));
      Result = c_register_object(v2164);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  selector_register_property(property *v2164)
{ c_register_property(v2164);
  if (allocate_ask_property(v2164) == Kernel.ctrue)
   (Optimize.OPT->allocation = CTRUE);
  return (_oid_(v2164));} 

OID  allocate_ask_property(property *v2164)
{ { OID Result = 0;
    { ITERATE(v6224);
      Result= Kernel.cfalse;
      for (START(v2164->restrictions); NEXT(v6224);)
      if (Kernel._slot == OBJECT(ClaireObject,v6224)->isa)
       { if ((_oid_((INHERIT(OBJECT(restriction,v6224)->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(OBJECT(restriction,v6224)->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(OBJECT(restriction,v6224)->range))))) != Kernel.ctrue) && 
            (OBJECT(slot,v6224)->srange != Kernel._any))
         { Result = Kernel.ctrue;
          break;} 
        else if ((_oid_((INHERIT(OBJECT(restriction,v6224)->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(OBJECT(restriction,v6224)->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(OBJECT(restriction,v6224)->range))))) != Kernel.ctrue) && 
            (gcsafe_ask_class(domain_I_restriction(OBJECT(restriction,v6224))) != CTRUE))
         { Result = 0;
          break;} 
        } 
      else if (Kernel._method == OBJECT(ClaireObject,v6224)->isa)
       { if ((BCONTAIN(status_I_restriction(OBJECT(restriction,v6224)),1)) || 
            ((((c_srange_method(OBJECT(method,v6224)) == Kernel._integer) ? CTRUE : ((c_srange_method(OBJECT(method,v6224)) == Kernel._object) ? CTRUE : ((c_srange_method(OBJECT(method,v6224)) == Kernel._any) ? CTRUE : CFALSE))) != CTRUE) || 
              (_oid_((INHERIT(OBJECT(restriction,v6224)->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(OBJECT(restriction,v6224)->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(OBJECT(restriction,v6224)->range))))) != Kernel.ctrue)))
         { Result = Kernel.ctrue;
          break;} 
        } 
      } 
    return (Result);} 
  } 

ClaireBoolean * stable_ask_relation(ClaireRelation *v2164)
{ GC_BIND;
  { OID  v6213 = GC_OID(get_module_object(v2164));
    if ((v2164->open == 2) && 
        ((contain_ask_set(Optimize.OPT->legal_modules,v6213) == CTRUE) || 
            (v6213 == _oid_(ClEnv))))
     (v2164->open = 1);
    } 
  { ClaireBoolean *Result ;
    Result = ((v2164->open <= 1) ? CTRUE : ((v2164->open == 4) ? CTRUE : CFALSE));
    GC_UNBIND; return (Result);} 
  } 

OID  get_module_object(ClaireObject *v2164)
{ return (_oid_(defined_symbol(OBJECT(symbol,(*Kernel.name)(_oid_(v2164))))));} 

OID  known_I_listargs(listargs *v6212)
{ Optimize.OPT->to_remove->addFast(_oid_(Reader.known_I));
  { OID Result = 0;
    { ITERATE(v6218);
      Result= Kernel.cfalse;
      for (START(v6212); NEXT(v6218);)
      if (INHERIT(OWNER(v6218),Kernel._property))
       Optimize.OPT->knowns->addFast(v6218);
      } 
    return (Result);} 
  } 

OID  oload_module(module *v6213)
{ load_module(v6213);
  return (turbo_module(v6213));} 

OID  oload_string(char *v6206)
{ load_string(v6206);
  return (turbo_module(ClEnv->module_I));} 

OID  turbo_module(module *v6213)
{ GC_RESERVE(5);  // v3.0.55 optim !
  { OID Result = 0;
    { int  v12756 = ClEnv->verbose;
      (Optimize.OPT->online_ask = CTRUE);
      (ClEnv->verbose = 0);
      { OID gc_local;
        ITERATE(v6224);
        bag *v6224_support;
        v6224_support = Kernel._method->instances;
        for (START(v6224_support); NEXT(v6224);)
        { GC_LOOP;
          if ((OBJECT(restriction,v6224)->module_I == v6213) && 
              ((OBJECT(method,v6224)->inline_ask != CTRUE) && 
                (((OBJECT(method,v6224)->formula == (NULL)) ? CTRUE : CFALSE) != CTRUE)))
           { lambda * v6212 = GC_OBJECT(lambda,OBJECT(method,v6224)->formula);
            OID  v6225 = GC_OID(v6212->body);
            { ClaireHandler c_handle = ClaireHandler();
              if ERROR_IN 
              { { if (OBJECT(restriction,v6224)->range == Kernel._any)
                   update_property(Kernel.range,
                    OBJECT(ClaireObject,v6224),
                    5,
                    Kernel._object,
                    GC_OID((*Optimize.c_type)(v6225)));
                  (v6212->body = (*Optimize.c_code)(v6225,
                    _oid_(Kernel._any)));
                  (Language._starvariable_index_star->value= (v6212->vars->length+1));
                  (v6212->body = lexical_build_any(GC_OID(v6212->body),GC_OBJECT(list,v6212->vars),Language._starvariable_index_star->value));
                  (v6212->dimension = Language._starvariable_index_star->value);
                  } 
                ClEnv->cHandle--;} 
              else if (belong_to(_oid_(ClEnv->exception_I),_oid_(Kernel._any)) == CTRUE)
              { c_handle.catchIt();{ (v6212->body = v6225);
                  ;} 
                } 
              else PREVIOUS_HANDLER;} 
            } 
          GC_UNLOOP;} 
        } 
      (Optimize.OPT->online_ask = CFALSE);
      (ClEnv->verbose = v12756);
      Result = Kernel.ctrue;
      } 
    GC_UNBIND; return (Result);} 
  } 

void  stats_meta_OPT(Optimize_meta_OPT *v6224)
{ ;} 

