/* Copyright (C) 1999-2013 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#include <sys/timex.h>

#ifndef MOD_OFFSET
# define modes mode
#endif


extern int INTUSE(__adjtimex) (struct timex *__ntx);


int
ntp_gettimex (struct ntptimeval *ntv)
{
  struct timex tntx;
  int result;

  tntx.modes = 0;
  result = INTUSE(__adjtimex) (&tntx);
  ntv->time = tntx.time;
  ntv->maxerror = tntx.maxerror;
  ntv->esterror = tntx.esterror;
  ntv->tai = tntx.tai;
  ntv->__unused1 = 0;
  ntv->__unused2 = 0;
  ntv->__unused3 = 0;
  ntv->__unused4 = 0;
  return result;
}