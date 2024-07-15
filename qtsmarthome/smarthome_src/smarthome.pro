TEMPLATE = app
QT += qml xml quick widgets serialport
DESTDIR = ../smarthome_src
TARGET = smarthome

SOURCES += src/main.cpp \
    src/file_reader.cpp \
    src/lightcontroller.cpp \
    src/myquickview.cpp \
    src/serial_port.cpp

HEADERS += \
    src/file_reader.h \
    src/lightcontroller.h \
    src/myquickview.h \
    src/serial_port.h

OTHER_FILES += \
    qml/smarthome/smarthome.qml \
    qml/smarthome/components/qmldir \
    qml/smarthome/components/WindSlider.qml \
    qml/smarthome/components/WeatherView.qml \
    qml/smarthome/components/WeatherItem.qml \
    qml/smarthome/components/WeatherGodScreen.qml \
    qml/smarthome/components/WeatherGod.qml \
    qml/smarthome/components/Titlebar.qml \
    qml/smarthome/components/TemperatureView.qml \
    qml/smarthome/components/TemperatureSlider.qml \
    qml/smarthome/components/TemperatureScale.qml \
    qml/smarthome/components/SlideSwitch.qml \
    qml/smarthome/components/SHText.qml \
    qml/smarthome/components/MainScreen.qml \
    qml/smarthome/components/MainMenu.qml \
    qml/smarthome/components/ForeCastView.qml \
    qml/smarthome/components/FanStack.qml \
    qml/smarthome/components/Devider.qml \
    qml/smarthome/components/Cloud.qml \
    qml/smarthome/components/ActualValueSlider.qml \
    qml/smarthome/components/models/HardwareModels.qml \
    qml/smarthome/components/settings/WindowWindTab.qml \
    qml/smarthome/components/settings/WindowSettings.qml \
    qml/smarthome/components/settings/WindowRainTab.qml \
    qml/smarthome/components/settings/TimePickerTab.qml \
    qml/smarthome/components/settings/TabPage.qml \
    qml/smarthome/components/settings/SettingsItem.qml \
    qml/smarthome/components/settings/LightSettingsTab.qml \
    qml/smarthome/components/settings/LightSettings.qml \
    qml/smarthome/components/settings/JalousieWindTab.qml \
    qml/smarthome/components/settings/JalousieTemperatureTab.qml \
    qml/smarthome/components/settings/JalousieSettings.qml \
    qml/smarthome/components/settings/HeatingSettingsTab.qml \
    qml/smarthome/components/settings/HeatingSettings.qml \
    qml/smarthome/components/tabwidget/VTabBar.qml \
    qml/smarthome/components/tabwidget/TabWidget.qml \
    qml/smarthome/components/tabwidget/HTabBar.qml
