/*
 * Copyright (C) 1998,1999 Nikos Mavroyanopoulos
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/* $Id: bzero.c,v 1.1.1.1 2000/05/22 13:07:51 nmav Exp $ */

#ifndef LIBDEFS_H
# define LIBDEFS_H
# include "third_party/libmcrypt/lib/libdefs.h"
#endif

void Bzero(void *s, size_t n)
{
#ifdef HAVE_MEMSET
	memset( (void*) s, '\0', (size_t) n);
#else
# ifdef HAVE_BZERO
	bzero( (void*) s, (size_t) n);
# else
	char *stmp = s;

	for (int i = 0; i < n; i++)
		stmp[i] = '\0';

# endif
#endif
}
