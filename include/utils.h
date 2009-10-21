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

#ifndef _IB_UTILS_H_
#define _IB_UTILS_H_

#include <stdexcept>
#include <string>
#include <vector>
#include <sstream>

#include "defines.h"

namespace qgl
{
    /** The constant: pi **/
    static const double pi = 3.14159265358979323846;

    QGL_EXPORT std::string read_file(const std::string& filename);

    /**
     * Convert a degree to radiant.
     **/
    QGL_EXPORT float deg_to_rad(float value);

    QGL_EXPORT bool close(float a, float b, float eps);

    /*!
     * This function will explode a string into pices by the given delimiter.
     *
     * @param str the string to explode
     * @param delimiter the delimiter
     *
     * @return a vector of bits
     */
    QGL_EXPORT std::vector<std::string> explode(const std::string& str, const std::string& delimiter);

    QGL_EXPORT float clamp(float value, float min, float max);
    
    struct Null {};
    
    QGL_EXPORT int char_to_int(char c);
    
    template <typename Type>
    std::string to_string(Type value)
    {
        std::stringstream buff;
        buff << value;
        return buff.str();
    }
    
    template <typename Type>
    Type from_string(const std::string& str)
    {
        Type value;
        std::stringstream buff(str);
        buff >> value;
        return value;
    }
    
    template <typename Type0, typename Type1, typename Type2>
    std::string compose(const std::string& format, Type0 value0, Type1 value1, Type2 value2)
    {
        std::vector<std::string> str_values(3);
        str_values[0] = to_string(value0);
        str_values[1] = to_string(value1);
        str_values[2] = to_string(value2);
        
        std::string result;
        
        for (unsigned int i = 0; i < format.size(); i++)
        {
            if (format[i] != '%')
            {
                result.push_back(format[i]);
            }
            else
            {
                if (i + 1 < format.size())
                {
                    char c = format[i + 1];
                    int n = char_to_int(c);
                    if (n < 3)
                    {
                        result += str_values[n];
                        i++;
                    }
                    else
                    {
                        throw std::logic_error("Compose is only implemented ip to 3 elements.");
                    }
                }
                else
                    throw std::invalid_argument("Format string has single '%' at end.");
            }
        }
        
        return result;
    }
    
    template <typename Type0>
    std::string compose(const std::string& format, Type0 value0)
    {
        return compose(format, value0, "", "");
    }
    
    template <typename Type0, typename Type1>
    std::string compose(const std::string& format, Type0 value0, Type1 value1)
    {
        return compose(format, value0, value1, "");
    }
    
    /**
     * Get the first part of a sequence.
     **/
    QGL_EXPORT std::string get_first(const std::string& sequence, const std::string& seperator);
    
    /**
     * Get the remainder of a sequence.
     **/
    QGL_EXPORT std::string get_remainder(const std::string& sequence, const std::string& seperator);
    
    /**
     * Get a random float.
     **/
    QGL_EXPORT float get_random_float(float min, float max);
    
    
    QGL_EXPORT float saturate(float value);
    QGL_EXPORT float smoothstep(float edge0, float edge1, float x);

    /**
     * Shortcut for settings the managed flag.
     **/
    template <typename Type>
    Type* manage(Type* object)
    {
        if (object != NULL)
            object->set_managed(true);
        return object;
    };
    
    QGL_EXPORT float rescale(float value, float source, float target);
    
    QGL_EXPORT std::string read_text_file(const std::string& filename);
}

#endif
