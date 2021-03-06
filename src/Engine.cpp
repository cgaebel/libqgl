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

#include "Engine.h"

#include "math_utils.h"
#include "SdlGraphicSystem.h"
#include "SdlInputSystem.h"
#include "Screen.h"

namespace qgl
{
//-----------------------------------------------------------------------------
    Engine::Engine()
    : running(false),
	  graphic_system(new SdlGraphicSystem), input_system(new SdlInputSystem), 
      screen(NULL)
	{				
        init();
	}

//-----------------------------------------------------------------------------    
    Engine::Engine(GraphicSystem* gs, InputSystem* is)
    : running(false),
	  graphic_system(gs), input_system(is), 
      screen(NULL)
    {
        init();
    }
        
//-----------------------------------------------------------------------------
    Engine::~Engine()
	{
		delete input_system;
		delete graphic_system;
	}
    
//-----------------------------------------------------------------------------        
    void Engine::run()
    {
        running = true;
        while (running)
        {
            if (input_system != NULL)
				input_system->process_input();
			
			// compute simulation
			
			if (graphic_system != NULL)
				graphic_system->draw_frame();
            
            // whait on next frame
        }
    }
    
//-----------------------------------------------------------------------------
    void Engine::stop()
    {
        running = false;
    }
    
//-----------------------------------------------------------------------------
    bool Engine::is_running() const
    {
        return running;
    }
	
//-----------------------------------------------------------------------------
	GraphicSystem& Engine::get_graphic_system()
	{
		QGL_ASSERT(graphic_system != NULL);
		return *graphic_system;
	}
	
//-----------------------------------------------------------------------------
	InputSystem& Engine::get_input_system()
	{
		QGL_ASSERT(input_system != NULL);
		return *input_system;
	}
    
//-----------------------------------------------------------------------------
    void Engine::set_screen(Screen& s)
    {
        screen = &s;
    }

//-----------------------------------------------------------------------------
    Screen& Engine::get_screen()
    {
        QGL_ASSERT(screen != NULL);
        return *screen;
    }
    
//-----------------------------------------------------------------------------
    const Screen& Engine::get_screen() const
    {
        QGL_ASSERT(screen != NULL);
        return *screen;
    }
	
//-----------------------------------------------------------------------------
	void Engine::on_quit()
	{
		stop();
	}	

//-----------------------------------------------------------------------------
    void Engine::on_mouse_press(Vector2ui pos, MouseButtonId button)
    {
        QGL_ASSERT(graphic_system != NULL);
        if (screen != NULL)
        {
            Vector2f rpos = rescale<2, float>(pos, graphic_system->get_size(), screen->get_size());
            screen->inject_mouse_press(button, rpos);
        }
    }
    
//-----------------------------------------------------------------------------
    void Engine::on_mouse_release(Vector2ui pos, MouseButtonId button)
    {
        QGL_ASSERT(graphic_system != NULL);
        if (screen != NULL)
        {
            Vector2f rpos = rescale<2, float>(pos, graphic_system->get_size(), screen->get_size());
            screen->inject_mouse_release(button, rpos);
        }
    }
    
//-----------------------------------------------------------------------------
    void Engine::on_mouse_move(Vector2ui pos, Vector2i dpos)
    {
        QGL_ASSERT(graphic_system != NULL);
        if (screen != NULL)
        {
            Vector2f rpos = rescale<2, float>(pos, graphic_system->get_size(), screen->get_size());
            Vector2f rdpos = rescale<2, float>(dpos, graphic_system->get_size(), screen->get_size());
            screen->inject_mouse_move(rpos, rdpos);
        }
    }
    
//-----------------------------------------------------------------------------
    void Engine::on_draw()
    {
        if (screen != NULL)
        {
            screen->draw(*graphic_system);
        }
    }
    
//-----------------------------------------------------------------------------
    void Engine::init()
    {
        input_system->get_quit_signal().connect(sigc::mem_fun(this, &Engine::on_quit));
        input_system->get_mouse_press_signal().connect(sigc::mem_fun(this, &Engine::on_mouse_press));
        input_system->get_mouse_release_signal().connect(sigc::mem_fun(this, &Engine::on_mouse_release));
        input_system->get_mouse_move_signal().connect(sigc::mem_fun(this, &Engine::on_mouse_move));
        
        graphic_system->get_draw_signal().connect(sigc::mem_fun(this, &Engine::on_draw));
    }
}

