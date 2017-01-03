/*******************************************************************************
 *
 *                             Messenger Backend
 *                      Copyright (C) 2017 Björn Petersen
 *                   Contact: r10s@b44t.com, http://b44t.com
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see http://www.gnu.org/licenses/ .
 *
 *******************************************************************************
 *
 * File:    mrpoortext.c
 * Purpose: See header.
 *
 ******************************************************************************/


#include <stdlib.h>
#include "mrmailbox.h"
#include "mrtools.h"
#include "mrlog.h"

#define CLASS_MAGIC 1333332222


/*******************************************************************************
 * Main interface
 ******************************************************************************/


mrpoortext_t* mrpoortext_new()
{
	mrpoortext_t* ths = NULL;

	if( (ths=calloc(1, sizeof(mrpoortext_t)))==NULL ) {
		exit(27); /* cannot allocate little memory, unrecoverable error */
	}

	MR_INIT_REFERENCE

	ths->m_title_meaning  = MR_TITLE_NORMAL;

    return ths;
}


void mrpoortext_unref(mrpoortext_t* ths)
{
	MR_DEC_REFERENCE_AND_CONTINUE_ON_0

	mrpoortext_empty(ths);
	free(ths);
}


void mrpoortext_empty(mrpoortext_t* ths)
{
	if( ths == NULL ) {
		return;
	}

	free(ths->m_title);
	ths->m_title = NULL;
	ths->m_title_meaning = MR_TITLE_NORMAL;

	free(ths->m_text);
	ths->m_text = NULL;

	ths->m_timestamp = 0;
	ths->m_state = 0;
}
