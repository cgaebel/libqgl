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

#ifndef _QGL_MATH_UTILS_H_
#define _QGL_MATH_UTILS_H_

namespace qgl
{
    template <typename T>
    bool equals(T a, T b)
    {
        return a == b;
    }
    template <> 
    bool equals(float a, float b);
    
    template <> 
    bool equals(double a, double b);
    
    template <typename T>
    T rescale(T value, T source, T target)
    {
        T fct = target / source;
        return value * fct;
    }
    
}

#endif
