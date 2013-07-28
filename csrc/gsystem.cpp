/***** CLAIRE Compilation of file c:\claire\v3.3\src\compile\gsystem.cl 
         [version 3.3.46 / safety 5] Sun Feb 15 15:37:28 2009 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
#include <Generate.h>
void  ident_symbol(symbol *v2548)
{ (*Language.ident)(Generate.PRODUCER->value,
    _oid_(v2548));
  } 

void  ident_thing(thing *v2548)
{ (*Language.ident)(Generate.PRODUCER->value,
    _oid_(v2548->name));
  } 

void  ident_class(ClaireClass *v2548)
{ (*Language.ident)(Generate.PRODUCER->value,
    _oid_(v2548->name));
  } 

void  interface_I_class(ClaireClass *v1723)
{ (*Generate.interface_I)(Generate.PRODUCER->value,
    _oid_(v1723));
  } 

void  class_princ_class(ClaireClass *v1723)
{ (*Generate.class_princ)(Generate.PRODUCER->value,
    _oid_(v1723));
  } 

OID  indent_c_void()
{ { OID Result = 0;
    { int  v1744 = Optimize.OPT->level;
      { Result= _oid_(CFALSE);
        while ((v1744 > 0))
        { princ_string(copy_string("  "));
          v1744= (v1744-1);
          } 
        } 
      } 
    return (Result);} 
  } 

OID  breakline_void()
{ princ_string(copy_string("\n"));
  return (indent_c_void());} 

void  new_block_void()
{ (Optimize.OPT->level = (Optimize.OPT->level+1));
  princ_string("{ ");
  } 

void  close_block_void()
{ (Optimize.OPT->level = (Optimize.OPT->level-1));
  princ_string("} ");
  breakline_void();
  } 

void  c_test_any(OID v1744)
{ GC_BIND;
  { OID  v1740 = GC_OID((*Optimize.c_type)(v1744));
    ClaireClass * v1741 = osort_any(v1740);
    OID  v1742 = GC_OID((*Optimize.c_code)(v1744,
      _oid_(v1741)));
    ClaireBoolean * v1726 = c_func_any(v1742);
    princ_string(copy_string("type -> "));
    print_any(v1740);
    princ_string(copy_string(" [sort "));
    print_any(_oid_(v1741));
    princ_string(copy_string("]\n"));
    princ_string(copy_string("opt["));
    print_any(_oid_(OWNER(v1742)));
    princ_string(copy_string("] -> "));
    print_any(v1742);
    princ_string(copy_string(" \n"));
    if (v1726 == CTRUE)
     { princ_string(copy_string("exp  -> "));
      (*Generate.expression)(v1742,
        Core.nil->value);
      princ_string(copy_string("\n"));
      } 
    else { princ_string(copy_string("stat -> "));
        statement_any(v1742,_string_(copy_string("result")),Core.nil->value);
        princ_string(copy_string("\n"));
        } 
      } 
  GC_UNBIND;} 

void  c_test_method(method *v1733)
{ GC_BIND;
  { lambda * v1732 = GC_OBJECT(lambda,v1733->formula);
    if (v1732 == (NULL))
     ;else { tformat_string(copy_string("---- Compiling ~S ---- \n"),0,list::alloc(1,_oid_(v1733)));
        (Optimize.OPT->in_method = _oid_(v1733));
        (Optimize.OPT->protection = CFALSE);
        (Optimize.OPT->allocation = CFALSE);
        if (Optimize.OPT->loop_index > 0)
         (Optimize.OPT->loop_index = 0);
        (Optimize.OPT->loop_gc = CFALSE);
        (Optimize.OPT->use_update = CFALSE);
        (Optimize.OPT->use_nth_equal = CFALSE);
        (Optimize.OPT->use_string_update = CFALSE);
        (Optimize.OPT->max_vars = 0);
        (Optimize.OPT->online_ask = CFALSE);
        (Optimize.OPT->legal_modules = ((set *) Kernel._module->instances));
        (OBJECT(Generate_producer,Generate.PRODUCER->value)->body = v1732->body);
        { ClaireClass * v1741 = Kernel._void;
          OID  v14751;
          { { v1741= check_sort_method(v1733);
              v14751 = OBJECT(Generate_producer,Generate.PRODUCER->value)->body;
              } 
            GC_OID(v14751);} 
          char * v5438 = GC_STRING(string_v((*Generate.protect_result)(Generate.PRODUCER->value,
            _oid_(v1741),
            _oid_(Optimize.OPT->protection),
            _oid_(v1733))));
          princ_string(copy_string("Opt => "));
          print_any(v14751);
          princ_string(copy_string(" \n\n"));
          new_block_void();
          (*Generate.print_body)(v14751,
            _string_(v5438),
            _oid_(v1741),
            GC_OID(v1732->body),
            Kernel.ctrue);
          } 
        (Optimize.OPT->in_method = CNULL);
        } 
      } 
  GC_UNBIND;} 

void  compile_module(module *v2548)
{ GC_BIND;
  (Optimize.OPT->need_modules = Kernel.emptySet);
  { bag * v4589 = GC_OBJECT(list,parents_list(GC_OBJECT(list,add_modules_list(list::alloc(1,_oid_(v2548))))));
    update_property(Optimize.legal_modules,
      Optimize.OPT,
      9,
      Kernel._object,
      GC_OID((*Kernel.set_I)(_oid_(v4589))));
    if (Optimize.compiler->class2file_ask == CTRUE)
     { tformat_string(copy_string("**** Compiling the module ~A [v. 3.~A - verbose:~A opt:~S] \n"),2,list::alloc(4,_string_(string_I_symbol(v2548->name)),
        GC_OID(Optimize.compiler->version),
        ClEnv->verbose,
        _oid_(Optimize.compiler->optimize_ask)));
      write_property(Generate.outmodule,Optimize.OPT,GC_OID(ClAlloc->import(Kernel._port,(int *) fopen_string(append_string(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),GC_STRING(string_v((*Generate.c_string)(Generate.PRODUCER->value,
        _oid_(v2548->name)))))),GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),copy_string("w")))));
      generate_files_module(v2548);
      begin_module(v2548);
      generate_classes_module(v2548);
      generate_c2f_module(v2548);
      end_module(v2548);
      } 
    else { generate_files_module(v2548);
        generate_f2f_module(v2548);
        generate_interface_module(v2548,GC_OBJECT(set,Optimize.OPT->legal_modules));
        } 
      v4589= GC_OBJECT(set,difference_set(GC_OBJECT(set,set_I_set(Optimize.OPT->need_modules)),GC_OBJECT(set,Optimize.OPT->legal_modules)));
    tformat_string(copy_string("++++ v3.3.32 info: ~A GC protection inserted. \n"),1,list::alloc(1,OBJECT(Generate_producer,Generate.PRODUCER->value)->stat));
    if (v4589->length != 0)
     tformat_string(copy_string("---- WARNING: ~S should be declared for ~S\n"),2,list::alloc(2,_oid_(v4589),_oid_(v2548)));
    } 
  GC_UNBIND;} 

void  generate_files_module(module *v2548)
{ GC_BIND;
  tformat_string(copy_string("==== Generate ~A files for module ~S [verbose = ~A, Opt? = ~S] \n"),0,list::alloc(4,GC_OID(_string_(OBJECT(Generate_producer,Generate.PRODUCER->value)->comment)),
    _oid_(v2548),
    ClEnv->verbose,
    _oid_(Optimize.compiler->optimize_ask)));
  (Optimize.OPT->instructions = list::empty(Kernel._any));
  (Optimize.OPT->properties = set::empty(Kernel._property));
  (Optimize.OPT->objects = list::empty(Kernel._object));
  (Optimize.OPT->functions = list::empty(Kernel._any));
  (Optimize.OPT->need_to_close = set::empty(Kernel._any));
  (*Generate.start_module_interface)(Generate.PRODUCER->value,
    _oid_(v2548));
  begin_module(v2548);
  { OID gc_local;
    ITERATE(v1744);
    bag *v1744_support;
    v1744_support = GC_OBJECT(list,v2548->made_of);
    for (START(v1744_support); NEXT(v1744);)
    { GC_LOOP;
      { tformat_string(copy_string("++++ Compiling the file ~A.cl [v. 3.~A - safety:~A] \n"),2,list::alloc(3,v1744,
          GC_OID(Optimize.compiler->version),
          Optimize.compiler->safety));
        if (equal(v1744,_string_(string_I_symbol(v2548->name))) == CTRUE)
         (*Optimize.Cerror)(_string_(copy_string("[211]  ~S cannot be used both as a file and module name")),
          v1744);
        generate_file_string2(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(v2548->source),GC_STRING(string_v(Reader._starfs_star->value)))),string_v(v1744))),GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),string_v(v1744))));
        if (CFALSE == CTRUE)
         claire_gc();
        } 
      GC_UNLOOP;} 
    } 
  end_module(v2548);
  GC_UNBIND;} 

void  generate_f2f_module(module *v1733)
{ GC_BIND;
  { ClairePort * v1736 = fopen_string(append_string(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),string_I_symbol(v1733->name))),GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),copy_string("w"));
    tformat_string(copy_string("==== generate file for module ~S ==== \n"),0,list::alloc(1,_oid_(v1733)));
    (Optimize.OPT->outfile = v1736);
    generate_file_string1(string_I_symbol(v1733->name),v1733);
    } 
  GC_UNBIND;} 

void  generate_file_string1(char *v1741,module *v1733)
{ GC_BIND;
  start_file_string(v1741,v1733);
  use_as_output_port(Optimize.OPT->outfile);
  (*Generate.generate_classes)(Generate.PRODUCER->value,
    _string_(v1741),
    _oid_(v1733));
  { OID gc_local;
    ITERATE(v1723);
    bag *v1723_support;
    v1723_support = GC_OBJECT(list,Optimize.OPT->objects);
    for (START(v1723_support); NEXT(v1723);)
    if (INHERIT(OWNER(v1723),Kernel._class))
     (*Generate.methods_bodies)(Generate.PRODUCER->value,
      v1723);
    } 
  generate_meta_load_module(v1733);
  breakline_void();
  princ_string(copy_string("GC_UNBIND;"));
  close_block_void();
  breakline_void();
  fclose_port(Optimize.OPT->outfile);
  GC_UNBIND;} 

void  generate_classes_module(module *v2548)
{ GC_BIND;
  erase_table(Generate.classFile);
  { OID gc_local;
    ITERATE(v1723);
    bag *v1723_support;
    v1723_support = GC_OBJECT(list,Optimize.OPT->objects);
    for (START(v1723_support); NEXT(v1723);)
    { GC_LOOP;
      if (INHERIT(OWNER(v1723),Kernel._class))
       { put_table(Generate.classFile,v1723,GC_OID(ClAlloc->import(Kernel._port,(int *) fopen_string(append_string(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),GC_STRING(string_v((*Generate.c_string)(Generate.PRODUCER->value,
          GC_OID((*Kernel.name)(v1723))))))),GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),copy_string("w")))));
        use_as_output_port(EXPORT((ClairePort *),nth_table1(Generate.classFile,v1723)));
        tformat_string(copy_string("++++ Creating the file ~A.java\n"),2,GC_OBJECT(list,list::alloc(1,GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
          GC_OID((*Kernel.name)(v1723)))))));
        (Optimize.OPT->level = 0);
        princ_string(copy_string("// class file for "));
        print_any(v1723);
        princ_string(copy_string(" in module "));
        print_any(_oid_(v2548));
        princ_string(copy_string(" "));
        breakline_void();
        breakline_void();
        breakline_void();
        princ_string(copy_string("public class "));
        ident_symbol(OBJECT(symbol,(*Kernel.name)(v1723)));
        princ_string(copy_string(" extends "));
        ident_symbol(OBJECT(ClaireClass,v1723)->superclass->name);
        new_block_void();
        breakline_void();
        breakline_void();
        princ_string(copy_string("/* empty constructor by default */"));
        breakline_void();
        princ_string(copy_string("public "));
        ident_symbol(OBJECT(symbol,(*Kernel.name)(v1723)));
        princ_string(copy_string("() {}"));
        breakline_void();
        breakline_void();
        breakline_void();
        princ_string(copy_string("/* declaration of fields */"));
        { OID gc_local;
          ITERATE(v1745);
          bag *v1745_support;
          v1745_support = GC_OBJECT(list,OBJECT(bag,(*Optimize.get_indexed)(v1723)));
          for (START(v1745_support); NEXT(v1745);)
          if (_oid_(domain_I_restriction(OBJECT(restriction,v1745))) == v1723)
           { breakline_void();
            princ_string(copy_string("public  "));
            interface_I_class(psort_any(_oid_(OBJECT(restriction,v1745)->range)));
            princ_string(copy_string(" "));
            ident_symbol(OBJECT(restriction,v1745)->selector->name);
            princ_string(copy_string(";"));
            } 
          } 
        breakline_void();
        princ_string(copy_string(""));
        fclose_port(EXPORT((ClairePort *),nth_table1(Generate.classFile,v1723)));
        } 
      GC_UNLOOP;} 
    } 
  GC_UNBIND;} 

void  generate_c2f_module(module *v2548)
{ GC_BIND;
  { ClairePort * v14773 = fopen_string(append_string(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),GC_STRING(string_v((*Generate.c_string)(Generate.PRODUCER->value,
      _oid_(v2548->name)))))),GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),copy_string("w"));
    (Optimize.OPT->outfile = v14773);
    use_as_output_port(v14773);
    (*Generate.generate_start_file)(Generate.PRODUCER->value,
      _oid_(v2548));
    fclose_port(v14773);
    claire_gc();
    generate_functions_module(v2548);
    claire_gc();
    v14773= fopen_string(append_string(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),GC_STRING(string_v((*Generate.c_string)(Generate.PRODUCER->value,
      _oid_(v2548->name)))))),GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),copy_string("a"));
    use_as_output_port(v14773);
    (Optimize.OPT->outfile = v14773);
    (Optimize.OPT->level = 2);
    generate_objects_module(v2548);
    use_as_output_port(EXPORT((ClairePort *),Reader.STDOUT->value));
    claire_gc();
    use_as_output_port(v14773);
    generate_meta_load_module(v2548);
    (*Generate.generate_end_file)(Generate.PRODUCER->value,
      _oid_(v2548));
    } 
  GC_UNBIND;} 

void  generate_interface_module(module *v2548,bag *v1732)
{ tformat_string(copy_string("==== Generate inteface (.h) files for module ~S \n"),0,list::alloc(1,_oid_(v2548)));
  use_as_output_port(Optimize.OPT->cinterface);
  breakline_void();
  (*Generate.generate_interface)(Generate.PRODUCER->value,
    _oid_(v2548));
  (*Generate.namespace_I)(Generate.PRODUCER->value,
    _oid_(v2548));
  generate_objects_module(v2548);
  (*Kernel.module_I)(Generate.PRODUCER->value,
    _oid_(v2548));
  (*Generate.end_module_interface)(Generate.PRODUCER->value,
    _oid_(v2548));
  fclose_port(Optimize.OPT->cinterface);
  use_as_output_port(EXPORT((ClairePort *),Reader.STDOUT->value));
  } 

void  generate_objects_module(module *v2548)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID gc_local;
    ITERATE(v1744);
    bag *v1744_support;
    v1744_support = GC_OBJECT(list,Optimize.OPT->objects);
    for (START(v1744_support); NEXT(v1744);)
    { breakline_void();
      (*Generate.public_static)(Generate.PRODUCER->value);
      if (INHERIT(OWNER(v1744),Core._global_variable))
       { { OID  v16291;
          if (nativeVar_ask_global_variable(OBJECT(global_variable,v1744)) == CTRUE)
           v16291 = _oid_(getRange_global_variable(OBJECT(global_variable,v1744)));
          else v16291 = _oid_(Core._global_variable);
            (*Generate.interface_I)(Generate.PRODUCER->value,
            v16291);
          } 
        princ_string(copy_string(" "));
        ident_symbol(OBJECT(thing,v1744)->name);
        princ_string(copy_string(";"));
        } 
      else { (*Generate.interface_I)(Generate.PRODUCER->value,
            _oid_(psort_any(_oid_(OWNER(v1744)))));
          princ_string(copy_string(" "));
          if (INHERIT(OWNER(v1744),Kernel._class))
           { princ_string(copy_string("_"));
            c_princ_string(string_I_symbol(OBJECT(symbol,(*Kernel.name)(v1744))));
            } 
          else if (INHERIT(OWNER(v1744),Reader._reserved_keyword))
           { princ_string(copy_string("_cl_"));
            c_princ_string(string_I_symbol(OBJECT(symbol,(*Kernel.name)(v1744))));
            } 
          else ident_symbol(OBJECT(symbol,(*Kernel.name)(v1744)));
            princ_string(copy_string(";"));
          } 
        } 
    } 
  { OID gc_local;
    ITERATE(v1744);
    bag *v1744_support;
    v1744_support = GC_OBJECT(set,Optimize.OPT->properties);
    for (START(v1744_support); NEXT(v1744);)
    { GC_LOOP;
      if (Optimize.OPT->objects->memq(v1744) != CTRUE)
       { { OID  v4604;
          { { OID  v3497 = CNULL;
              { OID gc_local;
                ITERATE(v4714);
                bag *v4714_support;
                v4714_support = GC_OBJECT(set,Optimize.OPT->properties);
                for (START(v4714_support); NEXT(v4714);)
                { GC_LOOP;
                  if (v4714 != v1744)
                   { if (equal_string(string_I_symbol(OBJECT(thing,v4714)->name),string_I_symbol(OBJECT(thing,v1744)->name)) == CTRUE)
                     { v3497= v4714;
                      break;} 
                    } 
                  GC_UNLOOP;} 
                } 
              v4604 = v3497;
              } 
            GC_OID(v4604);} 
          if (v4604 != CNULL)
           { property * v4714 = OBJECT(property,v4604);
            close_exception(((general_error *) (*Core._general_error)(_string_(copy_string("[217] ~S and ~S cannot be defined in the same module")),
              _oid_(list::alloc(2,_oid_(v4714),v1744)))));
            } 
          else ;} 
        princ_string(copy_string("\n"));
        (*Generate.public_static)(Generate.PRODUCER->value);
        (*Generate.interface_I)(Generate.PRODUCER->value,
          _oid_(psort_any(_oid_(OWNER(v1744)))));
        princ_string(copy_string(" "));
        ident_symbol(OBJECT(thing,v1744)->name);
        princ_string(copy_string(";// "));
        print_any(_oid_(OBJECT(thing,v1744)->name));
        princ_string(copy_string(""));
        } 
      GC_UNLOOP;} 
    } 
  GC_UNBIND;} 

void  generate_meta_load_module(module *v2548)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  princ_string(copy_string("// definition of the meta-model for "));
  print_any(_oid_(v2548));
  princ_string(copy_string(" \n"));
  breakline_void();
  princ_string(copy_string(""));
  (*Generate.generate_meta_load)(Generate.PRODUCER->value,
    _oid_(v2548));
  princ_string(copy_string("// definition of the properties "));
  { OID gc_local;
    ITERATE(v1744);
    bag *v1744_support;
    v1744_support = GC_OBJECT(set,Optimize.OPT->properties);
    for (START(v1744_support); NEXT(v1744);)
    if (Optimize.OPT->objects->memq(v1744) != CTRUE)
     (*Generate.declare)(Generate.PRODUCER->value,
      v1744);
    } 
  breakline_void();
  breakline_void();
  princ_string(copy_string("// instructions from module sources"));
  { OID  v1730 = CNULL;
    { OID gc_local;
      ITERATE(v1729);
      bag *v1729_support;
      v1729_support = GC_OBJECT(list,Optimize.OPT->instructions);
      for (START(v1729_support); NEXT(v1729);)
      { GC_LOOP;
        { breakline_void();
          if (Kernel._string == OWNER(v1729))
           { if (equal(_oid_(Kernel._string),_oid_(OWNER(v1730))) != CTRUE)
             breakline_void();
            princ_string(copy_string("// "));
            (*Kernel.princ)(v1729);
            princ_string(copy_string(""));
            } 
          else if (global_var_def_ask_any(v1729) == CTRUE)
           (*Generate.global_var_def_I)(Generate.PRODUCER->value,
            _oid_(v2548),
            v1729);
          else statement_any(v1729,_oid_(Kernel.emptySet),_oid_(Kernel.emptySet));
            GC__OID(v1730 = v1729, 1);
          } 
        GC_UNLOOP;} 
      } 
    } 
  GC_UNBIND;} 

ClaireBoolean * global_var_def_ask_any(OID v1744)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = ((INHERIT(OWNER(v1744),Language._Let)) ?
      ((INHERIT(OWNER(OBJECT(Let,v1744)->value),Language._Call)) ? (((*Kernel.selector)(OBJECT(Let,v1744)->value) == _oid_(Optimize.object_I)) ? (((*(OBJECT(bag,(*Core.args)(OBJECT(Let,v1744)->value))))[2] == _oid_(Core._global_variable)) ? CTRUE: CFALSE): CFALSE): CFALSE) :
      CFALSE );
    GC_UNBIND; return (Result);} 
  } 

ClaireClass * getRange_global_variable(global_variable *v1744)
{ { ClaireClass *Result ;
    Result = ((equal(_oid_(v1744->range),_oid_(Kernel.emptySet)) == CTRUE) ?
      OWNER(v1744->value) :
      class_I_type(v1744->range) );
    return (Result);} 
  } 

void  generate_functions_module(module *v2548)
{ GC_BIND;
  princ_string(copy_string("// definition of class methods "));
  { ClairePort * v1736 = (Optimize.OPT->outfile);
    { OID gc_local;
      ITERATE(v1726);
      bag *v1726_support;
      v1726_support = GC_OBJECT(list,Optimize.OPT->functions);
      for (START(v1726_support); NEXT(v1726);)
      { GC_LOOP;
        { (Optimize.OPT->level = 2);
          (Optimize.OPT->outfile = v1736);
          print_c_function_lambda2(GC_OBJECT(lambda,OBJECT(lambda,(*Kernel.nth)(v1726,
            1))),GC_STRING(string_v((*Kernel.nth)(v1726,
            2))),GC_OID((*Kernel.nth)(v1726,
            3)));
          } 
        GC_UNLOOP;} 
      } 
    } 
  GC_UNBIND;} 

list * parents_module(module *v2548,list *v1732)
{ if (v1732->memq(_oid_(v2548)) == CTRUE) 
  { { list *Result ;
      Result = v1732;
      return (Result);} 
     } 
  else{ GC_BIND;
    if (((v2548->part_of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
     v1732= GC_OBJECT(list,parents_module(v2548->part_of,v1732));
    v1732= GC_OBJECT(list,v1732->addFast(_oid_(v2548)));
    { list *Result ;
      Result = v1732;
      GC_UNBIND; return (Result);} 
    } 
  } 

list * parents_list(list *v2548)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { list *Result ;
    { list * v1732 = list::empty(Kernel._module);
      { OID gc_local;
        ITERATE(v1744);
        for (START(v2548); NEXT(v1744);)
        { GC_LOOP;
          GC__ANY(v1732 = parents_module(OBJECT(module,v1744),v1732), 1);
          GC_UNLOOP;} 
        } 
      Result = v1732;
      } 
    GC_UNBIND; return (Result);} 
  } 

void  get_module2(module *v1733)
{ load_module(v1733);
  begin_module(v1733);
  } 

void  generate_file_string2(char *v2548,char *v4404)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { ClairePort * v4713 = fopen_string(append_string(v2548,copy_string(".cl")),copy_string("r"));
    ClaireBoolean * v1722 = Reader.reader->toplevel;
    ClairePort * v4712 = (Reader.reader->fromp);
    if (Optimize.compiler->class2file_ask != CTRUE)
     (Optimize.OPT->outfile = fopen_string(append_string(v4404,GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),copy_string("w")));
    (Reader.reader->toplevel = CFALSE);
    (Optimize.compiler->loading_ask = CTRUE);
    (Reader.reader->nb_line = 1);
    (Reader.reader->external = v2548);
    (Reader.reader->fromp = v4713);
    if (Optimize.compiler->class2file_ask != CTRUE)
     start_file_string(v2548,ClEnv->module_I);
    { OID  v9713 = GC_OID(readblock_port(v4713));
      { OID gc_local;
        while ((equal(v9713,_oid_(Reader.eof)) != CTRUE))
        { GC_LOOP;
          if (ClEnv->verbose > 5)
           { princ_string(copy_string("["));
            princ_integer(Reader.reader->nb_line);
            princ_string(copy_string("] "));
            print_any(_oid_(OWNER(v9713)));
            princ_string(copy_string(" ("));
            print_any(GC_OID(_oid_(Optimize.OPT->need_modules)));
            princ_string(copy_string("%)\n"));
            } 
          if ((Kernel._string == OWNER(v9713)) && 
              (Optimize.compiler->class2file_ask != CTRUE))
           { if (Optimize.compiler->naming < 2)
             { ClairePort * v4776 = use_as_output_port(Optimize.OPT->outfile);
              princ_string(copy_string("\n//"));
              (*Kernel.princ)(v9713);
              princ_string(copy_string(""));
              use_as_output_port(v4776);
              } 
            } 
          else Optimize.OPT->instructions->addFast((*Optimize.c_code)(v9713,
              _oid_(Kernel._void)));
            GC__OID(v9713 = readblock_port(v4713), 1);
          GC_UNLOOP;} 
        } 
      } 
    fclose_port(v4713);
    (Optimize.compiler->loading_ask = CFALSE);
    (Reader.reader->toplevel = v1722);
    (Reader.reader->external = copy_string("toplevel"));
    (Reader.reader->fromp = v4712);
    if (Optimize.compiler->class2file_ask != CTRUE)
     fclose_port(Optimize.OPT->outfile);
    } 
  GC_UNBIND;} 

OID  make_c_function_lambda_Generate(lambda *v2548,char *v14127,OID v1733)
{ { OID Result = 0;
    if (Optimize.compiler->class2file_ask == CTRUE)
     Result = (*Generate.create_function_entry)(Generate.PRODUCER->value,
      _oid_(v2548),
      _string_(v14127),
      v1733);
    else Result = print_c_function_lambda2(v2548,v14127,v1733);
      return (Result);} 
  } 

OID  print_c_function_lambda2(lambda *v2548,char *v14127,OID v1733)
{ GC_BIND;
  (OBJECT(Generate_producer,Generate.PRODUCER->value)->body = v2548->body);
  { OID Result = 0;
    { ClaireClass * v1741 = Kernel._void;
      OID  v14751;
      { if (boolean_I_any(v1733) != CTRUE)
         v14751 = (*Optimize.c_code)(GC_OID(v2548->body),
          _oid_(Kernel._void));
        else if (Kernel._method == OWNER(v1733))
         { v1741= check_sort_method(OBJECT(method,v1733));
          v14751 = OBJECT(Generate_producer,Generate.PRODUCER->value)->body;
          } 
        else if (INHERIT(OWNER(v1733),Kernel._class))
         { v1741= OBJECT(ClaireClass,v1733);
          v14751 = (*Optimize.c_code)(GC_OID(v2548->body),
            v1733);
          } 
        else { v1741= Kernel._any;
            v14751 = (*Optimize.c_code)(GC_OID(v2548->body),
              _oid_(Kernel._any));
            } 
          GC_OID(v14751);} 
      OID  v5438 = GC_OID((*Generate.protect_result)(Generate.PRODUCER->value,
        _oid_(v1741),
        _oid_(Optimize.OPT->protection),
        v1733));
      ClaireBoolean * v5622 = need_debug_ask_any(v1733);
      ClaireBoolean * v11404 = ((Optimize.OPT->profile_ask == CTRUE) ? (((Kernel._method == OWNER(v1733)) || 
          (v1733 == CNULL)) ? CTRUE: CFALSE): CFALSE);
      (*Generate.generate_function_start)(Generate.PRODUCER->value,
        _oid_(v2548),
        _oid_(v1741),
        v1733,
        _string_(v14127));
      if (Optimize.OPT->max_vars > 0)
       { (Language._starvariable_index_star->value= 0);
        lexical_num_any2(v14751,(v2548->vars->length+1));
        (Optimize.OPT->loop_index = Language._starvariable_index_star->value);
        } 
      new_block_void();
      if (v11404 == CTRUE)
       (*Generate.generate_profile)(Generate.PRODUCER->value,
        v1733);
      if (v5622 == CTRUE)
       (*Generate.debug_intro)(Generate.PRODUCER->value,
        _oid_(v2548),
        v1733);
      (*Generate.print_body)(v14751,
        v5438,
        _oid_(v1741),
        GC_OID(v2548->body),
        _oid_(not_any(_oid_(((Optimize.OPT->protection == CTRUE) ? CTRUE : ((v11404 == CTRUE) ? CTRUE : ((v5622 == CTRUE) ? CTRUE : ((Optimize.OPT->alloc_stack == CTRUE) ? CTRUE : CFALSE))))))));
      close_block_void();
      breakline_void();
      (Optimize.OPT->alloc_stack = CFALSE);
      Result = ClAlloc->import(Kernel._port,(int *) use_as_output_port(EXPORT((ClairePort *),Reader.STDOUT->value)));
      } 
    GC_UNBIND; return (Result);} 
  } 

void  print_body_If(If *v14751,char *v5438,ClaireClass *v1741,If *v846,ClaireBoolean *v9217)
{ GC_BIND;
  if ((c_func_any(GC_OID(v14751->test)) == CTRUE) && 
      ((Optimize.OPT->protection == CTRUE) && 
        ((c_safe_any(GC_OID(v846->arg)) == CTRUE) && 
          (Optimize.compiler->debug_ask->memq(_oid_(ClEnv->module_I)) != CTRUE))))
   { char * v4788 = ((v1741 != Kernel._void) ?
      copy_string("return ") :
      copy_string("") );
    princ_string(copy_string("if "));
    (*Optimize.bool_exp)(GC_OID(v14751->test),
      Kernel.ctrue,
      Core.nil->value);
    princ_string(copy_string(" "));
    breakline_void();
    new_block_void();
    outer_statement_any(GC_OID(v14751->arg),v4788,v1741,v9217);
    princ_string(copy_string(" "));
    close_block_void();
    princ_string(copy_string("else"));
    new_block_void();
    (*Generate.print_body)(GC_OID(v14751->other),
      _string_(v5438),
      _oid_(v1741),
      GC_OID(v846->other),
      _oid_(v9217));
    close_block_void();
    } 
  else print_body_any(_oid_(v14751),
      v5438,
      v1741,
      _oid_(v846),
      v9217);
    GC_UNBIND;} 

void  print_body_any(OID v14751,char *v5438,ClaireClass *v1741,OID v846,ClaireBoolean *v9217)
{ (*Generate.gc_introduction)(Generate.PRODUCER->value,
    v14751);
  outer_statement_any(v14751,v5438,v1741,v9217);
  } 

OID  print_body_Do(Do *v14751,char *v5438,ClaireClass *v1741,OID v846,ClaireBoolean *v9217)
{ GC_BIND;
  { OID Result = 0;
    { list * v1732 = GC_OBJECT(list,v14751->args);
      int  v12195 = v1732->length;
      int  v1733 = 0;
      (*Generate.gc_introduction)(Generate.PRODUCER->value,
        _oid_(v14751));
      { ITERATE(v1744);
        Result= Kernel.cfalse;
        for (START(v1732); NEXT(v1744);)
        { ++v1733;
          if (v1733 == v12195)
           outer_statement_any(v1744,v5438,v1741,v9217);
          else inner_statement_any(v1744,_oid_(Kernel.emptySet),_oid_(Kernel.emptySet));
            } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

void  outer_statement_any(OID v14751,char *v5438,ClaireClass *v1741,ClaireBoolean *v9217)
{ if ((c_func_any(v14751) == CTRUE) && 
      ((v9217 == CTRUE) && 
        ((v1741 != Kernel._void) && 
          (inherit_ask_class(OWNER(v14751),Language._If) != CTRUE))))
   { if (equal_string(v5438,copy_string("")) != CTRUE)
     { princ_string(v5438);
      princ_string(copy_string("("));
      (*Generate.expression)(v14751,
        Core.nil->value);
      princ_string(copy_string(");"));
      } 
    else { (*Generate.expression)(v14751,
          Core.nil->value);
        princ_string(copy_string(";"));
        } 
      } 
  else if (v1741 != Kernel._void)
   { new_block_void();
    (*Generate.define_variable)(Generate.PRODUCER->value,
      _oid_(v1741),
      _string_(copy_string("Result")));
    breakline_void();
    statement_any(v14751,_string_(copy_string("Result")),_oid_(Kernel.emptySet));
    if (equal_string(v5438,copy_string("")) != CTRUE)
     { princ_string(v5438);
      princ_string(copy_string("(Result);"));
      close_block_void();
      princ_string(copy_string(""));
      } 
    } 
  else { statement_any(v14751,_oid_(Kernel.emptySet),_oid_(Kernel.emptySet));
      princ_string(v5438);
      } 
    } 

ClaireBoolean * c_safe_any(OID v1744)
{ return (not_any(_oid_(((Optimize.OPT->allocation == CTRUE) ? ((BCONTAIN(c_status_any(v1744,Kernel.nil),1)) ? CTRUE: CFALSE): CFALSE))));} 

ClaireClass * check_sort_method(method *v2548)
{ GC_BIND;
  { ClaireClass *Result ;
    { ClaireType * v4806 = v2548->range;
      OID  v1722 = GC_OID(OBJECT(Generate_producer,Generate.PRODUCER->value)->body);
      ClaireType * v4807 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v1722))));
      ClaireClass * v1741 = psort_any(_oid_(v4806));
      (OBJECT(Generate_producer,Generate.PRODUCER->value)->body = c_strict_code_any(v1722,v1741));
      if (_inf_equal_type(v4807,v4806) != CTRUE)
       { tformat_string(copy_string("---- note: ~S's range was found to be ~S (vs. ~S) \n"),2,list::alloc(3,_oid_(v2548),
          _oid_(v4807),
          _oid_(v4806)));
        if (Generate.WrongMethod->value == 0)
         { (Generate.WrongMethod->value= v1722);
          close_exception(((general_error *) (*Core._general_error)(_string_(copy_string("You can look at WrongMethod")),
            _oid_(Kernel.nil))));
          } 
        if ((Optimize.compiler->safety < 2) || 
            ((Optimize.compiler->safety < 4) && 
                (boolean_I_any(sort_equal_class(osort_any(_oid_(v4807)),v1741)) != CTRUE)))
         (OBJECT(Generate_producer,Generate.PRODUCER->value)->body = c_strict_code_any(GC_OID(c_check_any(GC_OID((*Optimize.c_code)(v1722,
          _oid_(Kernel._any))),GC_OID((*Optimize.c_code)(_oid_(v4806),
          _oid_(Kernel._type))))),v1741));
        if (boolean_I_any(sort_equal_class(osort_any(_oid_(v4807)),v1741)) != CTRUE)
         { if ((v1741 != Kernel._void) && 
              ((_oid_((INHERIT(v4807->isa,Kernel._class) ? (ClaireObject *) sort_I_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v4807))) :  (ClaireObject *)  sort_I_type((ClaireType *) OBJECT(ClaireType,_oid_(v4807))))) == _oid_(Kernel._void)) || 
                  (inherit_ask_class(v1741,OBJECT(ClaireClass,_oid_((INHERIT(v4807->isa,Kernel._class) ? (ClaireObject *) sort_I_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v4807))) :  (ClaireObject *)  sort_I_type((ClaireType *) OBJECT(ClaireType,_oid_(v4807))))))) != CTRUE)))
           (*Optimize.Cerror)(_string_(copy_string("[218] Sort error: Cannot compile ~S.")),
            _oid_(v2548));
          } 
        } 
      { ClaireType * v4808 = GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel._exp)(_oid_(v4806),
          _oid_(v4807))));
        if ((Optimize.compiler->safety > 1) && 
            (osort_any(_oid_(v4808)) == v1741))
         { (OBJECT(Generate_producer,Generate.PRODUCER->value)->body = (*Optimize.c_strict_check)(GC_OID(OBJECT(Generate_producer,Generate.PRODUCER->value)->body),
            _oid_(class_I_type(v4808))));
          ;} 
        } 
      if (INHERIT(v4806->isa,Kernel._tuple))
       { (Optimize.OPT->alloc_stack = CTRUE);
        } 
      if ((Optimize.OPT->allocation == CTRUE) && 
          (nth_integer(status_I_restriction(v2548),5) != CTRUE))
       { if (nth_integer(status_I_restriction(v2548),1) != CTRUE)
         ;} 
      else { (Optimize.OPT->loop_gc = CFALSE);
          (Optimize.OPT->protection = CFALSE);
          } 
        Result = psort_any(_oid_(v2548->range));
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  typed_args_list_list(list *v2548)
{ { OID Result = 0;
    { ClaireBoolean * v15841 = CTRUE;
      { ITERATE(v1744);
        Result= Kernel.cfalse;
        for (START(v2548); NEXT(v1744);)
        { if (v15841 == CTRUE)
           v15841= CFALSE;
          else princ_string(",");
            (*Generate.interface_I)(Generate.PRODUCER->value,
            _oid_(sort_Variable(OBJECT(Variable,v1744))));
          (*Language.ident)(Generate.PRODUCER->value,
            v1744);
          } 
        } 
      } 
    return (Result);} 
  } 

ClaireBoolean * need_debug_ask_any(OID v1733)
{ { ClaireBoolean *Result ;
    if (Kernel._method == OWNER(v1733))
     { property * v1736 = OBJECT(restriction,v1733)->selector;
      Result = ((Optimize.compiler->debug_ask->memq(_oid_(OBJECT(restriction,v1733)->module_I)) == CTRUE) ? 
      ((domain_I_restriction(OBJECT(restriction,v1733)) != Kernel._environment) ? 
      ((OBJECT(restriction,v1733)->module_I != claire.it) ? 
      ((v1736 != Core.self_eval) ? 
      ((v1736 != Core.execute) ? 
      ((v1736 != Core.eval_message) ? 
      ((v1736 != Core.push_debug) ? 
      ((v1736 != Core.pop_debug) ? 
      ((v1736 != Core.tr_indent) ? 
      ((v1736 != Core.find_which) ? 
      ((v1736 != Core.matching_ask) ? 
      ((v1736 != Core.vmatch_ask) ? 
      CTRUE: CFALSE): CFALSE): CFALSE): CFALSE): CFALSE): CFALSE): CFALSE): CFALSE): CFALSE): CFALSE): CFALSE): CFALSE);
      } 
    else Result = CFALSE;
      return (Result);} 
  } 

void  get_dependents_method(method *v1733)
{ GC_BIND;
  { OID gc_local;
    ITERATE(v1736);
    bag *v1736_support;
    v1736_support = GC_OBJECT(set,dependents_method(v1733));
    for (START(v1736_support); NEXT(v1736);)
    { property * v6597 = v1733->selector;
      add_table(Reader.PRdependent,_oid_(v6597),v1736);
      } 
    } 
  GC_UNBIND;} 

void  c_princ_function(ClaireFunction *v2548)
{ c_princ_string(string_I_function(v2548));
  } 

void  set_outfile_lambda(lambda *v2548)
{ GC_BIND;
  { module * v1733 = ClEnv->module_I;
    char * v4369 = string_I_symbol(v1733->name);
    ClairePort * v1736 = (Optimize.OPT->outfile);
    OID  v4517;
    { if (v2548->vars->length != 0)
       v4517 = (*Kernel.range)((*(v2548->vars))[1]);
      else v4517 = CNULL;
        GC_OID(v4517);} 
    if (v4517 != CNULL)
     { { ClaireBoolean * g0007I;
        { OID  v3751;
          { OID gc_local;
            ITERATE(v1723);
            v3751= Kernel.cfalse;
            bag *v1723_support;
            v1723_support = GC_OBJECT(list,Optimize.OPT->objects);
            for (START(v1723_support); NEXT(v1723);)
            if ((INHERIT(OWNER(v1723),Kernel._class)) && 
                (equal(v1723,v4517) == CTRUE))
             { v3751 = Kernel.ctrue;
              break;} 
            } 
          g0007I = boolean_I_any(v3751);
          } 
        
        if (g0007I == CTRUE) v4369= GC_STRING(string_v((*Generate.c_string)(Generate.PRODUCER->value,
            _oid_(OBJECT(ClaireClass,v4517)->name))));
          } 
      if (equal_string(v4369,string_I_symbol(ClEnv->module_I->name)) != CTRUE)
       v1736= fopen_string(append_string(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),v4369)),GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),copy_string("a"));
      (Optimize.OPT->outfile = v1736);
      } 
    ;} 
  GC_UNBIND;} 

