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

#ifndef _QGL_VECTOR_H_
#define _QGL_VECTOR_H_

#include <iosfwd>

#include "debug.h"
#include "math_utils.h" 

namespace qgl
{
    /**
     * Vector
     **/
    template <unsigned int N, typename T>
    class Vector
    {
    public:
        /**
         * Default Constructor
         *         
         * @note The default constructo will NOT initialize the vector.
         **/
        Vector() {}
        
        /**
         * Copy Constructor
         **/
        Vector(const Vector<N, T>& orig)
        {
            for (unsigned int i = 0; i < N; i++)
            {
                data[i] = orig.data[i];
            }
        }
        
        /**
         * Conversin constructor
         **/
        template <typename U>
        Vector(const Vector<N, U>& other)
        {
            for (unsigned int i = 0; i < N; i++)
            {
                data[i] = other(i);
            }
        }
        
        /**
         * Destructor
         **/
        ~Vector() {}
        
        /**
         * Assignment operator.
         **/
        const Vector<N, T>& operator = (const Vector<N, T>& orig)
        {
            for (unsigned int i = 0; i < N; i++)
            {
                data[i] = orig.data[i];
            }
            return *this;
        }
        
        T& operator () (unsigned int i)
        {
            QGL_ASSERT(i < N);
            return data[i];
        }
        
        T operator () (unsigned int i) const
        {
            QGL_ASSERT(i < N);
            return data[i];
        }
        
    protected:
        T data[N];
    };
    
    /**
     * Specialisation for Vector2
     **/
    template <typename T>
    class Vector2 : public Vector<2, T>
    {
    public:
        Vector2() {}                    
        
        Vector2(T x, T y)
        {
            Vector<2, T>::data[0] = x;
            Vector<2, T>::data[1] = y;
        }
        
        Vector2(const Vector<2, T>& orig)
        : Vector<2, T>(orig) {}
        
        template <typename U>
        Vector2(const Vector<2, U>& orig)
        : Vector<2, T>(orig) {}
    };
    
    typedef Vector2<int> Vector2i;
    typedef Vector2<unsigned int> Vector2ui;    
    typedef Vector2<float> Vector2f;
    typedef Vector2<double> Vector2d;
    
    /**
     * Specialisation for Vector2
     **/
    template <typename T>
    class Vector3 : public Vector<3, T>
    {
    public:
        Vector3() {}
        
        Vector3(T x, T y, T z)
        {
            Vector<3, T>::data[0] = x;
            Vector<3, T>::data[1] = y;
            Vector<3, T>::data[2] = z;
        }
        
        Vector3(const Vector<3, T>& orig)
        : Vector<3, T>(orig) {}
        
        template <typename U>
        Vector3(const Vector<3, U>& orig)
        : Vector<3, T>(orig) {}
    };
    
    typedef Vector3<int> Vector3i;
    typedef Vector3<unsigned int> Vector3ui;    
    typedef Vector3<float> Vector3f;
    typedef Vector3<double> Vector3d;
    
    /**
     * Is equal operator for Vector.
     **/
    template <unsigned int N, typename T>
    bool operator == (const Vector<N, T>& a, const Vector<N, T>& b)
    {
        for (unsigned int i = 0; i < N; i++)
        {
            if (! equals(a(i), b(i)))
            {
                return false;
            }
        }
        return true;
    }
    
    /**
     * Is not equal operator for Vector.
     **/
    template <unsigned int N, typename T>
    bool operator != (const Vector<N, T>& a, const Vector<N, T>& b)
    {
        return !(a == b);
    }
    
    /**
     * Is equal operator for Vector.
     **/
    template <unsigned int N, typename T>
    std::ostream& operator << (std::ostream& os, const Vector<N, T>& v)
    {
        os << "(";
        for (unsigned int i = 0; i < N; i++)
        {
            os << v(i);
            if (i != N - 1)
            {
                os << ", ";
            }
        }
        os << ")";
        return os;
    }
    
    /**
     * Vector addition
     **/
    template <unsigned int N, typename T>
    Vector<N, T> operator + (const Vector<N, T>& a, const Vector<N, T>& b)
    {
        Vector<N, T> result;
        for (unsigned int i = 0; i < N; i++)
        {
            result(i) = a(i) + b(i);
        }
        return result;
    }
    
    /**
     * Vector subtraction
     **/
    template <unsigned int N, typename T>
    Vector<N, T> operator - (const Vector<N, T>& a, const Vector<N, T>& b)
    {
        Vector<N, T> result;
        for (unsigned int i = 0; i < N; i++)
        {
            result(i) = a(i) - b(i);
        }
        return result;
    }
    
    template <unsigned int N, typename T>
    Vector<N, T> rescale(const Vector<N, T>& value, const Vector<N, T>& source, const Vector<N, T>& target)
    {
        Vector<N, T> result;
        for (unsigned int i = 0; i < N; i++)
        {
            result(i) = rescale<T>(value(i), source(i), target(i));
        }
        return result;
    }

}

#endif
