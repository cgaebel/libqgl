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

#include "SdlSentry.h"

#include <stdexcept>
#include <SDL.h>

namespace qgl
{
    unsigned int SdlSentry::use_count = 0;

//------------------------------------------------------------------------------
    SdlSentry::SdlSentry()
    {
        if (use_count == 0)
        {
            if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
            {
                throw std::runtime_error(SDL_GetError());
            }
        }
        use_count++;
    }
        
//------------------------------------------------------------------------------
    SdlSentry::~SdlSentry()
    {
        use_count--;
        if (use_count == 0)
        {
            SDL_Quit();
        }
    }
}
