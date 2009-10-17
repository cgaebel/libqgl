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
#include "SdlSentry.h"

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
		~InputSystem();
		
		/** 
		 * Get the quit signal.
		 **/
		sigc::signal<void>& get_quit_signal();
		
		/**
		 * Process pending input.
		 **/
		void process_input();
		
	private:
		SdlSentry sdl_sentry;
		
		sigc::signal<void> quit_signal;
		
		InputSystem(const InputSystem&);
		const InputSystem& operator = (const InputSystem&);
	};
}

#endif
