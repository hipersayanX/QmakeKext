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

#ifndef QMAKEKEXT_H
#define QMAKEKEXT_H

#include <IOKit/IOService.h>

class com_osxkernel_driver_QmakeKext: public IOService
{
    OSDeclareDefaultStructors(com_osxkernel_driver_QmakeKext)

    public:
        virtual bool init(OSDictionary *dictionary=NULL) override;
        virtual void free() override;
        virtual IOService *probe(IOService *provider, SInt32 *score) override;
        virtual bool start(IOService *provider) override;
        virtual void stop(IOService *provider) override;
};

#endif // QMAKEKEXT_H
