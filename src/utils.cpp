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

#include "utils.h"

#include <fstream>
#include <stdexcept>
#include <cmath>

namespace qgl
{
//------------------------------------------------------------------------------
    QGL_EXPORT std::string read_file(const std::string& filename)
    {
        std::ifstream input(filename.c_str());
        if (input.good())
        {
            std::string result;
            char c = input.get();
            while (c != EOF)
            {
                result.push_back(c);
                c = input.get();
            }
            return result;
        }
        else
        {
            throw std::runtime_error("Failed to open file '" + filename + "' for reading.");
        }
    }

//------------------------------------------------------------------------------
    QGL_EXPORT float deg_to_rad(float value)
    {
        return value * (pi / 180.0f);
    }

//------------------------------------------------------------------------------
    QGL_EXPORT bool close(float a, float b, float eps)
    {
        return std::abs(a - b) < eps;
    }

//------------------------------------------------------------------------------
    QGL_EXPORT std::vector<std::string> explode(const std::string& str, const std::string& delimiter)
    {
        std::vector<std::string> gibs;
        size_t start = 0;
        size_t end = 0;

        while ((start != std::string::npos) && (start < str.size()))
        {
            end = str.find(delimiter, start);

            std::string gib;
            if (end == std::string::npos)
            {
                gib = str.substr(start);
                start = std::string::npos;
            }
            else
            {
                gib = str.substr(start, end - start);
                start = end + delimiter.size();
            }
            gibs.push_back(gib);
        }

        return gibs;
    }

//------------------------------------------------------------------------------
    QGL_EXPORT float clamp(float value, float min, float max)
    {
        if (value > max)
            return max;
        if (value < min)
            return min;
        return value;
    }

//------------------------------------------------------------------------------    
    QGL_EXPORT int char_to_int(char c)
    {
        switch (c)
        {
            case '0':            
                return 0;
            case '1':
                return 1;
            case '2':
                return 2;
            case '3':
                return 3;
            case '4':
                return 4;
            case '5':
                return 5;
            case '6':
                return 6;
            case '7':
                return 7;
            case '8':
                return 8;
            case '9':
                return 9;
            default:
                throw std::runtime_error("not a int");
        }
    }

//------------------------------------------------------------------------------    
    QGL_EXPORT std::string get_first(const std::string& sequence, const std::string& seperator)
    {
        size_t pos = sequence.find(seperator);
        if (pos == std::string::npos)
            return sequence;
        else
            return sequence.substr(0, pos);
    }

//------------------------------------------------------------------------------
    QGL_EXPORT std::string get_remainder(const std::string& sequence, const std::string& seperator)
    {
        size_t pos = sequence.find(seperator);
        if (pos == std::string::npos)
            return "";
        else
            return sequence.substr(pos + seperator.size());
    }

//------------------------------------------------------------------------------    
    QGL_EXPORT float get_random_float(float min, float max)
    {
        float dist = max - min;
        float rnd = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
        return rnd * dist + min;
    }
    
//------------------------------------------------------------------------------
    QGL_EXPORT float saturate(float value)
    {
        if (value < 0.0)
            return 0.0;
        else if (value > 1.0)
            return 1.0;
        else
            return value;
    }
    
//------------------------------------------------------------------------------
    QGL_EXPORT float smoothstep(float edge0, float edge1, float x)
    {
        x = saturate((x - edge0) / (edge1 - edge0));
        return x*x*(3-2*x);
    }

//------------------------------------------------------------------------------    
    QGL_EXPORT float rescale(float value, float source, float target)
    {
        float fct = target / source;
        return value * fct;
    }

//------------------------------------------------------------------------------    
    QGL_EXPORT std::string read_text_file(const std::string& filename)
    {
        std::ifstream input(filename.c_str());
        if (input.bad())
            throw std::runtime_error(compose("Failed to open '%0' for reading.", filename));
        
        std::string result;
        char c = input.get();
        while (c != EOF)
        {
            result.push_back(c);
            c = input.get();
        }
        return result;
    }
}
