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

#ifndef _QGL_DEBUG_H_
#define _QGL_DEBUG_H_

#include <stdexcept>
#include <sstream>

#include "defines.h"

namespace qgl
{
    class AssertFailed : public std::logic_error
    {
    public:
        AssertFailed(const std::string& msg)
        : std::logic_error(msg) {}
    };    
    
    enum LogLevel
    {
        DETAILS,
        WARNING,
        ERROR
    };
    
    void set_log_level(LogLevel level);
    
    void log_message(LogLevel level, const std::string& func, const std::string& msg);
} 

#define QGL_FUNCTION __PRETTY_FUNCTION__

#define QGL_ASSERT(COND) \
    if (! (COND)) \
    { \
        std::stringstream msg; \
        msg << QGL_FUNCTION << ": Assert '" << #COND << "' failed."; \
        throw qgl::AssertFailed(msg.str()); \
    }

#define QGL_LOG_DETAILS(MSG) log_message(qgl::DETAILS, QGL_FUNCTION, MSG)
#define QGL_LOG_WARNING(MSG) log_message(qgl::WARNING, QGL_FUNCTION, MSG)
#define QGL_LOG_ERROR(MSG) log_message(qgl::ERROR, QGL_FUNCTION, MSG)
    
#endif
