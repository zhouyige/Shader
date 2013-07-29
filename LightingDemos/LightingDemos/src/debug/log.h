///////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2010 AsNet Co., Ltd.
// All Rights Reserved. These instructions, statements, computer
// programs, and/or related material (collectively, the "Source")
// contain unpublished information proprietary to AsNet Co., Ltd
// which is protected by US federal copyright law and by 
// international treaties. This Source may NOT be disclosed to 
// third parties, or be copied or duplicated, in whole or in 
// part, without the written consent of AsNet Co., Ltd.
///////////////////////////////////////////////////////////////////////////////
// Author: Canh Doan
///////////////////////////////////////////////////////////////////////////////

#ifndef APP_DEBUG_LOG_H
#define APP_DEBUG_LOG_H

class Log
{
public:
	/**
	 * Initialize a new instance of log object
	 */
	Log(const char *szName);

	/**
	 * Deallocate resource
	 */
	~Log(const char *szName){}

	/**
	 * Write out the debug log message
	 */
	void Debug(const char* szFunc, int nLine, const char *szFormat, ...);

	/**
	 * Write out the error log message
	 */
	void Error(const char *szFunc, int nLine, const char *szFormat, ...);
};

#endif // APP_DEBUG_LOG_H

///////////////////////////////////////////////////////////////////////////////
