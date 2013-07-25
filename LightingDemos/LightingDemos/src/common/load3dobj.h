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

#ifndef APP_COMMON_LOAD3DOBJ_H
#define APP_COMMON_LOAD3DOBJ_H

namespace Load3DObj
{
	/**
	 * Load 3D model from file *.3ds format, result is stored to 3DS object
	 * struct that it is defined in the package file.
	 */
	void Load3dsModel();

	/**
	 * Load 3D model from file *.obj format, result is stored to object struct 
	 * that it is defined in the package file
	 */
	void LoadObjModel();
};

#endif // APP_COMMON_LOAD3DOBJ_H

///////////////////////////////////////////////////////////////////////////////