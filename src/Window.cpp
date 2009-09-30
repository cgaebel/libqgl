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

#include "Window.h"

#include <stdexcept>
#include <SDL.h>

#include "debug.h"
#include "string_utils.h"

namespace qgl
{
//------------------------------------------------------------------------------
    Window::Window()
    {
        set_video_mode(Vector2ui(800, 600), false);
    }
    
//------------------------------------------------------------------------------
    Vector2ui Window::get_size() const
    {
        SDL_Surface* surface = SDL_GetVideoSurface();
        QGL_ASSERT(surface != NULL);
        return Vector2ui(surface->w, surface->h);
    }

//------------------------------------------------------------------------------
    bool Window::is_fullscreen() const
    {
        SDL_Surface* surface = SDL_GetVideoSurface();
        QGL_ASSERT(surface != NULL);
        return (surface->flags & SDL_FULLSCREEN) == SDL_FULLSCREEN; 
    }
    
//------------------------------------------------------------------------------
    void Window::set_video_mode(const Vector2ui& size, bool fullscreen)
    {        
        QGL_LOG_DETAILS(compose("Resize window to %0 %1.", size, fullscreen ? "(fullscreen)" : ""));
        
        unsigned int flags = SDL_OPENGL;
        if (fullscreen)
            flags |= SDL_FULLSCREEN;
        SDL_Surface* surface = SDL_SetVideoMode(size(0), size(1), 0, flags);
        if (surface == NULL)
        {
            std::string msg = SDL_GetError();
            QGL_LOG_ERROR(msg);
            throw std::runtime_error(msg);
        }
    }
    
//------------------------------------------------------------------------------
    void Window::set_title(const std::string& value)
    {
        SDL_WM_SetCaption(value.c_str(), value.c_str());
    }
        
//------------------------------------------------------------------------------
    std::string Window::get_title() const
    {
        char *title;
        SDL_WM_GetCaption(&title, NULL);
        return title;
    }
}
