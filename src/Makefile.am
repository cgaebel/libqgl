##
## libqgl - The quick game library
## Copyright 2009 Sean Farell
##
## This file is part of libqgl.
##
## libqgl is free software: you can redistribute it and/or modify
## it under the terms of the GNU Lesser General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## libqgl is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU Lesser General Public License
## along with libqgl. If not, see <http://www.gnu.org/licenses/>.
##

lib_LTLIBRARIES = libqgl.la

INCLUDES = -I$(top_srcdir)/include -DBUILD_QGL @SDL_CFLAGS@ @SIGC_CFLAGS@

libqgl_la_LIBADD = @SDL_LIBS@  @SIGC_LIBS@ @GL_LIBS@

libqgl_la_LDFLAGS = -version-info @LT_VERSION@

libqgl_la_SOURCES = \
	debug.cpp \
    utils.cpp \
    opengl_utils.cpp \
	math_utils.cpp \
	Engine.cpp \
	GraphicSystem.cpp \
	SdlSentry.cpp \
	InputSystem.cpp \
    ColorFormat.cpp \
	Image.cpp \
    Font.cpp \
    Screen.cpp \
    Widget.cpp \
    Label.cpp \
    Button.cpp 
