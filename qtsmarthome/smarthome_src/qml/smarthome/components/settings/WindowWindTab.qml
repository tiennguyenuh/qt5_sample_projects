/** This file is part of Home Control Qt Quick Embedded Widgets Demo**
*
* Copyright © 2010 Nokia Corporation and/or its subsidiary(-ies).*
* All rights reserved.
*
* Contact:  Nokia Corporation (qt-info@nokia.com)
*
* You may use this file under the terms of the BSD license as follows:
*
* “Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
* Redistributions of source code must retain the above copyright notice, this
* list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice,
* this list of conditions and the following disclaimer in the documentation
* and/or other materials provided with the distribution.
* Neither the name of Nokia Corporation and its Subsidiary(-ies) nor the
* names of its contributors may be used to endorse or promote products
* derived from this software without specific prior written permission.
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
* PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.”
*/

import QtQuick 2.0
import "../"

/**
 * This is the tab for showing the wind settings
 * It is used in the Settings Elements.
 */
TabPage {
    id: windowWindTab

    property alias currentSliderValue: windSlider.value
    property alias currentSliderActualValue: windSlider.actualValue
    property real currentWindForceValue

    signal checkStateTriggered()

    /**
    * A custom item for wind settings.
    * (\see WindSlider)
    */
    WindSlider {
        id: windSlider
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 70
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: -100
        value: 35
        actualValue: currentWindForceValue / 12 * 60
        onValueChanged: {
            console.log("window win tab value change ", actualValue)
            checkStateTriggered()
        }
    }
}
