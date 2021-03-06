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

#include "SdlGraphicSystem.h"

#include <stdexcept>
#include <SDL.h>
#include <GL/glew.h>

#include "debug.h"
#include "string_utils.h"
#include "Image.h"

namespace qgl
{
//------------------------------------------------------------------------------
    SdlGraphicSystem::SdlGraphicSystem()
    {
        set_video_mode(Vector2ui(800, 600), false);
        glewInit();
    }
    
//------------------------------------------------------------------------------
    SdlGraphicSystem::~SdlGraphicSystem() {}
    
//------------------------------------------------------------------------------
    Vector2ui SdlGraphicSystem::get_size() const
    {
        SDL_Surface* surface = SDL_GetVideoSurface();
        QGL_ASSERT(surface != NULL);
        return Vector2ui(surface->w, surface->h);
    }

//------------------------------------------------------------------------------
    bool SdlGraphicSystem::is_fullscreen() const
    {
        SDL_Surface* surface = SDL_GetVideoSurface();
        QGL_ASSERT(surface != NULL);
        return (surface->flags & SDL_FULLSCREEN) == SDL_FULLSCREEN; 
    }
    
//------------------------------------------------------------------------------
    void SdlGraphicSystem::set_video_mode(const Vector2ui& size, bool fullscreen)
    {        
        QGL_LOG_DETAILS(compose("Resize SdlGraphicSystem to %0 %1.", size, fullscreen ? "(fullscreen)" : ""));
        
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
    void SdlGraphicSystem::set_title(const std::string& value)
    {
        SDL_WM_SetCaption(value.c_str(), value.c_str());
    }
        
//------------------------------------------------------------------------------
    std::string SdlGraphicSystem::get_title() const
    {
        char *title;
        SDL_WM_GetCaption(&title, NULL);
        return title;
    }

//------------------------------------------------------------------------------	
	void SdlGraphicSystem::draw_frame()
	{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        draw_signal.emit();
        
        SDL_GL_SwapBuffers();
	}

//------------------------------------------------------------------------------    
    void SdlGraphicSystem::set_ortho2d(float left,  float right, float bottom, float top)
    {
        glMatrixMode(GL_PROJECTION);  
        glLoadIdentity();
        gluOrtho2D(left, right, bottom, top);
        
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }
    
//------------------------------------------------------------------------------
    void SdlGraphicSystem::set_color(const Vector3f& color) 
    {
        glColor3f(color(0), color(1), color(2));
    }
        
//------------------------------------------------------------------------------
    void SdlGraphicSystem::bind_image(const Image& image) 
    {
        // REVIEW: Yea, this is kinda not the way it should go,
        // but since Image just works, we will leve it for now.
        image.bind();
    }
    
//------------------------------------------------------------------------------
    void SdlGraphicSystem::draw_rectangle(Vector2f& pos, Vector2f& size) 
    {
        glBegin(GL_QUADS);
          glNormal3f(0.0f, 0.0f, 1.0f);
          
          glTexCoord2f(0.0f, 0.0f);
          glVertex3f(pos(0), pos(1), 0.0f);
          
          glTexCoord2f(1.0f, 0.0f);
          glVertex3f(pos(0) + size(0), pos(1), 0.0f);
          
          glTexCoord2f(1.0f, 1.0f);
          glVertex3f(pos(0) + size(0), pos(1) + size(1), 0.0f);
          
          glTexCoord2f(0.0f, 1.0f);
          glVertex3f(pos(0), pos(1) + size(1), 0.0f);
        glEnd();
    }
    
//------------------------------------------------------------------------------
    void SdlGraphicSystem::enable_blending() 
    {
        // REVIEW: Do need to set the blend function? Is it even the right thing
        // to do?
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
    
//------------------------------------------------------------------------------
    void SdlGraphicSystem::disable_blending() 
    {
        glDisable(GL_BLEND);
    }
    
//------------------------------------------------------------------------------
    void SdlGraphicSystem::enable_lighting() 
    {
        glEnable(GL_LIGHTING);
    }
    
//------------------------------------------------------------------------------
    void SdlGraphicSystem::disable_lighting() 
    {
        glDisable(GL_LIGHTING);
    }
}
