/***** CLAIRE Compilation of file c:\claire\v3.3\src\compile\cgen.cl 
         [version 3.3.46 / safety 5] Sun Feb 15 15:37:28 2009 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
#include <Generate.h>
char * c_string_c_producer1(Generate_c_producer *v1723,Variable *v2548)
{ GC_BIND;
  { char *Result ;
    if (Optimize.compiler->naming == 2)
     Result = append_string(copy_string("v"),GC_STRING(string_I_integer (integer_I_symbol(v2548->pname))));
    else { print_in_string_void();
        ident_c_producer(v1723,v2548->pname);
        Result = end_of_print_void();
        } 
      GC_UNBIND; return (Result);} 
  } 

char * c_string_c_producer2(Generate_c_producer *v1723,symbol *v2548)
{ print_in_string_void();
  ident_c_producer(v1723,v2548);
  return (end_of_print_void());} 

char * string_I_c_producer1(Generate_c_producer *v1723,Variable *v2548)
{ GC_BIND;
  { char *Result ;
    if (Optimize.compiler->naming == 2)
     Result = append_string(copy_string("v"),GC_STRING(string_I_integer (integer_I_symbol(v2548->pname))));
    else { print_in_string_void();
        ident_c_producer(v1723,v2548->pname);
        Result = end_of_print_void();
        } 
      GC_UNBIND; return (Result);} 
  } 

char * string_I_c_producer2(Generate_c_producer *v1723,symbol *v2548)
{ print_in_string_void();
  ident_c_producer(v1723,v2548);
  return (end_of_print_void());} 

void  ident_c_producer3(Generate_c_producer *v1723,Variable *v1743)
{ GC_BIND;
  if (Optimize.compiler->naming == 2)
   princ_string(append_string("v",GC_STRING(string_I_integer (integer_I_symbol(v1743->pname)))));
  else { symbol * v1741 = v1743->pname;
      int  v1734 = index_list(v1723->bad_names,_oid_(v1741));
      if (v1734 == 0)
       c_princ_string(string_I_symbol(v1741));
      else c_princ_symbol(OBJECT(symbol,(*(v1723->good_names))[v1734]));
        } 
    GC_UNBIND;} 

void  ident_c_producer(Generate_c_producer *v1723,symbol *v1741)
{ { int  v1734 = index_list(v1723->bad_names,_oid_(v1741));
    if (v1734 == 0)
     c_princ_string(string_I_symbol(v1741));
    else c_princ_symbol(OBJECT(symbol,(*(v1723->good_names))[v1734]));
      } 
  } 

void  class_princ_c_producer(Generate_c_producer *v1723,ClaireClass *v2548)
{ if (v2548->name->module_I != claire.it)
   { ident_c_producer(v1723,v2548->name->module_I->name);
    princ_string(copy_string("_"));
    } 
  ident_c_producer(v1723,v2548->name);
  } 

void  produce_c_producer2(Generate_c_producer *v1723,OID v1744)
{ if (INHERIT(OWNER(v1744),Kernel._function))
   { princ_string(copy_string("_function_("));
    c_princ_function(OBJECT(ClaireFunction,v1744));
    princ_string(copy_string(","));
    print_any(_string_(string_I_function(OBJECT(ClaireFunction,v1744))));
    princ_string(copy_string(")"));
    } 
  else if (INHERIT(OWNER(v1744),Kernel._char))
   { princ_string(copy_string("_char_('"));
    if ((v1744 == _oid_(_char_('\"'))) || 
        ((v1744 == _oid_(_char_('\''))) || 
          ((v1744 == _oid_(_char_('\?'))) || 
            (v1744 == _oid_(_char_('\\'))))))
     princ_string(copy_string("\\"));
    princ_char(OBJECT(ClaireChar,v1744));
    princ_string(copy_string("')"));
    } 
  else if (INHERIT(OWNER(v1744),Kernel._environment))
   princ_string(copy_string("ClEnv"));
  else if (Kernel._string == OWNER(v1744))
   { if (Optimize.OPT->use_string_update == CTRUE)
     { princ_string(copy_string("copy_string("));
      print_any(v1744);
      princ_string(copy_string(")"));
      } 
    else print_any(v1744);
      } 
  else if (INHERIT(OWNER(v1744),Core._global_variable))
   globalVar_c_producer(v1723,OBJECT(global_variable,v1744));
  else if (Kernel._boolean == OWNER(v1744))
   { if ((OBJECT(ClaireBoolean,v1744)) == CTRUE)
     princ_string(copy_string("CTRUE"));
    else princ_string(copy_string("CFALSE"));
      } 
  else if (INHERIT(OWNER(v1744),Kernel._symbol))
   { princ_string(copy_string("symbol::make("));
    print_any(_string_(string_I_symbol(OBJECT(symbol,v1744))));
    princ_string(copy_string(","));
    ident_symbol(OBJECT(symbol,v1744)->module_I->name);
    princ_string(copy_string(","));
    ident_symbol(defined_symbol(OBJECT(symbol,v1744))->name);
    princ_string(copy_string(")"));
    } 
  else if (INHERIT(OWNER(v1744),Kernel._class))
   { if (v1744 == _oid_(Kernel._cl_import))
     princ_string(copy_string("Kernel._cl_import"));
    else { ident_c_producer(v1723,defined_symbol(OBJECT(ClaireClass,v1744)->name)->name);
        princ_string(copy_string("._"));
        c_princ_string(string_I_symbol(OBJECT(ClaireClass,v1744)->name));
        princ_string(copy_string(""));
        } 
      } 
  else if (INHERIT(OWNER(v1744),Reader._reserved_keyword))
   { ident_c_producer(v1723,defined_symbol(OBJECT(thing,v1744)->name)->name);
    princ_string(copy_string("._cl_"));
    c_princ_string(string_I_symbol(OBJECT(thing,v1744)->name));
    princ_string(copy_string(""));
    } 
  else if (INHERIT(OWNER(v1744),Kernel._thing))
   { if (INHERIT(OBJECT(ClaireObject,v1744)->isa,Kernel._module))
     { ident_c_producer(v1723,OBJECT(thing,v1744)->name);
      princ_string(copy_string(".it"));
      } 
    else { ident_c_producer(v1723,defined_symbol(OBJECT(thing,v1744)->name)->name);
        princ_string(copy_string("."));
        ident_symbol(OBJECT(thing,v1744)->name);
        princ_string(copy_string(""));
        } 
      } 
  else princ_string(copy_string("CNULL"));
    } 

void  globalVar_c_producer(Generate_c_producer *v1723,global_variable *v1744)
{ GC_BIND;
  if ((equal(_oid_(v1744->range),_oid_(Kernel.emptySet)) == CTRUE) && 
      (INHERIT(OWNER(v1744->value),Kernel._integer)))
   (*Kernel.princ)(v1744->value);
  else { ident_c_producer(v1723,defined_symbol(v1744->name)->name);
      princ_string(copy_string("."));
      ident_symbol(v1744->name);
      if (nativeVar_ask_global_variable(v1744) != CTRUE)
       princ_string(copy_string("->value"));
      princ_string(copy_string(""));
      } 
    GC_UNBIND;} 

void  stat_exp_c_producer(Generate_c_producer *v1723,OID v2548,OID v332)
{ GC_BIND;
  if (INHERIT(OWNER(v2548),Optimize._to_C))
   stat_exp_c_producer(v1723,GC_OID(OBJECT(Compile_to_C,v2548)->arg),v332);
  else if (INHERIT(OWNER(v2548),Optimize._to_CL))
   stat_exp_c_producer(v1723,GC_OID(OBJECT(Compile_to_CL,v2548)->arg),v332);
  else if (designated_ask_any(v2548) == CTRUE)
   princ_string(copy_string(";"));
  else { (*Generate.expression)(v2548,
        v332);
      princ_string(copy_string(";"));
      breakline_void();
      princ_string(copy_string(""));
      } 
    GC_UNBIND;} 

void  namespace_I_c_producer(Generate_c_producer *v1723,module *v1733)
{ princ_string(copy_string("\n\n// namespace class for "));
  print_any(_oid_(v1733));
  princ_string(copy_string(" \n"));
  { princ_string(copy_string("class "));
    ident_c_producer(v1723,v1733->name);
    princ_string(copy_string("Class: public NameSpace {\npublic:\n"));
    } 
  } 

void  module_I_c_producer(Generate_c_producer *v1723,module *v1733)
{ princ_string(copy_string("\n\n// module definition \n"));
  princ_string(copy_string(" void metaLoad();};\n\n"));
  princ_string(copy_string("extern "));
  ident_c_producer(v1723,v1733->name);
  princ_string(copy_string("Class "));
  ident_c_producer(v1723,v1733->name);
  princ_string(copy_string(";\n"));
  { module * v4621 = v1733->part_of;
    { while (((boolean_I_any(_oid_(v4621->made_of)) != CTRUE) && 
          (v4621 != claire.it)))
      { princ_string(copy_string("extern NameSpace "));
        ident_c_producer(v1723,v4621->name);
        princ_string(copy_string(";\n"));
        v4621= v4621->part_of;
        } 
      } 
    } 
  } 

void  declare_c_producer(Generate_c_producer *v1723,property *v1736)
{ breakline_void();
  { expression_thing(v1736,Core.nil->value);
    princ_string(copy_string(" = "));
    princ_string(((INHERIT(v1736->isa,Kernel._operation)) ?
      copy_string("operation") :
      copy_string("property") ));
    princ_string(copy_string("::make("));
    print_any(_string_(string_I_symbol(v1736->name)));
    princ_string(copy_string(","));
    if ((v1736->open != 1) || 
        (v1736->dispatcher > 0))
     { expression_integer(v1736->open,_oid_(Kernel.emptySet));
      princ_string(copy_string(","));
      } 
    expression_thing(v1736->name->module_I,Core.nil->value);
    if (INHERIT(v1736->isa,Kernel._operation))
     { princ_string(copy_string(","));
      princ_integer(CLREAD(operation,v1736,precedence));
      princ_string(copy_string(""));
      } 
    else if (v1736->dispatcher > 0)
     { princ_string(copy_string(","));
      (*Generate.expression)(_oid_(v1736->domain),
        Core.nil->value);
      princ_string(copy_string(","));
      princ_integer(v1736->dispatcher);
      princ_string(copy_string(""));
      } 
    princ_string(copy_string(");"));
    } 
  } 

void  start_module_interface_c_producer(Generate_c_producer *v1723,module *v2548)
{ GC_BIND;
  { char * v9052 = GC_STRING(append_string(GC_STRING(Optimize.compiler->headers_dir),GC_STRING(append_string(GC_STRING(append_string(GC_STRING(string_v(Reader._starfs_star->value)),string_I_symbol(v2548->name))),copy_string(".h")))));
    (Optimize.OPT->cinterface = fopen_string(v9052,copy_string("w")));
    use_as_output_port(Optimize.OPT->cinterface);
    princ_string(copy_string("// interface defination for module "));
    print_any(_oid_(v2548));
    princ_string(copy_string(", "));
    princ_string(date_I_integer(1));
    princ_string(copy_string(""));
    princ_string(copy_string("#ifndef CLAIREH_"));
    ident_thing(v2548);
    princ_string(copy_string("\n#define CLAIREH_"));
    ident_thing(v2548);
    princ_string(copy_string("\n"));
    { OID gc_local;
      ITERATE(v1744);
      bag *v1744_support;
      v1744_support = GC_OBJECT(list,Optimize.compiler->headers);
      for (START(v1744_support); NEXT(v1744);)
      { princ_string(copy_string("#include \""));
        princ_string(string_v(v1744));
        princ_string(copy_string(".h\"\n"));
        } 
      } 
    use_as_output_port(EXPORT((ClairePort *),Reader.STDOUT->value));
    } 
  GC_UNBIND;} 

void  end_module_interface_c_producer(Generate_c_producer *v1723,module *v2548)
{ princ_string("\n#endif\n");
  } 

void  generate_end_file_c_producer(Generate_c_producer *v1730,module *v1733)
{ GC_BIND;
  close_block_void();
  fclose_port(Optimize.OPT->outfile);
  { OID gc_local;
    ITERATE(v1723);
    bag *v1723_support;
    v1723_support = GC_OBJECT(list,Optimize.OPT->objects);
    for (START(v1723_support); NEXT(v1723);)
    { GC_LOOP;
      if (INHERIT(OWNER(v1723),Kernel._class))
       { ClairePort * v1736 = fopen_string(append_string(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),GC_STRING(c_string_c_producer2(v1730,OBJECT(symbol,(*Kernel.name)(v1723)))))),GC_STRING(v1730->extension)),copy_string("a"));
        use_as_output_port(v1736);
        close_block_void();
        fclose_port(v1736);
        } 
      GC_UNLOOP;} 
    } 
  GC_UNBIND;} 

void  generate_classes_c_producer(Generate_c_producer *v1730,char *v1741,module *v1733)
{ princ_string("\n\n");
  princ_string(v1741);
  princ_string("Class ");
  princ_string(v1741);
  princ_string(";\n\n");
  { module * v4620 = v1733;
    module * v4621 = v4620->part_of;
    { while (((boolean_I_any(_oid_(v4621->made_of)) != CTRUE) && 
          ((v4621 != claire.it) && 
            ((*(v4621->parts))[1] == _oid_(v4620)))))
      { princ_string("NameSpace ");
        (*Language.ident)(Generate.PRODUCER->value,
          _oid_(v4621->name));
        princ_string(";\n");
        v4621= v4621->part_of;
        v4620= v4621;
        } 
      } 
    } 
  } 

void  generate_start_file_c_producer(Generate_c_producer *v1723,module *v1733)
{ GC_BIND;
  tformat_string(copy_string("++++ Creating the file ~A.cpp \n"),2,list::alloc(1,GC_OID(_string_(c_string_c_producer2(v1723,v1733->name)))));
  start_file_string(string_I_symbol(v1733->name),v1733);
  (Optimize.OPT->level = 0);
  princ_string(copy_string("/* class file for module "));
  print_any(_oid_(v1733));
  princ_string(copy_string(" */"));
  breakline_void();
  breakline_void();
  princ_string(copy_string("public class "));
  ident_c_producer(v1723,v1733->name);
  princ_string(copy_string(" extends NameSpace"));
  new_block_void();
  GC_UNBIND;} 

void  generate_meta_load_c_producer(Generate_c_producer *v1723,module *v1733)
{ princ_string(copy_string("void "));
  ident_c_producer(v1723,v1733->name);
  princ_string(copy_string("Class::metaLoad() "));
  new_block_void();
  breakline_void();
  { princ_string(copy_string("GC_BIND;"));
    breakline_void();
    princ_string(copy_string("ClEnv->module_I = it;\n"));
    } 
  } 

OID  start_file_string(char *v1741,module *v1733)
{ GC_BIND;
  use_as_output_port(Optimize.OPT->outfile);
  princ_string(copy_string("/***** CLAIRE Compilation of file "));
  princ_string(v1741);
  princ_string(copy_string(".cl \n         [version "));
  (*Kernel.princ)(GC_OID(release_void()));
  princ_string(copy_string(" / safety "));
  print_any(Optimize.compiler->safety);
  princ_string(copy_string("] "));
  princ_string(substring_string(date_I_integer(1),1,24));
  princ_string(copy_string(" *****/\n\n"));
  princ_string(copy_string("#include <claire.h>\n"));
  princ_string(copy_string("#include <Kernel.h>\n"));
  { OID gc_local;
    ITERATE(v1744);
    bag *v1744_support;
    v1744_support = GC_OBJECT(list,add_modules_list(list::alloc(1,_oid_(v1733))));
    for (START(v1744_support); NEXT(v1744);)
    { GC_LOOP;
      { { OID gc_local;
          ITERATE(v1747);
          bag *v1747_support;
          v1747_support = GC_OBJECT(list,OBJECT(module,v1744)->uses);
          for (START(v1747_support); NEXT(v1747);)
          if (Kernel._string == OWNER(v1747))
           { princ_string(copy_string("#include <"));
            (*Kernel.princ)(v1747);
            princ_string(copy_string(".h>\n"));
            } 
          } 
        if (OBJECT(module,v1744)->made_of->length != 0)
         { princ_string(copy_string("#include <"));
          ident_symbol(OBJECT(symbol,(*Kernel.name)(v1744)));
          princ_string(copy_string(".h>\n"));
          } 
        } 
      GC_UNLOOP;} 
    } 
  if (boolean_I_any(Optimize.OPT->cfile) == CTRUE)
   { princ_string(copy_string("#include <"));
    (*Kernel.princ)(GC_OID(Optimize.OPT->cfile));
    princ_string(copy_string(".h>\n"));
    } 
  { OID Result = 0;
    Result = ClAlloc->import(Kernel._port,(int *) use_as_output_port(EXPORT((ClairePort *),Reader.STDOUT->value)));
    GC_UNBIND; return (Result);} 
  } 

void  define_variable_c_producer2(Generate_c_producer *v1723,ClaireClass *v1740,char *v1743)
{ interface_I_class(v1740);
  princ_string(v1743);
  princ_string(copy_string(" "));
  if ((v1740 == Kernel._integer) || 
      (v1740 == Kernel._any))
   princ_string(copy_string("= 0"));
  else if (v1740 == Kernel._float)
   princ_string(copy_string("=0.0"));
  princ_string(copy_string(";"));
  } 

void  generate_profile_c_producer(Generate_c_producer *v1723,OID v1733)
{ if (Kernel._method == OWNER(v1733))
   get_dependents_method(OBJECT(method,v1733));
  { princ_string(copy_string("   PRcount *PR_x = PRstart(PRget_property("));
    expression_thing(((Kernel._method == OWNER(v1733)) ?
      OBJECT(restriction,v1733)->selector :
      Kernel.fastcall ),Core.nil->value);
    princ_string(copy_string("));"));
    breakline_void();
    princ_string(copy_string(""));
    } 
  } 

void  generate_interface_c_producer(Generate_c_producer *v1723,module *v2548)
{ GC_RESERVE(8);  // v3.0.55 optim !
  { OID gc_local;
    ITERATE(v1744);
    bag *v1744_support;
    v1744_support = GC_OBJECT(list,Optimize.OPT->objects);
    for (START(v1744_support); NEXT(v1744);)
    if (INHERIT(OWNER(v1744),Kernel._class))
     { princ_string(copy_string("\nclass "));
      class_princ_c_producer(v1723,OBJECT(ClaireClass,v1744));
      princ_string(copy_string(";"));
      } 
    } 
  { OID gc_local;
    ITERATE(v1744);
    bag *v1744_support;
    v1744_support = GC_OBJECT(list,Optimize.OPT->objects);
    for (START(v1744_support); NEXT(v1744);)
    { GC_LOOP;
      if (INHERIT(OWNER(v1744),Kernel._class))
       { princ_string(copy_string("\n\nclass "));
        class_princ_c_producer(v1723,OBJECT(ClaireClass,v1744));
        princ_string(copy_string(": public "));
        class_princ_c_producer(v1723,OBJECT(ClaireClass,v1744)->superclass);
        new_block_void();
        breakline_void();
        princ_string(copy_string("public:"));
        { OID gc_local;
          ITERATE(v1745);
          bag *v1745_support;
          v1745_support = GC_OBJECT(list,OBJECT(bag,(*Optimize.get_indexed)(v1744)));
          for (START(v1745_support); NEXT(v1745);)
          { ClaireBoolean * g0060I;
            { OID  v11930;
              { OID gc_local;
                ITERATE(v4807);
                v11930= Kernel.cfalse;
                for (START(OBJECT(ClaireClass,v1744)->superclass->slots); NEXT(v4807);)
                if (_I_equal_any(_oid_(OBJECT(restriction,v4807)->selector),_oid_(OBJECT(restriction,v1745)->selector)) != CTRUE)
                 { v11930 = Kernel.ctrue;
                  break;} 
                } 
              g0060I = not_any(v11930);
              } 
            
            if (g0060I == CTRUE) { breakline_void();
                princ_string(copy_string("   "));
                (*Generate.interface_I)(Generate.PRODUCER->value,
                  _oid_(psort_any(_oid_(OBJECT(restriction,v1745)->range))));
                ident_symbol(OBJECT(restriction,v1745)->selector->name);
                princ_string(copy_string(";"));
                } 
              } 
          } 
        (*Generate.methods_interface)(Generate.PRODUCER->value,
          v1744);
        close_block_void();
        princ_string(copy_string(";"));
        } 
      GC_UNLOOP;} 
    } 
  { OID gc_local;
    ITERATE(v1732);
    bag *v1732_support;
    v1732_support = GC_OBJECT(list,Optimize.OPT->functions);
    for (START(v1732_support); NEXT(v1732);)
    { GC_LOOP;
      { OID  v2441 = GC_OID((*Kernel.nth)(v1732,
          1));
        OID  v7721 = GC_OID((*Kernel.nth)(v1732,
          2));
        OID  v1741 = GC_OID((*Kernel.nth)(v1732,
          3));
        princ_string(copy_string("\nextern "));
        (*Generate.interface_I)(Generate.PRODUCER->value,
          v1741);
        princ_string(copy_string(" "));
        (*Kernel.c_princ)(v2441);
        princ_string(copy_string("("));
        typed_args_list_list(OBJECT(list,v7721));
        princ_string(copy_string(");"));
        } 
      GC_UNLOOP;} 
    } 
  GC_UNBIND;} 

void  global_var_def_I_c_producer(Generate_c_producer *v1723,module *v2548,Let *v1744)
{ GC_BIND;
  { global_variable * v6494 = OBJECT(global_variable,get_symbol(OBJECT(symbol,(*(OBJECT(bag,(*Core.args)(GC_OID(v1744->value)))))[1])));
    ClaireClass * v1741 = getRange_global_variable(v6494);
    OID  v11654 = GC_OID((*(OBJECT(Do,v1744->arg)->args))[2]);
    OID  v11849;
    { if (INHERIT(OWNER(v11654),Language._Update))
       v11849 = OBJECT(Update,v11654)->value;
      else if ((INHERIT(OWNER(v11654),Language._Call)) || 
          (INHERIT(OWNER(v11654),Language._Call_method)))
       v11849 = (*(OBJECT(bag,(*Core.args)(v11654))))[5];
      else { OID  v8406;close_exception(((general_error *) (*Core._general_error)(_string_(copy_string("Design bug: make ~S a public global var !")),
            _oid_(list::alloc(1,_oid_(v6494))))));
          
          v11849=_void_(v8406);} 
        GC_OID(v11849);} 
    ClaireBoolean * v1722 = c_func_any(v11849);
    Variable * v6344 = GC_OBJECT(Variable,build_Variable_string(copy_string("V_C"),_oid_(Kernel._any)));
    if (nativeVar_ask_global_variable(v6494) != CTRUE)
     statement_any(_oid_(v1744),Core.nil->value,Core.nil->value);
    else { if (v1722 != CTRUE)
         { new_block_void();
          princ_string(copy_string("OID "));
          ident_c_producer3(v1723,v6344);
          princ_string(copy_string(";"));
          breakline_void();
          statement_any(v11849,GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
            _oid_(v6344))),Core.nil->value);
          princ_string(copy_string(""));
          } 
        ident_c_producer(v1723,v2548->name);
        princ_string(copy_string("."));
        ident_c_producer(v1723,v6494->name);
        princ_string(copy_string(" = "));
        if (v1722 == CTRUE)
         to_c_c_producer1(v1723,v11849,v1741,Core.nil->value);
        else to_c_c_producer1(v1723,_oid_(v6344),v1741,Core.nil->value);
          princ_string(copy_string(";"));
        if (v1722 != CTRUE)
         close_block_void();
        breakline_void();
        princ_string(copy_string(""));
        } 
      } 
  GC_UNBIND;} 

void  gc_introduction_c_producer(Generate_c_producer *v1723,OID v2437)
{ GC_BIND;
  if (Optimize.OPT->protection == CTRUE)
   { OID  v1746 = GC_OID(gc_usage_any(v2437,CFALSE));
    if ((Optimize.OPT->loop_gc == CTRUE) && 
        (INHERIT(OWNER(v1746),Kernel._integer)))
     { if ((OBJECT(ClaireBoolean,(*Kernel._inf)(v1746,
        100))) == CTRUE)
       { (Optimize.OPT->loop_index = 0);
        princ_string(copy_string("GC_RESERVE(1);  // HOHO v3.0.55 optim !"));
        } 
      else { princ_string(copy_string("GC_RESERVE("));
          princ_integer((Optimize.OPT->loop_index+1));
          princ_string(copy_string(");  // v3.0.55 optim !"));
          } 
        } 
    else princ_string(copy_string("GC_BIND;"));
      breakline_void();
    } 
  GC_UNBIND;} 

OID  gc_usage_any(OID v2548,ClaireBoolean *v332)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(OWNER(v2548),Language._Instruction))
     { if (INHERIT(OBJECT(ClaireObject,v2548)->isa,Language._Construct))
       Result = gc_usage_star_list(GC_OBJECT(list,OBJECT(Construct,v2548)->args),v332);
      else if (INHERIT(OBJECT(ClaireObject,v2548)->isa,Language._Definition))
       Result = Kernel.ctrue;
      else if (INHERIT(OBJECT(ClaireObject,v2548)->isa,Language._Call_method))
       Result = gc_usage_star_list(GC_OBJECT(list,OBJECT(Call_method,v2548)->args),v332);
      else if (INHERIT(OBJECT(ClaireObject,v2548)->isa,Language._Call_slot))
       Result = gc_usage_any(GC_OID(OBJECT(Call_slot,v2548)->arg),v332);
      else if (INHERIT(OBJECT(ClaireObject,v2548)->isa,Language._Call_table))
       Result = gc_usage_any(GC_OID(OBJECT(Call_table,v2548)->arg),v332);
      else if (INHERIT(OBJECT(ClaireObject,v2548)->isa,Language._Call_array))
       Result = gc_usage_any(GC_OID(OBJECT(Call_array,v2548)->arg),v332);
      else if (INHERIT(OBJECT(ClaireObject,v2548)->isa,Optimize._to_C))
       Result = gc_usage_any(GC_OID(OBJECT(Compile_to_C,v2548)->arg),v332);
      else if (INHERIT(OBJECT(ClaireObject,v2548)->isa,Optimize._to_CL))
       Result = gc_usage_any(GC_OID(OBJECT(Compile_to_CL,v2548)->arg),v332);
      else if (INHERIT(OBJECT(ClaireObject,v2548)->isa,Optimize._to_protect))
       Result = Kernel.ctrue;
      else if (INHERIT(OBJECT(ClaireObject,v2548)->isa,Language._Update))
       Result = gc_usage_any(GC_OID(OBJECT(Update,v2548)->value),v332);
      else if (INHERIT(OBJECT(ClaireObject,v2548)->isa,Language._Call))
       Result = gc_usage_star_list(GC_OBJECT(list,OBJECT(Call,v2548)->args),v332);
      else if (INHERIT(OBJECT(ClaireObject,v2548)->isa,Language._If))
       Result = gc_or_any(gc_usage_any(GC_OID(OBJECT(If,v2548)->test),v332),gc_or_any(GC_OID(gc_usage_any(GC_OID(OBJECT(If,v2548)->arg),v332)),GC_OID(gc_usage_any(GC_OID(OBJECT(If,v2548)->other),v332))));
      else if (INHERIT(OBJECT(ClaireObject,v2548)->isa,Language._Do))
       Result = gc_usage_star_list(GC_OBJECT(list,OBJECT(Do,v2548)->args),v332);
      else if (INHERIT(OBJECT(ClaireObject,v2548)->isa,Language._Iteration))
       Result = gc_or_any(GC_OID(gc_usage_any(GC_OID(OBJECT(Iteration,v2548)->set_arg),v332)),GC_OID(gc_usage_any(GC_OID(OBJECT(Iteration,v2548)->arg),CTRUE)));
      else if (INHERIT(OBJECT(ClaireObject,v2548)->isa,Language._Let))
       { OID  v1744 = GC_OID(OBJECT(Let,v2548)->value);
        { OID  v13852;
          if ((v332 == CTRUE) && 
              (INHERIT(OWNER(v1744),Optimize._to_protect)))
           v13852 = OBJECT(Instruction_with_var,v2548)->var->index;
          else v13852 = Kernel.cfalse;
            Result = gc_or_any(v13852,gc_or_any(GC_OID(gc_usage_any(v1744,v332)),GC_OID(gc_usage_any(GC_OID(OBJECT(Let,v2548)->arg),v332))));
          } 
        } 
      else if (INHERIT(OBJECT(ClaireObject,v2548)->isa,Language._Assign))
       { OID  v1744 = GC_OID(OBJECT(Assign,v2548)->arg);
        { OID  v14813;
          { if ((v332 == CTRUE) && 
                (inner2outer_ask_any(v1744) == CTRUE))
             v14813 = (*Kernel.index)(GC_OID(OBJECT(Assign,v2548)->var));
            else v14813 = Kernel.cfalse;
              GC_OID(v14813);} 
          Result = gc_or_any(v14813,GC_OID(gc_usage_any(v1744,v332)));
          } 
        } 
      else if (INHERIT(OBJECT(ClaireObject,v2548)->isa,Optimize._to_protect))
       Result = Kernel.ctrue;
      else if (INHERIT(OBJECT(ClaireObject,v2548)->isa,Language._Gassign))
       Result = gc_usage_any(GC_OID(OBJECT(Gassign,v2548)->arg),v332);
      else if (INHERIT(OBJECT(ClaireObject,v2548)->isa,Language._And))
       Result = gc_usage_star_list(GC_OBJECT(list,OBJECT(And,v2548)->args),v332);
      else if (INHERIT(OBJECT(ClaireObject,v2548)->isa,Language._Or))
       Result = gc_usage_star_list(GC_OBJECT(list,OBJECT(Or,v2548)->args),v332);
      else if (INHERIT(OBJECT(ClaireObject,v2548)->isa,Language._Cast))
       Result = gc_usage_any(GC_OID(OBJECT(Cast,v2548)->arg),v332);
      else if (INHERIT(OBJECT(ClaireObject,v2548)->isa,Language._Super))
       Result = gc_usage_star_list(GC_OBJECT(list,OBJECT(Super,v2548)->args),v332);
      else if (INHERIT(OBJECT(ClaireObject,v2548)->isa,Language._Case))
       Result = gc_usage_star_list(GC_OBJECT(list,OBJECT(Case,v2548)->args),v332);
      else if (INHERIT(OBJECT(ClaireObject,v2548)->isa,Language._While))
       Result = gc_or_any(GC_OID(gc_usage_any(GC_OID(OBJECT(While,v2548)->arg),CTRUE)),GC_OID(gc_usage_any(GC_OID(OBJECT(While,v2548)->test),v332)));
      else if (INHERIT(OBJECT(ClaireObject,v2548)->isa,Language._Return))
       Result = gc_usage_any(GC_OID(OBJECT(Return,v2548)->arg),v332);
      else if (INHERIT(OBJECT(ClaireObject,v2548)->isa,Language._Handle))
       Result = gc_or_any(gc_or_any(GC_OID(gc_usage_any(GC_OID(OBJECT(ClaireHandle,v2548)->arg),v332)),GC_OID(gc_usage_any(GC_OID(OBJECT(ClaireHandle,v2548)->other),v332))),gc_usage_any(GC_OID(OBJECT(ClaireHandle,v2548)->test),v332));
      else Result = Kernel.cfalse;
        } 
    else Result = Kernel.cfalse;
      GC_UNBIND; return (Result);} 
  } 

OID  gc_or_any(OID v1744,OID v1745)
{ { OID Result = 0;
    if (v1744 == Kernel.cfalse)
     Result = v1745;
    else if (v1744 == Kernel.ctrue)
     { if (v1745 == Kernel.cfalse)
       Result = v1744;
      else Result = v1745;
        } 
    else if (INHERIT(OWNER(v1745),Kernel._integer))
     { if (equal(v1744,v1745) == CTRUE)
       Result = v1745;
      else Result = 1000;
        } 
    else Result = v1744;
      return (Result);} 
  } 

OID  gc_usage_star_list(list *v1732,ClaireBoolean *v332)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID Result = 0;
    { OID  v1744 = Kernel.cfalse;
      { OID gc_local;
        ITERATE(v1745);
        for (START(v1732); NEXT(v1745);)
        { GC_LOOP;
          GC__OID(v1744 = gc_or_any(v1744,gc_usage_any(v1745,v332)), 1);
          GC_UNLOOP;} 
        } 
      Result = v1744;
      } 
    GC_UNBIND; return (Result);} 
  } 

void  debug_intro_c_producer(Generate_c_producer *v1723,lambda *v2548,method *v1744)
{ GC_BIND;
  { module * v1733;
    { ClaireObject *V_CC ;
      if (Kernel._method == v1744->isa)
       V_CC = v1744->module_I;
      else V_CC = CFALSE;
        v1733= (module *) V_CC;} 
    int  v1734 = 1;
    princ_string(copy_string("DB_BIND("));
    ident_thing(v1733);
    princ_string(copy_string(","));
    expression_thing(v1744->selector,_oid_(Kernel.emptySet));
    princ_string(copy_string(","));
    princ_integer(v2548->vars->length);
    princ_string(copy_string(",{"));
    if ((v2548->vars->length == 1) && 
        ((*Kernel.range)((*(v2548->vars))[1]) == _oid_(Kernel._void)))
     princ_string(copy_string("PUSH(_oid_(ClEnv));"));
    else { OID gc_local;
        ITERATE(v1743);
        for (START(v2548->vars); NEXT(v1743);)
        { princ_string(copy_string("PUSH("));
          { OID  v1741 = (*(v1744->srange))[v1734];
            if (((v1741 == _oid_(Kernel._any)) && 
                  ((*Kernel.range)(v1743) != _oid_(Kernel._float))) || 
                (v1741 == _oid_(Kernel._integer)))
             (*Generate.expression)(v1743,
              Kernel.cfalse);
            else to_cl_c_producer(v1723,v1743,(((*Kernel.range)(v1743) == _oid_(Kernel._float)) ?
                Kernel._float :
                OBJECT(ClaireClass,v1741) ),Kernel.cfalse);
              } 
          princ_string(copy_string(");"));
          ++v1734;
          } 
        } 
      princ_string(copy_string("});"));
    breakline_void();
    princ_string(copy_string(""));
    } 
  GC_UNBIND;} 

char * protect_result_c_producer(Generate_c_producer *v1723,ClaireClass *v1741,ClaireBoolean *v6973,OID v1744)
{ GC_BIND;
  if (Optimize.compiler->safety > 5)
   { (Optimize.OPT->protection = CFALSE);
    v6973= CFALSE;
    (Optimize.OPT->loop_gc = CFALSE);
    } 
  { char *Result ;
    { char * v4806 = ((v1741 != Kernel._void) ?
        ((v6973 == CTRUE) ?
          copy_string("GC_UNBIND; return ") :
          copy_string("return ") ) :
        ((v6973 == CTRUE) ?
          copy_string("GC_UNBIND;") :
          copy_string("") ) );
      ClaireObject * v1733;
      if (need_debug_ask_any(v1744) == CTRUE)
       v1733 = OBJECT(method,v1744)->module_I;
      else v1733 = CFALSE;
        if (INHERIT(v1733->isa,Kernel._module))
       { print_in_string_void();
        princ_string(copy_string("DB_UNBIND("));
        ident_thing(((thing *) v1733));
        princ_string(copy_string(","));
        (*Generate.expression)(GC_OID((*Kernel.selector)(v1744)),
          _oid_(Kernel.emptySet));
        princ_string(copy_string(","));
        if (v1741 == Kernel._void)
         princ_string(copy_string("CNULL"));
        else if ((v1741 == Kernel._any) || 
            (v1741 == Kernel._integer))
         princ_string(copy_string("Result"));
        else to_cl_c_producer(v1723,GC_OID(_oid_(build_Variable_string(copy_string("Result"),_oid_(v1741)))),v1741,Core.nil->value);
          princ_string(copy_string(");"));
        breakline_void();
        princ_string(copy_string("  "));
        princ_string(v4806);
        princ_string(copy_string(""));
        Result = end_of_print_void();
        } 
      else Result = (((Optimize.OPT->profile_ask == CTRUE) && 
          ((Kernel._method == OWNER(v1744)) || 
              (v1744 == CNULL))) ?
        append_string(copy_string("PRend(PR_x);"),v4806) :
        v4806 );
      } 
    GC_UNBIND; return (Result);} 
  } 

void  generate_function_start_c_producer(Generate_c_producer *v1723,lambda *v2548,ClaireClass *v1741,OID v1733,char *v14127)
{ GC_BIND;
  { OID  v4517;
    { if (v2548->vars->length != 0)
       v4517 = (*Kernel.range)(GC_OID((*(v2548->vars))[1]));
      else v4517 = _oid_(Kernel._any);
        GC_OID(v4517);} 
    ClaireFunction * v2441 = make_function_string(v14127);
    list * v4658 = GC_OBJECT(list,(((v2548->vars->length == 1) && 
        ((v4517 == _oid_(Kernel._environment)) || 
            (v4517 == _oid_(Kernel._void)))) ?
      Kernel.nil :
      v2548->vars ));
    update_function_entry_c_producer(v1723,v2441,v4658,v1741);
    use_as_output_port(Optimize.OPT->outfile);
    if (Kernel._method == OWNER(v1733))
     { if ((OBJECT(restriction,v1733)->range == Kernel._float) || 
          (OBJECT(restriction,v1733)->domain->memq(_oid_(Kernel._float)) == CTRUE))
       generate_float_function_c_producer(v1723,OBJECT(method,v1733),string_I_function(v2441));
      else if (INHERIT(OBJECT(restriction,v1733)->range->isa,Kernel._tuple))
       generate_tuple_function_c_producer(v1723,OBJECT(method,v1733),string_I_function(v2441));
      } 
    generate_regular_function_c_producer(v1723,
      v2548,
      v2441,
      v1741,
      v1733,
      v4658);
    } 
  GC_UNBIND;} 

void  generate_regular_function_c_producer(Generate_c_producer *v1723,lambda *v2548,ClaireFunction *v2441,ClaireClass *v1741,OID v1733,list *v4658)
{ GC_BIND;
  if (Optimize.compiler->naming != 2)
   { princ_string(copy_string("\n/* The c++ function for: "));
    if (Kernel._method == OWNER(v1733))
     { print_any(_oid_(OBJECT(restriction,v1733)->selector));
      princ_string(copy_string("("));
      ppvariable_list(GC_OBJECT(list,v2548->vars));
      princ_string(copy_string(") ["));
      if (Optimize.compiler->naming == 1)
       bitvectorSum_integer(status_I_restriction(OBJECT(restriction,v1733)));
      princ_string(copy_string("]"));
      } 
    else princ_string(string_I_function(v2441));
      princ_string(copy_string(" */\n"));
    } 
  { interface_I_c_producer(v1723,v1741);
    princ_string(copy_string(" "));
    c_princ_function(v2441);
    princ_string(copy_string("("));
    typed_args_list_list(v4658);
    princ_string(copy_string(")\n"));
    } 
  GC_UNBIND;} 

void  generate_float_function_c_producer(Generate_c_producer *v1723,method *v1733,char *v14127)
{ GC_BIND;
  { list * v4640 = (((v1733->domain->length == 1) && 
        (domain_I_restriction(v1733) == Kernel._void)) ?
      Kernel.nil :
      v1733->domain );
    int  v1734 = v4640->length;
    list * v4658;
    { { bag *v_list; OID v_val;
        OID v1744,CLcount;
        v_list = v4640;
         v4658 = v_list->clone();
        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
        { v1744 = (*(v_list))[CLcount];
          { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
            (v2072->pname = gensym_void());
            { Variable * v6784 = v2072; 
              ClaireType * v6785;
              if (v1744 == _oid_(Kernel._float))
               v6785 = Kernel._any;
              else v6785 = OBJECT(ClaireType,v1744);
                (v6784->range = v6785);} 
            add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
            v_val = _oid_(v2072);
            } 
          
          (*((list *) v4658))[CLcount] = v_val;} 
        } 
      GC_OBJECT(list,v4658);} 
    char * v12048 = GC_STRING(append_string(v14127,copy_string("_")));
    ClaireFunction * v2441 = make_function_string(v12048);
    lambda * v2180 = GC_OBJECT(lambda,lambda_I_list(v4658,Core.nil->value));
    ClaireClass * v1741 = ((v1733->range == Kernel._float) ?
      Kernel._any :
      psort_any(_oid_(v1733->range)) );
    generate_regular_function_c_producer(v1723,
      v2180,
      v2441,
      v1741,
      _oid_(v1733),
      v4658);
    Optimize.OPT->functions->addFast(_oid_(list::alloc(3,_oid_(v2441),
      _oid_(v4658),
      _oid_(v1741))));
    new_block_void();
    if (v1741 != Kernel._void)
     princ_string(copy_string("return "));
    if (v1733->range == Kernel._float)
     princ_string(copy_string("_float_("));
    c_princ_function(OBJECT(ClaireFunction,(*Optimize.functional_I)(_oid_(v1733))));
    princ_string(copy_string("("));
    { int  v1729 = 1;
      int  v6783 = v1734;
      { OID gc_local;
        while ((v1729 <= v6783))
        { if (v1729 != 1)
           princ_string(copy_string(","));
          if ((*(v1733->domain))[v1729] == _oid_(Kernel._float))
           { princ_string(copy_string("float_v("));
            expression_Variable(OBJECT(Variable,(*(v4658))[v1729]),Core.nil->value);
            princ_string(copy_string(")"));
            } 
          else expression_Variable(OBJECT(Variable,(*(v4658))[v1729]),Core.nil->value);
            ++v1729;
          } 
        } 
      } 
    princ_string(copy_string(")"));
    if (v1733->range == Kernel._float)
     princ_string(copy_string(")"));
    princ_string(copy_string(";"));
    close_block_void();
    princ_string(copy_string("\n"));
    } 
  GC_UNBIND;} 

void  at_c_producer(Generate_c_producer *v1723)
{ princ_string("->");
  } 

void  generate_tuple_function_c_producer(Generate_c_producer *v1723,method *v1733,char *v14127)
{ GC_BIND;
  { list * v4640 = (((v1733->domain->length == 1) && 
        (domain_I_restriction(v1733) == Kernel._void)) ?
      Kernel.nil :
      v1733->domain );
    int  v1734 = v4640->length;
    list * v4658;
    { { bag *v_list; OID v_val;
        OID v1744,CLcount;
        v_list = v4640;
         v4658 = v_list->clone();
        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
        { v1744 = (*(v_list))[CLcount];
          { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
            (v2072->pname = gensym_void());
            (v2072->range = OBJECT(ClaireType,v1744));
            add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
            v_val = _oid_(v2072);
            } 
          
          (*((list *) v4658))[CLcount] = v_val;} 
        } 
      GC_OBJECT(list,v4658);} 
    char * v12048 = GC_STRING(append_string(v14127,copy_string("_")));
    ClaireFunction * v2441 = make_function_string(v12048);
    lambda * v2180 = GC_OBJECT(lambda,lambda_I_list(v4658,Core.nil->value));
    ClaireClass * v1741 = Kernel._tuple;
    generate_regular_function_c_producer(v1723,
      v2180,
      v2441,
      v1741,
      _oid_(v1733),
      v4658);
    Optimize.OPT->functions->addFast(_oid_(list::alloc(3,_oid_(v2441),
      _oid_(v4658),
      _oid_(v1741))));
    new_block_void();
    if (v1741 != Kernel._void)
     princ_string(copy_string("return "));
    c_princ_function(OBJECT(ClaireFunction,(*Optimize.functional_I)(_oid_(v1733))));
    princ_string(copy_string("("));
    { int  v1729 = 1;
      int  v6808 = v1734;
      { OID gc_local;
        while ((v1729 <= v6808))
        { if (v1729 != 1)
           princ_string(copy_string(","));
          expression_Variable(OBJECT(Variable,(*(v4658))[v1729]),Core.nil->value);
          ++v1729;
          } 
        } 
      } 
    princ_string(copy_string(")"));
    princ_string(copy_string("->copyIfNeeded()"));
    princ_string(copy_string(";"));
    close_block_void();
    princ_string(copy_string("\n"));
    } 
  GC_UNBIND;} 

OID  create_function_entry_c_producer(Generate_c_producer *v1723,lambda *v4638,char *v2441,OID v1733)
{ return (Core.nil->value);} 

OID  update_function_entry_c_producer(Generate_c_producer *v1723,ClaireFunction *v2441,list *v4658,ClaireClass *v1741)
{ Optimize.OPT->functions->addFast(_oid_(list::alloc(3,_oid_(v2441),
    _oid_(v4658),
    _oid_(v1741))));
  return (Kernel.cfalse);} 

char * c_interface_class1_Generate(ClaireClass *v2548)
{ { char *Result ;
    { int  v1734 = index_list(OBJECT(Generate_producer,Generate.PRODUCER->value)->interfaces,_oid_(v2548));
      Result = ((v1734 == 0) ?
        "OID *" :
        string_v((*(OBJECT(Generate_producer,Generate.PRODUCER->value)->interfaces))[(v1734+1)]) );
      } 
    return (Result);} 
  } 

void  c_interface_class2_Generate(ClaireClass *v2548,char *v1741)
{ { int  v1734 = index_list(OBJECT(Generate_producer,Generate.PRODUCER->value)->interfaces,_oid_(v2548));
    if (v1734 == 0)
     (OBJECT(Generate_producer,Generate.PRODUCER->value)->interfaces = OBJECT(Generate_producer,Generate.PRODUCER->value)->interfaces->addFast(_oid_(v2548))->addFast(_string_(v1741)));
    else ((*(OBJECT(Generate_producer,Generate.PRODUCER->value)->interfaces))[(v1734+1)]=_string_(v1741));
      } 
  } 

void  c_interface_method_Generate(method *v2548)
{ c_princ_string(string_v((*Optimize.function_name)(_oid_(v2548->selector),
    _oid_(v2548->domain),
    _oid_(v2548->functional))));
  } 

void  interface_I_c_producer(Generate_c_producer *v1723,ClaireClass *v2548)
{ if (v2548 == Kernel._void)
   princ_string(copy_string("void "));
  else if (v2548 == Kernel._integer)
   princ_string(copy_string("int "));
  else if ((v2548 == Kernel._function) || 
      ((v2548 == Kernel._char) || 
        (v2548 == Kernel._boolean)))
   { ident_c_producer(v1723,v2548->name);
    princ_string(copy_string(" *"));
    } 
  else if ((INHERIT(v2548,Kernel._cl_import)) || 
      ((v2548 == Kernel._string) || 
        (v2548 == Kernel._array)))
   princ_string(string_v((*Optimize.c_interface)(_oid_(v2548))));
  else if (INHERIT(v2548,Kernel._object))
   { class_princ_c_producer(v1723,v2548);
    princ_string(copy_string(" *"));
    } 
  else if (INHERIT(v2548,Kernel._bag))
   { ident_c_producer(v1723,v2548->name);
    princ_string(copy_string(" *"));
    } 
  else if (v2548 == Kernel._float)
   princ_string(copy_string("double "));
  else princ_string(copy_string("OID "));
    } 

void  to_cl_c_producer(Generate_c_producer *v1723,OID v1744,ClaireClass *v1741,OID v332)
{ if (v1741 == Kernel._void)
   { princ_string(copy_string("_void_("));
    (*Generate.expression)(v1744,
      v332);
    princ_string(copy_string(")"));
    } 
  else if (INHERIT(v1741,Kernel._object))
   { if (v1744 == Kernel.ctrue)
     princ_string(copy_string("Kernel.ctrue"));
    else if (v1744 == Kernel.cfalse)
     princ_string(copy_string("Kernel.cfalse"));
    else { princ_string(copy_string("_oid_("));
        (*Generate.expression)(v1744,
          v332);
        princ_string(copy_string(")"));
        } 
      } 
  else if (v1741 == Kernel._integer)
   { if (Optimize.compiler->safety > 1)
     (*Generate.expression)(v1744,
      v332);
    else { princ_string(copy_string("_integer_("));
        (*Generate.expression)(v1744,
          v332);
        princ_string(copy_string(")"));
        } 
      } 
  else if (v1741 == Kernel._char)
   { princ_string(copy_string("_oid_("));
    (*Generate.expression)(v1744,
      v332);
    princ_string(copy_string(")"));
    } 
  else if (v1741 == Kernel._string)
   { princ_string(copy_string("_string_("));
    (*Generate.expression)(v1744,
      v332);
    princ_string(copy_string(")"));
    } 
  else if (v1741 == Kernel._array)
   { princ_string(copy_string("_array_("));
    (*Generate.expression)(v1744,
      v332);
    princ_string(copy_string(")"));
    } 
  else if (v1741 == Kernel._float)
   { princ_string(copy_string("_float_("));
    (*Generate.expression)(v1744,
      v332);
    princ_string(copy_string(")"));
    } 
  else if (INHERIT(v1741,Kernel._cl_import))
   { princ_string(copy_string("ClAlloc->import("));
    expression_any(_oid_(v1741),_oid_(Kernel.emptySet));
    princ_string(copy_string(",(int *) "));
    (*Generate.expression)(v1744,
      v332);
    princ_string(copy_string(")"));
    } 
  else if (v1741 == Kernel._any)
   (*Generate.expression)(v1744,
    v332);
  else close_exception(((general_error *) (*Core._general_error)(_string_(copy_string("[internal] to_cl for a ~S is not implemented")),
      _oid_(list::alloc(1,_oid_(v1741))))));
    } 

void  to_c_c_producer1(Generate_c_producer *v1723,OID v1744,ClaireClass *v1741,OID v332)
{ if (v1741 == Kernel._integer)
   (*Generate.expression)(v1744,
    v332);
  else if (v1744 == CNULL)
   princ_string(copy_string("NULL"));
  else if ((INHERIT(OWNER(v1744),Core._global_variable)) && 
      ((equal((*Kernel.range)(v1744),_oid_(Kernel.emptySet)) == CTRUE) && 
        (equal((*Kernel.value)(v1744),Core.nil->value) == CTRUE)))
   princ_string(copy_string("Kernel.nil"));
  else { to_c_c_producer2(v1723,v1741);
      (*Generate.expression)(v1744,
        v332);
      princ_string(copy_string(")"));
      } 
    } 

void  to_c_c_producer2(Generate_c_producer *v1723,ClaireClass *v1741)
{ if (INHERIT(v1741,Kernel._object))
   { princ_string(copy_string("OBJECT("));
    class_princ_class(v1741);
    princ_string(copy_string(","));
    } 
  else if (v1741 == Kernel._float)
   princ_string(copy_string("float_v("));
  else if (v1741 == Kernel._char)
   princ_string(copy_string("char_v("));
  else if (v1741 == Kernel._string)
   princ_string(copy_string("string_v("));
  else if (v1741 == Kernel._array)
   princ_string(copy_string("array_v("));
  else if (INHERIT(v1741,Kernel._cl_import))
   { princ_string(copy_string("EXPORT(("));
    interface_I_class(v1741);
    princ_string(copy_string("),"));
    } 
  else close_exception(((general_error *) (*Core._general_error)(_string_(copy_string("[internal] to_c for a ~S is not implemented")),
      _oid_(list::alloc(1,_oid_(v1741))))));
    } 

void  public_static_c_producer(Generate_c_producer *v1723)
{ ;} 

void  bool_exp_I_c_producer(Generate_c_producer *v1723,OID v2548,OID v332)
{ if (INHERIT(OWNER(v2548),Optimize._to_CL))
   { princ_string(copy_string("("));
    (*Optimize.bool_exp)(v2548,
      Kernel.ctrue,
      v332);
    princ_string(copy_string(" ? Kernel.ctrue : Kernel.cfalse)"));
    } 
  else { princ_string(copy_string("("));
      (*Optimize.bool_exp)(v2548,
        Kernel.ctrue,
        v332);
      princ_string(copy_string(" ? CTRUE : CFALSE)"));
      } 
    } 

void  inherit_exp_c_producer(Generate_c_producer *v1723,OID v4249,OID v4250,OID v332)
{ princ_string("INHERIT(");
  (*Generate.expression)(v4249,
    v332);
  princ_string(",");
  (*Generate.expression)(v4250,
    v332);
  princ_string(")");
  } 

void  bitvector_exp_c_producer(Generate_c_producer *v1723,OID v4249,OID v4250,OID v332)
{ princ_string("BCONTAIN(");
  (*Generate.expression)(v4249,
    v332);
  princ_string(",");
  (*Generate.expression)(v4250,
    v332);
  princ_string(")");
  } 

void  equal_exp_c_producer(Generate_c_producer *v1723,OID v4249,ClaireBoolean *v4883,OID v4250,OID v9948)
{ GC_BIND;
  if ((INHERIT(OWNER(v4249),Optimize._to_CL)) && 
      ((INHERIT(OWNER(v4250),Optimize._to_CL)) && 
        ((osort_any(GC_OID((*Language.set_arg)(v4249))) == osort_any(GC_OID((*Language.set_arg)(v4250)))) && 
          ((identifiable_ask_any(GC_OID((*Kernel.arg)(v4249))) == CTRUE) || 
              ((identifiable_ask_any(GC_OID((*Kernel.arg)(v4250))) == CTRUE) || 
                (((*Language.set_arg)(v4249) == _oid_(Kernel._string)) || 
                  ((*Language.set_arg)(v4249) == _oid_(Kernel._float))))))))
   equal_exp_c_producer(v1723,
    GC_OID((*Kernel.arg)(v4249)),
    v4883,
    GC_OID((*Kernel.arg)(v4250)),
    Kernel.ctrue);
  else if ((INHERIT(OWNER(v4249),Optimize._to_protect)) && 
      ((INHERIT(owner_any((*Kernel.arg)(v4249)),Optimize._to_CL)) && 
        (((*Optimize.c_gc_ask)(GC_OID((*Kernel.arg)(GC_OID((*Kernel.arg)(v4249))))) != Kernel.ctrue) && 
          ((INHERIT(OWNER(v4250),Optimize._to_protect)) && 
            ((INHERIT(owner_any((*Kernel.arg)(v4250)),Optimize._to_CL)) && 
              ((*Optimize.c_gc_ask)(GC_OID((*Kernel.arg)(GC_OID((*Kernel.arg)(v4250))))) != Kernel.ctrue))))))
   equal_exp_c_producer(v1723,
    GC_OID((*Kernel.arg)(v4249)),
    v4883,
    GC_OID((*Kernel.arg)(v4250)),
    v9948);
  else { ClaireBoolean * g0072I;
    { ClaireBoolean *v_and;
      { v_and = (((*Optimize.c_sort)(v4249) == _oid_(Kernel._string)) ? CTRUE : CFALSE);
        if (v_and == CFALSE) g0072I =CFALSE; 
        else { v_and = (((*Optimize.c_sort)(v4250) == _oid_(Kernel._string)) ? CTRUE : CFALSE);
          if (v_and == CFALSE) g0072I =CFALSE; 
          else { { OID  v10875;
              if (INHERIT(OWNER(v4250),Optimize._to_C))
               v10875 = ((OBJECT(Compile_to_C,v4250)->arg == CNULL) ? Kernel.ctrue : Kernel.cfalse);
              else v10875 = Kernel.cfalse;
                v_and = not_any(v10875);
              } 
            if (v_and == CFALSE) g0072I =CFALSE; 
            else g0072I = CTRUE;} 
          } 
        } 
      } 
    
    if (g0072I == CTRUE) { princ_string(copy_string("(equal_string("));
        (*Generate.expression)(v4249,
          Core.nil->value);
        princ_string(copy_string(","));
        (*Generate.expression)(v4250,
          Core.nil->value);
        princ_string(copy_string(") "));
        sign_equal_boolean(v4883);
        princ_string(copy_string(" CTRUE)"));
        } 
      else if ((INHERIT(OWNER(v4249),Optimize._to_CL)) && 
        (((*Language.set_arg)(v4249) != _oid_(Kernel._integer)) && 
          (v4250 == CNULL)))
     { princ_string(copy_string("("));
      (*Generate.expression)(GC_OID((*Kernel.arg)(v4249)),
        Core.nil->value);
      princ_string(copy_string(" "));
      sign_equal_boolean(v4883);
      princ_string(copy_string(" NULL)"));
      } 
    else if ((char_exp_ask_c_producer2(v1723,v4249) == CTRUE) || 
        (char_exp_ask_c_producer2(v1723,v4250) == CTRUE))
     { princ_string(copy_string("("));
      char_exp_c_producer2(v1723,v4249,Core.nil->value);
      princ_string(copy_string(" "));
      sign_equal_boolean(v4883);
      princ_string(copy_string(" "));
      char_exp_c_producer2(v1723,v4250,Core.nil->value);
      princ_string(copy_string(")"));
      } 
    else if ((boolean_I_any(v9948) == CTRUE) || 
        ((identifiable_ask_any(v4249) == CTRUE) || 
          ((identifiable_ask_any(v4250) == CTRUE) || 
            ((*Optimize.c_sort)(v4249) == _oid_(Kernel._float)))))
     { if (equal(_oid_(glb_class(stupid_t_any1(v4249),stupid_t_any1(v4250))),_oid_(Kernel.emptySet)) == CTRUE)
       { warn_void();
        tformat_string(copy_string("~S = ~S will fail ! [263]"),2,list::alloc(2,v4249,v4250));
        } 
      princ_string(copy_string("("));
      bexpression_any(v4249,Core.nil->value);
      princ_string(copy_string(" "));
      sign_equal_boolean(v4883);
      princ_string(copy_string(" "));
      bexpression_any(v4250,Core.nil->value);
      princ_string(copy_string(")"));
      } 
    else { princ_string(copy_string("(equal("));
        (*Generate.expression)(v4249,
          Core.nil->value);
        princ_string(copy_string(","));
        (*Generate.expression)(v4250,
          Core.nil->value);
        princ_string(copy_string(") "));
        sign_equal_boolean(v4883);
        princ_string(copy_string(" CTRUE)"));
        } 
      } 
  GC_UNBIND;} 

ClaireBoolean * char_exp_ask_c_producer2(Generate_c_producer *v1723,OID v1744)
{ { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v1744),Kernel._char))
     Result = CTRUE;
    else if (INHERIT(OWNER(v1744),Language._Call_method))
     { method * v1733 = OBJECT(Call_method,v1744)->arg;
      Result = ((_oid_(v1733) == Generate._starnth_1_string_star->value) ? CTRUE : (((_oid_(v1733) == Generate._starnth_string_star->value) && 
          (2 <= Optimize.compiler->safety)) ? CTRUE : CFALSE));
      } 
    else Result = CFALSE;
      return (Result);} 
  } 

void  char_exp_c_producer2(Generate_c_producer *v1723,OID v1744,OID v332)
{ GC_BIND;
  if (INHERIT(OWNER(v1744),Kernel._char))
   { princ_string(copy_string("'"));
    if ((v1744 == _oid_(_char_('\"'))) || 
        ((v1744 == _oid_(_char_('\''))) || 
          ((v1744 == _oid_(_char_('\?'))) || 
            (v1744 == _oid_(_char_('\\'))))))
     princ_string(copy_string("\\"));
    princ_char(OBJECT(ClaireChar,v1744));
    princ_string(copy_string("'"));
    } 
  else if (INHERIT(OWNER(v1744),Language._Call_method))
   { method * v1733 = OBJECT(Call_method,v1744)->arg;
    if ((_oid_(v1733) == Generate._starnth_1_string_star->value) || 
        (_oid_(v1733) == Generate._starnth_string_star->value))
     { OID  v4249 = (*(OBJECT(Call_method,v1744)->args))[1];
      OID  v4250 = (*(OBJECT(Call_method,v1744)->args))[2];
      (*Generate.expression)(v4249,
        v332);
      princ_string(copy_string("["));
      (*Generate.expression)(v4250,
        v332);
      princ_string(copy_string(" - 1]"));
      } 
    else { princ_string(copy_string("((char) "));
        (*Generate.expression)(v1744,
          v332);
        princ_string(copy_string("->ascii)"));
        } 
      } 
  else { princ_string(copy_string("((char) "));
      (*Generate.expression)(v1744,
        v332);
      princ_string(copy_string("->ascii)"));
      } 
    GC_UNBIND;} 

void  c_member_c_producer(Generate_c_producer *v1723,OID v2548,ClaireClass *v1741,property *v1744,OID v332)
{ if (INHERIT(stupid_t_any1(v2548),v1741))
   { (*Generate.expression)(v2548,
      v332);
    princ_string(copy_string("->"));
    ident_symbol(v1744->name);
    princ_string(copy_string(""));
    } 
  else { princ_string(copy_string("CLREAD("));
      class_princ_class(v1741);
      princ_string(copy_string(","));
      (*Generate.expression)(v2548,
        v332);
      princ_string(copy_string(","));
      ident_symbol(v1744->name);
      princ_string(copy_string(")"));
      } 
    } 

void  addFast_c_producer(Generate_c_producer *v1723)
{ princ_string("->addFast");
  } 

void  cast_I_c_producer(Generate_c_producer *v1723,Compile_C_cast *v2548,OID v332)
{ GC_BIND;
  princ_string("((");
  class_princ_class(v2548->set_arg);
  princ_string(" *) ");
  (*Generate.expression)(v2548->arg,
    v332);
  princ_string(")");
  GC_UNBIND;} 

void  gc_protection_exp_c_producer(Generate_c_producer *v1723,Variable *v1743,ClaireBoolean *v13418,OID v1742,OID v332)
{ GC_BIND;
  (v1723->stat = (v1723->stat+1));
  if ((osort_any(GC_OID(_oid_(v1743->range))) == Kernel._float) || 
      (osort_any(GC_OID(_oid_(v1743->range))) == Kernel._integer))
   { princ_string(copy_string("("));
    ident_c_producer3(v1723,v1743);
    princ_string(copy_string("="));
    if (v13418 == CTRUE)
     (*Generate.expression)(v1742,
      v332);
    else c_princ_string(string_v(v1742));
      princ_string(copy_string(")"));
    } 
  else { princ_string(copy_string("GC__"));
      princ_string(((osort_any(GC_OID(_oid_(v1743->range))) == Kernel._any) ?
        copy_string("OID") :
        ((osort_any(GC_OID(_oid_(v1743->range))) == Kernel._string) ?
          copy_string("STRING") :
          copy_string("ANY") ) ));
      princ_string(copy_string("("));
      ident_c_producer3(v1723,v1743);
      if (v1742 != _oid_(v1743))
       { princ_string(copy_string(" = "));
        if (v13418 == CTRUE)
         (*Generate.expression)(v1742,
          v332);
        else c_princ_string(string_v(v1742));
          } 
      princ_string(copy_string(", "));
      princ_integer(((Optimize.OPT->loop_index == 0) ?
        1 :
        (v1743->index+1) ));
      princ_string(copy_string(")"));
      } 
    GC_UNBIND;} 

void  bag_expression_c_producer(Generate_c_producer *v4381,ClaireClass *v1723,bag *v1732,ClaireType *v1740,OID v332)
{ GC_BIND;
  if (v1732->length == 0)
   { print_any(_oid_(v1723));
    princ_string(copy_string("::empty("));
    if (v1740 != Kernel._void)
     { (*Generate.expression)(GC_OID((*Optimize.c_code)(_oid_(v1740),
          _oid_(Kernel._object))),
        v332);
      } 
    princ_string(copy_string(")"));
    } 
  else { print_any(_oid_(v1723));
      princ_string(copy_string("::alloc"));
      if ((v1723 == Kernel._tuple) && 
          (Optimize.OPT->alloc_stack == CTRUE))
       princ_string(copy_string("Stack"));
      princ_string(copy_string("("));
      if (v1740 != Kernel._void)
       { (*Generate.expression)(GC_OID((*Optimize.c_code)(_oid_(v1740),
            _oid_(Kernel._object))),
          v332);
        princ_string(copy_string(","));
        } 
      princ_integer(v1732->length);
      princ_string(copy_string(","));
      args_list_bag(v1732,v332,_sup_integer(v1732->length,2));
      princ_string(copy_string(")"));
      } 
    GC_UNBIND;} 

void  generate_s_file_string(char *v2548,list *v1732,OID v1733)
{ GC_BIND;
  { ClairePort * v1736 = fopen_string(append_string(GC_STRING(append_string(GC_STRING(_7_string(GC_STRING(Optimize.compiler->source),v2548)),copy_string("-s"))),GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),copy_string("w"));
    list * v14424 = GC_OBJECT(list,add_modules_list(v1732));
    list * v13204 = GC_OBJECT(list,parents_list(v1732));
    (Optimize.OPT->cinterface = v1736);
    (Optimize.OPT->properties = set::empty(Kernel._property));
    (Optimize.OPT->objects = list::empty(Kernel._any));
    (Optimize.OPT->functions = list::empty(Kernel._any));
    (Optimize.OPT->need_to_close = set::empty(Kernel._any));
    (Optimize.OPT->legal_modules = set_I_bag(v13204));
    use_as_output_port(v1736);
    princ_string(copy_string("// --- System configuration file for "));
    print_any(_string_(v2548));
    princ_string(copy_string(" , ["));
    print_any(_string_(date_I_integer(1)));
    princ_string(copy_string("] ---\n\n"));
    princ_string(copy_string("#include <claire.h>\n"));
    princ_string(copy_string("#include <Kernel.h>\n"));
    { ITERATE(v1744);
      for (START(v14424); NEXT(v1744);)
      if (OBJECT(module,v1744)->made_of->length != 0)
       { princ_string(copy_string("#include <"));
        ident_symbol(OBJECT(symbol,(*Kernel.name)(v1744)));
        princ_string(copy_string(".h>\n"));
        } 
      } 
    create_load_modules_string(v2548,v1736,v13204,v1733);
    if ((boolean_I_any(_oid_(_at_property1(Core.main,Kernel._list))) == CTRUE) && 
        (domain_I_restriction(GC_OBJECT(restriction,((restriction *) _at_property1(Core.main,Kernel._list)))) == Kernel._list))
     { char * v1741 = copy_string("main_list");
      princ_string(copy_string("\nextern void "));
      princ_string(v1741);
      princ_string(copy_string("(list *l);\n"));
      princ_string(copy_string("void call_main() {"));
      princ_string(v1741);
      princ_string(copy_string("(ClEnv->params);}\n"));
      } 
    else princ_string(copy_string("\nvoid call_main() {default_main();}\n"));
      fclose_port(v1736);
    } 
  GC_UNBIND;} 

void  create_load_modules_string(char *v2548,ClairePort *v1736,list *v13204,OID v1733)
{ GC_BIND;
  breakline_void();
  { OID gc_local;
    ITERATE(v1744);
    for (START(v13204); NEXT(v1744);)
    if ((*Kernel.status)(v1744) == 5)
     { princ_string(copy_string("void load_"));
      ident_symbol(OBJECT(symbol,(*Kernel.name)(v1744)));
      princ_string(copy_string("() {"));
      ident_symbol(OBJECT(symbol,(*Kernel.name)(v1744)));
      princ_string(copy_string(".metaLoad();}\n"));
      } 
    } 
  princ_string(copy_string("\n\nvoid loadModules() \n"));
  new_block_void();
  princ_string(copy_string("//module definitions "));
  breakline_void();
  princ_string(copy_string(""));
  { OID gc_local;
    ITERATE(v1744);
    bag *v1744_support;
    v1744_support = GC_OBJECT(set,_backslash_type(v13204,GC_OBJECT(set,set::alloc(Kernel.emptySet,3,_oid_(claire.it),
      _oid_(mClaire.it),
      _oid_(Kernel.it)))));
    for (START(v1744_support); NEXT(v1744);)
    { GC_LOOP;
      { ident_symbol(OBJECT(symbol,(*Kernel.name)(v1744)));
        princ_string(copy_string(".initModule("));
        print_any(_string_(string_I_symbol(OBJECT(symbol,(*Kernel.name)(v1744)))));
        princ_string(copy_string(","));
        expression_thing(OBJECT(module,v1744)->part_of,Core.nil->value);
        princ_string(copy_string(","));
        (*Generate.expression)(GC_OID((*Optimize.c_code)(GC_OID(_oid_(OBJECT(module,v1744)->uses)),
            _oid_(Kernel._list))),
          Core.nil->value);
        princ_string(copy_string(","));
        breakline_void();
        print_any(GC_OID((*Kernel.source)(v1744)));
        princ_string(copy_string(","));
        (*Generate.expression)(GC_OID((*Optimize.c_code)(GC_OID(_oid_(OBJECT(module,v1744)->made_of)),
            _oid_(Kernel._list))),
          Core.nil->value);
        princ_string(copy_string(");"));
        breakline_void();
        princ_string(copy_string(""));
        } 
      GC_UNLOOP;} 
    } 
  princ_string(copy_string("//module load "));
  breakline_void();
  princ_string(copy_string(""));
  { OID gc_local;
    ITERATE(v1744);
    for (START(v13204); NEXT(v1744);)
    if ((OBJECT(module,v1744)->made_of->length != 0) && 
        ((*Kernel.status)(v1744) != 5))
     { ident_symbol(OBJECT(symbol,(*Kernel.name)(v1744)));
      princ_string(copy_string(".metaLoad();"));
      breakline_void();
      princ_string(copy_string(""));
      } 
    } 
  { OID gc_local;
    ITERATE(v1744);
    for (START(v13204); NEXT(v1744);)
    if ((*Kernel.status)(v1744) == 5)
     { ident_symbol(OBJECT(symbol,(*Kernel.name)(v1744)));
      princ_string(copy_string(".it->evaluate = "));
      expression_any(_oid_(make_function_string(append_string(copy_string("load_"),string_I_symbol(OBJECT(symbol,(*Kernel.name)(v1744)))))),Kernel.cfalse);
      breakline_void();
      princ_string(copy_string(""));
      ident_symbol(OBJECT(symbol,(*Kernel.name)(v1744)));
      princ_string(copy_string(".it->status = 2;"));
      breakline_void();
      princ_string(copy_string(""));
      } 
    } 
  princ_string(copy_string("ClEnv->module_I = "));
  { OID  v12797;
    if (INHERIT(OWNER(v1733),Kernel._module))
     v12797 = v1733;
    else v12797 = _oid_(claire.it);
      (*Generate.expression)(v12797,
      Core.nil->value);
    } 
  princ_string(copy_string("; "));
  breakline_void();
  princ_string(copy_string(""));
  if (Optimize.compiler->safety > 5)
   princ_string(copy_string("ClAlloc->statusGC = 2;\n"));
  if (Optimize.OPT->profile_ask == CTRUE)
   { OID gc_local;
    ITERATE(v1736);
    for (START(Reader.PRdependent->graph); NEXT(v1736);)
    { GC_LOOP;
      if (INHERIT(OWNER(v1736),Kernel._property))
       { OID gc_local;
        ITERATE(v4714);
        bag *v4714_support;
        v4714_support = GC_OBJECT(set,OBJECT(bag,nth_table1(Reader.PRdependent,v1736)));
        for (START(v4714_support); NEXT(v4714);)
        if ((contain_ask_set(Optimize.OPT->to_remove,v4714) != CTRUE) && 
            (OBJECT(thing,v1736)->name->definition == OBJECT(thing,v4714)->name->definition))
         { princ_string(copy_string("PRdepends_property("));
          expression_thing(OBJECT(thing,v1736),Core.nil->value);
          princ_string(copy_string(","));
          expression_thing(OBJECT(thing,v4714),Core.nil->value);
          princ_string(copy_string(");\n"));
          } 
        } 
      GC_UNLOOP;} 
    } 
  close_block_void();
  GC_UNBIND;} 

void  methods_interface_c_producer(Generate_c_producer *v1723,ClaireClass *v1744)
{ GC_RESERVE(6);  // v3.0.55 optim !
  { OID gc_local;
    ITERATE(v1736);
    bag *v1736_support;
    v1736_support = GC_OBJECT(list,OBJECT(bag,nth_table1(Language.InterfaceList,_oid_(v1744))));
    for (START(v1736_support); NEXT(v1736);)
    { GC_LOOP;
      { ClaireObject * v1733 = GC_OBJECT(ClaireObject,_at_property1(OBJECT(property,v1736),v1744));
        if ((Kernel._method == v1733->isa) && 
            (get_property(Kernel.formula,v1733) != CNULL))
         { ClaireClass * v1741 = class_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.range)(_oid_(v1733)))));
          list * v7721 = GC_OBJECT(list,cdr_list(OBJECT(lambda,(*Kernel.formula)(_oid_(v1733)))->vars));
          breakline_void();
          interface_I_c_producer(v1723,v1741);
          princ_string(copy_string(" "));
          (*Kernel.c_princ)(GC_OID((*Kernel.name)(v1736)));
          princ_string(copy_string("("));
          typed_args_list_list(v7721);
          princ_string(copy_string(");  "));
          } 
        } 
      GC_UNLOOP;} 
    } 
  GC_UNBIND;} 

void  methods_bodies_c_producer(Generate_c_producer *v1723,ClaireClass *v1744)
{ GC_RESERVE(6);  // v3.0.55 optim !
  { OID gc_local;
    ITERATE(v1736);
    bag *v1736_support;
    v1736_support = GC_OBJECT(list,OBJECT(bag,nth_table1(Language.InterfaceList,_oid_(v1744))));
    for (START(v1736_support); NEXT(v1736);)
    { GC_LOOP;
      { ClaireObject * v1733 = GC_OBJECT(ClaireObject,_at_property1(OBJECT(property,v1736),v1744));
        if ((Kernel._method == v1733->isa) && 
            (get_property(Kernel.formula,v1733) != CNULL))
         { ClaireClass * v1741 = class_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.range)(_oid_(v1733)))));
          list * v7721 = GC_OBJECT(list,cdr_list(OBJECT(lambda,(*Kernel.formula)(_oid_(v1733)))->vars));
          breakline_void();
          princ_string(copy_string("// interface method "));
          breakline_void();
          princ_string(copy_string(""));
          breakline_void();
          interface_I_c_producer(v1723,v1741);
          princ_string(copy_string(" "));
          class_princ_class(v1744);
          princ_string(copy_string("::"));
          (*Kernel.c_princ)(GC_OID((*Kernel.name)(v1736)));
          princ_string(copy_string("("));
          typed_args_list_list(v7721);
          princ_string(copy_string(")"));
          breakline_void();
          princ_string(copy_string("  "));
          princ_string(copy_string("\t{ "));
          if (v1741 != Kernel._void)
           { princ_string(copy_string("return ("));
            interface_I_c_producer(v1723,v1741);
            princ_string(copy_string(") "));
            } 
          if ((OBJECT(ClaireBoolean,(*Kernel._sup)(GC_OID((*Kernel.dispatcher)(v1736)),
            0))) == CTRUE)
           { (*Generate.expression)(v1736,
              Core.nil->value);
            princ_string(copy_string("->fcall((int) this"));
            { OID gc_local;
              ITERATE(v1743);
              for (START(v7721); NEXT(v1743);)
              { princ_string(copy_string(",(int) "));
                (*Generate.expression)(v1743,
                  Core.nil->value);
                } 
              } 
            princ_string(copy_string(")"));
            } 
          else { c_princ_function(OBJECT(ClaireFunction,(*Optimize.functional_I)(_oid_(v1733))));
              princ_string(copy_string("(this"));
              { OID gc_local;
                ITERATE(v1743);
                for (START(v7721); NEXT(v1743);)
                { princ_string(copy_string(","));
                  (*Generate.expression)(v1743,
                    Core.nil->value);
                  } 
                } 
              princ_string(copy_string(")"));
              } 
            princ_string(copy_string(";}\n"));
          breakline_void();
          princ_string(copy_string(""));
          } 
        } 
      GC_UNLOOP;} 
    } 
  GC_UNBIND;} 

