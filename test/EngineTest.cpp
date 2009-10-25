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

#include "Engine.h"
#include "NullGraphicSystem.h"
#include "NullInputSystem.h"

SUITE(EngineTest)
{
//-----------------------------------------------------------------------------
    /** 
     * Engine with only NULL system. 
     *
     * This engine is used to test the engine implementation. The advantage
     * of having NULL systems is that the test time is significantly lower.
     **/
    class NullEngine : public qgl::Engine
    {
    public:
        NullEngine()
        : qgl::Engine(new qgl::NullGraphicSystem, new qgl::NullInputSystem) {}
    };

//-----------------------------------------------------------------------------
	TEST(default_constructible)
	{
		qgl::Engine engine;
	}
    
//-----------------------------------------------------------------------------    
    TEST(initialize_systems)
    {
        qgl::GraphicSystem* graphic_system = new qgl::NullGraphicSystem;
        qgl::InputSystem* input_system = new qgl::NullInputSystem;
        
        qgl::Engine engine(graphic_system, input_system);
        
        CHECK(graphic_system == &engine.get_graphic_system());
        CHECK(input_system == &engine.get_input_system());
    }
    
    
}