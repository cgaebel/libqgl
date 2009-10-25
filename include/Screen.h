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

#ifndef _QGL_SCREEN_H_
#define _QGL_SCREEN_H_

#include <vector>

#include "defines.h"
#include "Vector.h"

#include "KeyId.h"
#include "MouseButtonId.h"

namespace qgl
{
    class Widget;
    class GraphicSystem;

    /**
     * Scene
     **/
    class QGL_EXPORT Screen
    {
    public:
        /**
         * Constructor
         **/
        Screen();
        
        /**
         * Destructor
         **/
        virtual ~Screen();
        
        /**
         * Add a widget to the scene.
         *
         * @param widget the widget to add
         **/
        void add_widget(Widget& widget);
        
        /**
         * Remove a widget from the scene.
         *
         * @param widget the widget to remove
         **/
        void remove_widget(Widget& widget);
        
        /**
         * Get all widgets in this scene.
         *
         * @return a list of all widgets in this scene.
         *
         * @{
         **/
        const std::vector<Widget*>& get_widgets();
        std::vector<const Widget*> get_widgets() const;
        /** @} **/
        
        /**
         * Get size.
         **/
        const Vector2f& get_size() const;
        
        /**
         * Set size.
         **/
        void set_size(const Vector2f& value);
                        
        /**
         * Draw the screen.
         **/
        virtual void draw(GraphicSystem& graphic_system) const;
               
        virtual void inject_key_press(KeyId key);    
        virtual void inject_key_release(KeyId key);        
        virtual void inject_mouse_move(Vector2f pos, Vector2f mov);
        virtual void inject_mouse_button_press(MouseButtonId button, Vector2f pos);
        virtual void inject_mouse_button_release(MouseButtonId button, Vector2f pos);
        
    private:
        Vector2f size;
        std::vector<Widget*> widgets;
    
        // prevent implicit copy
        Screen(const Screen&);
        const Screen& operator = (const Screen&);
    };
}

#endif
