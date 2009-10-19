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

#ifndef _QGL_INPUT_SYSTEM_H_
#define _QGL_INPUT_SYSTEM_H_

#include <sigc++/signal.h>

#include "defines.h"
#include "SdlSentry.h"
#include "KeyId.h"
#include "MouseButtonId.h"
#include "Vector.h"

namespace qgl
{
    /**
    * User Input System
    **/
    class QGL_EXPORT InputSystem
    {
    public:
        /**
        * Constructor
        **/
        InputSystem();
        
        /**
        * Destructor
        **/
        ~InputSystem();
        
        /** 
        * Get the quit signal.
        **/
        sigc::signal<void>& get_quit_signal();
        
        /**
        * Get the key press signal.
        **/
        sigc::signal<void, KeyId>& get_key_press_signal();
        
        /**
        * Get the key release signal.
        **/
        sigc::signal<void, KeyId>& get_key_release_signal();
        
        /**
         * Get the mouse press signal.
         **/
        sigc::signal<void, Vector2ui, MouseButtonId>& get_mouse_press_signal();
        
        /** 
         * Get the mouse release signal.
         **/
        sigc::signal<void, Vector2ui, MouseButtonId>& get_mouse_release_signal();
		
		/**
		 * Get the mouse move signal.
		 **/
		sigc::signal<void, Vector2ui, Vector2i>& get_mouse_move_signal();
        
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
        
    private:
        SdlSentry sdl_sentry;
        
        sigc::signal<void> quit_signal;
        sigc::signal<void, KeyId> key_press_signal;
        sigc::signal<void, KeyId> key_release_signal;
        sigc::signal<void, Vector2ui, MouseButtonId> mouse_press_signal;
        sigc::signal<void, Vector2ui, MouseButtonId> mouse_release_signal;
		sigc::signal<void, Vector2ui, Vector2i> mouse_move_signal;
        
        InputSystem(const InputSystem&);
        const InputSystem& operator = (const InputSystem&);
    };
}

#endif
