// interface defination for module Optimize, Sun Feb 15 15:37:26 2009
#ifndef CLAIREH_Optimize
#define CLAIREH_Optimize


class Optimize_meta_OPT;
class Optimize_meta_compiler;
class Compile_to_protect;
class Compile_to_CL;
class Compile_to_C;
class Compile_C_cast;
class Optimize_ClairePattern;
class Optimize_optUnion;
class Optimize_Call_function2;

class Optimize_meta_OPT: public thing{ 
  public:
     list *instructions;
     list *objects;
     set *properties;
     list *functions;
     set *need_to_close;
     set *need_modules;
     set *legal_modules;
     ClaireBoolean *allocation;
     ClaireBoolean *protection;
     ClaireBoolean *alloc_stack;
     set *ignore;
     set *to_remove;
     ClairePort *cinterface;
     ClairePort *outfile;
     int max_vars;
     ClaireBoolean *loop_gc;
     int loop_index;
     int level;
     OID in_method;
     ClaireBoolean *profile_ask;
     OID cfile;
     ClaireBoolean *use_update;
     ClaireBoolean *use_nth_equal;
     ClaireBoolean *online_ask;
     ClaireBoolean *recompute;
     list *unsure;
     set *knowns;
     set *simple_operations;
     set *non_identifiable_set;
     ClaireBoolean *use_string_update;} 
;

class Optimize_meta_compiler: public thing{ 
  public:
     char *external;
     list *headers;
     char *source;
     list *debug_ask;
     OID version;
     ClaireBoolean *active_ask;
     int safety;
     char *env;
     int naming;
     list *libraries;
     ClaireBoolean *inline_ask;
     ClaireBoolean *loading_ask;
     ClaireBoolean *class2file_ask;
     ClaireBoolean *greedy_ask;
     list *libraries_dir;
     char *headers_dir;
     list *options;
     ClaireBoolean *overflow_ask;
     ClaireBoolean *diet_ask;
     ClaireBoolean *optimize_ask;} 
;

class Compile_to_protect: public Optimized_instruction{ 
  public:
     OID arg;} 
;

class Compile_to_CL: public Optimized_instruction{ 
  public:
     OID arg;
     ClaireClass *set_arg;} 
;

class Compile_to_C: public Optimized_instruction{ 
  public:
     OID arg;
     ClaireClass *set_arg;} 
;

class Compile_C_cast: public Compile_to_C{ 
  public:} 
;

class Optimize_ClairePattern: public Type{ 
  public:
     property *selector;
     list *arg;} 
;

class Optimize_optUnion: public Union{ 
  public:} 
;

class Optimize_Call_function2: public Optimized_instruction{ 
  public:
     ClaireFunction *arg;
     list *args;} 
;
extern char * home_void();
extern OID  safe_any2(OID v6224);
extern ClaireType * safe_any2_type(ClaireType *v6224);
extern ClaireType * c_type_any_Optimize(OID v2164);
extern OID  c_strict_code_any(OID v6224,ClaireClass *v6219);
extern OID  c_strict_check_any_Optimize(OID v6224,ClaireClass *v6219);
extern OID  c_code_any1_Optimize(OID v6224,ClaireClass *v6219);
extern OID  c_code_any2_Optimize(OID v2164);
extern ClaireBoolean * c_gc_ask_any(OID v2164);
extern ClaireClass * c_sort_any_Optimize(OID v2164);
extern ClaireClass * selector_psort_Call(Call *v2164);
extern int  c_status_any(OID v2164,list *v6212);
extern int  c_or_integer(int v6224,int v6225);
extern int  c_or_list(list *v6212);
extern int  status_I_restriction(restriction *v2164);
extern int  c_return_integer(int v6224,int v6225);
extern int  c_status_property(property *v2164);
extern OID  showstatus_method2(method *v6213);
extern void  s_test_method2(method *v6213);
extern ClaireBoolean * legal_ask_module(module *v2164,OID v6224);
extern OID  legal_ask_environment(ClaireEnvironment *v2164,OID v6224);
extern OID  c_register_object(ClaireObject *v2164);
extern OID  c_register_property(property *v2164);
extern OID  selector_register_property(property *v2164);
extern OID  allocate_ask_property(property *v2164);
extern ClaireBoolean * stable_ask_relation(ClaireRelation *v2164);
extern OID  get_module_object(ClaireObject *v2164);
extern OID  known_I_listargs(listargs *v6212);
extern OID  oload_module(module *v6213);
extern OID  oload_string(char *v6206);
extern OID  turbo_module(module *v6213);
extern void  stats_meta_OPT(Optimize_meta_OPT *v6224);
extern void  self_print_to_protect(Compile_to_protect *v6224);
extern OID  self_eval_to_protect(Compile_to_protect *v6224);
extern void  self_print_to_CL(Compile_to_CL *v2164);
extern ClaireType * c_type_to_CL_Optimize(Compile_to_CL *v2164);
extern ClaireBoolean * c_gc_ask_to_CL(Compile_to_CL *v2164);
extern void  self_print_to_C(Compile_to_C *v2164);
extern ClaireBoolean * c_gc_ask_to_C(Compile_to_C *v2164);
extern ClaireType * c_type_to_C_Optimize(Compile_to_C *v2164);
extern void  self_print_C_cast(Compile_C_cast *v2164);
extern ClaireBoolean * c_gc_ask_C_cast(Compile_C_cast *v2164);
extern ClaireType * c_type_C_cast_Optimize(Compile_C_cast *v2164);
extern OID  c_code_C_cast_Optimize(Compile_C_cast *v2164,ClaireClass *v6219);
extern void  self_print_Pattern(Optimize_ClairePattern *v2164);
extern ClaireBoolean * _Z_any3(OID v6224,Optimize_ClairePattern *v6225);
extern ClaireType * glb_Pattern(Optimize_ClairePattern *v6224,ClaireType *v6225);
extern ClaireBoolean * less_ask_Pattern(Optimize_ClairePattern *v6224,OID v6225);
extern ClaireBoolean * less_ask_any(OID v6224,Optimize_ClairePattern *v6225);
extern Optimize_ClairePattern * nth_property(property *v6216,tuple *v6224);
extern void  warn_void();
extern void  Cerror_string(char *v6219,listargs *v6212);
extern void  notice_void();
extern OID  c_warn_Call(Call *v2164,OID v8375);
extern OID  c_warn_Super(Super *v2164,OID v8375);
extern OID  c_warn_property(property *v2164,list *v6212,list *v8375);
extern OID  c_warn_Variable(Variable *v2164,OID v6224,ClaireType *v6225);
extern OID  sort_equal_class(ClaireClass *v6203,ClaireClass *v12119);
extern ClaireClass * psort_any(OID v6224);
extern ClaireClass * osort_any(OID v6224);
extern ClaireClass * sort_Variable(Variable *v6224);
extern ClaireClass * stupid_t_any1(OID v2164);
extern ClaireBoolean * stupid_t_any2(OID v2164,OID v6224);
extern ClaireBoolean * extended_ask_type(ClaireType *v2164);
extern ClaireType * extends_type(ClaireType *v6224);
extern ClaireType * sort_abstract_I_type(ClaireType *v6224);
extern ClaireBoolean * sort_abstract_ask_type(ClaireType *v6224);
extern ClaireType * ptype_type(ClaireType *v6224);
extern ClaireType * pmember_type(ClaireType *v6224);
extern OID  enumerate_code_any(OID v2164,ClaireType *v10263);
extern OID  range_infers_for_Variable(Variable *v2164,ClaireType *v6225,ClaireType *v12711);
extern OID  range_infers_Variable(Variable *v2164,ClaireType *v6225);
extern void  range_infer_case_any(OID v2164,ClaireType *v6225);
extern OID  c_check_any(OID v6224,OID v6225);
extern void  range_sets_any(OID v2164,ClaireType *v6225);
extern ClaireClass * c_srange_method(method *v6213);
extern ClaireBoolean * nativeVar_ask_global_variable(global_variable *v6224);
extern ClaireType * return_type_any(OID v2164);
extern OID  c_code_Type_Optimize(Type *v2164,ClaireClass *v6219);
extern OID  self_code_subtype(subtype *v2164);
extern OID  self_code_Param(Param *v2164);
extern OID  self_code_Union(Union *v2164);
extern OID  self_code_Interval(Interval *v2164);
extern OID  self_code_Reference(Reference *v2164);
extern OID  self_code_Pattern(Optimize_ClairePattern *v2164);
extern OID  member_code_class2(ClaireClass *v2164,OID v6224);
extern OID  member_code_Type(Type *v2164,OID v6224);
extern OID  member_code_Union(Union *v2164,OID v6224);
extern OID  member_code_Interval(Interval *v2164,OID v6224);
extern OID  member_code_Param(Param *v2164,OID v6224);
extern OID  member_code_tuple(tuple *v2164,OID v6224);
extern OID  member_code_any(OID v2164,OID v6224);
extern ClaireBoolean * _Z_any4(OID v6224,OID v6225);
extern ClaireBoolean * _Z_any5(OID v6224,OID v6225);
extern ClaireBoolean * gcsafe_ask_class(ClaireClass *v2164);
extern ClaireBoolean * gcsafe_ask_type(ClaireType *v2164);
extern ClaireBoolean * gcsafe_ask_property(property *v2164);
extern OID  c_gc_I_any1(OID v2164);
extern OID  c_gc_I_any2(OID v2164,ClaireType *v6220);
extern ClaireBoolean * need_protect_any(OID v6224);
extern Variable * Variable_I_symbol(symbol *v6219,int v6214,ClaireType *v6220);
extern list * get_indexed_class_Optimize(ClaireClass *v6203);
extern ClaireBoolean * designated_ask_any(OID v2164);
extern OID  gc_register_Variable(Variable *v2164);
extern OID  gc_register_Variable2(Variable *v2164,OID v10542);
extern ClaireBoolean * inner2outer_ask_any(OID v6224);
extern ClaireBoolean * identifiable_ask_any(OID v2164);
extern OID  c_inline_method1(method *v2164,list *v6212,ClaireClass *v6219);
extern OID  c_inline_method2(method *v2164,list *v6212);
extern OID  c_inline_arg_ask_any(OID v2164);
extern OID  c_substitution_any(OID v2164,list *v12468,list *v2297,ClaireBoolean *v3835);
extern OID  eval_any2(OID v6224,ClaireClass *v6225);
extern list * bound_variables_any(OID v2164);
extern OID  c_boolean_any(OID v6224);
extern OID  restriction_I_property(property *v2164,list *v6212,ClaireBoolean *v13003);
extern OID  restriction_I_list(list *v12462,list *v6212,ClaireBoolean *v13003);
extern OID  restriction_I_class(ClaireClass *v6203,list *v12462,list *v6212);
extern ClaireType * use_range_method(method *v2164,list *v10255);
extern ClaireType * c_type_Call_Optimize(Call *v2164);
extern OID  c_code_Call_Optimize(Call *v2164);
extern OID  c_code_call_Call(Call *v2164,ClaireClass *v12685);
extern Call * open_message_property(property *v2164,list *v6212);
extern ClaireBoolean * c_gc_ask_Call(Call *v2164);
extern OID  daccess_any(OID v2164,ClaireBoolean *v6202);
extern ClaireBoolean * c_gc_ask_Call_slot(Call_slot *v2164);
extern ClaireType * c_type_Call_slot_Optimize(Call_slot *v2164);
extern ClaireType * c_type_Call_table_Optimize(Call_table *v2164);
extern ClaireType * c_type_Call_array_Optimize(Call_array *v2164);
extern OID  c_code_write_Call(Call *v2164);
extern OID  c_code_hold_property(property *v6216,OID v6224,OID v6225,ClaireBoolean *v6202);
extern OID  c_code_add_Call(Call *v2164);
extern OID  c_code_add_bag_Call(Call *v2164);
extern OID  c_code_delete_Call(Call *v2164);
extern OID  c_code_not_Select(Select *v6224);
extern OID  c_code_belong_Call(Call *v2164);
extern OID  c_code_nth_Call(Call *v2164);
extern OID  c_code_table_Call(Call *v2164);
extern OID  c_code_array_Call(Call *v2164);
extern ClaireBoolean * Update_ask_relation(ClaireRelation *v6216,OID v6224,OID v6225);
extern ClaireBoolean * Update_ask_relation2(ClaireRelation *v6216,ClaireRelation *v6219);
extern ClaireType * c_type_Update_Optimize(Update *v2164);
extern OID  c_code_method_method1(method *v2164,list *v6212,list *v8375);
extern OID  c_code_method_method2(method *v2164,list *v6212,list *v8375,ClaireClass *v12685);
extern OID  Call_method_I_method(method *v2164,list *v16234);
extern ClaireType * c_type_Call_method_Optimize(Call_method *v2164);
extern OID  c_code_Call_method_Optimize(Call_method *v2164);
extern ClaireBoolean * c_gc_ask_Call_method(Call_method *v2164);
extern ClaireFunction * functional_I_method_Optimize(method *v2164);
extern OID  nth_type_check_type(ClaireType *v12704,ClaireType *v12701,ClaireType *v12716);
extern ClaireBoolean * c_inline_ask_method(method *v2164,list *v6212);
extern OID  inline_optimize_ask_Call(Call *v2164);
extern ClaireType * c_type_Assign_Optimize(Assign *v2164);
extern OID  c_code_Assign_Optimize(Assign *v2164);
extern ClaireBoolean * c_gc_ask_Assign(Assign *v2164);
extern ClaireType * c_type_Gassign_Optimize(Gassign *v2164);
extern OID  c_code_Gassign_Optimize(Gassign *v2164);
extern ClaireBoolean * c_gc_ask_Gassign(Gassign *v2164);
extern ClaireType * c_type_And_Optimize(And *v2164);
extern OID  c_code_And_Optimize(And *v2164);
extern ClaireType * c_type_Or_Optimize(Or *v2164);
extern OID  c_code_Or_Optimize(Or *v2164);
extern ClaireType * c_type_Quote_Optimize(Quote *v2164);
extern void  c_code_Quote_Optimize(Quote *v2164);
extern ClaireType * c_type_to_protect_Optimize(Compile_to_protect *v2164);
extern OID  c_code_to_protect_Optimize(Compile_to_protect *v2164);
extern ClaireBoolean * c_gc_ask_to_protect(Compile_to_protect *v2164);
extern ClaireType * c_type_Return_Optimize(Return *v2164);
extern OID  c_code_Return_Optimize(Return *v2164);
extern ClaireType * c_type_Handle_Optimize(ClaireHandle *v2164);
extern OID  c_code_Handle_Optimize(ClaireHandle *v2164,ClaireClass *v6219);
extern ClaireBoolean * c_gc_ask_Handle(ClaireHandle *v2164);
extern ClaireType * c_type_Cast_Optimize(Cast *v2164);
extern OID  c_code_Cast_Optimize(Cast *v2164);
extern ClaireType * c_type_Super_Optimize(Super *v2164);
extern OID  c_code_Super_Optimize(Super *v2164);
extern void  self_print_Call_function2(Optimize_Call_function2 *v2164);
extern ClaireType * c_type_Call_function2_Optimize(Optimize_Call_function2 *v2164);
extern OID  c_code_Call_function2_Optimize(Optimize_Call_function2 *v2164);
extern OID  c_code_Assert_Optimize(Assert *v2164);
extern OID  c_code_Trace_Optimize(Trace *v2164);
extern ClaireType * c_type_Assert_Optimize(Assert *v2164);
extern ClaireType * c_type_Trace_Optimize(Trace *v2164);
extern ClaireType * c_type_Branch_Optimize(Branch *v2164);
extern OID  c_code_Branch_Optimize(Branch *v2164);
extern OID  c_code_Macro_Optimize(Macro *v2164,ClaireClass *v6219);
extern ClaireType * c_type_Macro_Optimize(Macro *v2164);
extern ClaireType * c_type_Printf_Optimize(Printf *v2164);
extern OID  c_code_Printf_Optimize(Printf *v2164);
extern ClaireType * c_type_Error_Optimize(Error *v2164);
extern OID  c_code_Error_Optimize(Error *v2164);
extern ClaireType * extendedTest_ask_If(If *v2164);
extern ClaireType * c_type_If_Optimize(If *v2164);
extern OID  c_code_If_Optimize(If *v2164,ClaireClass *v6219);
extern ClaireBoolean * c_gc_ask_If(If *v2164);
extern ClaireType * c_type_Case_Optimize(Case *v2164);
extern OID  c_code_Case_Optimize(Case *v2164,ClaireClass *v6219);
extern ClaireType * c_type_Do_Optimize(Do *v2164);
extern OID  c_code_Do_Optimize(Do *v2164,ClaireClass *v6219);
extern ClaireBoolean * c_gc_ask_Do(Do *v2164);
extern ClaireType * c_type_Let_Optimize(Let *v2164);
extern OID  c_code_Let_Optimize(Let *v2164,ClaireClass *v6219);
extern ClaireType * c_type_When_Optimize(When *v2164);
extern OID  c_code_When_Optimize(When *v2164,ClaireClass *v6219);
extern ClaireBoolean * c_gc_ask_Let(Let *v2164);
extern ClaireType * c_type_For_Optimize(For *v2164);
extern ClaireType * infers_from_type2(ClaireType *v6220,OID v2164);
extern OID  c_code_For_Optimize(For *v2164,ClaireClass *v6219);
extern OID  c_code_multiple_For(For *v2164,ClaireType *v10263,ClaireClass *v6219);
extern ClaireBoolean * c_gc_ask_Iteration(Iteration *v2164);
extern ClaireType * c_type_Iteration_Optimize(Iteration *v2164);
extern OID  c_code_Iteration_Optimize(Iteration *v2164);
extern OID  c_code_Select_Optimize(Select *v2164);
extern OID  c_code_Lselect_Optimize(Lselect *v2164);
extern OID  c_code_select_Iteration(Iteration *v2164,ClaireClass *v6224);
extern OID  inner_select_Iteration(Iteration *v2164,OID v12708,OID v12685,OID v2297);
extern ClaireType * c_type_Exists_Optimize(Exists *v2164);
extern OID  c_code_Exists_Optimize(Exists *v2164,ClaireClass *v6219);
extern ClaireType * c_type_Image_Optimize(Image *v2164);
extern ClaireType * c_type_Select_Optimize(Select *v2164);
extern ClaireType * c_type_Lselect_Optimize(Lselect *v2164);
extern ClaireType * c_type_While_Optimize(While *v2164);
extern OID  c_code_While_Optimize(While *v2164,ClaireClass *v6219);
extern OID  Iterate_I_Iteration(Iteration *v2164);
extern OID  iterate_Interval(Interval *v6224,Variable *v6222,OID v6205);
extern OID  iterate_array(OID *v6224,Variable *v6222,OID v6205);
extern OID  Iterate_class(ClaireClass *v6224,Variable *v6222,OID v6205);
extern OID  Iterate_any1(OID v6224,Variable *v6222,OID v6205);
extern OID  Iterate_Lselect(Lselect *v6224,Variable *v6222,OID v6205);
extern OID  Iterate_Select(Select *v6224,Variable *v6222,OID v6205);
extern OID  Iterate_Collect(Collect *v6224,Variable *v6222,OID v6205);
extern OID  Iterate_any2(OID v6224,Variable *v6222,OID v6205);
extern OID  Iterate_any3(OID v6224,Variable *v6222,OID v6205);
extern ClaireType * c_type_List_Optimize(List *v2164);
extern OID  c_code_List_Optimize(List *v2164);
extern ClaireType * c_type_Set_Optimize(Set *v2164);
extern OID  c_code_Set_Optimize(Set *v2164);
extern ClaireType * c_type_Tuple_Optimize(Tuple *v2164);
extern OID  c_code_Tuple_Optimize(Tuple *v2164);
extern ClaireType * c_type_Definition_Optimize(Definition *v2164);
extern OID  c_code_Definition_Optimize(Definition *v2164,ClaireClass *v6219);
extern OID  total_ask_class(ClaireClass *v2164,list *v6212);
extern OID  analyze_I_class(ClaireClass *v6203,OID v2164,list *v10255,list *v12460);
extern OID  c_code_Defobj_Optimize(Defobj *v2164,ClaireClass *v6219);
extern OID  c_code_Defclass_Optimize(Defclass *v2164,ClaireClass *v6219);
extern ClaireType * c_type_Defmethod_Optimize(Defmethod *v2164);
extern OID  c_code_Defmethod_Optimize(Defmethod *v2164);
extern ClaireBoolean * sort_pattern_ask_list(list *v12466,OID v2847);
extern OID  sort_code_Defmethod(Defmethod *v2164,list *v12466);
extern method * add_method_property2(property *v6216,list *v12463,ClaireType *v12637,int v12681,ClaireFunction *v12211,ClaireFunction *v12212);
extern OID  add_method_I_method(method *v6213,list *v12463,OID v12637,OID v12924,ClaireFunction *v12279);
extern list * extract_status_new_any(OID v6224);
extern list * extract_signature_I_list(list *v6212);
extern ClaireBoolean * _equalsig_ask_list(list *v6224,list *v6225);
extern char * function_name_property_Optimize(property *v6216,list *v6212,OID v6224);
extern OID  compile_lambda_string(char *v2164,lambda *v6212,OID v6213);
extern OID  c_code_Defarray_Optimize(Defarray *v2164);
extern void  compute_if_write_inverse_relation2(ClaireRelation *v6186);
extern OID  compute_set_write_relation2(ClaireRelation *v6186);
extern OID  Produce_put_property2(property *v6218,Variable *v6224,OID v6225);
extern OID  Produce_erase_property2(property *v6218,Variable *v6224);
extern OID  Produce_put_table2(table *v6218,Variable *v6224,OID v6225);
extern OID  Produce_get_relation2(ClaireRelation *v6218,Variable *v6224);
extern OID  Produce_remove_property2(property *v6218,Variable *v6224,OID v6225);
extern OID  Produce_remove_table2(table *v6218,Variable *v6224,OID v6225);
extern void  Tighten_relation2(ClaireRelation *v6218);
extern void  lexical_num_any2(OID v2164,int v6214);
extern ClaireType * c_type_Defrule2_Optimize(Defrule *v2164);
extern OID  c_code_Defrule_Optimize(Defrule *v2164,ClaireClass *v6219);
extern void  compile_if_write_relation(ClaireRelation *v6186);
extern OID  compileEventMethod_property(property *v6216);

// namespace class for Optimize 
class OptimizeClass: public NameSpace {
public:

global_variable * srange;
global_variable * typing;
global_variable * status;
global_variable * tmatch_ask;
global_variable * pname;
global_variable * if_write;
ClaireClass * _meta_OPT;
ClaireClass * _meta_compiler;
global_variable * claire_options;
global_variable * claire_lib;
global_variable * claire_modules;
Optimize_meta_compiler * compiler;
property * c_type;
property * c_code;
property * c_gc;
property * get_index;
property * get_indexed;
property * make_c_function;
property * make_float_function;
property * c_expression;
property * bool_exp;
property * c_statement;
property * c_interface;
property * c_sort;
property * designated_ask;
property * sort_equal;
property * psort;
property * osort;
property * compile_lambda;
property * c_check;
property * need_protect;
property * member_code;
property * c_strict_code;
property * c_strict_check;
property * stupid_t;
property * object_I;
property * anyObject_I;
property * Cerror;
property * self_code;
property * get_module;
property * main;
ClaireClass * _to_protect;
ClaireClass * _to_CL;
ClaireClass * _to_C;
ClaireClass * _C_cast;
ClaireClass * _Pattern;
Optimize_meta_OPT * OPT;
ClaireClass * _optUnion;
keyword * ambiguous;
property * functional_I;
ClaireClass * _Call_function2;
global_variable * PENIBLE;
global_variable * _starname_star;
global_variable * SHIT;
operation * _equalsig_ask;
property * function_name;
property * home;// claire/"home"
property * instructions;// Compile/"instructions"
property * objects;// Compile/"objects"
property * properties;// Compile/"properties"
property * functions;// Compile/"functions"
property * need_to_close;// Compile/"need_to_close"
property * need_modules;// Compile/"need_modules"
property * legal_modules;// Compile/"legal_modules"
property * allocation;// Compile/"allocation"
property * protection;// Compile/"protection"
property * alloc_stack;// Compile/"alloc_stack"
property * ignore;// Compile/"ignore"
property * to_remove;// Compile/"to_remove"
property * cinterface;// Compile/"cinterface"
property * outfile;// Compile/"outfile"
property * max_vars;// Compile/"max_vars"
property * loop_gc;// Compile/"loop_gc"
property * loop_index;// Compile/"loop_index"
property * level;// Compile/"level"
property * in_method;// Compile/"in_method"
property * profile_ask;// Compile/"profile?"
property * cfile;// Compile/"cfile"
property * use_update;// Optimize/"use_update"
property * use_nth_equal;// Optimize/"use_nth="
property * online_ask;// Optimize/"online?"
property * recompute;// Optimize/"recompute"
property * unsure;// Optimize/"unsure"
property * knowns;// Optimize/"knowns"
property * headers;// claire/"headers"
property * debug_ask;// claire/"debug?"
property * active_ask;// claire/"active?"
property * safety;// claire/"safety"
property * env;// claire/"env"
property * naming;// claire/"naming"
property * libraries;// claire/"libraries"
property * loading_ask;// claire/"loading?"
property * class2file_ask;// claire/"class2file?"
property * greedy_ask;// claire/"greedy?"
property * libraries_dir;// claire/"libraries_dir"
property * headers_dir;// claire/"headers_dir"
property * options;// claire/"options"
property * ptype;// Optimize/"ptype"
property * c_code_call;// Optimize/"c_code_call"
property * c_register;// Optimize/"c_register"
property * c_gc_ask;// Compile/"c_gc?"
property * gcsafe_ask;// Optimize/"gcsafe?"
property * selector_psort;// Optimize/"selector_psort"
property * c_status;// Optimize/"c_status"
property * c_or;// Optimize/"c_or"
property * c_return;// Optimize/"c_return"
property * status_I;// Compile/"status!"
property * stable_ask;// Optimize/"stable?"
property * legal_ask;// Optimize/"legal?"
property * selector_register;// Optimize/"selector_register"
property * allocate_ask;// Optimize/"allocate?"
property * oload;// Optimize/"oload"
property * turbo;// Optimize/"turbo"
property * stats;// Optimize/"stats"
property * sort_abstract_I;// Optimize/"sort_abstract!"
property * warn;// Compile/"warn"
property * c_warn;// Optimize/"c_warn"
property * open_message;// Optimize/"open_message"
property * sort_abstract_ask;// Optimize/"sort_abstract?"
property * extended_ask;// Optimize/"extended?"
property * extends;// Optimize/"extends"
property * enumerate_code;// Optimize/"enumerate_code"
property * c_code_method;// Optimize/"c_code_method"
property * range_infers_for;// Optimize/"range_infers_for"
property * range_infers;// Optimize/"range_infers"
property * gc_register;// Optimize/"gc_register"
property * range_infer_case;// Optimize/"range_infer_case"
property * c_gc_I;// Optimize/"c_gc!"
property * range_sets;// Optimize/"range_sets"
property * Variable_I;// Compile/"Variable!"
property * identifiable_ask;// Compile/"identifiable?"
property * c_inline;// Optimize/"c_inline"
property * bound_variables;// Optimize/"bound_variables"
property * c_substitution;// Optimize/"c_substitution"
property * c_inline_arg_ask;// Optimize/"c_inline_arg?"
property * restriction_I;// Optimize/"restriction!"
property * c_inline_ask;// Optimize/"c_inline?"
property * c_boolean;// Optimize/"c_boolean"
property * use_range;// Optimize/"use_range"
property * inline_optimize_ask;// Optimize/"inline_optimize?"
property * daccess;// Optimize/"daccess"
property * c_code_write;// Optimize/"c_code_write"
property * c_code_hold;// Optimize/"c_code_hold"
property * c_code_add;// Optimize/"c_code_add"
property * c_code_delete;// Optimize/"c_code_delete"
property * c_code_table;// Optimize/"c_code_table"
property * c_code_array;// Optimize/"c_code_array"
property * c_code_nth;// Optimize/"c_code_nth"
property * c_code_belong;// Optimize/"c_code_belong"
property * c_code_not;// Optimize/"c_code_not"
property * Update_ask;// Optimize/"Update?"
property * Call_method_I;// Optimize/"Call_method!"
property * nth_type_check;// Optimize/"nth_type_check"
property * extendedTest_ask;// Optimize/"extendedTest?"
property * Iterate_I;// Optimize/"Iterate!"
property * total_ask;// Optimize/"total?"
property * analyze_I;// Optimize/"analyze!"
property * extract_signature_I;// Optimize/"extract_signature!"
property * extract_status_new;// Optimize/"extract_status_new"
property * add_method_I;// Optimize/"add_method!"
property * showstatus;// claire/"showstatus"
property * safe;// claire/"safe"
property * overflow_ask;// claire/"overflow?"
property * c_code_multiple;// Optimize/"c_code_multiple"
property * Produce_put;// Compile/"Produce_put"
property * Produce_get;// Compile/"Produce_get"
property * Produce_remove;// Compile/"Produce_remove"
property * compute_if_write_inverse;// Compile/"compute_if_write_inverse"
property * compute_set_write;// Compile/"compute_set_write"
property * Tighten;// Compile/"Tighten"
property * c_code_add_bag;// Optimize/"c_code_add_bag"
property * diet_ask;// claire/"diet?"
property * Produce_erase;// Compile/"Produce_erase"
property * lexical_num;// Compile/"lexical_num"
property * inner2outer_ask;// Compile/"inner2outer?"
property * pmember;// Optimize/"pmember"
property * c_code_select;// Optimize/"c_code_select"
property * inner_select;// Optimize/"inner_select"
property * compile_if_write;// Optimize/"compile_if_write"
property * compileEventMethod;// Optimize/"compileEventMethod"
property * s_test;// claire/"s_test"
property * c_srange;// Compile/"c_srange"
property * optimize_ask;// claire/"optimize?"
property * nativeVar_ask;// Compile/"nativeVar?"
property * simple_operations;// Compile/"simple_operations"
property * non_identifiable_set;// Compile/"non_identifiable_set"
property * sort_pattern_ask;// Optimize/"sort_pattern?"
property * sort_code;// Optimize/"sort_code"
property * return_type;// Compile/"return_type"
property * notice;// Compile/"notice"
property * infers_from;// Optimize/"infers_from"
property * use_string_update;// Compile/"use_string_update"

// module definition 
 void metaLoad();};

extern OptimizeClass Optimize;
extern NameSpace Compile;
extern NameSpace iClaire;

#endif
