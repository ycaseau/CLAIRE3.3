// interface defination for module Generate, Sun Feb 15 15:37:28 2009
#ifndef CLAIREH_Generate
#define CLAIREH_Generate


class Generate_producer;
class Generate_c_producer;

class Generate_producer: public thing{ 
  public:
     list *open_comparators;
     list *open_operators;
     OID body;
     char *extension;
     char *comment;
     list *interfaces;
     int stat;} 
;

class Generate_c_producer: public Generate_producer{ 
  public:
     list *bad_names;
     list *good_names;} 
;
extern void  ident_symbol(symbol *v2548);
extern void  ident_thing(thing *v2548);
extern void  ident_class(ClaireClass *v2548);
extern void  interface_I_class(ClaireClass *v1723);
extern void  class_princ_class(ClaireClass *v1723);
extern OID  indent_c_void();
extern OID  breakline_void();
extern void  new_block_void();
extern void  close_block_void();
extern void  c_test_any(OID v1744);
extern void  c_test_method(method *v1733);
extern void  compile_module(module *v2548);
extern void  generate_files_module(module *v2548);
extern void  generate_f2f_module(module *v1733);
extern void  generate_file_string1(char *v1741,module *v1733);
extern void  generate_classes_module(module *v2548);
extern void  generate_c2f_module(module *v2548);
extern void  generate_interface_module(module *v2548,bag *v1732);
extern void  generate_objects_module(module *v2548);
extern void  generate_meta_load_module(module *v2548);
extern ClaireBoolean * global_var_def_ask_any(OID v1744);
extern ClaireClass * getRange_global_variable(global_variable *v1744);
extern void  generate_functions_module(module *v2548);
extern list * parents_module(module *v2548,list *v1732);
extern list * parents_list(list *v2548);
extern void  get_module2(module *v1733);
extern void  generate_file_string2(char *v2548,char *v4404);
extern OID  make_c_function_lambda_Generate(lambda *v2548,char *v14127,OID v1733);
extern OID  print_c_function_lambda2(lambda *v2548,char *v14127,OID v1733);
extern void  print_body_If(If *v14751,char *v5438,ClaireClass *v1741,If *v846,ClaireBoolean *v9217);
extern void  print_body_any(OID v14751,char *v5438,ClaireClass *v1741,OID v846,ClaireBoolean *v9217);
extern OID  print_body_Do(Do *v14751,char *v5438,ClaireClass *v1741,OID v846,ClaireBoolean *v9217);
extern void  outer_statement_any(OID v14751,char *v5438,ClaireClass *v1741,ClaireBoolean *v9217);
extern ClaireBoolean * c_safe_any(OID v1744);
extern ClaireClass * check_sort_method(method *v2548);
extern OID  typed_args_list_list(list *v2548);
extern ClaireBoolean * need_debug_ask_any(OID v1733);
extern void  get_dependents_method(method *v1733);
extern void  c_princ_function(ClaireFunction *v2548);
extern void  set_outfile_lambda(lambda *v2548);
extern ClaireBoolean * c_func_any(OID v2548);
extern void  expression_thing(thing *v2548,OID v332);
extern void  expression_integer(int v2548,OID v332);
extern void  expression_any(OID v2548,OID v332);
extern void  expression_string(char *v2548,OID v332);
extern void  expression_float(double v2548,OID v332);
extern void  expression_float_(OID v6626,OID v6627);
extern void  expression_boolean(ClaireBoolean *v2548,OID v332);
extern void  expression_environment(ClaireEnvironment *v2548,OID v332);
extern void  expression_Variable(Variable *v2548,OID v332);
extern void  expression_global_variable(global_variable *v2548,OID v332);
extern void  expression_Set(Set *v2548,OID v332);
extern void  expression_set2(set *v2548,OID v332);
extern void  expression_Tuple(Tuple *v2548,OID v332);
extern void  expression_tuple(tuple *v2548,OID v332);
extern void  expression_List(List *v2548,OID v332);
extern void  expression_list(list *v2548,OID v332);
extern void  expression_Call2(Call *v2548,OID v332);
extern void  expression_Call_method12(Call_method1 *v2548,OID v332);
extern void  expression_Call_method22(Call_method2 *v2548,OID v332);
extern void  expression_Call_method2(Call_method *v2548,OID v332);
extern void  bexpression_any(OID v2548,OID v332);
extern void  expression_If(If *v2548,OID v332);
extern void  expression_Assign(Assign *v2548,OID v332);
extern void  expression_to_protect(Compile_to_protect *v2548,OID v332);
extern char * gc_protect_class(ClaireClass *v1723);
extern void  expression_Gassign(Gassign *v2548,OID v332);
extern void  expression_And(And *v2548,OID v332);
extern void  expression_Or(Or *v2548,OID v332);
extern void  expression_to_CL(Compile_to_CL *v2548,OID v332);
extern void  expression_to_C(Compile_to_C *v2548,OID v332);
extern void  expression_C_cast(Compile_C_cast *v2548,OID v332);
extern void  expression_Call_slot(Call_slot *v2548,OID v332);
extern void  expression_Call_table(Call_table *v2548,OID v332);
extern void  expression_Call_array(Call_array *v2548,OID v332);
extern void  expression_Update(Update *v2548,OID v332);
extern void  sign_equal_boolean(ClaireBoolean *v2548);
extern void  sign_or_boolean(ClaireBoolean *v2548);
extern void  bool_exp_any_Generate(OID v2548,ClaireBoolean *v4883,OID v332);
extern void  any_bool_exp_any(OID v2548,ClaireBoolean *v4883,OID v332,ClaireBoolean *v13798);
extern void  bool_exp_to_CL_Generate(Compile_to_CL *v2548,ClaireBoolean *v4883,OID v332);
extern void  bool_exp_If_Generate(If *v2548,ClaireBoolean *v4883,OID v332);
extern void  bool_exp_And_Generate(And *v2548,ClaireBoolean *v4883,OID v332);
extern void  bool_exp_Or_Generate(Or *v2548,ClaireBoolean *v4883,OID v332);
extern void  bool_exp_Call_method1_Generate(Call_method1 *v2548,ClaireBoolean *v4883,OID v332);
extern void  bool_exp_Call_method2_Generate(Call_method2 *v2548,ClaireBoolean *v4883,OID v332);
extern ClaireBoolean * bool_exp_ask_any(OID v1744);
extern void  args_list_bag(bag *v2548,OID v332,ClaireBoolean *v3438);
extern char * check_var_string(char *v2548,OID v1741,OID v332);
extern Variable * build_Variable_string(char *v1741,OID v1740);
extern list * unfold_args_list(list *v1732);
extern ClaireType * c_type_sort_any(OID v1744);
extern OID  unfold_arg_list(list *v1732,list *v4640,OID v1744);
extern void  unfold_use_list(list *v5825,OID v1744,OID v1741,OID v332);
extern void  statement_any(OID v2548,OID v1741,OID v332);
extern void  self_statement_Construct(Construct *v2548,OID v1741,OID v332);
extern void  self_statement_If(If *v2548,OID v1741,OID v332);
extern void  self_statement_Do(Do *v2548,OID v1741,OID v332);
extern void  inner_statement_any(OID v2548,OID v1741,OID v332);
extern void  self_statement_Let(Let *v2548,OID v1741,OID v332);
extern void  self_statement_And(And *v2548,OID v1741,OID v332);
extern void  self_statement_Or(Or *v2548,OID v1741,OID v332);
extern void  self_statement_While(While *v2548,OID v1741,OID v332);
extern void  self_statement_Assign(Assign *v2548,OID v1741,OID v332);
extern void  self_statement_Gassign(Gassign *v2548,OID v1741,OID v332);
extern void  self_statement_to_protect(Compile_to_protect *v2548,OID v1741,OID v332);
extern void  self_statement_For(For *v2548,OID v1741,OID v332);
extern void  self_statement_Iteration(Iteration *v2548,OID v1741,OID v332);
extern void  self_statement_Return(Return *v2548,OID v1741,OID v332);
extern void  self_statement_Call(Call *v2548,OID v1741,OID v332);
extern void  self_statement_Call_method(Call_method *v2548,OID v1741,OID v332);
extern void  self_statement_Call_method1(Call_method1 *v2548,OID v1741,OID v332);
extern void  self_statement_Call_method2(Call_method2 *v2548,OID v1741,OID v332);
extern void  self_statement_Super(Super *v2548,OID v1741,OID v332);
extern void  self_statement_Cast(Cast *v2548,OID v1741,OID v332);
extern void  self_statement_Handle(ClaireHandle *v2548,OID v1741,OID v332);
extern void  self_statement_to_CL(Compile_to_CL *v2548,OID v1741,OID v332);
extern void  self_statement_to_C(Compile_to_C *v2548,OID v1741,OID v332);
extern void  self_statement_C_cast(Compile_C_cast *v2548,OID v1741,OID v332);
extern void  self_statement_Call_slot(Call_slot *v2548,OID v1741,OID v332);
extern void  self_statement_Call_table(Call_table *v2548,OID v1741,OID v332);
extern void  self_statement_Call_array(Call_array *v2548,OID v1741,OID v332);
extern void  self_statement_Update(Update *v2548,OID v1741,OID v332);
extern char * c_string_c_producer1(Generate_c_producer *v1723,Variable *v2548);
extern char * c_string_c_producer2(Generate_c_producer *v1723,symbol *v2548);
extern char * string_I_c_producer1(Generate_c_producer *v1723,Variable *v2548);
extern char * string_I_c_producer2(Generate_c_producer *v1723,symbol *v2548);
extern void  ident_c_producer3(Generate_c_producer *v1723,Variable *v1743);
extern void  ident_c_producer(Generate_c_producer *v1723,symbol *v1741);
extern void  class_princ_c_producer(Generate_c_producer *v1723,ClaireClass *v2548);
extern void  produce_c_producer2(Generate_c_producer *v1723,OID v1744);
extern void  globalVar_c_producer(Generate_c_producer *v1723,global_variable *v1744);
extern void  stat_exp_c_producer(Generate_c_producer *v1723,OID v2548,OID v332);
extern void  namespace_I_c_producer(Generate_c_producer *v1723,module *v1733);
extern void  module_I_c_producer(Generate_c_producer *v1723,module *v1733);
extern void  declare_c_producer(Generate_c_producer *v1723,property *v1736);
extern void  start_module_interface_c_producer(Generate_c_producer *v1723,module *v2548);
extern void  end_module_interface_c_producer(Generate_c_producer *v1723,module *v2548);
extern void  generate_end_file_c_producer(Generate_c_producer *v1730,module *v1733);
extern void  generate_classes_c_producer(Generate_c_producer *v1730,char *v1741,module *v1733);
extern void  generate_start_file_c_producer(Generate_c_producer *v1723,module *v1733);
extern void  generate_meta_load_c_producer(Generate_c_producer *v1723,module *v1733);
extern OID  start_file_string(char *v1741,module *v1733);
extern void  define_variable_c_producer2(Generate_c_producer *v1723,ClaireClass *v1740,char *v1743);
extern void  generate_profile_c_producer(Generate_c_producer *v1723,OID v1733);
extern void  generate_interface_c_producer(Generate_c_producer *v1723,module *v2548);
extern void  global_var_def_I_c_producer(Generate_c_producer *v1723,module *v2548,Let *v1744);
extern void  gc_introduction_c_producer(Generate_c_producer *v1723,OID v2437);
extern OID  gc_usage_any(OID v2548,ClaireBoolean *v332);
extern OID  gc_or_any(OID v1744,OID v1745);
extern OID  gc_usage_star_list(list *v1732,ClaireBoolean *v332);
extern void  debug_intro_c_producer(Generate_c_producer *v1723,lambda *v2548,method *v1744);
extern char * protect_result_c_producer(Generate_c_producer *v1723,ClaireClass *v1741,ClaireBoolean *v6973,OID v1744);
extern void  generate_function_start_c_producer(Generate_c_producer *v1723,lambda *v2548,ClaireClass *v1741,OID v1733,char *v14127);
extern void  generate_regular_function_c_producer(Generate_c_producer *v1723,lambda *v2548,ClaireFunction *v2441,ClaireClass *v1741,OID v1733,list *v4658);
extern void  generate_float_function_c_producer(Generate_c_producer *v1723,method *v1733,char *v14127);
extern void  at_c_producer(Generate_c_producer *v1723);
extern void  generate_tuple_function_c_producer(Generate_c_producer *v1723,method *v1733,char *v14127);
extern OID  create_function_entry_c_producer(Generate_c_producer *v1723,lambda *v4638,char *v2441,OID v1733);
extern OID  update_function_entry_c_producer(Generate_c_producer *v1723,ClaireFunction *v2441,list *v4658,ClaireClass *v1741);
extern char * c_interface_class1_Generate(ClaireClass *v2548);
extern void  c_interface_class2_Generate(ClaireClass *v2548,char *v1741);
extern void  c_interface_method_Generate(method *v2548);
extern void  interface_I_c_producer(Generate_c_producer *v1723,ClaireClass *v2548);
extern void  to_cl_c_producer(Generate_c_producer *v1723,OID v1744,ClaireClass *v1741,OID v332);
extern void  to_c_c_producer1(Generate_c_producer *v1723,OID v1744,ClaireClass *v1741,OID v332);
extern void  to_c_c_producer2(Generate_c_producer *v1723,ClaireClass *v1741);
extern void  public_static_c_producer(Generate_c_producer *v1723);
extern void  bool_exp_I_c_producer(Generate_c_producer *v1723,OID v2548,OID v332);
extern void  inherit_exp_c_producer(Generate_c_producer *v1723,OID v4249,OID v4250,OID v332);
extern void  bitvector_exp_c_producer(Generate_c_producer *v1723,OID v4249,OID v4250,OID v332);
extern void  equal_exp_c_producer(Generate_c_producer *v1723,OID v4249,ClaireBoolean *v4883,OID v4250,OID v9948);
extern ClaireBoolean * char_exp_ask_c_producer2(Generate_c_producer *v1723,OID v1744);
extern void  char_exp_c_producer2(Generate_c_producer *v1723,OID v1744,OID v332);
extern void  c_member_c_producer(Generate_c_producer *v1723,OID v2548,ClaireClass *v1741,property *v1744,OID v332);
extern void  addFast_c_producer(Generate_c_producer *v1723);
extern void  cast_I_c_producer(Generate_c_producer *v1723,Compile_C_cast *v2548,OID v332);
extern void  gc_protection_exp_c_producer(Generate_c_producer *v1723,Variable *v1743,ClaireBoolean *v13418,OID v1742,OID v332);
extern void  bag_expression_c_producer(Generate_c_producer *v4381,ClaireClass *v1723,bag *v1732,ClaireType *v1740,OID v332);
extern void  generate_s_file_string(char *v2548,list *v1732,OID v1733);
extern void  create_load_modules_string(char *v2548,ClairePort *v1736,list *v13204,OID v1733);
extern void  methods_interface_c_producer(Generate_c_producer *v1723,ClaireClass *v1744);
extern void  methods_bodies_c_producer(Generate_c_producer *v1723,ClaireClass *v1744);
extern void  inline_exp_c_producer1(Generate_c_producer *v1723,Call_method1 *v2548,OID v332);
extern void  inline_exp_c_producer2(Generate_c_producer *v1723,Call_method2 *v2548,OID v332);
extern void  inline_exp_c_producer3(Generate_c_producer *v1723,Call_method *v2548,OID v332);
extern void  print_external_call_c_producer(Generate_c_producer *v1723,Call_method *v2548,OID v332);
extern void  inline_exp_c_producer5(Generate_c_producer *v1723,Call *v2548,OID v332);
extern ClaireBoolean * fcall_ask_Call2_Generate(Call *v1744);
extern list * get_restrictions_Call2(Call *v1744,list *v4656);
extern void  fcall_exp_Call2_Generate(Call *v1744,OID v332);
extern void  c_sorted_arg_any(OID v1744,ClaireClass *v1741,OID v332,ClaireBoolean *v15164);
extern void  c_sorted_args_Call(Call *v1744,list *v4655,OID v332,ClaireBoolean *v15164);
extern void  bitvector_I_c_producer(Generate_c_producer *v1723,OID v1744);
extern void  bitvectorSum_integer(int v1744);
extern void  signature_I_c_producer(Generate_c_producer *v1723,OID v1744);
extern OID  getC_any(OID v1744);
extern void  gassign_c_producer(Generate_c_producer *v1723,Gassign *v2548,OID v332);
extern void  call_slot_c_producer(Generate_c_producer *v1723,Call_slot *v2548,OID v332);
extern void  call_table_c_producer(Generate_c_producer *v1723,Call_table *v2548,OID v332);
extern void  call_array_c_producer(Generate_c_producer *v1723,Call_array *v2548,OID v332);
extern void  update_c_producer(Generate_c_producer *v1723,Update *v2548,OID v332);
extern void  object_test_c_producer(Generate_c_producer *v1723,OID v4249,ClaireBoolean *v4883,OID v332);
extern void  exp_to_protect_c_producer(Generate_c_producer *v1723,Compile_to_protect *v2548,OID v332);
extern void  macro_c_producer(Generate_c_producer *v1723);
extern void  init_var_c_producer(Generate_c_producer *v1723,ClaireClass *v1741);
extern void  any_interface_c_producer(Generate_c_producer *v1723);
extern void  pointer_cast_c_producer(Generate_c_producer *v1723,ClaireClass *v1741);
extern void  exp_Assign_c_producer(Generate_c_producer *v1723,Assign *v2548,OID v332);
extern void  stat_handle_c_producer(Generate_c_producer *v1723,ClaireHandle *v2548,OID v1741,OID v332);
extern void  stat_construct_c_producer(Generate_c_producer *v1723,Construct *v2548,OID v1741,OID v332);
extern void  stat_while_c_producer(Generate_c_producer *v1723,While *v2548,OID v1741,OID v332);
extern void  stat_gassign_c_producer(Generate_c_producer *v1723,Gassign *v2548,OID v1741,OID v332);
extern void  stat_for_c_producer(Generate_c_producer *v1723,For *v2548,OID v1741,OID v332);
extern void  stat_iteration_c_producer(Generate_c_producer *v1723,Iteration *v2548,OID v1741,OID v332);
extern void  stat_super_c_producer(Generate_c_producer *v1723,Super *v2548,OID v1741,OID v332);
extern void  stat_let_c_producer(Generate_c_producer *v1723,Let *v2548,OID v1741,OID v332);

// namespace class for Generate 
class GenerateClass: public NameSpace {
public:

global_variable * _star_ask_interval_star;
global_variable * _star_dash_dash_integer_star;
global_variable * _star_plus_integer_star;
global_variable * _starnth_integer_star;
global_variable * _starnth_list_star;
global_variable * _starnth_1_bag_star;
global_variable * _starnth_string_star;
global_variable * _starnth_1_string_star;
global_variable * _starnth_equal_list_star;
global_variable * _starnot_star;
global_variable * _starknown_star;
global_variable * _starunknown_star;
global_variable * _starnot_equal_star;
global_variable * _starcontain_star;
global_variable * _starmin_integer_star;
global_variable * _starmax_integer_star;
global_variable * _starlength_array_star;
global_variable * _starlength_bag_star;
global_variable * _starclose_exception_star;
ClaireClass * _producer;
global_variable * PRODUCER;
table * classFile;
global_variable * WrongMethod;
ClaireClass * _c_producer;
Generate_c_producer * C_plus_plusPRODUCER;
property * fcall_ask;
property * fcall_exp;
global_variable * FCLimit;
global_variable * FCALLSTINKS;
global_variable * bitvectorList;
property * open_comparators;// Generate/"open_comparators"
property * open_operators;// Generate/"open_operators"
property * extension;// Generate/"extension"
property * interfaces;// Generate/"interfaces"
property * interface_I;// Generate/"interface!"
property * indent_c;// Generate/"indent_c"
property * breakline;// Generate/"breakline"
property * new_block;// Generate/"new_block"
property * close_block;// Generate/"close_block"
property * c_test;// claire/"c_test"
property * c_func;// Compile/"c_func"
property * expression;// Generate/"expression"
property * statement;// Generate/"statement"
property * compile;// claire/"compile"
property * parents;// Generate/"parents"
property * outmodule;// Generate/"outmodule"
property * generate_files;// Generate/"generate_files"
property * generate_classes;// Generate/"generate_classes"
property * generate_c2f;// Generate/"generate_c2f"
property * generate_f2f;// Generate/"generate_f2f"
property * generate_interface;// Generate/"generate_interface"
property * start_module_interface;// Generate/"start_module_interface"
property * generate_file;// Generate/"generate_file"
property * start_file;// Generate/"start_file"
property * generate_meta_load;// Generate/"generate_meta_load"
property * generate_start_file;// Generate/"generate_start_file"
property * generate_functions;// Generate/"generate_functions"
property * generate_objects;// Generate/"generate_objects"
property * generate_end_file;// Generate/"generate_end_file"
property * typed_args_list;// Generate/"typed_args_list"
property * namespace_I;// Generate/"namespace!"
property * public_static;// Generate/"public_static"
property * declare;// Generate/"declare"
property * print_c_function;// Generate/"print_c_function"
property * create_function_entry;// Generate/"create_function_entry"
property * check_sort;// Generate/"check_sort"
property * protect_result;// Generate/"protect_result"
property * need_debug_ask;// Generate/"need_debug?"
property * set_outfile;// Generate/"set_outfile"
property * generate_profile;// Generate/"generate_profile"
property * debug_intro;// Generate/"debug_intro"
property * inner_statement;// Generate/"inner_statement"
property * update_function_entry;// Generate/"update_function_entry"
property * get_dependents;// Generate/"get_dependents"
property * produce;// Generate/"produce"
property * at;// Generate/"at"
property * bag_expression;// Generate/"bag_expression"
property * inline_exp;// Generate/"inline_exp"
property * gc_protection_exp;// Generate/"gc_protection_exp"
property * exp_to_protect;// Generate/"exp_to_protect"
property * gc_protect;// Generate/"gc_protect"
property * gassign;// Generate/"gassign"
property * to_cl;// Generate/"to_cl"
property * to_c;// Generate/"to_c"
property * call_slot;// Generate/"call_slot"
property * call_table;// Generate/"call_table"
property * call_array;// Generate/"call_array"
property * update;// Generate/"update"
property * sign_equal;// Generate/"sign_equal"
property * sign_or;// Generate/"sign_or"
property * macro;// Generate/"macro"
property * equal_exp;// Generate/"equal_exp"
property * object_test;// Generate/"object_test"
property * bitvector_exp;// Generate/"bitvector_exp"
property * inherit_exp;// Generate/"inherit_exp"
property * args_list;// Generate/"args_list"
property * check_var;// Generate/"check_var"
property * build_Variable;// Generate/"build_Variable"
property * unfold_args;// Generate/"unfold_args"
property * c_type_sort;// Generate/"c_type_sort"
property * unfold_arg;// Generate/"unfold_arg"
property * unfold_use;// Generate/"unfold_use"
property * self_statement;// Generate/"self_statement"
property * stat_construct;// Generate/"stat_construct"
property * init_var;// Generate/"init_var"
property * stat_while;// Generate/"stat_while"
property * stat_gassign;// Generate/"stat_gassign"
property * stat_for;// Generate/"stat_for"
property * stat_iteration;// Generate/"stat_iteration"
property * stat_super;// Generate/"stat_super"
property * stat_handle;// Generate/"stat_handle"
property * any_interface;// Generate/"any_interface"
property * pointer_cast;// Generate/"pointer_cast"
property * bad_names;// Generate/"bad_names"
property * good_names;// Generate/"good_names"
property * generate_float_function;// Generate/"generate_float_function"
property * generate_regular_function;// Generate/"generate_regular_function"
property * bitvectorSum;// Generate/"bitvectorSum"
property * c_member;// Generate/"c_member"
property * addFast;// Generate/"addFast"
property * print_external_call;// Generate/"print_external_call"
property * getC;// Generate/"getC"
property * signature_I;// Generate/"signature!"
property * bitvector_I;// Generate/"bitvector!"
property * get_restrictions;// Generate/"get_restrictions"
property * c_sorted_args;// Generate/"c_sorted_args"
property * c_sorted_arg;// Generate/"c_sorted_arg"
property * generate_function_start;// Generate/"generate_function_start"
property * print_body;// Generate/"print_body"
property * c_safe;// Generate/"c_safe"
property * outer_statement;// Generate/"outer_statement"
property * methods_interface;// Generate/"methods_interface"
property * methods_bodies;// Generate/"methods_bodies"
property * gc_introduction;// Generate/"gc_introduction"
property * gc_usage;// Generate/"gc_usage"
property * gc_usage_star;// Generate/"gc_usage*"
property * gc_or;// Generate/"gc_or"
property * stat_exp;// Generate/"stat_exp"
property * define_variable;// Generate/"define_variable"
property * char_exp_ask;// Generate/"char_exp?"
property * char_exp;// Generate/"char_exp"
property * bool_exp_ask;// Generate/"bool_exp?"
property * bool_exp_I;// Generate/"bool_exp!"
property * bexpression;// Generate/"bexpression"
property * end_module_interface;// Generate/"end_module_interface"
property * stat_let;// Generate/"stat_let"
property * exp_Assign;// Generate/"exp_Assign"
property * generate_tuple_function;// Generate/"generate_tuple_function"
property * generate_s_file;// Generate/"generate_s_file"
property * create_load_modules;// Generate/"create_load_modules"
property * global_var_def_ask;// Generate/"global_var_def?"
property * global_var_def_I;// Generate/"global_var_def!"
property * getRange;// Generate/"getRange"
property * globalVar;// Generate/"globalVar"
property * c_string;// Generate/"c_string"
property * any_bool_exp;// Generate/"any_bool_exp"
property * class_princ;// Generate/"class_princ"

// module definition 
 void metaLoad();};

extern GenerateClass Generate;
extern NameSpace Compile;
extern NameSpace iClaire;

#endif
