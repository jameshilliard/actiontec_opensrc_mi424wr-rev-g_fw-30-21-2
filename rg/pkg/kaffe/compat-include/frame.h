/* Header file for unwinding stack frames for exception handling.  */
/* Compile this one with gcc.  */
/* Copyright (C) 1997, 1998 Free Software Foundation, Inc.
   Contributed by Jason Merrill <jason@cygnus.com>.

This file is part of GNU CC.

GNU CC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU CC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU CC; see the file COPYING.  If not, write to
the Free Software Foundation, 51 Franklin Street, Fifth Floor,
Boston, MA 02110-1301, USA.  */


typedef struct frame_state
{
  void *cfa;
  void *eh_ptr;
  long cfa_offset;
  long args_size;
  long reg_or_offset[FIRST_PSEUDO_REGISTER+1];
  unsigned short cfa_reg;
  unsigned short retaddr_column;
  char saved[FIRST_PSEUDO_REGISTER+1];
} frame_state;

/* Values for 'saved' above.  */
#define REG_UNSAVED 0
#define REG_SAVED_OFFSET 1
#define REG_SAVED_REG 2

/* The representation for an "object" to be searched for frame unwind info.
   For targets with named sections, one object is an executable or shared
   library; for other targets, one object is one translation unit.

   A copy of this structure declaration is printed by collect2.c;
   keep the copies synchronized!  */

struct object {
  void *pc_begin;
  void *pc_end;
  struct dwarf_fde *fde_begin;
  struct dwarf_fde **fde_array;
  size_t count;
  struct object *next;
};

/* Note the following routines are exported interfaces from libgcc; do not
   change these interfaces.  Instead create new interfaces.  Also note
   references to these functions may be made weak in files where they
   are referenced.  */

extern void __register_frame (void * );
extern void __register_frame_table (void *);
extern void __deregister_frame (void *);

/* Called either from crtbegin.o or a static constructor to register the
   unwind info for an object or translation unit, respectively.  */

extern void __register_frame_info (void *, struct object *);

/* Similar, but BEGIN is actually a pointer to a table of unwind entries
   for different translation units.  Called from the file generated by
   collect2.  */
extern void __register_frame_info_table (void *, struct object *);

/* Called from crtend.o to deregister the unwind info for an object.  */

extern void *__deregister_frame_info (void *);

/* Called from __throw to find the registers to restore for a given
   PC_TARGET.  The caller should allocate a local variable of `struct
   frame_state' (declared in frame.h) and pass its address to STATE_IN.
   Returns NULL on failure, otherwise returns STATE_IN.  */

extern struct frame_state *__frame_state_for (void *, struct frame_state *);
