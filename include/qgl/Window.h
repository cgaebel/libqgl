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

#ifndef _QGL_WINDOW_H_
#define _QGL_WINDOW_H_

#include "defines.h"
#include "Vector.h"
#include "SdlSentry.h"

namespace qgl
{
    /**
     * System Window
     *
     **/
    class QGL_EXPORT Window
    {
    public:
        /**
         * Default Constructor
         **/
        Window();
        
        /**
         * Get the window size.
         **/
        Vector2ui get_size() const;
        
        /**
         * Check if the window is fullscreen
         **/
        bool is_fullscreen() const;
        
        /**
         * Set the video mode.
         **/
        void set_video_mode(const Vector2ui& size, bool fullscreen);
    
    private:
        SdlSentry sdl_sentry;
    
        // prevent implicit copy
        Window(const Window&);
        const Window& operator = (const Window&);
    };
}

#endif
