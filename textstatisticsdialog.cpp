#include "textstatisticsdialog.h"
#include "ui_textstatisticsdialog.h"

TextStatisticsDialog::TextStatisticsDialog(
    QString selectedText, QString cc, QString wc, QString lc, QString sz,
    QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TextStatisticsDialog)
{
    ui->setupUi(this);

    ui->textEdit->setPlainText(selectedText);
    ui->textEdit->setReadOnly(true);
    ui->lineEditCC->setText(cc);
    ui->lineEditWC->setText(wc);
    ui->lineEditLC->setText(lc);
    ui->lineEditSZ->setText(sz);
    connect(ui->pushButtonClose, &QPushButton::clicked, [=](){
        accept();
    });
    resize(600, 400);
}

TextStatisticsDialog::~TextStatisticsDialog()
{
    delete ui;
}

