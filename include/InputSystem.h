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
        virtual ~InputSystem();
        
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
        virtual void process_input() = 0;
        
        /**
         * Inject Quit Event
         **/
        virtual void inject_quit() = 0;
        
        /**
         * Inject key press event.
         **/
        virtual void inject_key_press(qgl::KeyId key) = 0;
        
        /**
         * Inject key release event.
         **/
        virtual void inject_key_release(qgl::KeyId key) = 0;
        
        /**
         * Inject mouse press event.
         **/
        virtual void inject_mouse_press(qgl::Vector2ui pos, qgl::MouseButtonId button) = 0;
        
        /**
         * Inject mouse release event.
         **/
        virtual void inject_mouse_release(qgl::Vector2ui pos, qgl::MouseButtonId button) = 0;
		
		/**
		 * Inject mouse move event.
		 **/
		virtual void inject_mouse_move(qgl::Vector2ui pos, qgl::Vector2i dpos) = 0;
        
    protected:
        sigc::signal<void> quit_signal;
        sigc::signal<void, KeyId> key_press_signal;
        sigc::signal<void, KeyId> key_release_signal;
        sigc::signal<void, Vector2ui, MouseButtonId> mouse_press_signal;
        sigc::signal<void, Vector2ui, MouseButtonId> mouse_release_signal;
		sigc::signal<void, Vector2ui, Vector2i> mouse_move_signal;
    
    private:    
        InputSystem(const InputSystem&);
        const InputSystem& operator = (const InputSystem&);
    };
}

#endif
