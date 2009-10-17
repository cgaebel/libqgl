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

#include "GraphicSystem.h"
#include "InputSystem.h"

namespace qgl
{
//-----------------------------------------------------------------------------
    Engine::Engine()
    : running(false),
	  graphic_system(NULL), input_system(NULL)
	{
		graphic_system = new GraphicSystem;
		input_system = new InputSystem;
		
		input_system->get_quit_signal().connect(sigc::mem_fun(this, &Engine::on_quit));
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
				graphic_system->refresh_screen();
            
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
	void Engine::on_quit()
	{
		stop();
	}		
}
