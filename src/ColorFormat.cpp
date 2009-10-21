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

#include "ColorFormat.h"

#include <iostream>

namespace qgl
{
//------------------------------------------------------------------------------
    std::ostream& operator << (std::ostream& os, ColorFormat cf)
    {
        switch (cf)
        {
            case NO_COLOR_FORMAT:
                os << "NO_COLOR_FORMAT";
            case RGB_COLOR_FORMAT:
                os << "RGB_COLOR_FORMAT";
            case RGBA_COLOR_FORMAT:
                os << "RGBA_COLOR_FORMAT";
            default:
                os << static_cast<unsigned int>(cf);
        }
        return os;
    }
}

