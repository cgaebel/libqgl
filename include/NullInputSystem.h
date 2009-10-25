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

#ifndef _QGL_NULL_INPUT_SYSTEM_H_
#define _QGL_NULL_INPUT_SYSTEM_H_

#include "InputSystem.h"

namespace qgl
{
    class QGL_EXPORT NullInputSystem : public InputSystem
    {
    public:
        /**
         * Constructor
         **/
        NullInputSystem();
        
        /**
         * Destructor
         **/
        ~NullInputSystem();
        
        /**
        * Process pending input.
        **/
        void process_input();
        
        /**
        * Inject Quit Event
        **/
        void inject_quit();
        
        /**
        * Inject key press event.
        **/
        void inject_key_press(qgl::KeyId key);
        
        /**
        * Inject key release event.
        **/
        void inject_key_release(qgl::KeyId key);
        
        /**
         * Inject mouse press event.
         **/
        void inject_mouse_press(qgl::Vector2ui pos, qgl::MouseButtonId button);
        
        /**
         * Inject mouse release event.
         **/
        void inject_mouse_release(qgl::Vector2ui pos, qgl::MouseButtonId button);
		
		/**
		 * Inject mouse move event.
		 **/
		void inject_mouse_move(qgl::Vector2ui pos, qgl::Vector2i dpos);
    };
}

#endif