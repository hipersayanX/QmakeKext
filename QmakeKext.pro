# QmakeKext, Skeleton for creating kernel extensions for Mac OS X using Qmake.
# Copyright (C) 2017  Gonzalo Exequiel Pedone
#
# Webcamoid is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Webcamoid is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Webcamoid. If not, see <http://www.gnu.org/licenses/>.
#
# Web-Site: https://github.com/hipersayanX/QmakeKext

CONFIG -= qt
CONFIG += unversioned_libname unversioned_soname

# NOTE: "builtin-infoPlistUtility" can be found in:
#
# https://github.com/facebook/xcbuild
#
# It can be useful for filling some missing members in Info.plist, but doesn't
# fill it's values (bug maybe?).
checkIPLU = $$system(which builtin-infoPlistUtility)

isEmpty(checkIPLU) {
    procPlist = cp -vf Info.plist $${TARGET}.kext/Contents
} else {
    procPlist = builtin-infoPlistUtility \
                    Info.plist \
                    -expandbuildsettings \
                    -platform macosx \
                    -o $${TARGET}.kext/Contents/Info.plist
}

signingIdentity = "-"

QMAKE_POST_LINK = \
    mkdir -p $${TARGET}.kext/Contents/MacOS && \
    cp -vf lib$${TARGET}.dylib $${TARGET}.kext/Contents/MacOS/$${TARGET} && \
    $${procPlist} && \
    codesign \
        --force \
        --sign $${signingIdentity} \
        --timestamp=none \
        $${TARGET}.kext

QMAKE_CXXFLAGS += \
    -nostdinc \
    -fno-builtin \
    -fno-exceptions \
    -fno-rtti \
    -msoft-float \
    -fno-common \
    -mkernel \
    -fapple-kext \
    -fasm-blocks \
    -fstrict-aliasing
QMAKE_CXXFLAGS_SHLIB =

QMAKE_LFLAGS -= \
    -headerpad_max_install_names
QMAKE_LFLAGS += \
    -Xlinker -export_dynamic \
    -Xlinker -no_deduplicate \
    -Xlinker -kext \
    -nostdlib
QMAKE_LFLAGS_SHLIB =
QMAKE_LFLAGS_SONAME =
QMAKE_LFLAGS_VERSION =
QMAKE_LFLAGS_COMPAT_VERSION =

INCLUDEPATH = \
    /System/Library/Frameworks/Kernel.framework/Headers

LIBS = \
    -lkmod \
    -lkmodc++ \
    -lcc_kext

TARGET = QmakeKext
TEMPLATE = lib

HEADERS += \
    src/qmakekext.h

SOURCES += \
    src/qmakekext.cpp

OTHER_FILES = \
    Info.plist

unix {
    target.path = /usr/lib
    INSTALLS += target
}
