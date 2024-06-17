#ifndef TEXTSTATISTICSDIALOG_H
#define TEXTSTATISTICSDIALOG_H

#include <QDialog>

namespace Ui {
class TextStatisticsDialog;
}

class TextStatisticsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TextStatisticsDialog(QString selectedText, QString cc, QString wc, QString lc, QString sz,
            QWidget *parent = nullptr);
    ~TextStatisticsDialog();

private:
    Ui::TextStatisticsDialog *ui;
};

#endif // TEXTSTATISTICSDIALOG_H
