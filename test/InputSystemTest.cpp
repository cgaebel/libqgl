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

#include <UnitTest++/UnitTest++.h>

#include "InputSystem.h"

SUITE(InputSystemTest)
{
//------------------------------------------------------------------------------
	struct QuitHandler
	{
		unsigned int trigger_count;
		
		QuitHandler()
		: trigger_count(0) {}
		
		void handle()
		{
			trigger_count++;
		}
	};

//------------------------------------------------------------------------------
	TEST(handles_quit_event)
	{
		qgl::InputSystem input_system;
		QuitHandler handler;
		input_system.get_quit_signal().connect(sigc::mem_fun(handler, &QuitHandler::handle));
		
		input_system.inject_quit();
		input_system.process_input();
		
		CHECK_EQUAL(1, handler.trigger_count);
	}

//------------------------------------------------------------------------------
	struct KeyHandler
	{
		unsigned int press_count;
		unsigned int release_count;
		qgl::KeyId last_key;		
		
		KeyHandler()
		: press_count(0), release_count(0), last_key(qgl::UNKNOWN_KEY) {}
		
		void handle_press(qgl::KeyId key)
		{
			press_count++;
			last_key = key;
		}
		
		void handle_release(qgl::KeyId key)
		{
			release_count++;
			last_key = key;
		}		
	};
	
//------------------------------------------------------------------------------
	TEST(handles_keys)
	{
		qgl::InputSystem input_system;
		KeyHandler handler;
		input_system.get_key_press_signal().connect(sigc::mem_fun(handler, &KeyHandler::handle_press));
		input_system.get_key_release_signal().connect(sigc::mem_fun(handler, &KeyHandler::handle_release));
		
		input_system.inject_key_press(qgl::ESCAPE_KEY);
		input_system.process_input();
		
		CHECK_EQUAL(1, handler.press_count);
		CHECK_EQUAL(0, handler.release_count);
		CHECK_EQUAL(qgl::ESCAPE_KEY, handler.last_key);
		
		input_system.inject_key_release(qgl::ESCAPE_KEY);
		input_system.process_input();
		
		CHECK_EQUAL(1, handler.press_count);
		CHECK_EQUAL(1, handler.release_count);
		CHECK_EQUAL(qgl::ESCAPE_KEY, handler.last_key);
	}
	
//------------------------------------------------------------------------------
	struct MouseButtonHandler
	{
		unsigned int press_count;
		unsigned int release_count;
		qgl::MouseButtonId last_button;		
		qgl::Vector2ui last_pos;
		
		MouseButtonHandler()
		: press_count(0), release_count(0), 
          last_button(qgl::NO_MOUSE_BUTTON), last_pos(0, 0) {}
		
		void handle_press(qgl::Vector2ui pos, qgl::MouseButtonId button)
		{
			press_count++;
			last_button = button;
			last_pos = pos;
		}
		
		void handle_release(qgl::Vector2ui pos, qgl::MouseButtonId button)
		{
			release_count++;
			last_button = button;
			last_pos = pos;
		}		
	};
	
//------------------------------------------------------------------------------
	TEST(handles_mouse_buttons)
	{
		qgl::InputSystem input_system;
		MouseButtonHandler handler;
		input_system.get_mouse_press_signal().connect(sigc::mem_fun(handler, &MouseButtonHandler::handle_press));
		input_system.get_mouse_release_signal().connect(sigc::mem_fun(handler, &MouseButtonHandler::handle_release));
		
		input_system.inject_mouse_press(qgl::Vector2ui(15, 26), qgl::LEFT_MOUSE_BUTTON);
		input_system.process_input();
		
		CHECK_EQUAL(1, handler.press_count);
		CHECK_EQUAL(0, handler.release_count);
		CHECK_EQUAL(qgl::LEFT_MOUSE_BUTTON, handler.last_button);
		CHECK_EQUAL(qgl::Vector2ui(15, 26), handler.last_pos);
		
		input_system.inject_mouse_release(qgl::Vector2ui(30, 50), qgl::LEFT_MOUSE_BUTTON);
		input_system.process_input();
		
		CHECK_EQUAL(1, handler.press_count);
		CHECK_EQUAL(1, handler.release_count);
		CHECK_EQUAL(qgl::LEFT_MOUSE_BUTTON, handler.last_button);
		CHECK_EQUAL(qgl::Vector2ui(30, 50), handler.last_pos);
	}
	
//------------------------------------------------------------------------------
	struct MouseMotionHandler
	{
		unsigned int event_count;
		qgl::Vector2ui last_pos;
		qgl::Vector2i last_dpos;
		
		MouseMotionHandler()
		: event_count(0), last_pos(0, 0), last_dpos(0, 0) {}
		
		void handle_move(qgl::Vector2ui pos, qgl::Vector2i dpos)
		{
			event_count++;
			last_pos = pos;
			last_dpos = dpos;
		}
	};
	
//------------------------------------------------------------------------------
	TEST(handles_mouse_move)
	{
		qgl::InputSystem input_system;
		MouseMotionHandler handler;
		input_system.get_mouse_move_signal().connect(sigc::mem_fun(handler, &MouseMotionHandler::handle_move));
		
		input_system.inject_mouse_move(qgl::Vector2ui(15, 26), qgl::Vector2i(-1, +2));
		input_system.process_input();
		
		CHECK_EQUAL(1, handler.event_count);
		CHECK_EQUAL(qgl::Vector2ui(15, 26), handler.last_pos);
		CHECK_EQUAL(qgl::Vector2i(-1, +2), handler.last_dpos);
	}
}
