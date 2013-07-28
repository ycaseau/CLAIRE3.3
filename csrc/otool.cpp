/***** CLAIRE Compilation of file c:\claire\v3.3\src\compile\otool.cl 
         [version 3.3.46 / safety 5] Sun Feb 15 15:37:26 2009 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
void  self_print_to_protect(Compile_to_protect *v6224)
{ GC_BIND;
  princ_string(copy_string("[to_protect "));
  print_any(GC_OID(v6224->arg));
  princ_string(copy_string("]"));
  GC_UNBIND;} 

OID  self_eval_to_protect(Compile_to_protect *v6224)
{ GC_BIND;
  { OID Result = 0;
    Result = OPT_EVAL(v6224->arg);
    GC_UNBIND; return (Result);} 
  } 

void  self_print_to_CL(Compile_to_CL *v2164)
{ GC_BIND;
  princ_string(copy_string("CL{"));
  print_any(GC_OID(v2164->arg));
  princ_string(copy_string("}:"));
  print_any(_oid_(v2164->set_arg));
  princ_string(copy_string(""));
  GC_UNBIND;} 

ClaireType * c_type_to_CL_Optimize(Compile_to_CL *v2164)
{ GC_BIND;
  { ClaireType *Result ;
    Result = sort_abstract_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v2164->arg))));
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_to_CL(Compile_to_CL *v2164)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = (((gcsafe_ask_class(v2164->set_arg) != CTRUE) && 
        ((v2164->set_arg == Kernel._float) || 
            (_inf_equalt_class(v2164->set_arg,Kernel._cl_import) == CTRUE))) ? CTRUE : (((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(GC_OID(v2164->arg)))) == CTRUE) ? CTRUE : CFALSE));
    GC_UNBIND; return (Result);} 
  } 

void  self_print_to_C(Compile_to_C *v2164)
{ GC_BIND;
  princ_string(copy_string("C{"));
  print_any(GC_OID(v2164->arg));
  princ_string(copy_string("}:"));
  print_any(_oid_(v2164->set_arg));
  princ_string(copy_string(""));
  GC_UNBIND;} 

ClaireBoolean * c_gc_ask_to_C(Compile_to_C *v2164)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = ((gcsafe_ask_class(v2164->set_arg) != CTRUE) ? (((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(GC_OID(v2164->arg)))) == CTRUE) ? (((_inf_equalt_class(v2164->set_arg,Kernel._object) == CTRUE) || 
        (v2164->set_arg == Kernel._string)) ? CTRUE: CFALSE): CFALSE): CFALSE);
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_to_C_Optimize(Compile_to_C *v2164)
{ GC_BIND;
  { ClaireType *Result ;
    Result = glb_class(v2164->set_arg,GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v2164->arg))))));
    GC_UNBIND; return (Result);} 
  } 

void  self_print_C_cast(Compile_C_cast *v2164)
{ GC_BIND;
  princ_string(copy_string("<"));
  print_any(GC_OID(v2164->arg));
  princ_string(copy_string(":"));
  print_any(_oid_(v2164->set_arg));
  princ_string(copy_string(">"));
  GC_UNBIND;} 

ClaireBoolean * c_gc_ask_C_cast(Compile_C_cast *v2164)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v2164->arg));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_C_cast_Optimize(Compile_C_cast *v2164)
{ return (v2164->set_arg);} 

OID  c_code_C_cast_Optimize(Compile_C_cast *v2164,ClaireClass *v6219)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(v6219,Kernel._object))
     { Compile_C_cast * v2072 = ((Compile_C_cast *) GC_OBJECT(Compile_C_cast,new_object_class(Optimize._C_cast)));
      (v2072->arg = (*Optimize.c_code)(GC_OID(v2164->arg),
        _oid_(v6219)));
      (v2072->set_arg = v2164->set_arg);
      add_I_property(Kernel.instances,Optimize._C_cast,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    else Result = (*Optimize.c_code)(GC_OID(v2164->arg),
        _oid_(v6219));
      GC_UNBIND; return (Result);} 
  } 

void  self_print_Pattern(Optimize_ClairePattern *v2164)
{ GC_BIND;
  print_any(_oid_(v2164->selector));
  princ_string(copy_string("[tuple("));
  princ_bag(GC_OBJECT(list,v2164->arg));
  princ_string(copy_string(")]"));
  GC_UNBIND;} 

ClaireBoolean * _Z_any3(OID v6224,Optimize_ClairePattern *v6225)
{ GC_BIND;
  { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v6224),Language._Call))
     { ClaireBoolean *v_and;
      { v_and = ((OBJECT(Call,v6224)->selector == v6225->selector) ? CTRUE : CFALSE);
        if (v_and == CFALSE) Result =CFALSE; 
        else { { list * v5438;
            { { bag *v_list; OID v_val;
                OID v6226,CLcount;
                v_list = GC_OBJECT(list,OBJECT(Call,v6224)->args);
                 v5438 = v_list->clone();
                for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                { v6226 = (*(v_list))[CLcount];
                  v_val = (*Optimize.c_type)(v6226);
                  
                  (*((list *) v5438))[CLcount] = v_val;} 
                } 
              GC_OBJECT(list,v5438);} 
            v_and = tmatch_ask_list(v5438,GC_OBJECT(list,v6225->arg));
            } 
          if (v_and == CFALSE) Result =CFALSE; 
          else Result = CTRUE;} 
        } 
      } 
    else Result = CFALSE;
      GC_UNBIND; return (Result);} 
  } 

ClaireType * glb_Pattern(Optimize_ClairePattern *v6224,ClaireType *v6225)
{ return (Kernel.emptySet);} 

ClaireBoolean * less_ask_Pattern(Optimize_ClairePattern *v6224,OID v6225)
{ GC_BIND;
  { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v6225),Optimize._Pattern))
     { ClaireBoolean *v_and;
      { v_and = ((v6224->selector == OBJECT(Optimize_ClairePattern,v6225)->selector) ? CTRUE : CFALSE);
        if (v_and == CFALSE) Result =CFALSE; 
        else { v_and = ((v6224->arg->length == OBJECT(Optimize_ClairePattern,v6225)->arg->length) ? CTRUE : CFALSE);
          if (v_and == CFALSE) Result =CFALSE; 
          else { { OID  v7360;
              { int  v6209 = 1;
                int  v6687 = v6224->arg->length;
                { OID gc_local;
                  v7360= _oid_(CFALSE);
                  while ((v6209 <= v6687))
                  { GC_LOOP;
                    if (_equaltype_ask_any(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*(v6224->arg))[v6209])),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*(OBJECT(Optimize_ClairePattern,v6225)->arg))[v6209]))) != CTRUE)
                     { v7360 = Kernel.ctrue;
                      break;} 
                    ++v6209;
                    GC_UNLOOP;} 
                  } 
                } 
              v_and = not_any(v7360);
              } 
            if (v_and == CFALSE) Result =CFALSE; 
            else Result = CTRUE;} 
          } 
        } 
      } 
    else Result = OBJECT(ClaireBoolean,(*Core._inf_equalt)(_oid_(Language._Call),
        v6225));
      GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * less_ask_any(OID v6224,Optimize_ClairePattern *v6225)
{ GC_BIND;
  { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v6224),Optimize._Pattern))
     { ClaireBoolean *v_and;
      { v_and = ((OBJECT(Optimize_ClairePattern,v6224)->selector == v6225->selector) ? CTRUE : CFALSE);
        if (v_and == CFALSE) Result =CFALSE; 
        else { v_and = ((OBJECT(Optimize_ClairePattern,v6224)->arg->length == v6225->arg->length) ? CTRUE : CFALSE);
          if (v_and == CFALSE) Result =CFALSE; 
          else { { OID  v9282;
              { int  v6209 = 1;
                int  v6689 = OBJECT(Optimize_ClairePattern,v6224)->arg->length;
                { OID gc_local;
                  v9282= _oid_(CFALSE);
                  while ((v6209 <= v6689))
                  { GC_LOOP;
                    if (_equaltype_ask_any(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*(OBJECT(Optimize_ClairePattern,v6224)->arg))[v6209])),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*(v6225->arg))[v6209]))) != CTRUE)
                     { v9282 = Kernel.ctrue;
                      break;} 
                    ++v6209;
                    GC_UNLOOP;} 
                  } 
                } 
              v_and = not_any(v9282);
              } 
            if (v_and == CFALSE) Result =CFALSE; 
            else Result = CTRUE;} 
          } 
        } 
      } 
    else Result = CFALSE;
      GC_UNBIND; return (Result);} 
  } 

Optimize_ClairePattern * nth_property(property *v6216,tuple *v6224)
{ GC_BIND;
  { Optimize_ClairePattern *Result ;
    { Optimize_ClairePattern * v2072 = ((Optimize_ClairePattern *) GC_OBJECT(Optimize_ClairePattern,new_object_class(Optimize._Pattern)));
      (v2072->selector = v6216);
      (v2072->arg = list_I_tuple(v6224));
      add_I_property(Kernel.instances,Optimize._Pattern,11,_oid_(v2072));
      Result = v2072;
      } 
    GC_UNBIND; return (Result);} 
  } 

void  warn_void()
{ GC_BIND;
  if (Optimize.OPT->in_method != CNULL)
   tformat_string(copy_string("---- WARNING[in ~S]: "),2,list::alloc(1,GC_OID(Optimize.OPT->in_method)));
  else tformat_string(copy_string("---- WARNING: "),2,list::empty());
    GC_UNBIND;} 

void  Cerror_string(char *v6219,listargs *v6212)
{ GC_BIND;
  princ_string(copy_string("---- Compiler Error[in "));
  print_any(GC_OID(Optimize.OPT->in_method));
  princ_string(copy_string("]:\n"));
  princ_string(copy_string("---- file read up to line "));
  princ_integer(Reader.reader->nb_line);
  princ_string(copy_string("\n"));
  close_exception(((general_error *) (*Core._general_error)(_string_(v6219),
    _oid_(v6212))));
  GC_UNBIND;} 

void  notice_void()
{ if (Optimize.OPT->in_method != CNULL)
   ;} 

OID  c_warn_Call(Call *v2164,OID v8375)
{ GC_BIND;
  { OID Result = 0;
    { property * v6219 = v2164->selector;
      if (v8375 == _oid_(Kernel._void))
       (*Optimize.Cerror)(_string_(copy_string("[205] message ~S sent to void object")),
        _oid_(v2164));
      else if ((boolean_I_any(_oid_(v6219->restrictions)) != CTRUE) && 
          (contain_ask_set(Optimize.OPT->ignore,_oid_(v6219)) != CTRUE))
       { warn_void();
        tformat_string(copy_string("the property ~S is undefined [255]\n"),2,list::alloc(1,_oid_(v6219)));
        } 
      else if ((contain_ask_set(Optimize.OPT->ignore,_oid_(v6219)) != CTRUE) && 
          (((v6219->open <= 1) || 
              (v6219->open == 4)) && 
            ((INHERIT(OWNER(v8375),Kernel._list)) && (class_I_type(OBJECT(ClaireType,(*(OBJECT(bag,v8375)))[1]))->open != 3))))
       { warn_void();
        tformat_string(copy_string("wrongly typed message ~S (~S) [256]\n"),2,list::alloc(2,_oid_(v2164),v8375));
        } 
      else if (Optimize.compiler->optimize_ask == CTRUE)
       { notice_void();
        ;} 
      Result = _oid_(open_message_property(v2164->selector,GC_OBJECT(list,v2164->args)));
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_warn_Super(Super *v2164,OID v8375)
{ GC_BIND;
  { OID Result = 0;
    { property * v6219 = v2164->selector;
      if (v8375 == _oid_(Kernel._void))
       (*Optimize.Cerror)(_string_(copy_string("[205] message ~S sent to void object")),
        _oid_(v2164));
      else if (boolean_I_any(_oid_(v6219->restrictions)) != CTRUE)
       { warn_void();
        tformat_string(copy_string("the property ~S is undefined [255]\n"),2,list::alloc(1,_oid_(v6219)));
        } 
      else if ((contain_ask_set(Optimize.OPT->ignore,_oid_(v6219)) != CTRUE) && 
          (v6219->open <= 1))
       ;{ Call * v6213 = GC_OBJECT(Call,open_message_property(v2164->selector,GC_OBJECT(list,v2164->args)));
        Super * v2072 = ((Super *) GC_OBJECT(Super,new_object_class(Language._Super)));
        (v2072->selector = v6213->selector);
        (v2072->cast_to = v2164->cast_to);
        (v2072->args = v6213->args);
        add_I_property(Kernel.instances,Language._Super,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_warn_property(property *v2164,list *v6212,list *v8375)
{ if ((v2164->open <= 1) && 
      ((contain_ask_set(Optimize.OPT->ignore,_oid_(v2164)) != CTRUE) && 
        (Optimize.compiler->safety > 1)))
   ;return (_oid_(open_message_property(v2164,v6212)));} 

OID  c_warn_Variable(Variable *v2164,OID v6224,ClaireType *v6225)
{ GC_BIND;
  if (boolean_I_any((*Kernel._exp)(_oid_(v6225),
    GC_OID(_oid_(v2164->range)))) != CTRUE)
   { if (Optimize.compiler->safety > 4)
     { warn_void();
      tformat_string(copy_string("~S of type ~S is put in the variable ~S:~S [257]\n"),2,list::alloc(4,v6224,
        _oid_(v6225),
        _oid_(v2164),
        GC_OID(_oid_(v2164->range))));
      } 
    else (*Optimize.Cerror)(_string_(copy_string("[212] the value ~S of type ~S cannot be placed in the variable ~S:~S")),
        v6224,
        _oid_(v6225),
        _oid_(v2164),
        GC_OID(_oid_(v2164->range)));
      } 
  else if ((Optimize.compiler->safety <= 1) || 
      (boolean_I_any(sort_equal_class(osort_any(GC_OID(_oid_(v2164->range))),osort_any(_oid_(v6225)))) != CTRUE))
   { warn_void();
    tformat_string(copy_string("~S of type ~S is put in the variable ~S:~S [257]\n"),2,list::alloc(4,v6224,
      _oid_(v6225),
      _oid_(v2164),
      GC_OID(_oid_(v2164->range))));
    } 
  { OID Result = 0;
    if ((Optimize.compiler->safety <= 1) && 
        (_inf_equal_type(v6225,GC_OBJECT(ClaireType,v2164->range)) != CTRUE))
     Result = c_check_any(GC_OID((*Optimize.c_code)(v6224,
      _oid_(Kernel._any))),GC_OID((*Optimize.c_code)(GC_OID(_oid_(v2164->range)),
      _oid_(Kernel._type))));
    else Result = v6224;
      GC_UNBIND; return (Result);} 
  } 

OID  sort_equal_class(ClaireClass *v6203,ClaireClass *v12119)
{ { OID Result = 0;
    if (INHERIT(v6203,Kernel._object))
     Result = _oid_(inherit_ask_class(v12119,Kernel._object));
    else Result = _oid_(((v6203 == v12119) ? CTRUE : ((((Optimize.compiler->overflow_ask != CTRUE) && 
            ((v6203 == Kernel._any) && 
                (v12119 == Kernel._integer))) || 
          ((v6203 == Kernel._integer) && 
              (v12119 == Kernel._any))) ? CTRUE : CFALSE)));
      return (Result);} 
  } 

ClaireClass * psort_any(OID v6224)
{ { ClaireClass *Result ;
    { ClaireClass * v6203 = class_I_type(OBJECT(ClaireType,v6224));
      Result = ((INHERIT(v6203,Kernel._object)) ?
        v6203 :
        ((v6203 == Kernel._float) ?
          v6203 :
          sort_I_class(v6203) ) );
      } 
    return (Result);} 
  } 

ClaireClass * osort_any(OID v6224)
{ { ClaireClass *Result ;
    { ClaireClass * v6203 = class_I_type(OBJECT(ClaireType,v6224));
      Result = ((v6203 == Kernel._float) ?
        v6203 :
        sort_I_class(v6203) );
      } 
    return (Result);} 
  } 

ClaireClass * sort_Variable(Variable *v6224)
{ GC_BIND;
  { ClaireClass *Result ;
    { ClaireType * v6218 = v6224->range;
      Result = (((INHERIT(v6218->isa,Core._Union)) && (equal(_oid_(CLREAD(Union,v6218,t1)),_oid_(Kernel.emptySet)) == CTRUE)) ?
        psort_any(GC_OID(_oid_(CLREAD(Union,CLREAD(Union,v6218,t2),t2)))) :
        psort_any(_oid_(v6218)) );
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireClass * stupid_t_any1(OID v2164)
{ GC_BIND;
  { ClaireClass *Result ;
    if (INHERIT(OWNER(v2164),Language._Variable))
     { ClaireType * v6218 = GC_OBJECT(ClaireType,OBJECT(Variable,v2164)->range);
      Result = ((sort_abstract_ask_type(v6218) == CTRUE) ?
        Kernel._any :
        (((INHERIT(v6218->isa,Core._Union)) && (equal(_oid_(CLREAD(Union,v6218,t1)),_oid_(Kernel.emptySet)) == CTRUE)) ?
          OBJECT(ClaireClass,(*Core.t1)(GC_OID(_oid_(CLREAD(Union,v6218,t2))))) :
          class_I_type(v6218) ) );
      } 
    else if (INHERIT(OWNER(v2164),Core._global_variable))
     { ClaireType * v6218 = OBJECT(global_variable,v2164)->range;
      Result = ((boolean_I_any(_oid_(v6218)) == CTRUE) ?
        class_I_type(v6218) :
        OWNER(OBJECT(global_variable,v2164)->value) );
      } 
    else if (INHERIT(OWNER(v2164),Language._And))
     Result = Kernel._boolean;
    else if (INHERIT(OWNER(v2164),Kernel._bag))
     Result = OWNER(v2164);
    else if (INHERIT(OWNER(v2164),Kernel._environment))
     Result = Kernel._environment;
    else if (INHERIT(OWNER(v2164),Kernel._class))
     Result = Kernel._class;
    else if (INHERIT(OWNER(v2164),Language._Call_slot))
     { slot * v6219 = OBJECT(Call_slot,v2164)->selector;
      property * v6216 = v6219->selector;
      { ITERATE(v12615);
        for (START(v6216->definition); NEXT(v12615);)
        if (Kernel._slot == OBJECT(ClaireObject,v12615)->isa)
         { if (_inf_equal_type(domain_I_restriction(v6219),domain_I_restriction(OBJECT(restriction,v12615))) == CTRUE)
           v6219= OBJECT(slot,v12615);
          } 
        } 
      Result = class_I_type(v6219->range);
      } 
    else if (INHERIT(OWNER(v2164),Language._Call_method))
     Result = class_I_type(OBJECT(Call_method,v2164)->arg->range);
    else if (INHERIT(OWNER(v2164),Language._Call))
     Result = selector_psort_Call(OBJECT(Call,v2164));
    else if (INHERIT(OWNER(v2164),Optimize._to_C))
     Result = OBJECT(Compile_to_C,v2164)->set_arg;
    else if (INHERIT(OWNER(v2164),Optimize._to_protect))
     Result = stupid_t_any1(GC_OID(OBJECT(Compile_to_protect,v2164)->arg));
    else if (INHERIT(OWNER(v2164),Kernel._symbol))
     Result = OWNER(v2164);
    else if (INHERIT(OWNER(v2164),Kernel._char))
     Result = OWNER(v2164);
    else if (Kernel._boolean == OWNER(v2164))
     Result = OWNER(v2164);
    else if (INHERIT(OWNER(v2164),Kernel._primitive))
     Result = OWNER(v2164);
    else if (INHERIT(OWNER(v2164),Language._Assign))
     Result = stupid_t_any1(GC_OID(OBJECT(Assign,v2164)->arg));
    else if (INHERIT(OWNER(v2164),Language._Let))
     Result = stupid_t_any1(GC_OID(OBJECT(Let,v2164)->arg));
    else if (INHERIT(OWNER(v2164),Language._Do))
     Result = stupid_t_any1(GC_OID(last_list(OBJECT(Do,v2164)->args)));
    else if (INHERIT(OWNER(v2164),Language._If))
     Result = meet_class(stupid_t_any1(GC_OID(OBJECT(If,v2164)->arg)),stupid_t_any1(GC_OID(OBJECT(If,v2164)->other)));
    else if (INHERIT(OWNER(v2164),Language._Collect))
     Result = Kernel._list;
    else if (INHERIT(OWNER(v2164),Language._Image))
     Result = Kernel._set;
    else if (INHERIT(OWNER(v2164),Language._Or))
     Result = Kernel._boolean;
    else if (INHERIT(OWNER(v2164),Language._Select))
     Result = Kernel._set;
    else if (INHERIT(OWNER(v2164),Language._Lselect))
     Result = Kernel._list;
    else if (INHERIT(OWNER(v2164),Language._List))
     Result = Kernel._list;
    else if (INHERIT(OWNER(v2164),Language._Set))
     Result = Kernel._set;
    else Result = ((INHERIT(OWNER(v2164),Kernel._thing)) ?
      OWNER(v2164) :
      ((INHERIT(OWNER(v2164),Language._Tuple)) ?
        Kernel._tuple :
        ((INHERIT(OWNER(v2164),Language._Exists)) ?
          ((OBJECT(Exists,v2164)->other == CNULL) ?
            Kernel._any :
            Kernel._boolean ) :
          ((INHERIT(OWNER(v2164),Kernel._integer)) ?
            Kernel._integer :
            Kernel._any ) ) ) );
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * stupid_t_any2(OID v2164,OID v6224)
{ { ClaireBoolean *Result ;
    { ClaireClass * v12118 = stupid_t_any1(v2164);
      ClaireClass * v12119 = stupid_t_any1(v6224);
      Result = ((v12118 != Kernel._any) ? ((v12118 == v12119) ? CTRUE: CFALSE): CFALSE);
      } 
    return (Result);} 
  } 

ClaireBoolean * extended_ask_type(ClaireType *v2164)
{ { ClaireBoolean *Result ;
    Result = ((INHERIT(v2164->isa,Core._Union)) ?
      ((Kernel._set == CLREAD(Union,v2164,t2)->isa) ? ((boolean_I_any(_oid_(CLREAD(Union,v2164,t2))) == CTRUE) ? (((*(((bag *) CLREAD(Union,v2164,t2))))[1] == CNULL) ? CTRUE: CFALSE): CFALSE): CFALSE) :
      CFALSE );
    return (Result);} 
  } 

ClaireType * extends_type(ClaireType *v6224)
{ GC_BIND;
  { ClaireType *Result ;
    { Optimize_optUnion * v2072 = ((Optimize_optUnion *) GC_OBJECT(Optimize_optUnion,new_object_class(Optimize._optUnion)));
      (v2072->t1 = v6224);
      (v2072->t2 = set::alloc(Kernel.emptySet,1,CNULL));
      Result = v2072;
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * sort_abstract_I_type(ClaireType *v6224)
{ GC_BIND;
  { ClaireType *Result ;
    if (((_oid_((INHERIT(v6224->isa,Kernel._class) ? (ClaireObject *) sort_I_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v6224))) :  (ClaireObject *)  sort_I_type((ClaireType *) OBJECT(ClaireType,_oid_(v6224))))) != _oid_(Kernel._any)) && 
          ((_oid_((INHERIT(v6224->isa,Kernel._class) ? (ClaireObject *) sort_I_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v6224))) :  (ClaireObject *)  sort_I_type((ClaireType *) OBJECT(ClaireType,_oid_(v6224))))) != _oid_(Kernel._integer)) || 
              (Optimize.compiler->overflow_ask == CTRUE))) || 
        (v6224 == Kernel._float))
     { Union * v2072 = ((Union *) GC_OBJECT(Union,new_object_class(Core._Union)));
      (v2072->t1 = Kernel._any);
      (v2072->t2 = v6224);
      Result = v2072;
      } 
    else Result = v6224;
      GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * sort_abstract_ask_type(ClaireType *v6224)
{ { ClaireBoolean *Result ;
    Result = ((INHERIT(v6224->isa,Core._Union)) ?
      equal(_oid_(CLREAD(Union,v6224,t1)),_oid_(Kernel._any)) :
      CFALSE );
    return (Result);} 
  } 

ClaireType * ptype_type(ClaireType *v6224)
{ { ClaireType *Result ;
    Result = ((INHERIT(v6224->isa,Core._Union)) ?
      ((CLREAD(Union,v6224,t1) == Kernel._any) ?
        CLREAD(Union,v6224,t2) :
        v6224 ) :
      v6224 );
    return (Result);} 
  } 

ClaireType * pmember_type(ClaireType *v6224)
{ return (member_type(ptype_type(v6224)));} 

OID  enumerate_code_any(OID v2164,ClaireType *v10263)
{ GC_BIND;
  { OID Result = 0;
    if (_inf_equal_type(ptype_type(v10263),Kernel._bag) == CTRUE)
     Result = c_strict_code_any(v2164,Kernel._bag);
    else { if (Optimize.compiler->optimize_ask == CTRUE)
         { notice_void();
          ;} 
        Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Core.enumerate,Kernel._any))),list::alloc(1,v2164),list::alloc(1,_oid_(v10263)));
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  range_infers_for_Variable(Variable *v2164,ClaireType *v6225,ClaireType *v12711)
{ GC_BIND;
  if (v2164->range == (NULL))
   { if (INHERIT(v6225->isa,Core._Interval))
     v6225= Kernel._integer;
    (v2164->range = v6225);
    } 
  else if ((_inf_equal_type(v6225,GC_OBJECT(ClaireType,v2164->range)) != CTRUE) && 
      (Optimize.compiler->safety <= 1))
   { if (((boolean_I_any(_oid_(v6225)) == CTRUE) ? ((boolean_I_any(_oid_(v2164->range)) == CTRUE) ? CTRUE: CFALSE): CFALSE) != CTRUE)
     { warn_void();
      tformat_string(copy_string("range of variable in ~S is wrong [258]\n"),2,list::alloc(1,_oid_(v2164)));
      } 
    } 
  { OID Result = 0;
    if ((sort_Variable(v2164) != Kernel._any) && 
        (((sort_Variable(v2164) != Kernel._integer) || 
            (Optimize.compiler->overflow_ask == CTRUE)) && 
          (((_inf_equal_type(v12711,Kernel._array) == CTRUE) ? ((_inf_equal_type(v6225,Kernel._float) == CTRUE) ? CTRUE: CFALSE): CFALSE) != CTRUE)))
     { Result = _void_((v2164->range = sort_abstract_I_type(GC_OBJECT(ClaireType,v2164->range))));
      } 
    else Result = Kernel.cfalse;
      GC_UNBIND; return (Result);} 
  } 

OID  range_infers_Variable(Variable *v2164,ClaireType *v6225)
{ gc_register_Variable(v2164);
  { OID Result = 0;
    if ((v2164->range == (NULL)) || 
        ((extended_ask_type(v2164->range) == CTRUE) && 
            (INHERIT(v2164->range->isa,Optimize._optUnion))))
     { if (Kernel._set == v6225->isa)
       Result = _void_((v2164->range = class_I_type(v6225)));
      else Result = _void_((v2164->range = v6225));
        } 
    else Result = Kernel.cfalse;
      return (Result);} 
  } 

void  range_infer_case_any(OID v2164,ClaireType *v6225)
{ GC_BIND;
  if (INHERIT(OWNER(v2164),Language._Variable))
   { if (boolean_I_any(sort_equal_class(osort_any(GC_OID(_oid_(OBJECT(Variable,v2164)->range))),osort_any(_oid_(v6225)))) == CTRUE)
     { ClaireClass * v12118 = psort_any(_oid_(class_I_type(GC_OBJECT(ClaireType,OBJECT(Variable,v2164)->range))));
      if (v12118 != psort_any(_oid_(class_I_type(v6225))))
       { Variable * v6691 = OBJECT(Variable,v2164); 
        ClaireType * v6693;
        { Union * v2072 = ((Union *) GC_OBJECT(Union,new_object_class(Core._Union)));
          (v2072->t1 = Kernel.emptySet);
          { Union * v6694 = v2072; 
            ClaireType * v6715;
            { Union * v2072 = ((Union *) GC_OBJECT(Union,new_object_class(Core._Union)));
              (v2072->t1 = v12118);
              (v2072->t2 = v6225);
              v6715 = v2072;
              } 
            (v6694->t2 = v6715);} 
          v6693 = v2072;
          } 
        (v6691->range = v6693);} 
      else (OBJECT(Variable,v2164)->range = v6225);
        } 
    else if (osort_any(GC_OID(_oid_(OBJECT(Variable,v2164)->range))) == Kernel._any)
     (OBJECT(Variable,v2164)->range = sort_abstract_I_type(v6225));
    } 
  GC_UNBIND;} 

OID  c_check_any(OID v6224,OID v6225)
{ GC_BIND;
  { OID Result = 0;
    { method * v6213 = ((method *) _at_property1(Core.check_in,Kernel._any));
      if (Optimize.compiler->safety > 3)
       Result = v6224;
      else { legal_ask_module(v6213->module_I,_oid_(v6213));
          { Call_method2 * v2072 = ((Call_method2 *) GC_OBJECT(Call_method2,new_object_class(Language._Call_method2)));
            (v2072->arg = v6213);
            (v2072->args = list::alloc(2,GC_OID(c_gc_I_any1(v6224)),GC_OID(c_gc_I_any1(v6225))));
            add_I_property(Kernel.instances,Language._Call_method2,11,_oid_(v2072));
            Result = _oid_(v2072);
            } 
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

void  range_sets_any(OID v2164,ClaireType *v6225)
{ GC_BIND;
  if (INHERIT(OWNER(v2164),Language._Variable))
   { if (boolean_I_any(sort_equal_class(osort_any(GC_OID(_oid_(OBJECT(Variable,v2164)->range))),osort_any(_oid_(v6225)))) == CTRUE)
     { ClaireClass * v12118 = psort_any(_oid_(class_I_type(GC_OBJECT(ClaireType,OBJECT(Variable,v2164)->range))));
      if (v12118 != psort_any(_oid_(class_I_type(v6225))))
       { Variable * v6716 = OBJECT(Variable,v2164); 
        ClaireType * v6717;
        { Union * v2072 = ((Union *) GC_OBJECT(Union,new_object_class(Core._Union)));
          (v2072->t1 = Kernel.emptySet);
          { Union * v6719 = v2072; 
            ClaireType * v6720;
            { Union * v2072 = ((Union *) GC_OBJECT(Union,new_object_class(Core._Union)));
              (v2072->t1 = v12118);
              (v2072->t2 = v6225);
              v6720 = v2072;
              } 
            (v6719->t2 = v6720);} 
          v6717 = v2072;
          } 
        (v6716->range = v6717);} 
      else (OBJECT(Variable,v2164)->range = v6225);
        } 
    else if (osort_any(GC_OID(_oid_(OBJECT(Variable,v2164)->range))) == Kernel._any)
     (OBJECT(Variable,v2164)->range = sort_abstract_I_type(v6225));
    } 
  GC_UNBIND;} 

ClaireClass * c_srange_method(method *v6213)
{ { ClaireClass *Result ;
    Result = ((v6213->range == Kernel._float) ?
      Kernel._float :
      OBJECT(ClaireClass,last_list(v6213->srange)) );
    return (Result);} 
  } 

ClaireBoolean * nativeVar_ask_global_variable(global_variable *v6224)
{ return (((Optimize.compiler->optimize_ask == CTRUE) ? ((v6224->store_ask == CFALSE) ? ((v6224->name->module_I == v6224->name->definition) ? (((OBJECT(ClaireBoolean,_oid_((INHERIT(v6224->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v6224->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(v6224->range))))))) == CTRUE) ? CTRUE: CFALSE): CFALSE): CFALSE): CFALSE));} 

ClaireType * return_type_any(OID v2164)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { ClaireType *Result ;
    if (INHERIT(OWNER(v2164),Optimize._to_C))
     Result = return_type_any(GC_OID(OBJECT(Compile_to_C,v2164)->arg));
    else if (INHERIT(OWNER(v2164),Optimize._to_protect))
     Result = return_type_any(GC_OID(OBJECT(Compile_to_protect,v2164)->arg));
    else if (INHERIT(OWNER(v2164),Language._Let))
     Result = return_type_any(GC_OID(OBJECT(Let,v2164)->arg));
    else if (INHERIT(OWNER(v2164),Language._Do))
     { set * v6224 = Kernel.emptySet;
      { OID gc_local;
        ITERATE(v6225);
        bag *v6225_support;
        v6225_support = GC_OBJECT(list,OBJECT(Do,v2164)->args);
        for (START(v6225_support); NEXT(v6225);)
        { GC_LOOP;
          GC__ANY(v6224 = OBJECT(set,(*Kernel._exp)(_oid_(v6224),
            GC_OID(_oid_(return_type_any(v6225))))), 1);
          GC_UNLOOP;} 
        } 
      Result = v6224;
      } 
    else if (INHERIT(OWNER(v2164),Language._If))
     Result = OBJECT(ClaireType,(*Kernel._exp)(GC_OID(_oid_(return_type_any(GC_OID(OBJECT(If,v2164)->arg)))),
      GC_OID(_oid_(return_type_any(GC_OID(OBJECT(If,v2164)->other))))));
    else if (INHERIT(OWNER(v2164),Language._Return))
     Result = OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(OBJECT(Return,v2164)->arg)));
    else if (INHERIT(OWNER(v2164),Language._Case))
     { set * v6224 = Kernel.emptySet;
      { OID gc_local;
        ITERATE(v6225);
        bag *v6225_support;
        v6225_support = GC_OBJECT(list,OBJECT(Case,v2164)->args);
        for (START(v6225_support); NEXT(v6225);)
        { GC_LOOP;
          GC__ANY(v6224 = OBJECT(set,(*Kernel._exp)(_oid_(v6224),
            GC_OID(_oid_(return_type_any(v6225))))), 1);
          GC_UNLOOP;} 
        } 
      Result = v6224;
      } 
    else if (INHERIT(OWNER(v2164),Language._Handle))
     Result = return_type_any(GC_OID(OBJECT(ClaireHandle,v2164)->arg));
    else Result = Kernel.emptySet;
      GC_UNBIND; return (Result);} 
  } 

OID  c_code_Type_Optimize(Type *v2164,ClaireClass *v6219)
{ GC_BIND;
  { OID Result = 0;
    Result = (*Optimize.c_code)(GC_OID((*Optimize.self_code)(_oid_(v2164))),
      _oid_(v6219));
    GC_UNBIND; return (Result);} 
  } 

OID  self_code_subtype(subtype *v2164)
{ GC_BIND;
  { OID Result = 0;
    { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v2072->selector = Kernel.nth);
      (v2072->args = list::alloc(2,_oid_(v2164->arg),GC_OID((*Optimize.c_code)(GC_OID(_oid_(v2164->t1)),
        _oid_(Kernel._type)))));
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  self_code_Param(Param *v2164)
{ GC_BIND;
  { OID Result = 0;
    if ((v2164->params->length == 1) && 
        (((*(v2164->params))[1] == _oid_(Kernel.of)) && 
          (Kernel._set == OWNER((*(v2164->args))[1]))))
     { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v2072->selector = Core.param_I);
      (v2072->args = list::alloc(2,_oid_(v2164->arg),GC_OID((*Optimize.c_code)(GC_OID((*Kernel.nth)(GC_OID((*(v2164->args))[1]),
          1)),
        _oid_(Kernel._type)))));
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    else { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
        (v2072->selector = Kernel.nth);
        { Call * v6721 = v2072; 
          list * v6722;
          { OID v_bag;
            GC_ANY(v6722= list::empty(Kernel.emptySet));
            ((list *) v6722)->addFast(_oid_(v2164->arg));
            ((list *) v6722)->addFast(GC_OID(_oid_(v2164->params)));
            { { list * v8349;{ bag *v_list; OID v_val;
                  OID v6225,CLcount;
                  v_list = GC_OBJECT(list,v2164->args);
                   v8349 = v_list->clone();
                  for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                  { v6225 = (*(v_list))[CLcount];
                    v_val = (*Optimize.c_code)(v6225,
                      _oid_(Kernel._type));
                    
                    (*((list *) v8349))[CLcount] = v_val;} 
                  } 
                
                v_bag=_oid_(v8349);} 
              GC_OID(v_bag);} 
            ((list *) v6722)->addFast(v_bag);} 
          (v6721->args = v6722);} 
        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  self_code_Union(Union *v2164)
{ GC_BIND;
  { OID Result = 0;
    { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v2072->selector = Core.U);
      (v2072->args = list::alloc(2,GC_OID((*Optimize.c_code)(GC_OID(_oid_(v2164->t1)),
        _oid_(Kernel._type))),GC_OID((*Optimize.c_code)(GC_OID(_oid_(v2164->t2)),
        _oid_(Kernel._type)))));
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  self_code_Interval(Interval *v2164)
{ GC_BIND;
  { OID Result = 0;
    { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v2072->selector = Kernel._dot_dot);
      (v2072->args = list::alloc(2,v2164->arg1,v2164->arg2));
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  self_code_Reference(Reference *v2164)
{ GC_BIND;
  { OID Result = 0;
    { Definition * v2072 = ((Definition *) GC_OBJECT(Definition,new_object_class(Language._Definition)));
      (v2072->arg = Core._Reference);
      { Definition * v6723 = v2072; 
        list * v6724;
        { OID v_bag;
          GC_ANY(v6724= list::empty(Kernel.emptySet));
          { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Kernel._equal);
              (v2072->args = list::alloc(2,_oid_(Core.args),GC_OID(_oid_(v2164->args))));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v_bag = _oid_(v2072);
              } 
            GC_OID(v_bag);} 
          ((list *) v6724)->addFast(v_bag);
          { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Kernel._equal);
              (v2072->args = list::alloc(2,_oid_(Kernel.index),v2164->index));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v_bag = _oid_(v2072);
              } 
            GC_OID(v_bag);} 
          ((list *) v6724)->addFast(v_bag);
          { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Kernel._equal);
              (v2072->args = list::alloc(2,_oid_(Kernel.arg),_oid_(v2164->arg)));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v_bag = _oid_(v2072);
              } 
            GC_OID(v_bag);} 
          ((list *) v6724)->addFast(v_bag);} 
        (v6723->args = v6724);} 
      add_I_property(Kernel.instances,Language._Definition,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  self_code_Pattern(Optimize_ClairePattern *v2164)
{ GC_BIND;
  { OID Result = 0;
    if (Optimize.compiler->inline_ask == CTRUE)
     { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v2072->selector = Kernel.nth);
      { Call * v6747 = v2072; 
        list * v6748;
        { OID v_bag;
          GC_ANY(v6748= list::empty(Kernel.emptySet));
          ((list *) v6748)->addFast(_oid_(v2164->selector));
          { { Tuple * v2072 = ((Tuple *) GC_OBJECT(Tuple,new_object_class(Language._Tuple)));
              (v2072->args = v2164->arg);
              add_I_property(Kernel.instances,Language._Tuple,11,_oid_(v2072));
              v_bag = _oid_(v2072);
              } 
            GC_OID(v_bag);} 
          ((list *) v6748)->addFast(v_bag);} 
        (v6747->args = v6748);} 
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    else Result = _oid_(Language._Call);
      GC_UNBIND; return (Result);} 
  } 

OID  member_code_class2(ClaireClass *v2164,OID v6224)
{ GC_BIND;
  { OID Result = 0;
    { Call * v7097;
      { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v2072->selector = ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v6224))),Kernel._object) == CTRUE) ?
            Kernel.isa :
            Core.owner ));
          (v2072->args = list::alloc(1,v6224));
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
          v7097 = v2072;
          } 
        GC_OBJECT(Call,v7097);} 
      if (((v2164->open <= -1) || 
            (v2164->open == 1)) && 
          (boolean_I_any(_oid_(v2164->subclass)) != CTRUE))
       { OID  v15868;
        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v2072->selector = Kernel._equal);
          (v2072->args = list::alloc(2,_oid_(v2164),_oid_(v7097)));
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
          v15868 = _oid_(v2072);
          } 
        Result = (*Optimize.c_code)(v15868);
        } 
      else { OID  v445;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Core.inherit_ask);
            (v2072->args = list::alloc(2,_oid_(v7097),_oid_(v2164)));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v445 = _oid_(v2072);
            } 
          Result = (*Optimize.c_code)(v445);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  member_code_Type(Type *v2164,OID v6224)
{ GC_BIND;
  { OID Result = 0;
    { Call_method2 * v2072 = ((Call_method2 *) GC_OBJECT(Call_method2,new_object_class(Language._Call_method2)));
      update_property(Kernel.arg,
        v2072,
        2,
        Kernel._object,
        GC_OID(_oid_(_at_property2(Kernel._Z,list::alloc(2,_oid_(Kernel._any),_oid_(Kernel._any))))));
      (v2072->args = list::alloc(2,GC_OID((*Optimize.c_code)(v6224,
        _oid_(Kernel._any))),GC_OID((*Optimize.c_code)(_oid_(v2164),
        _oid_(Kernel._any)))));
      add_I_property(Kernel.instances,Language._Call_method2,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  member_code_Union(Union *v2164,OID v6224)
{ GC_BIND;
  { OID Result = 0;
    { Or * v2072 = ((Or *) GC_OBJECT(Or,new_object_class(Language._Or)));
      (v2072->args = list::alloc(2,GC_OID((*Optimize.member_code)(GC_OID(_oid_(v2164->t1)),
        v6224)),GC_OID((*Optimize.member_code)(GC_OID(_oid_(v2164->t2)),
        v6224))));
      add_I_property(Kernel.instances,Language._Or,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  member_code_Interval(Interval *v2164,OID v6224)
{ GC_BIND;
  { OID Result = 0;
    { OID  v1406;
      { And * v2072 = ((And *) GC_OBJECT(And,new_object_class(Language._And)));
        { And * v6753 = v2072; 
          list * v6754;
          { OID v_bag;
            GC_ANY(v6754= list::empty(Kernel.emptySet));
            { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Kernel._sup_equal);
                (v2072->args = list::alloc(2,v6224,v2164->arg1));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v_bag = _oid_(v2072);
                } 
              GC_OID(v_bag);} 
            ((list *) v6754)->addFast(v_bag);
            { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Kernel._inf_equal);
                (v2072->args = list::alloc(2,v6224,v2164->arg2));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v_bag = _oid_(v2072);
                } 
              GC_OID(v_bag);} 
            ((list *) v6754)->addFast(v_bag);} 
          (v6753->args = v6754);} 
        add_I_property(Kernel.instances,Language._And,11,_oid_(v2072));
        v1406 = _oid_(v2072);
        } 
      Result = (*Optimize.c_code)(v1406,
        _oid_(Kernel._any));
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  member_code_Param(Param *v2164,OID v6224)
{ GC_BIND;
  { OID Result = 0;
    { OID  v5250;
      { And * v2072 = ((And *) GC_OBJECT(And,new_object_class(Language._And)));
        { And * v6759 = v2072; 
          list * v6777;
          { list * v11930;
            { OID v_bag;
              GC_ANY(v11930= list::empty(Kernel.emptySet));
              { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Kernel._Z);
                  (v2072->args = list::alloc(2,v6224,_oid_(v2164->arg)));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v_bag = _oid_(v2072);
                  } 
                GC_OID(v_bag);} 
              ((list *) v11930)->addFast(v_bag);} 
            list * v12891;
            { list * v15114 = list::empty(Kernel.emptySet);
              { int  v6209 = 1;
                int  v6755 = v2164->params->length;
                { OID gc_local;
                  while ((v6209 <= v6755))
                  { GC_LOOP;
                    { OID  v13852;
                      { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v2072->selector = Kernel._Z);
                        { Call * v6781 = v2072; 
                          list * v6782;
                          { OID v_bag;
                            GC_ANY(v6782= list::empty(Kernel.emptySet));
                            { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                update_property(Kernel.selector,
                                  v2072,
                                  2,
                                  Kernel._object,
                                  GC_OID((*(v2164->params))[v6209]));
                                (v2072->args = list::alloc(1,v6224));
                                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                v_bag = _oid_(v2072);
                                } 
                              GC_OID(v_bag);} 
                            ((list *) v6782)->addFast(v_bag);
                            ((list *) v6782)->addFast(GC_OID((*(v2164->args))[v6209]));} 
                          (v6781->args = v6782);} 
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                        v13852 = _oid_(v2072);
                        } 
                      v15114->addFast(v13852);
                      } 
                    ++v6209;
                    GC_UNLOOP;} 
                  } 
                } 
              v12891 = GC_OBJECT(list,v15114);
              } 
            v6777 = append_list(v11930,v12891);
            } 
          (v6759->args = v6777);} 
        add_I_property(Kernel.instances,Language._And,11,_oid_(v2072));
        v5250 = _oid_(v2072);
        } 
      Result = (*Optimize.c_code)(v5250,
        _oid_(Kernel._any));
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  member_code_tuple(tuple *v2164,OID v6224)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(OWNER(v6224),Language._Tuple))
     { if (length_bag(OBJECT(bag,(*Core.args)(v6224))) != v2164->length)
       Result = Kernel.cfalse;
      else { OID  v1312;
          { And * v2072 = ((And *) GC_OBJECT(And,new_object_class(Language._And)));
            { And * v6785 = v2072; 
              list * v6786;
              { list * v15114 = list::empty(Kernel.emptySet);
                { int  v6209 = 1;
                  int  v6783 = v2164->length;
                  { OID gc_local;
                    while ((v6209 <= v6783))
                    { GC_LOOP;
                      { OID  v7992;
                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v2072->selector = Kernel._Z);
                          (v2072->args = list::alloc(2,GC_OID((*(OBJECT(bag,(*Core.args)(v6224))))[v6209]),(*(v2164))[v6209]));
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                          v7992 = _oid_(v2072);
                          } 
                        v15114->addFast(v7992);
                        } 
                      ++v6209;
                      GC_UNLOOP;} 
                    } 
                  } 
                v6786 = GC_OBJECT(list,v15114);
                } 
              (v6785->args = v6786);} 
            add_I_property(Kernel.instances,Language._And,11,_oid_(v2072));
            v1312 = _oid_(v2072);
            } 
          Result = (*Optimize.c_code)(v1312,
            _oid_(Kernel._any));
          } 
        } 
    else Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property2(Kernel._Z,GC_OBJECT(list,list::alloc(2,_oid_(Kernel._any),_oid_(Kernel._any)))))),GC_OBJECT(list,list::alloc(2,v6224,_oid_(v2164))),GC_OBJECT(list,list::alloc(2,_oid_(Kernel._any),_oid_(Kernel._any))));
      GC_UNBIND; return (Result);} 
  } 

OID  member_code_any(OID v2164,OID v6224)
{ GC_BIND;
  (Language.LDEF->value= Core.nil->value);
  { OID Result = 0;
    { list * v8375 = list::alloc(2,GC_OID((*Optimize.c_type)(v6224)),GC_OID((*Optimize.c_type)(v2164)));
      OID  v6218 = GC_OID(extract_pattern_any(v2164,Kernel.nil));
      { ClaireBoolean * g0071I;
        { ClaireBoolean *v_or;
          { v_or = ((v6218 == CNULL) ? CTRUE : CFALSE);
            if (v_or == CTRUE) g0071I =CTRUE; 
            else { v_or = ((v2164 == _oid_(Kernel._object)) ? CTRUE : CFALSE);
              if (v_or == CTRUE) g0071I =CTRUE; 
              else { { OID  v9914;
                  if (INHERIT(OWNER(v2164),Core._global_variable))
                   v9914 = _oid_(OBJECT(global_variable,v2164)->range);
                  else v9914 = Kernel.cfalse;
                    v_or = boolean_I_any(v9914);
                  } 
                if (v_or == CTRUE) g0071I =CTRUE; 
                else g0071I = CFALSE;} 
              } 
            } 
          } 
        
        if (g0071I == CTRUE) Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property2(Kernel._Z,v8375))),list::alloc(2,v6224,v2164),v8375);
          else Result = (*Optimize.member_code)(v6218,
          v6224);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * _Z_any4(OID v6224,OID v6225)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = (((OBJECT(ClaireBoolean,(*Kernel._inf_equal)(v6224,
      GC_OID(OPT_EVAL((*(OBJECT(Call,v6225)->args))[2]))))) == CTRUE) ? (((OBJECT(ClaireBoolean,(*Kernel._inf_equal)(GC_OID(OPT_EVAL((*(OBJECT(Call,v6225)->args))[1])),
      v6224))) == CTRUE) ? CTRUE: CFALSE): CFALSE);
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * _Z_any5(OID v6224,OID v6225)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = ((belong_to(v6224,OPT_EVAL((*(OBJECT(Call,v6225)->args))[1])) == CTRUE) ? ((equal(v6224,OPT_EVAL((*(OBJECT(Call,v6225)->args))[2])) != CTRUE) ? CTRUE: CFALSE): CFALSE);
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * gcsafe_ask_class(ClaireClass *v2164)
{ return (((v2164 == Kernel._void) ? CTRUE : 
  ((INHERIT(v2164,Kernel._thing)) ? CTRUE : 
  ((INHERIT(v2164,Kernel._class)) ? CTRUE : 
  (((v2164 != Kernel._object) && 
      ((INHERIT(v2164,Kernel._object)) && 
        ((v2164->open < 3) && 
          ((inherit_ask_class(v2164,Kernel._collection) != CTRUE) && 
            (v2164 != Core._lambda))))) ? CTRUE : 
  ((v2164 == Kernel._integer) ? CTRUE : 
  ((v2164 == Kernel._char) ? CTRUE : 
  ((INHERIT(v2164,Kernel._boolean)) ? CTRUE : 
  ((v2164 == Kernel._function) ? CTRUE : 
  CFALSE)))))))));} 

ClaireBoolean * gcsafe_ask_type(ClaireType *v2164)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = ((equal(_oid_(v2164),_oid_(Kernel.emptySet)) == CTRUE) ?
      CTRUE :
      ((INHERIT(v2164->isa,Core._Union)) ?
        (((OBJECT(ClaireBoolean,(*Optimize.gcsafe_ask)(GC_OID(_oid_(CLREAD(Union,v2164,t1)))))) == CTRUE) ? (((OBJECT(ClaireBoolean,(*Optimize.gcsafe_ask)(GC_OID(_oid_(CLREAD(Union,v2164,t2)))))) == CTRUE) ? CTRUE: CFALSE): CFALSE) :
        gcsafe_ask_class(class_I_type(v2164)) ) );
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * gcsafe_ask_property(property *v2164)
{ { ClaireBoolean *Result ;
    { OID  v10875;
      { ITERATE(v6224);
        v10875= Kernel.cfalse;
        for (START(v2164->restrictions); NEXT(v6224);)
        if (_oid_((INHERIT(v2164->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v2164->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(v2164->range))))) != Kernel.ctrue)
         { v10875 = Kernel.ctrue;
          break;} 
        } 
      Result = not_any(v10875);
      } 
    return (Result);} 
  } 

OID  c_gc_I_any1(OID v2164)
{ GC_BIND;
  { OID Result = 0;
    if ((Optimize.OPT->online_ask != CTRUE) && 
        ((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v2164))) == CTRUE))
     { (Optimize.OPT->protection = CTRUE);
      { Compile_to_protect * v2072 = ((Compile_to_protect *) GC_OBJECT(Compile_to_protect,new_object_class(Optimize._to_protect)));
        (v2072->arg = v2164);
        add_I_property(Kernel.instances,Optimize._to_protect,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      } 
    else Result = v2164;
      GC_UNBIND; return (Result);} 
  } 

OID  c_gc_I_any2(OID v2164,ClaireType *v6220)
{ GC_BIND;
  { OID Result = 0;
    if ((Optimize.OPT->online_ask != CTRUE) && 
        ((((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v2164))) == CTRUE) || 
            ((INHERIT(OWNER(v2164),Language._Let)) && 
                ((*Optimize.gcsafe_ask)(GC_OID((*Optimize.c_type)(v2164))) != Kernel.ctrue))) && 
          (_oid_((INHERIT(v6220->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v6220))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(v6220))))) != Kernel.ctrue)))
     { (Optimize.OPT->protection = CTRUE);
      { Compile_to_protect * v2072 = ((Compile_to_protect *) GC_OBJECT(Compile_to_protect,new_object_class(Optimize._to_protect)));
        (v2072->arg = v2164);
        add_I_property(Kernel.instances,Optimize._to_protect,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      } 
    else Result = v2164;
      GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * need_protect_any(OID v6224)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = ((INHERIT(OWNER(v6224),Language._Call_slot)) ?
      Optimize.OPT->use_update :
      ((INHERIT(OWNER(v6224),Language._Call_method2)) ?
        ((OBJECT(Call_method,v6224)->arg->selector == Kernel.nth) ?
          ((Optimize.OPT->use_nth_equal == CTRUE) ? CTRUE : ((domain_I_restriction(OBJECT(Call_method,v6224)->arg) == Kernel._class) ? CTRUE : ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(OBJECT(Call_method,v6224)->args))[1]))),Kernel._tuple) == CTRUE) ? CTRUE : CFALSE))) :
          CTRUE ) :
        CTRUE ) );
    GC_UNBIND; return (Result);} 
  } 

Variable * Variable_I_symbol(symbol *v6219,int v6214,ClaireType *v6220)
{ GC_BIND;
  { Variable *Result ;
    { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
      (v2072->pname = v6219);
      (v2072->index = v6214);
      (v2072->range = v6220);
      add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
      Result = v2072;
      } 
    GC_UNBIND; return (Result);} 
  } 

list * get_indexed_class_Optimize(ClaireClass *v6203)
{ return (v6203->slots);} 

ClaireBoolean * designated_ask_any(OID v2164)
{ GC_BIND;
  { ClaireBoolean *Result ;
    { ClaireBoolean *v_or;
      { v_or = inherit_ask_class(OWNER(v2164),Kernel._thing);
        if (v_or == CTRUE) Result =CTRUE; 
        else { v_or = inherit_ask_class(OWNER(v2164),Language._Variable);
          if (v_or == CTRUE) Result =CTRUE; 
          else { v_or = inherit_ask_class(OWNER(v2164),Kernel._integer);
            if (v_or == CTRUE) Result =CTRUE; 
            else { v_or = ((Kernel._boolean == OWNER(v2164)) ? CTRUE : CFALSE);
              if (v_or == CTRUE) Result =CTRUE; 
              else { v_or = ((equal(v2164,Core.nil->value) == CTRUE) ? CTRUE : CFALSE);
                if (v_or == CTRUE) Result =CTRUE; 
                else { v_or = ((equal(v2164,_oid_(Kernel.emptySet)) == CTRUE) ? CTRUE : CFALSE);
                  if (v_or == CTRUE) Result =CTRUE; 
                  else { v_or = ((v2164 == CNULL) ? CTRUE : CFALSE);
                    if (v_or == CTRUE) Result =CTRUE; 
                    else { v_or = ((Kernel._float == OWNER(v2164)) ? CTRUE : CFALSE);
                      if (v_or == CTRUE) Result =CTRUE; 
                      else { if (INHERIT(OWNER(v2164),Language._Call))
                         { OID  v6224 = GC_OID((*Optimize.c_code)(v2164));
                          v_or = (((inherit_ask_class(OWNER(v6224),Language._Call) != CTRUE) && 
                              (designated_ask_any(v6224) == CTRUE)) ? CTRUE : ((OBJECT(Call,v2164)->selector == Core.get_stack) ? CTRUE : CFALSE));
                          } 
                        else if (INHERIT(OWNER(v2164),Language._Call_slot))
                         v_or = designated_ask_any(GC_OID(OBJECT(Call_slot,v2164)->arg));
                        else if (INHERIT(OWNER(v2164),Language._Call_table))
                         v_or = designated_ask_any(GC_OID(OBJECT(Call_table,v2164)->arg));
                        else if (INHERIT(OWNER(v2164),Optimize._to_protect))
                         v_or = ((need_protect_any(GC_OID(OBJECT(Compile_to_protect,v2164)->arg)) != CTRUE) ? ((designated_ask_any(GC_OID(OBJECT(Compile_to_protect,v2164)->arg)) == CTRUE) ? CTRUE: CFALSE): CFALSE);
                        else if (INHERIT(OWNER(v2164),Language._Call_method))
                         { ClaireBoolean *v_and;
                          { v_and = ((contain_ask_set(Optimize.OPT->simple_operations,_oid_(OBJECT(Call_method,v2164)->arg->selector)) == CTRUE) ? CTRUE : ((OBJECT(Call_method,v2164)->arg == _at_property1(Kernel.nth,Kernel._bag)) ? CTRUE : CFALSE));
                            if (v_and == CFALSE) v_or =CFALSE; 
                            else { { OID  v11836;
                                { OID gc_local;
                                  ITERATE(v6225);
                                  v11836= Kernel.cfalse;
                                  bag *v6225_support;
                                  v6225_support = GC_OBJECT(list,OBJECT(Call_method,v2164)->args);
                                  for (START(v6225_support); NEXT(v6225);)
                                  if (designated_ask_any(v6225) != CTRUE)
                                   { v11836 = Kernel.ctrue;
                                    break;} 
                                  } 
                                v_and = not_any(v11836);
                                } 
                              if (v_and == CFALSE) v_or =CFALSE; 
                              else v_or = CTRUE;} 
                            } 
                          } 
                        else v_or = ((INHERIT(OWNER(v2164),Optimize._to_CL)) ?
                          designated_ask_any(GC_OID(OBJECT(Compile_to_CL,v2164)->arg)) :
                          ((INHERIT(OWNER(v2164),Optimize._to_C)) ?
                            designated_ask_any(GC_OID(OBJECT(Compile_to_C,v2164)->arg)) :
                            CFALSE ) );
                        if (v_or == CTRUE) Result =CTRUE; 
                        else Result = CFALSE;} 
                      } 
                    } 
                  } 
                } 
              } 
            } 
          } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  gc_register_Variable(Variable *v2164)
{ if ((0 <= Optimize.OPT->loop_index) && 
      (v2164->index > Optimize.OPT->loop_index))
   (Optimize.OPT->loop_index = v2164->index);
  return (Kernel.ctrue);} 

OID  gc_register_Variable2(Variable *v2164,OID v10542)
{ ;{ OID Result = 0;
    if (inner2outer_ask_any(v10542) == CTRUE)
     Result = gc_register_Variable(v2164);
    else Result = Kernel.cfalse;
      return (Result);} 
  } 

ClaireBoolean * inner2outer_ask_any(OID v6224)
{ GC_BIND;
  { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v6224),Optimize._to_protect))
     Result = CTRUE;
    else if (INHERIT(OWNER(v6224),Language._Variable))
     Result = not_any((*Optimize.gcsafe_ask)(GC_OID(_oid_(OBJECT(Variable,v6224)->range))));
    else if (INHERIT(OWNER(v6224),Language._Call_method))
     Result = (((OBJECT(Call_method,v6224)->arg->selector == Kernel.copy) && 
        (OBJECT(Call_method,v6224)->arg->range == Kernel._bag)) ? CTRUE : (((BCONTAIN(OBJECT(Call_method,v6224)->arg->status,4)) && 
        (inner2outer_ask_any((*(OBJECT(Call_method,v6224)->args))[1]) == CTRUE)) ? CTRUE : CFALSE));
    else if (INHERIT(OWNER(v6224),Optimize._to_CL))
     Result = inner2outer_ask_any(OBJECT(Compile_to_CL,v6224)->arg);
    else Result = ((INHERIT(OWNER(v6224),Optimize._to_C)) ?
      inner2outer_ask_any(OBJECT(Compile_to_C,v6224)->arg) :
      ((INHERIT(OWNER(v6224),Language._List)) ?
        CTRUE :
        ((INHERIT(OWNER(v6224),Language._Set)) ?
          CTRUE :
          ((INHERIT(OWNER(v6224),Language._Let)) ?
            inner2outer_ask_any(GC_OID(_oid_(OBJECT(Instruction_with_var,v6224)->var))) :
            CFALSE ) ) ) );
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * identifiable_ask_any(OID v2164)
{ GC_BIND;
  { ClaireBoolean *Result ;
    { ClaireBoolean *v_or;
      { v_or = ((v2164 == CNULL) ? CTRUE : CFALSE);
        if (v_or == CTRUE) Result =CTRUE; 
        else { if (INHERIT(OWNER(v2164),Optimize._to_CL))
           v_or = identifiable_ask_any(GC_OID(OBJECT(Compile_to_CL,v2164)->arg));
          else { ClaireClass * v6220 = class_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v2164))));
              v_or = not_any(_oid_(contain_ask_set(Optimize.OPT->non_identifiable_set,_oid_(v6220))));
              } 
            if (v_or == CTRUE) Result =CTRUE; 
          else Result = CFALSE;} 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_inline_method1(method *v2164,list *v6212,ClaireClass *v6219)
{ GC_BIND;
  ;{ OID Result = 0;
    Result = (*Optimize.c_code)(GC_OID(c_inline_method2(v2164,v6212)),
      _oid_(v6219));
    GC_UNBIND; return (Result);} 
  } 

OID  c_inline_method2(method *v2164,list *v6212)
{ GC_RESERVE(11);  // v3.0.55 optim !
  { OID Result = 0;
    { lambda * v6206 = GC_OBJECT(lambda,v2164->formula);
      OID  v6224 = GC_OID(v6206->body);
      list * v9112 = GC_OBJECT(list,bound_variables_any(v6224));
      symbol * v13506 = (((v2164->selector == Language.iterate) || 
          (v2164->selector == Language.Iterate)) ?
        OBJECT(Variable,(*(v6206->vars))[2])->pname :
        Kernel._class->name );
      v6224= GC_OID(instruction_copy_any(v6224));
      { OID gc_local;
        ITERATE(v6222);
        for (START(v9112); NEXT(v6222);)
        { GC_LOOP;
          { Variable * v12708;
            { { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
                (v2072->pname = ((OBJECT(Variable,v6222)->pname == v13506) ?
                  v13506 :
                  gensym_void() ));
                (v2072->index = 1000);
                add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
                v12708 = v2072;
                } 
              GC_OBJECT(Variable,v12708);} 
            store_object(v12708,
              3,
              Kernel._object,
              get_property(Kernel.range,OBJECT(ClaireObject,v6222)),
              CFALSE);
            GC__OID(v6224 = substitution_any(v6224,OBJECT(Variable,v6222),_oid_(v12708)), 5);
            } 
          GC_UNLOOP;} 
        } 
      (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+v9112->length));
      Result = c_substitution_any(v6224,GC_OBJECT(list,v6206->vars),v6212,CFALSE);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_inline_arg_ask_any(OID v2164)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(OWNER(v2164),Language._Call))
     { list * v6212 = GC_OBJECT(list,OBJECT(Call,v2164)->args);
      OID  v6213;
      { { list * v13758;
          { { bag *v_list; OID v_val;
              OID v6224,CLcount;
              v_list = v6212;
               v13758 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v6224 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v6224);
                
                (*((list *) v13758))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v13758);} 
          v6213 = restriction_I_property(OBJECT(Call,v2164)->selector,v13758,CTRUE);
          } 
        GC_OID(v6213);} 
      if (Kernel._method == OWNER(v6213))
       { if ((OBJECT(method,v6213)->inline_ask == CTRUE) && 
            (c_inline_ask_method(OBJECT(method,v6213),v6212) == CTRUE))
         Result = c_inline_method2(OBJECT(method,v6213),v6212);
        else Result = Kernel.cfalse;
          } 
      else Result = Core.nil->value;
        } 
    else { OID  v14719;
        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v2072->selector = Kernel.set_I);
          (v2072->args = list::alloc(1,v2164));
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
          v14719 = _oid_(v2072);
          } 
        Result = c_inline_arg_ask_any(v14719);
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  c_substitution_any(OID v2164,list *v12468,list *v2297,ClaireBoolean *v3835)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(OWNER(v2164),Language._Variable))
     { OID  v6209;
      { { OID  v11985 = CNULL;
          { int  v6210 = 1;
            int  v6816 = v12468->length;
            { OID gc_local;
              while ((v6210 <= v6816))
              { if (OBJECT(Variable,v2164)->pname == OBJECT(Variable,(*(v12468))[v6210])->pname)
                 { v11985= v6210;
                  break;} 
                ++v6210;
                } 
              } 
            } 
          v6209 = v11985;
          } 
        GC_OID(v6209);} 
      if (v6209 != CNULL)
       Result = (*(v2297))[v6209];
      else Result = v2164;
        } 
    else if (INHERIT(OWNER(v2164),Kernel._bag))
     { { int  v6209 = 1;
        int  v6817 = OBJECT(bag,v2164)->length;
        { OID gc_local;
          while ((v6209 <= v6817))
          { ((*(OBJECT(list,v2164)))[v6209]=c_substitution_any((*(OBJECT(bag,v2164)))[v6209],v12468,v2297,v3835));
            ++v6209;
            } 
          } 
        } 
      Result = v2164;
      } 
    else if (INHERIT(OWNER(v2164),Language._Call))
     { if (OBJECT(Call,v2164)->selector == Core.eval)
       Result = c_substitution_any(GC_OID((*(OBJECT(Call,v2164)->args))[1]),v12468,v2297,((OBJECT(Call,v2164)->args->length == 1) ? CTRUE : (((OBJECT(Call,v2164)->args->length == 2) && 
          (belong_to((*(v2297))[1],(*(OBJECT(Call,v2164)->args))[2]) == CTRUE)) ? CTRUE : CFALSE)));
      else if (v3835 == CTRUE)
       { ClaireHandler c_handle = ClaireHandler();
        if ERROR_IN 
        { { list * v5015;
            { { bag *v_list; OID v_val;
                OID v6225,CLcount;
                v_list = GC_OBJECT(list,OBJECT(Call,v2164)->args);
                 v5015 = v_list->clone();
                for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                { v6225 = (*(v_list))[CLcount];
                  v_val = c_substitution_any(v6225,v12468,v2297,CTRUE);
                  
                  (*((list *) v5015))[CLcount] = v_val;} 
                } 
              GC_OBJECT(list,v5015);} 
            Result = apply_property(OBJECT(Call,v2164)->selector,v5015);
            } 
          ClEnv->cHandle--;} 
        else if (belong_to(_oid_(ClEnv->exception_I),_oid_(Kernel._any)) == CTRUE)
        { c_handle.catchIt();{ tformat_string(copy_string("a strange problem happens ~A \n"),0,GC_OBJECT(list,list::alloc(1,ClEnv->verbose)));
            warn_void();
            tformat_string(copy_string("failed substitution: ~S"),2,GC_OBJECT(list,list::alloc(1,GC_OID(_oid_(ClEnv->exception_I)))));
            c_substitution_any(GC_OID(_oid_(OBJECT(Call,v2164)->args)),v12468,v2297,CFALSE);
            Result = v2164;
            } 
          } 
        else PREVIOUS_HANDLER;} 
      else { c_substitution_any(GC_OID(_oid_(OBJECT(Call,v2164)->args)),v12468,v2297,CFALSE);
          Result = v2164;
          } 
        } 
    else if (INHERIT(OWNER(v2164),Language._Instruction))
     { { OID gc_local;
        ITERATE(v6219);
        bag *v6219_support;
        v6219_support = OWNER(v2164)->slots;
        for (START(v6219_support); NEXT(v6219);)
        { OID  v6225 = get_slot(OBJECT(slot,v6219),OBJECT(ClaireObject,v2164));
          put_slot(OBJECT(slot,v6219),OBJECT(ClaireObject,v2164),c_substitution_any(v6225,v12468,v2297,v3835));
          } 
        } 
      Result = v2164;
      } 
    else Result = v2164;
      GC_UNBIND; return (Result);} 
  } 

OID  eval_any2(OID v6224,ClaireClass *v6225)
{ return (OPT_EVAL(v6224));} 

list * bound_variables_any(OID v2164)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { list *Result ;
    { list * v6212 = list::empty(Kernel._any);
      if (INHERIT(OWNER(v2164),Language._Instruction_with_var))
       v6212= list::alloc(Kernel._any,1,GC_OID(_oid_(OBJECT(For,v2164)->var)));
      if (INHERIT(OWNER(v2164),Language._Variable))
       ;else if (INHERIT(OWNER(v2164),Language._Instruction))
       { OID gc_local;
        ITERATE(v6219);
        for (START(OBJECT(ClaireObject,v2164)->isa->slots); NEXT(v6219);)
        { GC_LOOP;
          GC__ANY(v6212 = add_star_list(v6212,bound_variables_any(get_slot(OBJECT(slot,v6219),OBJECT(ClaireObject,v2164)))), 1);
          GC_UNLOOP;} 
        } 
      else if (INHERIT(OWNER(v2164),Kernel._bag))
       { OID gc_local;
        ITERATE(v6224);
        for (START(OBJECT(bag,v2164)); NEXT(v6224);)
        v6212= add_star_list(v6212,bound_variables_any(v6224));
        } 
      Result = v6212;
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_boolean_any(OID v6224)
{ GC_BIND;
  { OID Result = 0;
    { ClaireType * v12716 = GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v6224)));
      ClaireType * v13516 = ptype_type(v12716);
      if (_inf_equal_type(v13516,Kernel._boolean) == CTRUE)
       { if (INHERIT(OWNER(v6224),Language._Call))
         { if ((OBJECT(Call,v6224)->selector == Core.NOT) && 
              (ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID((*(OBJECT(Call,v6224)->args))[1])))) != Kernel._boolean))
           { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Core._I_equal);
              { Call * v6840 = v2072; 
                list * v6841;
                { OID v_bag;
                  GC_ANY(v6841= list::empty(Kernel.emptySet));
                  { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Kernel.boolean_I);
                      (v2072->args = list::alloc(1,GC_OID((*(OBJECT(Call,v6224)->args))[1])));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v_bag = _oid_(v2072);
                      } 
                    GC_OID(v_bag);} 
                  ((list *) v6841)->addFast(v_bag);
                  ((list *) v6841)->addFast(Kernel.ctrue);} 
                (v6840->args = v6841);} 
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v6224 = _oid_(v2072);
              } 
            GC_OID(v6224);} 
          } 
        if (_inf_equal_type(v12716,Kernel._boolean) == CTRUE)
         Result = c_strict_code_any(v6224,Kernel._boolean);
        else Result = (*Optimize.c_code)(v6224,
            _oid_(Kernel._boolean));
          } 
      else if (_inf_equal_type(v12716,Kernel._bag) == CTRUE)
       { OID  v7898;
        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v2072->selector = Core._I_equal);
          { Call * v6843 = v2072; 
            list * v6844;
            { OID v_bag;
              GC_ANY(v6844= list::empty(Kernel.emptySet));
              { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Kernel.length);
                  (v2072->args = list::alloc(1,v6224));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v_bag = _oid_(v2072);
                  } 
                GC_OID(v_bag);} 
              ((list *) v6844)->addFast(v_bag);
              ((list *) v6844)->addFast(0);} 
            (v6843->args = v6844);} 
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
          v7898 = _oid_(v2072);
          } 
        Result = (*Optimize.c_code)(v7898);
        } 
      else { OID  v10781;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.boolean_I);
            (v2072->args = list::alloc(1,v6224));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v10781 = _oid_(v2072);
            } 
          Result = (*Optimize.c_code)(v10781);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

