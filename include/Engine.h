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
#include "Vector.h"
#include "MouseButtonId.h"

namespace qgl
{
	class GraphicSystem;
	class InputSystem;
    class Screen;

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
         * Constructor with specific systems.
         **/
        Engine(GraphicSystem* graphic_system, InputSystem* input_system);
        
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
        
        /**
         * Set the currently active screen.
         **/
        void set_screen(Screen& screen);
        
        /**
         * Get the currently active screen.
         *
         * @{
         **/
        Screen& get_screen();
        const Screen& get_screen() const;
        /** @} **/
	
	protected:
		virtual void on_quit();
        virtual void on_mouse_press(Vector2ui pos, MouseButtonId button);        
        virtual void on_mouse_release(Vector2ui pos, MouseButtonId button);
        virtual void on_mouse_move(Vector2ui pos, Vector2i dpos);
        
        virtual void on_draw();
		
    private:
        bool running;
		
		GraphicSystem* graphic_system;
		InputSystem* input_system;

        Screen* screen;
        
        void init();
		
        // prevent implicit copy
        Engine(const Engine&);
        const Engine& operator = (const Engine&);
    };

}

#endif
