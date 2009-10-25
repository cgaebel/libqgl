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

#ifndef _QGL_GRAPHIC_SYSTEM_H_
#define _QGL_GRAPHIC_SYSTEM_H_

#include <sigc++/signal.h>

#include "defines.h"
#include "Vector.h"

namespace qgl
{
    /**
     * Graphic System
     *
     **/
    class QGL_EXPORT GraphicSystem
    {
    public:
        /**
         * Default Constructor
         **/
        GraphicSystem();
        
        /**
         * Destructor
         **/
        virtual ~GraphicSystem();
        
        /**
         * Get the GraphicSystem size.
         **/
        virtual Vector2ui get_size() const = 0;
        
        /**
         * Check if the GraphicSystem is fullscreen
         **/
        virtual bool is_fullscreen() const = 0;
        
        /**
         * Set the video mode.
         **/
        virtual void set_video_mode(const Vector2ui& size, bool fullscreen) = 0;
        
        /**
         * Set title.
         **/
        virtual void set_title(const std::string& value) = 0;
        
        /**
         * Get the GraphicSystem title.
         **/
        virtual std::string get_title() const = 0;
		
		/**
		 * Refresh the screen.
		 **/
		virtual void draw_frame() = 0;
        
        /**
         * Get the signal that is emited to draw the frame.
         **/
        sigc::signal<void>& get_draw_signal();
    
    protected:
        sigc::signal<void> draw_signal;
    
    private:  
        // prevent implicit copy
        GraphicSystem(const GraphicSystem&);
        const GraphicSystem& operator = (const GraphicSystem&);
    };
}

#endif
