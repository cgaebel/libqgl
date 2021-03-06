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

#include "InputSystem.h"

#include <SDL.h>

namespace qgl
{
//------------------------------------------------------------------------------
    InputSystem::InputSystem() {}
    
//------------------------------------------------------------------------------
    InputSystem::~InputSystem() {}
    
//------------------------------------------------------------------------------
    sigc::signal<void>& InputSystem::get_quit_signal()
    {
        return quit_signal;
    }

//------------------------------------------------------------------------------
    sigc::signal<void, KeyId>& InputSystem::get_key_press_signal()
    {
        return key_press_signal;
    }
    
//------------------------------------------------------------------------------
    sigc::signal<void, KeyId>& InputSystem::get_key_release_signal()
    {
        return key_release_signal;
    }
    
//------------------------------------------------------------------------------
    sigc::signal<void, Vector2ui, MouseButtonId>& InputSystem::get_mouse_press_signal()
    {
        return mouse_press_signal;
    }
    
//------------------------------------------------------------------------------
    sigc::signal<void, Vector2ui, MouseButtonId>& InputSystem::get_mouse_release_signal()
    {
        return mouse_release_signal;
    }

//------------------------------------------------------------------------------	
	sigc::signal<void, Vector2ui, Vector2i>& InputSystem::get_mouse_move_signal()
	{
		return mouse_move_signal;
	}
}
