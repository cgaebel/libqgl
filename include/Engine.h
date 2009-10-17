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

#ifndef _QGL_ENGINE_H_
#define _QGL_ENGINE_H_

#include "defines.h"

namespace qgl
{
	class GraphicSystem;
	class InputSystem;

    /**
     * Engine
     * 
     * The Engine class represents a common case setup for games. It includes
     * all basic systems.
     **/
    class QGL_EXPORT Engine
    {
    public:
        /**
         * Constructor
         **/
        Engine();
        
        /**
         * Destructor
         **/
        ~Engine();
        
        /**
         * Engine main loop.
         **/
        void run();
        
        /**
         * Stop engine execution.
         **/
        void stop();
        
        /**
         * Check if the engine is running.
         **/
        bool is_running() const;
		
		/**
		 * Get the graphic system.
		 **/
		GraphicSystem& get_graphic_system();
		
		/**
		 * Get the input system.
		 **/
		InputSystem& get_input_system();
	
	protected:
		virtual void on_quit();
		
    private:
        bool running;
		
		GraphicSystem* graphic_system;
		InputSystem* input_system;        
		
        // prevent implicit copy
        Engine(const Engine&);
        const Engine& operator = (const Engine&);
    };

}

#endif
