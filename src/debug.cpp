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

#include "debug.h"

#include <iostream>

namespace qgl
{
    LogLevel log_level = WARNING;
    
//------------------------------------------------------------------------------    
    void set_log_level(LogLevel level)
    {
        log_level = level;
    }
    
//------------------------------------------------------------------------------    
    void log_message(LogLevel level, const std::string& func, const std::string& msg)
    {
        if (level >= log_level)
        {
            std::cout << func << ": " << msg << std::endl;
        }
    }
} 