
#include "textstatistics.h"

#include <QApplication>
#include <QMap>
#include <QMessageBox>
#include <QDialog>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QRegularExpression>
#include <QTranslator>
#include <QDebug>

#include "textstatisticsdialog.h"

int TextStatistics::init(QMap<QString, QString> params, QWidget *parent)
{
    Q_UNUSED(params);

    m_action = new QAction(tr("Text Statistics"), parent);
    connect(m_action, &QAction::triggered, [&,parent](){
        QMessageBox::information(parent, tr("Text Statistics"), PLUGIN_VERSION);
    });

    return 0;
}

QList<QAction *> TextStatistics::terminalContextAction(QString selectedText, QString workingDirectory, QMenu *parentMenu)
{
    Q_UNUSED(workingDirectory);
    if(selectedText.isEmpty()) {
        return QList<QAction *>();
    }

    QList<QAction *> actions;
    QAction *textStatistics = new QAction(tr("Text Statistics"), parentMenu);
    actions.append(textStatistics);
    connect(textStatistics, &QAction::triggered, this, [=](){
        static QRegularExpression re("\\s+");
        TextStatisticsDialog dialog(selectedText,
            QString::number(selectedText.length()),
            QString::number(selectedText.split(re, Qt::SkipEmptyParts).count()),
            QString::number(selectedText.split("\n", Qt::SkipEmptyParts).count()),
            QString::number(selectedText.toUtf8().size()),
            parentMenu);
        dialog.setWindowTitle(tr("Text Statistics"));
        dialog.exec();
    });

    return actions;
}

void TextStatistics::setLanguage(const QLocale &language,QApplication *app) {
    static QTranslator *qtTranslator = nullptr;
    if(qtTranslator == nullptr) {
        qtTranslator = new QTranslator(app);
    } else {
        app->removeTranslator(qtTranslator);
        delete qtTranslator;
        qtTranslator = new QTranslator(app);
    }
    switch(language.language()) {
    case QLocale::Chinese:
        if(qtTranslator->load(":/lang/textstatistics_zh_CN.qm"))
            app->installTranslator(qtTranslator);
        break;
    default:
    case QLocale::English:
        if(qtTranslator->load(":/lang/textstatistics_en_US.qm"))
            app->installTranslator(qtTranslator);
        break;
    }
}

void TextStatistics::retranslateUi() {
    m_action->setText(tr("Text Statistics"));
}
