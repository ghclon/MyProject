#include "my2widget.h"
#include "ui_my2widget.h"
#include <QSettings>
#include <QVariant>
#include <QFile>
#include <qDebug>
#include "dialogsetting.h"
#include "ui_dialogsetting.h"

My2Widget::My2Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::My2Widget)
{
    ui->setupUi(this);

    QString fileName = "settconfig.ini";
    QSettings sett(fileName, QSettings::IniFormat);
    if (!QFile::exists(fileName))
    {
      qDebug() << "FILE" << fileName <<" DON'T EXIST" << endl;
      sett.setValue("SET_1/TimeoutCity","5");
      sett.setValue("SET_1/TimeoutSite","10");
      sett.setValue("SET_1/Site","gismeteo.ru");
    }


    QObject::connect(ui->SettPushButton, SIGNAL(clicked()), this, SLOT(OpenSett()));

}

My2Widget::~My2Widget()
{
    delete ui;
}

void My2Widget::OpenSett()
{
    DialogSetting *ws = new DialogSetting();
    ws->show();

}


