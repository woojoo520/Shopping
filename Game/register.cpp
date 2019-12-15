#include "register.h"
#include "ui_register.h"

/**
 * @brief Construct a new Register:: Register object
 * Initialization, setting the format of account password
 * @param parent 
 */
Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    ui->User_pwd->setEchoMode(QLineEdit::Password);
    ui->resurePwd->setEchoMode(QLineEdit::Password);
}

/**
 * @brief Destroy the Register:: Register object
 */
Register::~Register()
{
    delete ui;
}

QVector<QString> Register::getInfoMation() {

}


/**
 * @brief Get registered user information and submit to server
 * get the information of the user's name, password, address, phone number and the logo picture. send a signal to the mainWindow to pass it to server
 */
void Register::on_registerBtn_clicked()
{
    QJsonObject infoJson;
    infoJson["type"] = "UserRegister";
    infoJson["User_Name"] = ui->User_Name->text();
    infoJson["User_pwd"] = ui->User_pwd->text();
    infoJson["resurePwd"] = ui->resurePwd->text();
    infoJson["User_Address"] = ui->User_Address->text();
    infoJson["User_Phone"] = ui->User_Phone->text();
    infoJson["fileName"] = fileName;
    emit sendInfo(infoJson);
}

/**
 * @brief   Open local folder and upload user image
 * Get the user's local picture as the user's logo image, and display the picture in the logo area
 */
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

/**
 * @brief   Get the picture of logo area and save it in the registration information
 */
void Register::SaveImg() {
    QString savePath = "E:\\Qt\\Shopping\\Game\\pic\\UserLogo\\" + ui->User_Name->text() + ".jpg";
    QScreen *screen = QGuiApplication::primaryScreen();
    screen->grabWindow(ui->logo_Label->winId()).save(savePath);
    qDebug() << "savePath = " << savePath << endl;
    QJsonObject infoJson;
    infoJson["type"] = "updateImgSrc";
    infoJson["User_name"] = ui->User_Name->text();
    infoJson["savePath"] = savePath;
    emit ImgSrcSignal(infoJson);
}
