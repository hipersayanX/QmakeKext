# QmakeKext
Skeleton for creating kernel extensions for Mac OS X using Qmake

For testing the generated kext, you must request a [Developer ID Certificate](https://developer.apple.com/library/content/documentation/Darwin/Conceptual/KEXTConcept/KEXTConceptAnatomy/kext_anatomy.html), because even with [SIP](https://en.wikipedia.org/wiki/System_Integrity_Protection) [disabled](https://developer.apple.com/library/content/documentation/Security/Conceptual/System_Integrity_Protection_Guide/ConfiguringSystemIntegrityProtection/ConfiguringSystemIntegrityProtection.html), codesigning is still required.

After compiling the kext, you must change the owner to **root:wheel**:

    sudo chown -R root:wheel QmakeKext.kext

And then load the kext with:

    sudo kextload -v QmakeKext.kext

If the kext is not signed, kextload will fail.
