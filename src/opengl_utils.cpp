//
// libqgl - The quick game library
// Copyright 2009 Sean Farell
//
// This file is part of libqgl.
//
// libqgl is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// libqgl is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with libqgl. If not, see <http://www.gnu.org/licenses/>.
//


#include "opengl_utils.h"

#include <GL/glew.h>

#include "Vector.h"

namespace qgl
{
//------------------------------------------------------------------------------
    GLuint build_cube_dl()
    {
        GLuint cube_dl = glGenLists(1);
        
        Vector3f min(-0.5, -0.5, -0.5);
        Vector3f max( 0.5,  0.5,  0.5);
                
        glNewList(cube_dl, GL_COMPILE);
        glBegin(GL_QUADS);
          glNormal3f( 0.0f, 0.0f, 1.0f);
          glVertex3f(min(0), min(1), max(2));
          glVertex3f(max(0), min(1), max(2));
          glVertex3f(max(0), max(1), max(2));
          glVertex3f(min(0), max(1), max(2));

          glNormal3f( 0.0f, 0.0f,-1.0f);
          glVertex3f(min(0), min(1), min(2));
          glVertex3f(min(0), max(1), min(2));
          glVertex3f(max(0), max(1), min(2));
          glVertex3f(max(0), min(1), min(2));

          glNormal3f( 0.0f, 1.0f, 0.0f);
          glVertex3f(min(0), max(1), min(2));
          glVertex3f(min(0), max(1), max(2));
          glVertex3f(max(0), max(1), max(2));
          glVertex3f(max(0), max(1), min(2));

          glNormal3f( 0.0f,-1.0f, 0.0f);
          glVertex3f(min(0), min(1), min(2));
          glVertex3f(max(0), min(1), min(2));
          glVertex3f(max(0), min(1), max(2));
          glVertex3f(min(0), min(1), max(2));

          glNormal3f( 1.0f, 0.0f, 0.0f);
          glVertex3f(max(0), min(1), min(2));
          glVertex3f(max(0), max(1), min(2));
          glVertex3f(max(0), max(1), max(2));
          glVertex3f(max(0), min(1), max(2));

          glNormal3f(-1.0f, 0.0f, 0.0f);
          glVertex3f(min(0), min(1), min(2));
          glVertex3f(min(0), min(1), max(2));
          glVertex3f(min(0), max(1), max(2));
          glVertex3f(min(0), max(1), min(2));
        glEnd();
    
        glEndList();
                
        return cube_dl;
    }

//------------------------------------------------------------------------------
    QGL_EXPORT void glDrawBox3f(float x, float y, float z)
    {
        static GLuint cube_dl = build_cube_dl();
        
        glEnable(GL_NORMALIZE);
        
        glPushMatrix();
        glScalef(x, y, z);
                
        glCallList(cube_dl);
        
        glPopMatrix();
    }

//------------------------------------------------------------------------------    
    QGL_EXPORT void glDrawRectangle(float x, float y, float w, float h)
    {
        glBegin(GL_QUADS);
          glNormal3f(0.0f, 0.0f, 1.0f);
          
          glTexCoord2f(0.0f, 0.0f);
          glVertex3f(    x,     y, 0.0f);
          
          glTexCoord2f(1.0f, 0.0f);
          glVertex3f(x + w,     y, 0.0f);
          
          glTexCoord2f(1.0f, 1.0f);
          glVertex3f(x + w, y + h, 0.0f);
          
          glTexCoord2f(0.0f, 1.0f);
          glVertex3f(    x, y + h, 0.0f);
        glEnd();
    }
}
