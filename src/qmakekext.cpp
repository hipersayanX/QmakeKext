/* QmakeKext, Skeleton for creating kernel extensions for Mac OS X using Qmake.
 * Copyright (C) 2017  Gonzalo Exequiel Pedone
 *
 * Webcamoid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Webcamoid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Webcamoid. If not, see <http://www.gnu.org/licenses/>.
 *
 * Web-Site: https://github.com/hipersayanX/QmakeKext
 */

#include <IOKit/IOLib.h>

#include "qmakekext.h"

OSDefineMetaClassAndStructors(com_osxkernel_driver_QmakeKext, IOService)

bool com_osxkernel_driver_QmakeKext::init(OSDictionary *dictionary)
{
    bool res = IOService::init(dictionary);
    IOLog("QmakeKext::init\n");

    return res;
}

void com_osxkernel_driver_QmakeKext::free()
{
    IOLog("QmakeKext::free\n");
    IOService::free();
}

IOService *com_osxkernel_driver_QmakeKext::probe(IOService *provider,
                                                 SInt32 *score)
{
    IOService *res = IOService::probe(provider, score);
    IOLog("QmakeKext::probe\n");

    return res;
}

bool com_osxkernel_driver_QmakeKext::start(IOService *provider)
{
    bool res = IOService::start(provider);
    IOLog("QmakeKext::start\n");

    return res;
}

void com_osxkernel_driver_QmakeKext::stop(IOService *provider)
{
    IOLog("QmakeKext::stop\n");
    IOService::stop(provider);
}
