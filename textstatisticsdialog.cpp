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
    ui->textEdit->setWordWrapMode(QTextOption::NoWrap);
    ui->lineEditCC->setText(cc);
    ui->lineEditCC->setReadOnly(true);
    ui->lineEditWC->setText(wc);
    ui->lineEditWC->setReadOnly(true);
    ui->lineEditLC->setText(lc);
    ui->lineEditLC->setReadOnly(true);
    ui->lineEditSZ->setText(sz);
    ui->lineEditSZ->setReadOnly(true);
    connect(ui->pushButtonClose, &QPushButton::clicked, [=](){
        accept();
    });
    resize(600, 400);
}

TextStatisticsDialog::~TextStatisticsDialog()
{
    delete ui;
}

