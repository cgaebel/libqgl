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

#include "string_utils.h"

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
    void InputSystem::process_input()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                {
                    QGL_LOG_DETAILS("Processing quit.");
                    quit_signal.emit();
                    break;
                }
                case SDL_KEYDOWN:
                {
                    KeyId key = static_cast<KeyId>(event.key.keysym.sym);
                    QGL_LOG_DETAILS(compose("Processing key %0 press.", key));
                    key_press_signal.emit(key);
                    break;
                }
                case SDL_KEYUP:
                {
                    KeyId key = static_cast<KeyId>(event.key.keysym.sym);
                    QGL_LOG_DETAILS(compose("Processing key %0 release.", key));
                    key_release_signal.emit(key);
                    break;
                }
				case SDL_MOUSEBUTTONDOWN:
				{
					Vector2ui pos = Vector2ui(event.button.x, event.button.y);
					MouseButtonId button = static_cast<MouseButtonId>(event.button.button);					
					mouse_press_signal.emit(pos, button);
					break;
				}
				case SDL_MOUSEBUTTONUP:
				{
					Vector2ui pos = Vector2ui(event.button.x, event.button.y);
					MouseButtonId button = static_cast<MouseButtonId>(event.button.button);					
					mouse_release_signal.emit(pos, button);
					break;
				}
            }
        }
    }
    
//------------------------------------------------------------------------------
    void InputSystem::inject_quit()
    {
        QGL_LOG_DETAILS("Injecting quit.");
        
        SDL_Event event = {0};
        event.type = SDL_QUIT;
        event.quit.type = SDL_QUIT;
        
        SDL_PushEvent(&event);
    }
    
//------------------------------------------------------------------------------
    void InputSystem::inject_key_press(qgl::KeyId key)
    {
        QGL_LOG_DETAILS(compose("Injecting key %0 press.", key));
        
        SDL_Event event = {0};
        event.type = SDL_KEYDOWN;
        event.key.type = SDL_KEYDOWN;
        event.key.state = SDL_PRESSED;
        event.key.keysym.sym = static_cast<SDLKey>(key);		
        
        SDL_PushEvent(&event);
    }
     
//------------------------------------------------------------------------------
    void InputSystem::inject_key_release(qgl::KeyId key)
    {
        QGL_LOG_DETAILS(compose("Injecting key %0 release.", key));
        
        SDL_Event event = {0};
        event.type = SDL_KEYUP;
        event.key.type = SDL_KEYUP;
        event.key.state = SDL_RELEASED;
        event.key.keysym.sym = static_cast<SDLKey>(key);		
        
        SDL_PushEvent(&event);
    }
    
//------------------------------------------------------------------------------
    void InputSystem::inject_mouse_press(qgl::Vector2ui pos, qgl::MouseButtonId button)
    {
        QGL_LOG_DETAILS(compose("Injecting nouse %0 press at %1.", button, pos));
        
        SDL_Event event = {0};
        event.type = SDL_MOUSEBUTTONDOWN;
        event.button.type = SDL_MOUSEBUTTONDOWN;
        event.button.which = 0;
        event.button.state = SDL_PRESSED;
        event.button.button = static_cast<unsigned char>(button);
		event.button.x = pos(0);
		event.button.y = pos(1);
        
        SDL_PushEvent(&event);
    }
        
//------------------------------------------------------------------------------
    void InputSystem::inject_mouse_release(qgl::Vector2ui pos, qgl::MouseButtonId button)
    {
		QGL_LOG_DETAILS(compose("Injecting nouse %0 release at %1.", button, pos));
        
        SDL_Event event = {0};
        event.type = SDL_MOUSEBUTTONUP;
        event.button.type = SDL_MOUSEBUTTONUP;
        event.button.which = 0;
        event.button.state = SDL_RELEASED;
        event.button.button = static_cast<unsigned char>(button);
		event.button.x = pos(0);
		event.button.y = pos(1);
        
        SDL_PushEvent(&event);
    }
}

