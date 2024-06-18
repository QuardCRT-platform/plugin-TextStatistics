#include <QCryptographicHash>
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
    ui->lineEditMD5->setText(QCryptographicHash::hash(selectedText.toUtf8(), QCryptographicHash::Md5).toHex());
    ui->lineEditMD5->setReadOnly(true);
    ui->lineEditSHA1->setText(QCryptographicHash::hash(selectedText.toUtf8(), QCryptographicHash::Sha1).toHex());
    ui->lineEditSHA1->setReadOnly(true);
    ui->lineEditSHA256->setText(QCryptographicHash::hash(selectedText.toUtf8(), QCryptographicHash::Sha256).toHex());
    ui->lineEditSHA256->setReadOnly(true);
    ui->lineEditSHA512->setText(QCryptographicHash::hash(selectedText.toUtf8(), QCryptographicHash::Sha512).toHex());
    ui->lineEditSHA512->setReadOnly(true);
    connect(ui->pushButtonClose, &QPushButton::clicked, [=](){
        accept();
    });
}

TextStatisticsDialog::~TextStatisticsDialog()
{
    delete ui;
}

