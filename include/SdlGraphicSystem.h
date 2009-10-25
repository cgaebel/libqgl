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

#ifndef _QGL_SDL_GRAPHIC_SYSTEM_H_
#define _QGL_SDL_GRAPHIC_SYSTEM_H_

#include <sigc++/signal.h>

#include "GraphicSystem.h"

#include "defines.h"
#include "Vector.h"
#include "SdlSentry.h"

namespace qgl
{
    /**
     * Implementation of the GraphicSystem using SDL.
     *
     **/
    class QGL_EXPORT SdlGraphicSystem : public GraphicSystem
    {
    public:
        /**
         * Default Constructor
         **/
        SdlGraphicSystem();
        
        /**
         * Destructor
         **/
        ~SdlGraphicSystem();
        
        virtual Vector2ui get_size() const;
        virtual bool is_fullscreen() const;
        virtual void set_video_mode(const Vector2ui& size, bool fullscreen);
        
        virtual void set_title(const std::string& value);
        virtual std::string get_title() const;
        
		virtual void draw_frame();
        
        virtual void set_ortho2d(float left,  float right, float bottom, float top);
        
        virtual void set_color(const Vector3f& color);
        
        virtual void bind_image(const Image& image);
        
        virtual void draw_rectangle(Vector2f& pos, Vector2f& size);
        
        virtual void enable_blending();
        virtual void disable_blending();
        virtual void enable_lighting();
        virtual void disable_lighting();
    
    private:
        SdlSentry sdl_sentry;
    };
}

#endif
