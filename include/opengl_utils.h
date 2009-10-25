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


#ifndef _QGL_OPENGL_UTILS_H_
#define _QGL_OPENGL_UTILS_H_

#include "defines.h"

namespace qgl
{
    // NOTE: We follow openGL's naming convention in this file.
    
    /**
     * Draw a box
     **/
    QGL_EXPORT void glDrawBox3f(float x, float y, float z);
    
    /**
     * Draw a rectangle
     **/
    QGL_EXPORT void glDrawRectangle(float x, float y, float w, float h);
}

#endif
