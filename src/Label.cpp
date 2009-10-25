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

#include "Label.h"

#include <GL/glew.h>

#include "opengl_utils.h"

namespace qgl
{
//------------------------------------------------------------------------------
    Label::Label() {}    

//------------------------------------------------------------------------------
    Label::Label(const Font& f, const std::string& t)
    : font(f), text(t) 
    {
        size = static_cast<Vector2f>(font.estimate_multiline(text));
    }
    
//------------------------------------------------------------------------------
    const Font& Label::get_font() const
    {
        return font;
    }
    
//------------------------------------------------------------------------------
    void Label::set_font(const Font& value)
    {
        font = value;
        size = font.estimate_multiline(text);
        imgs.clear();
    }
    
//------------------------------------------------------------------------------
    const std::string& Label::get_text() const
    {
        return text;
    }
    
//------------------------------------------------------------------------------
    void Label::set_text(const std::string& value)
    {
        text = value;
        size = font.estimate_multiline(text);
        imgs.clear();
    }
    
//------------------------------------------------------------------------------
    void Label::draw() const
    {
        if (imgs.empty())
            imgs = font.render_multiline(text);
        
        glColor3f(1.0f, 1.0f, 1.0f);
        
        Vector2f pos = position;
        for (unsigned int i = 0; i < imgs.size(); i++)
        {
             Vector2f size = Vector2f(imgs[i].get_width(), imgs[i].get_height());
        
             imgs[i].bind();   
             glDrawRectangle(pos(0), pos(1), size(0), size(1));
             imgs[i].unbind();
             
             pos(1) += imgs[i].get_height();
        }
    }
}
