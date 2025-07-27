#pragma once

#include <QObject>
#include "plugin-sdk/plugin.h"

class ChatPlugin : public QObject, public IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID PluginIID FILE "manifest.json")
    Q_INTERFACES(IPlugin)

public:
    QString name() const override;
};