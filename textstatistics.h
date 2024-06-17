#ifndef TEXTSTATISTICS_H_
#define TEXTSTATISTICS_H_

#include "plugininterface.h"

#define PLUGIN_NAME    "Text Statistics"
#define PLUGIN_VERSION "0.0.1"

class TextStatistics : public PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.quardCRT.PluginInterface" FILE "./plugininterface/plugininterface.json")
    Q_INTERFACES(PluginInterface)

public:
    TextStatistics() : m_action(nullptr) {}
    virtual ~TextStatistics() {}

    int init(QMap<QString, QString> params, QWidget *parent);

    void setLanguage(const QLocale &language,QApplication *app);
    void retranslateUi();
    QString name() { return PLUGIN_NAME; }
    QString version() { return PLUGIN_VERSION; }

    QMap<QString,void *> metaObject() {
        QMap<QString,void *> ret;
        ret.insert("QAction", (void *)m_action);
        return ret;
    }

    QMenu *terminalContextMenu(QString selectedText, QString workingDirectory, QMenu *parentMenu) {Q_UNUSED(selectedText);Q_UNUSED(workingDirectory);Q_UNUSED(parentMenu); return nullptr;}
    QList<QAction *> terminalContextAction(QString selectedText, QString workingDirectory, QMenu *parentMenu);

private:
    QAction *m_action;
};

#endif /* TEXTSTATISTICS_H_ */
