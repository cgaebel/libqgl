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

#ifndef _NULL_GRAPHIC_SYSTEM_H_
#define _NULL_GRAPHIC_SYSTEM_H_

#include "GraphicSystem.h"

namespace qgl
{
    /**
     * Null implementation of the GraphicSystem.
     **/
    class NullGraphicSystem : public GraphicSystem
    {
    public:
        /**
         * Default Constructor
         **/
        NullGraphicSystem();
        
        /**
         * Destructor
         **/
        ~NullGraphicSystem();
        
        virtual Vector2ui get_size() const;
        virtual bool is_fullscreen() const;
        virtual void set_video_mode(const Vector2ui& size, bool fullscreen);
        
        virtual void set_title(const std::string& value);
        virtual std::string get_title() const;
        
		virtual void draw_frame();
    
    private:
        Vector2ui size;
        bool fullscreen;
        std::string title;
    };
}

#endif
