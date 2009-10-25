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

#include "SdlGraphicSystem.h"

SUITE(SdlGraphicSystemTest)
{
//------------------------------------------------------------------------------
    TEST(initial_size)
    {
        qgl::SdlGraphicSystem graphic_system;
        CHECK_EQUAL(qgl::Vector2ui(800, 600), graphic_system.get_size());
    }
    
//------------------------------------------------------------------------------
    TEST(initial_is_graphic_systemed)
    {
        qgl::SdlGraphicSystem graphic_system;
        CHECK(!graphic_system.is_fullscreen());
    }
    
//------------------------------------------------------------------------------
    TEST(set_video_mode)
    {
        qgl::SdlGraphicSystem graphic_system;
        graphic_system.set_video_mode(qgl::Vector2ui(1280, 1024), true);
        CHECK_EQUAL(qgl::Vector2ui(1280, 1024), graphic_system.get_size());
        CHECK(graphic_system.is_fullscreen());
    }
    
//------------------------------------------------------------------------------    
    TEST(set_title)
    {
        qgl::SdlGraphicSystem graphic_system;
        graphic_system.set_title("Mu ha ha ha!");
        CHECK_EQUAL("Mu ha ha ha!", graphic_system.get_title());
    }
}
