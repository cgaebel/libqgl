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

#ifndef _QGL_WIDGET_H_
#define _QGL_WIDGET_H_

#include "defines.h"

#include "Vector.h"
#include "KeyId.h"
#include "MouseButtonId.h"

namespace qgl
{
    class Screen;
    class GraphicSystem;
    
    /**
     * Widget
     **/
    class QGL_EXPORT Widget
    {
    public:
        /**
         * Constructor
         **/
        Widget();
        
        /**
         * Destructor
         **/
        virtual ~Widget();
        
        /**
         * Check if this widget is on a screen.
         **/
        bool is_on_screen() const;
        
        /**
         * Get the screen this widget is on.
         *
         * @{
         **/
        Screen& get_screen();
        const Screen& get_screen() const;
        /** @} **/
        
        /**
         * Set the managed flag.
         *
         * @see manage()
         **/
        void set_managed(bool value);
        
        /**
         * Check if this widget is managed.
         **/
        bool is_managed() const;
        
        /**
         * Get position.
         **/
        const Vector2f& get_position() const;
        
        /**
         * Set position.
         **/
        void set_position(const Vector2f& value);
        
        /**
         * Get size.
         **/
        const Vector2f& get_size() const;
        
        /**
         * Draw the widget.
         **/
        virtual void draw(GraphicSystem& graphic_system) const;
        
        virtual void inject_key_press(KeyId key);    
        virtual void inject_key_release(KeyId key);
        virtual void inject_mouse_press(MouseButtonId button, Vector2f pos);
        virtual void inject_mouse_release(MouseButtonId button, Vector2f pos);
        virtual void inject_mouse_move(Vector2f pos, Vector2f mov);
    
    protected:        
        Vector2f position;
        Vector2f size;
        
    private:
        Screen* screen;
        bool managed;
    
        // prevent implicit copy
        Widget(const Widget&);
        const Widget& operator = (const Widget&);
        
    friend class Screen;
    };
}

#endif
