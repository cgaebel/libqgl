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

#include "Window.h"

SUITE(WindowTest)
{
//------------------------------------------------------------------------------
    TEST(initial_size)
    {
        qgl::Window window;
        CHECK_EQUAL(qgl::Vector2ui(800, 600), window.get_size());
    }
    
//------------------------------------------------------------------------------
    TEST(initial_is_windowed)
    {
        qgl::Window window;
        CHECK(!window.is_fullscreen());
    }
    
//------------------------------------------------------------------------------
    TEST(set_video_mode)
    {
        qgl::Window window;
        window.set_video_mode(qgl::Vector2ui(1280, 1024), true);
        CHECK_EQUAL(qgl::Vector2ui(1280, 1024), window.get_size());
        CHECK(window.is_fullscreen());
    }
    
//------------------------------------------------------------------------------    
    TEST(set_title)
    {
        qgl::Window window;
        window.set_title("Mu ha ha ha!");
        CHECK_EQUAL("Mu ha ha ha!", window.get_title());
    }
}
