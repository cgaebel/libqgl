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

#include "Widget.h"

#include <cstdlib>
#include "Screen.h"

namespace qgl
{
//------------------------------------------------------------------------------
    Widget::Widget()
    : screen(NULL), managed(false), 
      position(0, 0), size(15, 15) {}
    
//------------------------------------------------------------------------------
    Widget::~Widget() 
    {
        if (screen != NULL)
            screen->remove_widget(*this);
    }
    
//------------------------------------------------------------------------------
    bool Widget::is_on_screen() const
    {
        return screen != NULL;
    }

//------------------------------------------------------------------------------    
    Screen& Widget::get_screen() 
    {
        return *screen;
    }
    
//------------------------------------------------------------------------------
    const Screen& Widget::get_screen() const
    {
        return *screen;
    }
    
//------------------------------------------------------------------------------
    void Widget::set_managed(bool value)
    {
        managed = value;
    }
        
//------------------------------------------------------------------------------
    bool Widget::is_managed() const
    {
        return managed;
    }
    
//------------------------------------------------------------------------------
    const Vector2f& Widget::get_position() const
    {
        return position;
    }
    
//------------------------------------------------------------------------------
    void Widget::set_position(const Vector2f& value)
    {
        position = value;
    }
    
//------------------------------------------------------------------------------
    const Vector2f& Widget::get_size() const
    {
        return size;
    }
    
//------------------------------------------------------------------------------
    void Widget::draw(GraphicSystem& graphic_system) const {}
        
//------------------------------------------------------------------------------
    void Widget::inject_key_press(KeyId key) {}
    
//------------------------------------------------------------------------------
    void Widget::inject_key_release(KeyId key) {}        
    
//------------------------------------------------------------------------------
    void Widget::inject_mouse_move(Vector2f pos, Vector2f mov) {}
    
//------------------------------------------------------------------------------
    void Widget::inject_mouse_button_press(MouseButtonId button, Vector2f pos) {}
    
//------------------------------------------------------------------------------
    void Widget::inject_mouse_button_release(MouseButtonId button, Vector2f pos) {}
}
