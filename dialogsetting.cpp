#include "dialogsetting.h"
#include "ui_dialogsetting.h"
#include <QSettings>
#include <QVariant>
#include <QFile>
#include <qDebug>

DialogSetting::DialogSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSetting)
{
    ui->setupUi(this);

    QString fileName = "settconfig.ini";
    QSettings sett(fileName, QSettings::IniFormat);
    ui->SiteSettLineEdit->setText(sett.value("SET_1/Site").toString());
    ui->TimeoutSiteSettLineEdit->setText(sett.value("SET_1/TimeoutSite").toString());
    ui->TimeoutCitySettLineEditor->setText(sett.value("SET_1/TimeoutCity").toString());

    QObject::connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(AcceptedSett()));
}

DialogSetting::~DialogSetting()
{
    delete ui;
}

void DialogSetting::AcceptedSett()
{
    QString fileName = "settconfig.ini";
    QSettings sett(fileName, QSettings::IniFormat);

    sett.setValue("SET_1/Site",ui->SiteSettLineEdit->text());
    sett.setValue("SET_1/TimeoutSite",ui->TimeoutSiteSettLineEdit->text());
    sett.setValue("SET_1/TimeoutCity",ui->TimeoutCitySettLineEditor->text());
}

