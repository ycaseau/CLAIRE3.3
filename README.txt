/***********************************************************************/
/**   CLAIRE 3.3                                      Yves Caseau      */
/**                                                                    */
/**  Copyright (C) 1998-2013 Yves Caseau. All Rights Reserved.         */
/**  Redistribution and use in source and binary forms are permitted   */
/**  provided that source distribution retains this entire copyright   */
/**  notice and comments.                                              */
/**  THIS SOFTWARE IS PROVIDED AS IS AND WITHOUT ANY WARRANTY,         */
/**  INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF          */
/**  MERCHANTABILTY AND FITNESS FOR A PARTICULAR PURPOSE               */
/***********************************************************************/


This is the main README for the new GitHub distribution of CLAIRE 3.3
It remains to be written !

This distribution contains four directories

  - meta: 	contains the self-description of CLAIRE with CLAIRE files (.cl)
  - compile: 	contains the CLAIRE files for the CLAIRE compiler 
  - include:	contains the header files (.h) , most of which are created by the 
                CLAIRE compiler
  - csrc:	contains C++ files, of two kinds
		- the kernel, necessary to create microCLAIRE 
                - the files obtained through the compilation of meta+compile/*.cl


as well as six files:
  - ccmain.cl		A claire file that describes the main/command line for CLAIRE
  - init.cl  		A self-description of the CLAIRE module structure
  - Makefile.nt		A makefile to compile and install CLAIRE on Windows (Visual C++)
  - Makefile.unix	A makefile to compule and install CLAIRE on Linux (GCC)
  - bugLog is the file that is produced by CLAIRE automatic testing (running test cases
    from previous bugs). The presence of this file is the garantee of successful non-regression
    testing :)
  - the CLAIRE 3.4 documentation


  