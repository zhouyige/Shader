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

#include "package.h"

///////////////////////////////////////////////////////////////////////////////
// Variables
Terrain 			*g_pTerrain = NULL;
ApplyTexture2D		*m_pApplyTexture2D = NULL;

// Rotate variables
float rotation_x=0.0, rotation_x_increment=0.1f;
float rotation_y=0.0, rotation_y_increment=0.05f;
float rotation_z=0.0, rotation_z_increment=0.03f;
float g_fAngle = 0.0;
float g_lightDir[4] = {0.0f, 1.0f, 0.0f, 0.0f};

///////////////////////////////////////////////////////////////////////////////
// Declare all methods

/**
 * Initialize method
 */
void Initialize(void);

/**
 * Initialize for OpenGL
 */
void InitializeGL(void);

/**
 * Initialize all texture
 */
void InitializeTextures(void);

/**
 * Initialize shader, get location of attribute and uniform
 */
void InitializeShader(void);

/**
 * Initialize vertex array object
 */
void InitializeVAO(void);

/**
 * Update function
 */
void OnUpdate(int w, int h);

/**
 * Paint function, this method is used for paint first time.
 */
void Paint(void);

/**
 * Paint function, this method is used for paint in run-time
 */
void OnPaint(void);

///////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
	// Init for GLUT
	// Init display window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1024,768);
	glutCreateWindow("Texture Demo by Canh Doan ^^");

	// Init function handle
	glutReshapeFunc(OnUpdate);
	glutDisplayFunc(Paint);
	glutIdleFunc(OnPaint);

	// Init GLEW
	glewInit();

	Initialize();

	glutMainLoop();

	return 0;
}

///////////////////////////////////////////////////////////////////////////////

void Initialize(void)
{
	InitializeGL();
	// InitializeShader();
	// InitializeTextures();
	// InitializeVAO();
	g_pTerrain = new Terrain();
	g_pTerrain->Construct(HEIGHTMAP_SIZE, HEIGHTMAP_GRID_SPACING, HEIGHTMAP_SCALE);
}

///////////////////////////////////////////////////////////////////////////////

void InitializeGL(void)
{
	glClearColor(0.0f,0.0f,0.0f,0.0f); // Set background color
	glEnable(GL_DEPTH_TEST); // We enable the depth test (also called z buffer)
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL); // Polygon rasterization mode
}

///////////////////////////////////////////////////////////////////////////////

void InitializeShader(void)
{
}

///////////////////////////////////////////////////////////////////////////////

void InitializeTextures(void)
{
	
}

///////////////////////////////////////////////////////////////////////////////

void InitializeVAO(void)
{
}

///////////////////////////////////////////////////////////////////////////////

void OnUpdate(int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
}

///////////////////////////////////////////////////////////////////////////////

void Paint(void)
{
	glClearColor(0.3f, 0.5f, 0.9f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	g_pTerrain->OnRender();
}

///////////////////////////////////////////////////////////////////////////////

void OnPaint(void)
{
	rotation_x = rotation_x + rotation_x_increment;
	rotation_y = rotation_y + rotation_y_increment;
	rotation_z = rotation_z + rotation_z_increment;

	if (rotation_x > 359) rotation_x = 0;
	if (rotation_y > 359) rotation_y = 0;
	if (rotation_z > 359) rotation_z = 0;

	g_fAngle += 0.01f;
	if(g_fAngle > TWOPI)
		g_fAngle -= TWOPI;
	
	glutPostRedisplay();
}

///////////////////////////////////////////////////////////////////////////////
