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

#ifndef _QGL_SDL_SENTRY_H_
#define _QGL_SDL_SENTRY_H_

#include "defines.h"

namespace qgl
{
    /**
     * SDL Sentry
     *
     **/
    class QGL_EXPORT SdlSentry
    {
    public:
        /**
         * Constructor
         **/
        SdlSentry();
        
        /**
         * Destructor
         **/
        ~SdlSentry();
    
    private:
        static unsigned int use_count;
    
        // prevent implicit copy
        SdlSentry(const SdlSentry&);
        const SdlSentry& operator = (const SdlSentry&);
    };
}

#endif
