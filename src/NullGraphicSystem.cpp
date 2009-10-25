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

#include "NullGraphicSystem.h"

namespace qgl
{
//------------------------------------------------------------------------------
    NullGraphicSystem::NullGraphicSystem()
    : size(800, 600), fullscreen(false) {}

//------------------------------------------------------------------------------
    NullGraphicSystem::~NullGraphicSystem() {}
    
//------------------------------------------------------------------------------
    Vector2ui NullGraphicSystem::get_size() const
    {
        return size;
    }

//------------------------------------------------------------------------------
    bool NullGraphicSystem::is_fullscreen() const
    {
        return fullscreen;
    }
    
//------------------------------------------------------------------------------
    void NullGraphicSystem::set_video_mode(const Vector2ui& s, bool fs)
    {        
        size = s;
        fullscreen = fs;
    }
    
//------------------------------------------------------------------------------
    void NullGraphicSystem::set_title(const std::string& value)
    {
        title = value;
    }
        
//------------------------------------------------------------------------------
    std::string NullGraphicSystem::get_title() const
    {
        return title;
    }

//------------------------------------------------------------------------------	
	void NullGraphicSystem::draw_frame()
	{
        draw_signal.emit();        
	}

//------------------------------------------------------------------------------    
    void NullGraphicSystem::set_ortho2d(float left,  float right, float bottom, float top) {}
    
//------------------------------------------------------------------------------
    void NullGraphicSystem::set_color(const Vector3f& color) {}
        
//------------------------------------------------------------------------------
    void NullGraphicSystem::bind_image(const Image& image) {}
    
//------------------------------------------------------------------------------
    void NullGraphicSystem::draw_rectangle(Vector2f& pos, Vector2f& size) {}
    
//------------------------------------------------------------------------------
    void NullGraphicSystem::enable_blending() {}
    
//------------------------------------------------------------------------------
    void NullGraphicSystem::disable_blending() {}
    
//------------------------------------------------------------------------------
    void NullGraphicSystem::enable_lighting() {}
    
//------------------------------------------------------------------------------
    void NullGraphicSystem::disable_lighting() {}
}
