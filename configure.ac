dnl
dnl libqgl - The quick game library
dnl Copyright 2009 Sean Farell
dnl
dnl This file is part of libqgl.
dnl
dnl libqgl is free software: you can redistribute it and/or modify
dnl it under the terms of the GNU Lesser General Public License as published by
dnl the Free Software Foundation, either version 3 of the License, or
dnl (at your option) any later version.
dnl
dnl libqgl is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
dnl GNU General Public License for more details.
dnl
dnl You should have received a copy of the GNU Lesser General Public License
dnl along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
dnl

AC_INIT([libqgl], [0.1.0])
AM_INIT_AUTOMAKE(foreign)

AC_LANG([C++])
AC_PROG_CXX
AC_PROG_LIBTOOL
AC_LIBTOOL_WIN32_DLL

dnl current
dnl     The most recent interface number that this library implements.
dnl revision
dnl     The implementation number of the current interface.
dnl age
dnl     The difference between the newest and oldest interfaces that this 
dnl     library implements. In other words, the library implements all the 
dnl     interface numbers in the range from number current - age to current. 

dnl 1. Start with version information of �0:0:0� for each libtool library.
dnl 2. Update the version information only immediately before a public release 
dnl    of your software. More frequent updates are unnecessary, and only 
dnl    guarantee that the current interface number gets larger faster.
dnl 3. If the library source code has changed at all since the last update, 
dnl    then increment revision (�c:r:a� becomes �c:r+1:a�).
dnl 4. If any interfaces have been added, removed, or changed since the last 
dnl    update, increment current, and set revision to 0.
dnl 5. If any interfaces have been added since the last public release, 
dnl    then increment age.
dnl 6. If any interfaces have been removed since the last public release, 
dnl    then set age to 0. 

dnl current:revision:age
LT_VERSION="0:0:0"
AC_SUBST(LT_VERSION)

AC_CONFIG_FILES([    
    Makefile
    libqgl.pc
    include/Makefile
    src/Makefile
])

AC_OUTPUT