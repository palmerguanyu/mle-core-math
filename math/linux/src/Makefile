# -*- Makefile -*-
#
#  Copyright (C) 2000-2007  Wizzer Works
#
#  Wizzer Works makes available all content in this file ("Content").
#  Unless otherwise indicated below, the Content is provided to you
#  under the terms and conditions of the Common Public License Version 1.0
#  ("CPL"). A copy of the CPL is available at
#
#      http://opensource.org/licenses/cpl1.0.php
#
#  For purposes of the CPL, "Program" will mean the Content.
#
#  For information concerning this Makefile, contact Mark S. Millard,
#  of Wizzer Works at msm@wizzerworks.com.
#
#*************************************************************************
#
# Makefile - For making the linux Configuration of the Magic Lantern Math
#            Libraries.
#
# $Id$
#
#*************************************************************************

ISM_DEPTH = ..
include $(ISM_DEPTH)/ismdefs

#
# Set which versions we are making.  There needs to be a subdirectory
# under here for each (for VERSIONS_MAKERULE to work).
#
VERSIONS = \
    FloatDebug FloatRelease FixedDebug FixedRelease \
    ToolsFloatDebug ToolsFloatRelease

#
# Descend into the subdirectories for COMMONTARGS:
#
SUBDIRS = \
	$(NULL)

all $(COMMONTARGS):
	$(SUBDIRS_MAKERULE)
	$(VERSIONS_MAKERULE)

install export: $(_FORCE)
	$(SUBDIRS_MAKERULE)
	$(VERSIONS_MAKERULE)

collect:
	$(IBCOLLECT) -log ../build/collect.raw \
                     -srcDir . \
                     -destDir "Core/math/linux/src" \
                     -tags SOURCE \
                     Makefile leafdefs
	$(SUBDIRS_MAKERULE)
	$(VERSIONS_MAKERULE)

include $(ISMRULES)
