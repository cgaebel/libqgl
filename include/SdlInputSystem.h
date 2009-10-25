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

#ifndef _QGL_SDL_INPUT_SYSTEM_H_
#define _QGL_SDL_INPUT_SYSTEM_H_

#include <sigc++/signal.h>

#include "InputSystem.h"

#include "SdlSentry.h"

namespace qgl
{
    /**
     * Implementation of the Input System with SDL.
     **/
    class QGL_EXPORT SdlInputSystem : public InputSystem
    {
    public:
        /**
         * Constructor
         **/
        SdlInputSystem();
        
        /**
         * Destructor
         **/
        ~SdlInputSystem();
        
        virtual void process_input();
        
        virtual void inject_quit();
        virtual void inject_key_press(qgl::KeyId key);
        virtual void inject_key_release(qgl::KeyId key);
        virtual void inject_mouse_press(qgl::Vector2ui pos, qgl::MouseButtonId button);
        virtual void inject_mouse_release(qgl::Vector2ui pos, qgl::MouseButtonId button);
		virtual void inject_mouse_move(qgl::Vector2ui pos, qgl::Vector2i dpos);
        
    private:
        SdlSentry sdl_sentry;
               
        SdlInputSystem(const SdlInputSystem&);
        const SdlInputSystem& operator = (const SdlInputSystem&);
    };
}

#endif
