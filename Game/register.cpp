#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    ui->User_pwd->setEchoMode(QLineEdit::Password);
    ui->resurePwd->setEchoMode(QLineEdit::Password);
}

Register::~Register()
{
    delete ui;
}

QVector<QString> Register::getInfoMation() {

}

void Register::on_registerBtn_clicked()
{
    QVector<QString> infoVec;
    infoVec.push_back(ui->User_Name->text());
    infoVec.push_back(ui->User_pwd->text());
    infoVec.push_back(ui->resurePwd->text());
    infoVec.push_back(ui->User_Address->text());
    infoVec.push_back(ui->User_Phone->text());
    infoVec.push_back(fileName);
    emit sendInfo(infoVec);
}

void Register::on_logoBtn_clicked()
{
    fileName = QFileDialog::getOpenFileName(
                this, tr("open image file"),
                "./", tr("Image files(*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm);;All files (*.*)"));

    if(fileName.isEmpty())
    {
        QMessageBox::warning(this,"警告","打开图片失败!");
        return;
    } else {
        QImage *img = new QImage;
        img->load(fileName);
        QImage newImg = img->scaled(ui->logo_Label->width(), ui->logo_Label->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->logo_Label->setPixmap(QPixmap::fromImage(newImg));
    }
}

void Register::SaveImg() {
    QString savePath = "E:\\Qt\\Shopping\\Game\\pic\\UserLogo\\" + ui->User_Name->text() + ".jpg";
    QScreen *screen = QGuiApplication::primaryScreen();
    screen->grabWindow(ui->logo_Label->winId()).save(savePath);
    qDebug() << "savePath = " << savePath << endl;
    QVector<QString> InfoVec;
    InfoVec.push_back(ui->User_Name->text());
    InfoVec.push_back(savePath);
    emit ImgSrcSignal(InfoVec);
}
