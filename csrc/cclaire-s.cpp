// --- System configuration file for "cclaire" , ["Sun Feb 15 15:37:25 2009\n"] ---

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
#include <Generate.h>



void loadModules() 
{ //module definitions 
  Core.initModule("Core",mClaire.it,list::alloc(Kernel.emptySet,1,_oid_(Kernel.it)),
  "c:\\claire\\v3.3\\src\\meta",list::alloc(Kernel.emptySet,4,_string_(copy_string("method")),
    _string_(copy_string("object")),
    _string_(copy_string("function")),
    _string_(copy_string("types"))));
  iClaire.initModule("iClaire",claire.it,list::alloc(Kernel.emptySet,1,_oid_(mClaire.it)),
  "",Kernel.nil);
  Language.initModule("Language",iClaire.it,list::alloc(Kernel.emptySet,2,_oid_(Kernel.it),_oid_(Core.it)),
  "c:\\claire\\v3.3\\src\\meta",list::alloc(Kernel.emptySet,4,_string_(copy_string("pretty")),
    _string_(copy_string("call")),
    _string_(copy_string("control")),
    _string_(copy_string("define"))));
  Reader.initModule("Reader",iClaire.it,list::alloc(Kernel.emptySet,3,_oid_(Kernel.it),
    _oid_(Core.it),
    _oid_(Language.it)),
  "c:\\claire\\v3.3\\src\\meta",list::alloc(Kernel.emptySet,4,_string_(copy_string("read")),
    _string_(copy_string("syntax")),
    _string_(copy_string("file")),
    _string_(copy_string("inspect"))));
  Compile.initModule("Compile",iClaire.it,list::alloc(Kernel._module,1,_oid_(mClaire.it)),
  "",list::empty(Kernel._string));
  Optimize.initModule("Optimize",Compile.it,list::alloc(Kernel._module,2,_oid_(Reader.it),_oid_(mClaire.it)),
  "c:\\claire\\v3.3\\src\\compile",list::alloc(Kernel._string,5,_string_(copy_string("osystem")),
    _string_(copy_string("otool")),
    _string_(copy_string("ocall")),
    _string_(copy_string("ocontrol")),
    _string_(copy_string("odefine"))));
  Generate.initModule("Generate",Compile.it,list::alloc(Kernel._module,2,_oid_(Optimize.it),_oid_(mClaire.it)),
  "c:\\claire\\v3.3\\src\\compile",list::alloc(Kernel._string,5,_string_(copy_string("gsystem")),
    _string_(copy_string("gexp")),
    _string_(copy_string("gstat")),
    _string_(copy_string("cgen")),
    _string_(copy_string("copt"))));
  //module load 
  Core.metaLoad();
  Language.metaLoad();
  Reader.metaLoad();
  Optimize.metaLoad();
  Generate.metaLoad();
  ClEnv->module_I = claire.it; 
  } 

extern void main_list(list *l);
void call_main() {main_list(ClEnv->params);}
