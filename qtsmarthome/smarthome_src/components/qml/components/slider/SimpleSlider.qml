/** This file is part of Medical Device Qt Quick Embedded Widgets Demo**
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
/**
A simple slider. The fillbar changes with the slider. The outer image
simply clips the image of the fillbar, so the y-coordinate of the
fillbar can be bound to the y-coordinate of the slider.

property int value:              Value to set the current value of the slider.
property string backgroundImage: The image of the background of the slider.
property string fillingBarImage: The image of the filling bar of the slider.
*/
Image {
    id: background

    property int value: 0
    property string backgroundImage: "../pics/multislider/Beryl/valuebar.svg"
    property string fillingBarImage: "../pics/multislider/Beryl/valuebar_filled.svg"

    sourceSize.width: background.width
    sourceSize.height: background.height
    smooth: true
    clip: true
    source: backgroundImage

    Image {
        id: fillingBar
        width: parent.width
        height: background.height
        sourceSize.height: fillingBar.height
        sourceSize.width: fillingBar.width
        source: fillingBarImage
        anchors.top: slider.bottom
        anchors.topMargin: -1
        anchors.left: slider.left
    }


    Rectangle {
        id: slider
        y: value
        width: parent.width - 2
        height: 32
        anchors.horizontalCenter: parent.horizontalCenter
        border.width: 2
        border.color: "#709E10"
        smooth: true
        radius: 2
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#cccccc"
            }

            GradientStop {
                position: 0.5
                color: "#818181"
            }

            GradientStop {
                position: 1
                color: "#d3d3d3"
            }
        }

        MouseArea {
            anchors.fill: parent
            anchors.horizontalCenter: parent.horizontalCenter
            drag.target: parent
            drag.axis: Drag.YAxis
            drag.minimumY: 2
            drag.maximumY: background.height - slider.height - 2

            onPressed: {
                slider.border.color = "#D5EC00"
            }
            onReleased: {
                slider.border.color = "#709E10"
            }
        }
    }
}

