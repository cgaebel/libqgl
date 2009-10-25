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

#include "Screen.h"

#include <algorithm>
#include <GL/glew.h>
#include <GL/glu.h>

#include "debug.h"
#include "Widget.h"

namespace qgl
{
//------------------------------------------------------------------------------
    Screen::Screen()
    : size(1280, 1024) {}
    
//------------------------------------------------------------------------------
    Screen::~Screen() 
    {
        for (unsigned int i = 0; i < widgets.size(); i++)
        {
            widgets[i]->screen = NULL;
            if (widgets[i]->is_managed())
                delete widgets[i];
        }
    }

//------------------------------------------------------------------------------    
    void Screen::add_widget(Widget& widget)
    {
        widgets.push_back(&widget);
        widget.screen = this;
    }

//------------------------------------------------------------------------------    
    void Screen::remove_widget(Widget& widget)
    {
        std::vector<Widget*>::iterator iter = std::find(widgets.begin(), widgets.end(), &widget);            
        QGL_ASSERT(iter != widgets.end());
        
        (*iter)->screen = NULL;
        widgets.erase(iter);
    }
    
//------------------------------------------------------------------------------
    const std::vector<Widget*>& Screen::get_widgets()
    {
        return widgets;
    }
    
//------------------------------------------------------------------------------
    std::vector<const Widget*> Screen::get_widgets() const
    {
        return std::vector<const Widget*>(widgets.begin(), widgets.end());
    }
    
//------------------------------------------------------------------------------
    const Vector2f& Screen::get_size() const
    {
        return size;
    }
        
//------------------------------------------------------------------------------
    void Screen::set_size(const Vector2f& value)
    {
        size = value;
    }
    
//------------------------------------------------------------------------------
    void Screen::draw() const
    {
        glMatrixMode(GL_PROJECTION);        
        glLoadIdentity();
        gluOrtho2D(0.0f, size(0), size(1), 0.0f);
        
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glDisable(GL_LIGHTING);
        
        for (unsigned int i = 0; i < widgets.size(); i++)
        {
            widgets[i]->draw();
        }
    }
    
//------------------------------------------------------------------------------
    void Screen::inject_key_press(KeyId key) {}   
    
//------------------------------------------------------------------------------
    void Screen::inject_key_release(KeyId key) {}        
    
//------------------------------------------------------------------------------
    void Screen::inject_mouse_move(Vector2f pos, Vector2f mov) 
    {
        
    }
    
//------------------------------------------------------------------------------
    void Screen::inject_mouse_button_press(MouseButtonId button, Vector2f pos)
    {
        for (unsigned int i = 0; i < widgets.size(); i++)
        {
            Vector2f dpos = pos - widgets[i]->get_position();
            Vector2f wsize = widgets[i]->get_size();
            
            if (dpos(0) >= 0.0 && dpos(1) >= 0.0 && 
                dpos(0) <= wsize(0) && dpos(0) <= wsize(0))
            {            
                widgets[i]->inject_mouse_button_press(button, dpos);
            }
        }
    }
    
//------------------------------------------------------------------------------
    void Screen::inject_mouse_button_release(MouseButtonId button, Vector2f pos)
    {
        for (unsigned int i = 0; i < widgets.size(); i++)
        {
            Vector2f dpos = pos - widgets[i]->get_position();
            Vector2f wsize = widgets[i]->get_size();
            
            if (dpos(0) >= 0.0 && dpos(1) >= 0.0 && 
                dpos(0) <= wsize(0) && dpos(1) <= wsize(1))
            {            
                widgets[i]->inject_mouse_button_release(button, dpos);
            }
        }
    }
}
