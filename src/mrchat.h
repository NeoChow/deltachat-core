/*******************************************************************************
 *
 *                             Messenger Backend
 *     Copyright (C) 2016 Björn Petersen Software Design and Development
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
 * File:    mrchat.h
 * Authors: Björn Petersen
 * Purpose: MrChat represents a single chat - this is a conversation with
 *          a single user or a group
 *
 ******************************************************************************/


#ifndef __MRCHAT_H__
#define __MRCHAT_H__


class MrMailbox;


enum MrChatType
{
	 MR_CHAT_UNDEFINED =  0
	,MR_CHAT_NORMAL    = 10 // a normal chat is a chat with a single contact
	,MR_CHAT_PRIVATE   = 20
	,MR_CHAT_GROUP     = 30
};


class MrChat
{
public:
	             MrChat      (MrMailbox*);
	             ~MrChat     ();

	// the data should be read only and are valid until the object is Release()'d.
	// unset strings are set to NULL.
	int          m_id;
	MrChatType   m_type;
	char*        m_name;
	time_t       m_timestamp;

	// send a message
	void         SendMsg     (const char* text);

private:
	// the mailbox, the chat belongs to
	MrMailbox*   m_mailbox;
};


class MrChatList
{
public:
	             MrChatList  ();
	             ~MrChatList ();
	carray*      m_chats; // contains MrChat objects
};


#endif // __MRCHAT_H__

