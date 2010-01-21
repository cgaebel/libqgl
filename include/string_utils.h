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

#ifndef _QGL_STRING_UTILS_H_
#define _QGL_STRING_UTILS_H_

#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>

namespace qgl
{
    template <typename T>
    std::string to_string(T value)
    {
        std::stringstream strstr;
        strstr << value;
        return strstr.str();
    }
    
    inline
    int char_to_int(char c)
    {
        if((c < '0') || (c > '9'))
            throw std::logic_error("not a number");

        return c - '0';
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, 
              typename T5, typename T6, typename T7, typename T8, typename T9>
    std::string compose(const std::string& format, T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4, 
                                                   T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9)
    {
        std::vector<std::string> args(10);
        args[0] = to_string(arg0);
        args[1] = to_string(arg1);
        args[2] = to_string(arg2);
        args[3] = to_string(arg3);
        args[4] = to_string(arg4);
        args[5] = to_string(arg5);
        args[6] = to_string(arg6);
        args[7] = to_string(arg7);
        args[8] = to_string(arg8);
        args[9] = to_string(arg9);        
        
        std::string result;
        
        for (unsigned int i = 0; i < format.size(); i++)
        {
            if (format[i] == '%')
            {
                if (i + 1 < format.size())
                {
                    int idx = char_to_int(format[i + 1]);
                    result += args.at(idx);
                    i++;
                }
                else
                {
                    throw std::logic_error("% at end of string.");
                }
            }
            else
            {
                result.push_back(format[i]);
            }
        }
        
        return result;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, 
              typename T5, typename T6, typename T7, typename T8>
    std::string compose(const std::string& format, T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4, 
                                                   T5 arg5, T6 arg6, T7 arg7, T8 arg8)
    {
        return compose(format, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, "");
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, 
              typename T5, typename T6, typename T7>
    std::string compose(const std::string& format, T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4, 
                                                   T5 arg5, T6 arg6, T7 arg7)
    {
        return compose(format, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, "", "");
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, 
              typename T5, typename T6>
    std::string compose(const std::string& format, T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4, 
                                                   T5 arg5, T6 arg6)
    {
        return compose(format, arg0, arg1, arg2, arg3, arg4, arg5, arg6, "", "", "");
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4,
              typename T5>
    std::string compose(const std::string& format, T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4, 
                                                   T5 arg5)
    {
        return compose(format, arg0, arg1, arg2, arg3, arg4, arg5, "", "", "", "");
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    std::string compose(const std::string& format, T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4)
    {
        return compose(format, arg0, arg1, arg2, arg3, arg4, "", "", "", "", "");
    }
    
    template <typename T0, typename T1, typename T2, typename T3>
    std::string compose(const std::string& format, T0 arg0, T1 arg1, T2 arg2, T3 arg3)
    {
        return compose(format, arg0, arg1, arg2, arg3, "", "", "", "", "", "");
    }
    
    template <typename T0, typename T1, typename T2>
    std::string compose(const std::string& format, T0 arg0, T1 arg1, T2 arg2)
    {
        return compose(format, arg0, arg1, arg2, "", "", "", "", "", "", "");
    }
    
    template <typename T0, typename T1>
    std::string compose(const std::string& format, T0 arg0, T1 arg1)
    {
        return compose(format, arg0, arg1, "", "", "", "", "", "", "", "");
    }
    
    template <typename T0>
    std::string compose(const std::string& format, T0 arg0)
    {
        return compose(format, arg0, "", "", "", "", "", "", "", "", "");
    }
    
    inline
    std::string compose(const std::string& format)
    {
        return compose(format, "", "", "", "", "", "", "", "", "", "");
    }
}

#endif
